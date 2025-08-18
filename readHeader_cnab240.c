// Leitor de arquivo FEBRABAN CNAB 240

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

// Função para extrair campos do header
void extrair_campos(const char *header, HeaderCNAB *resultado) {
    // Extrai cada campo na posição correta (ajustando para índice base 0)
    strncpy(resultado->codigoBanco, header, 3);
    resultado->codigoBanco[3] = '\0';
    
    strncpy(resultado->loteServico, header + 3, 4);
    resultado->loteServico[4] = '\0';
    
    strncpy(resultado->tipoRegistro, header + 7, 1);
    resultado->tipoRegistro[1] = '\0';
    
    strncpy(resultado->usoExclusivoCNAB, header + 8, 9);
    resultado->usoExclusivoCNAB[9] = '\0';
    
    strncpy(resultado->tipoInscricao, header + 17, 1);
    resultado->tipoInscricao[1] = '\0';
    
    strncpy(resultado->numeroInscricao, header + 18, 14);
    resultado->numeroInscricao[14] = '\0';
}

// Função para exibir os campos extraídos
void exibir_campos(HeaderCNAB *header) {
    printf("\n=== Campos extraídos do Header CNAB 240 ===\n");
    printf("Código do Banco: %s\n", header->codigoBanco);
    printf("Lote de Serviço: %s\n", header->loteServico);
    printf("Tipo de Registro: %s\n", header->tipoRegistro);
    printf("Uso Exclusivo CNAB: %s\n", header->usoExclusivoCNAB);
    printf("Tipo de Inscrição: %s", header->tipoInscricao);
    
    // Detalha o tipo de inscrição para facilitar leitura
    if (strcmp(header->tipoInscricao, "1") == 0) {
        printf(" (CPF)\n");
    } else if (strcmp(header->tipoInscricao, "2") == 0) {
        printf(" (CNPJ)\n");
    } else {
        printf(" (Desconhecido)\n");
    }
    
    printf("Número de Inscrição: %s\n", header->numeroInscricao);
}

int main() {
    HeaderCNAB header;
    char headerString[100];
    
    printf("=== Leitor de Header CNAB 240 ===\n\n");
    printf("Digite o header CNAB 240 (32 caracteres): ");
    
    // Lê o header diretamente do console
    scanf("%99[^\n]", headerString);
    
    // Verifica se o header tem o tamanho mínimo
    if (strlen(headerString) < 32) {
        printf("Erro: o header deve ter pelo menos 32 caracteres!\n");
        return 1;
    }
    
    // Extrai os campos do header
    extrair_campos(headerString, &header);
    
    // Exibe os campos extraídos
    exibir_campos(&header);
    
    return 0;
}
