#include <stdio.h>
#include <stdlib.h>
#include "database.h"



int main()
{
    char nomeArquivo[100];

    tDatabase *db = CriaDatabase();
    LeDatabase(db);
    OrdenaDatabase(db);

     scanf(" %s", nomeArquivo);

    FILE *arquivoSaida = fopen(nomeArquivo,"wb");
    if(arquivoSaida == NULL)
        exit(1);
    int bytesSalvos = SalvarDatabase(db, arquivoSaida);
    fclose(arquivoSaida);

    printf("Numero de bytes salvos: %d\n", bytesSalvos);

    DestroiDatabase(db);

    tDatabase *dbCarregado = CriaDatabase();
    FILE *arquivoEntrada = fopen(nomeArquivo,"rb");
    if(arquivoEntrada==NULL)
        exit(1);
    int bytesCarregados = CarregaDatabase(dbCarregado, arquivoEntrada);
    fclose(arquivoEntrada);

    printf("Numero de bytes lidos: %d\n\n", bytesCarregados);

    ImprimeDatabase(dbCarregado);

    DestroiDatabase(dbCarregado);


    return 0;
}