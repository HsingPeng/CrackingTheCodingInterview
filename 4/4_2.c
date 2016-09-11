#include <stdio.h>
#include <stdlib.h>

enum STAT { VISITED, VISITING, UNVISITED };

struct EdgeNode {
	struct Vertex *adjVex;
	struct EdgeNode *next;
};

struct Vertex {
	int index;
	enum STAT visited;
};

struct VertexNode {
	struct Vertex *vertex;
	struct EdgeNode *next;
};

struct GraphList {
	struct VertexNode *adjList;
	int numVertexes;
};

struct QueueNode {
	struct Vertex *data;
	struct QueueNode *next;
	struct QueueNode *prev;
};

struct Queue {
	struct QueueNode *first;
	struct QueueNode *last;
};

int enQueue(struct Queue *queue, struct Vertex *data)
{
	struct QueueNode *node= (struct QueueNode *)malloc(sizeof(struct QueueNode));
	if (node == NULL) {
		return -1;
	}

	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	if (queue->first == NULL) {
		queue->first = node;
		queue->last = node;
	} else {
		node->next = queue->first;
		queue->first->prev = node;
		queue->first = node;
	}

	return 0;
}

struct Vertex *deQueue(struct Queue *queue)
{
	if (queue->last == NULL) {
		return NULL;
	}

	struct QueueNode * node = queue->last;
	if (queue->last == queue->first) {
		queue->last = NULL;
		queue->first = NULL;
	} else {
		queue->last = queue->last->prev;
		queue->last->next = NULL;
	}
	struct Vertex *data = node->data;
	free(node);
	return data;
}

struct Queue *createQueue()
{
	struct Queue* queue = (struct Queue *)malloc(sizeof(struct Queue));
	if (queue == NULL) {
		return NULL;
	}
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

int search(struct GraphList *g, struct Vertex *start, struct Vertex *end)
{
	struct Queue *queue = createQueue();
	start->visited = VISITING;
	enQueue(queue, start);
	struct Vertex *vertex;
	while ((vertex = deQueue(queue)) != NULL) {
		
		struct EdgeNode *edgeNode = (g->adjList + vertex->index)->next;
		while (edgeNode != NULL) {
			if (edgeNode->adjVex->visited == UNVISITED) {
				if (edgeNode->adjVex == end) {
					return 1;
				}

				edgeNode->adjVex->visited = VISITING;
				enQueue(queue, edgeNode->adjVex);
			}

			edgeNode = edgeNode->next;
		}

		vertex->visited = VISITED;
	}

	return 0;
}

/**
 * 0 -> 2 -> 3
 * |    |
 * |    ---> 4
 * ---> 1
 *
 * Search 4 from 0 .
**/
int main()
{
	struct GraphList g;
	struct VertexNode nodes[5];
	g.adjList = nodes;
	g.numVertexes = 5;

	int i = -1;
	while (++i < 5) {
		struct Vertex *vertex = (struct Vertex *)malloc(sizeof(struct Vertex));
		vertex->index = i;
		vertex->visited = UNVISITED;
		nodes[i].vertex = vertex;
		nodes[i].next = NULL;
	}

	struct EdgeNode node1 = {nodes[2].vertex, NULL};
	struct EdgeNode node2 = {nodes[1].vertex, &node1};
	nodes[0].next = &node2;

	//struct EdgeNode node3 = {nodes[4].vertex, NULL};
	struct EdgeNode node4 = {nodes[3].vertex, /*&node3*/NULL};
	nodes[2].next = &node4;

	if (search(&g, nodes[0].vertex, nodes[4].vertex)) {
		printf("YES.\n");
	} else {
		printf("NO.\n");
	}

	return 0;
}
