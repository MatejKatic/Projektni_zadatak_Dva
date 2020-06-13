#include <iostream>
#include "Pokemon.h"
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include "selection_sort.h"
#include <unordered_set>
#include "insertion_sort.h"
#include <chrono>
#include "merge_sort.h"
#include <ctime>
#include <map>
#include<queue>
#include <list>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using namespace std::chrono;

void ispis_na_ekranu()
{
	cout << "1 - Ispisi osnovne podatke o pokemnu " << endl
		<< "2 - Pretraga po ID" << endl
		<< "3 - Prikaz po snazi napada" << endl
		<< "4 - Kopiranje u novi vektor" << endl
		<< "5 - Prikaz po generacijama" << endl
		<< "6 - Selection vs Insertion" << endl
		<< "7 - Pogodi trajanje" << endl
		<< "8 - Lets Bogo!" << endl
		<< "9 - The Merge Dance" << endl
		<< "10 - Pretraga po Type 2" << endl
		<< "11 - Vizualiziraj" << endl
		<< "12 - Izrada stringa iz stringa" << endl;


}


void upis_Pokemona(Pokemon& p)
{
	cout << endl;
	cin.ignore();
	string Naziv;
	string Tip_1;
	string Tip_2;
	int total;
	cout << "Naziv: ";
	getline(cin, Naziv);
	p.get_Name(Naziv);
	cout << endl;
	cout << "Tip 1: ";
	getline(cin, Tip_1);
	p.get_Type_1(Tip_1);
	cout << endl;
	cout << "Tip 2: ";
	getline(cin, Tip_2);
	p.get_Type_2(Tip_2);
	cout << endl;
	cout << "Total: ";
	cin >> total;
	cin.ignore();
	p.get_Total(total);
	cout << endl;
	cout << p.ispis() << endl;
}


int convert(string& s)
{
	stringstream converter(s);
	int n;
	converter >> n;
	return n;
}



void unos_u_datoteku(ifstream& pokemon_unos, vector<Pokemon>& pp)
{
	int ID;
	int Total;
	string Name;
	string Type_1;
	int HP;
	string Type_2;
	string Legendary;
	int Attack;
	int Defense;
	int Sp_Attack;
	int Sp_Defense;
	int Speed;
	int Generation;
	if (!pokemon_unos)
	{
		cout << "404 error" << endl;
	}
	string ispis;
	string broj;
	getline(pokemon_unos, ispis);
	while (getline(pokemon_unos, ispis))
	{
		stringstream ss(ispis);
		getline(ss, broj, ',');
		ID = convert(broj);
		getline(ss, Name, ',');
		getline(ss, Type_1, ',');
		getline(ss, Type_2, ',');
		getline(ss, broj, ',');
		Total = convert(broj);
		getline(ss, broj, ',');
		HP = convert(broj);
		getline(ss, broj, ',');
		Attack = convert(broj);
		getline(ss, broj, ',');
		Defense = convert(broj);
		getline(ss, broj, ',');
		Sp_Attack = convert(broj);
		getline(ss, broj, ',');
		Sp_Defense = convert(broj);
		getline(ss, broj, ',');
		Speed = convert(broj);
		getline(ss, broj, ',');
		Generation = convert(broj);
		getline(ss, Legendary);
		pp.emplace_back(ID, Total ,Name,Type_1,HP,Type_2,Legendary,Attack,Defense,Sp_Attack,Sp_Defense,Speed,Generation);
	}
}



