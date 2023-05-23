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

    // type���Ʋ�ѯ���ͣ�context��min��max���Ʋ�ѯ����
    // ����������ѯ������һ������
    template <typename T>
    friend ListNode<Order> *queryAndBackOrder(const OrderList &orderList, const string &type, const T &context);

    // ��������ģ����ѯ����ʾ���з��ϵĶ���
    template <typename T>
    friend void queryAndShowOrder(const OrderList &orderList, const string &type, const T &context);

    template <typename T>
    friend void queryAndShowOrder(const OrderList &orderList, const string &type, const T &min, const T &max);

    // �޸Ķ������˵�ʽ������
    template <typename T>
    friend ListNode<Order> *changeOrder(const OrderList &orderList, const string &type, const T &context);

    // �޸Ķ��������ݴ��붩���ҵ���ͬ������Ž����޸�ͬ����
    void changeOrder(ListNode<Order> *order);

    // ɾ���������˵�ʽ������
    template <typename T>
    friend long long delOrder(OrderList &orderList, const string &type, const T &context);

    // ɾ�����������ݶ�����ţ�
    void delOrder(const long long &orderId);

    // ͨ�����������ʼ��ָ�������Ķ�������
    template <typename T>
    friend void initSpecificOrderList(const OrderList &orderList, OrderList &specificOrderList, const string &type, const T &context);

    // ��������
    void sort(bool (*cmp)(const ListNode<Order> &, const ListNode<Order> &));

    // ͳ�ƶ���
    void statsOrder(const string &type = "", const string &context = "");

private:
    // ���������ڵ��ǰ�����
    void swap(ListNode<Order> *left, ListNode<Order> *right);
};

// ����������ѯ������һ������
template <typename T>
ListNode<Order> *queryAndBackOrder(const OrderList &orderList, const string &type, const T &context) {
    ListNode<Order> *ptr = orderList.getHead();

    // �������Ψһ�����账���������
    if (type == "orderID") {
        while (ptr) {
            if (ptr->getData().compare(type, context)) {
                return ptr;
            }
            ptr = ptr->getNext();
        }
    } else {
        // �����������
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
            cout << "��ѯ�������������������Ӧ����ǰ�ı�Ž���ѡ��: ";
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

// ��������ģ����ѯ����ʾ���з��ϵĶ���
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

        cout << "�ö���������" << endl;
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
            cout << "�����ڷ��������Ķ���" << endl;
        } else {
            cout << "����ѯ��" << num << "������" << endl;
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
        cout << "�����ڷ��������Ķ���" << endl;
    } else {
        cout << "����ѯ��" << num << "������" << endl;
    }
}

// �޸Ķ���
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
                cout << "�������µĹ�˾����: ";
                cin >> stringTemp;
                ptr->getData().setCompany(stringTemp);
                flag = true;
                break;
            }
            case 2: {
                cout << "�������µĿͻ�����: ";
                cin >> stringTemp;
                ptr->getData().setCustomer(stringTemp);
                flag = true;
                break;
            }
            case 3: {
                cout << "�������µĲ�Ʒ����: ";
                cin >> stringTemp;
                ptr->getData().setProduct(stringTemp);
                flag = true;
                break;
            }
            case 4: {
                cout << "�������µĲ�Ʒ����: ";
                cin >> doubleTemp;
                ptr->getData().setPrice(doubleTemp);
                flag = true;
                break;
            }
            case 5: {
                cout << "�������µĶ�������: ";
                cin >> intTemp;
                ptr->getData().setNum(intTemp);
                flag = true;
                break;
            }
            case 6: {
                cout << "�������µ�֧��״̬(0δ֧�� 1��֧��): ";
                while (cin >> intTemp) {
                    if (intTemp == 0 || intTemp == 1) {
                        ptr->getData().setPayState(intTemp);
                        flag = true;
                        break;
                    } else {
                        cout << "��������Ӧ��Ϊ'0(δ֧��)'��'1(��֧��)'������������: ";
                    }
                }
                break;
            }
            case 7: {
                cout << "�������µĶ���״̬(0δ���� 1������ 2�����): ";
                while (cin >> intTemp) {
                    if (intTemp == 0 || intTemp == 1 || intTemp == 2) {
                        ptr->getData().setOrderState(intTemp);
                        flag = true;
                        break;
                    } else {
                        cout << "��������Ӧ��Ϊ'0(δ����)'��'1(������)'��'2(�����)'������������: ";
                    }
                }
                break;
            }
            default:
                cout << "������������������\n> ";
                break;
            }

            Menu::changeChoice();
        }

        if (flag) {
            cout << "----------------------------------------------------------------" << endl
                 << "�޸ĺ󶩵���Ϣ����" << endl
                 << "----------------------------------------------------------------" << endl
                 << *ptr;
            return ptr;
        }
    } else {
        cout << "�ö���������" << endl;
    }

    return nullptr;
}

// ɾ������
template <typename T>
long long delOrder(OrderList &orderList, const string &type, const T &context) {
    ListNode<Order> *ptr = queryAndBackOrder(orderList, type, context);
    if (!ptr) {
        cout << "----------------------------------------------------------------" << endl
             << "�ö���������" << endl;
        return 0;
    }

    cout << *ptr
         << "�Ƿ�ȷ��ɾ���ö���(1�� 2��): ";
    int typeNum;
    cin >> typeNum;
    if (typeNum == 2) {
        cout << "----------------------------------------------------------------" << endl
             << "ȡ��ɾ��" << endl;
        return 0;
    }

    long long orderID = ptr->getData().getOrderID();
    ListNode<Order> *prevPtr = ptr->getPrev();
    ListNode<Order> *nextPtr = ptr->getNext();
    if (prevPtr && nextPtr) {
        // ɾ�м�ڵ�
        prevPtr->setNext(nextPtr);
        nextPtr->setPrev(prevPtr);
    } else if (prevPtr) {
        // ɾβ�ڵ�
        prevPtr->setNext(nullptr);
        orderList.setTail(prevPtr);
    } else if (nextPtr) {
        // ɾͷ�ڵ�
        nextPtr->setPrev(nullptr);
        orderList.setHead(nextPtr);
    } else {
        // ɾ����Ψһ�ڵ�
        orderList.setHead(nullptr);
        orderList.setTail(nullptr);
    }

    orderList.decSize();
    delete ptr;
    cout << "----------------------------------------------------------------" << endl
         << "ɾ���ɹ�" << endl;
    return orderID;
}

// ͨ�����������ʼ��ָ�������Ķ�������
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
