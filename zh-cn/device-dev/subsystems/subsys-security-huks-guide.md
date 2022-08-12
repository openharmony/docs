# OpenHarmony通用密钥库开发

## 概述

### 功能简介

在安全领域里，密码系统被攻击通常不是因为选择的加密算法不够安全，而是密钥管理不到位。用户信息的安全取决于密钥的安全，所以失去对密钥的控制将导致密码系统的失败，从而危害到用户信息的安全。Huks提供系统级的密钥管理能力，支撑鸿蒙生态应用和系统应用，实现密钥全生命周期（生成，存储，使用，销毁）的管理和安全使用，对标AndriodKeyStore补充和增强密钥管理相关能力，满足生态应用和上层业务的诉求。通过密钥明文不出可信环境、密钥非明文存储等方式，保护用户密钥安全。

支持特性：
1. 国密算法SM2，SM3，SM4
2. 支持AES，RSA，DSA，HMAC，ECC P曲线，ECC 25519曲线，SM2，SM3，SM4的密钥导入
3. 支持AES，RSA，DSA，HMAC，ECC P曲线，ECC 25519曲线的密钥导出
4. 密钥使用访问控制能力，包括锁屏密码，人脸，指纹的访问控制，密钥使用目的/有效期的访问控制
5. 证书生命周期管理。包括公钥证书的生成，导入，存储，销毁以及基于设备密钥做Key Attestation和ID Attestation
6. 安全加固能力，HUKS CORE运行在TEE安全环境中，密钥生命周期不出TEE

### 基本概念

- HUKS Service

  提供密钥管理服务的具体业务功能模块，HUKS Service并不直接处理密钥运算，而是依赖HUKS Core为上层提供服务。

- HUKS Core

  提供密钥管理服务的核心功能模块，密钥全生命周期明文不出HUKS Core模块。

- HUKS Local Engine

  提供密钥本地算法的支持。密钥本地算法与密钥全生命周期管理管理服务的区别是：前者将密钥返回给应用，应用之后可将密钥传给本地算法进行操作，由应用本身管理密钥；后者是为应用生成并存储管理密钥，应用获取不到密钥明文，只能得到一个密钥别名。后续通过密钥别名操作请求密钥进行各种运算操作。

- 可信执行环境（Trusted Execution Environment，TEE）

  通过软硬件方法在中央处理器中构建一个安全区域，保证其内部加载的程序和数据在机密性和完整性上得到保护。通过将系统的硬件和软件资源划分为两个执行环境——可信执行环境和普通执行环境，使其有独立的内部数据通路和计算所需存储空间，保证敏感信息不向外泄漏。普通执行环境的应用不能访问TEE的资源，TEE中的应用在没有授权的情况下也无法相互访问。

- 随机生成

  密钥在HUKS CORE中以随机数形式生成，生成后全生命周期明文不出HUKS CORE

- 导入

  密钥在HUKS CORE外部随机生成，之后明文导入HUKS CORE。导入之后密钥明文全生命周期不出HUKS CORE。由于密钥是明文导入，在传输过程中存在泄露的风险，与之对应的是下面的安全导入。

- 安全导入

  密钥在HUKS CORE外部随机生成，之后使用HUKS CORE中生成的专门用于导入密钥的非对称密钥对的公钥加密，安全导入到HUKS CORE中使用对应的私钥解密。导入之后密钥明文全生命周期不出HUKS CORE。


### 实现原理

以密钥的生成为例：
上层应用通过密钥管理SDK调用到HUKS Service，Huks Service再调用Huks Core，Huks Core会调用密钥管理模块生成密钥。之后Huks Core使用基于RootKey派生的加密密钥对生成的密钥加密再传给Service侧，Service侧再以文件形式存储加密后的密钥。

![image](figures/HUKS-GenrateKey1.png)

![image](figures/HUKS-GenrateKey2.png)


### 约束与限制

1. Huks的实现需要在可信执行环境（TEE）中实现，保证密钥管理和操作的可信可靠。

