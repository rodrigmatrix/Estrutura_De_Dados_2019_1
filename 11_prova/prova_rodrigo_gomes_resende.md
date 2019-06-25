# Prova Rodrigo Gomes Resende 
## Matrícula 421757
### Questão 1
A inserção ocorre com marcações de valores em memória em ordem sequencial. É verificado se o valor existe em memória, se ele já existir é passado para o próximo local vazio na memória. A busca ocorre verificando onde o valor deve se encontrar, se ele não estiver naquele lugar da memória, é verificado a próxima posição dela até um espaço vazio ser encontrado. Na remoção, ocorre a mesma lógica da busca mas é necessário refazer a tabela inserindo novamente os valores presentes nela para que eles estejam na posição de memória certa após a remoção. Outra forma seria marcando os elementos para dizer se eles já foram removidos ou não, fazendo com que seja possível inserir naquela posição os elementos mantendo a posição de memória correta.
### Questão 2
```cpp
#include <iostream>
using namespace std;
typedef struct Node{
        Node * next;
        int value;
        Node(int value, Node * next){
            this->value = value;
            this->next = next;
        }
};
typedef struct List{
    Node * first;
    List(){
        this->first = nullptr;
    }
    List * clone(List &other){
        List * newList = new List();
        Node * node = other.first;
        Node * nodeClone = newList.first;
        newList->first = node;
        do{
            if(node == nullptr){
                nodeClone->next = nullptr;
                return newList;
            }
            nodeClone->next = new Node(node.value, node.next);
            nodeClone = nodeClone->next;
            node = node.next;
        }while(this->first != node);
        return newList;
    }
};
```
### Questão 3
Chamar a root da árvore para esquerda e direita. Em cada nó, salvar o valor de cada elemento em uma lista com o seu último ancestral. Ao encontrar ambos os elementos, verificar qual dos dois foi inserido primeiro e verificar seu ancestral e se ele passou pelo outro elemento.
### Questão 4
```cpp
```

