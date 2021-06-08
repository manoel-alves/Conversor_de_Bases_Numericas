#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include "convert.c"

void menu() { //imprime o menu de bases numericas
    system("cls");
    printf("--------------------------------\n");
    printf("Escolha as Bases para Conversão:\n");
    printf("--------------------------------\n");
    printf("(1) Decimal\n");
    printf("(2) Binário\n");
    printf("(3) Hexadecimal\n");
    printf("(4) Octal\n");
    printf("\n(0) Sair\n");
    printf("--------------------------------\n");
}

bool exec_op(char opc1, char opc2) { //executa a conversao escolhida

    char opc[50];
    bool rpt = false;
    bool check = false;
    bool rpt_op = false;
    bool check_typo = false;
    while(rpt_op == false) {
                    
        system("cls");

        check_typo = false;

        switch (opc1) {
            case '1':
                if(opc2 == '2') {
                    dec_bin();
                }
                else if(opc2 == '3') {
                    dec_hex();
                }
                else {
                    dec_oct();
                }
                break;

            case '2':
                if(opc2 == '1') {
                    bin_dec();
                }
                else if(opc2 == '3') {
                    bin_hex();
                }
                else {
                    bin_oct();
                }
                break;

            case '3':
                if(opc2 == '1') {
                    hex_dec();
                }
                else if(opc2 == '2') {
                    hex_bin();
                }
                else {

                    printf("Em desenvolvimento!\n");
                    printf("\nPressione qualquer tecla para voltar. . .");
                    getchar();
                    getchar();
                    rpt = true;
                    rpt_op = true;
                    check_typo = true;
                    hex_oct();
                
                }
                break;

            case '4':
                if(opc2 == '1') {
                    oct_dec();

                    printf("Em desenvolvimento!\n");
                    printf("\nPressione qualquer tecla para voltar. . .");
                    getchar();
                    getchar();
                    rpt = true;
                    rpt_op = true;
                    check_typo = true;

                    break;
                }
                else if(opc2 == '2') {
                    oct_bin();
                    break;
                }
                else {
                    oct_hex();

                    printf("Em desenvolvimento!\n");
                    printf("\nPressione qualquer tecla para voltar. . .");
                    getchar();
                    getchar();
                    rpt = true;
                    rpt_op = true;
                    check_typo = true;

                    break;
                }
        }

        
        while(check_typo == false) {
            printf("\nDeseja repetir? (S/N): ");
            scanf(" %s", &opc);

            if(opc[1] != '\0') {
                printf("Opcao invalida!"); 
                check_typo = false;   
            }
            else {
                if(islower(opc[0])) {
                    opc[0] = toupper(opc[0]);
                }

                if(opc[0] == 'S') {
                    rpt = true;
                    check_typo = true;
                }
                else if(opc[0] == 'N') {
                    rpt = false;
                    check_typo = true;
                }
                else {
                    printf("Opcao invalida!"); 
                    check_typo = false;   
                }
            }
        }

        while(rpt == false) { //determina se o programa sera repetido ou finalizado
            printf("Deseja realizar outra conversao? (S/N): ");
            scanf(" %s", &opc);

            if(opc[1] != '\0') {
                system("cls");
                printf("Opcao invalida!\n");
                rpt = false;
            }
            else {
                if(islower(opc[0])) {
                    opc[0] = toupper(opc[0]);
                }

                if(opc[0] == 'S') {
                    system("cls");
                    check = false;
                    rpt_op = true;
                    rpt = true;
                }
                else if(opc[0] == 'N') {
                    system("cls");
                    check = true;
                    rpt_op = true;
                    rpt = true;
                }
                else {
                    system("cls");
                    printf("Opcao invalida!\n");
                    rpt = false;
                }
            }
        } 

    }

    return check;
}

int main() { 
    
    setlocale(LC_CTYPE, "portuguese");

    char opc1[50];
    char opc2[50];
    bool rpt = false;
    bool check = false;
    bool check_opc = false;

    while(check == false) { 
        menu();

        check_opc = false;
        while(check_opc == false) { //OPCAO 1
            printf("De: ");
            
            scanf(" %s", &opc1);

            if(opc1[1] != '\0' || (opc1[0] - '0') > 4 || (opc1[0] - '0') < 0 || isalpha(opc1[0])) { //checa se a opcao e valida
                check_opc = false;
                menu();
                printf("> Opção Inválida! <\n");
                printf("----------------------------------\n");
            }          
            else {
                check_opc = true;
            }
        } 

        if(opc1[0] == '0') { //Termina o programa caso o usuario tenha escolhido 0
            check = true;
            break;
        }

        menu();

        check_opc = false;
        while(check_opc == false) { //OPCAO 2
            printf("De: %c\n", opc1[0]);
            printf("Para: ");
            scanf(" %s", &opc2);

            if(opc2[1] != '\0' || opc2[0] == opc1[0] || (opc2[0] - '0') > 4 || (opc2[0] - '0') < 0 || isalpha(opc2[0])) { //checa se e valido
                check_opc = false;
                menu();
                printf("> Opção Inválida! <\n");
                printf("----------------------------------\n");
            }
            else {
                check_opc = true;
            }
        } 

        if(opc2[0] == '0') { //Termina o programa caso o usuario tenha escolhido 0
            break;
        }

        check = exec_op(opc1[0], opc2[0]); //executa a conversao escolhida
    } 
    
    return 0;
}