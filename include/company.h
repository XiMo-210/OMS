//
// Created by XiMo on 2023/4/22.
//

#ifndef OMS_COMPANY_H
#define OMS_COMPANY_H
#include "user.h"

class Company : public User {
public:
    // 构造
    Company();

    // 构造
    Company(const string &name, const string &password);

    friend istream &operator>>(istream &in, Company &company);

    friend ostream &operator<<(ostream &out, const Company &company);
};

#endif // OMS_COMPANY_H
