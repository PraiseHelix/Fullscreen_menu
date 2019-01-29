#pragma once
#include <iostream>
#include "listener_dummy.hpp"

class listener_dummy : public option_listener {
public:
	virtual void is_pressed(const std::string & string) override { std::cout << string << std::endl; }
};