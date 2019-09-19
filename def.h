#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

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


///Listas & Lineas (NODO)

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
    string nom_ext;
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

///TipoRet
TipoRet ret_dir(Lista_archivos c);

///Mostrar
void mostrar_dir(Lista_archivos c);

#endif // DEF_H_INCLUDED
