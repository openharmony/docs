# OH_NativeBundle_ApplicationInfo


## 概述

描述应用包信息。

OH_NativeBundle_ApplicationInfo是[OH_NativeBundle_GetCurrentApplicationInfo()](_bundle.md#oh_nativebundle_getcurrentapplicationinfo)的输出参数，描述了应用的相关信息。

**起始版本：**

9

**相关模块：**

[Bundle](_bundle.md)


## 汇总


### 成员变量

| 名称 | 描述 |
| -------- | -------- |
| [bundleName](#bundlename) | 应用包名。 |
| [fingerprint](#fingerprint) | 应用的指纹信息。 |
| [appId<sup>11+</sup>](#appid) | 应用的appId。 |
| [appIdentifier<sup>11+</sup>](#appidentifier) | 应用的载体ID。 |


## 结构体成员变量说明


### bundleName


```
char* OH_NativeBundle_ApplicationInfo::bundleName
```

**描述：**

应用的包名。

**起始版本：**

9


### fingerprint


```
char* OH_NativeBundle_ApplicationInfo::fingerprint
```

**描述：**

应用的指纹信息。

**起始版本：**

9


### appId


```
char* OH_NativeBundle_ApplicationInfo::appId
```

**描述：**

应用的appId

**起始版本：**

11

### appIdentifier


```
char* OH_NativeBundle_ApplicationInfo::appIdentifier
```

**描述：**

应用的载体ID，应用的唯一标识，由云端统一分配。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。

**起始版本：**

11