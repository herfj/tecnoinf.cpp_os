#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

///Hernán Fbrica & Tomas Baute
///Version 0.0.0.1

#include "def.h"
#include "funciones.cpp"



int main()
{
    bool rep;
    bool var;
    rep=true;
    TipoRet retorna;
    Comandos op_selecionada;

    int i; i=0;

    Lista_archivos raiz;
    raiz=crear();
    Cmd_Param ent;

    while (rep)
    {
        var=false;
        ent=entrada();

        if ((strcmp(ent.cmd.cadena, "DIR"))==0)
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

    return 0;
}
