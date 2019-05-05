#include <iostream>
#include <list>
#include <queue>
#include <stdlib.h>
#include "Customer.h"
using namespace std;

class Bank {

    public:
    vector<Customer*> checkout;
    list<Customer*> entrance;
    queue<Customer*> exit;

    void show_checkout(){
        for(int i = 0; i < this->checkout.size(); i++){
            cout << "[ ";
            if(this->checkout.at(i) != nullptr){
                cout << this->checkout.at(i)->id << "," ;
                cout << this->checkout.at(i)->documents << "," ;
                cout << this->checkout.at(i)->tolerance << " ";
            }
            cout << "]";
        }
        cout << endl;
    }
    void show_entrance(){
        cout << "{";
        for(list<Customer*>::iterator it = this->entrance.begin(); it != this->entrance.end(); it++){
            if(*it != nullptr){
                cout << (*it)->id << "," ;
                cout << (*it)->documents << "," ;
                cout << (*it)->tolerance << " ";
            }
        }
        cout << "}" << endl;
    }
    void show_exit(){
        queue<Customer*> backup = this->exit;
        cout << "{ ";
        while (!backup.empty()){
		    cout << backup.front()->id << ", ";
            cout << backup.front()->documents << ", ";
            cout << backup.front()->tolerance << " ";
		    backup.pop();
            
	    }
	    cout<< "}" << endl;
    }
    void init_checkout(int size){
        if(this->checkout.size() > 0){
            free(&this->checkout);
        }
        else{
            for(int i = 0; i < size; i++){
                this->checkout.push_back(nullptr);
            }
        }
    }
    void process_document(){
        for(int i = 0; i < this->checkout.size(); i++){
            if(this->entrance.size() != 0){
                if(this->checkout.at(i) == nullptr){
                    this->checkout.at(i) = this->entrance.front();
                    this->entrance.pop_front();
                    this->show_checkout();
                    this->show_entrance();
                }
                else{
                    //processando documento
                    if(this->checkout.at(i)->documents != 0){
                        if(this->checkout.at(i)->tolerance == 0){
                            this->checkout.at(i) = nullptr;
                            this->entrance.pop_front();
                            //TODO mandar para saída
                        }
                        else{
                            this->checkout.at(i)->documents -= 1;
                            this->show_checkout();
                            this->show_entrance();
                        }
                    }
                    else{
                        this->exit.push(this->checkout.at(i));
                        this->checkout.at(i) = nullptr;
                        this->show_checkout();
                        this->show_entrance();
                    }
                }
            }
            else{
                this->show_checkout();
                this->show_entrance();
            }
        }
    }
    void tic(){
        while(this->checkout.size() != 0){

        }
    }
    void add_customer(Customer* c){
        this->entrance.push_back(c);
    }
    void add_exit(Customer* c){
        this->exit.push(c);
    }
};
