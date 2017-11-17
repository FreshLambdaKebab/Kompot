#include "InputManager.h"

InputManager::InputManager():
	m_mouseCoords(0.0f)
{
}

InputManager::~InputManager()
{
}

void InputManager::PressKey(unsigned int key)
{
	//if a key is pressed set it to true in the keymap
	m_keyMap[key] = true;
}

void InputManager::ReleaseKey(unsigned int key)
{
	//if a key is released set it to false in the key map
	m_keyMap[key] = false;
}

bool InputManager::IsKeyDown(unsigned int key)
{
	auto it = m_keyMap.find(key);
	if (it != m_keyMap.end()) {
		return it->second;
	}
	else {
		return false;
	}
	
}

void InputManager::SetMouseCoords(float x, float y)
{
	m_mouseCoords.x = x;
	m_mouseCoords.y = y;
}
