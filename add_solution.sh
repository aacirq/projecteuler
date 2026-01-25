#!/bin/bash

# Usage: ./add_solution.sh <problem_id>
# Example: ./add_solution.sh 1

problem_id=$1
dir_name="problem${problem_id}"
mkdir ${dir_name}
touch ${dir_name}/main.cpp
echo -e "add_solver(problem${problem_id} main.cpp)" >> ${dir_name}/CMakeLists.txt
echo -e "add_subdirectory(problem${problem_id})" >> CMakeLists.txt
echo -e "#include <iostream>\n\nint main()\n{\n    return 0;\n}" >> ${dir_name}/main.cpp
