package br.iesb.banco.models.pessoa

/**
 * Pessoa base como classe abstrata, pois não será possível criar uma pessoa
 * de tipo genérico, somente pessoas físicas e pessoas Jurídicas
 *
 * Classe sem encapsulamento pois os dados podem ser alterados livrementes,
 * sem a necessidade de regras
 */
abstract class Pessoa(var endereco: String, var nome: String, var documento: String) {

    override fun toString(): String {
        return "Nome: $nome; Endereco: $endereco; Documento: $documento"
    }

}