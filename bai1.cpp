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

void delete_TNode(TNode *&root, int x)
{
    if (!root) return;
    if (x < root->data) delete_TNode(root->pleft, x);
    else
    if (x > root->data) delete_TNode(root->pright, x);
    else
    {
        if (!root->pleft && !root->pright)
        {
            delete root;
            root = NULL;
        }
        else
        if (root->pleft && !root->pright)
        {
            TNode* temp = root;
            root = root->pleft;
            delete temp;
        }
        else
        if (!root->pleft && root->pright)
        {
            TNode* temp = root;
            root = root->pright;
            delete temp;
        }
        else
        {
            TNode* temp = root->pright;
            while (temp->pleft)
                temp = temp->pleft;
            root->data = temp->data;
            delete_TNode(root->pright,temp->data);
        }
    }
}

bool search_TNode(TNode* root, int x)
{
    while (root)
    {
        if (root->data < x) root = root->pright;
        else
        if (root->data > x) root = root->pleft;
        else
        return 1;
    }
    return 0;
}

void NLR(TNode* root)
{
    if (root)
    {
        cout << root->data << " ";
        NLR(root->pleft);
        NLR(root->pright);
    }
}

void LRN(TNode* root)
{
    if (root)
    {
        LRN(root->pleft);
        LRN(root->pright);
        cout << root->data << " ";
    }
}

void LNR(TNode* root)
{
    if (root)
    {
        LNR(root->pleft);
        cout << root->data << " ";
        LNR(root->pright);
    }
}

int main()
{
    cout << "nhap so phan tu can chen vao cay nhi phan tim kiem: ";
    int n;
    cin >> n;
    cout << "nhap " << n << " phan tu do: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert_TNode(root,x);
    }
    cout << "nhap 1 so tu 1-5" << endl;
    cout << "1: xoa mot phan tu tren cay nhi phan tim kiem" << endl;
    cout << "2: tim kiem mot phan tu tren cay nhi phan tim kiem" << endl;
    cout << "3: duyet cay nhi phan tim kiem NLR " << endl;
    cout << "4: duyet cay nhi phan tim kiem LRN" << endl;
    cout << "5: duyet cay nhi phan tim kiem LNR" << endl;
    int t;
    cin >> t;
    if (t == 1)
    {
        cout << "nhap phan tu can xoa: ";
        int x;
        cin >> x;
        delete_TNode(root,x);
        cout << "cay nhi phan sau khi xoa nut " << x << " la: (NLR)" << endl;
        NLR(root);
    }
    if (t == 2)
    {
        cout << "nhap phan tu can tim kiem ";
        int x;
        cin >> x;
        bool k = search_TNode(root,x);
        if (k == 1) cout << "tim thay " << x << endl;
        else cout << "khong tim thay " << x << endl;
    }
    if (t == 3)
    {
        cout << "duyet cay nhi phan tim kiem NLR: ";
        NLR(root);
    }
    if (t == 4)
    {
        cout << "duyet cay nhi phan tim kiem LRN: ";
        LRN(root);
    }
    if (t == 5)
    {
        cout << "duyet cay nhi phan tim kiem LNR: ";
        LNR(root);
    }
}
