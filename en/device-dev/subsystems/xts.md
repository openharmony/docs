# XTS<a name="EN-US_TOPIC_0000001126156429"></a>

-   [Introduction](#section465982318513)
-   [System Types](#section125090457443)
-   [Directory Structure](#section161941989596)
-   [Constraints](#section119744591305)
-   [Usage Guidelines](#section137768191623)
-   [Test Case Development Guidelines](#section3695134065513)
    -   [C-based Test Case Development and Compilation \(for the Mini System\)](#section198193336544)
    -   [C-based Test Case Execution \(for the Mini System\)](#section13820233175418)
    -   [C++-based Test Case Development and Compilation \(for Standard and Small Systems\)](#section3822123311540)
    -   [C++-based Test Case Execution \(for Standard and Small Systems\)](#section128222336544)
    -   [JavaScript-based Test Case Development \(for the Standard System\)](#section159801435165220)
    -   [JavaScript-based Test Case Packaging \(for the Standard System\)](#section445519106559)


## Introduction<a name="section465982318513"></a>

The X test suite \(XTS\) subsystem contains a set of OpenHarmony certification test suites, including the currently supported application compatibility test suite \(ACTS\) and the device compatibility test suite \(DCTS\) that will be supported in the future.

This subsystem contains the ACTS and  **tools**  software package.

-   The  **acts**  directory stores the source code and configuration files of ACTS test cases. The ACTS helps device vendors detect the software incompatibility as early as possible and ensures that the software is compatible to OpenHarmony during the entire development process.
-   The  **tools**  software package stores the test case development framework related to  **acts**.

## System Types<a name="section125090457443"></a>

OpenHarmony supports the following system types:

-   Mini system

    A mini system runs on the devices whose memory is greater than or equal to 128 KiB and that are equipped with MCU processors such as ARM Cortex-M and 32-bit RISC-V. This system provides multiple lightweight network protocols and graphics frameworks, and a wide range of read/write components for the IoT bus. Typical products include connection modules, sensors, and wearables for smart home.

-   Small system

    A small system runs on the devices whose memory is greater than or equal to 1 MiB and that are equipped with application processors such as ARM Cortex-A. This system provides higher security capabilities, standard graphics frameworks, and video encoding and decoding capabilities. Typical products include smart home IP cameras, electronic cat eyes, and routers, and event data recorders \(EDRs\) for smart travel.

-   Standard system

    A standard system runs on the devices whose memory is greater than or equal to 128 MiB and that are equipped with application processors such as ARM Cortex-A. This system provides a complete application framework supporting the enhanced interaction, 3D GPU, hardware composer, diverse components, and rich animations. This system applies to high-end refrigerator displays.


## Directory Structure<a name="section161941989596"></a>

```
/test/xts
├── acts                 # Test code
│   └── subsystem       # Source code of subsystem test cases for the standard system
│   └── subsystem_lite  # Source code of subsystems test cases for mini and small systems
│   └── BUILD.gn        # Build configuration of test cases for the standard system
│   └── build_lite      
│       └── BUILD.gn    # Build configuration of test cases for mini and small systems
└── tools                # Test tool code
```

## Constraints<a name="section119744591305"></a>

Test cases for the mini system must be developed based on C, and those for the small system must be developed based on C++.

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

You should select the appropriate programming language and your target test framework to develop test cases.

**Table  4**  Test frameworks and test case languages for different systems

<a name="table4418343171415"></a>
<table><thead align="left"><tr id="row34183435145"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p941874311148"><a name="p941874311148"></a><a name="p941874311148"></a>System</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p1841804341413"><a name="p1841804341413"></a><a name="p1841804341413"></a>Test Framework</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p2418104311148"><a name="p2418104311148"></a><a name="p2418104311148"></a>Language</p>
</th>
</tr>
</thead>
<tbody><tr id="row8419164319148"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p7419194312143"><a name="p7419194312143"></a><a name="p7419194312143"></a>Mini</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10419124312145"><a name="p10419124312145"></a><a name="p10419124312145"></a>HCTest</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p11419643191410"><a name="p11419643191410"></a><a name="p11419643191410"></a>C</p>
</td>
</tr>
<tr id="row141915438147"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p441911436141"><a name="p441911436141"></a><a name="p441911436141"></a>Small</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p541916432142"><a name="p541916432142"></a><a name="p541916432142"></a>HCPPTest</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p54191643131416"><a name="p54191643131416"></a><a name="p54191643131416"></a>C++</p>
</td>
</tr>
<tr id="row4419134341417"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p341964313143"><a name="p341964313143"></a><a name="p341964313143"></a>Standard</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p10419443171416"><a name="p10419443171416"></a><a name="p10419443171416"></a>HJSUnit and HCPPTest</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p9419143181414"><a name="p9419143181414"></a><a name="p9419143181414"></a>JavaScript and C++</p>
</td>
</tr>
</tbody>
</table>

### C-based Test Case Development and Compilation \(for the Mini System\)<a name="section198193336544"></a>

**Developing test cases for the mini system**

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

    Create a  **BUILD.gn**  \(example\) build file in each test module directory. Specify the name of the built static library and its dependent header file and library in the build file. The format is as follows:

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

4.  Add build options to the  **BUILD.gn**  file in the  **acts**  directory.

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

5.  Run build commands.

    Test suites are built along with version build. The ACTS is built together with the debug version.

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >The ACTS build middleware is a static library, which will be linked to the image.


### C-based Test Case Execution \(for the Mini System\)<a name="section13820233175418"></a>

**Executing test cases for the mini system**

Burn the image into the development board.

**Executing the test**

1.  Use a serial port tool to log in to the development board and save information about the serial port.
2.  Restart the device and view serial port logs.

**Analyzing the test result**

View the serial port logs, whose format is as follows:

The log for each test suite starts with  **Start to run test suite:**  and ends with  **xx Tests xx Failures xx Ignored**.

### C++-based Test Case Development and Compilation \(for Standard and Small Systems\)<a name="section3822123311540"></a>

**Developing test cases for small-system devices**  \(For examples of the standard system, go to the  **global/i18n\_standard directory**.\)

The HCPPTest framework is enhanced and adapted based on the open-source framework Googletest.

1.  Access the  **test/xts/acts**  repository where the test cases will be stored.

    ```
    ├── acts
    │ └──subsystem_lite
    │ │ └── module_posix
    │ │ │ └── BUILD.gn
    │ │ │ └── src
    │ └──build_lite
    │ │ └── BUILD.gn
    ```

2.  Write the test case in the  **src**  directory.

    1. Import the test framework header file.

    The following statement includes  **gtest.h**.

    ```
    #include "gtest/gtest.h"
    ```

    2. Define Setup and TearDown.

    ```
    using namespace std;
    using namespace testing::ext;
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

    3. Use the  **HWTEST**  or  **HWTEST\_F**  macro to write the test case.

    **HWTEST**: definition of common test cases, including the test suite name, test case name, and case annotation.

    **HWTEST\_F**: definition of SetUp and TearDown test cases, including the test suite name, test case name, and case annotation.

    Three parameters are involved: test suite name, test case name, and test case properties \(including type, granularity, and level\).

    ```
    HWTEST_F(TestSuite, TestCase_0001, Function | MediumTest | Level1) {
    // Do something
    }
    ```

3.  Create a configuration file \(**BUILD.gn**\) of the test module.

    Create a  **BUILD.gn**  build file in each test module directory. Specify the name of the built static library and its dependent header file and library in the build file. Each test module is independently built into a  **.bin**  executable file, which can be directly pushed to the development board for testing.

    Example:

    ```
    import("//test/xts/tools/lite/build/suite_lite.gni")
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

4.  Add build options to the  **BUILD.gn**  file in the  **acts**  directory.

    Add the test module to the  **test/xts/acts/build\_lite/BUILD.gn**  script in the  **acts**  directory.

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

5.  Run build commands.

    Test suites are built along with the version build. The ACTS is built together with the debug version.

    >![](public_sys-resources/icon-note.gif) **NOTE:** 
    >The ACTS for the small system is independently built to an executable file \(.bin\) and archived in the  **suites\\acts**  directory of the build result.


### C++-based Test Case Execution \(for Standard and Small Systems\)<a name="section128222336544"></a>

**Executing test cases for the small system**

Currently, test cases are shared by the NFS and mounted to the development board for execution.

**Setting up the environment**

1.  Use a network cable or wireless network to connect the development board to your PC.
2.  Configure the IP address, subnet mask, and gateway for the development board. Ensure that the development board and the PC are in the same network segment.
3.  Install and register the NFS server on the PC and start the NFS service.
4.  Run the  **mount**  command for the development board to ensure that the development board can access NFS shared files on the PC.

    Format:  **mount** _NFS server IP address_**:/**_NFS shared directory_ **/**_development board directory_ **nfs**

    Example:

    ```
    mount 192.168.1.10:/nfs /nfs nfs
    ```


**Executing test cases**

Execute  **ActsDemoTest.bin**  to trigger test case execution, and analyze serial port logs generated after the execution is complete.

### JavaScript-based Test Case Development \(for the Standard System\)<a name="section159801435165220"></a>

The HJSUnit framework is used to support automated test of OpenHarmony apps that are developed using the JavaScript language based on the JS application framework.

**Basic syntax of test cases**

The test cases are developed with the JavaScript language and must meet the programming specifications of the language.

**Table  5** 

<a name="table13980103565212"></a>
<table><thead align="left"><tr id="row1098093545218"><th class="cellrowborder" valign="top" width="17.92179217921792%" id="mcps1.2.4.1.1"><p id="p49811235135214"><a name="p49811235135214"></a><a name="p49811235135214"></a>Syntax</p>
</th>
<th class="cellrowborder" valign="top" width="68.88688868886888%" id="mcps1.2.4.1.2"><p id="p898183565220"><a name="p898183565220"></a><a name="p898183565220"></a>Description</p>
</th>
<th class="cellrowborder" valign="top" width="13.19131913191319%" id="mcps1.2.4.1.3"><p id="p17981143512526"><a name="p17981143512526"></a><a name="p17981143512526"></a>Mandatory</p>
</th>
</tr>
</thead>
<tbody><tr id="row1598183515528"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p139810358527"><a name="p139810358527"></a><a name="p139810358527"></a>beforeAll</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p198111352526"><a name="p198111352526"></a><a name="p198111352526"></a>Presets a test-suite-level action executed only once before all test cases are executed. You can pass the action function as the only parameter.</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p298114355529"><a name="p298114355529"></a><a name="p298114355529"></a>No</p>
</td>
</tr>
<tr id="row11981103512529"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p20981135135215"><a name="p20981135135215"></a><a name="p20981135135215"></a>afterAll</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p39811935115217"><a name="p39811935115217"></a><a name="p39811935115217"></a>Presets a test-suite-level clear action executed only once after all test cases are executed. You can pass the clear function as the only parameter.</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p998110354527"><a name="p998110354527"></a><a name="p998110354527"></a>No</p>
</td>
</tr>
<tr id="row1298116359526"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p898112359526"><a name="p898112359526"></a><a name="p898112359526"></a>beforeEach</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p149811335175215"><a name="p149811335175215"></a><a name="p149811335175215"></a>Presets a test-case-level action executed before each test case is executed. The number of execution times is the same as the number of test cases defined by <strong id="b32523248388"><a name="b32523248388"></a><a name="b32523248388"></a>it</strong>. You can pass the action function as the only parameter.</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p13981133585212"><a name="p13981133585212"></a><a name="p13981133585212"></a>No</p>
</td>
</tr>
<tr id="row6982435115219"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p19982133517525"><a name="p19982133517525"></a><a name="p19982133517525"></a>afterEach</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p1398213575219"><a name="p1398213575219"></a><a name="p1398213575219"></a>Presets a test-case-level clear action executed after each test case is executed. The number of execution times is the same as the number of test cases defined by <strong id="b10590142313399"><a name="b10590142313399"></a><a name="b10590142313399"></a>it</strong>. You can pass the clear function as the only parameter.</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p159821535195219"><a name="p159821535195219"></a><a name="p159821535195219"></a>No</p>
</td>
</tr>
<tr id="row16982143513521"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p598203510527"><a name="p598203510527"></a><a name="p598203510527"></a>describe</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p5982123595215"><a name="p5982123595215"></a><a name="p5982123595215"></a>Defines a test suite. You can pass two parameters: test suite name and test suite function. The <strong id="b7320205019400"><a name="b7320205019400"></a><a name="b7320205019400"></a>describe</strong> statement supports nesting. You can use <strong id="b138214222410"><a name="b138214222410"></a><a name="b138214222410"></a>beforeall</strong>, <strong id="b18677102314115"><a name="b18677102314115"></a><a name="b18677102314115"></a>beforeEach</strong>, <strong id="b1353142514113"><a name="b1353142514113"></a><a name="b1353142514113"></a>afterEach</strong>, and <strong id="b131041629204111"><a name="b131041629204111"></a><a name="b131041629204111"></a>afterAll</strong> in each <strong id="b590433484116"><a name="b590433484116"></a><a name="b590433484116"></a>describe</strong> statement.</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p898217352527"><a name="p898217352527"></a><a name="p898217352527"></a>Yes</p>
</td>
</tr>
<tr id="row6982113518526"><td class="cellrowborder" valign="top" width="17.92179217921792%" headers="mcps1.2.4.1.1 "><p id="p17982123510526"><a name="p17982123510526"></a><a name="p17982123510526"></a>it</p>
</td>
<td class="cellrowborder" valign="top" width="68.88688868886888%" headers="mcps1.2.4.1.2 "><p id="p598211352522"><a name="p598211352522"></a><a name="p598211352522"></a>Defines a test case. You can pass three parameters: test case name, filter parameter, and test case function.</p>
<p id="p5205769588"><a name="p5205769588"></a><a name="p5205769588"></a>Usage of the filter parameter:</p>
<p id="p1545919528618"><a name="p1545919528618"></a><a name="p1545919528618"></a>The value of the filter parameter is a 32-bit integer. Setting different bits to <strong id="b045919521765"><a name="b045919521765"></a><a name="b045919521765"></a>1</strong> means different configurations:</p>
<a name="ul6932113319395"></a><a name="ul6932113319395"></a><ul id="ul6932113319395"><li>bit 0: whether the filter parameter takes effect. <strong id="b1193293318395"><a name="b1193293318395"></a><a name="b1193293318395"></a>1</strong> means that the test case is used for the function test and other settings of the parameter do not take effect.</li><li>Bits 0-10: test case categories</li><li>Bits 16-18: test case scales</li><li>Bits 24-28: test levels</li></ul>
<p id="p7965165151011"><a name="p7965165151011"></a><a name="p7965165151011"></a><strong id="b15148755145114"><a name="b15148755145114"></a><a name="b15148755145114"></a>Test case categories</strong>: Bits 0-10 indicate FUNCTION (function test), PERFORMANCE (performance test), POWER (power consumption test), RELIABILITY (reliability test), SECURITY (security compliance test), GLOBAL (integrity test), COMPATIBILITY (compatibility test), USER (user test), STANDARD (standard test), SAFETY (security feature test), and RESILIENCE (resilience test), respectively.</p>
<p id="p199651555102"><a name="p199651555102"></a><a name="p199651555102"></a><strong id="b135908568519"><a name="b135908568519"></a><a name="b135908568519"></a>Test case scales</strong>: Bits 16-18 indicate SMALL (small-scale test), MEDIUM (medium-scale test), and LARGE (large-scale test), respectively.</p>
<p id="p296545151020"><a name="p296545151020"></a><a name="p296545151020"></a><strong id="b12181058125111"><a name="b12181058125111"></a><a name="b12181058125111"></a>Test levels</strong>: Bits 24-28 indicate LEVEL0 (level-0 test), LEVEL1 (level-1 test), LEVEL2 (level-2 test), LEVEL3 (level-3 test), and LEVEL4 (level-4 test), respectively.</p>
</td>
<td class="cellrowborder" valign="top" width="13.19131913191319%" headers="mcps1.2.4.1.3 "><p id="p17601752115716"><a name="p17601752115716"></a><a name="p17601752115716"></a>Yes</p>
</td>
</tr>
</tbody>
</table>

Use the standard syntax of Jasmine to write test cases. The ES6 specification is supported.

1.  Store the test cases in the  **entry/src/main/js/test**  directory, whose structure is as follows:

    ```
    ├── BUILD.gn   
    │ └──entry
    │ │ └──src
    │ │ │ └──main
    │ │ │ │ └──js
    │ │ │ │ │ └──default               
    │ │ │ │ │ │ └──pages
    │ │ │ │ │ │ │ └──index             
    │ │ │ │ │ │ │ │ └──index.js        # Entry file
     │ │ │ │ │ └──test                  # Test code
    │ │ │ └── resources                # HAP resources
    │ │ │ └── config.json              # HAP configuration file
    ```

2.  Start the JS test framework and load test cases. The following is an example for  **index.js**.

    ```
    // Start the JS test framework and load test cases.
    import {Core, ExpectExtend} from 'deccjsunit/index'
    
    export default {
        data: {
            title: ""
        },
        onInit() {
            this.title = this.$t('strings.world');
        },
        onShow() {
            console.info('onShow finish')
            const core = Core.getInstance()
            const expectExtend = new ExpectExtend({
                'id': 'extend'
            })
            core.addService('expect', expectExtend)
            core.init()
            const configService = core.getDefaultService('config')
            configService.setConfig(this)
            require('../../../test/List.test')
            core.execute()
        },
        onReady() {
        },
    }
    ```

3.  Write a unit test case by referring to the following example:

    ```
    // Use HJSUnit to perform the unit test.
    describe('appInfoTest', function () {    
        it('app_info_test_001', 0, function () {
            var info = app.getInfo()
            expect(info.versionName).assertEqual('1.0')
            expect(info.versionCode).assertEqual('3')
        })
    }) 
    ```


### JavaScript-based Test Case Packaging \(for the Standard System\)<a name="section445519106559"></a>

For details about how to build a HAP, see the JS application development guide of the standard system  [Building and Creating HAPs](https://developer.harmonyos.com/en/docs/documentation/doc-guides/build_overview-0000001055075201).

