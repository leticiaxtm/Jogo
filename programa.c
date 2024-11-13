#include "biblioteca.h"

int gerarNumAleatorio()
{
    if (calcular.dificuldade == 1)
        return rand() % 100;
    if (calcular.dificuldade == 2)
        return rand() % 1000;
    if (calcular.dificuldade == 3)
        return rand() % 10000;
    if (calcular.dificuldade == 4)
        return rand() % 100000;
}

int gerarOperacao()
{
    int continuar;
    do
    {
     int operacao = (rand() % 3) + 1, entrada;   
        switch (operacao)
        {
        case 1:
            calcular.valor1 = gerarNumAleatorio();
            calcular.valor2 = gerarNumAleatorio();
            printf("%d + %d= ", calcular.valor1, calcular.valor2);
            scanf("%d", &entrada);
            if (somar(entrada))
            {
                continuar = 1;
                calcular.pontuacao+=calcular.dificuldade*10;
            }
            else
            {
                continuar = 0;
            }

            break;
        case 2:
            calcular.valor1 = gerarNumAleatorio();
            calcular.valor2 = gerarNumAleatorio();
            printf("%d - %d= ", calcular.valor1, calcular.valor2);
            scanf("%d", &entrada);
            if (diminuir(entrada))
            {
                continuar = 1;
                calcular.pontuacao+=calcular.dificuldade*10;
            }
            else
            {
                continuar = 0;
            }
            break;
        case 3:
            calcular.valor1 = gerarNumAleatorio();
            calcular.valor2 = gerarNumAleatorio();
            printf("%d*%d= ", calcular.valor1, calcular.valor2);
            scanf("%d", &entrada);
            if (multiplicar(entrada))
            {
                continuar = 1;
                calcular.pontuacao+=calcular.dificuldade*10;
            }
            else
            {
                continuar = 0;
            }
            break;

        default:
            break;
        }
    } while (continuar == 1);
    printf("Voce errou!! Sua pontuacao foi:%d", calcular.pontuacao);
}

void jogar()
{
    int opcao;
    do
    {
        printf("\nDigite um valor de 1 ate 4 para escolher a dificuldade do jogo:\n");
        printf("1 - Facil\n");
        printf("2 - Medio\n");
        printf("3 - Dificil\n");
        printf("4 - Insano\n");
        printf("0 - Sair\n");
        printf("-> \n");
        scanf("%d", &opcao);
        calcular.dificuldade = opcao;
        switch (opcao)
        {
        case 1:
        case 2:
        case 3:
        case 4:
            gerarOperacao();
            break;
        case 0:
            printf("Saindo...");
            return 0;
            break;
        default:
        printf("Opcao invalida!!");
            break;
        }
    } while (opcao != 0);
}

int somar(int entrada)
{                                                           // Inicio da função, criação de parâmetros.
    calcular.resultado = calcular.valor1 + calcular.valor2; // Realização da operaçãio soma.
    if (entrada == calcular.resultado)
    {             // Verificação se o resultado digitado pelo usuário está correto.
        return 1; // Retorno positivo.
    }
    else
    { // Caso o resultado esteja errado irá retornar zero
        return 0;
    }

    return 0;
}

int diminuir(int entrada)
{                                                           // Inicio da função, criação de parâmetros.
    calcular.resultado = calcular.valor1 - calcular.valor2; // Realização da operaçãio subtração.
    if (entrada == calcular.resultado)
    {             // Verificação se o resultado digitado pelo usuário está correto.
        return 1; // Retorno positivo.
    }
    else
    { // Caso o resultado esteja errado irá retornar zero
        return 0;
    }

    return 0;
}
int multiplicar(int entrada)
{                                                           // Inicio da função, criação de parâmetros.
    calcular.resultado = calcular.valor1 * calcular.valor2; // Realização da operaçãio multiplicação.
    if (entrada == calcular.resultado)
    {             // Verificação se o resultado digitado pelo usuário está correto.
        return 1; // Retorno positivo.
    }
    else
    { // Caso o resultado esteja errado irá retornar zero
        return 0;
    }

    return 0;
}