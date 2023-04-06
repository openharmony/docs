# Porting a Library Built Using Makefile

The following shows how to port the yxml library.

## Source Code Acquisition

Acquire the source code of yxml from [the open-source repository](https://github.com/getdnsapi/yxml). The following table lists the directory structure.

**Table 1** Directory structure of the source code

| Directory           | Description                                                 |
| ------------------- | ----------------------------------------------------------- |
| yxml/bench/         | Benchmark-related code                                      |
| yxml/test/          | Input and output files as well as scripts of the test cases |
| yxml/Makefile       | File for organizing compilation                             |
| yxml/.gitattributes | -                                                           |
| yxml/.gitignore     | -                                                           |
| yxml/COPYING        | -                                                           |
| yxml/yxml.c         | -                                                           |
| yxml/yxml.c.in      | -                                                           |
| yxml/yxml-gen.pl    | -                                                           |
| yxml/yxml.h         | -                                                           |
| yxml/yxml.md        | -                                                           |
| yxml/yxml-states    | -                                                           |


## Cross-Compilation Settings

The following steps show how to configure and modify the toolchains for cross-compiling the libraries built using CMake to compile executable files for the OpenHarmony platform.

1.  Configure the toolchains.

    Replace the original configuration of MakeFile \(listed in Table 1) in the root directory of the yxml library with the following clang toolchains configuration.

    clang toolchains configuration:

    ```
    # Set the cross-compilation toolchain and ensure that the path of the toolchain has been added to the PATH environment variable.
    CC:=clang
    AR:=llvm-ar
    # The --target and --sysroot flags must be specified.
    CFLAGS:=-Wall -Wextra -Wno-unused-parameter -O2 -g --target=arm-liteos -march=armv7-a --sysroot=$(OHOS_SYSROOT_PATH)
    ```

    Original configuration:

    
   ```
   CC:=gcc
   AR:=ar
   CFLAGS:=-Wall -Wextra -Wno-unused-parameter -O2 -g
   ```

2.  Perform the compilation.

    Run a Linux command to enter the directory \(listed in Table 1) for storing yxml source files and then run the following command:
    
   ```
   make test OHOS_SYSROOT_PATH=...
   ```

    **OHOS\_SYSROOT\_PATH** specifies the absolute path of the directory where **sysroot** is located. For OpenHarmony, set **OHOS\_SYSROOT\_PATH** to the absolute path of the **out/hispark\__xxx_/ipcamera\_hispark\__xxx_/sysroot** directory. This directory is generated after full compilation is complete. Therefore, complete full compilation before porting.

3.  View the result.

    After step 2 is complete, a static library file and test case are generated in the **out** directory of the yxml library.

    **Table 2** Directory structure of compiled files

    | Directory                                   | Description                                      |
    | ------------------------------------------- | ------------------------------------------------ |
    | OpenHarmony/third_party/yxml/yxml/out/lib/  | Static library file.                              |
    | OpenHarmony/third_party/yxml/yxml/out/test/  | Test cases as well as the input and output files. |
    
    
    


## Library Test

The test procedure for the yxml library is similar to that for the double-conversion library. For details, see the procedure described in [Porting a Library Built Using CMake](../porting/porting-thirdparty-cmake.md#library-test). The following describes how to use the test cases of the yxml library.

**Table 3** Directory structure of the test directory

| Directory                                          | Description                                                  |
| -------------------------------------------------- | ------------------------------------------------------------ |
| OpenHarmony/third_party/yxml/yxml/out/test/test.sh | Automatic test script, which cannot be used because OpenHarmony does not support automatic script execution. However, you can refer to this script to conduct a manual test. |
| OpenHarmony/third_party/yxml/yxml/out/test/test    | Executable file for testing.                                 |
| OpenHarmony/third_party/yxml/yxml/out/test/\*.xml   | Input test file.                                             |
| OpenHarmony/third_party/yxml/yxml/out/test/\*.out   | Expected output file.                                        |

The content of the **test.sh** file is as follows:

```
#!/bin/sh
for i in *.xml; do
  b=`basename $i .xml`
  o=${b}.out
  t=${b}.test
  ./test <$i >$t
  if [ -n "`diff -q $o $t`" ]; then
    echo "Test failed for $i:"
    diff -u $o $t
    exit 1
  fi
done
echo "All tests completed successfully."
```

The shell of OpenHarmony does not support input and output redirection symbols \(< and \>\). During the test, you need to copy the content in the **_\*_.xml** file to the shell and press **Enter**. The output content is displayed in the shell screen.

The following operations are performed based on the assumption that the OpenHarmony environment has been set up and the **nfs** directory has been mounted and accessed.

1.  Execute the following command:

    ```
    ./test
    ```

2.  Copy the content in the **_\*_.xml**  file to shell.

    Taking the **pi01.xml** file in the **test** directory as an example, copy the following content to shell and press **Enter**:

   ```
   <?SomePI abc?><a/>
   ```

3.  Check whether the output in the shell is the same as that of the **_\*_.out** file in the **test** directory described in Table 3.

    The output is as follows:

    ```
    pistart SomePI
    picontent abc
    piend
    elemstart a
    elemend
    ok
    ```

    The output is the same as the **pi01.out** file in the **test** directory listed in Table 3. In this case, the test is passed.


## Adding the Compiled yxml Library to the OpenHarmony Project

The procedure for adding the yxml library is almost the same as that for adding the double-conversion library, except that the implementation of **build.gn** and **config.gni** files. For details, see the procedure described in [Adding the Compiled double-conversion Library to the OpenHarmony Project](../porting/porting-thirdparty-cmake.md#adding-the-compiled-double-conversion-library-to-the-openharmony-project).

-   The implementation of the newly added **BUILD.gn** file in the yxml library is as follows:

  ```
  import("config.gni")
  group("yxml") {
      if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
          deps = [":make"]
      }
  }
  if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
      action("make") {
          script = "//third_party/yxml/build_thirdparty.py"
          outputs = ["$target_out_dir/log_yxml.txt"]
          exec_path = rebase_path(rebase_path("./yxml", root_build_dir))
          command = "make clean && $MAKE_COMMAND"
          args = [
              "--path=$exec_path",
              "--command=${command}"
          ]
      }
  }
  ```

-   The configuration of the newly added  **config.gni**  file in the yxml library is as follows:

  ```
  TEST_ENABLE = "YES"

  if (TEST_ENABLE == "YES") {
    MAKE_COMMAND = "make test OHOS_SYSROOT_PATH=${root_out_dir}sysroot/"
  } else {
      MAKE_COMMAND = "make OHOS_SYSROOT_PATH=${root_out_dir}sysroot/"
  }
  ```

- The following table lists the directory structure of the OpenHarmony project.

  **Table 4** Directory structure of the ported library

  | Directory                                       | Description                                                  |
  | ----------------------------------------------- | ------------------------------------------------------------ |
  | OpenHarmony/third_party/yxml/BUILD.gn           | GN file for adding the third-party library to the OpenHarmony project. |
  | OpenHarmony/third_party/yxml/build_thirdparty.py | Script file for GN to call the **shell** command to convert compilation from GN to Makefile. |
  | OpenHarmony/third_party/yxml/config.gni         | Third-party library compilation configuration file, which can be modified to determine whether the test cases will be used during the building. |
  | OpenHarmony/third_party/yxml/yxml/              | Directory of the third-party library to be ported.           |

 <!--no_check--> 
