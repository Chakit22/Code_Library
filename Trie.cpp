#include<bits/stdc++.h>
using namespace std;

class TrieNode {
public:
	TrieNode* children[26];
	bool isEOW;

	TrieNode() {
		for (int i = 0; i < 26; ++i)
			children[i] = NULL;
		isEOW = false;
	}
};

class Trie {
	TrieNode* root;
	int size;
public:
	Trie() {
		root = new TrieNode;
		size = 0;
	}

	void insert(string s) {
		TrieNode* temp = root;

		for (int i = 0; i < s.length(); ++i) {
			if (temp->children[s[i] - 'a'] == NULL) {
				temp->children[s[i] - 'a'] = new TrieNode;
			}
			temp = temp->children[s[i] - 'a'];
		}
		temp->isEOW = true;
	}

	bool search(string s) {
		TrieNode* temp = root;
		for (int i = 0; i < s.size(); ++i) {
			if (temp->children[s[i] - 'a'] == NULL)
				return false;
			temp = temp->children[s[i] - 'a'];
		}
		return temp->isEOW;
	}
};

int main() {
	Trie t;
	t.insert("cat");
	cout << t.search("car");
}