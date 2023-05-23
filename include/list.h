//
// Created by XiMo on 2023/4/22.
//

#ifndef OMS_LIST_H
#define OMS_LIST_H
#include "listNode.h"

// 链表类
template <typename T>
class List {
public:
    // 构造
    List();

    // 析构
    ~List();

    // 获取链表长度
    const int &getSize() const;

    // 链表长度+1
    void incSize();

    // 链表长度-1
    void decSize();

    // 获取头节点
    ListNode<T> *getHead() const;

    // 修改头节点
    void setHead(ListNode<T> *head);

    // 获取尾节点
    ListNode<T> *getTail() const;

    // 修改尾节点
    void setTail(ListNode<T> *tail);

    // 往尾节点后添加新节点（通过文件读取或键盘输入）
    ListNode<T> *addNode(istream &in);

    // 往尾节点后添加新节点（通过节点）
    void addNode(ListNode<T> *node);

    // 输出所有数据
    void display();

protected:
    int size;          // 链表长度
    ListNode<T> *head; // 头节点
    ListNode<T> *tail; // 尾节点
};

// 构造
template <typename T>
List<T>::List() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

// 析构
template <typename T>
List<T>::~List() {
    ListNode<T> *tailPtr = tail;
    // 判断是否为空链表，是则不需要析构
    if (tailPtr == nullptr) {
        return;
    }
    ListNode<T> *prevPtr = nullptr;
    while (tailPtr->getPrev() != nullptr) {
        // 从尾节点开始逐步释放空间
        prevPtr = tailPtr->getPrev();
        delete tailPtr;
        tailPtr = prevPtr;
    }
    delete tailPtr;

    size = 0;
    tailPtr = nullptr;
    prevPtr = nullptr;
}

// 获取链表长度
template <typename T>
const int &List<T>::getSize() const {
    return size;
}

// 链表长度+1
template <typename T>
void List<T>::incSize() {
    ++size;
}

// 链表长度-1
template <typename T>
void List<T>::decSize() {
    --size;
}

// 获取头节点
template <typename T>
ListNode<T> *List<T>::getHead() const {
    return head;
}

// 修改头节点
template <typename T>
void List<T>::setHead(ListNode<T> *head) {
    this->head = head;
}

// 获取尾节点
template <typename T>
ListNode<T> *List<T>::getTail() const {
    return tail;
}

// 修改尾节点
template <typename T>
void List<T>::setTail(ListNode<T> *tail) {
    this->tail = tail;
}

// 往尾节点后添加新节点（通过文件读取或键盘输入）
template <typename T>
ListNode<T> *List<T>::addNode(istream &in) {
    auto newNode = new ListNode<T>;
    T newData;
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

// 往尾节点后添加新节点（通过节点）
template <typename T>
void List<T>::addNode(ListNode<T> *node) {
    node->setNext(nullptr);
    node->setPrev(tail);

    // 尾节点不为空时挂上新节点
    if (tail != nullptr) {
        tail->setNext(node);
    }
    // 更新尾节点
    tail = node;

    // 头节点为空时初始化头节点
    if (head == nullptr) {
        head = node;
        head->setPrev(nullptr);
    }

    ++size;
}

// 输出所有数据
template <typename T>
void List<T>::display() {
    ListNode<T> *ptr = head;
    int num = 0;
    while (ptr) {
        cout << "NO." << ++num << endl
             << *ptr;
        ptr = ptr->getNext();
    }
    cout << "共有" << size << "条" << endl;
}

#endif // OMS_LIST_H
