# X Test Suite Certification Subsystem<a name="EN-US_TOPIC_0000001051663004"></a>

## Overview<a name="section9242181211612"></a>

X test suite is a set of OpenHarmony certification test suites, including the currently supported application compatibility test suite \(ACTS\) and the device compatibility test suite \(DCTS\) that will be supported in the future.

The  **test/xts**  repository contains the  **acts**  directory and  **tools**  software package.

-   The  **acts**  directory stores the source code and configuration files of ACTS test cases. The ACTS helps device vendors detect the software incompatibility as early as possible and ensures that the software is compatible to OpenHarmony during the entire development process.
-   The  **tools**  software package provides the test case development framework where ACTS code is compiled.

## Directory Structure<a name="section36203291667"></a>

The directory structure of the  **test/xts**  repository is as follows:

├── acts

│   ├── BUILD.gn \#Compilation configuration of test cases

│   └── testing\_subsystem\_A\_lite \#Test case source code of A

│   └── testing\_subsystem\_B\_lite \#Test case source code of B

└── tools

│   └── build \#Templates and scripts related to test cases compilation

│   └── hcpptest \#Source code of the development framework for SmartVision device \(IP camera\) test cases

│   └── hctest \#Source code of the development framework for IoTLink module test cases

│   └── BUILD.gn \#Compilation configuration

│   └── build.sh \#Compiling entry

## Constraints<a name="section755813411667"></a>

You must use the C language to develop IoTLink module ACTS cases, and C++ for SmartVision device \(IP camera\) ACTS cases.

## ACTS Cases for the IoTLink Module<a name="section98382591568"></a>

The HCTest framework is used.

The HCTest framework supports the C language and allows you to execute your test cases on the connecting module. The framework is enhanced and adapted based on the open-source test framework Unity.

1. Store test cases in the  **test/xts/acts**  repository.

├── acts

│   ├── BUILD.gn

│   └── Testing\_subsystem\_lite

│   │   └── Testing\_module\_hal

│   │   │   └── BUILD.gn

│   │   │   └── src \#Test case source code

2. Write the test case stored in the  **src**  directory.

\(1\) Import the test framework.

```
#include "hctest.h"
```

\(2\) Use the  **LITE\_TEST\_SUIT**  macro to define names of the subsystem, module, and test suite.

```
/**  
* @brief  register a test suit named "IntTestSuite"  
* @param  test subsystem name  
* @param  example module name  
* @param  IntTestSuite test suit name  
*/
LITE_TEST_SUIT(test, example, IntTestSuite);
```

\(3\) Define Setup and TearDown.

Format: test suite name+Setup, test suite name+TearDown.

The Setup and TearDown functions must exist, but function bodies can be empty.

\(4\) Use the  **LITE\_TEST\_CASE**  macro to write the test case.

Three parameters are involved: test suite name, test case name, and test case level.

The case level can be one of the following:

**Level0**,  **Level1**,  **Level2**,  **Level3**, and  **Level4**.

```
LITE_TEST_CASE(IntTestSuite, TestCase001, Level0) 
{  
  // Do something.
};
```

The following table describes the case levels.

