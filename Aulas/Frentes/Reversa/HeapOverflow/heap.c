#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _registro REGISTRO;
typedef struct _no NO;

struct _registro{
    NO *inicio;
    NO *fim;
    int tamanho;
};

struct _no{
    int privilegio;
    char nome[12];
    char senha[16];
    NO *next;
};

REGISTRO *lista_criar(void){
    REGISTRO *lista = (REGISTRO *) malloc(sizeof(REGISTRO));

    if(lista != NULL){
        lista->inicio = NULL;
        lista->fim = NULL;
        lista->tamanho = 0;
    }

    return lista;    
}

int lista_vazia(REGISTRO *lista){
    if(lista != NULL && lista->inicio != NULL)
        return 0;
    
    return 1;
}

void lista_apagar(REGISTRO **lista){
    if(lista != NULL){
        if(!lista_vazia(*lista)){
            NO *no = (*lista)->inicio;

            while(no != NULL){
                (*lista)->inicio = no->next;
                no->next = NULL;
                free(no);
                (*lista)->tamanho--;
                no = (*lista)->inicio;
            }
        }

        (*lista)->inicio = NULL;
        (*lista)->fim = NULL;
        free(*lista);
        *lista = NULL;
    }

    return;
}

NO *lista_inserir(REGISTRO *lista){
    if(lista != NULL){
        NO *novo = NULL;
        novo = (NO *) malloc(sizeof(NO));
        
        if(novo != NULL){
            novo->privilegio = 0;
            novo->next = NULL;
            
            if(!lista_vazia(lista))
                lista->fim->next = novo;
            else
                lista->inicio = novo;
            
            lista->fim = novo;
            lista->tamanho++;
        }

        return novo;
    }

    printf("Falha ao cadastrar usuario, tente novamente!\n");

    return NULL;
}

NO *lista_buscar(REGISTRO *lista, char *login, char *senha){
    if(!lista_vazia(lista)){
        NO *p = lista->inicio;
        while(p != NULL){
            if(strcmp(p->nome, login) == 0){
                if(strcmp(p->senha, senha) == 0){
                    printf("Login feito com sucesso!\n\n");
                    return p;
                }

                printf("Nome de login ou senha incorretos\n\n");

                return NULL;
            }
        }

        printf("Nome de login ou senha incorretos\n\n");
    }

    printf("Nao ha usuarios cadastrados\n");

    return NULL;
}

int main(void){
    REGISTRO *lista = lista_criar();
    NO *temp = NULL;
    char menu[10], login[12], senha[16];

    if(lista != NULL){
        do{
            printf("Digite 'cadastro' para cadastrar, 'login' para entrar ou 'sair' para encerrar\n> ");
            scanf("%9s", menu);
            printf("\n");

            if(strcmp(menu, "cadastro") == 0){
                temp = lista_inserir(lista);
                if(temp != NULL){
                    printf("Digite seu nome de login: ");
                    scanf("%s", temp->nome);

                    printf("Digite sua senha (max 15 characteres): ");
                    scanf("%15s", temp->senha);

                    printf("Seja bem-vindo!\n\n");

                    temp = NULL;
                }
            }else if(strcmp(menu, "login") == 0){
                printf("Digite seu nome de login: ");
                scanf("%11s", login);

                printf("Digite sua senha: ");
                scanf("%15s", senha);

                temp = lista_buscar(lista, login, senha);

                if(temp != NULL){
                    if(temp->privilegio == 1){
                        printf("Parabens, voce completou o desafio!\n");
                        break;
                    }else{
                        printf("Voce esta logado como um usuario comum\n");
                        printf("Saindo...\n\n");
                    }

                    temp = NULL;
                }
            }
        }while(strcmp(menu, "sair") != 0);
    }

    lista_apagar(&lista);

    return 0;
}
