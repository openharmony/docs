# Porting a Library Built Using CMake<a name="EN-US_TOPIC_0000001200172241"></a>

The following shows how to port the double-conversion library.

## Source Code Acquisition<a name="section1771132116245"></a>

Acquire the source code of double-conversion from  [https://github.com/google/double-conversion](https://github.com/google/double-conversion). The following table lists the directory structure.

**Table  1**  Directory structure of the source code

<a name="table824211132418"></a>
<table><thead align="left"><tr id="row524220131043"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p22421213442"><a name="p22421213442"></a><a name="p22421213442"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p132427131241"><a name="p132427131241"></a><a name="p132427131241"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1335114463010"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p3354144414307"><a name="p3354144414307"></a><a name="p3354144414307"></a>double-conversion/cmake/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1235564417307"><a name="p1235564417307"></a><a name="p1235564417307"></a>Template used for building with CMake</p>
</td>
</tr>
<tr id="row1024211133411"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12423137414"><a name="p12423137414"></a><a name="p12423137414"></a>double-conversion/double-conversion/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p824221314420"><a name="p824221314420"></a><a name="p824221314420"></a>Directory of source files</p>
</td>
</tr>
<tr id="row1242813545"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p424213131343"><a name="p424213131343"></a><a name="p424213131343"></a>double-conversion/msvc/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p172429139418"><a name="p172429139418"></a><a name="p172429139418"></a>-</p>
</td>
</tr>
<tr id="row20242513641"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p2024210139412"><a name="p2024210139412"></a><a name="p2024210139412"></a>double-conversion/test/</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p7242713241"><a name="p7242713241"></a><a name="p7242713241"></a>Source files of the test cases</p>
</td>
</tr>
<tr id="row12242191314413"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p172420131646"><a name="p172420131646"></a><a name="p172420131646"></a>double-conversion/.gitignore</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p112426131843"><a name="p112426131843"></a><a name="p112426131843"></a>-</p>
</td>
</tr>
<tr id="row1484211616360"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1384206143617"><a name="p1384206143617"></a><a name="p1384206143617"></a>double-conversion/AUTHORS</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p384310614366"><a name="p384310614366"></a><a name="p384310614366"></a>-</p>
</td>
</tr>
<tr id="row1290331063610"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p18903410183613"><a name="p18903410183613"></a><a name="p18903410183613"></a>double-conversion/BUILD</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1990491033617"><a name="p1990491033617"></a><a name="p1990491033617"></a>-</p>
</td>
</tr>
<tr id="row5967101420368"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p696710141361"><a name="p696710141361"></a><a name="p696710141361"></a>double-conversion/CMakeLists.txt</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1196714147366"><a name="p1196714147366"></a><a name="p1196714147366"></a>Top-level file used for building with CMake</p>
</td>
</tr>
<tr id="row19372034133612"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1596214484473"><a name="p1596214484473"></a><a name="p1596214484473"></a>double-conversion/COPYING</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p163811348364"><a name="p163811348364"></a><a name="p163811348364"></a>-</p>
</td>
</tr>
<tr id="row0184133717364"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1166255034715"><a name="p1166255034715"></a><a name="p1166255034715"></a>double-conversion/Changelog</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p151851337193617"><a name="p151851337193617"></a><a name="p151851337193617"></a>-</p>
</td>
</tr>
<tr id="row173871412369"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p411055217475"><a name="p411055217475"></a><a name="p411055217475"></a>double-conversion/LICENSE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p9387641173617"><a name="p9387641173617"></a><a name="p9387641173617"></a>-</p>
</td>
</tr>
<tr id="row534170185015"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p035703507"><a name="p035703507"></a><a name="p035703507"></a>double-conversion/Makefile</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p6367075019"><a name="p6367075019"></a><a name="p6367075019"></a>-</p>
</td>
</tr>
<tr id="row1367804175011"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1246133725014"><a name="p1246133725014"></a><a name="p1246133725014"></a>double-conversion/README.md</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p136796410508"><a name="p136796410508"></a><a name="p136796410508"></a>-</p>
</td>
</tr>
<tr id="row2070619141508"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1963193815509"><a name="p1963193815509"></a><a name="p1963193815509"></a>double-conversion/SConstruct</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p570691485015"><a name="p570691485015"></a><a name="p570691485015"></a>-</p>
</td>
</tr>
<tr id="row186521925020"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p152191040155012"><a name="p152191040155012"></a><a name="p152191040155012"></a>double-conversion/WORKSPACE</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p4661119175014"><a name="p4661119175014"></a><a name="p4661119175014"></a>-</p>
</td>
</tr>
</tbody>
</table>

## Porting Guidelines<a name="section9737174410328"></a>

Cross-compile the double-conversion library by modifying the toolchain to generate executable files for the OpenHarmony platform and then add these files to the OpenHarmony project by invoking CMake via GN.

## Cross-Compilation<a name="section38205577332"></a>

### Compilation Reference<a name="section1088111263418"></a>

The  [README.md](https://github.com/google/double-conversion/blob/master/README.md)  file in the code repository details the procedures for compiling the double-conversion library using CMake as well as the testing methods. This document focuses on the building, compilation, and testing of the library. If you have any questions during library porting, refer to the  **README.md**  file. For porting of other third-party libraries that can be independently built with CMake, you can refer to the compilation guides provided by the libraries.

### Cross-Compilation Settings<a name="section8168182883515"></a>

The following steps show how to configure and modify the toolchains for cross-compiling the libraries built using CMake to compile executable files for the OpenHarmony platform.

1.  Configure the toolchains.

    Add configuration of the clang toolchains to the top-level file  **CMakeLists.txt**  listed in  [Table 1](#table824211132418).

    ```
    set(CMAKE_CROSSCOMPILING TRUE)
    set(CMAKE_SYSTEM_NAME Generic)
    set(CMAKE_CXX_COMPILER_ID Clang)
    set(CMAKE_TOOLCHAIN_PREFIX llvm-)
    # Specify the C compiler (ensure that the path of the toolchain has been added to the PATH environment variable) and its flags. To perform cross-compilation using clang, the --target flag must be specified.
    set(CMAKE_C_COMPILER clang)
    set(CMAKE_C_FLAGS "--target=arm-liteos -D__clang__ -march=armv7-a -w")
    # Specify the C++ compiler (ensure that the path of the toolchain has been added to the PATH environment variable) and its flags. To perform cross-compilation, the --target flag must be specified.
    set(CMAKE_CXX_COMPILER clang++) 
    set(CMAKE_CXX_FLAGS "--target=arm-liteos -D__clang__ -march=armv7-a -w")
    # Specify the linker and its flags. --target and --sysroot must be specified. You can specify OHOS_SYSROOT_PATH via the suffix parameter of the cmake command.
    set(MY_LINK_FLAGS "--target=arm-liteos --sysroot=${OHOS_SYSROOT_PATH}")
    set(CMAKE_LINKER clang)
    set(CMAKE_CXX_LINKER clang++)
    set(CMAKE_C_LINKER clang)
    set(CMAKE_C_LINK_EXECUTABLE
        "${CMAKE_C_LINKER} ${MY_LINK_FLAGS} <FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
    set(CMAKE_CXX_LINK_EXECUTABLE
        "${CMAKE_CXX_LINKER} ${MY_LINK_FLAGS} <FLAGS> <LINK_FLAGS> <OBJECTS> -o <TARGET> <LINK_LIBRARIES>")
    # Specify the path for searching chained libraries.
    set(CMAKE_SYSROOT ${OHOS_SYSROOT_PATH})
    ```

2.  Perform the compilation.

    Run a Linux command to enter the directory \(listed in  [Table 1](#table824211132418)\) for storing double-conversion source files and then run the following commands:

    ```
    mkdir build && cd build
    cmake .. -DBUILD_TESTING=ON -DOHOS_SYSROOT_PATH="..."
    make -j
    ```

    **OHOS\_SYSROOT\_PATH**  specifies the absolute path where  **sysroot**  is located. For OpenHarmony, set  **OHOS\_SYSROOT\_PATH**  to the absolute path of the  **out/hispark\__xxx_/ipcamera\_hispark\__xxx_/sysroot**  directory. This directory is generated after full compilation is complete. Therefore, complete full compilation before porting.

3.  <a name="li15717101715249"></a>View the result.

    After step 2 is complete, a static library file and test cases are generated in the  **build**  directory.

    **Table  2**  Directory structure of compiled files

    <a name="table1452412391911"></a>
    <table><thead align="left"><tr id="row15259397114"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p084365219116"><a name="p084365219116"></a><a name="p084365219116"></a>Directory</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p118435524118"><a name="p118435524118"></a><a name="p118435524118"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row17861750780"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p208014918411"><a name="p208014918411"></a><a name="p208014918411"></a>double-conversion/build/libdouble-conversion.a</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p155272391619"><a name="p155272391619"></a><a name="p155272391619"></a>Static library file</p>
    </td>
    </tr>
    <tr id="row141820612910"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p1941811618918"><a name="p1941811618918"></a><a name="p1941811618918"></a>double-conversion/build/test/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p64181761995"><a name="p64181761995"></a><a name="p64181761995"></a>Test cases and CMake cache files</p>
    </td>
    </tr>
    <tr id="row19525239815"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p452512394117"><a name="p452512394117"></a><a name="p452512394117"></a>double-conversion/build/CMakeCache.txt</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p652615391617"><a name="p652615391617"></a><a name="p652615391617"></a>Cache files during CMake building</p>
    </td>
    </tr>
    <tr id="row1526839312"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p28017499413"><a name="p28017499413"></a><a name="p28017499413"></a>double-conversion/build/CMakeFiles/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p25261439314"><a name="p25261439314"></a><a name="p25261439314"></a>-</p>
    </td>
    </tr>
    <tr id="row15269396111"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p138014494415"><a name="p138014494415"></a><a name="p138014494415"></a>double-conversion/build/cmake_install.cmake</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p75268391519"><a name="p75268391519"></a><a name="p75268391519"></a>-</p>
    </td>
    </tr>
    <tr id="row185265399113"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p78054914419"><a name="p78054914419"></a><a name="p78054914419"></a>double-conversion/build/CTestTestfile.cmake</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p65261039218"><a name="p65261039218"></a><a name="p65261039218"></a>-</p>
    </td>
    </tr>
    <tr id="row125261139115"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p158064916419"><a name="p158064916419"></a><a name="p158064916419"></a>double-conversion/build/DartConfiguration.tcl</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p20526939118"><a name="p20526939118"></a><a name="p20526939118"></a>-</p>
    </td>
    </tr>
    <tr id="row2526839712"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p6803491043"><a name="p6803491043"></a><a name="p6803491043"></a>double-conversion/build/generated/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p115269395113"><a name="p115269395113"></a><a name="p115269395113"></a>-</p>
    </td>
    </tr>
    <tr id="row173131653454"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p7803493412"><a name="p7803493412"></a><a name="p7803493412"></a>double-conversion/build/Makefile</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p19316135318512"><a name="p19316135318512"></a><a name="p19316135318512"></a>-</p>
    </td>
    </tr>
    <tr id="row4380879618"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p10381478619"><a name="p10381478619"></a><a name="p10381478619"></a>double-conversion/build/Testing/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p17381679610"><a name="p17381679610"></a><a name="p17381679610"></a>-</p>
    </td>
    </tr>
    </tbody>
    </table>


## Library Test<a name="section6686144293611"></a>

1.  Set up the OpenHarmony environment.

    Using  Hi3516D V300 as an example, compile the OpenHarmony image and burn it to the development board. For details, see  [Developing the First Example Program Running on Hi3518](../quick-start/quickstart-lite-steps-hi3516-running.md).

    The following screen is displayed after a successful login to the OS.

    **Figure  1**  Successful startup of OpenHarmony<a name="fig13279524162418"></a>  
    ![](figures/successful-startup-of-openharmony.png "successful-startup-of-openharmony")

2.  Mount the  **nfs**  directory and put the executable file  **cctest**  into the  **test**  directory \(listed in  [Table 2](#table1452412391911)\) to the  **nfs**  directory.
3.  Perform the test cases.

    If the double-conversion library is not cross-compiled, you can execute the test cases by running the  **make test**  command and obtain the result via CMake. However, this command is not applicable to the library after cross-compilation. This way, you can perform the test cases by executing the generated test case files.

    -   After the  **nfs**  directory is successfully mounted, run the following command to list all items in the test cases:

    ```
    cd nfs
    ./cctest --list
    ```

    Some items are as follows:

    ```
    test-bignum/Assign<
    test-bignum/ShiftLeft<
    test-bignum/AddUInt64<
    test-bignum/AddBignum<
    test-bignum/SubtractBignum<
    test-bignum/MultiplyUInt32<
    test-bignum/MultiplyUInt64<
    test-bignum/MultiplyPowerOfTen<
    test-bignum/DivideModuloIntBignum<
    test-bignum/Compare<
    test-bignum/PlusCompare<
    test-bignum/Square<
    test-bignum/AssignPowerUInt16<
    test-bignum-dtoa/BignumDtoaVariousDoubles<
    test-bignum-dtoa/BignumDtoaShortestVariousFloats<
    test-bignum-dtoa/BignumDtoaGayShortest<
    test-bignum-dtoa/BignumDtoaGayShortestSingle<
    test-bignum-dtoa/BignumDtoaGayFixed<
    test-bignum-dtoa/BignumDtoaGayPrecision<
    test-conversions/DoubleToShortest<
    test-conversions/DoubleToShortestSingle<
    ...
    ```

    -   Run the following command to test  **test-bignum**:

    ```
    ./cctest test-bignum
    ```

    The test is passed if the following information is displayed:

    ```
    Ran 13 tests.
    ```


## Adding the Compiled double-conversion Library to the OpenHarmony Project<a name="section1651053153715"></a>

1.  Copy the double-conversion library to the OpenHarmony project.

    Copy this library that can be cross-compiled to the  **third\_party**  directory of OpenHarmony. To avoid modifying the  **BUILD.gn**  file in the directory of the third-party library to be ported, add a directory to store adaptation files, including  **BUILD.gn**,  **build\_thirdparty.py**, and  **config.gni**, for converting GN to CMake building.

    **Table  3**  Directory structure of the ported library

    <a name="table13265185817173"></a>
    <table><thead align="left"><tr id="row92666583171"><th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.1"><p id="p2266105816178"><a name="p2266105816178"></a><a name="p2266105816178"></a>Directory</p>
    </th>
    <th class="cellrowborder" valign="top" width="50%" id="mcps1.2.3.1.2"><p id="p32661158161718"><a name="p32661158161718"></a><a name="p32661158161718"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1526655816175"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p226605811710"><a name="p226605811710"></a><a name="p226605811710"></a>openHarmony/third_party/double-conversion/BUILD.gn</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p1626675812177"><a name="p1626675812177"></a><a name="p1626675812177"></a>GN file for adding the third-party library to the <span id="text2025921715555"><a name="text2025921715555"></a><a name="text2025921715555"></a>OpenHarmony</span> project</p>
    </td>
    </tr>
    <tr id="row1726610589179"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p12266115815170"><a name="p12266115815170"></a><a name="p12266115815170"></a>openHarmony/third_party/double-conversion/build_thirdparty.py</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p122661958201719"><a name="p122661958201719"></a><a name="p122661958201719"></a>Script file for GN to call the <strong id="b45891919155715"><a name="b45891919155715"></a><a name="b45891919155715"></a>shell</strong> command to convert compilation from GN to CMake.</p>
    </td>
    </tr>
    <tr id="row7266195891714"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p162665581170"><a name="p162665581170"></a><a name="p162665581170"></a>openHarmony/third_party/double-conversion/config.gni</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p626712588175"><a name="p626712588175"></a><a name="p626712588175"></a>Third-party library compilation configuration file, which can be modified to determine whether the test cases will be used during the building</p>
    </td>
    </tr>
    <tr id="row1272420109203"><td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.1 "><p id="p17725101052012"><a name="p17725101052012"></a><a name="p17725101052012"></a>openHarmony/third_party/double-conversion/double-conversion/</p>
    </td>
    <td class="cellrowborder" valign="top" width="50%" headers="mcps1.2.3.1.2 "><p id="p87252109205"><a name="p87252109205"></a><a name="p87252109205"></a>Directory of the third-party library to be ported</p>
    </td>
    </tr>
    </tbody>
    </table>

2.  Add the GN file to the CMake adaptation file.

    -   The following shows the implementation for building using the newly added  **BUILD.gn**  file. For other third-party libraries that can be independently compiled using CMake, you only need to change the target paths when porting them to OpenHarmony.

    ```
    import("config.gni")
    group("double-conversion") {
        if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
            deps = [":make"]
        }
    }
    if (ohos_build_thirdparty_migrated_from_fuchisa == true) {
        action("make") {
            script = "//third_party/double-conversion/build_thirdparty.py"
            outputs = ["$root_out_dir/log_dc.txt"]
            exec_path = rebase_path(rebase_path("./build", ohos_third_party_dir))
            command = "rm * .* -rf && $CMAKE_TOOLS_PATH/cmake .. $CMAKE_FLAG $CMAKE_TOOLCHAIN_FLAG && make -j"
            args = [
                "--path=$exec_path",
                "--command=${command}"
            ]
        }
    }
    ```

    -   The newly added  **config.gni**  file is used to configure the library in the following example implementation. For other third-party libraries that can be independently compiled using CMake, you only need to change the configuration of  **CMAKE\_FLAG**  when porting them to OpenHarmony.

    ```
    #CMAKE_FLAG: config compile feature
    CMAKE_FLAG = "-DBUILD_TESTING=ON -DCMAKE_CXX_STANDARD=11"
    
    #toolchain: follow up-layer, depend on $ohos_build_compiler
    if (ohos_build_compiler == "clang") {
        CMAKE_TOOLCHAIN_FLAG = "-DOHOS_SYSROOT_PATH=${ohos_root_path}prebuilts/lite/sysroot/"
    } else {
        CMAKE_TOOLCHAIN_FLAG = ""
    }
    
    #CMake tools path,no need setting if this path already joined to $PATH.
    CMAKE_TOOLS_PATH = "setting CMake tools path..."
    ```

    -   The following shows the implementation of the newly added  **build\_thirdparty.py**  file. For other third-party libraries that can be independently compiled using CMake, you can port them to OpenHarmony without modifications.

    ```
    import os
    import sys
    from subprocess import Popen
    import argparse
    import shlex
    
    def cmd_exec(command):
        cmd = shlex.split(command)
        proc = Popen(cmd)
        proc.wait()
        ret_code = proc.returncode
        if ret_code != 0:
            raise Exception("{} failed, return code is {}".format(cmd, ret_code))
    
    def main():
        parser = argparse.ArgumentParser()
        parser.add_argument('--path', help='Build path.')
        parser.add_argument('--command', help='Build command.')
        parser.add_argument('--enable', help='enable python.', nargs='*')
        args = parser.parse_args()
    
        if args.enable:
            if args.enable[0] == 'false':
                return
    
        if args.path:
            curr_dir = os.getcwd()
            os.chdir(args.path)
            if args.command:
                if '&&' in args.command:
                    command = args.command.split('&&')
                    for data in command:
                        cmd_exec(data)
                else:
                    cmd_exec(args.command)
            os.chdir(curr_dir)
    
    if __name__ == '__main__':
        sys.exit(main())
    ```

    -   Add a configuration item in the configuration file to control compiling of the library. By default, library compilation is disabled.

    For example, add the following configuration to the  **//build/lite/ohos\_var.gni**  file:

    ```
    declare_args() {
        ohos_build_thirdparty_migrated_from_fuchisa = true
    }
    ```

3.  Build the library.

    -   Manual building

    Execute the following command:

    ```
    hb build -T //third_party/double-conversion:double-conversion
    ```

    If the compilation is successful, a static library file and test cases will be generated in the  [build](#li15717101715249)  directory.


