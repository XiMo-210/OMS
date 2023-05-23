//
// Created by XiMo on 2023/5/18.
//

#include "../include/user.h"

User::User() = default;

User::User(const string &name, const string &password) {
    this->name = name;
    this->password = password;
}

const string &User::getName() const {
    return name;
}

void User::setName(const string &name) {
    this->name = name;
}

const string &User::getPassword() const {
    return password;
}

void User::setPassword(const string &password) {
    this->password = password;
}
