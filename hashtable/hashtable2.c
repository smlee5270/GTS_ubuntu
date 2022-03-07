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
	newNode->key = key;
	newNode->value = value;
	newNode->Next = NULL;

	return newNode;
}


void Insert(int key, int value){

	
	int hashIndex = hashFunction(key);

	struct Node* newNode = Create(key, value);

	if(hashTable[hashIndex].count == 0) {

		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count = 1;	

	} else {

		newNode->Next = hashTable[hashIndex].head;
		hashTable[hashIndex].head = newNode;
		hashTable[hashIndex].count++;
	}

	printf("Success Node Insert!\n");
	return;


}


void Search(int key){

	int hashIndex = hashFunction(key);

	if(hashTable[hashIndex].head == NULL){

		printf("Node Empty..\n");

	} else {

	
		struct Node* horse = hashTable[hashIndex].head;

		while(horse) {

			if(horse->key == key){
				
				printf("Search Success! key: %d, value: %d\n", horse->key, horse->value);
				return;
			}

			horse = horse->Next;		
		}
		
		printf("Search Fail..\n");
		return;
	}
}


void Remove(int key){

	int hashIndex = hashFunction(key);

	
	if(hashTable[hashIndex].head == NULL) {

		printf("cannot find Node\n");
		return;
	}


	struct Node* horse = hashTable[hashIndex].head;
	struct Node* last = NULL;


	while(horse != NULL) {
	
		if(horse->key == key) {

			if(horse == hashTable[hashIndex].head) {

				hashTable[hashIndex].head = horse->Next;
	
			} else {

				last->Next = horse->Next;
			}

		
			horse = horse->Next;
			last = horse;	
		}
	
		printf("Remove Node Success! key:%d  value:%d\n", horse->key, horse->value);
		free(horse);
		hashTable[hashIndex].count--;
		return;
	}
	

	printf("Remove Fail..\n");
	return;
}


void Show(void){

	
	for(int i=0; i<SIZE; i++) {
		
		struct Node* horse = hashTable[i].head;
		
		while(horse != NULL) {

			printf("Bucket:%d  key:%d  value:%d\n", i, horse->key, horse->value);
			horse = horse->Next;
		}
	}

	return;
}




int main(void){

	hashTable = (struct bucket*)malloc(SIZE*sizeof(struct bucket));

	Insert(11, 32);
	Insert(22, 35);
	Insert(53, 532);
	Insert(421, 52);
	Insert(422, 62);
	Insert(623, 342);
	Insert(53213, 343522);
	Insert(424513, 3212);
	Insert(2121423, 53322);
	Insert(775323, 323142);
	Insert(661323, 43232);
	Insert(422443, 56722);
	Insert(9, 72);
	Insert(8, 82);
	Insert(7, 92);


	Show();

	Search(11);
	Search(2121423);
	Remove(2121423);
	Remove(661323);
	Remove(11);

	Show();
	
	return 0;


}
