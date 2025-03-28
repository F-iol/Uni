#include <iostream>
#include <vector>
#include <string>
using namespace std;



class AirPlane {
public:
	virtual void moveFront() = 0;

	virtual void moveBack() = 0;
};


class ModernDrone:public AirPlane {
	private:
		int xPosition;
		int yPosition;
		int zPosition;
		string id;
	public:
		ModernDrone(int xPosition,int yPosition,int zPosition,string id) {
			this->xPosition=xPosition;
			this->yPosition = yPosition;
			this->zPosition = zPosition;
			this->id = id;
		}

		string GetId() {
			return id;
		}
		int getxPosition() {
			return xPosition;
		}
		int getyPosition() {
			return yPosition;
		}
		int getzPosition() {
			return zPosition;
		}
		bool testPosition(int newPositon) {
			if (newPositon >= 1 && newPositon <= 100) return true;
			return false;
		}

		void SetxPosition(int xPosition) {
			if (testPosition(xPosition)) this->xPosition = xPosition;
		}
		void SetyPosition(int yPosition) {
			if(testPosition(yPosition)) this->yPosition = yPosition;
		}

		void SetzPosition(int zPosition) {
			if (testPosition(zPosition)) this->zPosition = zPosition;
		}

		void moveFront() {
			if (testPosition(yPosition))
				yPosition++;
			cout << "Actual y position is: " << yPosition << endl;
		}
		void moveBack() {
			if (testPosition(yPosition))
				yPosition--;
			cout << "Actual y position is: " << yPosition << endl;
		}
};

class Glider {
private:
	int xPosition;
	int yPosition;
	int zPosition;
	string id;
public:
	Glider(int xPosition, int yPosition, int zPosition, string id) {
		this->xPosition = xPosition;
		this->yPosition = yPosition;
		this->zPosition = zPosition;
		this->id = id;
	}
	void run() {
		cout << "Glider flies" << endl;
		zPosition++;
		yPosition++;
		cout << "Actual y position is: " << yPosition << " and z is:  " << zPosition << endl;

	}
	void stop() {
		cout << "Glider stops" << endl;
		zPosition = 0;
		yPosition--;
		cout << "Actual y position is: " << yPosition << " and z is:  " << zPosition << endl;
	}
};


class AdapterGlider :public AirPlane {
private:
	Glider* glider;
public: 
	AdapterGlider(Glider *glider) {
		this->glider = glider;
	}
	void moveFront() {
		glider->run();
	}

	void moveBack() {
		glider->stop();
	}

};


class Operator {
private:
	vector<AirPlane*> airPlane;

public:
	void add_airPlane(AirPlane *airPlane) {
		this->airPlane.push_back(airPlane);
		}
	void moveFront() {
		for (int i = 0; i < airPlane.size(); i++) {
			airPlane[i]->moveFront();
		}
	}
	void moveBack() {
		for (int i = 0; i < airPlane.size(); i++) {
			airPlane[i]->moveBack();
		}
	}
	

};



int main()
{
	ModernDrone* modernDrone1 = new ModernDrone(0, 0, 0, "1");
	ModernDrone* modernDrone2 = new ModernDrone(0, 0, 0, "2");
	ModernDrone* modernDrone3 = new ModernDrone(0, 0, 0, "3");
	Glider* gldier1 = new Glider(0, 0, 0, "2");
	Glider* gldier2 = new Glider(0, 0, 0, "3");
	AdapterGlider* adapterGlider1 = new AdapterGlider(gldier1);
	AdapterGlider* adapterGlider2 = new AdapterGlider(gldier2);
	Operator* operator1 = new Operator();

	operator1->add_airPlane(modernDrone1);
	operator1->add_airPlane(modernDrone2);
	operator1->add_airPlane(modernDrone3);
	operator1->add_airPlane(adapterGlider1);
	operator1->add_airPlane(adapterGlider2);
	operator1->moveFront();


	
	delete(modernDrone1);
	delete(modernDrone2);
	delete(modernDrone3);
	delete(adapterGlider1);
	delete(adapterGlider2);
	delete(gldier1);
	delete(gldier2);

	return 0;
}
