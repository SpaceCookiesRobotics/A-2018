#pragma config(Motor,  port2,           lm,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           lb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           rf,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           rmb,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           lpuncher,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           rb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rpuncher,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           tread,         tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "../Shared/Competition.h"

void autonomous()
{
}

/*void pointturnright (){
	motor[r_drive] = -127;
	motor[l_drive] = 127;
	wait1Msec();       //time needs to be adjusted after testing
}

void puncher1 () {
	motor[l_puncher] = 127;
	motor[r_puncher] = 127;
	wait1Msec(5000);
}

void driveforward (int time){
	motor[l_drive] = 127;
	motor[r_drive] = 127;
	wait1Msec(time);
}
void autonomous()
{
driveforward (2000);
pointturnright ();
puncher1 ();
driveforward (5000);
}*/

void setleft (int speed){
	motor[lf]=speed;
	motor[lm]=speed;
	motor[lb]=speed;
}

void setright (int speed){
	motor[rf]=speed;
	motor[rmb]=speed;
}

void puncherprogram () {
	if (vexRT[Btn5DXmtr2] == 1)      //If button 5D is pressed...
	{
		motor[lpuncher] = 127; 	//...raise the arm.
		motor[rpuncher] = 127; 	//...raise the arm.
	}
	else if(vexRT[Btn5UXmtr2] == 1)  //Else, if button 5U is pressed...
	{
		motor[lpuncher] = -127; 	//...lower the arm.
		motor[rpuncher] = -127; 	//...lower the arm.
	}
	else                      	//Else (neither button is pressed)...
	{
		motor[lpuncher] = 0;     //...stop the arm.
		motor[rpuncher] = 0;     //...stop the arm.
	}
}
void tanktread () {
	if (vexRT[Btn6U] == 1)      //If button 6U is pressed...
	{
		motor[tread] = 127; 	//... the claw spin
	}
	else
	if (vexRT[Btn6U] == 0)      //If button 6U is pressed...
	{
		motor[tread] = 0; 	//... the claw spin
	}
}

void joystick()
{
while (1==1){
	setleft(vexRT[Ch3]);
	setright(vexRT[Ch2]);
	puncherprogram ();
	tanktread ();
}
}
