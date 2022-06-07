package br.iesb.banco.models.pessoa

/**
 * Classe sem encapsulamento pois os dados podem ser alterados livrementes,
 * sem a necessidade de regras
 */
class PessoaJuridica(
    endereco: String,
    nome: String,
    documento: String,
    var razaoSocial: String,
    var inscricaoEstadual: String
) : Pessoa(endereco, nome, documento) {
    override fun toString(): String {
        return "Pessoa Juridica[${super.toString()}]"
    }
}
