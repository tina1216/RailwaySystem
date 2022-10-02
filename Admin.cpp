#include "Admin.h"

Admin* createAdmin(){
    Admin admin01, admin02, admin03;

    admin01.adminId = 01;
    admin01.psw = "111111";
    admin02.adminId = 02;
    admin02.psw = "222222";
    admin03.adminId = 03;
    admin03.psw = "A12345";

    Admin* adminArr = new Admin[3];
    adminArr[0] = admin01;
    adminArr[1] = admin02;
    adminArr[2] = admin03;

    return adminArr;
}