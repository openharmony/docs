# IHostapdInterface


## 概述

定义上层WLAN服务的接口。

**起始版本：** 4.1

**相关模块：**[Hostapd](_hostapd.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [StartAp](#startap) () | 打开AP | 
| [StopAp](#stopap) () | 关闭AP | 
| [EnableAp](#enableap) ([in] String ifName, [in] int id) | 启用AP | 
| [DisableAp](#disableap) ([in] String ifName, [in] int id) | 禁用AP. | 
| [SetApPasswd](#setappasswd) ([in] String ifName, [in] String pass, [in]int id) | 设置个人热点密码 | 
| [SetApName](#setapname) ([in] String ifName, [in] String name, [in] int id) | 设置个人热点名称 | 
| [SetApWpaValue](#setapwpavalue) ([in] String ifName, [in] int securityType, [in] int id) | 设置AP安全类型 | 
| [SetApBand](#setapband) ([in] String ifName, [in] int band, [in] int id) | 设置AP带宽 | 
| [SetAp80211n](#setap80211n) ([in] String ifName, [in] int value, [in] int id) | 设置AP需要支持的协议类型 | 
| [SetApWmm](#setapwmm) ([in] String ifName, [in] int value, [in] int id) | 设置AP WMM模式 | 
| [SetApChannel](#setapchannel) ([in] String ifName, [in] int channel, [in] int id) | 设置AP通道 | 
| [SetApMaxConn](#setapmaxconn) ([in] String ifName, [in] int maxConn, [in] int id) | 设置AP最大连接 | 
| [SetMacFilter](#setmacfilter) ([in] String ifName, [in] String mac, [in] int id) | 设置AP模式下的黑名单设置为禁止MAC地址连接 | 
| [DelMacFilter](#delmacfilter) ([in] String ifName, [in] String mac, [in] int id) | 在AP模式下设置的黑名单过滤，并删除来自黑名单中指定的MAC地址。 | 
| [GetStaInfos](#getstainfos) ([in] String ifName, [out] String buf, [in] int size, [in] int id) | 获取有关所有连接的STA的信息 | 
| [DisassociateSta](#disassociatesta) ([in] String ifName, [in] String mac, [in] int id) | 断开指定的STA连接 | 
| [RegisterEventCallback](#registereventcallback) ([in] [IHostapdCallback](interface_i_hostapd_callback.md) cbFunc, [in] String ifName) | 注册回调以侦听异步事件 | 
| [UnregisterEventCallback](#unregistereventcallback) ([in] [IHostapdCallback](interface_i_hostapd_callback.md) cbFunc, [in] String ifName) | 注销回调 | 
| [HostApdShellCmd](#hostapdshellcmd) ([in] String ifName, [in] String cmd) | 用于处理Hostapd的cmd命令 | 


## 成员函数说明


### DelMacFilter()

```
IHostapdInterface::DelMacFilter ([in] String ifName, [in] String mac, [in] int id )
```

**描述**


在AP模式下设置的黑名单过滤，并删除来自黑名单中指定的MAC地址。

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| mac | 表示黑名单中的MAC地址 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### DisableAp()

```
IHostapdInterface::DisableAp ([in] String ifName, [in] int id )
```

**描述**


禁用AP.

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### DisassociateSta()

```
IHostapdInterface::DisassociateSta ([in] String ifName, [in] String mac, [in] int id )
```

**描述**


断开指定的STA连接

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| mac | 表示要断开的指定mac | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### EnableAp()

```
IHostapdInterface::EnableAp ([in] String ifName, [in] int id )
```

**描述**


启用AP

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### GetStaInfos()

```
IHostapdInterface::GetStaInfos ([in] String ifName, [out] String buf, [in] int size, [in] int id )
```

**描述**


获取有关所有连接的STA的信息

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| buf | 表示已连接STA数组信息 | 
| size | 表示获取已连接STA数组中，数组信息的大小。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### HostApdShellCmd()

```
IHostapdInterface::HostApdShellCmd ([in] String ifName, [in] String cmd )
```

**描述**


用于处理Hostapd的cmd命令

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| cmd | 表示来自WifiHal的HostApd命令 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### RegisterEventCallback()

```
IHostapdInterface::RegisterEventCallback ([in] IHostapdCallback cbFunc, [in] String ifName )
```

**描述**


注册回调以侦听异步事件

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cbFunc | 表示要注册的回调 | 
| ifName | 表示网卡名称 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetAp80211n()

```
IHostapdInterface::SetAp80211n ([in] String ifName, [in] int value, [in] int id )
```

**描述**


设置AP需要支持的协议类型

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| value | 表示Hostapd配置值 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetApBand()

```
IHostapdInterface::SetApBand ([in] String ifName, [in] int band, [in] int id )
```

**描述**


设置AP带宽

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| band | 表示SAP带宽 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetApChannel()

```
IHostapdInterface::SetApChannel ([in] String ifName, [in] int channel, [in] int id )
```

**描述**


设置AP通道

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| channel | 表示AP通道 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetApMaxConn()

```
IHostapdInterface::SetApMaxConn ([in] String ifName, [in] int maxConn, [in] int id )
```

**描述**


设置AP最大连接

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| maxConn | 表示设置连接设备的最大数量 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetApName()

```
IHostapdInterface::SetApName ([in] String ifName, [in] String name, [in] int id )
```

**描述**


设置个人热点名称

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| name | 热点名称 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetApPasswd()

```
IHostapdInterface::SetApPasswd ([in] String ifName, [in] String pass, [in] int id )
```

**描述**


设置个人热点密码

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| pass | 密码 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetApWmm()

```
IHostapdInterface::SetApWmm ([in] String ifName, [in] int value, [in] int id )
```

**描述**


设置AP WMM模式

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| value | 表示启用或禁用Wmm | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetApWpaValue()

```
IHostapdInterface::SetApWpaValue ([in] String ifName, [in] int securityType, [in] int id )
```

**描述**


设置AP安全类型

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| securityType | 表示SAP安全类型，例如：wpa/wpa_psk等。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### SetMacFilter()

```
IHostapdInterface::SetMacFilter ([in] String ifName, [in] String mac, [in] int id )
```

**描述**


设置AP模式下的黑名单设置为禁止MAC地址连接

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 
| mac | 表示被阻止的MAC地址 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### StartAp()

```
IHostapdInterface::StartAp ()
```

**描述**


打开AP

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### StopAp()

```
IHostapdInterface::StopAp ()
```

**描述**


关闭AP

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| ifName | 表示网卡名称 | 
| id | 表示热点id | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。


### UnregisterEventCallback()

```
IHostapdInterface::UnregisterEventCallback ([in] IHostapdCallback cbFunc, [in] String ifName )
```

**描述**


注销回调

**起始版本：** 4.1

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| cbFunc | 表示要注销的回调 | 
| ifName | 表示NIC名称 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则为负值。
