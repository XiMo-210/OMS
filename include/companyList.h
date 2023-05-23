//
// Created by XiMo on 2023/4/23.
//

#ifndef OMS_COMPANYLIST_H
#define OMS_COMPANYLIST_H
#include "company.h"
#include "list.h"

class CompanyList : public List<Company> {
public:
    // µÇÂ¼
    bool logincheck(const Company &company);

    // ×¢²á
    bool registerCheck(const Company &company);
};

#endif // OMS_COMPANYLIST_H
