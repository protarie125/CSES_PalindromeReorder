#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

using Counter = map<char, int>;

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string line;
	cin >> line;

	const auto& n = line.length();
	auto counter = Counter{};
	for (int i = 0; i < n; ++i) {
		counter[line[i]] += 1;
	}

	auto oddCount = int{ 0 };
	for (const auto& [ch, ct] : counter) {
		if (1 == ct % 2) {
			oddCount += 1;
		}
	}

	if (2 <= oddCount) {
		cout << "NO SOLUTION\n";
		return 0;
	}

	if (1 == oddCount) {
		ostringstream oss{};

		auto oddChar = char{ 0 };
		auto putCt = int{ 0 };

		for (const auto& [ch, ct] : counter) {
			if (0 == ct % 2) {
				const auto& toPut = ct / 2;
				for (int i = 0; i < toPut; ++i) {
					oss << ch;
				}

				putCt += toPut;
			}
			else {
				oddChar = ch;
			}
		}

		const auto& oddPut = counter[oddChar];
		for (int i = 0; i < oddPut; ++i) {
			oss << oddChar;
		}
		putCt += oddPut;

		auto str = static_cast<string>(oss.str());
		cout << str;

		for (int i = putCt - 1 - oddPut; 0 <= i; --i) {
			cout << str[i];
		}

		return 0;
	}

	ostringstream oss{};
	auto putCt = int{ 0 };

	for (const auto& [ch, ct] : counter) {
		if (0 == ct % 2) {
			const auto& toPut = ct / 2;
			for (int i = 0; i < toPut; ++i) {
				oss << ch;
			}

			putCt += toPut;
		}
	}

	auto str = static_cast<string>(oss.str());
	cout << str;

	for (int i = putCt - 1; 0 <= i; --i) {
		cout << str[i];
	}

	return 0;
}