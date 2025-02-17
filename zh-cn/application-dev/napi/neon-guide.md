# 使用Neon指令扩展


ARM Neon是ARM架构的SIMD（Single Instruction Multiple Data）扩展实现，提供一条指令处理多个数据的并行处理能力，广泛用于多媒体编解码、2D/3D图形处理等领域，提高执行性能。


Neon扩展从ARMv7开始被采用，目前在Cortex-A7、Cortex-A12、Cortex-A15处理器中被设置为默认选项，但在其余的ARMv7 Cortex-A系列中是可选项。具体技术细节请参考《[Introducing NEON Development Article](https://developer.arm.com/documentation/dht0002/a/Introducing-NEON/What-is-SIMD-/ARM-SIMD-instructions?lang=en)》。


ARMv8a架构CPU默认集成Neon扩展，在AArch64与AArch32两种状态下都支持，详细请参考ARM官方文档《[Learn the architecture - Introducing Neon](https://developer.arm.com/documentation/102474/0100/Fundamentals-of-Armv8-Neon-technology)》。


## OpenHarmony架构支持情况

在OpenHarmony系统中，arm64-v8a ABI下默认已经开启了对Neon扩展的支持；在armeabi-v7a ABI下，为了能够尽可能的支持ARMv7a架构设备，默认不开启Neon扩展。

在OpenHarmony SDK的LLVM工具链中，为armeabi-v7a ABI提供了对多种配置的预编译运行时库的支持，供开发者根据不同的配置进行选择。具体目录结构如下，native-root表示NDK所在的native包解压根目录。

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

其中hard、soft、softfp是float-abi，未指定默认采用softfp；neon-vfpv4就是-mfpu指定的参数类型，LLVM工具链根据相应编译参数选择依赖不同架构配置的二进制库。


## 如何使用

使用Neon扩展的主要通过如下几种方式：

- 使用LLVM的Auto-Vectorization特性，由编译器来生成对应指令，默认开启，可以通过-fno-vectorize关闭，具体参考《[Auto-Vectorization in LLVM](https://llvm.org/docs/Vectorizers.html)》。

- 使用Neon intrinsics库，方便开发者直接操作低阶Neon指令。

- 手工写Neon汇编指令。

详细可以参考《[Arm Neon架构](https://developer.arm.com/Architectures/Neon)》。


## 举例说明

下面举例说明在一个armeabi-v7a OpenHarmony C++工程中如何使用Neon intrinsics。

1. 使用Neon intrinsics需要在源码包含arm_neon.h头文件，由于该特性与CPU架构强相关，在包含该头文件时，推荐用cpu features等宏括起来。

   ```c++
   #include "cpu_features_macros.h"
   void call_neon_intrinsics(short *output, const short* input, const short* kernel, int width, int kernelSize)
   {
      int nn, offset = -kernelSize/2;
      for (nn = 0; nn < width; nn++)
      {
           int mm, sum = 0;
           int32x4_t sum_vec = vdupq_n_s32(0); // Neon指令函数
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

2. 在函数实现处，根据CPU特性调用对应的实现函数。
   ```c++
   void Compute(void) {
   #if defined (CPU_FEATURES_ARCH_ARM)
     static const ArmFeatures features = GetArmInfo().features;
     // 根据features的字段进行支持cpu features的特性判断
     if (features.neon) {
       // Run optimized code.
     } else {
       // call normal function writed in c
     }
   #endif
   }
   ```

3. 在CMakeLists.txt文件中添加对应选项。
   ```makefile
   if (${OHOS_ARCH} STREQUAL "armeabi-v7a")
       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpu=neon -mfloat-abi=softfp")
   endif ()
   ```

上述步骤完成后，开发者即可在工程中使用Neon intrinsics指令。
