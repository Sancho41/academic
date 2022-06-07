package br.iesb.banco.models.pessoa

/**
 * Classe sem encapsulamento pois os dados podem ser alterados livrementes,
 * sem a necessidade de regras
 */
class PessoaFisica(endereco: String, nome: String, documento: String, var dataNascimento: String) :
    Pessoa(endereco, nome, documento) {

    override fun toString(): String {
        return "Pessoa Fisica[${super.toString()}]"
    }
}