# Crypto Architecture Kit术语

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

## A

### AES Advanced Encryption Standard；高级加密标准

最常见的对称加密算法，属于分组密码算法。分组长度为128位，密钥长度为128位、192位或256位，与3DES相比安全性更高、处理速度更快，用于保证数据存储或传输场景下的机密性。支持ECB、CBC、OFB、CFB、CTR、GCM、CCM、XTS等多种加密模式。

### AES-WRAP；基于AES的密钥封装算法

一种基于AES的密钥封装加密算法，用于安全地存储或传输对称密钥。其主要目的是通过加密保护密钥，防止密钥在存储或传输过程中被泄露或篡改。

### Asymmetric Key；非对称密钥

使用公钥和私钥两个密钥进行算法操作的密钥体制，公钥对外公开，私钥对外保密。加解密时一般使用公钥加密、私钥解密；签名验签时使用私钥签名、公钥验签，从而验证数据是否被篡改及数据来源。

## B

### Block Cipher；分组密码

将明文分成固定长度的数据块、对每个块分别进行加密操作的对称加密算法。AES、DES、3DES、SM4、RC2、Blowfish、CAST等均为分组密码。当最后一组明文不足分组长度时，需通过填充模式补足。

### Blowfish；分组密码算法

一种分组密码算法，分组长度为64位（8字节），密钥长度支持32位～448位（须为8的倍数），支持ECB、CBC、OFB、CFB等分组模式。

## C

### CAST；分组密码算法

分组密码算法（如CAST-128/CAST5），分组长度为64位（8字节），密钥长度支持40位～128位（须为8的倍数），支持ECB、CBC、OFB、CFB等分组模式。

### ChaCha20；流密码算法

一种现代化的流密码对称加密算法，密钥长度为256位，无需填充。支持默认模式（需传入IV）与Poly1305模式。

### CMAC Cipher-based Message Authentication Code；基于密码的消息认证码

一种基于分组密码（如AES）和密钥生成消息认证码的算法，用于确保消息的完整性和真实性，识别信息在传输过程中的篡改行为。

### Compressed/Uncompressed Point Format；压缩/非压缩点格式

椭圆曲线公钥点的两种编码格式。非压缩格式保存x、y两个坐标，压缩格式仅保存x坐标和一个标志位。ECC、SM2公钥与点数据可在压缩与非压缩格式之间相互转换。

## D

### DES Data Encryption Standard；数据加密标准

一种分组加密算法，将明文分成64位的块进行加密，加密过程包含16轮相同的加密函数，每轮使用由原始密钥经置换和移位生成的子密钥，密钥长度为64位。

### DH Diffie-Hellman Key Exchange Diffie-Hellman；密钥交换

一种密钥协商算法，只涉及公钥的交换，可提供前向安全性，即使在通信渠道被监听的情况下也不会暴露双方私钥。支持modp、ffdhe等知名安全素数群。

### DSA Digital Signature Algorithm；数字签名算法

一种基于模运算和整数有限域离散对数难题的公钥密码算法，常用于数字签名和验签，不能用于加解密。

## E

### ECC Elliptic Curve Cryptography；椭圆曲线密码

一种基于椭圆曲线数学的公钥密码算法，可看作定义在特殊集合下数的运算。当前算法库支持的ECC密钥均为Fp域（素数域）的椭圆曲线。

### ECDH Elliptic Curve Diffie-Hellman Key Exchange；椭圆曲线Diffie-Hellman密钥交换

基于椭圆曲线的Diffie-Hellman密钥协商算法。算法库提供多种椭圆曲线（如ECC224、ECC256、BrainPool系列、Secp256k1等）的ECDH能力，用于在非安全通道中协商出共享密钥。

### ECDSA Elliptic Curve Digital Signature Algorithm；椭圆曲线数字签名算法

基于椭圆曲线密码（ECC）的数字签名算法。相比基于离散对数问题（DLP）和大数分解问题（IFP）的公钥体制，椭圆曲线密码的单位比特强度更高，支持OnlySign/OnlyVerify模式。

