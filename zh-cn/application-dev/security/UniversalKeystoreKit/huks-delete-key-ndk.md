# 密钥删除(C/C++)

为保证数据安全性，当不需要使用该密钥时，应该删除密钥。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## 开发步骤

以删除HKDF256密钥为例。

1. 确定密钥别名keyAlias，密钥别名最大长度为128字节。paramSet为预留参数传空即可。

2. 调用接口[OH_Huks_DeleteKeyItem](../../reference/apis-universal-keystore-kit/capi-native-huks-api-h.md#oh_huks_deletekeyitem)，删除密钥。

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <string.h>
static napi_value DeleteKey(napi_env env, napi_callback_info info)
{
    /* 1.获取密钥别名 */
    struct OH_Huks_Blob keyAlias = {
        (uint32_t)strlen("test_key"),
        (uint8_t *)"test_key"
    };
    
    /* 2.调用OH_Huks_DeleteKeyItem删除密钥  */
    struct OH_Huks_Result ohResult = OH_Huks_DeleteKeyItem(&keyAlias, nullptr);

    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
