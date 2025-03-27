# XTS测评用例开发指导


## 简介

XTS子系统是OpenHarmony兼容性测评套件的集合，当前包括acts（application compatibility test suite）应用兼容性测试套件，后续会拓展dcts（device compatibility test suite）设备兼容性测试套件等。

XTS子系统当前包括acts与tools软件包：

- acts，存放acts相关测试用例源码与配置文件，其目的是帮助终端设备厂商尽早发现软件与OpenHarmony的不兼容性，确保软件在整个开发过程中满足OpenHarmony的兼容性要求。

- tools，存放acts相关测试用例开发框架。


## 系统类型

支持如下几种系统类型：

- 轻量系统（mini system）
  面向MCU类处理器例如Arm Cortex-M、RISC-V 32位的设备，硬件资源极其有限，支持的设备最小内存为128KiB，可以提供多种轻量级网络协议，轻量级的图形框架，以及丰富的IOT总线读写部件等。可支撑的产品如智能家居领域的连接类模组、传感器设备、穿戴类设备等。

- 小型系统（small system）
  面向应用处理器例如Arm Cortex-A的设备，支持的设备最小内存为1MiB，可以提供更高的安全能力、标准的图形框架、视频编解码的多媒体能力。可支撑的产品如智能家居领域的IP Camera、电子猫眼、路由器以及智慧出行域的行车记录仪等。

- 标准系统（standard system）
  面向应用处理器例如Arm Cortex-A的设备，支持的设备最小内存为128MiB，可以提供增强的交互能力、3D GPU以及硬件合成能力、更多控件以及动效更丰富的图形能力、完整的应用框架。可支撑的产品如高端的冰箱显示屏。


## 目录


```
/test/xts
├── acts                # 测试代码存放目录。
│   └── subsystem       # 标准系统子系统测试用例源码存放目录。
│   └── subsystem_lite  # 轻量系统、小型系统子系统测试用例源码存放目录。
│   └── BUILD.gn        # 标准系统测试用例编译配置。
│   └── build_lite      # 轻量系统、小型系统测试用例编译配置存放目录。
│       └── BUILD.gn    # 轻量系统、小型系统测试用例编译配置。
└── tools               # 测试工具代码存放目录。
```


## 约束

轻量系统用例开发语言是C，小型系统用例开发语言是C++。


## 使用说明

  **表1** 用例级别说明

| 级别名称 | 基本定义 | 测试范围 | 
| -------- | -------- | -------- |
| Level0 | 冒烟 | 验证关键功能点基本功能/最基本DFX属性在最常见输入下的表现，通过表示功能基本可运行。 | 
| Level1 | 基本 | 验证各功能点基本功能/基本DFX属性在常见输入下的表现，通过表示功能基本可测试。 | 
| Level2 | 重要 | 验证各功能点的基本功能/基本DFX属性在常规输入/常见异常情况下的表现，通过表示功能基本正常可用，可开展Beta。 | 
| Level3 | 一般 | 验证各功能点的全部功能/全部DFX属性在各种常规/非常规输入组合下，或各种正常/异常预置条件组合下的表现。 | 
| Level4 | 生僻 | 验证关键功能点在极端异常预置条件下、用户难以触及的异常输入组合下的表现。 | 

  **表2** 用例粒度说明

| 用例规模 | 被测试对象 | 测试环境 | 
| -------- | -------- | -------- |
| LargeTest | 业务功能/全场景特性/整机及场景级DFX | 尽量使用贴近真实的环境设备。 | 
| MediumTest | 模块/子系统集成至设备后的功能/DFX | 使用真实的单设备进行验证，可进行消息模拟，尽量不对函数进行MOCK。 | 
| SmallTest | 模块/类/函数 | 在开发者个人环境进行测试，尽量不依赖其他模块，存在大量的MOCK。 | 

  **表3** 测试类型说明

