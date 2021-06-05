#include "convert.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

void dec_bin() { //converte de decimal para binario
    printf("Decimal -> Binario\n");
    printf("----------------------------------\n");

    int i, dec;
    bool check = false;

    while(check == false) { //checa se os algarismos estao de acordo com os algarismos decimais
        char dec_prov[100];
        printf("Decimal: ");
        scanf("%s", dec_prov);

        i = 0;
        while(dec_prov[i] != '\0') {
            if(isalpha(dec_prov[i])) {
                check = false;
                system("cls");
                printf("Decimal -> Binario\n");
                printf("-------------------------------------\n");
                printf(">Caracter invalido! Insira novamente<\n");
                printf("-------------------------------------\n");
                
                break;
            }
            else if(dec_prov[i + 1] == '\0') {
                dec = atoi(dec_prov);
                check = true;
                break;
            }
            ++i;
        }
    } 

    system("cls");
    printf("Decimal -> Binario\n");
    printf("-------------------------------------\n");
    printf("Decimal: %d\n", dec);
    printf("Binario: ");

    if(dec == 0) { 
        printf("0");
    }
    else if(dec == 1) {
        printf("1");
    }
    else {
        i = 0;
        int bin[200];
        while(dec != 1) { //faz o calculo para descobrir cada bit e armazena no array bin (na ordem lsb -> msb)
            if(dec / 2 == 1) { //se nao tiver mais como dividir, armazena o resto e o resultado da divisão
                bin[i] = dec % 2;
                bin[i + 1] = round(dec / 2);
            }
            else { //armazena somente o resto da divisao
                bin[i] = dec % 2;
            }
            dec = round(dec / 2);
            ++i;
        }

        for(i; i >= 0; i--) { //imprime cada bit (msb -> lsb) 
            printf("%d", bin[i]);
        }
    }
    printf("\n----------------------------------");
}

void dec_oct() { //converte de decimal para octal

    printf("Decimal -> Octal\n");
    printf("----------------------------------\n");
    
    int i, dec;
    char oct[200];
    char dec_prov[100];
    bool check = false;

    while(check == false) { //checa se os algarismos estao de acordo com os algarismos decimais

        printf("Decimal: ");
        scanf("%s", dec_prov);

        i = 0;
        while(dec_prov[i] != '\0') {
            
            if(isalpha(dec_prov[i])) {

                check = false;
                system("cls");
                printf("Decimal -> Octal\n");
                printf("-------------------------------------\n");
                printf(">Caracter invalido! Insira novamente<\n");
                printf("-------------------------------------\n");
                break;

            }
            else if( dec_prov[i + 1] == '\0' ) {

                dec = atoi(dec_prov);
                check = true;
                break;
            
            }

            ++i;

        }
    }

    system("cls");
    printf("Decimal -> Octal\n");
    printf("-------------------------------------\n");
    printf("Decimal: %d\n", dec);
    printf("Octal: ");

    if( dec < 8 ) {

        printf("%d", dec);
    
    }
    else {

        i = 0;
        while( dec >= 8 ) {

            if( round(dec / 8) < 8 ) {

                oct[i] = dec % 8;
                oct[i + 1] = round(dec / 8);

            }
            else {
                
                oct[i] = dec % 8;
            
            }

            dec = round(dec / 8);
            ++i;

        }
        
        for (i; i >= 0; --i ) {
            
            printf("%d", oct[i]);

        }

    }

    printf("\n-------------------------------------");
} 

