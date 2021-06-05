#include <Stdio.h>
#include <stdlib.h>


#define MAX_STACK_SIZE 100

typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

//스택 초기화 함수

void init_stack(StackType *s)
{
    s -> top = -1;
}

//공백 상태 검출 함수
int is_empty(StackType *s)
{
    return (s -> top == -1);
}

//포화 상태 검출 함수
int is_full (StackType *s)
{
    return (s -> top == (MAX_STACK_SIZE -1));
}

//삽입 함수
void push (StackType *s, element item)
{
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return; //해당 함수만 종료
    }
    else s -> data[++(s->top)] = item;
}

    //삭제 함수
    element pop(StackType *s)
    {
        if(is_empty(s)) {
            fprintf(stderr, "스택 공백 에러\n");
            exit(1); //에러메세지를 남기며 바로 프로세스 종료 - 0으로 종료하는건 에러메세지 없이 종료
        }
        else return s -> data[(s -> top)--];
    }

//피크 함수 - 보여주기만 하는거!
element peek(StackType *s)
{
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s -> data[s -> top]; // s -> top은 s에 있는 top이라는 정수! 그냥 위치 알려주는거!
}

/*
일반적인 배열 스택 프로그램

int main(void)
{
    StackType s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
}

*/

//동적 스택 프로그램
/*
int main (void)
{
    StackType *s;
    s = (StackType *)malloc(sizeof(StackType));
    init_stack(s);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    free(s);
} */

//배열을 2개 만들어보자~
int main (void)
{
    StackType a, b;
    init_stack(&a);
    init_stack(&b);

    push(&a, 1);
    push(&a, 2);
    push(&a, 3);
    push(&b, pop(&a));
    push(&b, pop(&a));
    push(&b, pop(&a));
    printf("%d ",pop(&b));
    printf("%d ",pop(&b));
    printf("%d ",pop(&b));
   
}