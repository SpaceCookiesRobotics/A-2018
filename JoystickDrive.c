#pragma config(Motor,  port1,           l_drive,       tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           r_drive,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           l_puncher,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           r_puncher,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           tread,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           l_cascade,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           r_cascade_top, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          r_cascade_bot, tmotorVex393_HBridge, openLoop, reversed)

void setleft (int speed){
	motor[l_drive]=speed;
}
void setright (int speed)
	motor[r_drive]=speed;
}

void puncher () {
	if (vexRT[Btn5U] == 1)       	//If button 5U is pressed...
	{
		motor[l_puncher] = 127; //...raise the arm.
		motor[r_puncher] = 127;
	}
	else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
	{
		motor[l_puncher] = -127; //...lower the arm.
		motor[r_puncher] = -127;
	}
	else                      		//Else (neither button is pressed)...
	{
		motor[l_puncher] = 0;      	//...stop the arm.
		motor[r_puncher] = 0;
	}
}

void tanktread () {
	if(vexRT[Btn6U] == 1)  //if button 6U is pressed take in ball
		{
		motor[tread] = 127;
		}
	else if(vexRT[Btn6D] == 1) //if button 6D is pressed tank tread go opposite direction
		{
		motor[tread] = -127;
		}
	else
		{
		motor[tread] = 0;  //else tank tread stops
		}
}

task main()
{
while (1==1){                        //all on one joystick
	setleft (vexRT[Ch3]+vexRT[Ch4]);   //vertical + horizontal
	setright(vexRT[Ch3]-vexRT[Ch4]);   //vertical - horizontal
	puncher ();
	tanktread ();
}
}
