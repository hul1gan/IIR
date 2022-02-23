#---------------------------------------------------------------------------------------------------
# Version check
#---------------------------------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

#---------------------------------------------------------------------------------------------------
# Options
#---------------------------------------------------------------------------------------------------
option(RJF_BUILD_SHARED "RJF as shared library."   OFF)
option(RJF_BUILD_TESTS  "Build RJF library tests." OFF)
option(RJFCUDA_BUILD_TESTS  "Build RJF CUDA library tests." ON)
#---------------------------------------------------------------------------------------------------
# Main
#---------------------------------------------------------------------------------------------------
set(TEST_DIR /Source/Test)  
set(PROJECT_NAME rjf)

project(${PROJECT_NAME} LANGUAGES CXX CUDA)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Include)  #Команда include_directories влияет на область каталога. Это означает, что все директории заголовков, указанные данной командой, будут применяться для всех целей текущего CMakeLists.txt, а также для обрабатываемых подпроектов

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(${CMAKE_CURRENT_SOURCE_DIR}/Source/Module.cmake)
set(LIBRARY_TYPE STATIC)

#---------------------------------------------------------------------------------------------------
# Library
#---------------------------------------------------------------------------------------------------

if (RJF_BUILD_SHARED)
    set(LIBRARY_TYPE SHARED)
endif( )

add_library(${PROJECT_NAME} ${LIBRARY_TYPE} ${RJF_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Include/)

#---------------------------------------------------------------------------------------------------
#  Tests
#---------------------------------------------------------------------------------------------------
 
if (RJF_BUILD_TESTS)
    set(TEST_TARGET ${PROJECT_NAME}_test)
    
    find_package(CppUTest REQUIRED)  # Опция REQUIRED требует печати фатальной ошибки и завершении работы CMake, если требуемый пакет не найден
        
    include_directories(${CPPUTEST_INCLUDE_DIRS})
       
    set(TEST_SOURCES ./Source/Test/main.cpp
                     ./Source/Test/RejectionFilter.cpp
                     
    )
           
    add_executable(${TEST_TARGET} ${TEST_SOURCES})
        
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}${TEST_DIR}/byteArrayX.bin ${CMAKE_CURRENT_SOURCE_DIR}${TEST_DIR}/byteArrayY.bin DESTINATION data)
       
    target_link_libraries(${TEST_TARGET} ${PROJECT_NAME} ${CPPUTEST_LIBRARIES})  #команда для линковке с библиотекой
        
    install(FILES build/rjf_test DESTINATION data)
endif( )

#---------------------------------------------------------------------------------------------------
#  Tests
#---------------------------------------------------------------------------------------------------

if (RJFCUDA_BUILD_TESTS)
    set(TEST_TARGET ${PROJECT_NAME}_testcuda)
    
    find_package(CppUTest REQUIRED)  # Опция REQUIRED требует печати фатальной ошибки и завершении работы CMake, если требуемый пакет не найден
    
    include_directories(${CPPUTEST_INCLUDE_DIRS})
   
    set(TEST_SOURCES ./Source/Test/main.cpp
                    ./Source/CUDA/Test/CUDATest.cu
    )    
   
    add_executable(${TEST_TARGET} ${TEST_SOURCES})

    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}${TEST_DIR}/byteArrayX.bin ${CMAKE_CURRENT_SOURCE_DIR}${TEST_DIR}/byteArrayY.bin DESTINATION data)
   
    target_link_libraries(${TEST_TARGET} ${PROJECT_NAME} ${CPPUTEST_LIBRARIES})  #команда для линковке с библиотекой
    install(FILES build/rjf_testcuda DESTINATION data)
endif( ) 
 

set(CPACK_PACKAGE_FILE_NAME arkhive)
set(CPACK_GENERATOR "TGZ")
include(CPack)









