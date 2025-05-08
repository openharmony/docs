# 设备安全等级管理开发指导

## 概述

### 功能简介

OpenHarmony的分布式技术可以实现不同设备的资源融合，将多个设备虚拟成一个“超级虚拟终端”。在这个“超级虚拟终端”的内部，处理、流转各类用户数据时，需要确保各个节点不因安全能力薄弱，成为整个“超级虚拟终端”的薄弱点，因此引入设备安全等级管理（DSLM）模块来解决这类问题。

OpenHarmony设备安全等级管理（DSLM）模块，负责管理各种不同形态和种类的OpenHarmony设备的设备安全等级。在各类分布式业务中，当OpenHarmony对各类用户数据进行流转或处理的时候，可以调用本模块提供的接口获取相关目标设备的安全等级，并根据获取到的等级进行相应的处理。

### 基本概念

- 设备安全等级

  OpenHarmony设备的安全等级取决于设备的系统安全能力。OpenHarmony系统安全能力，根植于硬件实现的三个可信根：启动、存储、计算。基于基础安全工程能力，重点围绕以下三点构建相关的安全技术和能力：设备完整性保护、数据机密性保护、漏洞攻防对抗。

  OpenHarmony系统安全架构如下图所示：

  ![OpenHarmony系统安全架构](figures/ohos_system_security_architecture.png)

  上图为典型的OpenHarmony单设备系统安全架构，在不同种类OpenHarmony设备上的实现可以存在差异，取决于设备的威胁分析（风险高低）和设备的软硬件资源。OpenHarmony在参考业界权威的安全分级模型基础上，结合OpenHarmony实际的业务场景和设备分类，将OpenHarmony设备的安全能力划分为 5 个安全等级：SL1 ~ SL5。OpenHarmony操作系统生态体系中，要求高一级的设备安全能力默认包含低一级的设备安全能力。分级概要可参考下图：

  ![OpenHarmony设备安全等级](figures/ohos_device_security_level.png)

  - SL1为OpenHarmony设备中最低的安全等级。这类设备通常搭载轻量级系统和使用低端微处理器，业务形态较为单一，不涉及敏感数据的处理。本安全等级要求消除常见的错误，支持软件的完整性保护。若无法满足本等级的要求，则只能作为配件受OpenHarmony设备操控，无法反向操控OpenHarmony设备并进行更复杂的业务协同。

  - SL2安全等级的OpenHarmony设备，可对自身数据进行标记并定义访问控制规则，实现自主的访问控制，需要具备基础的抗渗透能力。此级别设备可支持轻量化的可安全隔离环境，用于部署少量必需的安全业务。

  - SL3安全等级的OpenHarmony设备，具备较为完善的安全保护能力。其操作系统具有较为完善的安全语义，可支持强制访问控制。系统可结构化为关键保护元素和非关键保护元素，其关键保护元素被明确定义的安全策略模型保护。此级别设备应具备一定的抗渗透能力，可对抗常见的漏洞利用方法。

  - SL4安全等级的OpenHarmony设备，可信基应保持足够的精简，具备防篡改的能力。SL4的实现应足够精简和安全，可对关键保护元素的访问控制进行充分的鉴定和仲裁。此级别设备具备相当的抗渗透能力，可抑制绝大多数软件攻击。

  - SL5安全等级的OpenHarmony设备，为OpenHarmony设备中具备最高等级安全防护能力的设备。系统核心软件模块应进行形式化验证。关键硬件模块如可信根、密码计算引擎等应具备防物理攻击能力，可应对实验室级别的攻击。此级别设备应具备高安全单元，如专用的安全芯片，用于强化设备的启动可信根、存储可信根、运行可信根。

- DSLM

  DSLM(Device Security Level Management), 是OpenHarmony设备安全等级管理的管理模块。负责各OpenHarmony设备之间的设备安全等级信息的同步和验证。并对外提供查询各设备的安全等级的接口。

### 运作机制

当“超级虚拟终端”内的各个设备有了自己的“设备安全等级”，这个“超级虚拟终端”的内部，各类用户数据的处理或流转便有了决策依据。例如：分布式文件存储服务，在处理某些敏感数据时，默认不允许相关数据存储在安全等级低于SL3的设备。

### 约束与限制

