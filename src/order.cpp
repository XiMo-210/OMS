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
            cout << "请输入公司名称: ";
            in >> order.company;
        }
    } else {
        in >> order.company;
    }

    if (typeid(in) == typeid(cin)) {
        cout << "请输入客户名称: ";
    }
    in >> order.customer;

    if (typeid(in) == typeid(cin)) {
        cout << "请输入产品名称: ";
    }
    in >> order.product;

    if (typeid(in) == typeid(cin)) {
        cout << "请输入产品定价: ";
    }
    in >> order.price;

    if (typeid(in) == typeid(cin)) {
        cout << "请输入订购数额: ";
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
        cout << "请输入支付状态(0未支付 1已支付): ";
    }
    while (in >> payState) {
        if (payState == 0 || payState == 1) {
            order.setPayState(payState);
            break;
        } else {
            cout << "输入有误，应该为'0(未支付)'或'1(已支付)'，请重新输入: ";
        }
    }

    int orderState;
    if (typeid(in) == typeid(cin)) {
        cout << "请输入订单状态(0未处理 1处理中 2已完成): ";
    }
    while (in >> orderState) {
        if (orderState == 0 || orderState == 1 || orderState == 2) {
            order.setOrderState(orderState);
            break;
        } else {
            cout << "输入有误，应该为'0(未处理)'或'1(处理中)'或'2(已完成)'，请重新输入: ";
        }
    }

    return in;
}

ostream &operator<<(ostream &out, const Order &order) {
    if (typeid(out) == typeid(cout)) {
        tm *ltm = localtime(&order.time);

        out << "订单编号: " << order.orderID << endl
            << "公司: " << order.company << endl
            << "客户: " << order.customer << endl
            << "产品: " << order.product << endl
            << "定价: " << order.price << endl
            << "数额: " << order.num << endl
            << "金额: " << order.amount << endl
            << "下单时间: " << 1900 + ltm->tm_year << "/" << 1 + ltm->tm_mon << "/" << ltm->tm_mday << " " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl
            << "支付状态: " << (order.payState == 0 ? "未支付" : "已支付") << endl
            << "订单状态: " << (order.orderState == 0 ? "未处理" : (order.orderState == 1 ? "处理中" : "已完成")) << endl;
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
