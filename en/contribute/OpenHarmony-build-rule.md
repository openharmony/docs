# OpenHarmony Build Specifications

## Overview

This topic aims to guide OpenHarmony developers to enhance the build reproducibility, maintainability, and quality. The build standards team has analyzed a variety of typical build issues and summarized the build guidelines and recommendations in this topic.

## General Build Principles

**P01 Automate the entire build process.**

Manual operations are error-prone and time-consuming. Automate all the build operations to make the build process more efficient and reliable.

**P02 Make build projects and build environments code-based.**

Use a high-level build framework such as CMake, Maven, and Gradle to describe build projects, and use Ansible or Dockerfile to describe build environments.

This principle helps hide the complexity of the build system from developers.

**P03 Make the build process reproducible and traceable.**

Manage build dependencies and always explicitly specify fixed dependency versions to ensure version consistency. Incorporate build environments and build projects into the configuration file as configuration options to ensure that the build projects are traceable.

**P04 Ensure that the build scripts are simple, clear, and easy to maintain.**

Build scripts are also code and should be easy to read.

**P05 Standardize the build process.**

The build directory structure, dependencies, initialization, entry, and naming must be standardized to ensure consistency among all OpenHarmony products, platforms, and components for easier management and maintenance.

## Build Projects

### General Guidelines

#### One-Click Build

##### G.COM.01 Use build scripts to implement one-click, automated build by delivery unit.

One-click, automated build means that no manual interventions are allowed throughout the entire build process (until the final delivery package is generated) in a build environment.

Manual interventions include but are not limited to: manual parameter setting on the IDE; file directory creation or deletion; file creation, copying, moving, deletion, or renaming; manual setting of file attributes; file compression/decompression. 

Delivery unit refers to a product, platform, or component that can be independently compiled, loaded, deployed, and run.

[Type] Requirement

[Description] One-click build improves operation efficiency while greatly reducing the possibility of operation errors.

[Negative Example] The one-click build of a component can be triggered only by the CI system but cannot be triggered locally.

[Negative Example] Manually set the memory mapping address on the Xplorer IDE UI for a component, and then perform manual build.

[Negative Example] Manually create the **r6c03_view\r6c03_client_view** directory for a component.

[Positive Example] Use the python script to automatically create a directory.

```python
dir_src = os.getcwd()
dir_client_view = r"r6c03_client_view"
# os.path is used to shield system differences.
dir_mk = os.path.join(dir_src, dir_client_view)

cmd = "{0} {1}".format("mkdir", dir_mk)
cmd_re = subprocess.run(cmd)
```

#### Build Directory

##### G.COM.02 DO NOT delete or modify source code files and their directory structures during build.

[Type] Forbidden

[Description]

- If the source code directory structure is deleted or modified during the build, the build process will be non-reproducible.

- During the build, the build output (including the target files, temporary files, and build logs) should not pollute the source code directory. 

- During the build, do not modify source files, including but not limited to copying, moving, and running **dos2unix** to convert the source code format. Any modification to the source files must be completed in the code preparation phase before the build. 

- The tool-triggered, automatic generation of source code must also be completed in the preparation phase before the build. If tools are used to automatically generate source code during the build, the source code generated (low-value and reproducible) must be isolated from the existing source code directory for better distinguishing, so as to reduce the complexity of the build system.

[Exception] Some source code may be added or adjusted during patch build.

##### G.COM.12 Provide appropriate permissions for files and directories created during the build.

[Type] Requirement

[Description] Directories or files of the target system that are created during the build must comply with the design of least privilege. For example, do not create directories or files with the **777** permission in the Linux system during the build.

For details about common directory files and permissions in the Linux system, see the *Linux Security Configuration Standard*.

#### Build Initialization

##### G.COM.03 Provide the clean command for each component.

