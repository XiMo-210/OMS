//
// Created by XiMo on 2023/4/22.
//

#ifndef OMS_USER_H
#define OMS_USER_H
#include <iostream>
using namespace std;

class User {
public:
    User();

    User(const string& name ,const string& password);

    const string &getName() const;

    void setName(const string &name);

    const string &getPassword() const;

    void setPassword(const string &password);

    string name;     // �û�������˾���û�����Ϊ��˾���ƣ�
    string password; // ����
};

#endif // OMS_USER_H