| 测试类型名称 | 测试类型定义 | 
| -------- | -------- |
| Function | 验证被测对象提供给用户的业务功能实现正确性的测试项，这里的“用户”可以是终端用户或开发者，功能包括业务功能及平台功能。 | 
| Performance | 验证被测对象在特定预置条件/负载模型下的处理能力的测试项，“处理能力”一般以单位时间内可处理的业务量来衡量，如呼叫/秒，帧率/秒，事件处理量/秒等。 | 
| Power | 验证被测对象在特定预置条件/负载模型下在一定时间内能源消耗量的测试项。 | 
| Reliability | 验证被测对象在正常/异常输入情况下，或业务量压力和长时间连续运行压力情况下业务表现的测试项，含稳定性、压力、故障注入、Monkey测试项。 | 
| Security | 验证系统对恶意威胁的防护能力，威胁包括但不限于未授权访问、使用、泄露、破坏、修改、毁灭，以保障信息的机密性、完整性和可用性；验证系统对用户隐私的保护能力，保障用户的隐私数据被收集、使用、保有、披露和处置符合法律规范，保障用户的隐私权；验证对各类安全规范的遵从情况，如安全设计规范、安全红线、工信部安全认证规范等，保障安全相关法律法规的合规。 | 
| Global | 验证被测对象在是否具有国际化数据支持和本地化能力的测试项，包括语言显示、输入/输出习惯、时间显示、区域特性如货币时间禁忌等等。 | 
| Compatibility | 当被测对象为应用时，包括被测对象对于自身数据的后向兼容性、对于系统的前后向兼容性、对于不同用户数据(如播放器之音频文件格式/智能短信之用户短信内容)的兼容性测试项；&nbsp;当被测对象为系统时，包括被测系统对于系统自身数据的后向兼容性、以及对于生态中常用应用的兼容性测试项；当被测对象为软件时，包括被测软件对于相关的硬件的兼容性。 | 
| User | 验证被测对象在真实用户场景下的用户体验感受的测试项，注意此种情况下没有客观的“正确”与“失败”，所有的结论及评价都应该来自于用户。 | 
| Standard | 验证被测对象对于行业及公司内标准/协议/规范的遵从情况的测试项，注意此处的“标准”不包含任何安全标准，针对安全标准的测试项划归为“安全测试”类型。 | 
| Safety | 验证被测对象的Safety属性，避免产品可能对人身安全、健康以及产品本身带来的危害。 | 
| Resilience | 验证被测对象的韧性属性，确保系统受攻击时承受并保持在有定义的运行状态（包括降级）、恢复并适应攻击以保障Mission达成。 | 


## 用例开发指导

根据测试系统选择测试框架和对应测试用例语言。

  **表4** 系统和测试框架、开发语言对应关系

| 系统 | 测试框架 | 语言 | 
| -------- | -------- | -------- |
| 轻量系统 | hctest | c | 
| 小型系统 | hcpptest | c++ |
| 标准系统 | HJSUnit、hcpptest | js、c++ | 

### C语言用例开发编译指导（适用于轻量系统产品用例开发）

**示例：轻量系统测试用例开发**

当前使用的测试框架是hctest，hctest测试框架支持使用C语言编写测试用例，是在开源测试框架unity的基础上进行增强和适配。

1. 用例目录规范：测试用例存储到test/xts/acts仓中。
   
   ```
   ├── acts
   │ └──subsystem_lite
   │ │ └── module_hal
   │ │ │ └── BUILD.gn
   │ │ │ └── src
   │ └──build_lite
   │ │ └── BUILD.gn
   ```

