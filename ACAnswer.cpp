
#include "ACAnswer.h"

// 001-Yokan Party
// まず答えが0以上l以下であることが分かる
void Solution90_001()
{
	int n, k;
	long long l;

	cin >> n >> l >> k;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	// 最低でもk+1個以上の羊羹をx以上の長さにできるかどうか
	auto check = [&](long long x) -> bool {
		long long count = 0; // 羊羹ピースの個数
		long long pre = 0;   // 前回の切れ目

		for (int i = 0; i < n; i++) {
			if (a[i] - pre >= x) {
				count++;
				pre = a[i];
			}
		}

		if (l - pre >= x) count++;

		return count >= k + 1;
	};

	long long left = -1, right = l + 1;
	while (right - left > 1) {
		long long mid = (right + left) / 2;
		if (check(mid)) {
			left = mid;
		}
		else {
			right = mid;
		}
	}

	cout << left << endl;
}

// 002-Encyclopedia of Parentheses
void Solution90_002()
{
	int n;
	cin >> n;

	// ★カッコに整合性があるかどうかチェック
	auto isValid = [&](string s) -> bool {
		int score = 0; // －なら")"の方が多い、+なら整合なし、0ならOK

		for (auto c : s) {
			if (c == '(') score++;
			else if (c == ')') score--;

			if (score < 0) return false;
		}

		return score == 0;
	};

	// ビット全探索,bit全探索
	// "("か")"の2種類しかないから(0か1で表せるから)、都合よくビット全探索が使える
	for (int bit = 0; bit < (1 << n); ++bit) {
		string s = "";

		for (int i = n - 1; i >= 0; --i) {
			if (!(bit & (1 << i))) s += "("; // bitを2進数表記したときi番目のビットが0なら"("
			else s += ")";
		}

		if (isValid(s)) cout << s << endl;
	}
}

void Solution483A()
{
	int n;
	cin >> n;

	cout << (n + 1) / 2 << endl;
}

void Solution483B()
{
	int n, q;
	cin >> n >> q;

	vector<int> result;
	for (int i = 0; i < n; i++) result.push_back(i + 1);

	int k;
	for (int i = 0; i < q; i++) {
		cin >> k;
		reverse(result.begin(), result.begin() + k);
		for (int j = 0; j < k; j++) {
			result[j] *= -1;
		}
	}

	for (int i = 0; i < n; i++) cout << result[i] << endl;
}


