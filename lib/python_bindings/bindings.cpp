#include <pybind11/pybind11.h>
#ifndef _GTCV_OBJECTS_H_
#define _GTCV_OBJECTS_H_

#define GTCV_API_VERSION_MAJOR 0
#define GTCV_API_VERSION_MINOR 1
#define GTCV_API_VERSION_PATCH 0

#define GTCV_API_VERSION "0.1.0"
#define GTCV_API_VERSION_MAJOR_MINOR "0.1"
#define GTCV_API_VERSION_MAJOR_MINOR_PATCH "0.1.0"

#define GTCV_API_VERSION_MAJOR_OR_GREATER(major) (GTCV_API_VERSION_MAJOR >= major)
#define GTCV_API_VERSION_MINOR_OR_GREATER(minor) (GTCV_API_VERSION_MINOR >= minor)
#define GTCV_API_VERSION_PATCH_OR_GREATER(patch) (GTCV_API_VERSION_PATCH >= patch)

#define GTCV_API_DECLARE_ 
#define GTCV_API_IMPLEMENT_
#define GTCV_API_DEFINE_
#define GTCV_API_DECLARE_IMPLEMENT_
#define GTCV_API_DECLARE_DEFINE_
#define GTCV_API_IMPLEMENT_DEFINE_

#define GTCV_API_EXPORT extern "C" {
#define GTCV_API_IMPORT extern "C"
#define GTCV_API_UNUSED [[maybe_unused]]
#define GTCV_API_NORETURN [[noreturn]]
#define GTCV_API_DEPRECATED [[deprecated]]
#define GTCV_API_DEPRECATED_MSG(msg) [[deprecated(msg)]]
#define GTCV_API_DEPRECATED_REPL(repl) [[deprecated(repl)]]
#define GTCV_API_DEPRECATED_REPL_MSG(repl, msg) [[deprecated(repl, msg)]]
#define GTCV_API_DEPRECATED_SINCE(since) [[deprecated(since)]]
#define GTCV_API_DEPRECATED_SINCE_MSG(since, msg) [[deprecated(since, msg)]]
#define GTCV_API_DEPRECATED_SINCE_REPL(since, repl) [[deprecated(since, repl)]]
#define GTCV_API_DEPRECATED_SINCE_REPL_MSG(since, repl, msg) [[deprecated(since, repl, msg)]]

#define GTCV_API_FALLTHROUGH [[fallthrough]]
#define GTCV_API_LIKELY [[likely]]
#define GTCV_API_UNLIKELY [[unlikely]]

#define GTCV_API_NOEXCEPT noexcept
#define GTCV_API_TEMPLATE template
#define GTCV_API_INLINE inline
#define GTCV_API_STATIC static
#define GTCV_API_CONSTEXPR constexpr
#define GTCV_API_CONSTEXPR_INLINE GTCV_API_CONSTEXPR GTCV_API_INLINE
#define GTCV_API_CONSTEXPR_STATIC GTCV_API_CONSTEXPR GTCV_API_STATIC
#define GTCV_API_CONSTEXPR_STATIC_INLINE GTCV_API_CONSTEXPR GTCV_API_STATIC GTCV_API_INLINE

#define GTCV_API_NULL NULL

#define GTCV_API_NULLPTR nullptr
#define GTCV_API_NULLPTR_T nullptr_t
#define GTCV_API_NULLPTR_T_DECL std::nullptr_t
#define GTCV_API_NULLPTR_T_DEF std::nullptr_t GTCV_API_NULLPTR

#define GTCV_API_CPP __cplusplus
#define GTCV_API_CPP_98 199711L
#define GTCV_API_CPP_03 199711L
#define GTCV_API_CPP_11 201103L
#define GTCV_API_CPP_14 201402L
#define GTCV_API_CPP_17 201703L
#define GTCV_API_CPP_20 202002L
#define GTCV_API_CPP_23 202300L

#define GTCV_API_CPP_98_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_98)
#define GTCV_API_CPP_03_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_03)
#define GTCV_API_CPP_11_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_11)
#define GTCV_API_CPP_14_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_14)
#define GTCV_API_CPP_17_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_17)
#define GTCV_API_CPP_20_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_20)
#define GTCV_API_CPP_23_OR_GREATER (GTCV_API_CPP >= GTCV_API_CPP_23)

