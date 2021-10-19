(function () {
    "use strict";

    angular.module('autoLocadoraApp')
        .controller('NovoClienteController', novoClienteController);

    novoClienteController.$inject = ['helperFactory', 'novoClienteService'];

    function novoClienteController(helper, service) {
        var vm = this;
        /* ***************    INIT VARIÁVEIS    *********************************** */

        vm.novoCliente = {
            cpf:"",
            nome:"",
            cep:"",
            logradouro:"",
            complemento:"",
            bairro:"",
            cidade:"",
            uf:"",
            email:"",
            contato:"",
        }

        /* ***************    FUNÇÕES EXECUTADAS NA VIEW (HMTL)    **************** */
        vm.go = helper.go;
        vm.iniciar = iniciar;

        function iniciar() {
            vm.go();
        }
        /* ***************    FUNÇÕES INSTERNAS    ******************************** */


        vm.salvar = salvar;
        async function salvar(cliente) {
            try {
                const teste = await service.salvar(cliente);
                console.log({teste});
                alert("Cliente salvo com sucesso!");
                vm.go("/home");
            } catch (error) {
                alert("Não foi possível salvar o cliente!")
            }
        }
    }

})();