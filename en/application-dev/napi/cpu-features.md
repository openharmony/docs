# CPU Features


CPU features are hardware extensions provided by CPUs. You can call instructions and set special registers to use the CPU features, such as VFP-v32d32, Neon, IDIV, and AES on the ARMv7-A architecture. Many CPU features are optional, and different CPU vendors provide different CPU features.


During native library development in your OpenHarmony project, you can follow this topic to use code related to the CPU features in your application.


Currently, OpenHarmony does not provide APIs for obtaining CPU features. You can import library functions of the existing open source community as described below. Alternatively, you can directly read **/proc/cpuinfo** or call **libc getauxval(AT_HWCAP)** to obtain the CPU features of a device.


## How to Use

1. Import the open source library to your OpenHarmony C++ project. Specifically, download the [cpu_features library](https://github.com/google/cpu_features), and decompress it to the **cpp** directory of the project. The following uses the DevEco Studio C++ template sample application as an example.
   - The directory structure after the decompression is as follows:
      ```
      MyApplication
        |-- entry
         |-- src
              |-- main
                   |-- cpp
                       |--cpu_features
                       |--CMakeLists.txt
                       |--hello.cpp
      ```
   - Add the path to the cpu_features library to the **CMakeLists.txt** file.
      ```makefile
      add_subdirectory(cpu_features) # Add a subdirectory to the project.
      target_link_libraries(entry PUBLIC CpuFeature::cpu_features) # Add the library files that need to be linked.
      ```

2. Add the statement for determining the support for the CPU features to the code. The following uses the ARM and AArch64 architectures as an example:
   ```c++
   // ...
   // Include the header file for CPU architecture target detection.
   #include "cpu_features_macros.h"
   // In the ARM architecture, this macro is automatically defined in the preceding header file based on the target.
   #if defined (CPU_FEATURES_ARCH_ARM)
   #include "cpuinfo_arm.h" // Include the cpuinfo header file of the ARM architecture.
   #elif defined (CPU_FEATURES_ARCH_AARCH64)
   #include "cpuinfo_aarch64.h" // Include the cpuinfo header file of the AArch64 architecture.
   #endif
   // Add `using namespace cpu_features;` in the C++ code.
   // Obtain CPU feature information based on the architecture in use.
   #if defined (CPU_FEATURES_ARCH_ARM)
   static const ArmFeatures features = GetArmInfo().features;
   #elif defined (CPU_FEATURES_ARCH_AARCH64)
   static const Aarch64Features features = GetAarch64Info().features;
   #endif
   void Compute(void) {
     // Determine whether the CPU features are supported based on the features field.
     if (features.aes) {
       // ...
     } else {
       // ...
     }
   }
   ```

   > **NOTE**
   > 
   > The cpu_features library reads the corresponding CPU feature information from the kernel through **/proc/cpuinfo** or **getauxval**. The information may fail to be read due to the use of the application sandbox. Pay attention to error handling.
