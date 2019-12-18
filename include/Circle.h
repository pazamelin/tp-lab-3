#ifndef Circle_h
#define Circle_h

#include <stdio.h>
#include <cmath>

// Разработать класс Circle (круг), содержащий следующие поля:

// radius - радиус
// ference - длина окружности
// area - площадь круга
// Данные поля рекомендуется объявить как переменные типа double и с модификатором доступа private для безопасности. Доступ к этим полям следует ограничить с помощью методов класса.

// В класс Circle включить конструктор, принимающий значение радиуса.

// Класс должен обязательно содержать методы:

// setRadius()
// setFerence()
// setArea()
// getRadius()
// getFerence()
// getArea()
// Замечание

// при установке значения радиуса пересчитывать длину окружности и пощадь;
// при установке длины окружности пересчитывать радиус и площадь;
// при установке площади пересчитывать радиус и длину окружности.
// При помощи класса Circle решить две вспомогательные задачи:

class Circle{
private:
    double radius;
    double ference;
    double area;
public:
    Circle(double radius_value);
    void setRadius(double radius_value);
    void setFerence(double ference_value);
    void setArea(double area_value);
    double getRadius();
    double getFerence();
    double getArea();
};

#endif /* Circle_h */