<a name="table34971832145813"></a>
<table><thead align="left"><tr id="row175461132115812"><th class="cellrowborder" valign="top" width="13.751375137513753%" id="mcps1.1.4.1.1"><p id="p5546193210584"><a name="p5546193210584"></a><a name="p5546193210584"></a><strong id="b14603171785015"><a name="b14603171785015"></a><a name="b14603171785015"></a>Level</strong></p>
</th>
<th class="cellrowborder" valign="top" width="11.08110811081108%" id="mcps1.1.4.1.2"><p id="p15546133255813"><a name="p15546133255813"></a><a name="p15546133255813"></a><strong id="b1868982015014"><a name="b1868982015014"></a><a name="b1868982015014"></a>Definition</strong></p>
</th>
<th class="cellrowborder" valign="top" width="75.16751675167517%" id="mcps1.1.4.1.3"><p id="p454693295816"><a name="p454693295816"></a><a name="p454693295816"></a><strong id="b654623216588"><a name="b654623216588"></a><a name="b654623216588"></a>Testing Scope</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row054663212583"><td class="cellrowborder" valign="top" width="13.751375137513753%" headers="mcps1.1.4.1.1 "><p id="p4546732205817"><a name="p4546732205817"></a><a name="p4546732205817"></a>Level0</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.4.1.2 "><p id="p75464323584"><a name="p75464323584"></a><a name="p75464323584"></a>Smoke</p>
</td>
<td class="cellrowborder" valign="top" width="75.16751675167517%" headers="mcps1.1.4.1.3 "><p id="p10547232135819"><a name="p10547232135819"></a><a name="p10547232135819"></a>Verifies basic functionalities of key features and basic DFX attributes with the most common input. The pass result indicates that the features are runnable.</p>
</td>
</tr>
<tr id="row1054743225819"><td class="cellrowborder" valign="top" width="13.751375137513753%" headers="mcps1.1.4.1.1 "><p id="p35471932105811"><a name="p35471932105811"></a><a name="p35471932105811"></a>Level1</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.4.1.2 "><p id="p135471328585"><a name="p135471328585"></a><a name="p135471328585"></a>Basic</p>
</td>
<td class="cellrowborder" valign="top" width="75.16751675167517%" headers="mcps1.1.4.1.3 "><p id="p195475329589"><a name="p195475329589"></a><a name="p195475329589"></a>Verifies basic functionalities of key features and basic DFX attributes with common input. The pass result indicates that the features are testable.</p>
</td>
</tr>
<tr id="row654713285815"><td class="cellrowborder" valign="top" width="13.751375137513753%" headers="mcps1.1.4.1.1 "><p id="p1954793265810"><a name="p1954793265810"></a><a name="p1954793265810"></a>Level2</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.4.1.2 "><p id="p3547232135812"><a name="p3547232135812"></a><a name="p3547232135812"></a>Major</p>
</td>
<td class="cellrowborder" valign="top" width="75.16751675167517%" headers="mcps1.1.4.1.3 "><p id="p5547832195811"><a name="p5547832195811"></a><a name="p5547832195811"></a>Verifies basic functionalities of key features and basic DFX attributes with common input and errors. The pass result indicates that the features are functional and ready for beta testing.</p>
</td>
</tr>
<tr id="row85471332135818"><td class="cellrowborder" valign="top" width="13.751375137513753%" headers="mcps1.1.4.1.1 "><p id="p185471320586"><a name="p185471320586"></a><a name="p185471320586"></a>Level3</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.4.1.2 "><p id="p2547153212582"><a name="p2547153212582"></a><a name="p2547153212582"></a>Regular</p>
</td>
<td class="cellrowborder" valign="top" width="75.16751675167517%" headers="mcps1.1.4.1.3 "><p id="p17547133245813"><a name="p17547133245813"></a><a name="p17547133245813"></a>Verifies functionalities of all key features, and all DFX attributes with common and uncommon input combinations or normal and abnormal preset conditions.</p>
</td>
</tr>
<tr id="row1254710325584"><td class="cellrowborder" valign="top" width="13.751375137513753%" headers="mcps1.1.4.1.1 "><p id="p554713329584"><a name="p554713329584"></a><a name="p554713329584"></a>Level4</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.4.1.2 "><p id="p1454711328588"><a name="p1454711328588"></a><a name="p1454711328588"></a>Rare</p>
</td>
<td class="cellrowborder" valign="top" width="75.16751675167517%" headers="mcps1.1.4.1.3 "><p id="p105479324587"><a name="p105479324587"></a><a name="p105479324587"></a>Verifies functionalities of key features under extremely abnormal presets and uncommon input combinations.</p>
</td>
</tr>
</tbody>
</table>

\(5\) Use the  **RUN\_TEST\_SUITE**  macro to register the test suite.

```
RUN_TEST_SUITE(IntTestSuite);
```

3. Create the configuration file of the test module.

Create a  **BUILD.gn**  \(example\) compilation file in each test module directory. Specify the name of the compiled static library and its dependent header file and library in the compilation file. The format is as follows:

```
import("//test/xts/tools/build/suite_lite.gni")
hctest_suite("ActsDemoTest") {
    suite_name = "acts"
    sources = [
        "src/test_demo.c",
    ]
    include_dirs = [ ]
    cflags = [ "-Wno-error" ]
}
```

4. Add compilation options to the  **BUILD.gn**  file in the  **acts**  directory.

To add test code to the compilation file, you need to add the test module to the  **test/xts/acts/BUILD.gn**  script in the  **acts**  directory.

```
lite_component("acts") {  
    ...
    if(board_name == "liteos_riscv") {
        features += [    
            ...
            "//xts/acts/testing_subsystem_lite/testing_module_hal:ActsDemoTest"
        ]    
    }
}
```

5. Run compilation commands.

\(1\)  **python build.py wifiiot -b debug**

\(2\)  **out/wifiiot**

Note: The ACTS compilation middleware used for IoTLink modules is a static library, which will be linked to the version image  **Hi3861\_wifiiot\_app\_allinone.bin**.

## ACTS Cases for the SmartVision Device \(IP Camera\)<a name="section1997532920813"></a>

The HCPP Test framework is enhanced and adapted based on the open-source googletest framework.

1. Store test cases in the  **test/xts/acts**  repository.

├── acts

│   ├── BUILD.gn

│   └── Testing\_subsystem\_lite

