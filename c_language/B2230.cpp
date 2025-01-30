#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int main(void)
{
    int n,m;
    std::cin >> n >> m; // 공백을 기준으로 입력받음
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin >> A[i]; //배열을 입력받음
    }
    sort(A,A+n); //오른차순으로 정렬
    int mingap = INT_MAX;
    for(int i=0;i<n;i++)
    {
        int en=i+1;
        while(en<n)
        {
            int min=A[en]-A[i];
            if(min<m) //m보다 작은 경우
            {
                en+=1;
            }
            else //차이가 m이상인 경우
            {
                mingap=std::min(mingap,min);
                break;
            }
        }
    }
    cout << mingap << "\n";
    return 0;
}