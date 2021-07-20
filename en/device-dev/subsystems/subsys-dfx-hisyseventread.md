# HiSysEvent订阅指导<a name="EN-US_TOPIC_0000001127171782"></a>

-   [概述](#section315316685112)
-   [接口说明](#section0342191810519)
-   [开发实例](#section123181432175110)

## 概述<a name="section315316685112"></a>

The HiSysEvent provides the cross-process subscription mechanism. You can register the subscription interface.

## 接口说明<a name="section0342191810519"></a>

**Table  1**  HiSysEvent订阅接口

<a name="table1844019587496"></a>
<table><thead align="left"><tr id="row1440058184916"><th class="cellrowborder" valign="top" width="48.120000000000005%" id="mcps1.2.3.1.1"><p id="p19441135844915"><a name="p19441135844915"></a><a name="p19441135844915"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="51.88%" id="mcps1.2.3.1.2"><p id="p13441195815491"><a name="p13441195815491"></a><a name="p13441195815491"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16441155818499"><td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.2.3.1.1 "><p id="p114411558204915"><a name="p114411558204915"></a><a name="p114411558204915"></a>int ISysEventService::AddListener(in SysEventRule[] rules, in ISysEventCallback callback)</p>
</td>
<td class="cellrowborder" valign="top" width="51.88%" headers="mcps1.2.3.1.2 "><p id="p14727325133216"><a name="p14727325133216"></a><a name="p14727325133216"></a>接口功能：订阅HiSysEvent事件。</p>
<p id="p167271525203213"><a name="p167271525203213"></a><a name="p167271525203213"></a>输入参数：</p>
<a name="ul6717142214919"></a><a name="ul6717142214919"></a><ul id="ul6717142214919"><li>rules：事件订阅规则</li><li>callback：订阅回调对象</li></ul>
<p id="p83591223153818"><a name="p83591223153818"></a><a name="p83591223153818"></a>返回值：</p>
<a name="ul12105842111913"></a><a name="ul12105842111913"></a><ul id="ul12105842111913"><li>0：订阅成功，重复订阅</li><li>1：订阅成功，初次订阅</li><li>其他返回值：订阅失败</li></ul>
</td>
</tr>
<tr id="row37141037115411"><td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.2.3.1.1 "><p id="p4714143785410"><a name="p4714143785410"></a><a name="p4714143785410"></a>void ISysEventCallback::Handle(in String domain, in String eventName, in int eventType, in String eventDetail)</p>
</td>
<td class="cellrowborder" valign="top" width="51.88%" headers="mcps1.2.3.1.2 "><p id="p1772213111011"><a name="p1772213111011"></a><a name="p1772213111011"></a>接口功能：订阅事件的回调接口。</p>
<p id="p182081719151016"><a name="p182081719151016"></a><a name="p182081719151016"></a>输入参数：</p>
<a name="ul02091819131015"></a><a name="ul02091819131015"></a><ul id="ul02091819131015"><li>domain：事件所属领域</li><li>eventName：事件的名称</li><li>eventType：事件类型</li><li>eventDetail：包含事件相关信息的字符串，以json的形式体现</li></ul>
<p id="p18209419201010"><a name="p18209419201010"></a><a name="p18209419201010"></a>返回值：无。</p>
</td>
</tr>
</tbody>
</table>

**Table  2**  SysEventRule订阅规则对象

<a name="table1144011610564"></a>
<table><thead align="left"><tr id="row124411716175611"><th class="cellrowborder" valign="top" width="45.92%" id="mcps1.2.3.1.1"><p id="p19441151675610"><a name="p19441151675610"></a><a name="p19441151675610"></a>属性名称</p>
</th>
<th class="cellrowborder" valign="top" width="54.08%" id="mcps1.2.3.1.2"><p id="p16441171616563"><a name="p16441171616563"></a><a name="p16441171616563"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row174411216105615"><td class="cellrowborder" valign="top" width="45.92%" headers="mcps1.2.3.1.1 "><p id="p496413536613"><a name="p496413536613"></a><a name="p496413536613"></a><span>uint32_t</span> ruleType</p>
</td>
<td class="cellrowborder" valign="top" width="54.08%" headers="mcps1.2.3.1.2 "><p id="p94416160565"><a name="p94416160565"></a><a name="p94416160565"></a>规则类型（匹配范围包括domain以及eventName）：</p>
<a name="ul1652866141814"></a><a name="ul1652866141814"></a><ul id="ul1652866141814"><li>1：全字符匹配</li><li>2：前缀匹配</li><li>3：正则表达式匹配</li><li>其他值：无效的匹配方式</li></ul>
</td>
</tr>
<tr id="row64411816125614"><td class="cellrowborder" valign="top" width="45.92%" headers="mcps1.2.3.1.1 "><p id="p1258135313712"><a name="p1258135313712"></a><a name="p1258135313712"></a>std::string domain;</p>
</td>
<td class="cellrowborder" valign="top" width="54.08%" headers="mcps1.2.3.1.2 "><a name="ul14905926102311"></a><a name="ul14905926102311"></a><ul id="ul14905926102311"><li>domain：事件所属领域，如果传入的是空字符串，则默认事件领域字段匹配成功</li></ul>
</td>
</tr>
<tr id="row244161615619"><td class="cellrowborder" valign="top" width="45.92%" headers="mcps1.2.3.1.1 "><p id="p227913101887"><a name="p227913101887"></a><a name="p227913101887"></a>std::string eventName</p>
</td>
<td class="cellrowborder" valign="top" width="54.08%" headers="mcps1.2.3.1.2 "><a name="ul248063132319"></a><a name="ul248063132319"></a><ul id="ul248063132319"><li>eventName：事件的名称，如果传入的是空字符串，则默认事件名称字段匹配成功</li></ul>
</td>
</tr>
</tbody>
</table>

## 开发实例<a name="section123181432175110"></a>

1.  源代码开发：

    引入对应的aidl文件，包括：ISysEventService.aidl、SysEventRule.aidl、ISysEventCallback.aidl。

    在相应的业务逻辑里面调用ISysEventService::AddListener\(in SysEventRule\[\] rules, in ISysEventCallback callback\)接口。

    实现对应的回调对象：

    ISysEventCallback::Handle\(in String domain, in String eventName, in int eventType, in String eventDetail\)


1.  源代码开发：

    引入对应的aidl文件，包括：ISysEventService.aidl、SysEventRule.aidl、ISysEventCallback.aidl。

    在相应的业务逻辑里面调用ISysEventService::AddListener\(in SysEventRule\[\] rules, in ISysEventCallback callback\)接口。

    实现对应的回调对象：

    ISysEventCallback::Handle\(in String domain, in String eventName, in int eventType, in String eventDetail\)

2.  编译设置：

在编译子系统里面，需要依赖libbinder模块

aosp\_deps = \[ "shared\_library:libbinder",  \]

-   **[bytrace Usage Guidelines](subsys-toolchain-bytrace-guide.md)**  

-   **[hdc\_std Usage Guidelines](oem_subsys_toolchain_hdc_guide.md)**  


