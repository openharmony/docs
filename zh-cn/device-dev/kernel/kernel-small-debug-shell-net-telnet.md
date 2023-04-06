# telnet


## 命令功能

本命令用于启动或关闭telnet server服务。


## 命令格式

telnet [_on | off_]


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| on | 启动telnet&nbsp;server服务。 | N/A | 
| off | 关闭telnet&nbsp;server服务。 | N/A | 


## 使用指南

- telnet启动要确保网络驱动及网络协议栈已经初始化完成，且板子的网卡是link up状态。

- 暂时无法支持多个客户端（telnet + IP）同时连接开发板。
  > ![icon-notice.gif](public_sys-resources/icon-notice.gif) **须知：**
  > telnet属于调测功能，默认配置为关闭，正式产品中禁止使用该功能。


## 使用实例

举例：输入telnet on


## 输出说明

**示例** 输入 telnet on


```
OHOS # telnet on
OHOS # start telnet server successfully, waiting for connection.
```
