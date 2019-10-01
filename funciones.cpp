#include "def.h"

using namespace std;


///Funciones de Entrada, Errores , emtre otros

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

bool lineas_es_vacia(CabezalLineas l)
{
    if((l.pri==NULL)&&(l.ult==NULL))
    {
        return true;
    }
    else
    {
        return false;
    }
}

///Puede ser al pedo
bool es_vacia_linea(Lineas c)
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

CMD_PARAM entrada()
{
    CMD_PARAM ent;
    char cmd[T_CORT];

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
        cout<<"Error: Comando Incorrecto."<<endl;
    }
    return ent;
}

void errores_mensajes (Comandos cmd, int error, int cod)
{
    if (error==1) //Significa que es un error
    {
        switch(cmd)
        {
        case CREATE:
            cout << "Error: Ya existe un archivo con ese nombre completo - E" << cod << "x" << cod << cod << cod << endl;
            break;
        case IF:
            if(cod==1)
            {
                cout << "Error: NO existe ese nombre completo en este directorio - E" << cod << "x" << cod << cod << cod << endl;
            }
            break;
        case TYPE:
            cout << "Error: NO existe ese nombre completo en este directorio - E" << cod << "x" << cod << cod << cod << endl;
            break;
        default:
            cout << "Error Desconocido - E" << cod << "x" << cmd << cod << cod << endl;
        }
    }
    else //es un mensaje
    {
        switch(cmd)
        {

        case TYPE:
            cout << "Mensaje: EL Archivo esta vacio - M" << cod << "x" << cod << cod << cod << endl;
            break;
        }
    }

}

bool iguales (char char1[], char char2[])
{
    if ((strcmp(char1, char2)==0))
    {
        return true;
    }
    else
    {
        return false;
    }
}



///DIR

TipoRet ret_dir(Sistema c)
{
    cmd_dir(c);
    return OK;
}

void cmd_dir(Sistema s)
{

    if (es_vacia(s))
    {
        cout<<"La direccion '/' se encuentra vacia."<<endl;
    }
    else
    {
        while (!(es_vacia(s)))
        {
            cout << s.cabezal_archivos->nombre_ext <<"     Archivo     " << s.cabezal_archivos->cant << endl;
            s.cabezal_archivos=s.cabezal_archivos->sig;
        }
    }
}




///CREATE, Funciones insercion entre otras

TipoRet ret_create(Sistema *s, char parametros[])
{
    int r;
    r=cmd_create(&*s, parametros);
    switch(r)
    {
        case 0:
            return OK;
            break;
        case 1:
            return ERROR;
            break;
        case 2:
            return NO_IMPLEMENTADO;
            break;
    }

}

Descom_param_create descompone_param_de_create(char parametros[])
{
    int ubc=0;
    int i=0;
    int u=0;
    int j=0;
    int cant_a=0;
    int cant_ext=0;

    char nombre[T_ARC];
    char ext[T_EXT];

    bool var=true;
    bool var2=true;

    Descom_param_create param;

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
            param.ubic[i]=parametros[i];
        }
        i=ubc+1;
    }

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
        param.nombre_ext[i]=0;
    }

    for (j=0;j<T_ENT;j++)
    {
        if((parametros[i]=='.')&&(var2==true))
        {
            var2=false;
        }
        if(var2==true)
        {
            nombre[u]=parametros[i];
            i++;
            u++;
            cant_a++;
        }
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

    param.cant_ayext=cant_a+cant_ext+1;
    for(u=0;u<cant_a;u++)
    {
        param.nombre_ext[u]=nombre[u];
    }

    param.nombre_ext[u]='.';
    u++;
    j=0;

    for(u=u;u<param.cant_ayext;u++)
    {
        param.nombre_ext[u]=ext[j];
        j++;
    }
    return param;
}

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

void insert_f_a(Sistema *s, char nombre_ext[], int cant_ayext)
{
    Archivos nuevo_nodo=new _nodo2;
    nuevo_nodo->sig=NULL;
    Archivos aux;

    aux=(*s).cabezal_archivos;
    int i=0;

    for(i=0;i<T_ARC_Y_EXT;i++)
    {
        nuevo_nodo->nombre_ext[i]=00;
    }
    for(i=0;i<cant_ayext;i++)
    {
        nuevo_nodo->nombre_ext[i]=nombre_ext[i];
    }

    while (aux->sig!=NULL)
    {
            aux=aux->sig;
    }
    nuevo_nodo->cant=0;
    aux->sig=nuevo_nodo;
}

int cmd_create(Sistema *s, char parametros[])
{
    int i=0;

    bool inserta; inserta=true;

    Archivos nuevo_nodo=new _nodo2;
    Archivos aux;
    Archivos aux2;
    Archivos ant;
    Archivos ult;
    ant=(*s).cabezal_archivos;
    aux=(*s).cabezal_archivos;
    aux2=(*s).cabezal_archivos;
    ult=(*s).cabezal_archivos;

    Descom_param_create param;
    param=descompone_param_de_create(parametros);

    while(aux2!=NULL)
    {
        if ((iguales(param.nombre_ext, aux2->nombre_ext))&&(inserta==true))
        {
            inserta=false;
            errores_mensajes(CREATE,1,1);
            return 1;
        }
        aux2=aux2->sig;
    }

    if (inserta==true)
    {
        if ((es_vacia(*s))||((strcmp(param.nombre_ext,(*s).cabezal_archivos->nombre_ext))<0))
        {

            insert_p_a(&(*s), param.nombre_ext, param.cant_ayext);
            return 0;
        }
        else
        {
            while(ult->sig!=NULL)
            {
                ult=ult->sig;
            }
            if ((strcmp(param.nombre_ext, ult->nombre_ext))>0)
            {
                insert_f_a(&(*s), param.nombre_ext, param.cant_ayext);
                return 0;
            }
            else
            {
                while ((strcmp(param.nombre_ext, aux->nombre_ext))>0)
                {
                    ant=aux;
                    aux=aux->sig;
                }
                nuevo_nodo->sig=aux;
                ant->sig=nuevo_nodo;
                for(i=0; i<param.cant_ayext; i++)
                {
                    nuevo_nodo->nombre_ext[i]=param.nombre_ext[i];
                }
                nuevo_nodo->cant=0;
                return 0;
            }
        }
    }
}




