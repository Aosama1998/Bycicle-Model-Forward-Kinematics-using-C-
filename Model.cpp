#include <iostream>
#include <cmath>
using namespace std;

#define pi 3.14159265359

// Assume the value of the angular speed (W) of both the front tire and the rear tires are the same 

int main(){

float w =10; // constant angular speed of wheel at any time
float r =0.25; // Radius from the point of rotation to the CG of the Vehicle 

float alpha =0; // side slipping angle of the Vehicle 
float X_CG = 0 ; // X pos of the CG of the wheel
float Y_CG = 0 ; // Y pos of the CG of the wheel
float lr =0.5 ; //distance from center of any wheel to center of gravity
float theta_dot; // the rate of change of the bycicle's direction
float input[2]; // array of 2 which consits of the 2 inputs

input[0] = r*w; // Linear speed of bycicle 
input[1]= pi/6;  // Steering angle 


float output[3] ={0,0,0};  // this array contains the new X , Y Values of the CG Point after performing each iteration of calculations 
float sample_time =0.1 ;  // how often do I want to do these calculations 
float theta = 0; // actual angle the bycicle has rotated starting from the starting point 
float l =1;
int count=0;
for (int j =0; j<300; j++)
{
alpha=atan(  ( lr*(tan(input[1] )/l)  )  );
X_CG = ( input[0] ) * ( cos(theta+alpha) );
Y_CG = ( input[0] ) * ( sin(theta+alpha) );
theta_dot = input[0]*cos(alpha)*tan(input[1])/l;
output[0]+=X_CG*sample_time;
output[1]+=Y_CG*sample_time;
theta+=theta_dot*sample_time;
output[2]=theta;
output[2]=remainder(theta,2*pi); // Here because we don't want the theta to keep incrementing indefinetly, always subtract 360 from it to keep it under the 360 value


// Printing the values of the outputs 
cout <<" The new X Position is: " <<output[0]<<"      \n";
cout <<" The new y Position is: " <<output[1]<<"    \n";
cout <<" The new theta value is: " <<output[2]<<"   \n";



}

}

