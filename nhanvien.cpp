#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int i;
struct NhanVien{

    int maNv;
    char hoten[30];
    int namsinh;
    char quequan[20];
    NhanVien *next;
};
NhanVien *creat_Nhanvien()
{
    NhanVien *nv = (NhanVien*)malloc(sizeof(NhanVien));
    nv->next =NULL;
    return nv;
}
struct Danhsach_nhanvien{

    NhanVien *head;
    int count;
};

Danhsach_nhanvien *creat_danhsach_nhanvien()
{
    Danhsach_nhanvien *p = (Danhsach_nhanvien*) malloc(sizeof(Danhsach_nhanvien));
    p->count = 0;
    return p;
}
void delete_danhsach_nhanvien(Danhsach_nhanvien *plist)
{
    NhanVien *p = plist->head;
    while (plist->count--)
    {
        plist->head = p->next;
        free(p);
        p = plist->head;
    }
}

void Nhap_nhanvien(NhanVien *A)
{
    
        printf("-----------------Nhap nhan vien %d---------------\n",i+1);
        printf("nhap ma nhan vien:");
        scanf("%d",&(A->maNv));
        fflush(stdin);
        printf("Nhap ten:");
        fgets(A->hoten,sizeof(A->hoten),stdin);
        printf("Nhap nam sinh:");
        scanf("%d",&(A->namsinh));
        fflush(stdin);
        printf("Nhap que quan:");
        fgets(A->quequan,sizeof(A->quequan),stdin);
 }

void xuat_nhanvien(NhanVien *A)
{
    printf("\n\tMa:%d\n",A->maNv);
    printf("\tHoTen:%s\n",A->hoten);
    printf("\tNamsinh:%d\n",A->namsinh);
    printf("\tQuequan:%s\n",A->quequan);
}
void Nhap_danhsach_nhanvien(Danhsach_nhanvien *plist,int n)
{
    NhanVien *p = plist->head;
    for( i =0;i<n;i++)
    {
        Nhap_nhanvien(p);
        p = p->next;
    }
}
void Xuat_danhsach_nhanvien(Danhsach_nhanvien *plist)
{
    NhanVien *p = plist->head;
    int k=1;
    while (plist->count--)
    {
        /* code */
        printf("--------------Nhan vien %d------------",k);
        xuat_nhanvien(p);
        p = p->next;
        k++;
    }
}

// them nhan vien thi them o cuoi
void them_nhanvien_danhsach(Danhsach_nhanvien *plist)
{
    NhanVien *A = creat_Nhanvien();
    Nhap_nhanvien(A);
    if(plist->count == 0)
    {
        // nhan vien A se nam o dau cung nhu cuoi
     
        plist->head = A;
        plist->count++;
    }
    else
    {
        NhanVien *temp = plist->head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
            temp->next =A;
            A->next = NULL;
        }
        plist->count++;
    }
}
void them_nhanvien_danhsach(int ma,const char hoten[],int namsinh,const char quequan[],Danhsach_nhanvien *plist)
{
    NhanVien *A = creat_Nhanvien();
    A->maNv = ma;
    strcpy(A->hoten,hoten);
    A->namsinh = namsinh;
    strcpy(A->quequan,quequan);
    if(plist->count == 0)
    {
        // nhan vien A se nam o dau cung nhu cuoi
     
        plist->head = A;
        plist->count++;
    }
    else
    {
        NhanVien *temp = plist->head;
        //them cuoi danh sach
        while(temp->next!=NULL)
        {
           temp = temp->next;
        }
        temp->next =A;
        A->next = NULL;
        plist->count++;
    }
}




int main()
{
    Danhsach_nhanvien *Danhsach =creat_danhsach_nhanvien();
    printf("\t\tDANH SACH NHAN VIEN\n");

    them_nhanvien_danhsach(01,"HoangAnh",1998,"Ha Tinh",Danhsach);
    them_nhanvien_danhsach(02,"GiapBao",1997,"Ha Noi",Danhsach);
    Xuat_danhsach_nhanvien(Danhsach);

    return 0;
}
