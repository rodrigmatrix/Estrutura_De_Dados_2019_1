#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
using namespace std;

struct Ambient{
    list<char> texto;
    list<char>::iterator cursor;

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

    void deleteChar(){
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
                editor->deleteChar();
                break;

                case 'D':
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
