#include <bits/stdc++.h>
#define lli long long int
#define li long int
#define ld long double
using namespace std;
 
int main()
{
	lli n, total=0, ans=INT_MAX;
	cin >> n;
	li arr[n];
	for(lli i = 0; i < n; i++) 
    {
		cin >> arr[i];
		total += arr[i];
	}

	for(lli i = 0; i < 1<<n; i++) //所有可能子集2^n
    {
		lli s = 0;//sum
		for(lli j = 0; j < n; j++) 
        {
			if(i & 1<<j) s += arr[j];
		}

		lli curr = abs((total-s)-s);
		ans = min(ans, curr);
	}
	cout << ans;
	return 0;
}
//recur
// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// typedef long long int lli;

// // 递归函数来找出差值的最小绝对值
// lli findMinRec(vector<lli>& arr, lli i, lli sumCalculated, lli sumTotal) {
//     // 如果我们已经考虑了所有元素，则返回最终的差值的绝对值
//     if (i == 0) return abs((sumTotal - sumCalculated) - sumCalculated);

//     // 对于第i个元素，我们有两个选择：
//     // 1. 我们可以包含第i个元素在当前子集中
//     // 2. 我们不包括第i个元素在当前子集中
//     return min(findMinRec(arr, i - 1, sumCalculated + arr[i - 1], sumTotal),
//                findMinRec(arr, i - 1, sumCalculated, sumTotal));
// }

// // 返回差值的最小绝对值
// lli findMin(vector<lli>& arr, lli n) {
//     lli sumTotal = 0;
//     for (lli i = 0; i < n; i++) sumTotal += arr[i];

//     return findMinRec(arr, n, 0, sumTotal);
// }

// int main() {
//     lli n;
//     cin >> n;
//     vector<lli> arr(n);
//     for (lli i = 0; i < n; i++) cin >> arr[i];

//     cout << findMin(arr, n);
//     return 0;
// }
