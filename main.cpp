///Hernán Fbrica & Tomas Baute

#include <iostream>
#include <string.h>


using namespace std;

#include "constants.h"
#include "def.h"
#include "funciones.cpp"



int main()
{
    bool repeat; repeat=true;

    Response response;

    CMD_PARAM input;

    Sistema s;
    s=crear();

    while (repeat)
    {
        input=entrada(s.actual);

        if(input.isValid==true)
        {
            switch(input.cmd)
            {
            case DIR:
                cout<<""<<endl;
                response=ret_dir(s, input.parms);
                cout<<""<<endl;
                break;

            case CREATE:
                cout<<""<<endl;
                response=ret_create(&s, input.parms);
                cout<<""<<endl;
                break;

            case DELETE:
                cout<<""<<endl;
                response=ret_delete(&s, input.parms);
                cout<<""<<endl;
                break;

            case UNDELETE:
                cout<<""<<endl;
                response=ret_undelete(&s);
                cout<<""<<endl;
                break;

            case IC:
                cout<<""<<endl;
                response=ret_ic(&s, input.parms);
                cout<<""<<endl;
                break;

            case IF:
                cout<<""<<endl;
                response=ret_if(&s, input.parms);
                cout<<""<<endl;
                break;

            case TYPE:
                cout<<""<<endl;
                response=ret_type(&s, input.parms);
                cout<<""<<endl;
                break;

            case BC:
                cout<<""<<endl;
                response=ret_bc(&s, input.parms);
                cout<<""<<endl;
                break;

            case BF:
                cout<<""<<endl;
                response=ret_bf(&s, input.parms);
                cout<<""<<endl;
                break;

            case CAT:
                cout<<""<<endl;
                response=ret_cat(&s, input.parms);
                cout<<""<<endl;
                break;
            case MKDIR:
                cout<<""<<endl;
                response=ret_mkdir(&s, input.parms);
                cout<<""<<endl;
                break;
            case CD:
                cout<<""<<endl;
                response=ret_cd(&s, input.parms);
                cout<<""<<endl;
                break;
            case PWD:
                cout<<""<<endl;
                response=ret_pwd(&s);
                break;
            case RMDIR:
                cout<<""<<endl;
                response=ret_rmdir(&s, input.parms);
                cout<<""<<endl;
                break;
            case COPY:
                cout<<""<<endl;
                response=ret_copy(&s, input.parms);
                cout<<"No IMPLEMENTADO"<<endl;
                cout<<""<<endl;
                break;
            }
        }
    }
    return 0;
}

