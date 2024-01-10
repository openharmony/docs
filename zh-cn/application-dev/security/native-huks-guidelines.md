# 通用密钥库开发指导(Native)

## 场景介绍

HUKS是`OpenHarmony`提供**密钥的全生命周期管理能力**的模块。`HUKS`所管理的密钥可以由应用导入或者由应用调用`HUKS`接口生成。通过HUKS生成的密钥，密钥的全生命周期明文不会出安全环境，能保证任何人都无法获取到密钥的明文。即使生成密钥的业务自身，后续也只能通过HUKS提供的接口请求执行密钥操作，获取操作结果，但无法接触到密钥自身。

针对HUKS，常见的开发场景如下：

* 通过`HUKS`提供的Native API接口[生成新密钥](#生成新密钥)。
* 通过`HUKS`提供的Native API接口[导入外部密钥](#导入外部密钥)。
* 通过`HUKS`提供的Native API接口使用密钥进行[加密解密](#加密解密)。
* 通过`HUKS`提供的Native API接口使用密钥进行[签名验签](#签名验签)。
* 通过`HUKS`提供的Native API接口使用密钥进行[密钥协商](#密钥协商)。
* 通过`HUKS`提供的Native API接口使用密钥进行[密钥派生](#密钥派生)。
* 通过`HUKS`提供的Native API接口进行[密钥证明](#密钥证明)。

## 接口说明

### 密钥使用接口

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_Huks_GetSdkVersion](../reference/native-apis/_huks_key_api.md#oh_huks_getsdkversion) (struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*sdkVersion) | 获取当前Huks sdk版本号。  | 
| [OH_Huks_GenerateKeyItem](../reference/native-apis/_huks_key_api.md#oh_huks_generatekeyitem) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSetIn, struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSetOut) | 生成密钥。  | 
| [OH_Huks_ImportKeyItem](../reference/native-apis/_huks_key_api.md#oh_huks_importkeyitem) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*key) | 导入明文密钥。  | 
| [OH_Huks_ImportWrappedKeyItem](../reference/native-apis/_huks_key_api.md#oh_huks_importwrappedkeyitem) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*wrappingKeyAlias, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*wrappedKeyData) | 导入密文密钥。  | 
| [OH_Huks_ExportPublicKeyItem](../reference/native-apis/_huks_key_api.md#oh_huks_exportpublickeyitem) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*key) | 导出公钥。  | 
| [OH_Huks_DeleteKeyItem](../reference/native-apis/_huks_key_api.md#oh_huks_deletekeyitem) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet) | 删除密钥。  | 
| [OH_Huks_GetKeyItemParamSet](../reference/native-apis/_huks_key_api.md#oh_huks_getkeyitemparamset) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSetIn, struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSetOut) | 获取密钥的属性集。  | 
| [OH_Huks_IsKeyItemExist](../reference/native-apis/_huks_key_api.md#oh_huks_iskeyitemexist) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet) | 判断密钥是否存在。  | 
| [OH_Huks_AttestKeyItem](../reference/native-apis/_huks_key_api.md#oh_huks_attestkeyitem) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_CertChain](../reference/native-apis/_o_h___huks___cert_chain.md) \*certChain) | 获取密钥证书链。  | 
| [OH_Huks_InitSession](../reference/native-apis/_huks_key_api.md#oh_huks_initsession) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*handle, struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*token) | 初始化密钥会话接口，并获取一个句柄（必选）和挑战值（可选）。  | 
| [OH_Huks_UpdateSession](../reference/native-apis/_huks_key_api.md#oh_huks_updatesession) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*inData, struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*outData) | 分段添加密钥操作的数据并进行相应的密钥操作，输出处理数据。  | 
| [OH_Huks_FinishSession](../reference/native-apis/_huks_key_api.md#oh_huks_finishsession) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*inData, struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*outData) | 结束密钥会话并进行相应的密钥操作，输出处理数据。  | 
| [OH_Huks_AbortSession](../reference/native-apis/_huks_key_api.md#oh_huks_abortsession) (const struct [OH_Huks_Blob](../reference/native-apis/_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet) | 取消密钥会话。  | 

### 密钥参数接口

  | 名称 | 描述 | 
| -------- | -------- |
| [OH_Huks_InitParamSet](../reference/native-apis/_huks_param_set_api.md#oh_huks_initparamset) (struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*\*paramSet) | 初始化参数集。  | 
| [OH_Huks_AddParams](../reference/native-apis/_huks_param_set_api.md#oh_huks_addparams) (struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Param](../reference/native-apis/_o_h___huks___param.md) \*params, uint32_t paramCnt) | 添加参数到参数集里面。  | 
| [OH_Huks_BuildParamSet](../reference/native-apis/_huks_param_set_api.md#oh_huks_buildparamset) (struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*\*paramSet) | 构造正式的参数集。  | 
| [OH_Huks_FreeParamSet](../reference/native-apis/_huks_param_set_api.md#oh_huks_freeparamset) (struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*\*paramSet) | 销毁参数集。  | 
| [OH_Huks_CopyParamSet](../reference/native-apis/_huks_param_set_api.md#oh_huks_copyparamset) (const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*fromParamSet, uint32_t fromParamSetSize, struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*\*paramSet) | 复制参数集（深拷贝）。  | 
| [OH_Huks_GetParam](../reference/native-apis/_huks_param_set_api.md#oh_huks_getparam) (const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, uint32_t tag, struct [OH_Huks_Param](../reference/native-apis/_o_h___huks___param.md) \*\*param) | 从参数集中获取参数。  | 
| [OH_Huks_FreshParamSet](../reference/native-apis/_huks_param_set_api.md#oh_huks_freshparamset) (struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, bool isCopy) | 刷新（复制）参数集内Blob类型的数据到参数集内。  | 
| [OH_Huks_IsParamSetTagValid](../reference/native-apis/_huks_param_set_api.md#oh_huks_isparamsettagvalid) (const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet) | 检查参数集中的参数是否有效、是否有重复。  | 
| [OH_Huks_IsParamSetValid](../reference/native-apis/_huks_param_set_api.md#oh_huks_isparamsetvalid) (const struct [OH_Huks_ParamSet](../reference/native-apis/_o_h___huks___param_set.md) \*paramSet, uint32_t size) | 检查参数集大小是否有效。  | 
| [OH_Huks_CheckParamMatch](../reference/native-apis/_huks_param_set_api.md#oh_huks_checkparammatch) (const struct [OH_Huks_Param](../reference/native-apis/_o_h___huks___param.md) \*baseParam, const struct [OH_Huks_Param](../reference/native-apis/_o_h___huks___param.md) \*param) | 比较两个参数是否相同。  | 

## 开发步骤

### 生成新密钥
HUKS提供为业务安全随机生成密钥的能力。通过HUKS生成的密钥，密钥的全生命周期明文不会出安全环境，能保证任何人都无法获取到密钥的明文。即使生成密钥的业务自身，后续也只能通过HUKS提供的接口请求执行密钥操作，获取操作结果，但无法接触到密钥自身。

**开发步骤**

生成密钥时使用[OH_Huks_GenerateKeyItem](../reference/native-apis/_huks_key_api.md#oh_huks_generatekeyitem)方法，传入keyAlias作为密钥别名，传入paramSetIn包含该待生成密钥的属性信息。

1. 确定密钥别名；
2. 初始化密钥属性集：[OH_Huks_InitParamSet](../reference/native-apis/_huks_param_set_api.md#oh_huks_initparamset)、[OH_Huks_AddParams](../reference/native-apis/_huks_param_set_api.md#oh_huks_addparams)、[OH_Huks_BuildParamSet](../reference/native-apis/_huks_param_set_api.md#oh_huks_buildparamset)构造paramSet，其中必须包含[OH_Huks_KeyAlg](../reference/native-apis/_huks_type_api.md#oh_huks_keyalg)，[OH_Huks_KeySize](../reference/native-apis/_huks_type_api.md#oh_huks_keysize)，[OH_Huks_KeyPurpose](../reference/native-apis/_huks_type_api.md#oh_huks_keypurpose)属性；
3. 将密钥别名与密钥参数集作为参数传入，生成密钥。

> **说明**
> 
> 传入的 keyAlias 密钥别名最大为64字节

**C++代码示例：**

```C++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
OH_Huks_Result InitParamSet(
    struct OH_Huks_ParamSet **paramSet,
    const struct OH_Huks_Param *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_AddParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    ret = OH_Huks_BuildParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    return ret;
}

struct OH_Huks_Param g_testGenerateKeyParam[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_ECC
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_ECC_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_NONE
    }
};

static napi_value GenerateKey(napi_env env, napi_callback_info info)
{
    const char *alias = "test_generate";
    struct OH_Huks_Blob aliasBlob = { .size = (uint32_t)strlen(alias), .data = (uint8_t *)alias };
    struct OH_Huks_ParamSet *testGenerateKeyParamSet = nullptr;
    struct OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&testGenerateKeyParamSet, g_testGenerateKeyParam,
        sizeof(g_testGenerateKeyParam) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = OH_Huks_GenerateKeyItem(&aliasBlob, testGenerateKeyParamSet, nullptr);
    } while (0);
    OH_Huks_FreeParamSet(&testGenerateKeyParamSet);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```


### 导入外部密钥

如果密钥是在HUKS外部生成（比如应用间协商生成、服务器端生成），应用可以将密钥导入到HUKS托管。HUKS支持直接将密钥明文导入到HUKS，但是明文导入会导致密钥暴露在REE内存中，一般适用于轻量级设备或低安业务。对于高安敏感业务，HUKS还提供了安全导入密钥的能力，允许业务自己生成密钥，并通过与处于安全环境中的HUKS建立端到端的加密传输通道，将密钥安全加密导入到HUKS中，确保导入传入过程中密钥不被泄露。

与生成密钥一样，密钥一旦导入到HUKS中，密钥的生命周期明文不出安全环境，同样能保证任何人都无法获取到密钥的明文。

#### 明文导入

导入明文密钥时使用[OH_Huks_ImportKeyItem](../reference/native-apis/_huks_key_api.md#oh_huks_importkeyitem)方法，传入keyAlias作为密钥别名，传入paramSetIn包含该密钥的相关信息，其中必须包含密钥材料和密钥属性集。

1. 确定密钥别名；
2. 封装密钥材料和密钥属性集：密钥材料须符合[HUKS密钥材料格式](huks-appendix.md#密钥材料格式)并赋值key字段；另外，[OH_Huks_InitParamSet](../reference/native-apis/_huks_param_set_api.md#oh_huks_initparamset)、[OH_Huks_AddParams](../reference/native-apis/_huks_param_set_api.md#oh_huks_addparams)、[OH_Huks_BuildParamSet](../reference/native-apis/_huks_param_set_api.md#oh_huks_buildparamset)构造paramSet，其中必须包含[OH_Huks_KeyAlg](../reference/native-apis/_huks_type_api.md#oh_huks_keyalg)，[OH_Huks_KeySize](../reference/native-apis/_huks_type_api.md#oh_huks_keysize)，[OH_Huks_KeyPurpose](../reference/native-apis/_huks_type_api.md#oh_huks_keypurpose)属性；
3. 导入密钥。

**C++代码示例：**

```C++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
OH_Huks_Result InitParamSet(
    struct OH_Huks_ParamSet **paramSet,
    const struct OH_Huks_Param *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_AddParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    ret = OH_Huks_BuildParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    return ret;
}

static napi_value ImportKey(napi_env env, napi_callback_info info)
{
    (void)GenerateKey(env, info);
    const char *alias = "test_generate";
    struct OH_Huks_Blob aliasBlob = { .size = (uint32_t)strlen(alias), .data = (uint8_t *)alias };
    uint8_t pubKey[OH_HUKS_ECC_KEY_SIZE_256] = {0};
    struct OH_Huks_Blob publicKey = { OH_HUKS_ECC_KEY_SIZE_256, pubKey };
    struct OH_Huks_ParamSet *testImportKeyParamSet = nullptr;
    struct OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&testImportKeyParamSet, g_testGenerateKeyParam,
            sizeof(g_testGenerateKeyParam) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = OH_Huks_ExportPublicKeyItem(&aliasBlob, testImportKeyParamSet, &publicKey);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 4. Import Key */
        char newKey[] = "test_import";
        struct OH_Huks_Blob newKeyAlias = { .size = (uint32_t)strlen(newKey), .data = (uint8_t *)newKey };
        ohResult = OH_Huks_ImportKeyItem(&newKeyAlias, testImportKeyParamSet, &publicKey);
    } while (0);
    OH_Huks_FreeParamSet(&testImportKeyParamSet);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```

#### 加密导入

相比明文导入，加密导入步骤更多，密钥材料更复杂，此章节将展示开发过程中关键的开发流程和密钥材料数据结构。下图是加密导入的基本开发流程。

**图2** 加密导入开发流程

![huks_import_wrapped_key](figures/huks_import_wrapped_key.png)

**接口说明**

根据开发流程，在导入加密密钥过程中，需要依次调用HUKS的生成密钥、导出公钥、导入加密密钥、删除密钥接口。

需要注意的是，导出密钥接口返回的公钥明文材料是按照**X.509**格式封装，导入加密密钥接口中的密钥材料需满足**Length<sub>Data</sub>-Data** 的格式封装。具体，应用需要按照以下表格中的顺序依次封装加密密钥材料。

**表2** 加密密钥材料格式

| 内容 | 业务公钥长度L<sub>pk2</sub> | 业务公钥pk2 | k2加密参数AAD2长度L<sub>AAD2</sub> | k2加密参数AAD2 |  k2加密参数Nonce2长度L<sub>Nonce2</sub> | k2加密参数Nonce2 |
| :--: |:----:|:----: |:----: | :----:  | :----:|:----:|
|长度| 4字节 |L<sub>pk2</sub>字节| 4字节 | L<sub>AAD2</sub>字节 | 4字节 | L<sub>Nonce2</sub>字节 |
| 内容 | k2加密参数AEAD2长度L<sub>AEAD2</sub> | k2加密参数AEAD2 | k3密文长度L<sub>k3_enc</sub> | k3密文k3_enc |  k3加密参数AAD3长度L<sub>AAD3</sub> | k3加密参数AAD3 |
|长度| 4字节 |L<sub>AEAD2</sub>字节| 4字节 | L<sub>k3_enc</sub>字节 | 4字节 | L<sub>AAD3</sub>字节 |
| 内容| k3加密参数Nonce3长度L<sub>Nonce3</sub> | k3加密参数Nonce3 | k3加密参数AEAD3长度L<sub>AEAD3</sub> | k3加密参数AEAD3 |  **密钥明文材料长度** 的长度L<sub>k1'_size</sub> | 密钥明文材料长度k1'_size |
|长度| 4字节 |L<sub>Nonce3</sub>字节| 4字节 | L<sub>AEAD3</sub>字节 | 4字节 | L<sub>k1'_size</sub>字节 |
|内容|k1'密文长度L<sub>k1'_enc</sub>| k1'密文k1'_enc| | | | |
|长度| 4字节 |L<sub>k1'_enc</sub>字节| | | | |

**开发步骤**

这里主要展示涉及调用HUKS的开发样例（使用ECDH密钥协商套件），部分在业务本地执行的步骤不在这里展示详细样例。

1. 设备A（导入设备）将待导入密钥转换成HUKS格式的密钥材料To_Import_Key；
2. 设备A生成一个非对称密钥对Caller_Key；
3. 设备B（被导入设备）生成一个非对称密钥对Wrapping_Key，其密钥用途设置为unwrap；
4. 设备A生成一个对称密钥Caller_Kek；
5. 设备A、B导出非对称密钥对的公钥材料；
6. 设备A基于Caller_Key和设备B Wrapping_Key的公钥，协商出Agree_Key；
7. 设备A使用Caller_Kek加密To_Import_Key，生成To_Import_Key_Enc；
8. 设备A使用Agree_Key加密Caller_Kek，生成Caller_Kek_Enc；
9. 设备A将Caller_Key的公钥、Caller_Kek_Enc、To_Import_Key_Enc发送给设备B；
10. 设备B封装加密导入密钥材料；
11. 设备B导入封装的加密密钥材料；
12. 设备A、B删除用于加密导入的密钥。

**C++代码示例：**

```C++
#include "napi/native_api.h"
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <algorithm>

OH_Huks_Result InitParamSet(
    struct OH_Huks_ParamSet **paramSet,
    const struct OH_Huks_Param *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_AddParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    ret = OH_Huks_BuildParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    return ret;
}

/**
 * 安全导入主要使用场景，设备A希望安全地将密钥导入到设备B的HUKS中
 * wrappingKey是B设备的密钥对
 * callerKey是A设备的密钥对
 * callerAgreeKey是A设备密钥对的私钥+B设备公钥协商生成的
 */
struct HksImportWrappedKeyTestParams {
    // server key, for real
    struct OH_Huks_Blob *wrappingKeyAlias;
    struct OH_Huks_ParamSet *genWrappingKeyParamSet;
    uint32_t publicKeySize;
    
    struct OH_Huks_Blob *callerKeyAlias;
    struct OH_Huks_ParamSet *genCallerKeyParamSet;
    
    struct OH_Huks_Blob *callerKekAlias;
    struct OH_Huks_Blob *callerKek;
    struct OH_Huks_ParamSet *importCallerKekParamSet;
    
    struct OH_Huks_Blob *callerAgreeKeyAlias;
    struct OH_Huks_ParamSet *agreeParamSet;
    
    struct OH_Huks_ParamSet *importWrappedKeyParamSet;
    struct OH_Huks_Blob *importedKeyAlias;
    struct OH_Huks_Blob *importedPlainKey;
    uint32_t keyMaterialLen;
};

static const uint32_t IV_SIZE = 16;
static uint8_t IV[IV_SIZE] = {0};
OH_Huks_Result MallocAndCheckBlobData(struct OH_Huks_Blob *blob, const uint32_t blobSize) {
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;

    blob->data = (uint8_t *)malloc(blobSize);
    if (blob->data == NULL) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
    }

    return ret;
}
static const uint32_t WRAPPED_KEY_IV_SIZE = 16;
static uint8_t WRAPPED_KEY_IV[IV_SIZE] = "bababababababab";  // this is a test value, for real use the iv should be different every time 

static const uint32_t AAD_SIZE = 16;
static uint8_t AAD[AAD_SIZE] = "abababababababa";  // this is a test value, for real use the aad should be different every time 

static const uint32_t NONCE_SIZE = 12;
static uint8_t NONCE[NONCE_SIZE] = "hahahahahah";  // this is a test value, for real use the nonce should be different every time 

static const uint32_t AEAD_TAG_SIZE = 16;

static const uint32_t X25519_256_SIZE = 256;
static struct OH_Huks_Blob g_wrappingKeyAliasAes256 = {
    .size = (uint32_t)strlen("test_wrappingKey_x25519_aes256"),
    .data = (uint8_t *)"test_wrappingKey_x25519_aes256"};

static struct OH_Huks_Blob g_callerKeyAliasAes256 = {
    .size = (uint32_t)strlen("test_caller_key_x25519_aes256"),
    .data = (uint8_t *)"test_caller_key_x25519_aes256"};

static struct OH_Huks_Blob g_callerKekAliasAes256 = {
    .size = (uint32_t)strlen("test_caller_kek_x25519_aes256"),
    .data = (uint8_t *)"test_caller_kek_x25519_aes256"};

static struct OH_Huks_Blob g_callerAes256Kek = {
    .size = (uint32_t)strlen("This is kek to encrypt plain key"),
    .data = (uint8_t *)"This is kek to encrypt plain key"};

static struct OH_Huks_Blob g_callerAgreeKeyAliasAes256 = {
    .size = (uint32_t)strlen("test_caller_agree_key_x25519_aes256"),
    .data = (uint8_t *)"test_caller_agree_key_x25519_aes256"};

static struct OH_Huks_Blob g_importedKeyAliasAes256 = {
    .size = (uint32_t)strlen("test_import_key_x25519_aes256"),
    .data = (uint8_t *)"test_import_key_x25519_aes256"};

static struct OH_Huks_Blob g_importedAes256PlainKey = {
    .size = (uint32_t)strlen("This is plain key to be imported"),
    .data = (uint8_t *)"This is plain key to be imported"};

static struct OH_Huks_Param g_importWrappedAes256Params[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT | OH_HUKS_KEY_PURPOSE_DECRYPT},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_GCM},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE},
    {.tag = OH_HUKS_TAG_UNWRAP_ALGORITHM_SUITE, .uint32Param = OH_HUKS_UNWRAP_SUITE_X25519_AES_256_GCM_NOPADDING},
    {.tag = OH_HUKS_TAG_ASSOCIATED_DATA, .blob = {.size = AAD_SIZE, .data = (uint8_t *)AAD}}, // this is a test value, for real use the aad should be info associated with caller
    {.tag = OH_HUKS_TAG_NONCE, .blob = {.size = NONCE_SIZE, .data = (uint8_t *)NONCE}}}; // this is a test value, for real use the nonce should be different every time

static const uint32_t g_x25519PubKeySize = 32;

static struct OH_Huks_Param g_genWrappingKeyParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_X25519},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_UNWRAP},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_CURVE25519_KEY_SIZE_256}};

static struct OH_Huks_Param g_genCallerX25519Params[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_X25519},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_CURVE25519_KEY_SIZE_256}};

static struct OH_Huks_Param g_importParamsCallerKek[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_GCM},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE},
    {.tag = OH_HUKS_TAG_IV, .blob = {.size = WRAPPED_KEY_IV_SIZE, .data = (uint8_t *)WRAPPED_KEY_IV }}};  // this is a test value, for real use the iv should be different every time 

static struct OH_Huks_Param g_callerAgreeParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_X25519},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_CURVE25519_KEY_SIZE_256}
};

static struct OH_Huks_Param g_aesKekEncryptParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_GCM},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE},
    {.tag = OH_HUKS_TAG_ASSOCIATED_DATA, .blob = {.size = AAD_SIZE, .data = (uint8_t *)AAD}}, // this is a test value, for real use the aad should be info associated with caller
    {.tag = OH_HUKS_TAG_NONCE, .blob = {.size = NONCE_SIZE, .data = (uint8_t *)NONCE}}}; // this is a test value, for real use the nonce should be different every time

static struct OH_Huks_Param g_importAgreeKeyParams[] = {
    {.tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_AES},
    {.tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT},
    {.tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_AES_KEY_SIZE_256},
    {.tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_NONE},
    {.tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_GCM},
    {.tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_NONE},
    {.tag = OH_HUKS_TAG_IV, .blob = {.size = IV_SIZE, .data = (uint8_t *)IV}}};  // this is a test value, for real use the iv should be different every time 

OH_Huks_Result HuksAgreeKey(const struct OH_Huks_ParamSet *paramSet, const struct OH_Huks_Blob *keyAlias,
                            const struct OH_Huks_Blob *peerPublicKey, struct OH_Huks_Blob *agreedKey)
{
    uint8_t temp[10] = {0};
    struct OH_Huks_Blob inData = {
        sizeof(temp),
        temp};

    uint8_t handleU[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handle = {sizeof(uint64_t), handleU};
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, paramSet, &handle, nullptr);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }

    uint8_t outDataU[1024] = {0};
    struct OH_Huks_Blob outDataUpdate = {1024, outDataU};
    ret = OH_Huks_UpdateSession(&handle, paramSet, peerPublicKey, &outDataUpdate);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_FinishSession(&handle, paramSet, &inData, agreedKey);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}

static const uint32_t TIMES = 4;
static const uint32_t MAX_UPDATE_SIZE = 64;
static const uint32_t MAX_OUTDATA_SIZE = MAX_UPDATE_SIZE * TIMES;

#define HUKS_FREE_BLOB(blob) do { \
    if ((blob).data != nullptr) { \
        free((blob).data); \
        (blob).data = nullptr; \
    } \
    (blob).size = 0; \
} while (0)

#define OH_HUKS_KEY_BYTES(keySize) (((keySize) + 7) / 8)

static OH_Huks_Result HksEncryptLoopUpdate(const struct OH_Huks_Blob *handle, const struct OH_Huks_ParamSet *paramSet,
                                           const struct OH_Huks_Blob *inData, struct OH_Huks_Blob *outData)
{
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;

    struct OH_Huks_Blob inDataSeg = *inData;
    uint8_t *lastPtr = inData->data + inData->size - 1;
    struct OH_Huks_Blob outDataSeg = {MAX_OUTDATA_SIZE, NULL};
    uint8_t *cur = outData->data;
    outData->size = 0;

    inDataSeg.size = MAX_UPDATE_SIZE;
    bool isFinished = false;

    while (inDataSeg.data <= lastPtr) {
        if (inDataSeg.data + MAX_UPDATE_SIZE <= lastPtr)
        {
            outDataSeg.size = MAX_OUTDATA_SIZE;
        }
        else
        {
            isFinished = true;
            inDataSeg.size = lastPtr - inDataSeg.data + 1;
            break;
        }
        if (MallocAndCheckBlobData(&outDataSeg, outDataSeg.size).errorCode != (int32_t)OH_HUKS_SUCCESS)
        {
            ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
            return ret;
        }
        ret = OH_Huks_UpdateSession(handle, paramSet, &inDataSeg, &outDataSeg);
        if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
            free(outDataSeg.data);
            return ret;
        }
        std::copy(outDataSeg.data, outDataSeg.data + outDataSeg.size, cur);
        cur += outDataSeg.size;
        outData->size += outDataSeg.size;
        free(outDataSeg.data);
        if ((isFinished == false) && (inDataSeg.data + MAX_UPDATE_SIZE > lastPtr)) {
            ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
            return ret;
        }
        inDataSeg.data += MAX_UPDATE_SIZE;
    }

    struct OH_Huks_Blob outDataFinish = {inDataSeg.size * TIMES, NULL};
    if (MallocAndCheckBlobData(&outDataFinish, outDataFinish.size).errorCode != (int32_t)OH_HUKS_SUCCESS) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
        return ret;
    }

    ret = OH_Huks_FinishSession(handle, paramSet, &inDataSeg, &outDataFinish);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        free(outDataFinish.data);
        return ret;
    }
    std::copy(outDataFinish.data, outDataFinish.data + outDataFinish.size, cur);
    outData->size += outDataFinish.size;
    free(outDataFinish.data);

    return ret;
}

OH_Huks_Result HuksEncrypt(const struct OH_Huks_Blob *key, const struct OH_Huks_ParamSet *paramSet,
                           const struct OH_Huks_Blob *plainText, struct OH_Huks_Blob *cipherText)
{
    uint8_t handle[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handleBlob = {sizeof(uint64_t), handle};
    OH_Huks_Result ret = OH_Huks_InitSession(key, paramSet, &handleBlob, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = HksEncryptLoopUpdate(&handleBlob, paramSet, plainText, cipherText);
    return ret;
}

static OH_Huks_Result BuildWrappedKeyData(struct OH_Huks_Blob **blobArray, uint32_t size, struct OH_Huks_Blob *outData)
{
    uint32_t totalLength = size * sizeof(uint32_t);
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;

    /* counter size */
    for (uint32_t i = 0; i < size; ++i) {
        totalLength += blobArray[i]->size;
    }

    struct OH_Huks_Blob outBlob = {0, nullptr};
    outBlob.size = totalLength;
    ret = MallocAndCheckBlobData(&outBlob, outBlob.size);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    uint32_t offset = 0;

    /* copy data */
    for (uint32_t i = 0; i < size; ++i) {
        if (totalLength - offset >= sizeof(blobArray[i]->size)) {
            std::copy(reinterpret_cast<uint8_t *>(&blobArray[i]->size), reinterpret_cast<uint8_t *>(&blobArray[i]->size) + sizeof(blobArray[i]->size), outBlob.data + offset);
        } else {
            ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
            return ret;
        }
        
        offset += sizeof(blobArray[i]->size);

        if (totalLength - offset >= blobArray[i]->size) {
            std::copy(blobArray[i]->data, blobArray[i]->data + blobArray[i]->size, outBlob.data + offset);
        } else {
            ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
            return ret;
        }

        offset += blobArray[i]->size;
    }

    outData->size = outBlob.size;
    outData->data = outBlob.data;
    return ret;
}

static OH_Huks_Result CheckParamsValid(const struct HksImportWrappedKeyTestParams *params)
{
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;
    if (params == nullptr) {
        ret.errorCode = OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT;
        return ret;
    }

    if (params->wrappingKeyAlias == nullptr || params->genWrappingKeyParamSet == nullptr ||
        params->callerKeyAlias == nullptr ||
        params->genCallerKeyParamSet == nullptr || params->callerKekAlias == nullptr ||
        params->callerKek == nullptr || params->importCallerKekParamSet == nullptr ||
        params->callerAgreeKeyAlias == nullptr || params->agreeParamSet == nullptr ||
        params->importWrappedKeyParamSet == nullptr || params->importedKeyAlias == nullptr ||
        params->importedPlainKey == nullptr) {
        ret.errorCode = OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT;
        return ret;
    }
    return ret;
}

static OH_Huks_Result GenerateAndExportHuksPublicKey(const struct HksImportWrappedKeyTestParams *params,
                                           struct OH_Huks_Blob *huksPublicKey)
{
    OH_Huks_Result ret = OH_Huks_GenerateKeyItem(params->wrappingKeyAlias, params->genWrappingKeyParamSet, nullptr);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    huksPublicKey->size = params->publicKeySize;
    ret = MallocAndCheckBlobData(huksPublicKey, huksPublicKey->size);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ExportPublicKeyItem(params->wrappingKeyAlias, nullptr, huksPublicKey);
    return ret;
}

static OH_Huks_Result GenerateAndExportCallerPublicKey(const struct HksImportWrappedKeyTestParams *params,
                                             struct OH_Huks_Blob *callerSelfPublicKey)
{
    OH_Huks_Result ret = OH_Huks_GenerateKeyItem(params->callerKeyAlias, params->genCallerKeyParamSet, nullptr);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }

    callerSelfPublicKey->size = params->publicKeySize;
    ret = MallocAndCheckBlobData(callerSelfPublicKey, callerSelfPublicKey->size);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ExportPublicKeyItem(params->callerKeyAlias, params->genWrappingKeyParamSet, callerSelfPublicKey);
    return ret;
}

static OH_Huks_Result ImportKekAndAgreeSharedSecret(const struct HksImportWrappedKeyTestParams *params,
                                          const struct OH_Huks_Blob *huksPublicKey, struct OH_Huks_Blob *outSharedKey)
{
    OH_Huks_Result ret = OH_Huks_ImportKeyItem(params->callerKekAlias,
                                               params->importCallerKekParamSet, params->callerKek);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    
    ret = MallocAndCheckBlobData(outSharedKey, outSharedKey->size);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = HuksAgreeKey(params->agreeParamSet, params->callerKeyAlias, huksPublicKey, outSharedKey);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    struct OH_Huks_ParamSet *importAgreeKeyParams = nullptr;
    ret = InitParamSet(&importAgreeKeyParams, g_importAgreeKeyParams,
                       sizeof(g_importAgreeKeyParams) / sizeof(OH_Huks_Param));
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ImportKeyItem(params->callerAgreeKeyAlias, importAgreeKeyParams, outSharedKey);

    OH_Huks_FreeParamSet(&importAgreeKeyParams);
    return ret;
}

static OH_Huks_Result EncryptImportedPlainKeyAndKek(const struct HksImportWrappedKeyTestParams *params,
                                          struct OH_Huks_Blob *plainCipherText, struct OH_Huks_Blob *kekCipherText)
{
    struct OH_Huks_ParamSet *encryptParamSet = nullptr;
    OH_Huks_Result ret = InitParamSet(&encryptParamSet, g_aesKekEncryptParams,
                               sizeof(g_aesKekEncryptParams) / sizeof(OH_Huks_Param));
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = HuksEncrypt(params->callerKekAlias, encryptParamSet, params->importedPlainKey, plainCipherText);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    
    ret = HuksEncrypt(params->callerAgreeKeyAlias, encryptParamSet, params->callerKek, kekCipherText);
    OH_Huks_FreeParamSet(&encryptParamSet);
    return ret;
}

static OH_Huks_Result ImportWrappedKey(const struct HksImportWrappedKeyTestParams *params, struct OH_Huks_Blob *plainCipher,
                             struct OH_Huks_Blob *kekCipherText, struct OH_Huks_Blob *peerPublicKey, struct OH_Huks_Blob *wrappedKeyData)
{
    struct OH_Huks_Blob commonAad = {.size = AAD_SIZE,
                                     .data = reinterpret_cast<uint8_t *>(AAD)};
    struct OH_Huks_Blob commonNonce = {.size = NONCE_SIZE,
                                       .data = reinterpret_cast<uint8_t *>(NONCE)};
    struct OH_Huks_Blob keyMaterialLen = {.size = sizeof(uint32_t), .data = (uint8_t *)&params->keyMaterialLen};

    /* copy AEAD tag from cipher text and decrease its size */
    const uint32_t tagSize = AEAD_TAG_SIZE;
    uint8_t kekTagBuf[tagSize] = {0};
    struct OH_Huks_Blob kekTag = {.size = tagSize, .data = kekTagBuf};
    
    std::copy(plainCipher->data + (plainCipher->size - tagSize), plainCipher->data + (plainCipher->size - tagSize) + tagSize, kekTag.data);

    plainCipher->size -= tagSize;

    /* copy AEAD tag from kek cipher text and decrease its size */
    uint8_t agreeKeyTagBuf[tagSize] = {0};
    struct OH_Huks_Blob agreeKeyTag = {.size = tagSize, .data = agreeKeyTagBuf};
    std::copy(kekCipherText->data + (kekCipherText->size - tagSize), kekCipherText->data + (kekCipherText->size - tagSize) + tagSize, agreeKeyTagBuf);

    kekCipherText->size -= tagSize;

    struct OH_Huks_Blob *blobArray[] = {peerPublicKey, &commonAad, &commonNonce, &agreeKeyTag, kekCipherText,
                                        &commonAad, &commonNonce, &kekTag, &keyMaterialLen, plainCipher};
    OH_Huks_Result ret = BuildWrappedKeyData(blobArray, OH_HUKS_IMPORT_WRAPPED_KEY_TOTAL_BLOBS, wrappedKeyData);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    struct OH_Huks_Param *purpose = nullptr;
    ret = OH_Huks_GetParam(params->importWrappedKeyParamSet, OH_HUKS_TAG_PURPOSE, &purpose);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ImportWrappedKeyItem(params->importedKeyAlias, params->wrappingKeyAlias,
                              params->importWrappedKeyParamSet, wrappedKeyData);

    return ret;
}

OH_Huks_Result HksImportWrappedKeyTestCommonCase(const struct HksImportWrappedKeyTestParams *params)
{
    OH_Huks_Result ret = CheckParamsValid(params);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return ret;
    }

    struct OH_Huks_Blob huksPublicKey = {0, nullptr};
    struct OH_Huks_Blob callerSelfPublicKey = {0, nullptr};
    struct OH_Huks_Blob outSharedKey = {.size = OH_HUKS_KEY_BYTES(OH_HUKS_AES_KEY_SIZE_256), .data = nullptr};
    struct OH_Huks_Blob wrappedKeyData = {0, nullptr};
    uint8_t plainKeyCipherBuffer[OH_HUKS_MAX_KEY_SIZE] = {0};
    struct OH_Huks_Blob plainCipherText = {OH_HUKS_MAX_KEY_SIZE, plainKeyCipherBuffer};
    uint8_t kekCipherTextBuffer[OH_HUKS_MAX_KEY_SIZE] = {0};
    struct OH_Huks_Blob kekCipherText = {OH_HUKS_MAX_KEY_SIZE, kekCipherTextBuffer};
    do {
        /**
         * 模拟密钥安全导入场景，设备A为远端设备，设备B为本端设备
         *
         * 1. 设备A准备待导入的密钥材料，本示例使用g_importedAes256PlainKey作为模拟
         */
        
         /**
         * 2. 设备A生成一个非对称密钥对Caller_Key
         */
        ret = GenerateAndExportCallerPublicKey(params, &callerSelfPublicKey);
        if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
            break;
        }
        
         /**
          * 3. 设备B（被导入设备）生成一个非对称密钥对Wrapping_Key，其密钥用途设置为unwrap；
          */
        ret = GenerateAndExportHuksPublicKey(params, &huksPublicKey);
        if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
            break;
        }
        
         /**
         * 4. 设备A生成一个对称密钥Caller_Kek
         * 5. 设备A、B导出非对称密钥对的公钥材料。本示例将公钥作为变量存放在callerSelfPublicKey，huksPublicKey
         * 6. 设备A基于Caller_Key和设备B Wrapping_Key的公钥，协商出Agree_Key
         */
        ret = ImportKekAndAgreeSharedSecret(params, &huksPublicKey, &outSharedKey);
        if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
            break;
        }
        
        /**
         * 7. 设备A使用Caller_Kek加密To_Import_Key，生成To_Import_Key_Enc
         * 8. 设备A使用Agree_Key加密Caller_Kek，生成Caller_Kek_Enc
         */
        ret = EncryptImportedPlainKeyAndKek(params, &plainCipherText, &kekCipherText);
        if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
            break;
        }
        
        /**
         * 9. 设备A将Caller_Key的公钥、Caller_Kek_Enc、To_Import_Key_Enc发送给设备B。本示例作为变量存放在callerSelfPublicKey，plainCipherText，kekCipherText
         */
        
        /**
         * 10. 设备B封装加密导入密钥材料
         * 11. 设备B导入封装的加密密钥材料
         * 12. 设备A、B删除用于加密导入的密钥
         */
        ret = ImportWrappedKey(params, &plainCipherText, &kekCipherText, &callerSelfPublicKey, &wrappedKeyData);
    } while (0);

    HUKS_FREE_BLOB(huksPublicKey);
    HUKS_FREE_BLOB(callerSelfPublicKey);
    HUKS_FREE_BLOB(outSharedKey);
    HUKS_FREE_BLOB(wrappedKeyData);
    return ret;
}

void HksClearKeysForWrappedKeyTest(const struct HksImportWrappedKeyTestParams *params)
{
    OH_Huks_Result ret = CheckParamsValid(params);
    if (ret.errorCode != (int32_t)OH_HUKS_SUCCESS) {
        return;
    }
    (void)OH_Huks_DeleteKeyItem(params->wrappingKeyAlias, nullptr);
    (void)OH_Huks_DeleteKeyItem(params->callerKeyAlias, nullptr);
    (void)OH_Huks_DeleteKeyItem(params->callerKekAlias, nullptr);
    (void)OH_Huks_DeleteKeyItem(params->callerAgreeKeyAlias, nullptr);
    (void)OH_Huks_DeleteKeyItem(params->importedKeyAlias, nullptr);
}

static OH_Huks_Result InitCommonTestParamsAndDoImport(
    struct HksImportWrappedKeyTestParams *importWrappedKeyTestParams,
    const struct OH_Huks_Param *importedKeyParamSetArray,
    uint32_t arraySize)
{
    struct OH_Huks_ParamSet *genX25519KeyParamSet = nullptr;
    struct OH_Huks_ParamSet *genCallerKeyParamSet = nullptr;
    struct OH_Huks_ParamSet *callerImportParamsKek = nullptr;
    struct OH_Huks_ParamSet *agreeParamSet = nullptr;
    struct OH_Huks_ParamSet *importPlainKeyParams = nullptr;
    
    OH_Huks_Result ret;
    do {
        ret = InitParamSet(&genX25519KeyParamSet, g_genWrappingKeyParams,
                               sizeof(g_genWrappingKeyParams) / sizeof(OH_Huks_Param));
        if (ret.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        importWrappedKeyTestParams->genWrappingKeyParamSet = genX25519KeyParamSet;
        importWrappedKeyTestParams->publicKeySize = g_x25519PubKeySize;
    
        ret = InitParamSet(&genCallerKeyParamSet, g_genCallerX25519Params,
                           sizeof(g_genCallerX25519Params) / sizeof(OH_Huks_Param));
        if (ret.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        importWrappedKeyTestParams->genCallerKeyParamSet = genCallerKeyParamSet;
    
        ret = InitParamSet(&callerImportParamsKek, g_importParamsCallerKek,
                           sizeof(g_importParamsCallerKek) / sizeof(OH_Huks_Param));
        if (ret.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        importWrappedKeyTestParams->importCallerKekParamSet = callerImportParamsKek;
    
        ret = InitParamSet(&agreeParamSet, g_callerAgreeParams,
                           sizeof(g_callerAgreeParams) / sizeof(OH_Huks_Param));
        if (ret.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        importWrappedKeyTestParams->agreeParamSet = agreeParamSet;
    
        ret = InitParamSet(&importPlainKeyParams, importedKeyParamSetArray, arraySize);
        if (ret.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        importWrappedKeyTestParams->importWrappedKeyParamSet = importPlainKeyParams;
    
        ret = HksImportWrappedKeyTestCommonCase(importWrappedKeyTestParams);
    } while (0);
    
    OH_Huks_FreeParamSet(&genX25519KeyParamSet);
    OH_Huks_FreeParamSet(&genCallerKeyParamSet);
    OH_Huks_FreeParamSet(&callerImportParamsKek);
    OH_Huks_FreeParamSet(&agreeParamSet);
    OH_Huks_FreeParamSet(&importPlainKeyParams);
    return ret;
}

static napi_value ImportWrappedKey(napi_env env, napi_callback_info info) 
{
    struct HksImportWrappedKeyTestParams importWrappedKeyTestParams001 = {0};
       
    importWrappedKeyTestParams001.wrappingKeyAlias = &g_wrappingKeyAliasAes256;
    importWrappedKeyTestParams001.keyMaterialLen = g_importedAes256PlainKey.size;
    importWrappedKeyTestParams001.callerKeyAlias = &g_callerKeyAliasAes256;
    importWrappedKeyTestParams001.callerKekAlias = &g_callerKekAliasAes256;
    importWrappedKeyTestParams001.callerKek = &g_callerAes256Kek;
    importWrappedKeyTestParams001.callerAgreeKeyAlias = &g_callerAgreeKeyAliasAes256;
    importWrappedKeyTestParams001.importedKeyAlias = &g_importedKeyAliasAes256;
    importWrappedKeyTestParams001.importedPlainKey = &g_importedAes256PlainKey;
    OH_Huks_Result ohResult = InitCommonTestParamsAndDoImport(&importWrappedKeyTestParams001, g_importWrappedAes256Params,
                                   sizeof(g_importWrappedAes256Params) / sizeof(struct OH_Huks_Param));
    HksClearKeysForWrappedKeyTest(&importWrappedKeyTestParams001);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```

### 常见密钥操作

**场景概述**

为了实现对数据机密性、完整性等保护，在生成/导入密钥后，需要对数据进行密钥操作，比如加密解密、签名验签、密钥协商、密钥派生等，本章节提供了常用的密钥操作的示例。

**通用开发流程**

HUKS基于密钥会话来操作数据，使用密钥时基于以下流程：

1. **初始化密钥会话[OH_Huks_InitSession](../reference/native-apis/_huks_key_api.md#oh_huks_initsession)：** 传入密钥别名和密钥操作参数，初始化一个密钥会话并获取会话句柄。其中密钥操作参数中必须包含对应密码算法所必须的参数，包括密码算法、密钥长度、密钥目的、工作模式、填充模式、散列模式、IV、Nonce、AAD等。
2. **分段操作数据[OH_Huks_UpdateSession](../reference/native-apis/_huks_key_api.md#oh_huks_updatesession)：** 协商、派生、验签中，必须通过该接口执行算法操作，详见**开发步骤**。其他情况下，如数据过大（超过100K）或密码算法的要求需要对数据进行分段操作，可通过该接口分段传入数据。
3. **结束密钥会话[OH_Huks_FinishSession](../reference/native-apis/_huks_key_api.md#oh_huks_finishsession)：** 操作最后一段数据并结束密钥会话，如过程中发生错误或不需要此次密钥操作数据，必须取消会话[OH_Huks_AbortSession](../reference/native-apis/_huks_key_api.md#oh_huks_abortsession)。此步骤必选！

#### 加密解密

**C++代码示例：**
```C++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
OH_Huks_Result InitParamSet(
    struct OH_Huks_ParamSet **paramSet,
    const struct OH_Huks_Param *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_AddParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    ret = OH_Huks_BuildParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    return ret;
}

static const uint32_t IV_SIZE = 16;
static uint8_t IV[IV_SIZE] = { 0 }; // this is a test value, for real use the iv should be different every time

static struct OH_Huks_Param g_genEncDecParams[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT | OH_HUKS_KEY_PURPOSE_DECRYPT
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }
};

static struct OH_Huks_Param g_encryptParams[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_ENCRYPT
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }, {
        .tag = OH_HUKS_TAG_IV,
        .blob = {
            .size = IV_SIZE,
            .data = (uint8_t *)IV // this is a test value, for real use the iv should be different every time 
        }
    }
};

static struct OH_Huks_Param g_decryptParams[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_DECRYPT
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }, {
        .tag = OH_HUKS_TAG_IV,
        .blob = {
            .size = IV_SIZE,
            .data = (uint8_t *)IV // this is a test value, for real use the iv should be different every time 
        }
    }
};

static const uint32_t AES_COMMON_SIZE = 1024;

OH_Huks_Result HksAesCipherTestEncrypt(
        const struct OH_Huks_Blob *keyAlias,
        const struct OH_Huks_ParamSet *encryptParamSet, const struct OH_Huks_Blob *inData, struct OH_Huks_Blob *cipherText)
{
    uint8_t handleE[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handleEncrypt = {sizeof(uint64_t), handleE};
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, encryptParamSet, &handleEncrypt, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_FinishSession(&handleEncrypt, encryptParamSet, inData, cipherText);

    return ret;
}

OH_Huks_Result HksAesCipherTestDecrypt(
    const struct OH_Huks_Blob *keyAlias,
    const struct OH_Huks_ParamSet *decryptParamSet, const struct OH_Huks_Blob *cipherText, struct OH_Huks_Blob *plainText,
    const struct OH_Huks_Blob *inData)
{
    uint8_t handleD[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handleDecrypt = {sizeof(uint64_t), handleD};
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, decryptParamSet, &handleDecrypt, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_FinishSession(&handleDecrypt, decryptParamSet, cipherText, plainText);

    return ret;
}

static napi_value EncDecKey(napi_env env, napi_callback_info info)
{
    char tmpKeyAlias[] = "test_enc_dec";
    struct OH_Huks_Blob keyAlias = { (uint32_t)strlen(tmpKeyAlias), (uint8_t *)tmpKeyAlias };
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *encryptParamSet = nullptr;
    struct OH_Huks_ParamSet *decryptParamSet = nullptr;
    OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&genParamSet, g_genEncDecParams, sizeof(g_genEncDecParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&encryptParamSet, g_encryptParams, sizeof(g_encryptParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&decryptParamSet, g_decryptParams, sizeof(g_decryptParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        char tmpInData[] = "AES_ECB_INDATA_1";
        struct OH_Huks_Blob inData = { (uint32_t)strlen(tmpInData), (uint8_t *)tmpInData };
        /* 1. Generate Key */
        ohResult = OH_Huks_GenerateKeyItem(&keyAlias, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Encrypt */
        uint8_t cipher[AES_COMMON_SIZE] = {0};
        struct OH_Huks_Blob cipherText = {AES_COMMON_SIZE, cipher};
        ohResult = HksAesCipherTestEncrypt(&keyAlias, encryptParamSet, &inData, &cipherText);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }

        /* 3. Decrypt */
        uint8_t plain[AES_COMMON_SIZE] = {0};
        struct OH_Huks_Blob plainText = {AES_COMMON_SIZE, plain};
        ohResult = HksAesCipherTestDecrypt(&keyAlias, decryptParamSet, &cipherText, &plainText, &inData);
    } while (0);
    /* 4. Delete Key */
    (void)OH_Huks_DeleteKeyItem(&keyAlias, genParamSet);
        
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&encryptParamSet);
    OH_Huks_FreeParamSet(&decryptParamSet);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```

#### 签名验签

**C++代码示例：**
```C++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
OH_Huks_Result InitParamSet(
    struct OH_Huks_ParamSet **paramSet,
    const struct OH_Huks_Param *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_AddParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    ret = OH_Huks_BuildParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    return ret;
}

static struct OH_Huks_Param g_genSignVerifyParamsTest[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_RSA
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_SIGN | OH_HUKS_KEY_PURPOSE_VERIFY
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_RSA_KEY_SIZE_2048
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_PSS
    }, {
        .tag = OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_SHA384
    },
};

static struct OH_Huks_Param g_signParamsTest[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_RSA
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_SIGN
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_RSA_KEY_SIZE_2048
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_PSS
    }, {
        .tag = OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_SHA384
    }
};

static struct OH_Huks_Param g_verifyParamsTest[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_RSA
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_VERIFY
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_RSA_KEY_SIZE_2048
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_PSS
    }, {
        .tag = OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_SHA384
    }
};

static const uint32_t RSA_COMMON_SIZE = 1024;
static const char *g_dataToSign = "Hks_RSA_Sign_Verify_Test_0000000000000000000000000000000000000000000000000000000"
                                    "00000000000000000000000000000000000000000000000000000000000000000000000000000000"
                                    "0000000000000000000000000000000000000000000000000000000000000000000000000_string";

static napi_value SignVerifyKey(napi_env env, napi_callback_info info) 
{
    struct OH_Huks_Blob g_keyAlias = {
        (uint32_t)strlen("test_signVerify"),
        (uint8_t *)"test_signVerify"
    };
    struct OH_Huks_Blob inData = {
        (uint32_t)strlen(g_dataToSign),
        (uint8_t *)g_dataToSign
    };
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *signParamSet = nullptr;
    struct OH_Huks_ParamSet *verifyParamSet = nullptr;
    OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&genParamSet, g_genSignVerifyParamsTest, sizeof(g_genSignVerifyParamsTest) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&signParamSet, g_signParamsTest, sizeof(g_signParamsTest) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&verifyParamSet, g_verifyParamsTest, sizeof(g_verifyParamsTest) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 1. Generate Key */
        ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Sign */
        // Init
        uint8_t handleS[sizeof(uint64_t)] = {0};
        struct OH_Huks_Blob handleSign = { (uint32_t)sizeof(uint64_t), handleS };
        ohResult = OH_Huks_InitSession(&g_keyAlias, signParamSet, &handleSign, nullptr);

        // Update
        uint8_t outDataS[RSA_COMMON_SIZE] = {0};
        struct OH_Huks_Blob outDataSign = { RSA_COMMON_SIZE, outDataS };

        ohResult = OH_Huks_UpdateSession(&handleSign, signParamSet,  &inData, &outDataSign);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }

        // Finish
        struct OH_Huks_Blob finishInData = { 0, NULL };
        ohResult = OH_Huks_FinishSession(&handleSign, signParamSet, &finishInData, &outDataSign);
        
        /* 3. Verify */
        // Init
        uint8_t handleV[sizeof(uint64_t)] = {0};
        struct OH_Huks_Blob handleVerify = { (uint32_t)sizeof(uint64_t), handleV };
        ohResult = OH_Huks_InitSession(&g_keyAlias, verifyParamSet, &handleVerify, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        // Update loop
        uint8_t temp[] = "out";
        struct OH_Huks_Blob verifyOut = { (uint32_t)sizeof(temp), temp };
        ohResult = OH_Huks_UpdateSession(&handleVerify, verifyParamSet, &inData, &verifyOut);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        // Finish
        ohResult = OH_Huks_FinishSession(&handleVerify, verifyParamSet, &outDataSign, &verifyOut);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
    } while (0);
    (void)OH_Huks_DeleteKeyItem(&g_keyAlias, genParamSet);
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&signParamSet);
    OH_Huks_FreeParamSet(&verifyParamSet);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```

#### 密钥协商

应用在协商密钥时建议传入[HuksKeyStorageType](../reference/apis/js-apis-huks.md#hukskeystoragetype)中定义的类型；从API10开始应用只能选择存储(HUKS_STORAGE_ONLY_USED_IN_HUKS)，或者选择导出(HUKS_STORAGE_KEY_EXPORT_ALLOWED)，若不传入，则默认同时支持存储和导出，存在安全风险，不推荐业务使用。

**C++代码示例：**

```C++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
OH_Huks_Result InitParamSet(
    struct OH_Huks_ParamSet **paramSet,
    const struct OH_Huks_Param *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_AddParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    ret = OH_Huks_BuildParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    return ret;
}

static const uint32_t IV_SIZE = 16;
static uint8_t IV[IV_SIZE] = { 0 }; // this is a test value, for real use the iv should be different every time

static struct OH_Huks_Blob g_keyAliasFinal1001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_1_final"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_1_final"
};

static struct OH_Huks_Param g_genAgreeParams[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_ECC
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_ECC_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_NONE
    }
};

static struct OH_Huks_Param g_agreeParamsInit01[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_ECDH
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_ECC_KEY_SIZE_256
    }
};

static struct OH_Huks_Param g_agreeParamsFinish01[] = {
    {
        .tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
        .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS
    }, {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_ALIAS,
        .blob = g_keyAliasFinal1001
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }
};

static struct OH_Huks_Blob g_keyAliasFinal2001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_2_final"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_2_final"
};

static struct OH_Huks_Param g_agreeParamsInit02[] = {
    {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_ECDH
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_AGREE
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_ECC_KEY_SIZE_256
    }
};

static struct OH_Huks_Param g_agreeParamsFinish02[] = {
    {
        .tag = OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
        .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS
    }, {
        .tag = OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag = OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }, {
        .tag = OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_DERIVE
    }, {
        .tag = OH_HUKS_TAG_KEY_ALIAS,
        .blob = g_keyAliasFinal2001
    }, {
        .tag = OH_HUKS_TAG_PADDING,
        .uint32Param = OH_HUKS_PADDING_NONE
    }, {
        .tag = OH_HUKS_TAG_BLOCK_MODE,
        .uint32Param = OH_HUKS_MODE_CBC
    }
};

static const uint32_t ECDH_COMMON_SIZE = 1024;

static struct OH_Huks_Blob g_keyAlias01001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_1"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_1"
};

static struct OH_Huks_Blob g_keyAlias02001 = {
    (uint32_t)strlen("HksECDHAgreeKeyAliasTest001_2"),
    (uint8_t *)"HksECDHAgreeKeyAliasTest001_2"
};

OH_Huks_Result MallocAndCheckBlobData(
    struct OH_Huks_Blob *blob,
    const uint32_t blobSize)
{
    struct OH_Huks_Result ret;
    ret.errorCode = OH_HUKS_SUCCESS;

    blob->data = (uint8_t *)malloc(blobSize);
    if (blob->data == NULL) {
        ret.errorCode = OH_HUKS_ERR_CODE_INTERNAL_ERROR;
    }

    return ret;
}

OH_Huks_Result HksEcdhAgreeExport(const struct OH_Huks_Blob *keyAlias1, const struct OH_Huks_Blob *keyAlias2,
    struct OH_Huks_Blob *publicKey1, struct OH_Huks_Blob *publicKey2, const struct OH_Huks_ParamSet *genParamSet)
{
    OH_Huks_Result ret = OH_Huks_ExportPublicKeyItem(keyAlias1, genParamSet, publicKey1);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_ExportPublicKeyItem(keyAlias2, genParamSet, publicKey2);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}

static const char *g_inData = "Hks_ECDH_Agree_Test_000000000000000000000000000000000000000000000000000000000000"
                                    "00000000000000000000000000000000000000000000000000000000000000000000000000000000"
                                    "0000000000000000000000000000000000000000000000000000000000000000000000000_string";

OH_Huks_Result HksEcdhAgreeFinish(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_Blob *publicKey,
    const struct OH_Huks_ParamSet *initParamSet, const struct OH_Huks_ParamSet *finishParamSet, struct OH_Huks_Blob *outData)
{
    struct OH_Huks_Blob inData = {
        (uint32_t)strlen(g_inData),
        (uint8_t *)g_inData
    };

    uint8_t handleU[sizeof(uint64_t)] = {0};
    struct OH_Huks_Blob handle = { sizeof(uint64_t), handleU };
    OH_Huks_Result ret = OH_Huks_InitSession(keyAlias, initParamSet, &handle, nullptr);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    uint8_t outDataU[ECDH_COMMON_SIZE] = {0};
    struct OH_Huks_Blob outDataUpdate = { ECDH_COMMON_SIZE, outDataU };
    ret = OH_Huks_UpdateSession(&handle, initParamSet, publicKey, &outDataUpdate);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_FinishSession(&handle, finishParamSet, &inData, outData);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    return ret;
}

static napi_value AgreeKey(napi_env env, napi_callback_info info)
{
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *initParamSet01 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet01 = nullptr;
    struct OH_Huks_ParamSet *initParamSet02 = nullptr;
    struct OH_Huks_ParamSet *finishParamSet02 = nullptr;
    struct OH_Huks_Blob publicKey01 = { .size = OH_HUKS_ECC_KEY_SIZE_256, .data = nullptr };
    struct OH_Huks_Blob publicKey02 = { .size = OH_HUKS_ECC_KEY_SIZE_256, .data = nullptr };
    struct OH_Huks_Blob outData01 = { .size = ECDH_COMMON_SIZE, .data = nullptr };
    struct OH_Huks_Blob outData02 = { .size = ECDH_COMMON_SIZE, .data = nullptr };
    OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&genParamSet, g_genAgreeParams, sizeof(g_genAgreeParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&initParamSet01, g_agreeParamsInit01, sizeof(g_agreeParamsInit01) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&finishParamSet01, g_agreeParamsFinish01,
            sizeof(g_agreeParamsFinish01) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&initParamSet02, g_agreeParamsInit02, sizeof(g_agreeParamsInit02) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&finishParamSet02, g_agreeParamsFinish02,
            sizeof(g_agreeParamsFinish02) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 1. Get Key One */
        ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias01001, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Get Key Two */
        ohResult = OH_Huks_GenerateKeyItem(&g_keyAlias02001, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&publicKey01, publicKey01.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&publicKey02, publicKey02.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3. Get public keys of key one and key two */
        ohResult = HksEcdhAgreeExport(&g_keyAlias01001, &g_keyAlias02001, &publicKey01, &publicKey02, genParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&outData01, outData01.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = MallocAndCheckBlobData(&outData02, outData02.size);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 4. Agree with key one and public key of key two */
        ohResult = HksEcdhAgreeFinish(&g_keyAlias01001, &publicKey02, initParamSet01, finishParamSet01, &outData01);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 5. Agree with key two and public key of key one */
        ohResult = HksEcdhAgreeFinish(&g_keyAlias02001, &publicKey01, initParamSet02, finishParamSet02, &outData02);
    } while (0);
    free(publicKey01.data);
    free(publicKey02.data);
    free(outData01.data);
    free(outData02.data);
    OH_Huks_DeleteKeyItem(&g_keyAlias01001, genParamSet);
    OH_Huks_DeleteKeyItem(&g_keyAlias02001, genParamSet);
    OH_Huks_DeleteKeyItem(&g_keyAliasFinal1001, NULL);
    OH_Huks_DeleteKeyItem(&g_keyAliasFinal2001, NULL);
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&initParamSet01);
    OH_Huks_FreeParamSet(&finishParamSet01);
    OH_Huks_FreeParamSet(&initParamSet02);
    OH_Huks_FreeParamSet(&finishParamSet02);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```


### 密钥派生

应用在派生密钥时建议传入[OH_Huks_KeyStorageType](../reference/native-apis/_huks_type_api.md#oh_huks_keystoragetype)中定义的类型；从API10开始应用只能选择存储(OH_HUKS_STORAGE_ONLY_USED_IN_HUKS)，或者选择导出(OH_HUKS_STORAGE_KEY_EXPORT_ALLOWED)，若不传入，则默认同时支持存储和导出，存在安全问题，不推荐业务使用。

**C++代码示例：**

```C++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
OH_Huks_Result InitParamSet(
    struct OH_Huks_ParamSet **paramSet,
    const struct OH_Huks_Param *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_AddParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    ret = OH_Huks_BuildParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    return ret;
}

static const uint32_t DERIVE_KEY_SIZE_32 = 32;
static struct OH_Huks_Blob g_deriveKeyAlias = {
    (uint32_t)strlen("test_derive"),
    (uint8_t *)"test_derive"
};

static struct OH_Huks_Param g_genDeriveParams[] = {
    {
        .tag =  OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_AES
    }, {
        .tag =  OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_DERIVE
    }, {
        .tag =  OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_SHA256
    }, {
        .tag =  OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = OH_HUKS_AES_KEY_SIZE_256
    }
};

static struct OH_Huks_Param g_hkdfParams[] = {
    {
        .tag =  OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_HKDF
    }, {
        .tag =  OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_DERIVE
    }, {
        .tag =  OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_SHA256
    }, {
        .tag =  OH_HUKS_TAG_DERIVE_KEY_SIZE,
        .uint32Param = DERIVE_KEY_SIZE_32
    }
};

static struct OH_Huks_Param g_hkdfFinishParams[] = {
    {
        .tag =  OH_HUKS_TAG_DERIVED_AGREED_KEY_STORAGE_FLAG,
        .uint32Param = OH_HUKS_STORAGE_ONLY_USED_IN_HUKS
    }, {
        .tag =  OH_HUKS_TAG_KEY_ALIAS,
        .blob = g_deriveKeyAlias
    }, {
        .tag =  OH_HUKS_TAG_ALGORITHM,
        .uint32Param = OH_HUKS_ALG_HKDF
    }, {
        .tag =  OH_HUKS_TAG_KEY_SIZE,
        .uint32Param = DERIVE_KEY_SIZE_32
    }, {
        .tag =  OH_HUKS_TAG_PURPOSE,
        .uint32Param = OH_HUKS_KEY_PURPOSE_DERIVE
    }, {
        .tag =  OH_HUKS_TAG_DIGEST,
        .uint32Param = OH_HUKS_DIGEST_SHA256
    }
};

static const uint32_t COMMON_SIZE = 2048;
static const char *g_deriveInData = "Hks_HKDF_Derive_Test_00000000000000000000000000000000000000000000000000000000000"
                                    "00000000000000000000000000000000000000000000000000000000000000000000000000000000"
                                    "0000000000000000000000000000000000000000000000000000000000000000000000000_string";

static napi_value DeriveKey(napi_env env, napi_callback_info info) 
{
    struct OH_Huks_Blob genAlias = {
        (uint32_t)strlen("test_signVerify"),
        (uint8_t *)"test_signVerify"
    };
    struct OH_Huks_Blob inData = {
        (uint32_t)strlen(g_deriveInData),
        (uint8_t *)g_deriveInData
    };
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *hkdfParamSet = nullptr;
    struct OH_Huks_ParamSet *hkdfFinishParamSet = nullptr;
    OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&genParamSet, g_genDeriveParams, sizeof(g_genDeriveParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        
        ohResult = InitParamSet(&hkdfParamSet, g_hkdfParams, sizeof(g_hkdfParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
           break;
        } 
        
        // finish paramset
        ohResult = InitParamSet(&hkdfFinishParamSet, g_hkdfFinishParams, sizeof(g_hkdfFinishParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        
        /* 1. Generate Key */
        ohResult = OH_Huks_GenerateKeyItem(&genAlias, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 2. Derive */
        // Init
        uint8_t handleD[sizeof(uint64_t)] = {0};
        struct OH_Huks_Blob handleDerive = { sizeof(uint64_t), handleD };
        ohResult = OH_Huks_InitSession(&genAlias, hkdfParamSet, &handleDerive, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        // Update
        uint8_t tmpOut[COMMON_SIZE] = {0};
        struct OH_Huks_Blob outData = { COMMON_SIZE, tmpOut };
        ohResult = OH_Huks_UpdateSession(&handleDerive, hkdfParamSet, &inData, &outData);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        // Finish
        uint8_t outDataD[COMMON_SIZE] = {0};
        struct OH_Huks_Blob outDataDerive = { COMMON_SIZE, outDataD };
        ohResult = OH_Huks_FinishSession(&handleDerive, hkdfFinishParamSet, &inData, &outDataDerive);
    } while (0);
    (void)OH_Huks_DeleteKeyItem(&genAlias, nullptr);
    (void)OH_Huks_DeleteKeyItem(&g_deriveKeyAlias, nullptr);
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&hkdfParamSet);
    OH_Huks_FreeParamSet(&hkdfFinishParamSet);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```

### 密钥证明

HUKS为密钥提供合法性证明能力，主要应用于非对称密钥的公钥的证明。基于PKI证书链技术，HUKS可以为存储在HUKS中的非对称密钥对的公钥签发证书，证明其公钥的合法性。业务可以通过OpenHarmony提供的根CA证书，逐级验证HUKS签发的密钥证明证书，来确保证书中的公钥以及对应的私钥，确实来自合法的硬件设备，且存储管理在HUKS中。

**开发流程**

1. 指定密钥别名和需要证明的密钥属性的标签传入HUKS；
2. 调用HUKS为应用生成一个依次由根CA证书、设备CA证书、设备证书、密钥证书组成的X.509证书链；
3. 将证书链传输至受信任的服务器，并在服务器上解析和验证证书链的有效性和单个证书是否吊销。

**C++代码示例：**

```C++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>

OH_Huks_Result InitParamSet(
    struct OH_Huks_ParamSet **paramSet,
    const struct OH_Huks_Param *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }

    ret = OH_Huks_AddParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    ret = OH_Huks_BuildParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeParamSet(paramSet);
        return ret;
    }

    return ret;
}

static uint32_t g_size = 4096;
static uint32_t CERT_COUNT = 4;

void FreeCertChain(struct OH_Huks_CertChain **certChain, const uint32_t pos)
{
    if (certChain == nullptr || *certChain == nullptr) {
        return;
    }

    if ((*certChain)->certs == nullptr) {
        free(*certChain);
        *certChain = nullptr;
        return;
    }
    for (uint32_t j = 0; j < pos; j++) {
        if ((*certChain)->certs[j].data != nullptr) {
            free((*certChain)->certs[j].data);
            (*certChain)->certs[j].data = nullptr;
        }
    }

    if ((*certChain)->certs != nullptr) {
        free((*certChain)->certs);
        (*certChain)->certs = nullptr;
    }

    if (*certChain != nullptr) {
        free(*certChain);
        *certChain = nullptr;
    }
}

int32_t ConstructDataToCertChain(struct OH_Huks_CertChain **certChain)
{
    *certChain = (struct OH_Huks_CertChain *)malloc(sizeof(struct OH_Huks_CertChain));
    if (*certChain == nullptr) {
        return OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT;
    }
    (*certChain)->certsCount = CERT_COUNT;
  
    (*certChain)->certs = (struct OH_Huks_Blob *)malloc(sizeof(struct OH_Huks_Blob) * ((*certChain)->certsCount));
    if ((*certChain)->certs == nullptr) {
        free(*certChain);
        *certChain = nullptr;
    }
    for (uint32_t i = 0; i < (*certChain)->certsCount; i++) {
        (*certChain)->certs[i].size = g_size;
        (*certChain)->certs[i].data = (uint8_t *)malloc((*certChain)->certs[i].size);
        if ((*certChain)->certs[i].data == nullptr) {
            FreeCertChain(certChain, i);
            return OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT;
        }
    }
    return 0;
}

static struct OH_Huks_Param g_genAttestParams[] = {
    { .tag = OH_HUKS_TAG_ALGORITHM, .uint32Param = OH_HUKS_ALG_RSA },
    { .tag = OH_HUKS_TAG_KEY_SIZE, .uint32Param = OH_HUKS_RSA_KEY_SIZE_2048 },
    { .tag = OH_HUKS_TAG_PURPOSE, .uint32Param = OH_HUKS_KEY_PURPOSE_VERIFY },
    { .tag = OH_HUKS_TAG_DIGEST, .uint32Param = OH_HUKS_DIGEST_SHA256 },
    { .tag = OH_HUKS_TAG_PADDING, .uint32Param = OH_HUKS_PADDING_PSS },
    { .tag = OH_HUKS_TAG_BLOCK_MODE, .uint32Param = OH_HUKS_MODE_ECB },
};

#define CHALLENGE_DATA "hi_challenge_data"
static struct OH_Huks_Blob g_challenge = { sizeof(CHALLENGE_DATA), (uint8_t *)CHALLENGE_DATA };

static napi_value AttestKey(napi_env env, napi_callback_info info) 
{
    struct OH_Huks_Blob genAlias = {
        (uint32_t)strlen("test_attest"),
        (uint8_t *)"test_attest"
    };
    static struct OH_Huks_Param g_attestParams[] = {
        { .tag = OH_HUKS_TAG_ATTESTATION_CHALLENGE, .blob = g_challenge },
        { .tag = OH_HUKS_TAG_ATTESTATION_ID_ALIAS, .blob = genAlias },
    };
    struct OH_Huks_ParamSet *genParamSet = nullptr;
    struct OH_Huks_ParamSet *attestParamSet = nullptr;
    OH_Huks_Result ohResult;
    OH_Huks_CertChain *certChain = NULL;
    do {
        ohResult = InitParamSet(&genParamSet, g_genAttestParams, sizeof(g_genAttestParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = InitParamSet(&attestParamSet, g_attestParams, sizeof(g_attestParams) / sizeof(OH_Huks_Param));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = OH_Huks_GenerateKeyItem(&genAlias, genParamSet, nullptr);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        
        (void)ConstructDataToCertChain(&certChain);
        ohResult = OH_Huks_AttestKeyItem(&genAlias, attestParamSet, certChain);
    } while (0);
    if (certChain != nullptr) {
        FreeCertChain(&certChain, certChain->certsCount);
    }
    OH_Huks_FreeParamSet(&genParamSet);
    OH_Huks_FreeParamSet(&attestParamSet);
    (void)OH_Huks_DeleteKeyItem(&genAlias, NULL);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```