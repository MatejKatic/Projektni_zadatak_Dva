#include <iostream>
#include "insertion_sort.h"
using namespace std;

int insertion_sort(vector<Pokemon> data, int n) {
	int brojac = 0;
	for (int i = 1; i < n; i++) { // Prvog preskaèemo.
		for (int j = i; j > 0; j--) {
			if (data[j - 1].set_Name() > data[j].set_Name()) {
				swap(data[j], data[j - 1]);
				brojac++;
			}
		}
	}
	return brojac;
}