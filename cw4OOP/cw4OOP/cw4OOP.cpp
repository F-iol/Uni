#include <iostream>
#include <vector>

using namespace std;


class Subject {
	public:
		virtual void notify(float temp) = 0;
};



class Display {
	public:
		virtual void addObserver(Subject* observer) = 0;
		virtual void removeObserver(Subject* observer) = 0;
		virtual void SetTemperature(float temp) = 0;
		virtual void notifyObserver() = 0;
};


class Observer:public Subject  {
	public:

		Observer() {};
		void notify(float temp) {
			cout << "Temp has been changed to: "<< temp << endl;
		}
};

class Sensor :public Display {
	private:
	float Temperature=0;
	public:
		vector<Subject*> observers;

		void addObserver(Subject*Observer){
			observers.push_back(Observer);
		}
		void removeObserver(Subject* observer){
			observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());

		}

		void notifyObserver()  {
			for (Subject* observer : observers) {
				observer->notify(Temperature);
			}
		}
		void SetTemperature(float Temperature) {
			this->Temperature = Temperature;
			notifyObserver();
			}
		


};


int main() {


	Observer* observer1 = new Observer();
	Observer* observer2 = new Observer();
	Sensor* sensor1 = new Sensor();


	return 0;
}