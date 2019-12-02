#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find(vector<int> list, int noun, int verb) {
	list[1] = noun;
	list[2] = verb;
	for (int i = 0; i < list.size(); i += 4) {
		int posA = list[i + 1];
		int posB = list[i + 2];
		int posC = list[i + 3];
		if (list[i] == 99) {
			return -1;
		} else if (list[i] == 1) {
			list[posC] = list[posA] + list[posB];
		} else if (list[i] == 2) {
			list[posC] = list[posA] * list[posB];
		}
		if (list[posC] == 19690720) {
			return 100 * noun + verb;
		}
	}
	return -1;
}

int main() {
	vector<int> list;
	int n;
	while (scanf("%d,", &n) != EOF) {
		list.push_back(n);
	}
	for (int noun = 0; noun <= 99; noun++) {
		for (int verb = 0; verb <= 99; verb++) {
			int result = find (list, noun, verb);
			if (result != -1) {
				cout << result;
				break;
			}
		}
	}
	return 0;
}
