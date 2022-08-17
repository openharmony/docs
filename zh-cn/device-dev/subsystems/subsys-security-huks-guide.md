# OpenHarmony通用密钥库开发指导

## 概述

### 功能简介

用户信息的安全取决于密钥的安全，在安全领域里密码系统被攻击通常不是因为选择的加密算法不够安全，而是密钥管理不到位。HUKS（OpenHarmony Universal KeyStore）提供系统级的密钥管理能力，实现密钥全生命周期（生成、存储、使用、销毁）的管理和安全使用，满足生态应用和上层业务的诉求。通过密钥明文不出可信环境、密钥非明文存储等方式，保护用户密钥安全。

支持密钥全生命周期管理，包括以下特性：

1. 密钥生成/导入

2. 密钥存储

3. 密钥使用（加解密、签名验签、密钥派生、密钥协商、哈希、密钥访问控制）

4. 密钥销毁

### 基本概念

- 服务层（HUKS Service）

  提供密钥管理服务的具体业务功能模块，HUKS Service并不直接处理密钥运算，而是依赖HUKS Core为上层提供服务。

- 核心层（HUKS CORE）

  提供密钥管理服务的核心功能模块，密钥全生命周期明文不出HUKS Core模块。

- 可信执行环境（Trusted Execution Environment）

  通过划分软件和硬件资源的方法构建一个安全区域，使得安全区域内部的程序和数据得到保护。这种划分会分隔出两个执行环境——可信执行环境和普通执行环境。每个执行环境有独立的内部数据通路和计算所需存储空间，保证可信执行环境里的信息不会向外泄露。普通执行环境的应用不能访问可信执行环境的资源，可信执行环境中的应用在没有授权的情况下也无法相互访问。

- 三段式（Init-Update-Finish）

   Init：初始化密钥操作数据。

   Update：分段操作数据并返回结果，或追加数据。

   Finish：结束分段操作或追加数据，返回结果。

### 实现原理

以密钥的生成为例介绍HUKS Service与HUKS Core的通信过程，其他密钥操作类似：
上层应用通过密钥管理SDK调用到HUKS Service，HUKS Service再调用HUKS Core，HUKS Core会调用密钥管理模块生成密钥。之后HUKS Core使用基于RootKey派生的加密密钥对生成的密钥加密再传给Service侧，Service侧再以文件形式存储加密后的密钥。

![HUKS密钥生成流程图](figures/HUKS-GenerateKey1.png)

### 约束与限制

1. HUKS的实现需要在可信执行环境中实现，保证密钥管理和操作的可信可靠。

2. HuksHdiAttestKey返回的证书链应该按照业务证书、设备证书、CA证书和根证书的顺序组装，在每项证书之前还需要加上证书的长度。证书链组装完成后添加整个证书链的长度组装成Blob格式。证书的具体格式如要自己实现应与服务器侧解析的格式相对应。

      ![CertChain格式图](figures/HUKS-CertChain.png)

