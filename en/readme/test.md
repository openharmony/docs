# Test
OpenHarmony provides a comprehensive auto-test framework for designing test cases. Detecting defects in the development process can improve code quality.

This document describes how to use the OpenHarmony test framework.
## Setting Up the Environment
The test framework depends on Python. Before using the test framework, set up the environment as follows:
 - [Configuring the Environment](../device-dev/device-test/xdevice.md)
 - [Obtaining Source Code](../device-dev/get-code/sourcecode-acquire.md)


## Directory Structure
The directory structure of the test framework is as follows:
```
test # Test subsystem
├── developertest             # Developer test module
│   ├── aw                    # Static library of the test framework
│   ├── config                # Test framework configuration
│   │   │ ...
│   │   └── user_config.xml   # User configuration
│   ├── examples              # Test case examples
│   ├── src                   # Source code of the test framework
│   ├── third_party           # Adaptation code for third-party components on which the test framework depends
│   ├── reports               # Test reports
│   ├── BUILD.gn              # Build entry of the test framework
│   ├── start.bat             # Test entry for Windows
│   └── start.sh              # Test entry for Linux
└── xdevice                   # Modules on which the test framework depends
```
## Writing Test Cases
###  Designing the Test Case Directory
Design the test case directory as follows:
```
subsystem                                  # Subsystem
├── partA                                  # Part A
│   ├── moduleA                            # Module A
│   │   ├── include       
│   │   ├── src                            # Service code
│   │   └── test                           # Test directory
│   │       ├── unittest                   # Unit tests
│   │       │   ├── common                 # Common test cases
│   │       │   │   ├── BUILD.gn           # Build file of test cases
│   │       │   │   └── testA_test.cpp     # Source code of unit test cases
│   │       │   ├── phone                  # Test cases for smart phones
│   │       │   ├── ivi                    # Test cases for head units
│   │       │   └── liteos-a               # Test cases for IP cameras that use the LiteOS kernel
│   │       ├── moduletest                 # Module tests
│   │       ...
│   │            
│   ├── moduleB                      # Module B   
│   ├── test               
│   │   └── resource                 # Dependencies    
│   │       ├── moduleA              # Module A
│   │       │   ├── ohos_test.xml    # Resource configuration file
│   │       ... └── 1.txt            # Resource file  
│   │            
│   ├── ohos_build                   # Build entry configuration  
│   ...
│
...
```
> **NOTE**<br>Test cases are classified into common test cases and device-specific test cases. You are advised to place common test cases in the **common** directory and device-specific test cases in the directories of the related devices.

###  Writing Test Cases
This test framework supports test cases written in multiple programming languages and provides different templates for different languages.

#### C++ Test Case Example

- Naming rules for source files

    The source file name of test cases must be the same as that of the test suite. The file names must use lowercase letters and in the [Function]\_[Sub-function]\_**test** format. More specific sub-functions can be added as required.

    Example:

    ```
    calculator_sub_test.cpp
    ```

