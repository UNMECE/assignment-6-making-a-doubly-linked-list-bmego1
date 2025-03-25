#include "coordinate.h"


void add_coodinate(Coordinate *&link_end, float x, float y, int &id_counter) {
	Coordinate *new_coordinate = new Coordinate;
		new_coordinate -> x=x;
		new_coordinate -> y=y;
		new_coordinate -> coord_id = id_counter++;
		new_coordinate -> next = nullptr;
		new_coordinate -> previous = list_end;

		if(list_end) list_end -> next = new_coordinate;
			list_end = new_coordinate;
}


void foward_display(Coordinate *list_beginning) {
	Coordinate *current = list_beginning;
	 	while(current) {
			std::cout<< "ID: " << current->coord_id << " (" << current ->x << ", " << current->y << ")\n";
			current = current->next;
		}
}



void backward_display(coordinate *list_end) {
	Coordinate *current = list_end;
	while(current) {
		std::cout << "ID: " << current->coord_id << " (" << current->x << ", " <<current->y << ")\n";
		current = current->previous;
	}
}


void delete_coordinate(Coordinate *&list_beginning, int delete_coord_id) {
	Coordinate *current = list_beginning;
	while(current && current->coord_id != delete_coord_id) {
		current = nurrent-> next;
	}

	if(current->previous) current->previous = current->next;
	if(current->next) current->next->previous = current->previous;
	if(current == list_beginning) list_beginning = current->next;
	if(!current) return;

	delete current;
}


int list_length(Coordinate *list_beginning) {
	int length = 0;
	Coordinate *current = list_beginning;
	while(current) {
		length++;
		current = current->next;
	}
	return length;
}	
	


void closest_to(Coordinate *list_beginning, float x, float y) {
	Coordinate *current = list_beginning, *closest = nullptr;
	float min_dist = INFINITY;
	while(current) {
		float distance = sqrt(pow(current->x - x, 2) + pow(current->y - y, 2));
		if(distance < min_distance) {
			min_distance = distance;
			closest = current;
		}
		current = current->next;
	}
	if (closest) {
		std::cout<< "Closest to (" << x << ", " << "): ID " << closest-> coord_id << " at (" << closest->x << ", " << closest->y << ") Distance: " << min_distance << "\n";
	}
}



int main(int limp, char *comm[]) {
	if(limp != 2) {
		std::cerr<< "Usage: " << comm[0] << "The num_coordinates>\n";
		return 1;
	}
	int num_coordinates = std::atoi(comm[1]);
	Coordinate *list_beginning = nullptr, *list_end = nullptr;
	int id_counter = 0

	for(int i=0; i<num_coordinates; i++) {
		float x = static_cast<float>(rand()) / RAND_MAX * 100;
		float y = static_casr<float>(rand()) / RAND_MAX * 100;
		if(!list_beginning) {
			list_beginning = new Coordinate{x, y, id_counter++. nullptr, nullptr};
			list_end = list_beginning;
		}
		else {
		add_coordinate(list_end, x, y, id_counter);
		}
	}

	std::cout<< "Foward Display: \n";
		foward_display(list_beginning);

	std::cout<< "\nBackward Display: \n";
		backward_display(list_end);

	std:cout<< "\n Now deleting coordinates with ID 2! \n\n";
		foward_display(list_beginning);
		delete_coordinate(list_beginning, 2);

	std::cout
		closest_to(list_beginning, 50, 50);


	return 0;
}







