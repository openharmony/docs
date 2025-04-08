# 开发自测试执行框架使用指南


## 概述

OpenHarmony为开发者提供了一套全面的开发自测试框架developer_test，作为OpenHarmony测试工具集的一部分，提供给开发者自测试使用。开发者可根据测试需求开发相关测试用例，开发阶段提前发现缺陷，大幅提高代码质量。

本文从基础环境构建，用例开发，编译以及执行等方面介绍OpenHarmony开发自测试执行框架如何运行和使用。


### 简介

OpenHarmony系统开发人员在新增或修改代码之后，希望可以快速的验证修改代码的功能的正确性，而系统中已经存在了大量的已有功能的自动化测试用例，比如TDD用例或XTS用例等。开发者自测试执行框架目的就是为了提升开发者的自测试执行效率，方便开发人员可以快速便捷的执行指定的自动化测试用例，将测试活动左移到开发阶段。


### 约束与限制

框架使用时必须提前连接OpenHarmony设备方可执行测试用例。


## 环境准备

开发自测试框架依赖于python运行环境，python版本为3.7.5及以上版本，在使用测试框架之前可参见以下方式进行配置。

源码获取可[参考此链接](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/get-code/sourcecode-acquire.md)。

### 自测试框架基础环境依赖

| 环境依赖          | 版本型号                                                     | 详细说明                                                     |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 操作系统          | Ubuntu20.04及以上                                            | 代码编译环境。                                                 |
| Linux系统扩展组件 | libreadline-dev                                              | 命令行读取插件。                                               |
| python            | 3.7.5版本及以上                                              | 测试框架语言。                                                 |
| python插件        | pyserial 3.3及以上、paramiko2.7.1及以上、setuptools40.8.0及以上、rsa4.0及以上 | pserial：支持python的串口通信；paramiko：支持python使用SSH协议；setuptools：支持python方便创建和分发python包；rsa：支持python rsa加密。 |
| NFS Server        | haneWIN NFS Server 1.2.50及以上或者 NFS v4及以上             | 支持设备通过串口连接，使用轻量、小型设备。                     |
| HDC               | 1.2.0a                                                        | 支持设备通过HDC连接。                                         |



