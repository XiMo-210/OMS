//
// Created by XiMo on 2023/4/23.
//

#ifndef OMS_MENU_H
#define OMS_MENU_H
#include <iostream>
using namespace std;

class Menu {
public:
    // 登录菜单
    static void login();

    // 主菜单
    static void main();

    // 管理员查询菜单
    static void adminQuery();

    // 企业查询菜单
    static void companyQuery();

    // 管理员修改菜单
    static void adminChange();

    // 企业修改菜单
    static void companyChange();

    // 修改选项
    static void changeChoice();

    // 管理员删除菜单
    static void adminDelete();

    // 企业删除菜单
    static void companyDelete();

    // 管理员排序菜单
    static void adminSort();

    // 企业排序菜单
    static void companySort();

    // 管理员统计菜单
    static void adminStats();

    // 企业统计菜单
    static void companyStats();
};
#endif // OMS_MENU_H
