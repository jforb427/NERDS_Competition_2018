#include "WristDown.h"

WristDown::WristDown() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(&grabber);
	checkKeys();
}

// Called just before this Command runs the first time
void WristDown::Initialize() {
	getPreferences();
	grabber.SetWrist(angle);
}

// Called repeatedly when this Command is scheduled to run
void WristDown::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool WristDown::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void WristDown::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WristDown::Interrupted() {

}

void WristDown::getPreferences(){
	double p = Preferences::GetInstance()->GetDouble("Wrist/P", 0.1);
	double i = Preferences::GetInstance()->GetDouble("Wrist/I", 0.0);
	double d = Preferences::GetInstance()->GetDouble("Wrist/D", 0.0);
	double f = Preferences::GetInstance()->GetDouble("Wrist/F", 0.0);

	double maxSpeed = Preferences::GetInstance()->GetDouble("Wrist/Max Speed", 1);

	angle = Preferences::GetInstance()->GetDouble("Wrist/Wrist Down Angle", 1);

	grabber.SetPID(f, p, i, d);
	grabber.SetMaxSpeed(maxSpeed);
}

void WristDown::checkKeys(){
	if (!Preferences::GetInstance()->ContainsKey("Wrist/P")) {
		Preferences::GetInstance()->PutDouble("Wrist/P", 0.1);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/I")) {
		Preferences::GetInstance()->PutDouble("Wrist/I", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/D")) {
		Preferences::GetInstance()->PutDouble("Wrist/D", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/F")) {
		Preferences::GetInstance()->PutDouble("Wrist/F", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Max Speed")) {
		Preferences::GetInstance()->PutDouble("Wrist/Max Speed", 0.0);
	}
	if (!Preferences::GetInstance()->ContainsKey("Wrist/Wrist Down Angle")) {
		Preferences::GetInstance()->PutDouble("Wrist/Wrist Down Angle", 0.0);
	}
}
