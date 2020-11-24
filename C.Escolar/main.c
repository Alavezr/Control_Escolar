#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct {
    
    int nc;
    char ap[20];
    char am[20];
    char nombre[20];
    int dia;
int mes;
int anio;
    
} datos;



/*
void crear()
{
    FILE *control;
    control=fopen("Alumnos.dat","wb");
    if (control==NULL)
        exit(1);
    fclose(control);
    
}*/


void escribir(){
   
    FILE *control;
    control=fopen("Alumnos.dat","ab");
    if (control==NULL)
        exit(1);
    
    datos dat;
    
    
    
    srand(time(NULL));
   
    dat.nc= rand() % 1001; 
    
  
   
  
    printf("Este es el numero de control: %d\n", dat.nc);
    
    printf("Ingrese apellido paterno:  ");
    
    scanf("%s", &dat.ap);
    fflush(stdin);    
    
    printf("\nIngrese apellido materno: ");

    scanf("%s",&dat.am);
    
    fflush(stdin);
    
    printf("\nIngrese el nombre: ");
    
    scanf("%s",&dat.nombre);
    
    fflush(stdin);
 
    
    printf("Ingrese año de nacimiento: ");
    scanf("%d", &dat.anio);
    fflush(stdin);
    printf("\nIngrese el mes de nacimiento: ");
    scanf("%d", &dat.mes);
    fflush(stdin);
    printf("\nIngrese el dia de nacimiento: ");
    scanf("%d", &dat.dia);
    fflush(stdin);
    
    
    
    
    fwrite(&dat, sizeof(datos), 0, control);
    
    fclose(control);
    
    
    
}

    


void leer()
{
    FILE *control;
    control=fopen("Alumnos.dat","rb");
    
    if (control==NULL)
        exit(1);
    datos dat;
    
    fread(&dat, sizeof(datos), 1, control);
    while(!feof(control))
    {
        printf("%s %s %s\n", dat.ap, dat.am, dat.nombre);
        fread(&dat, sizeof(datos), 1, control);
        
        printf("%d %d %d\n", dat.anio, dat.mes, dat.dia);
        
        fread(&dat, sizeof(datos), 1, control);
    
    }
    
    fclose(control);
}




int main()
{
    int opcion;
    do {
        
        printf("1 - Alta de nuevo alumno\n");
        printf("2 - Ver alumnos\n");
        printf("3 - Salir\n");
        printf("Ingrese su opcion: ");
        scanf("%d",&opcion);
        
        if((opcion > 3)||(opcion<=0)){
            
            printf("¡Opcion no valida! :/ \n");
        }
        
        switch (opcion) {
            
            case 1:escribir();
                   break;
            case 2:leer();
                   break;
            
            
            
        }
    } while (opcion!=3);
    
    
    
    
    
    
    return 0;
}