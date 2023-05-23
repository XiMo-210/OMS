//
// Created by XiMo on 2023/4/23.
//

#ifndef OMS_LISTNODE_H
#define OMS_LISTNODE_H
#include <iostream>
using namespace std;

// 链表节点类
template <typename T>
class ListNode {
public:
    // 构造
    ListNode();

    // 常对象获取data
    T getData() const;

    // 普通对象获取data（可修改）
    T &getData();

    void setData(T &data);

    ListNode<T> *getNext() const;

    void setNext(ListNode<T> *next);

    ListNode<T> *getPrev() const;

    void setPrev(ListNode<T> *prev);

    template <typename T_>
    friend istream &operator>>(istream &in, ListNode<T_> &node);

    template <typename T_>
    friend ostream &operator<<(ostream &out, const ListNode<T_> &node);

private:
    T data;            // 元素数据
    ListNode<T> *next; // 后一节点
    ListNode<T> *prev; // 前一节点
};

template <typename T>
ListNode<T>::ListNode() : next(nullptr), prev(nullptr) {}

template <typename T>
T ListNode<T>::getData() const {
    return data;
}

template <typename T>
T &ListNode<T>::getData() {
    return data;
}

template <typename T>
void ListNode<T>::setData(T &data) {
    this->data = data;
}

template <typename T>
ListNode<T> *ListNode<T>::getNext() const {
    return next;
}

template <typename T>
void ListNode<T>::setNext(ListNode<T> *next) {
    this->next = next;
}

template <typename T>
ListNode<T> *ListNode<T>::getPrev() const {
    return prev;
}

template <typename T>
void ListNode<T>::setPrev(ListNode<T> *prev) {
    this->prev = prev;
}

template <typename T>
istream &operator>>(istream &in, ListNode<T> &node) {
    T temp;
    in >> temp;
    node.setData(temp);
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, const ListNode<T> &node) {
    return out << node.getData() << endl;
}

#endif // OMS_LISTNODE_H
