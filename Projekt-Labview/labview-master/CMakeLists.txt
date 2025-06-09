cmake_minimum_required(VERSION 3.10)

# Set some basic project attributes
project (labview
	VERSION 0.1)

# This project will output an executable file
add_executable(labview2 
	main.cpp
	# test1()	
	AbstractSource.cpp HelloSource.cpp WorldSource.cpp
	AbstractSink.cpp NormalCoutSink.cpp
	# test2()
	AbstractTransform.cpp Concatenate.cpp
	# test3() i test4()
	ModuleLink.cpp DynamicModuleLink.cpp
	# test5()
	LabView.cpp
	# test6()	
	ModuleFactory.cpp
)

target_compile_options(labview2 PRIVATE -Wall -Wextra)
target_compile_features(labview2 PUBLIC cxx_std_20)

