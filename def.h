#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#define T_ENT 100
#define T_CORT 20
#define T_ARC 15
#define T_EXT 3
#define TEXTO_MAX 50

using namespace std;


///Enum

typedef enum _Comandos{
    DIR, CREATE, DELETE, UNDELETE, IC, TYPE, IF, BC, BF, CAT
}Comandos;

typedef enum _TipoRet{
    OK,ERROR,NO_IMPLEMENTADO
}TipoRet;


typedef struct
{
    Comandos cmd;
    char ubic[T_ENT];
    char param2[T_ENT];
    char a_name[T_ARC];
    char ext[T_EXT];
    char text[TEXTO_MAX];
    bool cmd_correcto;
}Parametros;


//Lineas texto de los archivos
struct _nodo{
    _nodo *ant;
    string linea_texto;
    _nodo *sig;
};

typedef _nodo *Lineas;

//Struct de cabezal de lineas
struct _cabezalineas
{
    Lineas pri;
    Lineas ult;
}
typedef _cabezalineas CabezalLineas;

///Struct Archivo

typedef struct
{
    char nombre[T_ARC];
    char ext[T_EXT];
    CabezalLineas cabezal_linea;
    int cant;
}Archivos;

//Nodo de archivo
struct _nodo2{
    _nodo2 *ant;
    Archivos c_archivo;
    _nodo2 *sig;
};
typedef  _nodo2 *Sistema;


///Funciones
Sistema crear();
bool es_vacia(Sistema c);
Parametros entrada();

///TipoRet
TipoRet ret_dir(Sistema c);

///Mostrar
void mostrar_dir(Sistema c);


#endif // DEF_H_INCLUDED
