#include "./funcoesCriadas.h"


grafo* cria_grafo()  //funcao retorna uma lista de predadores, que eh o grafo
{

    char nomearq[31];   // nome do arquivo que sera lido
    dados DADO;         // variavel de registro
    cabecalho CAB;      // variavel do cabecalho

    //USADO POSTERIORMENTE PARA SEPARAR OS DADOS DOS VERTICES
    char *lin;


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
    fseek(arquivo,1600,SEEK_SET);   //pula para os dados

    if(CAB.status=='0'){            //checa consistencia
        printf(ERRO_PADRAO);  
        fclose(arquivo);    
        return NULL;
    }

    GRAFO->nroV=CAB.proxRRN-CAB.nroRegRem;
    GRAFO = calloc(1, sizeof(grafo));    //aloca o espaco do grafo

    //insere os dados de cada predador do arquivo de dados
    for (int vertice = 0; vertice < CAB.proxRRN; vertice++)
    { // loop que le os dados e insere no grafo
        DADO = le_registro(arquivo);
        if (DADO.removido == '0')
        {
            lin = strdup(DADO.variavel);
            GRAFO->PREDADOR[vertice].nome = strsep(&lin, "#");
            GRAFO->PREDADOR[vertice].especie = strsep(&lin, "#");
            GRAFO->PREDADOR[vertice].habitat = strsep(&lin, "#");
            GRAFO->PREDADOR[vertice].tipo = strsep(&lin, "#");
            GRAFO->PREDADOR[vertice].dieta = strsep(&lin, "#");
            GRAFO->PREDADOR[vertice].presa_n = strsep(&lin, "#");

            GRAFO->PREDADOR[vertice].pos = vertice;
            // seila
            GRAFO->PREDADOR[vertice].g_entrada;
            GRAFO->PREDADOR[vertice].g_saida;
            GRAFO->PREDADOR[vertice].presa_p;
        }
    }
    //depois ordena?

    fclose(arquivo);
    return GRAFO;
}

void exibe_vertice(grafo *GRAFO,int ver)
{
    printf("%s, %s, %s, %s",GRAFO->PREDADOR[ver].nome,GRAFO->PREDADOR[ver].especie,
    GRAFO->PREDADOR[ver].habitat,GRAFO->PREDADOR[ver].dieta);

    printf("%s, %d, %d, %d",GRAFO->PREDADOR[ver].tipo,GRAFO->PREDADOR[ver].g_entrada,
    GRAFO->PREDADOR[ver].g_saida,GRAFO->PREDADOR[ver].g_entrada+GRAFO->PREDADOR[ver].g_saida);

    printf("%s, %s\n",GRAFO->PREDADOR[ver].presa_n,GRAFO->PREDADOR[ver].presa_p);

}

void libera_grafo(grafo *g)
{   
    int v;
    for(v=0; v<g->nroV; v++){   //loop que libera o grafo
        free(g->PREDADOR[v].pos);//
        free(g->PREDADOR[v].nome);
        free(g->PREDADOR[v].especie);
        free(g->PREDADOR[v].habitat);
        free(g->PREDADOR[v].dieta);
        free(g->PREDADOR[v].tipo);
        free(g->PREDADOR[v].g_entrada);//
        free(g->PREDADOR[v].g_saida);//
        free(g->PREDADOR[v].presa_n);
        free(g->PREDADOR[v].presa_p);
    }
    free(g);
}