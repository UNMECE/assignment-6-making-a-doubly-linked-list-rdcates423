#include "coordinate.h"
#include <iostream>
#include <cmath>

using namespace std;

int global_id = 1;  // Tracks coord_id globally

void add_coordinate(Coordinate *&head, Coordinate *&tail,  float x, float y) {
    Coordinate *new_coord = new Coordinate;
    new_coord->x = x;
    new_coord->y = y;
    new_coord->coord_id = global_id++;
    new_coord->next = NULL;
    new_coord->previous = tail;

    if (tail) {
        tail->next = new_coord;
    } else {
    tail = new_coord;
   }
}

void forward_display(Coordinate *list_beginning) {
    Coordinate *temp = list_beginning;
    while (temp) {
        cout << "ID: " << temp->coord_id << " (" << temp->x << ", " << temp->y << ")\n";
        temp = temp->next;
    }
}

void backward_display(Coordinate *list_end) {
    Coordinate *temp = list_end;
    while (temp) {
        cout << "ID: " << temp->coord_id << " (" << temp->x << ", " << temp->y << ")\n";
        temp = temp->previous;
    }
}

void delete_coordinate(Coordinate *&head, Coordinate *&tail,  int coord_id_to_delete) {
    Coordinate *temp = head;
    while (temp) {
        if (temp->coord_id == coord_id_to_delete) {
            if (temp->previous) 
                temp->previous->next = temp->next;
            else 
                head = temp->next;  // Deleting first node

            if (temp->next) 
                temp->next->previous = temp->previous;
            else 
                tail  = temp->previous;  // Deleting last node

            delete temp;
            cout << "Deleted coordinate ID: " << coord_id_to_delete << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Coordinate ID " << coord_id_to_delete << " not found.\n";
}

int list_length(Coordinate *list_beginning) {
    int count = 0;
    Coordinate *temp = list_beginning;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void closest_to(Coordinate *list_beginning, float x, float y) {
    if (!list_beginning) {
        cout << "List is empty.\n";
        return;
    }

    Coordinate *closest = list_beginning;
    float min_distance = sqrt(pow(closest->x - x, 2) + pow(closest->y - y, 2));

    for (Coordinate *temp = list_beginning->next; temp; temp = temp->next) {
        float distance = sqrt(pow(temp->x - x, 2) + pow(temp->y - y, 2));
        if (distance < min_distance) {
            min_distance = distance;
            closest = temp;
        }
    }

    cout << "Closest coordinate to (" << x << ", " << y << ") is ID: "
         << closest->coord_id << " (" << closest->x << ", " << closest->y 
         << ") with distance " << min_distance << endl;
}