2. src目录下用例编写样例。
   
    1. 引用测试框架
    
       ```
       #include "hctest.h"
       ```

   2. 使用宏定义LITE_TEST_SUIT定义子系统、模块、测试套件名称。

   
      ```
      /**  
      * @brief  register a test suite named "IntTestSuite"  
      * @param  test subsystem name  
      * @param  example module name  
      * @param  IntTestSuite test suite name  
      */
       LITE_TEST_SUIT(test, example, IntTestSuite);
      ```

   3. 定义Setup与TearDown。

      命名方式：测试套件名称+Setup，测试套件名称+TearDown。

      Setup与TearDown必须存在，可以为空函数。

   4. 使用宏定义LITE_TEST_CASE写测试用例。

      包括三个参数：测试套件名称，测试用例名称，用例属性（测试类型、用例粒度、用例级别）。
      ```
      LITE_TEST_CASE(IntTestSuite, TestCase001, Function | MediumTest | Level1) 
      {  
        //do something. 
         };
      ```
   5. 使用宏定义 RUN_TEST_SUITE注册测试套件。

   
      ```
      RUN_TEST_SUITE(IntTestSuite);
      ```

3. 测试模块的配置文件（BUILD.gn）样例：
   在每个测试模块目录下新建BUILD.gn编译文件，用于指定编译后静态库的名称、依赖的头文件、依赖的库等；具体写法如下：

   
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

4. acts下BUILD.gn增加编译选项。
   需要将测试模块加入到acts目录下的编译脚本中，编译脚本路径：test/xts/acts/build_lite/BUILD.gn。

   
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

5. 测试套件编译命令。
   随版本编译，debug版本编译时会同步编译acts测试套件。

   > ![icon-note.gif](../public_sys-resources/icon-note.gif) **说明：**
   > acts测试套件编译中间件为静态库，最终链接到版本镜像中。

### C语言用例执行指导（适用于轻量系统产品用例开发）

**示例：轻量系统测试用例执行**

将版本镜像烧录进开发板。

**测试步骤**

1. 使用串口工具登录开发板，并保存串口打印信息。

2. 重启设备，查看串口日志。

**测试结果分析指导**

基于串口打印日志进行分析；

每个测试套件执行以Start to run test suite开始，以xx Tests xx Failures xx Ignored结束。


### C++语言用例开发编译指导（适用于小型系统、标准系统用例开发）

**示例：小型系统测试用例开发**（标准参考具体样例目录：global/i18n_standard）

当前使用的测试框架是hcpptest，hcpptest测试框架是在开源的googletest测试框架的基础上进行的增强和适配。

1. 规范用例目录：测试用例存储到test/xts/acts仓中。
   
   ```
   ├── acts
   │ └──subsystem_lite
   │ │ └── module_posix
   │ │ │ └── BUILD.gn
   │ │ │ └── src
   │ └──build_lite
   │ │ └── BUILD.gn
   ```

2. 测试模块src下用例编写样例：
   1. 引用测试框架：

      需要引用gtest.h  如：\#include "gtest/gtest.h"

   
      ```
      #include "gtest/gtest.h"
      ```

   2. 定义Setup与TearDown。

   
      ```
      using namespace std;
      using namespace testing::ext;
      class TestSuite: public testing::Test {
      protected:
      // Preset action of the test suite, which is executed before the first test case.
      static void SetUpTestCase(void){
      }
      // Test suite cleanup action, which is executed after the last test case.
      static void TearDownTestCase(void){
      }
      // Preset action of the test case.
      virtual void SetUp()
      {
      }
      // Cleanup action of the test case.
      virtual void TearDown()
      {
      }
      };
      ```

   3. 使用宏定义HWTEST或HWTEST_F写测试用例。

      普通测试用例的定义：HWTEST（测试套名称， 测试用例名称， 用例标注）。

      包含SetUp和TearDown的测试用例的定义 ：HWTEST_F（测试套名称， 测试用例名称，用例标注）。
    
      宏定义包括三个参数：测试套件名称，测试用例名称，用例属性（测试类型、用例粒度、用例级别）。

   
      ```
      HWTEST_F(TestSuite, TestCase_0001, Function | MediumTest | Level1) {
      // do something.
      }
      ```

