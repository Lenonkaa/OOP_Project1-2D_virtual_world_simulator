//
// Created by lenai on 4/14/2026.
//

#ifndef OOP1_POINT_H
#define OOP1_POINT_H

struct Point
{
    bool operator==(const Point& other) const {
        return (x == other.x && y == other.y);
    }

    int x;
    int y;


};


#endif //OOP1_POINT_H