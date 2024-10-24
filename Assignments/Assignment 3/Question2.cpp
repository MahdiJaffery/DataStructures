#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define line "\n\n"
#define space "\t"

using namespace std;

int getMaxDigits(const vector<int> &arr)
{
    int maxValue = *max_element(arr.begin(), arr.end());
    int digits = 0;
    while (maxValue > 0)
    {
        maxValue /= 10;
        digits++;
    }
    return digits;
}

void sortPosNum(vector<int> &arr)
{
    int n = arr.size();
    int maxDigits = getMaxDigits(arr);
    vector<queue<int>> Buckets(10);
    int placeValue = 1;

    for (int d = 0; d < maxDigits; d++)
    {
        for (int i = 0; i < n; i++)
        {
            int digit = (arr[i] / placeValue) % 10;
            Buckets[digit].push(arr[i]);
        }
        int index = 0;
        for (int i = 0; i < 10; i++)
        {
            while (!Buckets[i].empty())
            {
                arr[index++] = Buckets[i].front();
                Buckets[i].pop();
            }
        }
        placeValue *= 10;
    }
}

void sortNegNum(vector<int> &arr)
{
    int n = arr.size();
    int maxDigits = getMaxDigits(arr);
    vector<queue<int>> Buckets(10);
    int placeValue = 1;

    for (int d = 0; d < maxDigits; d++)
    {
        for (int i = 0; i < n; i++)
        {
            int digit = abs((arr[i] / placeValue) % 10);
            Buckets[digit].push(arr[i]);
        }
        int index = 0;
        for (int i = 0; i < 10; i++)
        {
            while (!Buckets[i].empty())
            {
                arr[index++] = Buckets[i].front();
                Buckets[i].pop();
            }
        }
        placeValue *= 10;
    }

    reverse(arr.begin(), arr.end());
}

void intSortFunc(vector<int> &arr)
{
    vector<int> posArr, negArr;

    for (int num : arr)
    {
        if (num >= 0)
            posArr.push_back(num);
        else
            negArr.push_back(num);
    }

    sortPosNum(posArr);
    sortNegNum(negArr);

    arr.clear();
    arr.insert(arr.end(), negArr.begin(), negArr.end());
    arr.insert(arr.end(), posArr.begin(), posArr.end());
}

void strSortFunc(vector<string> &arr, int maxLen)
{
    int n = arr.size();
    vector<queue<string>> Buckets(256);

    for (int pos = maxLen - 1; pos >= 0; pos--)
    {
        for (int i = 0; i < n; i++)
        {
            char ch = (pos < arr[i].length()) ? arr[i][pos] : 0;
            Buckets[ch].push(arr[i]);
        }
        int index = 0;
        for (int i = 0; i < 256; i++)
        {
            while (!Buckets[i].empty())
            {
                arr[index++] = Buckets[i].front();
                Buckets[i].pop();
            }
        }
    }
}

int main()
{
    vector<int> myArr = {32, -4, 67, 39, -436, 720, -355};
    intSortFunc(myArr);

    cout << "Sorted integer array:\t";
    for (int num : myArr)
        cout << num << space;
    cout << line;

    vector<string> myStrings = {"abc", "xyz", "def", "ghij", "kl", "mno"};
    int maxLen = 0;
    for (const string &str : myStrings)
        maxLen = max(maxLen, (int)str.length());
    strSortFunc(myStrings, maxLen);

    cout << "Sorted string array:\t";
    for (const string &str : myStrings)
        cout << str << space;
    cout << line;

    return 0;
}
