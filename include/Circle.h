//
//  Cricle.h
//  lab3 software
//
//  Created by Андрей Журавлев on 11.10.2019.
//  Copyright © 2019 Андрей Журавлев. All rights reserved.
//

#ifndef Cricle_h
#define Cricle_h
#include <cmath>

class Circle {
private:
    double _radius, _ference, _area;
public:
    Circle(double rad);
    
    void setRadius(double x);
    
    void setFerence(double x);
    
    void setArea(double x);
    
    double getRadius();
    
    double getFerence();
    
    double getArea();
};

#endif /* Cricle_h */
