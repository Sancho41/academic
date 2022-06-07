package br.iesb.banco

import br.iesb.banco.models.conta.ContaCorrente
import br.iesb.banco.models.conta.ContaPoupanca
import br.iesb.banco.strategies.creditos.CalculadorCreditoAutomotivo
import br.iesb.banco.strategies.creditos.CalculadorCreditoEmpresarial
import br.iesb.banco.models.pessoa.PessoaFisica
import br.iesb.banco.models.pessoa.PessoaJuridica
/**
 * Exercício dia 27/08/2020
 *
 * Professor, já deixando claro que não entendo muito bem sobre
 * regras de negócios de bancos, então fiz a implementação de como
 * eu imagino que seja, podendo não condizer com a realidade.
 *
 * @author Gabriel Sancho - 1712130049
 * */
fun main() {

    // Intancia as pessoa1, pessoa2 e a pessoa3 como pessoa Física
    val pessoa1 = PessoaFisica(
        "Riacho Fundo",
        "Gabriel",
        "111.333.444.555-54",
        "30/08/1998"
    )

    val pessoa2 = PessoaFisica(
        "Riacho Fundo",
        "Daniel",
        "111.333.444.555-54",
        "05/06/2005"
    )

    val pessoa3 = PessoaFisica(
        "Riacho Fundo",
        "Silvio",
        "111.333.444.555-54",
        "06/03/1970"
    )

    // Instancia a empresa1 como uma pessoa Jurídica
    val empresa1 = PessoaJuridica(
        "Asa Sul",
        "Games Do Sancho",
        "111.333.444.555-54",
        "Sancho LTDA",
        "127893712"
    )

    // Cria uma conta poupança para a pessoa1
    val cp1 = ContaPoupanca(
        "1111",
        1111,
        pessoa1
    )

    // Adiciona pessoas como dependentes na conta poupança da pessoa1
    cp1.adicionarDependente(pessoa2)
    cp1.adicionarDependente(pessoa3)

    println(cp1)

    // Cria uma conta corrente para empresa 1
    val cc1 = ContaCorrente(
        "2222",
        2222,
        empresa1
    )

    // Deposita 100.0 na conta poupança da pessoa1 e logo após faz o saque 50.0
    cp1.depositar(100.0)
    println("Depois de depositar 100.0 Conta Poupanca: " + cp1.getSaldo())

    cp1.sacar(50.0)
    println("Depois de sacar 50.0 Conta Poupanca: " + cp1.getSaldo())

    cp1.render()
    println("Depois de aplicar rendimento Conta Poupanca: " + cp1.getSaldo())

    // Deposita 100.0 na conta corrente da empresa1 e logo após faz o saque de 50.0
    // Note que na conta corrente existe uma taxa para saque
    cc1.depositar(100.0)
    println("Depois de depositar 100.0 Conta Corrente: " + cc1.getSaldo())

    cc1.sacar(50.0)
    println("Depois de sacar 50.0 Conta Corrente: " + cc1.getSaldo())

    // Transfere 20 reais de uma conta para outra
    cc1.transfere(20.0, cp1)
    println("Depois de transferir 20.0 [cc1 -> cp1]: ${cc1.getSaldo()} ${cp1.getSaldo()}")

    // Faz calculos de liberação de crédito para as respectivas contas, utilizando strategies
    println("Credito Automotivo para cp1: ${cp1.calcularCredito(CalculadorCreditoAutomotivo())}")
    println("Credito Empresarial para cc1: ${cc1.calcularCredito(CalculadorCreditoEmpresarial())}")

}