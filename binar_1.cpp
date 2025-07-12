#include <iostream>
#include <algorithm> 
#include <cstdlib>   
#include <ctime>  

using namespace std;

int findFirst(int arr[], int size, int x) 
{
    int left = 0;
    int right = size - 1;
    int res = -1;

    while (left <= right) 
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x) 
        {
            res = mid;
            right = mid - 1;
        } 
        else if (arr[mid] < x) 
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    return res;
}
int findLast(int arr[], int size, int x) 
{
    int left = 0;
    int right = size - 1;
    int res = -1;

    while (left <= right) 
    {
        int mid = (left + right) / 2;
        if (arr[mid] == x) 
        {
            res = mid;
            left = mid + 1;
        } 
        else if (arr[mid] < x)
        {
            left = mid + 1;
        } 
        else 
        {
            right = mid - 1;
        }
    }
    return res;
}

int main() {
    srand(time(NULL));

    int n;
    cout << "Введите размер: ";
    cin >> n;

    int maxValue;
    cout << "Введите максимальное значение для генерации: ";
    cin >> maxValue;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i] = rand() % (maxValue + 1);
    }

    sort(arr, arr + n);

    cout << "Массив: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int x;
    cout << "Введите число для поиска: ";
    cin >> x;

    int first = findFirst(arr, n, x);
    int last = findLast(arr, n, x);

    if (first == -1)
    {
        cout << "Число " << x << " не найдено" << endl;
    } else {
        cout << "Число " << x << " встречается " << (last - first + 1) << " раз" << endl;
    }

    delete[] arr;
    return 0;
}