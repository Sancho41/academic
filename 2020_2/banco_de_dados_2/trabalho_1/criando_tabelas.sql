CREATE TABLE locadora.cliente (
	codigo SERIAL NOT NULL PRIMARY KEY,
	nome character varying(255) NOT NULL,
	endereco character varying(255) NOT NULL,
	telefone character varying(255) NOT NULL
);


CREATE TABLE locadora.filme (
	codigo SERIAL NOT NULL PRIMARY KEY,
	categoria character varying(255) NOT NULL,
	titulo character varying(255) NOT NULL
);


CREATE TABLE locadora.atores (
	codigo SERIAL NOT NULL PRIMARY KEY,
	nome character varying(255) NOT NULL,
	data_nascimento date NOT NULL
);


CREATE TABLE locadora.fita (
	codigo SERIAL NOT NULL PRIMARY KEY,
	codigo_filme integer NOT NULL
);

ALTER TABLE 
	locadora.fita 
ADD CONSTRAINT fk_filme FOREIGN KEY (codigo_filme) REFERENCES locadora.filme (codigo);



CREATE TABLE locadora.alugueis (
	codigo SERIAL NOT NULL PRIMARY KEY,
	codigo_fita integer NOT NULL,
	codigo_cliente integer NOT NULL,
	devolvido boolean NOT NULL,
	data_devolucao date
);

ALTER TABLE locadora.alugueis
	ADD CONSTRAINT fk_fita FOREIGN KEY (codigo_fita) REFERENCES locadora.fita (codigo),
	ADD CONSTRAINT fk_cliente FOREIGN KEY (codigo_cliente) REFERENCES locadora.cliente (codigo),
	ALTER COLUMN devolvido set default false;
	

CREATE TABLE locadora.filme_atores ( 
	codigo_filme integer NOT NULL,
	codigo_ator integer NOT NULL,
	CONSTRAINT fk_filme FOREIGN KEY (codigo_filme) REFERENCES locadora.filme (codigo),
	CONSTRAINT fk_atores FOREIGN KEY (codigo_ator) REFERENCES locadora.atores (codigo),
	CONSTRAINT filme_atores_pkey PRIMARY KEY (codigo_filme, codigo_ator)
);
