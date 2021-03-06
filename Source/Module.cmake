set(RJF_SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Source)
if (RJF_BUILD_TESTS)
set(RJF_SOURCES ${RJF_SOURCES_DIR}/RejectionFilter.cpp ${RJF_SOURCES_DIR}/Interface.cpp ${RJF_SOURCES_DIR}/TestFunctions.cpp)
endif()
if (RJFCUDA_BUILD_TESTS)
set(RJF_SOURCES ${RJF_SOURCES_DIR}/CUDA/RJFcuda.cu ${RJF_SOURCES_DIR}/Interface.cpp ${RJF_SOURCES_DIR}/TestFunctions.cpp ${RJF_SOURCES_DIR}/CUDA.cpp)
endif()
