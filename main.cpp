#include "coordinate.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cout << "Usage: ./main <number_of_coordinates>\n";
        return 1;
    }

    int num_coordinates = atoi(argv[1]);
    if (num_coordinates <= 0) {
        cout << "Enter a valid positive integer for coordinates.\n";
        return 1;
    }

    srand(time(0));

    Coordinate *head = NULL, *tail = NULL;

    for (int i = 0; i < num_coordinates; i++) {
    float x = (rand() % 100) / 10.0;
    float y = (rand() % 100) / 10.0;
    add_coordinate(head, tail, x, y);
    if (!head) head = tail;  // Ensure head points to the first element
}


    cout << "\nCoordinates List (Forward Order):\n";
    forward_display(head);

    cout << "\nCoordinates List (Backward Order):\n";
    backward_display(tail);

    int delete_id = 2;
    cout << "\nDeleting coordinate with ID " << delete_id << "...\n";
    delete_coordinate(head, tail,  delete_id);
    
    cout << "\nUpdated List (Forward Order):\n";
    forward_display(head);

    float test_x = 5.0, test_y = 5.0;
    cout << "\nFinding closest coordinate to (" << test_x << ", " << test_y << ")...\n";
    closest_to(head, test_x, test_y);

	Coordinate *current = head;
while (current) {
    Coordinate *next = current->next;
    delete current;
    current = next;
}

    return 0;
}

