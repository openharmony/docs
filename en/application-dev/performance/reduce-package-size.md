# Reduce the size of the application package.

## Introduction

Reducing the size of an application package is one of the important ways to improve application download and installation experience. By compressing, simplifying, or reusing code or resources in an application, a size of the application can be effectively reduced, an application download and installation speed can be improved, and system space occupation can be reduced.

You can use any of the following methods to reduce the size of an app package:

 - Configure the SO compression option to compress the SO library to reduce the size of the application package.
 - When an application has multiple packages (HAP and HSP), the [HSP (Harmony Shared Package) ](../quick-start/in-app-hsp.md) dynamic sharing package can be used to share code and resources among multiple packages (HAP and HSP) of the application, eliminating the use of [HAR (Harmony Archive)]. (../quick-start/har-package.md) Statically shared packages cause repeated copy of code and resources between multiple packages (HAP and HSP), reducing the size of application packages.
 - Use the scanning tool to scan and analyze the app, HAP, and HSP packages, and take measures to optimize the application based on the output detection report.

## Method of Reducing the Size of an Application Package

### Configuring SO Compression Options

By default, the DevEco Studio does not compress .so library files during application packaging. After the .so compression option is configured, the DevEco Studio compresses .so library files into a package to reduce the application package size.

**Configuration Method**

Change the value of the [compressNativeLibs](../quick-start/module-configuration-file.md) field in the application module configuration file module.json5 to true, and recompile and package the application.

```json
{
  "module": { 
    // ...
    "compressNativeLibs": true //Indicates that the libs library is packaged in compression storage mode.
  }
}
```

**SO compression effect**

The following uses the default C++ library file in DevEco Studio as an example. The file sizes before and after compression are compared as follows:

| File Name                                 | Original Size      | Size After Compression    | Compression Rate |
| --------------------------------------- |---------------| -------------- | ----  |
| armeabi-v7a/libc++_shared.so            |1,108k         |386k             | 34%  |

### Using HSP to Share Code and Resources in Multi-Packet Scenarios

The current system provides two types of packages: ../quick-start/shared-guide.md and HAR (Harmony Archive) (../quick-start/har-package.md). Static shared package and [HSP (Harmony Shared Package) ](../quick-start/in-app-hsp.md) dynamic shared package.

Both the HAR and HSP are used to share code and resources and can contain code, C++ libraries, resources, and configuration files. The biggest differences between them are as follows: The code and resources in the HAR are compiled with the invoking module, and if there are multiple invoking modules, the build product contains multiple copies of the same code and resources; the code and resources in the HSP are compiled independently, and the build product contains only one copy of the code and resources.

In the multi-package scenario, if multiple HAP or HSP packages of an application use the HAR package to share code and resources, each packaged HAP or HSP package contains a copy of the shared HAR package. As a result, the app package contains redundant code and resources. As shown in the following figure, the application modules HAP1 and HAP2/HSP1 reference HAR2 and HAR3. After packaging, HAR2 and HAR3 in the app package have multiple duplicate copies, which are large in size.

![HAR Reference by Multiple HAP] (./figures/reduce-package-size-har.PNG)

In this scenario, it is recommended that developers use HSP instead of HAR to implement code and resource sharing. As shown in the following figure, HSP2 is used to upgrade and reconstruct the original application. After packaging, only one copy of HAR2 and HAR3 exists in the application package. If the total size of HAR2 and HAR3 is greater than HSP (11 KB), you can reduce the application package size.

![HSP referenced by multiple HAP] (./figures/reduce-package-size-hsp.PNG)

### Use the scanning tool to analyze the application package.

[Scanning Tool] (../tools/app-check-tool.md) can be used to analyze and detect application packages. Based on different parameter settings, the scanning tool scans the app, HAP, and HSP packages in a specified path and generates a detection result report, this feature provides data support for developers to optimize the package structure or locate problems. The tool provides the following functions:
- Scans for duplicate files.
- Scans for large files (files that exceed the specified size).
- Collects statistics on the size and proportion of each type of file.

Based on the scanning result, optimize the application as follows:

1. Duplicate file.
    - If a package contains duplicate resources, delete the duplicate resources.
    - If resources are repeated among multiple packages (HAP and HSP), HSP can be used to reuse resources.

2. Large file
    - Check whether the application is mandatory and whether the application can be deleted.
    - JPG, PNG, and GIF files can be compressed.

3. Files of a Specific Type
    - SO file. You can configure the SO compression option to compress and pack the file.
    - JPG, PNG, and GIF files can be compressed.
