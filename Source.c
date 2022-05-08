#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* link;
}Node;

Node* createNode();
void insertNode(Node** phead, Node* newNode);
void printNode(Node* head);
void addData(Node* head);
void findMax(Node* head);

int main(void)
{
	Node* head = NULL; 

	int n = 0;
	printf("node 개수 : ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("%d번 node : ", i + 1);
		Node* newNode = createNode();  //노드 생성
		insertNode(&head, newNode); //노드 연결
		newNode = NULL; //
	}
	printNode(head); //리스트 출력
	addData(head); //리스트 덧셈
	findMax(head); //최댓값 찾기

	//모든 일을 마치고 메모리 반환
	Node* next;
	while (head != NULL) {
		next = head->link;
		free(head);
		head = next;
	}
	head = NULL;
	next = NULL;

	return 0;
}

Node* createNode() {
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL) return 0; //malloc 되지 않았을 경우에 대한 예외 코드

	scanf_s("%d", &(newNode->data));
	newNode->link = NULL;

	return newNode;
}

void insertNode(Node** phead, Node* newNode) {
	if (*phead == NULL) { //헤더가 가리키는 주소가 NULL이라면
		*phead = newNode; //헤더가 새로운 노드를 가리킴
		newNode = NULL;
	}
	else { //헤더가 노드를 가리키고 있다면
		Node* temp = *phead;
		while (temp->link != NULL) temp = temp->link; //링크의 가장 끝
		temp->link = newNode; //링크의 가장 끝에 새로운 노드 연결
		newNode = NULL;
		temp = NULL;
	}
}

void printNode(Node* head) {
	printf("1) linked list = ");
	Node* tmp = head;
	while (tmp != NULL) {
		printf("%d ", tmp->data);
		tmp = tmp->link;
		if (tmp != NULL) printf("-> ");
	}
	printf("\n");
}

void addData(Node* head) {
	int sum = 0;
	Node* tmp = head;
	while (tmp != NULL) {
		sum += tmp->data;
		tmp = tmp->link;
	}
	printf("2) sum of data = %d\n", sum);
}

void findMax(Node* head) {
	int max = head->data;
	Node* tmp = head;
	while (tmp != NULL) {
		if (max<tmp->data) max = tmp->data;
		tmp = tmp->link;
	}
	printf("3) max of data = %d\n", max);
}