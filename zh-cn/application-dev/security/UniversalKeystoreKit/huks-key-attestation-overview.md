# 密钥证明介绍及算法规格

HUKS为密钥提供合法性证明能力，主要应用于非对称密钥的公钥的证明。

基于PKI证书链技术，HUKS可以为存储在HUKS中的非对称密钥对的公钥签发证书，证明其公钥的合法性。业务可以通过系统提供的根CA证书，逐级验证HUKS签发的密钥证明证书，来确保证书中的公钥以及对应的私钥，确实来自合法的硬件设备，且存储管理在HUKS中。

> **说明：**
> 1. 当调用方为系统服务且APL等级为normal时，暂不支持密钥证明，此种情况下，processName与APL字段将置空。
> 2. 密钥证明功能在模拟器场景不支持。
> 3. 轻量级设备不支持密钥证明功能。
> 4. 支持生成密钥和导入密钥进行密钥证明，业务方在服务器侧需要通过业务证书中的密钥来源字段校验密钥来源是否符合预期。   

密钥证明扩展域段为Asn.1 DER标准编码格式，数据结构定义如下：
```
KeyAttestation ::= SEQUENCE {
  version            AttestationVersion DEFAULT v1,
  claim1             AttestationClaim,
  claim2             AttestationClaim,
  claim3             AttestationClaim,
  ... ...
}
AttestationVersion ::= INTEGER { v1(0) }
AttestationClaim ::= SEQUENCE {
  securityLevel      SecurityLevel,
  type               AttestationType,
  value              AttestationValue
}
SecurityLevel ::= INTEGER
AttestationType ::= OBJECT IDENTIFIER
AttestationValue ::= ANY -- DEFINED BY AttestationType
ApplicationIDType ::= SEQUENCE {
  type               OBJECT IDENTIFIER,
  value              OCT_STR
}
```

常用AttestationClaim类型取值说明：
| type（OID）取值 | value的数据类型 | securityLevel | Claim说明 |
| -------- | -------- | -------- | -------- | 
| 1.3.6.1.4.1.2011.2.376.2.1.4 | OCT_STR | 保留字段，暂不使用 | 应用输入的挑战值Challenge。 |
| 1.3.6.1.4.1.2011.2.376.2.1.3 | ApplicationIDType | 保留字段，暂不使用 | 应用ID。 |
| 1.3.6.1.4.1.2011.2.376.2.1.5 | OCT_STR | 保留字段，暂不使用 | 密钥来源，生成或者导入。 |
|<!--DelRow--> 1.3.6.1.4.1.2011.2.376.2.1.2 | OCT_STR | 保留字段，暂不使用 | 密钥别名。 |
| 1.3.6.1.4.1.2011.2.376.2.2.4.8 | UTF8_STR | 保留字段，暂不使用 | 产品型号Model。从API 20开始支持。 |

<!--Del-->
> **说明：**
> OEM厂商可基于实际情况决定某些字段是否实现。
<!--DelEnd-->

ApplicationIDType类型取值说明：
| type（OID）取值 | value取值说明 |
| -------- | -------- |
| 1.3.6.1.4.1.2011.2.376.2.1.3.1 | 样例：{appId:"xxx", bundleName:"xxx", appIdentifier:"xxx", appMode:"xxx"}<br>其中appIdentifier、appMode从API 20开始支持。 |
| 1.3.6.1.4.1.2011.2.376.2.1.3.2 | 样例：{processName:"xxx", APL:"system_basic \| system_core"} <br>APL为[系统服务等级](../../security/AccessToken/app-permission-mgmt-overview.md#权限机制中的基本概念)。|

密钥证明过程如下：

1. 业务将指定密钥别名和需要证明的密钥属性的标签传入HUKS。

2. 调用HUKS为应用生成一个依次由根CA证书、设备CA证书、设备证书、密钥证书组成的X.509证书链。

3. 将证书链传输至受信任的服务器，并在服务器上解析和验证证书链的有效性和单个证书是否吊销。

<!--RP2-->
当前提供了两种密钥证明方式。
- 匿名密钥证明：不会泄露设备信息，没有权限管理。面向所有应用开放。为了保护用户设备信息，三方应用开发者只能使用匿名密钥证明。
- 非匿名密钥证明：可以看到调用方设备信息，有权限管控，需申请[ohos.permission.ATTEST_KEY](../AccessToken/permissions-for-system-apps.md#ohospermissionattest_key)权限。
<!--RP2End-->

当前模拟器<!--Del-->和开发板<!--DelEnd-->支持匿名证书，调试环境中使用的证书非真实设备证书，云侧需要区分该场景，避免误用。

## 支持的算法

以下为密钥证明支持的规格说明。
<!--Del-->
面向OpenHarmony的厂商适配密钥管理服务规格分为必选规格和可选规格。必选规格为所有厂商均支持的算法规格。而对于可选规格，厂商将基于实际情况决定是否实现，如需使用，请查阅具体厂商提供的说明，确保规格支持再使用。

**建议开发者使用必选规格开发应用，可保证全平台兼容。**
<!--DelEnd-->

<!--Del-->
**匿名密钥证明：**
<!--DelEnd-->

| 算法 | 备注 | API级别 | <!--DelCol4-->是否必选规格 |
| -------- | -------- | -------- | -------- |
| RSA | 支持Padding为PSS与PKCS1_V1_5的密钥 | 11+ | 是 |
| ECC | - | 11+ | 是 |
| X25519 | - | 16+ | 是 |
| ED25519 | - | 16+ | 是 |
| SM2 | - | 11+ | 是 |

<!--Del-->
**非匿名密钥证明：**

| 算法 | 备注 | API级别 | 是否必选规格 |
| -------- | -------- | -------- | -------- |
| RSA | 支持Padding为PSS与PKCS1_V1_5的密钥 | 8+ | 是 |
| ECC | - | 8+ | 是 |
| X25519 | - | 8+ | 是 |
| ED25519 | - | 16+ | 是 |
| SM2 | - | 8+ | 是 |
<!--DelEnd-->
