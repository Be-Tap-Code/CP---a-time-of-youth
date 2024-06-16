#include<bits/stdc++.h>

using namespace std;

//Định nghĩa một cấu trúc (struct) có tên node_array và tạo một định danh mới là node cho nó.
typedef struct node_array
{
    int a[3][3];
    int depth;
    int f;
    struct node_array *ch1;
    struct node_array *ch2;
    struct node_array *ch3;
    struct node_array *ch4;
    struct node_array *parent;
    struct node_array *next;
} node;

// Khai báo và khởi tạo các con trỏ liên quan đến hàng đợi và danh sách.
node *front=NULL,*rear=NULL,*x,*front_list=NULL,*rear_list=NULL;

// Khai báo các mảng và biến liên quan đến trạng thái của trò chơi.
int up[3][3],dn[3][3],rt[3][3],lt[3][3],goal[3][3],depth_flag=0,f_count=0;

// Hàm để thiết lập tất cả giá trị của một mảng 3x3 thành 0.
void set_zero(int a[3][3])
{
    int i,j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            a[i][j]=0;
}

// Hàm để sao chép nội dung từ một mảng 3x3 (b) sang một mảng khác (a).
void copy_array(int a[3][3],int b[3][3])//copy b to a
{
    int i,j;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            a[i][j]=b[i][j];
}

// Hàm kiểm tra xem hai mảng 3x3 có bằng nhau hay không.
int is_equal(int a[3][3],int b[3][3])
{
    int i,j,flag=1;
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            if(a[i][j]!=b[i][j])
                flag=0;
    return flag;
}

// Hàm đổi giá trị của hai con trỏ. (2 ma trận của puzzle)
void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


// Hàm in ra nội dung của một mảng 3x3.
void print_array(int a[3][3])
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

// Hàm kiểm tra xem một mảng 3x3 có chứa giá trị 0 hay không.
int check_zero(int a[3][3])//returns 1 if 0
{
    int i,j,flag=1;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            if(a[i][j]!=0)
                flag=0;
    }
    return flag;
}

// Hàm kiểm tra xem một nút đã tồn tại trong danh sách hay không.
int check_list(node *nd)//returns 0 if it doesnt match the list
{
    node *new_node=NULL;
    if(front_list==NULL)
        return 0;
    else
    {
        new_node=front_list;
        while(new_node!=NULL)
        {
            if(is_equal(new_node->a,nd->a)==1)
                return 1;
            new_node=new_node->next;
        }
        return 0;
    }
}

// Hàm chèn một nút vào hàng đợi.
void insert_queue(node *nd)
{
    nd->next=NULL;
    if(front==NULL)
    {
        front=nd;
        rear=nd;
    }
    else
    {
        rear->next=nd;
        rear=nd;
        rear->next=NULL;
    }
}

// Hàm chèn một nút vào danh sách.
void insert_list(node *nd)
{
    nd->next=NULL;
    if(front_list==NULL)
    {
        front_list=nd;
        rear_list=nd;
    }
    else
    {
        rear_list->next=nd;
        rear_list=nd;
        rear_list->next=NULL;
    }
}

// Hàm trả về giá trị tuyệt đối của một số.
int abs(int a)
{
    if(a>=0)
        return a;
    else
        return (-1*a);
}

// Hàm tính heuristics cho một nút trong thuật toán A*.
int calc_heuristic(node *nd)
{
    // Hàm này tính toán giá trị heuristic cho một nút trong thuật toán A*.
    // Trong trường hợp này, heuristic
    // được tính bằng cách đếm số bước cần để di chuyển từ vị trí hiện tại đến vị trí đích.
    int i,j,k,l,h=0;
    for(i=0; i<=2; i++)
    {
        for(j=0; j<=2; j++)
        {
            if(nd->a[i][j]!=0)
            {
                for(k=0; k<=2; k++)
                {
                    for(l=0; l<=2; l++)
                    {
                        if(nd->a[i][j]==goal[k][l])
                            goto buocnhay;
                    }
                }
buocnhay:
                h+=(abs(i-k)+abs(j-l));
            }
        }
    }
    return h;
}

// Hàm sinh ra các bước tiếp theo từ một trạng thái.
void next_move(node *nd)
{
    // Hàm này sinh ra các trạng thái kế tiếp từ trạng thái hiện tại nd.
    // Nó kiểm tra xem có thể thực hiện các bước lên, xuống, trái, phải không,
    // và nếu có, tạo ra các nút con và chèn chúng vào hàng đợi và danh sách.
    int i,j,x,y;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(nd->a[i][j]==0)
                goto label;
        }
    }
