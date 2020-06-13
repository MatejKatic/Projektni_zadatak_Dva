#pragma once
#include <string>
#include <vector>
using namespace std;

class Pokemon
{
public:
	Pokemon();
	Pokemon(int ID, int Total, string Name, string Type_1, int HP, string Type_2, string Legendary, int Attack, int Defense, int Sp_Attack, int Sp_Defense, int Speed, int Generation);
	void get_ID(int ID);
	int set_ID() const;
	void get_Total(int Total);
	int set_Total();
	void get_Name(string Name);
	string set_Name() const ;
	void get_Type_1(string Type_1);
	string set_Type_1();
	void get_HP(int HP);
	int set_HP();
	void get_Type_2(string Type_2);
	string set_Type_2();
	void set_Legendary(string Legendary);
	string get_Legendary();
	void set_Attack(int Attack);
	int get_Attack() const;
	void set_Defense(int Defense);
	int get_Defense();
	void set_Sp_Attack(int Sp_Attack);
	int get_Sp_Attack();
	void set_Sp_Defense(int Sp_Defense);
	int get_Sp_Defense();
	void set_Speed(int Speed);
	int get_Speed();
	void set_Generation(int Generation);
	int get_Generation() const;
	string ispis();
	string puni_ispis() const;

private:
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
};

struct jaci
{
	bool operator()(const Pokemon& i1, const Pokemon& i2) const
	{
		return i1.get_Attack() < i2.get_Attack();
	}
};


struct slabi
{
	bool operator()(const Pokemon& i1, const Pokemon& i2) const
	{
		return i1.get_Attack() > i2.get_Attack();
	}
};

struct Generacije
{
	bool operator()(const Pokemon& i1, const Pokemon& i2) const
	{
		return i1.get_Generation() > i2.get_Generation();
	}
};

struct ime
{
	bool operator()(const Pokemon& i1, const Pokemon& i2) const
	{
		return i1.set_Name() > i2.set_Name();
	}
};

struct ID
{
	bool operator()(const Pokemon& i1, const Pokemon& i2) const
	{
		return i1.set_ID() > i2.set_ID();
	}
};