#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[24];
typedef struct contagiado {
    cadena rut;
    cadena nombre;
    int edad;
    int fechaDiagnostico;
    cadena region;
    struct contagiado* link;
} nodo;

typedef nodo* enlace;
typedef enlace catastro[16];
int printMenu();
void eliminar(enlace* L, cadena rut);
int buscarRut(catastro u, cadena rut);
int seleccionarRegion();
void calcularDias(int fecha1, int fecha2);
void stringRegion(int i, cadena nombreRegion);
int printMenu()
{
    int opcion;
    printf("\nPresione su opcion: \n");
    printf("0.-Imprimir lista de pacientes\n");
    printf("1.-Agregar un paciente.\n2.-Eliminar paciente.\n3.-Buscar paciente.\n4.-Obtener porcentaje mayores de 70\n5.-Desplegar todos los pacientes de una region.\n6.-Salir.");
    printf("\n\n");
    printf("Opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
void inicializar(catastro u)
{
    for (int i = 0; i < 16; i++) {
        u[i] = NULL;
    }
}
void agregar(catastro u) // funcion encargada de agregar un nodo
{

    cadena rut, nombre;
    enlace p;
    p = (enlace)malloc(sizeof(nodo));
    int region;
    cadena nombreRegion;
    printf("Ingrese la region a la que pertenece: \n");
    printf("1.-Tarapaca.\n2.-Antofagasta.\n3.-Atacama.\n4.-Coquimbo.\n5.-Valparaiso.\n6.-O'higgins.\n7.-El Maule.\n8.-El Bio-Bio.\n");
    printf("9.-Araucania\n10.-Los Lagos.\n11.-Aysen.\n12.-Magallanes y Antartida chilena.\n13.-Region Metropolitana de Santiago.\n14.-Los Rios.\n15.-Arica y Parinacota\n16.-Nuble\n\n\n");
    printf("Region: ");
    scanf("%d", &region);

    region = region - 1; // para que sea acorde al array
    stringRegion(region, nombreRegion);

    printf("Ingrese su rut: ");
    scanf("%s", rut);
    int encontrado = buscarRut(u, rut); //llama a la funcion.
    if (encontrado) {
        printf("Rut ya registrado, intente nuevamente.\n");
        return;
    }
    strcpy(p->rut, rut);
    
    printf("Ingrese su nombre: ");
    //fflush(stdin);
    setbuf(stdin,NULL);
    fgets(nombre, 24, stdin);
    strcpy(p->nombre, nombre);
    printf("Ingrese su edad: ");
    scanf("%d", &p->edad);
    printf("Ingrese su fecha de diagnostico [AAAAMMDD]: ");
    scanf("%d", &p->fechaDiagnostico);
    strcpy(p->region, nombreRegion);

    //No es necesario fijarse si el primero es NULL porque se esta agregando al principio.
    //enlace* cabeza= &u[region]; //es un puntero a una variable de tipo enlace, u[region] es de tipo enlace. y & retorna la direccion de memoria de u[region]
    p->link = u[region]; // p->link apunta a la lista antigua. esto hace una dereferenciacion. 
    //*cabeza = p;//la direccion memoria sea igual al nuevo nodo.
    u[region]=p;
}
void stringRegion(int region, cadena respuesta)
{

    region++;

    if (region == 1) {
        strcpy(respuesta, "Tarapaca");

        //return respuesta;
    }
    else if (region == 2) {
        strcpy(respuesta, "Antofagasta");
        //return respuesta;
    }
    else if (region == 3) {
        strcpy(respuesta, "Atacama");
        //return respuesta;
    }
    else if (region == 4) {
        strcpy(respuesta, "Coquimbo");
        //return respuesta;
    }
    else if (region == 5) {
        strcpy(respuesta, "Valparaiso");
        //return respuesta;
    }
    else if (region == 6) {
        strcpy(respuesta, "Ohiggins");
        //return respuesta;
    }
    else if (region == 7) {
        strcpy(respuesta, "Maule");
        //return respuesta;
    }
    else if (region == 8) {
        strcpy(respuesta, "Bio Bio");
        //return respuesta;
    }
    else if (region == 9) {
        strcpy(respuesta, "Araucania");
        //return respuesta;
    }
    else if (region == 10) {
        strcpy(respuesta, "Los lagos");
        //return respuesta;
    }
    else if (region == 11) {
        strcpy(respuesta, "Aysen");
        //return respuesta;
    }
    else if (region == 12) {
        strcpy(respuesta, "Magallenes");
        //return respuesta;
    }
    else if (region == 13) {
        strcpy(respuesta, "Metropolitana");
        //return respuesta;
    }
    else if (region == 14) {
        strcpy(respuesta, "Los rios");
        //return respuesta;
    }
    else if (region == 15) {
        strcpy(respuesta, "Arica");
        //return respuesta;
    }
    else if (region == 16) {
        strcpy(respuesta, "Nuble");
        //return respuesta;
    }
    else {
        strcpy(respuesta, "region no valida.");
        //return respuesta;
    }
}
void interaccionAgregar(catastro u)
{
    int volver;
    do {
        agregar(u); // se va a la funcion agregar, se completa y pregunta.
        printf("Desea agregar otro contagiado: \n");
        printf("1.-Si.\n2.-No.\n");
        printf("Opcion: ");
        scanf("%d", &volver);
        system("cls"); // borra la pantalla
    } while (1 == volver);
}
void print(catastro u)
{

    for (int i = 0; i < 16; i++) {
        enlace ptr = u[i];

        while (ptr != NULL) {
            printf("*****************************\n");
            printf("Edad: %d\n", ptr->edad);
            printf("Fecha de diagnostico:%d\n", ptr->fechaDiagnostico);
            printf("Nombre: %s", ptr->nombre);
            printf("rut: %s\n", ptr->rut);
            printf("region: %s\n", ptr->region); //imprimir la string de region.
            printf("*****************************\n");
            ptr = ptr->link; //pasa al siguiente nodo
        }
    }
}
void interaccionEliminar(catastro u)
{
    cadena rutEliminado;
    cadena rut;
    int regionEliminada;

    printf("Rut a eliminar: ");
    scanf("%s", rut);
    strcpy(rutEliminado, rut);
    printf("El numero region: ");
    scanf("%d", &regionEliminada);
    eliminar(&u[regionEliminada - 1], rutEliminado); // se va a la funcion eliminarNodo.
}
void eliminar(enlace* L, cadena rut)
{
    enlace p, q;

    p = *L;
    q = *L;

    if (strcmp(q->rut, rut) == 0) {

        *L = q->link;
        free(q);
        q = NULL;

        return;
    }
    while (q != NULL) {

        if (strcmp(q->rut, rut) != 0) {
            p = q;
            q = q->link;
        }
        else {
            p->link = q->link;
            printf("\n%s\n", p->rut); // para que hay un printf aqui?
            free(q);
            q = NULL;
        }
    }
}
void buscar(catastro u, cadena region)
{
    int regionSeleccionada;
    regionSeleccionada = seleccionarRegion();
    enlace q = u[regionSeleccionada];
    cadena RUT;
    //printf("\nretorno: \n",regionSeleccionada);
    printf("Dijite el rut que desea buscar: ");
    scanf("%s", RUT);

    while (q != NULL) {

        if (strcmp(q->rut, RUT) == 0) {
            printf("*************************\n");
            printf("Nombre: %s", q->nombre);
            printf("Rut: %s\n", q->rut);
            printf("Edad: %d\n", q->edad);
            printf("Fecha de diagnostico: %d\n", q->fechaDiagnostico);
            printf("*************************\n");
            return;
        }
        else {
            q = q->link;
        }
    }
    return;
}
int seleccionarRegion()
{

    cadena REGION, Tarapaca, Antofagasta, Atacama, Coquimbo, Valparaiso, Ohiggins, Maule, Biobio;
    cadena Araucania, LosLagos, Aysen, Magallanes, Metropolitana, Losrios, Arica, nuble;
    strcpy(Tarapaca, "tarapaca");
    strcpy(Antofagasta, "antofagasta");
    strcpy(Atacama, "atacama");
    strcpy(Coquimbo, "coquimbo");
    strcpy(Valparaiso, "valparaiso");
    strcpy(Ohiggins, "ohiggins");
    strcpy(Maule, "maule");
    strcpy(Biobio, "biobio");
    strcpy(Araucania, "araucania");
    strcpy(LosLagos, "los lagos");
    strcpy(Aysen, "aysen");
    strcpy(Magallanes, "magallanes");
    strcpy(Metropolitana, "metropolita");
    strcpy(Losrios, "los rios");
    strcpy(Arica, "arica");
    strcpy(nuble, "nuble");

    printf("Opciones disponibles:  \n");
    printf("----------------------------------------\n");
    printf("tarapaca, antofagasta, atacama, coquimbo, valparaiso, ohiggins, maule,\nbiobio, araucania, Los lagos, aysen, magallanes, metropolitana, los rios, arica, nuble");
    printf("\n----------------------------------------\n");

    printf("Ingrese el nombre de la region: ");
    printf("\n");
    setbuf(stdin,NULL); //lo setea a nulo.
    fgets(REGION,24,stdin);

    if (strcmp(REGION, Tarapaca) == 0) {

        return 0;
    }
    else if (strcmp(REGION, Antofagasta) == 0) {
        return 1;
    }
    else if (strcmp(REGION, Atacama) == 0) {
        return 2;
    }
    else if (strcmp(REGION, Coquimbo) == 0) {
        return 3;
    }
    else if (strcmp(REGION, Valparaiso) == 0) {
        return 4;
    }
    else if (strcmp(REGION, Ohiggins) == 0) {
        return 5;
    }
    else if (strcmp(REGION, Maule) == 0) {
        return 6;
    }
    else if (strcmp(REGION, Biobio) == 0) {
        return 7;
    }
    else if (strcmp(REGION, Araucania) == 0) {
        return 8;
    }
    else if (strcmp(REGION, LosLagos) == 0) {
        return 9;
    }
    else if (strcmp(REGION, Aysen) == 0) {
        return 10;
    }
    else if (strcmp(REGION, Magallanes) == 0) {
        return 11;
    }
    else if (strcmp(REGION, Metropolitana) == 0) {
        return 12;
    }
    else if (strcmp(REGION, Losrios) == 0) {
        return 13;
    }
    else if (strcmp(REGION, Arica) == 0) {
        return 14;
    }
    else if (strcmp(REGION, nuble) == 0) {
        return 15;
    }
    else {

        return -1;
    }
}
void obtener(catastro u)
{

    int mayores = 0, total = 0;
    float porcentaje;

    for (int i = 0; i < 16; i++) {
        enlace ptr = u[i];

        while (ptr != NULL) {
            total++;
            if (ptr->edad > 70) {
                mayores++;
                ptr=ptr->link;
              
            }
            else {
                ptr = ptr->link;
                
            }
        }
    }
    porcentaje = mayores * 100 / total;
    printf("\nPorcentaje de personas mayores: %f\n", porcentaje);
    return;
}
int buscarRut(catastro u, cadena rut)
{

    for (int i = 0; i < 16; i++) {
        enlace ptr = u[i];
        while (ptr != NULL) {

            if (strcmp(ptr->rut, rut) == 0) {
                return 1;
            }
            else {
                ptr = ptr->link;
            }
        }
    }
    return 0;
}

void desplegar(catastro u, cadena region)
{
    //printf("La funcion aun no esta implemtanda\n");
    //return;
    printf("\nFuncion desplegar \n");

    int regionSeleccionada = seleccionarRegion();
    if (regionSeleccionada == -1) {
        printf("\nEsta region no existe.");
        return;
    }
    enlace ptr = u[regionSeleccionada];
    int fecha, diasContagio;

    printf("Ingrese la fecha del dia de hoy[AAAAMMDD]: ");
    scanf("%d", &fecha);
    printf("\n\n");

    while (ptr != NULL) {
        printf("************************\n");
        printf("Nombre: %s", ptr->nombre);
        printf("Rut: %s\n", ptr->rut);
        printf("Edad: %d\n", ptr->edad);
        printf("Fecha de diagnostico: %d\n", ptr->fechaDiagnostico);
        printf("Region: %s\n", ptr->region);
        calcularDias(fecha, ptr->fechaDiagnostico);
        
        ptr=ptr->link;
        
    }
printf("************************\n");
}
void calcularDias(int fecha1, int fecha2)
{

    int mesCon = fecha2 % 10000;
    mesCon = mesCon / 100;
    int diaCon = fecha2 % 100;
    int anoCon = fecha2 / 10000;
    int mes = fecha1 % 10000;
    mes = mes / 100;
    int dia = fecha1 % 100;
    int ano = fecha1 / 10000;

    if (anoCon > ano) {
        printf("año no valido.\n");
        return ;
    }
    else if (anoCon == ano && mesCon > mes) {
        printf("mes no valido.\n");
        return ;
    }
    else if (anoCon == ano && mesCon > mes && diaCon > dia) {
        printf("dia no valido\n");
        return ;
    }

    /*printf("dia%d\n",dia);
printf("%d\n",mes);
printf("%d\n",ano);*/
    // fecha 2 es actual.

    int diffano, diffdia, diffmes;

    if (dia >= diaCon)
        diffdia = dia - diaCon;
    else {
        dia += 30;
        mes -= 1;
        diffdia = dia - diaCon;
    }
    if (mes >= mesCon)
        diffmes = mes - mesCon;
    else {
        mes += 12;
        ano -= 1;
        diffmes = mes - mesCon;
    }
    diffano = ano - anoCon;
    int diasTotales;
    diasTotales = diffdia + diffmes * 30 + diffano * 365;

    printf("La cantidad de dias de contagio son: %d\n", diasTotales);
    return;
}

int main(void)
{

    catastro u;
    cadena region;
    
    inicializar(u);
        while (1) {

        switch (printMenu()) {
        case 0:
            print(u);
            break;
        case 1:
            interaccionAgregar(u);
            break;
        case 2:
            interaccionEliminar(u);
            break;
        case 3:
            buscar(u, region);
            break;
        case 4:
            obtener(u);
            break;
        case 5:
            desplegar(u, region);
            break;
        case 6: 
            return 0;        
        }
    }
    return 0;
}


 