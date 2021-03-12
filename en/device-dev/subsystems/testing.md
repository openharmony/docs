# Testing<a name="EN-US_TOPIC_0000001075761006"></a>

-   [Overview](#section12403172115920)
    -   [Basic Concepts](#section53632272090)
    -   [Working Principles](#section2394431106)

-   [Limitations and Constraints](#section2029921310472)
-   [Setting Up a Test Environment](#section175012297491)
    -   [Environment Requirements](#section935055691014)
    -   [Installing the Environment](#section6511193210111)
    -   [Verifying the Test Environment](#section1899144517117)

-   [Development Guidelines](#section16741101301210)
    -   [When to Use](#section93782214124)
    -   [Available APIs](#section54131732101218)
    -   [How to Develop](#section53541946111218)

-   [Development Example](#section7477121918136)
-   [How to Use the Test Platform](#section76401945124810)
-   [Directory Structure](#section1875515364133)

## Overview<a name="section12403172115920"></a>

### Basic Concepts<a name="section53632272090"></a>

The testing subsystem provides a one-click Python-based self-test platform for developers. It supports cross-platform tests and extension to third-party testing frameworks. The subsystem consists of modules for compiling, managing, scheduling and distributing, and executing test cases, collecting test results, generating test reports, creating test case templates, managing test environments, and many others.

Before development using the testing subsystem, you need to understand the following concepts:

-   Test case compilation

    This operation compiles the source code of test cases into binary files that can be executed on the tested device.

-   Test case scheduling & distributing

    This operation distributes test cases to different tested devices through the network port or serial port, and allocates a specific executor for each test case.

-   Test case executor

    A test case executor defines the execution logic of each test case, such as its pre-processing, execution, and result recording.

-   Test case template

    A test case template defines respective unified formats for test cases and for GN files.

-   Test platform kits

    The test platform provides common methods to be used during the running of the test tool, for example, providing the test case directory to mount the file system to a tested device, distributing test cases to the tested device, or obtaining test results from the tested device.

-   Test report generation

    This operation defines a template for generating self-test reports and web test reports.

-   Test environment management

    The tested devices can be managed through the USB port or serial port, including discovering a device and querying the device status.


### Working Principles<a name="section2394431106"></a>

-   The following figure shows the architecture of the test platform.

**Figure  1**  Platform architecture<a name="fig418674910399"></a>  
![](figures/platform-architecture.png "platform-architecture")

-   The following figure shows the running sequence diagram of the test platform.

**Figure  2**  Running sequence of the test platform<a name="fig107203017407"></a>  
![](figures/running-sequence-of-the-test-platform.png "running-sequence-of-the-test-platform")

-   Working principle of the test platform

The test platform is started using a shell script. It executes a series of testing commands entered on the command line interface \(CLI\) and prints the command output.

## Limitations and Constraints<a name="section2029921310472"></a>

-   The self-test platform supports only code-level test case development and verification, such as unit testing and module testing.
-   Currently, the testing framework supports only white-box testing.
-   Only one test platform can be started on a testing device.

## Setting Up a Test Environment<a name="section175012297491"></a>

### Environment Requirements<a name="section935055691014"></a>

**Table  1**  Environment requirements

<a name="table13112443615"></a>
<table><thead align="left"><tr id="row1947247360"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p64172414367"><a name="p64172414367"></a><a name="p64172414367"></a>Item</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p6452410368"><a name="p6452410368"></a><a name="p6452410368"></a>Testing Device</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p94924103617"><a name="p94924103617"></a><a name="p94924103617"></a>Tested Device</p>
</th>
</tr>
</thead>
<tbody><tr id="row10452414368"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1422414368"><a name="p1422414368"></a><a name="p1422414368"></a>Hardware</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><a name="ul19802171518438"></a><a name="ul19802171518438"></a><ul id="ul19802171518438"><li>Memory: 8 GB or above</li><li>Hard disk space: 100 GB or above</li><li>Hardware architecture: x86 or ARM64</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><a name="ul56772753313"></a><a name="ul56772753313"></a><ul id="ul56772753313"><li>Hi3516D V300 development board</li><li>Hi3518E V300 development board</li></ul>
</td>
</tr>
<tr id="row24182410361"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p45102453620"><a name="p45102453620"></a><a name="p45102453620"></a>Software</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><a name="ul16677122216594"></a><a name="ul16677122216594"></a><ul id="ul16677122216594"><li>OS: Windows 10 (64-bit) or Ubuntu 18.04<p id="p717443952718"><a name="p717443952718"></a><a name="p717443952718"></a>System component (Linux): libreadline-dev</p>
</li><li>Python: 3.7.5 or later</li><li>Python plug-ins: pySerial 3.3 or later, Paramiko 2.7.1 or later, Setuptools 40.8.0 or later, and RSA 4.0 or later</li><li>NFS server: haneWIN NFS Server 1.2.50 or later, or NFSv4 or later</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><a name="ul20976824133414"></a><a name="ul20976824133414"></a><ul id="ul20976824133414"><li>OS: OpenHarmony 1.0 or later</li><li>Kernel: LiteOS Cortex-A or Linux kernel</li></ul>
</td>
</tr>
</tbody>
</table>

### Installing the Environment<a name="section6511193210111"></a>

1.  \(Optional\) If the test environment runs Linux, run the following command to install system component Readline:

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

2.  Install Python extension plug-ins Setuptools. Install RSA, Paramiko, and pySerial if the device supports the serial port only.

    1. Run the following command to install Setuptools:

    ```
    pip install setuptools
    ```

    If the installation is successful, the following prompts are displayed:

    ```
    Requirement already satisfied: setuptools in d:\programs\python37\lib\site-packages (41.2.0)
    ```

    2. Run the following command to install RSA:

    ```
    pip install rsa
    ```

    If the installation is successful, the following prompts are displayed:

    ```
    Installing collected packages: pyasn1, rsa
    Successfully installed pyasn1-0.4.8 rsa-4.7
    ```

    3. Run the following command to install Paramiko:

    ```
    pip install paramiko
    ```

    If the installation is successful, the following prompts are displayed:

    ```
    Installing collected packages: pycparser, cffi, pynacl, bcrypt, cryptography, paramiko
    Successfully installed bcrypt-3.2.0 cffi-1.14.4 cryptography-3.3.1 paramiko-2.7.2 pycparser-2.20 pynacl-1.4.0
    ```

    4. \(Optional\) Run the following command to install pySerial. This step is mandatory for tested devices that support serial ports only.

    ```
    pip install pyserial
    ```

    If the installation is successful, the following prompts are displayed:

    ```
    Requirement already satisfied: pyserial in d:\programs\python37\lib\site-packages\pyserial-3.4-py3.7.egg (3.4)
    ```

3.  \(Optional\) Install the NFS server. This step is mandatory for tested devices that support serial ports only.

    **Windows OS**

    Download and install  **haneWIN NFS Server 1.2.50**  at https://www.hanewin.net/nfs-e.htm.

    **Linux OS**

    ```
    sudo apt install nfs-kernel-server
    ```

    After the environment is installed, you can conduct coding and debugging for a test platform in an integrated development environment \(IDE\) \(DevEco Studio is recommended\).


### Verifying the Test Environment<a name="section1899144517117"></a>

**Table  2**  Environment verification

<a name="table76761616112218"></a>
<table><thead align="left"><tr id="row6677121616229"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p176771416182216"><a name="p176771416182216"></a><a name="p176771416182216"></a>Item</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p18677181612220"><a name="p18677181612220"></a><a name="p18677181612220"></a>Operation</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p5677151642215"><a name="p5677151642215"></a><a name="p5677151642215"></a>Requirement</p>
</th>
</tr>
</thead>
<tbody><tr id="row567731662216"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1667711613224"><a name="p1667711613224"></a><a name="p1667711613224"></a>Check that a compliant Python version has been installed.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p16678101614220"><a name="p16678101614220"></a><a name="p16678101614220"></a>Run the <strong id="b7670932632"><a name="b7670932632"></a><a name="b7670932632"></a>python --version</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p6554216134112"><a name="p6554216134112"></a><a name="p6554216134112"></a>The Python version must be 3.7.5 or later.</p>
</td>
</tr>
<tr id="row559954144717"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1259195419474"><a name="p1259195419474"></a><a name="p1259195419474"></a>Check that Python extension plug-ins have been installed.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p175925424714"><a name="p175925424714"></a><a name="p175925424714"></a>Access the <strong id="b35031935731"><a name="b35031935731"></a><a name="b35031935731"></a>test/xdevice</strong> directory and run <strong id="b155070352317"><a name="b155070352317"></a><a name="b155070352317"></a>run.bat</strong> or <strong id="b5507935931"><a name="b5507935931"></a><a name="b5507935931"></a>run.sh</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1040211281418"><a name="p1040211281418"></a><a name="p1040211281418"></a>The <strong id="b82085361632"><a name="b82085361632"></a><a name="b82085361632"></a>&gt;&gt;&gt;</strong> prompt is displayed.</p>
</td>
</tr>
<tr id="row66781016182213"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p8678416132217"><a name="p8678416132217"></a><a name="p8678416132217"></a>Check that the NFS server has been started (for tested devices that support serial ports only).</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p56781416142210"><a name="p56781416142210"></a><a name="p56781416142210"></a>Log in to the development board through the serial port and run the <strong id="b194410371631"><a name="b194410371631"></a><a name="b194410371631"></a>mount</strong> command to mount the NFS server.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p27475710414"><a name="p27475710414"></a><a name="p27475710414"></a>The file directory can be mounted properly.</p>
</td>
</tr>
</tbody>
</table>

## Development Guidelines<a name="section16741101301210"></a>

### When to Use<a name="section93782214124"></a>

You can call the APIs to conduct white box tests of service code.

### Available APIs<a name="section54131732101218"></a>

The testing framework integrates the open-source unit testing framework and expands the macros of the test cases. For details about the framework, see the official open-source documentation.

**Table  3**  Expanded macros of the framework

<a name="table3247152012146"></a>
<table><thead align="left"><tr id="row824713209143"><th class="cellrowborder" valign="top" width="11.41%" id="mcps1.2.3.1.1"><p id="p52484202141"><a name="p52484202141"></a><a name="p52484202141"></a>Macro</p>
</th>
<th class="cellrowborder" valign="top" width="88.59%" id="mcps1.2.3.1.2"><p id="p1424812015145"><a name="p1424812015145"></a><a name="p1424812015145"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row424892018145"><td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.2.3.1.1 "><p id="p5248192016144"><a name="p5248192016144"></a><a name="p5248192016144"></a>HWTEST</p>
</td>
<td class="cellrowborder" valign="top" width="88.59%" headers="mcps1.2.3.1.2 "><p id="p2248120191418"><a name="p2248120191418"></a><a name="p2248120191418"></a>The execution of test cases does not rely on setup and teardown execution. Based on the <strong id="b112735719267"><a name="b112735719267"></a><a name="b112735719267"></a>TEST</strong> macro, this macro has added the <strong id="b443291902514"><a name="b443291902514"></a><a name="b443291902514"></a>TestSize.Level1</strong> parameter to specify the test case level, for example, <strong id="b154975135291"><a name="b154975135291"></a><a name="b154975135291"></a>HWTEST(CalculatorAddTest, TestPoint_001, TestSize.Level1)</strong>.</p>
</td>
</tr>
<tr id="row18248220131414"><td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.2.3.1.1 "><p id="p4248132014144"><a name="p4248132014144"></a><a name="p4248132014144"></a>HWTEST_F</p>
</td>
<td class="cellrowborder" valign="top" width="88.59%" headers="mcps1.2.3.1.2 "><p id="p17248132061412"><a name="p17248132061412"></a><a name="p17248132061412"></a>The execution of test cases (without parameters) depends on setup and teardown execution. Based on the <strong id="b112055810312"><a name="b112055810312"></a><a name="b112055810312"></a>TEST_F</strong> macro, this macro has added the <strong id="b421113883115"><a name="b421113883115"></a><a name="b421113883115"></a>TestSize.Level1</strong> parameter to specify the test case level, for example, <strong id="b921114813118"><a name="b921114813118"></a><a name="b921114813118"></a>HWTEST_F(CalculatorAddTest, TestPoint_001, TestSize.Level1)</strong>.</p>
</td>
</tr>
<tr id="row924892011148"><td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.2.3.1.1 "><p id="p5248132031420"><a name="p5248132031420"></a><a name="p5248132031420"></a>HWTEST_P</p>
</td>
<td class="cellrowborder" valign="top" width="88.59%" headers="mcps1.2.3.1.2 "><p id="p1248142031417"><a name="p1248142031417"></a><a name="p1248142031417"></a>The execution of test cases (with parameters) depends on setup and teardown execution. Based on the <strong id="b1196952353418"><a name="b1196952353418"></a><a name="b1196952353418"></a>TEST_P</strong> macro, this macro has added the <strong id="b197642314343"><a name="b197642314343"></a><a name="b197642314343"></a>TestSize.Level1</strong> parameter to specify the test case level, for example, <strong id="b59797231348"><a name="b59797231348"></a><a name="b59797231348"></a>HWTEST_P(CalculatorAddTest, TestPoint_001, TestSize.Level1)</strong>.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="section53541946111218"></a>

1.  Define a test suite file based on the test case directory, for example,  **test/developertest/examples/lite/cxx\_demo/test/unittest/common/calc\_subtraction\_test.cpp**. The class in this test suite should be inherited from the  **testing::Test**  class and named in the format of "_Tested feature_\_**Test**".

    ```
    /*
     * Copyright (c) 2020 OpenHarmony.
     * Licensed under the Apache License, Version 2.0 (the "License");
     * you may not use this file except in compliance with the License.
     * You may obtain a copy of the License at
     *
     *     http://www.apache.org/licenses/LICENSE-2.0
     *
     * Unless required by applicable law or agreed to in writing, software
     * distributed under the License is distributed on an "AS IS" BASIS,
     * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
     * See the License for the specific language governing permissions and
     * limitations under the License.
     */
    #include <gtest/gtest.h>
    
    using namespace std;
    using namespace testing::ext;
    
    class CalcSubtractionTest : public testing::Test {
    public:
        static void SetUpTestCase(void);
        static void TearDownTestCase(void);
        void SetUp();
        void TearDown();
    };
    ```

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >You must write test cases by observing the following specifications:
    >-   Naming
    >    The source file name of a test case must be consistent with the test suite content. Each test suite has multiple test cases and a test source file that is globally unique and named in \[Feature\]\_\[Function\]\_\[Subfunction 1\]\_\[Subfunction 1.1\] format \(subfunctions can be further divided\).
    >    The file name can contain only lower-case letters and underscores \(\_\) and must end with  **test**, for example,  **developertest/examples/lite/cxx\_demo**.
    >-   Coding
    >    The test cases must comply with the coding specifications for feature code. In addition, case descriptions are required for further clarification. For details, see  [Test case template](#li2069415903917).
    >-   Compilation and configuration
    >    The test cases must be compiled using GN, and the configurations must comply with the compilation guide of this open-source project. For details, see  [Compilation and Building Guidelines](https://device.harmonyos.com/en/docs/develop/subsystems/oem_subsys_build_des-0000001060646620).
    >-   <a name="li2069415903917"></a>Test case template
    >    For details, see the example test case  **developertest/examples/lite/cxx\_demo/test/unittest/common/calc\_subtraction\_test.cpp**.

2.  Implement the preprocessing \(via the  **SetUp**  function\) and postprocessing \(via the  **TearDown**  function\) operations required by the execution of the test suite.

    ```
    void CalcSubtractionTest::SetUpTestCase(void)
    {
        // step 1: input testsuite setup step
    }
    
    void CalcSubtractionTest::TearDownTestCase(void)
    {
        // step 2: input testsuite teardown step
    }
    
    void CalcSubtractionTest::SetUp(void)
    {
        // step 3: input testcase setup step
    }
    
    void CalcSubtractionTest::TearDown(void)
    {
        // step 4: input testcase teardown step
    }
    ```

3.  Compile a test case based on the feature to be tested. The following code uses  **HWTEST\_F**  as an example:

    ```
    /**
     * @tc.name: integer_sub_001
     * @tc.desc: Test Calculator
     * @tc.type: FUNC
     * @tc.require: AR00000000 SR00000000
     */
    HWTEST_F(CalcSubtractionTest, integer_sub_001, TestSize.Level1)
    {
        EXPECT_EQ(0, Subtraction(1, 0));
    }
    ```

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >-   **@tc.name**: test case name, which briefly describes the test purpose
    >-   **@tc.desc**: detailed description of the test case, including the test purpose, test procedure, and expected result
    >-   **@tc.type**: test type, which can be  **FUNC**,  **PERF**,  **SECU**, or  **RELI**.
    >-   **@tc.require**: requirement ID or issue ID, which is used to associate the modification with the test case

    <a name="table32731243909"></a>
    <table><thead align="left"><tr id="row16325154317013"><th class="cellrowborder" valign="top" width="7.3999999999999995%" id="mcps1.1.5.1.1"><p id="p7325134310013"><a name="p7325134310013"></a><a name="p7325134310013"></a>SN</p>
    </th>
    <th class="cellrowborder" valign="top" width="38.269999999999996%" id="mcps1.1.5.1.2"><p id="p16325134310015"><a name="p16325134310015"></a><a name="p16325134310015"></a>Test Type</p>
    </th>
    <th class="cellrowborder" valign="top" width="8.82%" id="mcps1.1.5.1.3"><p id="p1032516431404"><a name="p1032516431404"></a><a name="p1032516431404"></a>Code</p>
    </th>
    <th class="cellrowborder" valign="top" width="45.51%" id="mcps1.1.5.1.4"><p id="p1832594320017"><a name="p1832594320017"></a><a name="p1832594320017"></a>Description</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row183251943601"><td class="cellrowborder" valign="top" width="7.3999999999999995%" headers="mcps1.1.5.1.1 "><p id="p33251343305"><a name="p33251343305"></a><a name="p33251343305"></a>1</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.269999999999996%" headers="mcps1.1.5.1.2 "><p id="p032514432018"><a name="p032514432018"></a><a name="p032514432018"></a>Functionality test</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.82%" headers="mcps1.1.5.1.3 "><p id="p133252437011"><a name="p133252437011"></a><a name="p133252437011"></a>FUNC</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.51%" headers="mcps1.1.5.1.4 "><p id="p1332554310018"><a name="p1332554310018"></a><a name="p1332554310018"></a>Verifies that each functionality of the software complies with the function design and specifications.</p>
    </td>
    </tr>
    <tr id="row1632584311011"><td class="cellrowborder" valign="top" width="7.3999999999999995%" headers="mcps1.1.5.1.1 "><p id="p19325743609"><a name="p19325743609"></a><a name="p19325743609"></a>2</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.269999999999996%" headers="mcps1.1.5.1.2 "><p id="p73251343404"><a name="p73251343404"></a><a name="p73251343404"></a>Performance test</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.82%" headers="mcps1.1.5.1.3 "><p id="p23251543503"><a name="p23251543503"></a><a name="p23251543503"></a>PERF</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.51%" headers="mcps1.1.5.1.4 "><p id="p8325114311015"><a name="p8325114311015"></a><a name="p8325114311015"></a>Verifies that the software meets the performance requirements. Performance tests include load tests, capacitance tests, and pressure tests.</p>
    </td>
    </tr>
    <tr id="row3325243205"><td class="cellrowborder" valign="top" width="7.3999999999999995%" headers="mcps1.1.5.1.1 "><p id="p19325114310015"><a name="p19325114310015"></a><a name="p19325114310015"></a>3</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.269999999999996%" headers="mcps1.1.5.1.2 "><p id="p183266439019"><a name="p183266439019"></a><a name="p183266439019"></a>Security test</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.82%" headers="mcps1.1.5.1.3 "><p id="p632617439016"><a name="p632617439016"></a><a name="p632617439016"></a>SECU</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.51%" headers="mcps1.1.5.1.4 "><p id="p133261343301"><a name="p133261343301"></a><a name="p133261343301"></a>Verifies that the software complies with security requirements and related laws and regulations within the software lifecycle.</p>
    </td>
    </tr>
    <tr id="row33261843508"><td class="cellrowborder" valign="top" width="7.3999999999999995%" headers="mcps1.1.5.1.1 "><p id="p123263435018"><a name="p123263435018"></a><a name="p123263435018"></a>4</p>
    </td>
    <td class="cellrowborder" valign="top" width="38.269999999999996%" headers="mcps1.1.5.1.2 "><p id="p78251846615"><a name="p78251846615"></a><a name="p78251846615"></a>Reliability test</p>
    </td>
    <td class="cellrowborder" valign="top" width="8.82%" headers="mcps1.1.5.1.3 "><p id="p1732615435011"><a name="p1732615435011"></a><a name="p1732615435011"></a>RELI</p>
    </td>
    <td class="cellrowborder" valign="top" width="45.51%" headers="mcps1.1.5.1.4 "><p id="p103261243906"><a name="p103261243906"></a><a name="p103261243906"></a>Verifies the probability that the software does not cause system failures within a specified period of time and under given conditions. Software stability is also involved in the test.</p>
    </td>
    </tr>
    </tbody>
    </table>

4.  Compile the GN file of the test case, including defining the compilation target, adding compilation dependencies, and setting the source file. 

    Example file path:  **test/developertest/examples/lite/cxx\_demo/test/unittest/common/BUILD.gn**

    ```
    import("//build/lite/config/test.gni")
    
    unittest("CalcSubTest") {
        output_extension = "bin"
        sources = [
            "calc_subtraction_test.cpp"
        ]
        include_dirs = []
        deps = []
    }
    ```

5.  Add the compilation target to the subsystem compilation configuration to ensure that the test case is compiled with the version distribution. The following is an example:
    1.  For devices that support connection to the Harmony device connector \(hdc\), the example compilation configuration directory is  **test/developertest/examples/ohos.build**.

        ```
        {
          "subsystem": "subsystem_examples",
          "parts": {
            "subsystem_examples": {
              "module_list": [
                "//test/developertest/examples/detector:detector",
                ...
              ],
              "test_list": [
                "//test/developertest/examples/detector/test:unittest",
                ...
              ]
            },
            ...
        }
        ```

    2.  For devices that support serial ports only, the example compilation configuration directory is  **test/developertest/examples/lite/BUILD.gn**.

        ```
        import("//build/lite/config/test.gni")
        
        subsystem_test("test") {
            test_components = []
            if(ohos_kernel_type == "liteos_riscv") {
                features += [
                ]
            }else if(ohos_kernel_type == "liteos_a") {
                test_components += [
                    "//test/developertest/examples/lite/cxx_demo/test/unittest/common:CalcSubTest"
                ]
            }
        }
        ```


6.  Create a resource configuration file for the test case to use static resources.
    1.  Create the  **resource**  directory in the  **test**  directory of a component or module.
    2.  Create a directory for a device type, for example,  **phone**, in the  **resource**  directory.
    3.  Create a folder named after the module in the device type directory, for example,  **testmodule**.
    4.  Create the  **ohos\_test.xml**  file in the folder named after the module. The file content is in the following format:

        ```
        <?xml version="1.0" encoding="UTF-8"?>
        <configuration ver="2.0">
            <target name="DetectorFileTest">
                <preparer>
                    <option name="push" value="test.txt -> /data/test/resource" src="res"/>
                </preparer>
            </target>
        </configuration>
        ```

    5.  Define  **resource\_config\_file**  in the compilation configuration file of the test case to specify the resource file  **ohos\_test.xml**.

        >![](public_sys-resources/icon-note.gif) **NOTE:** 
        >The resource file is used to push the  **test.txt**  file in the  **resource**  directory to the  **/data/test/resource**  directory of the device to test. To do so, run the  **hdc push**  command.


7.  Execute the test case after it is compiled \(the preceding steps are complete\).

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >-   For devices that support connection to the hdc, test cases can be compiled separately.
    >-   For devices that support serial ports only, to compile the test case, run the commands in the root directory for compiling the debug code.
    >    For details about how to execute a test case, see  [How to Use the Test Platform](#section76401945124810).


## Development Example<a name="section7477121918136"></a>

The code repository of the testing subsystem provides complete demo cases, which are available in the  **test/developertest/examples/**  directory. The following is an example of compiling a test case for a subtraction function:

-   The tested code is as follows:

    ```
    static int Subtraction(int a, int b)
    {
        return a - b;
    }
    ```

-   The test case code is as follows:

    ```
    /**
     * @tc.name: integer_sub_002
     * @tc.desc: Verify the Subtraction function.
     * @tc.type: FUNC
     * @tc.require: AR00000000 SR00000000
     */
    HWTEST_F(CalcSubtractionTest, integer_sub_002, TestSize.Level1)
    {
        EXPECT_EQ(1, Subtraction(2, 1));
    }
    ```


## How to Use the Test Platform<a name="section76401945124810"></a>

1.  \(Optional\) Install the XDevice component. XDevice can be used as a Python extension package.

    Go to the installation directory  **test/xdevice**  and run the following command:

    ```
    python setup.py install
    ```

    If the installation is successful, the following prompts are displayed:

    ```
    ...
    Installed d:\programs\python37\lib\site-packages\xdevice-0.0.0-py3.7.egg
    Processing dependencies for xdevice==0.0.0
    Searching for pyserial==3.4
    Best match: pyserial 3.4
    Processing pyserial-3.4-py3.7.egg
    pyserial 3.4 is already the active version in easy-install.pth
    Installing miniterm.py script to D:\Programs\Python37\Scripts
    
    Using d:\programs\python37\lib\site-packages\pyserial-3.4-py3.7.egg
    Finished processing dependencies for xdevice==0.0.0
    ```

2.  Modify the  **developertest/config/user\_config.xml**  file to configure the Developertest component.
    1.  For devices that support connection to the hdc, modify the configuration file as follows:

        Between the  **device**  tags with the  **"usb-hdc"**  attribute, modify the IP address of the device and the port number matching the HDC connection. For example:

        ```
        <device type="usb-hdc">
            <ip>192.168.1.1</ip>
            <port>9111</port>
            <sn></sn>
        </device>
        ```

    2.  For devices that support serial ports only, modify the configuration file as follows:

        Between the  **device**  tags with the  **"ipcamera"**  attribute, modify the serial port information, including the COM port and baud rate. For example:

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


3.  \(Optional\) Modify the Developertest configuration. If a test case has been compiled, specify the compilation output path of the test case. In this case the test platform will not recompile the test case.

    Modify the  **config/user\_config.xml**  file.

    1.  Specify the output path of the test case, that is, the compilation output directory between the  **test\_cases**  tags. Example:

        ```
        <test_cases>
            <dir>/home/opencode/out/release/tests</dir>
        </test_cases>
        ```

    2.  For devices that support serial ports only, specify the NFS directory on the PC \(**host\_dir**\) and the corresponding directory on the board \(**board\_dir**\) between the  **NFS**  tags. For example:

        ```
        <NFS>
            <host_dir>D:\nfs</host_dir>
            <board_dir>user</board_dir>
        </NFS>
        ```


4.  \(Optional\) Prepare the test environment. If devices to be tested support only serial ports, check whether the environment is ready:
    -   The system image and file system have been burnt into the development board and are running properly on it. For example, in system mode, if the device prompt  **OHOS\#**  when you log in with the shell, the system is running properly.
    -   The development host has been connected to the serial port of the development board and the network port.
    -   IP addresses of the development host and development board are in the same network segment and can ping each other.
    -   An empty directory has been created on the development host for mounting test cases through NFS, and the NFS service has been started properly.

5.  Start the test platform and execute the test case.
    -   Start the test framework, go to the  **test/developertest**  directory, and execute the startup script.
        1.  Run the following command to start the test framework in Windows:

            ```
            start.bat
            ```

        2.  Run the following command to start the test framework in Linux:

            ```
            ./strat.sh
            ```


    -   Select a device type.

        Configure the device type based on the development board in the configuration file, for example,  **developertest/config/framework\_config.xml**.

    -   Run test commands.
        1.  To query the subsystems, modules, product form, and test types supported by test cases, run the  **show**  commands.

            ```
            Usage: 
                show productlist      Query supported product forms
                show typelist         Query the supported test type
                show subsystemlist    Query supported subsystems
                show modulelist       Query supported modules
            ```

        2.  Run test commands.  **-t**  is mandatory, and  **-ss**  and  **-tm**  are optional. The following is an example:

            ```
            run -t ut -ss subsystem_examples -tm calculator
            ```

        3.  Specify the arguments to execute the test suite for a specific feature or module.

            ```
            usage: run [-h] [-p PRODUCTFORM] [-t [TESTTYPE [TESTTYPE ...]]]
                [-ss SUBSYSTEM] [-tm TESTMODULE] [-ts TESTSUIT]
                [-tc TESTCASE] [-tl TESTLEVEL] 
            
            Optional arguments:
                -h, --help            Show this help message and exit.
                -p PRODUCTFORM, --productform PRODUCTFORM    Specified product form
                -t [TESTTYPE [TESTTYPE ...]], --testtype [TESTTYPE [TESTTYPE ...]]
                    Specify test type(UT,MST,ST,PERF,ALL)
                -ss SUBSYSTEM, --subsystem SUBSYSTEM    Specify test subsystem
                -tm TESTMODULE, --testmodule TESTMODULE    Specified test module
                -ts TESTSUIT, --testsuite TESTSUIT    Specify test suite
                -tc TESTCASE, --testcase TESTCASE    Specify test case
                -tl TESTLEVEL, --testlevel TESTLEVEL    Specify test level
            ```


    -   View the test framework help if needed.

        Run the following command query test commands that are supported by the test platform:

        ```
        help
        ```

    -   Exit the test platform.

        Run the following command to exit the test platform:

        ```
        quit
        ```


6.  View the test result and logs. The test logs and reports are generated in the  **developertest/reports**  directory after you run the test commands.
    -   The test result is displayed on the console. The root path of the test result is as follows:

        ```
        reports/xxxx-xx-xx-xx-xx-xx
        ```

    -   The test case formatting result is stored in the following directory:

        ```
        result/
        ```

    -   The test logs are stored in the following directory:

        ```
        log/plan_log_xxxx-xx-xx-xx-xx-xx.log
        ```

    -   The report summary file is as follows:

        ```
        summary_report.html
        ```

    -   The report details file is as follows:

        ```
        details_report.html
        ```


    -   The log directory of the test platform is as follows:

        ```
        reports/platform_log_xxxx-xx-xx-xx-xx-xx.log
        ```



## Directory Structure<a name="section1875515364133"></a>

The source code of XDevice is stored in the  **test/xdevice**  directory. The following table describes the  **xdevice**  directory structure.

**Table  4**  XDevice structure 

<a name="table954494411114"></a>
<table><thead align="left"><tr id="row5545104415118"><th class="cellrowborder" valign="top" width="45.050000000000004%" id="mcps1.2.3.1.1"><p id="p2054554411115"><a name="p2054554411115"></a><a name="p2054554411115"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="54.949999999999996%" id="mcps1.2.3.1.2"><p id="p13545124420115"><a name="p13545124420115"></a><a name="p13545124420115"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row185457441816"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p754544411116"><a name="p754544411116"></a><a name="p754544411116"></a>xdevice</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p05459441212"><a name="p05459441212"></a><a name="p05459441212"></a>Basic components of the test platform</p>
</td>
</tr>
<tr id="row454511442018"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p75451144810"><a name="p75451144810"></a><a name="p75451144810"></a>xdevice/src/xdevice</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p105453448111"><a name="p105453448111"></a><a name="p105453448111"></a>Source code for the basic test framework</p>
</td>
</tr>
<tr id="row87541401381"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p67551309382"><a name="p67551309382"></a><a name="p67551309382"></a>xdevice/config</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p1575512093811"><a name="p1575512093811"></a><a name="p1575512093811"></a>Configuration file of the basic test framework</p>
</td>
</tr>
<tr id="row5649112018488"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p196491420164819"><a name="p196491420164819"></a><a name="p196491420164819"></a>xdevice/src/xdevice/__main__.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p10650320204819"><a name="p10650320204819"></a><a name="p10650320204819"></a>Internal entrance to the basic test framework</p>
</td>
</tr>
<tr id="row686513384812"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p886514334481"><a name="p886514334481"></a><a name="p886514334481"></a>xdevice/src/xdevice/__init__.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p1986519338482"><a name="p1986519338482"></a><a name="p1986519338482"></a>Package and plug-in dependencies</p>
</td>
</tr>
<tr id="row4833912191119"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p1083418127115"><a name="p1083418127115"></a><a name="p1083418127115"></a>xdevice/src/xdevice/variables.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p138341712101118"><a name="p138341712101118"></a><a name="p138341712101118"></a>Global variables</p>
</td>
</tr>
<tr id="row1637375614140"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p8373105615143"><a name="p8373105615143"></a><a name="p8373105615143"></a>xdevice/src/xdevice/_core/command</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p1937319561140"><a name="p1937319561140"></a><a name="p1937319561140"></a>Commands input by test cases</p>
</td>
</tr>
<tr id="row10415205961418"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p184151659131413"><a name="p184151659131413"></a><a name="p184151659131413"></a>xdevice/src/xdevice/_core/config</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p1986220312212"><a name="p1986220312212"></a><a name="p1986220312212"></a>Configuration management of the basic test framework</p>
</td>
</tr>
<tr id="row94787251511"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p174781520154"><a name="p174781520154"></a><a name="p174781520154"></a>xdevice/src/xdevice/_core/environment</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p164783210154"><a name="p164783210154"></a><a name="p164783210154"></a>Environment management of the basic test framework, including device management</p>
</td>
</tr>
<tr id="row61686255266"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p81691225162617"><a name="p81691225162617"></a><a name="p81691225162617"></a>xdevice/src/xdevice/_core/executor</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p1316918254269"><a name="p1316918254269"></a><a name="p1316918254269"></a>Scheduling and distribution of test cases</p>
</td>
</tr>
<tr id="row197501910202715"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p1375091013272"><a name="p1375091013272"></a><a name="p1375091013272"></a>xdevice/src/xdevice/_core/driver</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p10750101062710"><a name="p10750101062710"></a><a name="p10750101062710"></a>Test executor for the basic test framework</p>
</td>
</tr>
<tr id="row176501346185920"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p66514461593"><a name="p66514461593"></a><a name="p66514461593"></a>xdevice/src/xdevice/_core/resource</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p15651746155911"><a name="p15651746155911"></a><a name="p15651746155911"></a>Resource files and test report templates for the basic test framework</p>
</td>
</tr>
<tr id="row1484675718210"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p20847105792118"><a name="p20847105792118"></a><a name="p20847105792118"></a>xdevice/src/xdevice/_core/testkit</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p784795762120"><a name="p784795762120"></a><a name="p784795762120"></a>Common operations for the basic test framework, including NFS mounting</p>
</td>
</tr>
<tr id="row182104023911"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p5211808398"><a name="p5211808398"></a><a name="p5211808398"></a>xdevice/src/xdevice/_core/logger.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p92110017395"><a name="p92110017395"></a><a name="p92110017395"></a>Log management of the basic test framework</p>
</td>
</tr>
<tr id="row164491410124017"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p7449171012400"><a name="p7449171012400"></a><a name="p7449171012400"></a>xdevice/src/xdevice/_core/plugin.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p1944991024013"><a name="p1944991024013"></a><a name="p1944991024013"></a>Plug-in management of the basic test framework</p>
</td>
</tr>
<tr id="row14857134011406"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p118571440104014"><a name="p118571440104014"></a><a name="p118571440104014"></a>xdevice/src/xdevice/_core/interface.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p158571940184016"><a name="p158571940184016"></a><a name="p158571940184016"></a>Interfaces for plug-ins of the basic test framework</p>
</td>
</tr>
<tr id="row94193383812"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p154194363813"><a name="p154194363813"></a><a name="p154194363813"></a>xdevice/setup.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p44193353819"><a name="p44193353819"></a><a name="p44193353819"></a>Installation script of the basic test framework</p>
</td>
</tr>
<tr id="row537019532284"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p63711953202815"><a name="p63711953202815"></a><a name="p63711953202815"></a>xdevice/run.bat</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p4371153172812"><a name="p4371153172812"></a><a name="p4371153172812"></a>Startup script of the basic test framework (Windows)</p>
</td>
</tr>
<tr id="row554513912325"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="p165451493324"><a name="p165451493324"></a><a name="p165451493324"></a>xdevice/run.sh</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="p165453953218"><a name="p165453953218"></a><a name="p165453953218"></a>Startup script of the basic test framework (Linux)</p>
</td>
</tr>
</tbody>
</table>

The source code of Developertest is stored in the  **test/developertest**  directory. The following table describes the  **developertest**  directory structure.

**Table  5**  Developertest structure

<a name="table2977131081412"></a>
<table><thead align="left"><tr id="row7977610131417"><th class="cellrowborder" valign="top" width="33.879999999999995%" id="mcps1.2.3.1.1"><p id="p18792459121314"><a name="p18792459121314"></a><a name="p18792459121314"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="66.12%" id="mcps1.2.3.1.2"><p id="p77921459191317"><a name="p77921459191317"></a><a name="p77921459191317"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row17977171010144"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p2793159171311"><a name="p2793159171311"></a><a name="p2793159171311"></a>developertest</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p879375920132"><a name="p879375920132"></a><a name="p879375920132"></a>Development test framework</p>
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
<tr id="row11435113411716"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p4435153416170"><a name="p4435153416170"></a><a name="p4435153416170"></a>developertest/examples</p>
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
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p19235143291715"><a name="p19235143291715"></a><a name="p19235143291715"></a>Compilation configuration of the subsystem</p>
</td>
</tr>
<tr id="row153133019174"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p163153019174"><a name="p163153019174"></a><a name="p163153019174"></a>developertest/start.bat</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p194133051713"><a name="p194133051713"></a><a name="p194133051713"></a>Developer test entry (Windows)</p>
</td>
</tr>
<tr id="row6640152712173"><td class="cellrowborder" valign="top" width="33.879999999999995%" headers="mcps1.2.3.1.1 "><p id="p2641202751712"><a name="p2641202751712"></a><a name="p2641202751712"></a>developertest/start.sh</p>
</td>
<td class="cellrowborder" valign="top" width="66.12%" headers="mcps1.2.3.1.2 "><p id="p86419276175"><a name="p86419276175"></a><a name="p86419276175"></a>Developer test entry (Linux)</p>
</td>
</tr>
</tbody>
</table>

