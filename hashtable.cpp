#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

typedef Node* HashTable;

int hashFunc(int value, int hashTablesize);
void Init(HashTable*& ht, int n);
void AddTail(Node*& p, int value);
void Delete(Node*& p, int value);
Node* search_SC(HashTable* ht, int value, int hashTablesize);
void insert_SC(HashTable*& ht, int value, int hashTablesize);
void remove_SC(HashTable*& ht, int value, int hashTablesize);
int search_LS(int* ht, int value, int hashTablesize);
void insert_LS(int* ht, int value, int hashTablesize);
void remove_LS(int* ht, int value, int hashTablesize);
int search_QP(int* ht, int value, int hashTablesize);
void insert_QP(int* ht, int value, int hashTablesize);
void remove_QP(int* ht, int value, int hashTablesize);
int hashFunc2(int value, int hashTablesize);
int search_DH(int* ht, int value, int hashTablesize);
void insert_DH(int* ht, int value, int hashTablesize);
void remove_DH(int* ht, int value, int hashTablesize);

int hashFunc(int value, int hashTablesize) {
	return value % hashTablesize;
}

void Init(HashTable*& ht,int n) {
	ht = new HashTable[n];
	for (int i = 0; i < n; i++) {
		ht[i] = NULL;
	}
}

void AddTail(Node*& p, int value) {
	Node* newNode = new Node{ value,NULL };
	if (p == NULL) {
		p = newNode;
	}
	else {
		Node* tmp = p;
		while (tmp != NULL && tmp->next !=NULL) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
}

void Delete(Node*& p, int value) {
	if (p != NULL) {
		Node* prev = NULL;
		Node* tmp = p;
		while (tmp != NULL) {
			if (tmp->data == value) {
				if (prev != NULL) {
					prev->next = tmp->next;
					delete tmp;
				}
				else {
					p = p->next;
				}
				return;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
}

Node* search_SC(HashTable *ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	Node* f = ht[index];
	while (f != NULL) {
		if (f->data == value) return f;
		f = f->next;
	}
	return NULL;
}

void insert_SC(HashTable*& ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	AddTail(ht[index], value);
}

void remove_SC(HashTable*& ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	Delete(ht[index], value);
}

int search_LS(int* ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	int cnt = 0;
	while (ht[index] != value && cnt != hashTablesize) {
		index = (index + 1) % hashTablesize;
		cnt++;
	}
	return (ht[index] == value) ? index : -1;
}

void insert_LS(int* ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	while (ht[index] != 0) {
		index = (index + 1) % hashTablesize;
	}
	ht[index] = value;
}

void remove_LS(int* ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	int cnt = 0;
	while (ht[index] != value && cnt != hashTablesize) {
		index = (index + 1) % hashTablesize;
		cnt++;
	}
	if (cnt != hashTablesize) {
		ht[index] = 0;
	}
}

int search_QP(int* ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	int cnt = 0;
	int i = 1;
	while (ht[index] != value && cnt != hashTablesize) {
		index = (index + i*i) % hashTablesize;
		cnt++;
		i++;
	}
	return (ht[index] == value) ? index : -1;
}

void insert_QP(int* ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	int i = 1;
	while (ht[index] != 0) {
		index = (index + i*i) % hashTablesize;
		i++;
	}
	ht[index] = value;
}

void remove_QP(int* ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	int cnt = 0;
	int i = 1;
	while (ht[index] != value && cnt != hashTablesize) {
		index = (index + i*i) % hashTablesize;
		cnt++;
		i++;
	}
	if (cnt != hashTablesize) {
		ht[index] = 0;
	}
}

int hashFunc2(int value, int hashTablesize) {
	return (hashTablesize - 2) - (value % (hashTablesize - 2));
}

int search_DH(int* ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	int index2 = hashFunc2(value, hashTablesize);
	int cnt = 0;
	while (ht[index] != value && cnt != hashTablesize) {
		index = (index + index2) % hashTablesize;
		cnt++;
	}
	return (ht[index] == value) ? index : -1;
}

void insert_DH(int* ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	int index2 = hashFunc2(value, hashTablesize);
	while (ht[index] != 0) {
		index = (index + index2) % hashTablesize;
	}
	ht[index] = value;
}

void remove_DH(int* ht, int value, int hashTablesize) {
	int index = hashFunc(value, hashTablesize);
	int index2 = hashFunc2(value, hashTablesize);
	int cnt = 0;
	while (ht[index] != value && cnt != hashTablesize) {
		index = (index + index2) % hashTablesize;
		cnt++;
	}
	if (cnt != hashTablesize) {
		ht[index] = 0;
	}
}

int main() {
	/*
	HashTable* mhashTable = NULL;
	int a[7] = { 50, 700, 76, 85, 92, 73, 101 };
	Init(mhashTable, 7);
	for (int i = 0; i < 7; i++) {
		insert_LS(mhashTable, a[i], 7);
	}
	*/
	int mhashTable[7] = { 0 };
	int a[7] = { 50, 700, 76, 85, 92, 73, 101 };
	for (int i = 0; i < 7; i++) {
		insert_DH(mhashTable, a[i], 7);
	}
	cout << search_DH(mhashTable, 92, 7) << endl;
	cout << search_DH(mhashTable, 102, 7) << endl;
	remove_DH(mhashTable, 73,7);
	remove_DH(mhashTable, 50, 7);
	remove_DH(mhashTable, 92, 7);
	remove_DH(mhashTable, 101, 7); 
	remove_DH(mhashTable, 102, 7);
	cout << search_DH(mhashTable, 92, 7) << endl;
	cout << search_DH(mhashTable, 85, 7) << endl;
}