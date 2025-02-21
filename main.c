#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

typedef struct
{
    char rua[50];
    int nmr;
    char cidade[30];
    char estado[30];
} End;

typedef struct
{
    char cpf[14];
    char nome[50];
    End endereco;
    Data dt_nasc;
} Cliente;

typedef struct
{
    int cod;
    char descri[50];
    int estoque;
    float vlr_unitario;
} Produto;

typedef struct
{
    int codVenda;
    char cpf_C[14];
    int cod_P;
    int qtd;
} Venda;

int Data_cliente(int dia, int mes, int ano)
{
    int dias_no_mes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
    {
        dias_no_mes[2] = 29;
    }

    if (ano < 1900 || mes < 1 || mes > 12 || dia < 1 || dia > dias_no_mes[mes])
    {
        return 0;
    }

    return 1;
}

void Incluir_cliente(Cliente *clientes, int *numclientes)
{
    Cliente novocliente;

    printf("Digite as informações do novo cliente:\n");
    printf("CPF: ");
    fgets(novocliente.cpf, 14, stdin);
    novocliente.cpf[strcspn(novocliente.cpf, "\n")] = '\0';

    for (int i = 0; i < *numclientes; i++)
    {
        if (strcmp(clientes[i].cpf, novocliente.cpf) == 0)
        {
            printf("\nErro - CPF já cadastrado.\n");
            return;
        }
    }

    printf("Nome: ");
    fgets(novocliente.nome, 50, stdin);
    novocliente.nome[strcspn(novocliente.nome, "\n")] = '\0';

    printf("Rua: ");
    fgets(novocliente.endereco.rua, 50, stdin);
    novocliente.endereco.rua[strcspn(novocliente.endereco.rua, "\n")] = '\0';

    printf("Número: ");
    scanf("%d", &novocliente.endereco.nmr);
    getchar();

    printf("Cidade: ");
    fgets(novocliente.endereco.cidade, 30, stdin);
    novocliente.endereco.cidade[strcspn(novocliente.endereco.cidade, "\n")] = '\0';

    printf("Estado: ");
    fgets(novocliente.endereco.estado, 30, stdin);
    novocliente.endereco.estado[strcspn(novocliente.endereco.estado, "\n")] = '\0';

    printf("Data de nascimento (dia, mes, ano): ");
    scanf("%d %d %d", &novocliente.dt_nasc.dia, &novocliente.dt_nasc.mes, &novocliente.dt_nasc.ano);
    getchar();

    if (!Data_cliente(novocliente.dt_nasc.dia, novocliente.dt_nasc.mes, novocliente.dt_nasc.ano))
    {
        printf("Erro - Data de nascimento inválida.\n");
        return;
    }

    clientes[*numclientes] = novocliente;
    (*numclientes)++;
    printf("Cliente adicionado com sucesso!\n");
}

void Alterar_cliente(Cliente *clientes, int numclientes)
{
    Cliente novoCliente;
    int cliente_encontrado = 0;
    int i;

    printf("Digite o CPF do cliente que deseja alterar: ");
    fgets(novoCliente.cpf, 14, stdin);
    novoCliente.cpf[strcspn(novoCliente.cpf, "\n")] = '\0';

    for (i = 0; i < numclientes && !cliente_encontrado; i++)
    {
        if (strcmp(clientes[i].cpf, novoCliente.cpf) == 0)
        {
            cliente_encontrado = 1;
        }
    }

    if (cliente_encontrado)
    {
        printf("Digite as novas informações do cliente:\n");
        printf("Nome: ");
        fgets(clientes[i - 1].nome, 50, stdin);
        clientes[i - 1].nome[strcspn(clientes[i - 1].nome, "\n")] = '\0';

        printf("Rua: ");
        fgets(clientes[i - 1].endereco.rua, 50, stdin);
        clientes[i - 1].endereco.rua[strcspn(clientes[i - 1].endereco.rua, "\n")] = '\0';

        printf("Número: ");
        scanf("%d", &clientes[i - 1].endereco.nmr);
        getchar();

        printf("Cidade: ");
        fgets(clientes[i - 1].endereco.cidade, 30, stdin);
        clientes[i - 1].endereco.cidade[strcspn(clientes[i - 1].endereco.cidade, "\n")] = '\0';

        printf("Estado: ");
        fgets(clientes[i - 1].endereco.estado, 30, stdin);
        clientes[i - 1].endereco.estado[strcspn(clientes[i - 1].endereco.estado, "\n")] = '\0';

        printf("Data de nascimento (dia, mes, ano): ");
        scanf("%d %d %d", &clientes[i - 1].dt_nasc.dia, &clientes[i - 1].dt_nasc.mes, &clientes[i - 1].dt_nasc.ano);
        getchar();

        if (!Data_cliente(clientes[i - 1].dt_nasc.dia, clientes[i - 1].dt_nasc.mes, clientes[i - 1].dt_nasc.ano))
        {
            printf("Erro - Data de nascimento inválida.\n");
            return;
        }

        printf("\nCliente alterado com sucesso!\n");
    }
    else
    {
        printf("\nErro - Cliente não encontrado.\n");
    }
}

