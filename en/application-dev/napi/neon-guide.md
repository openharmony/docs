# Using Neon Instructions


Arm Neon is an advanced Single Instruction Multiple Data (SIMD) architecture extension for Arm processors. It supports parallel processing of multiple pieces of data by using one instruction. It is widely used in fields such as multimedia encoding/decoding and 2D/3D graphics to improve execution performance.


The Neon extension is used since ARMv7. Currently, it is set as a default in Cortex-A7, Cortex-A12, and Cortex-A15 processors, but is optional in other ARMv7 Cortex-A series processors. For details, see [Introducing NEON Development Article](https://developer.arm.com/documentation/dht0002/a/Introducing-NEON/What-is-SIMD-/ARM-SIMD-instructions?lang=en).


The ARMv8-A processors integrate the Neon extension by default, which is supported in both AArch64 and AArch32. For details, see [Learn the architecture - Introducing Neon](https://developer.arm.com/documentation/102474/0100/Fundamentals-of-Armv8-Neon-technology).


## Architecture Support in OpenHarmony

In OpenHarmony, the Neon extension is enabled by default in the arm64-v8a ABI. It is disabled by default in the armeabi-v7a ABI, in order to support as many ARMv7-A devices as possible.

In the LLVM toolchain of the OpenHarmony SDK, the armeabi-v7a ABI supports precompiled runtime libraries with many configurations. The directory structure is as follows. **native-root** is the root directory where the native package of the NDK is decompressed.

```
{native-root}/llvm/lib/clang/current/lib/arm-linux-ohos/
    |-- a7_hard_neon-vfpv4
    |       |-- clang_rt.crtbegin.o
    |       |-- clang_rt.crtend.o
    |       |-- ...
    |
    |-- a7_soft
    |       |-- clang_rt.crtbegin.o
    |       |-- clang_rt.crtend.o
    |       |-- ...
    |
    |-- a7_softfp_neon-vfpv4
            |-- clang_rt.crtbegin.o
            |-- clang_rt.crtend.o
            |-- ...
```

**hard**, **soft**, and **softfp** are float-abi. If they are not specified, **softfp** is used by default. **neon-vfpv4** is the parameter type specified by **-mfpu**. The LLVM toolchain selects binary libraries that depend on different architecture configurations based on the compilation parameters.


## How to Use

The Neon extension can be used in the following ways:

- Use the Auto-Vectorization feature of LLVM. The compiler generates instructions. This feature is enabled by default and can be disabled by running **-fno-vectorize**. For details, see [Auto-Vectorization in LLVM](https://llvm.org/docs/Vectorizers.html).

- Use the Neon intrinsics library, which gives you direct, low-level access to Neon instructions.

- Write Neon assembly instructions.

For details, see [Arm Neon](https://developer.arm.com/Architectures/Neon).


## Example

The following example describes how to use Neon intrinsics in an armeabi-v7a OpenHarmony C++ project.

1. Include the **arm_neon.h** header file in the source code. The Neon intrinsics are closely related to the CPU architecture. Therefore, you are advised to include this header file in macros such as **cpu_features_macros**.

   ```c++
   #include "cpu_features_macros.h"
   void call_neon_intrinsics(short *output, const short* input, const short* kernel, int width, int kernelSize)
   {
      int nn, offset = -kernelSize/2;
      for (nn = 0; nn < width; nn++)
      {
           int mm, sum = 0;
           int32x4_t sum_vec = vdupq_n_s32(0); // Neon intrinsics
           for(mm = 0; mm < kernelSize/4; mm++)
           {
               int16x4_t  kernel_vec = vld1_s16(kernel + mm*4);
               int16x4_t  input_vec = vld1_s16(input + (nn+offset+mm*4));
               sum_vec = vmlal_s16(sum_vec, kernel_vec, input_vec);
           }
           // ...
      }
      // ...
   }
   ```

2. Call the corresponding implementation functions based on the CPU feature.
   ```c++
   void Compute(void) {
   #if defined (CPU_FEATURES_ARCH_ARM)
     static const ArmFeatures features = GetArmInfo().features;
     // Determine whether the CPU features are supported based on the features field.
     if (features.neon) {
       // Run optimized code.
     } else {
       // Call normal functions written in C.
     }
   #endif
   }
   ```

3. Add the corresponding options to the **CMakeLists.txt** file.
   ```makefile
   if (${OHOS_ARCH} STREQUAL "armeabi-v7a")
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpu=neon -mfloat-abi=softfp")
   endif ()
   ```

Now you can use Neon intrinsics in your project.

<!--no_check-->