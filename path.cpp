#include "btree.cpp"
void Path(BTNode *T, char *path, int p)
{
    if (!T)
        return;
    if (!T->lchild && !T->rchild)
    {
        int i;
        for (i = 0; i < p; i++)
        {
            printf("%c ", path[i]);
        }
        printf("%c\n", T->data);
    }
    else
        path[p++] = T->data;
    Path(T->lchild, path, p);
    Path(T->rchild, path, p);
    p--;
}
int main()
{
    BTNode *b;
    CreateBTree(b, "A(B(D(,G)),C(E,F))");
    DispBTree(b);
    printf("\n");
    char path[100];
    Path(b, path, 0);
}