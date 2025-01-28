
# SPHERE APPROXIMATION

## INTRODUCTION

This software is designed for the construction of sphere representations
of polygonal models based on a fantastic work [SphereTree](https://github.com/mlund/spheretree.git)

<p align="center">
  <img src="https://github.com/user-attachments/assets/ac2e3b6a-6a30-46d4-a211-f07bbb09a1dc" alt="Image 1" width="200">
  <img src="https://github.com/user-attachments/assets/5b851bf3-db31-4281-9beb-ee026f84ccf9" alt="Image 2" width="200">
</p>

<p align="center">
  <img src="https://github.com/user-attachments/assets/8ebe6235-737a-4058-9f7a-05f48c71b6b3" alt="Image 1" width="200">
  <img src="https://github.com/user-attachments/assets/0e5db557-0f87-439e-bb6c-e850fb81aec7" alt="Image 2" width="200">
</p>

<p align="center">
  <img src="https://github.com/user-attachments/assets/2ecf3c4d-2209-4e69-acbc-570510092a01" alt="Image 2" width="200">
  <img src="https://github.com/user-attachments/assets/28043498-e8e7-4fae-a09d-2caf87c24009" alt="Image 1" width="200">
</p>



## Program Dependencies

This program requires the following dependencies to be properly set up before compiling and running:
1. Integrated ManifoldPlus:
   
The program includes the integrated ManifoldPlus for processing and validating meshes. No additional setup is required, as it is already part of this repository. Make sure all submodules are correctly initialized and updated when cloning the repository:
Clone the repository and initialize submodules
```console
git clone --recurse-submodules <repository-url>
cd <repository-folder>
```

2. Python Environment with trimesh
   
The program relies on trimesh for 3D mesh manipulation and processing. Ensure you have Python 3.8 or higher installed.
Use pip to install trimesh in your Python environment:

```console
pip install trimesh
```

## Compile

Before compiling, ensure the Python environment with trimesh is activated:

```console
cmake -B build .
cmake --build build
```

For a debug build, add `-DCMAKE_BUILD_TYPE=Debug` and `-DENABLE_SANITIZER=ON` to the cmake step above.
The purpose of enabling sanitizers in a project is to detect and debug runtime issues during program execution.
Sanitizers are a set of tools provided by e.g. GCC and Clang and instrument the code to catch memory-related, threading, and other runtime bugs which may not be easily detectable during regular testing. 

When `ENABLE_SANITIZER` is enabled, `address`, `leak`, `undefined_behavior`, `memory` are enabled.

