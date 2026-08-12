# Universal Keystore Kit（密钥管理服务）

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

- [Universal Keystore Kit简介](huks-overview.md)
- 本地密钥管理<!--huks-local-key-management-->
  - [本地密钥管理基础概念](huks-concepts.md)
  - 密钥生成/导入<!--huks-key-generation-import-->
    - 密钥生成<!--huks-key-generation-->
      - [密钥生成介绍及算法规格](huks-key-generation-overview.md)
      - [生成密钥(ArkTS)](huks-key-generation-arkts.md)
      - [生成密钥(C/C++)](huks-key-generation-ndk.md)
    - 密钥导入<!--huks-key-import-->
      - [密钥导入介绍及算法规格](huks-key-import-overview.md)
      - [明文导入密钥(ArkTS)](huks-import-key-in-plaintext-arkts.md)
      - [明文导入密钥(C/C++)](huks-import-key-in-plaintext-ndk.md)
      - [安全导入密钥(ArkTS)](huks-import-wrapped-key-arkts.md)
      - [安全导入密钥(C/C++)](huks-import-wrapped-key-ndk.md)
      - [数字信封导入密钥(ArkTS)](huks-import-envelop-key-arkts.md)
      - [数字信封导入密钥(C/C++)](huks-import-envelop-key-ndk.md)
  - 密钥使用<!--huks-key-use-->
    - [密钥使用介绍及通用流程](huks-key-use-overview.md)
    - 加密/解密<!--huks-encryption-decryption-->
      - [加密/解密介绍及算法规格](huks-encryption-decryption-overview.md)
      - [加解密(ArkTS)](huks-encryption-decryption-arkts.md)
      - [加解密(C/C++)](huks-encryption-decryption-ndk.md)
    - 签名/验签<!--huks-signing-signature-verification-->
      - [签名/验签介绍及算法规格](huks-signing-signature-verification-overview.md)
      - [签名/验签(ArkTS)](huks-signing-signature-verification-arkts.md)
      - [签名/验签(C/C++)](huks-signing-signature-verification-ndk.md)
    - 密钥协商<!--huks-key-agreement-->
      - [密钥协商介绍及算法规格](huks-key-agreement-overview.md)
      - [密钥协商(ArkTS)](huks-key-agreement-arkts.md)
      - [密钥协商(C/C++)](huks-key-agreement-ndk.md)
    - 密钥封装<!--huks-kem-->
      - [密钥封装机制介绍及算法规格](huks-kem-overview.md)
      - [密钥封装(ArkTS)](huks-kem-arkts.md)
    - 密钥派生<!--huks-key-derivation-->
      - [密钥派生介绍及算法规格](huks-key-derivation-overview.md)
      - [密钥派生(ArkTS)](huks-key-derivation-arkts.md)
      - [密钥派生(C/C++)](huks-key-derivation-ndk.md)
    - 访问控制<!--huks-identity-authentication-->
      - [用户身份认证访问控制简介](huks-identity-authentication-overview.md)
      - [用户身份认证访问控制开发指导](huks-user-identity-authentication.md)
      - [细粒度用户身份认证访问控制开发指导](huks-refined-user-identity-authentication.md)
    - HMAC<!--huks-hmac-->
      - [HMAC介绍及算法规格](huks-hmac-overview.md)
      - [HMAC(ArkTS)](huks-hmac-arkts.md)
      - [HMAC(C/C++)](huks-hmac-ndk.md)<!--RP1--><!--RP1End-->
  - 密钥删除<!--huks-delete-key-->
    - [密钥删除(ArkTS)](huks-delete-key-arkts.md)
    - [密钥删除(C/C++)](huks-delete-key-ndk.md)
  - 密钥证明<!--huks-key-attestation-->
    - [密钥证明介绍及算法规格](huks-key-attestation-overview.md)
    - [匿名密钥证明(ArkTS)](huks-key-anon-attestation-arkts.md)
    - [匿名密钥证明(C/C++)](huks-key-anon-attestation-ndk.md)
    - [离线匿名密钥证明(ArkTS)](huks-offline-anon-attestation-arkts.md)<!--RP3--><!--RP3End-->
    <!--Del-->
    - [非匿名密钥证明(仅对系统应用开放)(ArkTS)](huks-key-attestation-arkts-sys.md)
    - [非匿名密钥证明(仅对系统应用开放)(C/C++)](huks-key-attestation-ndk-sys.md)
    <!--DelEnd-->
  - 其他操作<!--huks-other-operations-->
    - 查询密钥是否存在<!--huks-check-key-->
      - [查询密钥是否存在(ArkTS)](huks-check-key-arkts.md)
      - [查询密钥是否存在(C/C++)](huks-check-key-ndk.md)
    - 获取密钥属性<!--huks-obtain-key-properties-->
      - [获取密钥属性(ArkTS)](huks-obtain-key-properties-arkts.md)
      - [获取密钥属性(C/C++)](huks-obtain-key-properties-ndk.md)
    - 密钥导出<!--huks-export-key-->
      - [密钥导出(ArkTS)](huks-export-key-arkts.md)
      - [密钥导出(C/C++)](huks-export-key-ndk.md)
    - 查询密钥别名集<!--huks-list-aliases-->
      - [查询密钥别名集(ArkTS)](huks-list-aliases-arkts.md)
      - [查询密钥别名集(C/C++)](huks-list-aliases-ndk.md)<!--RP2--><!--RP2End-->
    - 群组密钥<!--huks-group-key-->
      - [群组密钥介绍](huks-group-key-overview.md)
      - [群组密钥(ArkTS)](huks-group-key-arkts.md)
      - [群组密钥(C/C++)](huks-group-key-ndk.md)
    <!--Del-->
    - [指定用户身份操作（仅对系统应用开放）](huks-as-user-sys.md)
    <!--DelEnd-->
