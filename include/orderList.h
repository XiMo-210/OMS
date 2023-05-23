//
// Created by XiMo on 2023/4/23.
//

#ifndef OMS_ORDERLIST_H
#define OMS_ORDERLIST_H
#include "list.h"
#include "menu.h"
#include "order.h"

class OrderList : public List<Order> {
public:
    ListNode<Order> *addCompanyOrder(istream &in, const string &company);

    // type控制查询类型，context，min，max控制查询条件
    // 根据条件查询并返回一条订单
    template <typename T>
    friend ListNode<Order> *queryAndBackOrder(const OrderList &orderList, const string &type, const T &context);

    // 根据条件模糊查询并显示所有符合的订单
    template <typename T>
    friend void queryAndShowOrder(const OrderList &orderList, const string &type, const T &context);

    template <typename T>
    friend void queryAndShowOrder(const OrderList &orderList, const string &type, const T &min, const T &max);

    // 修改订单（菜单式操作）
    template <typename T>
    friend ListNode<Order> *changeOrder(const OrderList &orderList, const string &type, const T &context);

    // 修改订单（根据传入订单找到相同订单编号进行修改同步）
    void changeOrder(ListNode<Order> *order);

    // 删除订单（菜单式操作）
    template <typename T>
    friend long long delOrder(OrderList &orderList, const string &type, const T &context);

    // 删除订单（根据订单编号）
    void delOrder(const long long &orderId);

    // 通过订单链表初始化指定条件的订单链表
    template <typename T>
    friend void initSpecificOrderList(const OrderList &orderList, OrderList &specificOrderList, const string &type, const T &context);

    // 订单排序
    void sort(bool (*cmp)(const ListNode<Order> &, const ListNode<Order> &));

    // 统计订单
    void statsOrder(const string &type = "", const string &context = "");

private:
    // 交换两个节点的前后关联
    void swap(ListNode<Order> *left, ListNode<Order> *right);
};

// 根据条件查询并返回一条订单
template <typename T>
ListNode<Order> *queryAndBackOrder(const OrderList &orderList, const string &type, const T &context) {
    ListNode<Order> *ptr = orderList.getHead();

    // 订单编号唯一，无需处理多条数据
    if (type == "orderID") {
        while (ptr) {
            if (ptr->getData().compare(type, context)) {
                return ptr;
            }
            ptr = ptr->getNext();
        }
    } else {
        // 处理多条数据
        int num = 0;
        ListNode<Order> *ptr_[orderList.getSize()];

        while (ptr) {
            if (ptr->getData().compare(type, context)) {
                ptr_[num] = ptr;
                if (num == 1) {

                    cout << "NO.1" << endl
                         << *ptr_[0]
                         << "NO.2" << endl
                         << *ptr;
                } else if (num) {
                    cout << "NO." << (num + 1) << endl
                         << *ptr;
                }
                ++num;
            }
            ptr = ptr->getNext();
        }
        if (num > 1) {
            cout << "查询到多条订单，请输入对应订单前的编号进行选择: ";
            int id;
            cin >> id;
            cout << "----------------------------------------------------------------" << endl;
            if (id > num) {
                return ptr_[num - 1];
            } else if (id < 0) {
                return ptr_[0];
            } else {
                return ptr_[id - 1];
            }
        } else if (num == 1) {
            return ptr_[0];
        }
    }

    return nullptr;
}

// 根据条件模糊查询并显示所有符合的订单
template <typename T>
void queryAndShowOrder(const OrderList &orderList, const string &type, const T &context) {
    ListNode<Order> *ptr = orderList.getHead();

    if (type == "orderID") {
        while (ptr) {
            if (ptr->getData().compare(type, context)) {
                cout << *ptr;
                return;
            }
            ptr = ptr->getNext();
        }

        cout << "该订单不存在" << endl;
    } else {
        int num = 0;

        if (type == "company") {
            while (ptr) {
                if (ptr->getData().getCompany().find(context) != string::npos) {
                    cout << "NO." << ++num << endl
                         << *ptr;
                }
                ptr = ptr->getNext();
            }
        } else if (type == "customer") {
            while (ptr) {
                if (ptr->getData().getCustomer().find(context) != string::npos) {
                    cout << "NO." << ++num << endl
                         << *ptr;
                }
                ptr = ptr->getNext();
            }
        } else if (type == "product") {
            while (ptr) {
                if (ptr->getData().getProduct().find(context) != string::npos) {
                    cout << "NO." << ++num << endl
                         << *ptr;
                }
                ptr = ptr->getNext();
            }
        } else {
            while (ptr) {
                if (ptr->getData().compare(type, context)) {
                    cout << "NO." << ++num << endl
                         << *ptr;
                }
                ptr = ptr->getNext();
            }
        }

        if (num == 0) {
            cout << "不存在符合条件的订单" << endl;
        } else {
            cout << "共查询到" << num << "条订单" << endl;
        }
    }
}

