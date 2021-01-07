# Testing<a name="EN-US_TOPIC_0000001074910589"></a>

-   [Overview](#en-us_topic_0000001059860314_section12403172115920)
    -   [Basic Concepts](#en-us_topic_0000001059860314_section53632272090)
    -   [Working Principles](#en-us_topic_0000001059860314_section2394431106)

-   [Limitations and Constraints](#en-us_topic_0000001059860314_section2029921310472)
    -   [Function Constraints](#en-us_topic_0000001059860314_section172441620111610)
    -   [Operation Constraints](#en-us_topic_0000001059860314_section201523661616)

-   [Setting Up a Test Environment](#en-us_topic_0000001059860314_section175012297491)
    -   [Environment Requirements](#en-us_topic_0000001059860314_section935055691014)
    -   [Installing the Environment](#en-us_topic_0000001059860314_section6511193210111)
    -   [Verifying the Test Environment](#en-us_topic_0000001059860314_section1899144517117)

-   [Development Guidelines](#en-us_topic_0000001059860314_section16741101301210)
    -   [When to Use](#en-us_topic_0000001059860314_section93782214124)
    -   [Available APIs](#en-us_topic_0000001059860314_section54131732101218)
    -   [How to Develop](#en-us_topic_0000001059860314_section53541946111218)

-   [Development Example](#en-us_topic_0000001059860314_section7477121918136)
-   [Directory Structure](#en-us_topic_0000001059860314_section1875515364133)

## Overview<a name="en-us_topic_0000001059860314_section12403172115920"></a>

### Basic Concepts<a name="en-us_topic_0000001059860314_section53632272090"></a>

The testing subsystem provides a one-click Python-based self-test platform for developers. It also supports operations on third-party testing frameworks, including compiling, managing, scheduling and distributing, and executing test cases, collecting test results, generating test reports, creating test case templates, and managing test environments.

Before development using the testing subsystem, you need to understand the following concepts:

-   Test case compilation

    This operation compiles the source code of test cases into binary files that can be executed on the tested device.

-   Test case scheduling & distributing

    This operation distributes test cases to different tested devices through the network port or serial port, and allocates a specific executor for each test case.

-   Test case executor

    A test case executor integrates the unit testing frameworks for different programming languages, such as Unity, and defines the execution logic of each test case, such as its pre-processing, execution, and result recording.

-   Test case template

    A test case template defines respective unified formats for test cases and for GN files.

-   Test tool kit

    The test tool kit provides common methods to be used during the running of the test tool, for example, providing the test case directory to mount the file system to a tested device, distributing test cases to the tested device, or obtaining test results from the tested device.

-   Test report generation

    This operation defines a template for generating self-test reports and converts the XML file of a report into an HTML file.

-   Test environment management

    The tested devices can be managed through the USB port or serial port, including discovering a device and querying the device status.


### Working Principles<a name="en-us_topic_0000001059860314_section2394431106"></a>

-   The following figure shows the architecture of the test tool.

**Figure  1**  Test tool architecture<a name="en-us_topic_0000001059860314_fig418674910399"></a>  
![](figures/test-tool-architecture.png "test-tool-architecture")

-   The following figure shows the running sequence diagram of the test tool.

**Figure  2**  Running sequence of the test tool<a name="en-us_topic_0000001059860314_fig107203017407"></a>  
![](figures/running-sequence-of-the-test-tool.png "running-sequence-of-the-test-tool")

-   Working principle of the test tool

The test tool is started using a shell script. It executes a series of testing commands entered on the command line interface \(CLI\) and prints the command output.

## Limitations and Constraints<a name="en-us_topic_0000001059860314_section2029921310472"></a>

### Function Constraints<a name="en-us_topic_0000001059860314_section172441620111610"></a>

-   Application scope

    Self-test tools support only code-level test case development and verification, such as unit testing and module testing.

-   Specifications

    Currently, the testing frameworks support only white-box testing.


### Operation Constraints<a name="en-us_topic_0000001059860314_section201523661616"></a>

Only one test platform can be started on a testing device.

## Setting Up a Test Environment<a name="en-us_topic_0000001059860314_section175012297491"></a>

### Environment Requirements<a name="en-us_topic_0000001059860314_section935055691014"></a>

**Table  1**  Environment requirements

<a name="en-us_topic_0000001059860314_table13112443615"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059860314_row1947247360"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="en-us_topic_0000001059860314_p64172414367"><a name="en-us_topic_0000001059860314_p64172414367"></a><a name="en-us_topic_0000001059860314_p64172414367"></a>Item</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="en-us_topic_0000001059860314_p6452410368"><a name="en-us_topic_0000001059860314_p6452410368"></a><a name="en-us_topic_0000001059860314_p6452410368"></a>Testing Device</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="en-us_topic_0000001059860314_p94924103617"><a name="en-us_topic_0000001059860314_p94924103617"></a><a name="en-us_topic_0000001059860314_p94924103617"></a>Tested Device</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059860314_row10452414368"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059860314_p1422414368"><a name="en-us_topic_0000001059860314_p1422414368"></a><a name="en-us_topic_0000001059860314_p1422414368"></a>Hardware</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><a name="en-us_topic_0000001059860314_ul19802171518438"></a><a name="en-us_topic_0000001059860314_ul19802171518438"></a><ul id="en-us_topic_0000001059860314_ul19802171518438"><li>Memory: 8 GB or above</li><li>Hard disk space: 100 GB or above</li><li>Hardware architecture: x86 or ARM64</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059860314_p5417240364"><a name="en-us_topic_0000001059860314_p5417240364"></a><a name="en-us_topic_0000001059860314_p5417240364"></a>Hi3516D V300 development board</p>
<p id="en-us_topic_0000001059860314_p1286125194416"><a name="en-us_topic_0000001059860314_p1286125194416"></a><a name="en-us_topic_0000001059860314_p1286125194416"></a>Hi3518E V300 development board</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row24182410361"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059860314_p45102453620"><a name="en-us_topic_0000001059860314_p45102453620"></a><a name="en-us_topic_0000001059860314_p45102453620"></a>Software</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><a name="en-us_topic_0000001059860314_ul16677122216594"></a><a name="en-us_topic_0000001059860314_ul16677122216594"></a><ul id="en-us_topic_0000001059860314_ul16677122216594"><li>OS: Windows 10 (64-bit) or Ubuntu 18.04<p id="en-us_topic_0000001059860314_p717443952718"><a name="en-us_topic_0000001059860314_p717443952718"></a><a name="en-us_topic_0000001059860314_p717443952718"></a>System component (Linux): libreadline-dev</p>
</li><li>Python: 3.7.5 or later</li><li>Python plug-ins: pySerial 3.3 or later, Paramiko 2.7.1 or later, Setuptools 40.8.0 or later, and RSA 4.0 or later</li><li>NFS server: haneWIN NFS Server 1.2.50 or later, or NFSv4 or later</li></ul>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><a name="en-us_topic_0000001059860314_ul20976824133414"></a><a name="en-us_topic_0000001059860314_ul20976824133414"></a><ul id="en-us_topic_0000001059860314_ul20976824133414"><li>OS: OpenHarmony 1.0 or later</li><li>Kernel: LiteOS Cortex-A or Linux kernel</li></ul>
</td>
</tr>
</tbody>
</table>

### Installing the Environment<a name="en-us_topic_0000001059860314_section6511193210111"></a>

1.  Go to the  **test/xdevice**  directory and run the  **python setup.py install**  command.
2.  \(Optional\) If the test environment runs Linux, run the following command to install system component readline:

    ```
    sudo apt-get install libreadline-dev
    ```

3.  Install Python extension plug-ins pySerial, Setuptools, RSA, and Paramiko.

    Run the following command to install pySerial:

    ```
    pip install pyserial
    ```

    Run the following command to install Setuptools:

    ```
    pip install setuptools
    ```

    Run the following command to install RSA:

    ```
    pip install rsa
    ```

    Run the following command to install Paramiko:

    ```
    pip install paramiko
    ```

4.  Install an NFS server.

    **Windows OS**

    Download and install  **haneWIN NFS Server 1.2.50**  at https://www.hanewin.net/nfs-e.htm.

    **Linux OS**

    ```
    sudo apt install nfs-kernel-server
    ```

    After the environment is installed, you can conduct coding and debugging for a test tool in an integrated development environment \(IDE\) \(DevEco Studio is recommended\).


### Verifying the Test Environment<a name="en-us_topic_0000001059860314_section1899144517117"></a>

**Table  2**  Environment verification

<a name="en-us_topic_0000001059860314_table76761616112218"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059860314_row6677121616229"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="en-us_topic_0000001059860314_p176771416182216"><a name="en-us_topic_0000001059860314_p176771416182216"></a><a name="en-us_topic_0000001059860314_p176771416182216"></a>Item</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="en-us_topic_0000001059860314_p18677181612220"><a name="en-us_topic_0000001059860314_p18677181612220"></a><a name="en-us_topic_0000001059860314_p18677181612220"></a>Operation</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="en-us_topic_0000001059860314_p5677151642215"><a name="en-us_topic_0000001059860314_p5677151642215"></a><a name="en-us_topic_0000001059860314_p5677151642215"></a>Requirement</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059860314_row567731662216"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059860314_p1667711613224"><a name="en-us_topic_0000001059860314_p1667711613224"></a><a name="en-us_topic_0000001059860314_p1667711613224"></a>Check that a compliant Python version has been installed.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059860314_p16678101614220"><a name="en-us_topic_0000001059860314_p16678101614220"></a><a name="en-us_topic_0000001059860314_p16678101614220"></a>Run the <strong id="en-us_topic_0000001059860314_b7670932632"><a name="en-us_topic_0000001059860314_b7670932632"></a><a name="en-us_topic_0000001059860314_b7670932632"></a>python --version</strong> command.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059860314_p6554216134112"><a name="en-us_topic_0000001059860314_p6554216134112"></a><a name="en-us_topic_0000001059860314_p6554216134112"></a>The Python version must be 3.7.5 or later.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row559954144717"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059860314_p1259195419474"><a name="en-us_topic_0000001059860314_p1259195419474"></a><a name="en-us_topic_0000001059860314_p1259195419474"></a>Check that Python extension plug-ins have been installed.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059860314_p175925424714"><a name="en-us_topic_0000001059860314_p175925424714"></a><a name="en-us_topic_0000001059860314_p175925424714"></a>Access the <strong id="en-us_topic_0000001059860314_b35031935731"><a name="en-us_topic_0000001059860314_b35031935731"></a><a name="en-us_topic_0000001059860314_b35031935731"></a>test/xdevice</strong> directory and run <strong id="en-us_topic_0000001059860314_b155070352317"><a name="en-us_topic_0000001059860314_b155070352317"></a><a name="en-us_topic_0000001059860314_b155070352317"></a>run.bat</strong> or <strong id="en-us_topic_0000001059860314_b5507935931"><a name="en-us_topic_0000001059860314_b5507935931"></a><a name="en-us_topic_0000001059860314_b5507935931"></a>run.sh</strong>.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059860314_p1040211281418"><a name="en-us_topic_0000001059860314_p1040211281418"></a><a name="en-us_topic_0000001059860314_p1040211281418"></a>The <strong id="en-us_topic_0000001059860314_b82085361632"><a name="en-us_topic_0000001059860314_b82085361632"></a><a name="en-us_topic_0000001059860314_b82085361632"></a>&gt;&gt;&gt;</strong> prompt is displayed.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row66781016182213"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059860314_p8678416132217"><a name="en-us_topic_0000001059860314_p8678416132217"></a><a name="en-us_topic_0000001059860314_p8678416132217"></a>Check the NFS server status.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059860314_p56781416142210"><a name="en-us_topic_0000001059860314_p56781416142210"></a><a name="en-us_topic_0000001059860314_p56781416142210"></a>Log in to the development board through the serial port and run the <strong id="en-us_topic_0000001059860314_b194410371631"><a name="en-us_topic_0000001059860314_b194410371631"></a><a name="en-us_topic_0000001059860314_b194410371631"></a>mount</strong> command to mount the NFS server.</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059860314_p27475710414"><a name="en-us_topic_0000001059860314_p27475710414"></a><a name="en-us_topic_0000001059860314_p27475710414"></a>The file directory can be mounted properly.</p>
</td>
</tr>
</tbody>
</table>

## Development Guidelines<a name="en-us_topic_0000001059860314_section16741101301210"></a>

### When to Use<a name="en-us_topic_0000001059860314_section93782214124"></a>

Test cases are mainly used to conduct self-tests for service code and can be used in code-level unit testing, module testing, and performance testing.

### Available APIs<a name="en-us_topic_0000001059860314_section54131732101218"></a>

The testing framework integrates the open-source unit testing framework and expands the macros of the test cases. For details about the framework, see the official open-source documentation.

**Table  3**  Expanded macros of the framework

<a name="en-us_topic_0000001059860314_table3247152012146"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059860314_row824713209143"><th class="cellrowborder" valign="top" width="11.41%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001059860314_p52484202141"><a name="en-us_topic_0000001059860314_p52484202141"></a><a name="en-us_topic_0000001059860314_p52484202141"></a>Macro</p>
</th>
<th class="cellrowborder" valign="top" width="88.59%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001059860314_p1424812015145"><a name="en-us_topic_0000001059860314_p1424812015145"></a><a name="en-us_topic_0000001059860314_p1424812015145"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059860314_row424892018145"><td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p5248192016144"><a name="en-us_topic_0000001059860314_p5248192016144"></a><a name="en-us_topic_0000001059860314_p5248192016144"></a>HWTEST</p>
</td>
<td class="cellrowborder" valign="top" width="88.59%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p2248120191418"><a name="en-us_topic_0000001059860314_p2248120191418"></a><a name="en-us_topic_0000001059860314_p2248120191418"></a>This macro applies to simple tests, and its execution does not rely on the setup and teardown execution. This macro expands the test case level based on the <strong id="en-us_topic_0000001059860314_b195655481312"><a name="en-us_topic_0000001059860314_b195655481312"></a><a name="en-us_topic_0000001059860314_b195655481312"></a>TEST</strong> macro, for example, <strong id="en-us_topic_0000001059860314_b1757154816312"><a name="en-us_topic_0000001059860314_b1757154816312"></a><a name="en-us_topic_0000001059860314_b1757154816312"></a>HWTEST(CalculatorAddTest, TestPoint_001, TestSize.Level1)</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row18248220131414"><td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p4248132014144"><a name="en-us_topic_0000001059860314_p4248132014144"></a><a name="en-us_topic_0000001059860314_p4248132014144"></a>HWTEST_F</p>
</td>
<td class="cellrowborder" valign="top" width="88.59%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p17248132061412"><a name="en-us_topic_0000001059860314_p17248132061412"></a><a name="en-us_topic_0000001059860314_p17248132061412"></a>Test cases defined in this macro are independent. The macro execution relies on the setup and teardown execution. This macro expands the test case level based on the <strong id="en-us_topic_0000001059860314_b19233145210316"><a name="en-us_topic_0000001059860314_b19233145210316"></a><a name="en-us_topic_0000001059860314_b19233145210316"></a>TEST_F</strong> macro, for example, <strong id="en-us_topic_0000001059860314_b72381252235"><a name="en-us_topic_0000001059860314_b72381252235"></a><a name="en-us_topic_0000001059860314_b72381252235"></a>HWTEST_F(CalculatorAddTest, TestPoint_001, TestSize.Level1)</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row924892011148"><td class="cellrowborder" valign="top" width="11.41%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p5248132031420"><a name="en-us_topic_0000001059860314_p5248132031420"></a><a name="en-us_topic_0000001059860314_p5248132031420"></a>HWTEST_P</p>
</td>
<td class="cellrowborder" valign="top" width="88.59%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p1248142031417"><a name="en-us_topic_0000001059860314_p1248142031417"></a><a name="en-us_topic_0000001059860314_p1248142031417"></a>This macro applies to parameterized tests. It expands the test case level based on the <strong id="en-us_topic_0000001059860314_b10661453933"><a name="en-us_topic_0000001059860314_b10661453933"></a><a name="en-us_topic_0000001059860314_b10661453933"></a>TEST_P</strong> macro, for example, <strong id="en-us_topic_0000001059860314_b1677532036"><a name="en-us_topic_0000001059860314_b1677532036"></a><a name="en-us_topic_0000001059860314_b1677532036"></a>HWTEST_P(CalculatorAddTest, TestPoint_001, TestSize.Level1)</strong>.</p>
</td>
</tr>
</tbody>
</table>

### How to Develop<a name="en-us_topic_0000001059860314_section53541946111218"></a>

1.  Define a test suite file based on the test case directory, for example,  **test/developertest/example/cxx\_demo/test/unittest/common/calc\_subtraction\_test.cpp**. The class in this test suite should be inherited from the  **testing::Test**  class and named in the format of "_Tested feature_**Test**".

    ```
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

2.  Implement the preprocessing \(via the  **SetUp**  function\) and postprocessing \(via the  **TearDown**  function\) operations required by the execution of the test suite.

    ```
    void CalcSubtractionTest::SetUpTestCase(void)
    {
        // step 2: input testsuit setup step
    }
    
    void CalcSubtractionTest::TearDownTestCase(void)
    {
        // step 2: input testsuit teardown step
    }
    
    void CalcSubtractionTest::SetUp(void)
    {
        // step 3: input testcase setup step
    }
    
    void CalcSubtractionTest::TearDown(void)
    {
        // step 3: input testcase teardown step
    }
    ```

3.  Compile a test case based on the feature to be tested. The following code uses  **HWTEST\_F**  as an example:

    ```
    /*
     * Feature: Calculator
     * Function: Subtraction
     * SubFunction: NA
     * FunctionPoints: Integer Subtraction
     * EnvConditions: NA
     * CaseDescription: Verify the Subtraction function.
     */
    HWTEST_F(CalcSubtractionTest, integer_sub_001, TestSize.Level1)
    {
        EXPECT_EQ(0, Subtraction(1, 0));
    }
    ```

4.  Compile the GN file of the test case, including defining the compilation target, adding compilation dependencies, and setting the source file. \(Example file path:  **test/developertest/example/cxx\_demo/test/unittest/common/BUILD.gn**\)

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

5.  Add the test case compilation target to the subsystem compilation configuration to ensure that the test case is compiled with the version release. \(Example file path:  **test/developertest/BUILD.gn**\)

    ```
    import("//build/lite/config/test.gni")
    
    subsystem_test("test") {
        test_components = []
        if(ohos_kernel_type == "liteos_riscv") {
            features += [
            ]
        }else if(ohos_kernel_type == "liteos_a") {
            test_components += [
                "//test/developertest/example/cxx_demo/test/unittest/common:CalcSubTest"
            ]
        }
    }
    ```

6.  Run the version compilation command in the root directory of the code to compile the test case.

## Development Example<a name="en-us_topic_0000001059860314_section7477121918136"></a>

The code repository of the testing subsystem provides complete demo cases, which are available in the  **test/developertest/example/**  directory. The following is an example of compiling a test case using a subtraction function:

-   The tested code is as follows:

    ```
    static int Subtraction(int a, int b)
    {
        return a - b;
    }
    ```

-   The test case code is as follows:

    ```
    /*
     * Feature: Calculator
     * Function: Subtraction
     * SubFunction: NA
     * FunctionPoints: Integer Subtraction
     * EnvConditions: NA
     * CaseDescription: Verify the Subtraction function.
     */
    HWTEST_F(CalcSubtractionTest, integer_sub_002, TestSize.Level1)
    {
        EXPECT_EQ(1, Subtraction(2, 1));
    }
    ```


## Directory Structure<a name="en-us_topic_0000001059860314_section1875515364133"></a>

The source code for the test platform framework is stored in the  **test/xdevice**  directory. The following table describes the  **xdevice**  directory structure.

**Table  4** **xdevice**  directory structure

<a name="en-us_topic_0000001059860314_table954494411114"></a>
<table><thead align="left"><tr id="en-us_topic_0000001059860314_row5545104415118"><th class="cellrowborder" valign="top" width="45.050000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001059860314_p2054554411115"><a name="en-us_topic_0000001059860314_p2054554411115"></a><a name="en-us_topic_0000001059860314_p2054554411115"></a>Directory</p>
</th>
<th class="cellrowborder" valign="top" width="54.949999999999996%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001059860314_p13545124420115"><a name="en-us_topic_0000001059860314_p13545124420115"></a><a name="en-us_topic_0000001059860314_p13545124420115"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001059860314_row185457441816"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p754544411116"><a name="en-us_topic_0000001059860314_p754544411116"></a><a name="en-us_topic_0000001059860314_p754544411116"></a>xdevice</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p05459441212"><a name="en-us_topic_0000001059860314_p05459441212"></a><a name="en-us_topic_0000001059860314_p05459441212"></a>Basic framework for test tools</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row454511442018"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p75451144810"><a name="en-us_topic_0000001059860314_p75451144810"></a><a name="en-us_topic_0000001059860314_p75451144810"></a>xdevice/src/xdevice</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p105453448111"><a name="en-us_topic_0000001059860314_p105453448111"></a><a name="en-us_topic_0000001059860314_p105453448111"></a>Source code for the basic testing framework</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row87541401381"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p67551309382"><a name="en-us_topic_0000001059860314_p67551309382"></a><a name="en-us_topic_0000001059860314_p67551309382"></a>xdevice/config</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p1575512093811"><a name="en-us_topic_0000001059860314_p1575512093811"></a><a name="en-us_topic_0000001059860314_p1575512093811"></a>Configuration file of the basic testing framework</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row5649112018488"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p196491420164819"><a name="en-us_topic_0000001059860314_p196491420164819"></a><a name="en-us_topic_0000001059860314_p196491420164819"></a>xdevice/src/xdevice/__main__.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p10650320204819"><a name="en-us_topic_0000001059860314_p10650320204819"></a><a name="en-us_topic_0000001059860314_p10650320204819"></a>Internal entrance to the basic testing framework</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row686513384812"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p886514334481"><a name="en-us_topic_0000001059860314_p886514334481"></a><a name="en-us_topic_0000001059860314_p886514334481"></a>xdevice/src/xdevice/__init__.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p1986519338482"><a name="en-us_topic_0000001059860314_p1986519338482"></a><a name="en-us_topic_0000001059860314_p1986519338482"></a>Package and plug-in dependencies</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row4833912191119"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p1083418127115"><a name="en-us_topic_0000001059860314_p1083418127115"></a><a name="en-us_topic_0000001059860314_p1083418127115"></a>xdevice/src/xdevice/variables.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p138341712101118"><a name="en-us_topic_0000001059860314_p138341712101118"></a><a name="en-us_topic_0000001059860314_p138341712101118"></a>Global variables</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row1637375614140"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p8373105615143"><a name="en-us_topic_0000001059860314_p8373105615143"></a><a name="en-us_topic_0000001059860314_p8373105615143"></a>xdevice/src/xdevice/_core/command</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p1937319561140"><a name="en-us_topic_0000001059860314_p1937319561140"></a><a name="en-us_topic_0000001059860314_p1937319561140"></a>Commands entered by test cases</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row10415205961418"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p184151659131413"><a name="en-us_topic_0000001059860314_p184151659131413"></a><a name="en-us_topic_0000001059860314_p184151659131413"></a>xdevice/src/xdevice/_core/config</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p1986220312212"><a name="en-us_topic_0000001059860314_p1986220312212"></a><a name="en-us_topic_0000001059860314_p1986220312212"></a>Configuration management of the basic testing framework</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row94787251511"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p174781520154"><a name="en-us_topic_0000001059860314_p174781520154"></a><a name="en-us_topic_0000001059860314_p174781520154"></a>xdevice/src/xdevice/_core/environment</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p164783210154"><a name="en-us_topic_0000001059860314_p164783210154"></a><a name="en-us_topic_0000001059860314_p164783210154"></a>Environment management of the basic testing framework, including device management</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row61686255266"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p81691225162617"><a name="en-us_topic_0000001059860314_p81691225162617"></a><a name="en-us_topic_0000001059860314_p81691225162617"></a>xdevice/src/xdevice/_core/executor</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p1316918254269"><a name="en-us_topic_0000001059860314_p1316918254269"></a><a name="en-us_topic_0000001059860314_p1316918254269"></a>Scheduling and distribution of test cases</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row197501910202715"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p1375091013272"><a name="en-us_topic_0000001059860314_p1375091013272"></a><a name="en-us_topic_0000001059860314_p1375091013272"></a>xdevice/src/xdevice/_core/driver</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p10750101062710"><a name="en-us_topic_0000001059860314_p10750101062710"></a><a name="en-us_topic_0000001059860314_p10750101062710"></a>Test executor for the basic testing framework</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row176501346185920"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p66514461593"><a name="en-us_topic_0000001059860314_p66514461593"></a><a name="en-us_topic_0000001059860314_p66514461593"></a>xdevice/src/xdevice/_core/resource</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p15651746155911"><a name="en-us_topic_0000001059860314_p15651746155911"></a><a name="en-us_topic_0000001059860314_p15651746155911"></a>Resource files and test report templates for the basic testing framework</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row1484675718210"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p20847105792118"><a name="en-us_topic_0000001059860314_p20847105792118"></a><a name="en-us_topic_0000001059860314_p20847105792118"></a>xdevice/src/xdevice/_core/testkit</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p784795762120"><a name="en-us_topic_0000001059860314_p784795762120"></a><a name="en-us_topic_0000001059860314_p784795762120"></a>Common operations for the basic testing framework, including NFS mounting</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row182104023911"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p5211808398"><a name="en-us_topic_0000001059860314_p5211808398"></a><a name="en-us_topic_0000001059860314_p5211808398"></a>xdevice/src/xdevice/_core/logger.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p92110017395"><a name="en-us_topic_0000001059860314_p92110017395"></a><a name="en-us_topic_0000001059860314_p92110017395"></a>Log management of the basic testing framework</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row164491410124017"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p7449171012400"><a name="en-us_topic_0000001059860314_p7449171012400"></a><a name="en-us_topic_0000001059860314_p7449171012400"></a>xdevice/src/xdevice/_core/plugin.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p1944991024013"><a name="en-us_topic_0000001059860314_p1944991024013"></a><a name="en-us_topic_0000001059860314_p1944991024013"></a>Plug-in management of the basic testing framework</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row14857134011406"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p118571440104014"><a name="en-us_topic_0000001059860314_p118571440104014"></a><a name="en-us_topic_0000001059860314_p118571440104014"></a>xdevice/src/xdevice/_core/interface.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p158571940184016"><a name="en-us_topic_0000001059860314_p158571940184016"></a><a name="en-us_topic_0000001059860314_p158571940184016"></a>Interfaces for plug-ins of the basic testing framework</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row94193383812"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p154194363813"><a name="en-us_topic_0000001059860314_p154194363813"></a><a name="en-us_topic_0000001059860314_p154194363813"></a>xdevice/setup.py</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p44193353819"><a name="en-us_topic_0000001059860314_p44193353819"></a><a name="en-us_topic_0000001059860314_p44193353819"></a>Installation script of the basic testing framework</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row537019532284"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p63711953202815"><a name="en-us_topic_0000001059860314_p63711953202815"></a><a name="en-us_topic_0000001059860314_p63711953202815"></a>xdevice/run.bat</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p4371153172812"><a name="en-us_topic_0000001059860314_p4371153172812"></a><a name="en-us_topic_0000001059860314_p4371153172812"></a>Startup script of the basic testing framework (Windows)</p>
</td>
</tr>
<tr id="en-us_topic_0000001059860314_row554513912325"><td class="cellrowborder" valign="top" width="45.050000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001059860314_p165451493324"><a name="en-us_topic_0000001059860314_p165451493324"></a><a name="en-us_topic_0000001059860314_p165451493324"></a>xdevice/run.sh</p>
</td>
<td class="cellrowborder" valign="top" width="54.949999999999996%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001059860314_p165453953218"><a name="en-us_topic_0000001059860314_p165453953218"></a><a name="en-us_topic_0000001059860314_p165453953218"></a>Startup script of the basic testing framework (Linux)</p>
</td>
</tr>
</tbody>
</table>

