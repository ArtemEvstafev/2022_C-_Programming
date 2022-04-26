# CMakeList.txt: проект CMake для HomeTasks; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("HomeTasks")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (HomeTasks "HomeTasks.h" "Task3.cpp")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
