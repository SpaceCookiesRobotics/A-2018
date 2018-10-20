#pragma config(Motor,  port1,           claw,          tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           r_drive,       tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           l_drive,       tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           l_puncher,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           r_puncher,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           tread,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           l_cascade_bot, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           r_cascade_top, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          r_cascade_bot, tmotorVex393_HBridge, openLoop, reversed)

void drivestraight (int time){
	motor[l_drive] = 127;
	motor[r_drive] = 127;
	wait1Msec(time);
}
void turnLeft (int time) { //point turn
  motor[l_drive] = -127;
  motor[r_drive] = 127;
  wait1Msec(time);
}

void turnRight (int time) { //point turn
	motor[l_drive] = 127;
	motor[r_drive] = -127;
	wait1Msec(time);
}

task main()
{
	drivestraight(3000); //robot should be on the left side of the field
	turnLeft(2000);
	drivestraight(5000); //robot should be on the alliance platform

	/*drivestraight(3000); //robot starts on the right side of the field
	turnRight(2000);
	drivestraight(5000); //robot should be on the alliance platform*/
}
