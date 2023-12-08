#include "ListArray.h"
#ifndef DRAWING_H
#define DRAWING_H

class Drawing {
        private:
                List<Shape*>* shapes;
        public:
		Drawing(){
			shapes = new ListArray<Shape*>();
		}
                
		~Drawing(){
			for(int i = 0; i < shapes->n; i++){
				delete shapes[i];
			}
		}
                
		void add_front(Shape* shape){
			shapes->prepend(shape); //utilizamos el metodo prepend de ListArray
		}
                
		void add_back(Shape* shape){
			shapes->apend(shape); //utilizamos el método apend de ListArray
		}
                
		void print_all(){
			for(int i = 0; i < shapes->n; i++){
				Shape* figura = shapes->get(i); // es la figura que se encuentra en la pos i
				figura->print(); //accedemos al metodo print de Shape
			}
		}

		double get_area_all_circles(){
			double area = 0;
			for(int i = 0; i < shapes->n; i++){
				Shape* figura = shapes->get(i);
				Circle* circulo = dynamic_cast<Circle*>(figura); // conviertes figura en circulo
				if(circulo){ // si se trata de un circulo
					area = area + circulo->area(); //sumamos el area de todos los circulos
				}
			}
			return area;
		}

		void move_squares(double incX, double incY){
			for(int i = 0; i < shapes->n; i++){
                	Shape* figura = shapes->get(i);
                	Square* cuadrado = dynamic_cast<Square*>(figura); // conviertes figura en cuadrado
                	if(cuadrado){
				cuadrado->translate(incX, incY);
			}
		}
		}

};

#endif
