# ntpdate


## 命令功能

命令用于从服务器同步系统时间。


## 命令格式

ntpdate [_SERVER_IP1_] [_SERVER_IP2_]...


## 参数说明

**表1** 参数说明

| 参数 | 参数说明 | 取值范围 | 
| -------- | -------- | -------- |
| SERVER_IP | NTP服务器IP。 | N/A | 


## 使用指南

直接执行ntpdate [_SERVER_IP1_] [_SERVER_IP2_]... ntpdate会获取第一个有效服务器IP的时间并显示。


## 使用实例

举例：使用ntpdate命令更新系统时间：ntpdate 192.168.1.3。


## 输出说明

  
```
OHOS # ntpdate 192.168.1.3
time server 192.168.1.3: Mon Jun 13 09:24:25 2016
```

因为板子和服务器时区的不同，获取后的显示时间可能和服务器时间有数小时的差别。
