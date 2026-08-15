# Opening and Closing Resources (C/C++)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=111094881c901cfe5b4be59a153e21d81f72600f translatedAt=2026-08-13T08:25:12.332Z pushedAt=2026-08-13T10:20:24.722Z -->

## Opening Resources

Starting from API 22, huksExternalCrypto provides APIs for opening and closing resources. Before performing key operations (key operations, general operations, PIN authentication, etc.), an app must call [OH_Huks_OpenResource](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_openresource) to open the resource. Opening a resource requires a `resourceId`, which is obtained by calling [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) provided by the certificate management capability.

### Linking the Dynamic Library in the CMake Script

```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so libhuks_external_crypto.z.so)
```

### How to Develop

1. Obtain the [keyUri](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certreference22) by calling [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) provided by the certificate management capability, and use it as the `resourceId`.

2. Initialize the parameter set: Construct the parameter set **paramSet** by using [OH_Huks_InitExternalCryptoParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_initexternalcryptoparamset), [OH_Huks_AddExternalCryptoParams](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_addexternalcryptoparams), and [OH_Huks_BuildExternalCryptoParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_buildexternalcryptoparamset).

3. Call [OH_Huks_OpenResource](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_openresource) to open the resource.

### Development Cases

```c++
#include "huks/native_huks_external_crypto_api.h"
#include "huks/native_huks_param.h"
#include "napi/native_api.h"
#include <string.h>

OH_Huks_Result InitParamSet(
    struct OH_Huks_ExternalCryptoParamSet **paramSet,
    const struct OH_Huks_ExternalCryptoParam *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitExternalCryptoParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_AddExternalCryptoParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeExternalCryptoParamSet(paramSet);
        return ret;
    }
    ret = OH_Huks_BuildExternalCryptoParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeExternalCryptoParamSet(paramSet);
        return ret;
    }
    return ret;
}

static const char *g_resourceId = "{\"providerName\":\"testProviderName\",\"abilityName\":\"CryptoExtension\",\"bundleName\":\"com.example.cryptoapplication\",\"index\":{\"key\":\"testKey\"}}";

static struct OH_Huks_ExternalCryptoParam g_openResourceParamsTest[] = {};

static napi_value OpenResource(napi_env env, napi_callback_info info) 
{
    struct OH_Huks_Blob resourceId = {
        (uint32_t)strlen(g_resourceId),
        (uint8_t *)g_resourceId
    };
    struct OH_Huks_ExternalCryptoParamSet *openResourceParamSet = nullptr;
    OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&openResourceParamSet, g_openResourceParamsTest,
            sizeof(g_openResourceParamsTest) / sizeof(OH_Huks_ExternalCryptoParam));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = OH_Huks_OpenResource(&resourceId, openResourceParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
    } while (0);
    OH_Huks_FreeExternalCryptoParamSet(&openResourceParamSet);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```

## Closing Resources

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

An ecosystem application calls the certificate HAP UI to display a certificate list. When a user selects a certificate, and the ecosystem application obtains **resourceId** that can be used to close the corresponding resource. For details about the scenarios and specifications, see [Resource Management Overview and Specifications](huks-resource-management-overview.md).

### Linking the Dynamic Library in the CMake Script

```txt
target_link_libraries(entry PUBLIC libhuks_ndk.z.so libhuks_external_crypto.z.so)
```

### How to Develop

1. Obtain the `resourceId` by calling [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) provided by the certificate management capability.

2. Initialize the parameter set: Construct the parameter set **paramSet** by using [OH_Huks_InitExternalCryptoParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_initexternalcryptoparamset), [OH_Huks_AddExternalCryptoParams](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_addexternalcryptoparams), and [OH_Huks_BuildExternalCryptoParamSet](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_buildexternalcryptoparamset).

3. Call [OH_Huks_CloseResource](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_closeresource) to close the resource. This API invokes [onClearUkeyPinAuthState](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#onclearukeypinauthstate) to clear the PIN authentication state associated with the resource, and invokes [onFinishSession](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#onfinishsession) to clear the session handle associated with the resource.

### Development Cases

```c++
#include "huks/native_huks_external_crypto_api.h"
#include "huks/native_huks_param.h"
#include "huks/native_huks_type.h"
#include "huks/native_huks_api.h"
#include "napi/native_api.h"
#include <string.h>

OH_Huks_Result InitParamSet(
    struct OH_Huks_ExternalCryptoParamSet **paramSet,
    const struct OH_Huks_ExternalCryptoParam *params,
    uint32_t paramCount)
{
    OH_Huks_Result ret = OH_Huks_InitExternalCryptoParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        return ret;
    }
    ret = OH_Huks_AddExternalCryptoParams(*paramSet, params, paramCount);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeExternalCryptoParamSet(paramSet);
        return ret;
    }
    ret = OH_Huks_BuildExternalCryptoParamSet(paramSet);
    if (ret.errorCode != OH_HUKS_SUCCESS) {
        OH_Huks_FreeExternalCryptoParamSet(paramSet);
        return ret;
    }
    return ret;
}

static const char *g_resourceId = "{\"providerName\":\"testProviderName\",\"abilityName\":\"CryptoExtension\",\"bundleName\":\"com.example.cryptoapplication\",\"userid\":100,\"index\":{\"key\":\"testKey\"}}";

static struct OH_Huks_ExternalCryptoParam g_closeResourceParamsTest[] = {};

static napi_value CloseResource(napi_env env, napi_callback_info info) 
{
    struct OH_Huks_Blob resourceId = {
        (uint32_t)strlen(g_resourceId),
        (uint8_t *)g_resourceId
    };
    struct OH_Huks_ExternalCryptoParamSet *closeResourceParamSet = nullptr;
    OH_Huks_Result ohResult;
    do {
        ohResult = InitParamSet(&closeResourceParamSet, g_closeResourceParamsTest,
            sizeof(g_closeResourceParamsTest) / sizeof(OH_Huks_ExternalCryptoParam));
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
        ohResult = OH_Huks_CloseResource(&resourceId, closeResourceParamSet);
        if (ohResult.errorCode != OH_HUKS_SUCCESS) {
            break;
        }
    } while (0);
    OH_Huks_FreeExternalCryptoParamSet(&closeResourceParamSet);
    
    napi_value ret;
    napi_create_int32(env, ohResult.errorCode, &ret);
    return ret;
}
```