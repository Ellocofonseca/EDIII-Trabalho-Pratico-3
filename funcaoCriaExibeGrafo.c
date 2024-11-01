#include "./funcoesCriadas.h"


predador* cria_grafo()  //funcao retorna uma lista de predadores
{

    char nomearq[31]; // nome do arquivo que sera lido
    dados DADO;       // variavel de registro
    cabecalho CAB;    // variavel do cabecalho

    predador* LISTA;  // variavel da lista que sera criada

    scanf("%s", nomearq); // le o nome do arquivo que sera aberto

    FILE *arquivo;
    arquivo = fopen(nomearq, "rb");

    if(arquivo==NULL){
        printf(ERRO_PADRAO);
        return;
    }

    CAB = le_cabecalho(arquivo);

    if(CAB.status=='0'){
        printf(ERRO_PADRAO);  
        fclose(arquivo);    
        return;
    }

    LISTA = calloc(CAB.proxRRN-CAB.nroRegRem, sizeof(predador));    //aloca o espaco da lista de adjacencia

    //insere os dados de cada predador do arquivo de dados




    return LISTA;
}