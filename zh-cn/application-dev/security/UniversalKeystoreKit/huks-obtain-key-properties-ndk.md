# 获取密钥属性(C/C++)


HUKS提供了接口供业务获取指定密钥的相关属性。在获取指定密钥属性前，需要确保已在HUKS中生成或导入持久化存储的密钥。
>**说明：**
> 轻量级设备不支持获取密钥属性功能。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## 开发步骤

1. 构造对应参数。
   - keyAlias：密钥别名，封装成[OH_Huks_Blob](../../reference/apis-universal-keystore-kit/_o_h___huks___blob.md)结构，密钥别名最大长度为128字节。
   - paramSetIn：预留参数，暂不需要处理，传空即可。
   - paramSetOut：用于放置获取到的参数集结果，为[OH_Huks_ParamSet](../../reference/apis-universal-keystore-kit/_o_h___huks___param_set.md)类型对象，需要业务提前申请好内存，需申请足够容纳获取到的密钥属性集的内存大小。

2. 调用接口[OH_Huks_GetKeyItemParamSet](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_getkeyitemparamset)，传入上述参数。

3. 返回值为成功码/错误码，获取成功后，从参数集中读取需要的参数。

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <string.h>
static napi_value GetKeyParamSet(napi_env env, napi_callback_info info)
{
    /* 1. 参数构造：确定密钥别名 */
    const char *alias = "test_key";
    struct OH_Huks_Blob aliasBlob = { .size = (uint32_t)strlen(alias), .data = (uint8_t *)alias };
    /* 构造参数：为参数集申请内存 */
    struct OH_Huks_ParamSet *outParamSet = (struct OH_Huks_ParamSet *)malloc(512); // 请业务按实际情况评估大小进行申请
    if (outParamSet == nullptr) {
        return nullptr;
    }
    outParamSet->paramSetSize = 512;
    struct OH_Huks_Result ohResult;
    do {
        /* 2. 获取密钥属性集 */
        ohResult = OH_Huks_GetKeyItemParamSet(&aliasBlob, nullptr, outParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        /* 3. 从参数集中读取参数，以OH_HUKS_TAG_PURPOSE为例 */
        OH_Huks_Param *purposeParam = nullptr; // 无需申请内存，获取后指针指向该参数在参数集中所处内存地址
        ohResult = OH_Huks_GetParam(outParamSet, OH_HUKS_TAG_PURPOSE, &purposeParam);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
    } while (0);
    OH_Huks_FreeParamSet(&outParamSet);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
