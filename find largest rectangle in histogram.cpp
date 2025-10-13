/*
 * Largest Rectangle in Histogram
 * 
 * This program finds the area of the largest rectangle that can be formed within a histogram.
 * It uses a creative 2D matrix approach where the histogram is visualized as a binary matrix,
 * then systematically explores all possible rectangles to find the maximum area. The algorithm
 * converts histogram heights into a 2D representation and checks for continuous rectangular
 * regions. Input consists of histogram size followed by height values. Output displays the
 * maximum rectangular area that can be formed within the histogram bars.
 */

// You are using GCC
#include <iostream>
using namespace std;
int main() {
    int size;
    cin>>size;
    int temparr[size];
    int max = 0;
    for (int i = 0 ; i < size ; i ++) {
        cin>>temparr[i];
        if (temparr[i]>max) {
            max = temparr[i];
        }
    }
    int arr[size][max];
    for (int i = 0 ; i < size ; i ++) {
        for (int j = 0 ; j < max ; j ++) {
            if ((j+1)<=temparr[i]) {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }
    int maxArea = 0;
    int currentArea = 0;
    int maxCol;
    for (int k = 0 ; k < size-1 ; k ++) {
        for (int j = 0 ; j < max ; j ++) {
            maxCol = 0;
            for (int i = k ; i < size; i ++) {
                if (arr[i][j] == 0) {
                    break;
                }
                maxCol = i;
            }
            currentArea = (maxCol+1-k)*(j+1);
            if ((currentArea)>maxArea) {
                maxArea = currentArea;
            }
            //cout<<"The area is "<<currentArea<<" till "<<maxCol<<","<<j<<endl;
        }
    }
    cout<<maxArea;
}