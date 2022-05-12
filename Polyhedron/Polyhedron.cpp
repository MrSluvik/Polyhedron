// Створити абстрактний клас “Багатокутник”. Клас повинен містити методи для обчислення периметра, знаходження площі і ін.обудувати похідний клас “Трикутник” і прямокутник, що містить також методи для знаходження довжин медіан, висот трикутника
#include <iostream>
#include<windows.h>
using namespace std;

class Polyhedron//клас багатокутник (базовий клас)
{
protected:
	virtual double perimetr()=0;//чисто віртуальна функція
	virtual double square()=0;
};

class Triangle: public Polyhedron//клас трикутник
{
protected:
	double AB, BC, AC;//сторони трикутника
	double M;//медіана
	double H;//висота 
	double p,P,S;//півпериметр і периметр і площа
public:
	Triangle(int AB, int BC,int AC) {//конструктор
		this->AB = AB;
		this->BC = BC;
		this->AC = AC;
	}

	double Mediana() {
		M = (sqrt(2*pow(AB,2)+2*pow(BC,2)-pow(AC,2)))/2;//знаходим медіау
		return M;
	}

	double Height() {
		p = (AB + BC + AC) / 2;//знаходим півпериметр для подальших формул
		H = 2 / AC * (sqrt(p * (p - AB) * (p - BC) * (p - AC)));//заходмо висоту проведену до сторони АС
		return H;
	}

	double perimetr() override {//переопреділяєм перемтр для трикутника
		P = AB + BC + AC;
		return P;
	 }

	double square() override {//переопреділяєм площу для трикутника
		S = 0.5 * (AB * H);
		return S;
	 }

	~Triangle() {};

};

class RectangleT:public Polyhedron//клас прямокутник
{
protected:
	double AB, BC;
	double P, S;
	double H;
public:
		RectangleT(int AB,int BC) //конструтор
		{
		this->AB = AB;
		this->BC = BC;		
	    }

		double Height()// висота прямокутника
		{
			return AB;
		}

		double perimetr()override//переопреділяєм перемтр для прямокутника
		{
			P = (AB + BC) * 2;
			return P;
		}
		double square() override//переопреділяєм площу для прямокутника
			
		{
			S = AB * BC;
			return S;
		}

		~RectangleT() {};
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Triangle t(8, 9, 13);//створюєм обєкт класу трикутник
	RectangleT r(2,4);//створюєм обєкт класу прямокутника
	cout << "Медіана трикутника : " << t.Mediana() << endl;
	cout << "Висота трикутника : " << t.Height()<<endl;
	cout << "Периметр трикутника : " << t.perimetr() << endl;
	cout << "Площа трикутника : " << t.square() << endl;
	cout << endl << endl;
	cout << "Висота прямокутника : " << r.Height()<<endl;	
	cout << "Периметр прямокутника : " << r.perimetr()<<endl;
	cout << "Площа прямокутника : " << r.square()<<endl;
}