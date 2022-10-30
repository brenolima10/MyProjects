#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

void menu();              //
void cadastro();          //
void login();             //
void verificar(char[30]); //
void login();             //
void pagamento();         // Carregando todas a funções na memória
void cardapio();          //
void addCarrinho();       //
void imprimirCarrinho();  //
void removerCarrinho();   //
void gerirCarrinho();     //

typedef struct Carrinho carrinho;
struct Carrinho // Detalhes do produto
{
    int preco;
    int quant;
    int cod;
    char prod[25];
    carrinho *ant;
    carrinho *prox;
};

carrinho *inicio = NULL;
carrinho *fim = NULL;
int tam = 0, total = 0;

void menu()
{
    int op;
    system("cls");
    printf("============================================================\n");
    printf("=============== T A K E I T I  S U S H I ===================\n");
    printf("============================================================\n");
    printf("============================================================\n");
    printf("=================== 1 - Login  =============================\n");
    printf("=================== 2 - Cadastro ===========================\n");
    printf("============================================================\n");
    printf("=================== 3 - Cardapio ===========================\n");
    printf("============================================================\n");
    printf("=================== 4 - Sair ===============================\n");
    printf("============================================================\n");
    printf("============================================================\n");
    printf("=================== Grupo 0 - UFC ==========================\n");
    printf("============================================================\n");
    printf("-->");
    scanf("%d", &op);

    switch (op)
    {

    case 1:
        system("cls");
        login();
        break;
    case 2:
        system("cls");
        cadastro();
        break;
    case 3:
        system("cls");
        printf("\n");
        printf("----------------------------------------- \n");
        printf("|               Cardapio                | \n");
        printf("|                                       | \n");
        printf("| Hossomaki - 10 pecas                  | \n");
        printf("| Kani                  R$ 17,00        | \n");
        printf("| Salmao                R$ 17,00        | \n");
        printf("| Camarao               R$ 18,00        | \n");
        printf("|                                       | \n");
        printf("| Hot Roll - 10 pecas                   | \n");
        printf("| Kani                  R$ 17,00        | \n");
        printf("| Salmao                R$ 17,00        | \n");
        printf("| Camarao               R$ 18,00        | \n");
        printf("|                                       | \n");
        printf("| Temaki Tradicional - 10 pecas         | \n");
        printf("| Kani                  R$ 17,00        | \n");
        printf("| Salmao                R$ 17,00        | \n");
        printf("| Camarao               R$ 18,00        | \n");
        printf("|                                       | \n");
        printf("| Bebidas                               | \n");
        printf("| Agua                  R$ 2,00         | \n");
        printf("| Suco Copo             R$ 3,00         | \n");
        printf("| Cerveja Lata          R$ 4,00         | \n");
        printf("| Refrigerante Lata     R$ 2,00         | \n");
        printf("----------------------------------------- \n");
        fflush(stdin);
        getchar();
        system("cls");
        menu();
    case 4:
        break;
    default:
        printf("\n\nOpcao Invalida.\n\n");
        fflush(stdin);
        getchar();
        menu();
    }
}

void login()
{ // chamar os dados salvos no txt

    char email[20], senha[20];

    printf("Email: ");
    scanf("%s", email);

    printf("Senha: ");
    scanf("%s", senha);

    verificar(email);

}

void cadastro()
{

    setlocale(LC_ALL, "portuguese");

    FILE *p;

    char nome[50], email[50], senha[50], data[10], c;
    int cpf, numero, i;

    p = fopen("Dados_Clientes.txt", "a");

    fflush(stdin);

    printf("Nome: ");
    scanf("%[^\n]s", nome);

    fflush(stdin);

    printf("Data de nascimento (dd/mm/aa): ");
    scanf("%[^\n]s", data);

    printf("Email: ");
    scanf("%s", email);

    printf("Senha: ");
    scanf("%s", senha);

    printf("CPF: ");
    scanf("%d", &cpf);

    fprintf(p, "Nome do cliente: %s\n", nome);
    fprintf(p, "Data de nascimento: %s\n", data);
    fprintf(p, "Email: %s\n", email);
    fprintf(p, "Senha: %s\n", senha);
    fprintf(p, "CPF: %d\n\n", cpf);
    fclose(p);
    printf("Cadastro realizado com sucesso!\n");

    printf("\nPressione qualquer tecla para retornar o menu principal...\n");
    fflush(stdin);
    getchar();
    system("cls");
    menu();
}