#define GTCV_API_C 199409L
#define GTCV_API_C_98 199409L
#define GTCV_API_C_99 199901L
#define GTCV_API_C_11 201112L
#define GTCV_API_C_17 201710L
#define GTCV_API_C_23 202300L

#define GTCV_API_C_98_OR_GREATER (GTCV_API_C >= GTCV_API_C_98)
#define GTCV_API_C_99_OR_GREATER (GTCV_API_C >= GTCV_API_C_99)
#define GTCV_API_C_11_OR_GREATER (GTCV_API_C >= GTCV_API_C_11)
#define GTCV_API_C_17_OR_GREATER (GTCV_API_C >= GTCV_API_C_17)
#define GTCV_API_C_23_OR_GREATER (GTCV_API_C >= GTCV_API_C_23)

#ifdef GTCV_API_CPP_11_OR_GREATER
    #define GTCV_API_AVAILABLE_BOOST __has_include(<boost/version.hpp>)
    #define GTCV_API_AVAILABLE_OPENCV __has_include(<opencv2/core/version.hpp>)
    #define GTCV_API_AVAILABLE_QT __has_include(<QtCore/QCoreApplication>)

    #if GTCV_API_AVAILABLE_BOOST
        #include <boost/version.hpp>
        #define GTCV_API_BOOST_AVAILABLE
    #endif /* GTCV_API_AVAILABLE_BOOST */

    #if GTCV_API_AVAILABLE_OPENCV
        #include <opencv2/opencv.hpp>
        #define GTCV_API_OPENCV_AVAILABLE
    #endif /* GTCV_API_AVAILABLE_OPENCV */

    #if GTCV_API_AVAILABLE_QT
        #include <QtCore/QCoreApplication>
        #define GTCV_API_QT_AVAILABLE
    #endif /* GTCV_API_AVAILABLE_QT */

    #define GTCV_OBJECT(className) GTCV_API_STATIC std::string getClassName() { return #className; }

    #define GTCV_API_NAMESPACE namespace GTCV_API {
    #define GTCV_API_NAMESPACE_END }

    #define GTCV_API ::GTCV_API::

    #define USING_GTCV_API using namespace GTCV_API;

#endif /* GTCV_API_CPP_11_OR_GREATER */

#endif /* _GTCV_OBJECTS_H_ */
namespace py = pybind11;

#include <pthread.h>

#define public_slot public
#define protected_slot protected
#define private_slot private

#define public_signal public
#define protected_signal protected
#define private_signal private

// Проверочный макрос
#define CHECK_SLOTS_ONLY static_assert(true, "This section should contain only slots!");

// Проверочный макрос
#define CHECK_SLOTS_ONLY static_assert(true, "This section should contain only slots!");

#define CREATE_SLOT(func, args) ((Slot){.func = func, .args = args})
#define CREATE_SIGNAL(capacity) ((Signal){.slots = malloc(sizeof(Slot) * capacity), .capacity = capacity, .count = 0, .mutex = PTHREAD_MUTEX_INITIALIZER})
#define ADD_SLOT_TO_SIGNAL(signal, slot)                          \
    do {                                                          \
    pthread_mutex_lock(&(signal).mutex);                      \
    if ((signal).count >= (signal).capacity) {                \
    (signal).capacity *= 2;                               \
    (signal).slots = realloc((signal).slots, sizeof(Slot) * (signal).capacity); \
    }                                                         \
    (signal).slots[(signal).count++] = slot;                  \
    pthread_mutex_unlock(&(signal).mutex);                    \
} while(0)

#define EMIT_SIGNAL(signal)                                   \
do {                                                          \
   pthread_mutex_lock(&(signal).mutex);                       \
   for (int i = 0; i < (signal).count; ++i) {                 \
   (signal).slots[i].func((signal).slots[i].args);            \
   }                                                          \
   pthread_mutex_unlock(&(signal).mutex);                     \
} while(0)

/**
 * @brief Function pointer type for slot functions.
 *
 * @param data Pointer to the data passed to the slot function.
 * @param args Pointer to the arguments passed to the slot function.
 */
