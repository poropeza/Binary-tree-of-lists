#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct nodo
{
    int anho;
    struct nodo *siguiente;
    struct nodo_a *raiz;

};

struct nodo_a
{
  char matricula[12];
  char alumno[37];
  char tesina[50];
  struct nodo_a *h_der;
  struct nodo_a *h_izq;


};



void push_lista(struct nodo **i,struct nodo **f,int anhos);
int cargar_archivo(FILE **alias,char cad[],struct nodo **i,struct nodo **f);
struct nodo* push_lista_archivo(struct nodo ***i,struct nodo ***f,int anhos);
void imprimir_en(struct nodo *inicio);
int detectar_si_existe_el_anho(struct nodo **inicio,int a);
struct nodo_a* push_arbol(struct nodo_a *a,char mat[],char nom[],char tes[]);
void EnOrden(struct nodo_a *a);
int detectar_si_existe_el_anho_main(struct nodo *inicio,int a); //devuelve 1 si el año ya existe
int EnOrdenBuscar(struct nodo_a *a,char mat[]);
struct nodo* push_lista_main(struct nodo **i,struct nodo **f,int anhos);
int detectar_si_existe_matricula(struct nodo_a *a,char mat[]);
void preOrden(struct nodo_a *a);
void postOrden(struct nodo_a *a);
void postOrdenDelete(struct nodo_a *a);
void imprimir_pre(struct nodo *inicio);
void imprimir_pos(struct nodo *inicio);
void eliminar(struct nodo **i,struct nodo **f);
void convertir_mayuscula(char a[]);



