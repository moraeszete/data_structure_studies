// Pedaço do arquivo FEBRABAN CNAB 240

//                                 I  F  T  Tipo  Default   Observações
// 01.0 Código Banco Compensação   1  3  3  Num             G001
// 02.0 Lote Lote de Serviço       4  7  4  Num   '0000'   *G002
// 03.0 Registro Tipo de Registro  8  8  1  Num   '0'      *G003
// 04.0 Uso Exclusivo CNAB         9 17  9  Alfa  Brancos   G004
// 05.0 Tipo Inscrição Empresa    18 18  1  Num            *G005
// 06.0 Número Inscrição Empresa  19 32 14  Num            *G006

// I=Posição inicial; F=Posição final; T=Tamanho
#include <stdio.h>

// Estrutura simples para os campos do Header CNAB 240
typedef struct {
    char codigoBanco[4];         
    char loteServico[5];         
    char tipoRegistro[2];        
    char usoExclusivoCNAB[10];   
    char tipoInscricao[2];       
    char numeroInscricao[15];   
} HeaderCNAB;

// Função para copiar uma string para outra
void copiar_string(char *destino, char *origem) {
    int i = 0;
    while (origem[i] != '\0') {
        destino[i] = origem[i];
        i++;
    }
    destino[i] = '\0'; // Adiciona o terminador nulo
}

// Função para formatar um campo com largura fixa
// isso aqui eu pedi ajuda pro sonneto
void formatar_campo(char *destino, char *origem, int largura, int *pos) {
    int i = 0;
    // Copia o texto de origem
    while (origem[i] != '\0') {
        destino[*pos] = origem[i];
        (*pos)++;
        i++;
    }
    
    // Preenche o resto do espaço com espaços em branco se necessário
    while (i < largura) {
        destino[*pos] = ' ';
        (*pos)++;
        i++;
    }
}

// Função para gerar o header e retornar como string (sem usar snprintf)
void gerar_header(HeaderCNAB *header, char *resultado) {
    int posicao = 0;
    
    // Formata cada campo com o tamanho correto
    formatar_campo(resultado, header->codigoBanco, 3, &posicao);
    formatar_campo(resultado, header->loteServico, 4, &posicao);
    formatar_campo(resultado, header->tipoRegistro, 1, &posicao);
    formatar_campo(resultado, header->usoExclusivoCNAB, 9, &posicao);
    formatar_campo(resultado, header->tipoInscricao, 1, &posicao);
    formatar_campo(resultado, header->numeroInscricao, 14, &posicao);
    
    // Adiciona o terminador nulo
    resultado[posicao] = '\0';
    
    // O resultado terá exatamente 32 caracteres mais o terminador nulo
}

int main() {
    HeaderCNAB header;
    char headerFormatado[33]; // 32 caracteres + terminador nulo
    
    // Define valores para o header manualmente o tamanho do array ja conta com o terminador 
    copiar_string(header.codigoBanco, "644");
    copiar_string(header.loteServico, "6498");
    copiar_string(header.tipoRegistro, "2");
    copiar_string(header.usoExclusivoCNAB, "999999999");
    copiar_string(header.tipoInscricao, "2");
    copiar_string(header.numeroInscricao, "12345678901234");

    // Gera o header formatado
    gerar_header(&header, headerFormatado);
    
    // Mostra o header gerado no console
    printf("--- Header CNAB 240 gerado ---\n");
    printf("%s\n", headerFormatado);
    printf("---------------------------------\n");
    printf("Detalhes dos campos:\n");
    printf("Código Banco: %s\n", header.codigoBanco);
    printf("Lote Serviço: %s\n", header.loteServico);
    printf("Tipo Registro: %s\n", header.tipoRegistro);
    printf("Uso Exclusivo: %s\n", header.usoExclusivoCNAB);
    printf("Tipo Inscrição: %s\n", header.tipoInscricao);
    printf("Número Inscrição: %s\n", header.numeroInscricao);

    return 0;
}
