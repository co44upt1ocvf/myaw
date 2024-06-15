#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class MergeSort {
public:
    void Sort(vector<int>& arr) {
        if (arr.size() <= 1)
            return;

        int mid = arr.size() / 2;
        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());

        Sort(left);
        Sort(right);

        Merge(arr, left, right);
    }

private:
    void Merge(vector<int>& arr, vector<int>& left, vector<int>& right) {
        int i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }

        while (i < left.size())
            arr[k++] = left[i++];

        while (j < right.size())
            arr[k++] = right[j++];
    }
};

int main() {
    system("chcp 65001");
    vector<int> arr(10);

    cout << "Вводи 10 чисел для массива БЫСТРО >:( :";
    for (int i = 0; i < 10; i++)
        cin >> arr[i];

    MergeSort mergeSort;
    auto sortFunction = [&]() { mergeSort.Sort(arr); };
    thread mergeSortThread(sortFunction);

    mergeSortThread.join();

    cout << "Сортированные числа: ";
    for (int i = 0; i < 10; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}