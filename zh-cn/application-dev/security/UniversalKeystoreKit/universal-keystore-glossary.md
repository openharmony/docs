# Universal Keystore Kit术语

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

## A

### Ability Privilege Level (APL)；能力权限等级

OpenHarmony系统中用于标识应用（Ability）权限层级的机制，定义了应用可访问系统资源和API的范围。

### Abstract Syntax Notation One (ASN.1)；抽象语法标记

由ISO/ITU-T定义的描述数据结构、编码规则与传输语法的标准记法。

### Authenticated Encryption with Associated Data (AEAD)；带附加数据的认证加密

一种在加密的同时对关联数据（如协议头）进行完整性校验的对称加密模式。

## C

### Cipher Block Chaining (CBC)；密码分组链接模式

将前一组密文与当前组明文进行按位异或（XOR）后再进行分组加密的工作模式。

### Cipher-based Message Authentication Code (CMAC)；基于分组密码的消息认证码

使用对称分组密码计算的消息认证码。

### Counter with CBC-MAC (CCM)；计数器与CBC-MAC模式

结合CTR加密与CBC-MAC完整性校验的认证加密模式。

### CryptoExtensionAbility；加密扩展能力

Stage模型中ExtensionAbility的派生类，为驱动厂商提供外部密钥管理扩展能力的接口定义。开发者通过继承该类实现UKey等外部硬件密钥管理扩展，将硬件能力注册到HUKS框架中。

### Curve25519；Curve25519椭圆曲线

由Bernstein设计的高性能椭圆曲线，主要用于密钥协商。

## D

### Diffie-Hellman (DH)；迪菲-赫尔曼密钥交换

基于有限域上离散对数困难性的密钥协商协议。

### Digital Envelope；数字信封

将对称密钥与非对称加密结合的密钥保护机制：使用对称密钥加密业务密钥，再使用接收方非对称公钥加密该对称密钥形成“信封”。

### Digital Signature Algorithm (DSA)；数字签名算法

基于有限域上离散对数困难性的非对称签名算法。

## E

### Edwards-curve Digital Signature Algorithm 25519 (ED25519)；Edwards曲线25519数字签名算法

基于Edwards曲线Curve25519的高效数字签名算法。

### Elliptic Curve Cryptography (ECC)；椭圆曲线密码学

基于椭圆曲线离散对数困难性的非对称密码体系。

### Elliptic Curve Diffie-Hellman (ECDH)；椭圆曲线迪菲-赫尔曼

在椭圆曲线群上实现的DH密钥协商协议。

### ExtensionAbility；扩展组件

Stage模型中提供的组件扩展机制，允许应用在不修改主组件的前提下动态扩展能力。CryptoExtensionAbility是HUKS外部密钥管理场景下ExtensionAbility的派生形态。

## F

### Federal Information Processing Standard Publication 203 (FIPS 203)；联邦信息处理标准203

NIST于2024年发布的密钥封装标准，对应ML-KEM算法。

### Finite Field Diffie-Hellman Ephemeral (FFDHE)；有限域DH临时密钥交换

IETF在RFC 7919中标准化的一组安全素数群。

## G

### Galois/Counter Mode (GCM)；伽罗瓦/计数器模式

在CTR加密基础上结合伽罗瓦域认证的认证加密模式。

### GMT 0016-2023；GMT 0016-2023智能密码钥匙密码应用接口规范

中国国家密码管理局发布的UKey设备接口标准。

## H

### Hash-based Message Authentication Code (HMAC)；基于哈希的消息认证码

结合哈希函数与共享密钥的消息认证码算法。

### HMAC-based Key Derivation Function (HKDF)；基于HMAC的密钥派生函数

RFC 5869定义的密钥派生函数，使用HMAC作为伪随机函数。

## K

### Key Derivation Function (KDF)；密钥派生函数

使用伪随机函数从秘密值派生出一个或多个密钥的密码学原语。

## M

### Module-Lattice-Based Digital Signature Algorithm (ML-DSA)；基于模格的数字签名算法

