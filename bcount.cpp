#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h> // Thêm thư viện time.h

// Struct đại diện cho mỗi tiến trình
struct Process {
    int id;            // ID của tiến trình
    int arrivalTime;   // Thời gian đến
    int burstTime;     // Thời gian thực thi
    int remainingTime; // Thời gian còn lại sau mỗi lần chạy
};

// Hàm thực hiện lập lịch bằng thuật toán Round Robin
void roundRobinScheduling(struct Process processes[], int n, int quantum) {
    int currentTime = 0;

    // Duyệt qua từng tiến trình
    while (true) {
        bool allProcessesDone = true; // Kiểm tra xem tất cả các tiến trình đã hoàn thành chưa

        // Duyệt qua từng tiến trình để kiểm tra và chạy
        for (int i = 0; i < n; i++) {
            // Nếu tiến trình chưa kết thúc
            if (processes[i].remainingTime > 0) {
                allProcessesDone = false; // Có ít nhất một tiến trình chưa hoàn thành

                // Chạy tiến trình trong quantum hoặc đến khi tiến trình kết thúc
                if (processes[i].remainingTime <= quantum) {
                    currentTime += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                } else {
                    currentTime += quantum;
                    processes[i].remainingTime -= quantum;
                }

                printf("Chạy tiến trình %d đến thời điểm %d\n", processes[i].id, currentTime);
            }
        }

        // Nếu tất cả các tiến trình đã hoàn thành, thoát khỏi vòng lặp
        if (allProcessesDone) {
            break;
        }
    }
}

int main() {
    srand(time(NULL));

    int n = 5; // Số lượng tiến trình
    int quantum = 3; // Đơn vị thời gian quantum

    // Khởi tạo mảng các tiến trình với thông tin ngẫu nhiên
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        processes[i].arrivalTime = rand() % 21; // Arrival Time trong đoạn [0, 20]
        processes[i].burstTime = rand() % 11 + 2; // Burst Time trong đoạn [2, 12]
        processes[i].remainingTime = processes[i].burstTime;
    }

    // Gọi hàm lập lịch Round Robin
    roundRobinScheduling(processes, n, quantum);

    return 0;
}
