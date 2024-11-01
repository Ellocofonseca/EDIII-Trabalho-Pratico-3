#include "./funcoesCriadas.h"


//FUNCOES DE ARQUIVO BINARIO

//a funcao le os campos do cabecalho do arquivo a partir da posicao que o ponteiro se encontra no momento
//depois de ler retorna a variavel do tipo cabecalho
cabecalho le_cabecalho(FILE *arquivo){
    cabecalho CAB;

    fread(&CAB.status,1,1,arquivo);
    fread(&CAB.topo,4,1,arquivo);
    fread(&CAB.proxRRN,4,1,arquivo);
    fread(&CAB.nroRegRem,4,1,arquivo);
    fread(&CAB.nroPagDisco,4,1,arquivo);
    fread(&CAB.qttCompacta,4,1,arquivo);
    return CAB;
}

//a funcao le os campos de dados do arquivo a partir da posicao que o ponteiro se encontra no momento
//caso o arquivo acabe o campo 'removido' da variavel DADO eh usado como flag para informar que o arquivo acabou
//retorna a variavel do tipo dados
//essa tatica com a flag impede que um arquivo que acaba do nada tenha seu dado incompleto inserido
dados le_registro(FILE *arquivo){

    dados DADO;

    if(fread(&DADO.removido,1,1,arquivo)==0){
        DADO.removido='2';
        return DADO;
    }
    if(fread(&DADO.encadeamento,4,1,arquivo)==0){
        DADO.removido='2';
        return DADO;
    }
    if(fread(&DADO.populacao,4,1,arquivo)==0){
        DADO.removido='2';
        return DADO;
    }
    if(fread(&DADO.tamanho,4,1,arquivo)==0){
        DADO.removido='2';
        return DADO;
    }
    if(fread(&DADO.unidadeMedida,1,1,arquivo)==0){
        DADO.removido='2';
        return DADO;
    }
    if(fread(&DADO.velocidade,4,1,arquivo)==0){
        DADO.removido='2';
        return DADO;
    }
    if(fread(DADO.variavel,142,1,arquivo)==0){
        DADO.removido='2';
        return DADO;
    }
    return DADO;
}
