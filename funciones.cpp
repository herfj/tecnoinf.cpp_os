#include "def.h"

using namespace std;


///Funciones de Entrada, Errores , emtre otros
Cmd_Param entrada()
{
    int i; i=0;
    int i2; i2=0;
    char c; c='a';
    bool cambia; cambia=false;
    Cmd_Param ent;

    cout << "> ";
    if ((i==0)&&(c==10))
    {
            getchar();
    }
    while (c!=10)
    {
        //Repite este proceso mientras no de enter
        c=getchar();
        if (c!=10)
        {
            if (i<TAMANIO_ENT)
            {
                if ((c!=' ')&&(cambia==false))
                {
                    ent.cmd.cadena[i]=c;
                    i++;
                    ent.cmd.cant=i;
                    cambia=false;
                }
                else
                {
                    cambia=true;
                    if (c!=' ')
                    {
                        if(c!='/')
                        {
                            ent.param.cadena[i2]=c;
                            i2++;
                            i++;
                            ent.param.cant=i2;
                        }
                    }
                }
            }
        }
    }
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


