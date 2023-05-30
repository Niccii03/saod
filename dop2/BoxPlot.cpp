#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BoxPlot 
{
    vector<double> data;
    double minVal;
    double maxVal;
    double median;
    double Q1;
    double Q3;
    vector<double> outliers;
public:
    BoxPlot(vector<double> d) 
    {
        data = d;
        calculate();
    }
    void calculate() 
    {
        sort(data.begin(), data.end());
        minVal = data.front();
        maxVal = data.back();
        int n = data.size();
        if (n % 2 == 0) 
        {
            median = (data[n / 2 - 1] + data[n / 2]) / 2;
            Q1 = (data[n / 4 - 1] + data[n / 4]) / 2;
            Q3 = (data[n * 3 / 4 - 1] + data[n * 3 / 4]) / 2;
        }
        else 
        {
            median = data[n / 2];
            Q1 = data[n / 4];
            Q3 = data[n * 3 / 4];
        }
        double IQR = Q3 - Q1;
        double lowerFence = Q1 - 1.5 * IQR;
        double upperFence = Q3 + 1.5 * IQR;
        for (double d : data) 
        {
            if (d < lowerFence || d > upperFence) 
            {
                outliers.push_back(d);
            }
        }
    }
    void display() 
    {
        int width = 50;
        int height = 10;
        vector<vector<char>> graph(height, vector<char>(width, ' '));
        // Draw horizontal axis
        for (int i = 0; i < width; i++) 
        {
            graph[height / 2][i] = '-';
        }
        // Draw vertical axis
        for (int i = 0; i < height; i++) 
        {
            graph[i][width / 2] = '|';
        }
        // Draw whiskers
        int Q1Pos = (int)((Q1 - minVal) / (maxVal - minVal) * (width - 1));
        int Q3Pos = (int)((Q3 - minVal) / (maxVal - minVal) * (width - 1));
        for (int i = Q1Pos; i <= Q3Pos; i++) 
        {
            graph[height / 4][i] = '-';
            graph[height * 3 / 4][i] = '-';
        }
        // Draw median
        int medianPos = (int)((median - minVal) / (maxVal - minVal) * (width - 1));
        for (int i = 0; i < height; i++) 
        {
            graph[i][medianPos] = '|';
        }
        // Draw outliers
        for (double d : outliers) 
        {
            int outlierPos = (int)((d - minVal) / (maxVal - minVal) * (width - 1));
            graph[height / 2][outlierPos] = 'x';
        }
        // Display graph
        for (int i = 0; i < height; i++) 
        {
            for (int j = 0; j < width; j++) 
            {
                cout << graph[i][j];
            }
            cout << endl;
        }
    }
};

int main() 
{
    vector<double> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    BoxPlot boxPlot(data);
    boxPlot.display();
    return 0;
}