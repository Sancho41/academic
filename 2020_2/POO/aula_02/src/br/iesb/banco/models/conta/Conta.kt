package br.iesb.banco.models.conta

import br.iesb.banco.interfaces.ICalculadorCredito
import br.iesb.banco.models.pessoa.Pessoa

/**
 * Conta base como classe abstrata, pois não será possível criar uma conta
 * de tipo genérico, somente contas correntes ou contas poupanças
 *
 * Alguns atributos não possuem setters (Inicializados nos construtores) uma vez
 * que acredito que esses dados não possam ser alterados após serem definidos.
 */
abstract class Conta(
    private val agencia: String,
    private val numero: Number,
    private var cliente: Pessoa,
) {
    private var saldo: Double = 0.0; // Inicializa o saldo da conta
    private val dependentes: MutableList<Pessoa> = arrayListOf()

    /**
     * Saca um valor da conta
     *
     * @param valor: Double
     * @throws Error("Saldo Insuficiente")
     */
    open fun sacar(valor: Double) {
        if (valor <= this.saldo) this.saldo -= valor
        else throw Error("Saldo Insuficiente")
    }

    /**
     * Transfere um valor de uma conta para outra
     *
     * @param valor: Double
     * @param destino: Conta
     * @throws Error("Saldo Insuficiente")
     */
    fun transfere(valor: Double, destino: Conta) {
        this.sacar(valor)
        destino.depositar(valor)
    }

    /**
     * Deposita um valor no saldo da conta
     *
     * @param valor: Double
     */
    fun depositar(valor: Double) {
        this.saldo += valor
    }

    /**
     * Recupera o saldo da conta
     *
     * @return Double
     */
    fun getSaldo(): Double {
        return this.saldo
    }

    /**
     * Recupera a agencia da conta
     *
     * @return String
     */
    fun getAgencia(): String {
        return this.agencia
    }

    /**
     * Recupera o número da conta
     *
     * @return Number
     */
    fun getNumero(): Number {
        return this.numero
    }

    /**
     * Recupera o cliente da conta
     *
     * @return Pessoa
     */
    fun getCliente(): Pessoa {
        return this.cliente
    }

    /**
     * Adiciona um novo dependente na conta
     *
     * @param dependente: Pessoa
     */
    fun adicionarDependente(dependente: Pessoa) {
        this.dependentes.add(dependente)
    }

    /**
     * Remove um dependente da conta
     *
     * @param dependente: Pessoa
     */
    fun removerDependente(dependente: Pessoa) {
        this.dependentes.remove(dependente)
    }

    /**
     * Calcula o crédito de acordo com a estratégia de calculo fornecida
     *
     * @param calculador: ICalculadorCredito
     * @return Double
     */
    fun calcularCredito(calculador: ICalculadorCredito): Double {
        return calculador.calcularCredito(this)
    }

    override fun toString(): String {
        return "Cliente: ${this.cliente}; " +
                "Número: ${this.numero}; " +
                "Agência: ${this.agencia}; " +
                "Saldo: ${this.saldo}; " +
                "Dependentes: ${this.dependentes}"
    }
}
