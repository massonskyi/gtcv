#pragma once
#ifndef _GTCV_SIGNAL_H_
#define _GTCV_SIGNAL_H_

#include <pthread.h>
#include "gtcv_objects.h"

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
#endif /* _GTCV_SIGNAL_H_ */