void multimapa(ifstream& pokemon_unos, multimap<int, string>& pokemon_mapa)
{
	vector<Pokemon> unos;
	list<Pokemon> unos_lista;
	int upis_id;
	unos_u_datoteku(pokemon_unos, unos);
	cout << endl;
	cout << "Upisi ID: ";
	cin >> upis_id;
	for (auto it = unos.begin(); it != unos.end(); ++it)
	{
		pokemon_mapa.insert(pair<int, string>(it->set_ID(), it->puni_ispis()));

	}
	auto found = pokemon_mapa.equal_range(upis_id);
	if (found.first != found.second)
	{
		auto prvi_begin = high_resolution_clock::now();
		cout << "Multimapa:" << endl;
		for (auto it = found.first; it != found.second; ++it)
		{
			cout << it->second << " ";
		}
		cout << endl;

		auto prvi_end = high_resolution_clock::now();
		auto prvi = duration_cast<microseconds>(prvi_end - prvi_begin).count();
		cout << endl;
		auto drugi_begin = high_resolution_clock::now();
		cout << "Vector:" << endl;
		for (auto it = unos.begin(); it != unos.end(); ++it)
		{
			if (upis_id == it->set_ID())
			{
				cout << it->puni_ispis() << endl;
			}
		}
		auto drugi_end = high_resolution_clock::now();
		auto drugi = duration_cast<microseconds>(drugi_end - drugi_begin).count();
		cout << endl;
		for (auto it = unos.begin(); it != unos.end(); ++it)
		{
			unos_lista.emplace_back(it->set_ID(), it->set_Total(), it->set_Name(), it->set_Type_1(), it->set_HP(), it->set_Type_2(), it->get_Legendary(), it->get_Attack(), it->get_Defense(), it->get_Sp_Attack(), it->get_Sp_Defense(), it->get_Speed(), it->get_Generation());
		}
		auto treci_begin = high_resolution_clock::now();
		cout << "Lista:" << endl;
		for (auto it = unos_lista.begin(); it != unos_lista.end(); ++it)
		{
			if (upis_id == it->set_ID())
			{
				cout << it->puni_ispis() << endl;
			}
		}
		auto treci_end = high_resolution_clock::now();
		auto treci = duration_cast<microseconds>(treci_end - treci_begin).count();
		cout << endl;
		int biggest, smallest, sredina = 0;
		if (prvi > drugi && prvi > treci)
		{
			biggest = prvi;
			sredina = drugi;
			smallest = treci;
		}
		else if (drugi > prvi && drugi > treci)
		{
			biggest = prvi;
			sredina = treci;
			smallest = drugi;
		}
		else
		{
			biggest = prvi;
			sredina = drugi;
			smallest = treci;
		}
		cout << "Najbrzi: " << biggest << endl;
		cout << "Srednji: " << sredina << endl;
		cout << "Najsporiji: " << smallest << endl;
	}
	else
	{
		cout << "Nema ID trazenog pokemona." << endl;
	}
}




void Attack_jaci(priority_queue<Pokemon, vector<Pokemon>, jaci>& pq_jaci, ifstream& pokemon_unos)
{
	vector<Pokemon> unos;
	unos_u_datoteku(pokemon_unos, unos);
	priority_queue<Pokemon, vector<Pokemon>, jaci> pq;
	for (auto it = unos.begin(); it != unos.end(); ++it)
	{
		pq.emplace(it->set_ID(), it->set_Total(), it->set_Name(), it->set_Type_1(), it->set_HP(), it->set_Type_2(), it->get_Legendary(), it->get_Attack(), it->get_Defense(), it->get_Sp_Attack(), it->get_Sp_Defense(), it->get_Speed(), it->get_Generation());
	}
	while (!pq.empty())
	{
		cout << pq.top().puni_ispis() << " ";
		pq.pop();
	}
}


void Attack_slabi(priority_queue<Pokemon, vector<Pokemon>, slabi>& pq_jaci, ifstream& pokemon_unos)
{
	vector<Pokemon> unos;
	unos_u_datoteku(pokemon_unos, unos);
	priority_queue<Pokemon, vector<Pokemon>, slabi> pq;
	for (auto it = unos.begin(); it != unos.end(); ++it)
	{
		pq.emplace(it->set_ID(), it->set_Total(), it->set_Name(), it->set_Type_1(), it->set_HP(), it->set_Type_2(), it->get_Legendary(), it->get_Attack(), it->get_Defense(), it->get_Sp_Attack(), it->get_Sp_Defense(), it->get_Speed(), it->get_Generation());
	}
	while (!pq.empty())
	{
		cout << pq.top().puni_ispis() << " ";
		pq.pop();
	}
}