void dec_hex() { //converte de decimal para hexadecimal
    printf("Decimal -> Hexadecimal\n");
    printf("----------------------------------\n");
    
    int i, dec;
    char hex[200];
    char dec_prov[100];
    bool check = false;

    while(check == false) { //checa se os algarismos estao de acordo com os algarismos decimais
        printf("Decimal: ");
        scanf("%s", dec_prov);

        i = 0;
        while(dec_prov[i] != '\0') {
            if(isalpha(dec_prov[i])) {
                check = false;
                system("cls");
                printf("Decimal -> Hexadecimal\n");
                printf("-------------------------------------\n");
                printf(">Caracter invalido! Insira novamente<\n");
                printf("-------------------------------------\n");
                break;
            }
            else if(dec_prov[i + 1] == '\0') {
                dec = atoi(dec_prov);
                check = true;
                break;
            }
            ++i;
        }
    }

    system("cls");
    printf("Decimal -> Hexadecimal\n");
    printf("-------------------------------------\n");
    printf("Decimal: %d\n", dec);
    printf("Hexadecimal: ");

    if(dec < 16) { //se o numero for menor que 16, imprime seu equivalente hexadecimal diretamente
        switch((dec % 16)) {
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", dec);
                break;
        }
    }
    else { //trata de numeros superiores ou igual a 16
        i = 0;
        int hold = dec;
        while(dec >= 16) { //faz o calculo para descobrir cada algarismo hexadecimal e o imprime
            if(round(dec / 16) < 16) { //caso nao tenha como dividir mais, ele pega o resto e o resultado da divisão
                switch((dec % 16)) {
                    case 10:
                        hex[i] = 'A';
                        break;
                    case 11:
                        hex[i] = 'B';
                        break;
                    case 12:
                        hex[i] = 'C';
                        break;
                    case 13:
                        hex[i] = 'D';
                        break;
                    case 14:
                        hex[i] = 'E';
                        break;
                    case 15:
                        hex[i] = 'F';
                        break;
                    default:
                        hex[i] = round(dec % 16) + '0';
                        break;
                }

                dec = round(dec / 16);
                switch(dec) {
                    case 10:
                        hex[i + 1] = 'A';
                        break;
                    case 11:
                        hex[i + 1] = 'B';
                        break;
                    case 12:
                        hex[i + 1] = 'C';
                        break;
                    case 13:
                        hex[i + 1] = 'D';
                        break;
                    case 14:
                        hex[i + 1] = 'E';
                        break;
                    case 15:
                        hex[i + 1] = 'F';
                        break;
                    default:
                        hex[i + 1] = dec + '0';
                        break;
                }

            }
            else { //armazena somente o resto da divisao
                switch((dec % 16)) {
                    case 10:
                        hex[i] = 'A';
                        break;
                    case 11:
                        hex[i] = 'B';
                        break;
                    case 12:
                        hex[i] = 'C';
                        break;
                    case 13:
                        hex[i] = 'D';
                        break;
                    case 14:
                        hex[i] = 'E';
                        break;
                    case 15:
                        hex[i] = 'F';
                        break;
                    default:
                        hex[i] = (dec % 16) + '0';
                        break;
                }  
            }
            dec = round(dec / 16);
            ++i;
        }

        for(i; i >= 0; i--) { // imprime o numero hexadecimal 
            printf("%c", hex[i]);
        }
    }
    printf("\n----------------------------------");
}

void bin_dec() { //converte de binario para decimal 
    printf("Binario -> Decimal\n");
    printf("----------------------------------\n");
    
    int i, dec, n_casas;
    char bin[50];
    bool check = false;

    while(check == false) { //checa se os algarismos estao de acordo com os algarismos binarios
        printf("Binario: ");
        scanf("%s", bin);

        i = 0;
        while(bin[i] != '\0') {
            if(isalpha(bin[i]) || (bin[i] - '0') > 1 || (bin[i] - '0') < 0) {
                check = false;
                system("cls");
                printf("Binario -> Decimal\n");
                printf("-------------------------------------\n");
                printf(">Caracter invalido! Insira novamente<\n");
                printf("-------------------------------------\n");
                break;
            }
            else if(bin[i + 1] == '\0') {
                check = true;
                break;
            }
            ++i;
        }
    }

    i = 0;
    n_casas = 0;
    while(bin[i] != '\0') { //conta o número de casas do numero binario
        n_casas++;
        ++i;
    }

    i = 0;
    dec = 0;
    while(bin[i] != '\0') { //calcula o numero decimal a partir de cada bit
        n_casas--;
        dec += (bin[i] - '0') * (int)pow(2, n_casas);
        ++i;
    }
    
    system("cls");
    printf("Binario -> Decimal\n");
    printf("-------------------------------------\n");
    printf("Binario: %s\n", bin);
    printf("Decimal: %d", dec); //imprime o decimal
    printf("\n----------------------------------");
}

