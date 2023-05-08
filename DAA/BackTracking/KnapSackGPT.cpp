// class knap
// {
//     friend int knapsack(int *, int *, int, int);
//     // Declare private member functions and variables
// private:
//     float bound(int i);            // Calculate upper bound
//     void knapsack(int i);          // Recursive function
//     int c, n, w, p, cw, cp, bestp; // Capacity, number of items, weight, profit, current weight, current profit, best profit
// }

// // Recursive function to solve knapsack problem
// void
// knapsack(int i)
// {
//     // If all items have been considered, update best profit and return
//     if (i > n)
//     {
//         bestp = cp;
//         return;
//     }
//     // If the current item can be included, include it and recursively call knapsack for the next item
//     if (cw + w[i] <= c)
//     {
//         cw += w[i];
//         cp += p[i];
//         knapsack(i + 1);
//         cw -= w[i];
//         cp -= p[i];
//     }
//     // If the upper bound of the next level is higher than the best profit, recursively call knapsack for the next item
//     if (bound(i + 1) > bestp)
//     {
//         knapsack(i + 1);
//     }
// }

// // Calculate upper bound for the knapsack problem
// float bound(int i)
// {
//     int cleft = c - cw;
//     int b = cp;
//     while (i <= n && w[i] <= cleft)
//     {
//         cleft = cleft - w[i];
//         b += p[i];
//         i++;
//     }
//     if (i <= n)
//     {
//         b += p[i] / w[i] * cleft;
//     }
//     return b;
// }

// // The main function to solve the knapsack problem
// int knapsack(int *profit, int *weight, int num_items, int capacity)
// {
//     // Initialize knapsack object and set member variables
//     knap k;
//     k.n = num_items;
//     k.c = capacity;
//     k.w = weight;
//     k.p = profit;
//     k.cw = 0;
//     k.cp = 0;
//     k.bestp = 0;

//     // Call the recursive function to solve the knapsack problem
//     k.knapsack(1);

//     // Return the best profit
//     return k.bestp;
// }
