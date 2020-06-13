#include "Pokemon.h"
#include <sstream>

Pokemon::Pokemon()
{

}

Pokemon::Pokemon(int ID, int Total, string Name, string Type_1, int HP, string Type_2, string Legendary, int Attack, int Defense, int Sp_Attack, int Sp_Defense, int Speed, int Generation)
{
    this->ID = ID;
    this->Total = Total;
    this->Name = Name;
    this->Type_1 = Type_1;
    this->HP = HP;
    this->Type_2 = Type_2;
    this->Legendary = Legendary;
    this->Attack = Attack;
    this->Defense = Defense;
    this->Sp_Attack = Sp_Attack;
    this->Sp_Defense = Sp_Defense;
    this->Speed = Speed;
    this->Generation = Generation;
}


void Pokemon::get_ID(int ID)
{
    this->ID = ID;
}

int Pokemon::set_ID() const
{
    return ID;
}

void Pokemon::get_Total(int Total)
{
    this->Total = Total;
}

int Pokemon::set_Total()
{
    return Total;
}

void Pokemon::get_Name(string Name)
{
    this->Name = Name;
}

string Pokemon::set_Name() const
{
    return Name;
}

void Pokemon::get_Type_1(string Type_1)
{
    this->Type_1 = Type_1;
}

string Pokemon::set_Type_1()
{
    return Type_1;
}

void Pokemon::get_HP(int HP)
{
    this->HP = HP;
}

int Pokemon::set_HP()
{
    return HP;
}

void Pokemon::get_Type_2(string Type_2)
{
    this->Type_2 = Type_2;
}

string Pokemon::set_Type_2()
{
    return Type_2;
}

void Pokemon::set_Legendary(string Legendary)
{
    this->Legendary = Legendary;
}

string Pokemon::get_Legendary()
{
    return Legendary;
}

void Pokemon::set_Attack(int Attack)
{
    this->Attack = Attack;
}

int Pokemon::get_Attack() const
{
    return Attack;
}

void Pokemon::set_Defense(int Defense)
{
    this->Defense = Defense;
}

int Pokemon::get_Defense()
{
    return Defense;
}

void Pokemon::set_Sp_Attack(int Sp_Attack)
{
    this->Sp_Attack = Sp_Attack;
}

int Pokemon::get_Sp_Attack()
{
    return Sp_Attack;
}

void Pokemon::set_Sp_Defense(int Sp_Defense)
{
    this->Sp_Defense = Sp_Defense;
}

int Pokemon::get_Sp_Defense()
{
    return Sp_Defense;
}

void Pokemon::set_Speed(int Speed)
{
    this->Speed = Speed;
}

int Pokemon::get_Speed()
{
    return Speed;
}

void Pokemon::set_Generation(int Generation)
{
    this->Generation = Generation;
}

int Pokemon::get_Generation() const
{
    return Generation;
}

string Pokemon::ispis()
{
    stringstream ss;
    ss << "Ime: " << Name << endl
       << "Tip 1: " << Type_1 << endl
       << "Tip 2: " << Type_2 << endl
       << "Total: " << Total << endl;
    return ss.str();
}

string Pokemon::puni_ispis() const
{
    stringstream ss;
    ss << "Ime: " << Name << endl
        << "Tip 1: " << Type_1 << endl
        << "Tip 2: " << Type_2 << endl
        << "Total: " << Total << endl
        << "HP: " << HP << endl
        << "Attack: " << Attack << endl
        << "Defense: " << Defense << endl
        << "Sp.Atk: " << Sp_Attack << endl
        << "Sp.Def " << Sp_Defense << endl
        << "Speed: " << Speed << endl
        << "Generation: " << Generation << endl
        << "Legendary: " << Legendary << endl
        << endl;
    return ss.str();
}


