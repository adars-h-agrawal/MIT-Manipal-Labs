#include<stdio.h>
#define MAX 5

typedef struct{
    int front,rear,size;
    int array[MAX];
} CircularQueue;

void initQueue(CircularQueue *q){
    q->front = q->rear = -1;
    q->size=0;
}

int isEmpty(CircularQueue *q){
    return q->size == 0;
}

int isFull(CircularQueue *q){
    return q->size == MAX;
}

void enqueue(CircularQueue *q, int value){
    if(isFull(q)){
        printf("Queue is Full!\n");
        return;
    }
    if(isEmpty(q)){
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX;
    q->array[q->rear] = value;
    q->size++;
}

int dequeue(CircularQueue *q){
    if(isEmpty(q)){
        printf("Queue is Empty\n");
        return;
    }
    int value = q->array[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    return value;
}

void display(CircularQueue *q){
    if(isEmpty(q)){
        printf("Queue is Empty!\n");
        return;
    }
    printf("Queue elements are : ");
    for(int i = 0; i < q->size; i++){
        printf("%d ", q->array[(q->front + i) % MAX]);
    }
    printf("\n");
}

int main(){
    CircularQueue q;
    initQueue(&q);
    int ch, item;
    do{
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter your Choice : ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            printf("Enter item : ");
            scanf("%d", &item);
            enqueue(&q, item);
            break;
        case 2:
            item = dequeue(&q);
            if(item!=NULL)
                printf("Dequeued element : %d\n", item);
            break;
        case 3:
            display(&q);
            break;
        default:
            break;
        }
    }while(ch!=4);
    return 0;
}
