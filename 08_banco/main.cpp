#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Bank.h"
using namespace std;

int main(){
    Bank b;
    Customer c1("joao", 1, 2);
    Customer c2("maria", 1, 2);
    b.add_customer(&c1);
    b.add_customer(&c2);
    b.show_checkout();
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