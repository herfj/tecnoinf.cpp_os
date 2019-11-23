///Hernán Fbrica & Tomas Baute

#include "def.h"

using namespace std;


///Funciones Elementales

//Creacion (Inizializacion del Sistema)
Sistema crear()
{
    Sistema aux;
    aux.RAIZ=new _nodo3;
    aux.RAIZ->hermano=NULL;
    aux.RAIZ->padre=NULL;
    aux.RAIZ->cabezal_archivos=NULL;
    aux.deleteado=NULL;
    aux.actual=aux.RAIZ;
    return aux;
}

///Funciones de Consulta (tipo Bool)

bool es_raiz(Directorios s)
{
    if((s->padre==NULL)&&(s->hermano==NULL)){
        return true;
    }
    else{
        return false;
    }
}

bool es_vacia(Sistema s)
{
    if (s.RAIZ==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool es_vaciaD(Directorios s)
{
    if (s==NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool es_vaciaA(Archivos a)
{
    if (a==NULL)
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


//Funciones Muestro Errores & Mensajes

void errores_mensajes (Comandos cmd, int error, int cod)
{
    if (error==1) //Significa que es un error
    {
        switch(cmd)
        {
        case CREATE:

            if(cod==0)
            {
                cout << "Error: Ya existe un archivo con ese nombre completo. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if(cod==1)
            {
                cout << "Error: EL nombre del contiene más 15 caracteres. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if (cod==2)
            {
                cout << "Error: EL extension del contiene más 3 caracteres. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if (cod==3)
            {
                cout << "Error: No ingreso una extension. - E" << cmd << "x" << cod << cod << cod << endl;
            }

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
            if(cod==2)
            {
                cout << "Error: NO se puede restaurar dado que ya no existe el diractorio de este archivo.  - E" << cmd << "x" << cod << cod << cod << endl;
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
            if(cod==2)
            {
                cout << "Error: NO existe un archivos en este directorio.  - E" << cmd << "x" << cod << cod << cod << endl;
            }
            break;
        case MKDIR:
            if(cod==0)
            {
                cout << "Error: No se ha encontrado la ubicacion ingresada. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if(cod==1)
            {
                cout << "Error: Ya existe un directorio con ese nombre. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if(cod==2)
            {
                cout << "Error: EL nombre del contiene más 15 caracteres. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if(cod==3)
            {
                cout << "Error: EL nombre no puede se RAIZ. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            break;
        case CD:
            if(cod==0)
            {
                cout << "Error: No se ha encontrado la ubicacion ingresada. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            break;
        case DIR: //Se usa este para mencionar este error dado que no lanza error
                cout << "Error: Faltan parametros en el comando ingresado. - E" << cmd << "x" << cod << cod << cod << endl;
            break;
        case RMDIR:
            if (cod==0)
            {
                cout << "Error: No puedes eliminar un directorio ancentro el al que estas posicionado o el directorio actual. - E" << cmd << "x" << cod << cod << cod << endl;
            }
            if (cod==1)
            {
                cout << "Error: No existe el directorio que desea eliminar. - E" << cmd << "x" << cod << cod << cod << endl;
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
            cout<<"Mensaje: La direccion se encuentra vacia. - M"<< cmd << "x" << cod << cod << cod << endl;
            break;
        case BF:
            cout << "Mensaje: EL contenido del archivo esta vacio. - M" << cmd << "x" << cod << cod << cod << endl;
            break;
        }
    }

}


//Separa el comando de los parametros
void pwd_ent(Directorios u,char ubic[])
{
    int i=0;
    int c=0; //cantidad
    int tdir=T_DIR;
    tdir=tdir+1;
    bool t=false;
    char nubic[T_ENT];

    nubic[c]='/';
    c++;

    if(es_raiz(u))
    {
        cout << ubic<<"> ";
    }
    else
    {
        for(i=0;i<tdir;i++)
        {
            if(u->nombre[i]=='\0')
            {
                t=true;
            }
            if(t==false){
                nubic[c]=u->nombre[i];
                c++;
            }
        }

         for(i=0;i<T_ENT;i++)
        {
            nubic[c]=ubic[i];
            c++;
        }
        pwd_ent(u->padre, nubic);
    }
}

CMD_PARAM entrada(Directorios aux)
{
    CMD_PARAM ent;
    char cmd[T_CORT];

    char txt_bruto[T_ENT];//texto sin analizar, contiene comando, nombre, ubicacion

    bool var;
    var=false;

    int t_cor_valor=20;
    int i=0; //variables para for
    int j;//variables para for
    int u=0;//variables para for
    int cont;
    cont=1;
    int ubc=0; //Guarda la ultima ubicacion de: /

    ent.cmd_correcto=false;
    for(j=0; j<T_ENT; j++)
    {
        txt_bruto[i]=0; //inicializa txt_bruto
    }

    char nombre[T_ENT];

    if(es_raiz(aux))
    {
        cout << "> ";
    }
    else
    {

    cout << "> ";

    }


    cin>>cmd;
    cin.clear();
    cin.getline(txt_bruto, T_ENT, '\n'); //recibe la linea que ingresa el usuario

    if (txt_bruto[i]==' ')
    {
        while (txt_bruto[i]==' ')
        {
            i++;
        }
        //var=true;
    }
    //while ((txt_bruto[i]!='\n')&&(var)&&(i<T_ENT)) //lee la linea hasta que presiona enter o se supera el tamaño estipulado
    while ((txt_bruto[i]!='\n')&&(i<T_ENT)) //lee la linea hasta que presiona enter o se supera el tamaño estipulado
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
    if ((strcmp(cmd, "MKDIR"))==0)
    {
        ent.cmd=MKDIR;
        ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "CD"))==0)
    {
        ent.cmd=CD;
        ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "PWD"))==0)
    {
        ent.cmd=PWD;
        ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "RMDIR"))==0)
    {
        ent.cmd=RMDIR;
        ent.cmd_correcto=true;
    }
    if ((strcmp(cmd, "COPY"))==0)
    {
        ent.cmd=COPY;
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


//Recibe un char[] de ubicacion y retorna el directorio de la ubicacion deseada

Ubicacion mueve_nodo(Directorios dir,char ubic[])
{
    int i;
    i=0;
    int u;
    u=0;
    int j;
    j=0;
    int ubc;
    ubc=0; //guarda la nueva ubicacion de /

    bool termina=false;
    bool b1=false; //bool 1

    Directorios hijo;

    Ubicacion retorno;
    retorno.no_se_encontro=false;

    char nombre_dir[T_DIR];
    char nueva_ubic[T_ENT];

    for(j=0; j<T_DIR; j++)
    {
        nombre_dir[j]=0;
    }

    for(j=0; j<T_ENT; j++)
    {
        nueva_ubic[j]=0;
    }


    if(ubic[0]=='/')
    {
        i++;
    }
    while ((ubic[i]!='/')&&(b1==false))
    {
        if ((u<T_DIR)&&(ubic[i]!='\0'))
        {
            nombre_dir[u]=ubic[i];
            i++;
            u++;
        }
        else
        {
            b1=true;
        }
    }

    if (b1==true)
    {
        retorno.Padre=dir;
        return retorno;
    }
    else
    {
        u=0;

        for(int f=i; f<T_ENT; f++)
        {
            nueva_ubic[u]=ubic[f];
            u++;
        }

        if (es_vaciaD(dir->hijo))
        {
            retorno.no_se_encontro=true;
            return retorno;
        }
        else
        {
            hijo=dir->hijo;

            while ((hijo!=NULL)&&(termina==false))
            {
                if (iguales(hijo->nombre, nombre_dir))
                {
                    termina=true;
                    retorno=mueve_nodo(hijo, nueva_ubic);
                    return retorno;
                }
                else
                {
                    hijo=hijo->hermano;
                }
            }
            if((hijo==NULL)&&(termina==false))
            {
                retorno.no_se_encontro=true;
                return retorno;
            }
        }
    }
}


///Descompocion de parametros PARA ARCHIVOS (otorgando los datos para cada funcion)

Descom_param_name param_solo_name(char parametros[])
{
    int ubc=0;
    int i=0;
    int u=0;
    int j=0;
    int r=0;
    int cant_a=0;
    int cant_ext=0;

    char nombre[T_ARC];
    char ext[T_EXT];

    bool var=true;
    bool var2=true;

    Descom_param_name param;
    param.hay_ubc=false;
    param.absoluta=false;


    for(j=0; j<T_ENT; j++)
    {
        param.ubic[j]=0;
    }

    for(j=0; j<T_ENT; j++)
    {
        if (parametros[j]=='/')
        {
            param.hay_ubc=true;
        }
    }

    if(param.hay_ubc==true)
    {
        if(parametros[0]=='/')
        {
            param.absoluta=true;
        }

        for(i=0; i<T_ENT; i++)
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

    //Inicializacion
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
    //FIN - Inicializacion

    bool salir=true;

    for (j=0; j<T_ENT && salir; j++)
    {
        if(((parametros[i]==' ')||(parametros[i]==0)||(parametros[i]=='.'))&&(var2==true))
        {
            var2=false;
        }
        if(var2==true)
        {

            if(cant_a<T_ARC)
            {
                nombre[u]=parametros[i];
                i++;
                u++;
                cant_a++;
            }
            else
            {
                param.nombre_ext[0]='\0';
                nombre[0]='\0';
                ext[0]='\0';
                param.ubic[0]='\0';
                salir=false;
                errores_mensajes(CREATE, 1, 1);
                param.error=true;
                return param;
            }
        }
        if(cant_a>T_ARC)
        {
            param.nombre_ext[0]='\0';
            nombre[0]='\0';
            ext[0]='\0';
            param.ubic[0]='\0';
            salir=false;
            errores_mensajes(CREATE, 1, 1);
            param.error=true;
            return param;
        }
    }

    i++;
    u=0;
    var=true;

    if (((parametros[i]==' ')||(parametros[i]==0)||(parametros[i]=='\0'))&&((i<T_ENT)&&(var==true)))
    {
        param.nombre_ext[0]='\0';
        nombre[0]='\0';
        ext[0]='\0';
        param.ubic[0]='\0';
        errores_mensajes(CREATE, 1, 3);
        param.error=true;
        return param;
    }

    for(j=0; j<T_ENT; j++)
    {
        if (((parametros[i]==' ')||(parametros[i]==0)||(parametros[i]=='\0'))&&((i<T_ENT)&&(var==true)))
        {
            var=false;
        }
        if(var==true)
        {
            if(cant_ext<T_EXT)
            {
                ext[r]=parametros[i];
                r++;
                i++;
                cant_ext++;
            }
            else
            {
                param.nombre_ext[0]='\0';
                nombre[0]='\0';
                ext[0]='\0';
                param.ubic[0]='\0';
                errores_mensajes(CREATE, 1, 2);
                param.error=true;
                return param;
            }
        }
        if(cant_ext>T_EXT)
        {
            param.nombre_ext[0]='\0';
            nombre[0]='\0';
            ext[0]='\0';
            param.ubic[0]='\0';
            errores_mensajes(CREATE, 1, 2);
            param.error=true;
            return param;
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

    if(iguales(param.ubic, "/"))
    {
        param.es_raiz=true;
    }
    else
    {
        param.es_raiz=false;

    }

    return param;
}

Descom_param_if_ic param_de_if_ic(char parametros[], Comandos cmd)
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
    param.hay_ubc=false;

    for(j=0; j<60; j++)
    {
        param.ubic[j]=0;
    }
    for(j=0; j<T_ENT; j++)
    {
        if (parametros[j]=='/')
        {
            param.hay_ubc=true;
        }
    }

    if(param.hay_ubc==true)
    {
        if(parametros[0]=='/')
        {
            param.absoluta=true;
        }

        for(i=0; i<T_ENT; i++)
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

    if(iguales(param.ubic, "/"))
    {
        param.es_raiz=true;
    }
    else
    {
        param.es_raiz=false;
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

    param.hay_ubc=false;

    for(j=0; j<T_ENT; j++)
    {
        if (parametros[j]=='/')
        {
            param.hay_ubc=true;
        }
    }

    if(param.hay_ubc==true)
    {
        if(parametros[0]=='/')
        {
            param.absoluta=true;
        }

        for(i=0; i<T_ENT; i++)
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

    if(iguales(param.ubic, "/"))
    {
        param.es_raiz=true;
    }
    else
    {
        param.es_raiz=false;
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
            n1[i]=0;
            n2[i]=0;
    }

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
        if (((parametros[i]!=' ')||(parametros[i]!=0))&&(var==false))
        {
            if(parametros[i]!=' ')
            {
                n2[u]=parametros[i];
                u++;
            }
        }
    }
    param.a1=param_solo_name(n1);
    param.a2=param_solo_name(n2);
    return param;
}

///Descompocion de parametros PARA DIRECTORIOS (otorgando los datos para cada funcion)

Descom_param_name_D param_solo_name_D(char parametros[])
{
    int ubc=0;
    int i=0;
    int u=0;
    int j=0;
    int r=0;
    int cant=0;

    char nombre[T_DIR];


    bool var=true;
    bool var2=true;

    Descom_param_name_D param;
    param.hay_ubc=false;
    param.absoluta=false;


    for(j=0; j<T_ENT; j++)
    {
        param.ubic[j]=0;
    }

    for(j=0; j<T_ENT; j++)
    {
        if (parametros[j]=='/')
        {
            param.hay_ubc=true;
        }
    }

    if(param.hay_ubc==true)
    {
        if(parametros[0]=='/')
        {
            param.absoluta=true;
        }

        for(i=0; i<T_ENT; i++)
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

    for(j=0; j<T_DIR; j++)
    {
        nombre[j]=0;
        param.nombre[j]=0;
    }


    for (j=0; j<T_ENT; j++)
    {
        if(((parametros[i]==' ')||(parametros[i]==0))&&(var2==true))
        {
            var2=false;
        }
        if(var2==true)
        {
            if(cant<T_DIR)
            {
                nombre[u]=parametros[i];
                i++;
                u++;
                cant++;
            }
            else
            {
                j=100;
                param.nombre[0]='\0';
                param.ubic[0]='\0';
                param.error=true;
                return param;
            }

        }
        if(cant>T_DIR)
        {
            j=100;
            param.nombre[0]='\0';
            param.ubic[0]='\0';
            param.error=true;
            return param;
        }
    }

    u=0;
    var=true;

    for(u=0; u<cant; u++)
    {
        param.nombre[u]=nombre[u];
    }

    if(iguales(param.ubic, "/"))
    {
        param.es_raiz=true;
    }
    else
    {
        param.es_raiz=false;
    }
    return param;
}



///DIR

TipoRet ret_dir(Sistema s, char parametros[])
{
    int r;
    r=cmd_dir(s, parametros);
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

void mostrar_archivo(Archivos a, int c, bool s)
{
    int i=0;

    for(i=0;i<c;i++)
    {
        cout <<"     ";
    }
    if (s==true)
    {
        cout << a->nombre_ext <<"     Archivo"<< endl;
    }
    else
    {
        cout << a->nombre_ext <<"     Archivo     "<< a->cant <<endl;
    }

    if (!(es_vaciaA(a->sig)))
    {
        mostrar_archivo(a->sig, c, s);
    }
}

void pwd_dir(Directorios u,char ubic[])
{
    int i=0;
    int c=0; //cantidad
    int tdir=T_DIR;
    tdir=tdir+1;
    bool t=false;
    char nubic[T_ENT];

    nubic[c]='/';
    c++;

    if(es_raiz(u))
    {
        cout << "Mensaje: La direccion: ";
        cout << ubic;
        cout << " se encuentra vacia. - M0x000";
        cout << endl;

    }
    else
    {
        for(i=0;i<tdir;i++)
        {
            if(u->nombre[i]=='\0')
            {
                t=true;
            }
            if(t==false)
            {
                nubic[c]=u->nombre[i];
                c++;
            }
        }

         for(i=0;i<T_ENT;i++)
        {
            nubic[c]=ubic[i];
            c++;
        }
        pwd_dir(u->padre, nubic);
    }

}

void dir_s(Directorios d, int c)
{
    int i;

    Directorios aus;
    aus=d;
    Archivos arch;
    arch=d->cabezal_archivos;

    for(i=0;i<(c-1);i++)
    {
        cout <<"     ";
    }
    cout << d->nombre <<"     Directorio     "<< endl;
    for(i=0;i<(c-1);i++)
    {
        cout <<"     ";
    }
    cout<<"<contenido: "<< d->nombre <<">"<<endl;

    if ((es_vaciaA(arch))&&(es_vaciaD(d->hijo)))
    {
        char nombre[T_ENT];
        int i;

        for (i=0;i<T_ENT;i++)
        {
            nombre[i]='\0';
        }

        for(i=0;i<c;i++)
        {
            cout <<"     ";
        }
        pwd_dir(d,nombre);
    }
    else
    {
        if (!(es_vaciaA(arch)))
        {
            mostrar_archivo(arch, c, true);
        }
        if ((!(es_vaciaA(arch)))&&(!(es_vaciaD(d->hijo))))
        {
            cout << "" << endl;
        }
        if (!(es_vaciaD(d->hijo)))
        {
            d=d->hijo;
            if (!(es_vaciaD(d)))
            {
                dir_s(d, c+1);
            }
        }
    }

    for(i=0;i<(c-1);i++)
    {
        cout <<"     ";
    }
    cout<<"</contenido: "<< aus->nombre <<">"<<endl;

    if (!(es_vaciaD(aus->hermano)))
    {
        dir_s(aus->hermano, c);
    }
}

bool param_s(char parametros[])
{
    int i;
    if((parametros[0]=='s')||(parametros[0]=='S'))
    {
        if(parametros[1]==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int cmd_dir(Sistema s, char parametros[])
{
    Directorios aux;
    aux=s.actual;
    Archivos arch;
    arch=aux->cabezal_archivos;

    int c=0;
    bool tiene_s=false;

    Descom_param_name_D param;

    if (parametros[0]!='\0')
    {
        param=param_solo_name_D(parametros);

        if(param_s(parametros))
        {
            tiene_s=true;
        }
        else
        {
            cout<<"Mensaje: Ingreso un parametro no valido (Distinto de S). - M0x001" << endl;
            return 1;
        }

    }
    else
    {
        tiene_s=false;
    }

    if ((es_vaciaA(arch))&&(es_vaciaD(aux->hijo)))
    {
        char nombre[T_ENT];
        int i;
        if(es_raiz(aux))
        {
            cout<<"Mensaje: La direccion: ";
            cout<<"/";
            cout<<" se encuentra vacia. - M0x000" << endl;
        }
        else
        {
            for (i=0;i<T_ENT;i++)
            {
                nombre[i]='\0';
            }
            for (i=0;i<T_ENT;i++)
            {
                nombre[i]='\0';
            }
            pwd_dir(aux,nombre);
        }
    }
    else
    {
        if (!(es_vaciaA(arch)))
        {
            mostrar_archivo(arch, c, tiene_s);
        }

        if ((!(es_vaciaA(aux->cabezal_archivos)))&&(!(es_vaciaD(aux->hijo))))
        {
            cout << "" << endl;
        }

        if (!(es_vaciaD(aux->hijo)))
        {
            aux=aux->hijo;
            if(tiene_s==true)
            {
                dir_s(aux, c+1);
            }
            else
            {
                while (!(es_vaciaD(aux)))
                {
                    cout << aux->nombre <<"     Directorio     ";
                    if ((aux->tiene_cota==true)&&(tiene_s==false))
                    {
                        cout << aux->tamanio << endl;
                    }
                    else
                    {
                        cout << "" << endl;
                    }
                    aux=aux->hermano;

                }
            }
        }
    }
    return 0;
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

void create_pwd_recursivo(Directorios u,Archivos a,char ubic[])
{
    int i=0;
    int c=0; //cantidad
    int tdir=T_DIR;
    tdir=tdir+1;
    bool t=false;
    char nubic[T_ENT];

    nubic[c]='/';
        c++;

    if(es_raiz(u))
    {
        for(i=0;i<T_ENT;i++)
        {
            if(ubic[i]!='\0')
            {
                a->ubic[i]=ubic[i];
            }
            else
            {
                if(t==false)
                {
                    a->ubic[i]='/';
                    t=true;
                }
            }

        }
    }
    else
    {
        for(i=0;i<tdir;i++)
        {
            if(u->nombre[i]=='\0')
            {
                t=true;
            }
            if(t==false)
            {
                nubic[c]=u->nombre[i];
                c++;
            }
        }

        for(i=0;i<T_ENT;i++)
        {
            nubic[c]=ubic[i];
            c++;
        }

        create_pwd_recursivo(u->padre, a, nubic);
    }
}

int cmd_create(Sistema *s, char parametros[])
{
    int i=0;

    bool inserta=true;
    bool primera=true;
    bool en_raiz=false;

    Archivos nuevo_nodo=new _nodo2;

    Directorios padre;

    Ubicacion ubc_ainsertar;

    Archivos aux;
    Archivos aux2;
    Archivos ant;
    Archivos ult;


    Descom_param_name param;

    if (parametros[0]!='\0')
    {
        param=param_solo_name(parametros);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }

    if (param.error==true)
    {
        return 1;
    }


    if(param.hay_ubc==true)
    {
        if(param.absoluta==true)
        {
            if(param.es_raiz==false)
            {
                ubc_ainsertar=mueve_nodo((*s).RAIZ, param.ubic);

                if (ubc_ainsertar.no_se_encontro==false)
                {
                    padre=ubc_ainsertar.Padre;
                }
                else
                {
                    errores_mensajes(MKDIR,1,0);
                    return 1;
                }

            }
            else
            {
                en_raiz=true;
                padre=(*s).RAIZ;
            }
        }
        else
        {
            ubc_ainsertar=mueve_nodo((*s).actual, param.ubic);

            if (ubc_ainsertar.no_se_encontro==false)
            {
                padre=ubc_ainsertar.Padre;
            }
            else
            {
                errores_mensajes(MKDIR,1,0);
                return 1;
            }
        }
    }
    else
    {
        padre=(*s).actual;
    }

    ant=padre->cabezal_archivos;
    aux=padre->cabezal_archivos;
    aux2=padre->cabezal_archivos;
    ult=padre->cabezal_archivos;

    if(es_raiz(padre))
    {
        nuevo_nodo->raiz=true;
    }
    else
    {
        nuevo_nodo->raiz=false;

        if(param.absoluta==true)
        {
            for(i=0;i<T_ENT;i++)
            {
                    nuevo_nodo->ubic[i]=param.ubic[i];
            }
        }
        else
        {
            char nombre[T_ENT];

            for (i=0;i<T_ENT;i++)
            {
                nombre[i]='\0';
            }
            create_pwd_recursivo(padre, nuevo_nodo, nombre);


        }
    }

    while(aux2!=NULL)
    {
        if ((iguales(param.nombre_ext, aux2->nombre_ext))&&(inserta==true))
        {
            inserta=false;
            errores_mensajes(CREATE,1,0);
            return 1;
        }
        aux2=aux2->sig;
    }

    if (inserta==true)
    {
        for(i=0; i<T_ARC_Y_EXT; i++)
        {
            nuevo_nodo->nombre_ext[i]=00;
        }

        for(i=0; i<param.cant_ayext; i++)
        {
            nuevo_nodo->nombre_ext[i]=param.nombre_ext[i];
        }
        nuevo_nodo->cant_lineas=0;
        nuevo_nodo->cant=0;
        nuevo_nodo->cabezal_linea.pri=NULL;
        nuevo_nodo->cabezal_linea.ult=NULL;

        if ((es_vaciaA(padre->cabezal_archivos))||((strcmp(param.nombre_ext,padre->cabezal_archivos->nombre_ext))<0))
        {
            nuevo_nodo->sig=padre->cabezal_archivos;
            padre->cabezal_archivos=nuevo_nodo;

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
                nuevo_nodo->sig=NULL;
                ult->sig=nuevo_nodo;

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
    bool en_raiz=false;

    Directorios padre;

    Ubicacion ubc_ainsertar;

    Archivos aux;
    Archivos aux2;

    Descom_param_if_ic param;


    if (parametros[0]!='\0')
    {
        param=param_de_if_ic(parametros, IF);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }


    Lineas nuevo_linea=new _nodo;

    if(param.error==true)
    {
        return 1;
    }

    if(param.hay_ubc==true)
    {
        if(param.absoluta==true)
        {
            if(param.es_raiz==false)
            {
                ubc_ainsertar=mueve_nodo((*s).RAIZ, param.ubic);

                if (ubc_ainsertar.no_se_encontro==false)
                {
                    padre=ubc_ainsertar.Padre;
                }
                else
                {
                    errores_mensajes(MKDIR,1,0);
                    return 1;
                }

            }
            else
            {
                en_raiz=true;
                padre=(*s).RAIZ;
            }
        }
        else
        {
            ubc_ainsertar=mueve_nodo((*s).actual, param.ubic);

            if (ubc_ainsertar.no_se_encontro==false)
            {
                padre=ubc_ainsertar.Padre;
            }
            else
            {
                errores_mensajes(MKDIR,1,0);
                return 1;
            }
        }
    }
    else
    {
        padre=(*s).actual;
    }

    aux=padre->cabezal_archivos;
    aux2=padre->cabezal_archivos;

    for(i=0; i<TEXTO_MAX; i++)
    {
        nuevo_linea->linea_texto[i]=param.linea[i];
    }

    aux=padre->cabezal_archivos;
    aux2=padre->cabezal_archivos;

    while((aux!=NULL)&&(encontre==false))
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
    bool en_raiz=false;

    Directorios padre;

    Ubicacion ubc_ainsertar;

    Archivos aux;
    Archivos aux2;

    Descom_param_if_ic param;


    if (parametros[0]!='\0')
    {
        param=param_de_if_ic(parametros, IC);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }


    Lineas nuevo_linea=new _nodo;

    if(param.error==true)
    {
        return 1;
    }

    if(param.hay_ubc==true)
    {
        if(param.absoluta==true)
        {
            if(param.es_raiz==false)
            {
                ubc_ainsertar=mueve_nodo((*s).RAIZ, param.ubic);

                if (ubc_ainsertar.no_se_encontro==false)
                {
                    padre=ubc_ainsertar.Padre;
                }
                else
                {
                    errores_mensajes(MKDIR,1,0);
                    return 1;
                }

            }
            else
            {
                en_raiz=true;
                padre=(*s).RAIZ;
            }
        }
        else
        {
            ubc_ainsertar=mueve_nodo((*s).actual, param.ubic);

            if (ubc_ainsertar.no_se_encontro==false)
            {
                padre=ubc_ainsertar.Padre;
            }
            else
            {
                errores_mensajes(MKDIR,1,0);
                return 1;
            }
        }
    }
    else
    {
        padre=(*s).actual;
    }

    aux=padre->cabezal_archivos;
    aux2=padre->cabezal_archivos;

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

    ///____________________________VAR__________________________________
    int i=0;
    int contador=0;

    Ubicacion ubc_ainsertar;

    bool var=false;
    bool en_raiz=false;
    bool encontre=false;

    Directorios padre;

    Lineas linea_aux;

    Descom_param_name param;

    Archivos aux;
    Archivos aux2;
    ///_________________________________________________________________


    if (parametros[0]!='\0')
    {
        param=param_solo_name(parametros);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }

    if(param.hay_ubc==true)
    {
        if(param.absoluta==true)
        {
            if(param.es_raiz==false)
            {
                ubc_ainsertar=mueve_nodo((*s).RAIZ, param.ubic);

                if (ubc_ainsertar.no_se_encontro==false)
                {
                    padre=ubc_ainsertar.Padre;
                }
                else
                {
                    errores_mensajes(MKDIR,1,0);
                    return 1;
                }

            }
            else
            {
                en_raiz=true;
                padre=(*s).RAIZ;
            }
        }
        else
        {
            ubc_ainsertar=mueve_nodo((*s).actual, param.ubic);

            if (ubc_ainsertar.no_se_encontro==false)
            {
                padre=ubc_ainsertar.Padre;
            }
            else
            {
                errores_mensajes(MKDIR,1,0);
                return 1;
            }
        }
    }
    else
    {
        padre=(*s).actual;
    }


    aux=padre->cabezal_archivos;
    aux2=padre->cabezal_archivos;


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
                    while((linea_aux!=NULL)&&(contador<aux2->cant_lineas))
                    {
                        cout<<linea_aux->linea_texto<<endl;
                        linea_aux=linea_aux->sig;
                        contador++;
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

void eliminar_p_a(Directorios u)
{
    Archivos aux;
    aux=u->cabezal_archivos;

    u->cabezal_archivos=aux->sig;
    delete aux;
}

void elimnar_f_a(Directorios u)
{
    Archivos aux;
    Archivos ant;
    aux=u->cabezal_archivos;
    ant=u->cabezal_archivos;
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

    bool var=false;
    bool en_raiz=false;
    bool existe=false;

    char nombre[T_ENT];
    char *ubic[T_ENT];

    Ubicacion ubc_ainsertar;

    Directorios padre;

    Archivos aux;
    Archivos aux2;
    Archivos ant;
    Archivos undelete=new _nodo2;

    Lineas linea_aux;

    undelete->sig=NULL;

    Descom_param_name param;

    if (parametros[0]!='\0')
    {
        param=param_solo_name(parametros);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }

    if(param.hay_ubc==true)
    {
        if(param.absoluta==true)
        {
            if(param.es_raiz==false)
            {
                ubc_ainsertar=mueve_nodo((*s).RAIZ, param.ubic);

                if (ubc_ainsertar.no_se_encontro==false)
                {
                    padre=ubc_ainsertar.Padre;
                }
                else
                {
                    errores_mensajes(MKDIR,1,0);
                    return 1;
                }
            }
            else
            {
                en_raiz=true;
                padre=(*s).RAIZ;
            }
        }
        else
        {
            ubc_ainsertar=mueve_nodo((*s).actual, param.ubic);

            if (ubc_ainsertar.no_se_encontro==false)
            {
                padre=ubc_ainsertar.Padre;
            }
            else
            {
                errores_mensajes(MKDIR,1,0);
                return 1;
            }
        }
    }
    else
    {
        padre=(*s).actual;
    }


    ant=padre->cabezal_archivos;
    aux=padre->cabezal_archivos;
    aux2=padre->cabezal_archivos;

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
            undelete->raiz=aux2->raiz;

            linea_aux=aux2->cabezal_linea.pri;

            undelete->cabezal_linea.pri=NULL;

            for(i=0; i<aux2->cant_lineas; i++)
            {
                Lineas nuevo_linea=new _nodo;

                for(int d=0; d<TEXTO_MAX; d++)
                {
                    nuevo_linea->linea_texto[d]=linea_aux->linea_texto[d];
                }
                nuevo_linea->c=linea_aux->c;

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
            for(i=0; i<T_ENT; i++)
            {
                undelete->ubic[i]=aux2->ubic[i];
            }


            if(padre->cabezal_archivos==aux2)
            {
                eliminar_p_a(padre);
            }
            else
            {
                if(aux2->sig==NULL)
                {
                    elimnar_f_a(padre);
                }
                else
                {
                    ant->sig=aux2->sig;
                    delete aux2;
                }
            }
        }
    }

    (*s).deleteado=undelete;
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

    Ubicacion ubc_ainsertar;

    Directorios padre;

    Lineas linea_aux;

    undelete= (*s).deleteado;
    int i=0;
    int u=0;
    bool error1=false;
    int r;

    char param[T_ENT];

    if(iguales(undelete->ubic, "/"))
    {
        padre=(*s).RAIZ;
    }
    else
    {
        ubc_ainsertar=mueve_nodo((*s).RAIZ, undelete->ubic);

        if (ubc_ainsertar.no_se_encontro==false)
        {
            padre=ubc_ainsertar.Padre;
        }
        else
        {
            errores_mensajes(UNDELETE, 1, 2);
            return 1;
        }
    }

    ausiliar=padre->cabezal_archivos;
    aux2=padre->cabezal_archivos;


    if(undelete==NULL)
    {
        errores_mensajes(UNDELETE, 1, 0);
        return 1;
    }

    for(i=0; i<T_ARC_Y_EXT;i++)
    {
        if(undelete->ubic[i]!='\0')
        {
            param[i]=undelete->ubic[i];
            u++;
        }
    }

    for(i=0; i<T_ARC_Y_EXT;i++)
    {
        if (u<T_ENT)
        {
            param[u]=undelete->nombre_ext[i];
            u++;
        }
    }

    while((aux2!=NULL)&&(error1==false))
    {
        if(iguales(aux2->nombre_ext,undelete->nombre_ext))
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

    ausiliar=padre->cabezal_archivos;


    while(ausiliar!=NULL)
    {
        if(iguales(ausiliar->nombre_ext,undelete->nombre_ext))
        {
            aux=ausiliar;
        }
        ausiliar=ausiliar->sig;
    }

    aux->cant=undelete->cant;
    aux->cant_lineas=undelete->cant_lineas;

    int h;

    h=aux->cant_lineas;

    linea_aux=undelete->cabezal_linea.pri;

    for(i=0; i<h; i++)
    {
        Lineas nuevo_linea=new _nodo;

        for(int s=0; s<TEXTO_MAX; s++)
        {
            nuevo_linea->linea_texto[s]=linea_aux->linea_texto[s];
        }
        nuevo_linea->c=linea_aux->c;

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

void borrar_linea(Lineas borrar, int i, int m)
{
    if (i<m)
    {
        if(borrar->sig!=NULL)
        {
            borrar_linea(borrar->sig, i+1, m);
        }
        delete borrar;
    }
}

int cmd_bf(Sistema *s, char parametros[])
{
    int i;
    i=0;
    int cant_c;
    cant_c=0;

    bool existe=false;
    bool borrartodo=false;

    Directorios padre;
    Ubicacion ubc_ainsertar;

    Archivos aux;
    Archivos aux2;

    Lineas linea_aux;

    Lineas linea_ant;

    Descom_param_name_k param;


    if (parametros[0]!='\0')
    {
        param=param_name_k(parametros, BF);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }

    if(param.error==true)
    {
        return 1;
    }

    if(param.hay_ubc==true)
    {
        if(param.absoluta==true)
        {
            if(param.es_raiz==false)
            {
                ubc_ainsertar=mueve_nodo((*s).RAIZ, param.ubic);

                if (ubc_ainsertar.no_se_encontro==false)
                {
                    padre=ubc_ainsertar.Padre;
                }
                else
                {
                    errores_mensajes(MKDIR,1,0);
                    return 1;
                }
            }
            else
            {
                padre=(*s).RAIZ;
            }
        }
        else
        {
            ubc_ainsertar=mueve_nodo((*s).actual, param.ubic);

            if (ubc_ainsertar.no_se_encontro==false)
            {
                padre=ubc_ainsertar.Padre;
            }
            else
            {
                errores_mensajes(MKDIR,1,0);
                return 1;
            }
        }
    }
    else
    {
        padre=(*s).actual;
    }

    aux = padre->cabezal_archivos;


    if(aux==NULL)
    {
        errores_mensajes(BF,0,2);
        return 0;
    }
    else
    {
        aux2 = padre->cabezal_archivos;
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
                    param.k=aux2->cant_lineas;
                    borrartodo=true;
                }
                else
                {
                    if(aux2->cant_lineas==param.k)
                    {
                        borrartodo=true;
                    }
                }

                linea_aux=aux2->cabezal_linea.ult;
                linea_ant=aux2->cabezal_linea.ult;

                for(i=0; i<param.k; i++)
                {
                    cant_c=cant_c+linea_aux->c;
                    if (linea_aux->ant!=NULL)
                    {
                        linea_aux=linea_aux->ant;
                    }
                }

                if (linea_aux->sig!=NULL)
                {
                    borrar_linea(linea_aux->sig,0, param.k);
                }

                linea_aux->sig=NULL;

                if(borrartodo==true)
                {
                    delete linea_aux;
                    aux2->cabezal_linea.ult=NULL;
                    aux2->cabezal_linea.pri=NULL;
                    aux2->cant_lineas=0;
                    aux2->cant=0;
                }
                else
                {
                    aux2->cabezal_linea.ult=linea_aux;
                    aux2->cant_lineas=aux2->cant_lineas-param.k;
                    aux2->cant=aux2->cant-cant_c;
                    delete linea_aux;
                }
            }
        }
    }
    return 0;
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

void borrar_linea2(Lineas borrar, int i, int m)
{
    if (i<m)
    {
        if(borrar->ant!=NULL)
        {
            borrar_linea2(borrar->ant, i+1, m);
        }
        delete borrar;
    }
}

int cmd_bc(Sistema *s, char parametros[])
{
    int i;
    i=0;
    int cant_c;
    cant_c=0;

    bool existe=false;
    bool borrartodo=false;

    Directorios padre;
    Ubicacion ubc_ainsertar;

    Archivos aux;
    Archivos aux2;

    Lineas linea_aux;

    Lineas linea_ant;

    Descom_param_name_k param;

    if (parametros[0]!='\0')
    {
        param=param_name_k(parametros, BC);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }

    if(param.error==true)
    {
        return 1;
    }
    if(param.hay_ubc==true)
    {
        if(param.absoluta==true)
        {
            if(param.es_raiz==false)
            {
                ubc_ainsertar=mueve_nodo((*s).RAIZ, param.ubic);

                if (ubc_ainsertar.no_se_encontro==false)
                {
                    padre=ubc_ainsertar.Padre;
                }
                else
                {
                    errores_mensajes(MKDIR,1,0);
                    return 1;
                }
            }
            else
            {
                padre=(*s).RAIZ;
            }
        }
        else
        {
            ubc_ainsertar=mueve_nodo((*s).actual, param.ubic);

            if (ubc_ainsertar.no_se_encontro==false)
            {
                padre=ubc_ainsertar.Padre;
            }
            else
            {
                errores_mensajes(MKDIR,1,0);
                return 1;
            }
        }
    }
    else
    {
        padre=(*s).actual;
    }

    aux = padre->cabezal_archivos;


    if(aux==NULL)
    {
        errores_mensajes(DIR,0,0);
        return 0;
    }
    else
    {
        aux2 = padre->cabezal_archivos;
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
                    param.k=aux2->cant_lineas;
                    borrartodo=true;
                }
                else
                {
                    if(aux2->cant_lineas==param.k)
                    {
                        borrartodo=true;
                    }
                }

                linea_aux=aux2->cabezal_linea.pri;
                linea_ant=aux2->cabezal_linea.pri;

                for(i=0; i<param.k; i++)
                {
                    cant_c=cant_c+linea_aux->c;
                    if (linea_aux->sig!=NULL)
                    {
                        linea_aux=linea_aux->sig;
                    }
                }
            
                if (linea_aux->ant!=NULL)
                {
                    borrar_linea2(linea_aux->ant,0, param.k);
                }

                linea_aux->ant=NULL;

                if(borrartodo==true)
                {
                    delete linea_aux;
                    aux2->cabezal_linea.ult=NULL;
                    aux2->cabezal_linea.pri=NULL;
                    aux2->cant_lineas=0;
                    aux2->cant=0;
                }
                else
                {
                    aux2->cabezal_linea.pri=linea_aux;
                    aux2->cant_lineas=aux2->cant_lineas-param.k;
                    aux2->cant=aux2->cant-cant_c;
                    delete linea_aux;
                }
            }
        }
    }
    return 0;
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
    
    Ubicacion ubc_ainsertar;

    Directorios da1; //ubicacion archivo 1
    Directorios da2; //ubicacion archivo 2

    Archivos aux1; //auxiliar de busqueda 1
    Archivos aux2; //auxiliar de busqueda 2
    Archivos a1; //si se encuentra el archivo 1 se almacena en esta variable auxiliar
    Archivos a2; //si se encuentra el archivo 2 se almacena en esta variable auxiliar

    Lineas l_a1;
    Lineas l_a2;

    if (parametros[0]!='\0')
    {
        param=param_2_name(parametros);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }


    //Busqueda de ubicacion archivo 1
    if(param.a1.hay_ubc==true)
    {
        if(param.a1.absoluta==true)
        {
            if(param.a1.es_raiz==false)
            {
                ubc_ainsertar=mueve_nodo((*s).RAIZ, param.a1.ubic);

                if (ubc_ainsertar.no_se_encontro==false)
                {
                    da1=ubc_ainsertar.Padre;
                }
                else
                {
                    errores_mensajes(MKDIR,1,0);
                    return 1;
                }
            }
            else
            {
                da1=(*s).RAIZ;
            }
        }
        else
        {
            ubc_ainsertar=mueve_nodo((*s).actual, param.a1.ubic);

            if (ubc_ainsertar.no_se_encontro==false)
            {
                da1=ubc_ainsertar.Padre;
            }
            else
            {
                errores_mensajes(MKDIR,1,0);
                return 1;
            }
        }
    }
    else
    {
        da1=(*s).actual;
    }

    aux1=da1->cabezal_archivos;
    
    a1=da1->cabezal_archivos;

    //Busqueda de ubicacion archivo 2
    if(param.a2.hay_ubc==true)
    {
        if(param.a2.absoluta==true)
        {
            if(param.a2.es_raiz==false)
            {
                ubc_ainsertar=mueve_nodo((*s).RAIZ, param.a2.ubic);

                if (ubc_ainsertar.no_se_encontro==false)
                {
                    da2=ubc_ainsertar.Padre;
                }
                else
                {
                    errores_mensajes(MKDIR,1,0);
                    return 1;
                }
            }
            else
            {
                da2=(*s).RAIZ;
            }
        }
        else
        {
            ubc_ainsertar=mueve_nodo((*s).actual, param.a2.ubic);

            if (ubc_ainsertar.no_se_encontro==false)
            {
                da2=ubc_ainsertar.Padre;
            }
            else
            {
                errores_mensajes(MKDIR,1,0);
                return 1;
            }
        }
    }
    else
    {
        da2=(*s).actual;
    }

    aux2=da2->cabezal_archivos;
    
    a2=da2->cabezal_archivos;

    bool encontro_a1=false; //Sirve para sabersi lo encontro
    bool encontro_a2=false; //Sirve para sabersi lo encontro

    //Busca a1
    while((aux1!=NULL)&&(encontro_a1==false))
    {

        if(iguales(aux1->nombre_ext,param.a1.nombre_ext))
        {
            encontro_a1=true;
            a1=aux1;
        }
        aux1=aux1->sig;
    }

    //Busca a2
    while((aux2!=NULL)&&(encontro_a2==false))
    {
        if(iguales(aux2->nombre_ext,param.a2.nombre_ext))
        {
            encontro_a2=true;
            a2=aux2;
        }
        aux2=aux2->sig;
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

                nuevo_linea->c=l_a2->c;

                nuevo_linea->sig=NULL;
                nuevo_linea->ant=a1->cabezal_linea.ult;

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
    return 0;
}



///MKDIR

TipoRet ret_mkdir(Sistema *s, char parametros[])
{
    int r;
    r=cmd_mkdir(&*s, parametros);
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

int cmd_mkdir(Sistema *s, char parametros[])
{
    bool en_raiz=false;
    bool inserta=true;

    Directorios nuevo=new _nodo3;
    Directorios padre;
    Directorios aus;
    Directorios ant;

    Ubicacion ubc_ainsertar;

    Descom_param_name_D param;
    if (parametros[0]!='\0')
    {
        param=param_solo_name_D(parametros);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }

    if(param.error==true)
    {
        errores_mensajes(MKDIR, 1, 2);
        return 1;
    }

    if ((iguales(param.nombre,"RAIZ"))||(iguales(param.nombre,"raiz"))||(iguales(param.nombre,"Raiz")))
    {
        errores_mensajes(MKDIR,1,3);
        return 1;
    }

    int i;

    for(i=0;i<T_DIR;i++)
    {
        nuevo->nombre[i]=0;
    }

    if(param.hay_ubc==true)
    {
        if(param.absoluta==true)
        {
            if(param.es_raiz==false)
            {
                ubc_ainsertar=mueve_nodo((*s).RAIZ, param.ubic);

                if (ubc_ainsertar.no_se_encontro==false)
                {
                    padre=ubc_ainsertar.Padre;
                }
                else
                {
                    errores_mensajes(MKDIR,1,0);
                    return 1;
                }

            }
            else
            {
                en_raiz=true;
                padre=(*s).RAIZ;
            }
        }
        else
        {
            ubc_ainsertar=mueve_nodo((*s).actual, param.ubic);
            if (ubc_ainsertar.no_se_encontro==false)
            {
                padre=ubc_ainsertar.Padre;
            }
            else
            {
                errores_mensajes(MKDIR,1,0);
                return 1;
            }
        }
    }
    else
    {
        padre=(*s).actual;
    }

    for(i=0;i<T_DIR;i++)
    {
        nuevo->nombre[i]=param.nombre[i];
    }
    nuevo->tamanio=0;
    nuevo->tiene_cota=false;


    if(es_vaciaD(padre->hijo))
    {
        nuevo->hijo=NULL;
        nuevo->hermano=NULL;
        padre->hijo=nuevo;
        nuevo->padre=padre;
        nuevo->cabezal_archivos=NULL;
    }
    else
    {
        aus=padre->hijo;
        nuevo->padre=padre;

        while(aus!=NULL)
        {
            if ((iguales(nuevo->nombre, aus->nombre))&&(inserta==true))
            {
                inserta=false;
                errores_mensajes(MKDIR,1,1);
                return 1;
            }
            aus=aus->hermano;;
        }
        aus=padre->hijo;

        if((strcmp(nuevo->nombre, padre->hijo->nombre))<0)
        {
            nuevo->hermano=padre->hijo;
            padre->hijo=nuevo;
        }
        else
        {
            while((aus!=NULL)&&(strcmp(nuevo->nombre, aus->nombre))>0)
            {
                ant=aus;
                aus=aus->hermano;
            }
            nuevo->hermano=aus;
            ant->hermano=nuevo;
            return 0;
        }
    }
    return 1;
}



///CD

TipoRet ret_cd(Sistema *s, char parametros[])
{
    int r;
    r=cmd_cd(&*s, parametros);
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

int cmd_cd(Sistema *s, char parametros[])
{
    Directorios padre;
    Directorios aus;
    Ubicacion ubc;

    char nombre[T_DIR];

    bool vacio=false;
    bool termina=false;
    bool en_raiz=false;

    Descom_param_name_D param;
    if (parametros[0]!='\0')
    {
        param=param_solo_name_D(parametros);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }

    int i;

    if(param.error==true)
    {
        errores_mensajes(DIR, 1, 0);
        return 1;
    }

    for(i=0;i<T_DIR;i++)
    {
        nombre[i]=0;
    }

    if(param.hay_ubc==true)
    {
        if(param.absoluta==true)
        {
            if(param.es_raiz==false)
            {
                ubc=mueve_nodo((*s).RAIZ, param.ubic);
                if (ubc.no_se_encontro==false)
                {
                    padre=ubc.Padre;
                }
                else
                {
                    errores_mensajes(CD,1,0);
                    return 1;
                }

            }
            else
            {
                en_raiz=true;
                padre=(*s).RAIZ;
            }
        }
        else
        {
            ubc=mueve_nodo((*s).actual, param.ubic);
            if (ubc.no_se_encontro==false)
            {
                padre=ubc.Padre;
            }
            else
            {
                errores_mensajes(CD,1,0);
                return 1;
            }
        }
    }
    else
    {
        padre=(*s).actual;
    }


    for(i=0;i<T_DIR;i++)
    {
        nombre[i]=param.nombre[i];
    }

    if(nombre[0]=='\0')
    {
        vacio=true;;
    }

    if (vacio==true)
    {
        if(en_raiz==true)
        {
            (*s).actual=(*s).RAIZ;
            return 0;
        }
         else
        {
            (*s).actual=padre;
            return 0;
        }
    }

    if(es_vaciaD(padre->hijo))
    {
        errores_mensajes(CD, 1, 0);
        return 1;
    }
    else
    {
        aus=padre->hijo;

        while ((aus!=NULL)&&(termina==false))
        {
            if (iguales(aus->nombre, nombre))
            {
                (*s).actual=aus;
                termina=true;
                return 0;
            }
            else
            {
                aus=aus->hermano;
            }
        }
        if(es_vaciaD(aus))
        {
            errores_mensajes(CD, 1, 0);
            return 1;
        }
    }
    return 1;
}



///PWD

TipoRet ret_pwd(Sistema *s)
{
    int r;
    r=cmd_pwd(&*s);
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

void pwd_recursivo(Directorios u,char ubic[])
{
    int i=0;
    int c=0; //cantidad
    int tdir=T_DIR;
    tdir=tdir+1;
    bool t=false;
    char nubic[T_ENT];

    nubic[c]='/';
        c++;

    if(es_raiz(u))
    {
        cout<<ubic<<endl;
    }
    else
    {
        for(i=0;i<tdir;i++)
        {
            if(u->nombre[i]=='\0')
            {
                t=true;
            }
            if(t==false)
            {
                nubic[c]=u->nombre[i];
                c++;
            }
        }

         for(i=0;i<T_ENT;i++)
        {
            nubic[c]=ubic[i];
            c++;
        }
        pwd_recursivo(u->padre, nubic);
    }

}

int cmd_pwd(Sistema *s)
{
    char nombre[T_ENT];
    int i;
    Directorios d;
    d=(*s).actual;

    if(es_raiz((*s).actual))
    {
        cout<<"/"<<endl;
    }
    else
    {
        for (i=0;i<T_ENT;i++)
        {
            nombre[i]='\0';
        }

        pwd_recursivo((*s).actual,nombre);
        cout<<""<<endl;
    }
    return 0;
}



///RMDIR

TipoRet ret_rmdir(Sistema *s, char parametros[])
{
    int r;
    r=cmd_rmdir(&*s, parametros);
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

void delete_a(Archivos a)
{
    Lineas l;

    if(a->sig!=NULL)
    {
        delete_a(a->sig);
    }
    
    if (a->cabezal_linea.pri!=NULL)
    {
        l=a->cabezal_linea.pri;
        if (l->sig!=NULL)
        {
            delete_l(l->sig);
        }
        delete l;
        a->cabezal_linea.pri=NULL;
        a->cabezal_linea.ult=NULL;
    }
    delete a;
}

void delete_l(Lineas l)
{
    if(l->sig!=NULL)
    {
        delete_l(l->sig);
    }
    delete l;
}

void rmdir_recursivo(Directorios d)
{
    Archivos a;
    Lineas l;

    a=d->cabezal_archivos;
    if(a=NULL)
    {
        if(a->sig!=NULL)
        {
            delete_a(a->sig);
        }
        
        if (a->cabezal_linea.pri!=NULL)
        {
            l=a->cabezal_linea.pri;
            if (l->sig!=NULL)
            {
                delete_l(l->sig);
            }
            delete l;
            a->cabezal_linea.pri=NULL;
            a->cabezal_linea.ult=NULL;
        }
        delete a;
        d->cabezal_archivos=NULL;
    }
    if(d->hijo!=NULL)
    {
        rmdir_recursivo(d->hijo);
    }
    if(d->hermano!=NULL)
    {
        rmdir_recursivo(d->hermano);
    }
    delete d;
}

int cmd_rmdir(Sistema *s, char parametros[])
{
    Directorios padre;
    Directorios eliminar;
    Directorios aus;
    Directorios aus1;
    Directorios aus2;
    Directorios ult;

    Ubicacion ubc;

    Archivos a;
    Lineas l;

    bool vacio=false;
    bool termina=false;
    bool en_raiz=false;
    bool error1=false;

    Descom_param_name_D param;
    
    if (parametros[0]!='\0')
    {
        param=param_solo_name_D(parametros);
    }
    else
    {
        errores_mensajes(DIR,1,0);
        return 1;
    }

    int i;

    if(param.error==true)
    {
        return 1;
    }

    if(param.hay_ubc==true)
    {
        if(param.absoluta==true)
        {
            if(param.es_raiz==false)
            {
                ubc=mueve_nodo((*s).RAIZ, param.ubic);
                if (ubc.no_se_encontro==false)
                {
                    padre=ubc.Padre;
                }
                else
                {
                    errores_mensajes(CD,1,0);
                    return 1;
                }

            }
            else
            {
                en_raiz=true;
                padre=(*s).RAIZ;
            }
        }
        else
        {
            ubc=mueve_nodo((*s).actual, param.ubic);
            if (ubc.no_se_encontro==false)
            {
                padre=ubc.Padre;
            }
            else
            {
                errores_mensajes(CD,1,0);
                return 1;
            }
        }
    }
    else
    {
        padre=(*s).actual;
    }

    if(param.nombre[0]=='\0')
    {
        vacio=true;;
    }

    if (vacio==true)
    {
        errores_mensajes(RMDIR,1,0);
        return 1;
    }

    if(es_vaciaD(padre->hijo))
    {
        errores_mensajes(RMDIR, 1, 1);
        return 1;
    }
    else
    {
        aus=padre->hijo;

        while ((aus!=NULL)&&(termina==false))
        {
            if (iguales(aus->nombre, param.nombre))
            {
                eliminar=aus;
                termina=true;
            }
            else
            {
                aus=aus->hermano;
            }
        }
    }

    aus=eliminar;
    aus1=(*s).actual;

    while ((!(es_vaciaD(aus)))&&(error1==false))
    {
        if (aus==aus1)
        {
            error1=true;
        }
        else
        {
            aus=aus->padre;
        }
    }

    if(error1==true)
    {
        errores_mensajes(RMDIR,1,0);
        return 1;
    }
    else
    {
        aus=padre;
        if(eliminar==aus->hijo)
        {
            if(eliminar->hermano!=NULL)
            {
                aus->hijo=eliminar->hermano;
            }
            else
            {
                aus->hijo=NULL;
            }
        }
        else
        {
            ult=padre->hijo;
            while(!es_vaciaD(ult->hermano))
            {
                aus1=ult;
                ult=ult->hermano;
            }
            if(ult==eliminar)
            {
                aus1->hermano=NULL;
            }
            else
            {
                aus=padre->hijo;
                while ((strcmp(aus->nombre, eliminar->nombre))>0)
                {
                    aus2=aus1;
                    aus1=aus;
                    aus=aus->hermano;
                }
                aus2->hermano=aus;
            }
        }
        
        a=eliminar->cabezal_archivos;
        if(a=NULL)
        {
            if(a->sig!=NULL)
            {
                delete_a(a->sig);
            }
            
            if (a->cabezal_linea.pri!=NULL)
            {
                l=a->cabezal_linea.pri;
                if (l->sig!=NULL)
                {
                    delete_l(l->sig);
                }
                delete l;
                a->cabezal_linea.pri=NULL;
                a->cabezal_linea.ult=NULL;
            }
            delete a;
            eliminar->cabezal_archivos=NULL;
        }
        if(eliminar->hijo!=NULL)
        {
            rmdir_recursivo(eliminar->hijo);
        }
    }
    
    return 0;
}



///COPY

TipoRet ret_copy(Sistema *s, char parametros[])
{
    int r;
    r=cmd_copy(&*s, parametros);
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

int cmd_copy(Sistema *s, char parametros[])
{
    return 2;
}
