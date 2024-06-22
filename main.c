#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
#include<locale.h>

#define MAX 100
int i;
int t;
int totalClientes = 0;
char toUpperNome[100];
int currentId = 101101;
int status1 =0;



void cadastrar(void);
void buscarCliente(void);
void limparTela(void);
void pauseScr(void);
void exibirTodosClientesAtivos(void);
void editarClientes(void);
void excluirCliente(void);
void toUpper(void);

struct st_cadastroClientes{
    char nomeCompleto[50];
    char sexo[10];
    int cpf;
    char dataNasc[50];
    char email[50];
    int numeroTelefone;
    int id;
    int status;
};
struct st_cadastroClientes cadastroCliente[MAX];

void toUpper(){
    for(t=0;t<100;t++){
        toUpperNome[t] = tolower(toUpperNome[t]);
    }
    for (int t = 0; t < 100; ++t) {
        if(toUpperNome[t]== ' '){
            toUpperNome[t+1]= toupper(toUpperNome[t+1]);
        }
    }toUpperNome[0]= toupper(toUpperNome[0]);
}
void inicioMenu(){
    int opcao;
    printf("-----------------------------------HyperSoft-----------------------------------\n");
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
        excluirCliente();
    }else if(opcao == 5){
        exibirTodosClientesAtivos();
    }else{
        printf("Opcao invalida\n");
        system("pause");
        system("cls");
        inicioMenu();
    }
}

