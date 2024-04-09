# Security Subsystem - Key Management Service Changelog

## cl.security.1 Permission Change on the Key Attestation APIs

**Access Level**

Public API

**Reason for Change**

The public key of the end-entity certificate (device certificate) in the certificate chain obtained by using the key attestation API can be used as the unique identifier of a device, which imposes privacy leakage risks. For security purposes, a permission is required for calling these APIs.

**Change Impact**

This change is a non-compatible change. Adaptation is required.

**API level**

9

**Change Since**

OpenHarmony SDK 4.1.5.3

**Key API/Component Changes**

| Involved APIs| Before the Change| After the Change|
| ------- | ----- | ------ |
| attestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback<HuksReturnResult>) : void | No permission    is required. | The ohos.permission.ATTEST_KEY permission is required.|
| attestKeyItem(keyAlias: string, options: HuksOptions) : Promise<HuksReturnResult> | No permission    is required. | The ohos.permission.ATTEST_KEY permission is required.|
| struct OH_Huks_Result OH_Huks_AttestKeyItem(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_CertChain *certChain) | No permission    is required. | The ohos.permission.ATTEST_KEY permission is required.|

**Adaptation Guide**

Method 1: Use the following APIs for key attestation.
| API|
| ------- |
| anonAttestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback<HuksReturnResult>): void; |
| anonAttestKeyItem(keyAlias: string, options: HuksOptions): Promise<HuksReturnResult> |
| struct OH_Huks_Result OH_Huks_AnonAttestKeyItem(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_CertChain *certChain) |

Method 2: Request the ohos.permission.ATTEST_KEY permission for your application. This permission is available only to system applications.

