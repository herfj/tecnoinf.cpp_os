#include "def.h"

using namespace std;


///Funciones de Entrada, Errores , emtre otros
Parametros entrada()
{
    Parametros ent;
    char cmd[T_CORT];
    char text_bruto[T_ENT];
    char txt_completo[T_ENT];
    bool var; var=true;

    int i=0;
    int j;
    int u=0;
    int ubc=0; //Guarda la ultima ubicacion de: /

    ent.cmd_correcto=false;
    cout<<"> ";

    cin.getline(txt_completo, T_ENT, '\n');
    cin.clear();
    cmd=strtok(txt_completo," ");
    cmd=strtok(NULL," ");


    /*

    cin.getline(cmd, T_CORT, ' ');
    cin.clear();
    cin.getline(text_bruto, T_ENT, '\n');
    */
    cout<<cmd<<endl;

    if ((strcmp(cmd, "DIR"))==0)
    {
            ent.cmd=DIR;
            ent.cmd_correcto=true;
            cout<<"comando DIR"<<endl;
            ///return param_dir();
    }
    if ((strcmp(cmd, "CREATE"))==0)
    {
            ent.cmd=CREATE;
            ent.cmd_correcto=true;
            ///return param_create();
    }
    if ((strcmp(cmd, "DELETE"))==0)
    {
            ent.cmd=DELETE;
            ent.cmd_correcto=true;
            ///return param_delete();
    }
    if ((strcmp(cmd, "UNDELETE"))==0)
    {
            ent.cmd=UNDELETE;
            ent.cmd_correcto=true;
            ///return param_undelete();
    }
    if ((strcmp(cmd, "IC"))==0)
    {
            ent.cmd=IC;
            ent.cmd_correcto=true;
            ///return param_ic();
    }
    if ((strcmp(cmd, "IC"))==0)
    {
            ent.cmd=IC;
            ent.cmd_correcto=true;
            ///return param_ic();
    }
    if ((strcmp(cmd, "TYPE"))==0)
    {
            ent.cmd=TYPE;
            ent.cmd_correcto=true;
            ///return param_type();
    }
    if ((strcmp(cmd, "IF"))==0)
    {
            ent.cmd=IF;
            ent.cmd_correcto=true;
            ///return param_if();
    }
    if ((strcmp(cmd, "BC"))==0)
    {
            ent.cmd=BC;
            ent.cmd_correcto=true;
            ///return param_bc();
    }
    if ((strcmp(cmd, "BF"))==0)
    {
            ent.cmd=BF;
            ent.cmd_correcto=true;
            ///return param_bf();
    }
    if ((strcmp(cmd, "CAT"))==0)
    {
            ent.cmd=CAT;
            ent.cmd_correcto=true;
            ///return param_cat();
    }


    if(ent.cmd_correcto==true)
    {

    }



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


