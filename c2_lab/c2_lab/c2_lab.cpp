
#include <iostream>


using namespace std;


class Figure{
    private:
       

    public:
        virtual float pole()=0;
        virtual float obwod()=0;
};

class Square:public Figure {
    private:
        float a;


    public:
        Square(float a) {
            this->a = a;
        }

        float pole() { return a * a; }
        float obwod() { return 4 * a; }
};  
class Circle :public Figure{
    private:
        float r;
    public:
        Circle(float r) {
            this->r =r;
        }
        float pole() { return 3.14 * (r * r); }
        float obwod() { return 2 * r * 3.14; }
};
class Prostokat : public Figure {
    private:
        float a;
        float b;
    public:
        Prostokat(float a, float b) {
            this->a = a;
            this->b = b;
        }
        float pole() { return a * b; }
        float obwod() { return 2 * a + 2 * b; }
};

int main()
{
    int decyzja;
    Circle* circle = new Circle(5);
    Square* square = new Square(5);
    Prostokat* prostokat = new Prostokat(2, 4);
    Figure* figure = circle;
    do {
        cout << " MENU" << endl;
        cout << " 1. Square" << endl;
        cout << " 2.Circle" << endl;
        cout << " 3.Prostokat" << endl;
        cout << " 5. Podaj pole wybraj figury" << endl;
        cout << " 6. Podaj obwod wybranej figury" << endl;
        cout << "0. Exit" << endl;
        cin >> decyzja;

        if (decyzja == 1) figure = square;
        if (decyzja == 2) figure = circle;
        if (decyzja == 3) figure = prostokat;
        if (decyzja == 5) cout << "Pole: " << figure->pole() << endl;
        if (decyzja == 6) cout << "Obwod: " << figure->obwod() << endl;

    } while (decyzja != 0);
    delete (circle);
    delete(square);
    return 0;

}
