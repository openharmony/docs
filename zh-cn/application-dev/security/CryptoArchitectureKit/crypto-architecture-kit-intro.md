# Crypto Architecture Kit简介

Crypto Architecture Kit屏蔽了第三方密码学算法库实现差异的算法框架，提供加解密、签名验签、消息验证码、哈希、安全随机数、密钥派生等相关功能。

开发者可以通过调用加解密算法框架服务，忽略底层不同三方算法库的差异，实现迅捷开发。

## 约束与限制

- Crypto Architecture Kit不支持多线程并发操作。

- Crypto Architecture Kit当前只支持OpenSSL。

- Crypto Architecture Kit提供大部分常用算法，部分算法和规格并不适用于对安全要求高的场景，如MD5等。请开发者根据实际需求选择合适的算法。

## 能力范围

加解密算法库为开发者提供了以下相关功能，并提供了对应的算法规格说明和开发指导，请开发者参照开发。

- [密钥生成和转换](crypto-key-generation-conversion-overview.md)

- [加解密](crypto-encryption-decryption-overview.md)

- [签名验签](crypto-sign-sig-verify-overview.md)

- [密钥协商](crypto-key-agreement-overview.md)

- [消息摘要计算](crypto-generate-message-digest-overview.md)

- [消息认证码计算](crypto-compute-mac.md)

- [安全随机数生成](crypto-generate-random-number.md)

- [密钥派生](crypto-key-derivation-overview.md)

## 基本概念

在开发具体的功能前，开发者需要了解以下基本概念。

- 对称密钥
  
  加解密双方使用同一个密钥对完成数据加密、解密的操作。即数据发送方使用某个加密密钥对明文进行特殊加密算法处理后，使其变成复杂的加密密文发送出去，接收方需使用同一个密钥及相同算法的逆算法解密，才能得到原来的可读明文。

- 非对称密钥
  
  非对称密钥使用公钥和私钥两个密钥来进行算法操作，公钥对外公开，私钥对外保密。

  对于加解密操作，一般使用公钥对明文加密形成密文，持有私钥的人即可解密密文。

  对于签名验签操作，使用私钥对明文进行签名，公钥持有者可以通过公钥对签名数据做验签，验证数据是否被篡改。

## 与相关Kit的关系

加解密算法库框架仅提供密钥的密码学操作，不提供密钥管理功能。因此，使用算法库时，需要应用自己来保管密钥，适用于临时会话密钥等仅在内存中使用的场景，或者应用自己实现密钥安全存储的场景。

如果业务需要由系统提供密钥管理功能（密钥存储等），请使用[Universal Keystore Kit（密钥管理服务）](../UniversalKeystoreKit/huks-overview.md)。