void vector_v(ifstream& pokemon_unos, multimap<string, string>& pokemon_mapa)
{
	vector<Pokemon> unos;
	vector<string> v;
	int unesi;
	string tip;
	unos_u_datoteku(pokemon_unos, unos);
	for (auto it = unos.begin(); it != unos.end(); ++it)
	{
		pokemon_mapa.insert(pair<string, string>(it->set_Type_1(), it->puni_ispis()));

	}
	do
	{
		cout << "Unesi Tip pokemona: " << endl;
		cin >> tip;
		auto found = pokemon_mapa.equal_range(tip);
		cout << endl;
		if (found.first != found.second)
		{
			for (auto it = found.first; it != found.second; ++it)
			{
				v.push_back(it->second);
			}
			cout << endl;
		}
		else
		{
			cout << "Taj tip pokemona ne postoji." << endl;
		}
		cout << "Zelite li ponovno unijeti? (1 - da) (0 - ne): ";
		cin >> unesi;
	} while (unesi == 1);
	for (auto& i : v)
	{
		cout << i << endl;
	}
}


void Generations(priority_queue<Pokemon, vector<Pokemon>, Generacije>& pq_generacije, ifstream& pokemon_unos)
{
	vector<Pokemon> unos;
	vector<string> sortiranje;
	Pokemon* imena = new Pokemon[unos.size()];
	unos_u_datoteku(pokemon_unos, unos);
	for (auto it = unos.begin(); it != unos.end(); ++it)
	{
		pq_generacije.emplace(it->set_ID(), it->set_Total(), it->set_Name(), it->set_Type_1(), it->set_HP(), it->set_Type_2(), it->get_Legendary(), it->get_Attack(), it->get_Defense(), it->get_Sp_Attack(), it->get_Sp_Defense(), it->get_Speed(), it->get_Generation());
	}
	while (!pq_generacije.empty())
	{
		cout << pq_generacije.top().puni_ispis() << " ";
		pq_generacije.pop();
	}
}



void Selection_vs_Insertion(ifstream& pokemon_unos)
{
	vector<Pokemon> unos;
	int vrati_v1 = 0;
	int vrati_v2 = 0;
	unos_u_datoteku(pokemon_unos, unos);
	vector<Pokemon>v1(unos);
	vector<Pokemon>v2(unos);
	auto prvi_begin = high_resolution_clock::now();
	vrati_v1 = insertion_sort(v1, v1.size() - 1);
	auto prvi_end = high_resolution_clock::now();
	auto prvi = duration_cast<milliseconds>(prvi_end - prvi_begin).count();
	auto drugi_begin = high_resolution_clock::now();
	vrati_v2 = selection_sort(v2, v2.size() - 1);
	auto drugi_end = high_resolution_clock::now();
	auto drugi = duration_cast<milliseconds>(drugi_end - drugi_begin).count();
	cout << "Selection sort: " << prvi << " ms" << endl;
	cout << "Broj zamjena: " << vrati_v1 << endl;
	cout << "Insertion sort: " << drugi << " ms" << endl;
	cout << "Broj zamjena: " << vrati_v2 << endl;
}

int generate_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void polje_s_funkcijama(int arr[], int n)
{
	random_shuffle(arr, arr + n);
	binary_search(arr, arr + n, 7);
}

void Pogodi_trajanej()
{
	srand(time(nullptr));
	int mili;
	int x = generate_random(1, 100000000);
	cout << "Koliko ce milisekundi trajat proces: ";
	cin >> mili;
	int* polje = new int[x];
	for (int i = 0; i < x; i++)
	{
		polje[i] = i + 1;
	}
	auto begin = high_resolution_clock::now();
	polje_s_funkcijama(polje, x);
	auto end = high_resolution_clock::now();
	auto vrijeme = duration_cast<microseconds>(end - begin).count();
	cout << "Vase upisano vrijeme trajanja: " << mili  << " ms" << endl;
	cout << "Konkretno trajanje: " << vrijeme << " ms" << endl;
	cout << "Razlika: " << endl;
	if (mili < vrijeme)
	{
		cout << vrijeme - mili << " ms";
	}
	else
	{
		cout << mili - vrijeme << " ms";
	}

}


