//
// Created by XiMo on 2023/4/23.
//

#include "../include/admin.h"
#include <fstream>

// ����
Admin::Admin(const string &path, const string &fileType) {
    ifstream ifs;

    ifs.open(path + fileType, ios::in);
    if (!ifs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
    }
    ifs >> name >> password;
}

// ��¼
bool Admin::login() {
    string inputName;
    string inputPassword;

    cout << "���������Ա���û���\n> ";
    cin >> inputName;
    cout << "���������Ա������\n> ";
    cin >> inputPassword;

    cout << "----------------------------------------------------------------" << endl;
    if (name != inputName || password != inputPassword) {
        cout << "�û������������" << endl;
        return false;
    }
    cout << "��½�ɹ�" << endl;
    return true;
}
