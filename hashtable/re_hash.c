#include<stdio.h>
#include<stdlib.h>


struct bucket* hashTable = NULL;
int SIZE = 10;


struct bucket{
	
	int count;
	struct Node* head;
};


struct Node{

	int key;
	int value;
	struct Node* Next;
};


struct Node* Create(int key, int value){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->key = key;
	newNode->value = value;
	newNode->Next = NULL;

	return newNode;
}


int hashFunction(int key){

	return key % SIZE; 
}


void Insert(int key, int value){

	struct Node* newNode = Create(key, value);

	int hashIndex = hashFunction(key);

	
	if(hashTable[hashIndex].head == NULL){

		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count = 1;
		return;
	}


	struct Node* Node = hashTable[hashIndex].head;


	while(Node != NULL){

		Node = Node->Next;
	}

	Node = newNode;
	hashTable[hashIndex].count++;
	printf("Insert Success!\n");

}



void Remove(int key){

	int hashIndex = hashFunction(key);

	struct Node* Node;
	struct Node* trace;

	Node = hashTable[hashIndex].head;


	if(Node == NULL){

		printf("Cannot find Node\n");
		return 0;
	}
	

	while(Node != NULL) {

		//find key!
		if(Node->key == key) {
		
			//when Node is head
			if(Node == hashTable[hashIndex].head){
				hashTable[hashIndex].head = Node->Next;
			} else {

				trace->Next = Node->Next;
			}
		}
		//not find key
		else {
			trace = Node;
			Node = Node->Next;
		}
	}

	free(Node);
	printf("Remove Node Success!\n");
	return;

}


void Search(int key){

	int hashIndex = hashFunction(key);

	struct Node* Node = hashTable[hashIndex].head;
	
	while(Node != NULL) {


		if(Node->key == key){

			printf("Search Node key:[%d], value:[%d]\n",Node->key, Node->value);
			return 0;
		}
	}

	printf("Cannot Search Node..\n");
	return 0;
}


void Display(){



}





int main(void){

	hashTable = (struct bucket*)malloc(SIZE*sizeof(struct bucket));



}
