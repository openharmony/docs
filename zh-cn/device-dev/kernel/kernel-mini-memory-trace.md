# Trace调测<a name="ZH-CN_TOPIC_0000001162019075"></a>

-   [基本概念](#section44851752123712)
-   [运行机制](#section5282148123813)
-   [接口说明](#section16304193215387)
-   [开发指导](#section498695853819)
    -   [开发流程](#section1875652316393)
    -   [编程实例](#section0403134913395)
    -   [示例代码](#section1492711418400)
    -   [结果验证](#section869613984012)


## 基本概念<a name="section44851752123712"></a>

Trace调测旨在帮助开发者获取内核的运行流程，各个模块、任务的执行顺序，从而可以辅助开发者定位一些时序问题或者了解内核的代码运行过程。

## 运行机制<a name="section5282148123813"></a>

内核提供一套Hook框架，将Hook点预埋在各个模块的主要流程中，开发者通过注册的形式在自己所需的Hook点上注册回调函数，当内核运行至对应流程中会由内核主动调用Hook函数，将当前流程的关键数据传递给开发者。

## 接口说明<a name="section16304193215387"></a>

OpenHarmony LiteOS-M内核的Trace模块提供下面几种功能，接口详细信息可以查看API参考。

**表 1**  Trace模块接口说明

<a name="table208266479117"></a>
<table><thead align="left"><tr id="row19826947121114"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="p16415637105612"><a name="p16415637105612"></a><a name="p16415637105612"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="p11415163718562"><a name="p11415163718562"></a><a name="p11415163718562"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="p1641533755612"><a name="p1641533755612"></a><a name="p1641533755612"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row082617478118"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1082624717117"><a name="p1082624717117"></a><a name="p1082624717117"></a>Hook注册接口</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p1182654713112"><a name="p1182654713112"></a><a name="p1182654713112"></a>LOS_HookReg</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p1582614474114"><a name="p1582614474114"></a><a name="p1582614474114"></a>向指定Hook点注册回调函数</p>
</td>
</tr>
<tr id="row19470201017154"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="p1747021015152"><a name="p1747021015152"></a><a name="p1747021015152"></a>Hook解注册接口</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="p16470410201517"><a name="p16470410201517"></a><a name="p16470410201517"></a>LOS_HookUnReg</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="p147021017155"><a name="p147021017155"></a><a name="p147021017155"></a>解注册当前Hook点的回调函数</p>
</td>
</tr>
</tbody>
</table>

## 开发指导<a name="section498695853819"></a>

### 开发流程<a name="section1875652316393"></a>

开启Trace调测的典型流程如下：

1.  配置Trace模块相关宏。

    需要在target\_config.h头文件中修改配置：

    <a name="table1078714915105"></a>
    <table><thead align="left"><tr id="row1280518971010"><th class="cellrowborder" valign="top" width="27.24%" id="mcps1.1.4.1.1"><p id="p1380510912104"><a name="p1380510912104"></a><a name="p1380510912104"></a>配置项</p>
    </th>
    <th class="cellrowborder" valign="top" width="30.330000000000002%" id="mcps1.1.4.1.2"><p id="p08051291106"><a name="p08051291106"></a><a name="p08051291106"></a>含义</p>
    </th>
    <th class="cellrowborder" valign="top" width="42.43%" id="mcps1.1.4.1.3"><p id="p12805149151012"><a name="p12805149151012"></a><a name="p12805149151012"></a>设置值</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row168052913104"><td class="cellrowborder" valign="top" width="27.24%" headers="mcps1.1.4.1.1 "><p id="p180618915101"><a name="p180618915101"></a><a name="p180618915101"></a>LOSCFG_DEBUG_HOOK</p>
    </td>
    <td class="cellrowborder" valign="top" width="30.330000000000002%" headers="mcps1.1.4.1.2 "><p id="p198061196105"><a name="p198061196105"></a><a name="p198061196105"></a>Trace功能的开关</p>
    </td>
    <td class="cellrowborder" valign="top" width="42.43%" headers="mcps1.1.4.1.3 "><p id="p1980609121010"><a name="p1980609121010"></a><a name="p1980609121010"></a>0：关闭；1：打开</p>
    </td>
    </tr>
    </tbody>
    </table>

2.  选择想要注册的Hook点，实现对应的回调函数，Hook类型清单见liteos\_m/utils/internal/los\_hook\_types.h。
3.  调用LOS\_HookReg进行函数注册。

### 编程实例<a name="section0403134913395"></a>

本实例实现功能：模拟运行时malloc、free不同大小的内存，记录每次malloc，free的行为及时序。

### 示例代码<a name="section1492711418400"></a>

示例代码如下：

```
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "los_hook.h"

#define SIZE_512        512
#define SIZE_1K         1024
#define SIZE_2K         2048

/* 回调时打印malloc出来的大小 */
void MallocRecord(void *pool, unsigned int size)
{
    printf("malloc size = %u\n", size);
    return;
}

/* 回调时打印free的指针地址 */
void FreeRecord(void *pool, void *ptr)
{
    printf("free pool = 0x%x ptr = 0x%x\n", pool, ptr);
    return;
}

void TestTrace(void)
{
    char *pool1 = NULL;
    char *pool2 = NULL;
    char *pool3 = NULL;
    char *retptr = NULL;
    /* 分别为pool1，pool2，pool3分配不同大小的内存，用于区分验证 */
    pool1 = (char *)malloc(SIZE_512);
    if (pool1 == NULL) {
        printf("pool1 malloc failed!\n");
        return;
    }
    retptr = memset(pool1, 'a', SIZE_512);
    if (retptr == NULL) {
        printf("pool1 memset failed!\n");
        return;
    }
    printf("pool1 addr = 0x%x *pool1[0] = %c\n", pool1, *pool1);

    pool2 = (char *)malloc(SIZE_1K);
    if (pool2 == NULL) {
        printf("pool2 malloc failed!\n");
        return;
    }
    retptr = memset(pool2, 'b', SIZE_1K);
    if (retptr == NULL) {
        printf("pool2 memset failed!\n");
        return;
    }
    printf("pool2 addr = 0x%x *pool2[0] = %c\n", pool2, *pool2);

    pool3 = (char *)malloc(SIZE_2K);
    if (pool3 == NULL) {
        printf("pool3 malloc failed!\n");
        return;
    }
    retptr = memset(pool3, 'c', SIZE_2K);
    if (retptr == NULL) {
        printf("pool3 memset failed!\n");
        return;
    }
    printf("pool3 addr = 0x%x *pool3[0] = %c\n", pool3, *pool3);

    /* 按pool3, pool1, pool2的顺序释放，来检验回调函数的时序 */
    free(pool3);
    free(pool1);
    free(pool2);

    return;
}
/* 在使用Trace模块功能之前，首先进行回调函数的注册，注意回调函数的返回值都为void */
void InitTest(void)
{
    printf("init hook\n");
    /* 根据想要获取的Trace信息选择对应的Hook类型进行注册，具体可选Hook类型清单见liteos_m/utils/internal/los_hook_types.h */
    LOS_HookReg(LOS_HOOK_TYPE_MEM_ALLOC, MallocRecord);
    LOS_HookReg(LOS_HOOK_TYPE_MEM_FREE, FreeRecord);
    return;
}
```

### 结果验证<a name="section869613984012"></a>

输出结果如下：

```
init hook
malloc size = 512
pool1 addr = 0x20002f44 *pool1[0] = a
malloc size = 1024
pool2 addr = 0x2000314c *pool2[0] = b
malloc size = 2048
pool3 addr = 0x20003554 *pool3[0] = c
free pool = 0x200002a4 ptr = 0x20003554
free pool = 0x200002a4 ptr = 0x20002f44
free pool = 0x200002a4 ptr = 0x2000314c
```

根据地址信息，可以看到free的顺序为pool3，pool1，pool2。

