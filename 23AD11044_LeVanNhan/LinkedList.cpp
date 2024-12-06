#include "LinkedList.h"

// Tạo một node mới
Node* CreateNode(PhoneInformation data) {
    Node* p = new Node();
    if (p == nullptr) return nullptr;

    p->data = data;
    p->pNext = nullptr;
    return p;
}

// Chèn node vào đầu danh sách liên kết
void InsertFirst(List& l, Node* p) {
    if (p == nullptr) return; // Kiểm tra node null

    if (l.pHead == nullptr) {
        // Nếu danh sách rỗng, phần tử mới sẽ là cả đầu và đuôi
        l.pHead = l.pTail = p;
    } else {
        // Nếu danh sách không rỗng, chèn node vào đầu
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

// Chèn node vào cuối danh sách liên kết
void InsertLast(List& l, Node* p) {
    if (p == nullptr) return; // Kiểm tra node null

    if (l.pHead == nullptr) {
        // Nếu danh sách rỗng, phần tử mới sẽ là cả đầu và đuôi
        l.pHead = l.pTail = p;
    } else {
        // Nếu danh sách không rỗng, thêm node vào cuối
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

// Chèn node vào sau node q trong danh sách liên kết
void InsertAfter(List& l, Node* p, Node* q) {
    if (p == nullptr || q == nullptr) return; // Kiểm tra node null

    p->pNext = q->pNext;  // Đặt p->pNext trỏ tới node tiếp theo của q
    q->pNext = p;         // Đặt p làm node tiếp theo của q

    // Nếu p được chèn vào cuối danh sách, cập nhật l.pTail
    if (p->pNext == nullptr) {
        l.pTail = p;
    }
}

// Xóa phần tử đầu tiên trong danh sách
void RemoveFirst(List& l) {
    if (l.pHead == nullptr) return;

    Node* temp = l.pHead;
    l.pHead = l.pHead->pNext;
    delete temp;

    // Nếu danh sách sau khi xóa phần tử đầu tiên trở nên rỗng
    if (l.pHead == nullptr) {
        l.pTail = nullptr;
    }
}

// Xóa phần tử cuối cùng trong danh sách
void RemoveLast(List& l) {
    if (l.pHead == nullptr) return;

    if (l.pHead == l.pTail) {
        delete l.pHead;
        l.pHead = l.pTail = nullptr;
    } else {
        Node* p = l.pHead;
        while (p->pNext != l.pTail) {
            p = p->pNext;
        }

        delete l.pTail;
        l.pTail = p;
        l.pTail->pNext = nullptr;
    }
}

// Xóa một phần tử bất kỳ trong danh sách
void Remove(List& l, Node* p) {
    if (l.pHead == nullptr || p == nullptr) return;

    // Nếu phần tử cần xóa là phần tử đầu tiên
    if (p == l.pHead) {
        RemoveFirst(l);
        return;
    }

    // Nếu phần tử cần xóa là phần tử cuối cùng
    if (p == l.pTail) {
        RemoveLast(l);
        return;
    }

    Node* x = l.pHead;
    Node* k = nullptr;

    // Duyệt qua danh sách để tìm phần tử cần xóa
    while (x != nullptr) {
        if (x == p) {
            k->pNext = x->pNext;  // Cập nhật con trỏ pNext của node trước phần tử cần xóa
            delete x;              // Xóa phần tử
            return;
        }

        k = x;
        x = x->pNext;
    }
}

// Đếm số node
int countNodeLL(List l)
{
    int count = 0;
    Node* current = l.pHead;

    // Duyệt qua tất cả các phần tử trong danh sách
    while (current != nullptr) {
        count++;  // Tăng biến đếm khi gặp một node
        current = current->pNext;  // Chuyển đến node tiếp theo
    }

    return count;  // Trả về số lượng phần tử trong danh sách
}