2. 接口返回的密钥必须按照规定形式组装成KeyBlob，哪些接口需要遵循该限制请见[接口说明](#接口说明)

构造KeyBlob的示例请参见[hks_keyblob.c/HksBuildKeyBlob](https://gitee.com/openharmony/security_huks/blob/master/services/huks_standard/huks_engine/main/core/src/hks_keyblob.c)

#### 密钥存储态

为了基于密钥属性对密钥的使用进行访问控制，需要在存储密钥的同时存储它的相关信息，存储态下密钥属性和密钥的组合结构如下：

![image](figures/HUKS-KeyBlob.png)

## 开发指导

### 场景介绍

HUKS以CORE层为基础向应用提供密钥库能力，包括密钥管理及密钥的密码学操作等功能。如果想要使用自己的实现替换HUKS的CORE层，需要实现以下接口。

### 接口说明

**表1** 接口功能介绍

| 接口名                                                       | 功能介绍                                  | 约束与限制                     | 对应的js接口                                        |
| ------------------------------------------------------------ | ---------------------------------------- | ----------------------------- | ------------------------------------------------------------ |
| HuksHdiModuleInit()                   | Core的初始化。                            |  无                           | 无 |
| HuksHdiRefresh()                          | 刷新根密钥。                              |  无                            | 无 |
| HuksHdiGenerateKey()                  | 生成密钥。                                |  出参要遵循KeyBlob格式          |generateKey(keyAlias: string, options: HuksOptions)|
| HuksHdiImportKey()                     | 导入明文密钥。                            |  出参要遵循KeyBlob格式           | importKey(keyAlias: string, options: HuksOptions)|
| HuksHdiImportWrappedKey()        |导入加密密钥。                              |  出参要遵循KeyBlob格式          | importWrappedKey(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions)|
| HuksHdiExportPublicKey()         | 导出公钥。                                 |无                             | exportKey(keyAlias: string, options: HuksOptions) |
| HuksHdiInit()                              | 三段式中的Init接口。                       |无                              | init(keyAlias: string, options: HuksOptions) |
| HuksHdiUpdate()                           | 三段式中的Update接口。                     |签名验签时入参是原始数据          | update(handle: number, token?: Uint8Array, options: HuksOptions) |
| HuksHdiFinish()                           | 三段式中的Finish接口。                     |签名验签时入参是签名后数据        | finish(handle: number, options: HuksOptions) |
| HuksHdiAbort()                         | 终止三段式。                               |无                             | abort(handle: number, options: HuksOptions) |
| HuksHdiGetKeyProperties()        | 获取密钥属性。                              |无                            | getKeyProperties(keyAlias: string, options: HuksOptions)|

- - -

**HuksHdiModuleInit**

**接口描述**

Core的初始化，包括锁，加密算法库，authtoken key和根密钥。

**接口原型**
<pre><code>int32_t HuksHdiModuleInit();</code></pre>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

**HuksHdiRefresh**

**接口描述**

刷新根密钥。

**接口原型**
<pre><code>int32_t HuksHdiRefresh();</code></pre>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

**HuksHdiGenerateKey**

**接口描述**

根据paramSet生成密钥。

**接口原型**
<pre><code>int32_t HuksHdiGenerateKey(const struct HksBlob *keyAlias, const struct HksParamSet *paramSet, const struct HksBlob *keyIn, struct HksBlob *keyOut);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksBlob *keyAlias</strong>
  将要生成的密钥的别名，要求：
  1. keyAlias != null
  2. keyAlias -> data != null
  3. keyAlias -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  要生成密钥的参数
  <br></br>
  <strong>const struct HksBlob *keyIn</strong>
  在agree key时使用
  <br></br>
  <strong>struct HksBlob *keyOut</strong>
  出参，将paramset和生成的密钥存放在这里
  </pre>
</details>
<br></br>

<details>
  <summary><strong>约束与限制</strong></summary>

  1. 请在接口内检查上述参数是否符合要求，如是否是空指针、密钥算法是否支持等

  2. keyOut请参照[KeyBlob](#密钥存储态)的结构

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

**HuksHdiImportKey**

**接口描述**

导入明文密钥。

**接口原型**
<pre><code>int32_t HuksHdiImportKey(const struct HksBlob *keyAlias, const struct HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *keyOut);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksBlob *msg</strong>
  将要导入的密钥的别名，要求：
  1. keyAlias != null
  2. keyAlias -> data != null
  3. keyAlias -> size != 0
  <br></br>
  <strong>const struct HksBlob *key</strong>
  要导入的密钥，要求：
  1. key != null
  2. key -> data != null
  3. key -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  导入密钥的参数
  <br></br>
  <strong>struct HksBlob *keyOut</strong>
  出参，将paramset和生成的密钥存放在这里
  <br></br>
  </pre>
</details>
<br></br>

<details>
  <summary><strong>约束与限制</strong></summary>

  1. 请在接口内检查上述参数是否符合要求，如是否是空指针、密钥算法是否支持等

  2. keyOut请参照[KeyBlob](#密钥存储态)的结构

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

**HuksHdiImportWrappedKey**

**接口描述**

导入加密密钥。

**接口原型**
<pre><code>int32_t HuksHdiImportWrappedKey(const struct HksBlob *keyAlias, const struct HksBlob *wrappingUsedkey, const struct HksBlob *wrappedKeyData, const struct HksParamSet *paramSet, struct HksBlob *keyOut);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksBlob *KeyAlias</strong>
  将要导入的密钥的别名，要求：
  1. keyAlias != null
  2. keyAlias -> data != null
  3. keyAlias -> size != 0
  <br></br>
  <strong>const struct HksBlob *key</strong>
  要导入的密钥数据被加密时使用的密钥，要求：
  1. wrappingUsedkey != null
  2. wrappingUsedkey -> data != null
  3. wrappingUsedkey -> size != 0
  <br></br>
  <strong>const struct HksBlob *wrappedKeyData</strong>
  要导入的密钥的加密数据，要求：
  1. wrappedKeyData != null
  2. wrappedKeyData -> data != null
  3. wrappedKeyData -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  导入密钥的参数
  <br></br>
  <strong>struct HksBlob *keyOut</strong>
  出参，将paramset和生成的密钥存放在这里
  </pre>
</details>
<br></br>

<details>
  <summary><strong>约束与限制</strong></summary>

  1. 请在接口内检查上述参数是否符合要求，如是否是空指针、密钥算法是否支持等

  2. keyOut请参照[KeyBlob](#密钥存储态)的结构

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

**HuksHdiExportPublicKey**

**接口描述**

导出公钥。

**接口原型**
<pre><code>int32_t HuksHdiExportPublicKey(const struct HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *keyOut);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksBlob *key</strong>
  与要导出的公钥对应的私钥，要求：
  1. key != null
  2. key -> data != null
  3. key -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  空参数
  <br></br>
  <strong>struct HksBlob *keyOut</strong>
  出参，存放导出的公钥
  </pre>
</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

**HuksHdiInit**

**接口描述**

三段式中的Init接口。

**接口原型**
<pre><code>int32_t HuksHdiInit(const struct HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *handle, struct HksBlob *token);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksBlob *key</strong>
  init操作的密钥，要求：
  1. key != null
  2. key -> data != null
  3. key -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  init操作的参数
  <br></br>
  <strong>struct HksBlob *handle</strong>
  三段式的句柄
  <br></br>
  <strong>struct HksBlob *token</strong>
  存放安全访问控制的challenge
  </pre>
</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

**HuksHdiUpdate**

**接口描述**

三段式中的Update接口。

**接口原型**
<pre><code>int32_t HuksHdiUpdate(const struct HksBlob *handle, const struct HksParamSet *paramSet, const struct HksBlob *inData, struct HksBlob *outData);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksBlob *handle</strong>
  三段式的句柄
  <br></br>
  <strong> const struct HksParamSet *paramSet</strong>
  update操作的参数
  <br></br>
  <strong> const struct HksBlob *inData</strong>
  update操作的输入
  <br></br>
  <strong> struct HksBlob *outData</strong>
  update操作的结果
  </pre>
</details>
<br></br>

<details>
  <summary><strong>约束与限制</strong></summary>

  1. 在进行签名验签时inData要传入原文数据

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

**HuksHdiFinish**

**接口描述**

三段式中的Finish接口。

**接口原型**
<pre><code>int32_t HuksHdiFinish(const struct HksBlob *handle, const struct HksParamSet *paramSet, const struct HksBlob *inData, struct HksBlob *outData);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksBlob *handle</strong>
  三段式的句柄
  <br></br>
  <strong> const struct HksParamSet *paramSet</strong>
  finish操作的参数
  <br></br>
  <strong> const struct HksBlob *inData</strong>
  finish操作的输入
  <br></br>
  <strong> struct HksBlob *outData</strong>
  finish操作的结果
  </pre>
</details>
<br></br>

<details>
  <summary><strong>约束与限制</strong></summary>

  1. 在进行签名验签时inData要传入需要验证的签名数据，通过返回结果表示验签是否成功

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

**HuksHdiAbort**

**接口描述**

终止三段式。当init，update和finish操作中的任一阶段发生错误时，都要调用abort来终止密钥的使用。

**接口原型**
<pre><code>int32_t HuksHdiAbort(const struct HksBlob *handle, const struct HksParamSet *paramSet);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksBlob *handle</strong>
  三段式的句柄
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  Abort操作的参数
  </pre>
</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

**HuksHdiGetKeyProperties**

**接口描述**

获取密钥属性。

**接口原型**
<pre><code>int32_t HuksHdiGetKeyProperties(const struct HksParamSet *paramSet, const struct HksBlob *key);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksParamSet *paramSet</strong>
  空对象
  <br></br>
  <strong>const struct HksBlob *key</strong>
  要获取属性的密钥
  </pre>
</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

### 开发步骤

Huks Core层接口实例，以下是目录结构及各部分功能简介。

```undefined
// base/security/user_auth/services/huks_standard/huks_engine/main
├── BUILD.gn # 编译脚本
├── core_dependency # 实现依赖
└── core # Core层的软实现
    ├── BUILD.gn # 编译脚本
    ├── include 
    └── src
        ├── hks_core_interfaces.c # Hdi到Core的适配层
        └── hks_core_service.c # 具体实现
        └── ... #其他功能代码
```

1. 关于Core层接口的具体实现，详细代码参见[hks_core_service.c](https://gitee.com/openharmony/security_huks/blob/master/services/huks_standard/huks_engine/main/core/src/hks_core_service.c)文件。

```c
   // 导入明文密钥
   int32_t HksCoreImportKey(const struct HksBlob *keyAlias, const struct HksBlob *key,
    const struct HksParamSet *paramSet, struct HksBlob *keyOut)
   {
        struct HksBlob innerKey = { 0, NULL };
        struct HksParam *importKeyTypeParam = NULL;
        //在属性里加入IMPORT_KEY
        int32_t ret = HksGetParam(paramSet, HKS_TAG_IMPORT_KEY_TYPE, &importKeyTypeParam);
        if ((ret == HKS_SUCCESS) &&
            ((importKeyTypeParam->uint32Param == HKS_KEY_TYPE_PRIVATE_KEY) ||
            (importKeyTypeParam->uint32Param == HKS_KEY_TYPE_KEY_PAIR))) {
            ret = GetPrivateOrPairInnerFormat(importKeyTypeParam->uint32Param, key, paramSet, &innerKey);
        } else {
            ret = CopyToInnerKey(key, &innerKey);
        }
        if (ret != HKS_SUCCESS) {
            HKS_LOG_E("translate key to inner format failed, ret = %d", ret);
            return ret;
        }
        //检查import key的参数
        ret = HksCoreCheckImportKeyParams(keyAlias, &innerKey, paramSet, keyOut);
        if (ret != HKS_SUCCESS) {
            return ret;
        }
        //构建存储态的密钥
        ret = HksBuildKeyBlob(keyAlias, HKS_KEY_FLAG_IMPORT_KEY, &innerKey, paramSet, keyOut);
        (void)memset_s(innerKey.data, innerKey.size, 0, innerKey.size);
        HKS_FREE_BLOB(innerKey);
        return ret;
   }
   
   // 三段式init接口
   int32_t HksCoreInit(const struct  HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *handle,
    struct HksBlob *token)
    {
        HKS_LOG_D("HksCoreInit in Core start");
        uint32_t pur = 0;
        uint32_t alg = 0;

        if (key == NULL || paramSet == NULL || handle == NULL || token == NULL) {
            HKS_LOG_E("the pointer param entered is invalid");
            return HKS_FAILURE;
        }

        if (handle->size < sizeof(uint64_t)) {
            HKS_LOG_E("handle size is too small, size : %u", handle->size);
            return HKS_ERROR_INSUFFICIENT_MEMORY;
        }

        struct HuksKeyNode *keyNode = HksCreateKeyNode(key, paramSet);
        if (keyNode == NULL || handle == NULL) {
            HKS_LOG_E("the pointer param entered is invalid");
            return HKS_ERROR_BAD_STATE;
        }
        //初始化handle。通过handle向session中存储信息，供update/finish使用。使得外部可以通过同个handle分多次进行同一密钥操作。
        handle->size = sizeof(uint64_t);
        (void)memcpy_s(handle->data, handle->size, &(keyNode->handle), handle->size);
        //从参数中提取出算法
        int32_t ret = GetPurposeAndAlgorithm(paramSet, &pur, &alg);
        if (ret != HKS_SUCCESS) {
            HksDeleteKeyNode(keyNode->handle);
            return ret;
        }

        ret = HksCoreSecureAccessInitParams(keyNode, paramSet, token);
        if (ret != HKS_SUCCESS) {
            HKS_LOG_E("init secure access params failed");
            HksDeleteKeyNode(keyNode->handle);
            return ret;
        }
        
        uint32_t i;
        uint32_t size = HKS_ARRAY_SIZE(g_hksCoreInitHandler);
        for (i = 0; i < size; i++) {
            if (g_hksCoreInitHandler[i].pur == pur) {
                HKS_LOG_E("Core HksCoreInit [pur] = %d, pur = %d", g_hksCoreInitHandler[i].pur, pur);
                ret = g_hksCoreInitHandler[i].handler(keyNode, paramSet, alg);
                break;
            }
        }

        if (ret != HKS_SUCCESS) {
            HksDeleteKeyNode(keyNode->handle);
            HKS_LOG_E("CoreInit failed, ret : %d", ret);
            return ret;
        }

        if (i == size) {
            HksDeleteKeyNode(keyNode->handle);
            HKS_LOG_E("don't found purpose, pur : %u", pur);
            return HKS_FAILURE;
        }

        HKS_LOG_D("HksCoreInit in Core end");
        return ret;
    }
   
   // 三段式update接口
   int32_t HksCoreUpdate(const struct HksBlob *handle, const struct HksParamSet *paramSet, const struct HksBlob *inData,
    struct HksBlob *outData)
{
    HKS_LOG_D("HksCoreUpdate in Core start");
    uint32_t pur = 0;
    uint32_t alg = 0;

    if (handle == NULL || paramSet == NULL || inData == NULL) {
        HKS_LOG_E("the pointer param entered is invalid");
        return HKS_FAILURE;
    }

    uint64_t sessionId;
    struct HuksKeyNode *keyNode = NULL;
    //根据handle获取本次三段式操作需要的上下文
    int32_t ret = GetParamsForUpdateAndFinish(handle, &sessionId, &keyNode, &pur, &alg);
    if (ret != HKS_SUCCESS) {
        HKS_LOG_E("GetParamsForCoreUpdate failed");
        return ret;
    }
    //校验参数
    ret = HksCoreSecureAccessVerifyParams(keyNode, paramSet);
    if (ret != HKS_SUCCESS) {
        HksDeleteKeyNode(sessionId);
        HKS_LOG_E("HksCoreUpdate secure access verify failed");
        return ret;
    }

    uint32_t i;
    uint32_t size = HKS_ARRAY_SIZE(g_hksCoreUpdateHandler);
    for (i = 0; i < size; i++) {
        //调用对应的密码学处理函数
        if (g_hksCoreUpdateHandler[i].pur == pur) {
            struct HksBlob appendInData = { 0, NULL };
            ret = HksCoreAppendAuthInfoBeforeUpdate(keyNode, pur, paramSet, inData, &appendInData);
            if (ret != HKS_SUCCESS) {
                HKS_LOG_E("before update: append auth info failed");
                break;
            }
            ret = g_hksCoreUpdateHandler[i].handler(keyNode, paramSet,
                appendInData.data == NULL ? inData : &appendInData, outData, alg);
            if (appendInData.data != NULL) {
                HKS_FREE_BLOB(appendInData);
            }
            break;
        }
    }

    if (ret != HKS_SUCCESS) {
        HksDeleteKeyNode(keyNode->handle);
        HKS_LOG_E("CoreUpdate failed, ret : %d", ret);
        return ret;
    }

    if (i == size) {
        HksDeleteKeyNode(sessionId);
        HKS_LOG_E("don't found purpose, pur : %u", pur);
        return HKS_FAILURE;
    }
    return ret;
}
   ```

### 调测验证

开发完成后，通过[HUKS JS接口](https://gitee.com/openharmony/security_huks/blob/master/interfaces/kits/js/@ohos.security.huks.d.ts)开发JS应用。JS测试代码如下：

AES生成密钥和加密：

```js
import huks from '@ohos.security.huks';

export default {
    data: {},
    onInit() {
        console.log(`huks demo cipher_aes init finish`);
    },
    onShow() {
        console.log(`huks demo cipher_aes onshow start`);
        this.start();
        console.log(`huks demo cipher_aes onshow end`);
    },
    async start() {
        let handle;
        let IV = '0000000000000000';
        let cipherInData = 'Hks_AES_Cipher_Test_101010101010101010110_string';
        let srcKeyAlias = 'huksCipherAesSrcKeyAlias';
        let encryptUpdateResult = new Array()
        let decryptUpdateResult = new Array()
        let properties = new Array();
        properties[0] = {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_AES,
        }
        properties[1] = {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value:
            huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
            huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
        }
        properties[2] = {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
        }
        properties[3] = {
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
            value: huks.HuksCipherMode.HUKS_MODE_CBC,
        }
        properties[4] = {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
        }

        let HuksOptions = {
            properties: properties,
            inData: new Uint8Array(new Array())
        }

        await huks.generateKey(srcKeyAlias, HuksOptions).then((data) => {
            console.log(`test generateKey data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test generateKey err information: ' + JSON.stringify(err));
        });
        let propertiesEncrypt = new Array();

        propertiesEncrypt[0] = {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_AES,
        }
        propertiesEncrypt[1] = {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT,
        }
        propertiesEncrypt[2] = {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_128,
        }
        propertiesEncrypt[3] = {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
        }
        propertiesEncrypt[4] = {
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
            value: huks.HuksCipherMode.HUKS_MODE_CBC,
        }
        propertiesEncrypt[5] = {
            tag: huks.HuksTag.HUKS_TAG_DIGEST,
            value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
        }
        propertiesEncrypt[6] = {
            tag: huks.HuksTag.HUKS_TAG_IV,
            value: this.stringToUint8Array(IV)
        }
        let encryptOptions = {
            properties: propertiesEncrypt,
            inData: new Uint8Array(new Array())
        }
        await huks.init(srcKeyAlias, encryptOptions).then((data) => {
            console.log(`test init data: ${JSON.stringify(data)}`);
            handle = data.handle;
        }).catch((err) => {
            console.log('test init err information: ' + JSON.stringify(err));
        });
        encryptOptions.inData = this.stringToUint8Array(cipherInData)
        await huks.update(handle, encryptOptions).then(async (data) => {
            console.log(`test update data ${JSON.stringify(data)}`);
            encryptUpdateResult = Array.from(data.outData);
        }).catch((err) => {
            console.log('test update err information: ' + err);
        });
        encryptOptions.inData = new Uint8Array(new Array());
        await huks.finish(handle, encryptOptions).then((data) => {
            console.log(`test finish data: ${JSON.stringify(data)}`);
            let finishData = this.uint8ArrayToString(new Uint8Array(encryptUpdateResult));
            if (finishData === cipherInData) {
                console.log('test finish encrypt err ');
            } else {
                console.log('test finish encrypt success');
            }
        }).catch((err) => {
            console.log('test finish err information: ' + JSON.stringify(err));
        });
        propertiesEncrypt.splice(1, 1, {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
        });
        let decryptOptions = {
            properties: propertiesEncrypt,
            inData: new Uint8Array(new Array())
        }

        await huks.init(srcKeyAlias, decryptOptions).then((data) => {
            console.log(`test init data: ${JSON.stringify(data)}`);
            handle = data.handle;
        }).catch((err) => {
            console.log('test init err information: ' + JSON.stringify(err));
        });

        decryptOptions.inData = new Uint8Array(encryptUpdateResult);
        await huks.update(handle, decryptOptions).then(async (data) => {
            console.log(`test update data ${JSON.stringify(data)}`);
            decryptUpdateResult = Array.from(data.outData);
        }).catch((err) => {
            console.log('test update err information: ' + err);
        });
        decryptOptions.inData = new Uint8Array(new Array());
        await huks.finish(handle, decryptOptions).then((data) => {
            console.log(`test finish data: ${JSON.stringify(data)}`);
            let finishData = this.uint8ArrayToString(new Uint8Array(decryptUpdateResult));
            if (finishData === cipherInData) {
                console.log('test finish decrypt success ');
            } else {
                console.log('test finish decrypt err');
            }
        }).catch((err) => {
            console.log('test finish err information: ' + JSON.stringify(err));
        });

        await huks.deleteKey(srcKeyAlias, HuksOptions).then((data) => {
            console.log(`test deleteKey data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test deleteKey err information: ' + JSON.stringify(err));
        });
    },
    stringToUint8Array(str) {
        var arr = [];
        for (var i = 0, j = str.length; i < j; ++i) {
            arr.push(str.charCodeAt(i));
        }
        return new Uint8Array(arr);
    },
    uint8ArrayToString(fileData) {
        var dataString = '';
        for (var i = 0; i < fileData.length; i++) {
            dataString += String.fromCharCode(fileData[i]);
        }
        return dataString;
    }
}
```

RSA签名验签：

```js
import huks from '@ohos.security.huks';

export default {
    data: {},
    onInit() {
        console.log(`huks demo signVerify_rsa init finish`);
    },
    onShow() {
        console.log(`huks demo signVerify_rsa onshow start`);
        this.start();
        console.log(`huks demo signVerify_rsa onshow end`);
    },
    async start() {
        let handle;
        let signVerifyInData = 'signVerifyInData';
        let srcKeyAliasSign = 'huksSignVerifySrcKeyAliasSign';
        let srcKeyAliasVerify = 'huksSignVerifySrcKeyAliasVerify';
        let properties = new Array();
        let finishOutData;
        let exportKey;
        properties[0] = {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_RSA,
        }
        properties[1] = {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value:
            huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN |
            huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY,
        }
        properties[2] = {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
        }
        properties[3] = {
            tag: huks.HuksTag.HUKS_TAG_DIGEST,
            value: huks.HuksKeyDigest.HUKS_DIGEST_MD5,
        }
        properties[4] = {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
        }


        let HuksOptions = {
            properties: properties,
            inData: new Uint8Array(new Array())
        }

        await huks.generateKey(srcKeyAliasSign, HuksOptions).then((data) => {
            console.log(`test generateKey data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test generateKey err information: ' + JSON.stringify(err));
        });
        let propertiesSign = new Array();

        propertiesSign[0] = {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_RSA,
        }
        propertiesSign[1] = {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value:
            huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_SIGN
        }
        propertiesSign[2] = {
            tag: huks.HuksTag.HUKS_TAG_DIGEST,
            value: huks.HuksKeyDigest.HUKS_DIGEST_MD5,
        }
        propertiesSign[3] = {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
        }
        propertiesSign[4] = {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
        }

        let signOptions = {
            properties: propertiesSign,
            inData: new Uint8Array(new Array())
        }
        await huks.init(srcKeyAliasSign, signOptions).then((data) => {
            console.log(`test init data: ${JSON.stringify(data)}`);
            handle = data.handle;
        }).catch((err) => {
            console.log('test init err information: ' + JSON.stringify(err));
        });
        signOptions.inData = this.stringToUint8Array(signVerifyInData)
        await huks.update(handle, signOptions).then(async (data) => {
            console.log(`test update data ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test update err information: ' + err);
        });
        signOptions.inData = new Uint8Array(new Array());
        await huks.finish(handle, signOptions).then((data) => {
            console.log(`test finish data: ${JSON.stringify(data)}`);
            finishOutData = data.outData;
        }).catch((err) => {
            console.log('test finish err information: ' + JSON.stringify(err));
        });

        await huks.exportKey(srcKeyAliasSign, HuksOptions).then((data) => {
            console.log(`test exportKey data: ${JSON.stringify(data)}`);
            exportKey = data.outData;
        }).catch((err) => {
            console.log('test exportKey err information: ' + JSON.stringify(err));
        });

        let propertiesVerify = new Array();

        propertiesVerify[0] = {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_RSA,
        }
        propertiesVerify[1] = {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_VERIFY
        }
        propertiesVerify[2] = {
            tag: huks.HuksTag.HUKS_TAG_DIGEST,
            value: huks.HuksKeyDigest.HUKS_DIGEST_MD5,
        }

        propertiesVerify[3] = {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_RSA_KEY_SIZE_512,
        }

        propertiesVerify[4] = {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_PKCS1_V1_5,
        }

        let verifyOptions = {
            properties: propertiesVerify,
            inData: new Uint8Array(new Array())
        }

        verifyOptions.inData = exportKey;
        await huks.importKey(srcKeyAliasVerify, verifyOptions).then((data) => {
            console.log(`test ImportKey data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test exportKey err information: ' + JSON.stringify(err));
        });

        await huks.init(srcKeyAliasVerify, verifyOptions).then((data) => {
            console.log(`test init data: ${JSON.stringify(data)}`);
            handle = data.handle;
        }).catch((err) => {
            console.log('test init err information: ' + JSON.stringify(err));
        });

        verifyOptions.inData = this.stringToUint8Array(signVerifyInData);
        await huks.update(handle, verifyOptions).then(async (data) => {
            console.log(`test update data ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test update err information: ' + err);
        });
        verifyOptions.inData = finishOutData;
        await huks.finish(handle, verifyOptions).then((data) => {
            console.log(`test finish data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test finish err information: ' + JSON.stringify(err));
        });

        await huks.deleteKey(srcKeyAliasVerify, HuksOptions).then((data) => {
            console.log(`test deleteKey data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test deleteKey err information: ' + JSON.stringify(err));
        });

        await huks.deleteKey(srcKeyAliasSign, HuksOptions).then((data) => {
            console.log(`test deleteKey data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test deleteKey err information: ' + JSON.stringify(err));
        });
    },
    stringToUint8Array(str) {
        var arr = [];
        for (var i = 0, j = str.length; i < j; ++i) {
            arr.push(str.charCodeAt(i));
        }
        return new Uint8Array(arr);
    },
    uint8ArrayToString(fileData) {
        var dataString = '';
        for (var i = 0; i < fileData.length; i++) {
            dataString += String.fromCharCode(fileData[i]);
        }
        return dataString;
    }
}
```

X25519密钥协商：

```js
import huks from '@ohos.security.huks';

let handle;

export default {
    data: {},
    onInit() {
        console.log(`huks demo agree_x25519 init finish`);
    },
    onShow() {
        console.log(`huks demo agree_x25519 onshow start`);
        this.start();
        console.log(`huks demo agree_x25519 onshow end`);
    },
    async start() {
        let srcKeyAliasFirst = "AgreeX25519KeyFirstAlias";
        let srcKeyAliasSecond = "AgreeX25519KeySecondAlias";
        let agreeX25519InData = 'AgreeX25519TestIndata';
        let exportKeyFrist;
        let exportKeySecond;
        let properties = new Array();

        properties[0] = {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_X25519,
        }
        properties[1] = {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_AGREE,
        }
        properties[2] = {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_CURVE25519_KEY_SIZE_256,
        }
        properties[3] = {
            tag: huks.HuksTag.HUKS_TAG_DIGEST,
            value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
        }
        properties[4] = {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
        }
        properties[5] = {
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
            value: huks.HuksCipherMode.HUKS_MODE_CBC,
        }
        let HuksOptions = {
            properties: properties,
            inData: new Uint8Array(new Array())
        }
        await this.generateKey(srcKeyAliasFirst, HuksOptions).then((data) => {
            console.log('test generateKey data = ' + JSON.stringify(data));
        }).catch((err) => {
            console.log(`test generateKey err: " + ${JSON.stringify(err)}`);
        });

        await this.generateKey(srcKeyAliasSecond, HuksOptions).then((data) => {
            console.log('test generateKey data = ' + JSON.stringify(data));
        }).catch((err) => {
            console.log(`test generateKey err: " + ${JSON.stringify(err)}`);
        });

        await this.exportKey(srcKeyAliasFirst, HuksOptions).then((data) => {
            console.log('test exportKey data = ' + JSON.stringify(data));
            exportKeyFrist = data.outData;
        }).catch((err) => {
            console.log(`test exportKey err: " + ${JSON.stringify(err)}`);
        });

        await this.exportKey(srcKeyAliasSecond, HuksOptions).then((data) => {
            console.log('test exportKey data = ' + JSON.stringify(data));
            exportKeySecond = data.outData;
        }).catch((err) => {
            console.log(`test exportKey err: " + ${JSON.stringify(err)}`);
        });

        await this.init(srcKeyAliasFirst, HuksOptions).then((data) => {
            console.log(`test init data: ${JSON.stringify(data)}`);
            handle = data.handle;
        }).catch((err) => {
            console.log(`test init err: " + ${JSON.stringify(err)}`);
        });

        HuksOptions.inData = exportKeySecond;
        await this.update(handle, HuksOptions).then((data) => {
            console.log(`test update data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log(`test update err: " + ${JSON.stringify(err)}`);
        });

        let finishProperties = new Array();
        finishProperties[0] = {
            tag: huks.HuksTag.HUKS_TAG_KEY_STORAGE_FLAG,
            value: huks.HuksKeyStorageType.HUKS_STORAGE_PERSISTENT,
        }
        finishProperties[1] = {
            tag: huks.HuksTag.HUKS_TAG_IS_KEY_ALIAS,
            value: true
        }
        finishProperties[2] = {
            tag: huks.HuksTag.HUKS_TAG_ALGORITHM,
            value: huks.HuksKeyAlg.HUKS_ALG_AES,
        }
        finishProperties[3] = {
            tag: huks.HuksTag.HUKS_TAG_KEY_SIZE,
            value: huks.HuksKeySize.HUKS_AES_KEY_SIZE_256,
        }
        finishProperties[4] = {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value:
            huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_ENCRYPT |
            huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
        }
        finishProperties[5] = {
            tag: huks.HuksTag.HUKS_TAG_DIGEST,
            value: huks.HuksKeyDigest.HUKS_DIGEST_NONE,
        }
        finishProperties[6] = {
            tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
            value: this.stringToUint8Array(srcKeyAliasFirst+ 'final'),
        }
        finishProperties[7] = {
            tag: huks.HuksTag.HUKS_TAG_PADDING,
            value: huks.HuksKeyPadding.HUKS_PADDING_NONE,
        }
        finishProperties[8] = {
            tag: huks.HuksTag.HUKS_TAG_BLOCK_MODE,
            value: huks.HuksCipherMode.HUKS_MODE_ECB,
        }

        let finishOptionsFrist = {
            properties: finishProperties,
            inData: this.stringToUint8Array(agreeX25519InData)
        }

        await this.finish(handle, finishOptionsFrist).then((data) => {
            console.log(`test finish data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test finish err information: ' + JSON.stringify(err));
        });

        await this.init(srcKeyAliasSecond, HuksOptions).then((data) => {
            console.log(`test init data: ${JSON.stringify(data)}`);
            handle = data.handle;
        }).catch((err) => {
            console.log(`test init err: " + ${JSON.stringify(err)}`);
        });

        HuksOptions.inData = exportKeyFrist;
        await this.update(handle, HuksOptions).then((data) => {
            console.log(`test update data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log(`test update err: " + ${JSON.stringify(err)}`);
        });

        let finishOptionsSecond = {
            properties: finishProperties,
            inData: this.stringToUint8Array(agreeX25519InData)
        }
        finishOptionsSecond.properties.splice(6, 1, {
            tag: huks.HuksTag.HUKS_TAG_KEY_ALIAS,
            value: this.stringToUint8Array(srcKeyAliasSecond + 'final'),
        })
        await this.finish(handle, finishOptionsSecond).then((data) => {
            console.log(`test finish data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test finish err information: ' + JSON.stringify(err));
        });

        await this.deleteKey(srcKeyAliasFirst, HuksOptions).then((data) => {
            console.log(`test deleteKey data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test deleteKey err information: ' + JSON.stringify(err));
        });
        await this.deleteKey(srcKeyAliasSecond, HuksOptions).then((data) => {
            console.log(`test deleteKey data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test deleteKey err information: ' + JSON.stringify(err));
        });
        await this.deleteKey(srcKeyAliasFirst+'final', HuksOptions).then((data) => {
            console.log(`test deleteKey data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test deleteKey err information: ' + JSON.stringify(err));
        });
        await this.deleteKey(srcKeyAliasSecond+'final', HuksOptions).then((data) => {
            console.log(`test deleteKey data: ${JSON.stringify(data)}`);
        }).catch((err) => {
            console.log('test deleteKey err information: ' + JSON.stringify(err));
        });
    },
    // 使用Promise封装callback,方便调用的逻辑处理
    generateKey(srcKeyAlies, HuksOptions) {
        return new Promise((resolve, reject) => {
            huks.generateKey(srcKeyAlies, HuksOptions, function (err, data) {
                console.log(`test generateKey data: ${JSON.stringify(data)}`);
                if (err.code !== 0) {
                    console.log('test generateKey err information: ' + JSON.stringify(err));
                    reject(err);
                } else {
                    resolve(data);
                }
            });
        });
    },
    // 使用Promise封装callback,方便调用的逻辑处理
    exportKey(srcKeyAlies, HuksOptions) {
        return new Promise((resolve, reject) => {
            huks.exportKey(srcKeyAlies, HuksOptions, function (err, data) {
                console.log(`test exportKey data: ${JSON.stringify(data)}`);
                if (err.code !== 0) {
                    console.log('test exportKey err information: ' + JSON.stringify(err));
                    reject(err);
                } else {
                    resolve(data);
                }
            });
        });
    },
    // 使用Promise封装callback,方便调用的逻辑处理
    init(srcKeyAlies, HuksOptions) {
        return new Promise((resolve, reject) => {
            huks.init(srcKeyAlies, HuksOptions, function (err, data) {
                if (err.code !== 0) {
                    console.log('test init err information: ' + JSON.stringify(err));
                    reject(err);
                } else {
                    resolve(data);
                }
            });
        });
    },
    // 使用Promise封装callback,方便调用的逻辑处理
    update(handle, HuksOptions) {
        return new Promise((resolve, reject) => {
            huks.update(handle, HuksOptions, function (err, data) {
                if (err.code !== 0) {
                    console.log('test update err information: ' + JSON.stringify(err));
                    reject(err);
                } else {
                    resolve(data);
                }
            });
        });
    },
    // 使用Promise封装callback,方便调用的逻辑处理
    abort(handle, HuksOptionsAbort) {
        return new Promise((resolve, reject) => {
            huks.abort(handle, HuksOptionsAbort, function (err, data) {
                if (err.code !== 0) {
                    console.log('test abort err information: ' + JSON.stringify(err));
                    reject(err);
                } else {
                    resolve(data);
                }
            });
        });
    },
    // 使用Promise封装callback,方便调用的逻辑处理
    finish(handle, HuksOptionsFinish) {
        return new Promise((resolve, reject) => {
            huks.finish(handle, HuksOptionsFinish, function (err, data) {
                if (err.code !== 0) {
                    console.log('test finish err information: ' + JSON.stringify(err));
                    reject(err);
                } else {
                    resolve(data);
                }
            });
        });
    },
    // 使用Promise封装callback,方便调用的逻辑处理
    deleteKey(srcKeyAlies, HuksOptions) {
        return new Promise((resolve, reject) => {
            huks.deleteKey(srcKeyAlies, HuksOptions, function (err, data) {
                if (err.code !== 0) {
                    console.log('test deleteKey err information: ' + JSON.stringify(err));
                    reject(err);
                } else {
                    resolve(data);
                }
            });
        });
    },
    stringToUint8Array(str) {
        var arr = [];
        for (var i = 0, j = str.length; i < j; ++i) {
            arr.push(str.charCodeAt(i));
        }
        return new Uint8Array(arr);
    },
}
```