bool sortiranje(vector<Pokemon>& v)
{
	for (unsigned i = 0; i < v.size() - 1; i++)
	{
		if (v[i].set_Name() > v[i + 1].set_Name())
		{
			return false;
		}
	}
	return true;
}


void bogo(ifstream& pokemon_unos)
{
	srand(time(nullptr));
	vector<Pokemon> unos;
	unos_u_datoteku(pokemon_unos, unos);
	vector<Pokemon> slucajan;
	Pokemon* v1 = new Pokemon[unos.size() - 1];
	int brojac = 0;

	for (auto it = unos.begin(); it != unos.end(); ++it)
	{
		v1[it->set_ID()].get_ID(it->set_ID());
		v1[it->set_ID()].get_Name(it->set_Name());
		v1[it->set_ID()].get_Type_1(it->set_Type_1());
		v1[it->set_ID()].get_Type_2(it->set_Type_2());
		v1[it->set_ID()].get_Total(it->set_Total());
		v1[it->set_ID()].get_HP(it->set_HP());
		v1[it->set_ID()].set_Attack(it->get_Attack());
		v1[it->set_ID()].set_Defense(it->get_Defense());
		v1[it->set_ID()].set_Sp_Attack(it->get_Sp_Attack());
		v1[it->set_ID()].set_Sp_Defense(it->get_Sp_Defense());
		v1[it->set_ID()].set_Speed(it->get_Speed());
		v1[it->set_ID()].set_Generation(it->get_Generation());
		v1[it->set_ID()].set_Legendary(it->get_Legendary());
	}
	for (int i = 0; i < 5; i++)
	{
		int x = generate_random(1, 721);
		slucajan.emplace_back(v1[x].set_ID(), v1[x].set_Total(), v1[x].set_Name(), v1[x].set_Type_1(), v1[x].set_HP(), v1[x].set_Type_2(), v1[x].get_Legendary(), v1[x].get_Attack(), v1[x].get_Defense(), v1[x].get_Sp_Attack(), v1[x].get_Sp_Defense(), v1[x].get_Speed(), v1[x].get_Generation());
	
	}
	while (!sortiranje(slucajan))
	{
		next_permutation(slucajan.begin(), slucajan.end(), ime());
	}
	cout << "Vlastiti Bogo Sort: " << endl;
	for (auto& i : slucajan)
	{
		cout << i.puni_ispis() << endl;
	}
	cout << "Ugradena funkcija: " << endl;
	while (!is_sorted(slucajan.begin(), slucajan.end(), ime())) {
		next_permutation(slucajan.begin(), slucajan.end(), ime());
	}
	for (auto& i : slucajan)
	{
		cout << i.puni_ispis() << endl;
	}
	cout << "Next_Permutation: " << endl;
	while (next_permutation(slucajan.begin(), slucajan.end(), ime()));
	for (auto& i : slucajan)
	{
		cout << i.puni_ispis() << endl;
	}
	delete[] v1;
}

void merge_dance(ifstream& pokemon_unos)
{
	srand(time(nullptr));
	vector<Pokemon> unos;
	unos_u_datoteku(pokemon_unos, unos);
	vector<Pokemon> slucajan;
	Pokemon* v1 = new Pokemon[unos.size() - 1];

	for (auto it = unos.begin(); it != unos.end(); ++it)
	{
		v1[it->set_ID()].get_ID(it->set_ID());
		v1[it->set_ID()].get_Name(it->set_Name());
		v1[it->set_ID()].get_Type_1(it->set_Type_1());
		v1[it->set_ID()].get_Type_2(it->set_Type_2());
		v1[it->set_ID()].get_Total(it->set_Total());
		v1[it->set_ID()].get_HP(it->set_HP());
		v1[it->set_ID()].set_Attack(it->get_Attack());
		v1[it->set_ID()].set_Defense(it->get_Defense());
		v1[it->set_ID()].set_Sp_Attack(it->get_Sp_Attack());
		v1[it->set_ID()].set_Sp_Defense(it->get_Sp_Defense());
		v1[it->set_ID()].set_Speed(it->get_Speed());
		v1[it->set_ID()].set_Generation(it->get_Generation());
		v1[it->set_ID()].set_Legendary(it->get_Legendary());
	}
	int broj_elemanta;
	cout << "Upisite broj elamanata: ";
	cin >> broj_elemanta;
	for (int i = 0; i < broj_elemanta; i++)
	{
		int x = generate_random(1, 721);
		slucajan.emplace_back(v1[x].set_ID(), v1[x].set_Total(), v1[x].set_Name(), v1[x].set_Type_1(), v1[x].set_HP(), v1[x].set_Type_2(), v1[x].get_Legendary(), v1[x].get_Attack(), v1[x].get_Defense(), v1[x].get_Sp_Attack(), v1[x].get_Sp_Defense(), v1[x].get_Speed(), v1[x].get_Generation());

	}
	merge_sort(slucajan, (broj_elemanta + 1 - broj_elemanta));

}

