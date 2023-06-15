#include <bits/stdc++.h> // includes all library but can slow code drastically
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// ------------------------------------------------------------------------------------------------------------

void prime(int a)
{

    int prime[50] = {0};

    for (int i = 2; i <= pow(a, 0.5); i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= a; j = j + i)
            {
                prime[j] = 1;
            }
        }
    }

    for (int i = 2; i <= a; i++)
    {
        if (prime[i] == 0)
        {
            cout << i << ' ';
        }
    }
}

// --------------------------------------------------------------------------------------------------------------

void string_permutation(string s, string ans)
{

    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        string_permutation(ros, ans + ch);
    }
}

// --------------------------------------------------------------------------------------------------------------

bool isSafe_ratMaze(int **arr, int x, int y, int size)
{
    if (x < size && y < size && arr[x][y] == 1)
    {
        return true;
    }
    return false;
}

bool ratMaze(int **arr, int x, int y, int size, int **solArr)
{
    if (x == size - 1 && y == size - 1)
    {
        solArr[x][y] = 1;
        return true;
    }

    if (isSafe_ratMaze(arr, x, y, size))
    {
        solArr[x][y] = 1;

        if (ratMaze(arr, x + 1, y, size, solArr))
        {
            return true;
        }
        if (ratMaze(arr, x, y + 1, size, solArr))
        {
            return true;
        }

        solArr[x][y] = 0;
        return false;
    }

    return false;
}

// --------------------------------------------------------------------------------------------------------------

bool isSafe_queenMaze(int **arr, int x, int y, int size)
{

    for (int row = 0; row < size; row = row + 1)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }

    int row = x;
    int col = y;

    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row = row - 1;
        col = col - 1;
    }

    row = x;
    col = y;

    while (row >= 0 && col < size)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row = row - 1;
        col = col + 1;
    }
    return true;
}

bool queenMaze(int **arr, int x, int size)
{
    if (x >= size)
    {
        return true;
    }

    for (int col = 0; col < size; col = col + 1)
    {
        if (isSafe_queenMaze(arr, x, col, size))
        {
            arr[x][col] = 1;

            if (queenMaze(arr, x + 1, size))
            {
                return true;
            }

            arr[x][col] = 0;
        }
    }
    return false;
}

// --------------------------------------------------------------------------------------------------------------

void bubbleSort(int arr[], int n, int position)
{
    if (position == n - 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        return;
    }

    if (arr[position] > arr[position + 1])
    {
        int temp = arr[position];
        arr[position] = arr[position + 1];
        arr[position + 1] = temp;

        return bubbleSort(arr, n, 0);
    }
    return bubbleSort(arr, n, position + 1);
}

// --------------------------------------------------------------------------------------------------------------

void merge_(int arr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i = i + 1)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i = i + 1)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i = i + 1;
        }
        else
        {
            arr[k] = b[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i < n1)
    {
        arr[k] = a[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        j = j + 1;
        k = k + 1;
    }
    return;
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge_(arr, l, mid, r);
    }
    return;
}

// --------------------------------------------------------------------------------------------------------------

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    return;
}

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; j = j + 1)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, r);
    return i + 1;
}

void quicksort(int arr[], int l, int r)
{
    if (l < r)
    {
        int pivot = partition(arr, l, r);

        quicksort(arr, l, pivot - 1);
        quicksort(arr, pivot + 1, r);
    }
    return;
}

// --------------------------------------------------------------------------------------------------------------

int get_Bit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

// --------------------------------------------------------------------------------------------------------------

int set_Bit(int n, int pos)
{
    return (n | (1 << pos));
}

// --------------------------------------------------------------------------------------------------------------

int clear_Bit(int n, int pos)
{
    int mask = ~(1 << pos);
    return (n & mask);
}

// --------------------------------------------------------------------------------------------------------------

int update_Bit(int n, int pos, int value)
{

    return (clear_Bit(n, pos) | (value << pos));
}

// --------------------------------------------------------------------------------------------------------------

void subsets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i = i + 1)
    {
        for (int j = 0; j < n; j = j + 1)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
    return;
}

// --------------------------------------------------------------------------------------------------------------

void unique(int arr[], int n)
{
    int XOR_sum = 0;
    for (int i = 0; i < n; i = i + 1)
    {
        XOR_sum = XOR_sum ^ arr[i];
    }
    int tempxor = XOR_sum;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1)
    {
        setbit = XOR_sum & 1;
        pos = pos + 1;
        XOR_sum = XOR_sum >> 1;
    }
    int newxor = 0;
    for (int i = 0; i < n; i = i + 1)
    {
        if (get_Bit(arr[i], pos - 1) == 1)
        {
            newxor = newxor ^ arr[i];
        }
    }

    cout << newxor << endl;
    cout << (tempxor ^ newxor) << endl;
    return;
}

