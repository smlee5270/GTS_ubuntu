#include<stdio.h>
#include<stdlib.h>

struct bucket* hashTable = NULL;
int SIZE = 10;



struct Node{

	int key;
	int value;
	struct Node* Next;
};



struct bucket{

	int count;
	struct Node* head;
};



int hashFunction(int key){

	return key % SIZE;
}



struct Node* Create(int key, int value){

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

	newNode->Next = NULL;
	newNode->key = key;
	newNode->value = value;

	return newNode;
}



void Insert(int key, int value){

			
	int hashIndex = hashFunction(key);

	struct Node* newNode = Create(key, value);

	if(hashTable[hashIndex].count == 0) {

		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count = 1;
	}

	
	else {
		
		newNode->Next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count++;
	}
		
	printf("Insert Node Success\n");
	return;

}



void Remove(int key) {


	int hashIndex = hashFunction(key);

	if(hashTable[hashIndex].head == NULL) {

		printf("cannot find Node\n");
		return;
	}

	struct Node* Node = hashTable[hashIndex].head;
	struct Node* trace;

	while(Node != NULL){

		//find Node
		if(Node->key == key){

			if(Node == hashTable[hashIndex].head) {
				hashTable[hashIndex].head = Node->Next; 
			}

			else {
				trace->Next = Node->Next;
			}
		}


		trace = Node;
		Node = Node->Next;
	}

	free(Node);
	hashTable[hashIndex].count--;
	printf("Remove Node Success\n");

	return;
}



void Search(int key) {

	int hashIndex = hashFunction(key);

	struct Node* Node = hashTable[hashIndex].head;

	while(Node != NULL) {

		
		if(Node->key == key){
		
			printf("find Node key : [%d] Value : [%d]\n",Node->key, Node->value); 
			return;
		}

		Node = Node->Next;
	}

	printf("cannot find Node\n");
	return;
}


void Display() {

	struct Node* horse;

	for(int i=0; i<SIZE; i++){
		
		horse = hashTable[i].head;
		printf("Bucket[%d]\n", i);

		while(horse != NULL){

			printf("find Node key : [%d] Value : [%d]\n", horse->key, horse->value);
			horse = horse->Next;
		}
	}

	printf("------------------end of Display-------------------\n");
	
	return;
}



int main(void){


	hashTable = (struct bucket*)malloc(SIZE*sizeof(struct bucket));

	Insert(0, 1);
        Insert(1, 10);
        Insert(11, 90);
        Insert(21, 94);
        Insert(31, 23);
        Insert(6, 25);
        Insert(97, 4);

	Display();

	Remove(31);
	Remove(11);

	Display();

	Search(6);
	Search(85);

	return 0;
}


