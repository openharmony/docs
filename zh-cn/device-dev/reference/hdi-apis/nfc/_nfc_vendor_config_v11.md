# NfcVendorConfig


## 概述

厂家自定义的NFC配置。

**起始版本：** 4.1

**相关模块：**[HdiNfc](_hdi_nfc_v11.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned int [isoDepExtApduLength](#isodepextapdulength) | 为ISO_DEP定义的扩展APDU长度  | 
| unsigned char [defaultOffHostRoute](#defaultoffhostroute) | 默认路由的SE ID  | 
| unsigned char [defaultOffHostRouteFelica](#defaultoffhostroutefelica) | 基于Felica的默认路由SE ID  | 
| unsigned char [defaultSysCodeRoute](#defaultsyscoderoute) | 基于Felica协议中定义的system code路由的默认路由位置  | 
| unsigned char [defaultSysCodePwrState](#defaultsyscodepwrstate) | 基于Felica协议中定义的system code路由支持的电源状态  | 
| unsigned char [defaultUnconfiguredRoute](#defaultunconfiguredroute) | 基于协议和技术的默认路由.  | 
| unsigned char [esePipeId](#esepipeid) | 配置ese使用的pipeID  | 
| unsigned char [simPipeId](#simpipeid) | 配置SIM卡使用的pipeID  | 
| boolean [pollBailOutMode](#pollbailoutmode) | 配置是否支持bai-out模式，为TRUE则支持，否则则是typeA/B轮询。  | 
| unsigned char [checkAlgorithm](#checkalgorithm) | 为T4T卡选择卡在位检测算法，若未定义则默认使用I_BLOCK。  | 
| unsigned char[] [vendorProtocalDiscoveryCfg](#vendorprotocaldiscoverycfg) | 厂家自定义的私有协议和探索配置  | 
| unsigned char [vendorProtocalDiscoveryCfgSize](#vendorprotocaldiscoverycfgsize) | 厂家自定义的私有协议和探索配置数据大小  | 
| List&lt; unsigned char &gt; [hostWhitelist](#hostwhitelist) | 主机白名单  | 
| List&lt; unsigned char &gt; [offHostRouteUicc](#offhostrouteuicc) | 多SE场景，选择默认路由SIM的offhost列表  | 
| List&lt; unsigned char &gt; [offHostRouteEse](#offhostrouteese) | 多SE场景，选择默认路由eSE的offhost列表  | 
| unsigned char [defaultIsoDepRoute](#defaultisodeproute) | ISO-DEP默认路由位置  | 


## 类成员变量说明


### checkAlgorithm

```
unsigned char NfcVendorConfig::checkAlgorithm
```
**描述**

为T4T卡选择卡在位检测算法，若未定义则默认使用I_BLOCK。


### defaultIsoDepRoute

```
unsigned char NfcVendorConfig::defaultIsoDepRoute
```
**描述**

ISO-DEP默认路由位置


### defaultOffHostRoute

```
unsigned char NfcVendorConfig::defaultOffHostRoute
```
**描述**

默认路由的SE ID


### defaultOffHostRouteFelica

```
unsigned char NfcVendorConfig::defaultOffHostRouteFelica
```
**描述**

基于Felica的默认路由SE ID


### defaultSysCodePwrState

```
unsigned char NfcVendorConfig::defaultSysCodePwrState
```
**描述**

基于Felica协议中定义的system code路由支持的电源状态


### defaultSysCodeRoute

```
unsigned char NfcVendorConfig::defaultSysCodeRoute
```
**描述**

基于Felica协议中定义的system code路由的默认路由位置


### defaultUnconfiguredRoute

```
unsigned char NfcVendorConfig::defaultUnconfiguredRoute
```
**描述**

基于协议和技术的默认路由.


### esePipeId

```
unsigned char NfcVendorConfig::esePipeId
```
**描述**

配置ese使用的pipeID


### hostWhitelist

```
List<unsigned char> NfcVendorConfig::hostWhitelist
```
**描述**

主机白名单


### isoDepExtApduLength

```
unsigned int NfcVendorConfig::isoDepExtApduLength
```
**描述**

为ISO_DEP定义的扩展APDU长度


### offHostRouteEse

```
List<unsigned char> NfcVendorConfig::offHostRouteEse
```
**描述**

多SE场景，选择默认路由eSE的offhost列表


### offHostRouteUicc

```
List<unsigned char> NfcVendorConfig::offHostRouteUicc
```
**描述**

多SE场景，选择默认路由SIM的offhost列表


### pollBailOutMode

```
boolean NfcVendorConfig::pollBailOutMode
```
**描述**

配置是否支持bai-out模式，为TRUE则支持，否则则是typeA/B轮询。


### simPipeId

```
unsigned char NfcVendorConfig::simPipeId
```
**描述**

配置SIM卡使用的pipeID


### vendorProtocalDiscoveryCfg

```
unsigned char [] NfcVendorConfig::vendorProtocalDiscoveryCfg
```
**描述**

厂家自定义的私有协议和探索配置


### vendorProtocalDiscoveryCfgSize

```
unsigned char NfcVendorConfig::vendorProtocalDiscoveryCfgSize
```
**描述**

厂家自定义的私有协议和探索配置数据大小