int main()
{
   struct nodo *inicio=0, *finall=0,*aux=0;
   struct nodo_a reg;
   char archivo_abrir[30];
	FILE *alias;
	int x;
	char extraer_anho[3],mat[15];
    int anho,bandera=0,opc_imprimir;

   int opc;

   do
   {
       do
       {
       		printf("                           +-------------------+\n");
			printf("                           |                   | \n");
			printf("                           |      UPEMOR       | \n");
			printf("                           |                   |   \n");
			printf("                           |                   |  \n");
			printf("______....+-------------------+....______\n");
			printf("....------******** ______....LLLLLLLLLLLLLLLLLLL....______ ```````------....\n");
			printf(" ....------******                                       ```````------....  |\n");
			printf("|   +--------------+         _______________             +------------+    |\n");
			printf("|   |    TESINAS   |        /               \\            |  SISTEMAS  |   |\n");
			printf("|   |              |       /_________________\\           |            |\n");
			printf("|   +--------------+       | |      |      | |           +------------+    |\n");
			printf("|                          | |______|______| |                             |\n");
			printf("|__________________________|/|_____[|]_____|\\|____________________________|\n");
			printf("|__________________________|/|      |      |\\|____________________________|\n");
			printf("|                          | |______|______| |                             |\n");
			printf("|__________________________|/               \\|____________________________|\n");
       	
           printf("\n1. Cargar Informacion desde Archivo");  // La opción Cargar información se usará para agilizar la carga de información. Deberá ejecutar la lectura de un se usará para agilizar la carga de información. Deberá ejecutar la lectura de un archivo de texto con información de tesinas para comenzar a trabajar con el programa info_inicio.txt
           printf("\n2. Buscar Informacion"); // La opción de Capturar datos servirá para agregar nueva información de tesinas entregadas. La información que se capturará es: Matrícula; Nombre completo de alumno (comenzando por apellido paterno) y título de tesina (esta información será la misma que será leída del archivo de texto).
           printf("\n3. Capturar Datos"); // La opción de Buscar información servirá para obtener información de una tesina en particular. Para realizar la búsqueda se usa la matrícula de un alumno y se presentan los datos de la tesina, si es que está almacenada.
           printf("\n4. Mostrar Tesinas"); // La opción de Mostrar tesinas servirá para presentar la información de todas las tesinas almacenadas. Para esta opción, se debe permitir decidir si imprimir la información en orden, en post orden o en pre orden.
           printf("\n5. Eliminacion Completa"); // La opción de Eliminación completa servirá para borrar toda la información de tesinas almacenadas y de los nodos usados para almacenar dicha información
           printf("\n6. Salir\n");
           scanf("%d%*c",&opc);

           if(opc<1 || opc>6)
                    system("cls");


       }while(opc<1 || opc>6);

       switch(opc)
       {
         case 1:
         	
         	 if(bandera==0)
			 {
			 	  printf("\nIngrese el nombre del archivo que desea abrir:\n");
	              scanf("%[^\n]%*c",archivo_abrir);
	              
	              x=cargar_archivo(&alias,archivo_abrir,&inicio,&finall);
					
					if(x==0)
					{
						printf("Archivo cargado correctamente\n\n");
						bandera=1; //se especifica ue ya se cargó un archivo
					}
						
					else
						printf("\nNo se encuentra el archivo\n\n");
						
					
				 	
			 }
			 else
			 	printf("\nNo se puede cargar otro archivo hasta eliminar la informacion actual\n\n");

              



              break;
         case 2:
         	
         	printf("\nIngrese la matrícula a buscar: ");
         	scanf("%[^\n]%*c",mat);
         	
         	convertir_mayuscula(mat);
         	
         	
         	extraer_anho[0]=mat[4];
			extraer_anho[1]=mat[5];
			anho= atoi(extraer_anho); 
			anho=anho+2000; //ya se tiene el año de ingreso
         	
         	
         	
             if(detectar_si_existe_el_anho_main(inicio,anho)==1)
			 {
			 	aux=inicio;
			 	
			 	if(aux!=0)
				{
					do
					{
						if(aux->anho==anho)
						{
							
							if(EnOrdenBuscar(aux->raiz,mat)==0)
								printf("\nNo se encuentra la matricula en el sistema\n\n");
							else
								break;
								
							
							
						}
						aux=aux->siguiente;
								 	
					 }while(aux!=inicio);
					
				}
			 	
			 	
			 }
			 else
			 	printf("\nNo se encuentra la matrícula proporcionada\n\n");
         	
              break;
              
              
         case 3:
         		do
				 {
				 	printf("\nIngrese Matricula: ");
         		    scanf("%[^\n]%*c",reg.matricula);
				 	
				 }while(strlen(reg.matricula)<10);
				 
				 convertir_mayuscula(reg.matricula);
         		
         		
         			extraer_anho[0]=reg.matricula[4];
					extraer_anho[1]=reg.matricula[5];
					anho= atoi(extraer_anho); 
					anho=anho+2000; //ya se tiene el año de ingreso
         		
         		if(detectar_si_existe_el_anho_main(inicio,anho)==1)
				{
					
					//push arbol
					
					
					aux=inicio;
					
					do
					{
						if(aux->anho==anho)
						{
							if(detectar_si_existe_matricula(aux->raiz,reg.matricula)!=5)  //verifica ue no exista la matrcula
							{
								//se inserta el nodo binario
								printf("\nIngrese Nombre completo del alumno empezando por apellido paterno:\n ");
				         		scanf("%[^\n]%*c",reg.alumno);
				         		convertir_mayuscula(reg.alumno);
				         
				         		printf("Ingrese Titulo Tesina: ");
				         		scanf("%[^\n]%*c",reg.tesina);
				         		convertir_mayuscula(reg.tesina);
							
								aux->raiz= push_arbol(aux->raiz,reg.matricula,reg.alumno,reg.tesina);
								
								break;
								
							}
							else
								printf("\nLa matricula ya se encuentra registrada\n\n");
							
							
						}
						
						aux=aux->siguiente;
						
					}while(aux!=inicio);
					
				}
				else
				{
					printf("\nIngrese Nombre completo del alumno empezando por apellido paterno:\n ");
				    scanf("%[^\n]%*c",reg.alumno);
				    convertir_mayuscula(reg.alumno);
				    printf("Ingrese Titulo Tesina: ");
				    scanf("%[^\n]%*c",reg.tesina);
				    convertir_mayuscula(reg.tesina);
					
					aux= push_lista_main(&inicio,&finall,anho);
					aux->raiz = push_arbol(aux->raiz,reg.matricula,reg.alumno,reg.tesina);
				}
	         		
	         		
         	
              break;
              
         case 4:
         		
         		if(inicio!=0)
				 {
				 	 do
					 {
					 	printf("\nComo lo desea imprimir?\n\n");
		         		printf("\n1. Pre-Orden");
		         		printf("\n2. En-Orden");
		         		printf("\n3. Post-Orden\n");
		         		scanf("%d%*c",&opc_imprimir);
		         		
		         		if(opc_imprimir<1 || opc_imprimir>3)
		         			system("cls");
					 	
					 	
					 }while(opc_imprimir<1 || opc_imprimir>3);
					 
					 switch(opc_imprimir)
					 {
					 	case 1:
					 		imprimir_pre(inicio);
					 		
					 		break;
					 		
					 	case 2:
					 		imprimir_en(inicio);
					 		
					 		break;
					 		
					 	case 3:
					 		imprimir_pos(inicio);
					 		
					 		break;
					 }
				 	
				 }
				 else
				 	printf("\nNo hay informacion en el sistema\n\n");
         		
         		
         		
         	
         		
         	 
              break;
         case 5:
         	
         	bandera=0; //se indica ue ya se puede cargar otro archivo
         	eliminar(&inicio,&finall);
         	
              break;
         case 6:
         	  eliminar(&inicio,&finall);
              printf("\nHasta Luego\n\n");
              break;
       }

       system("pause");
       system("cls");

   }while(opc!=6);


   system("pause");

    return 0;
}

