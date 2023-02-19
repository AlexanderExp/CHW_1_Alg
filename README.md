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

Дополнительная оптимизация сокращает время сортировки почти отсортированного массива ещё сильнее. Тем временем, для остальных типов массивов оптимизация так же работает положительно, сокращая время их сортировки.
В целом:
• Асимптотическая сложность - 𝑂(𝑛!)
• Время работы в худшем и среднем случае - 𝑂 𝑛!
• Время работы в лучшем случае - 𝑂𝑛
• Дополнительная память - 𝑂(1)

3) Bubble Sort, оптимизированный первым и вторым условием Айверсона

<img width="475" alt="image" src="https://user-images.githubusercontent.com/95678672/219963070-b48cf2b4-efe2-4dec-a909-fe80703dc1a3.png"> <img width="730" alt="image" src="https://user-images.githubusercontent.com/95678672/219963085-075d5e06-21df-496a-9e47-800db41b1b52.png">

Оптимизация сортировки пузырьком двумя условиями еще лучше влияет на скорость сортировки массива. Видим общее улучшение времени сортировок.

4) Counting Sort

<img width="474" alt="image" src="https://user-images.githubusercontent.com/95678672/219963308-9e43b5d8-7a41-48c1-aec3-2e94618345fe.png"> <img width="724" alt="image" src="https://user-images.githubusercontent.com/95678672/219963318-dce1aa56-4dc1-4fe7-95b1-68abe7b91c71.png">


5) Selection Sort

<img width="474" alt="image" src="https://user-images.githubusercontent.com/95678672/219963338-f859f1b6-e68f-4e78-8a1a-944088ec4892.png"> <img width="809" alt="image" src="https://user-images.githubusercontent.com/95678672/219963345-39175bfa-9cfe-49d0-9c1b-13d0e4617e0c.png">


6) Radix Sort

<img width="473" alt="image" src="https://user-images.githubusercontent.com/95678672/219963364-2ef651ed-c6e1-42cd-af92-c8bfdc138a06.png"> <img width="886" alt="image" src="https://user-images.githubusercontent.com/95678672/219963371-42a88404-59bd-40ee-b39b-eb2f3052ca2e.png">

7) Heap Sort

<img width="472" alt="image" src="https://user-images.githubusercontent.com/95678672/219963384-002c34e0-eaf4-4e0f-92b6-2083928769d7.png"> <img width="994" alt="image" src="https://user-images.githubusercontent.com/95678672/219963399-a1946073-179f-45cb-938d-a79b042e3e29.png">

8) Merge Sort

<img width="473" alt="image" src="https://user-images.githubusercontent.com/95678672/219963432-991f57d0-14f1-44de-99b8-c21887f87107.png"> <img width="993" alt="image" src="https://user-images.githubusercontent.com/95678672/219963442-c1e670d1-23a5-49cd-84c9-6f39e27eab2d.png">

9) Quick Sort

<img width="472" alt="image" src="https://user-images.githubusercontent.com/95678672/219963474-80ecaf38-ebcf-47bc-a42c-ec08043c743d.png"> <img width="807" alt="image" src="https://user-images.githubusercontent.com/95678672/219963457-6f3c76bd-ab32-43c3-945a-7e3ab2f1acb0.png">

10) Regular insertion Sort

<img width="473" alt="image" src="https://user-images.githubusercontent.com/95678672/219963532-ef18b1b5-d930-4a74-8392-396356947a40.png"> <img width="807" alt="image" src="https://user-images.githubusercontent.com/95678672/219963544-2624179c-813c-473e-9fe5-13598800802a.png">

11) Binary insertion Sort

<img width="473" alt="image" src="https://user-images.githubusercontent.com/95678672/219963579-3f5fbb77-a975-4610-a2c6-2025a31f9638.png"> <img width="807" alt="image" src="https://user-images.githubusercontent.com/95678672/219963572-b151e9f4-ad29-46a6-ab82-014329f3f88e.png">

12) Shell Sort on Shell Sequence

<img width="475" alt="image" src="https://user-images.githubusercontent.com/95678672/219963608-d0f746b4-c097-49c4-999e-b3b4eb69397f.png"> <img width="807" alt="image" src="https://user-images.githubusercontent.com/95678672/219963658-9af8b869-50fc-4e64-b8a9-62aa17529962.png">


13) Shell Sort on Ciura Sequence

<img width="476" alt="image" src="https://user-images.githubusercontent.com/95678672/219963626-438a5b74-0357-4cea-9e0a-9662b2fca147.png"> <img width="807" alt="image" src="https://user-images.githubusercontent.com/95678672/219963646-4fdb825a-625d-4be6-9765-38f7c03321cb.png">