- Test case example
    ```
    
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
        // Set a setup function, which will be called before each test case.
    }
    
    void CalculatorSubTest::TearDown(void)
    {
        // Set a teardown function, which will be called after each test case.
    }
    
    /**
     * @tc.name: integer_sub_001
     * @tc.desc: Verify the sub function.
     * @tc.type: FUNC
     * @tc.require: Issue Number
     */
    HWTEST_F(CalculatorSubTest, integer_sub_001, TestSize.Level1)
    {
        // Step 1 Call the function to obtain the result.
        int actual = Sub(4, 0);
    
        // Step 2 Use an assertion to compare the obtained result with the expected result.
        EXPECT_EQ(4, actual);
    }
    ```
    The procedure is as follows:
    1. Add comment information to the test case file header.

        Enter the header comment in the standard format. For details, see [Code Specifications](https://gitee.com/openharmony/docs/blob/master/en/contribute/code-contribution.md).

    2. Add the test framework header file and namespace.
	    ```
    	#include <gtest/gtest.h>
    	
    	using namespace testing::ext;
    	```
    3. Add the header file of the test class.
	    ```
    	#include "calculator.h"
    	```
    4. Define the test suite (test class).
	    ```
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
    	    // Set a setup function, which will be called before each test case.
    	}
        
    	void CalculatorSubTest::TearDown(void)
    	{
    	    // Set a teardown function, which will be called after each test case.
    	}
    	```
	    > **NOTE**<br>When defining a test suite, ensure that the test suite name is the same as the target to build and uses the upper camel case style.

    5. Add implementation of the test cases, including test case comments and logic.
	    ```
    	/**
    	 * @tc.name: integer_sub_001
    	 * @tc.desc: Verify the sub function.
    	 * @tc.type: FUNC
    	 * @tc.require: Issue Number
    	 */
    	HWTEST_F(CalculatorSubTest, integer_sub_001, TestSize.Level1)
    	{
    	    // Step 1 Call the function to obtain the test result.
    	    int actual = Sub(4, 0);
        
    	    // Step 2 Use an assertion to compare the obtained result with the expected result.
    	    EXPECT_EQ(4, actual);
    	}
    	```
	    The following test case templates are provided for your reference.
	
	    |      Template|    Description|
    	| ------------| ------------|
    	| HWTEST(A,B,C)| Use this template if the test case execution does not depend on setup or teardown.|
    	| HWTEST_F(A,B,C)| Use this template if the test case execution (excluding parameters) depends on setup and teardown.|
    	| HWTEST_P(A,B,C)| Use this template if the test case execution (including parameters) depends on setup and teardown.|

	    In the template names: 
	- *A* indicates the test suite name.
	
	- *B* indicates the test case name, which is in the *Function*\_*No.* format. The *No.* is a three-digit number starting from **001**.

	- *C* indicates the test case level. There are five test case levels: guard-control level 0 and non-guard-control level 1 to level 4. Of levels 1 to 4, a smaller value indicates a more important function verified by the test case.
	
	    **NOTE**<br>
	    
	- The expected result of each test case must have an assertion.

	- The test case level must be specified.
    
    - It is recommended that the test be implemented step by step according to the template.
    
    - The comment must contain the test case name, description, type, and requirement number. The test case description must be in the @tc.xxx format. 
    
        The test case type @tc.type can be any of the following.
    	
    	| Test Case Type|Code|
        | ------------|------------|
        |Function test     |FUNC|
        |Performance Test     |PERF|
        |Reliability test   |RELI|
        |Security test     |SECU|
        |Fuzz test     |FUZZ|
    

#### JavaScript Test Case Example

- Naming rules for source files

    The source file name of a test case must be in the [Function]\[Sub-function]Test format, and each part must use the upper camel case style. More specific sub-functions can be added as required.

    Example:

    ```
    AppInfoTest.js
    ```

- Test case example

    ```ts
    import app from '@system.app'
    
    import {describe, beforeAll, beforeEach, afterEach, afterAll, it, expect} from '@ohos/hypium'
    
    describe("AppInfoTest", () => {
      beforeAll(() => {
        // Set a setup function, which will be called before all test cases.
        console.info('beforeAll called')
      })
    
      afterAll(() => {
        // Set a teardown function, which will be called after all test cases.
        console.info('afterAll called')
      })
    
      beforeEach(() => {
        // Set a setup function, which will be called before each test case.
        console.info('beforeEach called')
      })
    
      afterEach(() => {
        // Set a teardown function, which will be called after each test case.
        console.info('afterEach called')
      })
    
      /*
       * @tc.name:appInfoTest001
       * @tc.desc:verify app info is not null
       * @tc.type: FUNC
       * @tc.require: Issue Number
       */
      it("appInfoTest001", 0, () => {
        // Step 1 Call the function to obtain the test result.
        let info = app.getInfo()
    
        // Step 2 Use an assertion to compare the obtained result with the expected result.
        expect(info != null).assertEqual(true)
      })
    })
    ```

    

The procedure is as follows:
1. Add comment information to the test case file header.

   Enter the header comment in the standard format. For details, see [Code Specifications](https://gitee.com/openharmony/docs/blob/master/en/contribute/code-contribution.md).

2. Import the APIs and JSUnit test library to test.

```ts
import app from '@system.app'
    	
import {describe, beforeAll, beforeEach, afterEach, afterAll, it, expect} from '@ohos/hypium'
```


3. Define the test suite (test class).

```ts
import app from '@system.app'

import {describe, beforeAll, beforeEach, afterEach, afterAll, it, expect} from '@ohos/hypium'

describe("AppInfoTest", () => {
	beforeAll(() => {
		// Set a setup function, which will be called before all test cases.
		console.info('beforeAll called')
	})

	afterAll(() => {
		// Set a teardown function, which will be called after all test cases.
		console.info('afterAll called')
	})

	beforeEach(() => {
		// Set a setup function, which will be called before each test case.
		console.info('beforeEach called')
	})

	afterEach(() => {
		// Set a teardown function, which will be called after each test case.
		console.info('afterEach called')
	})
})
```

4. Add implementation of the test cases.
```ts
import app from '@system.app'

import {describe, it, expect} from '@ohos/hypium'
describe("AppInfoTest", () => {
  /*
   * @tc.name:appInfoTest001
   * @tc.desc:verify app info is not null
   * @tc.type: FUNC
   * @tc.require: Issue Number
   */
  it("appInfoTest001", 0,  () => {
    // Step 1 Call the function to obtain the test result.
    let info = app.getInfo()

    // Step 2 Use an assertion to compare the obtained result with the expected result.
    expect(info != null).assertEqual(true)
  })
})
```

### Writing the Build File for Test Cases
When a test case is executed, the test framework searches for the build file of the test case in the test case directory and builds the test case located. The following describes how to write build files (GN files) in different programming languages.

#### Writing Build Files for Test Cases
The following provides templates for different languages for your reference.

- **Test case build file example (C++)**
    ```c++
    
    import("//build/test.gni")
    
    module_output_path = "subsystem_examples/calculator"
    
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

        Enter the header comment in the standard format. For details, see [Code Specifications](https://gitee.com/openharmony/docs/blob/master/en/contribute/code-contribution.md).

    2. Import the build template.
	    ```
    	import("//build/test.gni")
    	```
    3. Specify the file output path.
    	```
    	module_output_path = "subsystem_examples/calculator"
    	```
    	> **NOTE**<br>The output path is ***Part name*/*Module name***.
    
    4. Configure the directories for dependencies.
    
    	```
    	config("module_private_config") {
    	  visibility = [ ":*" ]
    	   
    	  include_dirs = [ "../../../include" ]
    	}
    	```
    	> **NOTE**<br>Generally, the dependency directories are configured here and directly referenced in the build script of the test case.
    
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

	    > **NOTE**<br>Set the test type based on actual requirements. The following test types are available:
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
    	> **NOTE**<br>Grouping test cases by test type allows you to execute a specific type of test cases when required.
    
- **Test case build file example (JavaScript)**

    ```
    import("//build/test.gni")
    
    module_output_path = "subsystem_examples/app_info"
    
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

        Enter the header comment in the standard format. For details, see [Code Specifications](https://gitee.com/openharmony/docs/blob/master/en/contribute/code-contribution.md).

    2. Import the build template.
    
    	```
    	import("//build/test.gni")
    	```
    3. Specify the file output path.
    
    	```
    	module_output_path = "subsystem_examples/app_info"
    	```
    	> **NOTE**<br>The output path is ***Part name*/*Module name***.
    	
    4. Set the output build file for the test cases.
    
    	```
    	ohos_js_unittest("GetAppInfoJsTest") {
    	}
    	```
    	> **NOTE**<br>
    	>- Use the **ohos\_js\_unittest** template to define the JavaScript test suite. Pay attention to the difference between JavaScript and C++.
    	>- The file generated for the JavaScript test suite must be in .hap format and named after the test suite name defined here. The test suite name must end with **JsTest**.
    
    5. Configure the **config.json** file and signature file, which are mandatory.
    
    	```
    	ohos_js_unittest("GetAppInfoJsTest") {
    	  module_out_path = module_output_path
    	   
    	  hap_profile = "./config.json"
    	  certificate_profile = "//test/developertest/signature/openharmony_sx.p7b"
    	}
    	```
    	**config.json** is the configuration file required for HAP build. You need to set **target** based on the tested SDK version. Default values can be retained for other items. The following is an example:
    
    	```
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
    	      "target": 5 // Set it based on the tested SDK version. In this example, SDK5 is used.
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
    	> **NOTE**<br>Grouping test cases by test type allows you to execute a specific type of test cases when required.
    
#### Configuring ohos.build

Configure the part build file to associate with specific test cases.
```
"partA": {
    "module_list": [
          
    ],
    "inner_list": [
          
    ],
    "system_kits": [
          
    ],
    "test_list": [
      "//system/subsystem/partA/calculator/test:unittest"  // Configure test under calculator.
    ]
 }
```
> **NOTE**<br>**test_list** contains the test cases of the corresponding module.

### Configuring Test Case Resources
Test case resources include external file resources, such as image files, video files, and third-party libraries, required for test case execution.

Perform the following steps:
1. Create the **resource** directory in the **test** directory of the part, and create a directory for the module in the **resource** directory to store resource files of the module.

2. In the module directory under **resource**, create the **ohos_test.xml** file in the following format:
	```
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
3. In the build file of the test cases, configure **resource\_config\_file** to point to the resource file **ohos\_test.xml**.
	```
	ohos_unittest("CalculatorSubTest") {
	  resource_config_file = "//system/subsystem/partA/test/resource/calculator/ohos_test.xml"
	}
	```
	>**NOTE**<br>
	>- **target_name** indicates the test suite name defined in the **BUILD.gn** file in the **test** directory.
	>- **preparer** indicates the action to perform before the test suite is executed.
	>- **src="res"** indicates that the test resources are in the **resource** directory under the **test** directory. 
	>- **src="out"** indicates that the test resources are in the **out/release/$(*part*)** directory.

## Executing Test Cases
Before executing test cases, you need to modify the configuration based on the device used.

### Modifying user_config.xml
```
<user_config>
  <build>
    <!-- Whether to build a demo case. The default value is false. If a demo case is required, change the value to true. -->
    <example>false</example>
    <!-- Whether to build the version. The default value is false. -->
    <version>false</version>
    <!-- Whether to build the test cases. The default value is true. If the build is already complete, change the value to false before executing the test cases.-->
    <testcase>true</testcase>
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
>**NOTE**<br>If HDC is connected to the device before the test cases are executed, you only need to configure the device IP address and port number, and retain the default settings for other parameters.

### Executing Test Cases on Windows
#### Building Test Cases

Test cases cannot be built on Windows. You need to run the following command to build test cases on Linux:
```
./build.sh --product-name hispark_taurus_standard --build-target make_test
```
When the build is complete, the test cases are automatically saved in **out/hispark_taurus/packages/phone/images/tests**.

>**NOTE**<br>**hispark_taurus_standard** indicates the product supported by the current version, and **make_test** indicates all test cases. You can set the build options based on requirements:
> -  --**product-name** specifies the name of the product to build. It is mandatory.
> - --**build-target** specifies the target to build. It is optional. 

#### Setting Up the Execution Environment
1. On Windows, create the **Test** directory in the test framework and then create the **testcase** directory in the **Test** directory.

2. Copy **developertest** and **xdevice** from the Linux environment to the **Test** directory on Windows, and copy the test cases to the **testcase** directory.
	
	> **NOTE**<br>
	>
	> Port the test framework and test cases from the Linux environment to the Windows environment for subsequent execution.
3. Modify the **user_config.xml** file.
	```
	<build>
	  <!-- Because the test cases have been built, change the value to false. -->
	  <testcase>false</testcase>
	</build>
	<test_cases>
	  <!-- The test cases are copied to the Windows environment. Change the test case output path to the path of the test cases in the Windows environment.-->
	  <dir>D:\Test\testcase\tests</dir>
	</test_cases>
	```
	>**NOTE**<br>`<testcase>` indicates whether to build test cases. `<dir>` indicates the path for searching for test cases.

#### Executing Test Cases
1. Start the test framework.
	```
	start.bat
	```
2. Select the product.

    After the test framework starts, you are asked to select a product. Select the development board to test, for example, **Hi3516DV300**.

3. Execute test cases.

    Run the following command to execute test cases:
	```
	run -t UT -ts CalculatorSubTest -tc integer_sub_00l
	```
	In the command:
	```
	-t [TESTTYPE]: specifies the test type, which can be UT, MST, ST, or PERF. This parameter is mandatory.
	-tp [TESTPART]: specifies the part to test. This parameter can be used independently.
	-tm [TESTMODULE]: specifies the module to test. This parameter must be used together with -tp.
	-ts [TESTSUITE]: specifies a test suite. This parameter can be used independently.
	-tc [TESTCASE]: specifies a test case. This parameter must be used together with -ts.
	You can run -h to display help information.
	```
### Executing Test Cases on Linux
#### Mapping the Remote Port
To enable test cases to be executed on a remote Linux server or a Linux VM, map the port to enable communication between the device and the remote server or VM. Configure port mapping as follows:
1. On the HDC server, run the following commands:
	```
	hdc_std kill
	hdc_std -m -s 0.0.0.0:8710
	```
	>**NOTE**<br>The IP address and port number are default values.

2. On the HDC client, run the following command:
	```
	hdc_std -s xx.xx.xx.xx:8710 list targets
	```
	>**NOTE**<br>Enter the IP address of the device to test.

#### Executing Test Cases
1. Start the test framework.
	```
	./start.sh
	```
2. Select the product.

    After the test framework starts, you are asked to select a product. Select the development board to test, for example, **Hi3516DV300**.

3. Execute test cases.

    The test framework locates the test cases based on the command, and automatically builds and executes the test cases.
	```
	run -t UT -ts CalculatorSubTest -tc interger_sub_00l
	```
	In the command:
	```
	-t [TESTTYPE]: specifies the test type, which can be UT, MST, ST, or PERF. This parameter is mandatory.
	-tp [TESTPART]: specifies the part to test. This parameter can be used independently.
	-tm [TESTMODULE]: specifies the module to test. This parameter must be used together with -tp.
	-ts [TESTSUITE]: specifies a test suite. This parameter can be used independently.
	-tc [TESTCASE]: specifies a test case. This parameter must be used together with -ts.
	You can run -h to display help information.
	```

## Viewing the Test Report
After the test cases are executed, the test result will be automatically generated. You can view the detailed test result in the related directory.

### Test Result
You can obtain the test result in the following directory:
```
test/developertest/reports/xxxx_xx_xx_xx_xx_xx
```
>**NOTE**<br>The folder for test reports is automatically generated.

The folder contains the following files:
| Type| Description|
| ------------ | ------------ |
| result/ |Test cases in standard format|
| log/plan_log_xxxx_xx_xx_xx_xx_xx.log | Test case logs|
| summary_report.html | Test report summary|
| details_report.html | Detailed test report|

### Test Framework Logs
```
reports/platform_log_xxxx_xx_xx_xx_xx_xx.log
```

### Latest Test Report
```
reports/latest
```

## Repositories Involved

[test\_xdevice](https://gitee.com/openharmony/test_xdevice/blob/master/README.md)
