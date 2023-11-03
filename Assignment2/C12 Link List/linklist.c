#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int elem;
    struct node *next;
} Node;
typedef Node *Link;

// 根据人数创建循环链表
Link creatlink(int n)
{
    Link h = (Link)malloc(sizeof(Node));
    h->elem = n;
    Link p, q;
    p = h;
    for (int i = 1; i <= n; i++)
    {
        q = (Link)malloc(sizeof(Node));
        q->elem = i;
        p->next = q;
        p = q;
    }
    p->next = h->next;
    return h;
}

// 从节点 p 开始数到 m 并删除该节点，返回下一个节点
Link deletenode(Link h, Link p, int m, int *ptr)
{
    h->elem--;
    Link q = p->next;
    for (int i = 1; i < m - 1; i++)
    {
        p = q;
        q = q->next;
    }
    p->next = q->next;
    if (h->next == q)
        h->next = q->next;
    *ptr = q->elem; // *ptr 存储被删除节点的编号
    free(q);
    return p->next;
}

// 点名，当人数等于 m 或第 z 个节点被删除，结束点名
bool calltheroll(Link h, int m, int z)
{
    int id = 0;
    Link p = h->next;
    while (h->elem >= m)
    {
        p = deletenode(h, p, m, &id);
        if (id == z)
            return true;
    }
    return false;
}

int main()
{
    int n, m, z;
    scanf("%d %d %d", &n, &m, &z);
    Link h = creatlink(n);
    if (calltheroll(h, m, z))
        printf("YES\n");
    else
        printf("NO\n");
    return EXIT_SUCCESS;
}