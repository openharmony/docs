# wifi_hal.h


## **概述**

**所属模块:**

[WLAN](_w_l_a_n.md)


## **汇总**


### 类

  | 类 | 描述 | 
| -------- | -------- |
| [IWiFi](_i_wi_fi.md) | HAL对WLAN服务提供的基本能力。&nbsp;[更多...](_i_wi_fi.md) | 


### 类型定义

  | 类型定义 | 描述 | 
| -------- | -------- |
| ([CallbackFunc](_w_l_a_n.md#callbackfunc))&nbsp;(uint32_t&nbsp;event,&nbsp;void&nbsp;\*data,&nbsp;const&nbsp;char&nbsp;\*ifName) | 定义IWiFi回调函数的原型，监听异步事件。&nbsp;[更多...](_w_l_a_n.md#callbackfunc) | 


### 函数

  | 函数 | 描述 | 
| -------- | -------- |
| [WifiConstruct](_w_l_a_n.md#wificonstruct)&nbsp;(struct&nbsp;[IWiFi](_i_wi_fi.md)&nbsp;\*\*wifiInstance) | 创建IWiFi结构体，挂接[IWiFi](_i_wi_fi.md)中能力接口。&nbsp;[更多...](_w_l_a_n.md#wificonstruct) | 
| [WifiDestruct](_w_l_a_n.md#wifidestruct)&nbsp;(struct&nbsp;[IWiFi](_i_wi_fi.md)&nbsp;\*\*wifiInstance) | 销毁IWiFi结构体并释放相关资源。&nbsp;[更多...](_w_l_a_n.md#wifidestruct) | 


## **详细描述**

提供给WLAN服务的WLAN基本能力接口。

**Since：**

1.0

**Version：**

1.0
