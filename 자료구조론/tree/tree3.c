#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//�ݺ����� ���� ��ȸ
//�������� ���� ���Ͻŵ�? �׷��� ���� �Ⱥ��� �ϼ̴���..?

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

#define SIZE 100
int top = -1;
TreeNode *stack[SIZE];

void push(TreeNode *p)
{
    if (top < SIZE -1) //top�� �ִ� ����� �ƴ϶�� 
        stack[++top] = p; //���� ĭ�� ���� �ִ´�.
}

TreeNode *pop()
{
    TreeNode *p = NULL;
    if(top >= 0)
        p = stack[top--]; //���� �ְ� top�� ���δ�.
    return p;
}

void inorder_iter(TreeNode *root)
{
    while(1) {
        for(; root; root = root -> left) // �� �������� ������ //null�� ���ö����� ���ÿ� ���� �ְ�
            push(root); //������ ���� �ִ±���
        root = pop(); //�ƴ��� �ϳ��� ������ �װ� �������ڳ�?
        if(!root) break; //root�� ��������� -> null�� ������ ���ϴϱ� !null�� �ؼ� ���ྲ!
        printf("[%d] ", root->data); //���� ����ؾ�¡ ����
        root = root->right; //���� �������� �������ΰ�?
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
    printf("���� ��ȸ=");
    inorder_iter(root);
    printf("\n");
    return 0;
}