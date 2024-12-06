#ifndef QUEUE_H
#define QUEUE_H
#include "BSTPhone.h"
#include <stdexcept>


struct NodeQueue
{
    BSTPhone* data;
    NodeQueue *next;

    NodeQueue(BSTPhone* phoneData) : data(phoneData), next(nullptr) {}
};

class Queue {
private:
    NodeQueue* front;
    NodeQueue* rear;
public:
    // Constructor: Khởi tạo hàng đợi rỗng
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor: Giải phóng bộ nhớ của tất cả các node trong hàng đợi
    ~Queue() {
        while (!isEmpty()) {
            pop();  // pop sẽ giải phóng bộ nhớ của mỗi node
        }
    }

    // Kiểm tra hàng đợi có rỗng không
    bool isEmpty() {
        return front == nullptr;
    }

    // Thêm phần tử vào cuối hàng đợi
    void push(BSTPhone* data)
    {
        NodeQueue* newNode = new NodeQueue(data);
        if (isEmpty()) {
            // Khi hàng đợi trống, cả front và rear sẽ trỏ đến newNode
            front = rear = newNode;
            rear->next = front; // Tạo danh sách vòng
        } else {
            // Khi hàng đợi có ít nhất 1 phần tử
            rear->next = newNode;  // rear trỏ đến newNode
            rear = newNode;        // Cập nhật rear
            rear->next = front;    // rear trỏ lại đầu hàng đợi (danh sách vòng)
        }
    }

    // Lấy phần tử đầu hàng đợi và xóa nó
    BSTPhone* pop()
    {
        if(isEmpty())
            throw runtime_error("Queue is Empty");

        NodeQueue *frontNode = rear->next; // Lấy node đầu hàng đợi
        BSTPhone* value = frontNode->data;

        if (front == rear) { // Chỉ còn 1 phần tử trong hàng đợi
            front = rear = nullptr; // Cập nhật lại cho hàng đợi trống
        } else {
            front = front->next;  // Cập nhật front tới phần tử tiếp theo
            rear->next = front;   // rear trỏ lại front (danh sách vòng)
        }

        delete frontNode; // Giải phóng bộ nhớ
        return value;
    }

    // Lấy phần tử đầu tiên mà không xóa
    BSTPhone* peek()
    {
        if (isEmpty())
            throw runtime_error("Queue is empty");
        return rear->next->data;
    }
};

#endif // QUEUE_H
