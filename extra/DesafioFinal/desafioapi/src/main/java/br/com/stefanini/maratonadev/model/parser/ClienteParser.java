package br.com.stefanini.maratonadev.model.parser;

import br.com.stefanini.maratonadev.dto.ClienteDto;
import br.com.stefanini.maratonadev.model.Cliente;

public class ClienteParser {

    public static ClienteParser get() {
        return new ClienteParser();
    }

    public ClienteDto dto(Cliente client) {
        ClienteDto dto = new ClienteDto();
        dto.setCpf(client.getCpf());
        dto.setNome(client.getNome());
        dto.setCep(client.getCep());
        dto.setLogradouro(client.getLogradouro());
        dto.setComplemento(client.getComplemento());
        dto.setBairro(client.getBairro());
        dto.setCidade(client.getCidade());
        dto.setUf(client.getUf());
        dto.setEmail(client.getEmail());
        dto.setContato(client.getContato());
        return dto;
    }
}
