#include "def.h"

using namespace std;


///Funciones de Entrada, Errores , emtre otros

Sistema crear()
{
    Sistema aux;
    aux.cabezal_archivos=NULL;
    aux.cabezal_arch_D=NULL;
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

CMD_PARAM entrada()
{
    CMD_PARAM ent;
    char cmd[T_CORT];

    char txt_bruto[T_ENT];//texto sin analizar, contiene comando, nombre, ubicacion

    bool var;
    var=false;

    int t_cor_valor=20;
    int i=0; //variables para fot
    int j;//variables para for
    int u=0;//variables para for
    int cont;
    cont=1;
    int ubc=0; //Guarda la ultima ubicacion de: /

    ent.cmd_correcto=false;
    for(j=0; j<T_ENT; j++)
    {
        txt_bruto[i]=00; //inicializa txt_bruto
    }

    cout<<"> ";

    cin>>cmd;
    cin.clear();
    cin.getline(txt_bruto, T_ENT, '\n'); //recibe la linea que ingresa el usuario

    if (txt_bruto[i]==' ')
    {
        while (txt_bruto[i]==' ')
        {
            i++;
        }
        var=true;
    }

    while ((txt_bruto[i]!='\n')&&(var)&&(i<T_ENT)) //lee la linea hasta que presiona entero se supera el tamaño estipulado
    {
        ent.parametros[u]=txt_bruto[i]; //guarda todos los caracteres que ingreso el usuario
        u++;
        i++;
    }
 ///a continuacion compara y determina que comando ingreso el usuario

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


    if(ent.cmd_correcto==false) //si lo ingresado no corresponde a ningun comando se muestra un error
    {
        cout<<""<<endl;
        cout<<"Error: Comando Incorrecto."<<endl;
        cout<<""<<endl;
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
            cout << "Error: Ya existe un archivo con ese nombre completo. - E" << cmd << "x" << cod << cod << cod << endl;
            break;
        case IF:
            if(cod==1)
            {
                cout << "Error: NO existe un archivo con ese nombre en este directorio.  - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if(cod==2)
            {
                cout << "Error: El tamaño del texto ingresado es superior al permitido. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if (cod==3)
            {
                cout << "Error: El texto a insertar en la linea debe estar entre comillas. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if (cod==4)
            {
                cout << "Error: Has superado el limite de lineas a insertar. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            break;
        case IC:
            if(cod==1)
            {
                cout << "Error: NO existe un archivo con ese nombre en este directorio.  - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if(cod==2)
            {
                cout << "Error: El tamaño del texto ingresado es superior al permitido. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if (cod==3)
            {
                cout << "Error: El texto a insertar en la linea debe estar entre comillas. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if (cod==4)
            {
                cout << "Error: Has superado el limite de lineas a insertar. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            break;
        case DELETE:
            cout << "Error: NO existe un archivo con ese nombre en este directorio.  - E" << cmd << "x" << cod << cod << cod << endl;
            break;
        case TYPE:
            cout << "Error: NO existe un archivo con ese nombre en este directorio.  - E" << cmd << "x" << cod << cod << cod << endl;
            break;
        case UNDELETE:
            if(cod==0)
            {
                cout << "Error: NO existe un archivo a restaurar.  - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if(cod==1)
            {
                cout << "Error: NO se puede restaurar dado que ya un archivo con el mismo nombre.  - E" << cmd << "x" << cod << cod << cod << endl;
            }
            break;
        case CAT:
            if(cod==0)
            {
                cout << "Error: NO existe un archivo con el primer nombre que ingreso en este directorio.  - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if(cod==1)
            {
                cout << "Error: NO existe un archivo con el segundo nombre que ingreso en este directorio.  - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if(cod==2)
            {
                cout << "Error: Se supera el limite de lineas a insertar  - E" << cmd << "x" << cod << cod << cod << endl;
            }
            break;
        case BF:
            if(cod==0)
            {
                cout << "Error: NO agregaste un numero valido (k).  - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if(cod==1)
            {
                cout << "Error: NO existe un archivo con ese nombre en este directorio.  - E" << cmd << "x" << cod << cod << cod << endl;
            }
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
            cout << "Mensaje: EL contenido del archivo esta vacio. - M" << cmd << "x" << cod << cod << cod << endl;
            break;
        case DIR:
            cout<<"Mensaje: La direccion '/' se encuentra vacia. - M"<< cmd << "x" << cod << cod << cod << endl;
            break;
        case BF:
            cout << "Mensaje: EL contenido del archivo esta vacio. - M" << cmd << "x" << cod << cod << cod << endl;
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



///Descompocion de parametro (otorgando los datos para cada funcion)

Descom_param_name param_solo_name(char parametros[])
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

    Descom_param_name param;

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
        for(i=0; i<=ubc; i++)
        {
            param.ubic[i]=parametros[i];
        }
        i=ubc+1;
    }

    for(j=0; j<T_ARC; j++)
    {
        nombre[j]=0;
    }

    for(j=0; j<T_EXT; j++)
    {
        ext[j]=0;
    }
    for(j=0; j<T_ARC_Y_EXT; j++)
    {
        param.nombre_ext[j]=0;
    }

    for (j=0; j<T_ENT; j++)
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

    for(j=0; j<T_EXT; j++)
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
    for(u=0; u<cant_a; u++)
    {
        param.nombre_ext[u]=nombre[u];
    }

    param.nombre_ext[u]='.';
    u++;
    j=0;

    for(u=u; u<param.cant_ayext; u++)
    {
        param.nombre_ext[u]=ext[j];
        j++;
    }
    return param;
}

Descom_param_if_ic descompone_param_de_if_ic(char parametros[], Comandos cmd)
{
    int ubc=0;
    int i=0;
    int u=0;
    int j=0;
    int cant_a=0;
    int cant_ext=0;
    int cant_texto=0;

    char nombre[T_ARC];
    char ext[T_EXT];

    bool var=true;
    bool var2=true;
    bool var3=false;
    bool no_comillas=true;
    bool no_comillas2=true;
    bool primeravez=true;

    Descom_param_if_ic param;

    for(j=0; j<60; j++)
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
        for(i=0; i<=ubc; i++)
        {
            param.ubic[i]=parametros[i];
        }
        i=ubc+1;
    }

    for(j=0; j<T_ARC; j++)
    {
        nombre[j]=0;
    }

    for(j=0; j<T_EXT; j++)
    {
        ext[j]=0;
    }
    for(j=0; j<T_ARC_Y_EXT; j++)
    {
        param.nombre_ext[j]=0;
    }
    for(j=0; j<TEXTO_MAX; j++)
    {
        param.linea[j]=0;
    }


    for (j=0; j<T_ENT; j++)
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

    for(j=0; j<T_EXT; j++)
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
    for(u=0; u<cant_a; u++)
    {
        param.nombre_ext[u]=nombre[u];
    }

    param.nombre_ext[u]='.';
    u++;
    j=0;

    for(u=u; u<param.cant_ayext; u++)
    {
        param.nombre_ext[u]=ext[j];
        j++;
    }

    j=0;
    i++;

    for(int f=0; f<T_ENT; f++)
    {
        if ((parametros[f]=='"')&&(no_comillas==true))
        {
            no_comillas=false;
        }
        else
        {
            if ((parametros[f]=='"')&&(no_comillas2==true))
            {
                no_comillas2=false;
            }
        }
    }

    if ((no_comillas==false)&&(no_comillas2==false))
    {
        for(int w=i; w<T_ENT; w++)
        {
            if((parametros[w]=='"')&&(var3==false))
            {
                var3=true;

                if(primeravez==true)
                {
                    int y=w+1;

                    for(y=y;y<T_ENT;y++)
                    {
                        if ((parametros[y]!='"')&&((primeravez==true)))
                        {
                            cant_texto++;
                            param.cant_letras=cant_texto;
                        }
                        else
                        {
                            primeravez=false;
                        }
                    }
                }
                if(cant_texto>TEXTO_MAX)
                {
                    param.error=true;
                    errores_mensajes(cmd, 1, 2);
                    return param;
                }
            }
            else
            {
                if ((parametros[w]!='"')&&(var3=true)&&(j<TEXTO_MAX))
                {
                    param.linea[j]=parametros[w];
                    j++;
                    //param.cant_letras=j;
                }
                else
                {
                    if((parametros[w]=='"')&&(var3==true))
                    {
                        var3=false ;
                    }
                }
            }
        }
    }
    else
    {
        errores_mensajes(cmd, 1, 3);
        param.error=true;
    }

    return param;
}

Descom_param_name_k param_name_k(char parametros[], Comandos cmd)
{
    int ubc=0;
    int i=0;
    int u=0;
    int j=0;
    int cant_a=0;
    int cant_ext=0;

    int unidad=-1;
    int k_cant;

    char nombre[T_ARC];
    char ext[T_EXT];

    bool var=true;
    bool var2=true;
    bool k=false;

    Descom_param_name_k param;

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
        for(i=0; i<=ubc; i++)
        {
            param.ubic[i]=parametros[i];
        }
        i=ubc+1;
    }

    for(j=0; j<T_ARC; j++)
    {
        nombre[j]=0;
    }

    for(j=0; j<T_EXT; j++)
    {
        ext[j]=0;
    }
    for(j=0; j<T_ARC_Y_EXT; j++)
    {
        param.nombre_ext[j]=0;
    }

    for (j=0; j<T_ENT; j++)
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

    for(j=0; j<T_EXT; j++)
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

    for(int df=i;df<T_ENT;df++)
    {
        if(parametros[df]==' ')
        {

        }
        else
        {
            if((parametros[df]=='0')||(parametros[df]=='1')||(parametros[df]=='2')||(parametros[df]=='3')||(parametros[df]=='4')||(parametros[df]=='5')||(parametros[df]=='6')||(parametros[df]=='7')||(parametros[df]=='8')||(parametros[df]=='9'))
            {
                if(k==false)
                {
                    unidad=((int)parametros[df])-48;
                    k=true;
                    param.k=unidad;
                }
            }
        }
    }

    if (k==false)
    {
        errores_mensajes(cmd, 1, 0);
        param.error=true;
        return param;
    }
    param.cant_ayext=cant_a+cant_ext+1;

    for(u=0; u<cant_a; u++)
    {
        param.nombre_ext[u]=nombre[u];
    }

    param.nombre_ext[u]='.';
    u++;
    j=0;

    for(u=u; u<param.cant_ayext; u++)
    {
        param.nombre_ext[u]=ext[j];
        j++;
    }

    return param;
}

Descom_param_2name param_2_name(char parametros[])
{
    int ubc=0;
    int i=0;
    int u=0;
    int j=0;
    int cant_a=0;
    int cant_ext=0;

    char nombre[T_ARC];
    char ext[T_EXT];
    char n1[T_ENT];
    char n2[T_ENT];

    bool var=true;
    bool var2=true;

    Descom_param_2name param;
    Descom_param_name a1;
    Descom_param_name a2;
    for(i=0;i<T_ENT;i++)
    {
        if ((parametros[i]!=' ')&&(var==true))
        {
            n1[j]=parametros[i];
            j++;
        }
        else
        {
            var=false;
        }
        if ((parametros[i]!=' ')&&(var==false))
        {
            n2[u]=parametros[i];
            u++;
        }
    }
    param.a1=param_solo_name(n1);
    param.a2=param_solo_name(n2);


    return param;
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
        errores_mensajes(DIR, 0,0);
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

void insert_p_a(Sistema *s, char nombre_ext[], int cant_ayext)
{
    Archivos nuevo_nodo=new _nodo2;

    int i=0;

    for(i=0; i<T_ARC_Y_EXT; i++)
    {
        nuevo_nodo->nombre_ext[i]=00;
    }
    for(i=0; i<cant_ayext; i++)
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

    for(i=0; i<T_ARC_Y_EXT; i++)
    {
        nuevo_nodo->nombre_ext[i]=00;
    }
    for(i=0; i<cant_ayext; i++)
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

    bool inserta;
    inserta=true;

    Archivos nuevo_nodo=new _nodo2;
    Archivos aux;
    Archivos aux2;
    Archivos ant;
    Archivos ult;
    ant=(*s).cabezal_archivos;
    aux=(*s).cabezal_archivos;
    aux2=(*s).cabezal_archivos;
    ult=(*s).cabezal_archivos;

    Descom_param_name param;
    param=param_solo_name(parametros);

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

int cmd_if(Sistema *s, char parametros[])
{
    int i=0;

    bool encontre=false;

    Archivos aux;
    Archivos aux2;
    aux=(*s).cabezal_archivos;
    aux2=(*s).cabezal_archivos;

    Descom_param_if_ic param;
    param=descompone_param_de_if_ic(parametros, IF);

    Lineas nuevo_linea=new _nodo;

    if(param.error==true)
    {
        return 1;
    }

    for(i=0; i<TEXTO_MAX; i++)
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
        if(aux2->cant_lineas<LARGO_MAX)
        {
            aux2->cant=aux2->cant+param.cant_letras;
            nuevo_linea->sig=NULL;
            nuevo_linea->ant=aux2->cabezal_linea.ult;
            nuevo_linea->c=param.cant_letras;

            if(lineas_es_vacia(aux2->cabezal_linea))
            {
                aux2->cabezal_linea.pri=nuevo_linea;
            }
            else
            {
                aux2->cabezal_linea.ult->sig=nuevo_linea;
            }
            aux2->cabezal_linea.ult=nuevo_linea;
            aux2->cant_lineas=aux2->cant_lineas+1;
        }
        else
        {
            errores_mensajes(IF, 1, 4);
        }
        return 0;
    }
    else
    {
        errores_mensajes(IF, 1, 1);
        return 1;
    }
}



///IC

TipoRet ret_ic(Sistema *s, char parametros[])
{
    int r;
    r=cmd_ic(&*s, parametros);
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

int cmd_ic(Sistema *s, char parametros[])
{
    int i=0;

    bool encontre=false;

    Archivos aux;
    Archivos aux2;
    aux=(*s).cabezal_archivos;
    aux2=(*s).cabezal_archivos;

    Descom_param_if_ic param;
    param=descompone_param_de_if_ic(parametros, IC);

    Lineas nuevo_linea=new _nodo;

    if(param.error==true)
    {
        return 1;
    }

    for(i=0; i<TEXTO_MAX; i++)
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

    if (param.cant_letras>TEXTO_MAX)
    {
        errores_mensajes(IC, 1, 2);
        return 1;
    }
    if(encontre==true)
    {
        if(aux2->cant_lineas<LARGO_MAX)
        {
            aux2->cant=aux2->cant+param.cant_letras;
            nuevo_linea->ant=NULL;
            nuevo_linea->sig=aux2->cabezal_linea.pri;
            nuevo_linea->c=param.cant_letras;

            if(lineas_es_vacia(aux2->cabezal_linea))
            {

                aux2->cabezal_linea.ult=nuevo_linea;
            }
            else
            {
                aux2->cabezal_linea.pri->ant=nuevo_linea;
            }
            aux2->cabezal_linea.pri=nuevo_linea;
            aux2->cant_lineas=aux2->cant_lineas+1;
            return 0;
        }
        else
        {
            errores_mensajes(IC, 1, 4);
        }
    }
    else
    {
        errores_mensajes(IC, 1, 1);
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
    int i;
    i=0;

    bool var=false;
    bool encontre=false;

    Lineas linea_aux;

    Archivos aux;
    Archivos aux2;

    aux=(*s).cabezal_archivos;
    aux2=(*s).cabezal_archivos;

    Descom_param_name param;
    param=param_solo_name(parametros);

    if (es_vacia((*s)))
    {
        errores_mensajes(DIR,0,0);
        return 1;
    }
    else
    {
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
            if ((aux2->cabezal_linea.pri==NULL)||(aux2->cant_lineas==0))
            {
                errores_mensajes(TYPE,0,1);
                return 0;
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
            errores_mensajes(TYPE,1,1);
            return 1;
        }
    }
}



///DELETE

TipoRet ret_delete(Sistema *s, char parametros[])
{
    int r;
    r=cmd_delete(&*s, parametros);
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

void eliminar_p_a(Sistema *s)
{
    Archivos aux;
    aux=(*s).cabezal_archivos;

    (*s).cabezal_archivos=aux->sig;
    delete aux;
}

void elimnar_f_a(Sistema *s)
{
    Archivos aux;
    Archivos ant;
    aux=(*s).cabezal_archivos;
    ant=(*s).cabezal_archivos;
    while(aux->sig!=NULL)
    {
        ant=aux;
        aux=aux->sig;
    }
    ant->sig=NULL;
    delete aux;
}

int cmd_delete(Sistema *s, char parametros[])
{
    int i;
    i=0;

    bool existe=false;

    Archivos aux;
    Archivos aux2;
    Archivos ant;
    Archivos undelete=new _nodo2;

    Lineas linea_aux;

    aux = (*s).cabezal_archivos;
    aux2 = (*s).cabezal_archivos;
    ant = (*s).cabezal_archivos;

    undelete->sig=NULL;

    Descom_param_name param;
    param=param_solo_name(parametros);

    if(aux==NULL)
    {
        errores_mensajes(DIR,0,0);
        return 0;
    }
    else
    {
        while ((aux!=NULL)&&(existe==false))
        {
            if(iguales(aux->nombre_ext,param.nombre_ext))
            {
                existe=true;
                aux2=aux;
            }
            aux=aux->sig;
        }

        if(existe==false)
        {
            errores_mensajes(DELETE,1,0);
            return 1;
        }
        else
        {
            undelete->cant_lineas=aux2->cant_lineas;
            undelete->cant=aux2->cant;

            linea_aux=aux2->cabezal_linea.pri;
            undelete->cabezal_linea.pri=NULL;

            for(i=0; i<aux2->cant_lineas; i++)
            {
                Lineas nuevo_linea=new _nodo;

                for(int d=0; d<TEXTO_MAX; d++)
                {
                    nuevo_linea->linea_texto[d]=linea_aux->linea_texto[d];
                }

                nuevo_linea->sig=NULL;
                nuevo_linea->ant=undelete->cabezal_linea.ult;

                if(lineas_es_vacia(undelete->cabezal_linea))
                {
                    undelete->cabezal_linea.pri=nuevo_linea;
                }
                else
                {
                    undelete->cabezal_linea.ult->sig=nuevo_linea;
                }
                undelete->cabezal_linea.ult=nuevo_linea;
                linea_aux=linea_aux->sig;
            }

            for(i=0; i<T_ARC_Y_EXT; i++)
            {
                undelete->nombre_ext[i]=aux2->nombre_ext[i];
            }

            if((*s).cabezal_archivos==aux2)
            {
                eliminar_p_a(&*s);
            }
            else
            {
                if(aux2->sig==NULL)
                {
                    elimnar_f_a(&*s);
                }
                else
                {
                    ant->sig=aux2->sig;
                    delete aux2;
                }
            }
        }
    }
    (*s).cabezal_arch_D=undelete;
    return 0;
}


///UNDELETE

TipoRet ret_undelete(Sistema *s)
{
    int r;
    r=cmd_undelete(&*s);
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

int cmd_undelete(Sistema *s)
{
    Archivos undelete;
    Archivos ausiliar;
    Archivos aux;
    Archivos aux2;
    aux2=(*s).cabezal_archivos;

    Lineas linea_aux;

    undelete= (*s).cabezal_arch_D;
    int i;
    bool k=true;
    bool error1=false;
    int r;

    char param[T_ARC_Y_EXT];

    if(undelete==NULL)
    {
        errores_mensajes(UNDELETE, 1, 0);
        return 1;
    }

    for(i=0; i<T_ARC_Y_EXT;i++)
    {
        param[i]=undelete->nombre_ext[i];
    }

    while((aux2!=NULL)&&(error1==false))
    {
        if(iguales(aux2->nombre_ext,param))
        {
            error1=true;
        }
        aux2=aux2->sig;
    }

    if (error1==true)
    {
        errores_mensajes(UNDELETE, 1, 1);
        undelete=NULL;
        return 1;
    }

    r=cmd_create(&*s, param);
    ausiliar=(*s).cabezal_archivos;

    while((ausiliar!=NULL)&&(k))
    {
        if(iguales(ausiliar->nombre_ext,param))
        {
            k=false;
            aux=ausiliar;
        }
        ausiliar=ausiliar->sig;
    }

    aux->cant=undelete->cant;
    aux->cant_lineas=undelete->cant_lineas;

    linea_aux=undelete->cabezal_linea.pri;

    int h;

    h=aux->cant_lineas;

    for(i=0; i<h; i++)
    {
        Lineas nuevo_linea=new _nodo;

        for(int s=0; s<TEXTO_MAX; s++)
        {
            nuevo_linea->linea_texto[s]=linea_aux->linea_texto[s];
        }

        nuevo_linea->sig=NULL;
        nuevo_linea->ant=aux->cabezal_linea.ult;

        if(lineas_es_vacia(aux->cabezal_linea))
        {
            aux->cabezal_linea.pri=nuevo_linea;
        }
        else
        {
            aux->cabezal_linea.ult->sig=nuevo_linea;
        }

        aux->cabezal_linea.ult=nuevo_linea;

        linea_aux=linea_aux->sig;
    }
    cout<<"Recuperamos el archivo eliminado recientemente, “"<<aux->nombre_ext<< "”"<<endl;
    return 0;
}



///BF

TipoRet ret_bf(Sistema *s, char parametros[])
{
    int r;
    r=cmd_bf(&*s, parametros);
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

int cmd_bf(Sistema *s, char parametros[])
{
    int i;
    i=0;
    int cant_c;
    cant_c=0;

    bool existe=false;

    Archivos aux;
    Archivos aux2;

    Lineas linea_aux;

    Lineas linea_ant;

    aux = (*s).cabezal_archivos;
    aux2 = (*s).cabezal_archivos;

    Descom_param_name_k param;
    param=param_name_k(parametros, BF);

    if(param.error==true)
    {
        return 1;
    }

    if(aux==NULL)
    {
        errores_mensajes(DIR,0,0);
        return 0;
    }
    else
    {
        while ((aux!=NULL)&&(existe==false))
        {
            if(iguales(aux->nombre_ext,param.nombre_ext))
            {
                existe=true;
                aux2=aux;
            }
            aux=aux->sig;
        }

        if (existe==false)
        {
            errores_mensajes(BF,1, 1);
            return 1;
        }
        else
        {
            if(aux2->cabezal_linea.pri==NULL)
            {
                errores_mensajes(BF,0,0);
                return 0;
            }
            else
            {
                if (aux2->cant_lineas<param.k)
                {

                        aux2->cabezal_linea.pri=NULL;
                        aux2->cabezal_linea.ult=NULL;
                        aux2->cant_lineas=0;
                        aux2->cant=0;
                        return 0;
                }
                else
                {
                    if(aux2->cant_lineas==param.k)
                    {
                        aux2->cabezal_linea.pri=NULL;
                        aux2->cabezal_linea.ult=NULL;
                        aux2->cant_lineas=0;
                        aux2->cant=0;
                        return 0;
                    }
                    else
                    {

                        linea_aux=aux2->cabezal_linea.ult;
                        linea_ant=aux2->cabezal_linea.ult;

                        for(i=0; i<param.k; i++)
                        {
                            cant_c=cant_c+linea_aux->c;
                            linea_aux=linea_aux->ant;

                            linea_aux->sig=NULL;
                        }
                        aux2->cabezal_linea.ult=linea_aux;
                        aux2->cant_lineas=aux2->cant_lineas-param.k;
                        aux2->cant=aux2->cant-cant_c;
                    }
                }
            }
        }
    }
    //delete linea_aux;
    return 2;
}


///BC

TipoRet ret_bc(Sistema *s, char parametros[])
{
    int r;
    r=cmd_bc(&*s, parametros);
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

int cmd_bc(Sistema *s, char parametros[])
{
    int i;
    i=0;
    int cant_c;
    cant_c=0;

    bool existe=false;

    Archivos aux;
    Archivos aux2;

    Lineas linea_aux;

    Lineas linea_ant;

    aux = (*s).cabezal_archivos;
    aux2 = (*s).cabezal_archivos;

    Descom_param_name_k param;
    param=param_name_k(parametros, BF);

    if(param.error==true)
    {
        return 1;
    }

    if(aux==NULL)
    {
        errores_mensajes(DIR,0,0);
        return 0;
    }
    else
    {
        while ((aux!=NULL)&&(existe==false))
        {
            if(iguales(aux->nombre_ext,param.nombre_ext))
            {
                existe=true;
                aux2=aux;
            }
            aux=aux->sig;
        }

        if (existe==false)
        {
            errores_mensajes(BF,1, 1);
            return 1;
        }
        else
        {
            if(aux2->cabezal_linea.pri==NULL)
            {
                errores_mensajes(BF,0,0);
                return 0;
            }
            else
            {
                if (aux2->cant_lineas<param.k)
                {

                        aux2->cabezal_linea.ult=NULL;
                        aux2->cabezal_linea.pri=NULL;
                        aux2->cant_lineas=0;
                        aux2->cant=0;
                        return 0;
                }
                else
                {
                    if(aux2->cant_lineas==param.k)
                    {
                        aux2->cabezal_linea.ult=NULL;
                        aux2->cabezal_linea.pri=NULL;
                        aux2->cant_lineas=0;
                        aux2->cant=0;
                        return 0;
                    }
                    else
                    {

                        linea_aux=aux2->cabezal_linea.pri;
                        linea_ant=aux2->cabezal_linea.pri;

                        for(i=0; i<param.k; i++)
                        {
                            cant_c=cant_c+linea_aux->c;
                            linea_aux=linea_aux->sig;

                            linea_aux->sig=NULL;
                        }
                        aux2->cabezal_linea.pri=linea_aux;
                        aux2->cant_lineas=aux2->cant_lineas-param.k;
                        aux2->cant=aux2->cant-cant_c;
                    }
                }
            }
        }
    }
    //delete linea_aux;
    return 2;
}


///CAT

TipoRet ret_cat(Sistema *s, char parametros[])
{
    int r;
    r=cmd_cat(&*s, parametros);
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

int cmd_cat(Sistema *s, char parametros[])
{
    Descom_param_2name param;
    param=param_2_name(parametros);

    Archivos aux; //auxiliar de busqueda
    Archivos a1; //si se encuentra el archivo 1 se almacena en esta variable auxiliar
    Archivos a2; //si se encuentra el archivo 2 se almacena en esta variable auxiliar

    Lineas l_a1;
    Lineas l_a2;

    aux=(*s).cabezal_archivos;
    a1=(*s).cabezal_archivos;
    a2=(*s).cabezal_archivos;

    bool encontro_a1=false; //Sirve para sabersi lo encontro
    bool encontro_a2=false; //Sirve para sabersi lo encontro

    //Busca a1
    while((aux!=NULL)&&(encontro_a1==false))
    {
        if(iguales(aux->nombre_ext,param.a1.nombre_ext))
        {
            encontro_a1=true;
            a1=aux;
        }
        aux=aux->sig;
    }

    aux=(*s).cabezal_archivos;

    //Busca a2
    while((aux!=NULL)&&(encontro_a2==false))
    {
        if(iguales(aux->nombre_ext,param.a2.nombre_ext))
        {
            encontro_a2=true;
            a2=aux;
        }
        aux=aux->sig;
    }

    if((encontro_a1==false)||(encontro_a2==false))
    {
        if(encontro_a1==false)
        {
            errores_mensajes(CAT, 1, 0);
            return 1;
        }
        else
        {
            errores_mensajes(CAT, 1, 1);
            return 1;
        }
    }
    else
    {
        l_a1=a1->cabezal_linea.pri;
        l_a2=a2->cabezal_linea.pri;

        int h;
        h=a2->cant_lineas;
        int i;

        int cant_lineas_nueva=0;

        cant_lineas_nueva=a1->cant_lineas+a2->cant_lineas;

        if (cant_lineas_nueva>LARGO_MAX)
        {
            errores_mensajes(CAT, 1, 2);
            return 1;
        }
        else
        {
            a1->cant_lineas=cant_lineas_nueva;
            a1->cant=a1->cant+a2->cant;
            for(i=0; i<h; i++)
            {
                Lineas nuevo_linea=new _nodo;

                for(int s=0; s<TEXTO_MAX; s++)
                {
                    nuevo_linea->linea_texto[s]=l_a2->linea_texto[s];
                }

                nuevo_linea->sig=NULL;
                nuevo_linea->ant=aux->cabezal_linea.ult;

                if(lineas_es_vacia(a1->cabezal_linea))
                {
                    a1->cabezal_linea.pri=nuevo_linea;
                }
                else
                {
                    a1->cabezal_linea.ult->sig=nuevo_linea;
                }

                a1->cabezal_linea.ult=nuevo_linea;

                l_a2=l_a2->sig;
            }
        }
    }

    return 2;
}
