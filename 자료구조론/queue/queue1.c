//선형큐
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct{
    int front;
    int rear;
    element data[MAX_QUEUE_SIZE];
} QueueType;

//오류 함수
void error(char *message)
{
    fprintf(stderr, "%s \n", message);
    exit(1);
}

void init_queue(QueueType *q)
{
    q->rear = -1;
    q->front = -1;
} //초기화 함수?

void queue_print(QueueType *q) 
{
    for (int i = 0; i < MAX_QUEUE_SIZE; i++){
        if(i <= q->front || i > q->rear) //처음보다 작고 마지막보다 클 때! 가장 마지막에?
            printf("   |");
        else
            printf("%d | ", q->data[i]);
    }
    printf("\n");
}

int is_full(QueueType *q)
{
    if (q->rear == MAX_QUEUE_SIZE - 1)
        return 1;
    else
        return 0;
}

int is_empty(QueueType *q)
{
    if(q->front == q->rear)
        return 1;
    else
        return 0;
}

void enqueue(QueueType *q, int item) //삽입
{
    if(is_full(q)){
        error("큐가 포화상태입니다.");
        return;
    }
    q->data[++(q->rear)] = item; //rear의 다음 = 마지막의 다음칸에 넣기
}

int dequeue(QueueType *q) //삭제
{
    if(is_empty(q)){
        error("큐가 공백상태입니다.");
        return -1;
    }
    int item = q->data[++(q->front)]; //item에 front 다음 값을 넣기 (q->front)는 위치를 알려주는 정수니까!
    return item;
}


int main(void)
{
    int item = 0;
    QueueType q;

    init_queue(&q);

    enqueue(&q, 10); queue_print(&q);
    enqueue(&q, 20); queue_print(&q);
    enqueue(&q, 30); queue_print(&q);
    item = dequeue(&q); queue_print(&q);
    item = dequeue(&q); queue_print(&q); 
    item = dequeue(&q); queue_print(&q); 


}