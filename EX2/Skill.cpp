#include "Skill.h"

istream& operator>>(istream& inp, Skill& skill)
{
	cout << "Input Skill and level of skill: ";
	getline(inp, skill.skillName);
	inp >> skill.skillLevel;
	inp.ignore();

	return inp;
}

Skill::Skill()
{
	skillName	= "";
	skillLevel	= 1;
}

Skill::Skill(const string& _name, const unsigned int& _level)
{
	skillName	= _name;
	skillLevel	= _level;
}

Skill::Skill(const Skill& skill) 
{
	skillName	= skill.skillName;
	skillLevel	= skill.skillLevel;
}

string Skill::g_SkillName() const
{
	return skillName;
}

unsigned int Skill::g_SkillLevel() const
{
	return skillLevel;
}

void Skill::s_SkillName(const string& _name)
{
	skillName	= _name;
}

void Skill::s_SkillLevel(const unsigned int& _level)
{
	skillLevel	= _level;
}