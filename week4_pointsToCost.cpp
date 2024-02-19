#include <iostream>
#include <vector>
// #include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int N;
    double C, x, y;
    cin >> N >> C;

    vector<double> X(N), Y(N);
    double sumX = 0, cost = 0;

    // Read the points and calculate the sum of x-coordinates
    for (int i = 0; i < N; ++i) 
    {
        cin >> X[i] >> Y[i];
        sumX += X[i];
    }

    // Calculate the optimal p (average of x-coordinates)
    double p = sumX / N;

    // Calculate the minimized cost
    for (int i = 0; i < N; ++i) 
    {
        cost += (X[i] - p) * (X[i] - p) + (Y[i] - C) * (Y[i] - C);
    }

    // Output the minimized cost with precision up to 10^-9
    cout << fixed << setprecision(9) << cost << endl;

    return 0;
}
