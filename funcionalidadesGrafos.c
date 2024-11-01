#include "./funcoesCriadas.h"

void func10()
{
    grafo* g;

    g=cria_grafo(); //funcao que cria e retorna o grafo de acordo com o arquivo que sera aberto dentro da funcao

    //retorna erro se der problema e nao faz os prints
    if(g==NULL)
        return;

    for(int ver=0; ver<g->nroV; ver++)   //loop que exibe os vertices do grafo
        exibe_vertice(g,ver);

    libera_grafo(g);    //quem sabe nem precise disso
}