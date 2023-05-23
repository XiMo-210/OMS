//
// Created by XiMo on 2023/4/23.
//

#ifndef OMS_COMPANYLIST_H
#define OMS_COMPANYLIST_H
#include "company.h"
#include "list.h"

class CompanyList : public List<Company> {
public:
    // ��¼
    bool logincheck(const Company &company);

    // ע��
    bool registerCheck(const Company &company);
};

#endif // OMS_COMPANYLIST_H