void bin_oct() { //Converte de binario para octal

    printf("Binario -> Octal\n");
    printf("----------------------------------\n");
    
    int i, dec, oct, pos, quant, n_casas, quant_lim;
    int bin_fmt[50]; //armazena o binario como inteiro
    char bin_usr[50]; //armazena o que o usuario digitou
    bool reg = false;
    bool check = false;

    while(check == false) { //checa se os algarismos estao de acordo com os algarismos binarios
        printf("Binario: ");
        scanf("%s", bin_usr);

        i = 0;
        while(bin_usr[i] != '\0') {
            if(isalpha(bin_usr[i]) || (bin_usr[i] - '0') > 1 || (bin_usr[i] - '0') < 0) {
                check = false;
                system("cls");
                printf("Binario -> Octal\n");
                printf("-------------------------------------\n");
                printf(">Caracter invalido! Insira novamente<\n");
                printf("-------------------------------------\n");
                break;
            }
            else if(bin_usr[i + 1] == '\0') {
                check = true;
                break;
            }
            ++i;
        }
    } 

    system("cls");
    printf("Binario -> Octal\n");
    printf("-------------------------------------\n");
    printf("Binario: %s\n", bin_usr);
    printf("Octal: ");

    n_casas = 0;
    while(bin_usr[n_casas] != '\0') { //conta o numero de bits
        n_casas++; 
    }
    
    
    if( n_casas % 3 == 0 ) { //quando o numero de casas for divisivel por 3

        quant = n_casas / 3;

        int j = 0;
        while(quant != 0) {

            oct = 0;
            pos = 3;
            for(int i = 0; i < 3; ++i) { //converte para octal
                --pos;
                oct += ((bin_usr[j] - '0') * pow(2, pos));
                ++j;
            }

            printf("%d", oct);
            --quant;

        }

    }
    else { //quando o numero de casas NAO for divisivel por 3

        quant = n_casas; 
        while(quant % 3 != 0) { //procura o próximo numero divisivel por 3 maior que n_casas
            ++quant;
        } 

            
        for(int i = 0; i < quant; ++i) { //TRATA O NUMERO DE CASAS 
            if(i < (quant - n_casas)) {
                bin_fmt[i] = 0;
            }
            else {
                bin_fmt[i] = bin_usr[i - (quant - n_casas)] - '0';
            }
                
        }

        int j = 0;
        while( (quant / 3) != 0 ) { //converte para octal

            oct = 0;
            pos = 3;
            for(int i = 0; i < 3; ++i) { 
                --pos;
                oct += (bin_fmt[j] * pow(2, pos));
                ++j;
            }

            printf("%d", oct);
            quant = quant - 3;

        }

    }

}

