# Property


## 概述

执行器属性。

**起始版本：** 4.0

**相关模块：**[HdfPinAuth](_hdf_pin_auth_v20.md)


## 汇总


### Public 属性

| 名称 | 描述 | 
| -------- | -------- |
| unsigned long [authSubType](#authsubtype) | 认证子类型。 | 
| int [lockoutDuration](#lockoutduration) | 剩余锁定时间。 | 
| int [remainAttempts](#remainattempts) | 剩余可重试次数。 | 
| int [nextFailLockoutDuration](#nextfaillockoutduration) | 下一次失败锁定时间。 | 


## 类成员变量说明


### authSubType

```
unsigned long Property::authSubType
```

**描述**

认证子类型。


### lockoutDuration

```
int Property::lockoutDuration
```

**描述**

剩余锁定时间。


### nextFailLockoutDuration

```
int Property::nextFailLockoutDuration
```

**描述**

下一次失败锁定时间。


### remainAttempts

```
int Property::remainAttempts
```

**描述**

剩余可重试次数。