GTCV_API_DECLARE_ typedef void (*func_t)(void *data, void *args);

/**
 * @brief Structure representing a slot.
 *
 * A slot contains a function pointer and its associated arguments.
 */
GTCV_API_DECLARE_ typedef struct {
    func_t func; /**< Function pointer for the slot. */
    void *args;  /**< Arguments for the slot function. */
} Slot;

/**
 * @brief Structure representing a signal.
 *
 * A signal contains a dynamic array of slots, its capacity, and the current count of slots.
 */
GTCV_API_DECLARE_ typedef struct {
    Slot *slots;   /**< Dynamic array of slots. */
    int capacity;  /**< Capacity of the slots array. */
    int count;     /**< Current count of slots. */

    pthread_mutex_t mutex; // Мьютекс для защиты доступа к слотам
} Signal;

/**
 * @brief Initializes a Signal object.
 *
 * This function initializes a Signal object by setting its count to 0, its capacity to 2,
 * and allocating memory for its slots array.
 *
 * @param signal Pointer to the Signal object to be initialized.
 */
GTCV_API_DECLARE_ void signal_init(Signal *signal);

/**
 * @brief Frees the memory allocated for a Signal object.
 *
 * This function frees the memory allocated for the slots array of a Signal object.
 *
 * @param signal Pointer to the Signal object to be freed.
 */
GTCV_API_DECLARE_ void free_signal(Signal *signal);

/**
 * @brief Expands the slots array of a Signal object.
 *
 * This function doubles the capacity of the slots array if the current count of slots
 * reaches the capacity.
 *
 * @param signal Pointer to the Signal object whose slots array should be expanded.
 */
GTCV_API_DECLARE_ void expand_slots(Signal *signal);

/**
 * @brief Connects a slot to a signal.
 *
 * This function adds a slot to the signal's list of slots. If the slots array is full,
 * it expands the array before adding the new slot.
 *
 * @param signal Pointer to the Signal object to which the slot should be connected.
 * @param func Function pointer for the slot function.
 * @param args Arguments for the slot function.
 */
GTCV_API_DECLARE_ void connect_slot(Signal *signal, const func_t func, void *args);

/**
 * @brief Disconnects a slot from a signal.
 *
 * This function removes a slot from the signal's list of slots if the slot's
 * function matches the provided function pointer. It shifts the remaining slots
 * in the list to fill the gap and decrements the slot count.
 *
 * @param signal Pointer to the Signal object from which the slot should be disconnected.
 * @param func Function pointer to the slot function that should be disconnected.
 */
GTCV_API_DECLARE_ void disconnect_slot(Signal *signal, const func_t func);

// /**
//  * @brief Disconnects all slots from a signal.
//  *
//  * This function removes all slots from the signal's list of slots by setting the slot count to 0.
//  *
//  * @param signal Pointer to the Signal object from which all slots should be disconnected.
//  */
// GTCV_API_DECLARE_ void disconnect_all_slots(Signal *signal);

/**
 * @brief Emits a signal.
 *
 * This function calls the function of each slot in the signal's list of slots,
 * passing the provided data and the slot's arguments to the function.
 *
 * @param signal Pointer to the Signal object to be emitted.
 * @param data Pointer to the data to be passed to each slot function.
 */
GTCV_API_DECLARE_ void emit_signal(Signal *signal, void *data);
/*
 * COPYRIGHT (c) 2024 Massonskyi
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Initializes a Signal object.
 *
 * This function initializes a Signal object by setting its count to 0, its capacity to 2,
 * and allocating memory for its slots array.
 *
 * @param signal Pointer to the Signal object to be initialized.
 */
void signal_init(Signal *signal) {
    signal->count = 0;
    signal->capacity = 2;
    signal->slots = (Slot *)malloc(sizeof(Slot) * signal->capacity);
    pthread_mutex_init(&signal->mutex, NULL); // Инициализация мьютекса
}

/**
 * @brief Frees the memory allocated for a Signal object.
 *
 * This function frees the memory allocated for the slots array of a Signal object.
 *
 * @param signal Pointer to the Signal object to be freed.
 */
