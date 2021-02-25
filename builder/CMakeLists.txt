add_executable(without-builder wbuild.cpp)
set_target_properties(without-builder PROPERTIES
	CMAKE_CXX_STANDARD 17
	CMAKE_CXX_STANDARD_REQUIRED ON
	CMAKE_CXX_EXTENSIONS OFF)

add_executable(builder builder.cpp)
set_target_properties(builder PROPERTIES
	CMAKE_CXX_STANDARD 17
	CMAKE_CXX_STANDARD_REQUIRED ON
	CMAKE_CXX_EXTENSIONS OFF)

add_executable(fluent-builder fluent_builder.cpp)
set_target_properties(fluent-builder PROPERTIES
	CMAKE_CXX_STANDARD 17
	CMAKE_CXX_STANDARD_REQUIRED ON
	CMAKE_CXX_EXTENSIONS OFF)

add_executable(groovy-style-builder groovy_style_builder.cpp)
set_target_properties(groovy-style-builder PROPERTIES
	CMAKE_CXX_STANDARD 17
	CMAKE_CXX_STANDARD_REQUIRED ON
	CMAKE_CXX_EXTENSIONS OFF)

add_executable(builder-facets fluent_builder.cpp)
set_target_properties(fluent-builder PROPERTIES
	CMAKE_CXX_STANDARD 17
	CMAKE_CXX_STANDARD_REQUIRED ON
	CMAKE_CXX_EXTENSIONS OFF)


