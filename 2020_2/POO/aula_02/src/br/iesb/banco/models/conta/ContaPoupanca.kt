package br.iesb.banco.models.conta

import br.iesb.banco.models.pessoa.Pessoa

class ContaPoupanca(agencia: String, numero: Number, cliente: Pessoa) : Conta(agencia, numero, cliente) {
    private val taxaRendimento: Float = 0.2F

    /**
     * Aplica o rendimento de acordo com a taxaRendimento
     */
    fun render() {
        this.depositar(this.getSaldo() * this.taxaRendimento)
    }

    override fun toString(): String {
        return "ContaPoupanca: [${super.toString()}]"
    }
}