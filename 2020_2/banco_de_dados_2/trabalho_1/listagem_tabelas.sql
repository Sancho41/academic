SELECT * FROM locadora.cliente;

SELECT * FROM locadora.filme;

SELECT * FROM locadora.atores;

SELECT * FROM locadora.filme_atores;

SELECT filme.*, atores.* FROM locadora.filme as filme
INNER JOIN locadora.filme_atores as fa on filme.codigo = fa.codigo_filme
INNER JOIN locadora.atores as atores on atores.codigo = fa.codigo_ator

SELECT * FROM locadora.fita;

SELECT filme.*, COUNT(fita.codigo_filme) as "Quantidade de fitas" FROM locadora.fita as fita
INNER JOIN locadora.filme as filme on fita.codigo_filme = filme.codigo
GROUP BY filme.codigo;

SELECT * FROM lodacora.alugueis;

SELECT cliente.nome FROM locadora.cliente as cliente
INNER JOIN locadora.alugueis as alugueis on alugueis.codigo_cliente = cliente.codigo
GROUP BY cliente.nome

SELECT cliente.nome, COUNT(cliente.nome) as "Quantidade de alocações" FROM locadora.cliente as cliente
INNER JOIN locadora.alugueis as alugueis on alugueis.codigo_cliente = cliente.codigo
GROUP BY cliente.codigo

SELECT * FROM locadora.atores as atores
WHERE atores.nome LIKE 'A%'

DELETE FROM locadora.atores as atores WHERE atores.codigo = 3