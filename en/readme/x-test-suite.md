# X Test Suite<a name="EN-US_TOPIC_0000001132537809"></a>

-   [Introduction](#section465982318513)
-   [Devices](#section125090457443)
-   [Directory Structure](#section161941989596)
-   [Constraints](#section119744591305)
-   [Usage Guidelines](#section137768191623)
-   [Test Case Development Guidelines](#section3695134065513)
    -   [C-based Test Case Development and Compilation \(for Mini-System Devices\)](#section1551164914237)
    -   [C-based Test Case Execution \(for Mini-System Devices\)](#section10100701294)

-   [Repositories Involved](#section1371113476307)

## Introduction<a name="section465982318513"></a>

The X test suite \(XTS\) subsystem contains a set of OpenHarmony certification test suites, including the currently supported application compatibility test suite \(ACTS\) and the device compatibility test suite \(DCTS\) that will be supported in the future.

This subsystem contains the ACTS and  **tools**  software package.

-   The  **acts**  directory stores the source code and configuration files of ACTS test cases. The ACTS helps device vendors detect the software incompatibility as early as possible and ensures that the software is compatible to OpenHarmony during the entire development process.
-   The  **tools**  software package stores the test case development framework related to  **acts**.

## Devices<a name="section125090457443"></a>

OpenHarmony supports the following device types:

-   **Mini-System Devices \(reference memory ≥ 128 KB\)**

    Such devices are equipped with MCU processors such as ARM Cortex-M and 32-bit RISC-V. They provide rich short-distance connection and peripheral bus access capabilities. Typical products include LinkIoT module devices and sensors in the smart home field. The LinkIoT module is usually used for smart Internet of Things \(IoT\) devices as the hardware module that implements connectivity functions. In the smart home field, the LinkIoT module is integrated into devices by vendors. For example, a LinkIoT module provides WLAN/Bluetooth access and data connection, and it usually communicates with the chip of smart home devices via a universal asynchronous receiver-transmitter \(UART\) or general-purpose input/output \(GPIO\) interface.

-   **Small-System Devices \(reference memory ≥ 1 MB\)**

    Such devices are equipped with application processors such as ARM Cortex-A. They provide higher security capabilities, standard graphics framework, and multimedia capabilities for video encoding and decoding. Typical products include IP cameras, electronic cat eyes, and routers in the smart home field, as well as event data recorders \(EDRs\) in the smart travel field.


## Directory Structure<a name="section161941989596"></a>

```
/test/xts
├── acts                 # Test code
│   └── subsystem       # Source code of subsystem test cases for large-system devices
│   └── subsystem_lite  # Source code of subsystems test cases for mini- and small-system devices
│   └── BUILD.gn        # Build configuration of test cases for large-system devices
│   └── build_lite      # Build configuration of test cases for mini-and small-system devices
│       └── build_lite    # Build configuration
└── tools                # Test tool code
```

## Constraints<a name="section119744591305"></a>

Test cases for mini system devices must be developed based on C, and those for small system devices must be developed based on C++.

## Usage Guidelines<a name="section137768191623"></a>

**Table  1**  Test case levels

<a name="table12856113719456"></a>
<table><thead align="left"><tr id="row88561737114517"><th class="cellrowborder" valign="top" width="33.333333333333336%" id="mcps1.2.4.1.1"><p id="p54711456452"><a name="p54711456452"></a><a name="p54711456452"></a>Level</p>
</th>
<th class="cellrowborder" valign="top" width="33.283328332833285%" id="mcps1.2.4.1.2"><p id="p114834544518"><a name="p114834544518"></a><a name="p114834544518"></a>Definition</p>
</th>
<th class="cellrowborder" valign="top" width="33.383338333833386%" id="mcps1.2.4.1.3"><p id="p348154574518"><a name="p348154574518"></a><a name="p348154574518"></a>Scope</p>
</th>
</tr>
</thead>
<tbody><tr id="row78561137134514"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p17481345124512"><a name="p17481345124512"></a><a name="p17481345124512"></a>Level0</p>
</td>
<td class="cellrowborder" valign="top" width="33.283328332833285%" headers="mcps1.2.4.1.2 "><p id="p1548945204514"><a name="p1548945204514"></a><a name="p1548945204514"></a>Smoke</p>
</td>
<td class="cellrowborder" valign="top" width="33.383338333833386%" headers="mcps1.2.4.1.3 "><p id="p174824517456"><a name="p174824517456"></a><a name="p174824517456"></a>Verifies basic functionalities of key features and basic DFX attributes with the most common input. The pass result indicates that the features are runnable.</p>
</td>
</tr>
<tr id="row28563372451"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p448445144512"><a name="p448445144512"></a><a name="p448445144512"></a>Level1</p>
</td>
<td class="cellrowborder" valign="top" width="33.283328332833285%" headers="mcps1.2.4.1.2 "><p id="p44813452452"><a name="p44813452452"></a><a name="p44813452452"></a>Basic</p>
</td>
<td class="cellrowborder" valign="top" width="33.383338333833386%" headers="mcps1.2.4.1.3 "><p id="p648184584514"><a name="p648184584514"></a><a name="p648184584514"></a>Verifies basic functionalities of key features and basic DFX attributes with common input. The pass result indicates that the features are testable.</p>
</td>
</tr>
<tr id="row12856137204514"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p164834520453"><a name="p164834520453"></a><a name="p164834520453"></a>Level2</p>
</td>
<td class="cellrowborder" valign="top" width="33.283328332833285%" headers="mcps1.2.4.1.2 "><p id="p148245184511"><a name="p148245184511"></a><a name="p148245184511"></a>Major</p>
</td>
<td class="cellrowborder" valign="top" width="33.383338333833386%" headers="mcps1.2.4.1.3 "><p id="p348945124510"><a name="p348945124510"></a><a name="p348945124510"></a>Verifies basic functionalities of key features and basic DFX attributes with common input and errors. The pass result indicates that the features are functional and ready for beta testing.</p>
</td>
</tr>
<tr id="row48571137204514"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p7481545184513"><a name="p7481545184513"></a><a name="p7481545184513"></a>Level3</p>
</td>
<td class="cellrowborder" valign="top" width="33.283328332833285%" headers="mcps1.2.4.1.2 "><p id="p1748184514455"><a name="p1748184514455"></a><a name="p1748184514455"></a>Regular</p>
</td>
<td class="cellrowborder" valign="top" width="33.383338333833386%" headers="mcps1.2.4.1.3 "><p id="p8481245104519"><a name="p8481245104519"></a><a name="p8481245104519"></a>Verifies functionalities of all key features, and all DFX attributes with common and uncommon input combinations or normal and abnormal preset conditions.</p>
</td>
</tr>
<tr id="row14857133712451"><td class="cellrowborder" valign="top" width="33.333333333333336%" headers="mcps1.2.4.1.1 "><p id="p1248144515456"><a name="p1248144515456"></a><a name="p1248144515456"></a>Level4</p>
</td>
<td class="cellrowborder" valign="top" width="33.283328332833285%" headers="mcps1.2.4.1.2 "><p id="p94804514519"><a name="p94804514519"></a><a name="p94804514519"></a>Rare</p>
</td>
<td class="cellrowborder" valign="top" width="33.383338333833386%" headers="mcps1.2.4.1.3 "><p id="p1248445164516"><a name="p1248445164516"></a><a name="p1248445164516"></a>Verifies functionalities of key features under extremely abnormal presets and uncommon input combinations.</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  Test case granularities

<a name="table1690733521014"></a>
<table><thead align="left"><tr id="row9907143516105"><th class="cellrowborder" valign="top" width="19.591959195919593%" id="mcps1.2.4.1.1"><p id="p1141312416102"><a name="p1141312416102"></a><a name="p1141312416102"></a>Test Scale</p>
</th>
<th class="cellrowborder" valign="top" width="35.17351735173517%" id="mcps1.2.4.1.2"><p id="p34131416109"><a name="p34131416109"></a><a name="p34131416109"></a>Test Objects</p>
</th>
<th class="cellrowborder" valign="top" width="45.23452345234523%" id="mcps1.2.4.1.3"><p id="p12413141171010"><a name="p12413141171010"></a><a name="p12413141171010"></a>Test Environment</p>
</th>
</tr>
</thead>
<tbody><tr id="row2907335181017"><td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.2.4.1.1 "><p id="p6414134117109"><a name="p6414134117109"></a><a name="p6414134117109"></a>LargeTest</p>
</td>
<td class="cellrowborder" valign="top" width="35.17351735173517%" headers="mcps1.2.4.1.2 "><p id="p20414104113101"><a name="p20414104113101"></a><a name="p20414104113101"></a>Service functionalities, all-scenario features, and mechanical power environment (MPE) and scenario-level DFX</p>
</td>
<td class="cellrowborder" valign="top" width="45.23452345234523%" headers="mcps1.2.4.1.3 "><p id="p5414841121013"><a name="p5414841121013"></a><a name="p5414841121013"></a>Devices close to real devices</p>
</td>
</tr>
<tr id="row10907635131015"><td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.2.4.1.1 "><p id="p19414134117104"><a name="p19414134117104"></a><a name="p19414134117104"></a>MediumTest</p>
</td>
<td class="cellrowborder" valign="top" width="35.17351735173517%" headers="mcps1.2.4.1.2 "><p id="p114141241141018"><a name="p114141241141018"></a><a name="p114141241141018"></a>Modules, subsystem functionalities after module integration, and DFX</p>
</td>
<td class="cellrowborder" valign="top" width="45.23452345234523%" headers="mcps1.2.4.1.3 "><p id="p14414941111015"><a name="p14414941111015"></a><a name="p14414941111015"></a>Single device that is actually used. You can perform message simulation, but do not mock functions.</p>
</td>
</tr>
<tr id="row1990713353100"><td class="cellrowborder" valign="top" width="19.591959195919593%" headers="mcps1.2.4.1.1 "><p id="p641414110109"><a name="p641414110109"></a><a name="p641414110109"></a>SmallTest</p>
</td>
<td class="cellrowborder" valign="top" width="35.17351735173517%" headers="mcps1.2.4.1.2 "><p id="p54141541181018"><a name="p54141541181018"></a><a name="p54141541181018"></a>Modules, classes, and functions</p>
</td>
<td class="cellrowborder" valign="top" width="45.23452345234523%" headers="mcps1.2.4.1.3 "><p id="p1841494131013"><a name="p1841494131013"></a><a name="p1841494131013"></a>Local PC. Use a large number of mocks to replace dependencies with other modules.</p>
</td>
</tr>
</tbody>
</table>

**Table  3**  Test types

<a name="table18811230124619"></a>
<table><thead align="left"><tr id="row48163019466"><th class="cellrowborder" valign="top" width="19.040000000000003%" id="mcps1.2.3.1.1"><p id="p1791784418465"><a name="p1791784418465"></a><a name="p1791784418465"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="80.96%" id="mcps1.2.3.1.2"><p id="p2917164444614"><a name="p2917164444614"></a><a name="p2917164444614"></a>Definition</p>
</th>
</tr>
</thead>
<tbody><tr id="row682630104615"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p1091784414469"><a name="p1091784414469"></a><a name="p1091784414469"></a>Function</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p16917344104618"><a name="p16917344104618"></a><a name="p16917344104618"></a>Tests the correctness of both service and platform functionalities provided by the tested object for end users or developers.</p>
</td>
</tr>
<tr id="row1821930154611"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p591714474612"><a name="p591714474612"></a><a name="p591714474612"></a>Performance</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p15917154410463"><a name="p15917154410463"></a><a name="p15917154410463"></a>Tests the processing capability of the tested object under specific preset conditions and load models. The processing capability is measured by the service volume that can be processed in a unit time, for example, call per second, frame per second, or event processing volume per second.</p>
</td>
</tr>
<tr id="row13821030104616"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p691711440467"><a name="p691711440467"></a><a name="p691711440467"></a>Power</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p159171544104616"><a name="p159171544104616"></a><a name="p159171544104616"></a>Tests the power consumption of the tested object in a certain period of time under specific preset conditions and load models.</p>
</td>
</tr>
<tr id="row6821330114618"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p13917164454612"><a name="p13917164454612"></a><a name="p13917164454612"></a>Reliability</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p11917194416465"><a name="p11917194416465"></a><a name="p11917194416465"></a>Tests the service performance of the tested object under common and uncommon input conditions, or specified service volume pressure and long-term continuous running pressure. The test covers stability, pressure handling, fault injection, and Monkey test times.</p>
</td>
</tr>
<tr id="row11821930184612"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p1691774474618"><a name="p1691774474618"></a><a name="p1691774474618"></a>Security</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><a name="ul112421652121513"></a><a name="ul112421652121513"></a><ul id="ul112421652121513"><li>Tests the capability of defending against security threats, including but not limited to unauthorized access, use, disclosure, damage, modification, and destruction, to ensure information confidentiality, integrity, and availability.</li><li>Tests the privacy protection capability to ensure that the collection, use, retention, disclosure, and disposal of users' private data comply with laws and regulations.</li><li>Tests the compliance with various security specifications, such as security design, security requirements, and security certification of the Ministry of Industry and Information Technology (MIIT).</li></ul>
</td>
</tr>
<tr id="row16825307467"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p129188444462"><a name="p129188444462"></a><a name="p129188444462"></a>Global</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p179186444465"><a name="p179186444465"></a><a name="p179186444465"></a>Tests the internationalized data and localization capabilities of the tested object, including multi-language display, various input/output habits, time formats, and regional features, such as currency, time, and culture taboos.</p>
</td>
</tr>
<tr id="row08211308464"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p191814447465"><a name="p191814447465"></a><a name="p191814447465"></a>Compatibility</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><a name="ul186961827111612"></a><a name="ul186961827111612"></a><ul id="ul186961827111612"><li>Tests backward compatibility of an application with its own data, the forward and backward compatibility with the system, and the compatibility with different user data, such as audio file content of the player and smart SMS messages.</li><li>Tests system backward compatibility with its own data and the compatibility of common applications in the ecosystem.</li><li>Tests software compatibility with related hardware.</li></ul>
</td>
</tr>
<tr id="row1782730124618"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p13918144134614"><a name="p13918144134614"></a><a name="p13918144134614"></a>User</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p1291844494611"><a name="p1291844494611"></a><a name="p1291844494611"></a>Tests user experience of the object in real user scenarios. All conclusions and comments should come from the users, which are all subjective evaluation in this case.</p>
</td>
</tr>
<tr id="row58243024617"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p1291884474614"><a name="p1291884474614"></a><a name="p1291884474614"></a>Standard</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p0918124424614"><a name="p0918124424614"></a><a name="p0918124424614"></a>Tests the compliance with industry and company-specific standards, protocols, and specifications. The standards here do not include any security standards that should be classified into the security test.</p>
</td>
</tr>
<tr id="row382830124619"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p119181044164619"><a name="p119181044164619"></a><a name="p119181044164619"></a>Safety</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p1291818443468"><a name="p1291818443468"></a><a name="p1291818443468"></a>Tests the safety property of the tested object to avoid possible hazards to personal safety, health, and the object itself.</p>
</td>
</tr>
<tr id="row1083153014465"><td class="cellrowborder" valign="top" width="19.040000000000003%" headers="mcps1.2.3.1.1 "><p id="p39187441469"><a name="p39187441469"></a><a name="p39187441469"></a>Resilience</p>
</td>
<td class="cellrowborder" valign="top" width="80.96%" headers="mcps1.2.3.1.2 "><p id="p891815444462"><a name="p891815444462"></a><a name="p891815444462"></a>Tests the resilience property of the tested object to ensure that it can withstand and maintain the defined running status (including downgrading) when being attacked, and recover from and adapt defense to the attacks to approach mission assurance.</p>
</td>
</tr>
</tbody>
</table>

## Test Case Development Guidelines<a name="section3695134065513"></a>

You should select the appropriate programming language and your target test framework to develop test cases for the devices to test.

**Table  4**  Test frameworks and test case languages for different devices

<a name="table4418343171415"></a>
<table><thead align="left"><tr id="row34183435145"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p941874311148"><a name="p941874311148"></a><a name="p941874311148"></a>Device Type</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1841804341413"><a name="p1841804341413"></a><a name="p1841804341413"></a>Test Framework</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p2418104311148"><a name="p2418104311148"></a><a name="p2418104311148"></a>Language</p>
</th>
</tr>
</thead>
<tbody><tr id="row8419164319148"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p7419194312143"><a name="p7419194312143"></a><a name="p7419194312143"></a>Mini-system devices</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10419124312145"><a name="p10419124312145"></a><a name="p10419124312145"></a>HCTest</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11419643191410"><a name="p11419643191410"></a><a name="p11419643191410"></a>C</p>
</td>
</tr>
<tr id="row141915438147"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p441911436141"><a name="p441911436141"></a><a name="p441911436141"></a>Small-system devices</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p541916432142"><a name="p541916432142"></a><a name="p541916432142"></a>HCPPTest</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p54191643131416"><a name="p54191643131416"></a><a name="p54191643131416"></a>C++</p>
</td>
</tr>
<tr id="row4419134341417"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p341964313143"><a name="p341964313143"></a><a name="p341964313143"></a>Standard-system devices</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10419443171416"><a name="p10419443171416"></a><a name="p10419443171416"></a>HJUnit and HCPPTest</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p9419143181414"><a name="p9419143181414"></a><a name="p9419143181414"></a>Java and C++</p>
</td>
</tr>
<tr id="row42451815115215"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p324511515528"><a name="p324511515528"></a><a name="p324511515528"></a>Large-system devices</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p724516151520"><a name="p724516151520"></a><a name="p724516151520"></a>HJUnit and HCPPTest</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p748417474533"><a name="p748417474533"></a><a name="p748417474533"></a>Java and C++</p>
</td>
</tr>
</tbody>
</table>

### C-based Test Case Development and Compilation \(for Mini-System Devices\)<a name="section1551164914237"></a>

**Developing test cases for mini-system devices**

The HCTest framework is used to support test cases developed with the C language. HCTest is enhanced and adapted based on the open-source test framework Unity.

1.  Access the  **test/xts/acts**  repository where the test cases will be stored.

    ```
    ├── acts
    │ └──subsystem_lite
    │ │ └── module_hal
    │ │ │ └── BUILD.gn
    │ │ │ └── src
    │ └──build_lite
    │ │ └── BUILD.gn
    ```

2.  Write the test case in the  **src**  directory.

    1 Import the test framework header file.

    ```
    #include "hctest.h"
    ```

    2. Use the  **LITE\_TEST\_SUIT**  macro to define names of the subsystem, module, and test suite.

    ```
    /**  
    * @brief  Registers a test suite named IntTestSuite.
    * @param  test Subsystem name
    * @param  example Module name
    * @param  IntTestSuite Test suite name
    */
    LITE_TEST_SUIT(test, example, IntTestSuite);
    ```

    3. Define Setup and TearDown.

    Format: Test suite name+Setup, Test suite name+TearDown.

    The Setup and TearDown functions must exist, but function bodies can be empty.

    4. Use the  **LITE\_TEST\_CASE**  macro to write the test case.

    Three parameters are involved: test suite name, test case name, and test case properties \(including type, granularity, and level\).

    ```
    LITE_TEST_CASE(IntTestSuite, TestCase001, Function | MediumTest | Level1) 
    {  
      // Do something 
    };
    ```

    5. Use the  **RUN\_TEST\_SUITE**  macro to register the test suite.

    ```
    RUN_TEST_SUITE(IntTestSuite);
    ```

3.  Create the configuration file \(**BUILD.gn**\) of the test module.

    Create a  **BUILD.gn**  \(example\) compilation file in each test module directory. Specify the name of the compiled static library and its dependent header file and library in the compilation file. The format is as follows:

    ```
    import("//test/xts/tools/lite/build/suite_lite.gni")
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

    You need to add the test module to the  **test/xts/acts/build\_lite/BUILD.gn**  script in the  **acts**  directory.

    ```
    lite_component("acts") {  
        ...
        if(board_name == "liteos_m") {
            features += [    
                ...
                "//xts/acts/subsystem_lite/module_hal:ActsDemoTest"
            ]    
        }
    }
    ```

5.  Run compilation commands.

    Test suites are compiled along with version compilation. The ACTS is compiled together with the debug version.

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >The ACTS compiles middleware as a static library, which will be linked to the image.


### C-based Test Case Execution \(for Mini-System Devices\)<a name="section10100701294"></a>

**Executing test cases for mini-system devices**

Burn the image into the development board.

**Executing the test**

1.  Use a serial port tool to log in to the development board and save information about the serial port.
2.  Restart the device and view serial port logs.

**Analyzing the test result**

View the serial port logs, whose format is as follows:

The log for each test suite starts with  **Start to run test suite:**  and ends with  **xx Tests xx Failures xx Ignored**.

## Repositories Involved<a name="section1371113476307"></a>

xts\_acts

xts\_tools

