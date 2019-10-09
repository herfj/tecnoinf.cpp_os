#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#define T_ENT 100
#define T_CORT 20
#define T_ARC 15
#define T_EXT 3
#define T_ARC_Y_EXT 19
#define TEXTO_MAX 50
#define LARGO_MAX 3

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
}Descom_param_name;

typedef struct
{
    int cant_ayext=0;
    int cant_letras=0;
    char ubic[T_ENT];
    char nombre_ext[T_ARC_Y_EXT];
    char linea[TEXTO_MAX];
    bool error=false;
}Descom_param_if_ic;

typedef struct
{
    int cant_ayext=0;
    char ubic[T_ENT];
    char nombre_ext[T_ARC_Y_EXT];
    int k;
    bool error=false;
}Descom_param_name_k;

//Lineas texto de los archivos
struct _nodo{
    _nodo *ant;
    char linea_texto[TEXTO_MAX];
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
    int cant_lineas=0;
    _nodo2 *sig;
};
typedef  _nodo2 *Archivos;


typedef struct
{
    Archivos cabezal_archivos;
    Archivos cabezal_arch_D;
}Sistema;


///Funciones

Sistema crear();
bool es_vacia(Sistema c);
CMD_PARAM entrada();
void errores_mensajes (Comandos cmd, int error, int cod);
bool iguales (char char1[], char char2[]);

///Descomposicion parametro (arreglo)

Descom_param_name param_solo_name(char parametros[]);
Descom_param_if_ic descompone_param_de_if_ic(char parametros[]);

///DIR

TipoRet ret_dir(Sistema c);
void cmd_dir(Sistema c);

///CREATE

TipoRet ret_create(Sistema *s, char parametros[T_ENT]);
void insert_p_a(Sistema *s, char nombre_ext[], int cant_ayext);
void insert_f_a(Sistema *s, char nombre_ext[], int cant_ayext);
int cmd_create(Sistema *s, char parametros[]);

///IF

TipoRet ret_if(Sistema *s, char parametros[T_ENT]);
int cmd_if(Sistema *s, char parametros[]);

///IC

TipoRet ret_ic(Sistema *s, char parametros[T_ENT]);
int cmd_ic(Sistema *s, char parametros[]);

///TYPE

TipoRet ret_type(Sistema *s, char parametros[]);
int cmd_type(Sistema *s, char parametros[]);

///DELETE

TipoRet ret_delete(Sistema *s, char parametros[]);
int cmd_delete(Sistema *s, char parametros[]);

///UNDELETE

TipoRet ret_undelete(Sistema *s);
int cmd_undelete(Sistema *s);

///BF

TipoRet ret_bf(Sistema *s, char parametros[]);
int cmd_bf(Sistema *s, char parametros[]);

///BC

TipoRet ret_bc(Sistema *s, char parametros[]);
int cmd_bc(Sistema *s, char parametros[]);

///CAT

TipoRet ret_cat(Sistema *s, char parametros[]);
int cmd_cat(Sistema *s, char parametros[]);
#endif // DEF_H_INCLUDED