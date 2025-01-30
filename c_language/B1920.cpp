#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void is_exist(const vector<long>& A, long p) {
    int st = 0;
    int en = A.size() - 1;
    
    while(st <= en) {
        int mid = (st + en) / 2;
        if(A[mid] == p) {
            cout << 1 << "\n";
            return;
        }
        else if(A[mid] > p) {
            en = mid - 1;
        }
        else {
            st = mid + 1;
        }
    }
    cout << 0 << "\n";
}

int main() {
    int n, m;
    cin >> n;
    cin.ignore();  // 개행 문자 처리

    // 첫 번째 배열 A 입력
    string line;
    getline(cin, line);
    istringstream iss(line);
    vector<long> A(n);
    for(int i = 0; i < n; i++) {
        string input;
        iss >> input;
        A[i] = stol(input);
    }

    // A를 중복을 제거하고 정렬
    sort(A.begin(), A.end());
    auto last = unique(A.begin(), A.end());
    A.erase(last, A.end());

    // 두 번째 배열 B 입력
    cin >> m;
    cin.ignore();  // 개행 문자 처리
    getline(cin, line);
    istringstream iss2(line);
    vector<long> B(m);
    for(int i = 0; i < m; i++) {
        string input;
        iss2 >> input;
        B[i] = stol(input);
    }

    // B 배열의 각 원소에 대해 A 배열에서 존재 여부를 확인
    for(int i = 0; i < m; i++) {
        is_exist(A, B[i]);
    }

    return 0;
}