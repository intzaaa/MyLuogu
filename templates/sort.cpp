#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define _ vector<int>

const _ select_sort(_ vec)
{
    for (int i = 0; i < vec.size(); i++)
        swap(vec[i], *min_element(vec.begin() + i, vec.end()));

    return vec;
}

const _ bubble_sort(_ vec)
{
    for (int i = 0; i < vec.size() - 1; i++)
        for (int j = 0; j < vec.size() - 1 - i; j++)
            if (vec[j + 1] < vec[j])
                swap(vec[j + 1], vec[j]);

    return vec;
}

const _ insert_sort(_ vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }

    return vec;
}

void quick_sort(_ &vec, int left, int right)
{
    if (left >= right)
        return;

    const auto _left = left,
               _right = right--;

    auto &pivot = vec[_right];

    while (left <= right)
    {
        while (left <= right && vec[left] <= pivot)
            left++;
        while (left <= right && vec[right] >= pivot)
            right--;

        if (left < right)
            swap(vec[left], vec[right]);
    }

    swap(vec[left], pivot);

    quick_sort(vec, _left, left - 1);
    quick_sort(vec, left + 1, _right);
}

const _ quick_sort(_ vec)
{
    quick_sort(vec, 0, vec.size() - 1);

    return vec;
}

const _ merge(const _ &left, const _ &right) {
    int i = 0, j = 0;
    _ merged;
    
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            merged.push_back(left[i]);
            i++;
        } else {
            merged.push_back(right[j]);
            j++;
        }
    }

    while (i < left.size()) {
        merged.push_back(left[i]);
        i++;
    }
    while (j < right.size()) {
        merged.push_back(right[j]);
        j++;
    }

    return merged;
}

const _ merge_sort(_ vec) {
    if (vec.size() <= 1) return vec;
    
    int mid = vec.size() / 2;
    _ left(vec.begin(), vec.begin() + mid);
    _ right(vec.begin() + mid, vec.end());
    
    left = merge_sort(left);
    right = merge_sort(right);
    
    return merge(left, right);
}

const _ count_sort(_ vec)
{
    const auto _min = *min_element(vec.begin(), vec.end());
    const auto range = *max_element(vec.begin(), vec.end()) - _min + 1;

    _ vs(range, 0);
    for (const auto &n : vec)
        vs[n - _min]++;

    for (int i = 0, j = 0; i < vs.size(); i++)
        while (vs[i]-- > 0)
            vec[j++] = i + _min;

    return vec;
}

const string vector_to_string(const _ &vec)
{
    stringstream ss;
    for (int i = 0; i < vec.size(); i++)
    {
        ss << vec[i];

        if (&vec[i] != &vec.back())
            ss << ' ';
    }

    return ss.str();
}

void test(const _ &vec, const string &answer)
{
    const auto str = vector_to_string(vec);
    cout << str << ' ' << (str == answer ? '=' : '!') << endl;
}

int main(int argc, char *argv[])
{
    srand(unsigned(time(nullptr)));
    int n = stoi(argv[1]);
    _ sample;

    while (n-- > 0)
        sample.push_back(rand() % 100);

    cout << vector_to_string(sample) << endl
         << endl;
    const auto answer = vector_to_string(select_sort(sample));
    cout << answer << endl;

    test(bubble_sort(sample), answer);
    test(insert_sort(sample), answer);
    test(quick_sort(sample), answer);
    test(merge_sort(sample), answer);
    test(count_sort(sample), answer);
}
