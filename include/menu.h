//
// Created by XiMo on 2023/4/23.
//

#ifndef OMS_MENU_H
#define OMS_MENU_H
#include <iostream>
using namespace std;

class Menu {
public:
    // ��¼�˵�
    static void login();

    // ���˵�
    static void main();

    // ����Ա��ѯ�˵�
    static void adminQuery();

    // ��ҵ��ѯ�˵�
    static void companyQuery();

    // ����Ա�޸Ĳ˵�
    static void adminChange();

    // ��ҵ�޸Ĳ˵�
    static void companyChange();

    // �޸�ѡ��
    static void changeChoice();

    // ����Աɾ���˵�
    static void adminDelete();

    // ��ҵɾ���˵�
    static void companyDelete();

    // ����Ա����˵�
    static void adminSort();

    // ��ҵ����˵�
    static void companySort();

    // ����Աͳ�Ʋ˵�
    static void adminStats();

    // ��ҵͳ�Ʋ˵�
    static void companyStats();
};
#endif // OMS_MENU_H