// --------------------------------------------------------------------------------------------------------------

void maxSubarraySum(int arr[], int n)
{
    int sum = 0;
    int Max_sum = INT_MIN;
    for (int i = 0; i < n; i = i + 1)
    {
        if (arr[i] >= 0)
        {
            sum = sum + arr[i];
            Max_sum = max(Max_sum, sum);
        }
        else
        {
            sum = 0;
        }
    }
    cout << Max_sum;
    return;
}

// --------------------------------------------------------------------------------------------------------------

void helper(vector<int> a, vector<vector<int>> &ans, int idx)
{
    if (idx == a.size())
    {
        ans.push_back(a);
        return;
    }
    for (int i = idx; i < a.size(); i = i + 1)
    {
        if (i != idx && a[i] == a[idx])
        {
            continue;
        }
        swap(a[i], a[idx]);
        helper(a, ans, idx + 1);
    }
}
void permutation(vector<int> a)
{
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    helper(a, ans, 0);

    for (auto v : ans)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return;
}

// --------------------------------------------------------------------------------------------------------------

void Count_sort(int arr[], int n)
{
    int k = arr[0];

    for (int i = 0; i < n; i = i + 1)
    {
        k = max(k, arr[i]);
    }

    int count[100];

    for (int i = 0; i < n; i = i + 1)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }

    for (int i = 1; i <= k; i = i + 1)
    {
        count[i] = count[i] + count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i = i - 1)
    {
        count[arr[i]] = count[arr[i]] - 1;
        output[count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << output[i] << " ";
    }
    return;
}

// --------------------------------------------------------------------------------------------------------------

void dnf_sort(int arr[], int n) // can sort any three consecutive numbers in an array
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == -1)
        {
            swap(arr, low, mid);
            low = low + 1;
            mid = mid + 1;
        }
        else if (arr[mid] == 0)
        {
            mid = mid + 1;
        }
        else
        {
            swap(arr, mid, high);
            high = high - 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return;
}

// --------------------------------------------------------------------------------------------------------------

void wave_sort(int arr[], int n)
{
    for (int i = 0; i < n; i = i + 1)
    {
        if (arr[i] > arr[i - 1])
        {
            swap(arr, i, i - 1);
        }

        if (arr[i] > arr[i + 1] && i <= n - 2)
        {
            swap(arr, i, i + 1);
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return;
}

// --------------------------------------------------------------------------------------------------------------

long long inv_merge_(int arr[], int l, int mid, int r)
{
    long long inv = 0; // new
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int a[n1], b[n2];

    for (int i = 0; i < n1; i = i + 1)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i = i + 1)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i = i + 1;
        }
        else
        {
            arr[k] = b[j];
            j = j + 1;

            inv = inv + n1 - i; // a[i] > b[j] and i < j
        }
        k = k + 1;
    }

    while (i < n1)
    {
        arr[k] = a[i];
        i = i + 1;
        k = k + 1;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        j = j + 1;
        k = k + 1;
    }

    return inv;
}

long long inv_merge_sort(int arr[], int l, int r)
{
    long long inv = 0; // new
    if (l < r)
    {
        int mid = (l + r) / 2;
        inv = inv + inv_merge_sort(arr, l, mid);     // new
        inv = inv + inv_merge_sort(arr, mid + 1, r); // new
        inv = inv + inv_merge_(arr, l, mid, r);      // new
    }
    return inv;
}

//------------------------------------------------------------------------------------------------------------------

bool three_sum_prob(vector<int> a, int n, int x)
{

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i = i + 1)
    {
        int low = i + 1, high = n - 1;
        while (low < high)
        {
            int current = a[i] + a[low] + a[high];
            if (current == x)
            {
                cout << "pair: " << a[i] << " " << a[low] << " " << a[high];
                return true;
            }
            else if (current < x)
            {
                low = low + 1;
            }
            else
            {
                high = high - 1;
            }
        }
    }

    cout << " no such pair";
    return false;
}

//------------------------------------------------------------------------------------------------------------------