- If the **clean** command is executed with no arguments specified, all target files, temporary files, and build logs in the build project of the current level will be cleared, and the **clean** commands of the lower-level build project are recursively called to restore the build projects to the initial state.
- If the **clean** command is executed with certain arguments specified, only the corresponding target files, temporary files, and build logs generated in the specified build will be cleared.

[Type] Requirement

[Description] The **clean** command prevents a build from being affected by historical build files and build logs, ensuring build reproducibility. The **clean** command without any arguments must be supported. The **clean** command with arguments applies only to internal delivery and local build.

[Positive Example]

```
base_dir
 |---build.suffix
 |---logs
 |---component_depository_1
    |---build.suffix
    |---logs
 |---component_depository_2
    |---build.suffix
    |---logs

# No arguments
base_dir/build.suffix clean
#....Call clean of component_depository_1 and component_depository_2.

# With arguments: component name
base_dir/build.suffix clean component_depository_1
#....Call clean of component_depository_1 only.

# With arguments
component_depository_1/build.suffix clean makebin hert umpt
#....Call clean of the umpt board of component_depository_1.
```

##### G.COM.04 Clear legacy build files in the build environment before the build of a component.

[Type] Requirement

[Description] If code is downloaded for the first time and the build environment has been initialized, the build environment does not have legacy build files. In this case, you do not need to run the **clean** command. If build has been performed, run the **clean** command to clear legacy build files.

#### Full Build

##### G.COM.05 For a version release build, recompile all the archived deliverables (including all dependent platforms and components). DO NOT use incremental build. DO NOT change the installation disk by manually replacing files.

A version release build refers to the build of a formally released product version (including all dependent platforms and components).

[Type] Requirement

[Description] Conducting incremental build after file modification may cause failures in updating some binary files and integrating new security build options into the version, causing inconsistent build results. Manually replacing files may make the build unreproducible and inconsistent.


#### Build Configurations

Separate the build configuration data from the build script to prevent the build project architecture from decaying. Store configuration data, such as the source code path, build options, and target file path, in a file different from the file that stores the build script to minimize the maintenance cost of build scripts.

##### G.COM.06 DO NOT use a file that is strongly bound to the operating system (for example, an Excel file) as a build configuration file. Use a file format recognized by different platforms, such as an XML file, as the build configuration file.

[Type] Requirement

[Description] Using an Excel configuration file brings the following problems:

- The file calls Microsoft Office APIs during the build. Each time the Excel file is accessed, the Excel program is started in the background, causing slow responding.

- A large number of Excel configurations require manual operations on the GUI, resulting in poor manageability.

#### Build Logs

##### G.COM.07 Generate simple and clear build logs, and use the format "timestamp + [module name](optional) + log level + log content" for each log record.
[Type] Requirement

You are advised to set the timestamp in the format of date and time, for example, *MM/dd/yyyy HH:mm:ss*.

Log levels are classified into error, warning (warn), and information (info), either in lowercase or uppercase.

You are advised to use square brackets ([]) to enclose each part of a log record.

[Positive Example]

[05/21/2020 00:12:40] [ERROR] mkdir: cannot create directory Permission denied.

[Exception] If the entire log is automatically generated by a tool, you can skip the log file in the following way: Output "This project is built using + *tool name*" at the beginning of the log, for example, "This project is built using CMake."

##### G.COM.08 Stop the build if error is displayed in the log.

[Type] Requirement

[Description] An error log indicates a build error that requires manual intervention, for example, an incorrect environment variable, tool version error, operating system error, or incorrect software source code. For a version release build, all errors generated during the build must be eliminated. DO NOT shield build errors.

[Negative Example] A component is successfully built, but the build log contains a large amount of exception information, such as "fail", "critical", "cannot", "not found", "missing" and "no input files".

##### G.COM.09 Retain only the logs of the current build in the build log file.

[Type] Requirement

[Description] Retaining historical build logs in the build log file may cause confusing. For example, when a new build fails, users may confuse the logs of historical successful builds with those of the new build and mistakenly consider the new build successful.

