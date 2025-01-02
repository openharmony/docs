# native_huks_api.h


## Overview

Declares the APIs used to access the HUKS.

**Since**: 9

**Related module**: [HuksKeyApi](_huks_key_api.md)


## Summary


### Functions

| Name| Description| 
| -------- | -------- |
| struct [OH_Huks_Result](_o_h___huks___result.md)  [OH_Huks_GetSdkVersion](_huks_key_api.md#oh_huks_getsdkversion) (struct [OH_Huks_Blob](_o_h___huks___blob.md) \*sdkVersion) | Obtains the current HUKS SDK version. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GenerateKeyItem](_huks_key_api.md#oh_huks_generatekeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetIn, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetOut) | Generates a key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ImportKeyItem](_huks_key_api.md#oh_huks_importkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*key) | Imports a key in plaintext. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ImportWrappedKeyItem](_huks_key_api.md#oh_huks_importwrappedkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*wrappingKeyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*wrappedKeyData) | Imports a key in ciphertext. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ExportPublicKeyItem](_huks_key_api.md#oh_huks_exportpublickeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*key) | Exports the public key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_DeleteKeyItem](_huks_key_api.md#oh_huks_deletekeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | Deletes a key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_GetKeyItemParamSet](_huks_key_api.md#oh_huks_getkeyitemparamset) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetIn, struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSetOut) | Obtains the properties of a key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_IsKeyItemExist](_huks_key_api.md#oh_huks_iskeyitemexist) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | Checks whether a key exists. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AttestKeyItem](_huks_key_api.md#oh_huks_attestkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_CertChain](_o_h___huks___cert_chain.md) \*certChain) | Obtains the certificate chain of a key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AnonAttestKeyItem](_huks_key_api.md#oh_huks_anonattestkeyitem) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_CertChain](_o_h___huks___cert_chain.md) \*certChain) | Obtains the certificate chain of a key. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_InitSession](_huks_key_api.md#oh_huks_initsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*keyAlias, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*token) | Initializes a key session. This function returns a session handle (mandatory) and a challenge value (optional). | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_UpdateSession](_huks_key_api.md#oh_huks_updatesession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*inData, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*outData) | Adds data by segment for the key operation, performs the related key operation, and outputs the processed data. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_FinishSession](_huks_key_api.md#oh_huks_finishsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*inData, struct [OH_Huks_Blob](_o_h___huks___blob.md) \*outData) | Finishes a key session. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_AbortSession](_huks_key_api.md#oh_huks_abortsession) (const struct [OH_Huks_Blob](_o_h___huks___blob.md) \*handle, const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet) | Aborts a key session. | 
| struct [OH_Huks_Result](_o_h___huks___result.md) [OH_Huks_ListAliases](_huks_key_api.md#oh_huks_listaliases) (const struct [OH_Huks_ParamSet](_o_h___huks___param_set.md) \*paramSet, struct [OH_Huks_KeyAliasSet](_o_h___huks___key_alias_set.md) \*\*outData) | Lists key aliases. | 
