#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "BSTPhone.h"

struct Node {
    PhoneInformation data;
    Node* pNext;
};

struct List {
    Node* pHead;
    Node* pTail;

    List() : pHead(nullptr), pTail(nullptr) {}
};

// Tạo một node mới
Node* CreateNode(PhoneInformation data);
// Chèn node vào đầu danh sách liên kết
void InsertFirst(List& l, Node* p);

// Chèn node vào cuối danh sách liên kết
void InsertLast(List& l, Node* p);

// Chèn node vào sau node q trong danh sách liên kết
void InsertAfter(List& l, Node* p, Node* q);
// Xóa phần tử đầu tiên trong danh sách
void RemoveFirst(List& l);
// Xóa phần tử cuối cùng trong danh sách
void RemoveLast(List& l);
// Xóa một phần tử bất kỳ trong danh sách
void Remove(List& l, Node* p);
// Đếm số node
int countNodeLL(List l);
#endif // LINKEDLIST_H
