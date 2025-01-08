#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

//Aplicação para efetuar reservas em um restaurante
//O restaurante funciona de quinta a domingo
//A aplicação mostrará a lista de reservas e quantas pessoas precisarão de assento a cada dia de funcionamento
typedef struct {
    char nome[100];
    char cpf[15];
    int diaReserva; 
    int quantPessoas;
} Reserva;

#define MAX_RESERVAS 50 // Definir um número máximo de reservas

Reserva reservas[MAX_RESERVAS];
int totalReservas = 0;


void fazerReserva();
void listarReservas();
void totalPessoasPorDia();
void exibirMenu();

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;
    do {
        exibirMenu();
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1:
                fazerReserva();
                break;
            case 2:
                listarReservas();
                break;
            case 3:
                totalPessoasPorDia();
                break;
            case 4:
                printf("\nEncerrando o programa...\n");
                break;
            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

// Menu
void exibirMenu() {
    system("cls");
    printf(" ================== \n");
    printf(" SISTEMA DE RESERVA \n");
    printf(" ================== \n");
    printf("1 - Fazer Reserva\n");
    printf("2 - Listar Reservas\n");
    printf("3 - Total De Pessoas Por Dia\n");
    printf("4 - Sair\n");
    printf("Escolha uma opção: ");
}

// Cadastro
void fazerReserva() {
    if (totalReservas >= MAX_RESERVAS) {
        printf("\nLimite máximo de reservas alcançado!\n");
        system("pause");
        return;
    }

    Reserva novaReserva;
    printf(" ============= \n");
	printf(" FAZER RESERVA \n");
    printf(" ============= \n");
    printf("Nome do reservante: ");
    fgets(novaReserva.nome, sizeof(novaReserva.nome), stdin);
    novaReserva.nome[strcspn(novaReserva.nome, "\n")] = '\0'; 

    printf("CPF: ");
    fgets(novaReserva.cpf, sizeof(novaReserva.cpf), stdin);
    novaReserva.cpf[strcspn(novaReserva.cpf, "\n")] = '\0';

    do {
        printf("Dia da reserva (1-Quinta, 2-Sexta, 3-Sábado, 4-Domingo): ");
        scanf("%d", &novaReserva.diaReserva);
    } while (novaReserva.diaReserva < 1 || novaReserva.diaReserva > 4);

    printf("Quantidade de pessoas: ");
    scanf("%d", &novaReserva.quantPessoas);
    fflush(stdin);

    reservas[totalReservas++] = novaReserva;
    printf("\nReserva Cadastrada!\n");
    system("pause");
}


void listarReservas() {
    if (totalReservas == 0) {
        printf("\nNenhuma reserva cadastrada.\n");
        system("pause");
        return;
    }

    printf(" ====================== \n");
	printf(" Listagem de Reservas \n");
	printf(" ====================== \n");
    for (int i = 0; i < totalReservas; i++) {
        printf("Nome: %s\n", reservas[i].nome);
        printf("CPF: %s\n", reservas[i].cpf);
        printf("Dia: %d\n", reservas[i].diaReserva);
        printf("Número de Pessoas na reserva: %d\n", reservas[i].quantPessoas);
        printf("===============================\n");
    }
    system("pause");
}

// Número pessoas a cada dia
void totalPessoasPorDia() {
    if (totalReservas == 0) {
        printf("\nNenhuma reserva cadastrada.\n");
        system("pause");
        return;
    }

    int dia;
    printf("\nDigite o número correspondente ao dia (1-Quinta, 2-Sexta, 3-Sábado, 4-Domingo): ");
    scanf("%d", &dia);

    if (dia < 1 || dia > 4) {
        printf("\nDia inválido! Tente novamente.\n");
        system("pause");
        return;
    }

    int totalPessoas = 0;
    for (int i = 0; i < totalReservas; i++) {
        if (reservas[i].diaReserva == dia) {
            totalPessoas += reservas[i].quantPessoas;
        }
    }

    printf("\nTotal de pessoas no dia %d: %d\n", dia, totalPessoas);
    system("pause");
}

