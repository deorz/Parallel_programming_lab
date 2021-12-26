#define CL_USE_DEPRECATED_OPENCL_2_0_APIS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <ctime>

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#define MAX_SOURCE_SIZE (0x100000)

using namespace std;
const int pack_size = 100000;
double min_path = 10000;



int main(void)
{
	setlocale(LC_ALL, "Russian");
	vector <double>  res;
	res.resize(pack_size); 

	size_t global[3] = {10, 10, 10};
	size_t local[3] = {10, 10, 1};

	// Load the kernel source code into the array source_str
	FILE* fp;
	char* source_str;
	size_t source_size;
	#pragma warning(disable : 4996)
	fp = fopen("kernel.cl", "r");
	if (!fp)
	{
		fprintf(stderr, "Failed to load kernel.\n");
		exit(1);
	}
	source_str = (char*)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);

	// Get platform and device information
	cl_device_id device_id = NULL;
	cl_uint ret_num_devices;
	cl_uint ret_num_platforms;


	cl_int ret = clGetPlatformIDs(0, NULL, &ret_num_platforms);
	cl_platform_id* platforms = NULL;
	platforms = (cl_platform_id*)malloc(ret_num_platforms * sizeof(cl_platform_id));

	ret = clGetPlatformIDs(ret_num_platforms, platforms, NULL);

	ret = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_ALL, 1, &device_id, &ret_num_devices);

	char cBuffer[1024];
	clGetDeviceInfo(device_id, CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(cBuffer), &cBuffer, NULL);
	printf(cBuffer);
	cout << endl;
	clGetDeviceInfo(device_id, CL_DEVICE_VENDOR, sizeof(cBuffer), &cBuffer, NULL);
	printf(cBuffer);
	cout << endl;
	clGetPlatformInfo(platforms[0], CL_PLATFORM_NAME, sizeof(cBuffer), &cBuffer, NULL);
	printf(cBuffer);
	cout << endl;
	clGetPlatformInfo(platforms[0], CL_PLATFORM_VENDOR, sizeof(cBuffer), &cBuffer, NULL);
	printf(cBuffer);
	cout << endl;

	// Create an OpenCL context
	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

	// Create a command queue
	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 1, &ret);

	// Create a program from the kernel source
	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &ret);

	// Build the program
	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
	if (ret == CL_BUILD_PROGRAM_FAILURE) {
		// Determine the size of the log
		size_t log_size;
		clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_size);

		// Allocate memory for the log
		char* log = (char*)malloc(log_size);

		// Get the log
		clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, log_size, log, NULL);

		// Print the log
		printf("%s\n", log);
	}

	// Create the OpenCL kernel
	cl_kernel kernel = clCreateKernel(program, "loop_voyager", &ret);

	
	cl_mem output; 
	output = clCreateBuffer(context, CL_MEM_READ_ONLY, sizeof(double) * pack_size, NULL, NULL);

	
	ret = 0;
	ret |= clSetKernelArg(kernel, 0, sizeof(unsigned int), &pack_size);
	ret |= clSetKernelArg(kernel, 1, sizeof(cl_mem), &output);
	//ret |= clSetKernelArg(kernel, 2, sizeof(double), &towns);
	


	double start = clock();
	
	cl_event event;
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 3, NULL, global, local, 0, NULL, &event);

	
	ret = clWaitForEvents(1, &event);

	double time = (clock() - start) / 1000.0;
	cout << "Время OpenCL: " << time << endl;
	clReleaseEvent(event);
	ret = clEnqueueReadBuffer(command_queue, output, CL_TRUE, 0, sizeof(double) * res.size(), res.data(), 0, NULL, NULL);
	
	for (int i = 0; i < res.size(); i++)
	{
		if (res[i] != 0 && res[i] < min_path)
		{
			min_path = res[i];
		}
	}
	
	
	
	cout << "Самый короткий путь имеет длину маршрута: " << min_path << endl;

	clReleaseMemObject(output);
	clReleaseProgram(program);
	clReleaseKernel(kernel);
	clReleaseCommandQueue(command_queue);
	clReleaseContext(context);
	return 0;
}