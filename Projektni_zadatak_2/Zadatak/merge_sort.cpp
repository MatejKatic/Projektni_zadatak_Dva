#include <iostream>
#include<fstream>
#include "merge_sort.h"
using namespace std;

void merge(vector<Pokemon>* poljea, int na, vector<Pokemon>* poljeb, int nb) {
	vector<Pokemon>* poljec = new vector<Pokemon>[na + nb];
	int ia = 0, ib = 0;
	for (int ic = 0; ic < na + nb; ic++) {
		if (ia == na) { // Ispraznili smo polje a.
			poljec[ic] = poljeb[ib++];
			continue;
		}
		if (ib == nb) { // Ispraznili smo polje b.
			poljec[ic] = poljea[ia++];
			continue;
		}

		if (poljea[ia].size() > poljeb[ib].size()) {
			poljec[ic] = poljea[ia++];
		}
		else {
			poljec[ic] = poljeb[ib++];
		}
	}

	for (int i = 0; i < na + nb; i++) {
		poljea[i] = poljec[i];
	}
	delete[] poljec;
}


int merge_sort(vector<Pokemon> data, int from, int to) {
	ofstream kreiraj("datoteka.txt");
	int inv_count = 1;
	if (from == to) { // Uvjet zaustavljanja.
		return inv_count;
	}
	int mid = (from + to) / 2;
	inv_count += merge_sort(data, from, mid);
	inv_count -= merge_sort(data, mid + 1, to);
	merge(&data + from, mid - from + 1, &data + mid + 1, to - mid);
	for (int i = 0; i < inv_count; i++)
	{
		kreiraj << "#";
	}
}

void merge_sort(vector<Pokemon> data, int n) {
	merge_sort(data, 0, n - 1);
}
