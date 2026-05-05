#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    bool is_in_queue = false;
};

void printQueue(queue<int> q) {
    if (q.empty()) {
        cout << "[ Empty ]" << endl;
        return;
    }
    cout << "[ ";
    while (!q.empty()) {
        cout << "P" << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << " ]" << endl;
}

int main() {
    int n, quantum;
    cout << "Time Quantum: "; cin >> quantum;
    cout << "Number of Processes: "; cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cout << "Arrival & Burst P" << p[i].id << ": ";
        cin >> p[i].arrival_time >> p[i].burst_time;
        p[i].remaining_time = p[i].burst_time;
    }

    queue<int> ready_q;
    int current_time = 0;
    int completed = 0;

    cout << "\nQueue updates:" << endl;

    while (completed < n) {
        for (int i = 0; i < n; i++) {
            if (p[i].arrival_time <= current_time && p[i].remaining_time > 0 && !p[i].is_in_queue) {
                ready_q.push(p[i].id);
                p[i].is_in_queue = true;
            }
        }

        if (ready_q.empty()) {
            printQueue(ready_q);
            int next_arrival = -1;
            for (int i = 0; i < n; i++) {
                if (!p[i].is_in_queue) {
                    if (next_arrival == -1 || p[i].arrival_time < next_arrival)
                        next_arrival = p[i].arrival_time;
                }
            }
            if (next_arrival != -1) current_time = next_arrival;
            else current_time++;
            continue;
        }

        printQueue(ready_q);

        int pid = ready_q.front();
        ready_q.pop();
        int idx = pid - 1;

        int exec_time = min(p[idx].remaining_time, quantum);

        for (int t = 0; t < exec_time; t++) {
            current_time++;
            p[idx].remaining_time--;

            for (int i = 0; i < n; i++) {
                if (p[i].arrival_time <= current_time && p[i].remaining_time > 0 && !p[i].is_in_queue) {
                    ready_q.push(p[i].id);
                    p[i].is_in_queue = true;
                }
            }
        }

        if (p[idx].remaining_time > 0) {
            ready_q.push(pid);
        } else {
            completed++;
            p[idx].completion_time = current_time;
            p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
            p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
        }
    }

    printQueue(ready_q);

    cout << "\nProcess Completion Time Turnaround Time Waiting Time" << endl;
    double total_wt = 0;
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].id << " " << p[i].completion_time << " "
             << p[i].turnaround_time << " " << p[i].waiting_time << endl;
        total_wt += p[i].waiting_time;
    }

    cout << fixed << setprecision(3);
    cout << "\nAverage Waiting Time: " << (double)total_wt / n << endl;

    return 0;
}
