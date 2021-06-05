#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//반복적인 중위 순회
//교수님은 수업 안하신듯? 그래서 나도 안봄ㅋ 하셨던가..?

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p)
{
    if (top < SIZE -1) //top이 최대 사이즈가 아니라면 
        stack[++top] = p; //다음 칸에 값을 넣는다.
}

TreeNode *pop()
{
    TreeNode *p = NULL;
    if(top >= 0)
        p = stack[top--]; //값을 넣고 top을 줄인다.
    return p;
}

void inorder_iter(TreeNode *root)
{
    while(1) {
        for(; root; root = root -> left) // 아 왼쪽으로 보내고 //null이 나올때까지 스택에 값을 넣고
            push(root); //왼쪽의 값을 넣는구나
        root = pop(); //아니지 하나를 꺼내서 그걸 넣은거자너?
        if(!root) break; //root가 비어있으면 -> null은 실행을 안하니까 !null을 해서 실행쓰!
        printf("[%d] ", root->data); //값은 출력해야징 음음
        root = root->right; //왼쪽 끝났으니 오른쪽인가?
    }
}

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode *root = &n6;

int main(void)
{
    printf("중위 순회=");
    inorder_iter(root);
    printf("\n");
    return 0;
}