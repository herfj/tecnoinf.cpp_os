#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED



///Definiciones

//Constantes Globales
#define T_ENT 100
#define T_CORT 20

//Constantes de Archivos
#define T_ARC 15
#define T_EXT 3
#define T_ARC_Y_EXT 19

//Constantes de Lineas
#define TEXTO_MAX 50
#define LARGO_MAX 9

//Constantes de Directorios
#define T_DIR 15

using namespace std;

///Comandos (Enum)
typedef enum _Comandos{
    DIR, CREATE, DELETE, UNDELETE, IC, TYPE, IF, BC, BF, CAT, MKDIR, CD, PWD, RMDIR, COPY
}Comandos;

///TypeRET (Enum)
typedef enum _TipoRet{
    OK,ERROR,NO_IMPLEMENTADO
}TipoRet;

//CMD y PARAM
typedef struct
{
    Comandos cmd;
    char parametros[T_ENT];
    bool cmd_correcto;
}CMD_PARAM;


///Descomposicion partes (ARCHIVOS)

//Descomposicion de Archivo solo nombre y ext (Struct)
typedef struct
{
    int cant_ayext=0;
    char ubic[T_ENT];
    bool absoluta;
    bool hay_ubc;
    bool es_raiz;
    char nombre_ext[T_ARC_Y_EXT];
    bool error=false;
}Descom_param_name;

//Descomposicion de Archivo para los Comandos IF & IC (Struct)
typedef struct
{
    int cant_ayext=0;
    int cant_letras=0;
    char ubic[T_ENT];
    bool absoluta;
    bool hay_ubc;
    bool es_raiz;
    char nombre_ext[T_ARC_Y_EXT];
    char linea[TEXTO_MAX];
    bool error=false;
}Descom_param_if_ic;

//Descomposicion de Archivo para los Comandos BC & BF (Struct)
typedef struct
{
    int cant_ayext=0;
    char ubic[T_ENT];
    bool absoluta;
    bool hay_ubc;
    bool es_raiz;
    char nombre_ext[T_ARC_Y_EXT];
    int k;
    bool error=false;
}Descom_param_name_k;

//Descomposicion de Archivo para el Comando CAT (Struct)
typedef struct
{
    Descom_param_name a1;
    Descom_param_name a2;
}Descom_param_2name;


///Descomposicion partes (DIRECTORIOS)

//Descomposicion de Directorio solo nombre (Struct)
typedef struct
{
    int cant=0;
    char ubic[T_ENT];
    bool absoluta;
    bool hay_ubc;
    bool es_raiz;
    char nombre[T_DIR];
    bool error=false;
}Descom_param_name_D;


///NODOS LINEAS, ARCHIVOS, DIRECTORIOS

//Nodo LINEAS
struct _nodo{
    _nodo *ant;
    char linea_texto[TEXTO_MAX];
    int c=0;
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

//Nodo de ARCHIVOS
struct _nodo2{
    char nombre_ext[T_ARC_Y_EXT];
    CabezalLineas cabezal_linea;
    int cant;
    int cant_lineas=0;
    _nodo2 *sig;
};
typedef  _nodo2 *Archivos;

//Nodo de DIRECTORIOS
struct _nodo3{
    char nombre[T_DIR];
    int cota;
    int tamanio;
    bool tiene_cota;
    Archivos cabezal_archivos;
    _nodo3 *hijo;
    _nodo3 *hermano;
    _nodo3 *padre;
};
typedef  _nodo3 *Directorios;

//Struct Ubicacion nodo Directorio
typedef struct
{
    Directorios Padre;
    bool no_se_encontro;
}Ubicacion;

///Sistema
typedef struct
{
    Directorios RAIZ;
    Archivos cabezal_arch_D;
    Directorios actual;
}Sistema;


//Creacion (Inizializacion del Sistema)
Sistema crear();

///Funciones de Consulta (tipo Bool)

bool es_raiz(Directorios s);
bool es_vacia(Sistema s);
bool es_vaciaD(Directorios d);
bool es_vaciaA(Archivos a);
bool lineas_es_vacia(CabezalLineas l);
bool iguales (char char1[], char char2[]);

//Funciones Muestro Errores & Mensajes

void errores_mensajes (Comandos cmd, int error, int cod);

//Separa el comando de los parametros

CMD_PARAM entrada();

//Recibe un char[] de ubicacion y retorna el directorio de la ubicacion deseada

Ubicacion mueve_nodo(Directorios dir,char ubic[]);

///Descompocion de parametros PARA ARCHIVOS (otorgando los datos para cada funcion)

Descom_param_name param_solo_name(char parametros[]);
Descom_param_if_ic descompone_param_de_if_ic(char parametros[]);
Descom_param_name_k param_name_k(char parametros[], Comandos cmd);
Descom_param_2name param_2_name(char parametros[]);

///Descompocion de parametros PARA DIRECTORIOS (otorgando los datos para cada funcion)

Descom_param_name_D param_solo_name_D(char parametros[]);

///DIR

TipoRet ret_dir(Sistema s,char parametros[]);
void dir_s(Directorios d, int c);
int cmd_dir(Sistema s, char parametros[]);

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
void borrar_linea(Lineas borrar, int i, int m);
int cmd_bf(Sistema *s, char parametros[]);

///BC

TipoRet ret_bc(Sistema *s, char parametros[]);
void borrar_linea2(Lineas borrar, int i, int m);
int cmd_bc(Sistema *s, char parametros[]);

///CAT

TipoRet ret_cat(Sistema *s, char parametros[]);
int cmd_cat(Sistema *s, char parametros[]);

///MKDIR

TipoRet ret_mkdir(Sistema *s, char parametros[]);

int cmd_mkdir(Sistema *s, char parametros[]);

///CD

TipoRet ret_cd(Sistema *s, char parametros[]);
int cmd_cd(Sistema *s, char parametros[]);

///PWD

TipoRet ret_pwd(Sistema *s, char parametros[]);
void pwd_recursivo(Directorios u,char ubic[]);
int cmd_pwd(Sistema *s, char parametros[]);

///RMDIR

TipoRet ret_rmdir(Sistema *s, char parametros[]);
int cmd_rmdir(Sistema *s, char parametros[]);

//COPY

TipoRet ret_copy(Sistema *s, char parametros[]);
int cmd_copy(Sistema *s, char parametros[]);

#endif // DEF_H_INCLUDED
