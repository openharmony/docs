# 开发自测试执行框架使用指南


## 概述

OpenHarmony为开发者提供了一套全面的开发自测试框架developer_test，作为OpenHarmony测试工具集的一部分，提供给开发者自测试使用。开发者可根据测试需求开发相关测试用例，开发阶段提前发现缺陷，大幅提高代码质量。

本文从基础环境构建，用例开发，编译以及执行等方面介绍OpenHarmony开发自测试执行框架如何运行和使用。


### 简介

OpenHarmony系统开发人员在新增或修改代码之后，希望可以快速的验证修改代码的功能的正确性，而系统中已经存在了大量的已有功能的自动化测试用例，比如TDD用例或XTS用例等。开发者自测试执行框架目的就是为了提升开发者的自测试执行效率，方便开发人员可以快速便捷的执行指定的自动化测试用例，将测试活动左移到开发阶段。


### 约束与限制

- 框架使用时必须提前连接OpenHarmony设备方可执行测试用例。


## 环境准备

开发自测试框架依赖于python运行环境,python版本为3.7.5及以上版本,在使用测试框架之前可参阅以下方式进行配置。

源码获取可[参考](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/get-code/sourcecode-acquire.md)。

### 自测试框架基础环境依赖

| 环境依赖          | 版本型号                                                     | 详细说明                                                     |
| ----------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| 操作系统          | Ubuntu18.04及以上                                            | 代码编译环境                                                 |
| Linux系统扩展组件 | libreadline-dev                                              | 命令行读取插件                                               |
| python            | 3.7.5版本及以上                                              | 测试框架语言                                                 |
| python插件        | pyserial 3.3及以上、paramiko2.7.1及以上、setuptools40.8.0及以上、rsa4.0及以上 | pserial：支持python的串口通信；paramiko：支持python使用SSH协议；setuptools：支持python方便创建和分发python包；rsa：支持python rsa加密 |
| NFS Server        | haneWIN NFS Server 1.2.50及以上或者 NFS v4及以上             | 支持设备通过串口连接，使用轻量、小型设备                     |
| HDC               | 1.1.0                                                        | 支持设备通过HDC连接                                          |



1. 安装Linux扩展组件readline，安装命令如下：

    ```
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
    ```
    pip3 install setuptools
    ```
    安装成功提示如下：
    ```
    Requirement already satisfied: setuptools in d:\programs\python37\lib\site-packages (41.2.0)
    ```

3. 安装paramiko插件，安装命令如下：
    ```
    pip3 install paramiko
    ```
    安装成功提示如下：
    ```
    Installing collected packages: pycparser, cffi, pynacl, bcrypt, cryptography, paramiko
    Successfully installed bcrypt-3.2.0 cffi-1.14.4 cryptography-3.3.1 paramiko-2.7.2 pycparser-2.20 pynacl-1.4.0
    ```

4. 安装python的rsa插件，安装命令如下：
    ```
    pip3 install rsa
    ```
    安装成功提示如下：
    ```
    Installing collected packages: pyasn1, rsa
    Successfully installed pyasn1-0.4.8 rsa-4.7
    ```

5. 安装串口插件pyserial，安装命令如下：
    ```
    pip3 install pyserial
    ```
    安装成功提示如下：
    ```
    Requirement already satisfied: pyserial in d:\programs\python37\lib\site-packages\pyserial-3.4-py3.7.egg (3.4)
    ```

6. 如果设备仅支持串口输出测试结果，则需要安装NFS Server

    > 针对小型或轻量设备

    - Windows环境下安装，安装haneWIN NFS Server1.2.50软件包。
    - Linux环境下安装，安装命令如下：
    ```
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

