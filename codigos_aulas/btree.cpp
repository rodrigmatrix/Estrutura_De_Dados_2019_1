#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node(int value = 0, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

struct BTree{
    Node * root;
    BTree(){
        this->root = nullptr;
    }

    void _destroy(Node * node){
        if(node == nullptr)
            return;
        _destroy(node->left);
        _destroy(node->right);
        delete node;
    }

    ~BTree(){
        _destroy(this->root);
    }

    bool equals(Node * one, Node * two){
        if(one == nullptr && two == nullptr){
            return true;
        }
        else if(one != nullptr && two != nullptr){
            if(one->value == two->value){
                return equals(one->left, two->left) && equals(one->right, two->right);
            }
        }
        return false;
    }

    bool equals(BTree other){
        return equals(root, other.root);
    }


    void _serialize(stringstream& ss, Node * node){
        if(node == nullptr)
            ss << "# ";
        else{
            ss << node->value << " ";
            _serialize(ss, node->left);
            _serialize(ss, node->right);
        }
    }

    string serialize(){
        stringstream ss;
        _serialize(ss, this->root);
        return ss.str();
    }

    Node ** smart_find(Node ** elo, int value){
        if((*elo) == nullptr){
            return elo;
        }
        else if((*elo)->value == value){
            return elo;
        }
        else{
            if(value < (*elo)->value){
                return smart_find(&(*elo)->left, value);
            }
            else{
                return smart_find(&(*elo)->right, value);
            } 
        }
    }

    bool find(int value){
        Node ** elo = smart_find(&root, value);
        return (*elo != nullptr);
    }

    void insert(int value){
        Node ** elo = smart_find(&root, value);
        if(*elo == nullptr){
            *elo = new Node(value);
        }
    }

    void _show(Node * node, int nivel){
        if(node == nullptr){
            cout << string(nivel, '.') << "#\n";
            return;
        }
        cout << string(nivel, '.') << node->value << "\n";
        if(node->left == nullptr && node->right == nullptr)
            return;
        _show(node->left, nivel + 1);
        _show(node->right, nivel + 1);
    }

    void show(){
        _show(this->root, 0);
    }


    void _bshow(Node * node, string heranca, ostream & fout){
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            _bshow(node->left , heranca + "l", fout);
        int tam = heranca.size();
        for(int i = 0; i < tam - 1; i++){
            if(heranca[i] != heranca[i + 1])
                fout << "│" << "   ";
            else
                fout << " " << "   ";
        }
        if(heranca != ""){
            if(heranca.back() == 'l')
                fout << "┌───";
            else
                fout << "└───";
        }
        if(node == nullptr){
            fout << "#" << endl;
            return;
        }
        fout << node->value << endl;
        if(node != nullptr && (node->left != nullptr || node->right != nullptr))
            _bshow(node->right, heranca + "r", fout);
    }

    void bshow(){
        _bshow(this->root, "", cout);
    }
};




int main(int argc, char * argv[]){
    if(argc < 2){
        puts("./exec numero_de_nos");
        exit(1);
    }
    int nos;
    stringstream(argv[1]) >> nos;
    BTree bt;
    srand(time(NULL));
    for(int i = 0; i < nos; i++)
        bt.insert(rand() % 10);

    puts(">>>>>>>>");
    cout << bt.serialize() << "\n";
    puts("========");
    bt.show();
    puts("<<<<<<<<");
}