3. 测试模块下用例配置文件（BUILD.gn）样例。

   每个测试模块目录下新建BUILD.gn编译文件，用于指定编译后可执行文件的名称、依赖的头文件、依赖的库等；具体写法如下。每个测试模块将独立编译成.bin可执行文件， 该文件可直接push到单板上进行测试。

   举例：
   
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

4. acts目录下增加编译选项（BUILD.gn）样例。

   将测试模块加入到acts目录下的编译脚本中，编译脚本为：test/xts/acts/build_lite/BUILD.gn。

   
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

5. 测试套件编译命令。
     随版本编译，debug版本编译时会同步编译acts测试套件。
   > ![icon-note.gif](../public_sys-resources/icon-note.gif) **说明：**
   > 小型系统acts独立编译成可执行文件（bin格式）， 在编译产物的suites\acts目录下归档。


### C++语言用例执行指导（适用于小型系统、标准系统用例开发）

**示例：小型系统测试用例执行**

目前的用例执行采用nfs共享的方式，mount到单板去执行。

**环境搭建**

1. 使用有限网线或无线将开发板与PC进行连接。

2. 开发板配置IP、子网掩码、网关，确保开发板与PC处于同一个网段。

3. PC安装nfs服务器并完成注册，启动nfs服务。

4. 开发板配置mount命令，确保开发板可以访问PC端的nfs共享文件。
   格式：mount [nfs服务器IP]:[/nfs共享目录] [/开发板目录] nfs

     举例：
   
   ```
   mount 192.168.1.10:/nfs /nfs nfs
   ```

**用例执行**

测试套件执行 ActsDemoTest.bin 触发用例执行，基于串口打印日志进行分析。

### JS语言用例开发指导（适用于标准系统）

当前使用的测试框架是HJSUnit，用于支撑OpenHarmony application测试（特指基于JS应用框架使用 Javascript 语言开发的 APP）进行自动化测试。

**用例编写基础语法**

测试用例为 js 语言，必须满足 JavaScript 语言编程规范。

  **表7** 用例编写基础语法

| 用例语法 | 描述 | 要求 | 
| -------- | -------- | -------- |
| beforeAll | 测试套级别的预置条件，在所有测试用例开始前执行且仅执行一次，支持一个参数：预置动作函数。 | 可选 | 
| afterAll | 测试套级别的清理条件，在所有测试用例结束后执行且仅执行一次，支持一个参数：清理动作函数。 | 可选 | 
| beforeEach | 测试用例级别的预置条件，在每条测试用例开始前执行，执行次数与&nbsp;it&nbsp;定义的测试用例数一致，支持一个参数：预置动作函数。 | 可选 | 
| afterEach | 测试用例级别的清理条件，在每条测试用例结束后执行，执行次数与&nbsp;it&nbsp;定义的测试用例数一致，支持一个参数：清理动作函数。 | 可选 | 
| describe | 定义一个测试套，支持两个参数：测试套名称和测试套函数；&nbsp;describe&nbsp;支持嵌套，每个&nbsp;describe&nbsp;内均可以定义&nbsp;beforeAll&nbsp;、beforeEach&nbsp;、afterEach&nbsp;和&nbsp;afterAll。 | 必选 | 
| it | 定义一条测试用例，支持三个参数：用例名称，过滤参数和用例函数<br/>备注：<br/>**过滤参数**：过滤参数为一个&nbsp;32&nbsp;位的&nbsp;Int&nbsp;类型参数，0&nbsp;位&nbsp;置1表示不筛选、默认执行；0-10&nbsp;位&nbsp;置1表示测试用例类型；16-18&nbsp;位&nbsp;置1表示测试用例规模；24-28&nbsp;位&nbsp;置1表示测试层级。<br/>**测试用例类型**：置位0-10分别表示：FUNCTION&nbsp;方法类测试、PERFORMANCE&nbsp;性能类测试、POWER&nbsp;功耗类测试、RELIABILITY&nbsp;可靠性测试、SECURITY&nbsp;安全合规测试、GLOBAL&nbsp;整体性测试、COMPATIBILITY&nbsp;兼容性测试、USER&nbsp;用户测试、STANDARD&nbsp;标准测试、SAFETY&nbsp;安全特性测试、RESILIENCE&nbsp;压力测试。<br/>**测试用例规模**：置位16-18分别表示：SMALL&nbsp;小型测试、MEDIUM&nbsp;中型测试、LARGE&nbsp;大型测试。<br/>**测试层级**：置位24-28分别表示：LEVEL0-0&nbsp;级测试、LEVEL1-1&nbsp;级测试、LEVEL2-2&nbsp;级测试、LEVEL3-3&nbsp;级测试、LEVEL4-4&nbsp;级测试。 | 必选 | 

