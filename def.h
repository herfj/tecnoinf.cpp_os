#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#define TAMANIO_ENT 40
#define TAMANIO_ARCH 19
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
    char cadena[TAMANIO_ENT];
    int cant;
}Cad_Ent;

typedef struct
{
    char cadena[TAMANIO_ARCH];
    int cant;
}Cad_Arch;

typedef struct
{
    Cad_Arch param;
    Cad_Ent cmd;
}Cmd_Param;

//Lineas texto de los archivos
struct _nodo{
    _nodo *ant;
    string linea_texto;
    _nodo *sig;
};

typedef _nodo *Lineas;

///Struct Archivo

typedef struct
{
    //nodo cabezal
    Cad_Arch nom_ext;
    int cant_nom_ext;
    Lineas cabezal_linea;
    int cant;
}Archivos;

//Nodo de archivo
struct _nodo2{
    _nodo2 *ant;
    Archivos c_archivo;
    _nodo2 *sig;
};
typedef  _nodo2 *Lista_archivos;


///Funciones
Lista_archivos crear();
bool es_vacia(Lista_archivos c);
Cmd_Param entrada();

///TipoRet
TipoRet ret_dir(Lista_archivos c);

///Mostrar
void mostrar_dir(Lista_archivos c);


#endif // DEF_H_INCLUDED
