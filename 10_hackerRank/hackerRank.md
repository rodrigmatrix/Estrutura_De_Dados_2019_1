# Questões HackerRank

### Preorder Transversal
```cpp
void preOrder(Node *root) {
    if(root == nullptr){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
```
### Postorder Transversal
```cpp
void postOrder(Node *root) {
    if(root == nullptr){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << ' ';
}
```
### Inorder Transversal
```cpp
void inOrder(Node *root) {
    if(root == nullptr){
        return;
    }
    inOrder(root->left);
    cout << root->data << ' ';
    inOrder(root->right);
}
```
### Topview
```cpp
void topView(Node * root) {
    map<int, pair<int, int> > map;
    show(root, 0, 0, map);
    for(auto it: map){
        cout << it.second.first << ' ';
    }
}
void show(Node * root, int height, int level, auto &map){
    if(root == nullptr){
        return;
    }
    else if(map.find(height) == map.end() || level < map[height].second){
        map[height] = {root->data, level};
    }
    show(root->left, height - 1, level + 1, map);
    show(root->right, height + 1, level + 1, map);
}
```
### Height of Binary Tree
```cpp
int height(Node* root) {
    if(root == nullptr){
        return 0;
    }
    else if(root->left == nullptr && root->right == nullptr){
        return 0;
    }
    return largest(height(root->left), height(root->right))+1;
}
int largest(int left, int right){
    if(left > right){
        return left;
    }
    return right;
}
```
### Level Order Transversal
```cpp
void levelOrder(Node * root) {
    int level = levelTree(root);
    for(int i = 0; i < level; i++){
        show(root, i);
    }
}
void show(Node * root, int level){
    if(root == nullptr){
        return;
    }
    if(level == 0){
        cout << root->data << ' ';
    }
    else if(level > 0){
        show(root->left, level-1);
        show(root->right, level-1);
    }
}
int levelTree(Node * root){
    if(root == nullptr){
        return 0;
    }
    int left = levelTree(root->left);
    int right = levelTree(root->right);
    if(left > right){
        return left+1;
    }
    return right+1;
}
```
### Binary Search Tree: Insertion
```cpp
Node * insert(Node * root, int data) {
    if(root == nullptr){
        root = new Node(data);
    }
    else if(root->data > data){
        root->left = insert(root->left, data);
    }
    else if(root->data < data){
        root->right = insert(root->right, data);
    }
    return root;
}
```
### Binary Search Tree : Lowest Common Ancestor
```cpp
Node *lca(Node *root, int v1,int v2) {
    if(root == nullptr){
        return nullptr;
    }
    else if(root->data < v1 && root->data < v2){
        return lca(root->right, v1, v2);
    }
    else if(root->data > v1 && root->data > v2){
        return lca(root->left, v1, v2);
    }
    return root;
}
```