##### G.COM.10 Add the corresponding module name to each log for quick fault locating.

[Type] Recommendation

[Description] If there are a large number of logs, it is difficult to quickly locate the module involved in a specific fault. Adding the corresponding module name facilitates quick fault locating.

[Exception] The native logs of tools such as CMake contain the module paths, which can be used to locate the modules. For such logs, you do not need to add the module name information.

#### Build Users

##### G.COM.11 DO NOT use the super administrator **root** or system user for build. Instead, use a common user account.

[Type] Requirement

[Description] The super administrator **root** and system user have high system permissions. Using such an account for the build may cause the build environment to be tampered with.

In the installation state, the **root** user account can be used. In the running state, use a common user account. If you need to run the **sudo** command for privilege escalation, comply with *IAM Security Design Specifications*.

#### Build Output Files

##### G.COM.12 Follow the industry conventions for build output file name extensions.

[Type] Requirement

[Description] An incorrect file name extension is misleading.

The file name extensions of the output files, such as .lib and .obj files, must comply with the default naming rules of the build tools.

[Negative Example] A text file is named ***Example*.lib**.

[Negative Example] An object file is named ***Example*.a**.

[Negative Example] A static library is named **lib*Example***, without a file name extension.

[Positive Example] Query the common file name extension conventions at http://www.fileextension.org/, https://fileinfo.com/, https://www.file-extensions.org/, and http://file-extension.net/.

Conventions about common file name extensions are as follows:

| File Name Extension| Type Convention            | File Name Extension| Type Convention       |
| ---------- | -------------------- | ---------- | --------------- |
| .a         | Static library              | .so        | Dynamic library         |
| .o         | Object file          | .7z        | 7-zip compressed file   |
| .tar       | TAR archive file         | .gz/.gzip  | GNU zip archive file|
| .pack      | Java pack200 compressed file| .rar/.rar5 | RAR compressed file      |

### C/C++ Build Projects

#### Build Directory

##### G.C&C++.01 Standardize the build directory structure.

Build directories are classified into Source Tree, Build Tree, and Install Tree by functionality.

- Source Tree is the directory for storing source code and build scripts.
- Build Tree is the directory for storing build middleware. Generally, the directory name is **build**.
- Install Tree is the directory for storing build deliverables. The directory name is fixed at **output**.

The Source Tree, Build Tree, and Install Tree directories should be isolated from each other and should not overlap. One directory cannot be used for two or more purposes. For example, it is prohibited that a directory is used as both Source Tree to store source code and Build Tree to store build middleware.

Source Tree contains the following files and directories:

- Build tool entry file, such as **CMakeLists.txt**. After the **add_subdirectory()** command is executed in the upper-level **CMakeLists.txt** file, the CMake automatically invokes the **CMakeLists.txt** files in the subdirectory and lower-level subdirectories.
- **build.*suffix*** script file, which is the one-click build entry. You only need to invoke this script to complete the build. In the build entry file name, *.suffix* (such as .bat, .sh, or .py) indicates the programming language used by the build script.
- **config.*suffix*** configuration file, which is used to store build options and is the unique entry for configuration.
- Build script directory, which is optional. For example, the **cmake** directory is used to store CMake scripts. CMake script files include macros, functions, and the toolchain. The **CMakeLists.txt** script contains CMake script files by executing the **include()** command, and invokes the macros and functions in the script files.
- Component code directory, which is used to store source code and build scripts of each component.

Among the preceding files and directories, only the **CMakeLists.txt**, **build.*suffix***, and **config.*suffix*** files are mandatory. Other files and directories are optional and provided as examples for your better understanding.

Build Tree contains the following directories:

- **build** directory, which is used to store the build middleware. This directory may be created during the build process and may not exist in the Git repository. If the **build** directory is used to store build scripts, you can create another directory as Build Tree.

Install Tree contains the following directories:

