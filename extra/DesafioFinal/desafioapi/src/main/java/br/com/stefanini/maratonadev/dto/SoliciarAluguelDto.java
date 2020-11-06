package br.com.stefanini.maratonadev.dto;

public class SoliciarAluguelDto {
    private String cpf;
    private String placa;

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getPlaca() {
        return placa;
    }

    public void setPlaca(String placa) {
        this.placa = placa;
    }
}
