#pragma once

#include <iostream>

class Utils
{
public:
	inline int static getRandomNumber(int min, int max) { return min + (std::rand() % (max - min + 1)); }
};