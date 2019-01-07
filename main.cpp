#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <stdlib.h>


using namespace std;


typedef struct{
double  x,y,z;
} vec;


class Project{
public:
Project()
{
cout << "NO FILE INPUTTED" << endl;
}
Project(ifstream file)
{
file >> G >> num_of_n >> delta_t;
}
double Magnitude(vec v)
{
return sqrt(v.x *v.x + v.y*v.y + v.z*v.z);
}

//This function will return the unit vector of a vector (or in other words the direction)
vec getUnit(vec v) 
{
double mag = Magnitude(v);
v.x = v.x/mag;
v.y = v.y/mag;
v.z = v.z/mag;
return v;
}
vec addVector(vec v1, vec v2)
{
vec v;
v.x = v1.x + v2.x;
v.y = v1.y + v2.y;
v.z = v1.z + v2.z;
return v;
}

void PrintVector(vec v)
{
cout << "X component of Vector: " << v.x << endl;
cout << "Y component of Vector: " << v.y << endl;
cout << "Z component of Vector: " << v.z << endl; 
}
private:
vec force_12; //Force M1 applies to M2
vec force_21; //Force M2 applies to M1
vec p1; //p1 is momentum of M1
vec p2; //p2 is momentum of M2
vec r1; //r1 is the postion vector of M1 
vec r2; //r2 is the postion vector of M2
vec r;  //r is the postion vector of the distance between R1 to R2 
double m1; //This is the mass of m1 
double m2; //This is the mass of m2
double delta_t;
double G; //Newtons gravitational const
double num_of_n;
};
int main()
{
vec Pos_m1;
Pos_m1.x = 23;
Pos_m1.y = 12;
Pos_m1.z = 0;
Project obj;

Pos_m1 = obj.getUnit(Pos_m1);
obj.PrintVector(Pos_m1);

return 0;
}
