# Copyright Benoit Blanchon 2014-2017
# MIT License
# 
# Arduino JSON library
# https://bblanchon.github.io/ArduinoJson/
# If you like this project, please add a star!

add_executable(DynamicJsonBufferTests 
	alloc.cpp
	array.cpp
	no_memory.cpp
	# object.cpp
	strdup.cpp
	# string.cpp
)

target_link_libraries(DynamicJsonBufferTests catch)
add_test(DynamicJsonBuffer DynamicJsonBufferTests)
