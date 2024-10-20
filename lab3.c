#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

int nums_check(int mode){
        while (mode != 0){
                if (mode % 10 > 7){
                        return 1;
                }
                mode = mode / 10;
        }
        return 0;
}

int main(int argc, char* argv[]) {
        argc = argc + 1;
    // Конвертация строки в число, основание 8 для восприятия числа как восьмеричного
        long mode = strtol(argv[1], NULL, 8);
        int mode1 = strtol(argv[1], NULL, 10);
    // Проверка на корректность диапазона значений
        if (mode < 0  mode > 7777  nums_check(mode1) == 1) {
                return 1;
        }
    // Изменение прав доступа
        if (chmod(argv[2], mode)) {
                return 1;
        }

        return 0;
}
