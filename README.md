# TSP brute force
There you can find an interpretation of brute force Travelling salesman problem in 

- OpenMP
- MPI
- PosixThreads
- CPPThreads
- OpenCL

To open and run this project you have to install some SDK's

For MPI - Microsoft MPI 10.1.12498.18

For PosixThreads - pthread v2.1

For OpenCL - INTEL developers SDK

This projects are built on Microsoft Visual Studio Community 2022



Initial data:

| **0**  | **1**  | **28** | **10** | **40** | **29** | **24** | **18** | **44** | **41** |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| **37** | **0**  | **9**  | **43** | **35** | **26** | **15** | **1**  | **5**  | **18** |
| **8**  | **9**  | **0**  | **49** | **22** | **6**  | **1**  | **1**  | **19** | **27** |
| **28** | **30** | **30** | **0**  | **9**  | **33** | **23** | **18** | **3**  | **30** |
| **39** | **40** | **26** | **15** | **0**  | **43** | **36** | **47** | **46** | **27** |
| **7**  | **23** | **12** | **43** | **11** | **0**  | **39** | **42** | **49** | **49** |
| **30** | **20** | **14** | **15** | **42** | **2**  | **0**  | **19** | **5**  | **34** |
| **3**  | **1**  | **46** | **14** | **14** | **29** | **34** | **0**  | **42** | **36** |
| **24** | **11** | **37** | **23** | **23** | **47** | **37** | **6**  | **0**  | **30** |
| **19** | **37** | **30** | **29** | **18** | **8**  | **12** | **21** | **40** | **0**  |

Execution time comparsion:

| Number of threads |              |             |                |              |            |
| :---------------: | :----------: | :---------: | :------------: | :----------: | :--------: |
|                   |    OpenMP    |     MPI     | Posix  Threads | C++  Threads |  OpenCL*   |
|         1         | ~18.613 secs |      -      |       -        |      -       |     -      |
|         2         |      -       | ~10.253 sec |   ~9.323 sec   |  ~9.935 sec  | ~1.125 sec |
|         4         |      -       | ~6.585 sec  |   ~6.129 sec   |  ~6.517 sec  |            |
|        10         |      -       | ~3.707 sec  |   ~3.802 sec   |  ~3.583 sec  |            |

*This program executes on RTX2070 Max-Q and uses a 10x10x10 matrix

------

Written by **deorz**
