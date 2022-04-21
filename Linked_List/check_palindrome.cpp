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

// void print_linked_list(Node* root,int n){
// 	Node* tmp = root;
// 	for(int i=0;i<n;++i){
// 		cout<<tmp->data<<"   ";
// 		tmp = tmp->next;
// 	}

// 	cout<<"\n";
// }

// Node* reverse_linked_list(Node *root){
// 	if(root == NULL or root->next == NULL)
// 		return root;
// 	Node* prev = NULL;
// 	Node* cur = root;
// 	Node* nxt = cur->next;

// 	while(nxt != NULL){
// 		cur->next = prev;
// 		Node* tmp = nxt->next;
// 		prev = cur;
// 		cur = nxt;
// 		nxt = tmp;
// 	}
// 	cur->next = prev;
// 	return cur;
// }

// Node* find_mid(Node* root){
// 	if(root == NULL or root->next == NULL)
// 		return root;
// 	Node* slow = root;
// 	Node* fast = root;

// 	while(fast != NULL and fast->next != NULL){
// 		slow = slow->next;
// 		fast = fast->next->next;
// 	}
// 	return slow;
// }

// bool checkPalindrome(Node* root){
// 	Node *mid = find_mid(root);
// 	mid = reverse_linked_list(mid);

// 	Node *p1=NULL,*p2 = NULL;
// 	p1=root;
// 	p2=mid;

// 	while(p1 != NULL and p2 != NULL){
// 		if(p1->data != p2->data)
// 			return false;

// 		p1 = p1->next;
// 		p2 = p2->next;
// 	}
// 	return true;
// }

int main(){
	Node* root = NULL;
	int nodes;
	cin>>nodes ;
	for(int i=0;i<nodes;++i){
		int item;
		cin>>item;
		root = appendNode(root,item);
	}

	// if(checkPalindrome(root))
	// 	cout<<"Linked List is Palindrome";
	// else
	// 	cout<<"Linked List is not Palindrome.";
}
