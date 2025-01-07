# 查询密钥是否存在(C/C++)


HUKS提供了接口供应用查询指定密钥是否存在。

## 在CMake脚本中链接相关动态库
```txt
   target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## 开发步骤

1. 构造对应参数。
   - 指定密钥别名keyAlias，密钥别名最大长度为128字节。
   - 查询密钥需要的[属性TAG](../../reference/apis-universal-keystore-kit/_huks_type_api.md#oh_huks_tag)（默认传空）。

2. 调用接口[OH_Huks_IsKeyItemExist](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_iskeyitemexist)，查询密钥是否存在。

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
static napi_value IsKeyExist(napi_env env, napi_callback_info info)
{
    /* 1.获取密钥别名 */
    struct OH_Huks_Blob keyAlias = {
        (uint32_t)strlen("test_key"),
        (uint8_t *)"test_key"
    };
    
    /* 2.调用OH_Huks_IsKeyItemExist判断密钥是否存在  */
    struct OH_Huks_Result ohResult = OH_Huks_IsKeyItemExist(&keyAlias, nullptr);
    // OH_HUKS_SUCCESS表示存在, OH_HUKS_ERR_CODE_ITEM_NOT_EXIST表示不存在

    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
