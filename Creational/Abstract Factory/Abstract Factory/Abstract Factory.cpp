#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class Warrior
{

public:
	virtual void fight();

};

class DarkWarrior : public Warrior
{

public:
	void fight() override;

};

class WhiteWarrior : public Warrior
{

public:
	void fight() override;

};

class Mage
{

public:
	virtual void cast();

};

class DarkMage : public Mage
{

public:
	void cast() override;

};

class WhiteMage : public Mage
{

public:
	void cast() override;

};

class Barracks
{

public:
	virtual Warrior* create_warrior();
	virtual Mage* create_mage();

};

class DarkBarracks : public Barracks
{

public:
	Warrior* create_warrior() override;
	Mage* create_mage() override;

};

class WhiteBarracks : public Barracks
{

public:
	Warrior* create_warrior() override;
	Mage* create_mage() override;

};

void Warrior::fight()
{
}

void Mage::cast()
{
}

void DarkWarrior::fight()
{
	cout << "Dark Warrior!" << endl;
}

void WhiteWarrior::fight()
{
	cout << "White Warrior!" << endl;
}

void DarkMage::cast()
{
	cout << "Dark Mage!" << endl;
}

void WhiteMage::cast()
{
	cout << "White Mage!" << endl;
}

Warrior* Barracks::create_warrior()
{
	return nullptr;
}

Mage* Barracks::create_mage()
{
	return nullptr;
}

Warrior* DarkBarracks::create_warrior()
{
	return new DarkWarrior();
}

Mage* DarkBarracks::create_mage()
{
	return new DarkMage();
}

Warrior* WhiteBarracks::create_warrior()
{
	return new WhiteWarrior();
}

Mage* WhiteBarracks::create_mage()
{
	return new WhiteMage();
}

int main()
{
	auto darkBarracks = DarkBarracks();
	auto whiteBarracks = WhiteBarracks();

	Warrior* warrior = whiteBarracks.create_warrior();
	Mage* mage = whiteBarracks.create_mage();

	warrior->fight();
	mage->cast();

	delete warrior;
	delete mage;

	warrior = darkBarracks.create_warrior();
	mage = darkBarracks.create_mage();

	warrior->fight();
	mage->cast();

	delete warrior;
	delete mage;

	cin.get();
}