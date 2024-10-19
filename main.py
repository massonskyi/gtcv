import gtcv
print(gtcv.GTCV_API_VERSION)

# Создание объекта Signal
signal = gtcv.Signal()

# Инициализация сигнала
signal.init()

# # Расширение слотов
# signal.expand_slots(10)

# Подключение слота
def slot_function():
    print("Слот вызван")

signal.connect_slot(slot_function)

# Вызов сигнала
signal.emit_signal()

# Отключение слота
signal.disconnect_slot(slot_function)

# Отключение всех слотов
# signal.disconnect_all_slots()

# Освобождение сигнала
signal.free()