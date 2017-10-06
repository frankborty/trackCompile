set(MODULE src)

set(SRCS
  OCLTest.cpp
  OCLUtils.cpp
)

include_directories(${TRACKING-ITSU_SOURCE_DIR}/include)

add_library(${MODULE} ${SRCS})