7. 如果设备支持HDC连接，则需要安装HDC工具，安装流程请参考[HDC-OpenHarmony设备连接器](https://gitee.com/openharmony/developtools_hdc_standard/blob/master/README_zh.md)。


### 环境依赖检查

| 检查项                                             | 操作                                                | 满足环境                  |
| -------------------------------------------------- | --------------------------------------------------- | ------------------------- |
| 检查python安装成功                                 | 命令行窗口执行命令：python --version                | 版本不小于3.7.5即可       |
| 检查python扩展插件安装成功                         | 打开test/developertest目录，执行start.bat或start.sh | 可进入提示符“>>>”界面即可 |
| 检查NFS Server启动状态（被测设备仅支持串口时检测） | 通过串口登录开发板，执行mount命令挂载NFS            | 可正常挂载文件目录即可    |
| 检查HDC安装成功                                    | 命令行窗口执行命令：hdc_std -v                      | 版本不小于1.1.0即可       |


## 编写测试用例

本测试框架支持多种类型测试，针对不同测试类型提供了不同的用例编写模板以供参考。_

**TDD测试（C++）**

用例源文件命名规范

测试用例源文件名称和测试套内容保持一致，文件命名采用全小写+下划线方式命名，以test结尾，具体格式为：[功能]_[子功能]_test，子功能支持向下细分。
示例：
```
calculator_sub_test.cpp
```

用例示例
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
    // input testsuit setup step，setup invoked before all testcases
}

void CalculatorSubTest::TearDownTestCase(void)
{
    // input testsuit teardown step，teardown invoked after all testcases
}

void CalculatorSubTest::SetUp(void)
{
    // input testcase setup step，setup invoked before each testcases
}

void CalculatorSubTest::TearDown(void)
{
    // input testcase teardown step，teardown invoked after each testcases
}

/**
 * @tc.name: integer_sub_001
 * @tc.desc: Verify the sub function.
 * @tc.type: FUNC
 * @tc.require: issueNumber
 */
HWTEST_F(CalculatorSubTest, integer_sub_001, TestSize.Level1)
{
    // step 1:调用函数获取结果
    int actual = Sub(4，0)；

    // Step 2:使用断言比较预期与实际结果
    EXPECT_EQ(4, actual);
}
```
详细内容介绍：

1.添加测试用例文件头注释信息

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

2.引用测试框架头文件和命名空间

```
#include <gtest/gtest.h>

using namespace testing::ext;
```

3.添加被测试类的头文件

```
#include "calculator.h"
```

4.定义测试套（测试类）

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
    // input testsuit setup step，setup invoked before all testcases
}

void CalculatorSubTest::TearDownTestCase(void)
{
    // input testsuit teardown step，teardown invoked after all testcases
}

void CalculatorSubTest::SetUp(void)
{
    // input testcase setup step，setup invoked before each testcases
}

void CalculatorSubTest::TearDown(void)
{
    // input testcase teardown step，teardown invoked after each testcases
}
```
> **注意：** 在定义测试套时，测试套名称应与编译目标保持一致，采用大驼峰风格。

5.测试用例实现，包含用例注释和逻辑实现

```
/**
 * @tc.name: integer_sub_001
 * @tc.desc: Verify the sub function.
 * @tc.type: FUNC
 * @tc.require: issueNumber
 */
HWTEST_F(CalculatorSubTest, integer_sub_001, TestSize.Level1)
{
    //step 1:调用函数获取结果
    int actual = Sub(4，0)；

    //Step 2:使用断言比较预期与实际结果
    EXPECT_EQ(4, actual);
}
```
> **注意：** @tc.require: 格式必须以AR/SR或issue开头： 如：issueI56WJ7

在编写用例时，我们提供了三种用例模板供您选择。

| 类型            | 描述                                             |
| --------------- | ------------------------------------------------ |
| HWTEST(A,B,C)   | 用例执行不依赖Setup&Teardown时，可选取           |
| HWTEST_F(A,B,C) | 用例执行(不含参数)依赖于Setup&Teardown时，可选取 |
| HWTEST_P(A,B,C) | 用例执行(含参数)依赖于Set&Teardown时，可选取     |

其中，参数A，B，C的含义如下：

- 参数A为测试套名。

- 参数B为测试用例名，其命名必须遵循[功能点]_[编号]的格式，编号为3位数字，从001开始。

- 参数C为测试用例等级，具体分为门禁level0 以及非门禁level1-level4共五个等级，其中非门禁level1-level4等级的具体选取规则为：测试用例功能越重要，level等级越低。


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

**TDD测试（JS）**

- 用例源文件命名规范


测试用例原文件名称采用大驼峰风格，以TEST结尾，具体格式为：[功能][子功能]TEST，子功能支持向下细分。
示例：
```
AppInfoTest.js
```

- 用例示例

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
import app from '@system.app'

import {describe, beforeAll, beforeEach, afterEach, afterAll, it, expect} from 'deccjsunit/index'

