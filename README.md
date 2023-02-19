# CHW_1_Alg

АИСД-2, 2023, задание 5
Фролов Александр Сергеевич БПИ217

# О работе программы

Программа написана на с++ в CLion.

В программе реализованы следующие сортировки: 
1) выбором
2) пузырьком
3) пузырьком с условием Айверсона 1
4) пузырьком с условием Айверсона 1+2
5) простыми вставками
6) бинарными вставками
7) подсчетом (устойчивая)
8) цифровой
9) слиянием
10) быстрой (первый опорный)
11) пирамидальной
12) Шелла (последовательность Циура)
13) Шелла (последовательность Шелла)

При запуске программы каждая сортировка запускается сначала 24 * 30(30 - количество запусков для дальнейшего усреднения результата) раза на массивах, размер которых лежит в интервале [50-300]. На каждом размере массивов сортировка тестируется на 4 видах массивов: 
1) Заполенный случайными значениями, лежащими на интервале [0, 5]
2) Заполенный случайными значениями, лежащими на интервале [0, 4000]
3) Заполенный значениями, отсортированными в обратном порядке, (от n до 1), где n - размер массива
4) Почти отсортированный массив, в котором на каждых 50 элементах выполнена одна перестановка значений: 5-ой и 25-ой элемент переставлены друг с другом (начинаем счёт с 0) 

Затем каждая сортировка запускается еще 164 * 30(30 - количество запусков для дальнейшего усреднения результата) раза на массивах, размер которых лежит в интервале [100-4100]. На каждом размере массивов сортировка тестируется на 4 видах массивов: 
1) Заполенный случайными значениями, лежащими на интервале [0, 5]
2) Заполенный случайными значениями, лежащими на интервале [0, 4000]
3) Заполенный значениями, отсортированными в обратном порядке, (от n до 1), где n - размер массива
4) Почти отсортированный массив, в котором на каждых 50 элементах выполнена одна перестановка значений: 5-ой и 25-ой элемент переставлены друг с другом (начинаем счёт с 0) 

Каждая вариация запуска сортировки повторяется 30 раз. При каждом запуске замеряется время работы сортировки в наносекундах, затем 30 значений усредняется и выводится в csv файл (CHW.csv) напротив соответствующего названия сортировки и размера массива, под соответствующим типом массива.

Перед запуском программы для получения результатов замеров были закрыты все сторонние приложения, браузеры и прочее, чтобы не загружать процессор операциями, не относящимися к замерам.


# Итоги замеров по времени
Во-первых, на некоторых графиках можно заметить скачки, не соответствующие ожиданиям :<img width="470" alt="image" src="https://user-images.githubusercontent.com/95678672/219962060-e94d935c-7342-4013-9017-43f63d41b220.png"> <img width="469" alt="image" src="https://user-images.githubusercontent.com/95678672/219962083-53a6749d-d48d-41c6-a152-15b06dc9969c.png"> <img width="724" alt="image" src="https://user-images.githubusercontent.com/95678672/219962134-5ee8cfae-fcd7-44d8-a0f9-976760fc8b26.png">

Такие скачки встречаются периодически. Они могут быть вызваны совершенно разными процессами. Компьютер чтчо-то решил сделать без нашего ведома => загрузил процессор => возник перепад.


Теперь перейдем непосредственно к замерам:
1) Bubble Sort

<img width="469" alt="image" src="https://user-images.githubusercontent.com/95678672/219962683-f553e816-f357-4aa4-8fd2-17078f208bb8.png"> <img width="633" alt="image" src="https://user-images.githubusercontent.com/95678672/219962720-e8ffa305-db81-4768-ad3b-c642eb87c2cf.png">

Видим, что на почти отсортированном массиве эта сортировка работает быстрее, чем на рандомных массивах. В остальном, 
• Асимптотическая сложность - 𝑂(𝑛!)
• Время работы в худшем и среднем случае - 𝑂 𝑛!
• Дополнительная память - 𝑂(1)

2) Bubble Sort, оптимизированный первым условием Айверсона
<img width="474" alt="image" src="https://user-images.githubusercontent.com/95678672/219962864-09418f7a-b857-41e2-945d-80f5f6362a94.png"> <img width="682" alt="image" src="https://user-images.githubusercontent.com/95678672/219962854-22170f38-f90f-45fd-9750-2a3fe869e9a3.png">




