#include "Circle.h"
#include <cmath>

Circle::Circle(){
	radius = 1;
	center.x = 0;
	center.y = 0;
	color = "red";

}

Circle::Circle(std::string color, Point2D center, double radius){
	this->radius = radius;
	this->center = center;
	this->color = color;

}

Point2D Circle::get_center() const{
	return center; 

}

void Circle::set_center(Point2D p){
	center.x = p.x;
	center.y = p.y;
}

double Circle::get_radius() const{
	return radius;
}

void Circle::set_radius(double r){
	radius = r;
}

std::ostream& operator<<(std::ostream &out, const Circle &c){
	out<<"Los datos del circulo son:"<<std::endl<<"Color: "<<c.color<<std::endl<<"Radio: "<<c.radius<<std::endl<<"Centro: "<<c.center;
	return out;
}

double Circle::area(){
	double pi =  M_PI;
	double rcuadrado = pow(radius,2);
	double area = pi*rcuadrado;
	return area;
}

double Circle::perimeter() {
	double pi =  M_PI;
	double perimeter = 2*pi*radius; 
	return perimeter;
}

void Circle::translate(double incX, double incY){
	center.x += incX;
	center.y += incY;
} 

void Circle::print(){
	std::cout<<"Los datos del circulo son:"<<std::endl<<"Color: "<<color<<std::endl<<"Radio: "<<radius<<std::endl<<"Centro: ("<<center<<")"<<std::endl;

}
