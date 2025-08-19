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

// Estrutura simples para os campos do Header CNAB 240
typedef struct {
    char codigoBanco[4];         
    char loteServico[5];         
    char tipoRegistro[2];        
    char usoExclusivoCNAB[10];   
    char tipoInscricao[2];       
    char numeroInscricao[15];    
} HeaderCNAB;

// Função para copiar n caracteres de origem para destino
void copiar_caracteres(char *destino, char *origem, int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
    destino[n] = '\0'; 
}

// Função para calcular o tamanho de uma string
int tamanho_string(char *str) {
    int len = 0; //contador
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Função para extrair campos do header
void extrair_campos(char *header, HeaderCNAB *resultado) {
    // Extrai cada campo na posição correta (ajustando para índice base 0)
    copiar_caracteres(resultado->codigoBanco, header, 3);
    copiar_caracteres(resultado->loteServico, header + 3, 4);
    copiar_caracteres(resultado->tipoRegistro, header + 7, 1);
    copiar_caracteres(resultado->usoExclusivoCNAB, header + 8, 9);
    copiar_caracteres(resultado->tipoInscricao, header + 17, 1);
    copiar_caracteres(resultado->numeroInscricao, header + 18, 14);
}

// Função para exibir os campos extraídos
void exibir_campos(HeaderCNAB *header) {
    printf("\n=== Campos extraídos do Header CNAB 240 ===\n");
    printf("Código do Banco: %s\n", header->codigoBanco);
    printf("Lote de Serviço: %s\n", header->loteServico);
    printf("Tipo de Registro: %s\n", header->tipoRegistro);
    printf("Uso Exclusivo CNAB: %s\n", header->usoExclusivoCNAB);
    printf("Tipo de Inscrição: %s", header->tipoInscricao);
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
    if (tamanho_string(headerString) < 32) {
        printf("Erro: o header deve ter pelo menos 32 caracteres!\n");
        return 1;
    }
    
    // Extrai os campos do header
    extrair_campos(headerString, &header);
    // &header e o ponteiro para a struct HeaderCNAB

    // Exibe os campos extraídos
    exibir_campos(&header);
    
    return 0;
}
