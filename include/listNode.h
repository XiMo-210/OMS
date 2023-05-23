//
// Created by XiMo on 2023/4/23.
//

#ifndef OMS_LISTNODE_H
#define OMS_LISTNODE_H
#include <iostream>
using namespace std;

// ����ڵ���
template <typename T>
class ListNode {
public:
    // ����
    ListNode();

    // �������ȡdata
    T getData() const;

    // ��ͨ�����ȡdata�����޸ģ�
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
    T data;            // Ԫ������
    ListNode<T> *next; // ��һ�ڵ�
    ListNode<T> *prev; // ǰһ�ڵ�
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
