build:
	cmake --build --preset linux-debug
	
config:
	cmake --preset ci-linux-debug

test:
	ctest --preset linux-debug
