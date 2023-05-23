//
// Created by XiMo on 2023/4/23.
//

#include "../include/order.h"
#include <ctime>

const long long &Order::getOrderID() const {
    return orderID;
}

void Order::setOrderID(const long long &orderID) {
    this->orderID = orderID;
}

const string &Order::getCompany() const {
    return company;
}

void Order::setCompany(const string &company) {
    this->company = company;
}

const string &Order::getCustomer() const {
    return customer;
}

void Order::setCustomer(const string &customer) {
    this->customer = customer;
}

const string &Order::getProduct() const {
    return product;
}

void Order::setProduct(const string &product) {
    this->product = product;
}

const double &Order::getPrice() const {
    return price;
}

void Order::setPrice(const double &price) {
    this->price = price;
    this->amount = price * num;
}

const int &Order::getNum() const {
    return num;
}

void Order::setNum(const int &num) {
    this->num = num;
    this->amount = price * num;
}

const double &Order::getAmount() const {
    return amount;
}

const long long &Order::getTime() const {
    return time;
}

void Order::setTime(const long long &time) {
    this->time = time;
}

const int &Order::getPayState() const {
    return payState;
}

void Order::setPayState(const int &payState) {
    this->payState = payState;
}

const int &Order::getOrderState() const {
    return orderState;
}

void Order::setOrderState(const int &orderState) {
    this->orderState = orderState;
}

bool Order::compare(const string &type, const long long &context) const {
    return orderID == context;
}

bool Order::compare(const string &type, const string &context) const {
    if (type == "company") {
        return company == context;
    } else if (type == "customer") {
        return customer == context;
    } else if (type == "product") {
        return product == context;
    }

    return false;
}

bool Order::compare(const string &type, const int &context) const {
    if (type == "payState") {
        return payState == context;
    } else if (type == "orderState") {
        return orderState == context;
    }

    return false;
}

bool Order::compare(const string &type, const int &min, const int &max) const {
    if (type == "num") {
        return num >= min && num <= max;
    }

    return false;
}

bool Order::compare(const string &type, const double &min, const double &max) const {
    if (type == "price") {
        return price >= min && price <= max;
    } else if (type == "amount") {
        return amount >= min && amount <= max;
    }

    return false;
}

istream &operator>>(istream &in, Order &order) {
    if (typeid(in) == typeid(cin)) {
        order.orderID = ::time(nullptr);
    } else {
        in >> order.orderID;
    }

    if (typeid(in) == typeid(cin)) {
        if (order.company.empty()) {
            cout << "�����빫˾����: ";
            in >> order.company;
        }
    } else {
        in >> order.company;
    }

    if (typeid(in) == typeid(cin)) {
        cout << "������ͻ�����: ";
    }
    in >> order.customer;

    if (typeid(in) == typeid(cin)) {
        cout << "�������Ʒ����: ";
    }
    in >> order.product;

    if (typeid(in) == typeid(cin)) {
        cout << "�������Ʒ����: ";
    }
    in >> order.price;

    if (typeid(in) == typeid(cin)) {
        cout << "�����붩������: ";
    }
    in >> order.num;

    if (typeid(in) == typeid(cin)) {
        order.amount = order.price * order.num;
    } else {
        in >> order.amount;
    }

    if (typeid(in) == typeid(cin)) {
        order.time = order.orderID;
    } else {
        in >> order.time;
    }

    int payState;
    if (typeid(in) == typeid(cin)) {
        cout << "������֧��״̬(0δ֧�� 1��֧��): ";
    }
    while (in >> payState) {
        if (payState == 0 || payState == 1) {
            order.setPayState(payState);
            break;
        } else {
            cout << "��������Ӧ��Ϊ'0(δ֧��)'��'1(��֧��)'������������: ";
        }
    }

    int orderState;
    if (typeid(in) == typeid(cin)) {
        cout << "�����붩��״̬(0δ���� 1������ 2�����): ";
    }
    while (in >> orderState) {
        if (orderState == 0 || orderState == 1 || orderState == 2) {
            order.setOrderState(orderState);
            break;
        } else {
            cout << "��������Ӧ��Ϊ'0(δ����)'��'1(������)'��'2(�����)'������������: ";
        }
    }

    return in;
}

ostream &operator<<(ostream &out, const Order &order) {
    if (typeid(out) == typeid(cout)) {
        tm *ltm = localtime(&order.time);

        out << "�������: " << order.orderID << endl
            << "��˾: " << order.company << endl
            << "�ͻ�: " << order.customer << endl
            << "��Ʒ: " << order.product << endl
            << "����: " << order.price << endl
            << "����: " << order.num << endl
            << "���: " << order.amount << endl
            << "�µ�ʱ��: " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl
            << "֧��״̬: " << (order.payState == 0 ? "δ֧��" : "��֧��") << endl
            << "����״̬: " << (order.orderState == 0 ? "δ����" : (order.orderState == 1 ? "������" : "�����")) << endl;
    } else {
        out << order.orderID << " "
            << order.company << " "
            << order.customer << " "
            << order.product << " "
            << order.price << " "
            << order.num << " "
            << order.amount << " "
            << order.time << " "
            << order.payState << " "
            << order.orderState;
    }

    return out;
}
