# HiSysEvent订阅指导<a name="ZH-CN_TOPIC_0000001185655868"></a>

-   [概述](#section315316685112)
-   [接口说明](#section0342191810519)
-   [开发实例](#section123181432175110)

## 概述<a name="section315316685112"></a>

HiSysEvent提供了跨进程订阅机制，开发者可以通过注册订阅接口实时获取关注的事件，例如电池模块侦听功耗相关的事件，用于分析耗电情况。

## 接口说明<a name="section0342191810519"></a>

**表 1**  HiSysEvent订阅接口

<a name="table1844019587496"></a>
<table><thead align="left"><tr id="row1440058184916"><th class="cellrowborder" valign="top" id="mcps1.2.3.1.1"><p id="p19441135844915"><a name="p19441135844915"></a><a name="p19441135844915"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.3.1.2"><p id="p13441195815491"><a name="p13441195815491"></a><a name="p13441195815491"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16441155818499"><td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 "><p id="p877916438211"><a name="p877916438211"></a><a name="p877916438211"></a>int HiSysEventManager::AddEventListener(std::shared_ptr&lt;HiSysEventSubscribeCallBackBase&gt; listener, std::vector&lt;ListenerRule&gt;&amp; rules)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 "><p id="p14727325133216"><a name="p14727325133216"></a><a name="p14727325133216"></a>接口功能：<br>&emsp;&emsp;注册订阅HiSysEvent系统事件侦听对象，可设置规则订阅某些事件。</p>
<p id="p167271525203213"><a name="p167271525203213"></a><a name="p167271525203213"></a>输入参数：</p>
<a name="ul6717142214919"></a><a name="ul6717142214919"></a><ul id="ul6717142214919"><li>listener：订阅回调对象。</li><li>rules：事件订阅规则。</li></ul>
<p id="p83591223153818"><a name="p83591223153818"></a><a name="p83591223153818"></a>返回值：</p>
<a name="ul12105842111913"></a><a name="ul12105842111913"></a><ul id="ul12105842111913"><li>0：订阅成功，重复订阅。</li><li>1：订阅成功，初次订阅。</li><li>其他返回值：订阅失败。</li></ul>
</td>
</tr>
<tr id="row910319443242"><td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 "><p id="p15104154411248"><a name="p15104154411248"></a><a name="p15104154411248"></a>void HiSysEventManager::RemoveListener(std::shared_ptr&lt;HiSysEventSubscribeCallBackBase&gt; listener)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 "><p id="p1104194420248"><a name="p1104194420248"></a><a name="p1104194420248"></a>接口功能：<br>&emsp;&emsp;移除订阅hisysevent系统事件侦听对象。</p>
<p id="p7943171095411"><a name="p7943171095411"></a><a name="p7943171095411"></a>输入参数：</p>
<a name="ul894321075411"></a><a name="ul894321075411"></a><ul id="ul894321075411"><li>listener：订阅回调对象。</li></ul>
<p id="p9744631162515"><a name="p9744631162515"></a><a name="p9744631162515"></a>返回值：<br>&emsp;&emsp;无。</p>
</td>
</tr>
</tbody>
</table>

**表 2**  ListenerRule订阅规则对象

<a name="table1844019587498"></a>
<table><thead align="left"><tr id="row1440058184918"><th class="cellrowborder" valign="top" id="mcps1.2.3.1.1"><p id="p19441135844917"><a name="p19441135844917"></a><a name="p19441135844917"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.3.1.2"><p id="p13441195815493"><a name="p13441195815493"></a><a name="p13441195815493"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row16441155818499"><td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 "><p id="p877916438213"><a name="p877916438213"></a><a name="p877916438213"></a>ListenerRule(const std::string&amp; tag, RuleType ruleType = RuleType::WHOLE_WORD)                                                                      </p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 "><p id="p14727325133218"><a name="p14727325133218"></a><a name="p14727325133218"></a>接口功能：<br>&emsp;&emsp;订阅规则构造函数，创建事件标签订阅规则对象。</p>
<p id="p167271525203215"><a name="p167271525203215"></a><a name="p167271525203215"></a>输入参数：</p>
<a name="ul6717142214921"></a><a name="ul6717142214921"></a><ul id="ul6717142214921">
<li>tag：订阅规则的HisysEvent事件标签，字符串类型，最大长度16个字符（含），有效字符包含大小写字母及数字。</li>
<li>ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。</li></ul>
</td>
</tr>
<tr id="row910319443244"><td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 "><p id="p15104154411250"><a name="p15104154411250"></a><a name="p15104154411250"></a>ListenerRule(const std::string&amp; domain, const std::string&amp; eventName, RuleType ruleType = RuleType::WHOLE_WORD)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 "><p id="p15104154411250"><a name="p15104154411250"></a><a name="p15104154411250"></a>接口功能：<br>&emsp;&emsp;订阅规则构造函数，创建事件领域与事件名称订阅规则对象。</p>
<p id="p7943171095413"><a name="p7943171095413"></a><a name="p7943171095413"></a>输入参数：</p>
<a name="ul894321075413"></a><a name="ul894321075413"></a><ul id="ul894321075413">
<li>domain：订阅规则的HisysEvent事件领域，字符串类型，最大长度16个字符（含），有效字符包含大写字母、数字及下划线。</li>
<li>eventName：订阅规则的HisysEvent事件名称，字符串类型，最大长度32个字符（含），有效字符包含大写字母、数字及下划线。</li>
<li>ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。</li></ul>
</td>
</tr>
<tr id="row910319443246"><td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 "><p id="p15104154411252"><a name="p15104154411252"></a><a name="p15104154411252"></a>ListenerRule(const std::string&amp; domain, const std::string& eventName, const std::string&amp; tag, RuleType ruleType = RuleType::WHOLE_WORD)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 "><p id="p15104154411252"><a name="p15104154411252"></a><a name="p15104154411252"></a>接口功能：<br>&emsp;&emsp;订阅规则构造函数，创建事件领域、事件名称，事件标签订阅规则对象。</p>
<p id="p7943171095415"><a name="p7943171095415"></a><a name="p7943171095415"></a>输入参数：</p>
<a name="ul894321075415"></a><a name="ul894321075415"></a><ul id="ul894321075415">
<li>tag：订阅规则的HisysEvent事件标签，字符串类型，最大长度16个字符（含），有效字符包含大小写字母及数字。</li>
<li>domain：订阅规则的HisysEvent事件领域，字符串类型，最大长度16个字符（含），有效字符包含大写字母、数字及下划线。</li>
<li>eventName：订阅规则的HisysEvent事件名称，字符串类型，最大长度32个字符（含），有效字符包含大写字母、数字及下划线。</li>
<li>ruleType：订阅规则的规则类型，RuleType枚举类型(参考表3)。</li></ul></ul>
</td>
</tr>
</tbody>
</table>

**表 3**  RuleType类型

| 枚举值       | 描述          |
| ------------ | ------------- |
| WHOLE_WORD   | 全词匹配类型  |
| PREFIX       | 前缀匹配类型  |
| REGULAR      | 正则匹配类型  |

**表 4**  HiSysEventSubscribeCallBackBase订阅对象

<a name="table1011703742711"></a>

<table><thead align="left"><tr id="row121187375270"><th class="cellrowborder" valign="top" id="mcps1.2.3.1.1"><p id="p2118143782719"><a name="p2118143782719"></a><a name="p2118143782719"></a>接口名称</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.3.1.2"><p id="p4118037152710"><a name="p4118037152710"></a><a name="p4118037152710"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row111823719274"><td class="cellrowborder" width="60%" valign="top" headers="mcps1.2.3.1.1 "><p id="p161181537112712"><a name="p161181537112712"></a><a name="p161181537112712"></a>void HiSysEventSubscribeCallBackBase::OnHandle(const std::string&amp; domain, const std::string&amp; eventName, const int eventType, const std::string&amp; eventDetail)</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.3.1.2 "><p id="p1772213111011"><a name="p1772213111011"></a><a name="p1772213111011"></a>接口功能：<br>&emsp;&emsp;订阅事件的回调接口。</p>
<p id="p182081719151016"><a name="p182081719151016"></a><a name="p182081719151016"></a>输入参数：</p>
<a name="ul02091819131015"></a><a name="ul02091819131015"></a><ul id="ul02091819131015"><li>domain：事件所属领域。</li><li>eventName：事件的名称。</li><li>eventType：事件类型。</li><li>eventDetail：包含事件相关信息的字符串，以json的形式体现。</li></ul>
<p id="p18209419201010"><a name="p18209419201010"></a><a name="p18209419201010"></a>返回值：<br>&emsp;&emsp;无。</p>
</td>
</tr>
</tbody>
</table>

## 开发实例<a name="section123181432175110"></a>

订阅HiSysEvent事件C++接口实例

1.  源代码开发

    自定义订阅回调实现类头文件DemoListener.h：

	```
	#ifndef DEMO_LISTENER_H
	#define DEMO_LISTENER_H

	#include "hisysevent_subscribe_callback_native.h"

	#include <string>

	class DemoListener : public OHOS::HiviewDFX::HiSysEventSubscribeCallBackNative {
	public:
		explicit DemoListener() : HiSysEventSubscribeCallBackNative() {}
		void OnHandle(const std::string& domain, const std::string& eventName, const int eventType,
			const std::string& eventDetail);
		virtual ~DemoListener() {}
		void OnServiceDied();
	};
	
	#endif DEMO_LISTENER_H
	```

    增加DemoListener.cpp文件，在DemoListener类中根据实际需求自定义订阅回调接口的实现逻辑：

	```
	#include "demo_listener.h"

	#include <iostream>

	void DemoListener::OnHandle(const std::string& domain, const std::string& eventName,
		const int eventType, const std::string& eventDetail)
	{
		std::cout << eventDetail << std::endl;
	}

	void DemoListener::OnServiceDied()
	{
		std::cout << std::string("service disconnect, exit") << std::endl;
		exit(0);
	}
	```

	通过HiSysEventManager类提供的AddEventListener接口注册回调对象，完成对HiSysEvent的订阅：

	```
	auto demoListener = std::make_shared<DemoListener>();
	// 事件标签规则订阅，规则类型为默认的全词匹配类型
	ListenerRule tagRule("dfx");
	// 事件标签规则订阅，规则类型为正则匹配类型
	ListenerRule regRule("dfx.*", RuleType::REGULAR);
	// 事件领域及事件名称规则订阅，规则类型为前缀匹配类型
	ListenerRule domainNameRule("HIVIEWDFX", "APP_USAGE", RuleType::PREFIX);
	std::vector<ListenerRule> sysRules;
	sysRules.push_back(tagRule);
	sysRules.push_back(regRule);
	sysRules.push_back(domainNameRule);
	HiSysEventManager::AddEventListener(demoListener, sysRules);
	```

2.  编译配置文件中增加对hisysevent\_native组件libhisyseventmanager库的依赖：

    ```
	external_deps = [ "hisysevent_native:libhisyseventmanager", ]
	```
