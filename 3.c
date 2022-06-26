#include <stdio.h>

typedef struct Heap {
	int key[12];
	int heap_size;
}Heap;

int input_data();
void insert_max_heap(Heap* A, int key);
int delete_max_heap(Heap* A);
void print_max_heap(Heap* A);

int main(void)
{
	Heap heap;
	heap.heap_size = 0; //포인터가 아니면 .으로밖에 못 씀, 초기화, 초기화하지 않으면 에러

	for (int i = 1; i <= 11; i++) {
		int key = input_data();
		insert_max_heap(&heap, key);
	}
	for (int i = 1; i <= 11; i++) {
		int key = delete_max_heap(&heap);
		printf("빠져나온 값 %d\n", key);
		print_max_heap(&heap);
	}

	return 0;
}

int input_data()
{
	int new_key;
	printf("정수 값을 입력하세요.\n");
	scanf_s("%d", &new_key);

	return new_key;
}

void insert_max_heap(Heap* A, int new_key)
{
	int i = 0;
	(A->heap_size)++;
	i = A->heap_size;
	A->key[i] = new_key;

	while ((i != 1) && (A->key[i] > A->key[i / 2])) {//루트 노드가 아니고 임의의 노드의 키값이 부모노드의 키 값보다 크면 부모 노드와 교환
		int tmp = A->key[i];
		A->key[i] = A->key[i / 2];
		A->key[i / 2] = tmp;
		i /= 2;
	}
	print_max_heap(A);
}

int delete_max_heap(Heap* A)
{
	int item = A->key[1]; //가장 큰 값을 item에 넣고 반환
	A->key[1] = A->key[A->heap_size]; //가장 마지막 노드의 키 값을 첫 번째 노드에 넣는다.
	(A->heap_size)--; //힙의 크기가 하나 줄어든다.

	int i = 2; 
	int largest = 0;
	while (i <= (A->heap_size)) {
		if ((i < A->heap_size) && (A->key[i + 1] > A->key[i]))
			largest = i + 1; //오른쪽 노드가 더 클 때
		else largest = i; //왼쪽 노드가 더 클 때

		if (A->key[largest / 2] > A->key[largest]) break;//부모노드가 더 크면 반복문 멈춤

		//부모노드와 자식노드 값 교환
		int tmp = A->key[largest / 2]; 
		A->key[largest / 2] = A->key[largest];
		A->key[largest] = tmp;

		i = largest * 2;
	}

	return item;
}

void print_max_heap(Heap* A) 
{
	for (int i = 1; i <= (A->heap_size); i++) {
		printf("%d ",A->key[i]);
	}
	printf("\n\n");
}