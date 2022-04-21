#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;

	Node(int val){
		data = val;
		left = right = NULL;
	}
};
void level_order_const_space(Node* root,int l,int h){
	Node* head = new Node(root->data);
	head->left = root;
	Node* cur = head;
	Node* tail = cur;
	int level = 1,len = 1;

	while(level<=h){
		int cnt = 0;
		for(int i=0;i<len;++i){
			if(cur->left->left != NULL){
				cnt++;
				Node* node = new Node(cur->left->left->data);
				node->left = cur->left->left;
				tail->right = node;
				tail = tail->right;
			}
			if(cur->left->right != NULL){
				cnt++;
				Node* node = new Node(cur->left->right->data);
				node->left = cur->left->right;
				tail->right = node;
				tail = tail->right;
			}
			if(level <= l-1){
				Node* tmp = cur;
				cur = cur->right;
				delete tmp;
				head = cur;
			}else
			cur=cur->right;
		}
		len = cnt;
		++level;
	}
	if(level < l)
		return;
	print(head);
}

Node* insertNode(Node* root,int item){
	if(root == NULL){
		Node * nwnode = new Node(item);
		return nwnode;
	}

	int choice;
	cout<<"Enter 1 to insert to the left : \n";
	cout<<"Enter 2 to insert to the right : \n";
	cin>>choice;

	if(choice == 1){
		root->left = insertNode(root->left,item);
	}else
	root->right = insertNode(root->right,item);

	return root;
}

int main(){
	int n;
	cout<<"Enter the number of nodes : \n";
	cin>>n;
	Node* root = NULL;
	for(int i=0;i<n;++i){
		int item;
		cout<<"Enter the data \n";
		cin>>item;
		root = insertNode(root,item);
	}
	int l,h;
	cin>>l>>h;
	level_order_const_space(root,l,h);
}