用例编写语法采用 jasmine 的标准语法，格式支持ES6格式。

1. 规范用例目录：测试用例存储到entry/src/main/js/test目录。
   
   ```
   ├── BUILD.gn   
   │ └──entry
   │ │ └──src
   │ │ │ └──main
   │ │ │ │ └──js
   │ │ │ │ │ └──default               
   │ │ │ │ │ │ └──pages
   │ │ │ │ │ │ │ └──index             
   │ │ │ │ │ │ │ │ └──index.js        # 入口文件。
   │ │ │ │ │ └──test                  # 测试代码存放目录。  
   │ │ │ └── resources                # hap资源存放目录。
   │ │ │ └── config.json              # hap配置文件。
   ```

2. index.js示例。
   
   ```
   // 拉起js测试框架，加载测试用例。
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

3. 单元测试用例示例。
   
   ```
   // Example1: 使用HJSUnit进行单元测试。
   describe('appInfoTest', function () {    
       it('app_info_test_001', 0, function () {
           var info = app.getInfo()
           expect(info.versionName).assertEqual('1.0')
           expect(info.versionCode).assertEqual('3')
       })
   }) 
   ```

### JS语言用例编译打包指导（适用于标准系统）

hap包编译请参考[标准系统js应用开发指导](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/build_overview-0000001055075201)。


## 全量编译指导（适用于标准系统）

1. 全量编译。
   **命令**：

   
   ```
   ./build.sh suite=acts system_size=standard
   ```

   **测试用例输出目录**：out/release/suites/acts/testcases

   **测试框架&amp;用例整体输出目录**：out/release/suites/acts（编译用例时会同步编译测试套执行框架）


## 全量用例执行指导（适用于小型系统、标准系统）

**搭建测试环境**

Windows工作台下安装python3.7及以上版本，确保工作台和测试设备正常连接。

  **测试执行目录**（对应编译生成的out/release/suites/acts目录）

```
├── testcase                       # 测试套文件存放目录。
│ └──xxx.hap                       # 测试套可执行hap文件。
│ └──xxx.json                      # 测试套对应执行配置文件。
├── tools                          # 测试框架工具目录。
├── run.bat                        # window平台测试套启动执行文件。
├── report                         # 测试报告生成目录。
```

**用例执行**

1. 在Windows工作台上，找到从Linux服务器上拷贝下来的测试套件用例目录(对应编译生成的out/release/suites/acts目录)，在Windows命令窗口进入对应目录，直接执行acts\run.bat。

2. 界面启动后，输入用例执行指令。
   - 全量执行。
     
      ```
      run acts
      ```

        **图1** 运行进程

        ![zh-cn_image_0000001200230833](figures/zh-cn_image_0000001200230833.gif)

   - 模块执行(具体模块可以查看\acts\testcases\)。
     
      ```
      run –l ActsSamgrTest
      ```

        **图2** 查看运行命令

        ![zh-cn_image_0000001154351160](figures/zh-cn_image_0000001154351160.jpg)

   等待执行完成。

3. 查看测试报告。
   进入acts\reports\，获取当前的执行记录，打开“summary_report.html”可以获取到测试报告。
