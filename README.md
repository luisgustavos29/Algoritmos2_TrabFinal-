# Trabalho Final de Algoritmos II

# Sistema de Gerenciamento de Clientes, Produtos e Vendas

Este projeto foi desenvolvido para a matéria de Algoritmos II do segundo período do curso de Sistemas de Informação da UFU. O sistema tem como objetivo gerenciar clientes, produtos e vendas utilizando a linguagem de programação C.

## Funcionalidades

### Clientes

- **Incluir Cliente**: Permite a inclusão de um novo cliente no sistema.
- **Alterar Cliente**: Permite a alteração dos dados de um cliente já cadastrado.
- **Consultar Cliente**: Permite a consulta dos dados de um cliente por meio do CPF.
- **Excluir Cliente**: Permite a exclusão de um cliente, desde que ele não esteja associado a nenhuma venda.

### Produtos

- **Incluir Produto**: Permite a inclusão de um novo produto no sistema.
- **Alterar Produto**: Permite a alteração dos dados de um produto já cadastrado.
- **Consultar Produto**: Permite a consulta dos dados de um produto por meio do código.
- **Excluir Produto**: Permite a exclusão de um produto, desde que ele não esteja associado a nenhuma venda.

### Vendas

- **Incluir Venda**: Permite a inclusão de uma nova venda no sistema.
- **Alterar Venda**: Permite a alteração dos dados de uma venda já cadastrada.

## Estruturas de Dados

O sistema utiliza as seguintes estruturas de dados:

- **Data**: Representa uma data com dia, mês e ano.
- **End**: Representa um endereço com rua, número, cidade e estado.
- **Cliente**: Representa um cliente com CPF, nome, endereço e data de nascimento.
- **Produto**: Representa um produto com código, descrição, quantidade em estoque e valor unitário.
- **Venda**: Representa uma venda com código da venda, CPF do cliente, código do produto e quantidade vendida.

## Funções

### Clientes

- `int Data_cliente(int dia, int mes, int ano)`: Verifica se uma data é válida.
- `void Incluir_cliente(Cliente *clientes, int *numclientes)`: Inclui um novo cliente.
- `void Alterar_cliente(Cliente *clientes, int numclientes)`: Altera os dados de um cliente.
- `void Consultar_cliente(Cliente *clientes, int numclientes)`: Consulta os dados de um cliente.
- `void Excluir_cliente(Cliente *clientes, int *numclientes, Venda *vendas, int numvendas)`: Exclui um cliente.

### Produtos

- `void Incluir_produto(Produto *produtos, int *numprodutos)`: Inclui um novo produto.
- `void Alterar_produto(Produto *produtos, int numprodutos)`: Altera os dados de um produto.
- `void Consultar_produto(Produto *produtos, int numprodutos)`: Consulta os dados de um produto.
- `void Excluir_produto(Produto *produtos, Venda *vendas, int *numprodutos, int numVendas)`: Exclui um produto.

### Vendas

- `void Incluir_venda(Venda *vendas, Produto *produtos, Cliente *clientes, int *numVendas, int numprodutos, int numclientes)`: Inclui uma nova venda.
- `void Alterar_venda(Venda *vendas, Produto *produtos, Cliente *clientes, int numVendas, int numprodutos, int numclientes)`: Altera os dados de uma venda.

## Como Executar

1. Compile o código fonte utilizando um compilador C (ex: GCC).
2. Execute o arquivo binário gerado.

## Exemplo de Compilação e Execução

```sh
gcc -o sistema main.c
./sistema
```

## Considerações Finais

Este projeto foi desenvolvido com o intuito de aplicar os conceitos aprendidos na disciplina de Algoritmos II. Sinta-se à vontade para contribuir com melhorias e novas funcionalidades.
