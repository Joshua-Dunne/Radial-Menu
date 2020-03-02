/// <summary>
/// @author Joshua Dunne
/// @dates 16/09/19, 17/09/19, 18/09/19, 07/10/19
/// @estimated_time 10 hours
/// @actual_time 9 hours
/// </summary>

#include "Xbox360Controller.h"

Xbox360Controller::Xbox360Controller()
{
	Xbox360Controller::m_Joystick_index = 0;
}

Xbox360Controller::~Xbox360Controller()
{
}

void Xbox360Controller::update()
{
	m_previousState = m_currentState; // the previous state is now our current state
	isPressed();
	checkLeftStick();
	checkRightStick();
	checkDPad();
	checkTriggers();
}

/// <summary>
/// Check if a controller is connected
/// </summary>
/// <param name="controllerNum">Controller Num</param>
/// <returns>If that controller is connected</returns>
bool Xbox360Controller::isConnect(unsigned int controllerNum)
{
	bool isConnected = false;

	if (sf::Joystick::isConnected(controllerNum))
	{
		isConnected = true;
	}

	return isConnected;
}

/// <summary>
/// Check if a Button is Pressed, and set state of buttons
/// </summary>
void Xbox360Controller::isPressed()
{
	if(sf::Joystick::isButtonPressed(0, 0)) // Controller 1 Presses A
	{
		m_currentState.A = true;
	}
	else
	{
		m_currentState.A = false;

	}

	if (sf::Joystick::isButtonPressed(0, 1))  // Controller 1 Presses B
	{
		m_currentState.B = true;
	}
	else
	{
		m_currentState.B = false;
	}

	if (sf::Joystick::isButtonPressed(0, 2))  // Controller 1 Presses X
	{
		m_currentState.X = true;
	}
	else
	{
		m_currentState.X = false;
	}

	if (sf::Joystick::isButtonPressed(0, 3))  // Controller 1 Presses Y
	{
		m_currentState.Y = true;
	}
	else
	{
		m_currentState.Y = false;
	}

	if (sf::Joystick::isButtonPressed(0, 4))  // Controller 1 Presses Left Bumper
	{
		m_currentState.LB = true;
	}
	else
	{
		m_currentState.LB = false;
	}

	if (sf::Joystick::isButtonPressed(0, 5))  // Controller 1 Presses Right Bumper
	{
		m_currentState.RB = true;
	}
	else
	{
		m_currentState.RB = false;
	}

	if (sf::Joystick::isButtonPressed(0, 6))  // Controller 1 Presses Back
	{
		m_currentState.Back = true;
	}
	else
	{
		m_currentState.Back = false;
	}

	if (sf::Joystick::isButtonPressed(0, 7))  // Controller 1 Presses Start
	{
		m_currentState.Start = true;
	}
	else
	{
		m_currentState.Start = false;
	}

	if (sf::Joystick::isButtonPressed(0, 8))  // Controller 1 Presses Left Stick
	{
		m_currentState.LeftThumbStickClick = true;
	}
	else
	{
		m_currentState.LeftThumbStickClick = false;
	}

	if (sf::Joystick::isButtonPressed(0, 9))  // Controller 1 Presses Right Stick
	{
		m_currentState.RightThumbStickClick = true;
	}
	else
	{
		m_currentState.RightThumbStickClick = false;
	}
}

/// <summary>
/// Change the values of the Left Stick as it's used
/// </summary>
void Xbox360Controller::checkLeftStick()
{
	m_currentState.LeftThumbStick = sf::Vector2f{ sf::Joystick::getAxisPosition(0, sf::Joystick::X),
												  sf::Joystick::getAxisPosition(0, sf::Joystick::Y)};
}

/// <summary>
/// Change the values of the Right Stick as it's used
/// </summary>
void Xbox360Controller::checkRightStick()
{
	m_currentState.RightThumbStick = sf::Vector2f{ sf::Joystick::getAxisPosition(0, sf::Joystick::U),
													sf::Joystick::getAxisPosition(0, sf::Joystick::V)};
}

/// <summary>
/// See if the D-Pad is currently being used
/// </summary>
void Xbox360Controller::checkDPad()
{
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) > DPAD_THRESHOLD)
	{
		m_currentState.DpadRight = true;
	}
	else
	{
		m_currentState.DpadRight = false;
	}

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovX) < -DPAD_THRESHOLD)
	{
		m_currentState.DpadLeft = true;
	}
	else
	{
		m_currentState.DpadLeft = false;
	}

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) > DPAD_THRESHOLD)
	{
		m_currentState.DpadUp = true;
	}
	else
	{
		m_currentState.DpadUp = false;
	}

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::PovY) < -DPAD_THRESHOLD)
	{
		m_currentState.DpadDown = true;
	}
	else
	{
		m_currentState.DpadDown = false;
	}
}

/// <summary>
/// See if the Left or Right Triggers are being used
/// </summary>
void Xbox360Controller::checkTriggers()
{
	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) > TRIGGER_MINIMUM)
	{
		m_currentState.LTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
	}
	else
	{
		m_currentState.LTrigger = 0;
	}

	if (sf::Joystick::getAxisPosition(0, sf::Joystick::Z) < -TRIGGER_MINIMUM)
	{
		m_currentState.RTrigger = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
	}
	else
	{
		m_currentState.RTrigger = 0;
	}
}
