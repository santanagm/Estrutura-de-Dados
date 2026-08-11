#include <stdio.h>
#define MAX 20

void bubblesort(int a[], int inic, int final)
{
    int aux;
    for(int i = inic; i < final - 1; i++)
    {
        for(int j = inic; j < final - 1 - (i - inic); j++)
        {
            if(a[j] > a[j+1])
            {
                aux = a[j];
                a[j] = a[j+1];
                a[j+1] = aux;
            }
        }
    }
}

void remover(int a[], int n)
{
    int achou = 999;
    for(int i = 0; i<MAX; i++)
    {
        if(a[i] == n)
        {
            a[i] = -1;
            achou = 1;
        }
    }
    if(achou == 999) printf("O número %d não consta na sequência\n", n);
}

void add(int a[], int n)
{
    int achou = 999;
    for(int i = 0; i<MAX; i++)
    {
        if(a[i] == -1) 
        {
            achou = 1;
            a[i] = n;
            bubblesort(a, i, MAX);
            break;
        } 
    }
    if(achou == 999) printf("Não é possível adicionar mais números, sequência preenchida com 20 números.\n");
}
int main(void)
{
    int array[MAX] = {1, -1, -1, 6, -1, -1, 11, -1, -1, 14, -1, 20, -1, -1, 22, -1, 29, -1, -1, 32};
    int n, num;
    int size = sizeof(array) / sizeof(array[0]);
    while(1)
    {
        printf("Esta é a sequência atual: ");
        for (int i = 0; i <MAX; i++)
        {
            if (array[i] == -1) continue;

            printf("%d ", array[i]);
        }
        printf("\n");
        printf("\n");
        printf("Deseja adicionar ou remover algum número?\n");
        printf("\n");
        printf("Caso deseje ADICIONAR algum número, digite '1'\n");
        printf("Caso deseje REMOVER algum número, digite '2'\n");
        printf("Caso deseje manter a sequência intacta, digite '3'\n");
        scanf("%d", &n);
        if(n != 1 && n != 2 && n != 3) printf("Comando inválido!\n");
        
        else if(n == 1)
        {
            printf("Qual o número a ser adicionado?\n");
            scanf("%d", &num);
            add(array, num);
            printf("\n");
            printf("\n");
        }
        else if(n == 2)
        {
            printf("Qual o número a ser removido?\n");
            scanf("%d", &num);
            remover(array, num);
            printf("\n");
            printf("\n");
            /*printf("Esta é a sequência atual: ");
            for (int i = 0; i <MAX; i++)
            {
                if (array[i] == -1) continue;

                printf("%d ", array[i]);
            }
            printf("\n");
            printf("\n");*/
        }
        else break;
    }
    
    return 0;
}