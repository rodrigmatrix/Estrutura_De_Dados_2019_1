# Questão 1

##### Vetor: 
O vetor possui acesso aleatório a memória, podendo acessar qual posição existente de uma posição. Isso facilita e torna a busca por indices possível. É difícil controlar suas posições principalmente ao tentar implementar algo circular em um vetor onde o controle de posições é importante para não acessar memórianão existente(segmentation fault).

 ##### Lista Ligada:
Acesso é sequencial, sendo necessário passar por todas os nodes para chegar em um lugar específico. Facilita na criação de estruturas que são circulares, remoção de dados é mais simples, não sendo necessário mover todos os elementos de um vetor por exemplo. 

 ##### Hash:
Facilita guardar dados por um tipo de dado específico por chave/valor. É difícil armazenar dados que precisem estar de forma sequencial, os valores são substituidos se tiverem a mesma chave. O controle de quais já existem é difícil.
 ##### Árvore:
Facilitar a organização de dados, diminuir a quantidade de passos necessários para chegar em um determinado local, otimizar e comprimir dados que podem ser dispostos em uma árvore através de um dicionário. Dados 

# Questão 2
```cpp
bool remove(Node* node, int value){
    if(node == nullptr){
        return false;
    }
    else if(node == head && node->value == value){
        head == nullptr;
    }
    else if(node->next->value == value){
        node->next = node->next->next;
        return true;
    }
    return remove(node->next, value);
}
remove(list->head, value);
```

# Questão 3

```kotlin
    private fun remove(): Boolean{
        
    }
```
# Questão 4

```

```
