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

    // 尾节点不为空时挂上新节点
    if (tail != nullptr) {
        tail->setNext(newNode);
    }
    // 更新尾节点
    tail = newNode;

    // 头节点为空时初始化头节点
    if (head == nullptr) {
        head = newNode;
        head->setPrev(nullptr);
    }

    ++size;
    return newNode;
}

// 修改订单
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

// 删除订单
void OrderList::delOrder(const long long &orderId) {
    ListNode<Order> *ptr = head;

    while (ptr) {
        if (ptr->getData().getOrderID() == orderId) {
            ListNode<Order> *prevPtr = ptr->getPrev();
            ListNode<Order> *nextPtr = ptr->getNext();

            if (prevPtr && nextPtr) {
                // 删中间节点
                prevPtr->setNext(nextPtr);
                nextPtr->setPrev(prevPtr);
            } else if (prevPtr) {
                // 删尾节点
                prevPtr->setNext(nullptr);
                setTail(prevPtr);
            } else if (nextPtr) {
                // 删头节点
                nextPtr->setPrev(nullptr);
                setHead(nextPtr);
            } else {
                // 删链表唯一节点
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

// 订单排序（选排）
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

    cout << "排序成功" << endl
         << "----------------------------------------------------------------" << endl;
    display();
}

// 交换两个节点的前后关联
void OrderList::swap(ListNode<Order> *left, ListNode<Order> *right) {
    // 判断交换节点是否是头尾节点，改变头尾指针指向
    head = left == head ? right : head;
    tail = right == tail ? left : tail;

    if (left->getNext() == right) {
        // 交换相邻节点
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
        // 交换不相邻节点
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

// 统计订单
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
            cout << "统计对象不存在" << endl;
            return;
        }
        cout << "订单总数为: " << num << endl;
    } else {
        while (ptr) {
            amount += ptr->getData().getAmount();
            ptr = ptr->getNext();
        }
        cout << "订单总数为: " << getSize() << endl;
    }

    cout << "订单总额为: " << amount << endl;
}
