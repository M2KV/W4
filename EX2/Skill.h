#pragma once
#include <iostream>
#include <string>
using namespace std;

class Skill
{
private:
	friend istream& operator >>(istream& inp, Skill& skill);
	//friend ostream& operator <<(ostream& out, const Skill& skill);

	string skillName;
	unsigned int skillLevel;

public:
	Skill();
	Skill(const string& _name, const unsigned int& _level);
	Skill(const Skill& skill);

	string g_SkillName() const;
	unsigned int g_SkillLevel() const;

	void s_SkillName(const string& _name);
	void s_SkillLevel(const unsigned int& _level);

};