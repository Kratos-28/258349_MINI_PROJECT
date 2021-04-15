# SDLC Activity Based learning
[![Static Code Quality- Cppcheck](https://github.com/Kratos-28/258349_MINI_PROJECT/actions/workflows/cpp-check.yml/badge.svg)](https://github.com/Kratos-28/258349_MINI_PROJECT/actions/workflows/cpp-check.yml)
## Folder Structure
Folder             | Description
-------------------| -----------------------------------------
`1_Requirements`   | Documents detailing requirements and research
`2_Architecture`   | Documents specifying design details
`3_Images`         | Screenshot of output
`4_Implementation` | All code and documentation


## Challenges Faced and How Was It Overcome
| No. | Challenge | Solution
|-----|-----------|--------
|1. | Code Crashed without any error message (Segmentation Fault) | GDB tool helped to pin point the Invalid Read 
|2. | After program shut down, there was no way to recover data | Implemented File System |
|3. | IOWITHOUTPOSITIONING Error | Check if fseek() != -1 between consecutive read and write calls
|4. | Structure Padding causing write to uninitialized location(Still Reachable code error) | Won't Fix, need help
|5. | Requirement gathering proved to be challenging, mainly ageing | Read multiple Research papers to find about history of management systems 
|6. | gcov generating *.gcda and *.gcno files in different directory than object file | added few extra steps in make file under coverage, made a copy of .c file in current directory and ran coverage then deleted all the unnecessary files.

## Features
- Sorting alogrithm Comparison using c language for mini project requirement of stepin program.
- C language will be the primary language for this project
- Makefile will be there to make the project easier to handle
- Diagrams to represent designing of the project
- Seperate Header file for the program operations/features
- Seperate c file for each operation
- Multifile approach is used in this mini project
