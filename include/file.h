//
// Created by XiMo on 2023/4/23.
//

#ifndef OMS_FILE_H
#define OMS_FILE_H
#include <fstream>
#include <iostream>
using namespace std;

template <typename List, typename T>
class File {
public:
    // ����
    File(const string &path, const string &fileType);

    // ��ȡ�ļ���ʼ������
    void initList(List &list);

    // �ļ��������
    void add(T &data);

    // �����ݱ��浽�ļ�����д��
    void save(List &list);

private:
    string path;
    string fileType;
};

// ����
template <typename List, typename T>
File<List, T>::File(const string &path, const string &fileType) {
    this->path = path;
    this->fileType = fileType;
}

// ��ȡ�ļ���ʼ������
template <typename List, typename T>
void File<List, T>::initList(List &list) {
    ifstream ifs;
    ifs.open(path + fileType, ios::in);
    if (!ifs.is_open()) {
        ofstream out;
        out.open(path + fileType, ios::out | ios::app);
        out.close();
        ifs.open(path + fileType, ios::in);
    }

    // ��ȡһ���ַ������ж��ļ��Ƿ�Ϊ��
    ifs.get();

    while (!ifs.eof()) {
        list.addNode(ifs);
    }
    ifs.close();
}

// �ļ��������
template <typename List, typename T>
void File<List, T>::add(T &data) {
    ofstream ofs;
    ofs.open(path + fileType, ios::app);
    if (!ofs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    ofs << endl
        << data;
    ofs.close();
}

// �����ݱ��浽�ļ�����д��
template <typename List, typename T>
void File<List, T>::save(List &list) {
    ofstream ofs;
    ofs.open(path + ".temp", ios::app);
    if (!ofs.is_open()) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    auto ptr = list.getHead();
    while (ptr) {
        ofs << endl
            << ptr->getData();
        ptr = ptr->getNext();
    }
    ofs.close();
    remove((path + fileType).c_str());
    rename((path + ".temp").c_str(), (path + fileType).c_str());
}

#endif // OMS_FILE_H
