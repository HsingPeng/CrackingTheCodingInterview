/**
  *假设共有256种不同数据，则需256位bitmap存储
  *使用位存储，int型占4字节，共32bit，所以需8个int大小
  *	(gdb) p/t *bitmap@8
  *	$1 = {0, 1110, 0, 1110, 0, 0, 0, 0}
  *此处一个 0, 为32bit，而1110则是靠右的4个bit
**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char data;
	struct Node * next;
};

int main()
{
	struct Node node8 = {'c', NULL};
	struct Node node7 = {'b', &node8};
	struct Node node6 = {'a', &node7};
	struct Node node5 = {'a', &node6};
	struct Node node4 = {'1', &node5};
	struct Node node3 = {'3', &node4};
	struct Node node2 = {'2', &node3};
	struct Node node1 = {'1', &node2};

	printNode(&node1);
	deleteDups(&node1);
	printNode(&node1);

	return 0;
}

int printNode(struct Node * head)
{

	while(head->next != NULL){
		printf("%c -> ", head->data);
		head = head->next;
	}

	printf("%d\n", head->data);

}

int bitFill(int * bitmap, int value)
{
	*(bitmap + value / (sizeof(int)*8) ) |= 1 << (value%sizeof(int));
	return 0;
}

int bitcompare(int * bitmap, int value)
{

	return *(bitmap + value / (sizeof(int)*8) ) & ( 1 << (value%sizeof(int)) );
}

int deleteDups(struct Node * head)
{
	int * bitmap = malloc(sizeof(int) * 8);
	memset(bitmap, '\0', sizeof(int) * 8);

	bitFill(bitmap, head->data);

	while(head->next != NULL){
		if( bitcompare( bitmap, head->next->data) ){
			head->next = head->next->next;
		}else{
			bitFill( bitmap, head->next->data);
			head = head->next;
		}
	}

	return 0;
}