### ECIES Elliptic Curve Integrated Encryption Scheme；椭圆曲线集成加密方案

一种基于椭圆曲线密码学的混合加密算法，结合密钥协商（ECC）、密钥派生（X963KDF）与对称加密（AES-GCM）完成加解密。

### Ed25519 Edwards；曲线数字签名算法

基于EdDSA算法、采用Edwards曲线实现的数字签名算法，密钥长度为256位，不支持加解密，主要用于数字签名和验证。

## H

### Hardware Entropy；硬件熵源

通过HUKS从安全环境（如TEE、安全芯片）获取的硬件随机数熵源，用于生成更具“真随机性”的安全随机数，使结果更难以被猜测或复现。

### HMAC Hash-based Message Authentication Code；基于哈希的消息认证码

一种基于哈希的消息认证码算法，以通信双方共享的密钥和消息作为输入生成固定长度的认证码，用于检验报文完整性。在消息摘要算法基础上增加了密钥输入以确保信息正确性。

### HKDF HMAC-based Extract-and-Expand Key Derivation Function；基于HMAC的提取扩展密钥派生函数

基于HMAC消息认证码的密钥派生算法，用于从较短的输入密钥派生出更长的输出密钥。包含提取（EXTRACT_ONLY）、扩展（EXPAND_ONLY）、提取和扩展（EXTRACT_AND_EXPAND）三个模式。

## K

### KDF Key Derivation Function；密钥派生函数

使用伪随机函数从秘密值中导出一个或多个密钥的函数，可用于将密钥扩展到更长的密钥或获得所需格式的密钥。

### KEM Key-Encapsulation Mechanism；密钥封装机制

用于在不安全通道上安全协商共享密钥的机制。封装方使用公钥生成共享密钥和封装密钥，解封装方使用私钥和封装密钥恢复出相同的共享密钥。

### Key Agreement；密钥协商

在非安全通道环境中，通信双方不预先共享任何秘密的情况下协商出安全共享密钥的机制，对应算法有ECDH、X25519、DH等。

## M

### MAC Message Authentication Code；消息认证码

对消息进行完整性校验的码，通过使用双方共享的密钥识别信息伪装、篡改等行为。

### MD5 Message Digest 5；消息摘要算法5

一种消息摘要算法，生成16字节（128位）固定长度摘要。安全性较低，不适用于对安全要求较高的场景。

### Message Digest；消息摘要

将任意长度消息通过哈希算法映射为固定长度摘要值的过程，又称密码学哈希。摘要长度由算法决定。

### ML-DSA Module-Lattice-Based Digital Signature Algorithm；基于模块格的数字签名算法

一种基于模块格的数字签名后量子密码算法，用于签名验签，支持ML-DSA-44、ML-DSA-65、ML-DSA-87等参数集。

### ML-KEM Module-Lattice-Based Key-Encapsulation Mechanism；基于模块格的密钥封装机制

一种基于模块格的密钥封装机制后量子密码算法，用于密钥封装解封装，支持ML-KEM-512、ML-KEM-768、ML-KEM-1024等参数集。

## P

### PBKDF2 Password-Based Key Derivation Function 2；基于密码的密钥派生函数2

PKCS系列标准之一、具有可变计算成本的密钥派生函数，将伪随机函数（如基于哈希的HMAC）输入密码明文和盐值、重复多次运算来进行密钥派生。

### PKCS1 Public-Key Cryptography Standards 1；公钥密码标准1

一种填充模式，是 RSA 加密/签名的填充标准。RFC3447规范中的RSAES-PKCS1-V1_5模式，对应OpenSSL中的RSA_PKCS1_PADDING。

### PKCS5 Public-Key Cryptography Standards 5；公钥密码标准5

一种填充模式，填充字符由一个字节序列组成，每个字节填充的值与要填充的字节序列长度相同。

### PKCS7 Public-Key Cryptography Standards 7；公钥密码标准7

一种填充模式，填充方法与PKCS5一致，但可在1-255字节之间任意填充，常以分组大小作为填充长度。

### Poly1305；消息认证码算法

