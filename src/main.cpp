#include "../include/admin.h"
#include "../include/companyList.h"
#include "../include/file.h"
#include "../include/menu.h"
#include "../include/orderList.h"

int main() {
    // 初始化订单链表和企业链表
    OrderList orderList;
    CompanyList companyList;
    File<OrderList, Order> orderFile("../data/order", ".txt");
    File<CompanyList, Company> companyFile("../data/company", ".txt");
    orderFile.initList(orderList);
    companyFile.initList(companyList);

    Menu::login();
    int userType;
    while (cin >> userType && userType) {
        int typeNum;

        switch (userType) {
        case 1: {
            // 管理员登录
            Admin admin("../data/admin", ".txt");
            if (!admin.login()) {
                Menu::login();
                break;
            }

            Menu::main();
            while (cin >> typeNum && typeNum) {
                switch (typeNum) {
                case 1: { // 添加
                    cout << "----------------------------------------------------------------" << endl;
                    ListNode<Order> *orderNode = orderList.addNode(cin);
                    orderFile.add(orderNode->getData());
                    cout << "----------------------------------------------------------------" << endl
                         << "添加成功" << endl
                         << "----------------------------------------------------------------" << endl
                         << orderNode->getData() << endl;
                    break;
                }
                case 2: { // 查询
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    Menu::adminQuery();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "请输入想查询订单的编号: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "orderID", orderID);
                            break;
                        }
                        case 2: {
                            cout << "请输入想查询订单的公司名称: ";
                            string company;
                            cin >> company;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "company", company);
                            break;
                        }
                        case 3: {
                            cout << "请输入想查询订单的客户名称: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "customer", customer);
                            break;
                        }
                        case 4: {
                            cout << "请输入想查询订单的产品名称：";
                            string product;
                            cin >> product;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "product", product);
                            break;
                        }
                        case 5: {
                            cout << "请输入想查询订单的产品定价的范围: " << endl
                                 << "最小值: ";
                            double priceMin;
                            cin >> priceMin;
                            cout << "最大值: ";
                            double priceMax;
                            cin >> priceMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "price", priceMin, priceMax);
                            break;
                        }
                        case 6: {
                            cout << "请输入想查询订单的订购数额的范围: " << endl
                                 << "最小值: ";
                            int numMin;
                            cin >> numMin;
                            cout << "最大值: ";
                            int numMax;
                            cin >> numMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "num", numMin, numMax);
                            break;
                        }
                        case 7: {
                            cout << "请输入想查询订单的订购金额的范围: " << endl
                                 << "最小值: ";
                            double amountMin;
                            cin >> amountMin;
                            cout << "最大值: ";
                            double amountMax;
                            cin >> amountMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "amount", amountMin, amountMax);
                            break;
                        }
                        case 8: {
                            cout << "请输入想查询订单的支付状态(0未支付 1已支付): ";
                            int payState;
                            while (cin >> payState) {
                                if (payState == 0 || payState == 1) {
                                    cout << "----------------------------------------------------------------" << endl;
                                    queryAndShowOrder(orderList, "payState", payState);
                                    break;
                                } else {
                                    cout << "输入有误，应该为'0(未支付)'或'1(已支付)'，请重新输入: ";
                                }
                            }
                            break;
                        }
                        case 9: {
                            cout << "请输入想查询订单的订单状态(0未处理 1处理中 2已完成): ";
                            int orderState;
                            while (cin >> orderState) {
                                if (orderState == 0 || orderState == 1 || orderState == 2) {
                                    cout << "----------------------------------------------------------------" << endl;
                                    queryAndShowOrder(orderList, "orderState", orderState);
                                    break;
                                } else {
                                    cout << "输入有误，应该为'0(未处理)'或'1(处理中)'或'2(已完成)'，请重新输入: ";
                                }
                            }
                            break;
                        }
                        default:
                            cout << "输入有误，请重新输入" << endl;
                            break;
                        }

                        Menu::adminQuery();
                    }
                    break;
                }
                case 3: { // 修改
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    Menu::adminChange();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "请输入想修改订单的订单编号: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            changeOrder(orderList, "orderID", orderID);
                            break;
                        }
                        case 2: {
                            cout << "请输入想修改订单的公司名称: ";
                            string company;
                            cin >> company;
                            cout << "----------------------------------------------------------------" << endl;
                            changeOrder(orderList, "company", company);
                            break;
                        }
                        case 3: {
                            cout << "请输入想修改订单的客户名称: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            changeOrder(orderList, "customer", customer);
                            break;
                        }
                        default:
                            cout << "输入有误，请重新输入" << endl;
                            break;
                        }

                        Menu::adminChange();
                    }
                    break;
                }
                case 4: { // 删除
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    Menu::adminDelete();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "请输入想删除订单的订单编号: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            delOrder(orderList, "orderID", orderID);
                            break;
                        }
                        case 2: {
                            cout << "请输入想删除订单的公司名称: ";
                            string company;
                            cin >> company;
                            cout << "----------------------------------------------------------------" << endl;
                            delOrder(orderList, "company", company);
                            break;
                        }
                        case 3: {
                            cout << "请输入想删除订单的客户名称: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            delOrder(orderList, "customer", customer);
                            break;
                        }
                        default:
                            cout << "输入有误，请重新输入" << endl;
                            break;
                        }

                        Menu::adminDelete();
                    }
                    break;
                }
                case 5: { // 排序
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    Menu::adminSort();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl
                             << "请输入排序方式(1升序 2降序): ";
                        int type;
                        cin >> type;
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getOrderID() < right.getData().getOrderID();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getOrderID() > right.getData().getOrderID();
                                });
                            }
                            break;
                        }
                        case 2: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCompany() < right.getData().getCompany();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCompany() > right.getData().getCompany();
                                });
                            }
                            break;
                        }
                        case 3: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCustomer() < right.getData().getCustomer();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCustomer() > right.getData().getCustomer();
                                });
                            }
                            break;
                        }
                        case 4: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getProduct() < right.getData().getProduct();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getProduct() > right.getData().getProduct();
                                });
                            }
                            break;
                        }
                        case 5: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getPrice() < right.getData().getPrice();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getPrice() > right.getData().getPrice();
                                });
                            }
                            break;
                        }
                        case 6: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getNum() < right.getData().getNum();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getNum() > right.getData().getNum();
                                });
                            }
                            break;
                        }
                        case 7: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getAmount() < right.getData().getAmount();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getAmount() > right.getData().getAmount();
                                });
                            }
                            break;
                        }
                        default:
                            cout << "输入有误，请重新输入" << endl;
                            break;
                        }

                        Menu::adminSort();
                    }
                    break;
                }
                case 6: { // 统计
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    Menu::adminStats();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            orderList.statsOrder();
                            break;
                        }
                        case 2: {
                            cout << "请输入想统计订单的公司名称: ";
                            string company;
                            cin >> company;
                            cout << "----------------------------------------------------------------" << endl;
                            orderList.statsOrder("company", company);
                            break;
                        }
                        case 3: {
                            cout << "请输入想统计订单的客户名称: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            orderList.statsOrder("customer", customer);
                            break;
                        }
                        case 4: {
                            cout << "请输入想统计订单的产品名称: ";
                            string product;
                            cin >> product;
                            cout << "----------------------------------------------------------------" << endl;
                            orderList.statsOrder("product", product);
                            break;
                        }
                        default:
                            cout << "输入有误，请重新输入" << endl;
                            break;
                        }

                        Menu::adminStats();
                    }
                    break;
                }
                case 7: { // 显示所有订单
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    cout << "----------------------------------------------------------------" << endl;
                    orderList.display();
                    break;
                }
                default:
                    cout << "输入有误，请重新输入" << endl;
                    break;
                }

                Menu::main();
            }

            Menu::login();
            break;
        }
        case 2: {
            // 公司登录
            string name;
            string password;
            cout << "请输入公司名\n> ";
            cin >> name;
            cout << "请输入密码\n> ";
            cin >> password;
            cout << "----------------------------------------------------------------" << endl;
            Company company(name, password);
            if (!companyList.logincheck(company)) {
                Menu::login();
                break;
            }

            OrderList companyOrderList;
            initSpecificOrderList(orderList, companyOrderList, "company", company.name);

            Menu::main();
            while (cin >> typeNum && typeNum) {
                switch (typeNum) {
                case 1: { // 添加
                    cout << "----------------------------------------------------------------" << endl;
                    ListNode<Order> *companyOrderNode = companyOrderList.addCompanyOrder(cin, company.name);
                    auto orderNode = new ListNode<Order>(*companyOrderNode);
                    orderList.addNode(orderNode);
                    orderFile.add(orderNode->getData());
                    cout << "----------------------------------------------------------------" << endl
                         << "添加成功" << endl
                         << "----------------------------------------------------------------" << endl
                         << orderNode->getData() << endl;
                    break;
                }
                case 2: { // 查询
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    Menu::companyQuery();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "请输入想查询订单的编号: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "orderID", orderID);
                            break;
                        }
                        case 2: {
                            cout << "请输入想查询订单的客户名称: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "customer", customer);
                            break;
                        }
                        case 3: {
                            cout << "请输入想查询订单的产品名称：";
                            string product;
                            cin >> product;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "product", product);
                            break;
                        }
                        case 4: {
                            cout << "请输入想查询订单的产品定价的范围: " << endl
                                 << "最小值: ";
                            double priceMin;
                            cin >> priceMin;
                            cout << "最大值: ";
                            double priceMax;
                            cin >> priceMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "price", priceMin, priceMax);
                            break;
                        }
                        case 5: {
                            cout << "请输入想查询订单的订购数额的范围: " << endl
                                 << "最小值: ";
                            int numMin;
                            cin >> numMin;
                            cout << "最大值: ";
                            int numMax;
                            cin >> numMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "num", numMin, numMax);
                            break;
                        }
                        case 6: {
                            cout << "请输入想查询订单的订购金额的范围: " << endl
                                 << "最小值: ";
                            double amountMin;
                            cin >> amountMin;
                            cout << "最大值: ";
                            double amountMax;
                            cin >> amountMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "amount", amountMin, amountMax);
                            break;
                        }
                        case 7: {
                            cout << "请输入想查询订单的支付状态(0未支付 1已支付): ";
                            int payState;
                            while (cin >> payState) {
                                if (payState == 0 || payState == 1) {
                                    cout << "----------------------------------------------------------------" << endl;
                                    queryAndShowOrder(companyOrderList, "payState", payState);
                                    break;
                                } else {
                                    cout << "输入有误，应该为'0(未支付)'或'1(已支付)'，请重新输入: ";
                                }
                            }
                            break;
                        }
                        case 8: {
                            cout << "请输入想查询订单的订单状态(0未处理 1处理中 2已完成): ";
                            int orderState;
                            while (cin >> orderState) {
                                if (orderState == 0 || orderState == 1 || orderState == 2) {
                                    cout << "----------------------------------------------------------------" << endl;
                                    queryAndShowOrder(companyOrderList, "orderState", orderState);
                                    break;
                                } else {
                                    cout << "输入有误，应该为'0(未处理)'或'1(处理中)'或'2(已完成)'，请重新输入: ";
                                }
                            }
                            break;
                        }
                        default:
                            cout << "输入有误，请重新输入" << endl;
                            break;
                        }

                        Menu::companyQuery();
                    }
                    break;
                }
                case 3: { // 修改
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    Menu::companyChange();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "请输入想修改订单的订单编号: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            ListNode<Order> *order = changeOrder(companyOrderList, "orderID", orderID);
                            if (order) {
                                orderList.changeOrder(order);
                                if (order->getData().getCompany() != company.name) {
                                    companyOrderList.delOrder(order->getData().getOrderID());
                                }
                            }

                            break;
                        }
                        case 2: {
                            cout << "请输入想修改订单的客户名称: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            ListNode<Order> *order = changeOrder(companyOrderList, "customer", customer);
                            if (order) {
                                orderList.changeOrder(order);
                                if (order->getData().getCompany() != company.name) {
                                    companyOrderList.delOrder(order->getData().getOrderID());
                                }
                            }
                            break;
                        }
                        default:
                            cout << "输入有误，请重新输入" << endl;
                            break;
                        }

                        Menu::companyChange();
                    }
                    break;
                }
                case 4: { // 删除
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    Menu::companyDelete();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "请输入想删除订单的订单编号: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            orderID = delOrder(companyOrderList, "orderID", orderID);
                            if (orderID) {
                                orderList.delOrder(orderID);
                            }
                            break;
                        }
                        case 2: {
                            cout << "请输入想删除订单的客户名称: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            long long orderID = delOrder(companyOrderList, "customer", customer);
                            if (orderID) {
                                orderList.delOrder(orderID);
                            }
                            break;
                        }
                        default:
                            cout << "输入有误，请重新输入" << endl;
                            break;
                        }

                        Menu::companyDelete();
                    }
                    break;
                }
                case 5: { // 排序
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    Menu::companySort();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl
                             << "请输入排序方式(1升序 2降序): ";
                        int type;
                        cin >> type;
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getOrderID() < right.getData().getOrderID();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getOrderID() > right.getData().getOrderID();
                                });
                            }
                            break;
                        }
                        case 2: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCustomer() < right.getData().getCustomer();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCustomer() > right.getData().getCustomer();
                                });
                            }
                            break;
                        }
                        case 3: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getProduct() < right.getData().getProduct();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getProduct() > right.getData().getProduct();
                                });
                            }
                            break;
                        }
                        case 4: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getPrice() < right.getData().getPrice();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getPrice() > right.getData().getPrice();
                                });
                            }
                            break;
                        }
                        case 5: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getNum() < right.getData().getNum();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getNum() > right.getData().getNum();
                                });
                            }
                            break;
                        }
                        case 6: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getAmount() < right.getData().getAmount();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getAmount() > right.getData().getAmount();
                                });
                            }
                            break;
                        }
                        default:
                            cout << "输入有误，请重新输入" << endl;
                            break;
                        }

                        Menu::companySort();
                    }
                    break;
                }
                case 6: { // 统计
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    Menu::companyStats();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            companyOrderList.statsOrder();
                            break;
                        }
                        case 2: {
                            cout << "请输入想统计订单的客户名称: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            companyOrderList.statsOrder("customer", customer);
                            break;
                        }
                        case 3: {
                            cout << "请输入想统计订单的产品名称: ";
                            string product;
                            cin >> product;
                            cout << "----------------------------------------------------------------" << endl;
                            companyOrderList.statsOrder("product", product);
                            break;
                        }
                        default:
                            cout << "输入有误，请重新输入" << endl;
                            break;
                        }

                        Menu::companyStats();
                    }
                    break;
                }
                case 7: {
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "当前没有订单数据" << endl;
                        break;
                    }

                    cout << "----------------------------------------------------------------" << endl;
                    companyOrderList.display();
                    break;
                }
                default:
                    cout << "输入有误，请重新输入" << endl;
                    break;
                }

                Menu::main();
            }

            Menu::login();
            break;
        }
        case 3: { // 注册
            cout << "----------------------------------------------------------------" << endl;
            Company newCompany;
            cin >> newCompany;
            if (!companyList.registerCheck(newCompany)) {
                Menu::login();
                break;
            }

            auto newCompanyNode = new ListNode<Company>;
            newCompanyNode->setData(newCompany);
            companyList.addNode(newCompanyNode);
            companyFile.add(newCompany);
            cout << "----------------------------------------------------------------" << endl
                 << "注册成功" << endl;

            Menu::login();
            break;
        }
        default:
            cout << "输入有误，请重新输入" << endl;
            break;
        }
    }

    orderFile.save(orderList);
    companyFile.save(companyList);
    cout << "欢迎下次使用" << endl;

    system("pause");
    return 0;
}