- **output** directory, which is used to store deliverables. This directory may be created during the build process and may not exist in the Git repository.

[Type] Requirement

[Description]

A typical directory structure is as follows:

```
base_dir
 |---CMakeLists.txt      ---|
 |---build.suffix           |
 |---config.suffix          |
 |---cmake                  |--> Source Tree
 |---component_1            |
 |---component_2            |
 |---......                 |
 |---component_n         ---|
 |---build               ------> Build Tree
 |---output              ------> Install Tree
```

The directory structure of each component is similar to the top directory structure. Example:

```
component_1
 |---CMakeLists.txt      ---|
 |---build.suffix           |
 |---config.suffix          |
 |---cmake                  |--> Source Tree
 |---module_1               |
 |---module_2               |
 |---......                 |
 |---module_n            ---|
 |---build               ------> Build Tree
 |---output              ------> Install Tree
```

##### G.C&C++.02 DO NOT modify Source Tree in any form during the build process.

[Type] Recommendation

[Description] If Source Tree is modified during the build, the build process will be non-reproducible.

The common operations for modifying Source Tree are as follows:

- Patch installation
- Dotting
- Tailoring
- Automatic source code generation
- Modifying source code and then restoring it
- Adding, modifying, or deleting temporary files or directories
- Modifying the attribute or format of a file or directory (For example, modify the execute permission of a file or **dos2unix**.)

Recommended operations are as follows:

(1) Copy code to Build Tree, install a patch, and build the code.

(2) As the dotting tool modifies source code and makes the build process untrustworthy, do not use the dotting tool during the build. Instead, upload the dotted code to the code repository and use the dotted code for the build.

(3) Tailoring is an independent source code delivery requirement and can be considered as the code preparation phase. Source Tree in the versions before and after tailoring must not be modified during the build.

(4) The automatically generated source code must be stored in Build Tree.

(5) Modifying and then restoring source code is prohibited because the source code has changed during the build.

(6) Temporary files or directories must be stored in Build Tree.

(7) Ensure that the attributes and formats of files in the code repository are correct to prevent modifying them during the build.

To check for Source Tree changes, run the **git status** command in the source code directory after the build. Source Tree should not have any change. The **git status** command may fail to detect changes to Source Tree where source code is modified and then restored.

[Exception]

(1) Changes in the Build Tree and Install Tree directories detected by the **git status** command are allowed.

(2) Tailoring-caused changes detected by the **git status** command are allowed.

##### G.C&C++.03 Use D:\*deliveryUnitName + versionNumber (optional)* and /usr1/*deliveryUnitName + versionNumber (optional)* as the build root directory in Windows and Linux, respectively.

[Type] Recommendation

[Description] Name the build root directory in the format of *deliveryUnitName + versionNumber*, where *versionNumber* is optional. DO NOT use the directory name that cannot identify a specific delivery unit, such as **build** or **code**.

A clear build directory structure helps test personnel set build parameters, execute one-click build entries, and compare build results.

The following are two root directory examples:

```
D:\Offering [Version (optional)] or /usr1/Offering [Version (optional)]
```

##### G.C&C++.04 Store all middleware generated during the build in Build Tree.

[Type] Requirement

[Description] The middleware generated during the build includes the makefile automatically generated by the build tool CMake, the source code automatically generated by the build script, the source code and patches copied by the build script, as well as the object files, repository files, executable programs, and build logs generated during the build. Store the middleware in Build Tree only, to avoid pollution to Source Tree or Install Tree. Do not store anything else in Build Tree.
Create the **logs** subdirectory under Build Tree and name build log files in .log format.

##### G.C&C++.05 You can specify any directory except Source Tree and Install Tree as Build Tree.

[Type] Requirement

[Description] You can specify any directory other than Source Tree and Install Tree as Build Tree. In this way, the build process is irrelevant to the directory. The directory where the build is executed is Build Tree, and the build middleware is stored in this directory. Generally, the Build Tree directory name is **build**. You can also use another name.

