# Compilation and Building Overview<a name="EN-US_TOPIC_0000001060646620"></a>

-   [Basic Concepts](#section175012297491)
-   [Working Principles](#section193961322175011)
-   [Limitations and Constraints](#section2029921310472)

The compilation and building subsystem provides a framework based on Generate Ninja \(GN\) and Ninja. This subsystem allows you to:

-   Build products based on different chip platforms. For example, you can build IP camera products on the Hi3518EV300 and Hi3516DV300 development boards and WLAN module–based products on Hi3861 development boards.

-   Build a customized product that is generated according to HarmonyOS Package Manager \(HPM\) configurations.

## Basic Concepts<a name="section175012297491"></a>

It is considered best practice to learn the following basic concepts before you start development, compilation, and building:

-   **Platform**

    A platform is a combination of development boards and kernels.

    Supported subsystems and components vary with the platform.

-   **Component**

    A component is a reusable software unit that contains source code, configuration files, resource files, and compilation scripts.

-   **GN**

    GN is short for Generate Ninja, which is used to generate Ninja files.

-   **Ninja**

    Ninja is a small high-speed building system.


## Working Principles<a name="section193961322175011"></a>

The compilation and building processes are as follows:

-   **Parsing**: Parse the name of the product to be compiled and the compilation type \(debug or release\).
-   **Running GN**: Configure toolchains and global options for the compilation based on the product name and compilation type that have been parsed.
-   **Running Ninja**: Start the compilation.
-   **Packaging**: Package the component compilation result of the product to create a file system image.

## Limitations and Constraints<a name="section2029921310472"></a>

You must install GN and Ninja and compilation toolchains, and download the complete code.

