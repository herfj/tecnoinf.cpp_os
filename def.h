#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#define T_ENT 100
#define T_CORT 20
#define T_ARC 15
#define T_EXT 3
#define T_ARC_Y_EXT 19
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
    char parametros[T_ENT];
    bool cmd_correcto;
}CMD_PARAM;

typedef struct
{
    int cant_ayext=0;
    char ubic[T_ENT];
    char nombre_ext[T_ARC_Y_EXT];
    int acarrea_error;
}Descom_param_create;


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
};
typedef struct _cabezalineas CabezalLineas;


//Nodo de archivo
struct _nodo2{
    char nombre_ext[T_ARC_Y_EXT];
    CabezalLineas cabezal_linea;
    int cant;
    _nodo2 *sig;
};
typedef  _nodo2 *Archivos;


typedef struct
{
    Archivos cabezal_archivos;
}Sistema;


///Funciones
Sistema crear();
bool es_vacia(Sistema c);
CMD_PARAM entrada();
void errores_mensajes (Comandos cmd, int error, int cod);
bool iguales (char char1[], char char2[]);


///DIR

TipoRet ret_dir(Sistema c);
void mostrar_dir(Sistema c);

///CREATE
TipoRet ret_create(Sistema *s, char parametros[T_ENT]);
Descom_param_create descompone_param_de_create(char parametros[]);
void insert_p_a(Sistema *s, char nombre_ext[], int cant_ayext);
void insert_f_a(Sistema *s, char nombre_ext[], int cant_ayext);
int create_arc(Sistema *s, char parametros[]);

#endif // DEF_H_INCLUDED
