#include <iostream>
#include <list>
#include <queue>
#include "Customer.h"
using namespace std;

class Bank {
    public:
    vector<Customer*> checkout;
    list<Customer*> entrance;
    queue<Customer*> exit;
    void show_checkout(){
        for(int i = 0; i< this->checkout.size(); i++){
            cout << "[";
            if(this->checkout.at(i) != nullptr){
                cout << this->checkout.at(i)->id << "," ;
                cout << this->checkout.at(i)->documents << "," ;
                cout << this->checkout.at(i)->tolerance;
            }
            cout << "]";
        }
    }
    void add_customer(Customer* c){
        this->checkout.push_back(c);
    }
};
