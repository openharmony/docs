# Security Subsystem - HUKS Changelog

## cl.security.1 Permission Change on the Key Attestation APIs

**Access Level**

Public API

**Change Reason**

The public key of the end-entity certificate (device certificate) in the certificate chain obtained by using the key attestation API can be used as the unique identifier of a device, which imposes privacy leakage risks. For security purposes, a permission is required for calling these APIs.

**Change Impact**

This change is a non-compatible change. You are advised to use new APIs.

**API level**

9

**Change Since**

OpenHarmony SDK 4.1.5.3

**Key API/Component Changes**

| API| Before the Change| After the Change|
| ------- | ----- | ------ |
| attestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback<HuksReturnResult>) : void | No permission control| The ohos.permission.ATTEST_KEY permission is required.|
| attestKeyItem(keyAlias: string, options: HuksOptions) : Promise<HuksReturnResult> | No permission control| The ohos.permission.ATTEST_KEY permission is required.|
| struct OH_Huks_Result OH_Huks_AttestKeyItem(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_CertChain *certChain) | No permission control| The ohos.permission.ATTEST_KEY permission is required.|

**Adaptation Guide**

Method 1: Use the following APIs for key attestation.
| API|
| ------- |
| anonAttestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback<HuksReturnResult>): void; |
| anonAttestKeyItem(keyAlias: string, options: HuksOptions): Promise<HuksReturnResult> |
| struct OH_Huks_Result OH_Huks_AnonAttestKeyItem(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_CertChain *certChain) |

Adaptation Method 2: Apply for and configure the ohos.permission.ATTEST_KEY permission for your application.

## cl.security.2 Deprecation of getSdkVersion and enum HUKS_AES_KEY_SIZE_512

**Access Level**

Public API

**Reason for Change**

The **getSdkVersion** API and **enum HUKS_AES_KEY_SIZE_512** are reserved interfaces without any functionality.  These interfaces are redundant and therefore deprecated.

**Change Impact**

The deprecated interfaces are redundant. Other behaviors remain unchanged.

**API Level**
8

**Deprecated Since**

OpenHarmony SDK 4.1.5.5

**Deprecated APIs**

| API                                                    | Deprecated Description                                                    | Substitute API                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| function getSdkVersion(options: HuksOptions): string; | This API is reserved, and its function is not implemented.            | N/A|
| enum HUKS_AES_KEY_SIZE_512                           | This interface is reserved, and its function is not implemented.                | N/A         |

**Adaptation Guide**

The deprecated interfaces are redundant. Other behaviors remain unchanged.
