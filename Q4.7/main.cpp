#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node node[maxn];
int cnt;

void init()
{
    memset(node, '\0', sizeof(node));
    cnt = 0;
}

void create_minimal_tree(Node* &head, Node *parent, int a[], int start, int end)
{
    if(start <= end)
    {
        int mid = (start + end)/2;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        create_minimal_tree(head->lchild, head, a, start, mid-1);
        create_minimal_tree(head->rchild, head, a, mid+1, end);
    }
}

bool match(Node* p, Node* q)
{
    if(p == NULL && q == NULL) return true;
    else if(p == NULL || q == NULL) return false;
    else if(p->key != q->key) return false;
    else return match(p->lchild, q->lchild) && match(p->rchild, q->rchild);
}

bool subtree(Node *p, Node *q)
{
    if(p == NULL) return false;
    else if(p->key == q->key)
    {
        if(match(p, q)) return true;
    }
    else return subtree(p->lchild, q) || subtree(p->rchild, q);
}

bool contain_subtree(Node *p, Node *q)
{
    if(q == NULL) return true;
    else return subtree(p, q);
}


int main()
{
    init();
    int a1[] = {0,1,2,3,4,5,6,7};
    int a2[] = {0,1,2};
    Node *p=NULL, *q = NULL;
    create_minimal_tree(p, NULL, a1, 0, 7);
    create_minimal_tree(q, NULL, a2, 0, 4);
    if(contain_subtree(p, q))
        cout<<"is subtree"<<endl;
    else
        cout<<"is not subtree"<<endl;
    return 0;
}
