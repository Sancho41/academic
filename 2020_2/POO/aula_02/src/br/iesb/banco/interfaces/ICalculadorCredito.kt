package br.iesb.banco.interfaces

import br.iesb.banco.models.conta.Conta

/**
 * Strategy base para a calculadora de créditos
 */
interface ICalculadorCredito {
    fun calcularCredito(conta: Conta): Double
}