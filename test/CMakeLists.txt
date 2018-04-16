file(GLOB SRCS *.cpp)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_executable(testHidatoGenerator ${SRCS} ../hidato/HidatoGenerator.h ../hidato/HidatoGenerator.cpp)

target_link_libraries(testHidatoGenerator
        gtest
        gmock
        )

include_directories("..")

install(TARGETS testHidatoGenerator DESTINATION bin)