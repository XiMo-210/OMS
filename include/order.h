//
// Created by XiMo on 2023/4/22.
//

#ifndef OMS_ORDER_H
#define OMS_ORDER_H
#include <iostream>
using namespace std;

class Order {
public:
    const long long &getOrderID() const;

    void setOrderID(const long long &orderID);

    const string &getCompany() const;

    void setCompany(const string &company);

    const string &getCustomer() const;

    void setCustomer(const string &customer);

    const string &getProduct() const;

    void setProduct(const string &product);

    const double &getPrice() const;

    void setPrice(const double &price);

    const int &getNum() const;

    void setNum(const int &num);

    const double &getAmount() const;

    const long long &getTime() const;

    void setTime(const long long &time);

    const int &getPayState() const;

    void setPayState(const int &payState);

    const int &getOrderState() const;

    void setOrderState(const int &orderState);

    // 比较数据成员与所给值或范围是否匹配
    bool compare(const string &type, const long long &context) const;

    bool compare(const string &type, const string &context) const;

    bool compare(const string &type, const int &context) const;

    bool compare(const string &type, const int &min, const int &max) const;

    bool compare(const string &type, const double &min, const double &max) const;

    friend istream &operator>>(istream &in, Order &order);

    friend ostream &operator<<(ostream &out, const Order &order);

private:
    long long orderID; // 订单编号 秒计时间戳
    string company;    // 公司名称
    string customer;   // 客户名称
    string product;    // 产品名称
    double price;      // 产品定价
    int num;           // 订购数额
    double amount;     // 订单金额
    long long time;    // 下单时间 秒级时间戳
    int payState;      // 支付状态 0未支付 1已支付
    int orderState;    // 订单状态 0未处理 1处理中 2已完成
};

#endif // OMS_ORDER_H
