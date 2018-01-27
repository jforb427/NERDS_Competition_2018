/*
 * Robot.hpp
 *
 *  Created on: Jan 9, 2018
 *      Author: Local Admin
 */

#include <memory>

#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include "CommandBase.h"

class RSub {
public:
	static RSub* GetInstance();
	std::unique_ptr<OI> r_oi;
	std::unique_ptr<DriveTrain> r_drivetrain;
private:
	RSub();
	static RSub* instance;
};

class Robot: public frc::IterativeRobot {
public:
	Robot();
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;
private:
	std::unique_ptr<frc::Command> updateValues;
	std::unique_ptr<frc::Command> autonomousCommand;
	frc::SendableChooser<frc::Command*> chooser;
};


