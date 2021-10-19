package br.com.stefanini.maratonadev.model.parser;

import br.com.stefanini.maratonadev.dto.AluguelDto;
import br.com.stefanini.maratonadev.model.Aluguel;

public class AluguelParser {

    public static AluguelParser get() {
        return new AluguelParser();
    }

    public AluguelDto dto(Aluguel aluguel) {
        AluguelDto dto = new AluguelDto();
        dto.setId(aluguel.getId());
        dto.setDevolvido(aluguel.isDevolvido());
        dto.setDataAluguel(aluguel.getDataAluguel());
        dto.setCliente(aluguel.getCliente());
        dto.setCarro(aluguel.getCarro());
        return dto;
    }

}
