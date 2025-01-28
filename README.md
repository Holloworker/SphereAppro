
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

Before compiling, ensure the Python environment with trimesh is activated

```console
cmake -B build . -DCMAKE_BUILD_TYPE=Release
cmake --build build
```
For a debug build, add `-DCMAKE_BUILD_TYPE=Debug` and `-DENABLE_SANITIZER=ON` to the cmake step above.

## Usage

~~~
makeTreeMedial

  -depth              Depth of the sphere-tree

  -branch             Branching factor of sphere-tree

  -numCover           Number of sample points to cover object with

  -minCover           Minimum number of sample points per triangle

  -initSpheres        Initial number of spheres in medial axis approx.

  -minSpheres         Minimum number of spheres to create for each sub
                          region of the medial axis approximation.

  -erFact             Amount by which to reduce the error when refining
                          the medial axis approximation.

  -testerLevels       Controls the number of points to use to represent a
                          sphere when evaluating fit.  Use -1 for CONVEX
                          objects, 1 will generate 42 points and 2 will
                          generate 168 points.

  -optimise           Which optimisation algorithm to use, SIMPLEX just
                          rearranges the spheres to try improve fit, BALANCE
                          tries to throw away spheres that don't improve the
                          approximation.

  -maxOptLevel        Maximum level of the sphere-tree to apply the optimiser.
                          0 does first set only - i.e. children of level 0.

  -balExcess          The amount of extra error the BALANCE algorithm is
                          allowed to introduce when throwing away error,
                          e.g. 0.05 allows a 5 percent increase in the error.

  -nopause            Don't pause when processing, i.e. batch mode

  -eval               Evaluate the fit of the sphere-tree and append the info
                          to the end of the output file.

  -merge              algorithms
  -expand


  makeTreeMedial  -branch 8 -depth 1 -testerLevels 2 -numCover 10000
                  -minCover 5 -initSpheres 1000 -minSpheres 200 -erFact 2
                  -nopause -expand -merge bunny-1500.obj

~~~
