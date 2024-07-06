cmake_minimum_required(VERSION 3.20)

project(crepl)

add_executable(crepl main.c str.c scanner.c)

# Installing binary and headers
#
# suppose we are in the root directory of the project
# our binary directory is build/
# 
# ----------
# If we want to install to system we need administrative previliges.
# And the cmake command will be:
# cmake --install ./build/
# ----------
# If we want to install to a specific directory we can use the following command:
# cmake --install ./build/ --prefix /path/to/install
# NOTE: we may not need administrative previliges to install in this case.
# ----------

install(TARGETS crepl DESTINATION bin)
install(FILES str.h scanner.h DESTINATION include)