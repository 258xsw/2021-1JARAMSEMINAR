#include <stdio.h>
#include <stdlib.h>

// 배열 리스트

#define MAX_LIST_SIZE 100

typedef int element;

typedef struct 
{
    element array[MAX_LIST_SIZE];
    int size;
}ArrayListType;


//오류 처리 함수
void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

//리스트 초기화 함수
void init(ArrayListType *L)
{
    L -> size = 0;
}

// 리스트가 비어 있으면 1을 반환
// 그렇지 않으면 0을 반환
int is_empty(ArrayListType *L)
{
    return L -> size == 0;
}

// 리스트가 가득 차 있으면 1을 반환
// 그렇지 않으면 1을 반환
int is_full(ArrayListType *L)
{
    return L -> size == MAX_LIST_SIZE;
}

element get_entry(ArrayListType *L, int pos)
{
    if(pos < 0 || pos >= L -> size)
        error("위치 오류");
    return L -> array[pos];
}

//리스트 출력
void print_list(ArrayListType *L)
{
    int i;
    for(i = 0; i < L -> size; i++)
        printf("%d->", L -> array[i]); 
    printf("\n");
}

//항목 추가
void insert_last(ArrayListType *L, element item)
{
    if(L -> size >= MAX_LIST_SIZE){ //size가 MAX보다 크면
        error("리스트 오버플로우");
    }
    L -> array[L -> size++] = item; //size값 다음 칸에 저장
}

//항목 중간 삽입
void insert(ArrayListType *L, int pos, element item)
{
    if(!is_full(L) && (pos >= 0) && (pos <= L -> size)) { //배열이 공백이 아니고 삽입하고 싶은 위치가 0보다 크고, 현재 사이즈보다 작은 위치라면
        for(int i = (L -> size - 1); i >= pos; i--) //최대값부터 원하는 곳 까지 하나씩 작아지면서 카운트
            L -> array[i + 1] = L -> array[i]; //다음칸으로 옮겨~~
        L -> array[pos] = item; //원하는 위치에 원하는 값을 넣고
        L -> size++; //전체 사이즈 키우기
    }
}

//항목 삭제
element delete(ArrayListType *L, int pos)
{
    element item;
    if(pos < 0 || pos >= L -> size) //원하는 위치가 0보다 작거나 전체 사이즈보다 크거나
        error("위치 오류");
    item = L -> array[pos]; //해당 위치의 값?
    for(int i = pos; i<(L -> size - 1); i++) //해당 위치부터 끝까지
        L -> array[i] = L -> array[i + 1]; //한칸씩 당겨오기
        L -> size--; //최종값 줄이고
        return item; //출력하기
}

int main(void)
{
    //ArrayListType를 정적으로 생성하고 ArrayListType를 가리키는 포인터를 함수의 매개 변수로 전달한다.
    ArrayListType list;

    init(&list);
    insert(&list, 0, 10);   print_list(&list);  //0번째 위치에 10 추가
    insert(&list, 0, 20);   print_list(&list);   //0번째 위치에 20 추가
    insert(&list, 0, 30);   print_list(&list);   //0번째 위치에 30 추가
    insert_last(&list, 40);   print_list(&list);    //맨 끝에 40 추가
    delete(&list, 0);          print_list(&list);    //0번째 항목 삭제
    return 0;

}