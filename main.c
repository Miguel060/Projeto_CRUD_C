#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>

#define MAX 100
int i;
int n;
int totalClientes;

void cadastrar(void);
void buscarCliente(void);
void limparTela(void);
void pauseScr(void);
void exibirTodosClientesAtivos(void);
void editarClientes(void);

struct st_cadastroClientes{
    char nomeCompleto[50];
    char sexo;
    int cpf;
    char dataNasc[50];
    char email[50];
    int numeroTelefone;
    int id;
};
struct st_cadastroClientes cadastroCliente[MAX];


void inicioMenu(){
    int opcao;
    printf("-----------------------------------HyeperSoft-----------------------------------\n");
    printf("Opcoes: \n");
    printf("1- Buscar Clientes \n");
    printf("2- Cadastrar Clientes \n");
    printf("3- Substituir Dados do Cliente \n");
    printf("4- Excluir Clientes\n");
    printf("5- Exibir Clientes Ativos\n");
    printf("--------------------------------------------------------------------------------\n");
    scanf("%d", &opcao);
    if(opcao == 1){
    buscarCliente();
    }else if(opcao == 2){
        cadastrar();
    }else if(opcao == 3){
        editarClientes();
    }else if(opcao == 4){

    }else if(opcao == 5){
        exibirTodosClientesAtivos();
    }else{
        printf("Opcao invalida\n");
        pauseScr();
        system("cls");
        inicioMenu();

    }
}



