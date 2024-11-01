#include "./funcoesCriadas.h"


grafo* cria_grafo()  //funcao retorna uma lista de predadores, que eh o grafo
{

    char nomearq[31];   // nome do arquivo que sera lido
    dados DADO;         // variavel de registro
    cabecalho CAB;      // variavel do cabecalho

    vertice* PREDADOR; // variavel da lista que sera criada
    grafo* GRAFO;       //grafo

    scanf("%s", nomearq); // le o nome do arquivo que sera aberto

    FILE *arquivo;
    arquivo = fopen(nomearq, "rb"); //abre o arquivo

    if(arquivo==NULL){      //checa se abriu
        printf(ERRO_PADRAO);
        return NULL;
    }

    CAB = le_cabecalho(arquivo);    //le o cabecalho

    if(CAB.status=='0'){            //checa consistencia
        printf(ERRO_PADRAO);  
        fclose(arquivo);    
        return NULL;
    }

    GRAFO->nroV=CAB.proxRRN-CAB.nroRegRem;
    GRAFO = calloc(1, sizeof(grafo));    //aloca o espaco do grafo

    //insere os dados de cada predador do arquivo de dados

    //depois ordena


    return GRAFO;
}

void exibe_vertice(grafo *GRAFO,int vertice)
{
    printf("%s, %s, %s, %s",GRAFO->PREDADOR[vertice].nome,GRAFO->PREDADOR[vertice].especie,
    GRAFO->PREDADOR[vertice].habitat,GRAFO->PREDADOR[vertice].dieta);

    printf("%s, %d, %d, %d",GRAFO->PREDADOR[vertice].tipo,GRAFO->PREDADOR[vertice].g_entrada,
    GRAFO->PREDADOR[vertice].g_saida,GRAFO->PREDADOR[vertice].g_entrada+GRAFO->PREDADOR[vertice].g_saida);

    printf("%s, %s\n",GRAFO->PREDADOR[vertice].presa_n,GRAFO->PREDADOR[vertice].presa_p);

}