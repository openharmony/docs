# Compilation and Building


The compilation and building subsystem provides a framework based on Generate Ninja (GN) and Ninja. This subsystem allows you to:

-   Build products based on different chipset platforms, for example, Hi3516D V300.

-   Package capabilities required by a product by assembling modules based on the product configuration.

## Basic Concepts

It is considered best practice to learn the following basic concepts before you start building:

-   Platform

    A combination of development boards and kernels. Supported subsystems and components vary with the platform.

-   Subsystem

    OpenHarmony is designed with a layered architecture, which consists of the kernel layer, system service layer, framework layer, and application layer from the bottom up. System functions are developed by the level of system, subsystem, and component. In a multi-device deployment scenario, you can customize subsystems and components as required. A subsystem is a logical concept and is a flexible combination of components.

-   Component

    A component is a reusable software unit that contains source code, configuration files, resource files, and build scripts. A component can be built independently, integrated in binary mode, and then tested independently.

-   GN

    GN is a system used to generate build files for Ninja.

-   Ninja

    Ninja is a small high-speed build system.


## Working Principles

The compilation and build process of OpenHarmony is as follows:

-   Parsing commands: Parse the name of the product to build and load related configurations.
-   Running GN: Configure the toolchain and global options based on the parsed product name and compilation type.
-   Running Ninja: Start building and generate a product distribution.

## Building a Mini or Small System

See [build\_lite](https://gitee.com/openharmony/build_lite/blob/master/README.md).

## Building a Standard System

See [build](https://gitee.com/openharmony/build).

## Repositories Involved

**Compilation and building**

[build\_lite](https://gitee.com/openharmony/build_lite)

[build](https://gitee.com/openharmony/build)
