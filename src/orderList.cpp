//
// Created by XiMo on 2023/4/25.
//

#include "../include/orderList.h"

ListNode<Order> *OrderList::addCompanyOrder(istream &in, const string &company) {
    auto newNode = new ListNode<Order>;
    Order newData;
    newData.setCompany(company);
    in >> newData;
    newNode->setData(newData);
    newNode->setNext(nullptr);
    newNode->setPrev(tail);

    // β�ڵ㲻Ϊ��ʱ�����½ڵ�
    if (tail != nullptr) {
        tail->setNext(newNode);
    }
    // ����β�ڵ�
    tail = newNode;

    // ͷ�ڵ�Ϊ��ʱ��ʼ��ͷ�ڵ�
    if (head == nullptr) {
        head = newNode;
        head->setPrev(nullptr);
    }

    ++size;
    return newNode;
}

// �޸Ķ���
void OrderList::changeOrder(ListNode<Order> *order) {
    ListNode<Order> *ptr = head;
    while (ptr) {
        if (ptr->getData().getOrderID() == order->getData().getOrderID()) {
            ptr->setData(order->getData());
            return;
        }
        ptr = ptr->getNext();
    }
}

// ɾ������
void OrderList::delOrder(const long long &orderId) {
    ListNode<Order> *ptr = head;

    while (ptr) {
        if (ptr->getData().getOrderID() == orderId) {
            ListNode<Order> *prevPtr = ptr->getPrev();
            ListNode<Order> *nextPtr = ptr->getNext();

            if (prevPtr && nextPtr) {
                // ɾ�м�ڵ�
                prevPtr->setNext(nextPtr);
                nextPtr->setPrev(prevPtr);
            } else if (prevPtr) {
                // ɾβ�ڵ�
                prevPtr->setNext(nullptr);
                setTail(prevPtr);
            } else if (nextPtr) {
                // ɾͷ�ڵ�
                nextPtr->setPrev(nullptr);
                setHead(nextPtr);
            } else {
                // ɾ����Ψһ�ڵ�
                setHead(nullptr);
                setTail(nullptr);
            }

            --size;
            delete ptr;
            return;
        }
        ptr = ptr->getNext();
    }
}

// ��������ѡ�ţ�
void OrderList::sort(bool (*cmp)(const ListNode<Order> &, const ListNode<Order> &)) {
    ListNode<Order> *ptr = head;
    ListNode<Order> *ptr_ = nullptr;
    ListNode<Order> *tempPtr = nullptr;

    for (int i = 0; i < getSize() - 1; ++i) {
        tempPtr = ptr;
        ptr_ = ptr->getNext();
        for (int j = i + 1; j < getSize(); ++j) {
            if (cmp(*ptr_, *tempPtr)) {
                tempPtr = ptr_;
            }
            ptr_ = ptr_->getNext();
        }
        if (ptr != tempPtr) {
            swap(ptr, tempPtr);
            ptr = tempPtr;
        }
        ptr = ptr->getNext();
    }

    cout << "����ɹ�" << endl
         << "----------------------------------------------------------------" << endl;
    display();
}

// ���������ڵ��ǰ�����
void OrderList::swap(ListNode<Order> *left, ListNode<Order> *right) {
    // �жϽ����ڵ��Ƿ���ͷβ�ڵ㣬�ı�ͷβָ��ָ��
    head = left == head ? right : head;
    tail = right == tail ? left : tail;

    if (left->getNext() == right) {
        // �������ڽڵ�
        ListNode<Order> *prev = left->getPrev();
        ListNode<Order> *next = right->getNext();

        left->setNext(next);
        if (next) {
            next->setPrev(left);
        }
        left->setPrev(right);

        right->setPrev(prev);
        if (prev) {
            prev->setNext(right);
        }
        right->setNext(left);
    } else {
        // ���������ڽڵ�
        if (left->getPrev()) {
            left->getPrev()->setNext(right);
        }
        ListNode<Order> *prev = right->getPrev();
        prev->setNext(left);
        right->setPrev(left->getPrev());
        left->setPrev(prev);
        prev = nullptr;

        left->getNext()->setPrev(right);
        ListNode<Order> *next = right->getNext();
        if (next) {
            next->setPrev(left);
        }
        right->setNext(left->getNext());
        left->setNext(next);
        next = nullptr;
    }
}

// ͳ�ƶ���
void OrderList::statsOrder(const string &type, const string &context) {
    ListNode<Order> *ptr = head;
    double amount = 0;

    if (!type.empty()) {
        int num = 0;
        while (ptr) {
            if (ptr->getData().compare(type, context)) {
                ++num;
                amount += ptr->getData().getAmount();
            }
            ptr = ptr->getNext();
        }
        if (num == 0) {
            cout << "ͳ�ƶ��󲻴���" << endl;
            return;
        }
        cout << "��������Ϊ: " << num << endl;
    } else {
        while (ptr) {
            amount += ptr->getData().getAmount();
            ptr = ptr->getNext();
        }
        cout << "��������Ϊ: " << getSize() << endl;
    }

    cout << "�����ܶ�Ϊ: " << amount << endl;
}
