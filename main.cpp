#include <iostream>
#include <string.h>

using namespace std;

///Hernán Fbrica & Tomas Baute
///Version 0.0.0.2

#include "def.h"
#include "funciones.cpp"



int main()
{
    bool rep;
    bool var;
    rep=true;
    TipoRet retorna;
    Comandos op_selecionada;

    Lista_archivos raiz;
    raiz=crear();
    string ent;

    do
    {
        var=false;
        ent=entrada();

        if (ent=="DIR")
        {
            op_selecionada=DIR;
            var=true;
        }


        if(var==true)
        {
            switch(op_selecionada)
            {
            case DIR:
                retorna=ret_dir(raiz);
                break;
            case CREATE:

                break;
            case DELETE:

                break;
            case UNDELETE:

                break;
            case IC:

                break;
            case IF:

                break;
            case TYPE:

                break;
            case BC:

                break;
            case BF:

                break;
            case CAT:

                break;
            }
        }


    }
    while (rep);

    return 0;
}