│   │   └── Testing\_module\_posix

│   │   │   └── BUILD.gn

│   │   │   └── src \(Test case source code\)

2. Write the test case stored in the  **src**  directory.

\(1\) Import the test framework.

The following statement imports  **gtest.h**.

```
#include "gtest/gtest.h"
```

\(2\) Define Setup and TearDown.

```
class TestSuite: public testing::Test {
protected:
// Preset action of the test suite, which is executed before the first test case
static void SetUpTestCase(void){
}
// Test suite cleanup action, which is executed after the last test case
static void TearDownTestCase(void){
}
// Preset action of the test case
virtual void SetUp()
{
}
// Cleanup action of the test case
virtual void TearDown()
{
}
};
```

\(3\) Use the  **HWTEST**  or  **HWTEST\_F**  macro to write the test case.

**HWTEST**: definition of common test cases, including the test suite name, test case name, and case marking.

**HWTEST\_F**: definition of SetUp and TearDown test cases, including the test suite name, test case name, and case marking.

A macro definition contains three parameters: test suite name, test case name, and test case level.

The case level can be one of the following:

**Level0**,  **Level1**,  **Level2**,  **Level3**, and  **Level4**.

```
HWTEST_F(TestSuite, TestCase_0001, Level0) {
// Do something.
}
```

The following table describes the case levels.

<a name="table10426001094"></a>
<table><thead align="left"><tr id="row342660796"><th class="cellrowborder" valign="top" width="13.751375137513753%" id="mcps1.1.4.1.1"><p id="p7426201917"><a name="p7426201917"></a><a name="p7426201917"></a><strong id="b042543457"><a name="b042543457"></a><a name="b042543457"></a>Level</strong></p>
</th>
<th class="cellrowborder" valign="top" width="11.08110811081108%" id="mcps1.1.4.1.2"><p id="p18426201294"><a name="p18426201294"></a><a name="p18426201294"></a><strong id="b10788351959"><a name="b10788351959"></a><a name="b10788351959"></a>Definition</strong></p>
</th>
<th class="cellrowborder" valign="top" width="75.16751675167517%" id="mcps1.1.4.1.3"><p id="p1426100993"><a name="p1426100993"></a><a name="p1426100993"></a><strong id="b19691291853"><a name="b19691291853"></a><a name="b19691291853"></a>Testing Scope</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row9427809912"><td class="cellrowborder" valign="top" width="13.751375137513753%" headers="mcps1.1.4.1.1 "><p id="p124271401594"><a name="p124271401594"></a><a name="p124271401594"></a>Level0</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.4.1.2 "><p id="p1042715015915"><a name="p1042715015915"></a><a name="p1042715015915"></a>Smoke</p>
</td>
<td class="cellrowborder" valign="top" width="75.16751675167517%" headers="mcps1.1.4.1.3 "><p id="p174271501293"><a name="p174271501293"></a><a name="p174271501293"></a>Verifies basic functionalities of key features and basic DFX attributes with the most common input. The pass result indicates that the features are runnable.</p>
</td>
</tr>
<tr id="row7427300915"><td class="cellrowborder" valign="top" width="13.751375137513753%" headers="mcps1.1.4.1.1 "><p id="p0427501495"><a name="p0427501495"></a><a name="p0427501495"></a>Level1</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.4.1.2 "><p id="p184276018920"><a name="p184276018920"></a><a name="p184276018920"></a>Basic</p>
</td>
<td class="cellrowborder" valign="top" width="75.16751675167517%" headers="mcps1.1.4.1.3 "><p id="p1427706911"><a name="p1427706911"></a><a name="p1427706911"></a>Verifies basic functionalities of key features and basic DFX attributes with common input. The pass result indicates that the features are testable.</p>
</td>
</tr>
<tr id="row84271603919"><td class="cellrowborder" valign="top" width="13.751375137513753%" headers="mcps1.1.4.1.1 "><p id="p11427701094"><a name="p11427701094"></a><a name="p11427701094"></a>Level2</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.4.1.2 "><p id="p84271208910"><a name="p84271208910"></a><a name="p84271208910"></a>Major</p>
</td>
<td class="cellrowborder" valign="top" width="75.16751675167517%" headers="mcps1.1.4.1.3 "><p id="p142711018915"><a name="p142711018915"></a><a name="p142711018915"></a>Verifies basic functionalities of key features and basic DFX attributes with common input and errors. The pass result indicates that the features are functional and ready for beta testing.</p>
</td>
</tr>
<tr id="row642715014919"><td class="cellrowborder" valign="top" width="13.751375137513753%" headers="mcps1.1.4.1.1 "><p id="p9427110794"><a name="p9427110794"></a><a name="p9427110794"></a>Level3</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.4.1.2 "><p id="p2427301499"><a name="p2427301499"></a><a name="p2427301499"></a>Regular</p>
</td>
<td class="cellrowborder" valign="top" width="75.16751675167517%" headers="mcps1.1.4.1.3 "><p id="p1442730497"><a name="p1442730497"></a><a name="p1442730497"></a>Verifies functionalities of all key features, and all DFX attributes with common and uncommon input combinations or normal and abnormal preset conditions.</p>
</td>
</tr>
<tr id="row14427110291"><td class="cellrowborder" valign="top" width="13.751375137513753%" headers="mcps1.1.4.1.1 "><p id="p2427201098"><a name="p2427201098"></a><a name="p2427201098"></a>Level4</p>
</td>
<td class="cellrowborder" valign="top" width="11.08110811081108%" headers="mcps1.1.4.1.2 "><p id="p342770794"><a name="p342770794"></a><a name="p342770794"></a>Rare</p>
</td>
<td class="cellrowborder" valign="top" width="75.16751675167517%" headers="mcps1.1.4.1.3 "><p id="p7427701094"><a name="p7427701094"></a><a name="p7427701094"></a>Verifies functionalities of key features under extremely abnormal presets and uncommon input combinations.</p>
</td>
</tr>
</tbody>
</table>