template <typename T>
void queryAndShowOrder(const OrderList &orderList, const string &type, const T &min, const T &max) {
    ListNode<Order> *ptr = orderList.getHead();
    int num = 0;

    while (ptr) {
        if (ptr->getData().compare(type, min, max)) {
            cout << "NO." << ++num << endl
                 << *ptr;
        }
        ptr = ptr->getNext();
    }

    if (num == 0) {
        cout << "不存在符合条件的订单" << endl;
    } else {
        cout << "共查询到" << num << "条订单" << endl;
    }
}

// 修改订单
template <typename T>
ListNode<Order> *changeOrder(const OrderList &orderList, const string &type, const T &context) {
    ListNode<Order> *ptr = queryAndBackOrder(orderList, type, context);
    bool flag = false;
    if (ptr) {
        cout << *ptr;
        Menu::changeChoice();
        int typeNum;
        string stringTemp;
        int intTemp;
        double doubleTemp;
        while (cin >> typeNum && typeNum) {
            cout << "----------------------------------------------------------------" << endl;
            switch (typeNum) {
            case 1: {
                cout << "请输入新的公司名称: ";
                cin >> stringTemp;
                ptr->getData().setCompany(stringTemp);
                flag = true;
                break;
            }
            case 2: {
                cout << "请输入新的客户名称: ";
                cin >> stringTemp;
                ptr->getData().setCustomer(stringTemp);
                flag = true;
                break;
            }
            case 3: {
                cout << "请输入新的产品名称: ";
                cin >> stringTemp;
                ptr->getData().setProduct(stringTemp);
                flag = true;
                break;
            }
            case 4: {
                cout << "请输入新的产品定价: ";
                cin >> doubleTemp;
                ptr->getData().setPrice(doubleTemp);
                flag = true;
                break;
            }
            case 5: {
                cout << "请输入新的订购数额: ";
                cin >> intTemp;
                ptr->getData().setNum(intTemp);
                flag = true;
                break;
            }
            case 6: {
                cout << "请输入新的支付状态(0未支付 1已支付): ";
                while (cin >> intTemp) {
                    if (intTemp == 0 || intTemp == 1) {
                        ptr->getData().setPayState(intTemp);
                        flag = true;
                        break;
                    } else {
                        cout << "输入有误，应该为'0(未支付)'或'1(已支付)'，请重新输入: ";
                    }
                }
                break;
            }
            case 7: {
                cout << "请输入新的订单状态(0未处理 1处理中 2已完成): ";
                while (cin >> intTemp) {
                    if (intTemp == 0 || intTemp == 1 || intTemp == 2) {
                        ptr->getData().setOrderState(intTemp);
                        flag = true;
                        break;
                    } else {
                        cout << "输入有误，应该为'0(未处理)'或'1(处理中)'或'2(已完成)'，请重新输入: ";
                    }
                }
                break;
            }
            default:
                cout << "输入有误，请重新输入\n> ";
                break;
            }

            Menu::changeChoice();
        }

        if (flag) {
            cout << "----------------------------------------------------------------" << endl
                 << "修改后订单信息如下" << endl
                 << "----------------------------------------------------------------" << endl
                 << *ptr;
            return ptr;
        }
    } else {
        cout << "该订单不存在" << endl;
    }

    return nullptr;
}

// 删除订单
template <typename T>
long long delOrder(OrderList &orderList, const string &type, const T &context) {
    ListNode<Order> *ptr = queryAndBackOrder(orderList, type, context);
    if (!ptr) {
        cout << "----------------------------------------------------------------" << endl
             << "该订单不存在" << endl;
        return 0;
    }

    cout << *ptr
         << "是否确定删除该订单(1是 2否): ";
    int typeNum;
    cin >> typeNum;
    if (typeNum == 2) {
        cout << "----------------------------------------------------------------" << endl
             << "取消删除" << endl;
        return 0;
    }

    long long orderID = ptr->getData().getOrderID();
    ListNode<Order> *prevPtr = ptr->getPrev();
    ListNode<Order> *nextPtr = ptr->getNext();
    if (prevPtr && nextPtr) {
        // 删中间节点
        prevPtr->setNext(nextPtr);
        nextPtr->setPrev(prevPtr);
    } else if (prevPtr) {
        // 删尾节点
        prevPtr->setNext(nullptr);
        orderList.setTail(prevPtr);
    } else if (nextPtr) {
        // 删头节点
        nextPtr->setPrev(nullptr);
        orderList.setHead(nextPtr);
    } else {
        // 删链表唯一节点
        orderList.setHead(nullptr);
        orderList.setTail(nullptr);
    }

    orderList.decSize();
    delete ptr;
    cout << "----------------------------------------------------------------" << endl
         << "删除成功" << endl;
    return orderID;
}

// 通过订单链表初始化指定条件的订单链表
template <typename T>
void initSpecificOrderList(const OrderList &orderList, OrderList &specificOrderList, const string &type, const T &context) {
    auto ptr = orderList.getHead();

    while (ptr) {
        if (ptr->getData().compare(type, context)) {
            auto ptr_ = new ListNode<Order>(*ptr);
            specificOrderList.addNode(ptr_);
        }
        ptr = ptr->getNext();
    }
}

#endif // OMS_ORDERLIST_H
