#pragma once

#include <iostream>
#include "generic_option.hpp"

class option_listener {
public:
	virtual void is_pressed(const std::string & string) = 0;
};