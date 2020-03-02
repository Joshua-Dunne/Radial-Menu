#ifndef XBOX360CONTROLLER
#define XBOX360CONTROLLER
#endif

/// <summary>
/// @author Joshua Dunne
/// @dates 16/09/19, 17/09/19, 18/09/19, 07/10/19
/// @estimated_time 10 hours
/// @actual_time 9 hours
/// </summary>

#include <SFML/Graphics.hpp>
#include <iostream>

/// <summary>
/// data to store current state of the controller
/// </summary>

struct GamePadState
{
	bool A = false;
	bool B = false;
	bool X = false;
	bool Y = false;
	bool LB = false;
	bool RB = false;
	bool LeftThumbStickClick = false;
	bool RightThumbStickClick = false;
	bool DpadUp = false;
	bool DpadDown = false;
	bool DpadLeft = false;
	bool DpadRight = false;
	bool Start = false;
	bool Back = false;
	bool Xbox = false;
	float RTrigger = 0.0f;
	float LTrigger = 0.0f;
	sf::Vector2f RightThumbStick;
	sf::Vector2f LeftThumbStick;	
};


/// <summary>
/// Xbox Controller class to query current state of controller,
/// to mimic the controller states like Microsoft XNA.
/// </summary>

class Xbox360Controller
{
private:
	const int DPAD_THRESHOLD = 75; // Deadzone for D-Pad
	const float TRIGGER_MINIMUM = 0.5f;

public:
	// newly added for multiple controller support not required in your project
	// number of connected controllers
	static int s_noOfControllers;
	// index count for multiple controllers if connected
	int m_Joystick_index;
	// the current state of all the buttons
	GamePadState m_currentState; // What the buttons are like this update
	GamePadState m_previousState; // What the button were like last update

	Xbox360Controller(); // constructor
	~Xbox360Controller(); // destructor
	void update();
	bool isConnect(unsigned int controllerNum); // check if the controller is connected
	void isPressed(); // 0 is A, 1 is B, 2 is X, 3 is Y
	void checkLeftStick(); // see if the Left Stick has moved, and update value in GamePad State
	void checkRightStick(); // see if the Right Stick has moved, and update value in GamePad State
	void checkDPad(); // see if the Dpad has moved, and update value in GamePad State
	void checkTriggers();
	// see if the left trigger or right trigger are being used, update value in GamePad State

};