- 外部密钥管理扩展<!--huks-external-key-management-->
  - [外部密钥管理扩展简介](huks-external-hardware-key-management-overview.md)
  - Provider管理<!--huks-provider-management-->
    - [Provider管理介绍及规格](huks-provider-management-overview.md)
    - [注册/注销Provider(ArkTS)](huks-extension-registration-and-unregistration-arkts.md)
    - [注册/注销Provider(C/C++)](huks-extension-registration-and-unregistration-ndk.md)
  - 资源管理<!--huks-resource-management-->
    - [资源管理介绍及规格](huks-resource-management-overview.md)
    - [获取资源ID(ArkTS)](huks-extension-get-resource-id-arkts.md)
    - [打开资源/关闭资源(ArkTS)](huks-open-close-resource-arkts.md)
    - [打开资源/关闭资源(C/C++)](huks-open-close-resource-ndk.md)
  - 密钥管理<!--huks-extension-key-management-->
    - [密钥生成与导入导出介绍](huks-extension-key-generation-import-overview.md)
    - [密钥生成(ArkTS)](huks-extension-key-generation-arkts.md)
    - [密钥导入(ArkTS)](huks-extension-key-import-arkts.md)
    - [公钥导出(ArkTS)](huks-extension-key-export-arkts.md)
  - UKeyPIN码认证管理<!--huks-ukey-pin-authentication-management-->
    - [UKey PIN码认证介绍及规格](huks-ukey-pin-authentication-management-overview.md)
    <!--Del-->
    - [UKey PIN码认证(ArkTS)](huks-ukey-pin-authentication-arkts-sys.md)
    <!--DelEnd-->
    - [查询认证状态(ArkTS)](huks-query-authentication-status-arkts.md)
    - [查询认证状态(C/C++)](huks-query-authentication-status-ndk.md)
    - [清除UKey PIN码认证状态(ArkTS)](huks-clear-pin-auth-state-arkts.md)
  - 签名/验签<!--huks-ukey-signing-signature-verification-->
    - [签名/验签介绍及算法规格](huks-ukey-signing-signature-verification-overview.md)
    - [签名/验签(ArkTS)](huks-ukey-signing-signature-verification-arkts.md)
    - [签名/验签(C/C++)](huks-ukey-signing-signature-verification-ndk.md)
  - 通用操作<!--huks-ukey-general-operation-->
    - [通用查询介绍及规格](huks-ukey-general-query-overview.md)
    - [通用查询(ArkTS)](huks-ukey-general-query-arkts.md)
    - [通用查询(C/C++)](huks-ukey-general-query-ndk.md)
    - [属性设置(ArkTS)](huks-extension-set-property-arkts.md)
    - [获取错误信息(ArkTS)](huks-ukey-get-error-info-arkts.md)
  - [UKey流程示例指导](huks-ukey-best-dev.md)
  - 驱动HAP ExtensionAbility适配指导<!--huks-extension-ability-support-->
    - [CryptoExtensionAbility扩展能力介绍](huks-extension-ability-support-overview.md)
    - [CryptoExtensionAbility适配开发指导](huks-extension-ability-support-dev.md)<!--RP4--><!--RP4End-->
- [Universal Keystore Kit术语](universal-keystore-glossary.md)