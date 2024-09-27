# Exporting a Key (C/C++)


This topic walks you through on how to export the public key of a persistently stored asymmetric key. Currently, HUKS supports export of the ECC, RSA, Ed25519, X25519, and SM2 public keys.

## Add the dynamic library in the CMake script.
```txt
   target_link_libraries(entry PUBLIC libhuks_ndk.z.so)
```

## How to Develop

1. Set parameters.
   - **keyAlias**: key alias encapsulated in an [OH_Huks_Blob](../../reference/apis-universal-keystore-kit/_o_h___huks___blob.md) struct. The maximum length of the key alias is 64 bytes.
   - **paramSetIn**: This parameter is reserved. Leave it empty.
   - **key**: [OH_Huks_Blob](../../reference/apis-universal-keystore-kit/_o_h___huks___blob.md) object used to hold the key exported. Ensure that there is enough memory for storing the key exported.

2. Use [OH_Huks_GetKeyItemParamSet](../../reference/apis-universal-keystore-kit/_huks_key_api.md#oh_huks_getkeyitemparamset) to obtain key properties.

3. Check the return value. If the operation is successful, the exported key is in the **key** field in the DER format defined in X.509. For details about the format, see [Public Key Material Format](huks-concepts.md#public-key-material-format). If the operation fails, an error code is returned.

```c++
#include "huks/native_huks_api.h"
#include "huks/native_huks_param.h"
#include <string.h>
static napi_value ExportKey(napi_env env, napi_callback_info info)
{
    /* 1. Set the key alias. */
    const char *alias = "test_key";
    struct OH_Huks_Blob aliasBlob = { .size = (uint32_t)strlen(alias), .data = (uint8_t *)alias };
    /* Request the memory for holding the public key to be exported. */
    uint8_t *pubKey = (uint8_t *)malloc(512); // Request memory based on the key size.
    if (pubKey == nullptr) {
        return nullptr;
    }
    struct OH_Huks_Blob keyBlob = { 256, pubKey };
    struct OH_Huks_Result ohResult;
    do {
        ohResult = OH_Huks_ExportPublicKeyItem(&aliasBlob, nullptr, &keyBlob);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
    } while (0);
    free(pubKey);
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```
