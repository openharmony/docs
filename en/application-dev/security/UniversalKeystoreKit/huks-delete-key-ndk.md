# Deleting a Key (C/C++)


To ensure data security, delete the key that is no longer required.

## Add the dynamic library in the CMake script.
```txt
   target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

For example, delete a 256-bit HKDF key.

1. Set the key alias (**keyAlias**), which cannot exceed 128 bytes. **paramSet** is a reserved parameter. Leave it empty.

2. Use [OH_Huks_DeleteKeyItem](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_deletekeyitem) to delete the key.

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
static napi_value DeleteKey(napi_env env, napi_callback_info info)
{
    /* 1. Obtain the key alias. */
    struct OH_Huks_Blob keyAlias = {
        (uint32_t)strlen("test_key"),
        (uint8_t *)"test_key"
    };
    
    /* 2. Call OH_Huks_DeleteKeyItem to delete the key. */
    struct OH_Huks_Result ohResult = OH_Huks_DeleteKeyItem(&keyAlias, nullptr);

    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