1. 安装Ubuntu的步骤如下：

	参考此文[OpenHarmony-标准设备系统代码操作梳理](https://blog.csdn.net/nanzhanfei/article/details/121951919)，按照第二章“WSL2安装”步骤操作，即可完成Ubuntu的安装。由于Ubuntu20已自带python3.8.5，无需再次安装python。

2. 安装Linux扩展组件readline，安装命令如下：

    ```bash
    sudo apt-get install libreadline-dev
    ```
    安装成功提示如下：
    ```
    Reading package lists... Done
    Building dependency tree
    Reading state information... Done
    libreadline-dev is already the newest version (7.0-3).
    0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
    ```

2. 安装setuptools插件，安装命令如下：
    ```bash
    pip3 install setuptools
    ```
    安装成功提示如下：
    ```
    Requirement already satisfied: setuptools in d:\programs\python37\lib\site-packages (41.2.0)
    ```

3. 安装paramiko插件，安装命令如下：
    ```bash
    pip3 install paramiko
    ```
    安装成功提示如下：
    ```
    Installing collected packages: pycparser, cffi, pynacl, bcrypt, cryptography, paramiko
    Successfully installed bcrypt-3.2.0 cffi-1.14.4 cryptography-3.3.1 paramiko-2.7.2 pycparser-2.20 pynacl-1.4.0
    ```

4. 安装python的rsa插件，安装命令如下：
    ```bash
    pip3 install rsa
    ```
    安装成功提示如下：
    ```
    Installing collected packages: pyasn1, rsa
    Successfully installed pyasn1-0.4.8 rsa-4.7
    ```

5. 安装串口插件pyserial，安装命令如下：
    ```bash
    pip3 install pyserial
    ```
    安装成功提示如下：
    ```
    Requirement already satisfied: pyserial in d:\programs\python37\lib\site-packages\pyserial-3.4-py3.7.egg (3.4)
    ```

6. 如果设备仅支持串口输出测试结果，则需要安装NFS Server。

	> **说明：** 
	> 
	> 此操作针对小型或轻量设备，不针对标准设备。

    - Windows环境下安装，安装haneWIN NFS Server1.2.50软件包。
    - Linux环境下安装，安装命令如下：
    ```bash
    sudo apt install nfs-kernel-server
    ```
    安装成功提示如下：
    ```
    Reading package lists... Done
    Building dependency tree
    Reading state information... Done
    nfs-kernel-server is already the newest version (1:1.3.4-2.1ubuntu5.3).
    0 upgraded, 0 newly installed, 0 to remove and 11 not upgraded.
    ```

7. 如果设备支持HDC连接，则需要安装HDC工具，安装流程请参考[HDC-OpenHarmony设备连接器](https://gitee.com/openharmony/developtools_hdc/blob/master/README_zh.md)。


### 环境依赖检查

| 检查项                                             | 操作                                                | 满足环境                  |
| -------------------------------------------------- | --------------------------------------------------- | ------------------------- |
| 检查python安装成功                                 | 命令行窗口执行命令：python --version。                | 版本不小于3.7.5即可。       |
| 检查python扩展插件安装成功                         | 打开test/developertest目录，执行start.bat或start.sh。 | 可进入提示符“>>>”界面即可。 |
| 检查NFS Server启动状态（被测设备仅支持串口时检测） | 通过串口登录开发板，执行mount命令挂载NFS。            | 可正常挂载文件目录即可。    |
| 检查HDC安装成功                                    | 命令行窗口执行命令：hdc -v。                     | 版本不小于1.2.0a即可。       |


## 编写测试用例

本测试框架支持多种类型测试，针对不同测试类型提供了不同的用例编写模板以供参考。

**TDD测试（C++）**

- 用例源文件命名规范。

    测试用例源文件名称和测试套内容保持一致，文件命名采用全小写+下划线格式，以test结尾，具体格式为：[功能]_[子功能]_test，子功能支持向下细分。


- 单线程用例示例及编写步骤，以calculator_sub_test.cpp为例进行说明：
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
        // input testsuit setup step，setup invoked before all testcases.
    }
    
    void CalculatorSubTest::TearDownTestCase(void)
    {
        // input testsuit teardown step，teardown invoked after all testcases.
    }
    
    void CalculatorSubTest::SetUp(void)
    {
        // input testcase setup step，setup invoked before each testcases.
    }
    
    void CalculatorSubTest::TearDown(void)
    {
        // input testcase teardown step，teardown invoked after each testcases.
    }
    
    /**
     * @tc.name: integer_sub_001
     * @tc.desc: Verify the sub function.
     * @tc.type: FUNC
     * @tc.require: issueNumber
     */
    HWTEST_F(CalculatorSubTest, integer_sub_001, TestSize.Level1)
    {
        // step 1:调用函数获取结果。
        int actual = Sub(4，0)；
    
        // Step 2:使用断言比较预期与实际结果。
        EXPECT_EQ(4, actual);
    }
    ```
    详细内容介绍：
    1. 添加测试用例文件头注释信息。
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
    2. 引用测试框架头文件和命名空间。
	    ```
    	#include <gtest/gtest.h>
    	
    	using namespace testing::ext;
    	```
    3. 添加被测试类的头文件。
	    ```
    	#include "calculator.h"
    	```
    4. 定义测试套（测试类）。
		> **注意：** 在定义测试套时，测试套名称应与编译目标保持一致，采用大驼峰风格。
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
    	    // input testsuit setup step，setup invoked before all testcases.
    	}
        
    	void CalculatorSubTest::TearDownTestCase(void)
    	{
    	    // input testsuit teardown step，teardown invoked after all testcases.
    	}
        
    	void CalculatorSubTest::SetUp(void)
    	{
    	    // input testcase setup step，setup invoked before each testcases.
    	}
        
    	void CalculatorSubTest::TearDown(void)
    	{
    	    // input testcase teardown step，teardown invoked after each testcases.
    	}
    	```

    5. 测试用例实现，包含用例注释和逻辑实现。
	    ```
    	/**
    	 * @tc.name: integer_sub_001
    	 * @tc.desc: Verify the sub function.
    	 * @tc.type: FUNC
    	 * @tc.require: issueNumber
    	 */
    	HWTEST_F(CalculatorSubTest, integer_sub_001, TestSize.Level1)
    	{
    	    //step 1:调用函数获取结果.
    	    int actual = Sub(4，0)；
        
    	    //Step 2:使用断言比较预期与实际结果.
    	    EXPECT_EQ(4, actual);
    	}
    	```
		> **注意：** @tc.require的取值必须以AR/SR或issue开头，如：issueI56WJ7。

- 多线程用例示例及编写步骤，以base_object_test.cpp为例进行说明：
    ```
    // 测试用例文件头注释信息及用例注释同单线程用例示例。
    
    #include "base_object.h"
    #include <gtest/gtest.h>
	#include <gtest/hwext/gtest-multithread.h>
	#include <unistd.h>
    
    using namespace testing::ext;
    using namespace testing::mt;

	namespace OHOS {
	namespace AAFwk {
    class AAFwkBaseObjectTest : public testing::Test {......}

	// Step 1:待测函数，返回阶乘结果。
	int factorial(int n)
	{
		int result = 1;
		for (int i = 1; i <= n; i++) {
			result *= i;
		}
		printf("Factorial Function Result : %d! = %d\n", n, result);
		return result;
	} 

	// Step 2:使用断言比较预期与实际结果。
	void factorial_test()
	{
		int ret = factorial(3); // 调用函数获取结果。
		std::thread::id this_id = std::this_thread::get_id();
		std::ostringstream oss;
		oss << this_id;
		std::string this_id_str = oss.str();
		long int thread_id = atol(this_id_str.c_str());
		printf("running thread...: %ld\n", thread_id); // 输出当前线程的id。
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

	}  // namespace AAFwk.
	}  // namespace OHOS.

    ```
    详细内容介绍：
    1. 添加测试用例文件头注释信息。

		> **注意：** 与单线程用例标准一致。

    2. 引用测试框架头文件和命名空间。
	    ```
    	#include <gtest/gtest.h>
    	#include <gtest/hwext/gtest-multithread.h>
		#include <unistd.h>
    	using namespace testing::ext;
   		using namespace testing::mt;
    	```
    3. 添加被测试类的头文件。
	    ```
    	#include "base_object.h"
    	```
    4. 定义测试套（测试类）。
	    ```
    	class AAFwkBaseObjectTest : public testing::Test {......}

    	```
	    > **注意：** 与单线程用例标准一致。

    5. 测试用例实现，包含用例注释和逻辑实现。

	    ```
		// Step 1:待测函数，返回阶乘结果。
		int factorial(int n)
		{
			int result = 1;
			for (int i = 1; i <= n; i++) {
				result *= i;
			}
			printf("Factorial Function Result : %d! = %d\n", n, result);
			return result;
		} 
	
		// Step 2:使用断言比较预期与实际结果。
		void factorial_test()
		{
			int ret = factorial(3); // 调用函数获取结果。
			std::thread::id this_id = std::this_thread::get_id();
			std::ostringstream oss;
			oss << this_id;
			std::string this_id_str = oss.str();
			long int thread_id = atol(this_id_str.c_str());
			printf("running thread...: %ld\n", thread_id); // 输出当前线程的id。
			EXPECT_EQ(ret, 6);
		}

		// GTEST_RUN_TASK(TestFunction)多线程启动函数，参数为自定义函数。
		// 未调用SET_THREAD_NUM()时，默认线程数10个。		
    	HWTEST_F(AAFwkBaseObjectTest, Factorial_test_001, TestSize.Level1)
    	{
			SET_THREAD_NUM(4); // 设置线程数量，同一测试套中可动态设置线程数。
			printf("Factorial_test_001 BEGIN\n");
			GTEST_RUN_TASK(factorial_test); // 启动factorial_test任务的多线程执行。
			printf("Factorial_test_001 END\n");
    	}

		// HWMTEST_F(TEST_SUITE, TEST_TC, TEST_LEVEL, THREAD_NUM).
		// THREAD_NUM可设置用例执行的线程数量。
		// HWMTEST_F会创建指定数量的线程并执行被测函数。
    	HWMTEST_F(AAFwkBaseObjectTest, Factorial_test_002, TestSize.Level1, 6)
    	{
			printf("Factorial_test_002 BEGIN\n");
			factorial_test();
			printf("Factorial_test_002 END\n");
    	}
		// 新增多线程接口MTEST_ADD_TASK(THREAD_ID,ThreadTestFunc)，注册多线程，但不在该用例中执行，之后统一执行，适合多个用例组合场景下的多线程测试。
		// THREAD_ID从0开始定义区别不同的线程，也可以使用随机THREAD_ID，即传入RANDOM_THREAD_ID，此场景下THREAD_ID是不会重复的。
		// 新增多线程接口MTEST_POST_RUN()，统一执行之前注册的多线程用例。
    	```
		> **注意：** 多线程用例注释与单线程用例标准一致。

- C++用例模板说明：
		
	在编写用例时，我们提供了四种用例模板供您选择。

	|      类型 |    描述 |
	| ------------| ------------|
	| HWTEST(A,B,C)| 用例执行不依赖Setup&Teardown时，可选取。|
	| HWTEST_F(A,B,C)| 用例执行（不含参数）依赖于Setup&Teardown时，可选取。|
	| HWMTEST_F(A,B,C,D)| 多线程用例执行依赖于Setup&Teardown时，可选取。|
	| HWTEST_P(A,B,C)| 用例执行（含参数）依赖于Set&Teardown时，可选取。|


	其中，参数A，B，C的含义如下：

	- 参数A为测试套名。

	- 参数B为测试用例名，其命名必须遵循[功能点]_[编号]的格式，编号为3位数字，从001开始。

	- 参数C为测试用例等级，具体分为门禁level0 以及非门禁level1-level4共五个等级，其中非门禁level1-level4等级的具体选取规则为：测试用例功能越重要，level等级越低。

	- 参数D为多线程用例执行的线程数量设置。

	**注意：**

	- 测试用例的预期结果必须有对应的断言。

	- 测试用例必须填写用例等级。

	- 测试体建议按照模板分步实现。

	- 用例描述信息按照标准格式@tc.xxx value书写，注释信息必须包含用例名称，用例描述，用例类型，需求编号四项。其中用例测试类型@tc.type参数的选取，可参考下表。


		| 测试类型名称 | 类型编码 |
		| ------------ | -------- |
		| 功能测试     | FUNC     |
		| 性能测试     | PERF     |
		| 可靠性测试   | RELI     |
		| 安全测试     | SECU     |
		| 模糊测试     | FUZZ     |

**TDD测试（JavaScript）**

- 用例源文件命名规范。


	测试用例原文件名称采用大驼峰风格，以Test结尾，具体格式为：[功能][子功能]Test，子功能支持向下细分。
	示例：
	```
	AppInfoTest.js
	```

- 用例示例。

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
			// input testsuit setup step，setup invoked before all testcases.
			console.info('beforeAll caled')
		})
		
		afterAll(function() {
			// input testsuit teardown step，teardown invoked after all testcases.
			console.info('afterAll caled')
		})
		
		beforeEach(function() {
			// input testcase setup step，setup invoked before each testcases.
			console.info('beforeEach caled')
		})
		
		afterEach(function() {
			// input testcase teardown step，teardown invoked after each testcases.
			console.info('afterEach caled')
		})

		/*
		* @tc.name:appInfoTest001
		* @tc.desc:verify app info is not null
		* @tc.type: FUNC
		* @tc.require: issueNumber
		*/
		it("appInfoTest001", 0, function () {
			//step 1:调用函数获取结果。
			var info = app.getInfo()

			//Step 2:使用断言比较预期与实际结果。
			expect(info != null).assertEqual(true)
		})
	})
	```
	详细内容介绍：
	1. 添加测试用例文件头注释信息。
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
	2. 导入被测api和jsunit测试库。
		```js
		import app from '@system.app'
		
		import {describe, beforeAll, beforeEach, afterEach, afterAll, it, expect} from 'deccjsunit/index'
		```
	3. 定义测试套（测试类）。
		```js
		describe("AppInfoTest", function () {
			beforeAll(function() {
				// input testsuit setup step，setup invoked before all testcases.
				console.info('beforeAll caled')
			})
			
			afterAll(function() {
				// input testsuit teardown step，teardown invoked after all testcases.
				console.info('afterAll caled')
			})
			
			beforeEach(function() {
				// input testcase setup step，setup invoked before each testcases.
				console.info('beforeEach caled')
			})
			
			afterEach(function() {
				// input testcase teardown step，teardown invoked after each testcases.
				console.info('afterEach caled')
			})
		```
	4. 测试用例实现。
		```JS
		/*
		* @tc.name:appInfoTest001
		* @tc.desc:verify app info is not null
		* @tc.type: FUNC
		* @tc.require: issueNumber
		*/
		it("appInfoTest001", 0, function () {
			//step 1:调用函数获取结果。
			var info = app.getInfo()
		
			//Step 2:使用断言比较预期与实际结果。
			expect(info != null).assertEqual(true)
		})
		```
		> **注意：** @tc.require的取值必须以AR/SR或issue开头，如：issueI56WJ7。

**TDD测试（Rust）**

- 用例源文件命名规范。

    测试用例源文件名称和测试套内容保持一致，测试套命名采用全小写rust_+下划线格式，以test结尾，具体格式为：rust_[功能]_[子功能]_test，子功能支持向下细分。


- Rust用例示例及编写步骤，以rust_add_test.rs为例进行说明：
    ```Rust
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
    
    /// pub add.
    pub fn add(a: i32, b: i32) -> i32 {
        a + b
    }

    #[allow(dead_code)]
    pub fn bad_add(a: i32, b: i32) -> i32 {
        a - b
    }
    
    #[cfg(test)]
    mod tests {
        use super::*;
        #[test]
        fn test_add() {
            assert_eq!(add(1, 2), 3);
        }
        #[test]
        fn test_bad_add() {
            assert_eq!(bad_add(1, 2), 3);
        }
    }
    ```
    详细内容介绍：
    1. 添加测试用例文件头注释信息。
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
    2. 定义测试类。
	    ```Rust
        /// pub add
        pub fn add(a: i32, b: i32) -> i32 {
            a + b
        }

        #[allow(dead_code)]
        pub fn bad_add(a: i32, b: i32) -> i32 {
            a - b
        }
    	```
    3. 测试用例实现。
	    ```Rust
        #[cfg(test)]
        mod tests {
            use super::*;

            #[test]
            fn test_add() {
                assert_eq!(add(1, 2), 3);
            }

            #[test]
            fn test_bad_add() {
                assert_eq!(bad_add(1, 2), 3);
           }
        }
    	```
        > **注意：** #[cfg(test)]属性将测试代码标记为测试模块，并使用#[test]属性标记测试函数，这样才能被Rust的测试框架识别为测试函数。

**Fuzzing安全测试**

[Fuzzing安全测试用例编写规范](https://gitee.com/openharmony/testfwk_developer_test/blob/master/libs/fuzzlib/README_zh.md)


**Benchmark测试**

[Benchmark用例编写规范](https://gitee.com/openharmony/testfwk_developer_test/blob/master/libs/benchmark/README_zh.md)

## 编译测试用例

根据测试用例目录规划，当执行某一用例时，测试框架会根据编译文件逐层查找，最终找到所需用例进行编译。下面通过不同示例来讲解gn文件如何编写。

**TDD测试**

针对不同语言，下面提供不同的编译模板以供参考。

- **C++用例编译配置示例**

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
	详细内容如下：

	1. 添加文件头注释信息。
		```
		# Copyright (c) 2023 XXXX Device Co., Ltd.
		```
	2. 导入编译模板文件。
		```
		import("//build/test.gni")
		```
	3. 指定文件输出路径。
		```
		module_output_path = "developertest/calculator"
		```
		> **说明：** 
		> 
		> 此处输出路径为部件/模块名。

	4. 配置依赖包含目录。

		```
		config("module_private_config") {
		visibility = [ ":*" ]
		
		include_dirs = [ "../../../include" ]
		}
		```
		> **说明：** 
		>  
		> 一般在此处对相关配置进行设置，在测试用例编译脚本中可直接引用。

	5. 指定测试用例编译目标输出的文件名称。

		```
		ohos_unittest("CalculatorSubTest") {
		}
		```
	6. 编写具体的测试用例编译脚本（添加需要参与编译的源文件、配置和依赖）。
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

		> **说明：** 
		> 
		> 根据测试类型的不同，在具体编写过程中可选择不同的测试类型。
		> - ohos_unittest：单元测试。
        > - ohos_js_unittest: FA模型js用例单元测试。
        > - ohos_js_stage_unittest: stage模型ArkTs用例单元测试。
		> - ohos_moduletest：模块测试。
		> - ohos_systemtest：系统测试。
		> - ohos_performancetest：性能测试。
		> - ohos_securitytest：安全测试。
		> - ohos_reliabilitytest：可靠性测试。
		> - ohos_distributedtest：分布式测试。

	7. 对目标测试用例文件进行条件分组。

		```
		group("unittest") {
		testonly = true
		deps = [":CalculatorSubTest"]
		}
		```
		> **说明：** 
		>  
		> 进行条件分组的目的在于执行用例时可以选择性地执行某一种特定类型的用例。

- **JavaScript用例编译配置示例**

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

	详细内容如下：

	1. 添加文件头注释信息。

		```
		# Copyright (C) 2023 XXXX Device Co., Ltd.
		```

	2. 导入编译模板文件。

		```
		import("//build/test.gni")
		```

	3. 指定文件输出路径。

		```
		module_output_path = "developertest/app_info"
		```
		> **说明：** 
		> 
		> 此处输出路径为部件/模块名。

	4. 指定测试用例编译目标输出的文件名称。

		```
		ohos_js_unittest("GetAppInfoJsTest") {
		}
		```
		> **说明：** 
		> 
		> - 使用模板ohos_js_unittest定义js测试套，注意与C++用例区分。
		> - js测试套编译输出文件为hap类型，hap名为此处定义的测试套名，测试套名称必须以JsTest结尾。

	5. 指定hap包配置文件config.json和签名文件，两个配置为必选项。

		```
		ohos_js_unittest("GetAppInfoJsTest") {
		module_out_path = module_output_path
		
		hap_profile = "./config.json"
		certificate_profile = "//test/developertest/signature/openharmony_sx.p7b"
		}
		```
		config.json为hap编译所需配置文件，需要开发者根据被测sdk版本配置“target”项，其余项可默认，具体如下所示：

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
				"target": 5     // 根据被测sdk版本进行修改，此例为sdk5。
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
 
	6. 对目标测试用例文件进行条件分组。

		```
		group("unittest") {
		testonly = true
		deps = [ ":GetAppInfoJsTest" ]
		}
		```
		> **说明：** 
		> 
		> 进行条件分组的目的在于执行用例时可以选择性地执行某一种特定类型的用例。

- **stage模型ArkTs用例编译配置示例**

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
	详细内容如下：

	1. 添加文件头注释信息。

		```
		# Copyright (C) 2023 XXXX Device Co., Ltd.
		```

	2. 导入编译模板文件。

		```
		import("//build/test.gni")
		```

	3. 指定文件输出路径。

		```
		want_output_path = "developertest/stage_test"
		```
		> **说明：** 
		> 
		> 此处输出路径为部件/模块名。

	4. 指定测试用例编译目标输出的文件名称。

		```
		ohos_js_stage_unittest("ActsBundleMgrStageEtsTest") {
		}
		```
		> **说明：** 
		> 
		> 使用模板ohos_js_stage_unittest定义stage模型的ArkTs测试套。

	5. 指定配置文件module.json、签名文件、部件名称和编译输出路径，都为必选项。

		```
		ohos_js_stage_unittest("ActsBundleMgrStageEtsTest") {
        hap_profile = "entry/src/main/module.json"
        certificate_profile = "signature/openharmony_sx.p7b"
        subsystem_name = "developertest"
        part_name = "stage_test"  // 部件名称。
		}
		```

	6. 指定配置资源文件（添加需要参与编译的源文件、配置和依赖）。
		```
		# 声明一个HAP的AppScope模块，该目标的app_profile和sources会在编译时拼接到具体的entry内编译。
		ohos_app_scope("actbmsstageetstest_app_profile") {
        app_profile = "AppScope/app.json"
        sources = [ "AppScope/resources" ]
		}

		# stage模型用例代码分别放置到ets目录下。
		ohos_js_assets("actbmsstageetstest_js_assets") {
        source_dir = "entry/src/main/ets"
		}

		# 源文件，Stage模型编译后放置在resources目录下。
		ohos_resources("actbmsstageetstest_resources") {
        sources = [ "entry/src/main/resources" ]
        deps = [ ":actbmsstageetstest_app_profile" ]
        hap_profile = "entry/src/main/module.json"
		}

		```

   7. 对目标测试用例文件进行条件分组。

       ```
       group("unittest") {
       testonly = true
       deps = [ ":GetAppInfoJsTest" ]
       }
       ```
		> **说明：** 
		> 
		> 进行条件分组的目的在于执行用例时可以选择性地执行某一种特定类型的用例。

- **Rust用例编译配置示例**

	```
    #Copyright (C) 2023 XXXX Device Co., Ltd.

    import("//build/ohos.gni")
    import("//build/test.gni")

    module_output_path = "developer_test/rust_add_test"
    ohos_rust_unittest("rust_add_test") {
        module_out_path = module_output_path
        sources = [
		    "main.rs",
		    "rust_add_test.rs",
             ...
        }
        deps = [ ":rust_st_add" ]
    }

    group("unittest") {
        testonly = true
        deps = [ ":rust_add_test" ]
    }
	```

	详细内容如下：

	1. 添加文件头注释信息。

        ```
        #Copyright (C) 2023 XXXX Device Co., Ltd.
        ```
	2. 导入编译模板文件。

        ```
        import("//build/ohos.gni")
        import("//build/test.gni")
        ```
	3. 指定文件输出路径。

        ```
        module_output_path = "developer_test/rust_add_test"
        ```
        > **说明：**
        > 此处输出路径为部件/模块名。

	4. 指定测试用例编译目标输出的文件名称。

        ```
        ohos_rust_unittest("rust_add_test") {
        }
        ```
        > **说明：**
        > - 使用模板ohos_rust_unittest定义rust的unittest测试套，注意与C++用例区分。
        > - 测试套名称必须以rust_开头。
        > - 还可以使用模板ohos_rust_systemtest定义rust的systemtest测试套。

**编译入口配置文件bundle.json**

当完成用例编译配置文件编写后，需要进一步编写部件编译配置文件，以关联到具体的测试用例。
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
    "test": [ //配置模块calculator下的test。
      "//test/testfwk/developer_test/examples/app_info/test:unittest",  
      "//test/testfwk/developer_test/examples/calculator/test:unittest",
      "//test/testfwk/developer_test/examples/calculator/test:fuzztest"
 }
```
> **说明：** 
> 
> test_list中配置的是对应模块的测试用例。

## 配置测试资源

测试依赖资源主要包括测试用例在执行过程中需要的图片文件、视频文件、第三方库等对外的文件资源，目前只支持静态资源的配置。

依赖资源文件配置步骤如下：

1. 在部件的test目录下创建resource目录，在resource目录下创建对应的模块，在模块目录中存放该模块所需要的资源文件。

2. 在resource目录下对应的模块目录中创建一个ohos_test.xml文件，文件内容格式如下:

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

 3. 在测试用例的编译配置文件中定义resource_config_file进行指引，用来指定对应的资源文件ohos_test.xml。

	```
	ohos_unittest("CalculatorSubTest") {
	resource_config_file = "//system/subsystem/partA/test/resource/calculator/ohos_test.xml"
	}
	```
	> **说明：** 
	> 
	>- target_name: 测试套的名称，定义在测试目录的BUILD.gn中。preparer: 表示该测试套执行前执行的动作。
	>- src="res": 表示测试资源位于test目录下的resource目录下，src="out"：表示位于out/release/$(部件)目录下。

## 执行测试用例

### user_config.xml配置文件介绍

在执行测试用例之前，针对用例使用设备的不同，需要对相应配置进行修改，配置文件路径为developer_test\config\user_config.xml，修改完成即可执行测试用例。

```xml
<user_config>
  <build>
    <!-- 是否编译demo用例，默认为false，如果需要编译demo可修改为true -->
    <example>false</example>
    <!-- 是否编译版本，默认为false -->
    <version>false</version>
    <!-- 是否编译测试用例，默认为true，若已完成编译，再执行用例之前可修改为false，防止重新编译 -->
    <testcase>true</testcase>
	<!-- 在编译测试用例的情况下，选择编译target_cpu是64位的还是32位的，默认为空（32bit）可以选择: arm64 -->
    <parameter>
       <target_cpu></target_cpu>
    </parameter>
  </build>
  <environment>
    <!-- 配置远程映射机器的IP及端口，以支持HDC连接的设备 -->
    <device type="usb-hdc">
      \<ip\></ip>
      \<port\></port>
      \<sn\></sn>
    </device>
    <!-- 配置设备的串口信息，以支持串口连接的设备 -->
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
  <!-- 配置测试用例路径，若测试用例未编译，即<testcase>标签属性为true时，此处默认不填写；若编译已完成，需在此处指定测试用例的实际路径 -->
  <test_cases>
    <dir></dir>
  </test_cases>
  <!-- 配置覆盖率编译路径 -->
  <coverage>
    <outpath></outpath>
  </coverage>
  <!-- NFS挂载信息配置，被测设备仅支持串口连接时配置，指定NFS的映射路径，host_dir为PC侧的NFS目录，board_dir为板侧创建的目录 -->
  <NFS>
    <host_dir></host_dir>
    <mnt_cmd></mnt_cmd>
    <board_dir></board_dir>
  </NFS>
</user_config>
```
> **说明：** 
> 
> 在执行测试用例之前，若使用HDC连接设备，用例仅需配置设备IP和端口号即可，其余信息均默认不修改。

### Windows环境执行
#### 编译测试用例

由于Windows环境下无法实现用例编译，因此执行用例前需要在Linux环境下进行用例编译，用例编译命令：
```
./build.sh --product-name {product_name} --build-target make_test
```

> **说明：** 
> 
>- product-name：指定编译产品名称。
>- build-target：指定所需编译用例，make_test表示指定全部用例，实际开发中可指定特定用例。

编译完成后，测试用例将自动保存在out/ohos-arm-release/packages/phone/tests目录下。

#### 搭建执行环境
1. 在Windows环境创建测试框架目录Test，并在此目录下创建testcase目录。

2. 从Linux环境拷贝测试框架developertest和xdevice到创建的Test目录下，拷贝编译好的测试用例到testcase目录下。
	
	> **说明：** 
	>  
	> 将测试框架及测试用例从Linux环境移植到Windows环境，以便后续执行。
	
3. 修改user_config.xml。
	```xml
	<build>
	  <!-- 由于测试用例已编译完成，此标签属性需改为false -->
	  <testcase>false</testcase>
	</build>
	<test_cases>
	  <!-- 由于已将测试用例拷贝到Windows环境下，测试用例输出路径发生改变，需要修改为拷贝后所存放的路径 -->
	  <dir>D:\Test\testcase\tests</dir>
	</test_cases>
	```
	> **说明：** 
	>  
	> `<testcase>`标签表示是否需要编译用例；`<dir>`标签表示测试用例查找路径。

#### 执行用例命令

1. 启动测试框架。
	```
	start.bat
	```
2. 选择产品形态。

    进入测试框架，系统会自动提示您选择产品形态，请根据实际的开发板进行选择。

	如需手动添加，请在config/framework_config.xml的\<productform\>标签内增加产品项。

3. 执行测试用例。

    当选择完产品形态，可参考如下指令执行TDD测试用例。
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

	
	执行命令参数说明：
	```
	-t [TESTTYPE]: 指定测试用例类型，有UT，MST，ST，PERF，FUZZ，BENCHMARK，另外还有ACTS，HATS等。（必选参数）
	-tp [TESTPART]: 指定部件，可独立使用。
	-tm [TESTMODULE]: 指定模块，不可独立使用，需结合-tp指定上级部件使用。
	-ts [TESTSUITE]: 指定测试套，可独立使用。
	-tc [TESTCASE]: 指定测试用例，同时需要注明测试套内class名称，不可独立使用，需结合-ts指定上级测试套使用。
	-cov [COVERAGE]: 覆盖率执行参数。
	-h : 帮助命令。
	-ra [random]: c++用例乱序执行参数。
	--repeat : 支持设置用例执行次数。
	-hl [HISTORYLIST]: 显示最近10条测试用例，超过10条，只显示最近10条。
	-rh [RUNHISTORY]: 执行历史记录的第几条记录运行。
	--retry：检查上次运行结果，如果有失败用例则重复测试。
	```

	
### Linux环境执行


#### 映射远程端口及修改配置文件
为支持Linux远程服务器以及Linux虚拟机两种环境下执行测试用例，需要对端口进行远程映射，以实现与设备的数据通路连接。具体操作如下：
1. HDC Server指令：
	```
	hdc_std kill
	hdc_std -m -s 0.0.0.0:8710
	```
	> **说明：** 
	> 
	> IP和端口号为默认值。

2. HDC Client指令：
	```
	hdc_std -s xx.xx.xx.xx:8710 list targets
	```
	> **说明：** 
	> 
	> 此处IP填写设备侧IP地址。

3. 修改配置文件user_config.xml。
	```xml
	<build>
	  <!-- 测试用例需要编译时，此标签属性为true，反之为false -->
	  <testcase>true</testcase>
	</build>
	<environment>
    <!-- 需要配置IP为远程映射机器的IP，端口即为8710，sn号为设备的sn号，以支持HDC连接的设备 -->
    <device type="usb-hdc">
      \<ip\></ip>
      \<port\></port>
      \<sn\></sn>
    </device>
	<environment>
	```


#### 执行用例命令
1. 启动测试框架。
	```
	./start.sh
	```
2. 选择产品形态。

    进入测试框架，系统会自动提示您选择产品形态，请根据实际的开发板进行选择。

	若需要自测试框架编译测试用例，且没有找到需要的产品形态需手动添加，请在config/framework_config.xml的\<productform\>标签内增加产品项。

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

3. 执行测试用例。

    1） TDD命令。

    测试框架在执行用例时会根据指令找到所需用例，自动实现用例编译，执行过程，完成自动化测试。
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
	执行命令参数说明：
	```
	-t [TESTTYPE]: 指定测试用例类型（必选参数），有UT，MST，ST，PERF，FUZZ，BENCHMARK等。
	-tp [TESTPART]: 指定部件，可独立使用。
	-tm [TESTMODULE]: 指定模块，不可独立使用，需结合-tp指定上级部件使用。
	-ts [TESTSUITE]: 指定测试套，可独立使用。
	-tc [TESTCASE]: 指定测试用例，同时需要注明测试套内class名称，不可独立使用，需结合-ts指定上级测试套使用。
	-cov [COVERAGE]: 覆盖率执行参数。
	-h : 帮助命令。
	-ra [random]: c++用例乱序执行参数。
	-pd [partdeps]: 二级依赖部件执行参数。
	--repeat : 支持设置用例执行次数。
	-hl [HISTORYLIST]: 显示最近10条测试用例，超过10条，只显示最近10条。
	-rh [RUNHISTORY]: 执行历史记录的第几条记录运行。
	--retry：检查上次运行结果，如果有失败用例则重复测试。
	```

	在Linux下可以使用help命令查看有哪些产品形态、测试类型、支持的子系统、部件。
	```
	查看帮助命令：help
	查看show命令：help show
	查看支持的设备形态：   show productlist
	查看支持的测试类型：   show typelist
	查看支持的测试子系统： show subsystemlist
	查看支持的测试部件：   show partlist
	```
	2） ACTS/HATS命令。

	当选择完产品形态，可以参考如下执行ACTS或HATS测试用例。
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
	执行命令参数说明，ACTS和HATS命令参数一致，与TDD有所不同：
	```
	-t [TESTTYPE]: 指定测试用例类型（必选参数），有ACTS，HATS等。
	-ss [SUBSYSTEM]: 指定子系统，可单独使用，且可以执行多个子系统，用逗号隔开。
	-tp [TESTPART]: 指定部件，可独立使用。
	-ts [TESTSUITE]: 指定测试套，可独立使用，且可以执行多个测试套，用逗号隔开。
	-ta [TESTARGS]: 指定测试类测试方法，需结合-ts指定上级测试套使用。
	--repeat : 支持设置用例执行次数。
	-hl [HISTORYLIST]: 显示最近10条测试用例，超过10条，只显示最近10条。
	-rh [RUNHISTORY]: 执行历史记录的第几条记录运行。
	--retry：检查上次运行结果，如果有失败用例则重复测试。
	```

## 查看测试结果


当执行完测试指令，控制台会自动生成测试结果，若需要详细测试报告，您可在以下路径中进行查找相应的数据文档。

测试结果输出根路径如下：
```
test/developertest/reports/xxxx_xx_xx_xx_xx_xx
```
> **说明：** 
>  
> 测试报告文件目录将自动生成。

该目录中包含以下几类结果：
| 类型                                 | 描述               |
| ------------------------------------ | ------------------ |
| result/                              | 测试用例格式化结果。 |
| log/plan_log_xxxx_xx_xx_xx_xx_xx.log | 测试用例日志。       |
| summary_report.html                  | 测试报告汇总。       |
| details_report.html                  | 测试报告详情。       |



## 执行覆盖率用例
各子系统可按照以下方式，执行用例，生成gcda数据后方可生成覆盖率报告。

1. （可选执行）为了屏蔽非核心代码产生的冗余分支数据，可以在源码编译之前进入/test/testfwk/developer_test/localCoverage/restore_comment目录下执行：

       python3 build_before_generate.py

   选择编译时要屏蔽的部件，执行命令例如：

       run -tp partname
       run -tp partname1 partname2
2. 编译版本之前首先修改编译选项，在涉及到的子系统build.gn文件中添加cflags或cflags_cc及ldflags选项，都需要加--coverage字段：
       
       ldflags = [ "--coverage" ]
       C:   cflags = [ "--coverage" ]
       C++: cflags_cc = [ "--coverage" ]
            
   **推荐：**     也可以参考窗口子系统的方式（推荐这种方式），参考链接：https://gitee.com/openharmony/window_window_manager/pulls/1274/files
3. 执行覆盖率用例需要安装以下依赖包：
   
       1）安装lcov, 安装命令：sudo apt install lcov
       2）安装dos2unix, 安装命令：apt install dos2unix.
       3）安装lxml, 安装命令: pip install lxml
       4）安装selectolax, 安装命令: pip install selectolax
       5）安装CppHeaderParser, 安装命令 pip install CppHeaderParser

4. 远程映射设备，修改usr_config.xml中的ip号，设备映射方式查看上面介绍的远程端口映射。

       <!-- 配置远程映射机器的IP(设备挂载的pc的ip) -->
       <device type="usb-hdc">
         \<ip\></ip>
         \<port\></port>
         \<sn\></sn>
       </device>

5. 执行 ./start.sh，输入运行命令，示例如下：

       run -t UT -tp 部件名 -cov coverage
       run -t UT -ss 子系统名 -cov coverage
       run -t UT -ss 子系统名 -tp 部件名 -cov coverage
       run -t UT MST ST -tp 部件名 -cov coverage

   **注意：** 执行以上命令必须添加 -cov coverage 参数。

6. 从以下路径获取覆盖率报告：

   代码覆盖率报告：/test/testfwk/developer_test/localCoverage/codeCoverage/results/coverage/reports/cxx/html

   接口覆盖率报告：/test/testfwk/developer_test/localCoverage/interfaceCoverage/results/coverage/interface_kits/html