[Positive Example] Use CMake system variables **CMAKE_BINARY_DIR** and **CMAKE_CURRENT_BINARY_DIR** to access Build Tree to prevent coupling between Build Tree and Source Tree.

##### G.C&C++.06 Store all deliverables in Install Tree.

[Type] Requirement

[Description] In the local build scenario, deliverables are directly installed on the host computer and run. In the cross-build scenario, deliverables run on the target computer.

The deliverables include library files, executable programs, package files, and header files. They are binary interfaces provided by components. All the deliverables must be stored in Install Tree.

Do not place any file other than deliverables (such as build middleware) in Install Tree.

##### G.C&C++.07 You can specify any directory except Source Tree and Build Tree as Install Tree.

[Type] Requirement

[Description] You can specify any directory other than Source Tree and Build Tree as Install Tree. In this way, the build process is irrelevant to the directory. The Install Tree directory name is fixed at **output**.

[Positive Example] The CMake build project supports the function of specifying the Install Tree directory through the system variable **CMAKE_INSTALL_PREFIX**.

#### Build Entry

##### G.C&C++.08 Provide a unique build entry for each delivery unit. Name all the build entry scripts in the **build.*suffix*** format, and store them in the build root directory.

[Type] Requirement

[Description] A unique build entry allows for a more efficient and automated build process. Each delivery unit has a unique build entry, making one-click, automated build possible.

[Negative Example] The following build has multiple entry points. If no description document is provided, it is difficult to determine which entry point is correct.

build.bat 

build_all.sh 

build_v6.sh 

[Positive Example] A typical one-click build script **build.sh** is as follows:

```bash
#!/bin/bash

if [ -d "build" ]; then
    rm -fr build/*
else
    mkdir build
fi

if [ -d "output" ]; then
    rm -fr output/*
else
    mkdir output
fi

cd build
cmake ..

cpu_processor_num=$(grep processor /proc/cpuinfo | wc -l)
job_num=$(expr "$cpu_processor_num" \* 2)
echo Parallel job num is "$job_num"
make -j"$job_num"
```

##### G.C&C++.09 You can specify the build target.

[Type] Requirement

[Description] In routine development scenarios, you can specify the target to build modified code. A project can be built by specifying the target to meet flexible build and debugging requirements.

[Positive Example] A typical command is as follows:

```
base_dir # cd build
base_dir/build # cmake ..
# Build all targets.
base_dir/build # make
# Build a specific target.
base_dir/build # make target_name
```

##### G.C&C++.10 Reproducible build is supported.

[Type] Requirement

[Description] If you do not modify the source code, clear the middleware and deliverables, or modify the build environment after the last successful build, you can perform a new round of build and obtain the same result.

##### G.C&C++.11 Incremental build is supported.

[Type] Recommendation

[Description] In routine development scenarios, incremental build can improve development efficiency. Therefore, it is advised to support incremental build.

##### G.C&C++.12 Parallel build is supported.

[Type] Requirement

[Description] You can run the **make -jN** command for quicker parallel build. This guideline applies only to projects that use the make tool.

Support unified scheduling in jobserver mode to optimize the project load to the best level. The following alarms are not allowed:

```
warning: jobserver unavailable: using -j1.  Add '+' to parent make rule.
warning: -jN forced in submake: disabling jobserver mode.
```

To support the jobserver mode, perform any of the following operations:

1. Use **$(MAKE)** to directly invoke the **make** command.

    ```cmake
    ExternalProject_Add(foo
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/foo
        CONFIGURE_COMMAND sh configure_ext.sh
        BUILD_COMMAND $(MAKE)
    )
    ```

2. Use the shell script to invoke the **make** command.

    ```cmake
    ExternalProject_Add(foo
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/foo
        CONFIGURE_COMMAND sh configure_ext.sh
        BUILD_COMMAND sh build_ext.sh $(MAKE)
    )
    ```

   The content of **build_ext.sh** is as follows:

    ```bash
    #!/bin/bash

    make
    ```

   Note: **build_ext.sh** does not need to parse or use the **$(MAKE)** parameter.