void unos_type(ifstream& pokemon_unos, unordered_multimap<string, string>& pokemon_mapa)
{
	vector<Pokemon> unos;
	list<Pokemon> unos_lista;
	int unesi;
	string tip;
	unos_u_datoteku(pokemon_unos, unos);
	for (auto it = unos.begin(); it != unos.end(); ++it)
	{
		pokemon_mapa.emplace(it->set_Type_2(), it->puni_ispis());

	}
		cout << "Unesi Tip 2 pokemona: " << endl;
		cin >> tip;
		auto found = pokemon_mapa.equal_range(tip);
		cout << endl;
		if (found.first != found.second)
		{
			cout << "Unordered Multimapa:";
			cout << endl;
			auto prvi_begin = high_resolution_clock::now();
			for (auto it = found.first; it != found.second; ++it)
			{
				cout  << it->second << endl;
			}
			auto prvi_end = high_resolution_clock::now();
			auto prvi = duration_cast<microseconds>(prvi_end - prvi_begin).count();
			cout << endl;
			cout << "Vector:" << endl;
			auto drugi_begin = high_resolution_clock::now();
			for (auto it = unos.begin(); it != unos.end(); ++it)
			{
				if (tip == it->set_Type_2())
				{
					cout << it->puni_ispis() << endl;
				}
			}
			auto drugi_end = high_resolution_clock::now();
			auto drugi = duration_cast<microseconds>(drugi_end - drugi_begin).count();
			cout << endl;
			for (auto it = unos.begin(); it != unos.end(); ++it)
			{
				unos_lista.emplace_back(it->set_ID(), it->set_Total(), it->set_Name(), it->set_Type_1(), it->set_HP(), it->set_Type_2(), it->get_Legendary(), it->get_Attack(), it->get_Defense(), it->get_Sp_Attack(), it->get_Sp_Defense(), it->get_Speed(), it->get_Generation());
			}
			auto treci_begin = high_resolution_clock::now();
			cout << "Lista:" << endl;
			for (auto it = unos_lista.begin(); it != unos_lista.end(); ++it)
			{
				if (tip == it->set_Type_2())
				{
					cout << it->puni_ispis() << endl;
				}
			}
			auto treci_end = high_resolution_clock::now();
			auto treci = duration_cast<microseconds>(treci_end - treci_begin).count();
			cout << endl;
			int biggest, sredina, smallest;
			if (prvi > drugi && prvi > treci)
			{
				biggest = prvi;
				sredina = drugi;
				smallest = treci;
			}
			else if (drugi > prvi && drugi > treci)
			{
				biggest = prvi;
				sredina = treci;
				smallest = drugi;
			}
			else
			{
				biggest = prvi;
				sredina = drugi;
				smallest = treci;
			}
			cout << "Najbrzi: " << biggest << endl;
			cout << "Srednji: " << sredina << endl;
			cout << "Najsporiji: " << smallest << endl;
		}
		else
		{
			cout << "Nema trazenog pokemona" << endl;
		}
}


