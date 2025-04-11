#include <iostream>
#include<string>

using namespace std;


class Czlowiek {
	
private:
	
	friend void PrivateMethod() {
		cout << "This is private method" << endl;
	}

protected:
	int  ProtectedMethod() {}

public:
	virtual void PublicMethod() final {
		cout << "This function is final" << endl;
	}
	void PublicMethodV2(){}
	Czlowiek(){}

};


class Student :public Czlowiek {
private:
	int PrivateMethod() {
		cout << "Accessable(within class) and overwritable" << endl;
	}
	
protected:
	int ProtectedMethod() {
		
		cout << "Still works(only within class) and can be overwriten" << endl;
	}
public:
	void PublicMethodV2() {
		cout << "Overwritten Student's function" << endl;
	}
	Student(){}


};


class Warrior {
private:
	float HP;
	float Power;
public:
	Warrior(float HP = 5, float Power = 50) {
		this->HP = HP;
		this->Power = Power;
	}

	float Attack(){
		return Power * 0.1f;
	}
	float Defense(float EnemyPower){
		HP = HP - EnemyPower / 5.0;
		if (HP <= 0) cout << "Game Over" << endl; else cout << "HP left: " << HP << endl;
		return HP;
	}
};


int main() {
	/*Student student;
	student.PublicMethodV2();*/
	Warrior* warrior1 = new Warrior(8,20);
	Warrior* warrior2 = new Warrior(9,15);

	do {} while (warrior1->Defense(warrior2->Attack()) > 0);
	//warrior1->Defense(warrior2->Attack());
	

	delete(warrior1);
	delete(warrior2);
	return 0;
}