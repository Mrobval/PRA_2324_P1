#include"Shape.h"
#include <ostream>

Shape::Shape(){
	color = "red";
}

Shape::Shape(std::string color){
	this -> color = color;
	if( color != "red" && color != "blue" && color != "green"){
		throw std::invalid_argument ("El color es inválido");
	}
}

std::string Shape::get_color() const{
	return color;
}

void Shape::set_color(std::string c){
	if( c != "red" && c != "blue" && c != "green"){
                throw std::invalid_argument ("El color es inválido");
        }
	color = c;
}


