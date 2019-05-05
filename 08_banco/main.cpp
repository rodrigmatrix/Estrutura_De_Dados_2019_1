#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Bank.h"
using namespace std;

int main(){
    Bank b;
    Customer c1("joao", 1, 2);
    Customer c2("maria", 1, 4);
    Customer c3("carlos", 2, 4);
    b.add_customer(&c1);
    b.add_customer(&c2);
    b.add_customer(&c3);
    b.show_entrance();
    b.init_checkout(3);
    b.show_checkout();
    b.process_document();
    
    // while(true){
    //     string line, cmd;
    //     getline(cin, line);
    //     stringstream ui(line);
    //     ui >> cmd;
    //     if(cmd == "end"){
    //         break;
    //     }
    //     else if(cmd == "add customer"){
    //         int value;
    //         while(ui >> value){

    //         }
    //     }
    //     else if(cmd == "show"){
            
    //     }
    //     else if(cmd == "simulate"){
    //         int value;
    //         ui >> value;
    //     }
    //     else{
    //         cout << "Comando não existe\n";
    //     }
    // }
}