NIST FIPS 204标准定义的后量子签名算法。

### Module-Lattice-Based Key-Encapsulation Mechanism (ML-KEM)；基于模格的密钥封装机制

NIST FIPS 203标准定义的后量子密钥封装算法。

## N

### Number Used Once (NONCE)；一次性随机数

仅使用一次的随机数值，用于保证加密或认证结果唯一性、防止重放攻击。

## O

### Optimal Asymmetric Encryption Padding (OAEP)；最优非对称加密填充

由Bellare与Rogaway提出的RSA加密填充方案，可抵抗选择密文攻击。

## P

### Password-Based Key Derivation Function 2 (PBKDF2)；基于口令的密钥派生函数2

PKCS #5标准定义的基于口令的密钥派生函数。

### Personal Identification Number (PIN)；个人识别码

用户用于解锁硬件设备的数字口令。

### Probabilistic Signature Scheme (PSS)；概率签名方案

PKCS #1 v2.1定义的RSA签名填充方案，使用随机salt提升签名随机性。

### Provider；提供者

HUKS外部密钥管理扩展机制中的注册主体。三方驱动HAP检测到UKey等外部硬件时，调用Provider注册接口将扩展能力注册到HUKS框架，使HUKS能在用户调用密钥接口时将操作转发到对应硬件。

### Public-Key Cryptography Standards #1 Version 1.5 (PKCS #1 v1.5)；公钥密码学标准#1 v1.5

RSA实验室早期定义的RSA加密与签名填充方案。

### Public-Key Cryptography Standards #7 (PKCS #7)；公钥密码学标准#7

RSA实验室定义的数据封装与签名标准。

## R

### Rivest-Shamir-Adleman (RSA)；RSA公钥密码算法

基于大整数分解困难性的非对称密码算法。

## S

### Secure Hash Algorithm (SHA)；安全散列算法

由NIST发布的密码学哈希函数系列。

### Secure Key Facility (SKF)；智能密码钥匙密码应用接口

GMT 0016-2023标准中定义的UKey设备函数接口集。

### SM2；SM2椭圆曲线公钥密码算法

中国国家密码管理局发布的基于椭圆曲线的非对称密码算法，密钥长度256比特。

### SM3；SM3密码杂凑算法

中国国家密码管理局发布的密码杂凑算法，输出长度256比特。

### SM4；SM4对称分组密码算法

中国国家密码管理局发布的对称分组密码算法，密钥长度128比特，分组长度128比特。

## T

### Trusted Application (TA)；可信应用

运行在TEE内的可信安全软件，通过TEE的隔离机制访问设备密钥与敏感数据。HUKS TA在每次启动时根据设备安全根密钥重新派生ATKEY，与UserIAM的交互也完全位于TEE环境内。

### Trusted Execution Environment (TEE)；可信执行环境

存在于移动设备主处理器中的安全区域，与普通执行环境（REE）硬件隔离。HUKS核心层必须运行在TEE内，确保明文密钥只在TEE中被访问、运算，永不泄露到REE；对于具备安全环境的设备，OEM厂商需完成适配。

## U

### Universal Keystore Kit (HUKS)；通用密钥库服务

OpenHarmony提供的密钥管理服务子系统，为业务/应用提供密钥全生命周期的统一安全操作能力，涵盖密钥生成/导入/删除/证明、加密/解密、签名/验签、密钥协商/派生/封装、访问控制等。

### USB Key (UKey)；USB密钥

基于USB接口的硬件安全设备，可存储用户私钥、证书及身份认证信息。HUKS外部密钥管理扩展通过UKey满足金融等领域浏览器双向SSL认证、签名验签等高安全场景的需求。

### User Identity Authentication Manager (UserIAM)；用户身份认证管理

OpenHarmony中负责用户身份认证（如人脸、指纹、PIN）的子系统。

## X

### X.25519；Curve25519 X25519密钥协商算法

基于Curve25519曲线的密钥协商算法，密钥长度256比特。

### X.509；X.509证书标准

ITU-T定义的公钥证书格式标准。