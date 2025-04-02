#include <stdio.h>

#define MAX_TASKS 5

typedef struct {
    int id;
    int execution_time;
    int period;
    int remaining_time;
    int next_deadline;
} Task;

void sort_tasks_by_period(Task tasks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tasks[j].period > tasks[j + 1].period) {
                Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
}

void rate_monotonic(Task tasks[], int n, int hyperperiod) {
    printf("\nRate Monotonic Scheduling:\n");
    for (int t = 0; t < hyperperiod; t++) {
        int running_task = -1;
        for (int i = 0; i < n; i++) {
            if (tasks[i].remaining_time > 0) {
                running_task = i;
                break;
            }
        }
        
        if (running_task != -1) {
            printf("Time %d: Task %d is running\n", t, tasks[running_task].id);
            tasks[running_task].remaining_time--;
        } else {
            printf("Time %d: Idle\n", t);
        }
        
        for (int i = 0; i < n; i++) {
            if ((t + 1) % tasks[i].period == 0) {
                tasks[i].remaining_time = tasks[i].execution_time;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter number of tasks: ");
    scanf("%d", &n);
    
    Task tasks[MAX_TASKS];
    int hyperperiod = 1;
    
    for (int i = 0; i < n; i++) {
        printf("Enter execution time and period for Task %d: ", i + 1);
        scanf("%d %d", &tasks[i].execution_time, &tasks[i].period);
        tasks[i].id = i + 1;
        tasks[i].remaining_time = tasks[i].execution_time;
        hyperperiod *= tasks[i].period;
    }
    
    sort_tasks_by_period(tasks, n);
    rate_monotonic(tasks, n, hyperperiod);
    
    return 0;
}
