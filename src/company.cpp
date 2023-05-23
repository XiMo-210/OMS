//
// Created by XiMo on 2023/4/24.
//

#include "../include/company.h"

// 构造
Company::Company() = default;

// 构造
Company::Company(const string &name, const string &password) : User(name, password) {}

istream &operator>>(istream &in, Company &company) {
    if (typeid(in) == typeid(cin)) {
        cout << "请输入公司名称: ";
    }
    in >> company.name;

    if (typeid(in) == typeid(cin)) {
        cout << "请设置密码: ";
    }
    in >> company.password;

    return in;
}

ostream &operator<<(ostream &out, const Company &company) {
    if (typeid(out) == typeid(cout)) {
        out << "公司名称为: " << company.name << endl;
    } else {
        out << company.getName() << " "
            << company.getPassword();
    }

    return out;
}
