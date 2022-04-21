#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int val){
		data = val;
		next = NULL;
	}
};

Node* appendNode(Node* root,int item){
	if(root == NULL){
		Node *nwnode = new Node(item);
		return nwnode;
	}

	Node *tmp = root;
	while(tmp->next !=NULL){
		tmp = tmp->next;
	}

	tmp->next = new Node(item);
	return root;
}

void print_linked_list(Node* root,int n){
	Node* tmp = root;
	for(int i=0;i<n;++i){
		cout<<tmp->data<<"   ";
		tmp = tmp->next;
	}

	cout<<"\n";
}

Node* reverse_linked_list(Node *root){
	if(root == NULL or root->next == NULL)
		return root;
	Node* prev = NULL;
	Node* cur = root;
	Node* nxt = cur->next;

	while(nxt != NULL){
		cur->next = prev;
		Node* tmp = nxt->next;
		prev = cur;
		cur = nxt;
		nxt = tmp;
	}
	cur->next = prev;
	return cur;
}

int main(){
	Node* root = NULL;
	int nodes;
	cin>>nodes;
	for(int i=0;i<nodes;++i){
		int item;
		cin>>item;
		root = appendNode(root,item);
	}

	root = reverse_linked_list(root);
	print_linked_list(root,nodes);
}
