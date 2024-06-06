cmake_minimum_required(VERSION 3.16.0)
project(EurocontrolAsterixMessage)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# GLOB komutu ile 'lib' klasöründeki tüm .cpp ve .h dosyalarını bul
file(GLOB LIB_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/lib/*.h"
)

# GLOB komutu ile 'inc' klasöründeki tüm .cpp ve .h dosyalarını bul
file(GLOB INC_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
)

file(GLOB SRC_SOURCES
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

file(GLOB ASTERIX_MESSAGES
     "${CMAKE_CURRENT_SOURCE_DIR}/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/categories-types/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/tools/include/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/tools/include/parser/*.h"
     "${CMAKE_CURRENT_SOURCE_DIR}/tools/include/serializer/*.h"

     "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/tools/src/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/tools/src/parser/*.cpp"
     "${CMAKE_CURRENT_SOURCE_DIR}/tools/src/serializer/*.cpp"
)

# Tüm kaynak dosyalarını bir değişkene ekleyin
set(ASTERIX_MESSAGES_SOURCES
    ${LIB_SOURCES}
    ${INC_SOURCES}
    ${SRC_SOURCES} 
    ${ASTERIX_MESSAGES}
    "${CMAKE_CURRENT_SOURCE_DIR}/../lib/json.hpp"
)

# Bu dosyaları bir üst projeye dahil edebilmek için bir değişken ayarlayın
set(ASTERIX_MESSAGES_SOURCES ${ASTERIX_MESSAGES_SOURCES} PARENT_SCOPE)
