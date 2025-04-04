#include <iostream>
#include <cstdlib>
#include <cmath>

#ifndef COORDINATE_H
#define COORDINATE_H



struct _coordinate {
	float x;
	float y;
	int coord_id;
	struct _coordinate *next;
	struct _coordinate *previous;

};
typedef struct _coordinate Coordinate;



void add_coordinate(Coordinate *&list_end, float x, float y, int &id_counter);
void foward_display(Coordinate *list_beginning);
void backward_display(coordinate *list_end);
void delete_coodinate(Coordinate *list_beginning, int coord_id_to_delete);
int list_length(Coordinate *list_beginning);
void closest_to(Coordinate *list_beginning, floatx, float y);

#endif

