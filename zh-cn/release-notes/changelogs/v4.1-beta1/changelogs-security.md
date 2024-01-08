# 安全子系统-密钥管理服务变更说明

## cl.security.1  密钥管理服务密钥证明接口权限变更

**访问级别**

公开接口

**变更原因**

通过该接口获取的证书链中第3级证书(设备级)的公钥可作为设备唯一标识，存在隐私泄露风险，需对调用该接口能力的业务进行管控。

**变更影响**

非兼容性变更，需要开发者进行适配。

**API level**

9

**变更发生版本**

从OpenHarmony SDK 4.1.5.3开始。

**变更的接口**

| 接口声明 | 变更前 | 变更后 |
| ------- | ----- | ------ |
| attestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback<HuksReturnResult>) : void | 无权限管控 | 需要ohos.permission.ATTEST_KEY权限 |
| attestKeyItem(keyAlias: string, options: HuksOptions) : Promise<HuksReturnResult> | 无权限管控 | 需要ohos.permission.ATTEST_KEY权限 |
| struct OH_Huks_Result OH_Huks_AttestKeyItem(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_CertChain *certChain) | 无权限管控 | 需要ohos.permission.ATTEST_KEY权限 |

**适配指导**

适配方式1：业务切换如下匿名化密钥证明接口，无权限管控
| 接口声明 |
| ------- |
| anonAttestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback<HuksReturnResult>): void; |
| anonAttestKeyItem(keyAlias: string, options: HuksOptions): Promise<HuksReturnResult> |
| struct OH_Huks_Result OH_Huks_AnonAttestKeyItem(const struct OH_Huks_Blob *keyAlias, const struct OH_Huks_ParamSet *paramSet, struct OH_Huks_CertChain *certChain) |

适配方式2：业务申请并配置ohos.permission.ATTEST_KEY权限

## cl.security.1  密钥管理服务获取系统版本号、使用AES-512密钥接口废弃

**访问级别**

公开接口

**废弃原因**

密钥管理服务（HUKS）在历史版本预留了获取系统版本号、使用AES 512密钥的接口，实际未实现。经评估该接口冗余，需要废弃。

**废弃影响**

该变更为非兼容性变更，需要开发者适配。

**API Level**
8

**废弃发生版本**

从OpenHarmony SDK 4.1.5.5开始。

**废弃的接口**

| 接口声明                                                     | 废弃说明                                                     | 替代接口                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| function getSdkVersion(options: HuksOptions): string; | 该接口为预留接口，实际功能未实现。             | 不涉及 |
| enum HUKS_AES_KEY_SIZE_512                           | 该接口为预留接口，实际功能未实现。                 | 不涉及          |

**适配指导**

本次修改仅废弃冗余接口，其他行为不变。
