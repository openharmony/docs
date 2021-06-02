# Compilation and Building Overview<a name="EN-US_TOPIC_0000001076490572"></a>

-   [Basic Concepts](#section175012297491)
-   [Working Principles](#section193961322175011)
-   [Limitations and Constraints](#section2029921310472)

The compilation and building subsystem provides a framework based on Generate Ninja \(GN\) and Ninja. This subsystem allows you to:

-   Build products based on different chipset platforms, for example, Hi3516D V300.

-   Package capabilities required by a product by assembling modules based on the product configuration.

## Basic Concepts<a name="section175012297491"></a>

It is considered best practice to learn the following basic concepts before you start building:

-   **Platform**

    A platform is a combination of development boards and kernels.

    Supported subsystems and modules vary according to the platform.

-   **Subsystems**

    OpenHarmony is designed with a layered architecture, which from bottom to top consists of the kernel layer, system service layer, framework layer, and application layer. System functions are expanded by levels, from system to subsystem, and further to module. In a multi-device deployment scenario, unnecessary subsystems and modules can be excluded from the system as required. A subsystem is a logical concept and is a flexible combination of functions.

-   **Module**

    A module is a reusable software binary unit that contains source code, configuration files, resource files, and build scripts. A module can be built independently, integrated in binary mode, and then tested independently.

-   **GN**

    GN is short for Generate Ninja, which is used to generate Ninja files.

-   **Ninja**

    Ninja is a small high-speed build system.


## Working Principles<a name="section193961322175011"></a>

The process to build OpenHarmony is as follows:

-   Parsing commands: Parse the name of the product to build and load related configurations.
-   Running GN: Configure toolchains and global options based on the parsed product name and compilation type.
-   Running Ninja: Start building and generate a product distribution.

## Limitations and Constraints<a name="section2029921310472"></a>

-   You must download the source code using method 3 described in  [Source Code Acquisition](../get-code/source-code-acquisition.md).
-   The build environment must be Ubuntu 18.04 or later.
-   You must install the software package required for build.

    The installation command is as follows:

    ```
    sudo apt-get install binutils git-core git-lfs gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip m4
    ```


