//判定给定的树是否是斜树
// 2021年12月9日22：39
#include <stdio.h>
#include "btree.cpp"
bool IsxieTree(BTNode *T)
{
    if (T == NULL)
        return true;
    bool is = false;
    if (T->lchild != NULL && T->rchild != NULL)
        return false;
    else
    {
        is = true;
        return is && IsxieTree(T->lchild) && IsxieTree(T->rchild);
    }
    return false;
}
//求结点数
int getNum(BTNode *T)
{
    if (T == NULL)
        return 0;
    return 1 + getNum(T->lchild) + getNum(T->rchild);
}
//交换左右子树
void reverseLR(BTNode *T)
{
    if (T == NULL)
        return;
    BTNode *p = T->lchild;
    T->lchild = T->rchild;
    T->rchild = p;
}
//使得二叉树的左子树结点数均大于等于右子树结点数
void Function(BTNode *T)
{
    if (T == nullptr)
        return;
    Function(T->lchild);
    if (getNum(T->lchild) < getNum(T->rchild))
        reverseLR(T);
    Function(T->rchild);
}
void getK_elem(BTNode *T, int *data, int *q, int k, int *k_elem)
{
    if (!T)
        return;
    getK_elem(T->lchild, data, q, k, k_elem);
    if (T->data != *data)
        *q++;
    if (*q == k)
        *k_elem = T->data;
    getK_elem(T->rchild, data, q, k, k_elem);
}
int main()
{
    BTNode *b;
    CreateBTree(b, "5(3(2,),6(7,9))");
    DispBTree(b);
    printf("\n");
    printf("k=%d", b->data);
    if (IsxieTree(b))
        printf("is xie TREE.");
    else
        printf("IS NOT XIE TREE.");
    // Function(b);
    int k_elem;
    int *data, *q;
    *data = -1;
    *q = -1;
    printf("k=%d", b->data);
    getK_elem(b, data, q, 3, &k_elem);
    DispBTree(b);
    printf("k=%d", k_elem);
    return 0;
}