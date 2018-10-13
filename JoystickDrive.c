#pragma config(Motor,  port1,           claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           r_drive,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           l_drive,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           l_puncher,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           r_puncher,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           tread,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           l_cascade_bot, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           r_cascade_top, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          r_cascade_bot, tmotorVex393_HBridge, openLoop, reversed)

void setleft (int speed){
	motor[l_drive]=speed;
}
void setright (int speed){
	motor[r_drive]=speed;
}

void puncher () {
	if (vexRT[Btn5UXmtr2] == 1)      //If button 5U is pressed...
	{
		motor[l_puncher] = 127; 	//...raise the arm.
		motor[r_puncher] = 127;
	}
	else if(vexRT[Btn5DXmtr2] == 1)  //Else, if button 5D is pressed...
	{
		motor[l_puncher] = -127; 	//...lower the arm.
		motor[r_puncher] = -127;
	}
	else                      	//Else (neither button is pressed)...
	{
		motor[l_puncher] = 0;     //...stop the arm.
		motor[r_puncher] = 0;
	}
}

void tanktread () {
	motor[tread] = vexRT[Ch2];
}
void cascadebottom (int speed) {
	motor[l_cascade_bot] = speed;       // when joystick channel 2 on partner joystick moved left moves
	motor[r_cascade_bot] = speed;
}
void cascadetop (int speed) {
	motor[r_cascade_top] = speed;  //when joystick channel 4 on partner joystick moved top moves
}
void clawflip () {
	if (vexRT[Btn6UXmtr2] == 1)      //If button 6U is pressed...
	{
		motor[claw] = 127; 	//... the claw spin
	}
	else if(vexRT[Btn6DXmtr2] == 1)  //Else, if button 6D is pressed...
	{
		motor[claw] = -127; 	//...lower the claw
	}
	else                      	//Else (neither button is pressed)...
	{
		motor[claw] = 0;     //...stop the claw
	}
}

task main()
{
while (1==1){                        //all on one joystick
	setleft (vexRT[Ch3]+vexRT[Ch4]);   //vertical + horizontal
	setright(vexRT[Ch3]-vexRT[Ch4]);   //vertical - horizontal
	puncher ();
	tanktread ();
	cascadebottom (vexRT[Ch3Xmtr2]);  //all on partner joystick
	cascadetop (vexRT[Ch2Xmtr2]);
	clawflip ();
}
}
