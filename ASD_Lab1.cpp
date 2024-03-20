#include <iostream>
#include <chrono>
#include "data_structures.h"
#define N 10000

void stackArray()
{
    int stack_array[N];
    int stack_array_num = 0;

    for (int i = 0; i < N; ++i) {
        stack_array_push(1, stack_array, stack_array_num); // Заполняем стек единицами
    }

    for (int i = 0; i < N; ++i) {
        stack_array_pop(stack_array, stack_array_num); // Извлекаем элементы из стека
    }

}
void queueArray()
{
    int queue_array[N];
    int queue_front_ptr = -1;
    int queue_rear_ptr = -1;
    int queue_size = 0;
    for (size_t i = 0; i < N; i++) {
        queue_array_enqueue(1, queue_array, queue_front_ptr, queue_rear_ptr, queue_size); // Заполняем очередь единицами
    }

    for (size_t i = 0; i < N; i++) {
        queue_array_dequeue(queue_array, queue_front_ptr, queue_rear_ptr, queue_size);
    }
}

void stackList()
{ 
    stack_list* my_stack = new stack_list();

    for (size_t i = 0; i < N; i++) {
        push(my_stack, 1); // Заполняем стек единицами
    }
    
    for (size_t i = 0; i < N; i++)
    {
        pop(my_stack);
    }

}

void queueList()
{
    // Заполнение очереди через список
    queue_list* front = nullptr;
    queue_list* rear = nullptr;
    for (size_t i = 0; i < N; i++) {
        enqueue(front, rear, 1); // Заполняем очередь единицами
    }

    for (size_t i = 0; i < N; i++)
    {
        dequeue(front, rear);
    }
}

int main()
{
  
    auto start = std::chrono::high_resolution_clock::now();
    stackArray();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Stack (Array): " << duration.count() << " microsec" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    stackList();
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Stack (List): " << duration.count() << " microsec" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    queueArray();
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Queue (Array): " << duration.count() << " microsec" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    queueList();
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Queue (List): " << duration.count() << " microsec" << std::endl;

}
