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
    int processed;
    int lost;

    Bank (int processed = 0, int lost = 0){
        this->processed = processed;
        this->lost = lost;
    }

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
            this->checkout.clear();
            for(int i = 0; i < size; i++){
                this->checkout.push_back(nullptr);
            }
        }
        else{
            for(int i = 0; i < size; i++){
                this->checkout.push_back(nullptr);
            }
        }
    }

    void update_tolerance(){
        for(list<Customer*>::iterator it = this->entrance.begin(); it != this->entrance.end(); it++){
            if((*it) != nullptr){
                if((*it)->tolerance == 0){
                    this->lost += (*it)->documents;
                    this->entrance.erase(it);
                    this->exit.push(*it);
                    
                }
                else{
                    (*it)->tolerance -= 1;
                }
            }
        }
    }
    void clear_exit(){
         while (!this->exit.empty()){
		    this->exit.pop();
	    }
    }
    void process_document(){
        for(int i = 0; i < this->checkout.size(); i++){
                if(this->checkout.at(i) == nullptr){
                    if(this->entrance.size() != 0){
                        this->checkout.at(i) = this->entrance.front(); //TODO verificar se tem alguem
                        this->entrance.pop_front();
                    }
                }
                else{
                    //processando documento
                    if(this->checkout.at(i)->documents != 0){
                        this->checkout.at(i)->documents -= 1;
                        this->processed += 1;
                        if(this->checkout.at(i)->documents == 0){
                            this->exit.push(this->checkout.at(i));
                            this->checkout.at(i) = nullptr;
                        }
                    }
                    else{
                        this->exit.push(this->checkout.at(i));
                        this->checkout.at(i) = nullptr;
                    }
                }
        }
        this->update_tolerance();
        this->clear_exit();
    }
    void add_customer(Customer* c){
        this->entrance.push_back(c);
    }
    void add_exit(Customer* c){
        this->exit.push(c);
    }
};