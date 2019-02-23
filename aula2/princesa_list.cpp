#include <iostream>
#include <list>
using namespace std;

void show(list <int> heads){
   cout << "[ " ;
   for(list <int>::iterator i = heads.begin(); i != heads.end(); i++){
    //   if(head == 0){

    //   }
    //   else{

    //   }
    //   cout << ' ' << *i;
   }
}

void kill(list <int> heads, int head){
   heads.remove(head);
}

int main(){
   int size;
   int selected;
   cin >> size;
   cin >> selected;
   list <int> heads;
   for(int i = 1; i<=size; i++){
      heads.push_back(i);
   }
   // cout << "" << heads.size() << endl;
   show(heads);

}
