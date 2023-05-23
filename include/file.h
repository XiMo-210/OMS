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
    // 构造
    File(const string &path, const string &fileType);

    // 读取文件初始化链表
    void initList(List &list);

    // 文件添加数据
    void add(T &data);

    // 将数据保存到文件（覆写）
    void save(List &list);

private:
    string path;
    string fileType;
};

// 构造
template <typename List, typename T>
File<List, T>::File(const string &path, const string &fileType) {
    this->path = path;
    this->fileType = fileType;
}

// 读取文件初始化链表
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

    // 读取一个字符用于判断文件是否为空
    ifs.get();

    while (!ifs.eof()) {
        list.addNode(ifs);
    }
    ifs.close();
}

// 文件添加数据
template <typename List, typename T>
void File<List, T>::add(T &data) {
    ofstream ofs;
    ofs.open(path + fileType, ios::app);
    if (!ofs.is_open()) {
        cout << "文件打开失败" << endl;
        return;
    }

    ofs << endl
        << data;
    ofs.close();
}

// 将数据保存到文件（覆写）
template <typename List, typename T>
void File<List, T>::save(List &list) {
    ofstream ofs;
    ofs.open(path + ".temp", ios::app);
    if (!ofs.is_open()) {
        cout << "文件打开失败" << endl;
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