void bin_hex() { //converte de binario para hexadecimal
    printf("Binario -> Hexadecimal\n");
    printf("----------------------------------\n");
    
    int i, dec, pos, quant, n_casas, quant_lim;
    int bin_fmt[50]; //armazena o binario como inteiro
    char bin_usr[50]; //armazena o que o usuario digitou
    bool reg = false;
    bool check = false;

    while(check == false) { //checa se os algarismos estao de acordo com os algarismos binarios
        printf("Binario: ");
        scanf("%s", bin_usr);

        i = 0;
        while(bin_usr[i] != '\0') {
            if(isalpha(bin_usr[i]) || (bin_usr[i] - '0') > 1 || (bin_usr[i] - '0') < 0) {
                check = false;
                system("cls");
                printf("Binario -> Hexadecimal\n");
                printf("-------------------------------------\n");
                printf(">Caracter invalido! Insira novamente<\n");
                printf("-------------------------------------\n");
                break;
            }
            else if(bin_usr[i + 1] == '\0') {
                check = true;
                break;
            }
            ++i;
        }
    } 

    system("cls");
    printf("Binario -> Hexadecimal\n");
    printf("-------------------------------------\n");
    printf("Binario: %s\n", bin_usr);
    printf("Hexadecimal: ");

    n_casas = 0;
    while(bin_usr[n_casas] != '\0') { //conta o numero de bits
        n_casas++; 
    }
    
    if(n_casas <= 4) { //trata de numeros menores que 15
        dec = 0;
        pos = n_casas;
        for(int i = 0; i < n_casas; i++) { //converte para decimal
            pos--;
            dec += ((bin_usr[i] - '0') * pow(2, pos));
        }
        
        switch(dec) { //imprime o algarismo hexadecimal correspondente ao numero decimal
            case 10:
                printf("A");
                break;
            case 11:
                printf("B");
                break;
            case 12:
                printf("C");
                break;
            case 13:
                printf("D");
                break;
            case 14:
                printf("E");
                break;
            case 15:
                printf("F");
                break;
            default:
                printf("%d", dec);
                break;
        }
    }
    else { //trata de numeros maiores que 15
        if(n_casas % 4 != 0) { //trata de numeros binarios imcompletos (não divisiveis por 4)
            quant = (round(n_casas / 4) + 1) * 4;
            quant_lim = quant - n_casas;
            for(int i = 0; i < quant; i++) { //passa de char para int e completa com zeros a esquerda
                if(i < quant_lim) { 
                    bin_fmt[i] = 0;
                }
                else {
                    bin_fmt[i] = bin_usr[i - quant_lim] - '0';
                }
            }   
        }
        else { //trata de numeros binarios completos (divisiveis por 4)
            quant = n_casas;
            for(int i = 0; i < quant; i++) { //passa de char para int
                bin_fmt[i] = bin_usr[i] - '0';
            }
        }

        dec = 0;
        pos = 3;
        reg = false;
        for(int i = 0; i < quant; i++) { //divide o numero binario (de 4 em 4) e os converte para decimal
            dec += (bin_fmt[i] * pow(2, pos));

            if(pos == 0 && dec != 0) {
                reg = true;
            }

            if(pos == 0) { //imprime o algarismo hexadecimal e reseta a contagem regressiva que divide o numero binario (de 4 em 4)
                if(reg == false && dec != 0) { //exclue as possiveis divisões do binario que são apenas zeros a esquerda
                    reg = true;
                }
                switch(dec) { //imprime o algarismo correspondente ao numero decimal
                    case 10:
                        printf("A");
                        break;
                    case 11:
                        printf("B");
                        break;
                    case 12:
                        printf("C");
                        break;
                    case 13:
                        printf("D");
                        break;
                    case 14:
                        printf("E");
                        break;
                    case 15:
                        printf("F");
                        break;
                    default:
                        if(reg == true) { //só permite imprimir caso nao seja um zero a esquerda
                            printf("%d", dec);
                            break;
                        }
                        else {
                            break;
                        }
                }
                dec = 0;
                pos = 4;
            }
            pos--;
        }
    }
    printf("\n----------------------------------");
}

