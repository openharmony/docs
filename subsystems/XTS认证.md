# XTS认证<a name="ZH-CN_TOPIC_0000001074750691"></a>

-   [概述](#zh-cn_topic_0000001059475030_section44931242483)
-   [目录结构](#zh-cn_topic_0000001059475030_section45118915548)
-   [约束与限制](#zh-cn_topic_0000001059475030_section115518148474)
-   [开发指导](#zh-cn_topic_0000001059475030_section99973470498)
    -   [编写联接类模组acts测试用例](#zh-cn_topic_0000001059475030_section1348215596491)
    -   [编写智慧视觉类设备（Ipcamera）acts测试用例](#zh-cn_topic_0000001059475030_section11458163095019)
    -   [执行联接类模组acts测试用例](#zh-cn_topic_0000001059475030_section3115140115113)
    -   [执行智慧视觉类设备（Ipcamera）acts测试用例](#zh-cn_topic_0000001059475030_section1759138185215)


## 概述<a name="zh-cn_topic_0000001059475030_section44931242483"></a>

XTS是OpenHarmony生态认证测试套件的集合，当前包括acts（application compatibility test suite）应用兼容性测试套，后续会拓展dcts（device compatibility test suite）设备兼容性测试套等。

test/xts仓当前包括acts与tools软件包：

-   acts，存放acts相关测试用例源码与配置文件，其目的是帮助终端设备厂商尽早发现软件与OpenHarmony的不兼容性，确保软件在整个开发过程中满足OpenHarmony的兼容性要求。
-   tools，存放acts相关测试用例开发框架。

## 目录结构<a name="zh-cn_topic_0000001059475030_section45118915548"></a>

test/xts源代码目录结构：

├── acts

│   ├── BUILD.gn 测试用例编译配置

│   └── subsystem\_lite   子系统测试用例源码

└── tools

│   └── build 测试用例编译相关的模板与脚本

│   └── hcpptest 智慧视觉类设备（Ipcamera）测试用例开发框架源码

│   └── hctest  联接类模组测试用例开发框架源码

│   └── BUILD.gn 编译配置

│   └── build.sh  编译入口

## 约束与限制<a name="zh-cn_topic_0000001059475030_section115518148474"></a>

联接类模组acts用例开发语言是C，智慧视觉类设备（Ipcamera）acts用例开发语言是C++。

## 开发指导<a name="zh-cn_topic_0000001059475030_section99973470498"></a>

### 编写联接类模组acts测试用例<a name="zh-cn_topic_0000001059475030_section1348215596491"></a>

当前使用的测试框架是hctest。

hctest测试框架支持使用C语言编写测试用例，在联接类模组上执行，是在开源测试框架unity的基础上进行增强和适配。

1.  规范用例目录：测试用例存储test/xts/acts仓中。

    ├── acts

    │   ├── BUILD.gn

    │   └──subsystem\_lite

    │   │   └── module\_hal

    │   │   │   └──  BUILD.gn

    │   │   │   └── src

2.  src目录下用例编写样例。

    a. 引用测试框架

    ```
    #include "hctest.h"
    ```

    b. 使用宏定义LITE\_TEST\_SUIT定义子系统、模块、测试套件名称

    ```
    /**  
    * @brief  register a test suit named "IntTestSuite"  
    * @param  test subsystem name  
    * @param  example module name  
    * @param  IntTestSuite test suit name  
    */
    LITE_TEST_SUIT(test, example, IntTestSuite);
    ```

    c. 定义Setup与TearDown

    命名方式：测试套件名称+Setup，测试套件名称+TearDown。

    Setup与TearDown必须存在，可以为空函数。

    d. 使用宏定义LITE\_TEST\_CASE写测试用例

    包括三个参数：测试套件名称，测试用例名称，用例级别。

    用例级别取值为如下内容之一:

    “Level0”,“Level1”,“Level2”,“Level3”，“Level4”。

    ```
    LITE_TEST_CASE(IntTestSuite, TestCase001, Level0) 
    {  
      //do something 
    };
    ```

    用例级别说明如下表所示。

    **表 1**  用例级别说明

    <a name="zh-cn_topic_0000001059475030_table115309197517"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001059475030_row053010198520"><th class="cellrowborder" valign="top" width="13.46134613461346%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001059475030_p6251523752"><a name="zh-cn_topic_0000001059475030_p6251523752"></a><a name="zh-cn_topic_0000001059475030_p6251523752"></a><strong id="zh-cn_topic_0000001059475030_b72510235511"><a name="zh-cn_topic_0000001059475030_b72510235511"></a><a name="zh-cn_topic_0000001059475030_b72510235511"></a>级别名称</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="10.25102510251025%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001059475030_p1825117231157"><a name="zh-cn_topic_0000001059475030_p1825117231157"></a><a name="zh-cn_topic_0000001059475030_p1825117231157"></a><strong id="zh-cn_topic_0000001059475030_b1825142312518"><a name="zh-cn_topic_0000001059475030_b1825142312518"></a><a name="zh-cn_topic_0000001059475030_b1825142312518"></a>基本定义</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="76.2876287628763%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001059475030_p1325111230519"><a name="zh-cn_topic_0000001059475030_p1325111230519"></a><a name="zh-cn_topic_0000001059475030_p1325111230519"></a><strong id="zh-cn_topic_0000001059475030_b1525110231356"><a name="zh-cn_topic_0000001059475030_b1525110231356"></a><a name="zh-cn_topic_0000001059475030_b1525110231356"></a>测试范围</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001059475030_row45301619957"><td class="cellrowborder" valign="top" width="13.46134613461346%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001059475030_p122511231759"><a name="zh-cn_topic_0000001059475030_p122511231759"></a><a name="zh-cn_topic_0000001059475030_p122511231759"></a>Level0</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.25102510251025%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001059475030_p132511238516"><a name="zh-cn_topic_0000001059475030_p132511238516"></a><a name="zh-cn_topic_0000001059475030_p132511238516"></a>冒烟</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.2876287628763%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001059475030_p82511223550"><a name="zh-cn_topic_0000001059475030_p82511223550"></a><a name="zh-cn_topic_0000001059475030_p82511223550"></a>验证关键功能点基本功能/最基本DFX属性在最常见输入下的表现，通过表示功能基本可运行。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001059475030_row12531121912518"><td class="cellrowborder" valign="top" width="13.46134613461346%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001059475030_p16252523557"><a name="zh-cn_topic_0000001059475030_p16252523557"></a><a name="zh-cn_topic_0000001059475030_p16252523557"></a>Level1</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.25102510251025%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001059475030_p1125212231358"><a name="zh-cn_topic_0000001059475030_p1125212231358"></a><a name="zh-cn_topic_0000001059475030_p1125212231358"></a>基本</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.2876287628763%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001059475030_p02521123757"><a name="zh-cn_topic_0000001059475030_p02521123757"></a><a name="zh-cn_topic_0000001059475030_p02521123757"></a>验证各功能点基本功能/基本DFX属性在常见输入下的表现，通过表示功能基本可测试。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001059475030_row1531131917514"><td class="cellrowborder" valign="top" width="13.46134613461346%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001059475030_p1525219237517"><a name="zh-cn_topic_0000001059475030_p1525219237517"></a><a name="zh-cn_topic_0000001059475030_p1525219237517"></a>Level2</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.25102510251025%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001059475030_p5252523458"><a name="zh-cn_topic_0000001059475030_p5252523458"></a><a name="zh-cn_topic_0000001059475030_p5252523458"></a>重要</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.2876287628763%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001059475030_p1125215231552"><a name="zh-cn_topic_0000001059475030_p1125215231552"></a><a name="zh-cn_topic_0000001059475030_p1125215231552"></a>验证各功能点的基本功能/基本DFX属性在常规输入/常见异常情况下的表现，通过表示功能基本正常可用，可开展Beta。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001059475030_row1853111191556"><td class="cellrowborder" valign="top" width="13.46134613461346%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001059475030_p625220234514"><a name="zh-cn_topic_0000001059475030_p625220234514"></a><a name="zh-cn_topic_0000001059475030_p625220234514"></a>Level3</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.25102510251025%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001059475030_p92528231952"><a name="zh-cn_topic_0000001059475030_p92528231952"></a><a name="zh-cn_topic_0000001059475030_p92528231952"></a>一般</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.2876287628763%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001059475030_p72521423855"><a name="zh-cn_topic_0000001059475030_p72521423855"></a><a name="zh-cn_topic_0000001059475030_p72521423855"></a>验证各功能点的全部功能/全部DFX属性在各种常规/非常规输入组合下，或各种正常/异常预置条件组合下的表现。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001059475030_row25311219459"><td class="cellrowborder" valign="top" width="13.46134613461346%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001059475030_p52521223659"><a name="zh-cn_topic_0000001059475030_p52521223659"></a><a name="zh-cn_topic_0000001059475030_p52521223659"></a>Level4</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.25102510251025%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001059475030_p10252223853"><a name="zh-cn_topic_0000001059475030_p10252223853"></a><a name="zh-cn_topic_0000001059475030_p10252223853"></a>生僻</p>
    </td>
    <td class="cellrowborder" valign="top" width="76.2876287628763%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001059475030_p1625214231655"><a name="zh-cn_topic_0000001059475030_p1625214231655"></a><a name="zh-cn_topic_0000001059475030_p1625214231655"></a>验证关键功能点在极端异常预置条件下、用户难以触及的异常输入组合下的表现。</p>
    </td>
    </tr>
    </tbody>
    </table>

    e. 使用宏定义 RUN\_TEST\_SUITE注册测试套件。

    ```
    RUN_TEST_SUITE(IntTestSuite);
    ```

3.  测试模块的配置文件样例：（BUILD.gn）。

    每个测试模块目录下新建BUILD.gn编译文件，用于指定编译后静态库的名称、依赖的头文件、依赖的库等；具体写法如下：

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

4.  acts下BUILD.gn增加编译选项。

    需要将测试模块加入到acts目录下的编译脚本中，编译脚本路径：test/xts/acts/BUILD.gn。

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

5.  测试套件编译命令。

    **命令：**python build.py wifiiot -b debug

    **输出：**out/wifiiot

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >联接类模组acts测试编译中间件为静态库，最终会链接到版本镜像中 ：Hi3861\_wifiiot\_app\_allinone.bin。


### 编写智慧视觉类设备（Ipcamera）acts测试用例<a name="zh-cn_topic_0000001059475030_section11458163095019"></a>

hcpptest测试框架是在开源的googletest测试框架的基础上进行的增强和适配。

1.  规范用例目录：测试用例存储到test/xts/acts仓中。

    ├── acts

    │   ├── BUILD.gn

    │   └──subsystem\_lite

    │   │   └── module\_posix

    │   │   │   └──  BUILD.gn

    │   │   │   └── src

2.  测试模块src下用例编写样例。

    a. 引用测试框架：

    需要引用gtest.h  如：\#include "gtest/gtest.h"

    ```
    #include "gtest/gtest.h"
    ```

    b. 定义Setup与TearDown

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

    c. 使用宏定义HWTEST或HWTEST\_F写测试用例

    普通测试用例的定义：HWTEST（测试套名称， 测试用例名称， 用例标注）。

    包含SetUp和TearDown的测试用例的定义 ：HWTEST\_F（测试套名称， 测试用例名称，用例标注）。

    宏定义包括三个参数：测试套件名称，测试用例名称，用例级别。

    用例级别取值为如下内容之一:

    “Level0”,“Level1”,“Level2”,“Level3”，“Level4”。

    ```
    HWTEST_F(TestSuite, TestCase_0001, Level0) {
    // do something
    }
    ```

    用例级别说明如下表所示。

    **表 2**  用例级别说明

    <a name="zh-cn_topic_0000001059475030_table1830755842"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0000001059475030_row93075510420"><th class="cellrowborder" valign="top" width="13.681368136813681%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0000001059475030_p153681823247"><a name="zh-cn_topic_0000001059475030_p153681823247"></a><a name="zh-cn_topic_0000001059475030_p153681823247"></a><strong id="zh-cn_topic_0000001059475030_b036862311411"><a name="zh-cn_topic_0000001059475030_b036862311411"></a><a name="zh-cn_topic_0000001059475030_b036862311411"></a>级别名称</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="10.961096109610962%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0000001059475030_p9368823749"><a name="zh-cn_topic_0000001059475030_p9368823749"></a><a name="zh-cn_topic_0000001059475030_p9368823749"></a><strong id="zh-cn_topic_0000001059475030_b0368152312417"><a name="zh-cn_topic_0000001059475030_b0368152312417"></a><a name="zh-cn_topic_0000001059475030_b0368152312417"></a>基本定义</strong></p>
    </th>
    <th class="cellrowborder" valign="top" width="75.35753575357535%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0000001059475030_p3368112319418"><a name="zh-cn_topic_0000001059475030_p3368112319418"></a><a name="zh-cn_topic_0000001059475030_p3368112319418"></a><strong id="zh-cn_topic_0000001059475030_b2368523045"><a name="zh-cn_topic_0000001059475030_b2368523045"></a><a name="zh-cn_topic_0000001059475030_b2368523045"></a>测试范围</strong></p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0000001059475030_row13079520412"><td class="cellrowborder" valign="top" width="13.681368136813681%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001059475030_p1236811237417"><a name="zh-cn_topic_0000001059475030_p1236811237417"></a><a name="zh-cn_topic_0000001059475030_p1236811237417"></a>Level0</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.961096109610962%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001059475030_p336812235414"><a name="zh-cn_topic_0000001059475030_p336812235414"></a><a name="zh-cn_topic_0000001059475030_p336812235414"></a>冒烟</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.35753575357535%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001059475030_p2036852311414"><a name="zh-cn_topic_0000001059475030_p2036852311414"></a><a name="zh-cn_topic_0000001059475030_p2036852311414"></a>验证关键功能点基本功能/最基本DFX属性在最常见输入下的表现，通过表示功能基本可运行。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001059475030_row4307953415"><td class="cellrowborder" valign="top" width="13.681368136813681%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001059475030_p18369623540"><a name="zh-cn_topic_0000001059475030_p18369623540"></a><a name="zh-cn_topic_0000001059475030_p18369623540"></a>Level1</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.961096109610962%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001059475030_p103698231443"><a name="zh-cn_topic_0000001059475030_p103698231443"></a><a name="zh-cn_topic_0000001059475030_p103698231443"></a>基本</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.35753575357535%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001059475030_p136916234410"><a name="zh-cn_topic_0000001059475030_p136916234410"></a><a name="zh-cn_topic_0000001059475030_p136916234410"></a>验证各功能点基本功能/基本DFX属性在常见输入下的表现，通过表示功能基本可测试。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001059475030_row83075510419"><td class="cellrowborder" valign="top" width="13.681368136813681%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001059475030_p12369192315420"><a name="zh-cn_topic_0000001059475030_p12369192315420"></a><a name="zh-cn_topic_0000001059475030_p12369192315420"></a>Level2</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.961096109610962%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001059475030_p13698231341"><a name="zh-cn_topic_0000001059475030_p13698231341"></a><a name="zh-cn_topic_0000001059475030_p13698231341"></a>重要</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.35753575357535%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001059475030_p16369142312412"><a name="zh-cn_topic_0000001059475030_p16369142312412"></a><a name="zh-cn_topic_0000001059475030_p16369142312412"></a>验证各功能点的基本功能/基本DFX属性在常规输入/常见异常情况下的表现，通过表示功能基本正常可用，可开展Beta。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001059475030_row930815512416"><td class="cellrowborder" valign="top" width="13.681368136813681%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001059475030_p1636932315417"><a name="zh-cn_topic_0000001059475030_p1636932315417"></a><a name="zh-cn_topic_0000001059475030_p1636932315417"></a>Level3</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.961096109610962%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001059475030_p1336918239414"><a name="zh-cn_topic_0000001059475030_p1336918239414"></a><a name="zh-cn_topic_0000001059475030_p1336918239414"></a>一般</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.35753575357535%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001059475030_p143691023345"><a name="zh-cn_topic_0000001059475030_p143691023345"></a><a name="zh-cn_topic_0000001059475030_p143691023345"></a>验证各功能点的全部功能/全部DFX属性在各种常规/非常规输入组合下，或各种正常/异常预置条件组合下的表现。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0000001059475030_row183085518414"><td class="cellrowborder" valign="top" width="13.681368136813681%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0000001059475030_p63691423347"><a name="zh-cn_topic_0000001059475030_p63691423347"></a><a name="zh-cn_topic_0000001059475030_p63691423347"></a>Level4</p>
    </td>
    <td class="cellrowborder" valign="top" width="10.961096109610962%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0000001059475030_p63697236413"><a name="zh-cn_topic_0000001059475030_p63697236413"></a><a name="zh-cn_topic_0000001059475030_p63697236413"></a>生僻</p>
    </td>
    <td class="cellrowborder" valign="top" width="75.35753575357535%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0000001059475030_p133695231443"><a name="zh-cn_topic_0000001059475030_p133695231443"></a><a name="zh-cn_topic_0000001059475030_p133695231443"></a>验证关键功能点在极端异常预置条件下、用户难以触及的异常输入组合下的表现。</p>
    </td>
    </tr>
    </tbody>
    </table>

3.  测试模块下用例配置文件样例：（BUILD.gn）。

    每个测试模块目录下新建BUILD.gn编译文件，用于指定编译后可执行文件的名称、依赖的头文件、依赖的库等；具体写法如下。每个测试模块将独立编译成.bin可执行文件， 该文件可直接mount到单板上进行测试。

    举例：

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

4.  acts目录下增加编译选项（BUILD.gn）。

    将测试模块加入到acts目录下的编译脚本中，编译脚本为：test/xts/acts/BUILD.gn。

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

5.  测试套件编译命令。

    -   **hi3518ev300**

    **命令**：python build.py ipcamera\_hi3518ev300 -b debug

    **输出**：out/ipcamera\_hi3518ev300

    -   **hi3516dv300**

    **命令**：python build.py ipcamera\_hi3516dv300 -b debug

    **输出**：out/ipcamera\_hi3516dv300

    >![](public_sys-resources/icon-note.gif) **说明：** 
    >智慧视觉类设备（Ipcamera）acts独立编译成.bin可执行文件， 该文件可直接mount到单板上进行测试。


### 执行联接类模组acts测试用例<a name="zh-cn_topic_0000001059475030_section3115140115113"></a>

**获取测试大包**

请在如下目录获取版本镜像，归档目录：out\\wifiiot\\Hi3861\_wifiiot\_app\_allinone.bin。

备注：判断当前版本镜像是否集成acts测试套件方法：在map文件中查看对应.a是否被编译即可，out\\wifiiot\\Hi3861\_wifiiot\_app.map。

**版本镜像烧录进开发板**

**测试步骤**

1.  使用串口工具登录开发板，并保存串口打印信息。
2.  重启设备，查看串口日志。

**测试结果分析指导**

基于串口打印日志进行分析；

每个测试套件执行以：Start to run test suite:开始，以xx Tests xx Failures xx Ignored结束。

### 执行智慧视觉类设备（Ipcamera）acts测试用例<a name="zh-cn_topic_0000001059475030_section1759138185215"></a>

目前的用例执行采用nfs共享的方式，mount到单板去执行；

**环境搭建**

1.  使用有限网线或无线将Ipcamera开发板与PC进行连接。
2.  Ipcamera开发板配置IP、子网掩码、网关，确保Ipcamera开发板与PC处于同一个网段。
3.  PC安装nfs服务器并完成注册，启动nfs服务。
4.  Ipcamera开发板配置mount命令，确保Ipcamera开发板可以访问PC端的nfs共享文件。

    格式：mount \[nfs服务器IP\]:\[/nfs共享目录\] \[/Ipcamera开发板目录\] nfs

    举例：

    ```
    mount 192.168.1.10:/nfs /nfs nfs
    ```


**用例执行**

基于串口打印日志进行分析。

每个测试套件执行以./测试模块.bin 触发用例执行。

