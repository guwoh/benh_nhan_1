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

// dinh nghia cam ham su dung trong code
// entry funcions:
void dtCaNhan(caNhan* , int);  // khai báo hàm nhập data thông tin cá nhân
void dtYTe(yTe* , int);  // khai báo hàm nhập data thông tin y tế
void dtLichSuTiemChung(lichSuTiemChung* , int);  // khai báo hàm nhập data lịch sử tiêm chủng
void dtLichTiemChung(lichTiemChung* , int);  // khai báo hàm nhập data lịch tiêm chủng
// display funcions:
void displayCaNhan();
void displayYTe();
void displayLinhSuTiemChung();
void displayLichTiemChung();
// if_patient funcion: this funcion use in main code (if_patient,if_staff)
void if_bn();

int main()
{
    int numOfPa;
    printf("Nhap so luong benh nhan:");
    scanf("%d",&numOfPa);

}

hihi
ihii
hjaha
test 4
