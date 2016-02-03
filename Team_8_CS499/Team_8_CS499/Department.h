#include <vector>
#include "Course.h"

#pragma once

class Department
{

	private:

	public:
		Department();
		~Department();

		std::vector<Course> courses;
};