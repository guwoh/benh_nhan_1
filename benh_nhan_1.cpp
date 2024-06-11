/**
 * @file benh_nhan_1.cpp
 * @author guwoh (hiep.vh234005@sis.hust.edu.vn)
 * @brief Hệ thống cho bệnh nhân
 * @version 0.1
 * @date 2024-06-10
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct // Hồ sơ cá nhân:
{
    int ID;
    char name[100]; // Họ và tên
    int day,month,year; // Ngày tháng năm sinh
    char sex[100]; // Giới tính
    char address[100]; // Địa chỉ
    char numPhone[100]; // Số điện thoại
}caNhan;

typedef struct  // Thông tin y tế:
{
    char tienBenhLy[100]; // Tiền sử bệnh lý
    char tienTiemChung[100]; // Tiền sử tiêm chủng (các loại vắc xin đã tiêm)
    int gan;
}yTe;

typedef struct   // Lịch sử tiêm chủng:
{
    char VXDT[100]; // Danh sách các loại vắc xin đã tiêm
    int dayT,monthT,yearT; // Ngày tiêm
    char DDT[100]; // Địa điểm tiêm
}lichSuTiemChung;

typedef struct   // Lịch tiêm chủng:
{
    char duKien[100]; // Lịch tiêm chủng dự kiến
    char nhacNho[100]; // Nhắc nhở về các mũi tiêm sắp đến hạn
}lichTiemChung;


int dem=0;
int tangDem()  // dem gan cho phan ID voi moi benh nhan duoc nhap, id duoc gan tang 1
{
    ++dem;
    return dem;
}
int reset()    // reset dem ve 0
{
    dem=0;
    return dem;
}
// Hàm để xóa bộ đệm đầu vào
void clear() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// dinh nghia cam ham su dung trong code
// entry funcions:
void dtCaNhan(caNhan* , int);  // khai báo hàm nhập data thông tin cá nhân
void dtYTe(yTe* , int);  // khai báo hàm nhập data thông tin y tế
void dtLichSuTiemChung(lichSuTiemChung* , int);  // khai báo hàm nhập data lịch sử tiêm chủng
void dtLichTiemChung(lichTiemChung* , int);  // khai báo hàm nhập data lịch tiêm chủng

// display funcions:
void displayCaNhan(caNhan*,int);
void displayYTe(yTe*,int);
void displayLinhSuTiemChung();
void displayLichTiemChung();

// if_patient funcion: this funcion use in main code (if_patient,if_staff)
void if_bn();

int main()
{
    int numOfBn;
    caNhan* infor_cn;
    yTe* infor_yt;
    lichSuTiemChung* infor_lstc;
    lichTiemChung* infor_ltc;
    printf("Nhap so luong benh nhan:");
    scanf("%d",&numOfBn);    

    infor_cn =(caNhan*)malloc(numOfBn*sizeof(caNhan)); // cấp phát động thông tin cá nhân
    infor_yt =(yTe*)malloc(numOfBn*sizeof(yTe)); // cấp phát động thông tin cá nhân
    infor_lstc =(lichSuTiemChung*)malloc(numOfBn*sizeof(lichSuTiemChung)); // cấp phát động thông tin cá nhân
    infor_ltc =(lichTiemChung*)malloc(numOfBn*sizeof(lichTiemChung)); // cấp phát động thông tin cá nhân
    
    dtCaNhan(infor_cn,numOfBn);  // entry data of patient
    displayCaNhan(infor_cn,numOfBn);  // dis play data of patent 
    dtYTe(infor_yt,numOfBn);
    displayYTe(infor_yt,numOfBn);


    free(infor_cn);
    free(infor_yt);
    free(infor_lstc);
    free(infor_ltc);
    return 0;
}

// entry and display data of struct caNhan
void dtCaNhan(caNhan* infor, int numOfBn)
{
    for(int i=0; i < numOfBn; i++)
    {
        printf("_____________________________________________\n_____________________________________________\n");
        printf("Nhap thong tin cho benh nhan thu %d \n",i+1);
        
        printf("ID ca nhan: ");
        scanf("%d", &infor[i].ID);
        clear(); // clear bo nho dem
        
        printf("Ten benh nhan: ");
        fgets(infor[i].name,99,stdin);
        
        printf("Ngay thang nam sinh (dd/mm/yyyy): ");
        scanf("%d/%d/%d",&infor[i].day,&infor[i].month,&infor[i].year);
        clear();
        
        printf("Gioi tinh: ");
        fgets(infor[i].sex,99,stdin);
        
        printf("Dia chi thuong chu: ");
        fgets(infor[i].address,99,stdin);
        
        printf("So dien thoai ca nhan: ");
        fgets(infor[i].numPhone,99,stdin);
    }
}
void displayCaNhan(caNhan*infor, int numOfBn)
{
    for(int i=0; i < numOfBn; i++)
    {
        printf("_____________________________________________\n_____________________________________________\n");
        printf(" Check thong tin benh nhan!\n");
        printf(" Thong tin cho benh nhan thu %d \n",i+1);
        printf(" ID ca nhan: %d\n",infor[i].ID);
        printf(" Ten benh nhan: %s",infor[i].name);
        printf(" Ngay thang nam sinh (dd/mm/yyyy): %d/%d/%d\n",infor[i].day,infor[i].month,infor[i].year);
        printf(" Gioi tinh: %s",infor[i].sex);
        printf(" Dia chi thuong chu: %s",infor[i].address);
        printf(" So dien thoai ca nhan: %s",infor[i].numPhone);
    }
}

// entry and display data of struct yTe
void dtYTe(yTe*infor, int numOfBn)
{
    for(int i=0; i<numOfBn; i++)
    {   
        printf("_____________________________________________\n");
        printf("Nhap thong tin lien quan de y te:\n");
        
        printf("Tien su benh ly:");
        fgets(infor[i].tienBenhLy,99,stdin);
        
        printf("Tien su tiem chung yes/no: ");
        fgets(infor[i].tienTiemChung,99,stdin);
        if(infor[i].tienTiemChung == "yes")
        {

        }
    }
}

void displayYTe(yTe* infor, int numOfBn)
{
    printf("\n_____________________________________________\n");
    printf("Check thong tin y te benh nhan!\n");
    for(int i=0; i<numOfBn; i++)
    {   
        printf("\n Thong tin lien quan den y te %d:\n",i+1);
        printf(" Tien su benh ly: %s",infor[i].tienBenhLy);
        printf(" Tien su tiem chung: %s",infor[i].tienTiemChung);
    }
}

// entry and display data of struct lichSuTiemChung

// entry and display data of struct lichTiemChugn






