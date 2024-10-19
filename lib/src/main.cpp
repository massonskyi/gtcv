#include <iostream>
#include "gtcv_signal.h"

// Пример функции слота
void example_slot(void *data, void *args) {
    int *int_data = static_cast<int*>(data);
    int *int_args = static_cast<int*>(args);
    std::cout << "Slot called with data: " << *int_data << " and args: " << *int_args << std::endl;
}

int main(int argc, char** argv) {
    // Инициализация сигнала
    Signal signal;
    signal_init(&signal);

    // Пример данных и аргументов для слотов
    int data = 42;
    int args1 = 1;
    int args2 = 2;

    // Подключение слотов
    connect_slot(&signal, example_slot, &args1);
    connect_slot(&signal, example_slot, &args2);

    // Эмитирование сигнала
    emit_signal(&signal, &data);

    // Отключение слота
    disconnect_slot(&signal, example_slot);

    // Эмитирование сигнала после отключения одного слота
    emit_signal(&signal, &data);

    // Отключение всех слотов
    disconnect_all_slots(&signal);

    // Эмитирование сигнала после отключения всех слотов
    emit_signal(&signal, &data);

    // Освобождение памяти
    free_signal(&signal);

    return 0;
}
