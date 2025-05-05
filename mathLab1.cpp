#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <cctype>

using namespace std;
#define N 4


bool contains(const vector<string>& v, const string& s) {
    for (const auto& elem : v) {
        if (elem == s) {
            return true;
        }
    }
    return false;
}

void my_sort(vector<string>& v) {
    for (int i = 0; i < v.size(); i++) {
        int min_index = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[j] < v[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(v[i], v[min_index]);
        }
    }
}

vector<string> my_set_union(const vector<string>& A, const vector<string>& B) {
    vector<string> result;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
        }
        else if (B[j] < A[i]) {
            result.push_back(B[j]);
            j++;
        }
        else {
            result.push_back(A[i]);
            i++;
            j++;
        }
    }
    while (i < A.size()) {
        result.push_back(A[i]);
        i++;
    }
    while (j < B.size()) {
        result.push_back(B[j]);
        j++;
    }
    return result;
}

vector<string> my_set_intersection(const vector<string>& A, const vector<string>& B) {
    vector<string> result;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            i++;
        }
        else if (B[j] < A[i]) {
            j++;
        }
        else {
            result.push_back(A[i]);
            i++;
            j++;
        }
    }
    return result;
}

vector<string> my_set_difference(const vector<string>& A, const vector<string>& B) {
    vector<string> result;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
        }
        else if (B[j] < A[i]) {
            j++;
        }
        else {
            i++;
            j++;
        }
    }
    while(i < A.size()){
        result.push_back(A[i]);
        i++;
    }
    return result;
}

vector<string> my_set_symmetric_difference(const vector<string>& A, const vector<string>& B) {
    vector<string> result;
    int i = 0, j = 0;
    while(i < A.size() && j < B.size()){
        if(A[i] < B[j]){
            result.push_back(A[i]);
            i++;
        }
        else if(B[j] < A[i]){
            result.push_back(B[j]);
            j++;
        }
        else { 
            i++; 
            j++; 
        }
    }
    while(i < A.size()){
        result.push_back(A[i]);
        i++;
    }
    while(j < B.size()){
        result.push_back(B[j]);
        j++;
    }
    return result;
}

bool valid_element(const string& s) {
    if (s.size() != N) {
        cout << "Некорректное количество символов(" << s.size() <<"). Необходимо " << N << " символов." << endl;
        return false;
    }
    if (!isalpha(s[0])) {
        cout << "Первый символ не является буквой." << endl;
        return false;
    } 
    if (!isdigit(s[1]) || ((s[1] - '0') % 2 == 0)) {
        cout << "Второй символ не является нечетным числом." << endl;
        return false;
    }
    if (!isdigit(s[2])) {
        cout << "Третий символ не является числом." << endl;
        return false;
    }
    if (!isdigit(s[3]) || ((s[3] - '0') % 2 != 0)) {
        cout << "Четвертый символ не является четным числом." << endl;
        return false;
    }
    return true;
}

void printSet(const vector<string>& s) {
    for (const auto& elem : s) {
        cout << elem << " ";
    }
    cout << endl;
}

signed main() {
    vector<string> setA, setB;
    string element;
    bool valid = false;
    int n;

    cout << "Введите количество элементов в множествах: ";
    cin >> n;

    int nA = n, nB = n;
    
    cout << "Введите элементы множества A: ";
    for (int i = 0; i < nA; i++) {
        cin >> element;
        if (valid_element(element)) {
            if (!contains(setA, element)){
                setA.push_back(element);
            }
        } else {
            cout << "Попробуйте заново: ";
            nA++;
        }
    }
    
    cout << "Введите элементы множества B: ";
    valid = false;
    for (int i = 0; i < nB; i++){
        cin >> element;
        if (valid_element(element)) {
            if (!contains(setB, element)){
                setB.push_back(element);
            }
        } else {
            cout << "Попробуйте заново: ";
            nB++;
        }
    }
    
    my_sort(setA);
    my_sort(setB);
    
    vector<string> unionSet = my_set_union(setA, setB);
    vector<string> intersectionSet = my_set_intersection(setA, setB);
    vector<string> differenceSetA = my_set_difference(setA, setB);
    vector<string> differenceSetB = my_set_difference(setB, setA);
    vector<string> symmetricDifferenceSet = my_set_symmetric_difference(setA, setB);
    
    cout << "Множество A: ";
    printSet(setA);

    cout << "Множество B: ";
    printSet(setB);

    cout << "Объединение: ";
    printSet(unionSet);
    
    cout << "Пересечение: ";
    printSet(intersectionSet);
    
    cout << "Дополнение A \\ B: ";
    printSet(differenceSetA);
    
    cout << "Дополнение B \\ A: ";
    printSet(differenceSetB);
    
    cout << "Симметрическая разность: ";
    printSet(symmetricDifferenceSet);
    
    return 0;
}