void verificar(char email[30])
{

    FILE *p;

    char str[30], v_comp[30], x, y;
    int i, c;

    p = fopen("Dados_Clientes.txt", "r");

    if (p == NULL)
    {
        printf("Erro ao abrir arquivo!\n");
    }

    while (fscanf(p, "%s %s", &str, &v_comp) != EOF)
    {

        printf("%s ", v_comp);

        if (strstr(v_comp, email) != NULL)
        {
            x++;
        }
        else
        {
            y++;
        }
    }

    if (x == 1)
    {
        system("cls");
        printf("<*> Login efetuado com sucesso! <*>\n");
        printf("\nPressione qualquer tecla para realizar seus pedidos...\n");
        fflush(stdin);
        getchar();
        system("cls");
        cardapio();
    }
    else
    {
        system("cls");
        printf("<!> Usuario nao cadastrado! <!>\n");
        printf("\nPressione qualquer tecla para retornar ao menu principal...\n");
        fflush(stdin);
        getchar();
        system("cls");
        menu();
    }
    fclose(p);
}

void cardapio()
{

    int quant, soma;
    int op;
    do
    {
        system("cls");
        printf("----------------------------------------- \n");
        printf("|      Bem vindo ao Takeiti Sushi!      | \n");
        printf("----------------------------------------- \n");
        printf("\n");
        printf("----------------------------------------- \n");
        printf("|               Cardapio                | \n");
        printf("|                                       | \n");
        printf("| Hossomaki - 10 pecas                  | \n");
        printf("| 1-Kani                  R$ 17,00      | \n");
        printf("| 2-Salmao                R$ 17,00      | \n");
        printf("| 3-Camarao               R$ 18,00      | \n");
        printf("|                                       | \n");
        printf("| Hot Roll - 10 pecas                   | \n");
        printf("| 4-Kani                  R$ 17,00      | \n");
        printf("| 5-Salmao                R$ 17,00      | \n");
        printf("| 6-Camarao               R$ 18,00      | \n");
        printf("|                                       | \n");
        printf("| Temaki Tradicional - 10 pecas         | \n");
        printf("| 7-Kani                  R$ 17,00      | \n");
        printf("| 8-Salmao                R$ 17,00      | \n");
        printf("| 9-Camarao               R$ 18,00      | \n");
        printf("|                                       | \n");
        printf("| Bebidas                               | \n");
        printf("| 10-Agua                  R$ 2,00      | \n");
        printf("| 11-Suco Copo             R$ 3,00      | \n");
        printf("| 12-Cerveja Lata          R$ 4,00      | \n");
        printf("| 13-Refrigerante Lata     R$ 2,00      | \n");
        printf("----------------------------------------- \n");
        printf("Digite o codigo do produto ou digite 0 para finalizar o seu pedido.");
        printf("\n");
        printf("--> ");
        scanf("%d", &op);

        if (op >= 1 && op <= 13)
        {
            printf("Digite a quantidade que deseja? \n");
            printf("--> ");
            scanf("%d", &quant);
        }

        switch (op)
        {
        case 0:
            gerirCarrinho();
            break;
        case 1:
            addCarrinho(17, quant, 1, "Hossomaki-Kani");
            break;
        case 2:
            addCarrinho(17, quant, 2, "Hossomaki-Salmao");
            break;
        case 3:
            addCarrinho(18, quant, 3, "Hossomaki-Camarao");
            break;
        case 4:
            addCarrinho(17, quant, 4, "HotRoll-Kani");
            break;
        case 5:
            addCarrinho(17, quant, 5, "HotRoll-Salmao");
            break;
        case 6:
            addCarrinho(18, quant, 6, "HotRoll-Camarao");
            break;
        case 7:
            addCarrinho(17, quant, 7, "TemakiTradicional-Kani");
            break;
        case 8:
            addCarrinho(17, quant, 8, "TemakiTradicional-Salmao");
            break;
        case 9:
            addCarrinho(18, quant, 9, "TemakiTradicional-Camarao");
            break;
        case 10:
            addCarrinho(2, quant, 10, "Bebidas-Agua");
            break;
        case 11:
            addCarrinho(3, quant, 11, "Bebidas-SucoCopo");
            break;
        case 12:
            addCarrinho(4, quant, 12, "Bebidas-CervejaLata");
            break;
        case 13:
            addCarrinho(2, quant, 14, "Bebidas-RefrigeranteLata");
            break;
        default:
            printf("\n\n<!> Produto invalido, escolha um produto. <!>\n\n");
            fflush(stdin);
            getchar();
            system("cls");
            cardapio();
            break;
        }
    } while (op != 0);
}

