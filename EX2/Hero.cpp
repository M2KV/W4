#include "Hero.h"

istream& operator>>(istream& inp, Hero& hero)
{
	cout << "Input hero's name: ";
	inp >> hero.heroName;

	cout << "Input hero's health: ";
	inp >> hero.heroHealth;

	cout << "Input hero's mana: ";
	inp >> hero.heroMana; 

	cout << "Input hero's level: ";
	inp >> hero.heroLevel;

	inp.ignore();
	return inp;
}

ostream& operator<<(ostream& out, const Hero& hero)
{
	cout << "Hero's name: ";
	out << hero.heroName << "\n";

	cout << "Hero's health: ";
	out << hero.heroHealth << "\n";

	cout << "Hero's mana: ";
	out << hero.heroMana << "\n";

	cout << "Hero's level: ";
	out << hero.heroLevel << "\n";

	return out;
}

void Hero::Initialize_Skills()
{
	skillList.emplace_back(new Skill("Bom tu vong", 1));
	skillList.emplace_back(new Skill("Truong trong luc", 5));
	skillList.emplace_back(new Skill("Toc bien", 10));
	skillList.emplace_back(new Skill("Hoi mau", 15));
	skillList.emplace_back(new Skill("Boc pha", 20));
	skillList.emplace_back(new Skill("Tran troi", 25));
}

Hero::Hero()
{
	heroName	= "";
	heroHealth	= 100;
	heroMana	= 50;
	heroLevel	= 1;
	Initialize_Skills();
}

Hero::Hero(string _name, const unsigned int& _hp, const unsigned int& _mana, const unsigned int& _level)
{
	heroName	= _name;
	heroHealth	= _hp;
	heroMana	= _mana;
	heroLevel	= _level;
	Initialize_Skills();
}

Hero::Hero(const Hero& hr)
{
	heroName	= hr.heroName;
	heroHealth	= hr.heroHealth;
	heroMana	= hr.heroMana;
	heroLevel	= hr.heroLevel;

	for (int i = 0; i < hr.skillList.size(); ++i)
		skillList.emplace_back(new Skill(*hr.skillList[i]));
}

Hero::~Hero()
{
	heroName	= "";
	heroHealth	= 100;
	heroMana	= 50;
	heroLevel	= 1;
	for (Skill*& skill : skillList)
	{
		delete skill;
		skill = nullptr;
	}
	skillList.clear();
}

string Hero::g_HeroName() const
{
	return heroName;
}

unsigned int Hero::g_HeroHealth() const
{
	return heroHealth;
}

unsigned int Hero::g_HeroMana() const
{
	return heroMana;
}

unsigned int Hero::g_HeroLevel() const
{
	return heroLevel;
}

vector<Skill*> Hero::g_HeroList() const
{
	return skillList;
}

void Hero::s_HeroName(const string& _name)
{
	heroName = _name;
}

void Hero::s_HeroHeath(const unsigned int& _hp)
{
	heroHealth = _hp;
}

void Hero::s_HeroMana(const unsigned int& _mana)
{
	heroMana = _mana;
}

void Hero::s_HeroLevel(const unsigned int& _level)
{
	heroLevel = _level;
}

void Hero::s_skillList(vector<Skill> skills)
{
	skillList.clear();

	for (int i = 0; i < skills.size(); ++i)
		skillList.emplace_back(new Skill(skills[i]));
}

string Hero::showListSkill()
{
	string skill = "";
	for (const Skill* sk : skillList)
	{
		if (heroLevel >= sk->g_SkillLevel())
			skill += sk->g_SkillName() + ", ";
	}
	return skill;
}

void Hero::eraseListSkill(const int& len)
{
	if (len <= 0) return;
	if (len >= skillList.size())
	{
		for (Skill*& skill : skillList)
		{
			delete skill;
			skill = nullptr;
		}
		skillList.clear();
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			delete skillList[skillList.size() - i - 1];
			skillList[skillList.size() - i - 1] = nullptr;
			skillList.pop_back();
		}
	}
}