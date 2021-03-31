using namespace std;
#include <iomanip>
#include <iostream>
#include<string>
int main() {
	string deal, last, alpha[10] = { "zero","one","two","three","four","five","six","seven","eight","nine" };
	cin >> deal;
	int sum = 0;
	for (auto i : deal) {
		sum += i - '0';
	}
	last = to_string(sum);
	for (int i = 0; i < last.size();i++) {
		cout << alpha[last[i] - '0'];
		if (i != last.size() - 1)cout << " ";
	}
	return 0;
}