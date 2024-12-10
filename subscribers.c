#include <stdio.h>
#include <string.h>
#define N 100

struct abonent{
    char name[10];
    char second_name[10];
    char tel[10];
};

int main(){
    int filled = 0;
    int a = 1;
    while (a == 1){
        printf("1) Добавить абонента\n"
"2) Удалить абонента\n"
"3) Поиск абонентов по имени\n"
"4) Вывод всех записей\n"
"5) Выход \n");
        int operation;
        scanf("%d", &operation);
        int j = 0;
        int found;
        char search[10];
        struct abonent st[N];

        if (operation == 1){
            if (filled<N){
                printf("Введите Имя абонента №%d: \n", filled);
                scanf("%s", st[filled].name);
                printf("Введите Фамилию абонента №%d: \n", filled);
                scanf("%s", st[filled].second_name);
                printf("Введите Номер телефона абонента №%d: \n", filled);
                scanf("%s", st[filled].tel);
                filled++;
            }
            else{
                printf("Переполнение справочника, больше элементов добавлять нельзя! \n");
                continue;
            }
        }
        if (operation == 2){
            printf("Введите номер абонента для удаления: \n");
            scanf("%d", &j);
            if (j<0 || j>=filled){
                printf("Некорректный выбор абонента! \n");
                continue;
            }
            char *ptr = (char*)&st[j];
            for (int i=0; i<sizeof(st[j]); i++){
                ptr[i] = 0;
            }
            ptr = ptr + sizeof(st[j].name);
            for (int i=0; i<sizeof(st[j]); i++){
                ptr[i] = 0;
            }
            ptr = ptr + sizeof(st[j].second_name);
            for (int i=0; i<sizeof(st[j]); i++){
                ptr[i] = 0;
            }
            filled--;
            printf("Абонент успешно очищен. \n");
        }
        if (operation == 3){
            printf("Введите имя искомого абонента: \n");
            scanf("%s",search);
            found = 0;
            for (int i =0; i<N; i++){
                if (strcmp(st[i].name,search)==0){
                    printf("Найден абонент под номером №%d \n", i);
                    printf("%s \n", st[i].name);
                    printf("%s \n", st[i].second_name);
                    printf("%s \n", st[i].tel);
                    printf("\n");
                    found++;
                }
            }
            if (found == 0){
                printf("Абонент с заданным именем не найден! \n");
            }

        }
        if (operation == 4){
            if (filled == 0){
                printf("Записи отсутсвуют! \n");
            }
            else{
                printf("Все абоненты: \n");
                for (int i = 0; i<filled; i++){
                    printf("Номер абонента №%d \n", i);
                    printf("%s \n", st[i].name);
                    printf("%s \n", st[i].second_name);
                    printf("%s \n", st[i].tel);
                    printf("\n");
                }
            }
        }
        if (operation == 5){
            break;
        }
    }
    return 0;

}
