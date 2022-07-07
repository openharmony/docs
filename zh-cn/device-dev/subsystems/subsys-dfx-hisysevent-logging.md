# HiSysEvent打点


## 概述


### 功能简介

HiSysEvent提供OpenHarmony打点接口，通过在关键路径打点记录系统在运行过程中的重要信息，辅助开发者定位问题，此外还支持开发者将数据上传到云进行大数据质量度量。


### 约束与限制

在进行HiSysEvent事件打点之前，需要先完成HiSysEvent打点配置，具体配置方法请参考[《HiSysEvent打点配置指导》](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-dfx-hisysevent-logging-config.md)。


## 开发指导


### 接口说明

C++打点接口如下：

HiSysEvent类，具体的API详见接口文档 。

  **表4** HiSysEvent接口介绍

| 接口名 | 描述 | 
| -------- | -------- |
| template&lt;typename...&nbsp;Types&gt;&nbsp;static&nbsp;int&nbsp;Write(const&nbsp;std::string&nbsp;&amp;domain,<br/>&nbsp;const&nbsp;std::string&nbsp;&amp;eventName,<br/>&nbsp;EventType&nbsp;type,&nbsp;Types...&nbsp;keyValues) | 接口功能：记录系统事件。<br/>输入参数：<br/>-&nbsp;domain：事件的相关领域，需要使用预置领域请参考Domain，可自定义领域。自定义领域长度在16个字符以内，有效的字符是0-9、A-Z，以字母开头。<br/>-&nbsp;eventName：事件名，长度在32个字符以内，有效的字符是0-9、A-Z、下划线，以字母开头，不能以下划线结尾。<br/>-&nbsp;type：事件类型，参考EventType。<br/>-&nbsp;keyValues：事件参数键值对，支持基本的数据类型、std::string，以及std::vector&lt;基本类型&gt;、std:vector&lt;std::string&gt;。参数名长度在48个字符以内，有效的字符是0-9、A-Z、下划线，以字母开头，不能以下划线结尾。参数名的个数在32个以内。<br/>返回值：<br/>-&nbsp;0：系统事件记录成功。<br/>-&nbsp;负值：系统事件记录失败。 | 

  **表5** HiSysEvent::Domain接口介绍

| 成员名称 | 描述 | 
| -------- | -------- |
| static&nbsp;const&nbsp;std::string&nbsp;AAFWK | 元能力子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;APPEXECFWK | 用户程序框架子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;ACCOUNT | 账号子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;ARKUI | ARKUI子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;AI | AI业务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;BARRIER_FREE | 无障碍软件服务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;BIOMETRICS | 生物特征识别服务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;CCRUNTIME | C/C++运行环境子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;COMMUNICATION | 公共通信子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;DEVELOPTOOLS | 研发工具链子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;DISTRIBUTED_DATAMGR | 分布式数据管理子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;DISTRIBUTED_SCHEDULE | 分布式任务调度子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;GLOBAL | 全球化子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;GRAPHIC | 图形子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;HIVIEWDFX | DFX子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;IAWARE | 本地资源调度管控子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;INTELLI_ACCESSORIES | 智能配件业务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;INTELLI_TV | 智能电视业务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;IVI_HARDWARE | 车机专有硬件服务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;LOCATION | 位置服务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;MSDP | 综合传感处理平台子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;MULTI_MEDIA | 媒体子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;MULTI_MODAL_INPUT | 多模输入子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;NOTIFICATION | 事件通知子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;POWERMGR | 电源服务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;ROUTER | 路由器业务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;SECURITY | 安全子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;SENSORS | 泛Sensor服务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;SOURCE_CODE_TRANSFORMER | 应用移植子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;STARTUP | 启动恢复子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;TELEPHONY | 电话服务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;UPDATE | 升级服务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;USB | USB服务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;WEARABLE_HARDWARE | 穿戴专有硬件服务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;WEARABLE_HARDWARE | 穿戴业务子系统 | 
| static&nbsp;const&nbsp;std::string&nbsp;OTHERS | 其它 | 

  **表6** HiSysEvent::EventType接口介绍

| 接口名 | 描述 | 
| -------- | -------- |
| FAULT | 故障类型事件 | 
| STATISTIC | 统计类型事件 | 
| SECURITY | 安全类型事件 | 
| BEHAVIOR | 系统行为事件 | 


### 开发实例

C++接口实例

1. 源代码开发
   在类定义头文件或者类实现源文件中，包含HiSysEvent头文件：

     
   ```
   #include "hisysevent.h"
   ```

   假设在业务关注应用启动时间start_app，在业务类实现相关源文件中使用（调用接口打点）：

     
   ```
   HiSysEvent::Write(HiSysEvent::Domain::AAFWK, "start_app", HiSysEvent::EventType::FAULT, "app_name", "com.demo");
   ```

2. 编译设置，在BUILD.gn里增加子系统SDK依赖：
     
   ```
   external_deps = [ "hisysevent_native:libhisysevent" ]
   ```
