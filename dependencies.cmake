include(FetchContent)
include(ExternalProject)
#========= Req ==========#
find_package(CURL REQUIRED)
find_package(LibXml2 REQUIRED)


FetchContent_Declare(
	SDL342	
	GIT_REPOSITORY git@github.com:libsdl-org/SDL.git
	GIT_TAG        release-3.4.2
)
FetchContent_MakeAvailable(SDL342) # might need to be placed together with robots

#========= GTest ==========#
if (CMAKE_TESTING_ENABLED)
	set(CMAKE_CXX_STANDARD 14)
	set(CMAKE_CXX_STANDARD_REQUIRED ON)

	FetchContent_Declare(
		googletest
		GIT_REPOSITORY https://github.com/google/googletest.git
		GIT_TAG        v1.17.0
	)

	# For Windows: Prevent overriding the parent project's compiler/linker settings
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest) # might need to be placed together with robots
endif()
