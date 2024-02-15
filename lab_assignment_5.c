#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char letter;
	struct node* next;
} node;

// Returns number of nodes in the linkedList.
int length(node* head)
{
	node* temp = head;
	int count = 0;
	if(temp == NULL) {
		printf("List is NULL.");
		return 0;
	} else {
		while(temp != NULL) {
			count++;
			temp = temp->next;
		}
	}

	return count;

}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char* toCString(node* head)
{
	int lengthOfList = length(head);
	char* str = (char*)malloc(((lengthOfList)+1) * sizeof(char));
	node* temp = head;

	if(str == NULL) {
		printf("memory aloocation failed.");
		return NULL;
	}

	for(int i = 0; i < lengthOfList; i++) {
		str[i] = temp->letter;
		temp = temp->next;
	}

	str[lengthOfList] = '\0';

	return str;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	node* newNode = (node*)malloc(sizeof(node));
	if(newNode == NULL) {
		printf("memory allocation failed");
		return;
	}

	newNode->letter = c;
	newNode->next = NULL;

	if (*pHead == NULL) {
		*pHead = newNode;
	} else {
		node* temp = *pHead;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	
}

// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* temp = *pHead;
	node* front = NULL;

	while(temp != NULL) {
		front = temp->next;
		free(temp);
		temp = front;
	}
	*pHead = NULL;
}

int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile," %c", &c);
			insertChar(&head, c);
		}

		str = toCString(head);
		printf("String is : %s\n", str);

		free(str);
		deleteList(&head);

		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}

	fclose(inFile);
}