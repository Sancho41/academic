(function () {
    "use strict";

    angular.module('autoLocadoraApp')
        .service('clientesService', clientesService);

    clientesService.$inject = ['$http', 'constantes', 'helperFactory'];

    function clientesService($http, constantes, helper) {

        return {
            listar: listar
        }

        // ======================================

        function listar() {
            return $http.get(constantes.URL_BASE + '/cliente')
                .then(function (response) {
                    return response.data;
                })
                .catch(helper.sendError);
        }

    }


})();
