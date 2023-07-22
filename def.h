#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#include "constants.h" // Include the constants header

// Commands (Enum)
typedef enum _Commands{
    DIR, CREATE, DELETE, UNDELETE, IC, TYPE, IF, BC, BF, CAT, MKDIR, CD, PWD, RMDIR, COPY
} Commands;

// TypeRET (Enum)
typedef enum _Response{
    OK,ERROR,NOT_IMPLEMENTED
} Response;

//CMD y PARAM
typedef struct
{
    Commands cmd;
    char params[T_ENT];
    bool isValid;
} CMD_PARAM;


// Descomposicion partes (ARCHIVOS)

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

//Descomposicion de Archivo para los Commands IF & IC (Struct)
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

//Descomposicion de Archivo para los Commands BC & BF (Struct)
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


// Descomposicion partes (DIRECTORIOS)

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


// NODOS LINEAS, ARCHIVOS, DIRECTORIOS

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
    char ubic[T_ENT];
    bool raiz;
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
} Ubicacion;

// Sistema
typedef struct
{
    Directorios RAIZ;
    Directorios actual;
    Archivos deleteado;
} Sistema;


//Creacion (Inizializacion del Sistema)
Sistema crear();

// Funciones de Consulta (tipo Bool)

bool es_raiz(Directorios s);
bool es_vacia(Sistema s);
bool es_vaciaD(Directorios d);
bool es_vaciaA(Archivos a);
bool lineas_es_vacia(CabezalLineas l);
bool iguales (char char1[], char char2[]);

//Funciones Muestro Errores & Mensajes

void errores_mensajes (Commands cmd, int error, int cod);

//Separa el comando de los params

void pwd_ent(Directorios u,char ubic[]);
CMD_PARAM entrada(Directorios aux);

//Recibe un char[] de ubicacion y retorna el directorio de la ubicacion deseada

Ubicacion mueve_nodo(Directorios dir,char ubic[]);

// Descompocion de params PARA ARCHIVOS (otorgando los datos para cada funcion)

Descom_param_name param_solo_name(char params[]);
Descom_param_if_ic param_de_if_ic(char params[], Commands cmd);
Descom_param_name_k param_name_k(char params[], Commands cmd);
Descom_param_2name param_2_name(char params[]);

// Descompocion de params PARA DIRECTORIOS (otorgando los datos para cada funcion)

Descom_param_name_D param_solo_name_D(char params[]);

// DIR

Response ret_dir(Sistema s,char params[]);
void mostrar_archivo(Archivos a, int c, bool s);
void pwd_dir(Directorios u,char ubic[]);
void dir_s(Directorios d, int c);
bool param_s(char params[]);
int cmd_dir(Sistema s, char params[]);

// CREATE

Response ret_create(Sistema *s, char params[T_ENT]);
int cmd_create(Sistema *s, char params[]);

// IF

Response ret_if(Sistema *s, char params[T_ENT]);
int cmd_if(Sistema *s, char params[]);

// IC

Response ret_ic(Sistema *s, char params[T_ENT]);
int cmd_ic(Sistema *s, char params[]);

// TYPE

Response ret_type(Sistema *s, char params[]);
int cmd_type(Sistema *s, char params[]);

// DELETE

Response ret_delete(Sistema *s, char params[]);
void elimnar_p_a(Directorios u);
void elimnar_f_a(Directorios u);
int cmd_delete(Sistema *s, char params[]);

// UNDELETE

Response ret_undelete(Sistema *s);
int cmd_undelete(Sistema *s);

// BF

Response ret_bf(Sistema *s, char params[]);
void borrar_linea(Lineas borrar, int i, int m);
int cmd_bf(Sistema *s, char params[]);

// BC

Response ret_bc(Sistema *s, char params[]);
void borrar_linea2(Lineas borrar, int i, int m);
int cmd_bc(Sistema *s, char params[]);

// CAT

Response ret_cat(Sistema *s, char params[]);
int cmd_cat(Sistema *s, char params[]);

// MKDIR

Response ret_mkdir(Sistema *s, char params[]);

int cmd_mkdir(Sistema *s, char params[]);

// CD

Response ret_cd(Sistema *s, char params[]);
int cmd_cd(Sistema *s, char params[]);

// PWD

Response ret_pwd(Sistema *s);
void pwd_recursivo(Directorios u,char ubic[]);
int cmd_pwd(Sistema *s);

// RMDIR

Response ret_rmdir(Sistema *s, char params[]);
void delete_a(Archivos a);
void delete_l(Lineas l);
void rmdir_recursivo(Directorios d);
int cmd_rmdir(Sistema *s, char params[]);

// COPY

Response ret_copy(Sistema *s, char params[]);
int cmd_copy(Sistema *s, char params[]);

#endif // DEF_H_INCLUDED
