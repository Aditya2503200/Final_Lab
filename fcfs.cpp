#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    int id;
    int arrivalTime; 
    int burstTime;  
};

bool compareByArrivalTime(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].id = i + 1; 
    }
    sort(processes.begin(), processes.end(), compareByArrivalTime);

    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    cout << "\nOrder of process execution (ID, Waiting Time, Turnaround Time):\n";

    for (const auto &process : processes) {
        int waitingTime = currentTime - process.arrivalTime;
        int turnaroundTime = waitingTime + process.burstTime;
        cout << "Process " << process.id << ": "
             << "Waiting Time = " << waitingTime << ", "
             << "Turnaround Time = " << turnaroundTime << endl;
        totalWaitingTime += waitingTime;
        totalTurnaroundTime += turnaroundTime;
        currentTime += process.burstTime;
    }
    double averageWaitingTime = (double) totalWaitingTime / n;
    double averageTurnaroundTime = (double) totalTurnaroundTime / n;

    cout << "\nAverage Waiting Time: " << averageWaitingTime << endl;
    cout << "Average Turnaround Time: " << averageTurnaroundTime << endl;

    return 0;
}
