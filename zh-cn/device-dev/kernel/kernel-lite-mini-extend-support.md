# C++支持<a name="ZH-CN_TOPIC_0000001079036442"></a>

-   [基本概念](#section11374125415814)
    -   [运行机制](#section125251720195)

-   [开发指导](#section166302407911)
    -   [接口说明](#section1881825119919)
    -   [开发流程](#section76371145108)
    -   [编程实例](#section994427141111)


## 基本概念<a name="section11374125415814"></a>

C++作为目前使用最广泛的编程语言之一，支持类、封装、重载等特性，是在C语言基础上开发的一种面向对象的编程语言。

### 运行机制<a name="section125251720195"></a>

C++代码的识别主要由编译器支持，系统主要对全局对象进行构造函数调用，进行初始化操作。

## 开发指导<a name="section166302407911"></a>

### 接口说明<a name="section1881825119919"></a>

**表 1**  C++支持接口

<a name="table14277123518139"></a>
<table><thead align="left"><tr id="row152771935131315"><th class="cellrowborder" valign="top" width="23.792379237923793%" id="mcps1.2.4.1.1"><p id="p1127733591316"><a name="p1127733591316"></a><a name="p1127733591316"></a>功能分类</p>
</th>
<th class="cellrowborder" valign="top" width="33.02330233023302%" id="mcps1.2.4.1.2"><p id="p22771357138"><a name="p22771357138"></a><a name="p22771357138"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="43.18431843184319%" id="mcps1.2.4.1.3"><p id="p327714358130"><a name="p327714358130"></a><a name="p327714358130"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row119525513581"><td class="cellrowborder" valign="top" width="23.792379237923793%" headers="mcps1.2.4.1.1 "><p id="p2099535514346"><a name="p2099535514346"></a><a name="p2099535514346"></a>使用C++特性的前置条件</p>
</td>
<td class="cellrowborder" valign="top" width="33.02330233023302%" headers="mcps1.2.4.1.2 "><p id="p3155620345"><a name="p3155620345"></a><a name="p3155620345"></a>LOS_CppSystemInit</p>
</td>
<td class="cellrowborder" valign="top" width="43.18431843184319%" headers="mcps1.2.4.1.3 "><p id="p4616566343"><a name="p4616566343"></a><a name="p4616566343"></a>C++构造函数初始化</p>
</td>
</tr>
</tbody>
</table>

### 开发流程<a name="section76371145108"></a>

使用C++特性之前，需要调用函数LOS\_CppSystemInit，实现C++构造函数初始化，其中被初始化的构造函数存在init\_array这个段中，段区间通过变量\_\_init\_array\_start\_\_、\_\_init\_array\_end\_\_传递。

**表 2**  参数说明

<a name="table71191652173718"></a>
<table><thead align="left"><tr id="row1512085253715"><th class="cellrowborder" valign="top" width="42.77%" id="mcps1.2.3.1.1"><p id="p16120175233720"><a name="p16120175233720"></a><a name="p16120175233720"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="57.230000000000004%" id="mcps1.2.3.1.2"><p id="p61205526372"><a name="p61205526372"></a><a name="p61205526372"></a>参数说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row11120135213714"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p1053212673917"><a name="p1053212673917"></a><a name="p1053212673917"></a>__init_array_start__</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p2208154219392"><a name="p2208154219392"></a><a name="p2208154219392"></a>init_array段起始位置</p>
</td>
</tr>
<tr id="row1591908143918"><td class="cellrowborder" valign="top" width="42.77%" headers="mcps1.2.3.1.1 "><p id="p491968193914"><a name="p491968193914"></a><a name="p491968193914"></a>__init_array_end__</p>
</td>
<td class="cellrowborder" valign="top" width="57.230000000000004%" headers="mcps1.2.3.1.2 "><p id="p6919189393"><a name="p6919189393"></a><a name="p6919189393"></a>init_array段结束位置</p>
</td>
</tr>
</tbody>
</table>

>![](../public_sys-resources/icon-note.gif) **说明：** 
>调用该函数时，一定要在c++业务前。另外部分与系统资源强相关的类或接口，如std::thread，std::mutex等，在三方编译器使用的c库非musl c时，存在兼容性问题，不建议使用。

### 编程实例<a name="section994427141111"></a>

```
void app_init(void)
{
......
/* 启动阶段C++初始化 */
LOS_CppSystemInit((UINTPTR)&__init_array_start__, (UINTPTR)&__init_array_end__);
/* C++业务 */
......
}
```

