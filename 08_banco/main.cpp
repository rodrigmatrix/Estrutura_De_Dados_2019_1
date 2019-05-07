#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Bank.h"
using namespace std;

int main(){
    Bank b;
    while(true){
        string line, cmd;
        getline(cin, line);
        stringstream ui(line);
        
        ui >> cmd;
        if(cmd == "end"){
            break;
        }
        else if(cmd == "init"){
            int size;
            ui >> size;
            b.init_checkout(size);
        }
        else if(cmd == "in"){
            string id;
            int documents;
            int tolerance;
            ui >> id;
            ui >> documents;
            ui >> tolerance;
            b.add_customer(new Customer(id, documents, tolerance));
        }
        else if(cmd == "show"){
            b.show_checkout();
            b.show_entrance();
            b.show_exit();
            cout << endl;
        }
        else if(cmd == "tic"){
            b.process_document();
        }
        else if(cmd == "finalizar"){
            cout << "docs recebidos: " << b.processed << endl;
            cout << "docs perdidos: " << b.lost << endl;
        }
        else{
            cout << "Comando não existe\n";
        }
    }
}