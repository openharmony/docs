# Testing Subsystem<a name="EN-US_TOPIC_0000001050883540"></a>

## Overview<a name="section7375710115617"></a>

The test-driven development mode is used during the development process. You can develop new cases or modify existing cases to test new or enhanced system features. The self-test helps you develop high-quality code in the development phase.

## Directory Structure<a name="section102031353175317"></a>

**Table  1**  Directory structure of the source code for self-test tools

<a name="table2977131081412"></a>
<table><thead align="left"><tr id="row7977610131417"><th class="cellrowborder" valign="top" width="33.879999999999995%" id="mcps1.2.3.1.1"><p id="p18792459121314"><a name="p18792459121314"></a><a name="p18792459121314"></a>Name</p>
</th>
<th class="cellrowborder" valign="top" width="66.12%" id="mcps1.2.3.1.2"><p id="p77921459191317"><a name="p77921459191317"></a><a name="p77921459191317"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17977171010144"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p2793159171311"><a name="p2793159171311"></a><a name="p2793159171311"></a>developertest</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p879375920132"><a name="p879375920132"></a><a name="p879375920132"></a>Development self-test framework</p>
</td>
</tr>
<tr id="row259142201312"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p640585013134"><a name="p640585013134"></a><a name="p640585013134"></a>developertest/src</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p10406450131319"><a name="p10406450131319"></a><a name="p10406450131319"></a>Test framework source code</p>
</td>
</tr>
<tr id="row1188919458130"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p115448132141"><a name="p115448132141"></a><a name="p115448132141"></a>developertest/src/core</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p1254413131146"><a name="p1254413131146"></a><a name="p1254413131146"></a>Test executor</p>
</td>
</tr>
<tr id="row6978161091412"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p37931659101311"><a name="p37931659101311"></a><a name="p37931659101311"></a>developertest/src/core/build</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p6793059171318"><a name="p6793059171318"></a><a name="p6793059171318"></a>Test case compilation</p>
</td>
</tr>
<tr id="row6978201031415"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p1738210441049"><a name="p1738210441049"></a><a name="p1738210441049"></a>developertest/src/core/command</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p1629020401941"><a name="p1629020401941"></a><a name="p1629020401941"></a>Processing of command lines entered by users</p>
</td>
</tr>
<tr id="row1596814581415"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p158313363613"><a name="p158313363613"></a><a name="p158313363613"></a>developertest/src/core/config</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p12969358749"><a name="p12969358749"></a><a name="p12969358749"></a>Test framework configuration management</p>
</td>
</tr>
<tr id="row175618551244"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p73791172718"><a name="p73791172718"></a><a name="p73791172718"></a>developertest/src/core/driver</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p107568558416"><a name="p107568558416"></a><a name="p107568558416"></a>Test framework driver executor</p>
</td>
</tr>
<tr id="row114431614115"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p1644216201111"><a name="p1644216201111"></a><a name="p1644216201111"></a>developertest/src/core/resource</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p15441116171113"><a name="p15441116171113"></a><a name="p15441116171113"></a>Test framework configuration file</p>
</td>
</tr>
<tr id="row16289143217239"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p82908327236"><a name="p82908327236"></a><a name="p82908327236"></a>developertest/src/core/testcase</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p129013219235"><a name="p129013219235"></a><a name="p129013219235"></a>Test case management</p>
</td>
</tr>
<tr id="row1403172313113"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p5403202371115"><a name="p5403202371115"></a><a name="p5403202371115"></a>developertest/src/core/common.py</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p84031423201110"><a name="p84031423201110"></a><a name="p84031423201110"></a>Common operations on the test framework</p>
</td>
</tr>
<tr id="row1688681821114"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p4886718121111"><a name="p4886718121111"></a><a name="p4886718121111"></a>developertest/src/core/constants.py</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p10886151811115"><a name="p10886151811115"></a><a name="p10886151811115"></a>Global constants of the test framework</p>
</td>
</tr>
<tr id="row13247163492"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p710851611910"><a name="p710851611910"></a><a name="p710851611910"></a>developertest/src/core/exception.py</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p112471431895"><a name="p112471431895"></a><a name="p112471431895"></a>Test framework exceptions</p>
</td>
</tr>
<tr id="row1392104161718"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p292154131715"><a name="p292154131715"></a><a name="p292154131715"></a>developertest/src/core/utils.py</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p139224117173"><a name="p139224117173"></a><a name="p139224117173"></a>Test framework tools and methods</p>
</td>
</tr>
<tr id="row43471438181714"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p1134883851719"><a name="p1134883851719"></a><a name="p1134883851719"></a>developertest/src/main</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p7348123861711"><a name="p7348123861711"></a><a name="p7348123861711"></a>Test framework platform</p>
</td>
</tr>
<tr id="row144751036111712"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p16475163681716"><a name="p16475163681716"></a><a name="p16475163681716"></a>developertest/src/main/__main__.py</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p11475103641712"><a name="p11475103641712"></a><a name="p11475103641712"></a>Internal entrance of the test framework</p>
</td>
</tr>
<tr id="row11435113411716"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p4435153416170"><a name="p4435153416170"></a><a name="p4435153416170"></a>developertest/example</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p643523491711"><a name="p643523491711"></a><a name="p643523491711"></a>Test framework demo cases</p>
</td>
</tr>
<tr id="row988116194289"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p7881161913283"><a name="p7881161913283"></a><a name="p7881161913283"></a>developertest/third_party</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p58815196285"><a name="p58815196285"></a><a name="p58815196285"></a>Third-party components</p>
</td>
</tr>
<tr id="row11235133231718"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p19235153291712"><a name="p19235153291712"></a><a name="p19235153291712"></a>developertest/BUILD.gn</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p19235143291715"><a name="p19235143291715"></a><a name="p19235143291715"></a>Compilation configuration of the test subsystem</p>
</td>
</tr>
<tr id="row153133019174"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p163153019174"><a name="p163153019174"></a><a name="p163153019174"></a>developertest/start.bat</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p194133051713"><a name="p194133051713"></a><a name="p194133051713"></a>Developer self-test entry (Windows)</p>
</td>
</tr>
<tr id="row6640152712173"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p2641202751712"><a name="p2641202751712"></a><a name="p2641202751712"></a>developertest/start.sh</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p86419276175"><a name="p86419276175"></a><a name="p86419276175"></a>Developer self-test entry (Linux)</p>
</td>
</tr>
</tbody>
</table>

