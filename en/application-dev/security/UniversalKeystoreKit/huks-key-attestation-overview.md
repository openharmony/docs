# Key Attestation Overview and Algorithm Specifications

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

HUKS provides attestation for the public keys of asymmetric key pairs.

HUKS issues a certificate for the public key of an asymmetric key pair stored in HUKS using the public key infrastructure (PKI) certificate chain technology. The certificate can prove the validity of the public key. The service can use the root CA certificate provided by the system to verify the key certificates issued by HUKS level by level to ensure that the public key and private key in the certificates are from a trusted hardware device and stored in HUKS.

> **NOTE**
> 1. Key attestation is not supported if the caller is a system service with APL of **normal**. In this case, **processName** and **APL** are left empty.
> 2. Key attestation is not supported in Emulator scenarios.
> 3. <!--RP1-->Mini-system devices<!--RP1End--> do not support key attestation.
> 4. Key attestation is available to both the keys generated and imported. The service side needs to check whether the key source meets the expectation based on the key source field in the service certificate on the server.

The **Extensions** field is in the ASN.1 DER encoding format. The data structure is defined as follows:
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

**AttestationClaim** types and values:
| type (OID)| Data Type of value| securityLevel | Claim Description|
| -------- | -------- | -------- | -------- | 
| 1.3.6.1.4.1.2011.2.376.2.1.4 | OCT_STR | Reserved.| Challenge passed in by the application.|
| 1.3.6.1.4.1.2011.2.376.2.1.3 | ApplicationIDType | Reserved.| Application ID.|
| 1.3.6.1.4.1.2011.2.376.2.1.5 | OCT_STR | Reserved.| Key source, which is generated or imported.|
|<!--DelRow--> 1.3.6.1.4.1.2011.2.376.2.1.2 | OCT_STR | Reserved.| Key alias.|
| 1.3.6.1.4.1.2011.2.376.2.2.4.8 | UTF8_STR | Reserved.| Product model, supported since API version 20.|

<!--Del-->
> **NOTE**
> OEMs can decide whether to implement these fields based on their needs.
<!--DelEnd-->

ApplicationIDType types and values:
| type (OID)| value|
| -------- | -------- |
| 1.3.6.1.4.1.2011.2.376.2.1.3.1 | Example: {appId:"xxx", bundleName:"xxx", appIdentifier:"xxx", appMode:"xxx"},<br>where **appIdentifier** and **appMode** are supported since API version 20.|
| 1.3.6.1.4.1.2011.2.376.2.1.3.2 | Example: {processName:"xxx", APL:"system_basic \| system_core"} <br>APL is [Ability Privilege Level](../../security/AccessToken/app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism).|

The key attestation process is as follows:

1. The service transfers the key alias and properties to HUKS.

2. HUKS issues an X.509 certificate chain, which consists of the root CA certificate, device CA certificate, device certificate, and key certificate in sequence, for the application.

3. The certificate chain is sent to a trusted server. The server parses the certificate chain and verifies the certificate chain validity and whether a single certificate is revoked.

<!--RP2-->
Currently, the system provides two key attestation modes.
- Anonymous key attestation: This type of attestation will not disclose the device information, and the caller does not require any permission. Anonymous key attestation is available to all applications. To protect user device information, third-party applications can use anonymous attestation only.
- Non-anonymous key attestation: The device information of the caller can be viewed, and the caller must have the [ohos.permission.ATTEST_KEY](../AccessToken/permissions-for-system-apps.md#ohospermissionattest_key) permission.
<!--RP2End-->

Currently, emulators <!--Del-->and developer boards <!--DelEnd-->support anonymous certificates. The certificate used in the debugging environment is not a real device certificate. You need to note this in cloud scenarios and avoid misuse.

## Supported Algorithms

The following table lists the supported key attestation specifications.
<!--Del-->
The key management service specifications include mandatory specifications and optional specifications. Mandatory specifications are algorithm specifications that must be supported. Optional specifications can be used based on actual situation. Before using the optional specifications, refer to the documents provided by the vendor to ensure that the specifications are supported.

**You are advised to use mandatory specifications in your development for compatibility purposes.**
<!--DelEnd-->

<!--Del-->
**Anonymous key attestation**
<!--DelEnd-->

| Algorithm| Description| API Version| <!--DelCol4-->Mandatory|
| -------- | -------- | -------- | -------- |
| RSA | The padding mode can be PSS or PKCS1_V1_5.| 11+ | Yes|
| ECC | - | 11+ | Yes|
| X25519 | - | 16+ | Yes|
| ED25519 | - | 16+ | Yes|
| SM2 | - | 11+ | Yes|

<!--Del-->
**Non-anonymous key attestation**

| Algorithm| Description| API Version| Mandatory|
| -------- | -------- | -------- | -------- |
| RSA | The padding mode can be PSS or PKCS1_V1_5.| 8+ | Yes|
| ECC | - | 8+ | Yes|
| X25519 | - | 8+ | Yes|
| ED25519 | - | 16+ | Yes|
| SM2 | - | 8+ | Yes|
<!--DelEnd-->
