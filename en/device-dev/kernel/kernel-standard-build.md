# Guidelines for Compiling and Building the Linux Kernel<a name="EN-US_TOPIC_0000001076416924"></a>

-   [Example 1](#section19369206113115)
    -   [Scenario 1: Building the Native Kernel at the Version Level](#section1025111193220)
    -   [Scenario 2: Building the Modified Kernel Separately](#section17446652173211)


## Example 1<a name="section19369206113115"></a>

The following uses the Hi3516D V300 board and Ubuntu x86 server as an example.

### Scenario 1: Building the Native Kernel at the Version Level<a name="section1025111193220"></a>

Perform a full build for the project to generate the  **uImage**  kernel image.

```
./build.sh --product-name Hi3516DV300 # Build the uImage kernel image of the Hi3516D V300 board.
```

### Scenario 2: Building the Modified Kernel Separately<a name="section17446652173211"></a>

1.  Set up the build environment.

    1.  Merge the required patch by referring to  [guidelines for using patches on development boards](kernel-standard-patch.md).
    2.  Prepare for the build environment. You can use the Arm Clang or GCC compiler.

    Enter the root directory of the project and configure environment variables:

    ```
    export PATH=`pwd`/prebuilts/clang/host/linux-x86/clang-r353983c/bin:`pwd`/prebuilts/gcc/linux-x86/arm/gcc-linaro-7.5.0-arm-linux-gnueabi/bin/:$PATH # Configure the build environment.
    MAKE_OPTIONES="ARCH=arm CROSS_COMPILE=arm-linux-gnueabi- CC=clang HOSTCC=clang" # Use Clang provided by the project.
    ```

2.  Modify the kernel code or kernel configuration \(**defconfig**  file provided by OpenHarmony can be used for reference\).
3.  Create a build directory and generate the  **.config**  file of the kernel.

    ```
    make ${MAKE_OPTIONES} hi3516dv300_emmc_smp_hos_l2_defconfig # Use the defconfig file to build the kernel.
    ```

4.  Build the kernel image.

    ```
    make ${MAKE_OPTIONES} -j32 uImage # Build the uImage kernel image.
    ```


