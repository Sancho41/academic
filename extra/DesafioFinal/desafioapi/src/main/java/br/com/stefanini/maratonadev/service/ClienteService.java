package br.com.stefanini.maratonadev.service;

import br.com.stefanini.maratonadev.dao.ClienteDao;
import br.com.stefanini.maratonadev.dto.ClienteDto;
import br.com.stefanini.maratonadev.model.parser.CarroParser;
import br.com.stefanini.maratonadev.model.parser.ClienteParser;

import javax.enterprise.context.RequestScoped;
import javax.inject.Inject;
import java.util.List;
import java.util.stream.Collectors;

@RequestScoped
public class ClienteService {
    @Inject
    ClienteDao dao;

    public ClienteDto cadastrar(ClienteDto clienteDto) {
        return ClienteParser.get().dto(dao.cadastrar(clienteDto));
    }

    public List<ClienteDto> listar() {
        return dao.listar().stream().map(ClienteParser.get()::dto).collect(Collectors.toList());
    }
}
