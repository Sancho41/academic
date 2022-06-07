(function () {
    "use strict";

    angular.module('autoLocadoraApp')
        .controller('ClientesController', clientesController);

    clientesController.$inject = ['helperFactory', 'clientesService'];

    function clientesController(helper, service) {
        var vm = this;
        /* ***************    INIT VARIÁVEIS    *********************************** */

        /* ***************    FUNÇÕES EXECUTADAS NA VIEW (HMTL)    **************** */
        vm.go = helper.go;
        vm.iniciar = iniciar;

        function iniciar() {
            return  vm.listarClientes();
        }

        vm.listarClientes = listarClientes;

        function listarClientes() {
            return service.listar()
                .then(function (_listaClientes) {
                    vm.listaClientes = _listaClientes;
                    helper.rootScopeApply();
                });
        }

        /* ***************    FUNÇÕES INSTERNAS    ******************************** */


    }

})();