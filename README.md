
# SPHERE APPROXIMATION

## INTRODUCTION

This software is designed for the construction of sphere-tree representations
of polygonal models for use in interruptible collision detection algorithms.
The software contains various algorithms for performing these constructions. As
well as our own algorithms we have included our implementations of the OCTREE
algorithm and HUBBARD's medial axis based algorithm.  Detailed descriptions of
all the algorithms contained in this software can be found in the following
thesis:

[Bounding Volume Hierarchies for Level-of-Detail Collision Handling](http://hdl.handle.net/2262/86786)
_Bradshaw G., Dept. of Computer Science, Trinity College Dublin, May 2002._

This thesis, example animations and the latest version of this distributution can
be found at: http://isg.cs.tcd.ie/spheretree

~~~
makeTreeMedial
--------------
This program makes sphere-trees using OUR improved medial axis approximation
algorithms.  There are three such algorithms available, MERGE, BURST and
EXPAND.  The program can use any combination of these algorithms and pick the
best one for each section of the sphere-tree construction process.  The
command line options are as follows:

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

  -verify             Verify the model is suitable for use

  -nopause            Don't pause when processing, i.e. batch mode

  -eval               Evaluate the fit of the sphere-tree and append the info
                          to the end of the output file.

  -merge              Try the MERGE, BURST and EXPAND algorithms.  You can
  -burst              specify any number of these that you wish.
  -expand


  makeTreeMedial  -branch 8 -depth 1 -testerLevels 2 -numCover 10000
                  -minCover 5 -initSpheres 1000 -minSpheres 200 -erFact 2
                  -nopause -expand -merge bunny-1500.obj


makeTreeGrid
------------
This program makes sphere-trees using OUR grid algorithm.  The command line
options are:

  -depth              Depth of the sphere-tree

  -nopause            Don't pause when processing, i.e. batch mode

  -numCover           Number of sample points to cover object with

  -minCover           Minimum number of sample points per triangle

  -testerLevels       Controls the number of points to use to represent a
                          sphere when evaluating fit.  Use -1 for CONVEX
                          objects, 1 will generate 42 points and 2 will
                          generate 168 points.

  -verify             Verify the model is suitable for use

  -nopause            Don't pause when processing, i.e. batch mode

  -eval               Evaluate the fit of the sphere-tree and append the info
                          to the end of the output file.

  makeTreeGrid  -branch 8 -depth 3 -testerLevels 2 -numCover 10000 -minCover 5
                -nopause  bunny-1500.obj


makeTreeSpawn
-------------

This program makes sphere-trees using OUR spawn algorithm.  The command line
options are the same as for makeTreeGrid above.


makeTreeOctree
--------------
This program makes sphere-trees using the original OCTREE algorithm.  The
following command line options are available:

  -depth              Depth of the sphere-tree

  -nopause            Don't pause when processing, i.e. batch mode


makeTreeHubbard
---------------
This program makes sphere-trees using our implementation of Hubbard's
algorithm.  The algorithm constructs a static medial axis approximation
using a given number of sample points on the object.  Command line options
are as follows:

  -depth              Depth of the sphere-tree

  -branch             Branching factor of sphere-tree

  -numSamples         Number of sample points to cover object with

  -minSamples         Minimum number of sample points per triangle


  makeTreeHubbard  -branch 8 -depth 3 -numSamples 500 -minSamples 1
                   -nopause  bunny-1500.obj
~~~

## FILE FORMATS

All the sphere-tree construction programs are capable of loading both OBJ
files and our own special format (`.SUR`).  When we load the models we need to
generate the neighbourhood information for the triangles, the SUR file stores
this so that we don't need to compute it every time.  The GUI program is able
to export OBJ files as SUR.  The format of the SUR file is as follows:

- The number of vertices
- List of vertices with XYZ for position and XYZ for normal
- The number of triangles
- List of triangles with `i0`, `i1`, `i2` (indices of the vertices - zero base)
  `n0`, `n1`, `n2` (neighbouring triangles, `n0` shares edge from `i0` to `i1` etc.)

In order for the program to work properly, the models have the following
restrictions :  The model must be a completely closed surface free from self
intersections.  The -verify option can check if your model is valid.

The programs output the sphere-trees as an SPH file.  This is our own file
format and stores the sphere tree as a flat array.  If the branching factor of
the tree is `B` then the first child of node N will be located at `N*B+1`.  Similarly
the parent node `N` can be computed from the child number `C` as `(C-1)/B`.  The SPH
files are layed out as follows:

- Number of levels in the sphere-tree including root node
- Branching factor of the sphere-tree
- List of spheres as a flat array, XYZ for center and radius (-ve means sphere
is unused), the importance of the sphere (allspheres presently have an importance of 1.)

## BUILDING THE PROGRAMS

Unfortunately due to licensing issues we are unable to distribute all the files
that are used to build the program.  Some of the algorithms use other peoples
code which is distributed with the program.  However, the numerical recipes
code is not allowed to be redistributed and so you have to find the following
files yourself.  An althernative might be to port the NR dependent code to use
freely available code - if you do this i would be most interested in finding out.
The following files are needed: `complex.c`, `complex.h`, `nrutils.c`, `nrutils.h`, `svd.c`, `svd.h`
(some of these can be downloaded for free from http://www.nr.com/public-domain.html)

The distribution also contains the following sources from other people:

~~~
gdiam  Copyright 2000 Sariel Har-Peled (ssaarriieell@cs.uiuc.edu)
qHull  Copyright 1993, 1997, The Geometry Center
pcube  Copyright 1994 Don Hatch & Daniel Green
volInt Copyright 1995 by Brian Mirtich
~~~

Every effort has been made to ensure that we are not distributing copyrighted
material.  However, if you find that we are distributing something against its
copyright policy please let us know and we will gladly rectify it.

### Windows and MS Visual Studio

The distribution contains workspace files for Microsoft Visual C++ v6.  These
files are located in the `vc/` directory.  The spheretree.dsw contains all the
projects which can used to build the GUI and command line programs.  The GUI
program requires MFC and OpenGL to compile.  The windows code is also capable
of loading Rhino3D files using the RhinoIO API.  Uncomment `#define USE_RHINO_IO`
in surface.h to use this format (you may need to play around with the header and
library locations).  The GUI program also allows you to save images of the models
etc. if you have ImageMagick.  To use this uncomment `#define USE_IMAGE_MAGICK` in
IMsupport.h (you'll definitely need to know what you are doing with the libraries
and headers for this one). The EXE files for the programs will be put in the
build folder under either debug or release.

### Unix-like systems

A CMake build configuration is provided by `yixuanzhou@sjtu.edu.cn`, using the fantastic
[cmake-template](https://github.com/cpp-best-practices/cmake_template/tree/main). 

```console
cmake -B build .
cmake --build build
```

For a debug build, add `-DCMAKE_BUILD_TYPE=Debug` and `-DENABLE_SANITIZER=ON` to the cmake step above.
The purpose of enabling sanitizers in a project is to detect and debug runtime issues during program execution.
Sanitizers are a set of tools provided by e.g. GCC and Clang and instrument the code to catch memory-related, threading, and other runtime bugs which may not be easily detectable during regular testing. 

When `ENABLE_SANITIZER` is enabled, `address`, `leak`, `undefined_behavior`, `memory` are enabled.

