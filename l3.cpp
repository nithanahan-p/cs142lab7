#include<iostream>
using namespace std;

class node{
   public:
   int data;
   node*left;
   node*right;
   node*parent;
   node(int value){
     data=value;
     left=NULL;
     right=NULL;
     parent=NULL;
   }
};
class BST{
  public:
  node*root;
   BST(){
   root=NULL;}

void insert(int value){
   inserthelper(root,value);
}
void inserthelper(node*curr,int value){
   //base case if curr is null
   if(curr==NULL){
   curr=new node(value);
   //count++;
       if(root==NULL)
       root=curr;
       return;
   }

   //else compare the data with value and move to left or right
   else if(value<curr->data){
   //move left and insert
   if(curr->left==NULL){curr->left=new node(value);
   curr->left->parent=curr;}
   else inserthelper(curr->left,value);}
      else{
      //move right and insert
       if(curr->right==NULL){curr->right=new node(value);
       curr->right->parent=curr;}
       else inserthelper(curr->right,value);
      }
}

   
void display(){
   display2(root);
   cout<<endl;}
void display2(node*curr){
    //base condition
   if(curr==NULL) return;
   //display left
   
  else{
   display2(curr->left);
   //display curr
   cout<<curr->data<<",";
   //display right
   display2(curr->right);}
}

node*search1(node*curr,int value){
	//if value found or reach the end of the tree
	if(curr==NULL||curr->data==value)return curr;
	else if(value<curr->data) search1(curr->left,value);
	else search1(curr->right,value);}
bool search(int value){
	if(search1(root,value)!=NULL){
	cout<<"found"<<endl;}
	else{
		cout<<"not found"<<endl;}
	}
node*findmin(){
	findmin2(root);}
node*findmin2(node*curr){
	if(curr->left==NULL)cout<<curr->data<<endl;
	else findmin2(curr->left);
}	
		
void RAP(int value1,int value2){
	node *rep = search1(root,value2);
	node *current = search1(root,value1);
	RAP1(current,rep);
		}
void RAP1(node *current,node *rep){
	if(rep == root){
				root = current;	
	}
	else if(current == root){
	return;
	}
		else{
		if(rep->data > rep->parent->data){
			if(current == NULL){
			rep->parent->right = NULL;
			}
			   else{
			   rep->parent->right = current;
    		   if(current->data > current->parent->data){
    		   current->parent->right = NULL;
    			}
    			  else current->parent->left = NULL;
    			  current->parent = rep->parent;
		  }
					
		}
				else{
				    if(current == NULL){
			            rep->parent->left = NULL;
			        }
			        else{
			     	rep->parent->left = current;
					if(current->data>current->parent->data){
						current->parent->right = NULL;
					}
					else current->parent->left = NULL;
					current->parent = rep->parent;       
			        }
				
				}
			}
}
void delet(int value){
			//search deleting nodee
			node *current = search1(root,value);
			if(current == NULL){
			    return;
			}
			else{
				//replacing the values
			    if(current->left == NULL){ 
				    RAP1(current->right,current);
			    }
    			else if(current->right == NULL){ 
    				RAP1(current->left,current);
    			}
    			else{ 
    			    node *temp = findmin2(current->right);
    			    if(current == root){
    	                current->data = temp->data;
    	                RAP1(NULL,temp);
    				    delete temp;
    			    }
    			    else{
    				    RAP1(temp,current);
    				    temp->parent = current->parent;
    				    temp->left = current->left;
    				    delete temp;
    			    }
    			}
			}
			
}
		

  void print2DUtil(node *root, int space){
			// Base case  
			if (root == NULL)  
			    return;  
			// Increase distance between levels  
			space += 5;  
			// Process right child first  
			print2DUtil(root->right, space);  

			// Print current node after space  
			// count  
			cout<<endl;  
			for (int i = 5; i < space; i++)  
			    	cout<<" ";  
				cout<<root->data<<"\n";  

			// Process left child  
			print2DUtil(root->left, space);  
			}  

			// Wrapper over print2DUtil()  
			void print2D(){  
                cout << "******************************" << endl;
                // Pass initial space count as 0  
                print2DUtil(root, 0);  
                cout << "******************************" << endl;
             }
   
};
int main(){
    BST b1;
    b1.insert(6);
    b1.insert(9);
    b1.insert(4);
    b1.insert(3);
    b1.insert(5);
    b1.insert(1);
    b1.insert(7);
    b1.insert(10);
    b1.display();
    b1.print2D();
    cout<<"searching a node"<<endl;
    b1.search(8);
    cout<<"inserting a new node"<<endl;
    b1.insert(8);
    b1.display();
    cout<<"searching a node"<<endl;
    b1.search(8);
    cout<<"the min is:";
    b1.findmin();
    cout<<"replace with parent"<<endl;
    b1.RAP(6,5);
    b1.display();
     b1.print2D();
     cout<<"deleting a node"<<endl;
     b1.delet(3);
     b1.display();
     b1.print2D();
     
}
