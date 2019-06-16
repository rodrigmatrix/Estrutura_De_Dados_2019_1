#include <iostream>
#include <cstdlib>
#include <sstream>
using namespace std;

struct Node{
    int value;
    Node * left;
    Node * right;
    Node * father;
    bool isMarc;
    
    Node(int value = 0, Node * father = nullptr, Node * left = nullptr, Node * right = nullptr){
        this->value = value;
        this->left = left;
        this->right = right;
        this->father = father;
        this->isMarc = true;
    }
};

struct BSTree{
    Node * root;
    BSTree(){
        this->root = new Node();
    }

    void _destroy(Node * node){
        if(node == nullptr)
            return;
        _destroy(node->left);
        _destroy(node->right);
        delete node;
    }

    ~BSTree(){
        _destroy(this->root);
    }
    
    bool equals(Node * one, Node * two){
        if(one == nullptr && two == nullptr)
            return true;
        if(one != nullptr && two != nullptr){
            if(one->value == two->value)
                return equals(one->left, two->left) && equals(one->right, two->right);
        }
        return false;
    }

    bool equals(BSTree other){
        return equals(root, other.root);
    }

    void _serialize(stringstream& ss, Node * node){
        if(node->isMarc)
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

    Node * smart_find(Node * node, int value){
        if(node->isMarc || node->value == value)
            return node;
        if (value < node->value)
            return smart_find(node->left, value);
        else
            return smart_find(node->right, value);
    }

    bool find(int value){
        Node * node = smart_find(root, value);
        return (!node->isMarc);
    }

    void insert(int value){
        Node * node = smart_find(root, value);
        if(node->isMarc){
            node->isMarc = false;
            node->value = value;
            node->left = new Node(0, node);
            node->right = new Node(0, node);
        }
    }

    void _show(Node * node, int nivel){
        if(node->isMarc){
            cout << string(nivel, '.') << "#\n";
            return;
        }
        if(!node->left->isMarc || !node->right->isMarc)
            _show(node->left, nivel + 1);
        cout << string(nivel, '.') << node->value << "\n";
        if(!node->left->isMarc || !node->right->isMarc)
            _show(node->right, nivel + 1);
    }

    void show(){
        _show(this->root, 0);
    }


    void _bshow(Node * node, string heranca, ostream & fout){
        if(!node->isMarc && (!node->left->isMarc || !node->right->isMarc))
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
        if(node->isMarc){
            fout << "#" << endl;
            return;
        }
        fout << node->value << endl;
        if(!node->isMarc && (!node->left->isMarc || !node->right->isMarc))
            _bshow(node->right, heranca + "r", fout);
    }

    void bshow(){
        _bshow(this->root, "", cout);
    }

    void remove(int value){
        auto elo = smart_find(root, value);
        
        if(elo->isMarc){
            return;
        }

        if(elo->left->isMarc && elo->right->isMarc){
            elo->isMarc = true;
            delete(elo->left);
            delete(elo->right);
            elo->left = nullptr;
            elo->right = nullptr;
        }
        if(elo->right->isMarc){
            elo = elo->right;
            
        }

        if(!elo->left->isMarc){

        }

        

    }
};




int main(){
    BSTree bt;
    string line, cmd;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "add"){
            int value;
            while(ss >> value)
                bt.insert(value);
        }else if(cmd == "rm"){
            int value;
            ss >> value;
//            bt.remove(value);
        }else if(cmd == "show"){
            bt.bshow();
        }else if(cmd == "find"){
            int value;
            ss >> value;
            cout << (bt.find(value) ? "Encontrei\n" : "Nao encontrei\n");
        }else{
            cout << "fail: comando invalido\n"; 
        }

    }
}