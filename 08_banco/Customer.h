#include <iostream>
using namespace std;

class Customer{
    public:
    string id;
    int documents;
    int tolerance;

    Customer(string id, int documents, int tolerance){
        this->id = id;
        this->documents = documents;
        this->tolerance = tolerance;
    }
};