Отчет по лабораторной работе № 1 по дисциплине "Параллельное программирование".
Выполнила Куспанова Дания, гр. 6312-100503D

Задание: Написать программу на языке C/C++ для перемножения двух матриц. 
Исходные данные: файл(ы) содержащие значения исходных матриц.
Выходные данные: файл со значениями результирующей матрицы, время выполнения, объем задачи.
Обязательна автоматизированная верификация результатов вычислений с помощью сторонних библиотек или стороннего ПО (например на Matlab/Python).

Объемы задачи: матрицы 500х500, 1000х1000, 1500х1500;

Ход работы.
1) Для создания исходных файлов использовался язык программирования Python, на котором была написана программа, реализующая создание матриц и сохранение их в csv-файлы (matrix_500.csv, 
matrix_1000.csv, matrix_1500.csv). Исходный код находится в файле create_input_file.ipynb.
2) На языке С++ была реализована программа для основной работы с матрицами. Считанные из файлов матрицы один раз умножаются сами на себя, при этом данный опыт повторяется 10 раз и в отдельную матрицу
фиксируется время выполнения операции умножения исходной матрицы. Результирующие матрицы записываются в csv-файлы matrix_res_500.csv, matrix_res_1000.csv, matrix_res_1500.csv, а матрица времени
помещается в файл matrix_time.csv.
3) Далее на языке Python реализован скрип create_statistic.ipynb, реализующий отображение статистики результирующих файлов, в том числе зависимость времени перемножения матриц от их размера.

Вывод: В результате полученных данных задания становится очевидно, что время реализации операции умножения матриц зависит от их размера, то есть для большего размера матриц требуется больше времени.
Причем это время достигает огромных цифр. В своих исследованиях я убедилась, что для последовательного возведения в квадрат матриц размеров 500х500, 1000х1000, 1500х1500, понадобилось около 7-10 минут, что свидетельствует о сильной нагрузке на процессор (Intel Pentium CPU 6805).
