package br.com.stefanini.maratonadev.model;

import br.com.stefanini.maratonadev.dto.ClienteDto;
import io.quarkus.hibernate.orm.panache.PanacheEntityBase;
import org.hibernate.validator.constraints.Length;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;
import javax.validation.constraints.Email;
import javax.validation.constraints.NotNull;
import javax.validation.constraints.Pattern;

@Entity
@Table(name = "cliente")
public class Cliente extends PanacheEntityBase {
    @Id
    @Pattern(regexp = "\\d{11}")
    private String cpf;

    @NotNull
    @Length(min = 3, max = 100)
    @Pattern(regexp = "[A-Za-z ]+")
    private String nome;

    @NotNull
    private String cep;

    private String logradouro;

    private String complemento;

    @NotNull
    private String bairro;

    @NotNull
    private String cidade;

    @NotNull
    private String uf;

    @Email
    private String email;

    @Pattern(regexp = "\\d{11}|\\d{10}")
    private String contato;

    public Cliente() {
    }

    public Cliente(ClienteDto clienteDto) {
        this.cpf = clienteDto.getCpf();
        this.nome = clienteDto.getNome();
        this.cep = clienteDto.getCep();
        this.logradouro = clienteDto.getLogradouro();
        this.complemento = clienteDto.getComplemento();
        this.bairro = clienteDto.getBairro();
        this.cidade = clienteDto.getCidade();
        this.uf = clienteDto.getUf();
        this.email = clienteDto.getEmail();
        this.contato = clienteDto.getContato();
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCpf() {
        return cpf;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public String getCep() {
        return cep;
    }

    public void setCep(String cep) {
        this.cep = cep;
    }

    public String getLogradouro() {
        return logradouro;
    }

    public void setLogradouro(String logradouro) {
        this.logradouro = logradouro;
    }

    public String getComplemento() {
        return complemento;
    }

    public void setComplemento(String complemento) {
        this.complemento = complemento;
    }

    public String getBairro() {
        return bairro;
    }

    public void setBairro(String bairro) {
        this.bairro = bairro;
    }

    public String getCidade() {
        return cidade;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public String getUf() {
        return uf;
    }

    public void setUf(String uf) {
        this.uf = uf;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getContato() {
        return contato;
    }

    public void setContato(String contato) {
        this.contato = contato;
    }
}