3. 接口返回的密钥必须按照密钥存储态组装成KeyBlob，哪些接口需要遵循该限制请见[接口说明](#接口说明)。

   KeyBlob存储密钥的同时存储它的属性，结构见下图。构造KeyBlob的示例请参见[hks_keyblob.c/HksBuildKeyBlob](https://gitee.com/openharmony/security_huks/blob/master/services/huks_standard/huks_engine/main/core/src/hks_keyblob.c)。

      ![KeyBlob格式图](figures/HUKS-KeyBlob.png)

## 开发指导

### 场景介绍

HUKS Core作为基础向应用提供密钥库能力，包括密钥管理及密钥的密码学操作等功能。如果想要使用自己的实现替换HUKS Core，需要实现以下接口。

### 接口说明

**表1** 接口功能介绍

| 接口名                                                       | 功能介绍                                  | 约束与限制                     | 对应的js接口                                        |
| ------------------------------------------------------------ | ---------------------------------------- | ----------------------------- | ------------------------------------------------------------ |
| [HuksHdiModuleInit()](#hukshdimoduleinit)                   | HUKS Core的初始化。                            |  无                           | 无 |
| [HuksHdiRefresh()](#hukshdirefresh)                          | 刷新根密钥。                              |  无                            | 无 |
| [HuksHdiGenerateKey()](#hukshdigeneratekey)                  | 生成密钥。                                |  出参要遵循KeyBlob格式          |generateKey(keyAlias: string, options: HuksOptions)|
| [HuksHdiImportKey()](#hukshdiimportkey)                     | 导入明文密钥。                            |  出参要遵循KeyBlob格式           | importKey(keyAlias: string, options: HuksOptions)|
| [HuksHdiImportWrappedKey()](#hukshdiimportwrappedkey)        |导入加密密钥。                              |  出参要遵循KeyBlob格式          | importWrappedKey(keyAlias: string, wrappingKeyAlias: string, options: HuksOptions)|
| [HuksHdiExportPublicKey()](#hukshdiexportpublickey)         | 导出公钥。                                 |无                             | exportKey(keyAlias: string, options: HuksOptions) |
| [HuksHdiInit()](#hukshdiinit)                              | 三段式中的Init接口。                       |无                              | init(keyAlias: string, options: HuksOptions) |
| [HuksHdiUpdate()](#hukshdiupdate)                           | 三段式中的Update接口。                     |签名验签时入参是原始数据          | update(handle: number, token?: Uint8Array, options: HuksOptions) |
| [HuksHdiFinish()](#hukshdifinish)                           | 三段式中的Finish接口。                     |签名验签时入参是签名后数据        | finish(handle: number, options: HuksOptions) |
| [HuksHdiAbort()](#hukshdiabort)                         | 终止三段式。                               |无                             | abort(handle: number, options: HuksOptions) |
| [HuksHdiGetKeyProperties()](#hukshdigetkeyproperties)        | 获取密钥属性。                              |无                            | getKeyProperties(keyAlias: string, options: HuksOptions)|
| [HuksHdiAttestKey()](#hukshdiattestkey)        | 获取密钥证书。                              |出参要遵循certChain格式                      | attestKey(keyAlias: string, options: HuksOptions)|

- - -

#### HuksHdiModuleInit

**接口描述**

HUKS Core的初始化，包括锁，加密算法库，authtoken key和根密钥。

**接口原型**
<pre><code>int32_t HuksHdiModuleInit();</code></pre>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

#### HuksHdiRefresh

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

#### HuksHdiGenerateKey

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

  1. 请在接口内检查上述参数是否符合要求，如是否是空指针、密钥算法是否支持等。

  2. keyOut请参照[KeyBlob](#密钥存储态)的结构。

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

#### HuksHdiImportKey

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

  1. 请在接口内检查上述参数是否符合要求，如是否是空指针、密钥算法是否支持等。

  2. keyOut请参照[KeyBlob](#密钥存储态)的结构。

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

#### HuksHdiImportWrappedKey

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

  1. 请在接口内检查上述参数是否符合要求，如是否是空指针、密钥算法是否支持等。

  2. keyOut请参照[KeyBlob](#密钥存储态)的结构。

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

#### HuksHdiExportPublicKey

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

#### HuksHdiInit

**接口描述**

三段式中的Init接口。

**接口原型**
<pre><code>int32_t HuksHdiInit(const struct HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *handle, struct HksBlob *token);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksBlob *key</strong>
  Init操作的密钥，要求：
  1. key != null
  2. key -> data != null
  3. key -> size != 0
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  Init操作的参数
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

#### HuksHdiUpdate

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
  Update操作的参数
  <br></br>
  <strong> const struct HksBlob *inData</strong>
  Update操作的输入
  <br></br>
  <strong> struct HksBlob *outData</strong>
  Update操作的结果
  </pre>
</details>
<br></br>

<details>
  <summary><strong>约束与限制</strong></summary>

  1. 在进行签名验签时inData要传入原文数据。

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

#### HuksHdiFinish

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
  <strong>const struct HksParamSet *paramSet</strong>
  Finish操作的参数
  <br></br>
  <strong>const struct HksBlob *inData</strong>
  Finish操作的输入
  <br></br>
  <strong>struct HksBlob *outData</strong>
  Finish操作的结果
  </pre>
</details>
<br></br>

<details>
  <summary><strong>约束与限制</strong></summary>

  1. 在进行签名验签时inData要传入需要验证的签名数据，通过返回结果表示验签是否成功。

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

#### HuksHdiAbort

**接口描述**

终止三段式。当Init，Update和Finish操作中的任一阶段发生错误时，都要调用abort来终止密钥的使用。

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

#### HuksHdiGetKeyProperties

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

#### HuksHdiAttestKey

**接口描述**

获取密钥证书。

**接口原型**
<pre><code>int32_t (*HuksHdiAttestKey)(const struct HksBlob *key, const struct HksParamSet *paramSet, struct HksBlob *certChain);</code></pre>

<details>
  <summary><strong>参数说明</strong></summary>
  <pre>
  <strong>const struct HksBlob *key</strong>
  要获取证书的密钥
  <br></br>
  <strong>const struct HksParamSet *paramSet</strong>
  获取证书操作的参数
  <br></br>
  <strong>struct HksBlob *certChain</strong>
  出参，存放证书
  </pre>
</details>
<br></br>

<details>
  <summary><strong>约束与限制</strong></summary>

  1. certChain的格式需遵循[约束与限制第二点](#约束与限制)。

</details>
<br></br>

<details>
  <summary><strong>返回值</strong></summary>

  - HKS_SUCCESS：成功

  - 其他：失败
</details>

- - -

### 开发步骤

HUKS Core接口实例，以下是目录结构及各部分功能简介。

```undefined
// base/security/user_auth/services/huks_standard/huks_engine/main
├── BUILD.gn # 编译脚本
├── core_dependency # 实现依赖
└── core # HUKS Core层的软实现
    ├── BUILD.gn # 编译脚本
    ├── include 
    └── src
        ├── hks_core_interfaces.c # Hdi到HUKS Core的适配层
        └── hks_core_service.c # 具体实现
        └── ... #其他功能代码
```

关于HUKS Core接口的具体实现，如果开发者要使用三段式，可以按照以下步骤实现：

1. 创建一个句柄，通过这个句柄在session中存储密钥操作相关的信息，使得外部可以通过这个句柄分多次进行同一密钥操作。

2. 在执行密钥操作前通过句柄获得上下文信息，执行密钥操作时放入分片数据并取回密钥操作结果或者追加数据。

3. 结束密钥操作并取回结果，销毁句柄。

详细代码可以参考[hks_core_service.c](https://gitee.com/openharmony/security_huks/blob/master/services/huks_standard/huks_engine/main/core/src/hks_core_service.c)文件。

```c
   // 三段式Init接口
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
        //初始化handle。通过handle向session中存储信息，供Update/Finish使用。使得外部可以通过同个handle分多次进行同一密钥操作。
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
   
   // 三段式Update接口
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

    // 三段式Finish接口
    int32_t HksCoreFinish(const struct HksBlob *handle, const struct HksParamSet *paramSet, const struct HksBlob *inData,
    struct HksBlob *outData)
    {
        HKS_LOG_D("HksCoreFinish in Core start");
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
            HKS_LOG_E("HksCoreFinish secure access verify failed");
            return ret;
        }

        uint32_t i;
        uint32_t size = HKS_ARRAY_SIZE(g_hksCoreFinishHandler);
        for (i = 0; i < size; i++) {
            //调用对应的密码学处理函数
            if (g_hksCoreFinishHandler[i].pur == pur) {
                uint32_t outDataBufferSize = (outData == NULL) ? 0 : outData->size;
                struct HksBlob appendInData = { 0, NULL };
                ret = HksCoreAppendAuthInfoBeforeFinish(keyNode, pur, paramSet, inData, &appendInData);
                if (ret != HKS_SUCCESS) {
                    HKS_LOG_E("before finish: append auth info failed");
                    break;
                }
                ret = g_hksCoreFinishHandler[i].handler(keyNode, paramSet,
                    appendInData.data == NULL ? inData : &appendInData, outData, alg);
                if (appendInData.data != NULL) {
                    HKS_FREE_BLOB(appendInData);
                }
                if (ret != HKS_SUCCESS) {
                    break;
                }
                //添加密钥操作结束标签
                ret = HksCoreAppendAuthInfoAfterFinish(keyNode, pur, paramSet, outDataBufferSize, outData);
                break;
            }
        }

        if (i == size) {
            HKS_LOG_E("don't found purpose, pur : %d", pur);
            ret = HKS_FAILURE;
        }
        //删除对应的session
        HksDeleteKeyNode(sessionId);
        HKS_LOG_D("HksCoreFinish in Core end");
        return ret;
    }
   ```

### 调测验证

开发完成后，通过[HUKS JS接口](https://gitee.com/openharmony/security_huks/blob/master/interfaces/kits/js/@ohos.security.huks.d.ts)开发JS应用来验证能力是否完备。

对于每个Hdi接口，[接口说明](#接口说明)都提供了对应的JS接口。可以通过调用JS接口组合来验证对应的Hdi接口的能力，也可以通过完整的密钥操作来验证接口的能力。

JS测试代码示例如下：

AES生成密钥和加密

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

        /* 集成生成密钥参数集 & 加密参数集 */
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

        /* 生成密钥 */
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

        /* 进行密钥加密操作 */
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

        /* 修改加密参数集为解密参数集 */
        propertiesEncrypt.splice(1, 1, {
            tag: huks.HuksTag.HUKS_TAG_PURPOSE,
            value: huks.HuksKeyPurpose.HUKS_KEY_PURPOSE_DECRYPT,
        });
        let decryptOptions = {
            properties: propertiesEncrypt,
            inData: new Uint8Array(new Array())
        }
        
        /* 进行解密操作 */
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

RSA512签名验签

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
        /* 集成生成密钥参数集 & 签名参数集 & 验签参数集 */
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
        
        /* 生成密钥 */
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
        /* 对密钥进行签名操作 */
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
        
        /* 通过导出导入模拟获取一段密钥数据 */
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
        
        /* 对密钥进行验签 */
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