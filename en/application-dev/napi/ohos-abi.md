# OpenHarmony ABIs

OpenHarmony supports diverse device forms, instruction sets, and operating system kernels. To ensure application compatibility on different OpenHarmony devices, you must follow the basic OHOS Application Binary Interface (ABI) standards provided in this topic.

## Byte Order and Word Width

OHOS ABIs always use little-endian, ILP32 for 32-bit systems, and LP64 for 64-bit systems.


## Procedure Call Standards

The parameter transfer mode in function calls, register usage rules, and stack operation rules are defined. Different C++ compilers, operating systems, and architectures may use different calling rules. For details, see [Calling conventions for different C++ compilers and operating systems](https://www.agner.org/optimize/calling_conventions.pdf). For details about the architecture-specific call standards, see the following:

- [Procedure Call Standard for the Arm<sup>®</sup> 32-bit Architecture (AArch32)](https://github.com/ARM-software/abi-aa/tree/main/aapcs32)

- [Procedure Call Standard for the Arm<sup>®</sup> 64-bit Architecture (AArch64)](https://github.com/ARM-software/abi-aa/tree/main/aapcs64)


## C++ ABI

OpenHarmony uses libc++ in the LLVM project as the C++ runtime library. The libc++.so library is used on the system side, and the libc++_shared.so library is used on the application side. One set of code is used on both sides, with different C++ namespaces. For details about the symbol mangling rules of C++, see [Itanium C++ ABI](https://itanium-cxx-abi.github.io/cxx-abi/).


## Floating-Point Format

OpenHarmony uses IEE754 as the floating-point encoding format. For details about the definition of the long double format, see [Supported ABI Architectures](#supported-abi-architectures).


## Executable File Format

OpenHarmony uses ELF as the binary file format of the entire system. For details about the format, see [System V Application Binary Interface](https://refspecs.linuxfoundation.org/elf/gabi4+/contents.html). For details about the format definition related to the CPU architecture, see the following:

- [ELF for the Arm<sup>®</sup> Architecture](https://github.com/ARM-software/abi-aa/tree/main/aaelf32)

- [ELF for the Arm<sup>®</sup> 64-bit Architecture (AArch64)](https://github.com/ARM-software/abi-aa/tree/main/aaelf64)


## Supported ABI Architectures

This section describes the architectures supported by the OHOS ABIs and their differences.


### armeabi-v7a

This ABI is developed on the [Application Binary Interface (ABI) for the ARM Architecture](https://developer.arm.com/Architectures/Application%20Binary%20Interface) and applies to 32-bit ARMv7-A CPUs. For details about the supported core list, see *List of ARM processors*. It supports ARM32, Thumb-2, and VFPv3-D16 instructions.

The ABI uses **-mfloat-cpu=softfp** to enforce the floating-point rule in function calls. The compiler still uses hardware floating point instructions. Other extensions including Neon are optional in this ABI. For better compatibility, you are advised to use **-mfpu=softvfp** to compile the native libraries.

The ABI uses 64-bit long double (IEEE binary64).


### arm64-v8a

This ABI is developed on the *Application Binary Interface (ABI) for the ARM Architecture*. It supports the AArch64 instruction set and the Neon feature by default.

The ABI uses **-mfloat-cpu=softfp** to enforce the floating-point rule in function calls.

The ABI uses 128-bit long double (IEEE binary128).


### x86_64

The ABI is developed on Intel 64 and IA-32 ABI and supports MMX, SSE, SSE2, SSE3, SSSE3, and SSE4.1 instructions. For details about x86 specifications, see [System V Application Binary Interface](undefined) and [AMD64 Architecture Processor Supplement](undefined).

The ABI uses 128-bit long double (IEEE binary128). Note that many x86 platforms use the float80 format, whereas OpenHarmony uses the 128-bit format.


## Specifying the ABI in the Architecture at Build Time


### Setting in DevEco Studio

In the C++ project of OpenHarmony, find the **buildOption/externalNativeOptions** field in the **build-profile.json5** file of the project where the C++ code is located, and add the **abiFilters** field.

```json
{
    "abiType": 'stageMode',
    "buildOption": {
        "externalNativeOptions": {
            "path": "./src/main/cpp/CMakeLists.txt",
            "arguments": "",
            "abiFilters": [
                "armeabi-v7a",
                "arm64-v8a"
            ]
        }
    }
}
```


### Setting in .cmake

When you develop native code using SDK CAPIs, some common environment variables for cross compilation of OpenHarmony are defined in **build/cmake/ohos.toolchain.cmake**. The **OHOS_ARCH** variable defines the target ABI for build, which can be **arm64-v8a**, **armeabi-v7a**, and **x86_64**.
