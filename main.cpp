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
Project(string name)
{
ifstream file(name);
file >> G >> num_of_n >> delta_t;
//Allocating Memory needed 
force = new vec[num_of_n];
momentum = new vec[num_of_n];
position = new vec[num_of_n];
mass = new double[num_of_n];
for(int i = 0; i < num_of_n; i++)
{
file >> mass[i];
file >> position[i].x >> position[i].y >> position[i].z;
file >> momentum[i].x >> momentum[i].y >> momentum[i].z;
momentum[i].x *=mass[i];
momentum[i].y *=mass[i];
momentum[i].z *=mass[i];
}
}
~Project()
{
    //Cleaning up heap 
    delete[] force;
    delete[] momentum;
    delete[] position;
    delete[] mass;
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
/*
Side Note 
f12 = force[0]          p1 = momentum[0]        r1 = position[0] DESCRIBES MASS 1       m1 = mass[0]
f21 = force[1]          p2 = momentum[1]        r2 = position[1] DESCRIBES MASS 2       m2 = mass[1]
*/
vec *force; //This force pointer will point into a array of forces needed 
vec *momentum; //This momentum pointer will point into an array of momentums needed 
vec *position; //This position pointer will point into an array of positions needed 
vec r;  //r is the postion vector of the distance between R1 to R2 
double *mass; //This Mass pointer will point into an array of masses needed 
double delta_t;
double G; //Newtons gravitational const
int num_of_n;
};

int main()
{
string FileName = "input.txt";
Project obj(FileName);


return 0;
}