void EnOrden(struct nodo_a *a)
{
	if(a!=0)
	{
		EnOrden(a->h_izq);
		printf("\n%s %s %s",a->matricula,a->alumno,a->tesina);
		EnOrden(a->h_der);
		
	}
	
}

int EnOrdenBuscar(struct nodo_a *a,char mat[]) //regresa 0 si no consiguió
{
	int algo=0;
	
	if(a!=0)
	{
		EnOrdenBuscar(a->h_izq,mat);
		if(strncmp(a->matricula,mat,15)==0)
		{
			printf("\n%s%s%s\n",a->matricula,a->alumno,a->tesina);
			algo=1;
			return algo;
		}
		 
		EnOrdenBuscar(a->h_der,mat);
		
	}
	return algo;
	
}

int detectar_si_existe_matricula(struct nodo_a *a,char mat[]) //regresa 0 si no consiguió
{
	
	
	if(a!=0)
	{
			
			if(strncmp(a->matricula,mat,10)==0)
			{
				return 5;
				
			}
			else
			{
				if(strncmp(mat,a->matricula,10)<0)
				
					detectar_si_existe_matricula(a->h_izq,mat);
					
				else
				
					detectar_si_existe_matricula(a->h_der,mat);
			}
			
		return;
	
	}
	

return;


	
}

void imprimir_en(struct nodo *inicio)
{
	struct nodo *aux=0;
	struct nodo_a *a=0;
	
	aux=inicio;
    if(aux!=0)
	{
		do
		{
			printf("\nANHO: %d\n ",aux->anho);
			a=aux->raiz;
			
			
			if(a!=0)
			{
				EnOrden(aux->raiz);	
			}
			printf("\n-----------------");
			
			aux=aux->siguiente;
					 	
		 }while(aux!=inicio);
		
	}     		
    
}

