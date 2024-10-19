import gtcv

# Определение функций для слотов
def slot_function_1(data, args):
    print(f"Slot 1 called with data: {data} and args: {args}")

def slot_function_2(data, args):
    print(f"Slot 2 called with data: {data} and args: {args}")

# Создание объекта Signal
signal = gtcv.Signal()
signal.init()

# Подключение слотов к сигналу
signal.connect_slot(slot_function_1, "Arguments for slot 1")
signal.connect_slot(slot_function_2, "Arguments for slot 2")

# Испускание сигнала
signal.emit_signal("Test data")

# Освобождение ресурсов
signal.free()