#include "btree.cpp"
int getHeight(BTNode *bt)
{
    if (!bt)
        return 0;
    int lt = getHeight(bt->lchild);
    int rt = getHeight(bt->rchild);
    return lt > rt ? lt + 1 : rt + 1;
}
bool judgeBL(BTNode *bt)
{
    if (!bt)
        return true;
    if (getHeight(bt->rchild) - getHeight(bt->lchild) > 1 || getHeight(bt->lchild) - getHeight(bt->rchild) > 1)
        return false;
    else
        return judgeBL(bt->lchild) && judgeBL(bt->rchild);
}
int main()
{
    BTNode *b;
    // CreateBTree(b, "A(B(D(H,J),G),C(E,F))");
    CreateBTree(b, "A(E(D(,G)),B(,C))");
    DispBTree(b);
    printf("\n");
    if (judgeBL(b))
        printf("is a balanceTree.\n");
    else
        printf("is not a balanceTree.\n");
    return 0;
}