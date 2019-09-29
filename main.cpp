///Hernán Fbrica & Tomas Baute

#include <iostream>
#include <string.h>


using namespace std;

#include "def.h"
#include "funciones.cpp"



int main()
{
    bool rep; rep=true;

    TipoRet retorna;
    CMD_PARAM ent;

    int i; i=0;

    Sistema s;
    s=crear();


    while (rep)
    {
        ent=entrada();


        if(ent.cmd_correcto==true)
        {
            switch(ent.cmd)
            {
                case DIR:
                retorna=ret_dir(s);
                break;
            case CREATE:
                retorna=ret_create(&s, ent.parametros);
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

