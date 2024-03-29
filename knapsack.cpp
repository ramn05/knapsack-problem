#include <iostream>
using namespace std;

/* Function to find maximum of two integers */
int max(int a, int b) { return (a > b) ? a : b; }

/* Returns the maximum value that can be put in a knapsack of capacity W */
int knapSack(int W, int weight[], int value[], int n)
{
    int i, w;
    int K[n + 1][W + 1];

    /* Build table K[][] in bottom up manner */
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (weight[i - 1] <= w)
                K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}
int main()
{
    int n;
    cout << "\nEnter the number of items : ";
    cin >> n;
    int profit[n];
    int weight[n];
    int i;
    cout << "\nEnter the item's weight and its profit \n";
    for (i = 0; i < n; i++)
    {
        cin >> weight[i] >> profit[i];
    }
    cout << "Weight\tProfit\n";
    for (i = 0; i < n; i++)
    {
        cout << weight[i] << "\t" << profit[i] << "\n";
    }
    int W;
    cout << "\nEnter the capacity of the knapsack : ";
    cin >> W;
    cout << "\nMaximum value in a 0/1 knapsack : " << knapSack(W, weight, profit, n) << endl;
    return 0;
}