void addCarrinho(int preco, int quant, int cod, char *prod)
{

    carrinho *produto = (carrinho *)malloc(sizeof(carrinho));
    produto->preco = preco;
    produto->quant = quant;
    produto->cod = cod;
    strncpy(produto->prod, prod, strlen(prod));
    produto->ant = NULL;
    produto->prox = NULL;

    if (tam == 0)
    {
        inicio = produto;
        fim = produto;
    }
    else
    {
        fim->prox = produto;
        produto->ant = fim;
        fim = produto;
    }
    tam++;
}

void imprimirCarrinho()
{
    total = 0;
    carrinho *produto = inicio;
    system("cls");
    for (int i = 0; i < tam; i++)
    {
        int valorProduto = produto->quant * produto->preco;
        total += valorProduto;
        printf("\n\n Cod: %d - [ %s ] R$%d \nQuantidade: %d - Valor: %d \n", produto->cod, produto->prod, produto->preco, produto->quant, valorProduto);
        produto = produto->prox;
    }
}

void removerCarrinho(int cod)
{
    if (tam == 1)
    {
        inicio = NULL;
        fim = NULL;
    }
    else if (inicio->cod == cod)
    {
        carrinho *produto = inicio;
        produto->prox->ant = NULL;
        inicio = produto->prox;
        free(produto);
    }
    else if (fim->cod == cod)
    {
        carrinho *produto = fim;
        produto->ant->prox = NULL;
        fim = produto->ant;
        free(produto);
    }
    else
    {
        carrinho *produto = inicio;
        for (int i = 0; i < tam; i++)
        {
            if (cod == produto->cod)
            {
                produto->prox->ant = produto->ant;
                produto->ant->prox = produto->prox;
                free(produto);
            }
        }
    }
    tam--;
    cardapio();
}

void gerirCarrinho()
{
    int op, cod;
    imprimirCarrinho();
    printf("\n\n\n");
    printf("--------------------------------------------------- \n");
    printf("|               <$> Carrinho <$>                  | \n");
    printf("|            1 - Remover produto                  | \n");
    printf("|            2 - Voltar pro Cardapio              | \n");
    printf("|            3 - Fechar pedido                    | \n");
    printf("--------------------------------------------------- \n");
    printf("\nEscolha uma das opcoes: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        printf("Digite o codigo do produto:\n");
        printf("--> ");
        scanf("%d", &cod);
        removerCarrinho(cod);
        break;
    case 2:
        cardapio();
        break;
    case 3:
        pagamento();
        break;
    default:
        printf("Digite um valor valido!");
        system("cls");
        fflush(stdin);
        getchar();
        imprimirCarrinho();
        break;
    }
}

void pagamento()
{
    int pagamento;
    int troco;
    int valordado;
    int bandeira;

    system("cls");
    printf("----------------------------------------- \n");
    printf("|   O total do seu carrinho foi de R$%d  | \n", total);
    printf("----------------------------------------- \n");
    printf("\n\n");

    printf("--------------------------------------------------- \n");
    printf("|     Selecione a forma de pagamento desejada      |\n");
    printf("| 1 - Dinheiro                                     |\n");
    printf("| 2 - Cartao                                       |\n");
    printf("--------------------------------------------------- \n");
    printf("--> ");

    scanf("%d", &pagamento);
    system("cls");
    fflush(stdin);
    if (pagamento == 1)
    {

        printf("----------------------------------------------------------- \n");
        printf("|  informe o valor em dinheiro que ira ser entregue:      | \n");
        printf("----------------------------------------------------------- \n");
        printf("--> ");
        scanf("%d", &valordado);
        printf("\n");

        troco = valordado - total;

        system("cls");
        printf("----------------------------------------- \n");
        printf("|       O seu troco sera de R$%d        | \n", troco);
        printf("|  O entregador ja esta a caminho       | \n");
        printf("|  Obrigado pela preferencia            | \n");
        printf("----------------------------------------- \n");
        printf("\n");
    }

    if (pagamento == 2)
    {
        printf("----------------------------------------- \n");
        printf("|   Informe a Bandeira do cartao:       | \n");
        printf("|   1 - VISA                            | \n");
        printf("|   2 - MASTERCARD                      | \n");
        printf("|   3 - ELO                             | \n");
        printf("----------------------------------------- \n");
        printf("--> ");
        scanf("%d", &bandeira);

        system("cls");
        printf("----------------------------------------- \n");
        printf("|   O entregado ira levar a maquina     | \n");
        printf("|   Obrigado pela preferencia           | \n");
        printf("----------------------------------------- \n");
        printf("\n");
    }
}

int main()
{
    menu();
    return 0;
}