describe("AppInfoTest", function () {
    beforeAll(function() {
        // input testsuit setup step，setup invoked before all testcases
         console.info('beforeAll caled')
    })
    
    afterAll(function() {
         // input testsuit teardown step，teardown invoked after all testcases
         console.info('afterAll caled')
    })
    
    beforeEach(function() {
        // input testcase setup step，setup invoked before each testcases
         console.info('beforeEach caled')
    })
    
    afterEach(function() {
        // input testcase teardown step，teardown invoked after each testcases
         console.info('afterEach caled')
    })

    /*
     * @tc.name:appInfoTest001
     * @tc.desc:verify app info is not null
     * @tc.type: FUNC
     * @tc.require: issueNumber
     */
    it("appInfoTest001", 0, function () {
        //step 1:调用函数获取结果
        var info = app.getInfo()

        //Step 2:使用断言比较预期与实际结果
        expect(info != null).assertEqual(true)
    })
})
```
详细内容介绍：
1. 添加测试用例文件头注释信息
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
2. 导入被测api和jsunit测试库
    ```
	import app from '@system.app'
	
	import {describe, beforeAll, beforeEach, afterEach, afterAll, it, expect} from 'deccjsunit/index'
	```
3. 定义测试套（测试类）
    ```
	describe("AppInfoTest", function () {
	    beforeAll(function() {
	        // input testsuit setup step，setup invoked before all testcases
	         console.info('beforeAll caled')
	    })
	    
	    afterAll(function() {
	         // input testsuit teardown step，teardown invoked after all testcases
	         console.info('afterAll caled')
	    })
	    
	    beforeEach(function() {
	        // input testcase setup step，setup invoked before each testcases
	         console.info('beforeEach caled')
	    })
	    
	    afterEach(function() {
	        // input testcase teardown step，teardown invoked after each testcases
	         console.info('afterEach caled')
	    })
	```
4. 测试用例实现
    ```
	/*
	 * @tc.name:appInfoTest001
	 * @tc.desc:verify app info is not null
	 * @tc.type: FUNC
	 * @tc.require: issueNumber
	 */
	 it("appInfoTest001", 0, function () {
	    //step 1:调用函数获取结果
        var info = app.getInfo()
	
        //Step 2:使用断言比较预期与实际结果
        expect(info != null).assertEqual(true)
	 })
	```
	> **注意：** @tc.require: 格式必须以AR/SR或issue开头： 如：issueI56WJ7

**Fuzz测试**

[Fuzz用例编写规范](https://gitee.com/openharmony/test_developertest/blob/master/libs/fuzzlib/README_zh.md)


**Benchmark测试**

[Benchmark用例编写规范](https://gitee.com/openharmony/test_developertest/blob/master/libs/benchmark/README_zh.md)_

## 编译测试用例

根据测试用例目录规划，当执行某一用例时，测试框架会根据编译文件逐层查找，最终找到所需用例进行编译。下面通过不同示例来讲解gn文件如何编写。

**TDD测试**

针对不同语言，下面提供不同的编译模板以供参考。

- **C++用例编译配置示例**

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
详细内容如下：

1. 添加文件头注释信息
    ```
	# Copyright (c) 2021 XXXX Device Co., Ltd.
	```
2. 导入编译模板文件
    ```
	import("//build/test.gni")
	```
3. 指定文件输出路径
	```
	module_output_path = "developertest/calculator"
	```
	> **说明：** 此处输出路径为部件/模块名。

4. 配置依赖包含目录

	```
	config("module_private_config") {
	  visibility = [ ":*" ]
	   
	  include_dirs = [ "../../../include" ]
	}
	```
	> **说明：** 一般在此处对相关配置进行设置，在测试用例编译脚本中可直接引用。

5. 指定测试用例编译目标输出的文件名称

	```
	ohos_unittest("CalculatorSubTest") {
	}
	```
6. 编写具体的测试用例编译脚本（添加需要参与编译的源文件、配置和依赖）
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

    > **说明：根据测试类型的不同，在具体编写过程中可选择不同的测试类型：**
	 > - ohos_unittest：单元测试
	 > - ohos_moduletest：模块测试
	 > - ohos_systemtest：系统测试
	 > - ohos_performancetest：性能测试
	 > - ohos_securitytest：安全测试
	 > - ohos_reliabilitytest：可靠性测试
	 > - ohos_distributedtest：分布式测试

7. 对目标测试用例文件进行条件分组

	```
	group("unittest") {
	  testonly = true
	  deps = [":CalculatorSubTest"]
	}
	```
	> **说明：** 进行条件分组的目的在于执行用例时可以选择性的执行某一种特定类型的用例。

- **JavaScript用例编译配置示例**

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

详细内容如下：

1.添加文件头注释信息

```
# Copyright (C) 2021 XXXX Device Co., Ltd.
```

2.导入编译模板文件

```
import("//build/test.gni")
```

3.指定文件输出路径

```
module_output_path = "developertest/app_info"
```
> **说明：** 此处输出路径为部件/模块名。

4.指定测试用例编译目标输出的文件名称

```
ohos_js_unittest("GetAppInfoJsTest") {
}
```
> **说明：**
> - 使用模板ohos_js_unittest定义js测试套，注意与C++用例区分。
> - js测试套编译输出文件为hap类型，hap名为此处定义的测试套名，测试套名称必须以JsTest结尾。

5.指定hap包配置文件config.json和签名文件，两个配置为必选项

```
ohos_js_unittest("GetAppInfoJsTest") {
  module_out_path = module_output_path
   
  hap_profile = "./config.json"
  certificate_profile = "//test/developertest/signature/openharmony_sx.p7b"
}
```
 config.json为hap编译所需配置文件，需要开发者根据被测sdk版本配置“target”项，其余项可默认，具体如下所示：

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
         "target": 5     // 根据被测sdk版本进行修改，此例为sdk5
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

6.对目标测试用例文件进行条件分组

```
group("unittest") {
  testonly = true
  deps = [ ":GetAppInfoJsTest" ]
}
```
> **说明：** 进行条件分组的目的在于执行用例时可以选择性的执行某一种特定类型的用例。

**Fuzz测试**

[Fuzz编译文件编写规范](https://gitee.com/openharmony/test_developertest/blob/master/libs/fuzzlib/README_zh.md)

**Benchmark测试**

[Benchmark编译文件编写规范](https://gitee.com/openharmony/test_developertest/blob/master/libs/benchmark/README_zh.md)
      

**编译入口配置文件ohos.build**

当完成用例编译配置文件编写后，需要进一步编写部件编译配置文件，以关联到具体的测试用例。
```
"partA": {
    "module_list": [
          
    ],
    "inner_list": [
          
    ],
    "system_kits": [
          
    ],
    "test_list": [ //配置模块calculator下的test
      "//system/subsystem/partA/calculator/test:unittest",  
      "//system/subsystem/partA/calculator/test:fuzztest",
      "//system/subsystem/partA/calculator/test:benchmarktest"
 }
```
> **说明：** test_list中配置的是对应模块的测试用例。

## 测试资源配置

试依赖资源主要包括测试用例在执行过程中需要的图片文件，视频文件、第三方库等对外的文件资源。

依赖资源文件配置步骤如下：

1.在部件的test目录下创建resource目录，在resource目录下创建对应的模块，在模块目录中存放该模块所需要的资源文件

2.在resource目录下对应的模块目录中创建一个ohos_test.xml文件，文件内容格式如下:

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

3.在测试用例的编译配置文件中定义resource_config_file进行指引，用来指定对应的资源文件ohos_test.xml

```
ohos_unittest("CalculatorSubTest") {
  resource_config_file = "//system/subsystem/partA/test/resource/calculator/ohos_test.xml"
}
```
>**说明：**
>- target_name: 测试套的名称，定义在测试目录的BUILD.gn中。preparer: 表示该测试套执行前执行的动作。
>- src="res": 表示测试资源位于test目录下的resource目录下，src="out"：表示位于out/release/$(部件)目录下。

## 执行测试用例

### 配置文件

在执行测试用例之前，针对用例使用设备的不同，需要对相应配置进行修改，修改完成即可执行测试用例。

#### user_config.xml配置
```
<user_config>
  <build>
    <!-- 是否编译demo用例, 默认为false，如果需要编译demo可修改为true -->
    <example>false</example>
    <!-- 是否编译版本, 默认为false -->
    <version>false</version>
    <!-- 是否编译测试用例, 默认为true，若已完成编译，再执行用例之前可修改为false，防止重新编译 -->
    <testcase>true</testcase>
	<!-- 在编译测试用例的情况下，选择编译target_cpu是64位的还是32位的，默认为空（32bit）可以选择: arm64 -->
    <parameter>
       <target_cpu></target_cpu>
    </parameter>
  </build>
  <environment>
    <!-- 配置远程映射机器的IP及端口，以支持HDC连接的设备 -->
    <device type="usb-hdc">
      <ip></ip>
      <port></port>
      <sn></sn>
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
>**说明：** 在执行测试用例之前，若使用HDC连接设备，用例仅需配置设备IP和端口号即可，其余信息均默认不修改。

### 执行命令说明

1. 启动测试框架
	```
	start.bat
	```
2. 选择产品形态

    进入测试框架，系统会自动提示您选择产品形态，请根据实际的开发板进行选择。

	如需手动添加，请在config/framework_config.xml的\<productform\>标签内增加产品项。

3. 执行测试用例

    当选择完产品形态，可参考如下指令执行测试用例。
	```
	run -t UT -ts CalculatorSubTest -tc interger_sub_00l
	```
	执行命令参数说明：
	```
	-t [TESTTYPE]: 指定测试用例类型，有UT，MST，ST，PERF，FUZZ，BENCHMARK等。（必选参数）
	-tp [TESTPART]: 指定部件，可独立使用。
	-tm [TESTMODULE]: 指定模块，不可独立使用，需结合-tp指定上级部件使用。
	-ts [TESTSUITE]: 指定测试套，可独立使用。
	-tc [TESTCASE]: 指定测试用例，不可独立使用，需结合-ts指定上级测试套使用。
	-h : 帮助命令。

#### Windows环境执行

由于Windows环境下无法实现用例编译，因此执行用例前需要在Linux环境下进行用例编译，用例编译命令：
```
./build.sh --product-name {product_name} --build-target make_test
```

>说明: 
>- product-name：指定编译产品名称。
>- build-target：指定所需编译用例，make_test表示指定全部用例，实际开发中可指定特定用例。

编译完成后，测试用例将自动保存在out/ohos-arm-release/packages/phone/tests目录下。

##### 搭建执行环境
1. 在Windows环境创建测试框架目录Test，并在此目录下创建testcase目录

2. 从Linux环境拷贝测试框架developertest和xdevice到创建的Test目录下，拷贝编译好的测试用例到testcase目录下
	
	>**说明：** 将测试框架及测试用例从Linux环境移植到Windows环境，以便后续执行。
	
3. 修改user_config.xml
	```
	<build>
	  <!-- 由于测试用例已编译完成，此标签属性需改为false -->
	  <testcase>false</testcase>
	</build>
	<test_cases>
	  <!-- 由于已将测试用例拷贝到Windows环境下，测试用例输出路径发生改变，需要修改为拷贝后所存放的路径 -->
	  <dir>D:\Test\testcase\tests</dir>
	</test_cases>
	```
	>**说明：** `<testcase>`标签表示是否需要编译用例；`<dir>`标签表示测试用例查找路径。

#### Linux环境执行

如是直接连接Linux机器，则可直接使用上面的执行命令执行命令

##### 远程端口映射
为支持Linux远程服务器以及Linux虚拟机两种环境下执行测试用例，需要对端口进行远程映射，以实现与设备的数据通路连接。具体操作如下：
1. HDC Server指令：
	```
	hdc_std kill
	hdc_std -m -s 0.0.0.0:8710
	```
	>**说明：** IP和端口号为默认值。

2. HDC Client指令：
	```
	hdc_std -s xx.xx.xx.xx:8710 list targets
	```
	>**说明：** 此处IP填写设备侧IP地址。

## 查看测试结果

### 测试报告日志

当执行完测试指令，控制台会自动生成测试结果，若需要详细测试报告您可在相应的数据文档中进行查找。

### 测试结果
测试结果输出根路径如下：
```
test/developertest/reports/xxxx_xx_xx_xx_xx_xx
```
>**说明：** 测试报告文件目录将自动生成。

该目录中包含以下几类结果：
| 类型                                 | 描述               |
| ------------------------------------ | ------------------ |
| result/                              | 测试用例格式化结果 |
| log/plan_log_xxxx_xx_xx_xx_xx_xx.log | 测试用例日志       |
| summary_report.html                  | 测试报告汇总       |
| details_report.html                  | 测试报告详情       |

### 测试框架日志
```
reports/platform_log_xxxx_xx_xx_xx_xx_xx.log
```

### 最新测试报告
```
reports/latest
```