void max_consecutive_ones(vector<int> a, int k)
{
    int zero_count = 0;
    int i = 0;
    int ans = 0;

    for (int j = 0; j < a.size(); j = j + 1)
    {
        if (a[j] == 0)
        {
            zero_count = zero_count + 1;
        }
        while (zero_count > k)
        {
            if (a[i] == 0)
            {
                zero_count = zero_count - 1;
            }
            i = i + 1;
        }
        ans = max(ans, j - i + 1);
    }
    cout << ans;
    return;
}

//------------------------------------------------------------------------------------------------------------------

void longest_substring_without_repetition(string s)
{
    vector<int> dict(256, -1);
    int max_length = 0;
    int start = -1;

    for (int i = 0; i < s.size(); i = i + 1)
    {
        if (dict[s[i]] > start)
        {
            start = dict[s[i]];
        }
        dict[s[i]] = i;
        max_length = max(max_length, i - start);
    }
    cout << max_length;
    return;
}

//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------

int main()
{
    //  prime numbers till n-----------------------------------------------------------

    /*  int n;
        cin >> n;
        prime(n); */

    // string permutations-----------------------------------------------------------

    /*  string s;
        cin >> s;
        string_permutation(s, "");
        return 0; */

    // rat maze backtracking----------------------------------------------------------

    /* int size;
    cin >> size;

    int **arr = new int *[size];
    for (int i = 0; i < size; i = i + 1)
    {
        arr[i] = new int[size];
        for (int j = 0; j < size; j = j + 1)
        {
            cin >> arr[i][j];
        }
    }

    cout << endl;

    int **solArr = new int *[size];
    for (int i = 0; i < size; i = i + 1)
    {
        solArr[i] = new int[size];
        for (int j = 0; j < size; j = j + 1)
        {
            solArr[i][j] = {0};
        }
    }

    if (ratMaze(arr, 0, 0, size, solArr))
    {
        for (int i = 0; i < size; i = i + 1)
        {
            for (int j = 0; j < size; j = j + 1)
            {
                cout << solArr[i][j] << " ";
            }
            cout << endl;
        }
    } */

    // queenMaze---------------------------------------------------------------

    /*  int size;
     cin >> size;

     if (size < 4)
     {
         cout << "No possible combination";
     }

     int **arr = new int *[size];
     for (int i = 0; i < size; i = i + 1)
     {
         arr[i] = new int[size];
         for (int j = 0; j < size; j = j + 1)
         {
             arr[i][j] = 0;
         }
     }

     if (queenMaze(arr, 0, size))
     {
         for (int i = 0; i < size; i = i + 1)
         {
             for (int j = 0; j < size; j = j + 1)
             {
                 cout << arr[i][j] << " ";
             }
             cout << endl;
         }
     } */

    // bubble sort------------------------------------------------------------------
    /*  int n;
     cin >> n;

     if (n < 0)
     {
         cout << "Error! Number of inputs can't be less than 0" << endl;
         return -1;
     }

     int *arr = new int[n];

     for (int i = 0; i < n; i = i + 1)
     {
         cin >> arr[i];
     }

     bubbleSort(arr, n, 0);

     delete[] arr; */

    // merge_sort----------------------------------------------------------------------
    /* int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i = i + 1)
    {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i = i + 1)
    {
        cout << arr[i] << " ";
    }
    cout << endl; */

    // quick sort----------------------------------------------------------
    /* int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i = i + 1)
    {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    for (int i = 0; i < n; i = i + 1)
    {
        cout << arr[i] << " ";
    }
    cout << endl; */

    // bit-------------------------------------------------------------------
    /*     int n, pos, value;
        cin >> n >> pos >> value;
        cout << get_Bit(n, pos) << " " << set_Bit(n, pos) << " " << clear_Bit(n, pos) << " " << update_Bit(n, pos, value) << endl; */

    // subset------------------------------------------------------------------
    /*  int n;
     cin >> n;
     int arr[n];
     for (int i = 0; i < n; i = i + 1)
     {
         cin >> arr[i];
     }
     subsets(arr, n); */

    // unique in array----------------------------------------------------------
    /*  int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i = i + 1)
        {
            cin >> arr[i];
        }
        unique(arr, 6); */

    // permutation combination------------------------------------------------------------------
    /*  int n;
      cin >> n;

      vector<int> a(n);
      for (auto &i : a)
      {
          cin >> i;
      }
      permutation(a); */

    // count sort and dnf sort
    /*   int arr[] = {-1, 1, 0, 0, 1, -1, -1, 0, 1, -1};

       dnf_sort(arr, 10); */

    // sum of 3 elements in array equal to target

    string s;
    cin >> s;

    longest_substring_without_repetition(s);
    return 0;
}