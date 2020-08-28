package br.iesb.banco.models.conta

import br.iesb.banco.models.pessoa.Pessoa

class ContaCorrente(agencia: String, numero: Number, cliente: Pessoa) : Conta(agencia, numero, cliente) {
    private val taxaDeSaque: Double = 0.2 // Taxa de saque

    /**
     * Override da função sacar para poder aplicar a taxa de saque
     *
     * @param valor: Double
     */
    override fun sacar(valor: Double) {
        val saque = valor + taxaDeSaque
        if (saque <= this.getSaldo())
            super.sacar(saque)
    }

    override fun toString(): String {
        return "ContaCorrente: [${super.toString()}]"
    }
}