#include "def.h"

using namespace std;


///Funciones de Entrada, Errores , emtre otros
Parametros entrada()
{
    Parametros ent;
    char text_sin_cmd[T_ENT];
    bool var; var=true;
    int i=0;
    int j;
    int u=0;
    int ubc=0; //Guarda la ultima ubicacion de: /
        /*
    cin.getline(txt_completo, T_ENT, '\n');
    cin.clear();
    ent.cmd=strtok(txt_completo," ");
    ent.cmd=strtok(NULL," ");
    */

    cin.getline(ent.cmd, T_ENT, ' ');
    cin.clear();
    cin.getline(text_sin_cmd, T_ENT, '.');
    cin.clear();
    cin.getline(ent.ext, T_ENT, ' ');


    cout<<text_sin_cmd<<endl;
    /*
    if(text_sin_cmd[0]=='/')
    {
        for(i=0; i<60; i++)
        {

            if(text_sin_cmd[i]=='"')
            {
                var=false;
            }
            if ((text_sin_cmd[i]=='/')&&(var==true))
            {
                ubc=i;
            }
        }
        for(i=0; i<=ubc;i++)
        {
            ent.ubic[i]=text_sin_cmd[i];
        }
    }

    i=ubc+1;
    for(j=0;j<T_ARC;j++)
    {
        ent.a_name[j]=0;
    }
    while (text_sin_cmd[i]!='.')
    {
        ent.a_name[u]=text_sin_cmd[i];
        i++;
        u++;
    }

    i++;
    u=0;
    var=true;

    for(j=0;j<T_EXT;j++)
    {
        ent.ext[j]=0;
        if((text_sin_cmd[i]!=32)||(text_sin_cmd[i]!='\n')||(text_sin_cmd!=34))
        {
            var=false;
        }
        if((u<T_EXT)&&(var==true))
        {
            ent.ext[u]=text_sin_cmd[i];
            i++;
            u++;
        }
    }
*/


    return ent;
}

Sistema crear()
{
    Sistema aux;
    aux=NULL;
    return aux;
}

bool es_vacia(Sistema c)
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

TipoRet ret_dir(Sistema c)
{
    mostrar_dir(c);
    return NO_IMPLEMENTADO;
}

///Funciones

void mostrar_dir(Sistema c)
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


