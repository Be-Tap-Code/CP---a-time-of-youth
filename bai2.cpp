#include<bits/stdc++.h>
using namespace std;

struct TNode
{
    int data;
    TNode* pleft;
    TNode* pright;
};

TNode *root = NULL;

TNode *newTNode(int data)
{
    TNode *node = new TNode;
    node->data = data;
    node->pleft = NULL;
    node->pright = NULL;
    return node;
}

void insert_TNode(TNode *&root, int x)
{
    if (!root)
    {
        root = newTNode(x);
        return;
    }
    if (x < root->data)
        insert_TNode(root->pleft, x);
    else insert_TNode(root->pright, x);
}

int chieucao(TNode *root)
{
    int hl, hr;
    if (root == NULL)
        return 0;
    hl = chieucao(root->pleft);
    hr = chieucao(root->pright);
    return max(hl,hr) + 1;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert_TNode(root,x);
    }
    int high = chieucao(root);
    cout << high - 1;
}
