#pragma config(Motor,  port2,           rf,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rm,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           lb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           lfm,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           lpuncher,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           rb,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           rpuncher,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           tread,         tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "../Shared/Competition.h"

void setleft (int speed){
	motor[lfm]=speed;
	motor[lb]=speed;
}

void setright (int speed){
	motor[rf]=speed;
	motor[rm]=speed;
	motor[rb]=speed;
}

void drive (int s, int time){
	setleft(s);
	setright(s);
	wait1Msec(time);
}

void puncherauton (int time) {
	motor [lpuncher]=127;
	motor [rpuncher]=127;
	waitMsec (time);
}

void autonomous() //auton punches ball annd flips low flag
{
	puncherauton (2000);
	drive (127, 2000);
	drive (-127, 1000);
	drive (0, 5000);
}


void puncherprogram () {
	if (vexRT[Btn5UXmtr2] == 1)      //If button 5D is pressed...
	{
		motor[lpuncher] = 127; 	//...raise the arm.
		motor[rpuncher] = 127; 	//...raise the arm.
	}
	else                      	//Else (neither button is pressed)...
	{
		motor[lpuncher] = 0;     //...stop the puncher.
		motor[rpuncher] = 0;     //...stop the puncher.
	}
}
void tanktread () {
	if (vexRT[Btn6UXmtr2] == 1)      //If button 6U is pressed...
	{
		motor[tread] = 127; 	//... the claw spin
	}
	else
	if (vexRT[Btn6UXmtr2] == 0)      //If button 6U is pressed...
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
