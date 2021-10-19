package br.com.stefanini.maratonadev.rest;

import br.com.stefanini.maratonadev.dto.CarroDto;
import br.com.stefanini.maratonadev.dto.ClienteDto;
import br.com.stefanini.maratonadev.service.ClienteService;
import org.eclipse.microprofile.openapi.annotations.Operation;
import org.eclipse.microprofile.openapi.annotations.media.Content;
import org.eclipse.microprofile.openapi.annotations.media.Schema;
import org.eclipse.microprofile.openapi.annotations.responses.APIResponse;

import javax.inject.Inject;
import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

@Path("cliente")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class ClienteRest {

    @Inject
    ClienteService service;

    @POST
    @Operation(summary = "Cadastrar Cliente")
    @APIResponse(responseCode = "201",
            description = "cliente",
            content = {
                    @Content(mediaType =  "application/json",
                            schema = @Schema(implementation = ClienteDto.class))
            }
    )
    public Response cadastrar(ClienteDto clienteDto) {
        return Response
                .status(Response.Status.CREATED)
                .entity(service.cadastrar(clienteDto))
                .build();
    }

    @GET
    @Operation(summary = "Listar Clientes",
            description = "Lista de clientes")
    @APIResponse(responseCode = "200",
            description = "cliente",
            content = {
                    @Content(mediaType =  "application/json",
                            schema = @Schema(implementation = ClienteDto.class))
            }
    )
    public Response listar(){
        return Response
                .status(Response.Status.OK)
                .entity(service.listar())
                .build();
    }

}
