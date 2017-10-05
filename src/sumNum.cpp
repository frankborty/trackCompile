//#include "OCLUtils.h"

#include <CL/cl.hpp>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#define __CL_ENABLE_EXCEPTIONS //abilita le eccezioni

#define BUFFER_SIZE 20



int A[BUFFER_SIZE];
int B[BUFFER_SIZE];
int C[BUFFER_SIZE];

char *err_code (cl_int err_in);

namespace OCLUtils {

  int sumNum(void){
    int n1=10;
    int n2=20;
    int n3=0;

      std::vector<cl::Platform> platformList;
      std::string info;

      for (int i = 0; i < BUFFER_SIZE; i++) {
          A[i] = i+10;
          B[i] = i * 2;
          C[i] = 0;
      }


      //seleziono la prima piattaforma e creo il contesto
      cl::Platform::get(&platformList);
      cl_context_properties cprops[]= {
        CL_CONTEXT_PLATFORM,
        (cl_context_properties)platformList[0](),
        0
      };

      cl::Context context (CL_DEVICE_TYPE_CPU,cprops);

      //selezionio il primo device associato al contesto e stampo il nome
      std::vector<cl::Device> devices= context.getInfo<CL_CONTEXT_DEVICES>();

      std::ifstream fileSrc("add2Num.cl");
      if (!fileSrc.is_open()) {
              std::cout << "Failed to read sinewave.cl";
              exit(1);
          }
      std::string prog(
          std::istreambuf_iterator<char>(fileSrc),
          (std::istreambuf_iterator<char>()));


      cl::Program::Sources sources(1,std::make_pair(prog.c_str(),prog.length()+1));
      cl::Program program (context, sources);


      program.build(devices);

      // Create buffer for A and copy host contents
      cl::Buffer aBuffer = cl::Buffer(
          context,
          CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
          sizeof(int),
          (void *) &n1);

      // Create buffer for B and copy host contents
      cl::Buffer bBuffer = cl::Buffer(
          context,
          CL_MEM_READ_ONLY | CL_MEM_COPY_HOST_PTR,
          sizeof(int),
          (void *) &n2);

      // Create buffer for that uses the host ptr C
      cl::Buffer cBuffer = cl::Buffer(
          context,
          CL_MEM_WRITE_ONLY | CL_MEM_USE_HOST_PTR,
          sizeof(int),
          (void *) &n3);

      // Create kernel object
      cl::Kernel kernel(program, "add2Num");

      kernel.setArg(0,n1);
      kernel.setArg(1,n2);
      kernel.setArg(2,cBuffer);

      cl::CommandQueue queue(context, devices[0], 0);

      // Do the work
      queue.enqueueNDRangeKernel(
          kernel,
          cl::NullRange,
          cl::NDRange(1),
          cl::NullRange);




      std::cout << std::endl;
  /*
      int * output = (int *) queue.enqueueMapBuffer(
          cBuffer,
          CL_TRUE, // block
          CL_MAP_READ,
          0,
          sizeof(int));
  */
      //for (int i = 0; i < BUFFER_SIZE; i++) {
      std::cout << "RESULT:";
      std::cout << n3 <<std::endl;
      //}



    return n3;
}

}


