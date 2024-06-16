#include<bits/stdc++.h>
using namespace std;

struct NhanVien
{
    int maNhanVien;
    string tenNhanVien;
    string namSinh;
    int LuongNhanVien;
    NhanVien* pleft;
    NhanVien* pright;
};

NhanVien* root = NULL;

NhanVien* newNhanVien(int maNhanVien, string tenNhanVien, string namSinh, int LuongNhanVien)
{
    NhanVien* node = new NhanVien;
    node->maNhanVien = maNhanVien;
    node->tenNhanVien = tenNhanVien;
    node->namSinh = namSinh;
    node->LuongNhanVien = LuongNhanVien;
    node->pleft = NULL;
    node->pright = NULL;
    return node;
}

void insert_NhanVien(NhanVien *&root, int maNhanVien, string tenNhanVien, string namSinh, int LuongNhanVien)
{
    if (!root)
    {
        root = newNhanVien(maNhanVien, tenNhanVien, namSinh, LuongNhanVien);
        return;
    }
    if (tenNhanVien < root->tenNhanVien)
        insert_NhanVien(root->pleft, maNhanVien, tenNhanVien, namSinh, LuongNhanVien);
    else insert_NhanVien(root->pright, maNhanVien, tenNhanVien, namSinh, LuongNhanVien);
}

void search_NhanVien(NhanVien* root, string tenNhanVien)
{
    while (root)
    {
        if (root->tenNhanVien < tenNhanVien) root = root->pright;
        else if (root->tenNhanVien > tenNhanVien) root = root->pleft;
        else if (root->tenNhanVien == tenNhanVien)
        {
            cout << "Ma nhan vien: " << root->maNhanVien << endl;
            cout << "Ten nhan vien: " << root->tenNhanVien << endl;
            cout << "Nam sinh nhan vien: " << root->namSinh << endl;
            cout << "Luong nhan vien: " << root->LuongNhanVien << endl;
            return;
        }
    }
    cout << "Khong tim thay nhan vien! " << endl;
}

void delete_NhanVien(NhanVien *&root, string tenNhanVien)
{
    if (!root) return;
    if (tenNhanVien < root->tenNhanVien) delete_NhanVien(root->pleft, tenNhanVien);
    else if (tenNhanVien > root->tenNhanVien) delete_NhanVien(root->pright, tenNhanVien);
    else
    {
        if (!root->pleft && !root->pright)
        {
            delete root;
            root = NULL;
        }
        else if (root->pleft && !root->pright)
        {
            NhanVien* temp = root;
            root = root->pleft;
            delete temp;
        }
        else if (!root->pleft && root->pright)
        {
            NhanVien* temp = root;
            root = root->pright;
            delete temp;
        }
        else
        {
            NhanVien* temp = root->pright;
            while (temp->pleft)
                temp = temp->pleft;
            root->tenNhanVien = temp->tenNhanVien;
            delete_NhanVien(root->pright,temp->tenNhanVien);
        }
    }
}

void NhanVien10trieu(vector<NhanVien*> NV, int n)
{
    int flag = 0;
    cout << "Nhung nhan vien co muc luong 10 trieu la: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (NV[i]->LuongNhanVien == 10000000)
        {
            cout << "Tim thay nhan vien: " << endl;
            cout << "Ma nhan vien: " << NV[i]->maNhanVien << endl;
            cout << "Ten nhan vien: " << NV[i]->tenNhanVien << endl;
            cout << "Nam sinh nhan vien: " << NV[i]->namSinh << endl;
            cout << "Luong nhan vien: " << NV[i]->LuongNhanVien << endl;
            flag = 1;
        }
    }
    if (flag == 0) cout << "Khong co nhan vien nao co muc luong 10 trieu !" << endl;
}

void print(NhanVien* root)
{
    if (root)
    {
        cout << "Ma nhan vien: " << root->maNhanVien << endl;
        cout << "Ten nhan vien: " << root->tenNhanVien << endl;
        cout << "Nam sinh nhan vien: " << root->namSinh << endl;
        cout << "Luong nhan vien: " << root->LuongNhanVien << endl;
        print(root->pleft);
        print(root->pright);
    }
}

int main()
{
    int n;
    vector<NhanVien*> NV(1000);
    cout << "Hay nhap 1 neu muon them mot so sinh vien vao cay nhi phan: " << endl;
    cout << "Hay nhap 2 neu muon tim nhan vien trong cay nhi phan: " << endl;
    cout << "Hay nhap 3 neu muon xoa nhan vien trong cay nhi phan: " << endl;
    cout << "Hay nhap 4 neu muon in ra nhan vien co muc luong 10 trieu: " << endl;
    cout << "Hay nhap 5 neu muon in ra toan bo nhan vien hien tai: " << endl;
    cout << "Hay nhap 6 de thoat: " << endl;
    while (true)
    {
        cout << "Nhap lua chon cua ban: ";
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            cout << "Nhap so nhan vien: ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                NV[i] = new NhanVien;
                cout << "Nhap ma nhan vien: ";
                cin >> NV[i]->maNhanVien;
                cout << "Nhap ten nhan vien: ";
                cin >> NV[i]->tenNhanVien;
                cout << "Nhap nam sinh nhan vien: ";
                cin >> NV[i]->namSinh;
                cout << "Nhap luong cua nhan vien: ";
                cin >> NV[i]->LuongNhanVien;
                insert_NhanVien(root, NV[i]->maNhanVien, NV[i]->tenNhanVien, NV[i]->namSinh, NV[i]->LuongNhanVien);
            }
        }
        if (choice == 2)
        {
            string ten;
            cout << "Nhap vao ten nhan vien can tim: ";
            cin >> ten;
            search_NhanVien(root,ten);
        }
        if (choice == 3)
        {
            int MSNV;
            int flag = 0;
            cout << "Nhap vao ma so nhan vien muon xoa: ";
            cin >> MSNV;
            for (int i = 0; i < n; i++)
            {
                if (NV[i]->maNhanVien == MSNV)
                {
                    delete_NhanVien(root, NV[i]->tenNhanVien);
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                cout << "Khong tim thay nhan vien can xoa !" << endl;
            else cout << "Da xoa nhan vien !" << endl;
        }
        if (choice == 4)
        {
            NhanVien10trieu(NV,n);
        }
        if (choice == 5)
        {
            print(root);
        }
        if (choice == 6) break;
    }
    return 0;
}