void imprimir_pre(struct nodo *inicio)
{
	struct nodo *aux=0;
	struct nodo_a *a=0;
	
	aux=inicio;
    if(aux!=0)
	{
		do
		{
			printf("\nANHO: %d\n ",aux->anho);
			a=aux->raiz;
			
			
			if(a!=0)
			{
				preOrden(aux->raiz);	
			}
			printf("\n-----------------");
			
			aux=aux->siguiente;
					 	
		 }while(aux!=inicio);
		
	}     		
    
}

void imprimir_pos(struct nodo *inicio)
{
	struct nodo *aux=0;
	struct nodo_a *a=0;
	
	aux=inicio;
    if(aux!=0)
	{
		do
		{
			printf("\nANHO: %d\n ",aux->anho);
			a=aux->raiz;
			
			
			if(a!=0)
			{
				postOrden(aux->raiz);	
			}
			printf("\n-----------------");
			
			aux=aux->siguiente;
					 	
		 }while(aux!=inicio);
		
	}     		
    
}


void preOrden(struct nodo_a *a)
{ 
 /* si el árbol no está vacío, entonces recórrelo */
 if (a != 0) 
 { 
	 printf("\n%s %s %s",a->matricula,a->alumno,a->tesina);
	 preOrden(a->h_izq);
	 preOrden(a->h_der);
 }
}

void postOrden(struct nodo_a *a)
{ 
 /* si el árbol no está vacío, entonces recórrelo */
 if (a != 0) 
 { 
	 postOrden(a->h_izq);
	 postOrden(a->h_der);
	 printf("\n%s %s %s",a->matricula,a->alumno,a->tesina);
 }
}

void postOrdenDelete(struct nodo_a *a)
{ 
 /* si el árbol no está vacío, entonces recórrelo */
 if (a != 0) 
 { 
	 postOrdenDelete(a->h_izq);
	 postOrdenDelete(a->h_der);
	 free(a);
 }
}

void eliminar(struct nodo **i,struct nodo **f)
{
	struct nodo *aux=(*i);
	struct nodo_a *a=0;
	
	if(aux!=0)
	{
		do
		{
			a=aux->raiz;
			
			if (a != 0) 
			 { 
				postOrdenDelete(a);
			 }
			
			
			aux=aux->siguiente;
			
		}while(aux!=(*i));
		
		(*i)=0;
		(*f)=0;
			
	}
	
	
}

/*devuelve 0 si logró cargar el archivo, 1 en caso contrario*/
int cargar_archivo(FILE **alias,char cad[],struct nodo **i,struct nodo **f)/*cad es el nombre del archivo que se desea abrir)*/
{
     int error=0;
     struct nodo_a reg;
     char extraer_anho[3];
     int anho;
     struct nodo *aux=0;

     (*alias)= fopen(cad,"rt");

     if((*alias)==0)
     {
       error=1;
     }
     else
     {
       while(!feof((*alias)))
       {
       		//se almacenan todos los datos de una sola linea en la variable reg
			/*fscanf((*alias),"%s%*c",reg.matricula);
			convertir_mayuscula(reg.matricula);
			fscanf((*alias),"%s%*c",reg.apellido);
			convertir_mayuscula(reg.apellido);
			fscanf((*alias),"%s%*c",reg.nombre);
			convertir_mayuscula(reg.nombre);
			fscanf((*alias),"%[^\n]%*c",reg.tesina);
			convertir_mayuscula(reg.tesina);
			fscanf((*alias),"\n");*/
			
			fgets(reg.matricula,12,(*alias));
			convertir_mayuscula(reg.matricula);
		    fgets(reg.alumno,37,(*alias));
		    convertir_mayuscula(reg.alumno);
		    fgets(reg.tesina,50,(*alias));
		    convertir_mayuscula(reg.tesina);
		    fscanf((*alias),"\n");
		    //printf("%s%s%s", reg.matricula, reg.alumno, reg.tesina);
			
			extraer_anho[0]=reg.matricula[4];
			extraer_anho[1]=reg.matricula[5];
			
	     	//printf("\n%s",reg.matricula);
	     	
			anho= atoi(extraer_anho); 
			anho=anho+2000; //ya se tiene el año de ingreso
			
			
		//	printf("\n%d",anho);
			
			if(detectar_si_existe_el_anho(i,anho)==1)
			{
				
				//push arbol
				
				aux=(*i);
				
				do
				{
					if(aux->anho==anho)
					{
						if(detectar_si_existe_matricula(aux->raiz,reg.matricula)!=5)
						{
							//se inserta el nodo binario
						
							aux->raiz= push_arbol(aux->raiz,reg.matricula,reg.alumno,reg.tesina);
							
							break;
							
						}
						
					}
					
					aux=aux->siguiente;
					
				}while(aux!=(*i));
				
			}
			else
			{
				aux= push_lista_archivo(&i,&f,anho);
				aux->raiz = push_arbol(aux->raiz,reg.matricula,reg.alumno,reg.tesina);
			}
			
			
			
			
			
			
		/*	printf("\nmatricula: %s",reg.matricula);
			printf("\napellido: %s",reg.apellido);
			printf("\nnombre: %s",reg.nombre);
			printf("\ntesina: %s\n--------------\n",reg.tesina);*/
	
		
       }
     }
     
     fclose((*alias));

     return error;
}


