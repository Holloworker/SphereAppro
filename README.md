
# SPHERE APPROXIMATION

## INTRODUCTION

This software is designed for the construction of sphere representations
of polygonal models based on a fantastic work [SphereTree](https://github.com/mlund/spheretree.git)


![7da420ac1eac65c0725d9e17112071d](https://github.com/user-attachments/assets/ac2e3b6a-6a30-46d4-a211-f07bbb09a1dc)
![c8b089f01f1e9466fadc90ba4705527](https://github.com/user-attachments/assets/8ebe6235-737a-4058-9f7a-05f48c71b6b3)
![7da420ac1eac65c0725d9e17112071d](https://github.com/user-attachments/assets/f3cb9806-0b4b-49c5-a1e6-21882af371d7)
![9fc3350814863b4c96dc2a3492099f4](https://github.com/user-attachments/assets/5b851bf3-db31-4281-9beb-ee026f84ccf9)





```console
cmake -B build .
cmake --build build
```

For a debug build, add `-DCMAKE_BUILD_TYPE=Debug` and `-DENABLE_SANITIZER=ON` to the cmake step above.
The purpose of enabling sanitizers in a project is to detect and debug runtime issues during program execution.
Sanitizers are a set of tools provided by e.g. GCC and Clang and instrument the code to catch memory-related, threading, and other runtime bugs which may not be easily detectable during regular testing. 

When `ENABLE_SANITIZER` is enabled, `address`, `leak`, `undefined_behavior`, `memory` are enabled.