void free_signal(Signal *signal) {
    if (signal->slots != NULL){
        pthread_mutex_destroy(&signal->mutex);
        signal->slots = NULL;
        signal->capacity = 0;
        signal->count = 0;
        free(signal->slots);
    }
}

/**
 * @brief Expands the slots array of a Signal object.
 *
 * This function doubles the capacity of the slots array if the current count of slots
 * reaches the capacity.
 *
 * @param signal Pointer to the Signal object whose slots array should be expanded.
 */
void expand_slots(Signal *signal) {
    if (signal->count >= signal->capacity) {
        signal->capacity *= 2;
        signal->slots = (Slot *)realloc(signal->slots, signal->capacity * sizeof(Slot));
    }
}

/**
 * @brief Connects a slot to a signal.
 *
 * This function adds a slot to the signal's list of slots. If the slots array is full,
 * it expands the array before adding the new slot.
 *
 * @param signal Pointer to the Signal object to which the slot should be connected.
 * @param func Function pointer for the slot function.
 * @param args Arguments for the slot function.
 */
void connect_slot(Signal *signal, const func_t func, void *args) {
    pthread_mutex_lock(&signal->mutex); // Захватываем мьютекс

    expand_slots(signal);
    signal->slots[signal->count].func = func;
    signal->slots[signal->count].args = args;
    signal->count++;

    pthread_mutex_unlock(&signal->mutex); // Освобождаем мьютекс
}

/**
 * @brief Disconnects a slot from a signal.
 *
 * This function removes a slot from the signal's list of slots if the slot's
 * function matches the provided function pointer. It shifts the remaining slots
 * in the list to fill the gap and decrements the slot count.
 *
 * @param signal Pointer to the Signal object from which the slot should be disconnected.
 * @param func Function pointer to the slot function that should be disconnected.
 */
void disconnect_slot(Signal *signal, const func_t func) {
    pthread_mutex_lock(&signal->mutex); // Захватываем мьютекс

    for (int i = 0; i < signal->count; i++) {
        if (signal->slots[i].func == func) {
            for (int j = i; j < signal->count - 1; j++) {
                signal->slots[j] = signal->slots[j + 1];
            }
            signal->count--;
            break;
        }
    }

    pthread_mutex_unlock(&signal->mutex); // Освобождаем мьютекс
}

// /**
//  * @brief Disconnects all slots from a signal.
//  *
//  * This function removes all slots from the signal's list of slots by setting the slot count to 0.
//  *
//  * @param signal Pointer to the Signal object from which all slots should be disconnected.
//  */
// void disconnect_all_slots(Signal *signal) {
//     pthread_mutex_lock(&signal->mutex); // Захватываем мьютекс

//     signal->count = 0;

//     pthread_mutex_unlock(&signal->mutex); // Освобождаем мьютекс
// }

/**
 * @brief Emits a signal.
 *
 * This function calls the function of each slot in the signal's list of slots,
 * passing the provided data and the slot's arguments to the function.
 *
 * @param signal Pointer to the Signal object to be emitted.
 * @param data Pointer to the data to be passed to each slot function.
 */

void emit_signal(Signal *signal, void *data) {
    pthread_mutex_lock(&signal->mutex); // Захватываем мьютекс
    for (int i = 0; i < signal->count; i++) {
        const Slot *slot = &signal->slots[i];
        slot->func(data, slot->args);
    }
    pthread_mutex_unlock(&signal->mutex); // Освобождаем мьютекс
}

PYBIND11_MODULE(gtcv, m) {
    m.attr("GTCV_API_VERSION_MAJOR") = GTCV_API_VERSION_MAJOR; 
    m.attr("GTCV_API_VERSION_MINOR") = GTCV_API_VERSION_MINOR;
    m.attr("GTCV_API_VERSION_PATCH") = GTCV_API_VERSION_PATCH;
    m.attr("GTCV_API_VERSION") = GTCV_API_VERSION;


    py::class_<Signal>(m, "Signal")
        .def(py::init<>())
        .def("init", &signal_init)
        .def("free", &free_signal)
        .def("expand_slots", &expand_slots)
        .def("connect_slot", &connect_slot)
        .def("disconnect_slot", &disconnect_slot)
        .def("emit_signal", &emit_signal);
}