#ifndef COORDINATE_H
#define COORDINATE_H

#include <iostream>
#include <cmath>

struct _coordinate {
    float x;
    float y;
    int coord_id;
    struct _coordinate *next;
    struct _coordinate *previous;
};

typedef struct _coordinate Coordinate;

 void add_coordinate(Coordinate *&head, Coordinate *&tail, float x, float y);
 void forward_display(Coordinate *list_beginning);
 void backward_display(Coordinate *list_end);
 void delete_coordinate(Coordinate *&head, Coordinate *&tail, int coord_id_to_delete);
 int list_length(Coordinate *list_beginning);
 void closest_to(Coordinate *list_beginning, float x, float y);

#endif
