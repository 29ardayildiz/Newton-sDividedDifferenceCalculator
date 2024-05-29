#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<double>> dividedDifferences(const vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<double>> div_diff(n, vector<double>(n));

    for (int i = 0; i < n; ++i) {
        div_diff[i][0] = points[i][1];
    }

    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            div_diff[i][j] = (div_diff[i + 1][j - 1] - div_diff[i][j - 1]) / (points[i + j][0] - points[i][0]);
        }
    }

    return div_diff;
}

string NPolynomial(const vector<vector<int>>& points, const vector<vector<double>>& div_diff) {
    int n = points.size();
    string polynomial = "P(x) = " + to_string(div_diff[0][0]);

    for (int i = 1; i < n; ++i) {
        polynomial += " + " + to_string(div_diff[0][i]);
        for (int j = 0; j < i; ++j) {
            polynomial += "(x - " + to_string(points[j][0]) + ")";
        }
    }

    return polynomial;
}

int main() {
    int n;
    cout << "Enter the data points: ";
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));
    cout << "Enter the x values and y values:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> points[i][0] >> points[i][1];
    }

    vector<vector<double>> div_diff = dividedDifferences(points);
    string polynomial = NPolynomial(points, div_diff);
    cout << polynomial << endl;

    return 0;
}
