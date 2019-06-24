#include <iostream>
#include <iterator>
#include <list>
#include <utility>
#include <sstream>
using namespace std;

struct Ambient{
    list<char> texto;
    list<char>::iterator cursor;
    list<pair<char*, char> > erased;

    Ambient(){
        this->cursor = texto.begin();
    }

    void show_ambient(){
        for(auto it = texto.begin(); it != texto.end(); it++){
            if(it == this->cursor){
                cout << '#';
            }
            else{
                cout << *it;
            }
        }
        if(this->cursor == this->texto.end()){
            cout << '#';
        }
    }

    void insertChar(char c){
        texto.insert(this->cursor, c);
        this->cursor = this->cursor++;
    }

    void deleteFront(){
        auto del = this->cursor;
        this->cursor++;
        this->texto.erase(del);
    }

    void ctrlZ(){
        
    }

    void deleteBackspace(){
        if((*this->cursor) == this->texto.front()){
            return;
        }
        // auto pair = make_pair(this->cursor, *(this->cursor));
        // this->erased.insert(pair.first, pair.second, this->cursor);
        auto del = this->cursor;
        del--;
        this->texto.erase(del);
    }

    void moveCursorLeft(){
        this->cursor--;
    }

    void moveCursorRight(){
        this->cursor++;
    }
};

struct Editor{
    list<Ambient> linha_temporal;
    list<Ambient>::iterator estado_atual;
};

int main(){
    Ambient * editor = new Ambient();
    string input;
    while(true){
        getline(cin, input);
        stringstream ui(input);
        char cmd;
        while(ui >> cmd){
            switch (cmd){
                case 'R':
            
                break;

                case 'B':
                editor->deleteBackspace();
                break;

                case 'D':
                editor->deleteFront();
                break;

                case '>':
                editor->moveCursorRight();
                break;

                case '<':
                editor->moveCursorLeft();
                break;

                case 'Z':
                break;

                case 'Y':
                break;

                case 'A':
                break;

                case 'V':
                break;

                default:
                editor->insertChar(cmd);
                break;
            }
        }
        system("clear");
        editor->show_ambient();
    }
}
