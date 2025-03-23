#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 256

typedef struct {
    char task[MAX_LENGTH];
    int isDone;
} Task;

void addTask(Task tasks[], int* count) {
    if (*count >= MAX_TASKS) {
        printf("Görev listesi dolu!\n");
        return;
    }

    printf("Yeni görev girin: ");
    getchar(); // Tampon temizleme
    fgets(tasks[*count].task, MAX_LENGTH, stdin);
    tasks[*count].task[strcspn(tasks[*count].task, "\n")] = '\0'; // Satır sonunu kaldırma
    tasks[*count].isDone = 0;
    (*count)++;
    printf("Görev eklendi!\n");
}

void markTaskDone(Task tasks[], int count) {
    int index;
    printf("Tamamlanan görevin numarasını girin: ");
    scanf("%d", &index);

    if (index < 1 || index > count) {
        printf("Geçersiz görev numarası!\n");
        return;
    }

    tasks[index - 1].isDone = 1;
    printf("Görev tamamlandı olarak işaretlendi!\n");
}

void showTasks(Task tasks[], int count) {
    if (count == 0) {
        printf("Görev listesi boş!\n");
        return;
    }

    printf("Görevler:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. [%s] %s\n", i + 1, tasks[i].isDone ? "X" : " ", tasks[i].task);
    }
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    while (1) {
        printf("\n1. Gorev Ekle\n");
        printf("2. Gorev Tamamla\n");
        printf("3. Gorevleri Goruntule\n");
        printf("4. cıkıs\n");
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addTask(tasks, &taskCount);
            break;
        case 2:
            markTaskDone(tasks, taskCount);
            break;
        case 3:
            showTasks(tasks, taskCount);
            break;
        case 4:
            printf("Çıkış yapılıyor...\n");
            return 0;
        default:
            printf("Geçersiz seçim!\n");
        }
    }
}
