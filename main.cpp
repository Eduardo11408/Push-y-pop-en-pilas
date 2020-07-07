
#include<iostream>
#include<stdlib.h>
using namespace std;

struct nodo{
    int numero;
    struct nodo *siguiente;
};

typedef nodo *ptrPila;

void push(ptrPila &p, int valor)
{
    ptrPila aux;
    aux = new(struct nodo);
    aux->numero = valor;
    aux->siguiente = p;
    p = aux;
}

int pop( ptrPila &p)
{
    int numero;
    ptrPila aux;
    
    aux = p;
    numero = aux->numero;
    
    p = aux->siguiente;
    delete(aux);
    
    return numero;
    
}

void listar_pila(ptrPila p)
{
	ptrPila aux;
	aux = p;
	
	while(aux != NULL)
	{
	cout<<"\t"<<aux->numero<<endl;
	aux = aux->siguiente;	
	}
}
void menu()
{
    cout<<"\n\t Menu de opciones \n\n";
    cout<<"1. Agregar"<<endl;
    cout<<"2. Eliminar"<<endl;
    cout<<"3. Mostrar elementos"<<endl;
    cout<<"4. Salir"<<endl;
    cout<<"\nSeleccione una opcion: ";
}
int main(){
    ptrPila p = NULL;
    int dato;
    int opc;
    int x;
    
    do
    {
        menu(); cin>>opc;
        
        switch(opc)
        {
            case 1:
            
            cout<<"\Digite un numero: "; cin>>dato;
            push(p,dato);
            cout<<"\n\n\t\Numero "<<dato<<" agregado\n\n";
            break;
            
            case 2:
            
            x = pop(p);
            cout<<"\n\n\tNumero "<<x<<" eliminados\n\n";
            break;
            
            case 3:
            	x = pop(p);
            	cout<<"\n\n Listando pila\n\n";
            	if(p!=NULL)
            		listar_pila(p);
            	else
            		cout<<"\n\n\tNo hay elementos"<<endl;
            		break;
        }
        cout<<endl<<endl;
        system("pause"); system("cls");
    }while(opc!=4);
    
    return 0;
}
