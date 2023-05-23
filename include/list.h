//
// Created by XiMo on 2023/4/22.
//

#ifndef OMS_LIST_H
#define OMS_LIST_H
#include "listNode.h"

// ������
template <typename T>
class List {
public:
    // ����
    List();

    // ����
    ~List();

    // ��ȡ������
    const int &getSize() const;

    // ������+1
    void incSize();

    // ������-1
    void decSize();

    // ��ȡͷ�ڵ�
    ListNode<T> *getHead() const;

    // �޸�ͷ�ڵ�
    void setHead(ListNode<T> *head);

    // ��ȡβ�ڵ�
    ListNode<T> *getTail() const;

    // �޸�β�ڵ�
    void setTail(ListNode<T> *tail);

    // ��β�ڵ������½ڵ㣨ͨ���ļ���ȡ��������룩
    ListNode<T> *addNode(istream &in);

    // ��β�ڵ������½ڵ㣨ͨ���ڵ㣩
    void addNode(ListNode<T> *node);

    // �����������
    void display();

protected:
    int size;          // ������
    ListNode<T> *head; // ͷ�ڵ�
    ListNode<T> *tail; // β�ڵ�
};

// ����
template <typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

// ����
template <typename T>
List<T>::~List() {
    ListNode<T> *tailPtr = tail;
    // �ж��Ƿ�Ϊ������������Ҫ����
    if (tailPtr == nullptr) {
        return;
    }
    ListNode<T> *prevPtr = nullptr;
    while (tailPtr->getPrev() != nullptr) {
        // ��β�ڵ㿪ʼ���ͷſռ�
        prevPtr = tailPtr->getPrev();
        delete tailPtr;
        tailPtr = prevPtr;
    }
    delete tailPtr;

    size = 0;
    tailPtr = nullptr;
    prevPtr = nullptr;
}

// ��ȡ������
template <typename T>
const int &List<T>::getSize() const {
    return size;
}

// ������+1
template <typename T>
void List<T>::incSize() {
    ++size;
}

// ������-1
template <typename T>
void List<T>::decSize() {
    --size;
}

// ��ȡͷ�ڵ�
template <typename T>
ListNode<T> *List<T>::getHead() const {
    return head;
}

// �޸�ͷ�ڵ�
template <typename T>
void List<T>::setHead(ListNode<T> *head) {
    this->head = head;
}

// ��ȡβ�ڵ�
template <typename T>
ListNode<T> *List<T>::getTail() const {
    return tail;
}

// �޸�β�ڵ�
template <typename T>
void List<T>::setTail(ListNode<T> *tail) {
    this->tail = tail;
}

// ��β�ڵ������½ڵ㣨ͨ���ļ���ȡ��������룩
template <typename T>
ListNode<T> *List<T>::addNode(istream &in) {
    auto newNode = new ListNode<T>;
    T newData;
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

// ��β�ڵ������½ڵ㣨ͨ���ڵ㣩
template <typename T>
void List<T>::addNode(ListNode<T> *node) {
    node->setNext(nullptr);
    node->setPrev(tail);

    // β�ڵ㲻Ϊ��ʱ�����½ڵ�
    if (tail != nullptr) {
        tail->setNext(node);
    }
    // ����β�ڵ�
    tail = node;

    // ͷ�ڵ�Ϊ��ʱ��ʼ��ͷ�ڵ�
    if (head == nullptr) {
        head = node;
        head->setPrev(nullptr);
    }

    ++size;
}

// �����������
template <typename T>
void List<T>::display() {
    ListNode<T> *ptr = head;
    int num = 0;
    while (ptr) {
        cout << "NO." << ++num << endl
             << *ptr;
        ptr = ptr->getNext();
    }
    cout << "����" << size << "��" << endl;
}

#endif // OMS_LIST_H
