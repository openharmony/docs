# Hostapd


## 概述

WLAN模块为上层WLAN业务提供API接口。

上层WLAN服务开发人员可根据WLAN模块提供的向上统一接口获取如下能力：建立/关闭WLAN热点，扫描/关联WLAN热点，WLAN平台芯片管理，网络数据缓冲的申请、释放、移动等操作，网络设备管理，电源管理等。

**起始版本：** 4.1


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [HostapdTypes.idl](_hostapd_types_8idl.md) | 定义与WLAN模块相关的数据类型。 | 
| [IHostapdCallback.idl](_i_hostapd_callback_8idl.md) | 提供在重新启动hostapd时调用的回调，返回扫描结果、接收Netlink消息。 | 
| [IHostapdInterface.idl](_i_hostapd_interface_8idl.md) | 提供API接口，实现WLAN热点的开启、关闭、扫描、连接、断开等功能，设置国家代码、管理网络设备。 | 


### 类

| 名称 | 描述 | 
| -------- | -------- |
| struct&nbsp;&nbsp;[HdiApCbParm](_hdi_ap_cb_parm.md) | 定义Feature对象信息。 | 
| interface&nbsp;&nbsp;[IHostapdCallback](interface_i_hostapd_callback.md) | hostapd回调的接口。 | 
| interface&nbsp;&nbsp;[IHostapdInterface](interface_i_hostapd_interface.md) | 定义上层WLAN服务的接口。 | 
