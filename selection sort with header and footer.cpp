/*
 * Selection Sort for Date Sorting (Day, Month, Year)
 * 
 * This program sorts dates using selection sort algorithm based on chronological order.
 * It compares dates by year first, then month, then day to achieve proper chronological
 * sorting. The implementation handles three separate arrays for days, months, and years
 * and maintains synchronization during sorting operations. Input consists of number of
 * dates followed by day, month, and year for each date. Output displays dates in
 * chronological order (earliest first).
 */

//header
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int days[n];
    int months[n];
    int years[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &days[i], &months[i], &years[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        //middle code - copy from here
        for (int j = i + 1; j < n; j++) {
            // Compare years first
            if (years[j] < years[minIndex] ||
                (years[j] == years[minIndex] && months[j] < months[minIndex]) ||
                (years[j] == years[minIndex] && months[j] == months[minIndex] && days[j] < days[minIndex])) {
                minIndex = j;
            }
        }
        // Swap if needed
        if (minIndex != i) {
            int temp;

            temp = days[i];
            days[i] = days[minIndex];
            days[minIndex] = temp;
            
             temp = months[i];
            months[i] = months[minIndex];
            months[minIndex] = temp;
            //end copying
            //footer
                        temp = years[i];
            years[i] = years[minIndex];
            years[minIndex] = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", days[i], months[i], years[i]);
    }

    return 0;
}
