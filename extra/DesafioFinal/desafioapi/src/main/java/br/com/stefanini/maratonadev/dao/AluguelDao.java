package br.com.stefanini.maratonadev.dao;

import br.com.stefanini.maratonadev.dto.FinalizarAluguelDto;
import br.com.stefanini.maratonadev.dto.SoliciarAluguelDto;
import br.com.stefanini.maratonadev.model.Aluguel;
import br.com.stefanini.maratonadev.model.Carro;
import br.com.stefanini.maratonadev.model.Cliente;
import io.quarkus.hibernate.orm.panache.PanacheQuery;

import javax.enterprise.context.RequestScoped;
import javax.inject.Inject;
import javax.transaction.Transactional;
import java.time.LocalDate;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@RequestScoped
public class AluguelDao {
    @Inject
    ClienteDao clienteDao;

    @Inject
    CarroDao carroDao;

    @Transactional
    public Aluguel salvar(SoliciarAluguelDto soliciarAluguelDto) throws Exception {

        Cliente cliente = clienteDao.buscarPorCpf(soliciarAluguelDto.getCpf());
        Carro carro = carroDao.bucarPorPlaca(soliciarAluguelDto.getPlaca());

        if (cliente == null || carro == null)
            throw new Exception("Cliente ou carro não encontrado");

        Map<String, Object> params = new HashMap<>();
        params.put("devolvido", false);
        params.put("cliente", cliente);

        PanacheQuery<Aluguel> queryCliente = Aluguel
                .find("devolvido = :devolvido and cliente = :cliente", params);

        if (queryCliente.count() > 0) throw new Exception("Não foi possível efetuar aluguel");

        params.remove("cliente");
        params.put("carro", carro);

        PanacheQuery<Aluguel> queryCarro = Aluguel
                .find("devolvido = :devolvido and carro = :carro", params);

        if (queryCarro.count() > 0) throw new Exception("Não foi possível efetuar aluguel");

        Aluguel aluguel = new Aluguel();
        aluguel.setCliente(cliente);
        aluguel.setCarro(carro);
        aluguel.setDevolvido(false);
        aluguel.setDataAluguel(LocalDate.now());
        Aluguel.persist(aluguel);


        return aluguel;
    }

    public List<Aluguel> listar() {
        return Aluguel.listAll();
    }

    @Transactional
    public Aluguel finalizar(FinalizarAluguelDto finalizarAluguelDto) {
        Aluguel aluguel = Aluguel.findById(finalizarAluguelDto.getId());
        aluguel.setDevolvido(true);
        Aluguel.persist(aluguel);
        return aluguel;
    }
}