label:
    x=i;
    y=j;
    if(y+1 >2)
        nd->ch4=NULL;
    else
    {
        nd->ch4=(node*)malloc(sizeof(node));
        copy_array(nd->ch4->a,nd->a);
        swap(&nd->ch4->a[x][y],&nd->ch4->a[x][y+1]);
        if(check_list(nd->ch4)==1)
        {
            nd->ch4=NULL;
            free(nd->ch4);
        }
        else
        {
            nd->ch4->parent=nd;
            nd->ch4->depth=nd->depth+1;
            nd->ch4->f=nd->depth+calc_heuristic(nd->ch4)+1;
            insert_list(nd->ch4);
            insert_queue(nd->ch4);
        }
    }
    if(y-1 <0)
        nd->ch3=NULL;
    else
    {
        nd->ch3=(node*)malloc(sizeof(node));
        copy_array(nd->ch3->a,nd->a);
        swap(&nd->ch3->a[x][y],&nd->ch3->a[x][y-1]);
        if(check_list(nd->ch3)==1)
        {
            nd->ch3=NULL;
            free(nd->ch3);
        }
        else
        {
            nd->ch3->parent=nd;
            nd->ch3->depth=nd->depth+1;
            nd->ch3->f=nd->depth+calc_heuristic(nd->ch3)+1;
            insert_list(nd->ch3);
            insert_queue(nd->ch3);
        }
    }
    if(x+1 >2)
        nd->ch2=NULL;
    else
    {
        nd->ch2=(node*)malloc(sizeof(node));
        copy_array(nd->ch2->a,nd->a);
        swap(&nd->ch2->a[x][y],&nd->ch2->a[x+1][y]);
        if(check_list(nd->ch2)==1)
        {
            nd->ch2=NULL;
            free(nd->ch2);
        }
        else
        {
            nd->ch2->parent=nd;
            nd->ch2->depth=nd->depth+1;
            nd->ch2->f=nd->depth+calc_heuristic(nd->ch2)+1;
            insert_list(nd->ch2);
            insert_queue(nd->ch2);
        }
    }
    if(x-1 <0)
        nd->ch1=NULL;
    else
    {
        nd->ch1=(node*)malloc(sizeof(node));
        copy_array(nd->ch1->a,nd->a);
        swap(&nd->ch1->a[x][y],&nd->ch1->a[x-1][y]);

        if(check_list(nd->ch1)==1)
        {
            nd->ch1=NULL;
            free(nd->ch1);
        }
        else
        {
            nd->ch1->parent=nd;
            nd->ch1->depth=nd->depth+1;
            nd->ch1->f=nd->depth+calc_heuristic(nd->ch1)+1;
            insert_list(nd->ch1);
            insert_queue(nd->ch1);
        }
    }
}

// Hàm kiểm tra xem một trạng thái có phải là trạng thái đích hay không.
int is_goal(node *nd) //return 1 nếu là đích
{
    return is_equal(nd->a,goal);
}

// Hàm lấy ra nút đầu tiên từ hàng đợi
node *pop_queue()
{
    // Hàm này lấy ra nút đầu tiên từ hàng đợi
    // và di chuyển con trỏ hàng đợi đến nút tiếp theo.
    node *nd;
    nd=front;
    front=front->next;
    if(front==NULL)
        rear=NULL;
    return nd;
}

// Hàm in ra các bước để đạt được trạng thái đích.
void final_print(node *nd)
{
    //  Hàm này in ra đường đi từ trạng thái đích về trạng thái ban đầu,
    // sử dụng con trỏ parent của mỗi nút.
    while(nd!=NULL)
    {
        cout << endl;
        print_array(nd->a);
        nd=nd->parent;
        f_count++;
    }
    cout << "\nSo buoc thuc hien " << f_count-1;
    exit(0);
}

//  Hàm đếm số lượng nút trong hàng đợi.
int count_queue()
{
    int count=0;
    node *temp;
    temp=front;
    while(temp!=NULL)
    {
        temp=temp->next;
        count++;
    }
    return count;
}

// Hàm sắp xếp hàng đợi theo giá trị heuristics.
void arrange()
{
    // Hàm này sắp xếp hàng đợi theo giá trị heuristic của mỗi nút.
    // Điều này giúp thuật toán ưu tiên các nút có chi phí thấp hơn.
    node *t1,*t2,*t3;
    int i,j;
    i=count_queue();
    j=i;
    for(int k=0; k<i; k++)
    {
        t1=front;
        t2=front->next;

        for(int l=1; l<j; l++)
        {
            if(t1->next->f>t2->next->f)
            {
                t3=t2;
                t1->next=t2->next;
                t3->next=t3->next->next;
                t1->next->next=t2;
            }
            j--;
            t1=t1->next;
            t2=t2->next;
        }
    }
    t1=front;
    while(t1->next!=NULL)
        t1=t1->next;
    rear=t1;
    rear_list=t1;
}

// Thuật toán A* chính.
void A_star(node *root)
{
    {
        // Bắt đầu thuật toán,
        // chèn nút gốc vào hàng đợi và danh sách,
        // và thiết lập con trỏ nd trỏ đến nút gốc.
        node *nd;
        insert_queue(root);
        insert_list(root);
        nd=root;
        // Trong vòng lặp vô hạn, thuật toán kiểm tra xem trạng thái hiện tại (nd) có phải là trạng thái đích hay không.
        // Nếu đúng, thì gọi hàm final_print để in ra đường đi và kết thúc chương trình.
        // Nếu không, tiến hành sinh các bước tiếp theo (next_move), sắp xếp hàng đợi (arrange), và lấy ra nút đầu tiên từ hàng đợi (pop_queue).
        while(1)
        {
            nd=front;
            if(is_goal(nd)==1)
            {
                final_print(nd);
                break;
            }
            next_move(nd);
            arrange();
            nd=pop_queue();
        }
    }
}

// Hàm chính của chương trình, chạy các chương trình con
int main()
{
    node *n;
    int i,j;
    n=(node*)malloc(sizeof(node));
    x=(node*)malloc(sizeof(node));
    cout << "Nhap trang thai dich\n";
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            cin >> n->a[i][j];

    n->parent=NULL;
    n->next=NULL;
    n->ch1=NULL;
    n->ch2=NULL;
    n->ch3=NULL;
    n->ch4=NULL;
    n->depth=0;

    cout << "Nhap trang thai hien tai\n";
    for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            cin >> goal[i][j];

    n->f=calc_heuristic(n);
    cout << "\nCac buoc chay: \n";
    A_star(n);
    cin >> i;
    return 0;
}
// Code được tham khảo từ nguồn: https://github.com/technoapurva/8Puzzle
// Em đã tìm hiểu được code này trên github và code này sử dùng cấu trúc dữ liệu linked-list
// Dưới đây là phần trình bày code sau khi em tìm hiểu và thực hiện chạy tay nhiều lần
