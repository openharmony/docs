# XTS<a name="EN-US_TOPIC_0000001074750691"></a>

-   [Overview](#en-us_topic_0000001059475030_section44931242483)
-   [Directory Structure](#en-us_topic_0000001059475030_section45118915548)
-   [Limitations and Constraints](#en-us_topic_0000001059475030_section115518148474)
-   [Development Guidelines](#en-us_topic_0000001059475030_section99973470498)
    -   [ACTS Cases for the IoTLink Module](#en-us_topic_0000001059475030_section1348215596491)
    -   [ACTS Cases for the SmartVision Device \(IP Camera\)](#en-us_topic_0000001059475030_section11458163095019)
    -   [Executing ACTS Cases for the IoTLink Module](#en-us_topic_0000001059475030_section3115140115113)
    -   [Executing ACTS Cases for the SmartVision Device \(IP Camera\)](#en-us_topic_0000001059475030_section1759138185215)


## Overview<a name="en-us_topic_0000001059475030_section44931242483"></a>

X Test Suite is a set of OpenHarmony certification test suites, including the currently supported application compatibility test suite \(ACTS\) and the device compatibility test suite \(DCTS\) that will be supported in the future.

The  **test/xts**  repository contains the  **acts**  directory and  **tools**  software package.

-   The  **acts**  directory stores the source code and configuration files of ACTS test cases. The ACTS helps device vendors detect the software incompatibility as early as possible and ensures that the software is compatible to OpenHarmony during the entire development process.
-   The  **tools**  software package stores the test case development framework related to  **acts**.

## Directory Structure<a name="en-us_topic_0000001059475030_section45118915548"></a>

The directory structure of the  **test/xts**  repository is as follows:

├── acts

│   ├── BUILD.gn \#Compilation configuration of test cases

│   └── subsystem\_lite   \# Test case source code

└── tools

│   └── build \#Templates and scripts related to test cases compilation

│   └── hcpptest \#Source code of the development framework for SmartVision device \(IP camera\) test cases

│   └── hctest \#Source code of the development framework for IoTLink module test cases

│   └── BUILD.gn \#Compilation configuration

│   └── build.sh \#Compiling entry

## Limitations and Constraints<a name="en-us_topic_0000001059475030_section115518148474"></a>

You must use the C language to develop IoTLink module ACTS cases, and C++ for SmartVision device \(IP camera\) ACTS cases.

## Development Guidelines<a name="en-us_topic_0000001059475030_section99973470498"></a>

### ACTS Cases for the IoTLink Module<a name="en-us_topic_0000001059475030_section1348215596491"></a>

The HCTest framework is used.

The HCTest framework supports the C language and allows you to execute your test cases on the connecting module. The framework is enhanced and adapted based on the open-source test framework Unity.

1.  Store test cases in the  **test/xts/acts**  repository.

    ├── acts

    │   ├── BUILD.gn

    │   └──subsystem\_lite

    │   │   └── module\_hal

    │   │   │   └──  BUILD.gn

    │   │   │   └── src

2.  Write the test case stored in the  **src**  directory.

    a. Import the test framework.

    ```
    #include "hctest.h"
    ```

    b. Use the  **LITE\_TEST\_SUIT**  macro to define names of the subsystem, module, and test suite.

    ```
    /**  
    * @brief  register a test suit named "IntTestSuite"  
    * @param  test subsystem name  
    * @param  example module name  
    * @param  IntTestSuite test suit name  
    */
    LITE_TEST_SUIT(test, example, IntTestSuite);
    ```

    c. Define Setup and TearDown.

    Format: test suite name+Setup, test suite name+TearDown.

    The Setup and TearDown functions must exist, but function bodies can be empty.

    d. Use the  **LITE\_TEST\_CASE**  macro to write the test case.

    Three parameters are involved: test suite name, test case name, and test case level.

    The case level can be one of the following:

    **Level0**,  **Level1**,  **Level2**,  **Level3**, and  **Level4**.

    ```
    LITE_TEST_CASE(IntTestSuite, TestCase001, Level0) 
    {  
      //do something 
    };
    ```

    The following table describes the case levels.

    **Table  1**  Case levels

    <a name="en-us_topic_0000001059475030_table115309197517"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001059475030_row053010198520"><th class="cellrowborder" valign="top" width="13.46134613461346%" id="mcps1.2.4.1.1"><p id="en-us_topic_0000001059475030_p6251523752"><a name="en-us_topic_0000001059475030_p6251523752"></a><a name="en-us_topic_0000001059475030_p6251523752"></a><strong id="en-us_topic_0000001059475030_b735631654213"><a name="en-us_topic_0000001059475030_b735631654213"></a><a name="en-us_topic_0000001059475030_b735631654213"></a>Level</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="10.25102510251025%" id="mcps1.2.4.1.2"><p id="en-us_topic_0000001059475030_p1825117231157"><a name="en-us_topic_0000001059475030_p1825117231157"></a><a name="en-us_topic_0000001059475030_p1825117231157"></a><strong id="en-us_topic_0000001059475030_b6560217204216"><a name="en-us_topic_0000001059475030_b6560217204216"></a><a name="en-us_topic_0000001059475030_b6560217204216"></a>Definition</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="76.2876287628763%" id="mcps1.2.4.1.3"><p id="en-us_topic_0000001059475030_p1325111230519"><a name="en-us_topic_0000001059475030_p1325111230519"></a><a name="en-us_topic_0000001059475030_p1325111230519"></a><strong id="en-us_topic_0000001059475030_b5195171918426"><a name="en-us_topic_0000001059475030_b5195171918426"></a><a name="en-us_topic_0000001059475030_b5195171918426"></a>Testing Scope</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001059475030_row45301619957"><td class="cellrowborder" valign="top" width="13.46134613461346%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059475030_p122511231759"><a name="en-us_topic_0000001059475030_p122511231759"></a><a name="en-us_topic_0000001059475030_p122511231759"></a>Level0</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.25102510251025%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059475030_p132511238516"><a name="en-us_topic_0000001059475030_p132511238516"></a><a name="en-us_topic_0000001059475030_p132511238516"></a>Smoke</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.2876287628763%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059475030_p82511223550"><a name="en-us_topic_0000001059475030_p82511223550"></a><a name="en-us_topic_0000001059475030_p82511223550"></a>Verifies basic functionalities of key features and basic DFX attributes with the most common input. The pass result indicates that the features are runnable.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059475030_row12531121912518"><td class="cellrowborder" valign="top" width="13.46134613461346%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059475030_p16252523557"><a name="en-us_topic_0000001059475030_p16252523557"></a><a name="en-us_topic_0000001059475030_p16252523557"></a>Level1</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.25102510251025%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059475030_p1125212231358"><a name="en-us_topic_0000001059475030_p1125212231358"></a><a name="en-us_topic_0000001059475030_p1125212231358"></a>Basic</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.2876287628763%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059475030_p02521123757"><a name="en-us_topic_0000001059475030_p02521123757"></a><a name="en-us_topic_0000001059475030_p02521123757"></a>Verifies basic functionalities of key features and basic DFX attributes with common input. The pass result indicates that the features are testable.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059475030_row1531131917514"><td class="cellrowborder" valign="top" width="13.46134613461346%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059475030_p1525219237517"><a name="en-us_topic_0000001059475030_p1525219237517"></a><a name="en-us_topic_0000001059475030_p1525219237517"></a>Level2</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.25102510251025%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059475030_p5252523458"><a name="en-us_topic_0000001059475030_p5252523458"></a><a name="en-us_topic_0000001059475030_p5252523458"></a>Major</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.2876287628763%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059475030_p1125215231552"><a name="en-us_topic_0000001059475030_p1125215231552"></a><a name="en-us_topic_0000001059475030_p1125215231552"></a>Verifies basic functionalities of key features and basic DFX attributes with common input and errors. The pass result indicates that the features are functional and ready for beta testing.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059475030_row1853111191556"><td class="cellrowborder" valign="top" width="13.46134613461346%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059475030_p625220234514"><a name="en-us_topic_0000001059475030_p625220234514"></a><a name="en-us_topic_0000001059475030_p625220234514"></a>Level3</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.25102510251025%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059475030_p92528231952"><a name="en-us_topic_0000001059475030_p92528231952"></a><a name="en-us_topic_0000001059475030_p92528231952"></a>Regular</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.2876287628763%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059475030_p72521423855"><a name="en-us_topic_0000001059475030_p72521423855"></a><a name="en-us_topic_0000001059475030_p72521423855"></a>Verifies functionalities of all key features, and all DFX attributes with common and uncommon input combinations or normal and abnormal preset conditions.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059475030_row25311219459"><td class="cellrowborder" valign="top" width="13.46134613461346%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059475030_p52521223659"><a name="en-us_topic_0000001059475030_p52521223659"></a><a name="en-us_topic_0000001059475030_p52521223659"></a>Level4</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.25102510251025%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059475030_p10252223853"><a name="en-us_topic_0000001059475030_p10252223853"></a><a name="en-us_topic_0000001059475030_p10252223853"></a>Rare</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.2876287628763%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059475030_p1625214231655"><a name="en-us_topic_0000001059475030_p1625214231655"></a><a name="en-us_topic_0000001059475030_p1625214231655"></a>Verifies functionalities of key features under extremely abnormal presets and uncommon input combinations.</p>
    </td>
    </tr>
    </tbody>
    </table>

    e. Use the  **RUN\_TEST\_SUITE**  macro to register the test suite.

    ```
    RUN_TEST_SUITE(IntTestSuite);
    ```

3.  Create the configuration file of the test module.

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

4.  Add compilation options to the  **BUILD.gn**  file in the  **acts**  directory.

    You need to add the test module to the  **test/xts/acts/BUILD.gn**  script in the  **acts**  directory.

    ```
    lite_component("acts") {  
        ...
        if(board_name == "liteos_riscv") {
            features += [    
                ...
                "//xts/acts/subsystem_lite/module_hal:ActsDemoTest"
            ]    
        }
    }
    ```

5.  Run compilation commands.

    **python build.py wifiiot -b debug**

    **out/wifiiot**

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >The ACTS compilation middleware used for IoTLink module is a static library, which will be linked to the version image  **Hi3861\_wifiiot\_app\_allinone.bin**.


### ACTS Cases for the SmartVision Device \(IP Camera\)<a name="en-us_topic_0000001059475030_section11458163095019"></a>

The HCPP Test framework is enhanced and adapted based on the open-source googletest framework.

1.  Store test cases in the  **test/xts/acts**  repository.

    ├── acts

    │   ├── BUILD.gn

    │   └──subsystem\_lite

    │   │   └── module\_posix

    │   │   │   └──  BUILD.gn

    │   │   │   └── src

2.  Write the test case stored in the  **src**  directory.

    a. Import the test framework.

    The following statement imports  **gtest.h**.

    ```
    #include "gtest/gtest.h"
    ```

    b. Define Setup and TearDown.

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

    c. Use the  **HWTEST**  or  **HWTEST\_F**  macro to write the test case.

    **HWTEST**: definition of common test cases, including the test suite name, test case name, and case marking.

    **HWTEST\_F**: definition of SetUp and TearDown test cases, including the test suite name, test case name, and case marking.

    A macro definition contains three parameters: test suite name, test case name, and test case level.

    The case level can be one of the following:

    **Level0**,  **Level1**,  **Level2**,  **Level3**, and  **Level4**.

    ```
    HWTEST_F(TestSuite, TestCase_0001, Level0) {
    // do something
    }
    ```

    The following table describes the case levels.

    **Table  2**  Case levels

    <a name="en-us_topic_0000001059475030_table1830755842"></a>
    <table><thead align="left"><tr id="en-us_topic_0000001059475030_row93075510420"><th class="cellrowborder" valign="top" width="13.681368136813681%" id="mcps1.2.4.1.1"><p id="en-us_topic_0000001059475030_p153681823247"><a name="en-us_topic_0000001059475030_p153681823247"></a><a name="en-us_topic_0000001059475030_p153681823247"></a><strong id="en-us_topic_0000001059475030_b4584205664410"><a name="en-us_topic_0000001059475030_b4584205664410"></a><a name="en-us_topic_0000001059475030_b4584205664410"></a>Level</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="10.961096109610962%" id="mcps1.2.4.1.2"><p id="en-us_topic_0000001059475030_p9368823749"><a name="en-us_topic_0000001059475030_p9368823749"></a><a name="en-us_topic_0000001059475030_p9368823749"></a><strong id="en-us_topic_0000001059475030_b514111593442"><a name="en-us_topic_0000001059475030_b514111593442"></a><a name="en-us_topic_0000001059475030_b514111593442"></a>Definition</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="75.35753575357535%" id="mcps1.2.4.1.3"><p id="en-us_topic_0000001059475030_p3368112319418"><a name="en-us_topic_0000001059475030_p3368112319418"></a><a name="en-us_topic_0000001059475030_p3368112319418"></a><strong id="en-us_topic_0000001059475030_b2745175924412"><a name="en-us_topic_0000001059475030_b2745175924412"></a><a name="en-us_topic_0000001059475030_b2745175924412"></a>Testing Scope</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000001059475030_row13079520412"><td class="cellrowborder" valign="top" width="13.681368136813681%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059475030_p1236811237417"><a name="en-us_topic_0000001059475030_p1236811237417"></a><a name="en-us_topic_0000001059475030_p1236811237417"></a>Level0</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.961096109610962%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059475030_p336812235414"><a name="en-us_topic_0000001059475030_p336812235414"></a><a name="en-us_topic_0000001059475030_p336812235414"></a>Smoke</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.35753575357535%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059475030_p2036852311414"><a name="en-us_topic_0000001059475030_p2036852311414"></a><a name="en-us_topic_0000001059475030_p2036852311414"></a>Verifies basic functionalities of key features and basic DFX attributes with the most common input. The pass result indicates that the features are runnable.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059475030_row4307953415"><td class="cellrowborder" valign="top" width="13.681368136813681%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059475030_p18369623540"><a name="en-us_topic_0000001059475030_p18369623540"></a><a name="en-us_topic_0000001059475030_p18369623540"></a>Level1</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.961096109610962%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059475030_p103698231443"><a name="en-us_topic_0000001059475030_p103698231443"></a><a name="en-us_topic_0000001059475030_p103698231443"></a>Basic</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.35753575357535%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059475030_p136916234410"><a name="en-us_topic_0000001059475030_p136916234410"></a><a name="en-us_topic_0000001059475030_p136916234410"></a>Verifies basic functionalities of key features and basic DFX attributes with common input. The pass result indicates that the features are testable.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059475030_row83075510419"><td class="cellrowborder" valign="top" width="13.681368136813681%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059475030_p12369192315420"><a name="en-us_topic_0000001059475030_p12369192315420"></a><a name="en-us_topic_0000001059475030_p12369192315420"></a>Level2</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.961096109610962%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059475030_p13698231341"><a name="en-us_topic_0000001059475030_p13698231341"></a><a name="en-us_topic_0000001059475030_p13698231341"></a>Major</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.35753575357535%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059475030_p16369142312412"><a name="en-us_topic_0000001059475030_p16369142312412"></a><a name="en-us_topic_0000001059475030_p16369142312412"></a>Verifies basic functionalities of key features and basic DFX attributes with common input and errors. The pass result indicates that the features are functional and ready for beta testing.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059475030_row930815512416"><td class="cellrowborder" valign="top" width="13.681368136813681%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059475030_p1636932315417"><a name="en-us_topic_0000001059475030_p1636932315417"></a><a name="en-us_topic_0000001059475030_p1636932315417"></a>Level3</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.961096109610962%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059475030_p1336918239414"><a name="en-us_topic_0000001059475030_p1336918239414"></a><a name="en-us_topic_0000001059475030_p1336918239414"></a>Regular</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.35753575357535%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059475030_p143691023345"><a name="en-us_topic_0000001059475030_p143691023345"></a><a name="en-us_topic_0000001059475030_p143691023345"></a>Verifies functionalities of all key features, and all DFX attributes with common and uncommon input combinations or normal and abnormal preset conditions.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000001059475030_row183085518414"><td class="cellrowborder" valign="top" width="13.681368136813681%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000001059475030_p63691423347"><a name="en-us_topic_0000001059475030_p63691423347"></a><a name="en-us_topic_0000001059475030_p63691423347"></a>Level4</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.961096109610962%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000001059475030_p63697236413"><a name="en-us_topic_0000001059475030_p63697236413"></a><a name="en-us_topic_0000001059475030_p63697236413"></a>Rare</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.35753575357535%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000001059475030_p133695231443"><a name="en-us_topic_0000001059475030_p133695231443"></a><a name="en-us_topic_0000001059475030_p133695231443"></a>Verifies functionalities of key features under extremely abnormal presets and uncommon input combinations.</p>
    </td>
    </tr>
    </tbody>
    </table>

3.  Create the configuration file of the test module.

    Create a  **BUILD.gn**  \(example\) compilation file in each test module directory. Specify the name of the compiled static library and its dependent header file and library in the compilation file. Each test module is independently compiled into a  **.bin**  executable file, which can be directly mounted to the development board for testing.

    Example:

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

4.  Add compilation options to the  **BUILD.gn**  file in the  **acts**  directory.

    Add the test module to the  **test/xts/acts/BUILD.gn**  script in the  **acts**  directory.

    ```
     lite_component("acts") {  
    ...
    else if(board_name == "liteos_a") {
            features += [
                ...
                "//xts/acts/subsystem_lite/module_posix:ActsDemoTest"
            ]
        }
    }
    ```

5.  Run compilation commands.

    -   For Hi3518E V300:

    **python build.py ipcamera\_hi3518ev300 -b debug**

    **out/ipcamera\_hi3518ev300**

    -   For Hi3516D V300:

    **python build.py ipcamera\_hi3518ev300 -b debug**

    **out/ipcamera\_hi3516dv300**

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >The ACTS for the SmartVision device \(IP camera\) is independently compiled to a  **.bin**  executable file, which can be directly mounted to the development board for testing.


### Executing ACTS Cases for the IoTLink Module<a name="en-us_topic_0000001059475030_section3115140115113"></a>

**Obtaining the testing software package**

Obtain the image from the  **out\\wifiiot\\Hi3861\_wifiiot\_app\_allinone.bin**  directory.

Note: To check whether the ACTS is integrated into the current image, go to  **out\\wifiiot\\Hi3861\_wifiiot\_app.map**  to check whether the corresponding  **.a**  file is compiled.

**Burning the image into the development board**

**Performing testing**

1.  Use a serial port tool to log in to the development board and save information about the serial port.
2.  Restart the device and view serial port logs.

**Analyzing the test result.**

View the serial port logs, whose format is as follows:

The log for each test suite starts with  **Start to run test suite:**  and ends with  **xx Tests xx Failures xx Ignored**.

### Executing ACTS Cases for the SmartVision Device \(IP Camera\)<a name="en-us_topic_0000001059475030_section1759138185215"></a>

Currently, test cases are shared by the NFS and mounted to the development board for execution.

**Setting up the environment**

1.  Use a network cable or wireless network to connect the IP camera development board to your personal computer \(PC\).
2.  Configure the IP address, subnet mask, and gateway for the IP camera development board. Ensure that the development board and the PC are in the same network segment.
3.  Install and register the NFS server on the PC and start the NFS service.
4.  Run the  **mount**  command for the IP camera development board to ensure that the development board can access NFS shared files on the PC.

    Format:  **mount** _NFS server IP address_**:/**_NFS shared directory_ **/**_IP camera development board directory_ **nfs**

    Example:

    ```
    mount 192.168.1.10:/nfs /nfs nfs
    ```


**Executing test cases**

1.  View the serial port logs.
2.  Run the  **./**_Test module_**.bin**  command to execute test cases of each test suite.

