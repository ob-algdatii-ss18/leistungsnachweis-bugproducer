file(GLOB SRCS *.cpp)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_executable(testPlayGround ${SRCS} ../hidato/PlayGround.h ../hidato/PlayGround.cpp)

target_link_libraries(testPlayGround
        gtest
        gmock
        )

include_directories("..")

install(TARGETS testPlayGround DESTINATION bin)