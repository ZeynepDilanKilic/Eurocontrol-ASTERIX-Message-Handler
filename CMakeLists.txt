cmake_minimum_required(VERSION 3.16.0)
project(pAsterix VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include asterix-messages
add_subdirectory(asterix-messages)

# Project main directories
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
file(GLOB_RECURSE HEADER_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${INC_DIR}*.h")
file(GLOB_RECURSE SOURCE_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "${SRC_DIR}*.cpp")

# Ana proje kaynak dosyaları ve ASTERIX_MESSAGES dosyalarını birleştirin
set(ALL_SOURCES
    main.cpp
    ${HEADER_FILES}
    ${SOURCE_FILES}
    ${ASTERIX_MESSAGES_SOURCES}
)

# Yürütülebilir dosyayı oluşturun
add_executable(EurocontrolAsterixMessageHandle ${ALL_SOURCES})

# Include directories
include_directories(
    include
    lib
    tools/include
    tools/include/parser
    tools/include/serializer
)

# Eğer ek kütüphaneler varsa burada ekleyin
# target_link_libraries(pAsterix <libraries>)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
