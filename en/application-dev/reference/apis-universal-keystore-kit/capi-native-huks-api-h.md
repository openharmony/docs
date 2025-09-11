# native_huks_api.h

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

## Overview

Declares the APIs used to access the HUKS.

**File to include**: <huks/native_huks_api.h>

**Library**: libhuks_ndk.z.so

**System capability**: SystemCapability.Security.Huks.Core

The preceding system capability is available since API version 20. From API versions 9 to 19, the system capability is **SystemCapability.Security.Huks**.

**Since**: 9

**Related modules:** [HuksKeyApi](capi-hukskeyapi.md)

## Summary

### Functions

| Name| Description|
| -- | -- |
| [struct OH_Huks_Result OH_Huks_GetSdkVersion(struct OH_Huks_Blob *sdkVersion)](#oh_huks_getsdkversion) | Obtains the current HUKS SDK version.|
| [struct OH_Huks_Result OH_Huks_GenerateKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSetIn, struct OH_Huks_ParamSet *paramSetOut)](#oh_huks_generatekeyitem) | Generates a key.|
| [struct OH_Huks_Result OH_Huks_ImportKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet, const struct OH_Huks_Blob *key)](#oh_huks_importkeyitem) | Imports a key in plaintext.|
| [struct OH_Huks_Result OH_Huks_ImportWrappedKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_Blob *wrappingKeyAlias, const struct OH_Huks_ParamSet *paramSet,const struct OH_Huks_Blob *wrappedKeyData)](#oh_huks_importwrappedkeyitem) | Imports a key in ciphertext.|
| [struct OH_Huks_Result OH_Huks_ExportPublicKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_Blob *key)](#oh_huks_exportpublickeyitem) | Exports the public key.|
| [struct OH_Huks_Result OH_Huks_DeleteKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet)](#oh_huks_deletekeyitem) | Deletes a key.|
| [struct OH_Huks_Result OH_Huks_GetKeyItemParamSet(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSetIn, struct OH_Huks_ParamSet *paramSetOut)](#oh_huks_getkeyitemparamset) | Obtains the properties of a key.|
| [struct OH_Huks_Result OH_Huks_IsKeyItemExist(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet)](#oh_huks_iskeyitemexist) | Checks whether a key exists.|
| [struct OH_Huks_Result OH_Huks_AttestKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_CertChain *certChain)](#oh_huks_attestkeyitem) | Obtains the certificate chain of a key. This API is open only to system applications.|
| [struct OH_Huks_Result OH_Huks_AnonAttestKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_CertChain *certChain)](#oh_huks_anonattestkeyitem) | Obtains the certificate chain of a key.<br> This function involves time-consuming network operation. The caller can obtain the certificate chain through an asynchronous thread.|
| [struct OH_Huks_Result OH_Huks_InitSession(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_Blob *handle, struct OH_Huks_Blob *token)](#oh_huks_initsession) | Initializes a key session. This function returns a session handle (mandatory) and a challenge value (optional).|
| [struct OH_Huks_Result OH_Huks_UpdateSession(const struct OH_Huks_Blob *handle,const struct OH_Huks_ParamSet *paramSet, const struct OH_Huks_Blob *inData, struct OH_Huks_Blob *outData)](#oh_huks_updatesession) | Adds data by segment for the key operation, performs the related key operation, and outputs the processed data.|
| [struct OH_Huks_Result OH_Huks_FinishSession(const struct OH_Huks_Blob *handle,const struct OH_Huks_ParamSet *paramSet, const struct OH_Huks_Blob *inData, struct OH_Huks_Blob *outData)](#oh_huks_finishsession) | Finishes a key session.|
| [struct OH_Huks_Result OH_Huks_AbortSession(const struct OH_Huks_Blob *handle,const struct OH_Huks_ParamSet *paramSet)](#oh_huks_abortsession) | Aborts a key session.|
| [struct OH_Huks_Result OH_Huks_ListAliases(const struct OH_Huks_ParamSet *paramSet,struct OH_Huks_KeyAliasSet **outData)](#oh_huks_listaliases) | Obtains the key alias set.|
| [struct OH_Huks_Result OH_Huks_WrapKey(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet,struct OH_Huks_Blob *wrappedKey)](#oh_huks_wrapkey) | Exports a wrapped key.|
| [struct OH_Huks_Result OH_Huks_UnwrapKey(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet,struct OH_Huks_Blob *wrappedKey)](#oh_huks_unwrapkey) | Imports a wrapped key.|

## Function Description

### OH_Huks_GetSdkVersion()

```
struct OH_Huks_Result OH_Huks_GetSdkVersion(struct OH_Huks_Blob *sdkVersion)
```

**Description**

Obtains the current HUKS SDK version.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *sdkVersion | Pointer to the SDK version (string) obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: The value of **sdkVersion** or **sdkVersion->data** is **null**, or the value of **sdkVersion->size** is too small.|

### OH_Huks_GenerateKeyItem()

```
struct OH_Huks_Result OH_Huks_GenerateKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSetIn, struct OH_Huks_ParamSet *paramSetOut)
```

**Description**

Generates a key.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the key to generate. The alias must be unique in the process of the service.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSetIn | Pointer to the parameters for generating the key.|
| [struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSetOut | Pointer to a temporary key generated. If the generated key is not a temporary key, this parameter is a null pointer.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **keyAlias**, **paramSetIn**, or **paramSetOut** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_FILE_OPERATION_FAIL = 12000004: Failed to delete or write the file.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file does not exist.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_CRYPTO_FAIL = 12000006: The encryption engine failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_CALL_SERVICE_FAILED = 12000015: Failed to connect to the user IAM.<br>         OH_HUKS_ERR_CODE_DEVICE_PASSWORD_UNSET = 12000016: No device password is set.<br>         OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001: This feature is not supported currently.<br>         OH_HUKS_ERR_CODE_KEY_ALREADY_EXIST = 12000017 (new in API version 20): A key with the same name already exists.|

### OH_Huks_ImportKeyItem()

```
struct OH_Huks_Result OH_Huks_ImportKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet, const struct OH_Huks_Blob *key)
```

**Description**

Imports a key in plaintext.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the key to import. The alias must be unique in the process of the service.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the properties of the key to import.|
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *key | Pointer to the data of the key to import, complying with the format requirements of HUKS. For details, see [native_huks_type.h](capi-native-huks-type-h.md).|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **keyAlias**, **paramSet**, or **key** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_FILE_OPERATION_FAIL = 12000004: Failed to delete or write the file.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_CALL_SERVICE_FAILED = 12000015: Failed to connect to the user IAM.<br>         OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001: This feature is not supported currently.<br>         OH_HUKS_ERR_CODE_KEY_ALREADY_EXIST = 12000017 (new in API version 20): A key with the same name already exists.|

### OH_Huks_ImportWrappedKeyItem()

```
struct OH_Huks_Result OH_Huks_ImportWrappedKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_Blob *wrappingKeyAlias, const struct OH_Huks_ParamSet *paramSet,const struct OH_Huks_Blob *wrappedKeyData)
```

**Description**

Imports a key in ciphertext.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the key to import. The alias must be unique in the process of the service.|
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *wrappingKeyAlias | Pointer to the alias of the key used for key agreement, which generates a shared secret to decrypt the key to import.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for importing the key in ciphertext.|
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *wrappedKeyData | Pointer to the data of the key to import, complying with the format requirements of HUKS. For details, see [OH_Huks_AlgSuite](capi-native-huks-type-h.md#oh_huks_algsuite).|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **keyAlias**, **wrappingKeyAlias**, **paramSet**, or **wrappedKeyData** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_FILE_OPERATION_FAIL = 12000004: Failed to delete or write the file.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_CRYPTO_FAIL = 12000006: The encryption engine failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_CALL_SERVICE_FAILED = 12000015: Failed to connect to the user IAM.<br>         OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001: This feature is not supported currently.<br>         OH_HUKS_ERR_CODE_KEY_ALREADY_EXIST = 12000017 (new in API version 20): A key with the same name already exists.|

### OH_Huks_ExportPublicKeyItem()

```
struct OH_Huks_Result OH_Huks_ExportPublicKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_Blob *key)
```

**Description**

Exports the public key.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the public key to export. It must be the same as the alias used for generating the key.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for exporting the public key.|
| [struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *key | Pointer to the public key exported.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **keyAlias**, **paramSet**, or **key** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file does not exist.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001: This feature is not supported currently.|

### OH_Huks_DeleteKeyItem()

```
struct OH_Huks_Result OH_Huks_DeleteKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet)
```

**Description**

Deletes a key.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the key to delete. It must be the same as the alias used for generating the key.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for deleting the key. By default, this parameter is a null pointer. The default key storage level is [OH_HUKS_AUTH_STORAGE_LEVEL_CE](capi-native-huks-type-h.md#oh_huks_authstoragelevel).|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **keyAlias** or **paramSet** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file does not exist.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.|

### OH_Huks_GetKeyItemParamSet()

```
struct OH_Huks_Result OH_Huks_GetKeyItemParamSet(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSetIn, struct OH_Huks_ParamSet *paramSetOut)
```

**Description**

Obtains the properties of a key.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the target key.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSetIn | Pointer to the tag required for obtaining the properties. By default, this parameter is a null pointer.|
| [struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSetOut | Pointer to the key properties obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **keyAlias**, **paramSetIn**, or **paramSetOut** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file does not exist.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001: This feature is not supported currently.|

### OH_Huks_IsKeyItemExist()

```
struct OH_Huks_Result OH_Huks_IsKeyItemExist(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet)
```

**Description**

Checks whether a key exists.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the key to check.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for checking the key. By default, this parameter is a null pointer.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **keyAlias** or **paramSet** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file does not exist.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.|

### OH_Huks_AttestKeyItem()

```
struct OH_Huks_Result OH_Huks_AttestKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_CertChain *certChain)
```

**Description**

Obtains the certificate chain of a key. This API is open only to system applications.

**Required permissions**: ohos.permission.ATTEST_KEY (available only for system applications)

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the target key.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for obtaining the certificate chain.|
| [struct OH_Huks_CertChain](capi-hukstypeapi-oh-huks-certchain.md) *certChain | Pointer to the certificate chain obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **keyAlias**, **paramSet**, or **certChain** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file does not exist.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_CRYPTO_FAIL = 12000006: The encryption engine failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001: This feature is not supported currently.<br>         OH_HUKS_ERR_CODE_PERMISSION_FAIL = 201: Permission check failed. Request the permission first.|

### OH_Huks_AnonAttestKeyItem()

```
struct OH_Huks_Result OH_Huks_AnonAttestKeyItem(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_CertChain *certChain)
```

**Description**

Obtains the certificate chain of a key.<br> This function involves time-consuming network operation. The caller can obtain the certificate chain through an asynchronous thread.

**Since**: 11


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the target key.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for obtaining the certificate chain.|
| [struct OH_Huks_CertChain](capi-hukstypeapi-oh-huks-certchain.md) *certChain | Pointer to the certificate chain obtained.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **keyAlias**, **paramSet**, or **certChain** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file does not exist.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_CRYPTO_FAIL = 12000006: The encryption engine failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001: This feature is not supported currently.<br>         OH_HUKS_ERR_CODE_PERMISSION_FAIL = 201: Permission check failed. Request the permission first.|

### OH_Huks_InitSession()

```
struct OH_Huks_Result OH_Huks_InitSession(const struct OH_Huks_Blob *keyAlias,const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_Blob *handle, struct OH_Huks_Blob *token)
```

**Description**

Initializes a key session. This function returns a session handle (mandatory) and a challenge value (optional).

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the key to be operated.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for the initialization operation.|
| [struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *handle | Pointer to the handle of the key session. This handle is required for subsequent operations of the same key, including [OH_Huks_UpdateSession](#oh_huks_updatesession), [OH_Huks_FinishSession](#oh_huks_finishsession), and [OH_Huks_AbortSession](#oh_huks_abortsession).|
| [struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *token | Pointer to the token used for key access control.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **keyAlias**, **paramSet**, **handle**, or **token** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file does not exist.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_SESSION_LIMIT = 12000010: Hit the session limit.<br>         OH_HUKS_ERR_CODE_CRYPTO_FAIL = 12000006: The encryption engine failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001: This feature is not supported currently.|

**Reference**

[OH_Huks_UpdateSession](#oh_huks_updatesession)

[OH_Huks_FinishSession](#oh_huks_finishsession)

[OH_Huks_AbortSession](#oh_huks_abortsession)


### OH_Huks_UpdateSession()

```
struct OH_Huks_Result OH_Huks_UpdateSession(const struct OH_Huks_Blob *handle,const struct OH_Huks_ParamSet *paramSet, const struct OH_Huks_Blob *inData, struct OH_Huks_Blob *outData)
```

**Description**

Adds data by segment for the key operation, performs the related key operation, and outputs the processed data.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *handle | Pointer to the key session handle, which is returned by [OH_Huks_InitSession](#oh_huks_initsession).|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters required for the key operation.|
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *inData | Pointer to the data to be processed. If there is a large amount of data to be processed, you can call this function multiple times to process data by segment.|
| [struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *outData | Pointer to the output data.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **handle**, **paramSet**, **inData**, or **outData** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file or the handle does not exist.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_CREDENTIAL_NOT_EXIST = 12000013: The certificate does not exist.<br>         OH_HUKS_ERR_CODE_CRYPTO_FAIL = 12000006: The encryption engine failed.<br>         OH_HUKS_ERR_CODE_KEY_AUTH_VERIFY_FAILED = 12000008: Failed to verify the access token.<br>         OH_HUKS_ERR_CODE_KEY_AUTH_PERMANENTLY_INVALIDATED = 12000007: Failed to verify the access token information.<br>         OH_HUKS_ERR_CODE_KEY_AUTH_TIME_OUT = 12000009: The verification of the access token times out.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_DEVICE_PASSWORD_UNSET = 12000016: No device password is set.<br>         OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001: This feature is not supported currently.|

**Reference**

[OH_Huks_InitSession](#oh_huks_initsession)

[OH_Huks_FinishSession](#oh_huks_finishsession)

[OH_Huks_AbortSession](#oh_huks_abortsession)


### OH_Huks_FinishSession()

```
struct OH_Huks_Result OH_Huks_FinishSession(const struct OH_Huks_Blob *handle,const struct OH_Huks_ParamSet *paramSet, const struct OH_Huks_Blob *inData, struct OH_Huks_Blob *outData)
```

**Description**

Finishes a key session.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *handle | Pointer to the key session handle, which is returned by [OH_Huks_InitSession](#oh_huks_initsession).|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters required for the key operation.|
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *inData | Pointer to the data to be passed in.|
| [struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *outData | Pointer to the output data.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **handle**, **paramSet**, **inData**, or **outData** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file or the handle does not exist.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_CREDENTIAL_NOT_EXIST = 12000013: The certificate does not exist.<br>         OH_HUKS_ERR_CODE_CRYPTO_FAIL = 12000006: The encryption engine failed.<br>         OH_HUKS_ERR_CODE_KEY_AUTH_VERIFY_FAILED = 12000008: Failed to verify the access token.<br>         OH_HUKS_ERR_CODE_KEY_AUTH_PERMANENTLY_INVALIDATED = 12000007: Failed to verify the access token information.<br>         OH_HUKS_ERR_CODE_KEY_AUTH_TIME_OUT = 12000009: The verification of the access token times out.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_DEVICE_PASSWORD_UNSET = 12000016: No device password is set.<br>         OH_HUKS_ERR_CODE_FEATURE_NOT_SUPPORTED = 12000001: This feature is not supported currently.<br>         OH_HUKS_ERR_CODE_KEY_ALREADY_EXIST = 12000017 (new in API version 20): A key with the same name already exists.|

**Reference**

[OH_Huks_InitSession](#oh_huks_initsession)

[OH_Huks_UpdateSession](#oh_huks_updatesession)

[OH_Huks_AbortSession](#oh_huks_abortsession)


### OH_Huks_AbortSession()

```
struct OH_Huks_Result OH_Huks_AbortSession(const struct OH_Huks_Blob *handle,const struct OH_Huks_ParamSet *paramSet)
```

**Description**

Aborts a key session.

**Since**: 9


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *handle | Pointer to the key session handle, which is returned by [OH_Huks_InitSession](#oh_huks_initsession).|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for aborting the key session. By default, this parameter is a null pointer.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **handle**, **paramSet**, **inData**, or **outData** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INVALID_CRYPTO_ALG_ARGUMENT = 12000003: Invalid key parameter.<br>         OH_HUKS_ERR_CODE_ITEM_NOT_EXIST = 12000011: The key file or the handle does not exist.<br>         OH_HUKS_ERR_CODE_MISSING_CRYPTO_ALG_ARGUMENT = 12000002: Failed to obtain key arguments.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_CREDENTIAL_NOT_EXIST = 12000013: The certificate does not exist.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.|

**Reference**

[OH_Huks_InitSession](#oh_huks_initsession)

[OH_Huks_UpdateSession](#oh_huks_updatesession)

[OH_Huks_FinishSession](#oh_huks_finishsession)


### OH_Huks_ListAliases()

```
struct OH_Huks_Result OH_Huks_ListAliases(const struct OH_Huks_ParamSet *paramSet,struct OH_Huks_KeyAliasSet **outData)
```

**Description**

Obtains the key alias set.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for obtaining the key alias set. By default, this parameter is a null pointer.|
| [struct OH_Huks_KeyAliasSet](capi-hukstypeapi-oh-huks-keyaliasset.md) **outData | Pointer to the output data.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_ILLEGAL_ARGUMENT = 401: **paramSet** or **outData** is invalid.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.|

### OH_Huks_WrapKey()

```
struct OH_Huks_Result OH_Huks_WrapKey(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet,struct OH_Huks_Blob *wrappedKey)
```

**Description**

Exports a wrapped key.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the key to export.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for encrypting the exported key.|
| [struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *wrappedKey | Pointer to the wrapped key to export.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_NOT_SUPPORTED_API = 801: The API is not supported.<br>         OH_HUKS_ERR_CODE_FILE_OPERATION_FAIL = 12000004: Failed to delete or write the file.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_CRYPTO_FAIL = 12000011: The key file does not exist.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_INVALID_ARGUMENT = 12000018: The key alias, parameter set, or wrapped key is invalid.|

### OH_Huks_UnwrapKey()

```
struct OH_Huks_Result OH_Huks_UnwrapKey(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet,struct OH_Huks_Blob *wrappedKey)
```

**Description**

Imports a wrapped key.

**Since**: 20


**Parameters**

| Name| Description|
| -- | -- |
| [const struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *keyAlias | Pointer to the alias of the key to import. The alias must be unique in the service process. Otherwise, the key will be overwritten.|
| [const struct OH_Huks_ParamSet](capi-hukstypeapi-oh-huks-paramset.md) *paramSet | Pointer to the parameters for encrypting the imported key.|
| [struct OH_Huks_Blob](capi-hukstypeapi-oh-huks-blob.md) *wrappedKey | Pointer to the wrapped key to import.|

**Returns**

| Type| Description|
| -- | -- |
| [struct OH_Huks_Result](capi-hukstypeapi-oh-huks-result.md) | Possible error codes (**errorCode**):<br>         OH_HUKS_SUCCESS = 0: Operation successful.<br>         OH_HUKS_ERR_CODE_NOT_SUPPORTED_API = 801: The API is not supported.<br>         OH_HUKS_ERR_CODE_FILE_OPERATION_FAIL = 12000004: Failed to delete or write the file.<br>         OH_HUKS_ERR_CODE_COMMUNICATION_FAIL = 12000005: IPC communication failed.<br>         OH_HUKS_ERR_CODE_INTERNAL_ERROR = 12000012: A system error occurs.<br>         OH_HUKS_ERR_CODE_INSUFFICIENT_MEMORY = 12000014: Insufficient memory.<br>         OH_HUKS_ERR_CODE_CALL_SERVICE_FAILED = 12000015: Failed to connect to the user IAM.<br>         OH_HUKS_ERR_CODE_INVALID_ARGUMENT = 12000018: The key alias, parameter set, or wrapped key is invalid.|
