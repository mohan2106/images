#include<bits/stdc++.h>
using namespace std;

struct node{
	int x;
	int y;
	struct node *prev;
	struct node *next;
};
typedef struct node nd;

void addFirst(int x,int y,nd **root){
	nd *nextNode = (nd*)malloc(sizeof(nd));
	if(nextNode == NULL){
		cout<<"No space for new Node";
		return;
	}
	nextNode->x = x;
	nextNode->y = y;
	nextNode->prev= NULL;
	nextNode->next = *root;
	if(*root != NULL){
		(*root)->prev = nextNode;
	}
	
	*root = nextNode;
	//cout<<nextNode->x;
	return;
}
void delFirst(nd **root){
	if(*root == NULL){
		cout<<"Empty Linked List"<<endl;
	}else{
		nd *temp=*root;
		*root = temp->next;
		if(*root != NULL){
			(*root) ->prev = NULL;
		}
		free(temp);
	}
}
void del(int x,int y,nd **root){
	nd *temp=*root;
	if(temp == NULL){
		cout<<"Can't Delete key "<<x<<" Linked List is already Empty"<<endl;
	}else{
		while((temp->x != x) && (temp->y != y)){
			if(temp == NULL){
				break;
			}else{
				temp=temp->next;
			}
		}
		if(temp == NULL){
			cout<<"not Found"<<endl;
		}else{
			if(temp->prev != NULL){
				temp->prev->next = temp->next;
			}
			if(temp->next != NULL){
				temp->next->prev = temp->prev;
			}
			free(temp);
			
		}
	}

}
void printList(nd *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d %d\n", node->x, node->y); 
        node = node->next; 
    } 
} 


int main(){
	nd *root = NULL;
	cout<<"enter -1 to terminate"<<endl;
	while(1){
		int a;
		int b,c;
		cin>>a;
		if(a==-1){
			return 0;
		}
		switch(a){
			case 1:
				cin>>b>>c;
				addFirst(b,c,&root);
				break;
			case 2:
				delFirst(&root);
				break;
			case 3:
				cin>>b>>c;
				del(b,c,&root);
				break;
			// case 4:
			// 	cin>>b;
			// 	searchAtDistance(b,&root);
			// 	break;
			// case 5:
			// 	cin>>b>>C;
			// 	search(b,c,&root);
			// 	break;
			// case 6:
			// 	Length(&root);
			// 	break;
			case 10:
				printList(root);
				break;
			default:
				break;
		}
	}
	return 0;
}
