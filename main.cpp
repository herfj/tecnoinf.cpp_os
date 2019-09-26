///Hernán Fbrica & Tomas Baute

#include <iostream>
#include <string.h>


using namespace std;

#include "def.h"
#include "funciones.cpp"



int main()
{
    bool rep;

    rep=true;
    TipoRet retorna;
    Comandos op_selecionada;
    Parametros ent;

    int i; i=0;

    Sistema raiz;
    raiz=crear();


    while (rep)
    {
        ent=entrada();

        if(ent.cmd_correcto==true)
        {
            switch(op_selecionada)
            {
                case DIR:
                cout<<"fsdahgdshsgfahf";
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

