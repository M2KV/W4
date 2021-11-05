#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Skill.h"
using namespace std;

class Hero
{
private:
	friend istream& operator >>(istream& inp, Hero& hero);
	friend ostream& operator <<(ostream& out, const Hero& hero);

	string heroName;
	unsigned int heroHealth;
	unsigned int heroMana;
	unsigned int heroLevel;
	vector<Skill*> skillList;

	void Initialize_Skills();

public:
	Hero();
	Hero(string _name, const unsigned int& _hp, const unsigned int& _mana, const unsigned int& _level);
	Hero(const Hero& hr);
	~Hero();

	string g_HeroName() const;
	unsigned int g_HeroHealth() const;
	unsigned int g_HeroMana() const;
	unsigned int g_HeroLevel() const;
	vector<Skill*> g_HeroList() const;

	void s_HeroName(const string& _name);
	void s_HeroHeath(const unsigned int& _hp);
	void s_HeroMana(const unsigned int& _mana);
	void s_HeroLevel(const unsigned int& _level);
	void s_skillList(vector<Skill> skills);

	string showListSkill();
	void eraseListSkill(const int& len);
};