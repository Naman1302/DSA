#include<bits/stdc++.h>
using namespace std;

int partition3(vector<int> &a, int l, int r) {
//3 way partition
    int x = a[l]; 
    int j = l;
    int k = r;
    int i = l+1; 

    while (i <= k) {
        if (a[i] < x) {
          swap(a[i],a[j]);
          j++; 
          i++;
        }
        else if(a[i] > x) {
            swap(a[i],a[k]);
            k--;
        }
        else {
            i++;
        }
    }

    return j;
}

void randomized_quick_sort(vector<int> &a, int l, int r) {

    if (l >= r) {
        return;
    }

    int k = l + rand() % (r - l + 1); //random pivot
    swap(a[l], a[k]); //swapping with l to get the 3way partition sort started

    while (l < r) {//make calls one by one thus decreasing the recursion stack
        int m = partition3(a, l, r);
      //we will check which part is smaller and call for that as to avoid more time  
        if ((m-l) < (r-m)) {//if left array is small
            randomized_quick_sort(a, l, m - 1);
            l = m + 1; 
        }
        else {//if right part of array is small
            randomized_quick_sort(a, m + 1, r);
            r = m - 1;
        }
    }
}

int main() {
    int n; 
    std::cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }
    randomized_quick_sort(a, 0, a.size() - 1);
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << ' ';
    }
}
