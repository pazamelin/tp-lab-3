//
//  Circle.hpp
//  Third Shtanyuk's lab
//
//  Created by Коля on 16/12/2019.
//  Copyright © 2019 Коля. All rights reserved.
//

#ifndef Circle_hpp
#define Circle_hpp

#include <cmath>

class Circle {
private:
    double radius, ference, area;
public:
    Circle(double);
    
    void setRadius(double);
    
    void setFerence(double);
    
    void setArea(double);
    
    double getRadius();
    
    double getFerence();
    
    double getArea();
};

#endif /* Circle_hpp */
