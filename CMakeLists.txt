cmake_minimum_required(VERSION 3.19)

project(cpp-design-patterns VERSION 0.0.1
	LANGUAGES CXX)

find_package(Boost REQUIRED)

add_subdirectory(builder)
