# Development Self-Test Framework User Guide


## Overview

OpenHarmony provides you with a comprehensive development self-test framework **developer_test**. As a part of the OpenHarmony test toolset, the development self-test framework is provided for you to test the development by yourself. You can develop relevant test cases based on your test requirements to discover defects at the development phase, greatly improving the code quality.

This document describes how to use the development self-test framework of OpenHarmony.


### Introduction

After adding or modifying code, OpenHarmony developers want to quickly verify whether the modified code functions properly, and the system already has a large number of automated test cases of existing functions, such as TDD cases and XTS cases. The development self-test framework aims to help you improve your self-test efficiency so that you can quickly execute the specified automated test cases and conducting development tests at the development phase.


### Constraints

When executing test cases using the framework, you must connect to the OpenHarmony device in advance.


## Environment Preparations

The development self-test framework depends on the Python environment. It is required that the Python version be 3.7.5 or later. Before using the framework, you can refer to the following document for configuration.

Click [here](https://gitee.com/openharmony/docs/blob/master/en/device-dev/get-code/sourcecode-acquire.md) to obtain the source code.

### Basic Self-Test Framework Environment

| Environment Dependency         | Version                                                    | Description                                                    |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Operating system         | Ubuntu 18.04 or later                                           | Code compilation environment.                                                |
| Linux extension component| libreadline-dev                                              | Plugin used to read commands.                                              |
| python            | 3.7.5 or later                                             | Language used by the test framework.                                                |
| Python plugins       | pyserial 3.3 or later, paramiko 2.7.1 or later, setuptools 40.8.0 or later, and rsa4.0 or later| - **pserial**: supports Python serial port communication.<br>- **paramiko**: allows Python to use SSH. <br>- **setuptools**: allows Python packages to be created and distributed easily. <br>- **rsa**: implements RSA encryption in Python.|
| NFS Server        | haneWIN NFS Server 1.2.50 or later or NFS v4 or later            | Devices can be connected using serial ports. Mini- and small-system devices are used.                    |
| HDC               | 1.1.0                                                        | A tool that enables devices to be connected through the HarmonyOS Device Connector (HDC).                                         |



1. Run the following command to install the Linux extended component readline:

    ```bash
    sudo apt-get install libreadline-dev
    ```
    The installation is successful if the following information is displayed:
    ```
    Reading package lists... Done
    Building dependency tree
    Reading state information... Done
    libreadline-dev is already the newest version (7.0-3).
    0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
    ```

2. Run the following command to install the **setuptools** plugin:
    ```bash
    pip3 install setuptools
    ```
    The installation is successful if the following information is displayed:
    ```
    Requirement already satisfied: setuptools in d:\programs\python37\lib\site-packages (41.2.0)
    ```

3. Run the following command to install the **paramiko** plugin:
    ```bash
    pip3 install paramiko
    ```
    The installation is successful if the following information is displayed:
    ```
    Installing collected packages: pycparser, cffi, pynacl, bcrypt, cryptography, paramiko
    Successfully installed bcrypt-3.2.0 cffi-1.14.4 cryptography-3.3.1 paramiko-2.7.2 pycparser-2.20 pynacl-1.4.0
    ```

4. Run the following command to install the **ras** plugin:
    ```bash
    pip3 install rsa
    ```
    The installation is successful if the following information is displayed:
    ```
    Installing collected packages: pyasn1, rsa
    Successfully installed pyasn1-0.4.8 rsa-4.7
    ```

5. Run the following command to install the **pyserial** plugin:
    ```bash
    pip3 install pyserial
    ```
    The installation is successful if the following information is displayed:
    ```
    Requirement already satisfied: pyserial in d:\programs\python37\lib\site-packages\pyserial-3.4-py3.7.egg (3.4)
    ```

6. Install the NFS server if the device outputs results only through the serial port.

    > This step is applicable to small-system or mini-system devices.

    - Windows OS: Install the **haneWIN NFS Server1.2.50** package.
    - Linux OS: Run the following command to install the NFS server:
    ```bash
    sudo apt install nfs-kernel-server
    ```
    The installation is successful if the following information is displayed:
    ```
    Reading package lists... Done
    Building dependency tree
    Reading state information... Done
    nfs-kernel-server is already the newest version (1:1.3.4-2.1ubuntu5.3).
    0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
    ```

7. If the device supports HDC connection, install the HDC tool. For details about the installation process, see [HDC-OpenHarmony device connector](https://gitee.com/openharmony/developtools_hdc_standard/blob/master/README.md).


### Environment Dependency Check

| Check Item                                            | Operation                                               | Requirement                 |
| -------------------------------------------------- | --------------------------------------------------- | ------------------------- |
| Check whether Python is installed successfully.                                | Run the **python --version** command.               | The Python version is 3.7.5 or later.      |
| Check whether Python plugins are successfully installed.                        | Go to the **test/developertest** directory and run **start.bat** or **start.sh**.| The **>>>** prompt is displayed.|
| Check the NFS server status (for the devices that support only serial port output).| Log in to the development board through the serial port and run the **mount** command to mount the NFS.           | The file directory can be mounted.   |
| Check whether the HDC is successfully installed.                                   | Run the **hdc_std -v** command.                     | The HDC version is 1.1.0 or later.      |


## Test Case Preparation

The test framework supports multiple types of tests and provides different test case templates for them._

**TDD Test (C++)**

Naming rules for source files

The source file name of test cases must be the same as that of the test suite. The file names must use lowercase letters and in the *Function*_*Sub-function*_**test** format. More specific sub-functions can be added as required.
Example:
```
calculator_sub_test.cpp
```

Test case example
```c++
/*
 * Copyright (c) 2021 XXXX Device Co., Ltd.
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

#include "calculator.h"
#include <gtest/gtest.h>

using namespace testing::ext;

class CalculatorSubTest : public testing::Test {
public:
    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();
};

void CalculatorSubTest::SetUpTestCase(void)
{
    // Set a setup function, which will be called before all test cases.
}

void CalculatorSubTest::TearDownTestCase(void)
{
    // Set a teardown function, which will be called after all test cases.
}

void CalculatorSubTest::SetUp(void)
{
    // Set a setup function, which will be called before all test cases.
}

void CalculatorSubTest::TearDown(void)
{
    // Set a teardown function, which will be called after all test cases.
}

/**
 * @tc.name: integer_sub_001
 * @tc.desc: Verify the sub function.
 * @tc.type: FUNC
 * @tc.require: issueNumber
 */
HWTEST_F(CalculatorSubTest, integer_sub_001, TestSize.Level1)
{
    // Step 1 Call the function to obtain the test result.
    int actual = Sub(4, 0);

    // Step 2 Use an assertion to compare the obtained result with the expected result.
    EXPECT_EQ(4, actual);
}
```
The procedure is as follows:

1. Add comment information to the test case file header.

```
/*
 * Copyright (c) 2021 XXXX Device Co., Ltd.
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
```

2. Add the test framework header file and namespace.

```c++
#include <gtest/gtest.h>

using namespace testing::ext;
```

3. Add the header file of the test class.

```c++
#include "calculator.h"
```

4. Define the test suite (test class).

```c++
class CalculatorSubTest : public testing::Test {
public:
    static void SetUpTestCase(void);
    static void TearDownTestCase(void);
    void SetUp();
    void TearDown();
};

void CalculatorSubTest::SetUpTestCase(void)
{
    // Set a setup function, which will be called before all test cases.
}

void CalculatorSubTest::TearDownTestCase(void)
{
    // Set a teardown function, which will be called after all test cases.
}

void CalculatorSubTest::SetUp(void)
{
    // Set a setup function, which will be called before all test cases.
}

void CalculatorSubTest::TearDown(void)
{
    // Set a teardown function, which will be called after all test cases.
}==
```
> **NOTE**
>
> When defining a test suite, ensure that the test suite name is the same as the target to build and uses the upper camel case style.

5. Add implementation of the test cases, including test case comments and logic.

```c++
/**
 * @tc.name: integer_sub_001
 * @tc.desc: Verify the sub function.
 * @tc.type: FUNC
 * @tc.require: issueNumber
 */
HWTEST_F(CalculatorSubTest, integer_sub_001, TestSize.Level1)
{
    // Step 1 Call the function to obtain the test result.
    int actual = Sub(4, 0);

    // Step 2 Use an assertion to compare the obtained result with the expected result.
    EXPECT_EQ(4, actual);
}
```
> **NOTE**
>
> @tc.require: The format must be started with **AR/SR** or **issue**, for example, **issueI56WJ7**.

The following test case templates are provided for your reference.

| Type           | Description                                            |
| --------------- | ------------------------------------------------ |
| HWTEST(A,B,C)   | Use this template if the test case execution does not depend on setup or teardown.          |
| HWTEST_F(A,B,C) | Use this template if the test case execution (excluding parameters) depends on setup or teardown.|
| HWTEST_P(A,B,C) | Use this template if the test case execution (including parameters) depends on setup or teardown.    |

In the template names:

- **A** indicates the test suite name.

- **B** indicates the test case name, which is in the *Function*_*No.* format. The *No.* is a three-digit number starting from **001**.

- *C* indicates the test case level. There are five test case levels: guard-control level 0 and non-guard-control level 1 to level 4. Of levels 1 to 4, a smaller value indicates a more important function verified by the test case.


**NOTE**

- The expected result of each test case must have an assertion.

- The test case level must be specified.

- It is recommended that the test be implemented step by step according to the template.

- The comment must contain the test case name, description, type, and requirement number, which are in the @tc.*xxx*: *value* format. The test case type @**tc.type** can be any of the following:


| Test Case Type| Code|
| ------------ | -------- |
| Function test    | FUNC     |
| Performance test    | PERF     |
| Reliability test  | RELI     |
| Security test    | SECU     |
| Fuzzing test    | FUZZ     |

**TDD Test (JS)**

- Naming rules for source files


The source file name of a test case must be in the *Function**Sub-function***Test** format, and each part must use the upper camel case style. More specific sub-functions can be added as required.
Example:
```
AppInfoTest.js
```

- Test case example

```js
/*
 * Copyright (C) 2021 XXXX Device Co., Ltd.
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
import app from '@system.app'

import {describe, beforeAll, beforeEach, afterEach, afterAll, it, expect} from 'deccjsunit/index'

describe("AppInfoTest", function () {
    beforeAll(function() {
        // Set a setup function, which will be called before all test cases.
         console.info('beforeAll caled')
    })
    
    afterAll(function() {
         // Set a teardown function, which will be called after all test cases.
         console.info('afterAll caled')
    })
    
    beforeEach(function() {
        // Set a setup function, which will be called before all test cases.
         console.info('beforeEach caled')
    })
    
    afterEach(function() {
        // Set a teardown function, which will be called after all test cases.
         console.info('afterEach caled')
    })

    /*
     * @tc.name:appInfoTest001
     * @tc.desc:verify app info is not null
     * @tc.type: FUNC
     * @tc.require: issueNumber
     */
    it("appInfoTest001", 0, function () {
        // Step 1 Call the function to obtain the test result.
        var info = app.getInfo()

        // Step 2 Use an assertion to compare the obtained result with the expected result.
        expect(info != null).assertEqual(true)
    })
})
```
The procedure is as follows:
1. Add comment information to the test case file header.
    ```
    /*
     * Copyright (C) 2021 XXXX Device Co., Ltd.
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
    ```
2. Import the APIs and JSUnit test library to test.
    ```js
    import app from '@system.app'
    
    import {describe, beforeAll, beforeEach, afterEach, afterAll, it, expect} from 'deccjsunit/index'
    ```
3. Define the test suite (test class).
    ```js
    describe("AppInfoTest", function () {
        beforeAll(function() {
            // Set a setup function, which will be called before all test cases.
             console.info('beforeAll caled')
        })
        
        afterAll(function() {
             // Set a teardown function, which will be called after all test cases.
             console.info('afterAll caled')
        })
        
        beforeEach(function() {
            // Set a setup function, which will be called before all test cases.
             console.info('beforeEach caled')
        })
        
        afterEach(function() {
            // Set a teardown function, which will be called after all test cases.
             console.info('afterEach caled')
        })
    ```
4. Add implementation of the test cases.
    ```JS
    /*
     * @tc.name:appInfoTest001
     * @tc.desc:verify app info is not null
     * @tc.type: FUNC
     * @tc.require: issueNumber
     */
     it("appInfoTest001", 0, function () {
        // Step 1 Call the function to obtain the test result.
        var info = app.getInfo()
    
        // Step 2 Use an assertion to compare the obtained result with the expected result.
        expect(info != null).assertEqual(true)
     })
    ```
    > **NOTE**
    >
    > @tc.require: The format must be started with **issue**, for example, **issueI56WJ7**.

**Fuzzing Test**

[Fuzzing case specifications](https://gitee.com/openharmony/test_developertest/blob/master/libs/fuzzlib/README_zh.md)


**Benchmark Test**

[Benchmark case specifications](https://gitee.com/openharmony/test_developertest/blob/master/libs/benchmark/README_zh.md)

## **Test Case Building**

When a test case is executed, the test framework searches for the build file of the test case in the test case directory and builds the test case located. The following describes how to write build files (GN files) in different programming languages.

**TDD Test**

The following provides templates for different languages for your reference.

- **Test case build file example (C++)**

```
# Copyright (c) 2021 XXXX Device Co., Ltd.

import("//build/test.gni")

module_output_path = "developertest/calculator"

config("module_private_config") {
  visibility = [ ":*" ]

  include_dirs = [ "../../../include" ]
}

ohos_unittest("CalculatorSubTest") {
  module_out_path = module_output_path

  sources = [
    "../../../include/calculator.h",
    "../../../src/calculator.cpp",
  ]

  sources += [ "calculator_sub_test.cpp" ]

  configs = [ ":module_private_config" ]

  deps = [ "//third_party/googletest:gtest_main" ]
}

group("unittest") {
  testonly = true
  deps = [":CalculatorSubTest"]
}
```
The procedure is as follows:

1. Add comment information for the file header.
    ```
    # Copyright (c) 2021 XXXX Device Co., Ltd.
    ```
2. Import the build template.
    ```
    import("//build/test.gni")
    ```
3. Specify the file output path.
  ```
  module_output_path = "developertest/calculator"
  ```
  > **NOTE**<br>The output path is ***Part name*/*Module name***.

4. Configure the directories for dependencies.

  ```
  config("module_private_config") {
    visibility = [ ":*" ]
     
    include_dirs = [ "../../../include" ]
  }
  ```
  > **NOTE**
  >
  > Generally, the dependency directories are configured here and directly referenced in the build script of the test case.

5. Set the output build file for the test cases.

  ```
  ohos_unittest("CalculatorSubTest") {
  }
  ```
6. Write the build script (add the source file, configuration, and dependencies) for the test cases.
  ```
  ohos_unittest("CalculatorSubTest") {
    module_out_path = module_output_path
    sources = [
      "../../../include/calculator.h",
      "../../../src/calculator.cpp",
      "../../../test/calculator_sub_test.cpp"
    ]
    sources += [ "calculator_sub_test.cpp" ]
    configs = [ ":module_private_config" ]
    deps = [ "//third_party/googletest:gtest_main" ]
  }
  ```

    > **NOTE**
    >
    > Set the test type based on actual requirements. The following test types are available:
    >
    > - **ohos_unittest**: unit test
    > - **ohos_moduletest**: module test
    > - **ohos_systemtest**: system test
    > - **ohos_performancetest**: performance test
    > - **ohos_securitytest**: security test
    > - **ohos_reliabilitytest**: reliability test
    > - **ohos_distributedtest**: distributed test

7. Group the test case files by test type.

  ```
  group("unittest") {
    testonly = true
    deps = [":CalculatorSubTest"]
  }
  ```
  > **NOTE**
  >
  > Grouping test cases by test type allows you to execute a specific type of test cases when required.

- **Test case build file example (JavaScript)**

```
# Copyright (C) 2021 XXXX Device Co., Ltd.

import("//build/test.gni")

module_output_path = "developertest/app_info"

ohos_js_unittest("GetAppInfoJsTest") {
  module_out_path = module_output_path

  hap_profile = "./config.json"
  certificate_profile = "//test/developertest/signature/openharmony_sx.p7b"
}

group("unittest") {
  testonly = true
  deps = [ ":GetAppInfoJsTest" ]
}
```

The procedure is as follows:

1. Add comment information for the file header.

```
# Copyright (C) 2021 XXXX Device Co., Ltd.
```

2. Import the build template.

```
import("//build/test.gni")
```

3. Specify the file output path.

```
module_output_path = "developertest/app_info"
```
> **NOTE**
>
> The output path is ***Part name*/*Module name***.

4. Set the output build file for the test cases.

```
ohos_js_unittest("GetAppInfoJsTest") {
}
```
> **NOTE**
> - Use the **ohos_js_unittest** template to define the JavaScript test suite. Pay attention to the difference between JavaScript and C++.
> - The file generated for the JavaScript test suite must be in .hap format and named after the test suite name defined here. The test suite name must end with **JsTest**.

5. Configure the **config.json** file and signature file, which are mandatory.

```
ohos_js_unittest("GetAppInfoJsTest") {
  module_out_path = module_output_path
   
  hap_profile = "./config.json"
  certificate_profile = "//test/developertest/signature/openharmony_sx.p7b"
}
```
**config.json** is the configuration file required for HAP build. You need to set **target** based on the tested SDK version. Default values can be retained for other items. The following is an example:

```json
{
  "app": {
    "bundleName": "com.example.myapplication",
    "vendor": "example",
    "version": {
      "code": 1,
      "name": "1.0"
    },
    "apiVersion": {
           "compatible": 4,
         "target": 5     // Set it based on the tested SDK version. In this example, SDK5 is used.
    }
  },
  "deviceConfig": {},
  "module": {
    "package": "com.example.myapplication",
    "name": ".MyApplication",
    "deviceType": [
      "phone"
    ],
    "distro": {
      "deliveryWithInstall": true,
      "moduleName": "entry",
      "moduleType": "entry"
    },
    "abilities": [
      {
      "skills": [
          {
            "entities": [
              "entity.system.home"
            ],
            "actions": [
              "action.system.home"
            ]
          }
        ],
        "name": "com.example.myapplication.MainAbility",
        "icon": "$media:icon",
        "description": "$string:mainability_description",
        "label": "MyApplication",
        "type": "page",
        "launchType": "standard"
      }
    ],
    "js": [
      {
        "pages": [
          "pages/index/index"
        ],
        "name": "default",
          "window": {
             "designWidth": 720,
             "autoDesignWidth": false
          }
        }
      ]
    }
  }
```

6. Group the test case files by test type.

```
group("unittest") {
  testonly = true
  deps = [ ":GetAppInfoJsTest" ]
}
```
> **NOTE**
>
> Grouping test cases by test type allows you to execute a specific type of test cases when required.

**Fuzzing Test**

[Fuzzing case specifications](https://gitee.com/openharmony/test_developertest/blob/master/libs/fuzzlib/README_zh.md)

**Benchmark Test**

[Benchmark case specifications](https://gitee.com/openharmony/test_developertest/blob/master/libs/benchmark/README_zh.md)
      

**Configuring ohos.build**

Configure the part build file to associate with specific test cases.
```
"partA": {
    "module_list": [
          
    ],
    "inner_list": [
          
    ],
    "system_kits": [
          
    ],
    "test_list": [ // Test under configuration module calculator.
      "//system/subsystem/partA/calculator/test:unittest",  
      "//system/subsystem/partA/calculator/test:fuzztest",
      "//system/subsystem/partA/calculator/test:benchmarktest"
 }
```
> **NOTE**<br>**test_list** contains the test cases of the corresponding module.

## Configuring Test Resources

Test resources include external file resources, such as image files, video files, and third-party libraries, required for test case execution.

Perform the following steps:

1. Create a **resource** directory under the **test** directory of the part, create a corresponding module directory under the **resource** directory, and store the resource files required in this module directory.

2. In the module directory under **resource**, create the **ohos_test.xml** file in the following format:

```xml
<?xml version="1.0" encoding="UTF-8"?>
<configuration ver="2.0">
    <target name="CalculatorSubTest">
        <preparer>
            <option name="push" value="test.jpg -> /data/test/resource" src="res"/>
            <option name="push" value="libc++.z.so -> /data/test/resource" src="out"/>
        </preparer>
    </target>
</configuration>
```

3. In the build file of the test cases, configure **resource_config_file** to point to the resource file **ohos_test.xml**.

```
ohos_unittest("CalculatorSubTest") {
  resource_config_file = "//system/subsystem/partA/test/resource/calculator/ohos_test.xml"
}
```
>**NOTE**
>- **target_name** indicates the test suite name defined in the **BUILD.gn** file in the **test** directory. **preparer** indicates the action to perform before the test suite is executed.
>- **src="res"** indicates that the test resources are in the **resource** directory under the **test** directory. **src="out"** indicates that the test resources are in the **out/release/$(*part*)** directory.

## Test Case Execution

### Configuration File

Before executing test cases, you need to modify the configuration based on the device used.

#### Modifying user_config.xml
```xml
<user_config>
  <build>
    <!-- Whether to build a demo case. The default value is false. If a demo case is required, change the value to true. -->
    <example>false</example>
    <!-- Whether to build the version. The default value is false. -->
    <version>false</version>
    <!-- Whether to build the test cases. The default value is true. If the build is already complete, change the value to false before executing the test cases.-->
    <testcase>true</testcase>
	<!--When compiling test cases, select whether the target CPU is of the 64-bit or 32-bit. The default value is null (32-bit). You can select arm64. -->
    <parameter>
       <target_cpu></target_cpu>
    </parameter>
  </build>
  <environment>
    <!-- Configure the IP address and port number of the remote server to support connection to the device through the OpenHarmony Device Connector (HDC).-->
    <device type="usb-hdc">
      <ip></ip>
      <port></port>
      <sn></sn>
    </device>
    <!-- Configure the serial port information of the device to enable connection through the serial port.-->
    <device type="com" label="ipcamera">
      <serial>
        <com></com>
        <type>cmd</type>
        <baud_rate>115200</baud_rate>
        <data_bits>8</data_bits>
        <stop_bits>1</stop_bits>
        <timeout>1</timeout>
      </serial>
    </device>
  </environment>
  <!-- Configure the test case path. If the test cases have not been built (<testcase> is true), leave this parameter blank. If the build is complete, enter the path of the test cases.-->
  <test_cases>
    <dir></dir>
  </test_cases>
  <!-- Configure the coverage output path.-->
  <coverage>
    <outpath></outpath>
  </coverage>
  <!-- Configure the NFS mount information when the tested device supports only the serial port connection. Specify the NFS mapping path. host_dir indicates the NFS directory on the PC, and board_dir indicates the directory created on the board. -->
  <NFS>
    <host_dir></host_dir>
    <mnt_cmd></mnt_cmd>
    <board_dir></board_dir>
  </NFS>
</user_config>
```
>**NOTE**
>
>If HDC is connected to the device before the test cases are executed, you only need to configure the device IP address and port number, and retain the default settings for other parameters.

### Command Description

1. Start the test framework.
	```
	start.bat
	```
2. Select the product.

    After the test framework starts, you are asked to select a product. Select the development board to test.

	If you need to manually add a product, add it within the **\<productform\>** tag to **config/framework_config.xml**.

3. Execute test cases.

    Run the following command to execute test cases:
    ```
    run -t UT -ts CalculatorSubTest -tc interger_sub_00l
    ```
    In the command:
    ```
    -**t [TESTTYPE]**: specifies the test type, which can be **UT**, **MST**, **ST**, **PERF**, **FUZZ**, or **BENCHMARK**. This parameter is mandatory.
    -**tp [TESTPART]**: specifies the part to test. This parameter can be used independently.
    -**tm [TESTMODULE]**: specifies the module to test. This parameter must be specified together with **-tp**.
    -**ts [TESTSUITE]**: specifies a test suite. This parameter can be used independently.
    -**tc [TESTCASE]**: specifies a test case. This parameter must be specified together with **-ts**.
    -**h**: displays help information.
    ```

#### Executing Test Cases on Windows

Test cases cannot be built on Windows. You need to run the following command to build test cases on Linux:
```
./build.sh --product-name {product_name} --build-target make_test
```

>**NOTE**
>- **product-name**: specifies the name of the product to be compiled.
>- **build-target**: specifies the test case to build. **make_test** indicates all test cases. You can specify the test cases based on requirements.

After the build is complete, the test cases are automatically saved in **out/ohos-arm-release/packages/phone/tests**.

##### Setting Up the Execution Environment
1. On Windows, create the **Test** directory in the test framework and then create the **testcase** directory in the **Test** directory.

2. Copy **developertest** and **xdevice** from the Linux environment to the **Test** directory on Windows, and copy the test cases to the **testcase** directory.

  >**NOTE**
  >
  >Port the test framework and test cases from the Linux environment to the Windows environment for subsequent execution.

3. Modify the **user_config.xml** file.
  ```xml
  <build>
    <!-- Because the test cases have been built, change the value to false. -->
    <testcase>false</testcase>
  </build>
  <test_cases>
    <!-- The test cases are copied to the Windows environment. Change the test case output path to the path of the test cases in the Windows environment.-->
    <dir>D:\Test\testcase\tests</dir>
  </test_cases>
  ```
  >**NOTE**
  >
  >**\<testcase>** indicates whether to build test cases. **\<dir>** indicates the path for searching for test cases.

#### Executing Test Cases on Linux

If you directly connect to a Linux host, you can directly run commands to execute test cases.

##### Mapping the Remote Port
To enable test cases to be executed on a remote Linux server or a Linux VM, map the port to enable communication between the device and the remote server or VM. Configure port mapping as follows:
1. On the HDC server, run the following commands:
  ```
  hdc_std kill
  hdc_std -m -s 0.0.0.0:8710
  ```
  >**NOTE**
  >
  >The IP address and port number are default values.

2. On the HDC client, run the following command:
  ```
  hdc_std -s xx.xx.xx.xx:8710 list targets
  ```
  >**NOTE**
  >
  >Enter the IP address of the device to test.

## Viewing the Test Result

### Test Report Logs

After the test cases are executed, the test result will be automatically generated. You can view the detailed test result in the related directory.

### Test Result
You can obtain the test result in the following directory:
```
test/developertest/reports/xxxx_xx_xx_xx_xx_xx
```
>**NOTE**
>
>The folder for test reports is automatically generated.

The folder contains the following files:
| Type                                | Description              |
| ------------------------------------ | ------------------ |
| result/                              | Test cases in standard format.|
| log/plan_log_xxxx_xx_xx_xx_xx_xx.log | Test case logs.      |
| summary_report.html                  | Test report summary.      |
| details_report.html                  | Detailed test report.      |

### Test Framework Logs
```
reports/platform_log_xxxx_xx_xx_xx_xx_xx.log
```

### Latest Test Report
```
reports/latest
```
