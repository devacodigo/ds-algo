#include<bits/stdc++.h>

using namespace std;

// structure of node
class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    // Node(int data)
    // {
    //     this->data = data;
    // }
};
class Pair
{
    public:
    int state;
    Node* node=nullptr;
};
int idx=1;


Node *constructTree(vector<int> &arr)
{
    Node* root=new Node();
    root->data=arr[0];
    Pair* rootp=new Pair;
    rootp->node=root;
    rootp->state=1;
    stack<Pair*> st;
    st.push(rootp);

    while(st.size()>0){
        Pair* peekp=new Pair();
        peekp=st.top();
        if(peekp->state==1){
            if(arr[idx]!=-1){
                Node* lcn=new Node();
                lcn->data=arr[idx];
                peekp->node->left=lcn;
                Pair* lcnp=new Pair;
                lcnp->node=lcn;
                lcnp->state=1;
                
            
                st.push(lcnp);

            }
            
            peekp->state++;
            idx++;

        }
        else if(peekp->state==2){
            if(arr[idx]!=-1){
                Node* rcn=new Node();
                rcn->data=arr[idx];
                peekp->node->right=rcn;
                Pair* rcnp=new Pair;
                rcnp->node=rcn;
                rcnp->state=1;
            
                st.push(rcnp);
                

            }
            peekp->state++;
            idx++;
            


        }
        else if(peekp->state==3){
            st.pop();
             
        }
    }
    return root;

}
void display(Node *node)
{
   if(node==NULL){
       return;
   }
   string str="<-"+to_string(node->data)+"->";
   string lstr=node->left == NULL? ".":to_string(node->left->data);
   string rstr=node->right == NULL? ".":to_string(node->right->data);
   cout<<lstr+str+rstr<<endl;
   display(node->left);
   display(node->right);

   
   
}


int size(Node *node)
{
   //write your code here
   if(node==NULL){
       return 0;
   }
   int s=1;
   s+=size(node->left);
   s+=size(node->right);
   return s;

}

int height(Node *node)
{
    //write your code here
    if(node==NULL){
        return 0;
    }
    if(node->left==NULL && node->right==NULL){
        return 0;
    }
    int h=1;
    int l=height(node->left);
    int r=height(node->right);
    h+=max(l,r);
    return h;


}

int maximum(Node *node)
{
    //write your code here
    if(node==NULL){
        return 0;
    }
    int l=maximum(node->left);
    int r=maximum(node->right);
    int m=max(l,r);
    int ans=max(m,node->data);
    return ans;
}

int sum(Node *node)
{
    
    //write your code here
    if(node==NULL){
        return 0;
    }
    int s=node->data;
    s+=sum(node->left);
    s+=sum(node->right);
    return s;
}

int main()
{
 
  int n;
  cin>>n;
  
  vector<int> arr(n,0);
  for(int i = 0; i < n; i++){
      string temp;
      cin>>temp;
      
      if(temp=="n")
      {
        arr[i] = -1;  
      }
      else
      {
        arr[i] = stoi(temp); 
      }
  }
  
   Node *root = constructTree(arr);
//    display(root);

    int sz = size(root);
    int sm = sum(root);
    int max = maximum(root);
    int ht = height(root);
    cout<<sz<<endl;
    cout<<sm<<endl;
    cout<<max<<endl;
    cout<<ht<<endl;
  }