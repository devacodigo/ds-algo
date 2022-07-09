#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data=0;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

 class Pair {
    public:
    Node *node=nullptr;
    int state=0;

    Pair(Node *node, int state) {
      this->node = node;
      this->state = state;
    }
  };

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

//Display function
void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}


//Height function
int height(Node *node)
{
    return node == nullptr ? -1 : max(height(node->left), height(node->right)) + 1; 
}
class Pbst{
  public:
  int max=INT_MIN;
  int min=INT_MAX;
  bool isbst=true;

};


Pbst* bst(Node *node){
    // write your code here
    if(node==NULL){
      Pbst* bnull=new Pbst();
      return bnull;
    }

    Pbst* l=bst(node->left);
    Pbst* r=bst(node->right);

    Pbst* ans=new Pbst();
    bool atnode=(l->max<node->data) && (r->min>node->data);
    // if(!=true || r->min>node->data!=true){
    //   bool atnode=false;
    // }
    
    ans->isbst=((l->isbst==true) && (r->isbst==true)  && (atnode==true)) ? true:false;
    ans->min=min(l->min,min(r->min,node->data));
    ans->max=max(l->max,max(r->max,node->data));

    return ans;
    

 }

int main(){
    int n;
    cin>>n;
    
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++) {
        string tmp;
        cin>>tmp;
      if (tmp=="n") {
        arr[i] = -1;
      } else {
        arr[i] = stoi(tmp);
      }
    }
    
    
    Node *root = constructTree(arr);

    Pbst* r = bst(root);
    if(r->isbst == true)
    cout << "true";
    else 
    cout<<"false";
}