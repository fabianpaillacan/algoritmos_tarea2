#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char cadena[24];
typedef struct contagiado{ 
  cadena rut;
  cadena nombre;
  int edad;
  int fechaDiagnostico;
  cadena region;
  struct contagiado *link;
} nodo;

typedef nodo *enlace;
typedef enlace catastro[16];
void eliminarNodo (enlace *head, cadena rut);
int buscarRut(catastro u, cadena rut);


void inicializar (catastro u){
  
  for (int i=0; i<16; i++) {
       u[i]=NULL;
  }
}

void agregar (catastro u){
  
  int volver, region;
  cadena rut,nombre;
  enlace p,q;
    
  p=(enlace)malloc(sizeof(nodo));
      
    printf ("ingrese la region a la que pertenece: \n");
    printf ("1.-Tarapaca.\n2.-Antofagasta.\n3.-Atacama.\n4.-Coquimbo.\n5.-Valparaiso.\n6.-O'higgins.\n7.-El Maule.\n8.-El Bio-Bio.\n");
    printf ("9.-La Araucania\n10.-Los Lagos.\n11.-Aysen.\n12.-Magallanes y Antartida chilena.\n13.-Region Metropolitana de Santiago.\n14.-Los Rios.\n15.-Arica y Parinacota\n16.-Ñuble\n\n\n");
    printf("Region: ");
    scanf("%d",&region);
    region=region-1; // para que sea acorde al array
  
    printf ("ingrese su rut: ");
    scanf("%s",rut);
    int encontrado=buscarRut(u,rut);//llama a la funcion.
      
      if (encontrado){
        printf("Rut ya registrado, intente nuevamente.\n");
        return;
        }
   
    strcpy(p->rut,rut); 
    printf ("ingrese su nombre: ");
    scanf("%s",nombre);
    strcpy(p->nombre,nombre);
    printf ("\ningrese su edad: ");
    scanf("%d",&p->edad);
    printf ("ingrese su fecha de diagnostico: ");
    scanf ("%d",&p->fechaDiagnostico);
     
      enlace *L=&u[region];
       p->link=*L;
      *L=p;
}
void preguntar(catastro u){
     
  int volver;
    do{
      agregar(u); // se va a la funcion agregar, se completa y pregunta. 
      printf ("desea agregar otro contagiado: \n");
      printf("1.-Si.\n2.-No.\n");
      scanf("%d",&volver);
      system("clear"); // borra la pantalla
    }while(1==volver);
   
}   
void print (catastro u){
    
  for (int i=0; i<16; i++){
    enlace ptr=u[i]; // ptr toma el de los indices ¿?
    printf("region:  %i\n", i+1); 
      
    while (ptr!=NULL){
      printf("*****************************");
      printf ("Edad: %d\n", ptr->edad);
      printf ("Fecha de diagnostico: %d\n", ptr->fechaDiagnostico);
      printf("Nombre: %s\n",ptr->nombre);
      printf("rut: %s\n",ptr->rut);
      
      ptr=ptr->link;//pasa al siguiente nodo
    }
  }
}
void eliminar(catastro u ){
  
  cadena rutEliminado;
  cadena rut;

    int regionEliminada;
      printf("Rut a eliminar: ");
      scanf("%s", rut);
      strcpy(rutEliminado, rut);
      printf("El numero region: ");
      scanf("%d", &regionEliminada);
      eliminarNodo(&u[regionEliminada-1], rutEliminado); // se va a la funcion eliminarNodo.           
} 
void eliminarNodo (enlace *L, cadena rut){
  
  enlace p,q;
   p=*L;
   q=*L;
    printf("\n%s\n",q->rut);
      
  if(strcmp(q->rut, rut)==0){
    printf("\nentre a la condicion\n");
      
    *L = q->link;   
    free(q);
    q = NULL;
      
    return;
  }
  while(q != NULL){
    if(strcmp(q->rut, rut)!=0){
      
      p = q;
      q = q->link;
        
    }
    else{
              
      p->link = q->link;   
      printf("\n%s\n",p->rut);
      free(q);
      q = NULL;     
    }
  }
}
void buscar(cadena rut, catastro u, int region){
 
  enlace q=u[region-1];

  while(q != NULL){
    
    if(strcmp(q->rut, rut)==0){
      printf ("Edad: %d\n", q->edad);
      printf ("Fecha de diagnostico: %d\n", q->fechaDiagnostico);
      printf("Nombre: %s\n",q->nombre);
      printf("rut: %s\n",q->rut);
      
      return;
    }
    else{
      q=q->link;
    }
  }
}
void obtener(catastro u){
  
  int mayores=0, total=0;
  float porcentaje;
         
  for (int i=0; i<16; i++){
    enlace ptr=u[i];      
      
    while(ptr!=NULL){
      if(ptr->edad>70){
          mayores++;
      }
      else {
        ptr=ptr->link;
        total++;
      }    
    }
  }
    porcentaje=mayores*100/total;
    printf("\nPorcentaje de personas mayores: %f\n",porcentaje);
}
int buscarRut(catastro u, cadena rut){
 
  for (int i=0; i<16; i++){
    enlace ptr=u[i];
      
    while(ptr!=NULL){
      if(strcmp(ptr->rut, rut)==0){
        return 1;
      }
      else {
        ptr=ptr->link;
      }
    }
  }
  return 0;
}
void desplegar(){

}

 int main (void) {
   
  catastro u;
  int i,region=4;
  
  cadena rut;
  strcpy(rut,"4");
  inicializar (u);
  preguntar(u); //mejor nombre
  //print(u);
  //eliminar (u);
  //print(u);
  buscar(rut,u,region);
  obtener(u);
  desplegar();


  return 0;
}