# HuksKeyApi


## Overview

Defines the OpenHarmony Universal KeyStore (HUKS) capabilities, including key management and cryptography operations, provided for applications. Applications can call the HUKS functions to import or generate keys.

**System capability**: SystemCapability.Security.Huks

**Since**: 9


## Summary


### File

| Name| Description| 
| -------- | -------- |
| [native_huks_api.h](native__huks__api_8h.md) | Declares the functions used to access HUKS.<br>**File to include**: <huks/native_huks_api.h><br>**Library**: libhuks_ndk.z.so | 


### Functions

| Name| Description| 
| -------- | -------- |
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GetSdkVersion](#oh_huks_getsdkversion) (struct [OH_Huks_Blob](_o_h___huks___blob.md) \*sdkVersion) | Obtains the current HUKS SDK version. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GenerateKeyItem](#oh_huks_generatekeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetIn, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetOut) | Generates a key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ImportKeyItem](#oh_huks_importkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*key) | Imports a key in plaintext. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ImportWrappedKeyItem](#oh_huks_importwrappedkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*wrappingKeyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*wrappedKeyData) | Imports a key in ciphertext. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ExportPublicKeyItem](#oh_huks_exportpublickeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*key) | Exports the public key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_DeleteKeyItem](#oh_huks_deletekeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | Deletes a key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GetKeyItemParamSet](#oh_huks_getkeyitemparamset) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetIn, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetOut) | Obtains the properties of a key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_IsKeyItemExist](#oh_huks_iskeyitemexist) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | Checks whether a key exists. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AttestKeyItem](#oh_huks_attestkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_CertChain](_o_h___huks___cert_chain.md) \*certChain) | Obtains the certificate chain of a key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AnonAttestKeyItem](#oh_huks_anonattestkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_CertChain](_o_h___huks___cert_chain.md) \*certChain) | Obtains the certificate chain of a key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_InitSession](#oh_huks_initsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*token) | Initializes a key session. This function returns a session handle (mandatory) and a challenge value (optional). | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_UpdateSession](#oh_huks_updatesession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*inData, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*outData) | Adds and processes data by segment for a key operation, and outputs the processed data. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_FinishSession](#oh_huks_finishsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*inData, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*outData) | Finishes a key session. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AbortSession](#oh_huks_abortsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | Aborts a key session. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ListAliases](#oh_huks_listaliases) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_KeyAliasSet](_o_h___huks___key_alias_set.md) \*\*outData) | Lists key aliases. | 


## Function Description


### OH_Huks_AbortSession()

```
struct OH_Huks_Result OH_Huks_AbortSession (const struct OH_Huks_Blob * handle, const struct OH_Huks_ParamSet * paramSet )
```
**Description**
Aborts a key session.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the key session handle, which is returned by [OH_Huks_InitSession](#oh_huks_initsession). | 
| paramSet | Pointer to the parameters for aborting the key session. By default, this parameter is a null pointer. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.

**See**

[OH_Huks_InitSession](#oh_huks_initsession)

[OH_Huks_UpdateSession](#oh_huks_updatesession)

[OH_Huks_FinishSession](#oh_huks_finishsession)


### OH_Huks_AnonAttestKeyItem()

```
struct OH_Huks_Result OH_Huks_AnonAttestKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet, struct OH_Huks_CertChain * certChain )
```
**Description**
Obtains the certificate chain of a key.

<!--RP1--><!--RP1End-->

**Since**: 11

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAlias | Pointer to the alias of the target key. | 
| paramSet | Pointer to the parameters for obtaining the certificate chain. | 
| certChain | Pointer to the certificate chain obtained. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.

**NOTE**

This function involves time-consuming network operation. The caller can obtain the certificate chain through an asynchronous thread.


### OH_Huks_AttestKeyItem()

```
struct OH_Huks_Result OH_Huks_AttestKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet, struct OH_Huks_CertChain * certChain )
```

**Description**
Obtains the certificate chain of a key.

**Required permissions**
ohos.permission.ATTEST_KEY (for system applications only)

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAlias | Pointer to the alias of the target key. | 
| paramSet | Pointer to the parameters for obtaining the certificate chain. | 
| certChain | Pointer to the certificate chain obtained. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_DeleteKeyItem()

```
struct OH_Huks_Result OH_Huks_DeleteKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet )
```
**Description**
Deletes a key.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAlias | Pointer to the alias of the key to delete. It must be the same as the alias used for generating the key. | 
| paramSet | Pointer to the properties of the key to delete. If this parameter is not specified, the key of the [OH_HUKS_AUTH_STORAGE_LEVEL_CE](_huks_type_api.md#OH_Huks_AuthStorageLevel) level is deleted by default.| 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_ExportPublicKeyItem()

```
struct OH_Huks_Result OH_Huks_ExportPublicKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet, struct OH_Huks_Blob * key )
```
**Description**
Exports a public key.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAlias | Pointer to the alias of the public key to export. It must be the same as the alias used for generating the key. | 
| paramSet | Pointer to the parameters for exporting the public key. | 
| key | Pointer to the public key exported. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_FinishSession()

```
struct OH_Huks_Result OH_Huks_FinishSession (const struct OH_Huks_Blob * handle, const struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Blob * inData, struct OH_Huks_Blob * outData )
```
**Description**
Finishes a key session.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the key session handle, which is returned by [OH_Huks_InitSession](#oh_huks_initsession). | 
| paramSet | Pointer to the parameters required for the key operation. | 
| inData | Pointer to the data to be passed in. | 
| outData | Pointer to the output data. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.

**See**

[OH_Huks_InitSession](#oh_huks_initsession)

[OH_Huks_UpdateSession](#oh_huks_updatesession)

[OH_Huks_AbortSession](#oh_huks_abortsession)


### OH_Huks_GenerateKeyItem()

```
struct OH_Huks_Result OH_Huks_GenerateKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSetIn, struct OH_Huks_ParamSet * paramSetOut )
```
**Description**
Generates a key.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAlias | Pointer to the alias of the key to generate. The alias must be unique in the process of the service. | 
| paramSetIn | Pointer to the parameters for generating the key. | 
| paramSetOut | Pointer to a temporary key generated. If the generated key is not a temporary key, this parameter is a null pointer. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_GetKeyItemParamSet()

```
struct OH_Huks_Result OH_Huks_GetKeyItemParamSet (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSetIn, struct OH_Huks_ParamSet * paramSetOut )
```
**Description**
Obtains the properties of a key.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAlias | Pointer to the alias of the target key. | 
| paramSetIn | Pointer to the tag required for obtaining the properties. By default, this parameter is a null pointer. | 
| paramSetOut | Pointer to the key properties obtained. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_GetSdkVersion()

```
struct OH_Huks_Result OH_Huks_GetSdkVersion (struct OH_Huks_Blob * sdkVersion)
```
**Description**
Obtains the current HUKS SDK version.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| sdkVersion | Pointer to the SDK version (string) obtained. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_ImportKeyItem()

```
struct OH_Huks_Result OH_Huks_ImportKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Blob * key )
```
**Description**
Imports a key in plaintext.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAlias | Pointer to the alias of the key to import. The alias must be unique in the process of the service. | 
| paramSet | Pointer to the properties of the key to import. | 
| key | Pointer to the key to import. The key data must be of the [HuksTypeApi](_huks_type_api.md) type. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_ImportWrappedKeyItem()

```
struct OH_Huks_Result OH_Huks_ImportWrappedKeyItem (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_Blob * wrappingKeyAlias, const struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Blob * wrappedKeyData )
```
**Description**
Imports a key in ciphertext.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAlias | Pointer to the alias of the key to import. The alias must be unique in the process of the service. | 
| wrappingKeyAlias | Pointer to the alias of the key used for key agreement, which generates a shared secret to decrypt the key to import. | 
| paramSet | Pointer to the parameters for importing the key in ciphertext. | 
| wrappedKeyData | Pointer to the encrypted key to import. The data must be of the [OH_Huks_AlgSuite](_huks_type_api.md#oh_huks_algsuite) type.| 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_InitSession()

```
struct OH_Huks_Result OH_Huks_InitSession (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet, struct OH_Huks_Blob * handle, struct OH_Huks_Blob * token )
```
**Description**
Initializes a key session. This function returns a handle (mandatory) and a challenge value (optional).

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAlias | Pointer to the alias of the target key. | 
| paramSet | Pointer to the parameters for the initialization operation. | 
| handle | Pointer to the handle of the key session. This handle is required for subsequent operations of the same key, including [OH_Huks_UpdateSession](#oh_huks_updatesession), [OH_Huks_FinishSession](#oh_huks_finishsession), and [OH_Huks_AbortSession](#oh_huks_abortsession). | 
| token | Pointer to the token used for key access control. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.

**See**

[OH_Huks_UpdateSession](#oh_huks_updatesession)

[OH_Huks_FinishSession](#oh_huks_finishsession)

[OH_Huks_AbortSession](#oh_huks_abortsession)


### OH_Huks_IsKeyItemExist()

```
struct OH_Huks_Result OH_Huks_IsKeyItemExist (const struct OH_Huks_Blob * keyAlias, const struct OH_Huks_ParamSet * paramSet )
```
**Description**
Checks whether a key exists.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| keyAlias | Pointer to the alias of the key to check. | 
| paramSet | Pointer to the parameters for checking the key. By default, this parameter is a null pointer. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the key exists.

Returns [OH_Huks_ErrCode#OH_HUKS_ERR_CODE_ITEM_NOT_EXIST](_huks_type_api.md#oh_huks_errcode) if the key does not exist. 
Returns other errors in other cases.


### OH_Huks_ListAliases()

```
struct OH_Huks_Result OH_Huks_ListAliases (const struct OH_Huks_ParamSet * paramSet, struct OH_Huks_KeyAliasSet ** outData )
```
**Description**
Lists key aliases.

**Since**: 12

**Parameters**

| Name| Description| 
| -------- | -------- |
| paramSet | Pointer to the parameters for listing the key aliases. By default, this parameter is a null pointer. | 
| outData | pointer to the key aliases obtained. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.


### OH_Huks_UpdateSession()

```
struct OH_Huks_Result OH_Huks_UpdateSession (const struct OH_Huks_Blob * handle, const struct OH_Huks_ParamSet * paramSet, const struct OH_Huks_Blob * inData, struct OH_Huks_Blob * outData )
```
**Description**
Adds and processes data by segment for a key operation, and outputs the processed data.

**Since**: 9

**Parameters**

| Name| Description| 
| -------- | -------- |
| handle | Pointer to the key session handle, which is returned by [OH_Huks_InitSession](#oh_huks_initsession). | 
| paramSet | Pointer to the parameters required for the key operation. | 
| inData | Pointer to the data to be processed. If there is a large amount of data to be processed, you can call this function multiple times to process data by segment. | 
| outData | Pointer to the output data. | 

**Returns**

Returns [OH_HUKS_SUCCESS](_huks_type_api.md#oh_huks_errcode) if the operation is successful; returns an error code otherwise.

**See**

[OH_Huks_InitSession](#oh_huks_initsession)

[OH_Huks_FinishSession](#oh_huks_finishsession)

[OH_Huks_AbortSession](#oh_huks_abortsession)
