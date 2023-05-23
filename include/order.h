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

    // �Ƚ����ݳ�Ա������ֵ��Χ�Ƿ�ƥ��
    bool compare(const string &type, const long long &context) const;

    bool compare(const string &type, const string &context) const;

    bool compare(const string &type, const int &context) const;

    bool compare(const string &type, const int &min, const int &max) const;

    bool compare(const string &type, const double &min, const double &max) const;

    friend istream &operator>>(istream &in, Order &order);

    friend ostream &operator<<(ostream &out, const Order &order);

private:
    long long orderID; // ������� ���ʱ���
    string company;    // ��˾����
    string customer;   // �ͻ�����
    string product;    // ��Ʒ����
    double price;      // ��Ʒ����
    int num;           // ��������
    double amount;     // �������
    long long time;    // �µ�ʱ�� �뼶ʱ���
    int payState;      // ֧��״̬ 0δ֧�� 1��֧��
    int orderState;    // ����״̬ 0δ���� 1������ 2�����
};

#endif // OMS_ORDER_H
