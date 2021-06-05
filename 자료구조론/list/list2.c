#include <stdio.h>
#include <stdlib.h>

//단순 연결 리스트

typedef int element;

typedef struct ListNode { //노드 타입
    element data;
    struct ListNode *link;
} ListNode;

//오류 처리 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
//삽입 연산
ListNode* insert_first(ListNode * head, int value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p ->data = value;
    p -> link = head; //헤드 포인터 값을 복사
    head = p; //헤드 포인터 변경
    return head; //변경된 헤드 포인터 반환
}

//노드 pre 뒤에 새로운 노드 삽입
ListNode* insert(ListNode *head, ListNode *pre, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p -> data = value;
    p -> link = pre -> link;
    pre -> link = p;
    return head;
}

ListNode* delete_first(ListNode *head)
{
    ListNode *removed;
    if(head == NULL) return NULL;
    removed = head;
    head = removed -> link;
    free(removed);
    return head;
} 

//pre가 가리키는 노드의 다음 노드를 삭제한다.
ListNode* delete(ListNode *head, ListNode *pre)
{
    ListNode *removed;
    removed = pre -> link; //지울 위치 입력
    pre -> link = removed -> link; //지울 노드 앞 노드의 link에 지울 위치 노드의 link입력
    free(removed);
    return head;
}

void print_list(ListNode *head)
{
    for(ListNode *p = head; p != NULL; p = p->link)
        printf("%d->", p -> data);
    printf("\n");
}

ListNode* alternate(ListNode *a, ListNode *b, ListNode *c) {
	for( ; (a -> link != NULL) && (b -> link != NULL); c = c -> link) {
		c -> data = a -> data;
		a = a -> link;
		c = c -> link;
		c -> data = b -> data;
		b = b -> link;
		c = c -> link;

	}
	return c;
}
ListNode *search(ListNode *L, element data) {
	int i = 0;
	for(ListNode *p = L; p -> link != NULL; p = p -> link){
		if(p -> data == data)
			return p;
	}
}

//테스트 프로그램
int main (void)
{
    ListNode *head = NULL;
    ListNode *b = NULL, *c = NULL;

    for(int i = 0; i < 5; i++) {
        head = insert_first(head, i);
        //print_list(head);
    }
    
   for(int i = 5; i < 10; i++) {
        b = insert_first(head, i);
        //print_list(head);    
   }

   alternate(head, b, c);
   printf("----------\n");
   for(int i = 0; i < 5; i++) {
        print_list(c);    
   }   
     /*
    for(int i = 0; i < 5; i++){
        head = delete_first(head);
        print_list(head); 
    } */


}