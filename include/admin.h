//
// Created by XiMo on 2023/4/22.
//

#ifndef OMS_ADMIN_H
#define OMS_ADMIN_H
#include "user.h"

class Admin : public User {
public:
    // ����
    Admin(const string &path, const string &fileType);

    // ��¼
    bool login();
};

#endif // OMS_ADMIN_H