## Constraints<a name="section87444710110"></a>

Test tool environment dependency

1.  Python version: 3.7.5 or later
2.  NFS version: V4 or later
3.  Windows: Windows 10 or later; Linux: Ubuntu 18.04

## Installation<a name="section1347156474"></a>

Depend on the Python environment.

Install the serial port plugins  **pyserial**  and  **readline**  on the local Python, and run the  **pip intall pyserial**  and  **sudo apt-get install libreadline-dev**  commands on the shell. The following figure is displayed when the installation is complete.

![](figures/en-us_image_0000001052278423.png)

## Compiling Test Cases<a name="section125411936102918"></a>

-   Self-test case specifications
    -   Naming rules

        The source file name of the test case must be consistent with the test suite content. The relationship between the test suite and the test case is 1:N and the test suite and the test source file is 1:1. Each source file is globally unique and named in the format of \[Feature\]\_\[Function\]\_\[Subfunction 1\]\_\[Subfunction 1.1\]. Subfunctions can be further divided.

        The file name consists of lowercase letters and underscores \(\_\) and ends with test, for example,  **developertest/example/cxx\_demo**.

    -   Test case coding specifications

        The self-test cases must comply with the feature code coding specifications. In addition, necessary case description information must be added. For details, see  [\#li2069415903917](#li2069415903917).

    -   Test case compilation and configuration specifications

        The test cases are compiled in GN mode. The configuration must comply with the compilation guide of the open source project. For details, see  [en-us\_topic\_0000001051580775.md](en-us_topic_0000001051580775.md).


-   <a name="li2069415903917"></a>Self-test case template

    For details, see the test case  **demo**  developertest/example/cxx\_demo/test/unittest/common/calc\_subtraction\_test.cpp.

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >Feature: Description of the tested feature
    >Function: Function of the tested feature
    >SubFunction: Subfunction of the tested feature
    >FunctionPoints: Function points to test
    >EnvConditions: Environment and conditions of the feature to test
    >CaseDescription: Test case description
    >step: Procedure for executing the test case when the complex logic is tested

-   Directory plan for self-test cases

    ```
    subsystem (subsystem, system component)
    ├── module (module)
    │     └── test (module test directory)
    │             └── unittest (unit test)
    │                    ├── common (common test cases)
    │                    ├── liteos (only for LiteOS core test cases)
    │                    └── linux (only for Linux core test cases)
    │             └── moduletest (module test)
    │                    ├── common
    │                    ├── liteos
    │                    └── linux
    └── test (subsystem test directory)
           └── unittest (unit test)
                 ├── common
                 ├── liteos
                 ├── linux
           └── moduletest (module test)
                 ├── common
                 ├── liteos
                 ├── linux
    
    ```

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >The LiteOS and Linux are used as examples only for different device models. For the same feature on different development boards, if the test cases are the same, they are stored in the  **common**  directory. For the same feature, if the test cases are used to distinguish different device models and may include kernel differences and chip platform differences, the test cases are distinguished by directory.

-   Procedure for compiling self-test cases
    1.  Add the comment information of the case header file.
    2.  Reference the  **gtest**  header file and  **ext**  namespace.
    3.  Add the header file to test.
    4.  Define test suites \(test classes\).
    5.  Implement specific test cases of the test suite, including test case comments and logic implementation.
    6.  Compile the test case compilation configuration.

        >![](public_sys-resources/icon-note.gif) **NOTE:** 
        >\* Example: developertest/example/cxx\_demo/test/unittest/common/calc\_subtraction\_test.cpp
        >Notes:
        >-   **SetUp**  and  **TearDown**  are the processing logic before and after each test case in the test suite is executed.
        >-   **SetUpTestCase**  and  **TearDownTestCase**  are the processing logic before and after all cases in the test suite are executed.
        >-   HWTEST usage: This method is applicable only to simple tests \(not depending on  **Setup**  and  **Teardown**\). This method is not applicable to the scenario where multiple test scenarios require the same data configuration. The test cases may affect each other and are not independent.
        >-   Use the  **printf**  function to print logs.


-   Compile a test case compilation file.
    -   Define test case compilation and building objectives.
        1.  Add comments to the case compilation header file.
        2.  Import the test case compilation template file.
        3.  Specify the output path of the test case file.
        4.  Configure the directory contained in the test case compilation dependency.
        5.  Specify the name of the case execution file generated by the case compilation target.
        6.  Compile a specific test case compilation script and add the source files, configurations, and dependencies involved in the compilation.
        7.  Group the target case files by condition. The group name is fixed to  **unittest/moduletest**.

    -   If there are multiple test suites, define the common compilation configuration.
    -   Add test cases to the build system.

        >![](public_sys-resources/icon-note.gif) **NOTE:** 
        >\* Example: developertest/example/cxx\_demo/test/unittest/common/BUILD.gn


-   Test case level definition
    -   Basic \(Level 1\): < 1s
    -   Major \(Level 2\): < 10s
    -   Minor \(Level 3\): < 5 min
    -   Uncommon \(Level 4\): \> 5 min


## Using Test Framework<a name="section75882026185016"></a>

-   Install the basic framework  **xdevice**.
    1.  Open the  **xdevice**  installation directory, for example,  **test/xdevice**  in Windows.
    2.  Open the console window and run the following command:

        ```
        python setup.py install
        ```

    3.  The following figure is displayed when the installation is complete.

        ![](figures/en-us_image_0000001054501634.png)


-   Modify the configuration of the basic framework  **xdevice**.

    File: xdevice/config/user\_config.xml

    1.  \[device\] \# Configure the serial port information with the label IP camera, COM port, and baud rate. Example:

        ```
        <device type="com" label="ipcamera">
            <serial>
                <com>COM1</com>
                <type>cmd</type>
                <baund_rate>115200</baund_rate>
                <data_bits>8</data_bits>
                <stop_bits>1</stop_bits>
                <timeout>1</timeout>
            </serial>
        </device>
        ```


-   Modify the configuration of the  **developertest**  component.

    File: resource/config/user\_config.xml

    1.  \[test\_cases\] \# Specify the output path of the test case and the compilation output directory. Example:

        ```
        <test_cases>
            <dir>S:\out\ipcamera_hi3518ev300_liteos_a\test</dir>
        </test_cases>
        ```

    2.  \[NFS\] \# Specify the NFS mapping path.  **host\_dir**  is the NFS directory on the PC, and  **board\_dir**  is the directory created on the board. Example:

        ```
        <NFS>
            <host_dir>D:\nfs</host_dir>
            <board_dir>user</board_dir>
        </NFS>
        ```


-   Check the environment before executing the self-test cases.
    -   The system image and file system have been burnt to a development board and are running properly on the development board. In system mode, for example, the device prompt  **OHOS\#**  is displayed during shell login.
    -   The development host is properly connected to the serial port of the development board, and the development host is properly connected to the serial port of the development board.
    -   The IP addresses of the development host and development board are in the same network segment and can ping each other.
    -   An empty directory is created on the development host for mounting test cases through NFS, and the NFS service is started properly.

-   Run test suites.
    -   Start the test framework and go to the  **test/developertest**  directory.
        1.  Start the test framework on Windows.

            ```
            start.bat
            ```

        2.  Start the test framework on Linux.

            ```
            ./strat.sh
            ```


    -   Select a device mode.

        Configure device models based on the actual development board, for example,  **developertest/src/core/resource/config/framework\_config.xml**.

    -   Run the test command.
        1.  The following example shows how to run the test command.  **-t ut**  is mandatory, and  **-ss**  and  **-tm**  are optional.

            ```
            run -t ut -ss test -tm example
            ```

        2.  Specify the parameters that can be used to execute the test suite corresponding to a specific feature or module.

            ```
            usage: __main__.py [-h] [-p PRODUCTFORM] [-t [TESTTYPE [TESTTYPE ...]]]
                [-ss SUBSYSTEM] [-tm TESTMODULE] [-ts TESTSUIT]
                [-tc TESTCASE] [-tl TESTLEVEL] [-os TARGET_OS_NAME]
                [-bv BUILD_VARIANT] [-b [BUILD [BUILD ...]]]
                [-cov COVERAGE] [-tf TESTFILE] [-res RESOURCE]
                [-sn DEVICE_SN] [-c CONFIG] [-rp REPORTPATH] [-e EXECTYPE]
                [-td TEST_DRIVER]
                action Specify test para.positional arguments:
                    action                Specify action
            
            optional arguments:
                -h, --help            show this help message and exit
                -p PRODUCTFORM, --productform PRODUCTFORM    Specified product form
                -t [TESTTYPE [TESTTYPE ...]], --testtype [TESTTYPE [TESTTYPE ...]]
                    Specify test type(UT,MST,ST,PERF,ALL)
                -ss SUBSYSTEM, --subsystem SUBSYSTEM    Specify test subsystem
                -tm TESTMODULE, --testmodule TESTMODULE    Specified test module
                -ts TESTSUIT, --testsuit TESTSUIT    Specify test suit
                -tc TESTCASE, --testcase TESTCASE    Specify test case
                -tl TESTLEVEL, --testlevel TESTLEVEL    Specify test level
                -bv BUILD_VARIANT, --build_variant BUILD_VARIANT    Specify build variant(release,debug)
                -b [BUILD [BUILD ...]], --build [BUILD [BUILD ...]]
                    Specify build values(version,testcase)
                -tf TESTFILE, --testfile TESTFILE    Specify test suites list file
                -res RESOURCE, --resource RESOURCE    Specify test resource
                -sn DEVICE_SN, --device_sn DEVICE_SN    Specify device serial number
                -c CONFIG, --config CONFIG    Specify test config file
                -rp REPORTPATH, --reportpath REPORTPATH    Specify test report path
                -e EXECTYPE, --exectype EXECTYPE    Specify test execute type
                -td TEST_DRIVER, --testdriver TEST_DRIVER    Specify test driver id
            ```



-   See the test framework help if needed.
    -   The help command is used to query test commands that are supported by the test platform.

        ```
        help
        ```



-   Exit the self-test platform.
    -   Run the following command to exit the self-test platform:

        ```
        quit
        ```



## Test Result and Log<a name="section414715805819"></a>

-   Test logs and test reports are generated after you execute test instructions in the test framework.
-   Test result
    -   The test result is displayed on the console. The root path of the test result is as follows:

        ```
        reports/xxxx-xx-xx-xx-xx-xx
        ```

    -   Test case formatting result

        ```
        result/
        ```

    -   Test case log

        ```
        log/plan_log_xxxx-xx-xx-xx-xx-xx.log
        ```

    -   Test report summary

        ```
        summary_report.html
        ```

    -   Test report details

        ```
        details_report.html
        ```


-   Test framework log

    ```
    reports/platform_log_xxxx-xx-xx-xx-xx-xx.log
    ```

-   Latest test report

    ```
    reports/latest
    ```


## Repositories Involved<a name="section6299103515474"></a>

test\_developertest

test\_xdevice