void cadastrar(){
    limparTela();
    int proxCliente = totalClientes+1;
    printf("CADASTRO DE CLIENTE\n");
    printf("--------------------------------------------------------------------------------\n");
            for(i=totalClientes;i<proxCliente;i++){
                cadastroCliente[i].id = currentId;
                cadastroCliente[i].status = status1+1;
                printf("Id do cliente:%d\n", cadastroCliente[i].id);
                printf("Insira o sexo do cliente:(M/F)\n");
                scanf(" %[^\n]s", &cadastroCliente[i].sexo);
                getchar();
                printf("Insira o nome completo do cliente:\n");
                scanf(" %[^\n]s", &toUpperNome);
                toUpper();
                strcpy(cadastroCliente[i].nomeCompleto, toUpperNome);
                printf("Insira o CPF de %s:\n", cadastroCliente[i].nomeCompleto);
                scanf("%d", &cadastroCliente[i].cpf);

                printf("Insira a data de nascimento de %s\n", cadastroCliente[i].nomeCompleto);
                scanf("%s", &cadastroCliente[i].dataNasc);

                printf("Insira o numero de telefone de %s\n", cadastroCliente[i].nomeCompleto);
                scanf("%d", &cadastroCliente[i].numeroTelefone);

                printf("Insira o email de %s\n", cadastroCliente[i].nomeCompleto);
                scanf("%s", &cadastroCliente[i].email);

                printf("--------------------------------------------------------------------------------\n");
                printf("Cadastro concluido com sucesso!\n");
                totalClientes++;
                currentId++;
                pauseScr();
                limparTela();
                inicioMenu();
            }
}
void buscarCliente(){
    if(totalClientes == 0){
        printf("Nao ha clientes cadastrados!\n");
        pauseScr();
        limparTela();
        inicioMenu();
    }
    int busca;
    int buscaID;
    char buscaNome[50];
    limparTela();
    printf("1- Busca por ID\n");
    printf("2- Busca por Nome\n");
    scanf("%d", &busca);
    int tryCatch = 0;
    if(busca == 1){
        printf("Insira o ID do cliente: \n");
        scanf("%d", &buscaID);
        getchar();
        for(i=0;i<totalClientes;i++){
            if(buscaID == cadastroCliente[i].id){
                if(cadastroCliente[i].status == 0){
                    printf("Cliente nao existe no banco de dados!\n");
                    pauseScr();
                    limparTela();
                    inicioMenu();
                }
                tryCatch++;
                printf("--------------------------------------------------------------------------------\n");
                printf("ID:%d\n", cadastroCliente[i].id);
                printf("Sexo:%s\n", cadastroCliente[i].sexo);
                printf("Nome completo:%s\n", &cadastroCliente[i].nomeCompleto);
                printf("CPF:%d\n", cadastroCliente[i].cpf);
                printf("Data de nascimento: %s\n", cadastroCliente[i].dataNasc);
                printf("Telefone:%d\n", cadastroCliente[i].numeroTelefone);
                printf("Email:%s\n", cadastroCliente[i].email);
            }
        }

    }
    else if(busca == 2){
        printf("Insira o nome completo do cliente:\n");
        scanf(" %[^\n]s", &toUpperNome);
        toUpper();
        strcpy(buscaNome, toUpperNome);
        for(i=0;i<totalClientes;i++){
            if(strcmp(buscaNome, cadastroCliente[i].nomeCompleto)==0 && cadastroCliente[i].status != 0){
                tryCatch++;
                printf("ID:%d\n", cadastroCliente[i].id);
                printf("Sexo:%s\n", cadastroCliente[i].sexo);
                printf("Nome completo:%s\n", &cadastroCliente[i].nomeCompleto);
                printf("CPF:%d\n", cadastroCliente[i].cpf);
                printf("Data de nascimento: %s\n", cadastroCliente[i].dataNasc);
                printf("Telefone:%d\n", cadastroCliente[i].numeroTelefone);
                printf("Email:%s\n", cadastroCliente[i].email);
            }else if(strcmp(buscaNome, cadastroCliente[i].nomeCompleto)==0 && cadastroCliente[i].status == 0){
                printf("Cliente nao existe no banco de dados!\n");
                pauseScr();
                limparTela();
                inicioMenu();
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
    if(totalClientes==0){
        printf("Nao ha clientes cadastrados!\n");
        pauseScr();
        limparTela();
        inicioMenu();
    }
    for(i=0;i<totalClientes;i++){
     if(totalClientes!=0 && cadastroCliente[i].status!=0){
            printf("ID:%d\n", cadastroCliente[i].id);
            printf("Sexo:%s\n", cadastroCliente[i].sexo);
            printf("Nome completo:%s\n", &cadastroCliente[i].nomeCompleto);
            printf("CPF:%d\n", cadastroCliente[i].cpf);
            printf("Data de nascimento: %s\n", cadastroCliente[i].dataNasc);
            printf("Telefone:%d\n", cadastroCliente[i].numeroTelefone);
            printf("Email:%s\n", cadastroCliente[i].email);
            printf("--------------------------------------------------------------------------------\n");

        }
    }
    pauseScr();
    limparTela();
    inicioMenu();
}

void editarClientes(){
    limparTela();
    int op_edit;
    if(totalClientes==0){
        printf("Nao ha clientes cadastrados!\n");
        pauseScr();
        limparTela();
        inicioMenu();
    }
    printf("Editar dados do cliente\n");
    printf("1- Buscar por ID\n2- Buscar por nome\n");
    int busca;
    scanf("%d", &busca);
    if(busca == 1){
        int s_id;
        printf("Informe o codigo do cliente:\n");
        scanf("%d", &s_id);
        for(i=0;i<totalClientes;i++){
            if(s_id == cadastroCliente[i].id) {
                if(cadastroCliente[i].status == 0){
                    printf("Cliente nao existe no banco de dados!\n");
                    pauseScr();
                    limparTela();
                    inicioMenu();
                }
                printf("--------------------------------------------------------------------------------\n");
                printf("ID:%d\n", cadastroCliente[i].id);
                printf("Sexo:%s\n", cadastroCliente[i].sexo);
                printf("Nome completo:%s\n", &cadastroCliente[i].nomeCompleto);
                printf("CPF:%d\n", cadastroCliente[i].cpf);
                printf("Data de nascimento: %s\n", cadastroCliente[i].dataNasc);
                printf("Telefone:%d\n", cadastroCliente[i].numeroTelefone);
                printf("Email:%s\n", cadastroCliente[i].email);
                printf("--------------------------------------------------------------------------------\n");
                printf("Escolha o dado que deseja alterar\n1- Nome\n2- Sexo\n3- Telefone\n4- Cpf\n5- Email\n6- DataNasc\n");
                scanf("%d", &op_edit);
                if(op_edit == 1){
                    printf("Insira o nome do cliente\n");
                    scanf(" %[^\n]s", &cadastroCliente[i].nomeCompleto);
                }else if(op_edit == 2){
                    printf("Insira o sexo do cliente:(M/F)\n");
                    scanf("%s", &cadastroCliente[i].sexo);
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
        printf("Insira o nome do cliente\n");
        scanf(" %[^\n]s", &toUpperNome);
        toUpper();
        strcpy(buscaNome, toUpperNome);
        for (i = 0; i < totalClientes; ++i) {
            if(strcmp(buscaNome, cadastroCliente[i].nomeCompleto)==0){
                if(cadastroCliente[i].status == 0){
                    printf("Cliente nao existe no banco de dados!\n");
                    pauseScr();
                    limparTela();
                    inicioMenu();
                }
                printf("--------------------------------------------------------------------------------\n");
                printf("ID:%d\n", cadastroCliente[i].id);
                printf("Sexo:%s\n", cadastroCliente[i].sexo);
                printf("Nome completo:%s\n", &cadastroCliente[i].nomeCompleto);
                printf("CPF:%d\n", cadastroCliente[i].cpf);
                printf("Data de nascimento: %s\n", cadastroCliente[i].dataNasc);
                printf("Telefone:%d\n", cadastroCliente[i].numeroTelefone);
                printf("Email:%s\n", cadastroCliente[i].email);
                printf("--------------------------------------------------------------------------------\n");
                printf("Escolha o dado que deseja alterar\n1- Nome\n2- Sexo\n3- Telefone\n4- Cpf\n5- Email\n6- DataNasc\n");
                scanf("%d", &op_edit);
                if(op_edit == 1){
                    printf("Insira o nome do cliente\n");
                    scanf(" %[^\n]s", &toUpperNome);
                    toUpper();
                    strcpy(cadastroCliente[i].nomeCompleto, toUpperNome);
                }else if(op_edit == 2){
                    printf("Insira o sexo do cliente(M/F)\n");
                    scanf("%s", &cadastroCliente[i].sexo);
                }else if(op_edit == 3){
                    printf("Inisira o telefone do cliente\n");
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
            pauseScr();
            limparTela();
            inicioMenu();
        }
        pauseScr();
        limparTela();
        inicioMenu();
    }
    void excluirCliente() {
        int op;
        int buscaID;
        char buscaNome[100];
        int op2;
        limparTela();
        if(totalClientes==0){
            printf("Nao ha clientes cadastrados!\n");
            pauseScr();
            limparTela();
            inicioMenu();
        }
        printf("--------------------------------------------------------------------------------\n");
        printf("EXCLUIR CLIENTE\n");
        printf("Metodo de busca:\n 1-ID\n 2-Nome\n");
        scanf("%d", &op);
        if (op == 1) {
            printf("Insira o ID do cliente:\n");
            scanf("%d", &buscaID);
            for (i = 0; i < totalClientes; i++) {
                if (buscaID == cadastroCliente[i].id && cadastroCliente[i].status != 0) {
                    printf("--------------------------------------------------------------------------------\n");
                    printf("Tem certeza que deseja excluir o cliente %s ?\n", cadastroCliente[i].nomeCompleto);
                    printf("1-sim\n2-nao\n");
                    scanf("%d", &op2);
                    if (op2 == 1) {
                        strcpy(cadastroCliente[i].nomeCompleto, "NUll");
                        strcpy(cadastroCliente[i].dataNasc, "NULL");
                        strcpy(cadastroCliente[i].email, "NULL");
                        strcpy(cadastroCliente[i].sexo, "NULL");
                        cadastroCliente[i].cpf = 0;
                        cadastroCliente[i].numeroTelefone = 0;
                        cadastroCliente[i].status--;
                        totalClientes--;
                        printf("Cliente excluido com sucesso\n");
                        pauseScr();
                        limparTela();
                        inicioMenu();
                    }else if(op2 == 2){
                        pauseScr();
                        limparTela();
                        inicioMenu();
                    }else{
                        printf("Opcao invalida!\n");
                        pauseScr();
                        limparTela();
                        inicioMenu();
                    }
                }else{
                    printf("Cliente nao existe no banco de dados!\n");
                    pauseScr();
                    limparTela();
                    inicioMenu();
                }
            }
        } else if (op == 2) {
            printf("Insira o nome do cliente\n");
            scanf("%s", &toUpperNome);
            toUpper();
            strcpy(buscaNome, toUpperNome);
            for (i = 0; i < totalClientes; i++) {
                if (strcmp(buscaNome, cadastroCliente[i].nomeCompleto) == 0 && cadastroCliente[i].status!=0) {
                    printf("Tem certeza que deseja excluir o cliente %s ?\n", cadastroCliente[i].nomeCompleto);
                    printf("1-sim\n2-nao\n");
                    scanf("%d", &op2);
                    if (op2 == 1) {
                        strcpy(cadastroCliente[i].nomeCompleto, "NUll");
                        strcpy(cadastroCliente[i].dataNasc, "NULL");
                        strcpy(cadastroCliente[i].email, "NULL");
                        strcpy(cadastroCliente[i].sexo, "NULL");
                        cadastroCliente[i].cpf = 0;
                        cadastroCliente[i].numeroTelefone = 0;
                        cadastroCliente[i].status--;
                        totalClientes--;
                        printf("Cliente excluido com sucesso\n");
                        pauseScr();
                        limparTela();
                        inicioMenu();
                    }else if(op2 == 2){
                        pauseScr();
                        limparTela();
                        inicioMenu();
                    }else {
                        printf("Opcao invalida!\n");
                        pauseScr();
                        limparTela();
                        inicioMenu();
                    }
                }else{
                    printf("Cliente nao existe no banco de dados!\n");
                    pauseScr();
                    limparTela();
                    inicioMenu();
                }
            }
        }else{
            printf("Opcao invalida!");
            pauseScr();
            limparTela();
            inicioMenu();
        }
    }

int main(){
    setlocale(LC_ALL, "Portuguese_Brazil");
    inicioMenu();
    return 0;
}
