INSERT INTO locadora.cliente (nome, endereco, telefone) VALUES ('Sancho', 'Riacho Fundo', '0');
INSERT INTO locadora.cliente (nome, endereco, telefone) VALUES ('Isa', 'Asa Sul', '1');
INSERT INTO locadora.cliente (nome, endereco, telefone) VALUES ('Garibel', 'Vizin da isa', '2');
INSERT INTO locadora.cliente (nome, endereco, telefone) VALUES ('Luizin', 'Far Far Away', '3');
INSERT INTO locadora.cliente (nome, endereco, telefone) VALUES ('PDQ', 'Guará', '4');
---

INSERT INTO locadora.filme (categoria, titulo) VALUES ('Action', 'Django');
INSERT INTO locadora.filme (categoria, titulo) VALUES ('Action', 'Pulp Fiction');
INSERT INTO locadora.filme (categoria, titulo) VALUES ('Fantasy', 'Star Wars');
INSERT INTO locadora.filme (categoria, titulo) VALUES ('History', 'Imitation Game');
INSERT INTO locadora.filme (categoria, titulo) VALUES ('Fantasy', 'Harry Potter');
---

INSERT INTO locadora.atores (nome, data_nascimento) VALUES ('Seninho', '1999-11-05');
INSERT INTO locadora.atores (nome, data_nascimento) VALUES ('Ponita', '2001-05-03');
INSERT INTO locadora.atores (nome, data_nascimento) VALUES ('Sandro', '1998-08-30');
INSERT INTO locadora.atores (nome, data_nascimento) VALUES ('SpZ', '1999-11-04');
INSERT INTO locadora.atores (nome, data_nascimento) VALUES ('Chesse Bread', '1999-11-06');
---

INSERT INTO locadora.filme_atores (codigo_filme, codigo_ator) VALUES (1, 5);
INSERT INTO locadora.filme_atores (codigo_filme, codigo_ator) VALUES (2, 3);
INSERT INTO locadora.filme_atores (codigo_filme, codigo_ator) VALUES (3, 4);
INSERT INTO locadora.filme_atores (codigo_filme, codigo_ator) VALUES (4, 2);
INSERT INTO locadora.filme_atores (codigo_filme, codigo_ator) VALUES (5, 1);
INSERT INTO locadora.filme_atores (codigo_filme, codigo_ator) VALUES (3, 5);
INSERT INTO locadora.filme_atores (codigo_filme, codigo_ator) VALUES (2, 5);
INSERT INTO locadora.filme_atores (codigo_filme, codigo_ator) VALUES (3, 1);
---

INSERT INTO locadora.fita (codigo_filme) VALUES (1);
INSERT INTO locadora.fita (codigo_filme) VALUES (1);
INSERT INTO locadora.fita (codigo_filme) VALUES (1);
INSERT INTO locadora.fita (codigo_filme) VALUES (2);
INSERT INTO locadora.fita (codigo_filme) VALUES (2);
INSERT INTO locadora.fita (codigo_filme) VALUES (2);
INSERT INTO locadora.fita (codigo_filme) VALUES (3);
INSERT INTO locadora.fita (codigo_filme) VALUES (3);
INSERT INTO locadora.fita (codigo_filme) VALUES (3);
INSERT INTO locadora.fita (codigo_filme) VALUES (4);
INSERT INTO locadora.fita (codigo_filme) VALUES (4);
INSERT INTO locadora.fita (codigo_filme) VALUES (4);
INSERT INTO locadora.fita (codigo_filme) VALUES (5);
INSERT INTO locadora.fita (codigo_filme) VALUES (5);
INSERT INTO locadora.fita (codigo_filme) VALUES (5);
---

INSERT INTO locadora.alugueis (codigo_fita, codigo_cliente, devolvido, data_devolucao) VALUES (1,1,false,NULL);
INSERT INTO locadora.alugueis (codigo_fita, codigo_cliente, devolvido, data_devolucao) VALUES (2,4,true,'1998-01-12');
INSERT INTO locadora.alugueis (codigo_fita, codigo_cliente, devolvido, data_devolucao) VALUES (7,5,false,NULL);
INSERT INTO locadora.alugueis (codigo_fita, codigo_cliente, devolvido, data_devolucao) VALUES (12,4,false,NULL);
INSERT INTO locadora.alugueis (codigo_fita, codigo_cliente, devolvido, data_devolucao) VALUES (15,2,true,'2020-10-03');
INSERT INTO locadora.alugueis (codigo_fita, codigo_cliente, devolvido, data_devolucao) VALUES (1,5,false,NULL);
INSERT INTO locadora.alugueis (codigo_fita, codigo_cliente, devolvido, data_devolucao) VALUES (2,4,true,'1998-01-12');
INSERT INTO locadora.alugueis (codigo_fita, codigo_cliente, devolvido, data_devolucao) VALUES (7,3,false,NULL);
INSERT INTO locadora.alugueis (codigo_fita, codigo_cliente, devolvido, data_devolucao) VALUES (12,2,false,NULL);
INSERT INTO locadora.alugueis (codigo_fita, codigo_cliente, devolvido, data_devolucao) VALUES (15,1,true,'2020-10-03');
