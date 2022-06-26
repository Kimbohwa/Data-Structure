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
	printf("node ���� : ");
	scanf_s("%d", &n);

	for (int i = 0; i < n; i++) {
		printf("%d�� node : ", i + 1);
		Node* newNode = createNode();  //��� ����
		insertNode(&head, newNode); //��� ����
		newNode = NULL; //
	}
	printNode(head); //����Ʈ ���
	addData(head); //����Ʈ ����
	findMax(head); //�ִ� ã��

	//��� ���� ��ġ�� �޸� ��ȯ
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

	if (newNode == NULL) return 0; //malloc ���� �ʾ��� ��쿡 ���� ���� �ڵ�

	scanf_s("%d", &(newNode->data));
	newNode->link = NULL;

	return newNode;
}

void insertNode(Node** phead, Node* newNode) {
	if (*phead == NULL) { //����� ����Ű�� �ּҰ� NULL�̶��
		*phead = newNode; //����� ���ο� ��带 ����Ŵ
		newNode = NULL;
	}
	else { //����� ��带 ����Ű�� �ִٸ�
		Node* temp = *phead;
		while (temp->link != NULL) temp = temp->link; //��ũ�� ���� ��
		temp->link = newNode; //��ũ�� ���� ���� ���ο� ��� ����
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