3. Use the python script to invoke the **make** command.

    ```cmake
    ExternalProject_Add(foo
        SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/foo
        CONFIGURE_COMMAND sh configure_ext.sh
        BUILD_COMMAND python build_ext.py $(MAKE)
    )
    ```

   The content of **build_ext.py** is as follows:

    ```bash
    #!/usr/bin/python
    # -*- coding: UTF-8 -*-

    import subprocess

    def main():
        child = subprocess.Popen("make", close_fds=False)
        ret = child.wait()
        return
            
    if __name__ == '__main__':
        main()
    ```

    Note: **build_ext.py** does not need to parse or use the **$(MAKE)** parameter.


#### Build Dependencies

##### G.C&C++.13 Define a build dependency file **dependence.xml** to describe all components on which the build depends. The build script automatically reads the dependency file to produce the final software package.

[Type] Recommendation

[Description] Make software packages based on the dependency file, so that you do not need to define dependency components in the build scripts. This improves the build process maintainability.

#### Build Configurations

##### G.C&C++.14 Use the configuration file **conﬁg.*suﬃx*** in the build root directory as the unique configuration entry for the entire delivery project.

[Type] Requirement

[Description] Expose the least configuration options in the top-level **conﬁg.*suﬃx*** file. Configure only the information about the build environment and build tool in this file.

[Exception] If there are a small number of build options and key-value pairs are used, the configuration file can be named **config.conf**.

### GN Build Specifications

#### Build Rules

##### Rule 1.1 DO NOT use GN to invoke external build tools to build software modules.

[Type] Forbidden

[Description] Port external components to the GN build mode to avoid unnecessary dependencies on the environment during the build and obtain common capabilities, such as compiler security options and AddressSanitizer (ASan), provided by the build framework.

[Negative Example] In GN, use **action** to invoke **automake** and **Make** to build third-party components.

[Exception] The Linux kernel build framework builds user-mode programs. The kernel can be independently built outside the build framework. It is acceptable that some platforms use GN to include the kernel build in the build process to deliver one-click builds.

##### Rule 1.2 DO NOT add compiler security options that have been added to the build system to the GN file of the module.

[Type] Forbidden

[Description] The default options that have been added globally should not be added again to meet internal and external rules.

| Option| Parameter   | Default Value    |
|---------|------------|------------|
| Stack protection  | -fstack-protector-strong| Enabled|
| Fortify Source | -D_FORTIFY_SOURCE=2 -O2	| Enabled|

[Negative Example] Add **-fstack-protector-strong** to the GN file of the module.

##### Rule 1.3 DO NOT add build options that are opposite to the default build options to GN.

[Type] Forbidden

[Description] The default build options represent the default capabilities of the build system. If your module needs to remove some default build options, there must be sufficient reasons.

[Negative Example] Add **-wno-unused** to a module to clear build alarms.

[Exception] When porting or using a third-party component, you can overwrite the default build options based on the component requirements.

##### Rule 2.1 Use **gn format** to format GN files to meet the format and typesetting requirements.

[Type] Requirement

##### Rule 2.2 Use Python instead of shell to compile **action**.

[Type] Recommendation

[Description] The Python environment is easier to keep code unified and can run on multiple operating systems. It also provides better scalability, readability, and testability.

##### Rule 2.3 DO NOT modify the content in the source code directory during the execution of GN and Ninja.

[Type] Forbidden

[Description] The forbidden operations include but are not limited to installing patches for, copying files to, performing build tasks in, and generating intermediate files in the source code directory.

##### Rule 2.4 Set the encoding format of the build script to UTF-8 and the newline character to UNIX format.

[Type] Requirement

[Negative Example] After a script is compiled on Windows, Chinese comments are used and saved as local codes.