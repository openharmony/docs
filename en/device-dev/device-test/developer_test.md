# Development Self-Test Framework User Guide


## Overview

OpenHarmony provides you with a comprehensive development self-test framework **developer_test**. As a part of the OpenHarmony test toolset, the development self-test framework is provided for you to test the development by yourself. You can develop relevant test cases based on your test requirements to discover defects at the development phase, greatly improving the code quality.

This document describes how to use the development self-test framework of OpenHarmony.


### Overview

After adding or modifying code, OpenHarmony developers want to quickly verify whether the modified code functions properly, and the system already has a large number of automated test cases of existing functions, such as TDD cases and XTS cases. The development self-test framework aims to help you improve your self-test efficiency so that you can quickly execute the specified automated test cases and conducting development tests at the development phase.


### Constraints

When executing test cases using the framework, you must connect to the OpenHarmony device in advance.


## Environment Setup

The development self-test framework depends on the Python environment. It is required that the Python version be 3.7.5 or later. Before using the framework, you can refer to the following document for configuration.

Click [here](https://gitee.com/openharmony/docs/blob/master/en/device-dev/get-code/sourcecode-acquire.md) to obtain the source code.

### Basic Self-Test Framework Environment

| Environment Dependency         | Version                                                    | Description                                                    |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Operating system         | Ubuntu 20.04 or later                                           | Code compilation environment.                                                |
| Linux extension component| libreadline-dev                                              | Plugin used to read commands.                                              |
| python            | 3.7.5 or later                                             | Language used by the test framework.                                                |
| Python plugins       | pyserial 3.3 or later, paramiko 2.7.1 or later, setuptools 40.8.0 or later, and rsa4.0 or later| - **pserial**: supports Python serial port communication.<br>- **paramiko**: allows Python to use SSH. <br>- **setuptools**: allows Python packages to be created and distributed easily. <br>- **rsa**: implements RSA encryption in Python.|
| NFS Server        | haneWIN NFS Server 1.2.50 or later or NFS v4 or later            | Devices can be connected using serial ports. Mini- and small-system devices are used.                    |
| HDC               | 1.2.0a                                                        | A tool that enables devices to be connected through the OpenHarmony Device Connector (HDC).                                         |



1. Install Ubuntu.

	 As Ubuntu 20 has built-in Python 3.8.5, you do not need to install Python separately.

2. Run the following command to install the Linux extended component readline:

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

	> **NOTE** 
	> 
	> This operation applies to small-system or mini-system devices, not standard-system devices.

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

7. If the device supports HDC connection, install the HDC tool. For details about the installation process, see [HDC-OpenHarmony Device Connector](https://gitee.com/openharmony/developtools_hdc/blob/master/README.md).


### Environment Dependency Check

| Check Item                                            | Action                                               | Requirement                 |
| -------------------------------------------------- | --------------------------------------------------- | ------------------------- |
| Check whether Python is installed successfully.                                | Run the **python --version** command.               | The Python version is 3.7.5 or later.      |
| Check whether Python plugins are successfully installed.                        | Go to the **test/developertest** directory and run **start.bat** or **start.sh**.| The **>>>** prompt is displayed.|
| Check the NFS server status (for the devices that support only serial port output).| Log in to the development board through the serial port and run the **mount** command to mount the NFS.           | The file directory can be mounted.   |
| Check whether the HDC is successfully installed.                                   | Run the **hdc -v** command.                     | The HDC version is 1.2.0a or later.      |


## Test Case Preparation

The test framework supports multiple types of tests and provides different test case templates for them.

**TDD Test (C++)**

- Naming rules for source files

    The source file name of test cases must be the same as that of the test suite. The file names must use lowercase letters and in the [Function]\_[Sub-function]\_**test** format. More specific sub-functions can be added as required.


- The following uses **calculator_sub_test.cpp** as an example to describe how to compile a single-thread test case:
    ```
    /*
     * Copyright (c) 2023 XXXX Device Co., Ltd.
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
    	 * Copyright (c) 2023 XXXX Device Co., Ltd.
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
	    ```
    	#include <gtest/gtest.h>
    	
    	using namespace testing::ext;
    	```
    3. Add the header file of the test class.
	    ```
    	#include "calculator.h"
    	```
    4. Define the test suite (test class).
		> When defining a test suite, ensure that the test suite name is the same as the target to build and uses the upper camel case style.
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
    	    // Set a setup function, which will be called before all test cases.
    	}
        
    	void CalculatorSubTest::TearDown(void)
    	{
    	    // Set a teardown function, which will be called after all test cases.
    	}
    	```

    5. Add implementation of the test cases, including test case comments and logic.
	    ```
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
        > The value of **@tc.require** must start with AR/SR or issue, for example, **issueI56WJ7**.
    
- The following uses **base_object_test.cpp** as an example to describe how to compile a multi-thread test case:
    ```
    // The test case file header comment and test case comment are the same as those in the single-thread test case example.
    
    #include "base_object.h"
    #include <gtest/gtest.h>
	#include <gtest/hwext/gtest-multithread.h>
	#include <unistd.h>
    
    using namespace testing::ext;
    using namespace testing::mt;

	namespace OHOS {
	namespace AAFwk {
    class AAFwkBaseObjectTest : public testing::Test {......}

	// Step 1 Set the function to be tested to return the factorial result.
	int factorial(int n)
	{
		int result = 1;
		for (int i = 1; i <= n; i++) {
			result *= i;
		}
		printf("Factorial Function Result : %d! = %d\n", n, result);
		return result;
	} 

	// Step 2 Use an assertion to compare the obtained result with the expected result.
	void factorial_test()
	{
		int ret = factorial(3); // Call the function to obtain the result.
		std::thread::id this_id = std::this_thread::get_id();
		std::ostringstream oss;
		oss << this_id;
		std::string this_id_str = oss.str();
		long int thread_id = atol(this_id_str.c_str());
		printf("running thread...: %ld\n", thread_id); // Output the ID of the running thread.
		EXPECT_EQ(ret, 6);
	}

	HWTEST_F(AAFwkBaseObjectTest, Factorial_test_001, TestSize.Level1)
	{
		SET_THREAD_NUM(4);
		printf("Factorial_test_001 BEGIN\n");
		GTEST_RUN_TASK(factorial_test);
		printf("Factorial_test_001 END\n");
	}

	HWMTEST_F(AAFwkBaseObjectTest, Factorial_test_002, TestSize.Level1, 6)
	{
		printf("Factorial_test_002 BEGIN\n");
		factorial_test();
		printf("Factorial_test_002 END\n");
	}

	}  // namespace AAFwk
	}  // namespace OHOS

    ```
    The procedure is as follows:
    1. Add comment information to the test case file header.

	 > **NOTE**
     >
     > The standard is the same as that of the single-thread test case.

	    ```
    	#include <gtest/gtest.h>
    	#include <gtest/hwext/gtest-multithread.h>
		#include <unistd.h>
    	using namespace testing::ext;
   		using namespace testing::mt;
    	```
    3. Add the header file of the test class.
	    ```
    	#include "base_object.h"
    	```
    4. Define the test suite (test class).
	    ```
    	class AAFwkBaseObjectTest : public testing::Test {......}

    	```
	  

	      > **NOTE**
	      >
	      > The standard is the same as that of the single-thread test case.

	    ```
		// Step 1 Set the function to be tested to return the factorial result.
		int factorial(int n)
		{
			int result = 1;
			for (int i = 1; i <= n; i++) {
				result *= i;
			}
			printf("Factorial Function Result : %d! = %d\n", n, result);
			return result;
		} 
		
		// Step 2 Use an assertion to compare the obtained result with the expected result.
		void factorial_test()
		{
			int ret = factorial(3); // Call the function to obtain the result.
			std::thread::id this_id = std::this_thread::get_id();
			std::ostringstream oss;
			oss << this_id;
			std::string this_id_str = oss.str();
		long int thread_id = atol(this_id_str.c_str());
		printf("running thread...: %ld\n", thread_id); // Output the ID of the running thread.
			EXPECT_EQ(ret, 6);
		}

		// GTEST_RUN_TASK(TestFunction) is a multi-thread startup function. The parameter is a custom function.
		// If SET_THREAD_NUM() is not called, the default value 10 will be used.
    	HWTEST_F(AAFwkBaseObjectTest, Factorial_test_001, TestSize.Level1)
    	{
			SET_THREAD_NUM(4); // Set the number of threads. It can be dynamically set in the same test suite.
			printf("Factorial_test_001 BEGIN\n");
			GTEST_RUN_TASK(factorial_test); // Start the multi-thread execution of the factorial_test task.
			printf("Factorial_test_001 END\n");
    	}

		// HWMTEST_F(TEST_SUITE, TEST_TC, TEST_LEVEL, THREAD_NUM)
	    	// THREAD_NUM can be used to set the number of threads for executing a test case.
		// HWMTEST_F creates a specified number of threads and executes the tested function.
    	HWMTEST_F(AAFwkBaseObjectTest, Factorial_test_002, TestSize.Level1, 6)
    	{
			printf("Factorial_test_002 BEGIN\n");
			factorial_test();
			printf("Factorial_test_002 END\n");
    	}
      	       // Add the multi-thread API MTEST_ADD_TASK(THREAD_ID,ThreadTestFunc). Multiple threads are registered but are not executed in this test case. Instead, they are executed later in a unified manner. This API is applicable to the multi-thread test in the scenario where multiple test cases are combined.
              // THREAD_ID is used to distinguish threads and starts from 0. You can also use a random thread ID by passing in RANDOM_THREAD_ID. In this scenario, each thread ID is unique.
              // Add the multi-thread API MTEST_POST_RUN() to execute the previously registered threads in a unified manner.
    	```
    	> **NOTE**
    	>
    	> The comments for multi-thread test cases are the same as those of single-thread test cases.
  
- About C++ test case templates:
		
	The following test case templates are provided for your reference.

	|      Type|    Description|
	| ------------| ------------|
	| HWTEST(A,B,C)| Use this template if the test case execution does not depend on setup or teardown.|
	| HWTEST_F(A,B,C)| Use this template if the test case execution (excluding parameters) depends on setup and teardown.|
	| HWMTEST_F(A,B,C,D)| Use this template if the multi-thread test case execution depends on setup and teardown.|
	| HWTEST_P(A,B,C)| Use this template if the test case execution (including parameters) depends on setup and teardown.|


	In the template names:
	
	- **A** indicates the test suite name.
	
	- **B** indicates the test case name, which is in the *Function*_*No.* format. The *No.* is a three-digit number starting from **001**.
	
	- **C** indicates the test case level. There are five test case levels: guard-control level 0 and non-guard-control level 1 to level 4. Of levels 1 to 4, a smaller value indicates a more important function verified by the test case.
	
	- **D** indicates the number of threads for executing the multi-thread test case.
	
	**Note**:
	
	- The expected result of each test case must have an assertion.
	
	- The test case level must be specified.
	
	- It is recommended that the test be implemented step by step according to the template.
	
	- The test case description is in the standard @tc.*xxx* *value* format. The comment must contain the test case name, description, type, and requirement number. The test case type @tc.type can be any of the following:


		| Test Case Type | Code |
		| ------------ | -------- |
		| Function test | FUNC |
		| Performance Test | PERF |
		| Reliability test | RELI |
		| Security Test | SECU |
		| Fuzz test | FUZZ |

**TDD Test (JavaScript)**

- Naming rules for source files


	The source file name of a test case must be in the [Function][Sub-function]**Test** format, and each part must use the upper camel case style. More specific sub-functions can be added as required.
	Example:
	```
	AppInfoTest.js
	```

- Test case example

	```js
	/*
	* Copyright (C) 2023 XXXX Device Co., Ltd.
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
		* Copyright (C) 2023 XXXX Device Co., Ltd.
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
	4. Write test cases
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
		> The value of **@tc.require** must start with AR/SR or issue, for example, **issueI56WJ7**.

**Fuzzing Test**

[Fuzzing case specifications](https://gitee.com/openharmony/testfwk_developer_test/blob/master/libs/fuzzlib/README_zh.md)


**Benchmark Test**

[Benchmark case specifications](https://gitee.com/openharmony/testfwk_developer_test/blob/master/libs/benchmark/README_zh.md)

## **Test Case Building**

When a test case is executed, the test framework searches for the build file of the test case in the test case directory and builds the test case located. The following describes how to write build files (GN files) in different programming languages.

**TDD Test**

The following provides templates for different languages for your reference.

- **Test case build file example (C++)**

	```
	# Copyright (c) 2023 XXXX Device Co., Ltd.

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
		# Copyright (c) 2023 XXXX Device Co., Ltd.
		```
	2. Import the build template.
		```
		import("//build/test.gni")
		```
	3. Specify the file output path.
		```
		module_output_path = "developertest/calculator"
		```
		> **NOTE**
		> 
		> The output path is the *Part name*/*Module name*.

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
		> - **ohos_unittest**: unit test
        > - **ohos_js_unittest**: FA model JS unit test
        > - **ohos_js_stage_unittest**: stage model ArkTS unit test
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
	# Copyright (C) 2023 XXXX Device Co., Ltd.

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
		# Copyright (C) 2023 XXXX Device Co., Ltd.
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
		> The output path is the *Part name*/*Module name*.

	4. Set the output build file for the test cases.

		```
		ohos_js_unittest("GetAppInfoJsTest") {
		}
		```
		> **NOTE** 
		> 
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

- **Example of ArkTS case compilation configuration for the stage model**

    ```
    # Copyright (C) 2023 XXXX Device Co., Ltd.
    
    import("//build/test.gni")

    want_output_path = "developertest/stage_test"
    
    ohos_js_stage_unittest("ActsBundleMgrStageEtsTest") {
    hap_profile = "entry/src/main/module.json"
    deps = [
        ":actbmsstageetstest_js_assets",
        ":actbmsstageetstest_resources",
    ]
    ets2abc = true
    certificate_profile = "signature/openharmony_sx.p7b"
    hap_name = "ActsBundleMgrStageEtsTest"
    subsystem_name = "developertest"
    part_name = "stage_test"
    module_out_path = want_output_path
    }
    ohos_app_scope("actbmsstageetstest_app_profile") {
    app_profile = "AppScope/app.json"
    sources = [ "AppScope/resources" ]
    }
    ohos_js_assets("actbmsstageetstest_js_assets") {
    source_dir = "entry/src/main/ets"
    }
    ohos_resources("actbmsstageetstest_resources") {
    sources = [ "entry/src/main/resources" ]
    deps = [ ":actbmsstageetstest_app_profile" ]
    hap_profile = "entry/src/main/module.json"
    }
    group("unittest") {
    testonly = true
    deps = []
    deps += [ ":ActsBundleMgrStageEtsTest" ]
    }
    ```
	The procedure is as follows:

	1. Add comment information for the file header.

		```
		# Copyright (C) 2023 XXXX Device Co., Ltd.
		```

	2. Import the build template.

		```
		import("//build/test.gni")
		```

	3. Specify the file output path.

		```
		want_output_path = "developertest/stage_test"
		```
		> **NOTE** 
		> 
		> The output path is the *Part name*/*Module name*.

	4. Set the output build file for the test cases.

		```
		ohos_js_stage_unittest("ActsBundleMgrStageEtsTest") {
		}
		```
		>  **NOTE** 
		> 
		> Use the **ohos_js_stage_unittest** template to define the ArkTS test suite for the stage model.

	5. Specify the configuration file **module.json**, signature file, part name, and compilation output path, which are all mandatory.

		```
		ohos_js_stage_unittest("ActsBundleMgrStageEtsTest") {
        hap_profile = "entry/src/main/module.json"
        certificate_profile = "signature/openharmony_sx.p7b"
        subsystem_name = "developertest"
        part_name = "stage_test" // Part name
		}
		```

	6. Specify the configuration resource file (add the source files, configurations, and dependencies).
		```
		# Declare an AppScope module for the HAP. Those specified by app_profile and sources will be combined to a specific entry file for compilation.
		ohos_app_scope("actbmsstageetstest_app_profile") {
        app_profile = "AppScope/app.json"
        sources = [ "AppScope/resources" ]
		}

		# Place the test case code for the stage model in the ets directory.
		ohos_js_assets("actbmsstageetstest_js_assets") {
        source_dir = "entry/src/main/ets"
		}

		# Source files are stored in the resources directory after compilation in the stage model.
		ohos_resources("actbmsstageetstest_resources") {
        sources = [ "entry/src/main/resources" ]
        deps = [ ":actbmsstageetstest_app_profile" ]
        hap_profile = "entry/src/main/module.json"
		}

		```

   7. Group the test case files by test type.

       ```
       group("unittest") {
       testonly = true
       deps = [ ":GetAppInfoJsTest" ]
       }
       ```
		> **NOTE** 
		> 
		> Grouping test cases by test type allows you to execute a specific type of test cases when required.

**Configuring bundle.json**

Configure the part build file to associate with specific test cases.
```
"build": {
    "sub_component": [
		"//test/testfwk/developer_test/examples/app_info:app_info",  
		"//test/testfwk/developer_test/examples/detector:detector",  
		"//test/testfwk/developer_test/examples/calculator:calculator"
    ],
    "inner_list": [
		{
			"header": {
				"header_base": "////test/testfwk/developer_test/examples/detector/include",
				"header_files": [
					"detector.h"
				]
		},
		"name": "//test/testfwk/developer_test/examples/detector:detector"
	  }
    ],
    "test": [ // Test under configuration module calculator.
      "//test/testfwk/developer_test/examples/app_info/test:unittest",  
      "//test/testfwk/developer_test/examples/calculator/test:unittest",
      "//test/testfwk/developer_test/examples/calculator/test:fuzztest"
 }
```
> **NOTE** 
> 
> **test_list** contains the test cases of the corresponding module.

## Configuring Test Resources

The test resources mainly include external file resources such as image files, video files, and third-party libraries required during test case execution. Currently, only static resources can be configured.

Perform the following steps:

1. Create the **resource** directory in the **test** directory of the part, and create a directory for the module in the **resource** directory to store resource files of the module.

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
	> **NOTE** 
	> 
	>- **target_name** indicates the test suite name defined in the **BUILD.gn** file in the **test** directory. **preparer** indicates the action to perform before the test suite is executed.
	>- **src="res"** indicates that the test resources are in the **resource** directory under the **test** directory. **src="out"** indicates that the test resources are in the **out/release/$(*part*)** directory.

## Test Case Execution

### Configuration File user_config.xml

Before executing test cases, you need to modify the configuration in **developer_test\config\user_config.xml** based on the device used.

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
> **NOTE** 
> 
> If HDC is connected to the device before the test cases are executed, you only need to configure the device IP address and port number, and retain the default settings for other parameters.

### Executing Test Cases on Windows
#### **Test Case Building**

Test cases cannot be built on Windows. You need to run the following command to build test cases on Linux:
```
./build.sh --product-name {product_name} --build-target make_test
```

> **NOTE** 
> 
>- **product-name**: specifies the name of the product to be compiled.
>- **build-target**: specifies the test case to build. **make_test** indicates all test cases. You can specify the test cases based on requirements.

When the build is complete, the test cases are automatically saved in **out/ohos-arm-release/packages/phone/tests**.

#### Setting Up the Execution Environment
1. On Windows, create the **Test** directory in the test framework and then create the **testcase** directory in the **Test** directory.

2. Copy **developertest** and **xdevice** from the Linux environment to the **Test** directory on Windows, and copy the test cases to the **testcase** directory.
	
	> **NOTE** 
	>  
	> Port the test framework and test cases from the Linux environment to the Windows environment for subsequent execution.
	
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
	> **NOTE** 
	>  
	> **\<testcase>** indicates whether to build test cases. **\<dir>** indicates the path for searching for test cases.

#### Executing Test Cases

1. Start the test framework.
	```
	start.bat
	```
2. Select the product.

    After the test framework starts, you are asked to select a product. Select the development board to test.

	If you need to manually add a product, add it within the **\<productform\>** tag to **config/framework_config.xml**.

3. Execute the test cases.

    Run the following commands to execute test cases:
	```
	run -t UT
	run -t UT -tp PartName
	run -t UT -tp PartName -tm TestModuleName
	run -t UT -tp ability_base -ts base_object_test
	run -t UT -tp PartName -tm TestModuleName -ts CalculatorSubTest
	run -t UT -ts base_object_test
	run -t UT -ts base_object_test -tc AAFwkBaseObjectTest.BaseObject_test_001
	run -t UT -ts CalculatorSubTest -tc CalculatorSubTest.interger_sub_00l
	run -t UT -cov coverage
	run -t UT -ra random
	run -t UT -ts base_object_test --repeat 5
	run -hl
	run -rh 3
	run --retry
	```

	
	In the command:
	```
	-**t [TESTTYPE]**: specifies the test type, which can be **UT**, **MST**, **ST**, **PERF**, **FUZZ**, **BENCHMARK**, **ACTS**, **HATS**, and more. This parameter is mandatory.
	-**tp [TESTPART]**: specifies the part to test. This parameter can be used independently.
	-**tm [TESTMODULE]**: specifies the module to test. This parameter must be specified together with **-tp**.
	-**ts [TESTSUITE]**: specifies the test suite. This parameter can be used independently.
	-**tc [TESTCASE]**: specifies the test case. This parameter must be specified together with **-ts** to indicate the test suite.
	-**cov [COVERAGE]**: specifies the coverage.
	-**h**: displays help information.
	-**ra [random]**: specifies the out-of-order execution for C++ cases.
	--**repeat**: specifies the number of case execution times.
	-**hl [HISTORYLIST]**: enables the display of the latest 10 test cases. If there are more than 10 test cases, only the latest 10 test cases are displayed.
	-**rh [RUNHISTORY]**: specifies the sequence number of the historical record to execute.
	--**retry**: checks the last execution result and re-runs the failed test cases, if any.
	```

	
### Executing Test Cases on Linux


#### Configuring Remote Port Mapping and Modifying Configuration File
To enable test cases to be executed on a remote Linux server or a Linux VM, map the port to enable communication between the device and the remote server or VM. Configure port mapping as follows:
1. On the HDC server, run the following commands:
	```
	hdc_std kill
	hdc_std -m -s 0.0.0.0:8710
	```
	> **NOTE** 
	> 
	> The IP address and port number are default values.

2. On the HDC client, run the following command:
	```
	hdc_std -s xx.xx.xx.xx:8710 list targets
	```
	> **NOTE** 
	> 
	> Enter the IP address of the device to test.

3. Modify the **user_config.xml** file.
	```xml
	<build>
	  <!--If a test case needs to be compiled, set this attribute is true. Otherwise, set it to false. -->
	  <testcase>true</testcase>
	</build>
	<environment>
    <!-- Configure the IP address, port number, and SN of the remote server to support connection to the device through HDC. -->
    <device type="usb-hdc">
      <ip></ip>
      <port></port>
      <sn></sn>
    </device>
	<environment>
	```


#### Executing Test Cases
1. Start the test framework.
	```
	./start.sh
	```
2. Select the product.

    After the test framework starts, you are asked to select a product. Select the development board to test.

	If the displayed product list does not contain the target one, you can add it in the **\<productform\>** tag in **config/framework_config.xml**.

	```
	<framework_config>
	 <productform>
	  <option name="ipcamera_hispark_aries" />
	  <option name="ipcamera_hispark_taurus" />
	  <option name="wifiiot_hispark_pegasus" />
	  <option name="" />
	 </productform>
	</framework_config>

	```

3. Execute the test cases.

    1. TDD commands

    The test framework locates the test cases based on the command, and automatically builds and executes the test cases.
	```
	run -t UT
	run -t UT -tp PartName
	run -t UT -tp PartName -tm TestModuleName
	run -t UT -tp ability_base -ts base_object_test
	run -t UT -tp PartName -tm TestModuleName -ts CalculatorSubTest
	run -t UT -ts base_object_test
	run -t UT -ts base_object_test -tc AAFwkBaseObjectTest.BaseObject_test_001
	run -t UT -ts CalculatorSubTest -tc CalculatorSubTest.interger_sub_00l
	run -t -cov coverage
	run -t UT -ra random
	run -t UT -tp PartName -pd partdeps
	run -t UT -ts base_object_test --repeat 5
	run -hl
	run -rh 3
	run --retry
	```
	In the command:
	```
	-**t [TESTTYPE]**: specifies the test type, which can be **UT**, **MST**, **ST**, **PERF**, **FUZZ**, and **BENCHMARK**. This parameter is mandatory.
	-**tp [TESTPART]**: specifies the part to test. This parameter can be used independently.
	-**tm [TESTMODULE]**: specifies the module to test. This parameter must be specified together with **-tp**.
	-**ts [TESTSUITE]**: specifies the test suite. This parameter can be used independently.
	-**tc [TESTCASE]**: specifies the test case. This parameter must be specified together with **-ts** to indicate the test suite.
	-**cov [COVERAGE]**: specifies the coverage.
	-**h**: displays help information.
	-**ra [random]**: specifies the out-of-order execution for C++ cases.
	-**pd [partdeps]**: specifies execution parameter of the level-2 part dependencies.
	--**repeat**: specifies the number of case execution times.
	-**hl [HISTORYLIST]**: enables the display of the latest 10 test cases. If there are more than 10 test cases, only the latest 10 test cases are displayed.
	-**rh [RUNHISTORY]**: specifies the sequence number of the historical record to execute.
	--**retry**: checks the last execution result and re-runs the failed test cases, if any.
	```

	In Linux, you can run the following commands to view the supported product forms, test types, subsystems, and parts.
	```
	To view the help information, run **help**.
	To view the **show** command, run **help show**.
	To view the supported product forms, run **show productlist**.
	To view the supported test types, run **show typelist**.
	To view the supported test subsystems, run **show subsystemlist** .
	To view the supported test parts, run **show partlist**.
	```
	2. ACTS/HATS commands

	After selecting the product, you can refer to the following to execute the ACTS or HATS test cases.
	```
	run -t ACTS
	run -t HATS
	run -t ACTS -ss arkui
	run -t ACTS -ss arkui, modulemanager
	run -t ACTS -ss arkui -ts ActsAceEtsTest
	run -t HATS -ss telephony -ts HatsHdfV1RilServiceTest
	run -t ACTS -ss arkui -tp ActsPartName
	run -t ACTS -ss arkui -ts ActsAceEtsTest,ActsAceEtsResultTest
	run -t HATS -ss powermgr -ts HatsPowermgrBatteryTest,HatsPowermgrThermalTest
	run -t ACTS -ss arkui -ts ActsAceEtsTest -ta class:alphabetIndexerTest#alphabetIndexerTest001
	run -t ACTS -ss arkui -ts ActsAceEtsTest -ta class:alphabetIndexerTest#alphabetIndexerTest001 --repeat 2
	run -hl
	run -rh 1
	run --retry
	```
	The parameters in the ACTS and HATS commands are the same, but are different from those in TDD commands.
	```
	-**t [TESTTYPE]**: specifies the test case type, which can be **ACTS** or **HATS**. This parameter is mandatory.
	-**ss [SUBSYSTEM]**: specifies the subsystem to test. This parameter can be used independently. To specify multiple subsystems, separate them with commas (,).
	-**tp [TESTPART]**: specifies the part to test. This parameter can be used independently.
	-**ts [TESTSUITE]**: specifies the test suite. This parameter can be used independently. To specify multiple test suites, separate them with commas (,).
	-**ta [TESTARGS]**: specifies the test method. This parameter must be used together with **-ts**.
	--**repeat**: specifies the number of case execution times.
	-**hl [HISTORYLIST]**: enables the display of the latest 10 test cases. If there are more than 10 test cases, only the latest 10 test cases are displayed.
	-**rh [RUNHISTORY]**: specifies the sequence number of the historical record to execute.
	--**retry**: checks the last execution result and re-runs the failed test cases, if any.
	```

## Viewing the Test Result


After the test is executed, the console automatically generates the test result.

You can obtain the test result in the following directory:
```
test/developertest/reports/xxxx_xx_xx_xx_xx_xx
```
> **NOTE** 
>  
> The test report folder is automatically generated.

The folder contains the following files:
| Type                                | Description              |
| ------------------------------------ | ------------------ |
| result/                              | Test cases in standard format.|
| log/plan_log_xxxx_xx_xx_xx_xx_xx.log | Test case logs.               |
| summary_report.html                  | Test report summary.          |
| details_report.html                  | Detailed test report.         |



## Executing Coverage Cases
When GCDA data is available, you can execute the test cases as follows for subsystems to generate a coverage report:

1. (Optional) To block redundant branch data generated by non-core code, run the following command in the **/test/testfwk/developer_test/localCoverage/restore_comment** directory before source code compilation:

       python3 build_before_generate.py

   Run the following command to select the parts to be blocked during compilation:

       run -tp partname
       run -tp partname1 partname2
   
2. Before compiling the version, modify the compilation options. Add **-- coverage** to the **cflags**, **cflags_cc**, and **ldflags** options in the **build.gn** file of the involved subsystem.
       
       ldflags = [ "--coverage" ]
       C:   cflags = [ "--coverage" ]
       C++: cflags_cc = [ "--coverage" ]
   
   **Recommended**: You can also refer to the mode for the window subsystem. For details, see the files in this [pull request](https://gitee.com/openharmony/window_window_manager/pulls/1274/files).
   
3. To execute coverage test cases, perform the following to install the dependencies:
   
       1. Run the **sudo apt install lcov** command to install lcov.
       2. Run the **apt install dos2unix** command to install dos2unix.
       3. Run the **pip install lxml** command to install lxml.
       4. Run the **pip install selectolax** command to install selectolax.
       5. Run the **pip install CppHeaderParser** command to install CppHeaderParser.

4. To map a remote device, set its IP address in the **usr_config.xml** file. For details about device mapping, see [Configuring Remote Port Mapping and Modifying Configuration File](#configuring-remote-port-mapping-and-modifying-configuration-file).

       <!-- Set the IP address of the remote host to map (IP address of the PC to which the device is mounted).-->
       <device type="usb-hdc">
         <ip></ip>
         <port></port>
         <sn></sn>
       </device>

5. Run the **./start.sh** command. Below are examples:

       run -t UT -tp *Part name* -cov coverage
       run -t UT -ss *Subsystem name* -cov coverage
       run -t UT -ss *Subsystem name* -tp **Part name** -cov coverage
       run -t UT MST ST -tp *Part name* -cov coverage

   > **NOTE**
   >
   > The **-cov coverage** parameter must be added to the preceding commands.

6. Obtain the coverage report from the following paths:

   Code coverage report: **/test/testfwk/developer_test/localCoverage/codeCoverage/results/coverage/reports/cxx/html**

   API coverage report: **/test/testfwk/developer_test/localCoverage/interfaceCoverage/results/coverage/interface_kits/html**