///IF

TipoRet ret_if(Sistema *s, char parametros[])
{
    int r;
    r=cmd_if(&*s, parametros);
    switch(r)
    {
        case 0:
            return OK;
            break;
        case 1:
            return ERROR;
            break;
        case 2:
            return NO_IMPLEMENTADO;
            break;
    }
}

Descom_param_if descompone_param_de_if(char parametros[])
{
    int ubc=0;
    int i=0;
    int u=0;
    int j=0;
    int cant_a=0;
    int cant_ext=0;

    char nombre[T_ARC];
    char ext[T_EXT];

    bool var=true;
    bool var2=true;
    bool var3=false;

    Descom_param_if param;

    for(j=0;j<60;j++)
    {
        param.ubic[j]=0;
    }

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
            param.ubic[i]=parametros[i];
        }
        i=ubc+1;
    }

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
        param.nombre_ext[j]=0;
    }
    for(j=0;j<TEXTO_MAX;j++)
    {
        param.linea[j]=0;
    }


    for (j=0;j<T_ENT;j++)
    {
        if((parametros[i]=='.')&&(var2==true))
        {
            var2=false;
        }
        if(var2==true)
        {
            nombre[u]=parametros[i];
            i++;
            u++;
            cant_a++;
        }
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

    param.cant_ayext=cant_a+cant_ext+1;
    for(u=0;u<cant_a;u++)
    {
        param.nombre_ext[u]=nombre[u];
    }

    param.nombre_ext[u]='.';
    u++;
    j=0;

    for(u=u;u<param.cant_ayext;u++)
    {
        param.nombre_ext[u]=ext[j];
        j++;
    }

    j=0;
    i++;

    for(int w=i; w<T_ENT; w++)
    {
        if((parametros[w]=='"')&&(var3==false))
        {
            var3=true;

        }
        else
        {
            if ((parametros[w]!='"')&&(var3=true)&&(j<TEXTO_MAX))
            {
                param.linea[j]=parametros[w];
                j++;
            }
            else if((parametros[w]=='"')&&(var3==true))
            {
                var3=false ;

            }
        }
    }

    return param;
}

int cmd_if(Sistema *s, char parametros[])
{
    int i=0;

    bool encontre=false;

    Archivos aux;
    Archivos aux2;
    aux=(*s).cabezal_archivos;
    aux2=(*s).cabezal_archivos;

    Descom_param_if param;
    param=descompone_param_de_if(parametros);

    Lineas nuevo_linea=new _nodo;

    for(i=0;i<TEXTO_MAX; i++)
    {
        nuevo_linea->linea_texto[i]=param.linea[i];
    }

    while(aux!=NULL)
    {

        if ((iguales(param.nombre_ext, aux->nombre_ext)))
        {
            aux2=aux;
            encontre=true;
        }
        aux=aux->sig;
    }

    if(encontre==true)
    {
        nuevo_linea->sig=NULL;
        nuevo_linea->ant=aux2->cabezal_linea.ult;

        if(lineas_es_vacia(aux2->cabezal_linea))
        {
            aux2->cabezal_linea.pri=nuevo_linea;
        }
        else
        {
            aux2->cabezal_linea.ult->sig=nuevo_linea;
        }
        aux2->cabezal_linea.ult=nuevo_linea;

        return 0;
    }
    else
    {
        errores_mensajes(IF, 1, 1);
        return 1;
    }


}



///TYPE

TipoRet ret_type(Sistema *s, char parametros[])
{
    int r;
    r=cmd_type(&*s, parametros);
    switch(r)
    {
        case 0:
            return OK;
            break;
        case 1:
            return ERROR;
            break;
        case 2:
            return NO_IMPLEMENTADO;
            break;
    }
}

int cmd_type(Sistema *s, char parametros[])
{
    int i; i=0;

    bool var=false;
    bool encontre=false;

    Lineas linea_aux;

    Archivos aux;
    Archivos aux2;

    aux=(*s).cabezal_archivos;
    aux2=(*s).cabezal_archivos;

    Descom_param_create param;
    param=descompone_param_de_create(parametros);

    while((aux!=NULL)&&(var==false))
    {
        if ((iguales(param.nombre_ext, aux->nombre_ext))&&(var==false))
        {
            aux2=aux;
            var=true;
            encontre=true;
        }
        aux=aux->sig;
    }
    linea_aux=aux2->cabezal_linea.pri;

    if(encontre==true)
    {
        if (linea_aux==NULL)
        {
            errores_mensajes(TYPE,0,1);
        }
        else
        {
            if (var==true)
            {
                while(linea_aux!=NULL)
                {
                    cout<<linea_aux->linea_texto<<endl;
                    linea_aux=linea_aux->sig;
                }
            }
        }

        return 0;
    }
    else
    {
        errores_mensajes(IF,1,1);
        return 1;
    }

}