3. Create the configuration file of the test module.

Create a  **BUILD.gn**  \(example\) compilation file in each test module directory. Specify the name of the compiled static library and its dependent header file and library in the compilation file. Each test module is independently compiled into a  **.bin**  executable file, which can be directly mounted to the development board for testing.

The following is an example:

```
import("//test/xts/tools/build/suite_lite.gni")

hcpptest_suite("ActsDemoTest") {
    suite_name = "acts"
    sources = [
        "src/TestDemo.cpp"
    ]

    include_dirs = [
        "src",
        ...
    ]
    deps = [
        ...
    ]
    cflags = [ "-Wno-error" ]
}

```

4. Add compilation options to the  **BUILD.gn**  file in the  **acts**  directory.

To add the test code to the version compilation, you need to add the test module to the  **test/xts/acts/BUILD.gn**  script in the  **acts**  directory.

```
 lite_component("acts") {  
...
else if(board_name == "liteos_a") {
        features += [
            ...
            "//xts/acts/testing_subsystem_lite/testing_module_posix:ActsDemoTest"
        ]
    }
}
```

5. Run compilation commands.

1.1 Hi3518EV300

\(1\)  **python build.py ipcamera\_hi3518ev300 -b debug**

\(2\)  **out/ipcamera\_hi3518ev300**

1.2 Hi3516DV300

\(1\)  **python build.py ipcamera\_hi3516dv300 -b debug**

\(2\)  **out/ipcamera\_hi3516dv300**

Note: The ACTS for the SmartVision device \(IP camera\) is independently compiled to a  **.bin**  executable file, which can be directly mounted to the development board for testing.

## Executing ACTS Cases for the IoTLink Module<a name="section7879204912"></a>

1. Obtain the testing software package.

Obtain the image from the  **out\\wifiiot\\Hi3861\_wifiiot\_app\_allinone.bin**  directory.

Note: To check whether the ACTS is integrated into the current image, go to  **out\\wifiiot\\Hi3861\_wifiiot\_app.map**  to check whether the corresponding  **.a**  file is compiled.

2. Burn the image into the development board.

3. Perform testing.

\(1\) Use a serial port tool to log in to the development board and save information about the serial port.

\(2\) Restart the device and view serial port logs.

4. Analyze the test result.

View the serial port logs, and the format is as follows:

The log for each test suite starts with  **Start to run test suite:**  and ends with  **xx Tests xx Failures xx Ignored**.

## Executing ACTS Cases for the SmartVision Device \(IP Camera\)<a name="section204081752193"></a>

Currently, test cases are shared by the NFS and mounted to the development board for execution.

1. Set up the environment.

1.  Use a network cable or wireless network to connect the IP camera development board to your personal computer \(PC\).
2.  Configure the IP address, subnet mask, and gateway for the IP camera development board. Ensure that the development board and the PC are in the same network segment.
3.  Install and register the NFS server on the PC and start the NFS service.
4.  Run the  **mount**  command for the IP camera development board to ensure that the development board can access NFS shared files on the PC.

    Format:  **mount **_NFS server IP address_**:/**_NFS shared directory_**/**_IP camera development board directory_** nfs**

    Example:

    ```
    mount 192.168.1.10:/nfs /nfs nfs
    ```


2. Execute test cases.

\(1\) Analyze serial port logs.

\(2\) Run the  **./**_Test module_**.bin**  command to execute test cases of each test suite.

## Repositories Involved<a name="section6299103515474"></a>

xts\_acts

xts\_tools\_lite

