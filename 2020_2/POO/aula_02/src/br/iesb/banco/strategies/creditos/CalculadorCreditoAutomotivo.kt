package br.iesb.banco.strategies.creditos

import br.iesb.banco.interfaces.ICalculadorCredito
import br.iesb.banco.models.conta.Conta

/**
 * Estratégia para calculo para crédito automotivo
 */
class CalculadorCreditoAutomotivo: ICalculadorCredito {
    /**
     * @param conta: Conta
     * @return Double
     */
    override fun calcularCredito(conta: Conta): Double {
        return conta.getSaldo() * 10
    }
}