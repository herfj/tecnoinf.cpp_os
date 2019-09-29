#include "def.h"

using namespace std;


///Funciones de Entrada, Errores , emtre otros
CMD_PARAM entrada()
{
    CMD_PARAM ent;
    char cmd[T_CORT];
    char txt_param[T_ENT];
    char txt_bruto[T_ENT];

    bool var; var=false;

    int t_cor_valor=20;
    int i=0;
    int j;
    int u=0;
    int ubc=0; //Guarda la ultima ubicacion de: /

    ent.cmd_correcto=false;
    for(j=0;j<T_ENT;j++)
    {
        txt_bruto[i]=00;
    }

    cout<<"> ";

    cin>>cmd;
    cin.clear();
    cin.getline(txt_bruto, T_ENT, '\n');


    //    while (((txt_completo[i]!=' ')&&(txt_completo[i]!='\n'))&&(i<20))
    //    {
    //        cmd[i]=txt_completo[i];
    //        i++;
    //        cout<<"i es :"<<i<<endl;
    //        cout<<cmd<<"-"<<txt_completo<<endl;
    //    }
    //    cout<<"final de i es :"<<i<<endl;

    if (txt_bruto[i]==' ')
    {
        while (txt_bruto[i]==' ')
        {
            i++;
        }
        var=true;
    }


    while ((txt_bruto[i]!='\n')&&(var)&&(i<T_ENT))
    {
        ent.parametros[u]=txt_bruto[i];
        u++;
        i++;
    }


    if ((strcmp(cmd, "DIR"))==0)
    {
            ent.cmd=DIR;
            ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "CREATE"))==0)
    {
            ent.cmd=CREATE;
            ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "DELETE"))==0)
    {
            ent.cmd=DELETE;
            ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "UNDELETE"))==0)
    {
            ent.cmd=UNDELETE;
            ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "IC"))==0)
    {
            ent.cmd=IC;
            ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "IC"))==0)
    {
            ent.cmd=IC;
            ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "TYPE"))==0)
    {
            ent.cmd=TYPE;
            ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "IF"))==0)
    {
            ent.cmd=IF;
            ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "BC"))==0)
    {
            ent.cmd=BC;
            ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "BF"))==0)
    {
            ent.cmd=BF;
            ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "CAT"))==0)
    {
            ent.cmd=CAT;
            ent.cmd_correcto=true;
    }


    if(ent.cmd_correcto==false)
    {
        cout<<"Comando incorrecto"<<endl;
    }
    return ent;
}

Sistema crear()
{
    Sistema aux;
    aux.cabezal_archivos=NULL;
    return aux;
}

bool es_vacia(Sistema s)
{
    if (s.cabezal_archivos==NULL)
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
    return OK;
}

TipoRet ret_create(Sistema *s, char parametros[])
{
    create_arc( &*s, parametros);
    return NO_IMPLEMENTADO;
}

///Funciones

///Inserciones
void insert_p_a(Sistema *s, char nombre_ext[], int cant_ayext)
{
    Archivos nuevo_nodo=new _nodo2;

    int i=0;

    for(i=0;i<T_ARC_Y_EXT;i++)
    {
        nuevo_nodo->nombre_ext[i]=00;
    }
    for(i=0;i<cant_ayext;i++)
    {
        nuevo_nodo->nombre_ext[i]=nombre_ext[i];
    }
    nuevo_nodo->cant=0;
    nuevo_nodo->sig=(*s).cabezal_archivos;
    (*s).cabezal_archivos=nuevo_nodo;
}

void mostrar_dir(Sistema s)
{

    if (es_vacia(s))
    {
        cout<<"La direccion '/' se encuentra vacia."<<endl;
    }
    else
    {
        while (!es_vacia(s))
        {
            cout << s.cabezal_archivos->nombre_ext <<"   Archivo    " << s.cabezal_archivos->cant << endl;
            if (s.cabezal_archivos->sig!=NULL)
            {
                cout << " --- ";
            }
            s.cabezal_archivos=s.cabezal_archivos->sig;
        }
    }
}

void create_arc(Sistema *s, char parametros[])
{

    Archivos nuevo_nodo=new _nodo2;
    Archivos aux;
    Archivos ant;
    ant=(*s).cabezal_archivos;
    aux=(*s).cabezal_archivos;

    int ubc=0;
    int i=0;
    int u=0;
    int j=0;
    int cant_a=0;
    int cant_ext=0;
    int cant_ayext=0;

    char ubic[T_ENT];
    char nombre[T_ARC];
    char ext[T_EXT];
    char nombre_ext[T_ARC_Y_EXT];

    bool var=true;

    if(parametros[0]=='/')
    {
        for(i=0; i<60; i++)
        {
            if(parametros[i]=='"')
            {
                var=false;
            }
            if ((parametros[i]=='/')&&(var==true))
            {
                ubc=i;
            }
        }
        for(i=0; i<=ubc;i++)
        {
            ubic[i]=parametros[i];
        }
    }

    i=ubc+1;

    for(j=0;j<T_ARC;j++)
    {
        nombre[j]=0;
    }

    for(j=0;j<T_EXT;j++)
    {
        ext[j]=0;
    }
    for(j=0;j<T_ARC_Y_EXT;j++)
    {
        nombre_ext[i]=0;
    }

    while (parametros[i]!='.')
    {
        nombre[u]=parametros[i];
        i++;
        u++;
        cant_a++;
    }

    i++;
    u=0;
    var=true;

    for(j=0;j<T_EXT;j++)
    {
        if (((parametros[i]==' ')||(parametros[i]=='\n'))&&(i<T_ENT))
        {
            var=false;
        }
        if(var==true)
        {
            ext[j]=parametros[i];
            i++;
            cant_ext++;
        }
    }

    cant_ayext=cant_a+cant_ext+1;
    for(u=0;u<cant_a;u++)
    {
        nombre_ext[u]=nombre[u];
    }

    nombre_ext[u]='.';
    u++;
    j=0;

    for(u=u;u<cant_ayext;u++)
    {
        nombre_ext[u]=ext[j];
        j++;
    }
    cout<<""<<endl;
    cout<<nombre<<endl;
    cout<<ext<<endl;
    cout<<nombre_ext<<endl;
    cout<<""<<endl;
    if(es_vacia(*s)) //|(Aca va strcomper)*/
    {
        cout<<"entre"<<endl;
        insert_p_a(&(*s), nombre_ext, cant_ayext);
    }
//    else
//    {
//        if(valor>c.cfin->dato)
//        {
//            return insert_f(c, valor);
//        }
//        else
//        {
//            while (aux->dato<valor)
//            {
//                aux=aux->sig;
//                ant=aux->ant;
//            }
//            nuevo_nodo->sig=aux;
//            aux->ant=nuevo_nodo;
//            nuevo_nodo->ant=ant;
//            ant->sig=nuevo_nodo;
//        }
//    }

}
