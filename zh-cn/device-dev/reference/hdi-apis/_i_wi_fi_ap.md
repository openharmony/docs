# IWiFiAp


## **概述**

**所属模块:**

[WLAN](_w_l_a_n.md)


## **汇总**


### Public 属性

  | Public&nbsp;属性 | 描述 | 
| -------- | -------- |
| [baseFeature](#basefeature) | 基本特性。 | 
| (&nbsp;[getAsscociatedStas](#getasscociatedstas)&nbsp;)(const&nbsp;struct&nbsp;IWiFiAp&nbsp;\*apFeature,&nbsp;struct&nbsp;[StaInfo](_sta_info.md)&nbsp;\*staInfo,&nbsp;uint32_t&nbsp;count,&nbsp;uint32_t&nbsp;\*num) | 获取连接上的所有STA的信息（目前只包含MAC地址）。&nbsp;[更多...](#getasscociatedstas) | 
| (&nbsp;[setCountryCode](#setcountrycode)&nbsp;)(const&nbsp;struct&nbsp;IWiFiAp&nbsp;\*apFeature,&nbsp;const&nbsp;char&nbsp;\*code,&nbsp;uint32_t&nbsp;len) | 设置国家码（表示AP射频所在的国家，规定了AP射频特性，包括AP的发送功率、支持的信道等。其目的是为了使AP的射频特性符合不同国家或区域的法律法规要求）。&nbsp;[更多...](#setcountrycode) | 


## **详细描述**

继承了IWiFiBaseFeature基本特性，并包含AP模式下获取连接STA的信息和设置国家码的功能。

**Since：**

1.0

**Version：**

1.0


## **类成员变量说明**


### baseFeature

  
```
struct IWiFiBaseFeature IWiFiAp::baseFeature
```

**描述：**

基本特性。


### getAsscociatedStas

  
```
int32_t(* IWiFiAp::getAsscociatedStas) (const struct IWiFiAp *apFeature, struct StaInfo *staInfo, uint32_t count, uint32_t *num)
```

**描述：**

获取连接上的所有STA的信息（目前只包含MAC地址）。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| apFeature | 输入参数，AP特性。 | 
| staInfo | 输出参数，保存与AP连接的STA的基本信息。 | 
| count | 输入参数，staInfo结构体数组的元素个数。 | 
| num | 输出参数，实际连接的STA的个数。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。


### setCountryCode

  
```
int32_t(* IWiFiAp::setCountryCode) (const struct IWiFiAp *apFeature, const char *code, uint32_t len)
```

**描述：**

设置国家码（表示AP射频所在的国家，规定了AP射频特性，包括AP的发送功率、支持的信道等。其目的是为了使AP的射频特性符合不同国家或区域的法律法规要求）。

**参数：**

  | 名称 | 描述 | 
| -------- | -------- |
| apFeature | 输入参数，AP特性。 | 
| code | 输入参数，设置的国家码。 | 
| len | 输入参数，国家码长度。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
