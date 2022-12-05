#include <iostream>
using namespace std;
class Shape {
public:
	virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
	virtual void draw() {
		cout << "Shape: Rectangle" << endl;
	}
};

class Circle : public Shape {
public:
	virtual void draw() {
		cout << "Shape: Circle" << endl;
	}
};

class ShapeDecorator : public Shape {
	Shape* s;
public:
	ShapeDecorator(Shape* sd) {
		s = sd;
	}
	void draw() {
		s->draw();
	}
};// shape �� ���ڴ��� shapeDecorator�� ����� draw()�� �����Ѵ�.

class RedShapeDecorator : public ShapeDecorator {
public:
	RedShapeDecorator(Shape* sd) :ShapeDecorator(sd) {}
	void draw() {
		ShapeDecorator::draw();
		cout << "Border Color: Red" << endl;
	}
};

int main() {
	Shape *circle = new Circle();
	Shape *rectangle = new Rectangle();
	// ��ü�� ������ �� ���� �°� ����Ѵ�.
	cout << "Circle with normal border" << endl;
	circle->draw();
	cout << "\n";
	cout << "Circle of red border" << endl;
	RedShapeDecorator sd(circle);
	sd.draw();
	cout << "\n";
	cout << "Rectangle of red border" << endl;
	RedShapeDecorator sr(rectangle);
	sr.draw();
	cout << "\n";

}