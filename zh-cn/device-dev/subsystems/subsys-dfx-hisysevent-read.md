# HiSysEvent订阅指导<a name="ZH-CN_TOPIC_0000001185655868"></a>

-   [概述](#section315316685112)
-   [接口说明](#section0342191810519)
-   [开发实例](#section123181432175110)
    -   [C++接口实例](#section2016116181902)


## 概述<a name="section315316685112"></a>

HiSysEvent提供了跨进程订阅机制，开发者可以通过注册订阅接口实时获取关注的事件，例如电池模块侦听功耗相关的事件，用于分析耗电情况。

## 接口说明<a name="section0342191810519"></a>

**表 1**  HiSysEvent订阅接口

<a name="table1844019587496"></a>
<table><thead align="left"><tr id="row1440058184916"><th class="cellrowborder" valign="top" width="48.120000000000005%" id="mcps1.2.3.1.1"><p id="p19441135844915"><a name="p19441135844915"></a><a name="p19441135844915"></a>接口名</p>
</th>
<th class="cellrowborder" valign="top" width="51.88%" id="mcps1.2.3.1.2"><p id="p13441195815491"><a name="p13441195815491"></a><a name="p13441195815491"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16441155818499"><td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.2.3.1.1 "><p id="p877916438211"><a name="p877916438211"></a><a name="p877916438211"></a>int HiSysEventManager::AddEventListener(std::shared_ptr&lt;HiSysEventSubscribeCallBackBase&gt; listener, std::vector&lt;struct ListenerRule&gt;&amp; rules)</p>
</td>
<td class="cellrowborder" valign="top" width="51.88%" headers="mcps1.2.3.1.2 "><p id="p14727325133216"><a name="p14727325133216"></a><a name="p14727325133216"></a>接口功能：注册订阅HiSysEvent系统事件侦听对象，可设置规则订阅某些事件。</p>
<p id="p167271525203213"><a name="p167271525203213"></a><a name="p167271525203213"></a>输入参数：</p>
<a name="ul6717142214919"></a><a name="ul6717142214919"></a><ul id="ul6717142214919"><li>listener：订阅回调对象。</li><li>rules：事件订阅规则。</li></ul>
<p id="p83591223153818"><a name="p83591223153818"></a><a name="p83591223153818"></a>返回值：</p>
<a name="ul12105842111913"></a><a name="ul12105842111913"></a><ul id="ul12105842111913"><li>0：订阅成功，重复订阅。</li><li>1：订阅成功，初次订阅。</li><li>其他返回值：订阅失败。</li></ul>
</td>
</tr>
<tr id="row910319443242"><td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.2.3.1.1 "><p id="p15104154411248"><a name="p15104154411248"></a><a name="p15104154411248"></a>void HiSysEventManager::RemoveListener(std::shared_ptr&lt;HiSysEventSubscribeCallBackBase&gt; listener)</p>
</td>
<td class="cellrowborder" valign="top" width="51.88%" headers="mcps1.2.3.1.2 "><p id="p1104194420248"><a name="p1104194420248"></a><a name="p1104194420248"></a>接口功能：移除订阅hisysevent系统事件侦听对象。</p>
<p id="p7943171095411"><a name="p7943171095411"></a><a name="p7943171095411"></a>输入参数：</p>
<a name="ul894321075411"></a><a name="ul894321075411"></a><ul id="ul894321075411"><li>listener：订阅回调对象。</li></ul>
<p id="p9744631162515"><a name="p9744631162515"></a><a name="p9744631162515"></a>返回值：无。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  ListenerRule订阅规则对象

<a name="table1144011610564"></a>
<table><thead align="left"><tr id="row124411716175611"><th class="cellrowborder" valign="top" width="48.11%" id="mcps1.2.3.1.1"><p id="p19441151675610"><a name="p19441151675610"></a><a name="p19441151675610"></a>属性名称</p>
</th>
<th class="cellrowborder" valign="top" width="51.89%" id="mcps1.2.3.1.2"><p id="p16441171616563"><a name="p16441171616563"></a><a name="p16441171616563"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row174411216105615"><td class="cellrowborder" valign="top" width="48.11%" headers="mcps1.2.3.1.1 "><p id="p496413536613"><a name="p496413536613"></a><a name="p496413536613"></a><span>uint32_t</span> ruleType</p>
</td>
<td class="cellrowborder" valign="top" width="51.89%" headers="mcps1.2.3.1.2 "><p id="p94416160565"><a name="p94416160565"></a><a name="p94416160565"></a>规则类型（匹配范围包括domain以及eventName）：</p>
<a name="ul1652866141814"></a><a name="ul1652866141814"></a><ul id="ul1652866141814"><li>1：全字符匹配。</li><li>2：前缀匹配。</li><li>3：正则表达式匹配。</li><li>其他值：无效的匹配方式。</li></ul>
</td>
</tr>
<tr id="row64411816125614"><td class="cellrowborder" valign="top" width="48.11%" headers="mcps1.2.3.1.1 "><p id="p1258135313712"><a name="p1258135313712"></a><a name="p1258135313712"></a>std::string domain</p>
</td>
<td class="cellrowborder" valign="top" width="51.89%" headers="mcps1.2.3.1.2 "><a name="ul14905926102311"></a><a name="ul14905926102311"></a><ul id="ul14905926102311"><li>domain：事件所属领域，如果传入的是空字符串，则默认事件领域字段匹配成功。</li></ul>
</td>
</tr>
<tr id="row244161615619"><td class="cellrowborder" valign="top" width="48.11%" headers="mcps1.2.3.1.1 "><p id="p227913101887"><a name="p227913101887"></a><a name="p227913101887"></a>std::string eventName</p>
</td>
<td class="cellrowborder" valign="top" width="51.89%" headers="mcps1.2.3.1.2 "><a name="ul248063132319"></a><a name="ul248063132319"></a><ul id="ul248063132319"><li>eventName：事件的名称，如果传入的是空字符串，则默认事件名称字段匹配成功。</li></ul>
</td>
</tr>
</tbody>
</table>

**表 3**  HiSysEventSubscribeCallBackBase订阅对象

<a name="table1011703742711"></a>
<table><thead align="left"><tr id="row121187375270"><th class="cellrowborder" valign="top" width="48.25%" id="mcps1.2.3.1.1"><p id="p2118143782719"><a name="p2118143782719"></a><a name="p2118143782719"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" width="51.74999999999999%" id="mcps1.2.3.1.2"><p id="p4118037152710"><a name="p4118037152710"></a><a name="p4118037152710"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row111823719274"><td class="cellrowborder" valign="top" width="48.25%" headers="mcps1.2.3.1.1 "><p id="p161181537112712"><a name="p161181537112712"></a><a name="p161181537112712"></a>void HiSysEventSubscribeCallBackBase::OnHandle(const std::string&amp; domain, const std::string&amp; eventName, const int eventType, const std::string&amp; eventDetail)</p>
</td>
<td class="cellrowborder" valign="top" width="51.74999999999999%" headers="mcps1.2.3.1.2 "><p id="p1772213111011"><a name="p1772213111011"></a><a name="p1772213111011"></a>接口功能：订阅事件的回调接口。</p>
<p id="p182081719151016"><a name="p182081719151016"></a><a name="p182081719151016"></a>输入参数：</p>
<a name="ul02091819131015"></a><a name="ul02091819131015"></a><ul id="ul02091819131015"><li>domain：事件所属领域。</li><li>eventName：事件的名称。</li><li>eventType：事件类型。</li><li>eventDetail：包含事件相关信息的字符串，以json的形式体现。</li></ul>
<p id="p18209419201010"><a name="p18209419201010"></a><a name="p18209419201010"></a>返回值：无。</p>
</td>
</tr>
</tbody>
</table>

## 开发实例<a name="section123181432175110"></a>

### C++接口实例<a name="section2016116181902"></a>

本实例介绍如何订阅domain=HIVIEWDFX的所有系统事件。

1.  源代码开发：

    -   引入对应的头文件：

        hisysevent\_manager.h。

    -   实现回调接口：

        HiSysEventSubscribeCallBackBase::OnHandle\(const std::string& domain, const std::string& eventName, const int eventType, const std::string& eventDetail\)。

    -   注册回调对象：

        HiSysEventManager::AddEventListener\(std::shared\_ptr<HiSysEventSubscribeCallBackBase\> listener, std::vector<struct ListenerRule\>& rules\)。


    ```
    // 以下是订阅domain=HIVIEWDFX的所有系统事件的应用例子
    #include "hisysevent_manager.h"
    #include <iostream>
    namespace OHOS {
    namespace HiviewDFX {
    // 实现订阅回调对象的接口
    void HiSysEventToolListener::OnHandle(const std::string& domain, const std::string& eventName,
        const int eventType, const std::string& eventDetail)
    {
        std::cout << eventDetail << std::endl;
    }
    
    void HiSysEventToolListener::OnServiceDied()
    {
        std::cout << std::string("service disconnect, exit") << std::endl;
        exit(0);
    }
    } // namespace HiviewDFX
    } // namespace OHOS
    
    // 调用订阅接口注册开发实现的订阅对象
    auto toolListener = std::make_shared<HiSysEventToolListener>();
    struct ListenerRule rule;
    rule.ruleType = 1; // 1: default type
    rule.domain = "HIVIEWDFX";
    std::vector<struct ListenerRule> sysRules;
    sysRules.push_back(rule);
    HiSysEventManager::AddEventListener(toolListener, sysRules);
    ```

2.  编译设置：

    在BUILD.gn编译文件中，需要添加依赖hisysevent\_native部件的libhisyseventmanager库。

    ```
    external_deps = [ "hisysevent_native:libhisyseventmanager",  ]
    ```


