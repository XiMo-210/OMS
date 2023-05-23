//
// Created by XiMo on 2023/4/27.
//

#include "../include/companyList.h"

// 登录
bool CompanyList::logincheck(const Company &company) {
    ListNode<Company> *ptr = head;
    while (ptr) {
        if (company.getName() == ptr->getData().getName()) {
            if (company.getPassword() == ptr->getData().getPassword()) {
                cout << "登陆成功" << endl;
                return true;
            } else {
                cout << "企业名或密码错误" << endl;
                return false;
            }
        }
        ptr = ptr->getNext();
    }
    cout << "企业名或密码错误" << endl;
    return false;
}

bool CompanyList::registerCheck(const Company &company) {
    ListNode<Company> *ptr = head;
    while (ptr) {
        if (company.getName() == ptr->getData().getName()) {
            cout << "----------------------------------------------------------------" << endl
                 << "该公司已经注册" << endl;
            return false;
        }
        ptr = ptr->getNext();
    }
    return true;
}
