# 指定用户身份操作(仅对系统应用开放)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

多用户并发进行密钥操作时，为了实现密钥数据隔离和访问控制，HUKS提供了额外的可以指定用户进行密钥操作的接口。

>**说明：**
> 轻量级设备不支持指定用户身份操作功能。

## 约束与限制

- 调用方的user id必须在0到99之间，包含0和99。
- 这部分接口是原有能力的增强，仅面向系统应用开放。

## 接口说明

这部分增强接口，在现有的功能接口的基础上，增加支持参数`userId`用于指定用户ID。

指定用户的接口额外支持以下功能和使用条件：

1. 使用方可以同时在options参数中传入[HUKS_TAG_AUTH_STORAGE_LEVEL](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_authstoragelevel)选项，以指定存储在指定用户的DE区、CE区或ECE区。
2. 使用方在options参数中不额外传入[HUKS_TAG_AUTH_STORAGE_LEVEL](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_authstoragelevel)选项时，该接口默认行为是：使用指定userId对应CE存储区的密钥。即不传入[HUKS_TAG_AUTH_STORAGE_LEVEL](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_authstoragelevel)参数，等同于传入值为[HUKS_AUTH_STORAGE_LEVEL_CE](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_authstoragelevel)的[HUKS_TAG_AUTH_STORAGE_LEVEL](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_authstoragelevel)参数。

除此之外指定用户的接口的用法和支持的算法规格，与不指定用户的对应接口一致。

| 指定用户的接口 | 说明 | 不指定用户的接口示例参考 |
| -------- | -------- | ----------| 
| [generateKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksgeneratekeyitemasuser)              |   生成密钥。           |  [generateKeyItem](huks-key-generation-arkts.md)             |
| [deleteKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksdeletekeyitemasuser)                  |   删除密钥。           |  [deleteKeyItem](huks-delete-key-arkts.md)               |
| [importKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksimportkeyitemasuser)                  |   明文导入密钥。      |  [importKeyItem](huks-import-key-in-plaintext-arkts.md)                |
| [importWrappedKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksimportwrappedkeyitemasuser)    |  加密导入密钥。        |  [importWrappedKeyItem](huks-import-wrapped-key-arkts.md)             |
| [exportKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksexportkeyitemasuser)                  |   导出密钥。        |  [exportKeyItem](huks-export-key-arkts.md)                |
| [getKeyItemPropertiesAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksgetkeyitempropertiesasuser)    |  获取密钥属性。     |  [getKeyItemProperties](huks-obtain-key-properties-arkts.md)             |
| [hasKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#hukshaskeyitemasuser)                        |  查询密钥是否存在。    |  [hasKeyItem](huks-check-key-arkts.md)               |
| [initSessionAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksinitsessionasuser)                      |  初始化密钥会话。       |  initSession   [加密解密](huks-encryption-decryption-arkts.md) [签名验签](huks-signing-signature-verification-arkts.md) [密钥协商](huks-key-agreement-arkts.md) [密钥派生](huks-key-derivation-arkts.md)           |
| [attestKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksattestkeyitemasuser)                  |  非匿名密钥证明。    |  [attestKeyItem](huks-key-attestation-arkts.md)                |
| [anonAttestKeyItemAsUser](../../reference/apis-universal-keystore-kit/js-apis-huks-sys.md#huksanonattestkeyitemasuser)          | 匿名密钥证明。     |  [anonAttestKeyItem](huks-key-anon-attestation-arkts.md)                |
