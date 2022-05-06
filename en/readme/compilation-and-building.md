# Compilation and Building<a name="EN-US_TOPIC_0000001162500073"></a>


The compilation and building subsystem provides a framework based on Generate Ninja (GN) and Ninja. This subsystem allows you to:

-   Build products based on different chipset platforms, for example, Hi3516D V300.

-   Package capabilities required by a product by assembling modules based on the product configuration.

## Basic Concepts<a name="section175012297491"></a>

It is considered best practice to learn the following basic concepts before you start building:

-   Platform

    A combination of development boards and kernels. Supported subsystems and components vary with the platform.

-   Subsystem

    OpenHarmony is designed with a layered architecture, which consists of the kernel layer, system service layer, framework layer, and application layer from the bottom up. System functions are developed by the level of system, subsystem, and module. In a multi-device deployment scenario, you can customize subsystems and modules as required. A subsystem is a logical concept and is a flexible combination of modules.

-   Module

    A module is a reusable software unit that contains source code, configuration files, resource files, and build scripts. A module can be built independently, integrated in binary mode, and then tested independently.

-   GN

    Generate Ninja (GN) is a system used to generate build files for Ninja.

-   Ninja

    Ninja is a small high-speed build system.


## Working Principles<a name="section193961322175011"></a>

The compilation and build process of OpenHarmony is as follows:

-   Parsing commands: Parse the name of the product to build and load related configurations.
-   Running GN: Configure the toolchain and global options based on the parsed product name and compilation type.
-   Running Ninja: Start building and generate a product distribution.

## Building a Mini or Small System<a name="section119041639115811"></a>

See [build\_lite](https://gitee.com/openharmony/build_lite/blob/master/README.md).

## Building a Standard System<a name="section8750514195912"></a>

See the readme of the **build** repository.

## Repositories Involved<a name="section44651652878"></a>

**Compilation and building**

[build\_lite](https://gitee.com/openharmony/build_lite)

build
