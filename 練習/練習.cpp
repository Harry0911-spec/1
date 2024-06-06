//c039
#include <iostream>
using namespace std;
int main(void) {
	int n, i, j, M, m, cycle, t;
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> i >> j) {
		M = max(i, j);
		m = min(i, j);
		cycle = 0;
		for (int k = m; k <= M; k++) {
			n = k;
			t = 0;
			while (1) {
				t++;
				if (n == 1) break;
				if (n % 2) n = 3 * n + 1;
				else n = n / 2;
			}
			cycle = max(cycle, t);
		}
		cout << i << " " << j << " " << cycle << '\n';
	}
	return 0;
}

































//c007
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s0;
	bool flag = true;

	ios::sync_with_stdio(0);
	cin.tie(0);
	while (getline(cin, s0)) {
		for (auto c : s0) {
			if (c == '"') {
				cout << (flag ? "``" : "''");
				flag = !flag;
			}
			else {
				cout << c;
			}
		}
		cout << '\n';
	}
	return 0;
}



































//c054
#include <iostream>
using namespace std;

string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int main(void) {
	char c;
	int i;

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin.get(c)) {
		for (i = 1;i < s.length() && s[i] != c;i++);
		if (i < s.length()) {
			cout << s[i - 1];
		}
		else {
			cout << c;
		}
	}
	return 0;
}
































































//e.543
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string rev("A   3  HILM O   2TUVWXY51SE Z  8 ");
char mirrored(char ch);

int main(void) {
	string s;
	int p, m;
	int i;

	string meg[4] = { " not a palindrome","a regular palidrome","a mirrored string","a mirrored palidrome" };

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> s) {
		p = m = 1;

		string s0 = s;
		reverse(s0.begin(), s0.end());
		if (s0 != s) p = 0;

		for (i = 0;i < s.length() / 2;i++) {
			if (m && mirrored(s[i]) != s[(s.length() - 1 - i)]) {
				m = 0;
			}
		}
		cout << s << " is" << meg[m * 2 + p] << ".\n\n";
	}
	return 0;
}

char mirrored(char ch) {
	if (isalpha(ch)) {
		return rev[ch - 'A'];
	}
	else {
		return rev[ch - '0' + 25];
	}
}








































//d.132
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n, kase = 0, i, a[1000], b[1000], A, B, d, c1, c2, m;
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> n) {
		if (!n) break;
		cout << "Game " << ++kase << ":\n";

		for (i = 0; i < n; i++) {
			cin >> a[i];
		}
		while (1) {
			A = B = 0;
			for (i = 0; i < n; i++) {
				cin >> b[i];
				if (a[i] == b[i]) A++;
			}
			m = 0;
			for (i = 0; i < n; i++) {
				if (b[i] == 0) m++;
			}
			if (m == n) break;
			for (d = 1; d <= 9; d++) {
				c1 = c2 = 0;
				for (i = 0; i < n; i++) {
					if (a[i] == d) c1++;
					if (b[i] == d) c2++;
				}
				B += min(c1, c2);
			}
			cout << "    " << '(' << A << ',' << B - A << ')' << '\n';
		}
	}
	return 0;
}
