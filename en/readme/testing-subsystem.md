# Testing Subsystem<a name="EN-US_TOPIC_0000001050883540"></a>

-   [Overview](#section7375710115617)
-   [Directory Structure](#section102031353175317)
-   [Constraints](#section87444710110)
-   [Installation](#section1347156474)
-   [Test Cases](#section125411936102918)
-   [Test Framework Usage](#section75882026185016)
-   [Test Result and Logs](#section414715805819)
-   [Repositories Involved](#section6299103515474)

## Overview<a name="section7375710115617"></a>

The testing subsystem allows you to develop new test cases for new features, or modify existing test cases for modified features. The developers test framework helps you develop high-quality code.

## Directory Structure<a name="section102031353175317"></a>

```
test/
├── developertest             # Developers test framework
│   ├── aw                   # Static library of the test framework
│   ├── config               # Test framework configuration
│   ├── examples             # Test case examples
│   ├── src                  # Source code of the test framework
│   ├── third_party          # Adaptation code for third-party components on which the test framework depends
│   ├── start.bat            # Developers test entry for Windows
│   ├── start.sh             # Developers test entry for Linux
│   └── BUILD.gn             # Build entry of the test framework
├── xdevice                   # Basic component of the test framework
│   ├── config               # Framework configuration file
│   ├── extension            # Extension repository for the basic component
│   ├── resource             # Test resources of the basic component
│   └── src                  # Source code of the basic component
└── xts                       # X test suite
```

## Constraints<a name="section87444710110"></a>

The test tool environment must meet the following requirements:

1.  Python version: 3.7.5 or later
2.  Paramiko version: 2.7.1 or later
3.  Setuptools version: 40.8.0 or later
4.  RSA version: 4.0 or later
5.  NFS version: V4 or later \(required when device supports connection using the serial port but not the hdc\)
6.  pySerial version: 3.3 or later \(required when the device supports connection using the serial port but not the hdc\)
7.  OS version: Windows 10 or later; Ubuntu 18.04

## Installation<a name="section1347156474"></a>

-   The Python environment is required.
    1.  Run the following command to install the Linux extension component Readline:

        ```
        sudo apt-get install libreadline-dev
        ```

        If the installation is successful, the following prompts are displayed:

        ```
        Reading package lists... Done
        Building dependency tree
        Reading state information... Done
        libreadline-dev is already the newest version (7.0-3).
        0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
        ```

    2.  Run the following command to install the plug-in Setuptools:

        ```
        pip3 install setuptools
        ```

        If the installation is successful, the following prompts are displayed:

        ```
        Requirement already satisfied: setuptools in d:\programs\python37\lib\site-packages (41.2.0)
        ```

    3.  Run the following command to install the plug-in Paramiko:

        ```
        pip3 install paramiko
        ```

        If the installation is successful, the following prompts are displayed:

        ```
        Installing collected packages: pycparser, cffi, pynacl, bcrypt, cryptography, paramiko
        Successfully installed bcrypt-3.2.0 cffi-1.14.4 cryptography-3.3.1 paramiko-2.7.2 pycparser-2.20 pynacl-1.4.0
        ```

    4.  Run the following command to install the Python plug-in RSA:

        ```
        pip3 install rsa
        ```

        If the installation is successful, the following prompts are displayed:

        ```
        Installing collected packages: pyasn1, rsa
        Successfully installed pyasn1-0.4.8 rsa-4.7
        ```

    5.  Run the following command to install the serial port plug-in pySerial for Python on the local PC:

        ```
        pip3 install pyserial
        ```

        If the installation is successful, the following prompts are displayed:

        ```
        Requirement already satisfied: pyserial in d:\programs\python37\lib\site-packages\pyserial-3.4-py3.7.egg (3.4)
        ```

    6.  If the device supports test result output only using the serial port, install the NFS server.

        For example, to install haneWIN NFS Server 1.2.50 for Windows, download the installation package from https://www.hanewin.net/nfs-e.htm.

        For Linux, run the following command:

        ```
        sudo apt install nfs-kernel-server
        ```

        If the installation is successful, the following prompts are displayed:

        ```
        Reading package lists... Done
        Building dependency tree
        Reading state information... Done
        nfs-kernel-server is already the newest version (1:1.3.4-2.1ubuntu5.3).
        0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
        ```



## Test Cases<a name="section125411936102918"></a>

-   Test case specifications
    -   Naming rules

        The source file name of the test case must be consistent with the test suite content. The relationship between the test suite and the test case is 1:N and the test suite and the test source file is 1:1. Each source file is globally unique and named in the format of \[Feature\]\_\[Function\]\_\[Subfunction 1\]\_\[Subfunction 1.1\]. Subfunctions can be further divided.

        A source file name consists of lowercase letters and underscores \(\_\), and must end with  **test**, for example,  **developertest/examples**.

    -   Test case coding specifications

        The test cases must comply with the feature code coding specifications. In addition, necessary case description information must be added. For details, see  [Test case template](#li2069415903917).

    -   Test case compilation and configuration specifications

        The test cases are compiled in GN mode. The configuration must comply with the compilation guide of the open-source project. For details, see  [Usage](en-us_topic_0000001051580775.md).


-   <a name="li2069415903917"></a>Test case template

    For details, see the test case  **developertest/examples**.

-   Directories planned for test cases

    ```
    subsystem    # Subsystem and system module
    ├── part    # Components
    │     └── test    # Module test
    │             └── unittest    # Unit test
    │                    ├── common    # Common test cases
    │                    ├── liteos    # Test cases for the LiteOS kernel only
    │                    └── linux     # Test cases for the Linux kernel only
    │             └── moduletest    # Module test
    │                    ├── common
    │                    ├── liteos
    │                    └── linux
    └── test    # Subsystem test
           └── unittest    # Unit test
                 ├── common
                 ├── liteos
                 ├── linux
           └── moduletest    # Module test
                 ├── common
                 ├── liteos
                 ├── linux
    ```

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >The  **liteos**  and  **linux**  test cases are used as examples only for different device forms. For the same feature on different development boards, if the test cases are the same, they are stored in the  **common**  directory. For the same feature, if the test cases are used to distinguish different device forms and may include kernel differences and chip platform differences, the test cases are distinguished by directory.

-   Writing a test case
    1.  Add comments to the test case header file.
    2.  Reference the  **gtest**  header file and  **ext**  namespace.
    3.  Add the header file to test.
    4.  Define test suites \(test classes\).
    5.  Implement specific test cases of the test suite, including test case comments and logic implementation.
    6.  Set the test case compilation configuration.

        >![](public_sys-resources/icon-note.gif) **NOTE:** 
        >The following examples are provided for reference:
        >For devices supporting the serial port only:  **developertest/examples/lite/cxx\_demo/test/unittest/common/calc\_subtraction\_test.cpp**.
        >For devices supporting the hdc:  **developertest/examples/calculator/test/unittest/common/calculator\_add\_test.cpp**.
        >Notes:
        >-   **SetUp**  and  **TearDown**  are the processing logic before and after each test case in the test suite is executed.
        >-   **SetUpTestCase**  and  **TearDownTestCase**  are the processing logic before and after all cases in the test suite are executed.
        >-   HWTEST usage: This method is applicable only to simple tests \(not depending on  **Setup**  and  **Teardown**\). This method is not applicable to the scenario where multiple test scenarios require the same data configuration. The test cases may affect each other and are not independent.
        >-   Use the  **printf**  function to print logs.


-   Writing a test case compilation file
    -   Define test case compilation and building objectives.
        1.  Add comments to the test case compilation header file.
        2.  Import the test case compilation template file.
        3.  Specify the output path of the test case file.
        4.  Configure the directory contained in the test case compilation dependency.
        5.  Specify the file name generated by the test case compilation target.
        6.  Write a specific test case compilation script and add the source files, configurations, and dependencies involved in the compilation.
        7.  Group the target test case files by condition. The group name is fixed to  **unittest/moduletest**.

    -   If there are multiple test suites, define the common compilation configuration.
    -   Add test cases to the build system.

        >![](public_sys-resources/icon-note.gif) **NOTE:** 
        >The following examples are provided for reference:
        >-   Devices supporting serial port connection only
        >Test case compilation configuration:  **developertest/examples/lite/cxx\_demo/test/unittest/common/BUILD.gn**
        >Compilation entry configuration:  **developertest/examples/lite/BUILD.gn**
        >-   Devices supporting the hdc connection
        >Test case compilation configuration:  **developertest/examples/calculator/test/unittest/common/BUILD.gn**
        >Compilation entry configuration:  **developertest/examples/ohos.build**


-   Test case levels
    -   Basic \(level 1\)
    -   Major \(level 2\)
    -   Minor \(level 3\)
    -   Uncommon \(level 4\)


## Test Framework Usage<a name="section75882026185016"></a>

-   Install the basic component  **xdevice**  of the framework.
    1.  Open the XDevice installation directory, for example,  **test/xdevice**  in Windows.
    2.  Open the console and run the following command:

        ```
        python setup.py install
        ```

        If the installation is successful, the following prompts are displayed:

        ```
        Installed d:\programs\python37\lib\site-packages\xdevice-0.0.0-py3.7.egg
        Processing dependencies for xdevice==0.0.0
        Finished processing dependencies for xdevice==0.0.0
        ```


-   Configure the developers test module.
    1.  For devices that support the Harmony device connector \(hdc\), modify the configuration file as follows:

        Inside the  **<device\>**  tags with the  **type="usb-hdc"**  attribute, configure the test device IP address and the matched hdc port. For example:

        ```
        <device type="usb-hdc">
            <ip>192.168.1.1</ip>
            <port>9111</port>
            <sn></sn>
        </device>
        ```

    2.  For devices that only support the serial port connection, modify the configuration file as follows:

        Inside the  **<device\>**  tags with the  **label="ipcamera"**  attribute, configure the serial port information, including the COM port and baud rate. For example:

        ```
        <device type="com" label="ipcamera">
            <serial>
                <com>COM1</com>
                <type>cmd</type>
                <baud_rate>115200</baud_rate>
                <data_bits>8</data_bits>
                <stop_bits>1</stop_bits>
                <timeout>1</timeout>
            </serial>
        </device>
        ```


    -   Modify the configuration of the  **developertest**  module. \(Optional\) If a test case has been compiled, specify the compilation output path of the test case. In this case the test platform will not recompile the test case.

        Configuration file:  **resource/config/user\_config.xml**

        1.  Specify the output path of the test case and the compilation output directory. Example:

            ```
            <test_cases>
                <dir>/home/source_code/out/release/tests</dir>
            </test_cases>
            ```

        2.  For devices that support serial port connection only, specify the NFS directory for the PC \(**host\_dir**\) and the corresponding directory for the development board \(**board\_dir**\) between the  **<NFS\>**  tags. For example:

            ```
            <NFS>
                <host_dir>D:\nfs</host_dir>
                <board_dir>user</board_dir>
            </NFS>
            ```



-   Check that the test environment meets the following conditions:
    -   The system image and file system have been burnt into a development board and are running properly on the development board. In system mode, for example, the device prompt  **OHOS\#**  is displayed during shell login.
    -   The development host has been connected to the serial port of the development board and the network port.
    -   The IP addresses of the development host and development board are in the same network segment and can ping each other.
    -   An empty directory is created on the development host for mounting test cases through NFS, and the NFS service is started properly.

-   Run test suites.
    -   Start the test framework and go to the  **test/developertest**  directory.
        1.  Run the following command to start the test framework in Windows.

            ```
            start.bat
            ```

        2.  Run the following command to start the test framework in Linux.

            ```
            ./strat.sh
            ```


    -   Select a device form.

        Configure device forms based on the actual development board, for example,  **developertest/config/framework\_config.xml**.

    -   Run the test command.
        1.  To query the subsystems, modules, product forms, and test types supported by test cases, run the  **show**  commands.

            ```
            usage: 
                show productlist      Querying supported product forms
                show typelist         Querying the supported test type
                show subsystemlist    Querying supported subsystems
                show modulelist       Querying supported modules
            ```

        2.  Run the following command to execute the test \(**-t**  is mandatory, and  **-ss**  and  **-tm**  are optional\):

            ```
            run -t ut -ss test -tm example
            ```

        3.  Specify the parameters that can be used to execute the test suite specific to a specified feature or module.

            ```
            usage: run [-h] [-p PRODUCTFORM] [-t [TESTTYPE [TESTTYPE ...]]]
                [-ss SUBSYSTEM] [-tm TESTMODULE] [-ts TESTSUIT]
                [-tc TESTCASE] [-tl TESTLEVEL] 
            
            optional arguments:
                -h, --help            show this help message and exit
                -p PRODUCTFORM, --productform PRODUCTFORM    Specified product form
                -t [TESTTYPE [TESTTYPE ...]], --testtype [TESTTYPE [TESTTYPE ...]]
                    Specify test type(UT,MST,ST,PERF,ALL)
                -ss SUBSYSTEM, --subsystem SUBSYSTEM    Specify test subsystem
                -tm TESTMODULE, --testmodule TESTMODULE    Specified test module
                -ts TESTSUIT, --testsuit TESTSUIT    Specify test suite
                -tc TESTCASE, --testcase TESTCASE    Specify test case
                -tl TESTLEVEL, --testlevel TESTLEVEL    Specify test level
            ```



-   View test framework help if needed.
    -   Run the following command to query commands supported by the test platform:

        ```
        help
        ```



-   Run the following command to exit the test platform:

    ```
    quit
    ```


## Test Result and Logs<a name="section414715805819"></a>

-   Test logs and test reports are generated after you execute the test commands.
-   Test result
    -   Reports are displayed on the console. The root directory of the test result is as follows:

        ```
        reports/xxxx-xx-xx-xx-xx-xx
        ```

    -   Test case formatting result

        ```
        result/
        ```

    -   Test case logs

        ```
        log/plan_log_xxxx-xx-xx-xx-xx-xx.log
        ```

    -   Report summary

        ```
        summary_report.html
        ```

    -   Report details

        ```
        details_report.html
        ```


-   Test framework logs

    ```
    reports/platform_log_xxxx-xx-xx-xx-xx-xx.log
    ```

-   Latest test reports

    ```
    reports/latest
    ```


## Repositories Involved<a name="section6299103515474"></a>

test\_developertest

test\_xdevice

