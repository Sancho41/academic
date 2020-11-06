(function () {
    "use strict";

    angular.module('autoLocadoraApp')
        .service('novoClienteService', novoClienteService);

    novoClienteService.$inject = ['$http', 'constantes', 'helperFactory'];

    function novoClienteService($http, constantes, helper) {

        return {
            salvar
        }

        // ======================================

        function salvar(cliente) {
            return $http.post(constantes.URL_BASE + '/cliente', JSON.stringify(cliente), {headers: {'Content-Type': 'application/json'} })
                .then(function (response) {
                    return response.data;
                })
                .catch(helper.sendError);
        }

    }


})();
