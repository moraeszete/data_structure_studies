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
#include <string.h>

// Estrutura simples para os campos do Header CNAB 240
typedef struct {
    char codigoBanco[4];         // 01.0 Código Banco Compensação (posição 1-3)
    char loteServico[5];         // 02.0 Lote de Serviço (posição 4-7)
    char tipoRegistro[2];        // 03.0 Tipo de Registro (posição 8)
    char usoExclusivoCNAB[10];   // 04.0 Uso Exclusivo CNAB (posição 9-17)
    char tipoInscricao[2];       // 05.0 Tipo Inscrição Empresa (posição 18)
    char numeroInscricao[15];    // 06.0 Número Inscrição Empresa (posição 19-32)
} HeaderCNAB;

// Função para gerar o header e retornar como string
void gerar_header(HeaderCNAB *header, char *resultado) {
    snprintf(
        resultado, 
        33, // 32 caracteres + terminador nulo
        "%-3s%-4s%-1s%-9s%-1s%-14s", 
        header->codigoBanco,
        header->loteServico,
        header->tipoRegistro,
        header->usoExclusivoCNAB,
        header->tipoInscricao,
        header->numeroInscricao
    );
    // Formata os campos do header CNAB 240 com tamanhos fixos:
    // %-3s  = código banco (3 chars)
    // %-4s  = lote de serviço (4 chars)
    // %-1s  = tipo de registro (1 char)
    // %-9s  = uso exclusivo CNAB (9 chars)
    // %-1s  = tipo inscrição (1 char)
    // %-14s = número inscrição (14 chars)
}

int main() {
    HeaderCNAB header;
    char headerFormatado[33]; // 32 caracteres + terminador nulo
    
    // Definir valores para o header
    strcpy(header.codigoBanco, "001");
    strcpy(header.loteServico, "0000");
    strcpy(header.tipoRegistro, "0");
    strcpy(header.usoExclusivoCNAB, "         ");
    strcpy(header.tipoInscricao, "1");
    strcpy(header.numeroInscricao, "12345678901234");
    
    // Gerar o header formatado
    gerar_header(&header, headerFormatado);
    
    // Mostrar o header gerado no console
    printf("=== Header CNAB 240 gerado ===\n");
    printf("%s\n", headerFormatado);
    printf("\nDetalhes dos campos:\n");
    printf("Código Banco: %s\n", header.codigoBanco);
    printf("Lote Serviço: %s\n", header.loteServico);
    printf("Tipo Registro: %s\n", header.tipoRegistro);
    printf("Uso Exclusivo: %s\n", header.usoExclusivoCNAB);
    printf("Tipo Inscrição: %s\n", header.tipoInscricao);
    printf("Número Inscrição: %s\n", header.numeroInscricao);
    
    return 0;
}