void Consultar_cliente(Cliente *clientes, int numclientes)
{
    char cpf[14];
    int cliente_encontrado = 0;
    int i;

    printf("Digite o CPF do cliente que deseja consultar: ");
    fgets(cpf, 14, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    for (i = 0; i < numclientes && !cliente_encontrado; i++)
    {
        if (strcmp(clientes[i].cpf, cpf) == 0)
        {
            cliente_encontrado = 1;
        }
    }
    if (cliente_encontrado)
    {
        printf("Informações do cliente:\n");
        printf("CPF: %s\n", clientes[i - 1].cpf);
        printf("Nome: %s\n", clientes[i - 1].nome);
        printf("Endereço: %s, %d, %s, %s.\n",
               clientes[i - 1].endereco.rua, clientes[i - 1].endereco.nmr,
               clientes[i - 1].endereco.cidade, clientes[i - 1].endereco.estado);
        printf("Data de nascimento: %02d/%02d/%04d\n",
               clientes[i - 1].dt_nasc.dia, clientes[i - 1].dt_nasc.mes, clientes[i - 1].dt_nasc.ano);
    }
    else
    {
        printf("Erro - Cliente não encontrado.\n");
    }
}

void Excluir_cliente(Cliente *clientes, int *numclientes, Venda *vendas, int numvendas)
{
    char cpf[14];
    int cliente_encontrado = 0;
    int cliente_tem_venda = 0;
    int i, j;

    printf("Digite o CPF do cliente que deseja excluir: ");
    fgets(cpf, 14, stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    for (i = 0; i < numvendas && !cliente_tem_venda; i++)
    {
        if (strcmp(vendas[i].cpf_C, cpf) == 0)
        {
            cliente_tem_venda = 1;
        }
    }

    if (cliente_tem_venda)
    {
        printf("Erro: Cliente está cadastrado em uma venda e não pode ser excluído.\n");
        return;
    }

    for (i = 0; i < *numclientes && !cliente_encontrado; i++)
    {
        if (strcmp(clientes[i].cpf, cpf) == 0)
        {
            cliente_encontrado = 1;
        }
    }

    if (cliente_encontrado)
    {
        for (j = i - 1; j < *numclientes - 1; j++)
        {
            clientes[j] = clientes[j + 1];
        }
        (*numclientes)--;
        printf("Cliente excluído com sucesso!\n");
    }
    else
    {
        printf("Erro: Cliente não encontrado.\n");
    }
}

void Incluir_produto(Produto *produtos, int *numprodutos)
{
    Produto novoProduto;
    printf("Digite as informações do novo produto:\n");
    printf("Código: ");
    scanf("%d", &novoProduto.cod);

    for (int i = 0; i < *numprodutos; i++)
    {
        if (produtos[i].cod == novoProduto.cod)
        {
            printf("\nErro - Código de produto já cadastrado.\n");
            return;
        }
    }

    getchar();
    printf("Descrição: ");
    fgets(novoProduto.descri, 50, stdin);
    novoProduto.descri[strcspn(novoProduto.descri, "\n")] = '\0';

    printf("Estoque: ");
    scanf("%d", &novoProduto.estoque);

    printf("Valor unitário: ");
    scanf("%f", &novoProduto.vlr_unitario);

    produtos[*numprodutos] = novoProduto;
    (*numprodutos)++;
    printf("Produto adicionado com sucesso!\n");
}

void Alterar_produto(Produto *produtos, int numprodutos)
{
    Produto novoProduto;
    int produto_encontrado = 0;
    int i;

    printf("Digite o código do produto que deseja alterar: ");
    scanf("%d", &novoProduto.cod);
    getchar();

    for (i = 0; i < numprodutos && !produto_encontrado; i++)
    {
        if (produtos[i].cod == novoProduto.cod)
        {
            produto_encontrado = 1;
        }
    }
    if (produto_encontrado)
    {
        printf("Produto encontrado! Informe os novos dados:\n");

        printf("Descrição: ");
        fgets(produtos[i - 1].descri, 50, stdin);
        produtos[i - 1].descri[strcspn(produtos[i - 1].descri, "\n")] = '\0';

        printf("Estoque: ");
        scanf("%d", &produtos[i - 1].estoque);
        getchar();

        printf("Valor unitário: ");
        scanf("%f", &produtos[i - 1].vlr_unitario);
        getchar();

        printf("Produto alterado com sucesso!\n");
    }
    else
    {
        printf("Produto com código %d não encontrado.\n", novoProduto.cod);
    }
}

void Consultar_produto(Produto *produtos, int numprodutos)
{
    int cod;
    int produto_encontrado = 0;
    int i;

    printf("Digite o código do produto que deseja consultar: ");
    scanf("%d", &cod);

    for (i = 0; i < numprodutos && !produto_encontrado; i++)
    {
        if (produtos[i].cod == cod)
        {
            produto_encontrado = 1;
        }
    }
    if (produto_encontrado)
    {
        printf("Informações do produto:\n");
        printf("Código: %d\n", produtos[i - 1].cod);
        printf("Descrição: %s\n", produtos[i - 1].descri);
        printf("Estoque: %d\n", produtos[i - 1].estoque);
        printf("Valor unitário: %.2f\n", produtos[i - 1].vlr_unitario);
    }
    else
    {
        printf("Erro - Produto não encontrado.\n");
    }
}

void Excluir_produto(Produto *produtos, Venda *vendas, int *numprodutos, int numVendas)
{
    int cod;
    int produto_encontrado = 0;
    int i;

    printf("Digite o código do produto que deseja excluir: ");
    scanf("%d", &cod);

    for (i = 0; i < *numprodutos && !produto_encontrado; i++)
    {
        if (produtos[i].cod == cod)
        {
            produto_encontrado = 1;
        }
    }

    if (produto_encontrado)
    {
        for (int j = 0; j < numVendas; j++)
        {
            if (vendas[j].cod_P == cod)
            {
                printf("Erro: Produto não pode ser excluído pois está cadastrado em uma venda.\n");
                return;
            }
        }

        for (int j = i - 1; j < *numprodutos - 1; j++)
        {
            produtos[j] = produtos[j + 1];
        }

        (*numprodutos)--;
        printf("Produto excluído com sucesso!\n");
    }
    else
    {
        printf("Erro: Produto não encontrado.\n");
    }
}

void Incluir_venda(Venda *vendas, Produto *produtos, Cliente *clientes, int *numVendas, int numprodutos, int numclientes)
{
    Venda novavenda;
    int produto_encontrado = 0;
    int cliente_encontrado = 0;
    int i = 0;

    printf("Digite as informações da nova venda:\n");
    printf("Código da venda: ");
    scanf("%d", &novavenda.codVenda);

    printf("Código do produto: ");
    scanf("%d", &novavenda.cod_P);

    while (i < numprodutos && !produto_encontrado)
    {
        if (produtos[i].cod == novavenda.cod_P)
        {
            produto_encontrado = 1;
        }
        else
        {
            i++;
        }
    }

    if (!produto_encontrado)
    {
        printf("Erro - Produto não encontrado.\n");
        return;
    }

    getchar();
    printf("CPF do cliente: ");
    fgets(novavenda.cpf_C, 14, stdin);
    novavenda.cpf_C[strcspn(novavenda.cpf_C, "\n")] = '\0';

    i = 0;
    while (i < numclientes && !cliente_encontrado)
    {
        if (strcmp(clientes[i].cpf, novavenda.cpf_C) == 0)
        {
            cliente_encontrado = 1;
        }
        else
        {
            i++;
        }
    }

    if (!cliente_encontrado)
    {
        printf("Erro - Cliente não encontrado.\n");
        return;
    }

    printf("Quantidade: ");
    scanf("%d", &novavenda.qtd);

    i = 0;
    produto_encontrado = 0;
    while (i < numprodutos && !produto_encontrado)
    {
        if (produtos[i].cod == novavenda.cod_P)
        {
            if (produtos[i].estoque >= novavenda.qtd)
            {
                produto_encontrado = 1;
            }
            else
            {
                printf("Erro - Estoque insuficiente para a venda.\n");
                return;
            }
        }
        else
        {
            i++;
        }
    }

    vendas[*numVendas] = novavenda;
    (*numVendas)++;
    printf("Venda adicionada com sucesso!\n");
}

void Alterar_venda(Venda *vendas, Produto *produtos, Cliente *clientes, int numVendas, int numprodutos, int numclientes)
{
    Venda novavenda;
    int venda_encontrada = 0;
    int produto_encontrado = 0;
    int cliente_encontrado = 0;
    int i;

    printf("Digite o código da venda que deseja alterar: ");
    scanf("%d", &novavenda.codVenda);
    getchar();

    for (i = 0; i < numVendas && !venda_encontrada; i++)
    {
        if (vendas[i].codVenda == novavenda.codVenda)
        {
            venda_encontrada = 1;
        }
    }
    if (venda_encontrada)
    {
        printf("Venda encontrada! Informe os novos dados:\n");

        printf("Código do produto: ");
        scanf("%d", &novavenda.cod_P);
        getchar();

        i = 0;
        while (i < numprodutos && !produto_encontrado)
        {
            if (produtos[i].cod == novavenda.cod_P)
            {
                produto_encontrado = 1;
            }
            else
            {
                i++;
            }
        }

        if (!produto_encontrado)
        {
            printf("Erro - Produto não encontrado.\n");
            return;
        }

        printf("CPF do cliente: ");
        fgets(novavenda.cpf_C, 14, stdin);
        novavenda.cpf_C[strcspn(novavenda.cpf_C, "\n")] = '\0';

        i = 0;
        while (i < numclientes && !cliente_encontrado)
        {
            if (strcmp(clientes[i].