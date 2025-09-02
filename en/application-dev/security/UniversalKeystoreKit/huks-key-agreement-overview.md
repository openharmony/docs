# Key Agreement Overview and Algorithm Specifications

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

Generally, keys cannot be directly transmitted between devices. Key agreement allows two or more parties to jointly establish a shared key in a non-secure environment. During key agreement, only the public key is transmitted, and the private key is still stored on the device, which ensures data security and confidentiality.

For the key agreement between two devices, each device generates an asymmetric key and uses the public key of the peer device and its own private key to agree on a shared key.

> **NOTE**
> - <!--RP1-->The mini-system devices<!--RP1End--> do not support key agreement.
> - Using an existing key alias as the alias of the key generated from agreement will overwrite the existing key.

## Supported Algorithms

The following table lists the supported key agreement specifications.
<!--Del-->
The key management service specifications include mandatory specifications and optional specifications. Mandatory specifications are algorithm specifications that must be supported. Optional specifications can be used based on actual situation. Before using the optional specifications, refer to the documents provided by the vendor to ensure that the specifications are supported.

**You are advised to use mandatory specifications in your development for compatibility purposes.**
<!--DelEnd-->

| Algorithm| Description| API Level| <!--DelCol4-->Mandatory|
| -------- | -------- | -------- | -------- |
| ECDH | The key type must be ECC.| 8+ | Yes|
| DH | - | 8+ | Yes|
| X25519 | - | 8+ | Yes|
