#include "def.h"

using namespace std;


///Funciones de Entrada, Errores , emtre otros
string entrada()
{
    string ent;
    cout<<"> ";
    cin>>ent;
    return ent;
}

Lista_archivos crear()
{
    Lista_archivos aux;
    aux=NULL;
    return aux;
}

bool es_vacia(Lista_archivos c)
{
    if(c==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}


///Funiones TipoRet

TipoRet ret_dir(Lista_archivos c)
{
    mostrar_dir(c);
    return NO_IMPLEMENTADO;
}

///Funciones

void mostrar_dir(Lista_archivos c)
{
    if (es_vacia(c))
    {
        cout<<"La direccion '/' se encuentra vacia."<<endl;
    }
    else
    {
        while (!es_vacia(c))
        {
            cout << c;
            if (c->sig!=NULL)
            {
                cout << " - ";
            }
            c=c->sig;
        }
    }
}