void un_map(ifstream& pokemon_unos, unordered_multimap<int, string>& pokemon_mapa)
{
	int ID;
	string Name;
	if (!pokemon_unos)
	{
		cout << "404 error" << endl;
	}
	string ispis;
	string broj;
	getline(pokemon_unos, ispis);
	while (getline(pokemon_unos, ispis))
	{
		stringstream ss(ispis);
		getline(ss, broj, ',');
		ID = convert(broj);
		getline(ss, Name, ',');
		pokemon_mapa.insert({ ID, Name });
		auto its = pokemon_mapa.equal_range(ID);
		for (auto it = its.first; it != its.second; ++it) {
			cout << "Bucket " << pokemon_mapa.bucket(it->first) << ": " << it->second << endl;
		}
		pokemon_mapa.erase(pokemon_mapa.find(ID), pokemon_mapa.end());
	}
}

bool s_s(unordered_map<int, int>& set_unos)
{
	string i_unos;
	string s_unos;
	cout << "Unesi prvi string: ";
	cin >> i_unos;
	cout << endl;
	cout << "Unesi drugi string: ";
	cin >> s_unos;
	int n1 = i_unos.size();
	int n2 = s_unos.size();
	for (int i = 0; i < n1; i++) {
		set_unos[i_unos[i]]++;
	}
	for (int i = 0; i < n2; i++) {
		if (set_unos[s_unos[i]]) {
			set_unos[s_unos[i]]--;
		}
		else if (set_unos[s_unos[i] - 1] && set_unos[s_unos[i] - 2]) {

			set_unos[s_unos[i] - 1]--;
			set_unos[s_unos[i] - 2]--;
		}
		else {
			return false;
		}
	}
	return true;
}




int main()
{
	Pokemon p;
	ifstream pokemon_unos("SPA_PROJ_002_POKEMON_data.csv");
	if (!pokemon_unos)
	{
		cout << "Neki error" << endl;
	}
	multimap<int, string> pokemon_mapa;
	multimap<string, string> pokemon_mapa_druga;
	priority_queue<Pokemon, vector<Pokemon>, jaci> pq_jaci;
	priority_queue<Pokemon, vector<Pokemon>, slabi> pq_slabi;
	priority_queue<Pokemon, vector<Pokemon>, Generacije> pq_Generacije;
	unordered_multimap<string, string> pokemon_multi_mapa;
	unordered_multimap<int, string> pokemon_un;
	unordered_map<int, int> unos_set;
	int odabir;
	int odabit_attack;
	bool istinito;
	ispis_na_ekranu();
	cout << endl;
		cout << "Odabir: ";
		cin >> odabir;
		switch (odabir)
		{
		case 1:
			upis_Pokemona(p);
			break;
		case 2:
			multimapa(pokemon_unos, pokemon_mapa);
			break;
		case 3:
			cout << "Odaberite prikaz Attack prema: Jacim(1), slabim(2):" << endl;
			cin >> odabit_attack;
			if (odabit_attack == 1)
			{
				Attack_jaci(pq_jaci, pokemon_unos);
			}
			else if (odabit_attack == 2)
			{
				Attack_slabi(pq_slabi, pokemon_unos);
			}
			else
			{
				cout << "Pogresan unos" << endl;
			}
			break;
		case 4:
			vector_v(pokemon_unos, pokemon_mapa_druga);
			break;
		case 5:
			Generations(pq_Generacije, pokemon_unos);
			break;
		case 6:
			Selection_vs_Insertion(pokemon_unos);
			break;
		case 7:
			Pogodi_trajanej();
			break;
		case 8:
			bogo(pokemon_unos);
			break;
		case 9:
			merge_dance(pokemon_unos);
			break;
		case 10:
			unos_type(pokemon_unos, pokemon_multi_mapa);
			break;
		case 11:
			un_map(pokemon_unos, pokemon_un);
			break;
		case 12:
			istinito = s_s(unos_set);
			if (istinito)
			{
				cout << "Moze" << endl;
			}
			else
				cout << "Ne moze" << endl;
			break;
		default:
			cout << "Krivi unos" << endl;
			break;
		}
		pokemon_unos.close();
		return 0;
}