//
// Created by XiMo on 2023/4/22.
//

#ifndef OMS_ADMIN_H
#define OMS_ADMIN_H
#include "user.h"

class Admin : public User {
public:
    // ¹¹Ôì
    Admin(const string &path, const string &fileType);

    // µÇÂ¼
    bool login();
};

#endif // OMS_ADMIN_H
