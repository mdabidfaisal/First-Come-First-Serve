#include <iostream>
#include <iomanip>  // For std::setw to format the output
using namespace std;

int main() {
    const int max_p = 20;
    int n, bt[max_p], wt[max_p], tat[max_p];
    float avwt = 0, avtat = 0;  // Changed from int to float for more precise calculation
    int i, j;

    cout << "Enter total number of processes (maximum 20): ";
    cin >> n;

    if(n <= 0 || n > max_p) {
        cout << "Invalid number of processes. Please enter a value between 1 and " << max_p << "." << endl;
        return 1;
    }

    cout << "\nEnter Process Burst Time" << endl;
    for (i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]: ";
        cin >> bt[i];
        if(bt[i] < 0) {
            cout << "Burst time cannot be negative." << endl;
            return 1;
        }
    }

    // Initialize the waiting time for the first process
    wt[0] = 0;

    // Calculating waiting time
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
    }

    // Display headers
    cout << left << setw(10) << "Process" << setw(15) << "Burst Time" << setw(20) << "Waiting Time" << setw(25) << "Turnaround Time" << endl;

    // Calculating turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        cout << "P[" << i+1 << "]" << setw(4) << "" << setw(14) << bt[i] << setw(19) << wt[i] << setw(24) << tat[i] << endl;
    }

    avwt /= n;  // Changed i to n to ensure division is done over total number of processes
    avtat /= n;  // Same change as above

    cout << "\nAverage Waiting Time: " << fixed << setprecision(2) << avwt << endl;
    cout << "Average Turnaround Time: " << fixed << setprecision(2) << avtat << endl;

    return 0;
}
