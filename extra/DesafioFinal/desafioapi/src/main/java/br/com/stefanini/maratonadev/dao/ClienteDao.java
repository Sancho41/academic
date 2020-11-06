package br.com.stefanini.maratonadev.dao;

import br.com.stefanini.maratonadev.dto.ClienteDto;
import br.com.stefanini.maratonadev.model.Cliente;

import javax.enterprise.context.RequestScoped;
import javax.transaction.Transactional;
import java.util.List;

@RequestScoped
public class ClienteDao {

    @Transactional
    public Cliente cadastrar(ClienteDto clienteDto) {
        Cliente cliente = new Cliente(clienteDto);
        Cliente.persist(cliente);
        return cliente;
    }

    public List<Cliente> listar() {
        return Cliente.listAll();
    }

    public Cliente buscarPorCpf(String cpf) {
        return Cliente.findById(cpf);
    }
}