OpenHarmony设备的默认安全等级为SL1，设备制造商可以根据设备实际情况定制更高的安全等级。详细请参考章节[定制设备安全等级](#定制设备安全等级)。

应用开发者在调试分布式业务时，如遇到因设备安全等级过低而导致数据处理或流转失败的情况时，也可以参考章节[工具使用介绍](#工具使用介绍)临时提升相关设备的安全等级。

## 开发指导

### 场景介绍

各子系统在处理、流转各类用户数据时，可以调用DSLM模块提供的接口，获取相关设备的安全等级信息。并结合其所处理数据的实际情况，决策数据的进一步处理。

### 接口说明

所有接口均为native C内部接口，仅提供底层能力，不对App开放。相关接口列表如下：
| 接口名                                                       | 说明                                         |
| :----------------------------------------------------------- | :------------------------------------------- |
| int32_t RequestDeviceSecurityInfo(const DeviceIdentify \*identify, const RequestOption \*option, DeviceSecurityInfo \*\*info); | 请求获取某设备的设备安全等级信息（同步接口） |
| int32_t RequestDeviceSecurityInfoAsync(const DeviceIdentify \*identify, const RequestOption \*option, DeviceSecurityInfoCallback callback); | 请求获取某设备的设备安全等级信息（异步接口） |
| void FreeDeviceSecurityInfo(DeviceSecurityInfo \*info);       | 释放设备安全等级信息                         |
| int32_t GetDeviceSecurityLevelValue(const DeviceSecurityInfo \*info, int32_t \*level); | 从设备安全等级信息中提取对应的设备安全等级   |

### 开发步骤

1. 编译依赖添加

    ```undefined
    external_deps += [ "device_security_level:dslm_sdk" ]
    ```

2. 头文件依赖添加

    ```cpp
    #include "device_security_defines.h" // 关键数据结构定义头文件
    #include "device_security_info.h" // 接口函数定义头文件
    ```

3. 接口调用

    ```cpp
    // 查询参数1， 构造获取需要查询设备的设备UDID
    const DeviceIdentify *device = GetDestDeviceUdid();

    // 查询参数2，查询RequestOption构造
    const RequestOption *option = DEFAULT_OPTION;

    // 查询参数3，设备安全等级信息指针，用来接收返回结果
    DeviceSecurityInfo *info = NULL;

    // 调用RequestDeviceSecurityInfo接口获取对端设备的设备安全等级信息：
    int32_t ret = RequestDeviceSecurityInfo(device, DEFAULT_OPTION, &info);

    int32_t level = 0;
    // 从设备安全等级信息中提取设备安全等级字段
    ret = GetDeviceSecurityLevelValue(info, &level);
    if (ret == SUCCESS) {
        // 成功查询到相关等级。 
        FreeDeviceSecurityInfo(info);
        return;
    }
    // 结束处理前，需要释放内存
    FreeDeviceSecurityInfo(info);
    ```

### 开发示例

假设需要开发具备文件分享功能的某业务，为了防止部分敏感文件被无意识的分享出来。可以在其发送任意文件前增加如下判断处理：

- 当目标设备的设备安全等级大于或者等于SL3时，默认允许该文件的传递。
- 当目标设备的设备安全等级小于SL3时，默认拒绝该文件的外传，同时弹框告知用户。

同步接口使用示例

```cpp
void CheckDestDeviceSecurityLevel(const DeviceIdentify *device, RequestOption *option)
{
    // 设备安全等级信息指针
    DeviceSecurityInfo *info = NULL;
    // 调用同步接口获取设备的安全等级等级信息
    int32_t ret = RequestDeviceSecurityInfo(device, option, &info);
    if (ret != SUCCESS) {
        // 获取信息失败。此场景建议开发者根据实际情况进行重试
        return;
    }
    int32_t level = 0;
    // 从设备安全等级信息中提取设备安全等级字段
    ret = GetDeviceSecurityLevelValue(info, &level);
    if (ret != SUCCESS) {
        // 提取信息失败， 此场景建议开发者根据实际情况进行重试
        FreeDeviceSecurityInfo(info);
        return;
    }
    // 成功获取到设备安全等级，确认当前操作允许的最低安全等级
    // 假设当前操作允许的最低设备安全等级为3
    if (level >= 3) {
        // 目标设备的设备安全等级满足要求, 相关业务正常处理
    } else {
        // 目标设备的设备安全等级不满足要求, 建议开发者结合实际业务场景进行相应处理，例如告警、弹窗提示用户等
    }
    // 结束处理前，需要释放内存
    FreeDeviceSecurityInfo(info);
}
```

异步接口使用示例

```cpp
// 回调函数
void DeviceSecurityInfoCallback(const DeviceIdentify *identify, struct DeviceSecurityInfo *info)
{
    int32_t level = 0;
    // 从设备安全等级信息中提取设备安全等级字段
    int32_t ret = GetDeviceSecurityLevelValue(info, &level);
    if (ret != SUCCESS) {
        // 获取信息失败。此场景建议开发者根据实际情况进行重试
        FreeDeviceSecurityInfo(info);
        return;
    }
    // 成功获取到设备安全等级，确认当前操作允许的最低安全等级
    // 假设当前操作允许的最低设备安全等级为3
    if (level >= 3) {
        // 目标设备的设备安全等级满足要求, 相关业务正常处理
    } else {
        // 目标设备的设备安全等级不满足要求, 建议开发者结合实际业务场景进行相应处理，例如告警、弹窗提示用户等
    }
    // 结束处理前，需要释放内存
    FreeDeviceSecurityInfo(info);
}

void CheckDestDeviceSecurityLevelAsync(const DeviceIdentify *device, RequestOption *option)
{
    // 调用异步接口获取设备设备的安全等级等级信息
    int ret = RequestDeviceSecurityInfoAsync(device, option, DeviceSecurityInfoCallback);
    if (ret != SUCCESS) {
        // 获取信息失败，此场景建议开发者根据实际情况进行重试
        // 此场景下callback不会回调。
        return;
    }
    // 调用成功，等待callback回调。
}
```

## 定制设备安全等级

### 设备安全等级凭据

为了保证设备安全等级信息的完整性和不可抵赖性。设备的安全等级信息需要封装在“设备安全等级凭据”（简称为“凭据”）文件中在设备间进行传递，凭据中除了包含设备的安全等级信息之外，还可以包含设备型号、设备版本号等其它设备固有属性，同时使用PKI技术对上述信息进行签名。并结合[设备认证](https://gitee.com/openharmony/security_device_auth)、[HUKS](https://gitee.com/openharmony/security_huks)等OpenHarmony其他基础安全能力。最大程度的保证了凭据传递的安全性。

### 默认实现

OpenHarmony的设备安全等级管理模块提供了安全等级信息同步与验证的默认实现。它假定所有OpenHarmony设备的安全等级为SL1，并且采用了一套较为宽松的验证方案。详细细节可以参考[相关源码](https://gitee.com/openharmony/security_device_security_level/tree/master/oem_property/ohos)。

设备制造商可以根据设备实际情况，参考[基本概念](#基本概念)章节的描述，修改默认的设备安全等级信息。与此同时，设备制造商还可以将OpenHarmony中的默认实现替换为更加严格的验证策略，包括但不限于采用更加精确的一机一凭据策略、从服务器定期下载更新的凭据并严格认证凭据的签发者和有效期、使用TEE(Trusted Execution Environment)甚至SE(Secure Element)对凭据文件进行进一步的签名等流程。

### 生成凭据文件

凭据文件为4段BASE64编码的字符串，中间用"."链接，示例如下：

```undefined
<base64-header>.<base64-payload>.<base64-signature>.<base64-attestation>
```

#### 1. 构造header

当前header为固定的json字符串，其格式化显示如下：

``` json
{
    "typ": "DSL"
}
```

对原header字符串进行BASE64编码，得到`<base64-header>`：

```undefined
eyJ0eXAiOiAiRFNMIn0=
```

#### 2. 构造payload

根据设备实际情况构造payload的json字符串，示例如下：

``` json
{
    "type": "debug",
    "manufacture": "ohos",
    "brand": "rk3568",
    "model": "rk3568",
    "softwareVersion": "3.2.2",
    "securityLevel": "SL1",
    "signTime": "20220209150259",
    "version": "1.0.1"
}
```

对payload字符串进行BASE64编码，得到`<base64-payload>`：

```undefined
eyJ0eXBlIjogImRlYnVnIiwgIm1hbnVmYWN0dXJlIjogIm9ob3MiLCAiYnJhbmQiOiAicmszNTY4IiwgIm1vZGVsIjogInJrMzU2OCIsICJzb2Z0d2FyZVZlcnNpb24iOiAiMy4yLjIiLCAic2VjdXJpdHlMZXZlbCI6ICJTTDEiLCAic2lnblRpbWUiOiAiMjAyMjAyMDkxNTAyNTkiLCAidmVyc2lvbiI6ICIxLjAuMSJ9
```

payload中各字段说明如下：

|     字段名      |      字段说明      | 是否必选字段 |       取值范围        |
| :-------------: | :----------------: | :----------: | :-------------------: |
|      type       |    凭据发布类型    |      是      |    [debug release]    |
|   manufacture   |   设备制造商信息   |      是      |    string [0..128]    |
|      brand      |    设备品牌信息    |      是      |    string [0..128]    |
|      model      |    设备型号信息    |      是      |    string [0..128]    |
| softwareVersion | 设备软件版本号信息 |      是      |    string [0..128]    |
|  securityLevel  |  设备安全等级信息  |      是      | [SL1 SL2 SL3 SL4 SL5] |
|    signTime     |   本凭据签名时间   |      是      |    string [0..128]    |
|     version     |    本凭据版本号    |      是      |    string [0..32]     |
|       sn        |    设备SN序列号    |      否      |    string [0..128]    |
|      udid       |   设备UDID序列号   |      否      |    string [0..128]    |

#### 3. 构造signature

signature是对前面header和payload的签名

##### 3.1 构造构建待签名的原始数据

将BASE64编码后的header和payload合并，中间用符号"."连接，得到`<base64-head>.<base64-payload>`
示例如下：

```undefined
eyJ0eXAiOiAiRFNMIn0=.eyJ0eXBlIjogImRlYnVnIiwgIm1hbnVmYWN0dXJlIjogIm9ob3MiLCAiYnJhbmQiOiAicmszNTY4IiwgIm1vZGVsIjogInJrMzU2OCIsICJzb2Z0d2FyZVZlcnNpb24iOiAiMy4yLjIiLCAic2VjdXJpdHlMZXZlbCI6ICJTTDEiLCAic2lnblRpbWUiOiAiMjAyMjAyMDkxNTAyNTkiLCAidmVyc2lvbiI6ICIxLjAuMSJ9
```

##### 3.2 生成签名私钥

凭据文件使用ECDSA签名算法对原始数据进行签名，首先生成签名用ECDSA密钥对：`<ecc-l3-pk>`和`<ecc-l3-sk>`

> ![notice](../public_sys-resources/icon-notice.gif)**注意：**
> 本流程需要在安全可靠的环境中执行，例如符合相关安全要求的服务器密码机中，以确保用于签名的密钥不被泄露。

##### 3.3 对原始数据进行签名

将`<base64-head>.<base64-payload>`作为参数，使用刚刚生成的ECC私钥`<ecc-l3-sk>`对其进行签名，并对签名结果进行BASE64编码，得到签名结果值`<base64-signature>`：

```undefined
MGUCMDb9xoiFzTWVkHDU3VWSVQ59gLyw4TchZ0+eQ3vUfQsLt3Hkg0r7a/PmhkNr3X/mTgIxAIywIRE6vRTRs0xk6xKp8A0XwMMiIyjZlujPJfasCvFonpsvXLAqCAIYbe1J0k4Zfg==
```

#### 4. 构造attestation

> ![notice](../public_sys-resources/icon-notice.gif)**注意：**
> 本流程需要在安全可靠的环境中执行，例如符合相关安全要求的服务器密码机中，以确保用于签名的密钥不被泄露。
> 本流程涉及到的各密钥对不需要每次都重复生成，在确保密钥安全的前提下，后续可以直接复用。

##### 4.1 生成三级签名验证信息

1. 首先生成二级签名用ECDSA密钥对：`<ecc-l2-pk>`和`<ecc-l2-sk>`
2. 使用`<ecc-l2-sk>` 对3.2章节生成的`<ecc-l3-pk>`进行签名，得到`<ecc-l3-pk-signature>`
3. 将`<ecc-l3-pk>`和`<ecc-l3-pk-signature>`组合成json字符串示例如下：

``` json
{
    "userPublicKey": "<ecc-l3-pk>",
    "signature": "<ecc-l3-pk-signature>"
}
```

##### 4.2 生成二级签名验证信息

1. 生成一级签名用ECDSA密钥对：`<ecc-root-pk>`和`<ecc-root-sk>`
2. 使用`<ecc-root-sk>` 对4.1章节生成的`<ecc-l2-pk>`进行签名，得到`<ecc-l2-pk-signature>`
3. 将`<ecc-l3-pk>`和`<ecc-l3-pk-signature>`组合成json字符串示例如下：

``` json
{
    "userPublicKey": "<ecc-l2-pk>",
    "signature": "<ecc-l2-pk-signature>"
}
```

##### 4.3 生成根签名验证信息

1. 使用`<ecc-root-sk>` 对4.2章节生成的`<ecc-root-pk>`进行签名（即自签名），得到`<ecc-root-pk-self-signature>`
2. 将`<ecc-root-pk>`和`<ecc-root-pk-self-signature>`组合成json字符串示例如下：

``` json
{
    "userPublicKey": "<ecc-root-pk>",
    "signature": "<ecc-root-pk-self-signature>"
}
```

##### 4.4 合并生成attestation

1. 将上述三组签名信息合并到一个json数组中:

    ```json
    [
        {
            "userPublicKey": "<ecc-l3-pk>",
            "signature": "<ecc-l3-pk-signature>"
        },
        {
            "userPublicKey": "<ecc-l2-pk>",
            "signature": "<ecc-l2-pk-signature>"
        },
        {
            "userPublicKey": "<ecc-root-pk>",
            "signature": "<ecc-root-pk-self-signature>"
        }
    ]
    ```

2. 对该数据进行base64编码，得到`<base64-attestation>`

    ```undefined
    W3sidXNlclB1YmxpY0tleSI6ICJNSG93RkFZSEtvWkl6ajBDQVFZSkt5UURBd0lJQVFFTEEySUFCREdOMU9xYWZrWFc2a0l1SEZrMVQ0TS84RVJUY3p0eWRDaGtramFROEkzNEc2Q3E1aTNJcnczVnRhQS9KTTF2a0lHOUZDVWRUaHZFUlJFUTFUdG9xemdxZW9SUzVwQW1EYUUyalEwYzdDem8rOHVUWTRIYW1weXZ1TENtenlYUXFnPT0iLCAic2lnbmF0dXJlIjogIk1HTUNMeHVjUnoyZndKZ092QkxyU1U3K1hlVTA3R0EyVXhZbDFMbEJLUnVIUS9wZlNWVHBEd0ZHSTNTb3h5ODR3NThIQWpBeGRtNEY3b3YvYUtEL0NFZi9QZlZDWHVlbE1mQys1L3pkUExXUUJEVnlGdWQrNVdYL3g4U083VXM5UGFhRW1mZz0ifSwgeyJ1c2VyUHVibGljS2V5IjogIk1Ib3dGQVlIS29aSXpqMENBUVlKS3lRREF3SUlBUUVMQTJJQUJHMWU3TDJVd1AyWWxTajB2RWViUGJpNVpLMDh5NS9UeHRWb3VrRFpIUGtSNlRtb2JoVGpyMVRVNzZpUkU4bDlWQlhuU1h1QVB6cjBuSHdKVkdVZVJMdmp4MVh0YUZReE9QNjhjNlIvRTdFWkZ2STdRUFg1N0tvRkhYdkEvVlJaNnc9PSIsICJzaWduYXR1cmUiOiAiTUdRQ01FUVdFNnk0Rm42SFg1ekFvTzNkYzl5cG1Sd2lBclplc2o5aVBROTZEaEhuNXJkRTdNaGFMdWNRZ0MvaXhjSWJsZ0l3QkN5aFBvRUg2RjFITFlwM2xqbWVncVlZQ1E5NHEyZm1kbDB6dHhrWEVTOVpPOVRNSUZQRVpKYlpmUnU5ZHcyOSJ9LCB7InVzZXJQdWJsaWNLZXkiOiAiTUhvd0ZBWUhLb1pJemowQ0FRWUpLeVFEQXdJSUFRRUxBMklBQkZRUUlDWmpWUTV4bkE0c2RMbUJzUmVaMzRJeWdkSmZhanA3SnRReFBzU2RwWTJXV0FneXp6Rm40OFFRRWhoU1BtdzhJYUU3VlJKRENBT3FYRnhGektJbFBFTDFvcFJDUmhhWmJrRzc5Y3ZrWC9HVVhlaFVYc2V2ZGhyb2VRVERFdz09IiwgInNpZ25hdHVyZSI6ICJNR1FDTUdQRndvSDJLbHhwbVZhWXRWV1ViMHpDSUJxYXFXY2F6czFqOVp4YklLUmVkR2tJY0VJdHN0UFoxdnVTanYvNDJnSXdSeGZPcTRoQTdNMHlGV2ZPSndqRTlTc2JsYXhvRDNiRTZCYzN2QjUyMmsyQ0ZJNWJqelpkeUFTVW04d2J2TW5WIn1d
    ```

#### 5. 构造完整的凭据

用符号"."连接上述四段数据，最终得到 `<base64-header>.<base64-payload>.<base64-signature>.<base64-attestation>`，其示例如下：

```undefined
eyJ0eXAiOiAiRFNMIn0=.eyJ0eXBlIjogImRlYnVnIiwgIm1hbnVmYWN0dXJlIjogIm9ob3MiLCAiYnJhbmQiOiAicmszNTY4IiwgIm1vZGVsIjogInJrMzU2OCIsICJzb2Z0d2FyZVZlcnNpb24iOiAiMy4yLjIiLCAic2VjdXJpdHlMZXZlbCI6ICJTTDEiLCAic2lnblRpbWUiOiAiMjAyMjAyMDkxNTAyNTkiLCAidmVyc2lvbiI6ICIxLjAuMSJ9.MGUCMDb9xoiFzTWVkHDU3VWSVQ59gLyw4TchZ0+eQ3vUfQsLt3Hkg0r7a/PmhkNr3X/mTgIxAIywIRE6vRTRs0xk6xKp8A0XwMMiIyjZlujPJfasCvFonpsvXLAqCAIYbe1J0k4Zfg==.W3sidXNlclB1YmxpY0tleSI6ICJNSG93RkFZSEtvWkl6ajBDQVFZSkt5UURBd0lJQVFFTEEySUFCREdOMU9xYWZrWFc2a0l1SEZrMVQ0TS84RVJUY3p0eWRDaGtramFROEkzNEc2Q3E1aTNJcnczVnRhQS9KTTF2a0lHOUZDVWRUaHZFUlJFUTFUdG9xemdxZW9SUzVwQW1EYUUyalEwYzdDem8rOHVUWTRIYW1weXZ1TENtenlYUXFnPT0iLCAic2lnbmF0dXJlIjogIk1HTUNMeHVjUnoyZndKZ092QkxyU1U3K1hlVTA3R0EyVXhZbDFMbEJLUnVIUS9wZlNWVHBEd0ZHSTNTb3h5ODR3NThIQWpBeGRtNEY3b3YvYUtEL0NFZi9QZlZDWHVlbE1mQys1L3pkUExXUUJEVnlGdWQrNVdYL3g4U083VXM5UGFhRW1mZz0ifSwgeyJ1c2VyUHVibGljS2V5IjogIk1Ib3dGQVlIS29aSXpqMENBUVlKS3lRREF3SUlBUUVMQTJJQUJHMWU3TDJVd1AyWWxTajB2RWViUGJpNVpLMDh5NS9UeHRWb3VrRFpIUGtSNlRtb2JoVGpyMVRVNzZpUkU4bDlWQlhuU1h1QVB6cjBuSHdKVkdVZVJMdmp4MVh0YUZReE9QNjhjNlIvRTdFWkZ2STdRUFg1N0tvRkhYdkEvVlJaNnc9PSIsICJzaWduYXR1cmUiOiAiTUdRQ01FUVdFNnk0Rm42SFg1ekFvTzNkYzl5cG1Sd2lBclplc2o5aVBROTZEaEhuNXJkRTdNaGFMdWNRZ0MvaXhjSWJsZ0l3QkN5aFBvRUg2RjFITFlwM2xqbWVncVlZQ1E5NHEyZm1kbDB6dHhrWEVTOVpPOVRNSUZQRVpKYlpmUnU5ZHcyOSJ9LCB7InVzZXJQdWJsaWNLZXkiOiAiTUhvd0ZBWUhLb1pJemowQ0FRWUpLeVFEQXdJSUFRRUxBMklBQkZRUUlDWmpWUTV4bkE0c2RMbUJzUmVaMzRJeWdkSmZhanA3SnRReFBzU2RwWTJXV0FneXp6Rm40OFFRRWhoU1BtdzhJYUU3VlJKRENBT3FYRnhGektJbFBFTDFvcFJDUmhhWmJrRzc5Y3ZrWC9HVVhlaFVYc2V2ZGhyb2VRVERFdz09IiwgInNpZ25hdHVyZSI6ICJNR1FDTUdQRndvSDJLbHhwbVZhWXRWV1ViMHpDSUJxYXFXY2F6czFqOVp4YklLUmVkR2tJY0VJdHN0UFoxdnVTanYvNDJnSXdSeGZPcTRoQTdNMHlGV2ZPSndqRTlTc2JsYXhvRDNiRTZCYzN2QjUyMmsyQ0ZJNWJqelpkeUFTVW04d2J2TW5WIn1d
```

### 凭据交换协议

设备安全等级模块在感知到有新设备上线时，会通过[分布式软总线](https://gitee.com/openharmony/communication_dsoftbus)提供的通道向该设备请求其设备安全等级凭据。

凭据请求报文格式如下：

``` json
{
    "message": 1,
    "payload": {
        "version": 196608,
        "challenge": "0102030405060708",
        "support": [
            300
        ]
    }
}
```

其中各个字段解释如下：

|  字段名   |               含义解释                |
| :-------: | :-----------------------------------: |
|  message  | 消息头，取值1表示设备安全等级凭据请求 |
|  payload  |      消息payload，具体的请求信息      |
|  version  |           请求端协议版本号            |
| challenge |       本次请求信息对应的挑战值        |
|  support  |       请求端支持的凭据格式列表        |

对端设备在接受到凭据请求后，会按照如下格式进行回复

``` json
{
    "message": 2,
    "payload": {
        "version": 196608,
        "type": 300,
        "challenge": "0102030405060708",
        "info": "YWJjZAEDBQcJ..."
    }
}
```

其中各个字段解释如下：
|  字段名   |                          含义解释                          |
| :-------: | :--------------------------------------------------------: |
|  message  |           消息头，取值2表示设备安全等级凭据应答            |
|  payload  |                消息payload，具体的应答信息                 |
|  version  |                      应答端协议版本号                      |
|   type    |     应答端本次返回的凭据格式，用来描述如何解析info字段     |
| challenge |                  本次应答信息对应的挑战值                  |
|   info    | 签名后的凭据信息，同时还包含设备绑定关系、挑战值校验等信息 |

### 工具使用介绍

为方便开发者对于“凭据文件”的进一步理解，设备安全等级管理模块提供了凭据工具，该工具是一个python脚本，基于OPENSSL命令行的简单封装，可以便捷的提供凭据文件的签发和验证功能。
其使用方法如下：

1. 签名密钥初始化：

    ``` undefined
    ./dslm_cred_tool.py init
    ```

2. 凭据文件的生成：

    生成一个名为cred.txt的凭据文件，并指定设备型号为rk3568、设备版本号为3.0.0、设备安全等级为SL3等payload信息。

    ``` undefined
    ./dslm_cred_tool.py create --field-manufacture OHOS --field-brand rk3568  --field-model rk3568 --field-software-version 3.0.0 --field-security-level SL3 --cred-file cred.txt
    ```

    上述命令可以生成一个凭据示例文件如下：

    ``` undefined
    cat cred.txt
    eyJ0eXAiOiAiRFNMIn0=.eyJ0eXBlIjogImRlYnVnIiwgIm1hbnVmYWN0dXJlIjogIk9IT1MiLCAiYnJhbmQiOiAicmszNTY4IiwgIm1vZGVsIjogInJrMzU2OCIsICJzb2Z0d2FyZVZlcnNpb24iOiAiMy4wLjAiLCAic2VjdXJpdHlMZXZlbCI6ICJTTDMiLCAic2lnblRpbWUiOiAiMjAyMjAyMDkxNTUzMDMiLCAidmVyc2lvbiI6ICIxLjAuMSJ9.MGQCMEqZy/snsRyjMupnEvTpQfhQn+IcdCc5Q3NGxllNQVhoZX8PNyw6ATTgyx+26ghmtQIwVH5KwQ4/VejxckeHmtkBVhofhgmRapzvyVnyiB3PdsU7nvHk8A/zC7PFy1CWBG3z.W3sidXNlclB1YmxpY0tleSI6ICJNSG93RkFZSEtvWkl6ajBDQVFZSkt5UURBd0lJQVFFTEEySUFCQzFXRUxSVlU1NGp1U1ZXWlUrT29CM3hacFd5MWg3QW5uSFdKWm5QbTB3S2l0ZlJZelJKZ3FiUGQyZ3ltVXBUWVl1cmhyRDQxbFdPbUNzcmt0VWdaNTFXdGNCTmc5SG1GODkzc2ZHVFM5eUJNS0JoMGcxSHZaSVFSN1k0S3FXaWpnPT0iLCAic2lnbmF0dXJlIjogIk1HUUNNRFVicTZ2Z2R1YVF0bFVwOTR0azd4VjRJcEx2WVZWY3Y4aFNOTkw0azdPRHhmbEVGTHJFaUdPRWhwMUcweGFGYlFJd1pUbTk1cWx4OTBFZnptV3VIOGlEY2ZWYVlQS2N5SEYwR2ZFcEUzb1NESzQwZEFOZ0FJMWVQY09rTzBPOTdnTFAifSwgeyJ1c2VyUHVibGljS2V5IjogIk1Ib3dGQVlIS29aSXpqMENBUVlKS3lRREF3SUlBUUVMQTJJQUJGKzY1a0lSYTM2dkE4QVZWNXFrcUozYXpXTkdGQy9oaVdPL0tFNHR0S1pMOUsyNlhzQ2hQbjVNc3BlT2F3b1dqSU02bTVLOFZTcU1DYlZNN0svY0VRU0tYdDJTeVJGZERVZU9TaFZmQm9YVmxqaXRUU2puN0V5Q2pERVZiWjFRNEE9PSIsICJzaWduYXR1cmUiOiAiTUdRQ01HanF2cnZ5VW1YNVZLVVc1UkFkUTNkZ2hBYmNBazBRQnppQlFWMVFZUTNQMVFPSzdMckM1b0RObXh6T2Y0QUtmd0l3SzVWU2x3ZG5JSUR6Zm9PUXBEUVAycGhTVGgxSGVjbXJRK1F4VGxWelo0aHJsdnJyd2xCNnp0T3pWRFdNblRELyJ9LCB7InVzZXJQdWJsaWNLZXkiOiAiTUhvd0ZBWUhLb1pJemowQ0FRWUpLeVFEQXdJSUFRRUxBMklBQkZCa2FDNE9mc2VTREt2cW8vbU5VaUtXQ3JtK1VDNGFQcjVsODRNM2tMVCtDdkd3OWhqOGJ6d2I1MzNtVVlFZVhWWWtUdFlRYWRURkRJZXV1dGIzNU1QZDlEKytNMFRFWnZvcTY4NFhoYTVQMzBUbVRhK0ZvOG02UWliZWc3TmFQdz09IiwgInNpZ25hdHVyZSI6ICJNR1FDTURJcmpNYzhvODVPRHFZT0R4c05PcmpYdUhvWjM5endpZlhVTkdDc0lkN2xjU2FWcnhCVlNqRjRyaWg5Y1R6T3dRSXdWQXA3RUF5c1pucEI5REJWVWczQzlMeGQ3eTQxWEMwYVVPcGZUKzI3REVvWmM1WVVldDFGa1FwdmFQckduaFhVIn1d
    ```

3. 凭据文件的校验：

    ``` undefined
    ./dslm_cred_tool.py verify --cred-file cred.txt
    ```

    验证回显如下：

    ``` undefined
    head:
    {
      "typ": "DSL"
    }
    payload:
    {
      "type": "debug",
      "manufacture": "OHOS",
      "brand": "rk3568",
      "model": "rk3568",
      "softwareVersion": "3.0.0",
      "securityLevel": "SL3",
      "signTime": "20220209155303",
      "version": "1.0.1"
    }
    verify success!
    ```

4. 将生成的凭据文件推送到调试设备中并使之生效：
   
   临时关闭系统写保护：
   ``` undefined
   hdc_std target mount
   hdc_std shell "setenforce 0"
   ```

   将刚刚生成的凭据文件推送到设备中：
   ``` undefined
   hdc_std file send cred.txt  /system/etc/dslm_finger.cfg
   ```

   重启设备使新的凭据文件生效：
   ``` undefined
   hdc_std reboot
   ```

## 常见问题

- Q：凭据工具如何在真实的生产环境中使用？

    A：凭据工具不可以直接用于生产环境，它仅仅是一个示例，用来演示凭据的具体格式和生成过程。在真实的生产环境中，我们建议参考凭据工具的实现，在符合相关安全要求的服务器密码机中进行凭据的生成和相关密钥的保存。

- Q：真实的生产环境中，如何对凭据文件进行校验？

    A：我们建议设备制造商使用妥善保管的私钥对凭据文件进行签名，同时替换OpenHarmony中对于凭据文件的默认校验流程，增加对凭据签名者的严格校验。例如仅认可信任机构签发的凭据文件、增加凭据和设备ID的一对一强绑定等校验。

- Q：OpenHarmony设备的默认安全等级为SL1，此级别偏低。导致一些分布式业务（如分布式文件系统）在处理部分敏感数据时因权限不足而失败，该如何解决？

    A：请参考章节[工具使用介绍](#工具使用介绍)临时提升相关调试设备的安全等级。
