#include <iostream>
#include <vector>
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

void print(Node *head, int level)
{
    vector<int> v;
    for(int i=0; i<level; i++)
    {
        v.push_back(head->key);
        head = head->parent;
    }
    while(!v.empty())
    {
        cout<<v.back()<<" ";
        v.pop_back();
    }
    cout<<endl;
}

void find_sum(Node *head, int sum)
{
    if(head == NULL) return ;
    Node *no = head;
    int tmp = 0;
    for(int i=1;no!=NULL;++i)
    {
        tmp += no->key;
        if(tmp == sum)
            print(head, i);
        no = no->parent;
    }
    find_sum(head->lchild, sum);
    find_sum(head->rchild, sum);
}

void print2(vector<int> v, int level)
{
    for(int i = level; i<v.size();i++)
    {
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}

void find_sum2(Node *head, int sum, vector<int> v, int level)
{
    if(head == NULL) return ;
    v.push_back(head->key);
    int tmp = 0;
    for(int i = level; i>=0; i--)
    {
        tmp += v.at(i);
        if(tmp == sum)
            print2(v, i);
    }
    vector<int> v1(v), v2(v);
    find_sum2(head->lchild, sum, v1, level+1);
    find_sum2(head->rchild, sum, v2, level+1);
}

int main()
{
    init();
}
