//
// Created by XiMo on 2023/4/27.
//

#include "../include/companyList.h"

// ��¼
bool CompanyList::logincheck(const Company &company) {
    ListNode<Company> *ptr = head;
    while (ptr) {
        if (company.getName() == ptr->getData().getName()) {
            if (company.getPassword() == ptr->getData().getPassword()) {
                cout << "��½�ɹ�" << endl;
                return true;
            } else {
                cout << "��ҵ�����������" << endl;
                return false;
            }
        }
        ptr = ptr->getNext();
    }
    cout << "��ҵ�����������" << endl;
    return false;
}

bool CompanyList::registerCheck(const Company &company) {
    ListNode<Company> *ptr = head;
    while (ptr) {
        if (company.getName() == ptr->getData().getName()) {
            cout << "----------------------------------------------------------------" << endl
                 << "�ù�˾�Ѿ�ע��" << endl;
            return false;
        }
        ptr = ptr->getNext();
    }
    return true;
}
