package br.com.stefanini.maratonadev.rest;

import br.com.stefanini.maratonadev.dto.AluguelDto;
import br.com.stefanini.maratonadev.dto.FinalizarAluguelDto;
import br.com.stefanini.maratonadev.dto.SoliciarAluguelDto;
import br.com.stefanini.maratonadev.service.AluguelService;
import org.eclipse.microprofile.openapi.annotations.Operation;
import org.eclipse.microprofile.openapi.annotations.media.Content;
import org.eclipse.microprofile.openapi.annotations.media.Schema;
import org.eclipse.microprofile.openapi.annotations.responses.APIResponse;

import javax.inject.Inject;
import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;

@Path("aluguel")
@Consumes(MediaType.APPLICATION_JSON)
@Produces(MediaType.APPLICATION_JSON)
public class AluguelRest {
    @Inject
    AluguelService service;

    @POST
    @Operation(summary = "Solicitar um aluguel",
            description = "Solicitar um aluguel")
    @APIResponse(responseCode = "201",
            description = "aluguel",
            content = {
                    @Content(mediaType =  "application/json",
                            schema = @Schema(implementation = AluguelDto.class))
            }
    )
    public Response solicitarAluguel(SoliciarAluguelDto soliciarAluguelDto) {
        try {
            return Response
                    .status(Response.Status.CREATED)
                    .entity(service.solicitarAluguel(soliciarAluguelDto))
                    .build();
        } catch (Exception e) {
            e.printStackTrace();
            return Response.status(Response.Status.FORBIDDEN).build();
        }
    }

    @GET
    @Operation(summary = "Listar Alugueis",
            description = "Lista de alugueis")
    @APIResponse(responseCode = "200",
            description = "aluguel",
            content = {
                    @Content(mediaType =  "application/json",
                            schema = @Schema(implementation = AluguelDto.class))
            }
    )
    public Response listar() {
        return Response
                .status(Response.Status.OK)
                .entity(service.listar())
                .build();
    }

    @POST
    @Operation(summary = "Finaliza um aluguel",
            description = "Finaliza um alguel")
    @APIResponse(responseCode = "200",
            description = "aluguel",
            content = {
                    @Content(mediaType =  "application/json",
                            schema = @Schema(implementation = AluguelDto.class))
            }
    )
    @Path("/finalizar")
    public Response finalizarAluguel(FinalizarAluguelDto finalizarAluguelDto) {
        return Response
                .status(Response.Status.OK)
                .entity(service.finalizar(finalizarAluguelDto))
                .build();
    }
}
