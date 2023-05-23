//
// Created by XiMo on 2023/4/23.
//

#include "../include/admin.h"
#include <fstream>

// 构造
Admin::Admin(const string &path, const string &fileType) {
    ifstream ifs;

    ifs.open(path + fileType, ios::in);
    if (!ifs.is_open()) {
        cout << "文件打开失败" << endl;
    }
    ifs >> name >> password;
}

// 登录
bool Admin::login() {
    string inputName;
    string inputPassword;

    cout << "请输入管理员的用户名\n> ";
    cin >> inputName;
    cout << "请输入管理员的密码\n> ";
    cin >> inputPassword;

    cout << "----------------------------------------------------------------" << endl;
    if (name != inputName || password != inputPassword) {
        cout << "用户名或密码错误" << endl;
        return false;
    }
    cout << "登陆成功" << endl;
    return true;
}