void hex_dec() { //converte de hexadecimal para decimal  
    printf("Hexadecimal -> Decimal\n");
    printf("----------------------------------\n");
    
    int i, dec, n_alg;
    char hex[50];
    bool check = false;
    char algarismos[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    while(check == false) { //checa se os caracteres estao de acordo com os algarismos hexadecimais
        printf("Hexadecimal: ");
        scanf("%s", hex);

        i = 0;
        while(hex[i] != '\0') {
            
            if(islower(hex[i])){ //checa se o caractere esta minusculo e converte para maiusculo
                hex[i] = toupper(hex[i]);
            }
            
            check = false;
            for(int j = 0; j < 16; j++) { //checa se o caractere esta de acordo com os algarismos hexadecimais
                if(hex[i] == algarismos[j]) {
                    check = true;
                }
            }

            if(check == false) {
                system("cls");
                printf("Hexadecimal -> Decimal\n");
                printf("-------------------------------------\n");
                printf(">Caracter invalido! Insira novamente<\n");
                printf("-------------------------------------\n");
                break;
            }
            ++i;
        }
    } 

    i = 0;
    n_alg = 0;
    while(hex[i] != '\0') { //conta o número de algarismos do num hex
        if(islower(hex[i])) {
            hex[i] = toupper(hex[i]);
        }
        n_alg++;
        ++i;
    }
    
    i = 0;
    dec = 0;
    while(hex[i] != '\0') { //calcula o numero decimal a partir de cada algarismo hexadecimal
        n_alg--;
        switch(hex[i]) {
            case 'A':
                dec += 10 * (int)pow(16, n_alg);
                break;
            case 'B':
                dec += 11 * (int)pow(16, n_alg);
                break;
            case 'C':
                dec += 12 * (int)pow(16, n_alg);
                break;
            case 'D':
                dec += 13 * (int)pow(16, n_alg);
                break;
            case 'E':
                dec += 14 * (int)pow(16, n_alg);
                break;
            case 'F':
                dec += 15 * (int)pow(16, n_alg);
                break;
            default:
                dec += (hex[i] - '0') * (int)pow(16, n_alg);
        }
        
        ++i;
    }
    
    system("cls");
    printf("Hexadecimal -> Decimal\n");
    printf("-------------------------------------\n");
    printf("Hexadecimal: %s\n", hex);
    printf("Decimal: %d", dec); //imprime o numero decimal
    printf("\n----------------------------------");
}

void hex_bin() { //converte de hexadecimal para binario
    printf("Hexadecimal -> Binario\n");
    printf("-------------------------------------\n");

    int i;
    char hex[50];
    bool check = false;
    char algarismos[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    
    while(check == false) { //pede para o usuário digitar novamente até os algarismos estarem de acordo
        printf("Hexadecimal: ");
        scanf("%s", hex);

        i = 0;
        while(hex[i] != '\0') {
            
            if(islower(hex[i])){ //checa se o caractere esta minusculo e converte para maiusculo
                hex[i] = toupper(hex[i]);
            }
            
            for(int j = 0; j < 16; j++) { //checa se o caractere esta de acordo com os algarismos hexadecimais
                if(hex[i] == algarismos[j]) {
                    check = true;
                }
            }

            if(check == false) {
                system("cls");
                printf("Hexadecimal -> Binario\n");
                printf("-------------------------------------\n");
                printf(">Caracter invalido! Insira novamente<\n");
                printf("-------------------------------------\n");
                break;
            }
            ++i;
        }
    } 

    system("cls");
    printf("Hexadecimal -> Binario\n");
    printf("-------------------------------------\n");
    printf("Hexadecimal: %s\n", hex);
    printf("Binario: ");

    if(hex[0] == '0' && hex[1] == '\0') { 
        printf("0");
    }
    else {
        i = 0;
        while(hex[i] != '\0') { //Imprime o numero binario correspondente
            if(i == 0 && (hex[i] - '0') < 8) {
                switch(hex[i]) {
                    case '0':
                        break;
                    case '1':
                        printf("1");
                        break;
                    case '2':
                        printf("10");
                        break;
                    case '3':
                        printf("11");
                        break;
                    case '4':
                        printf("100");
                        break;
                    case '5':
                        printf("101");
                        break;
                    case '6':
                        printf("110");
                        break;
                    case '7':
                        printf("111");
                        break;
                }
            }
            else {
                switch(hex[i]) {
                    case '0':
                        printf("0000");
                        break;
                    case '1':
                        printf("0001");
                        break;
                    case '2':
                        printf("0010");
                        break;
                    case '3':
                        printf("0011");
                        break;
                    case '4':
                        printf("0100");
                        break;
                    case '5':
                        printf("0101");
                        break;
                    case '6':
                        printf("0110");
                        break;
                    case '7':
                        printf("0111");
                        break;
                    case '8':
                        printf("1000");
                        break;
                    case '9':
                        printf("1001");
                        break;
                    case 'A':
                        printf("1010");
                        break;
                    case 'B':
                        printf("1011");
                        break;
                    case 'C':
                        printf("1100");
                        break;
                    case 'D':
                        printf("1101");
                        break;
                    case 'E':
                        printf("1110");
                        break;
                    case 'F':
                        printf("1111");
                        break;
                    default:
                        break;
                }
            }
            ++i;
        }
    }
    printf("\n----------------------------------");
}

void hex_oct() {

    

}

void oct_dec() {} //TBA

void oct_bin() {} //TBA

void oct_hex() {} //TBA