char *err_code (cl_int err_in)
{
    switch (err_in) {

        case CL_SUCCESS :
            return (char*)" CL_SUCCESS ";
        case CL_DEVICE_NOT_FOUND :
            return (char*)" CL_DEVICE_NOT_FOUND ";
        case CL_DEVICE_NOT_AVAILABLE :
            return (char*)" CL_DEVICE_NOT_AVAILABLE ";
        case CL_COMPILER_NOT_AVAILABLE :
            return (char*)" CL_COMPILER_NOT_AVAILABLE ";
        case CL_MEM_OBJECT_ALLOCATION_FAILURE :
            return (char*)" CL_MEM_OBJECT_ALLOCATION_FAILURE ";
        case CL_OUT_OF_RESOURCES :
            return (char*)" CL_OUT_OF_RESOURCES ";
        case CL_OUT_OF_HOST_MEMORY :
            return (char*)" CL_OUT_OF_HOST_MEMORY ";
        case CL_PROFILING_INFO_NOT_AVAILABLE :
            return (char*)" CL_PROFILING_INFO_NOT_AVAILABLE ";
        case CL_MEM_COPY_OVERLAP :
            return (char*)" CL_MEM_COPY_OVERLAP ";
        case CL_IMAGE_FORMAT_MISMATCH :
            return (char*)" CL_IMAGE_FORMAT_MISMATCH ";
        case CL_IMAGE_FORMAT_NOT_SUPPORTED :
            return (char*)" CL_IMAGE_FORMAT_NOT_SUPPORTED ";
        case CL_BUILD_PROGRAM_FAILURE :
            return (char*)" CL_BUILD_PROGRAM_FAILURE ";
        case CL_MAP_FAILURE :
            return (char*)" CL_MAP_FAILURE ";
        case CL_MISALIGNED_SUB_BUFFER_OFFSET :
            return (char*)" CL_MISALIGNED_SUB_BUFFER_OFFSET ";
        case CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST :
            return (char*)" CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST ";
        case CL_INVALID_VALUE :
            return (char*)" CL_INVALID_VALUE ";
        case CL_INVALID_DEVICE_TYPE :
            return (char*)" CL_INVALID_DEVICE_TYPE ";
        case CL_INVALID_PLATFORM :
            return (char*)" CL_INVALID_PLATFORM ";
        case CL_INVALID_DEVICE :
            return (char*)" CL_INVALID_DEVICE ";
        case CL_INVALID_CONTEXT :
            return (char*)" CL_INVALID_CONTEXT ";
        case CL_INVALID_QUEUE_PROPERTIES :
            return (char*)" CL_INVALID_QUEUE_PROPERTIES ";
        case CL_INVALID_COMMAND_QUEUE :
            return (char*)" CL_INVALID_COMMAND_QUEUE ";
        case CL_INVALID_HOST_PTR :
            return (char*)" CL_INVALID_HOST_PTR ";
        case CL_INVALID_MEM_OBJECT :
            return (char*)" CL_INVALID_MEM_OBJECT ";
        case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR :
            return (char*)" CL_INVALID_IMAGE_FORMAT_DESCRIPTOR ";
        case CL_INVALID_IMAGE_SIZE :
            return (char*)" CL_INVALID_IMAGE_SIZE ";
        case CL_INVALID_SAMPLER :
            return (char*)" CL_INVALID_SAMPLER ";
        case CL_INVALID_BINARY :
            return (char*)" CL_INVALID_BINARY ";
        case CL_INVALID_BUILD_OPTIONS :
            return (char*)" CL_INVALID_BUILD_OPTIONS ";
        case CL_INVALID_PROGRAM :
            return (char*)" CL_INVALID_PROGRAM ";
        case CL_INVALID_PROGRAM_EXECUTABLE :
            return (char*)" CL_INVALID_PROGRAM_EXECUTABLE ";
        case CL_INVALID_KERNEL_NAME :
            return (char*)" CL_INVALID_KERNEL_NAME ";
        case CL_INVALID_KERNEL_DEFINITION :
            return (char*)" CL_INVALID_KERNEL_DEFINITION ";
        case CL_INVALID_KERNEL :
            return (char*)" CL_INVALID_KERNEL ";
        case CL_INVALID_ARG_INDEX :
            return (char*)" CL_INVALID_ARG_INDEX ";
        case CL_INVALID_ARG_VALUE :
            return (char*)" CL_INVALID_ARG_VALUE ";
        case CL_INVALID_ARG_SIZE :
            return (char*)" CL_INVALID_ARG_SIZE ";
        case CL_INVALID_KERNEL_ARGS :
            return (char*)" CL_INVALID_KERNEL_ARGS ";
        case CL_INVALID_WORK_DIMENSION :
            return (char*)" CL_INVALID_WORK_DIMENSION ";
        case CL_INVALID_WORK_GROUP_SIZE :
            return (char*)" CL_INVALID_WORK_GROUP_SIZE ";
        case CL_INVALID_WORK_ITEM_SIZE :
            return (char*)" CL_INVALID_WORK_ITEM_SIZE ";
        case CL_INVALID_GLOBAL_OFFSET :
            return (char*)" CL_INVALID_GLOBAL_OFFSET ";
        case CL_INVALID_EVENT_WAIT_LIST :
            return (char*)" CL_INVALID_EVENT_WAIT_LIST ";
        case CL_INVALID_EVENT :
            return (char*)" CL_INVALID_EVENT ";
        case CL_INVALID_OPERATION :
            return (char*)" CL_INVALID_OPERATION ";
        case CL_INVALID_GL_OBJECT :
            return (char*)" CL_INVALID_GL_OBJECT ";
        case CL_INVALID_BUFFER_SIZE :
            return (char*)" CL_INVALID_BUFFER_SIZE ";
        case CL_INVALID_MIP_LEVEL :
            return (char*)" CL_INVALID_MIP_LEVEL ";
        case CL_INVALID_GLOBAL_WORK_SIZE :
            return (char*)" CL_INVALID_GLOBAL_WORK_SIZE ";
        case CL_INVALID_PROPERTY :
            return (char*)" CL_INVALID_PROPERTY ";
        default:
            return (char*)"UNKNOWN ERROR";

    }
}
