#include "btree.cpp"
//层次遍历算法
#define MaxSize 100
//--------------------------------------------------------
//--循环队列基本运算算法----------------------------------
//--------------------------------------------------------
typedef struct
{
    BTNode *data[MaxSize];  //存放队中元素
    int front, rear;        //队头和队尾指针
} SqQueue;                  //顺序队类型
void InitQueue(SqQueue *&q) //初始化队列
{
    q = (SqQueue *)malloc(sizeof(SqQueue));
    q->front = q->rear = 0;
}
void DestroyQueue(SqQueue *&q) //销毁队列
{
    free(q);
}
bool QueueEmpty(SqQueue *q) //判断队列是否为空
{
    return (q->front == q->rear);
}
bool enQueue(SqQueue *&q, BTNode *e) //进队列
{
    if ((q->rear + 1) % MaxSize == q->front) //队满上溢出
        return false;
    q->rear = (q->rear + 1) % MaxSize;
    q->data[q->rear] = e;
    return true;
}
bool deQueue(SqQueue *&q, BTNode *&e) //出队列
{
    if (q->front == q->rear) //队空下溢出
        return false;
    q->front = (q->front + 1) % MaxSize;
    e = q->data[q->front];
    return true;
}
//--------------------------------------------------------
//递归实现
void levelTravese(BTNode *T, SqQueue *Q)
{ //初始时根结点已入队
    if (T == NULL)
        return;
    BTNode *p;
    deQueue(Q, p);
    printf("%c ", p->data);
    if (p->lchild != NULL)
        enQueue(Q, p->lchild);
    if (p->rchild != NULL)
        enQueue(Q, p->rchild);
    levelTravese(T->lchild, Q);
    levelTravese(T->rchild, Q);
}
//非递归实现
void LevelOrder(BTNode *b)
{
    BTNode *p;
    SqQueue *qu;
    InitQueue(qu);          //初始化队列
    enQueue(qu, b);         //根结点指针进入队列
    while (!QueueEmpty(qu)) //队不为空循环
    {
        deQueue(qu, p);         //出队节点p
        printf("%c ", p->data); //访问节点p
        if (p->lchild != NULL)  //有左孩子时将其进队
            enQueue(qu, p->lchild);
        if (p->rchild != NULL) //有右孩子时将其进队
            enQueue(qu, p->rchild);
    }
}
int main()
{
    SqQueue *Q;
    InitQueue(Q);
    BTNode *b;
    CreateBTree(b, "A(B(D(,G),H),C(E,F))");
    printf("b:");
    DispBTree(b);
    printf("\n");
    enQueue(Q, b);
    printf("层次遍历序列:");
    levelTravese(b, Q);
    printf("\n");
    DestroyBTree(b);
    return 1;
}