struct nodo* push_lista_main(struct nodo **i,struct nodo **f,int anhos)
{
    struct nodo *nuevo=0,*q=0,*p=0;

    nuevo= (struct nodo*)malloc(sizeof(struct nodo));

    if(nuevo!=0)
    {
        nuevo->anho=anhos;

        if((*i)==0)
        {
            //se genera el nodo en la lista por primera vez
            nuevo->siguiente=nuevo;
            nuevo->raiz=0;
            (*i)=nuevo;
            (*f)=nuevo;

        }
        else
        {
            //insertar al inicio
            if(nuevo->anho < (*i)->anho)
            {
                (*f)->siguiente=nuevo;
                nuevo->siguiente=(*i);
                nuevo->raiz=0;
                (*i)=nuevo;

            }
            else
            {
                //insertar al final
                if(nuevo->anho > (*f)->anho)
                {
                    (*f)->siguiente=nuevo;
                    nuevo->siguiente=(*i);
                    nuevo->raiz=0;
                    (*f)=nuevo;

                }
                else
                {
                    //insertar en el medio
                    q=(*i);
                    p=(*i)->siguiente;

                    while(p!=(*i) && p->anho < nuevo->anho)
                    {

							p=p->siguiente;
                        	q=q->siguiente;


                    }

                    //insertar al medio
                    q->siguiente=nuevo;
                    nuevo->siguiente=p;
                    nuevo->raiz=0;


                }
            }


        }
    }

	return nuevo;
}

void push_lista(struct nodo **i,struct nodo **f,int anhos)
{
    struct nodo *nuevo=0,*q=0,*p=0;

    nuevo= (struct nodo*)malloc(sizeof(struct nodo));

    if(nuevo!=0)
    {
        nuevo->anho=anhos;

        if((*i)==0)
        {
            //se genera el nodo en la lista por primera vez
            nuevo->siguiente=nuevo;
            nuevo->raiz=0;
            (*i)=nuevo;
            (*f)=nuevo;

        }
        else
        {
            //insertar al inicio
            if(nuevo->anho < (*i)->anho)
            {
                (*f)->siguiente=nuevo;
                nuevo->siguiente=(*i);
                nuevo->raiz=0;
                (*i)=nuevo;

            }
            else
            {
                //insertar al final
                if(nuevo->anho > (*f)->anho)
                {
                    (*f)->siguiente=nuevo;
                    nuevo->siguiente=(*i);
                    nuevo->raiz=0;
                    (*f)=nuevo;

                }
                else
                {
                    //insertar en el medio
                    q=(*i);
                    p=(*i)->siguiente;

                    while(p!=(*i) && p->anho < nuevo->anho)
                    {

							p=p->siguiente;
                        	q=q->siguiente;


                    }

                    //insertar al medio
                    q->siguiente=nuevo;
                    nuevo->siguiente=p;
                    nuevo->raiz=0;


                }
            }


        }
    }


}


