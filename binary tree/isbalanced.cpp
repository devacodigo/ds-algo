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

 class PPair {
    public:
    Node *node=nullptr;
    int state=0;

    PPair(Node *node, int state) {
      this->node = node;
      this->state = state;
    }
  };
class Pair{
    public:
    int ht=-1;
    bool flag=true;
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

// static bool flag=true;

// int  isbalance(Node *node)
// {
//     // write your code here 
//     if(node=NULL){
//       return -1;

//     }
//     int lh=isbalance(node->left);
//     int rh=isbalance(node->right);

//     bool val=abs(lh-rh)<=1;
//     if(val==false){
//       flag=false;
//     }
//     int htt=max(lh,rh)+1;

//     return htt;
  


// }

// through pair method

Pair* isbalance2(Node* node){
  if(node==NULL){
    Pair* pnull=new Pair();
    return pnull;
  }

  Pair* l=isbalance2(node->left);
  Pair* r= isbalance2(node->right);

  Pair* ans=new Pair();

  ans->ht=max(l->ht,r->ht)+1;
  bool flagatnode=abs(l->ht-r->ht)<=1;
  ans->flag=(l->flag==true) && (r->flag==false) && (flagatnode==true);
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

    
    Pair* r = isbalance2(root);
    if(r->flag==true)
    cout << "true";
    else 
    cout<<"false";
}