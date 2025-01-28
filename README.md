
# SPHERE APPROXIMATION

## INTRODUCTION

This software is designed for the construction of sphere representations
of polygonal models based on a fantastic work [SphereTree](https://github.com/mlund/spheretree.git)

<p align="center">
  <img src="https://github.com/user-attachments/assets/ac2e3b6a-6a30-46d4-a211-f07bbb09a1dc" alt="Image 1" width="200">
  <img src="https://github.com/user-attachments/assets/5b851bf3-db31-4281-9beb-ee026f84ccf9" alt="Image 2" width="200">
</p>

<p align="center">
  <img src="https://github.com/user-attachments/assets/0e5db557-0f87-439e-bb6c-e850fb81aec7" alt="Image 1" width="200">
  <img src="https://github.com/user-attachments/assets/8ebe6235-737a-4058-9f7a-05f48c71b6b3" alt="Image 2" width="200">
</p>

![7da420ac1eac65c0725d9e17112071d](https://github.com/user-attachments/assets/ac2e3b6a-6a30-46d4-a211-f07bbb09a1dc)
![52aa698ba32738d0dc4251548513f28](https://github.com/user-attachments/assets/0e5db557-0f87-439e-bb6c-e850fb81aec7)
![c8b089f01f1e9466fadc90ba4705527](https://github.com/user-attachments/assets/8ebe6235-737a-4058-9f7a-05f48c71b6b3)
![9fc3350814863b4c96dc2a3492099f4](https://github.com/user-attachments/assets/5b851bf3-db31-4281-9beb-ee026f84ccf9)





```console
cmake -B build .
cmake --build build
```

For a debug build, add `-DCMAKE_BUILD_TYPE=Debug` and `-DENABLE_SANITIZER=ON` to the cmake step above.
The purpose of enabling sanitizers in a project is to detect and debug runtime issues during program execution.
Sanitizers are a set of tools provided by e.g. GCC and Clang and instrument the code to catch memory-related, threading, and other runtime bugs which may not be easily detectable during regular testing. 

When `ENABLE_SANITIZER` is enabled, `address`, `leak`, `undefined_behavior`, `memory` are enabled.

