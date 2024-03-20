#include <iostream>
#include "data_structures.h"
#define N 10000
//--------------Стек (список)---------------//

void push(stack_list*& head, int value) {

    stack_list* newNode = new stack_list;
    newNode->value = value;
    newNode->next_ptr = nullptr;

    if (!head) {
        head = newNode;
        return;
    }

    stack_list* temp = head;
    while (temp->next_ptr) {
        temp = temp->next_ptr;
    }
    temp->next_ptr = newNode;
}

void pop(stack_list*& head) {
    stack_list* temp;
    while (head) {
        temp = head->next_ptr;
        delete head;
        head = temp;
    }
}

//--------------Очередь(список)---------------//

void enqueue(queue_list*& front, queue_list*& rear, int value) {
    queue_list* newNode = new queue_list;
    newNode->value = value;
    newNode->next_ptr = nullptr;
    if (!front) {
        front = rear = newNode;
    }
    else {
        rear->next_ptr = newNode;
        rear = newNode;
    }
}

void dequeue(queue_list*& front, queue_list*& rear) {
    if (!front) {
        std::cout << "Queue underflow" << std::endl;
        return;
    }
    queue_list* temp = front;
    front = front->next_ptr;
    if (!front) {
        rear = nullptr;
    }
    delete temp;
}


//---------------Ф-ции для стека(массив)----------//

void stack_array_push(int value, int* stack_ptr, int& stack_array_num)
{

    if (stack_array_num ==N)
    {
        std::cout << "Stack (Array) overflow" << std::endl;
        return;
    }

    *stack_ptr++ = value;
    stack_array_num++;
}

void stack_array_pop(int* stack_ptr, int& stack_array_num)
{
    if (stack_array_num == 0)
    {
        std::cout << "Stack (Array) underflow" << std::endl;
        return;
    }

    stack_ptr--;
    stack_array_num--;
}

//---------------------Ф-ции для очереди(массив)---------------------------------//

void queue_array_enqueue(int value, int* queue_array, int& queue_front, int& queue_rear, int& queue_size)
{
    if ((queue_rear + 1) % N == queue_front) //
    {
        std::cout << "Queue (List) overflow" << std::endl;
        return;
    }

    queue_array[queue_rear + 1] = value;
    queue_rear = (queue_rear + 1) % N;
    queue_size++;
}
void queue_array_dequeue(int* queue_array, int& queue_front, int& queue_rear, int& queue_size)
{
    if (queue_size == 0)
    {
        std::cout << "Queue (List) underflow" << std::endl;
        return;
    }
    queue_front = (queue_front + 1) % N;
    queue_size--;


}