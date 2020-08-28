package br.iesb.banco.strategies.creditos

import br.iesb.banco.interfaces.ICalculadorCredito
import br.iesb.banco.models.conta.Conta
import br.iesb.banco.models.pessoa.PessoaFisica

/**
 * Estrategia para calculo de crédito empresarial
 */
class CalculadorCreditoEmpresarial : ICalculadorCredito {

    /**
     * Verifica o tipo de conta, se não for aplicavel é gerado um erro.
     *
     * @param conta: Conta
     * @throws Error("O Crédito empresarial não é permitido para Pessoa Física.")
     * @return Double
     */
    override fun calcularCredito(conta: Conta): Double {
        val cliente = conta.getCliente()
        if (cliente is PessoaFisica)
            throw Error("O Crédito empresarial não é permitido para Pessoa Física.")
        return conta.getSaldo() * 20
    }
}