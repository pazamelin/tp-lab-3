#pragma once


	class Circle
	{
	private:
		double radius;
		double ference;
		double area;
	public:
		Circle(double newRadius);
		void setRadius(double newRadius);
		void setFerence(double newFerence);
		void setArea(double newArea);
		double getRadius();
		double getFerence();
		double getArea();
	};