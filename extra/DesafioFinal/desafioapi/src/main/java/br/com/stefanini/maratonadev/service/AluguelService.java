package br.com.stefanini.maratonadev.service;

import br.com.stefanini.maratonadev.dao.AluguelDao;
import br.com.stefanini.maratonadev.dto.AluguelDto;
import br.com.stefanini.maratonadev.dto.FinalizarAluguelDto;
import br.com.stefanini.maratonadev.dto.SoliciarAluguelDto;
import br.com.stefanini.maratonadev.model.parser.AluguelParser;

import javax.enterprise.context.RequestScoped;
import javax.inject.Inject;
import java.util.List;
import java.util.stream.Collectors;

@RequestScoped
public class AluguelService {
    @Inject
    AluguelDao dao;

    public AluguelDto solicitarAluguel(SoliciarAluguelDto soliciarAluguelDto) throws Exception {
        return AluguelParser.get().dto(dao.salvar(soliciarAluguelDto));
    }

    public List<AluguelDto> listar() {
        return dao.listar().stream().map(AluguelParser.get()::dto).collect(Collectors.toList());
    }

    public AluguelDto finalizar(FinalizarAluguelDto finalizarAluguelDto) {
        return AluguelParser.get().dto(dao.finalizar(finalizarAluguelDto));
    }
}
