#include <stdio.h>
#define MAX 100
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
	
} node;
typedef struct queue{
	node *front;
	node *rear;
}queue;
node *make(int x){
	node *p = (node*)malloc(sizeof(node));
	p->data = x;
	p->next=NULL;
	return p;
}
void ktao(queue *q){
	q->front = q->rear = NULL;
}
int isEmpty(queue *q){
	return q->front == NULL;
}
void enqueue(queue *q,int x){
	node *p=make(x);
	if (isEmpty(q)) {
        q->front = q->rear = p;
        return;
    }
	q->rear->next = p;
	q->rear = p;
}
int dequeue(queue *q){
	if (isEmpty(q)) {
        return 0;
    }
    node *tmp = q->front;
    int k = tmp->data;
    q->front = tmp->next;
    free(tmp);
    return k;
}
int main(){
	int n;
	queue s;
	ktao(&s);
	scanf("%d",&n);
	while(n--){
		int i;
		scanf("%d",&i);
		enqueue(&s,i);
	}
	while(!isEmpty(&s)){
		printf("%d ",dequeue(&s));
	}
}