struct nodo* push_lista_archivo(struct nodo ***i,struct nodo ***f,int anhos)
{
    struct nodo *nuevo=0,*q=0,*p=0;

    nuevo= (struct nodo*)malloc(sizeof(struct nodo));

    if(nuevo!=0)
    {
        nuevo->anho=anhos;

        if((**i)==0)
        {
            //se genera el nodo en la lista por primera vez
            nuevo->siguiente=nuevo;
            nuevo->raiz=0;
            (**i)=nuevo;
            (**f)=nuevo;

        }
        else
        {
            //insertar al inicio
            if(nuevo->anho < (**i)->anho)
            {
                (**f)->siguiente=nuevo;
                nuevo->siguiente=(**i);
                nuevo->raiz=0;
                (**i)=nuevo;

            }
            else
            {
                //insertar al final
                if(nuevo->anho > (**f)->anho)
                {
                    (**f)->siguiente=nuevo;
                    nuevo->siguiente=(**i);
                    nuevo->raiz=0;
                    (**f)=nuevo;

                }
                else
                {
                    //insertar en el medio
                    q=(**i);
                    p=(**i)->siguiente;

                    while(p!=(**i) && p->anho < nuevo->anho)
                    {

							p=p->siguiente;
                        	q=q->siguiente;


                    }

                    //insertar al medio
                    q->siguiente=nuevo;
                    nuevo->siguiente=p;
                    nuevo->raiz=0;


                }
            }


        }
    }

	return nuevo;
}


int detectar_si_existe_el_anho(struct nodo **inicio,int a) //devuelve 1 si el año ya existe
{
	int algo=0;
	struct nodo *aux=(*inicio);
	
	if(aux!=0)
	{
		do
		{
			if(aux->anho==a)
			{
				algo=1;
				break;
			}
			aux=aux->siguiente;
					 	
		 }while(aux!=(*inicio));
		
	}
	return algo;	
}

int detectar_si_existe_el_anho_main(struct nodo *inicio,int a) //devuelve 1 si el año ya existe
{
	int algo=0;
	struct nodo *aux=inicio;
	
	if(aux!=0)
	{
		do
		{
			if(aux->anho==a)
			{
				algo=1;
				break;
			}
			aux=aux->siguiente;
					 	
		 }while(aux!=inicio);
		
	}
	return algo;	
}



struct nodo_a* push_arbol(struct nodo_a *a,char mat[],char nom[],char tes[])
{
	struct nodo_a *nuevo;
	
	if(a==0)
	{
		nuevo= (struct nodo_a*)malloc(sizeof(struct nodo_a));
		
		if(nuevo!=0)
		{
			strcpy(nuevo->matricula,mat);
			//strcpy(nuevo->apellido,ap);
			strcpy(nuevo->alumno,nom);
			strcpy(nuevo->tesina,tes);
			nuevo->h_der=0;
			nuevo->h_izq=0;
			return nuevo;
		}
	}
	else
	{
		if(strncmp(nom,a->alumno,5)<0)
		{
			//se va a la izuierda
			a->h_izq= push_arbol(a->h_izq,mat,nom,tes);
		}
		else
		{
			a->h_der = push_arbol(a->h_der,mat,nom,tes);
		}
		
		return a;
	}
}

void convertir_mayuscula(char a[])
{
	int i;
	
	for(i=0;i<strlen(a);i++)
	{
		a[i]=toupper(a[i]);
	}
}
