#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
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
file >> G >> bodies >> delta_t >> amount;
//Allocating Memory needed 
force = new vec[bodies];
momentum = new vec[bodies];
position = new vec[bodies];
mass = new double[bodies];
r = new vec[bodies];
for(int i = 0; i < bodies; i++)
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
    delete[] r;
}
//HARD CODED FIX LATER !!!!!
void simulate()
{
//This file will contain the position coords of M2 (star)
ofstream star("Star.txt");
ofstream blackhole("Blackhole.txt");
blackhole << "Position Vector Of blackhole Orbiting with star" << endl;
blackhole << position[0].x << ", " << position[0].y << endl;  
star << "Position Vector Of star Orbiting around blackhole" << endl;
star << position[1].x << ", " << position[1].y << endl; 
for(int i = 0; i < amount;i++)
{
    //Computed distance between r1 and r2 
    r[0] = subVector(position[1] ,position[0]); //Computes r_12
    r[1] = subVector(position[0] , position[1]); //Computes r_21
    force[0] = scaleVector((-G*mass[0]*mass[1])/pow(Magnitude(r[0]),3),r[0]); //Computes Force_12
    force[1] = scaleVector((-G*mass[0]*mass[1])/pow(Magnitude(r[1]),3),r[1]); //Computes Force_21
    momentum[0] = addVector(momentum[0],scaleVector(delta_t,force[0])); //Computes P'_1 (New Momentum)
    momentum[1] = subVector(momentum[1],scaleVector(delta_t,force[0])); //Computes P'_2 (New Momentum)
    position[0] = addVector(position[0],scaleVector(delta_t/mass[0],momentum[0])); //Computes R'1 star
    position[1] = addVector(position[1],scaleVector(delta_t/mass[1],momentum[1])); //Computes R'2 blackhole
    star << position[1].x << ", " << position[1].y << endl;
    blackhole << position[0].x << ", " << position[0].y << endl;
}
}

vec scaleVector(double a, vec v)
{
   vec c = {v.x*a,v.y*a,v.z*a};
   return c;
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
vec subVector(vec v1, vec v2)
{
    vec c = {v1.x -v2.x, v1.y - v2.y, v1.z -v2.z};
    return c;
}
vec addVector(vec v1, vec v2)
{
vec v = {v1.x + v2.x,v1.y + v2.y, v1.z + v2.z};
return v;
}

void printVector(vec v)
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
vec *r;  //r is the postion vector of the distance between R1 to R2 
double *mass; //This Mass pointer will point into an array of masses needed 
double delta_t;
double G; //Newtons gravitational const
int bodies; //N number of bodies
int amount; //Amount to do loop 
};

int main()
{
string FileName = "o.txt";
Project obj(FileName);
obj.simulate();//Simulates A Star orbiting a blackhole

return 0;
}
