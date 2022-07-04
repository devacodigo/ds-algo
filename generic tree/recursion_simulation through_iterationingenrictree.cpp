#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    vector<Node*>children;
};
class Pair{
  public:
  Node* node;
  int state;
  // Pair(Node* node,int state){
  //   this->node=node;
  //   this->state=state;
  // }
};

void iterativePreAndPostOrder(Node* root){
	//write your code here
  string preorder;
  string postorder;
  stack<Pair*> st;

  Pair *rootp=new Pair();
  rootp->node=root;
  rootp->state=-1;
  

  st.push(rootp);

  while(st.size()>0){
    Pair *peekp;
    peekp=st.top();
    int x= peekp->node->children.size();

    if(peekp->state==-1){
      preorder+=to_string(peekp->node->data)+" ";
      
      peekp->state++;
      // cout<<preorder<<endl;

    }
    else if(peekp->state>=0 && peekp->state < x){
      Pair *childp=new Pair();
      childp->node=peekp->node->children.at(peekp->state);
      childp->state=-1;
      
      
      st.push(childp);

      peekp->state++;
      // cout<<preorder<<endl;

    }
    else if(peekp->state==peekp->node->children.size()){
      postorder+=to_string(peekp->node->data)+" ";
      
      
      peekp->state++;
      // cout<<preorder<<endl;
            

    }
    else
    {
      st.pop();
    }
  }
  cout<<preorder<<endl;
  cout<<postorder<<endl;
  
}

Node* construct(vector<int>&arr) {
    Node* root = nullptr;

    stack <Node*> st;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == -1) {
        st.pop();
      } else {
        Node* t = new Node();
        t->data = arr[i];

        if (st.size() > 0) {
          st.top()->children.push_back(t);
        } else {
          root = t;
        }
        st.push(t);
      }
    }
    return root;
  }
  
int main(){
    int n,x;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    Node *root = construct(arr);
    iterativePreAndPostOrder(root);
    return 0;
}
 