#include "Skill.h"
#include "Hero.h"
using namespace std;

void inputSkill(Hero& hero)
{
	vector<Skill> skills;
	
	cout << "Continue input new skill ? (Y/N): ";
	Skill skill;
	while (toupper(getchar()) != 'N')
	{
		cin >> skill;
		skills.emplace_back(skill);
		cout << "Continue input new skill ? (Y/N): ";
	} 
	hero.s_skillList(skills);
}

int main()
{
	Hero hero = Hero();
	cin >> hero;
	inputSkill(hero);
	cout << hero << "\n" << hero.showListSkill();
	return 0;
}