void cadastrar(){
    int currentId = 101101;
    limparTela();
    printf("CADASTRO DE CLIENTE\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("Quantos clientes serao cadastrados:\n");
    scanf("%d", &n);

    if(n!=0 && n<100){
        for(i=0;i<n;i++){
            printf("Id do cliente:%d\n", currentId);
            printf("Insira o sexo do cliente:(M/F) \n");
            scanf(" %c",&cadastroCliente[i].sexo);

            printf("Insira o nome completo do cliente:\n");
            scanf(" %[^\n]s", &cadastroCliente[i].nomeCompleto);
            printf("Insira o CPF de %s:\n", cadastroCliente[i].nomeCompleto);
            scanf("%d", &cadastroCliente[i].cpf);

            printf("Insira a data de nascimento de %s\n", cadastroCliente[i].nomeCompleto);
            scanf("%s", &cadastroCliente[i].dataNasc);

            printf("Insira o numero de telefone de %s\n", cadastroCliente[i].nomeCompleto);
            scanf("%d", &cadastroCliente[i].numeroTelefone);

            printf("Insira o email de %s\n", cadastroCliente[i].nomeCompleto);
            scanf("%s", &cadastroCliente[i].email);
            printf("--------------------------------------------------------------------------------\n");
            printf("Cadastro concluído com sucesso!\n");
            cadastroCliente[i].id = currentId++;
            totalClientes++;

        }
    }else if(n==0){
        printf("Numero invalido\n");
    }else if(n>MAX){
        printf("Limite poss�vel de clientes excedido\n");
    }
    pauseScr();
    limparTela();
    inicioMenu();
}
void buscarCliente(){
    int busca;
    int buscaID;
    char buscaNome[50];
    limparTela();
    printf("1- Busca por ID\n");
    printf("2- Busca por Nome\n");
    scanf("%d", &busca);
    getchar();
    int tryCatch = 0;
    if(busca == 1){
        printf("Insira o ID do cliente: \n");
        scanf("%d", &buscaID);

        for(i=0;i<totalClientes;i++){
            if(buscaID == cadastroCliente[i].id){
                tryCatch++;
                printf("Sexo:%c\n", cadastroCliente[i].sexo);
                printf("Nome completo:%s\n", &cadastroCliente[i].nomeCompleto);
                printf("CPF%d:\n", cadastroCliente[i].cpf);
                printf("Data de nascimento: %s\n", cadastroCliente[i].dataNasc);
                printf("Telefone:%d\n", cadastroCliente[i].numeroTelefone);
                printf("Email:%s\n", cadastroCliente[i].email);
            }
        }

    }if(busca == 2){
        printf("Insira o nome completo do cliente:\n");
        scanf(" %[^\n]s", &buscaNome[50]);
        for(i=0;i<totalClientes;i++){
            if(strcmp(buscaNome, cadastroCliente[i].nomeCompleto)==0){
                tryCatch++;
                printf("Sexo:%c\n", cadastroCliente[i].sexo);
                printf("Nome completo:%s\n", &cadastroCliente[i].nomeCompleto);
                printf("CPF%d:\n", cadastroCliente[i].cpf);
                printf("Data de nascimento: %s\n", cadastroCliente[i].dataNasc);
                printf("Telefone:%d", cadastroCliente[i].numeroTelefone);
            }
        }
    }
    if(tryCatch != 0){
        printf("Busca realizada com sucesso!\n");
        pauseScr();
        limparTela();
        inicioMenu();
    }
    else if(tryCatch == 0){
        printf("Erro na busca\n");
        pauseScr();
        limparTela();
        inicioMenu();
    }
}
void limparTela(){
    system("cls");
}
void pauseScr(){
    system("pause");
}
void exibirTodosClientesAtivos(){
    printf("CLIENTES ATIVOS %d\n", totalClientes);
    printf("--------------------------------------------------------------------------------\n");
    for(i=0;i<totalClientes;i++){
        printf("Sexo:%c\n", cadastroCliente[i].sexo);
        printf("Nome completo:%s\n", &cadastroCliente[i].nomeCompleto);
        printf("CPF%d:\n", cadastroCliente[i].cpf);
        printf("Data de nascimento: %s\n", cadastroCliente[i].dataNasc);
        printf("Telefone:%d", cadastroCliente[i].numeroTelefone);
    }
}

void editarClientes(){
    int op_edit;
    printf("Editar dados do cliente\n");
    printf("1- Buscar por ID\n 2- Buscar por nome\n");
    int busca;
    scanf("%d", &busca);
    if(busca == 1){
        int s_id;
        printf("Informe o codigo do cliente:\n");
        scanf("%d", &s_id);
        for(i=0;i<totalClientes;i++){
            if(s_id == cadastroCliente[i].id) {
                printf("Escolha o dado que deseja alterar\n1- Nome\n2- Sexo\n3- Telefone\n4- Cpf\n5- Email\n 6-DataNasc");
                scanf("%d", &op_edit);
                if(op_edit == 1){
                    printf("Insira o nome do cliente\n");
                    scanf(" %[^\n]s", &cadastroCliente[i].nomeCompleto);
                }else if(op_edit == 2){
                    printf("Insira o sexo do cliente\n");
                    scanf("%c", &cadastroCliente[i].sexo);
                }else if(op_edit == 3){
                    printf("Inisra o telefone do cliente\n");
                    scanf("%d", &cadastroCliente[i].numeroTelefone);
                }else if(op_edit == 4){
                    printf("Insira o cpf do cliente\n");
                    scanf("%d", &cadastroCliente[i].cpf);
                }else if(op_edit == 5){
                    printf("Insir o email do cliente\n");
                    scanf("%s", &cadastroCliente[i].email);
                }else if(op_edit == 6){
                    printf("Insira a data de nascimento do cliente\n");
                    scanf("%s", &cadastroCliente[i].dataNasc);
                }
            }
        }
    }else if(busca == 2){
        char buscaNome[50];
        printf("Insira o nome do cliente");
        scanf(" %[^\n]s", &buscaNome);
        for (i = 0; i < totalClientes; ++i) {
            if(strcmp(buscaNome, cadastroCliente[i].nomeCompleto)==0){
                printf("Escolha o dado que deseja alterar\n1- Nome\n2- Sexo\n3- Telefone\n4- Cpf\n5- Email\n 6-DataNasc\n");
                scanf("%d", &op_edit);
                if(op_edit == 1){
                    printf("Insira o nome do cliente\n");
                    scanf(" %[^\n]s", &cadastroCliente[i].nomeCompleto);
                }else if(op_edit == 2){
                    printf("Insira o sexo do cliente\n");
                    scanf("%c", &cadastroCliente[i].sexo);
                }else if(op_edit == 3){
                    printf("Inisra o telefone do cliente\n");
                    scanf("%d", &cadastroCliente[i].numeroTelefone);
                }else if(op_edit == 4){
                    printf("Insira o cpf do cliente\n");
                    scanf("%d", &cadastroCliente[i].cpf);
                }else if(op_edit == 5){
                    printf("Insira o email do cliente\n");
                    scanf("%s", &cadastroCliente[i].email);
                }else if(op_edit == 6){
                    printf("Insira a data de nascimento do cliente\n");
                    scanf("%s", &cadastroCliente[i].dataNasc);
                }
            }
        }
    }

        else{
            printf("Opcao invalida!\n");
            limparTela();
            inicioMenu();
        }
        inicioMenu();
    }

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    inicioMenu();
    return 0;
}
