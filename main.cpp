///Hernán Fbrica & Tomas Baute


#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

#include "def.h"
#include "funciones.cpp"



int main()
{
    bool rep;
    bool var;
    rep=true;
    TipoRet retorna;
    Comandos op_selecionada;
    Parametros ent;

    int i; i=0;

    Sistema raiz;
    raiz=crear();


    while (rep)
    {
        var=false;
        ent=entrada();
        cout<<"el cmd es"<<endl;
        cout<<ent.cmd<<endl;
        cout<<"el nombre es"<<endl;
        cout<<ent.a_name<<endl;

        cout<<"la ubic es"<<endl;
        cout<<ent.ubic<<endl;

        cout<<"La extension es"<<endl;
        cout<<ent.ext<<endl;
       /* if ((strcmp(ent.cmd, "DIR"))==0)
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

    */
    }
    return 0;
}
