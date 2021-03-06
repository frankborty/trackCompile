#ifndef TRACKINGITSU_INCLUDE_OCL_UTILS_H_
#define TRACKINGITSU_INCLUDE_OCL_UTILS_H_

#include <CL/cl.hpp>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>

namespace OCLUtils {
  char *err_code (int err_in);
}

#endif /* TRACKINGITSU_INCLUDE_OCL_UTILS_H_ */
