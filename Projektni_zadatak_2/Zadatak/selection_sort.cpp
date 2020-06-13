#include <iostream>
#include "selection_sort.h"
using namespace std;

int selection_sort(vector<Pokemon> data, int n) {
	int brojac = 0;
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (data[j].set_Name() > data[min_index].set_Name()) {
				min_index = j;
			}
		}

		swap(data[min_index], data[i]);
		brojac++;
	}
	return brojac;
}