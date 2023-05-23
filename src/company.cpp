//
// Created by XiMo on 2023/4/24.
//

#include "../include/company.h"

// ����
Company::Company() = default;

// ����
Company::Company(const string &name, const string &password) : User(name, password) {}

istream &operator>>(istream &in, Company &company) {
    if (typeid(in) == typeid(cin)) {
        cout << "�����빫˾����: ";
    }
    in >> company.name;

    if (typeid(in) == typeid(cin)) {
        cout << "����������: ";
    }
    in >> company.password;

    return in;
}

ostream &operator<<(ostream &out, const Company &company) {
    if (typeid(out) == typeid(cout)) {
        out << "��˾����Ϊ: " << company.name << endl;
    } else {
        out << company.getName() << " "
            << company.getPassword();
    }

    return out;
}
