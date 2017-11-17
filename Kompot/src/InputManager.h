#ifndef _INPUT_MANAGER_H
#define _INPUT_MANAGER_H

#include <unordered_map>
#include <glm\glm.hpp>

class InputManager
{
public:
	InputManager();
	~InputManager();

	//keyboard funcs
	void PressKey(unsigned int key);
	void ReleaseKey(unsigned int key);
	bool IsKeyDown(unsigned int key);

	//mouse funcs
	void SetMouseCoords(float x, float y);
	glm::vec2 GetMouseCoords()const { return m_mouseCoords; }

private:
	std::unordered_map<unsigned int, bool>m_keyMap;
	glm::vec2 m_mouseCoords;

};

#endif