ChaCha20的一种加密模式，加解密时需传入Poly1305ParamsSpec参数，加密后从结果末尾取16字节作为解密时的认证信息（authTag）。

### PSS Probabilistic Signature Scheme；概率签名方案

RFC3447规范中的RSASSA-PSS模式，对应OpenSSL中的RSA_PKCS1_PSS_PADDING，PSS 是 RSA 签名的概率性填充方案，需设置两个摘要（md和mgf1_md）并可设置盐值长度。

## R

### RC2；分组密码算法

一种分组密码算法，分组长度为64位（8字节），密钥长度支持8位～1024位（须为8的倍数），支持ECB、CBC、OFB、CFB分组模式。

### RC4；流密码算法

一种流密码算法，无需分组与填充，密钥长度支持8位～4096位（须为8的倍数）。

### Random Seed；随机种子

用来对伪随机数生成器内部状态进行初始化的数据，生成器通过种子生成一系列的随机序列。

### RIPEMD160；消息摘要算法

一种消息摘要算法，生成20字节（160位）固定长度摘要。

### RSA Rivest-Shamir-Adleman；非对称加密算法

一种非对称加密与签名验签算法，密钥规格由密钥类型与素数个数决定，支持512～8192位及2～5个素数。加解密支持NoPadding、PKCS1、PKCS1_OAEP填充模式，签名验签支持PKCS1、PSS填充模式。

## S

### scrypt；密钥派生函数

一种需要耗费大量内存和计算资源的密钥派生函数，从输入的密码和盐值生成加密密钥，主要参数包括迭代次数n、块大小r、并行性p，可根据安全需求和硬件性能调整优化。

### Secure Random Number；安全随机数

用于临时会话密钥生成和非对称加密算法密钥生成等场景的随机数，需具备随机性、不可预测性与不可重现性，满足密码学安全伪随机性要求。

### SHA Secure Hash Algorithm；安全哈希算法

一系列安全哈希摘要算法，包括SHA1、SHA224、SHA256、SHA384、SHA512等，分别生成20、28、32、48、64字节固定长度摘要。

### SHA3 Secure Hash Algorithm 3；安全哈希算法3

SHA系列摘要算法的第三代，包括SHA3-256、SHA3-384、SHA3-512等，分别生成32、48、64字节固定长度摘要。

### SM2；国密椭圆曲线公钥密码算法

一种基于椭圆曲线（Fp域）的公钥密码算法，用于非对称加解密与签名验签。加密结果由C1（椭圆曲线点）、C2（密文）、C3（摘要值）三部分组成，签名只支持SM3摘要。

### SM3；国密消息摘要算法

一种消息摘要算法，生成32字节（256位）固定长度摘要，是SM2签名默认且唯一支持的摘要算法。

### SM4；国密分组密码算法

一种分组密码算法，分组长度为128位，密钥长度为128位，加密与密钥扩展算法都采用32轮非线性迭代结构，数据解密与加密的算法结构相同，仅轮密钥使用顺序相反。

### Stream Cipher；流密码

以流方式对数据进行加密的对称算法，密文长度等于明文长度，无需填充。ChaCha20、RC4等均为流密码。

### Symmetric Key；对称密钥

加解密双方使用同一个密钥完成数据加密、解密的密钥体制，即发送方用某密钥及算法将明文加密为密文，接收方用同一密钥及相同算法的逆运算解密还原明文。

## T

### 3DES Triple Data Encryption Algorithm；三重数据加密算法

也称3DESede或TripleDES，使用3个64位的密钥对数据块进行三次加密（相当于对每个数据块执行三次DES），密钥长度更长、安全性高于DES，但处理速度不如DES。

## X

### X25519；椭圆曲线密钥交换算法

一种基于Curve25519的Diffie-Hellman密钥交换算法，用于密钥协商，密钥长度为256位。

### X963KDF；基于X9.63标准的密钥派生函数

一种基于X9.63标准的密钥派生函数，通常与椭圆曲线结合使用，用于从原始密钥材料和共享信息派生指定长度的密钥。
