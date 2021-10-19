### 1. Explique a semelhança entre um especialista humano e um sistema especialista.
> A semelhança é que os dois tem uma base de conhecimento e tem perícia sobre um determinado assunto específico.

### 2. Esboce a arquitetura de um sistema especialista e descreva o sistema como um todo.
> E necessário uma **base de conhecimento**, ou seja, fatos e dados que é fruto de uma especialidade. Para consumir esses dados, é necessário um **conjunto de regras** para determinar o que deve ser feito. É necessário um **motor de inferência** para poder computar as regras de acordo com as ações. E para cada ação feita, é necessário armazenar as ações em uma **memória de trabalho.**

### 3. (FIEG – SENAI – Faculdade de Tecnologia SENAI de Desenvolvimento Gerencial - FATESG): Leia o texto sobre liberação de crédito e elabore as variáveis de ambiente, os valores para essas variáveis e as regras de produção.

- Uma grande loja do comércio varejista de Goiânia resolve implantar um sistema especializado em liberação de crédito para os seus clientes. 

- O que será avaliado no perfil dos seus clientes é o valor da compra, se ele possui e qual o valor da sua renda. As faixas a serem analisadas são: Menos de um salário mínimo, entre 1 e 5 salários, entre 6 e 10 salários e mais de 10 salários. 

- Outro fator a ser analisado é se o cliente está cadastrado no Serviço de Proteção ao Crédito – SPC. 

- Outro grande fator que influenciará na tomada de decisão é a faixa etária do cliente– se é maior de idade, se está na faixa produtiva (18 à 60 anos) ou se é aposentado. 

- O sistema ainda avalia a quantidade de compras que o cliente já fez na loja, se ele possui alguma compra em atraso com a loja e caso ele tenha algum acordo com a loja por compras anteriores não quitadas. 
  
- Caso ele possua alguma compra em atraso o sistema avalia se está na faixa entre 30 e 45 dias de atraso. No caso de compras em atraso por mais de 90 dias o sistema não libera o crédito. 

- No caso de acordos feitos com a loja, o sistema avalia se eles estão em dias com os pagamentos ou se estão atrasados. No caso de acordos que estão em atraso o sistema não libera o crédito. 

- Caso o cliente tenha mais de 1 compra feita na loja, mesmo se ele tenha algum acordo para pagamento com atraso entre 30 e 45 dias o sistema libera o crédito com um fator de confiança de 60%. 

- Caso a pessoa seja menor de idade, o sistema só libera compras com valores inferiores a R$300,00 Para pessoas com o cadastro no SPC, o sistema só libera o crédito caso ela seja maior de idade, com renda entre 5 e 10 salários e com mais de 5 compras na loja, mas ela não pode ter nenhum tipo de acordo e nenhuma compra atrasada na loja. 

- Caso a pessoa não tenha feito nenhuma compra na loja, o sistema libera o crédito somente nos casos dela não esteja no SPC e ela tenha renda compatível. 

- Em nenhuma compra o valor do crédito poderá ser superior à 30% da renda do cliente.


### 4. Elabore um Sistema Especialista (quatro regras) capaz de determinar, com base na conjuntura atual, qual a forma de se deslocar do Campus A para o Campus B do IESB. O primeiro passo é extrair o conhecimento de um especialista. Considere que o conjunto de informações fornecido pelo mesmo foi o seguinte:
1. Existem duas opções de travessia: barquinho ou carro.
2. Dois fatores são predominantes tempo e conforto.
3. Quando o tempo é mais relevante que o conforto é feita a opção pela travessia com a barquinho.
4. Quando o conforto é mais relevante que o tempo é feita a opção pela travessia com o carro.
5. A travessia da ponte com um carro dura em média uma hora.
6. A travessia com barquinho dura em média quinze minutos.
7. O tempo é relevante quando se chega ao destino menos de onze minutos antes do compromisso.
8. 
