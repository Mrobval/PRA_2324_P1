#include "Point2D.h"
#include <ostream>
#include <cmath>

Point2D::Point2D(double x, double y){
	this -> x = x;
	this -> y = y;
}

double Point2D::distance(const Point2D &a, const Point2D &b){  //calcula distancia euclidiana
        double restax = a.x - b.x;
        double restay = a.y - b.y;
        double cx = pow(restax, 2);
        double cy = pow(restay,2);
        double distance = sqrt(cy + cx);
        return distance;
}

bool operator == (const Point2D &a, const Point2D &b){  //comprueba si dos puntos son iguales
        return a.x == b.x && a.y == b.y;
}

bool operator != (const Point2D &a, const Point2D &b){
        return a.x != b.x && a.y != b.y;
}

std::ostream& operator<<(std::ostream &out, const Point2D &p){
        out << "(" << p.x<<" , "<<p.y<<")"<<std::endl;
        return out;
}
