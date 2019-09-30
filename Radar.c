/*  El ejército de EE. UU. necesita desarrollar un programa para modelar el avance de sus tropas en el frente de batalla. Para ello se requiere que el programa
modele un mapa de 10 x 10 km. En dicho mapa se deberán modelar la cantidad de tropas. Cada tropa puede tener una cantidad de soldados, otra cantidad de humvees
y otra cantidad de tanques. Con este programa, el comandante de la ofensiva puede armar tropas y ubicarlas en el mapa para un ataque efectivo. Además, cada tropa
debe poder identificase como “aliado” o “enemigo”, de manera que el comandante pueda evaluar la cantidad de fuerzas aliadas y enemigas con el mismo programa.

-Decir si los aliados son mas que los enemigos
-Si los soldados tienen 1 de Ataque, Humvees 2 y Tanques 3, decir quien tiene mas "poder de fuego"*/

#include<stdio.h>


typedef struct
{
    char inicioLetra;
    char bando;
    int inicioNum;
    int soldados;
    int humvees;
    int tanques;
}tropas;

void loop(tropas mapa[][10]);
void inicio(tropas mapa[][10]);
void imprimirRadar(tropas mapa[][10]);
void ingresarDatos(tropas mapa[][10]);
void mapaFinish(tropas mapa[][10]);


int main()
{
    tropas mapa[10][10];

    loop(mapa);

    return 0;
}

void loop(tropas mapa[][10])
{
    inicio(mapa);
    imprimirRadar(mapa);
    ingresarDatos(mapa);
    mapaFinish(mapa);
}

void inicio (tropas mapa[][10])
{
    int i,j,num;
    char letra;

    letra='A';

    for(i=0;i<10;i++)
    {
        num=1;

        for(j=0;j<10;j++)
        {
            mapa[i][j].bando='0';
            mapa[i][j].soldados=0;
            mapa[i][j].humvees=0;
            mapa[i][j].tanques=0;
            mapa[i][j].inicioLetra=letra;
            mapa[i][j].inicioNum=num++;
        }
        letra++;
    }
}

void imprimirRadar(tropas mapa[][10])
{
    int i,j;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(j<9)
            {
                printf("%c %d | ", mapa[i][j].inicioLetra, mapa[i][j].inicioNum);
            }else
            {
                printf("%c %d", mapa[i][j].inicioLetra, mapa[i][j].inicioNum);
            }
        }
        if(i<9)
        {
           printf("\n-----------------------------------------------------------\n");
        }
    }
    printf("\n\n");
}

void ingresarDatos(tropas mapa[][10])
{
    int filavec,columna, bando, repetir;
    char fila;

    repetir=1;

    do
    {
        printf("\nIngrese letra de Fila: ");
        scanf("%c",&fila);
        fflush(stdin);
        printf("\nIngrese numero de Columna: ");
        scanf("%d",&columna);
        fflush(stdin);

        switch(fila)
        {
            case 'A':
            case 'a': filavec=0;
            break;
            case 'B':
            case 'b': filavec=1;
            break;
            case 'C':
            case 'c': filavec=2;
            break;
            case 'D':
            case 'd': filavec=3;
            break;
            case 'E':
            case 'e': filavec=4;
            break;
            case 'F':
            case 'f': filavec=5;
            break;
            case 'G':
            case 'g': filavec=6;
            break;
            case 'H':
            case 'h': filavec=7;
            break;
            case 'I':
            case 'i': filavec=8;
            break;
            case 'J':
            case 'j': filavec=9;
        }

        printf("\nIngrese A si las tropas son Aliadas o E si son Enemigas: ");
        scanf("%c",&mapa[filavec][columna-1].bando);
        fflush(stdin);
        printf("\nIngrese numero de Soldados: ");
        scanf("%d",&mapa[filavec][columna-1].soldados);
        fflush(stdin);
        printf("\nIngrese numero de Humvees: ");
        scanf("%d",&mapa[filavec][columna-1].humvees);
        fflush(stdin);
        printf("\nIngrese numero de Tanques: ");
        scanf("%d",&mapa[filavec][columna-1].tanques);
        fflush(stdin);

        printf("\nIngrese 1 para ingresar otro dato o 2 para ver mapa: ");
        scanf("%d",&repetir);
        fflush(stdin);

    }while(repetir==1);
}

void mapaFinish(tropas mapa[][10])
{
    int i,j,k;

    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(j<9)
            {
                printf("%c %d | ", mapa[i][j].bando, mapa[i][j].soldados);
            }else
            {
                printf("%c %d", mapa[i][j].bando, mapa[i][j].soldados);
            }
        }
        printf("\n");

        for(k=0;k<10;k++)
        {
            if(k<9)
            {
                printf("%d %d | ", mapa[i][k].humvees, mapa[i][k].tanques);
            }else
            {
                printf("%d %d", mapa[i][k].humvees, mapa[i][k].tanques);
            }
        }

        if(i<9)
        {
           printf("\n-----------------------------------------------------------\n");
        }
    }
}
