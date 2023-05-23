#include "../include/admin.h"
#include "../include/companyList.h"
#include "../include/file.h"
#include "../include/menu.h"
#include "../include/orderList.h"

int main() {
    // ��ʼ�������������ҵ����
    OrderList orderList;
    CompanyList companyList;
    File<OrderList, Order> orderFile("../data/order", ".txt");
    File<CompanyList, Company> companyFile("../data/company", ".txt");
    orderFile.initList(orderList);
    companyFile.initList(companyList);

    Menu::login();
    int userType;
    while (cin >> userType && userType) {
        int typeNum;

        switch (userType) {
        case 1: {
            // ����Ա��¼
            Admin admin("../data/admin", ".txt");
            if (!admin.login()) {
                Menu::login();
                break;
            }

            Menu::main();
            while (cin >> typeNum && typeNum) {
                switch (typeNum) {
                case 1: { // ���
                    cout << "----------------------------------------------------------------" << endl;
                    ListNode<Order> *orderNode = orderList.addNode(cin);
                    orderFile.add(orderNode->getData());
                    cout << "----------------------------------------------------------------" << endl
                         << "��ӳɹ�" << endl
                         << "----------------------------------------------------------------" << endl
                         << orderNode->getData() << endl;
                    break;
                }
                case 2: { // ��ѯ
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    Menu::adminQuery();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "���������ѯ�����ı��: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "orderID", orderID);
                            break;
                        }
                        case 2: {
                            cout << "���������ѯ�����Ĺ�˾����: ";
                            string company;
                            cin >> company;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "company", company);
                            break;
                        }
                        case 3: {
                            cout << "���������ѯ�����Ŀͻ�����: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "customer", customer);
                            break;
                        }
                        case 4: {
                            cout << "���������ѯ�����Ĳ�Ʒ���ƣ�";
                            string product;
                            cin >> product;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "product", product);
                            break;
                        }
                        case 5: {
                            cout << "���������ѯ�����Ĳ�Ʒ���۵ķ�Χ: " << endl
                                 << "��Сֵ: ";
                            double priceMin;
                            cin >> priceMin;
                            cout << "���ֵ: ";
                            double priceMax;
                            cin >> priceMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "price", priceMin, priceMax);
                            break;
                        }
                        case 6: {
                            cout << "���������ѯ�����Ķ�������ķ�Χ: " << endl
                                 << "��Сֵ: ";
                            int numMin;
                            cin >> numMin;
                            cout << "���ֵ: ";
                            int numMax;
                            cin >> numMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "num", numMin, numMax);
                            break;
                        }
                        case 7: {
                            cout << "���������ѯ�����Ķ������ķ�Χ: " << endl
                                 << "��Сֵ: ";
                            double amountMin;
                            cin >> amountMin;
                            cout << "���ֵ: ";
                            double amountMax;
                            cin >> amountMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(orderList, "amount", amountMin, amountMax);
                            break;
                        }
                        case 8: {
                            cout << "���������ѯ������֧��״̬(0δ֧�� 1��֧��): ";
                            int payState;
                            while (cin >> payState) {
                                if (payState == 0 || payState == 1) {
                                    cout << "----------------------------------------------------------------" << endl;
                                    queryAndShowOrder(orderList, "payState", payState);
                                    break;
                                } else {
                                    cout << "��������Ӧ��Ϊ'0(δ֧��)'��'1(��֧��)'������������: ";
                                }
                            }
                            break;
                        }
                        case 9: {
                            cout << "���������ѯ�����Ķ���״̬(0δ���� 1������ 2�����): ";
                            int orderState;
                            while (cin >> orderState) {
                                if (orderState == 0 || orderState == 1 || orderState == 2) {
                                    cout << "----------------------------------------------------------------" << endl;
                                    queryAndShowOrder(orderList, "orderState", orderState);
                                    break;
                                } else {
                                    cout << "��������Ӧ��Ϊ'0(δ����)'��'1(������)'��'2(�����)'������������: ";
                                }
                            }
                            break;
                        }
                        default:
                            cout << "������������������" << endl;
                            break;
                        }

                        Menu::adminQuery();
                    }
                    break;
                }
                case 3: { // �޸�
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    Menu::adminChange();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "���������޸Ķ����Ķ������: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            changeOrder(orderList, "orderID", orderID);
                            break;
                        }
                        case 2: {
                            cout << "���������޸Ķ����Ĺ�˾����: ";
                            string company;
                            cin >> company;
                            cout << "----------------------------------------------------------------" << endl;
                            changeOrder(orderList, "company", company);
                            break;
                        }
                        case 3: {
                            cout << "���������޸Ķ����Ŀͻ�����: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            changeOrder(orderList, "customer", customer);
                            break;
                        }
                        default:
                            cout << "������������������" << endl;
                            break;
                        }

                        Menu::adminChange();
                    }
                    break;
                }
                case 4: { // ɾ��
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    Menu::adminDelete();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "��������ɾ�������Ķ������: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            delOrder(orderList, "orderID", orderID);
                            break;
                        }
                        case 2: {
                            cout << "��������ɾ�������Ĺ�˾����: ";
                            string company;
                            cin >> company;
                            cout << "----------------------------------------------------------------" << endl;
                            delOrder(orderList, "company", company);
                            break;
                        }
                        case 3: {
                            cout << "��������ɾ�������Ŀͻ�����: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            delOrder(orderList, "customer", customer);
                            break;
                        }
                        default:
                            cout << "������������������" << endl;
                            break;
                        }

                        Menu::adminDelete();
                    }
                    break;
                }
                case 5: { // ����
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    Menu::adminSort();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl
                             << "����������ʽ(1���� 2����): ";
                        int type;
                        cin >> type;
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getOrderID() < right.getData().getOrderID();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getOrderID() > right.getData().getOrderID();
                                });
                            }
                            break;
                        }
                        case 2: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCompany() < right.getData().getCompany();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCompany() > right.getData().getCompany();
                                });
                            }
                            break;
                        }
                        case 3: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCustomer() < right.getData().getCustomer();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCustomer() > right.getData().getCustomer();
                                });
                            }
                            break;
                        }
                        case 4: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getProduct() < right.getData().getProduct();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getProduct() > right.getData().getProduct();
                                });
                            }
                            break;
                        }
                        case 5: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getPrice() < right.getData().getPrice();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getPrice() > right.getData().getPrice();
                                });
                            }
                            break;
                        }
                        case 6: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getNum() < right.getData().getNum();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getNum() > right.getData().getNum();
                                });
                            }
                            break;
                        }
                        case 7: {
                            if (type == 1) {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getAmount() < right.getData().getAmount();
                                });
                            } else {
                                orderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getAmount() > right.getData().getAmount();
                                });
                            }
                            break;
                        }
                        default:
                            cout << "������������������" << endl;
                            break;
                        }

                        Menu::adminSort();
                    }
                    break;
                }
                case 6: { // ͳ��
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    Menu::adminStats();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            orderList.statsOrder();
                            break;
                        }
                        case 2: {
                            cout << "��������ͳ�ƶ����Ĺ�˾����: ";
                            string company;
                            cin >> company;
                            cout << "----------------------------------------------------------------" << endl;
                            orderList.statsOrder("company", company);
                            break;
                        }
                        case 3: {
                            cout << "��������ͳ�ƶ����Ŀͻ�����: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            orderList.statsOrder("customer", customer);
                            break;
                        }
                        case 4: {
                            cout << "��������ͳ�ƶ����Ĳ�Ʒ����: ";
                            string product;
                            cin >> product;
                            cout << "----------------------------------------------------------------" << endl;
                            orderList.statsOrder("product", product);
                            break;
                        }
                        default:
                            cout << "������������������" << endl;
                            break;
                        }

                        Menu::adminStats();
                    }
                    break;
                }
                case 7: { // ��ʾ���ж���
                    if (!orderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    cout << "----------------------------------------------------------------" << endl;
                    orderList.display();
                    break;
                }
                default:
                    cout << "������������������" << endl;
                    break;
                }

                Menu::main();
            }

            Menu::login();
            break;
        }
        case 2: {
            // ��˾��¼
            string name;
            string password;
            cout << "�����빫˾��\n> ";
            cin >> name;
            cout << "����������\n> ";
            cin >> password;
            cout << "----------------------------------------------------------------" << endl;
            Company company(name, password);
            if (!companyList.logincheck(company)) {
                Menu::login();
                break;
            }

            OrderList companyOrderList;
            initSpecificOrderList(orderList, companyOrderList, "company", company.name);

            Menu::main();
            while (cin >> typeNum && typeNum) {
                switch (typeNum) {
                case 1: { // ���
                    cout << "----------------------------------------------------------------" << endl;
                    ListNode<Order> *companyOrderNode = companyOrderList.addCompanyOrder(cin, company.name);
                    auto orderNode = new ListNode<Order>(*companyOrderNode);
                    orderList.addNode(orderNode);
                    orderFile.add(orderNode->getData());
                    cout << "----------------------------------------------------------------" << endl
                         << "��ӳɹ�" << endl
                         << "----------------------------------------------------------------" << endl
                         << orderNode->getData() << endl;
                    break;
                }
                case 2: { // ��ѯ
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    Menu::companyQuery();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "���������ѯ�����ı��: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "orderID", orderID);
                            break;
                        }
                        case 2: {
                            cout << "���������ѯ�����Ŀͻ�����: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "customer", customer);
                            break;
                        }
                        case 3: {
                            cout << "���������ѯ�����Ĳ�Ʒ���ƣ�";
                            string product;
                            cin >> product;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "product", product);
                            break;
                        }
                        case 4: {
                            cout << "���������ѯ�����Ĳ�Ʒ���۵ķ�Χ: " << endl
                                 << "��Сֵ: ";
                            double priceMin;
                            cin >> priceMin;
                            cout << "���ֵ: ";
                            double priceMax;
                            cin >> priceMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "price", priceMin, priceMax);
                            break;
                        }
                        case 5: {
                            cout << "���������ѯ�����Ķ�������ķ�Χ: " << endl
                                 << "��Сֵ: ";
                            int numMin;
                            cin >> numMin;
                            cout << "���ֵ: ";
                            int numMax;
                            cin >> numMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "num", numMin, numMax);
                            break;
                        }
                        case 6: {
                            cout << "���������ѯ�����Ķ������ķ�Χ: " << endl
                                 << "��Сֵ: ";
                            double amountMin;
                            cin >> amountMin;
                            cout << "���ֵ: ";
                            double amountMax;
                            cin >> amountMax;
                            cout << "----------------------------------------------------------------" << endl;
                            queryAndShowOrder(companyOrderList, "amount", amountMin, amountMax);
                            break;
                        }
                        case 7: {
                            cout << "���������ѯ������֧��״̬(0δ֧�� 1��֧��): ";
                            int payState;
                            while (cin >> payState) {
                                if (payState == 0 || payState == 1) {
                                    cout << "----------------------------------------------------------------" << endl;
                                    queryAndShowOrder(companyOrderList, "payState", payState);
                                    break;
                                } else {
                                    cout << "��������Ӧ��Ϊ'0(δ֧��)'��'1(��֧��)'������������: ";
                                }
                            }
                            break;
                        }
                        case 8: {
                            cout << "���������ѯ�����Ķ���״̬(0δ���� 1������ 2�����): ";
                            int orderState;
                            while (cin >> orderState) {
                                if (orderState == 0 || orderState == 1 || orderState == 2) {
                                    cout << "----------------------------------------------------------------" << endl;
                                    queryAndShowOrder(companyOrderList, "orderState", orderState);
                                    break;
                                } else {
                                    cout << "��������Ӧ��Ϊ'0(δ����)'��'1(������)'��'2(�����)'������������: ";
                                }
                            }
                            break;
                        }
                        default:
                            cout << "������������������" << endl;
                            break;
                        }

                        Menu::companyQuery();
                    }
                    break;
                }
                case 3: { // �޸�
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    Menu::companyChange();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "���������޸Ķ����Ķ������: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            ListNode<Order> *order = changeOrder(companyOrderList, "orderID", orderID);
                            if (order) {
                                orderList.changeOrder(order);
                                if (order->getData().getCompany() != company.name) {
                                    companyOrderList.delOrder(order->getData().getOrderID());
                                }
                            }

                            break;
                        }
                        case 2: {
                            cout << "���������޸Ķ����Ŀͻ�����: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            ListNode<Order> *order = changeOrder(companyOrderList, "customer", customer);
                            if (order) {
                                orderList.changeOrder(order);
                                if (order->getData().getCompany() != company.name) {
                                    companyOrderList.delOrder(order->getData().getOrderID());
                                }
                            }
                            break;
                        }
                        default:
                            cout << "������������������" << endl;
                            break;
                        }

                        Menu::companyChange();
                    }
                    break;
                }
                case 4: { // ɾ��
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    Menu::companyDelete();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            cout << "��������ɾ�������Ķ������: ";
                            long long orderID;
                            cin >> orderID;
                            cout << "----------------------------------------------------------------" << endl;
                            orderID = delOrder(companyOrderList, "orderID", orderID);
                            if (orderID) {
                                orderList.delOrder(orderID);
                            }
                            break;
                        }
                        case 2: {
                            cout << "��������ɾ�������Ŀͻ�����: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            long long orderID = delOrder(companyOrderList, "customer", customer);
                            if (orderID) {
                                orderList.delOrder(orderID);
                            }
                            break;
                        }
                        default:
                            cout << "������������������" << endl;
                            break;
                        }

                        Menu::companyDelete();
                    }
                    break;
                }
                case 5: { // ����
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    Menu::companySort();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl
                             << "����������ʽ(1���� 2����): ";
                        int type;
                        cin >> type;
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getOrderID() < right.getData().getOrderID();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getOrderID() > right.getData().getOrderID();
                                });
                            }
                            break;
                        }
                        case 2: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCustomer() < right.getData().getCustomer();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getCustomer() > right.getData().getCustomer();
                                });
                            }
                            break;
                        }
                        case 3: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getProduct() < right.getData().getProduct();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getProduct() > right.getData().getProduct();
                                });
                            }
                            break;
                        }
                        case 4: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getPrice() < right.getData().getPrice();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getPrice() > right.getData().getPrice();
                                });
                            }
                            break;
                        }
                        case 5: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getNum() < right.getData().getNum();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getNum() > right.getData().getNum();
                                });
                            }
                            break;
                        }
                        case 6: {
                            if (type == 1) {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getAmount() < right.getData().getAmount();
                                });
                            } else {
                                companyOrderList.sort([](const ListNode<Order> &left, const ListNode<Order> &right) -> bool {
                                    return left.getData().getAmount() > right.getData().getAmount();
                                });
                            }
                            break;
                        }
                        default:
                            cout << "������������������" << endl;
                            break;
                        }

                        Menu::companySort();
                    }
                    break;
                }
                case 6: { // ͳ��
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    Menu::companyStats();
                    int typeNum_;
                    while (cin >> typeNum_ && typeNum_) {
                        cout << "----------------------------------------------------------------" << endl;
                        switch (typeNum_) {
                        case 1: {
                            companyOrderList.statsOrder();
                            break;
                        }
                        case 2: {
                            cout << "��������ͳ�ƶ����Ŀͻ�����: ";
                            string customer;
                            cin >> customer;
                            cout << "----------------------------------------------------------------" << endl;
                            companyOrderList.statsOrder("customer", customer);
                            break;
                        }
                        case 3: {
                            cout << "��������ͳ�ƶ����Ĳ�Ʒ����: ";
                            string product;
                            cin >> product;
                            cout << "----------------------------------------------------------------" << endl;
                            companyOrderList.statsOrder("product", product);
                            break;
                        }
                        default:
                            cout << "������������������" << endl;
                            break;
                        }

                        Menu::companyStats();
                    }
                    break;
                }
                case 7: {
                    if (!companyOrderList.getSize()) {
                        cout << "----------------------------------------------------------------" << endl
                             << "��ǰû�ж�������" << endl;
                        break;
                    }

                    cout << "----------------------------------------------------------------" << endl;
                    companyOrderList.display();
                    break;
                }
                default:
                    cout << "������������������" << endl;
                    break;
                }

                Menu::main();
            }

            Menu::login();
            break;
        }
        case 3: { // ע��
            cout << "----------------------------------------------------------------" << endl;
            Company newCompany;
            cin >> newCompany;
            if (!companyList.registerCheck(newCompany)) {
                Menu::login();
                break;
            }

            auto newCompanyNode = new ListNode<Company>;
            newCompanyNode->setData(newCompany);
            companyList.addNode(newCompanyNode);
            companyFile.add(newCompany);
            cout << "----------------------------------------------------------------" << endl
                 << "ע��ɹ�" << endl;

            Menu::login();
            break;
        }
        default:
            cout << "������������������" << endl;
            break;
        }
    }

    orderFile.save(orderList);
    companyFile.save(companyList);
    cout << "��ӭ�´�ʹ��" << endl;

    system("pause");
    return 0;
}