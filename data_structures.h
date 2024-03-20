#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

//--------------Стек (список)---------------//
struct stack_list {
    int value;
    stack_list* next_ptr;
    stack_list() : value(), next_ptr(nullptr) {}
};

void push(stack_list*& head, int value);
void pop(stack_list*& head);

//----------------------Очередь(список)-----------------------------//

struct queue_list {
    int value;
    queue_list* next_ptr;
    queue_list() : value(), next_ptr(nullptr) {}
};

void enqueue(queue_list*& front, queue_list*& rear, int value);
void dequeue(queue_list*& front, queue_list*& rear);

//---------------Ф-ции для стека(массив)----------//

void stack_array_push(int value, int* stack_ptr, int& stack_array_num);
void stack_array_pop(int* stack_ptr, int& stack_array_num);

//---------------------Ф-ции для очереди(массив)---------------------------------//

void queue_array_enqueue(int value, int* queue_array, int& queue_front, int& queue_rear, int& queue_size);
void queue_array_dequeue(int* queue_array, int& queue_front, int& queue_rear, int& queue_size);

#endif