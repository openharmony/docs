# 加解密算法库框架概述
加解密算法库框架是一个屏蔽了第三方密码学算法库实现差异的算法框架，提供加解密、签名验签、消息验证码、哈希、安全随机数等相关功能。开发者可以通过调用加解密算法库框架，忽略底层不同三方算法库的差异，实现迅捷开发。

> **说明：**
>
> 加解密算法库框架仅提供密钥的密码学操作，而不提供密钥管理功能。因此，使用算法库时，需要应用自己来保管密钥（适用于临时会话密钥等仅在内存中使用的场景，或者应用自己实现密钥安全存储的场景）。如果业务需要由系统提供密钥管理功能（密钥存储等），请使用[HUKS部件](huks-overview.md)。

## 框架实现原理

加解密算法库框架提供的组件分为三层：接口层，Framework层和插件层。接口层负责对外提供统一的JS接口，插件层实现针对具体三方算法库的功能，Framework层通过灵活加载插件层的插件适配并屏蔽三方算法库差异。

## 基本概念

### 对称密钥

对称密钥使用同一个密钥对数据进行加密解密操作。即对称加密算法中，数据发送方使用加密密钥对明文进行特殊加密算法处理后，使其变成复杂的加密密文发送出去。接收方收到密文后，若想解读原文，则需要使用同一个加密密钥以及相同算法的逆算法对密文进行解密，才能使其恢复成可读明文。

- **AES密钥**

  AES的全称是Advanced Encryption Standard，是最常见的对称加密。AES为分组密码，分组密码也就是把明文分成一组一组的，每组长度相等，每次加密一组数据，直到加密完整个明文。在AES标准规范中，分组长度只能是128位，也就是说，每个分组为16个字节（每个字节8位）。密钥的长度可以使用128位、192位或256位。

- **3DES密钥**

  3DES，也称为 3DESede 或 TripleDES，是三重数据加密算法，相当于是对每个数据块应用三次DES的对称加密算法，它使用3个64位的密钥对数据块进行三次加密。相比DES，3DES因密钥长度变长，安全性有所提高，但其处理速度不高。因此又出现了AES加密算法，AES较于3DES速度更快、安全性更高。

- **SM4密钥**

  SM4密码算法是一个分组算法，该算法的分组长度为128位，密钥的长度为128位。加密算法与密钥扩展算法都采用32轮非线性迭代结构，数据解密和数据加密的算法结构相同，只是轮密钥的使用顺序相反，解密轮密钥是加密轮密钥的逆序。

- **HMAC密钥**

  HMAC（Hash-based Message Authentication Code）是一种基于密钥的消息认证码算法。HMAC通过指定摘要算法，以通信双方共享密钥与消息作为输入，生成消息认证码用于检验传递报文的完整性，HMAC生成的消息认证码为固定长度。

  HMAC的密钥可以是任何长度。如果密钥的长度大于摘要算法信息分组的长度，则将密钥进行单向散列的结果作为新的密钥；如果密钥的长度小于摘要算法信息分组的长度，则将末尾填充0作为新的密钥；即最终的的密钥长度与摘要算法信息分组的长度保持一致。

### 非对称密钥

非对称密钥使用公钥和私钥两个密钥来进行算法操作，公钥对外公开，私钥对外保密。对于加解密操作，一般使用公钥对明文进行加密形成密文，持有私钥的人即可对密文解密形成明文。对于签名验签操作，使用私钥对明文进行签名，公钥持有者可以通过公钥对签名数据做验签，验证数据是否被篡改。

- **RSA密钥**

  RSA算法是由Ron Rivest、Adi Shamir和Leonard Adleman一起提出的，是一种非对称加密算法，广泛应用于现代的信息加密传输等领域。它的数学基础是大质数相乘，对其积做因式分解的计算困难性。

  RSA密钥参数，涉及三个整数，包括：

  n：模数（Modulus），是私钥和公钥的公共参数。

  sk：私钥指数（privateExponent），公式中常写作d。

  pk：公钥指数（publicExponent），公式中常写作e。

- **ECC密钥**

  ECC的全称是Elliptic Curve Cryptography，是一种基于椭圆曲线数学的公开密钥加密算法，其数学基础是利用椭圆曲线上的有理点构成Abel加法群上椭圆离散对数的计算困难性，算法库框架提供了多种椭圆曲线的ECC密钥生成能力。

  椭圆曲线算法可以看作是定义在特殊集合下数的运算，当前算法库支持的是Fp域的椭圆曲线，p为素数，Fp域也称素数域。

  Fp域下的ECC密钥参数，包括：

  p: 素数，用于确定Fp。

  a, b: 确定椭圆曲线的方程。

  g: 椭圆曲线的一个基点(base point)，可由gx，gy表示。

  n: 基点g的阶(order)。

  h: 余因子(cofactor)。

  sk: 私钥，是一个随机整数，小于n。

  pk: 公钥，是椭圆曲线上的一个点， pk = sk * g。

- **DSA密钥**

  DSA的全称是Digital Signature Algorithm，是一种基于模算数和整数有限域离散对数难题的一种公开密钥算法，不能用于加解密，一般用于数字签名和验签，算法库框架提供了多种不同长度的DSA密钥生成能力。

  DSA密钥参数，包括：

  p：一个素模数，比特长度为64的整数倍。

  q：p-1的素因子，长度与p的长度有关。

  g：g = (h ^ ((p - 1) / q)) mod p，h为满足1 < h < p -1的任意整数。

  sk：私钥，为随机生成的整数，满足0 < sk < q。

  pk：公钥，pk = (g ^ sk) mod p。

- **SM2密钥**

  SM2算法是一种基于椭圆曲线的公钥密码算法，其密钥长度为256位。SM2算法采用的是Fp域上的椭圆曲线。

  Fp域下的SM2密钥参数，包括：

  p: 大于3的素数，用于确定Fp。

  a, b: 定义椭圆曲线的方程。

  g: 椭圆曲线的一个基点(base point)，可由gx，gy表示。

  n: 基点g的阶(order)。

  h: 余因子(cofactor)。

  sk: 私钥，是一个随机整数，小于n。

  pk: 公钥，是椭圆曲线上的一个点， pk = sk * g。

### 加解密

- **对称AES加解密**

  算法库目前提供了AES加解密常用的7种加密模式：ECB、CBC、OFB、CFB、CTR、GCM和CCM。AES为分组加密算法，分组长度大小为128位。实际应用中明文最后一组可能不足128位，不足数据可以使用各种padding模式做数据填充。下文中描述了各个padding的区别：
  - NoPadding：不带填充。
  - PKCS5：填充字符由一个字节序列组成，每个字节填充该填充字节序列的长度，规定是8字节填充。
  - PKCS7：填充字符和PKCS5填充方法一致，但是可以在1-255字节之间任意填充。

  > **说明：**
  >
  > ECB、CBC加密模式，明文长度不是128位整数倍，必须使用填充方法补足。<br/>
  > 由于需要填充至分组大小，所以实际算法库中的PKCS5和PKCS7都是以分组大小作为填充长度的，即AES加密填充至16字节。

- **对称3DES加解密**

  该算法的加解密过程分别是对明文/密文数据进行三次DES加密或解密，得到相应的密文或明文。

  算法库目前提供了3DES加解密常用的4种加密模式：ECB、CBC、OFB和CFB。DES为分组加密算法，分组长度大小为64位。实际应用中明文最后一组可能不足64位，不足数据可以使用各种padding模式做数据填充。下文中描述了各个padding的区别：
  - NoPadding：不带填充。
  - PKCS5：填充字符由一个字节序列组成，每个字节填充该填充字节序列的长度，规定是8字节填充。
  - PKCS7：填充字符和PKCS5填充方法一致，但是可以在1-255字节之间任意填充。

  > **说明：**
  >
  > ECB、CBC加密模式，明文长度不是64位整数倍，必须使用填充方法补足。<br/>
  > 由于需要填充至分组大小，所以实际算法库中的PKCS5和PKCS7都是以分组大小作为填充长度的，即3DES加密填充至8字节。

- **对称SM4加解密**

  算法库目前提供了SM4加解密常用的6种加密模式：ECB、CBC、CTR、OFB、CFB和CFB128。SM4为分组加密算法，分组长度大小为128位。实际应用中明文最后一组可能不足128位，不足数据可以使用各种padding模式做数据填充。下文中描述了各个padding的区别：

  - NoPadding：不带填充。
  - PKCS5：填充字符由一个字节序列组成，每个字节填充该填充字节序列的长度，规定是8字节填充。
  - PKCS7：填充字符和PKCS5填充方法一致，但是可以在1-255字节之间任意填充。

  > **说明：**
  >
  > ECB、CBC加密模式，明文长度不是128位整数倍，必须使用填充方法补足。<br/>
  > 由于需要填充至分组大小，所以实际算法库中的PKCS5和PKCS7都是以分组大小作为填充长度的，即SM4加密填充至16字节。

- **非对称RSA加解密**

  RSA为非对称加密算法，加密长度需要在固定长度进行，实际应用中会使用各种padding模式做数据填充。算法库目前提供了RSA加解密常用的三种模式：NoPadding、PKCS1和PKCS1_OAEP。下文中描述了各个padding的区别：
  - NoPadding：不带填充，输入的数据必须与RSA钥模一样长，输出数据长度与RSA钥模一样长。
  - PKCS1：即RFC3447规范中的RSAES-PKCS1-V1_5模式（对应于OpenSSL中的RSA_PKCS1_PADDING）在进行RSA运算时需要将源数据D转化为Encryption block（EB），加密时，输入的数据最大长度 <= RSA钥模 - 11，输出数据长度与RSA钥模一样长。
  - PKCS1_OAEP：即RFC3447规范中的RSAES-OAEP模式（对应于OpenSSL中的RSA_PKCS1_OAEP_PADDING），是PKCS#1推出的新填充方式，此模式需要设置两个摘要（md和mgf1_md），加密时，输入的数据必须小于RSA钥模 - md摘要长度 - mgf1_md摘要长度 - 2（摘要长度以字节为单位），输出数据长度与RSA钥模一样长；此模式还可额外设置pSource字节流，来定义OAEP填充的编码输入P，并且可以获取PKCS1_OAEP的相关参数。<br><br>
  PKCS1_OAEP的相关参数包括：<br>
  md: 摘要算法。<br>
  mgf: 掩码生成算法，目前仅支持MGF1。<br>
  mgf1_md: mgf1摘要算法。<br>
  pSource: 字节流，用于编码输入。

  > **说明：**
  >
  > RSA钥模 = (RSA的bits + 7) / 8

- **非对称SM2加解密**

  SM2为非对称加密算法，是国家密码管理局发布的椭圆曲线公钥密码算法，加密长度在固定长度进行。算法库目前支持以C1C3C2格式输出加密数据，支持对C1C3C2格式的输入数据进行解密。

### 签名验签

- **RSA签名验签**

  算法库框架目前提供了两种RSA签名验签的padding模式：PKCS1和PSS。下面对两种模式做详细描述：
  - PKCS1: 即RFC3447规范中的RSASSA-PKCS1-V1_5模式（对应于OpenSSL中的RSA_PKCS1_PADDING），在签名验签时，使用该模式时需要设置摘要（md），摘要算法输出的长度（字节）需要小于RSA的钥模。
  - PSS: 即RFC3447规范中的RSASSA-PSS模式（对应于OpenSSL中的RSA_PKCS1_PSS_PADDING），此模式需要设置两个摘要（md和mgf1_md），且md和mgf1_md长度之和（字节）需要小于RSA的钥模；此模式还可额外设置以字节为单位的盐长度(saltLen)，并且可以获取PSS的相关参数。<br><br>
  PSS的相关参数包括：<br>
  md: 摘要算法。<br>
  mgf: 掩码生成算法，目前仅支持MGF1。<br>
  mgf1_md: MGF1算法中使用的摘要算法。<br>
  saltLen: 盐长度，以字节为单位。<br>
  trailer_field：用于编码操作的整数，其值只支持为1。

  > **说明：**
  >
  > RSA钥模 = (RSA的bits + 7) / 8

- **ECDSA**

  椭圆曲线数字签名算法（ECDSA）是基于椭圆曲线密码（ECC）的数字签名算法（DSA）。相比普通的离散对数问题（DLP）和大数分解问题（IFP），椭圆曲线密码的单位比特强度要高于其他公钥体制。算法库框架提供了多种椭圆曲线及摘要算法组合的椭圆曲线数字签名算法（ECDSA）能力。

- **DSA**

  数字签名算法（DSA）的安全性基于整数有限域离散对数问题的困难性，这类签名标准具有较大的兼容性和适用性。

- **SM2**

  数字签名算法（SM2）是基于椭圆曲线的算法，由国家密码管理局发布。


### 密钥协商

- **ECDH**

  ECDH的全称是椭圆曲线迪菲-赫尔曼秘钥交换，是用来在一个非安全通道中建立起安全的共有加密资料，交换双方可以在不共享任何秘密的情况下协商出一个密钥。算法库框架基于开源算法库提供了多种椭圆曲线的ECDH能力。

### 摘要

消息摘要算法是一种能将任意长度的输入消息，通过哈希算法生成长度固定的摘要的算法。消息摘要算法通过其不可逆的特性能被用于敏感信息的加密。消息摘要算法也被称为哈希算法或单向散列算法。
在摘要算法相同时，生成的摘要值主要有下列特点：

- 当输入消息相同时，生成摘要序列相同。
- 当输入消息的长度不一致时，生成摘要序列长度固定（摘要长度由算法决定）。
- 当输入消息不一致时，生成摘要序列几乎不会相同（依然存在相同概率，由摘要长度决定相同概率）。

### 消息验证码

HMAC（Hash-based Message Authentication Code）是一种基于密钥的消息认证码算法。HMAC通过指定摘要算法，以通信双方共享密钥与消息作为输入，生成消息认证码用于检验传递报文的完整性，HMAC生成的消息认证码为固定长度。HMAC在消息摘要算法的基础上增加了密钥的输入，确保了信息的正确性。

### 随机数

随机数在加解密过程中主要用于临时会话密钥的生成与非对称加密算法中密钥的生成。随机数由硬件生成的硬件随机数生成器或由软件生成的伪随机数生成器进行生成。在加解密的场景中，安全随机数生成器需要具备随机性，不可预测性，与不可重现性。密码学安全伪随机数生成器CSPRNG（Cryptography Secure Random Number Generators）生成的随机数满足密码学安全伪随机性。

- **内部状态**代表随机数生成器内存中的数值，当内部状态相同时，随机数生成器会生成固定的随机数序列。
- **种子**（seed）是一个用来对伪随机数的内部状态进行初始化的数据，随机数生成器通过种子来生成一系列的随机序列。

### 密钥派生函数

密钥派生函数（key derivation function）是指使用伪随机函数从秘密值（如主密钥）中导出一个或多个密钥。密钥派生函数可用于将密钥扩展到更长的密钥或获得所需格式的密钥。

- **PBKDF2**

PBKDF（Password-Based Key Derivation Function）是具有可变计算成本的密钥派生函数；PBKDF2是PKCS系列的标准之一，在RFC 2898中发布其规格。PBKDF2是将伪随机函数PRF（pseudorandom function），比如基于散列的HMAC，与盐值一同应用与输入的密码中，并多次重复该过程以生成派生密钥。

PBKDF2密钥派生函数的相关参数包括：

PRF：伪随机函数，如HMAC。

password：主密码，用于派生。

salt：盐值。

iterations: 迭代次数。

keySize：派生得到的密钥字节长度。

## 约束与限制

- 算法库框架不支持多线程并发操作。
- 算法库当前只支持OpenSSL。
- 使用密钥参数生成密钥时，用到的bigint类型需要以大端的形式输入，且必须为正数。
- 加解密算法库提供常用算法，其中有部分算法和规格并不适用于安全场景，如MD5等，用户需要根据使用需求选择适合的算法。

## 密钥生成规格

密钥生成有两种指定规格的方式：字符串参数 / 密钥参数。
- 字符串参数：以字符串的形式描述用户想要生成的密钥规格。
- 密钥参数：使用密钥的详细密码学信息，构造密钥对象。

### AES密钥生成规格

- 支持以字符串参数来生成AES密钥，其生成参数如下表所示：

  |对称密钥算法|密钥长度（bit）|字符串参数|
  |---|---|---|
  |AES|128|AES128|
  |AES|192|AES192|
  |AES|256|AES256|

  > **说明：**
  >
  > “字符串参数”是“对称密钥算法”和“密钥长度”拼接而成，用于在创建对称密钥生成器时，指定密钥规格。

### 3DES密钥生成规格

- 支持以字符串参数来生成3DES密钥，其生成参数如下表所示：

  |对称密钥算法|密钥长度（bit）|字符串参数|
  |---|---|---|
  |3DES|192|3DES192|

  > **说明：**
  >
  > “字符串参数”是“对称密钥算法”和“密钥长度”拼接而成，用于在创建对称密钥生成器时，指定密钥规格。

### RSA密钥生成规格

  > **说明：**
  >
  > 从API version 10开始， 支持使用密钥参数来生成RSA密钥。

- 支持以字符串参数来生成RSA密钥，其生成参数如下表所示：

  |RSA密钥类型|素数个数|字符串参数|
  |---|---|---|
  |RSA512|2|RSA512\|PRIMES_2|
  |RSA768|2|RSA768\|PRIMES_2|
  |RSA1024|2|RSA1024\|PRIMES_2|
  |RSA1024|3|RSA1024\|PRIMES_3|
  |RSA2048|2|RSA2048\|PRIMES_2|
  |RSA2048|3|RSA2048\|PRIMES_3|
  |RSA3072|2|RSA3072\|PRIMES_2|
  |RSA3072|3|RSA3072\|PRIMES_3|
  |RSA4096|2|RSA4096\|PRIMES_2|
  |RSA4096|3|RSA4096\|PRIMES_3|
  |RSA4096|4|RSA4096\|PRIMES_4|
  |RSA8192|2|RSA8192\|PRIMES_2|
  |RSA8192|3|RSA8192\|PRIMES_3|
  |RSA8192|4|RSA8192\|PRIMES_4|
  |RSA8192|5|RSA8192\|PRIMES_5|

  > **说明：**
  >
  > “字符串参数”是“RSA密钥类型”和“素数个数”拼接而成，用于在创建非对称密钥生成器时，指定密钥规格。生成RSA非对称密钥时，默认素数为2，PRIMES_2参数可省略。

- 支持以密钥参数来生成RSA密钥，其密钥参数种类和各个密钥参数的密码学规格要求如下表所示：

  |   |公共参数|公钥参数|私钥参数|公私钥对参数|
  |---|---------|---|---|---|
  |n    |×    |√    |×    |√   |
  |pk|    |√    |    |√    |
  |sk|    |    |×    |√    |

  > **说明：**
  >
  > 密钥参数用于在创建非对称密钥生成器时，指定密钥规格。</br>
  > 上表说明了算法库对于指定公/私钥参数生成RSA密钥的支持情况。</br>
    打√的表示需要指定这一列中的具体属性，来构成密钥参数。</br>
    打×的表示这一列中的具体属性对应于某种密钥参数，但是算法库当前不支持通过该密钥参数生成密钥。

  > **注意：**
  >
  > 1. RSA不支持通过指定公共参数（n）来随机生成密钥。
  > 2. RSA不支持通过指定私钥参数（n, sk）来生成私钥。

### ECC密钥生成规格

  > **说明：**
  >
  > 从API version 10开始， 支持使用密钥参数来生成ECC密钥。

- 支持以字符串参数来生成ECC密钥，其生成参数如下表所示：

  |非对称密钥算法|密钥长度（bit）|曲线名|字符串参数|
  |---|---|---|---|
  |ECC|224|NID_secp224r1|ECC224|
  |ECC|256|NID_X9_62_prime256v1|ECC256|
  |ECC|384|NID_secp384r1|ECC384|
  |ECC|521|NID_secp521r1|ECC521|

  > **说明：**
  >
  > “字符串参数”是“非对称密钥算法”和“密钥长度”拼接而成，用于在创建非对称密钥生成器时，指定密钥规格。</br>
  > 当前支持的ECC均为Fp域曲线。

- 支持以密钥参数来生成ECC密钥，其密钥参数种类和各个密钥参数的密码学规格要求如下表所示：
  |   |公共参数|公钥参数|私钥参数|公私钥对参数|
  |---|---|---|---|---|
  |fieldType|    √|    √|    √|    √|
  |p    |    √|    √|    √|    √|
  |a    |    √|    √|    √|    √|
  |b    |    √|    √|    √|    √|
  |g    |    √|    √|    √|    √|
  |n    |    √|    √|    √|    √|
  |h    |    √|    √|    √|    √|
  |pk    |    |    √|     |    √|
  |sk    |    |     |    √|    √|

  > **说明：**
  >
  > 密钥参数用于在创建非对称密钥生成器时，指定密钥规格。</br>
  > 上表说明了算法库对于指定公/私钥参数生成ECC密钥的支持情况。</br>
  > 打√的表示需要指定这一列中的具体属性，来构成密钥参数。

  > **注意：**
  >
  > 1. 当前ECC只支持Fp域，因此fieldType固定为"Fp"。fieldType和p构成了属性field，当前field只支持[ECFieldFp](../reference/apis/js-apis-cryptoFramework.md#ecfieldfp10)。
  > 2. g和pk为ECC曲线上的点，属于[Point](../reference/apis/js-apis-cryptoFramework.md#point10)类型，需要指定具体X，Y坐标。

### DSA密钥生成规格

  > **说明：**
  >
  > 从API version 10开始， 支持DSA算法，包括密钥生成和签名验签。

- 支持以字符串参数来生成DSA密钥，其生成参数如下表所示：

  |非对称密钥算法|密钥长度（bit）|字符串参数|
  |---|---|---|
  |DSA|1024|DSA1024|
  |DSA|2048|DSA2048|
  |DSA|3072|DSA3072|

  > **说明：**
  >
  > “字符串参数”是“非对称密钥算法”和“密钥长度”拼接而成，用于在创建非对称密钥生成器时，指定密钥规格。

- 支持以密钥参数来生成DSA密钥，其密钥参数种类和各个密钥参数的密码学规格要求如下表所示：

  |   |公共参数|公钥参数|私钥参数|公私钥对参数|
  |---|---------|---|---|---|
  |p    |√    |√    |×    |√   |
  |q    |√    |√    |×    |√   |
  |g    |√    |√    |×    |√   |
  |pk   |    |√    |    |√    |
  |sk   |    |     |×    |√    |

  > **说明：**
  >
  > 密钥参数用于在创建非对称密钥生成器时，指定密钥规格。</br>
  > 上表说明了算法库对于指定公/私钥参数生成DSA密钥的支持情况。</br>
  > 打√的表示需要指定这一列中的具体属性，来构成密钥参数。</br>
  > 打×的表示这一列中的具体属性对应于某种密钥参数，但是算法库当前不支持通过该密钥参数生成密钥。

  > **注意：**
  >
  > 1. DSA不支持通过指定私钥参数（p, q, g, sk）来生成私钥。
  > 2. 当使用公共参数（p, q, g）来生成DSA密钥对时，DSA密钥长度至少需要1024位。

### SM2密钥生成规格

> **说明：**
>
> 从API version 10开始， 支持SM2密钥随机生成。

- 支持以字符串参数来生成SM2密钥，其生成参数如下表所示：

  |非对称密钥算法|密钥长度（bit）|字符串参数|
  |---|---|---|
  |SM2|256|SM2_256|

  > **说明：**
  >
  > “字符串参数”是“非对称密钥算法”和“密钥长度”使用连接符号“_”拼接而成，用于在创建非对称密钥生成器时，指定密钥规格。

### SM4密钥生成规格

> **说明：**
>
> 从API version 10开始， 支持SM4密钥随机生成。

- 支持以字符串参数来生成SM4密钥，其生成参数如下表所示：

  |对称密钥算法|密钥长度（bit）|字符串参数|
  |---|---|---|
  |SM4|128|SM4_128|

  > **说明：**
  >
  > “字符串参数”是“对称密钥算法”和“密钥长度”使用连接符号“_”拼接而成，用于在创建对称密钥生成器时，指定密钥规格。

### HMAC密钥生成规格

> **说明：**
>
> 从API version 11开始， 支持HMAC密钥生成。

- 支持以字符串参数来生成HMAC密钥，其生成参数如下表所示：

  |对称密钥算法|摘要算法|密钥长度（bit）|字符串参数|
  |---|---|---|---|
  |HMAC|SHA1|160|HMAC\|SHA1|
  |HMAC|SHA224|224|HMAC\|SHA224|
  |HMAC|SHA256|256|HMAC\|SHA256|
  |HMAC|SHA384|384|HMAC\|SHA384|
  |HMAC|SHA512|512|HMAC\|SHA512|
  |HMAC|SM3|256|HMAC\|SM3|
  |HMAC||[1, 32768]|HMAC|

  > **说明：**
  >
  > 1. “字符串参数”是“对称密钥算法”和“摘要算法”使用连接符号“|”拼接而成，用于在创建对称密钥生成器时，指定密钥规格。
  > 2. 当需要传入的密钥长度不在上述摘要算法范围内，可以通过字符串参数“HMAC”创建对称密钥生成器，并根据HMAC密钥二进制数据生成密钥。

## 加解密规格

### 对称加解密

  > **说明：**
  >
  > 从API version 10开始， 支持对称加解密不带密钥长度的规格。

- 支持的对称加密算法：
  |对称加解密算法|分组模式|字符串参数                                         |
  |---|---|---|
  |3DES|ECB|3DES192\|ECB\|[NoPadding\|PKCS5\|PKCS7]|
  |3DES|CBC|3DES192\|CBC\|[NoPadding\|PKCS5\|PKCS7]|
  |3DES|OFB|3DES192\|OFB\|[NoPadding\|PKCS5\|PKCS7]|
  |3DES|CFB|3DES192\|CFB\|[NoPadding\|PKCS5\|PKCS7]|
  |AES|ECB|AES[128\|192\|256]\|ECB\|[NoPadding\|PKCS5\|PKCS7]|
  |AES|CBC|AES[128\|192\|256]\|CBC\|[NoPadding\|PKCS5\|PKCS7]|
  |AES|CTR|AES[128\|192\|256]\|CTR\|[NoPadding\|PKCS5\|PKCS7]|
  |AES|OFB|AES[128\|192\|256]\|OFB\|[NoPadding\|PKCS5\|PKCS7]|
  |AES|CFB|AES[128\|192\|256]\|CFB\|[NoPadding\|PKCS5\|PKCS7]|
  |AES|GCM|AES[128\|192\|256]\|GCM\|[NoPadding\|PKCS5\|PKCS7]|
  |AES|CCM|AES[128\|192\|256]\|CCM\|[NoPadding\|PKCS5\|PKCS7]|
  |SM4|ECB|SM4_128\|ECB\|[NoPadding\|PKCS5\|PKCS7]|
  |SM4|CBC|SM4_128\|CBC\|[NoPadding\|PKCS5\|PKCS7]|
  |SM4|CTR|SM4_128\|CTR\|[NoPadding\|PKCS5\|PKCS7]|
  |SM4|OFB|SM4_128\|OFB\|[NoPadding\|PKCS5\|PKCS7]|
  |SM4|CFB|SM4_128\|CFB\|[NoPadding\|PKCS5\|PKCS7]|
  |SM4|CFB128|SM4_128\|CFB128\|[NoPadding\|PKCS5\|PKCS7]|

  > **说明：**
  >
  > 1. []中只能任选一项。
  > 2. “字符串参数”是“对称加解密算法（含密钥长度）”、“分组模式”、“填充模式”拼接而成，用于在创建对称加解密实例时，指定对称加解密算法规格。
  > 3. “字符串参数”中“SM4<sup>10+</sup>”和密钥长度间需要添加下划线

### 非对称RSA加解密

  > **说明：**
  >
  > 从API version 10开始， 支持非对称RSA加解密不带密钥长度的规格。

RSA加解密时，涉及三种填充模式：NoPadding, PKCS1和PKCS1_OAEP。
- 使用NoPadding模式时可以指定的参数:

  |非对称密钥类型| 填充模式 | 字符串参数 |
  |---|---|---|
  |RSA512|NoPadding|RSA512\|NoPadding|
  |RSA768|NoPadding|RSA768\|NoPadding|
  |RSA1024|NoPadding|RSA1024\|NoPadding|
  |RSA2048|NoPadding|RSA2048\|NoPadding|
  |RSA3072|NoPadding|RSA3072\|NoPadding|
  |RSA4096|NoPadding|RSA4096\|NoPadding|
  |RSA8192|NoPadding|RSA8192\|NoPadding|
  |RSA|NoPadding|RSA\|NoPadding|

  > **说明：**
  >
  > 1. “字符串参数”是“非对称密钥类型”、“填充模式”拼接而成，用于在创建非对称加解密实例时，指定非对称加解密算法规格。
  > 2. 在上表最后一行，为了兼容由密钥参数生成的密钥，RSA加解密参数输入密钥类型时支持不带长度，加解密运算取决于实际输入的密钥长度。

- 使用PKCS1模式时可以指定的参数:

  |非对称密钥类型| 填充模式 | 字符串参数 |
  |---|---|---|
  |RSA512|PKCS1|RSA512\|PKCS1|
  |RSA768|PKCS1|RSA768\|PKCS1|
  |RSA1024|PKCS1|RSA1024\|PKCS1|
  |RSA2048|PKCS1|RSA2048\|PKCS1|
  |RSA3072|PKCS1|RSA3072\|PKCS1|
  |RSA4096|PKCS1|RSA4096\|PKCS1|
  |RSA8192|PKCS1|RSA8192\|PKCS1|
  |RSA|PKCS1|RSA\|PKCS1|

  > **说明：**
  >
  > 1. “字符串参数”是“非对称密钥类型”、“填充模式”拼接而成，用于在创建非对称加解密实例时，指定非对称加解密算法规格。
  > 2. 在上表最后一行，为了兼容由密钥参数生成的密钥，RSA加解密参数输入密钥类型时支持不带长度，加解密运算取决于实际输入的密钥长度。

- 使用PKCS1_OAEP模式时可以指定的参数：

  | 非对称密钥类型 | 填充模式 | 摘要 | 掩码摘要 |
  |---|---|---|---|
  |RSA512|PKCS1_OAEP|MD5|  [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256]|
  |RSA512|PKCS1_OAEP|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256]|
  |RSA512|PKCS1_OAEP|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256]|
  |RSA512|PKCS1_OAEP|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224]
  |RSA768|PKCS1_OAEP|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA768|PKCS1_OAEP|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA768|PKCS1_OAEP|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA768|PKCS1_OAEP|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384]|
  |RSA768|PKCS1_OAEP|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256]|
  |RSA768|PKCS1_OAEP|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224]|
  |RSA1024|PKCS1_OAEP|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA1024|PKCS1_OAEP|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA1024|PKCS1_OAEP|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA1024|PKCS1_OAEP|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA1024|PKCS1_OAEP|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA1024|PKCS1_OAEP|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384]|
  |RSA2048|PKCS1_OAEP|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA2048|PKCS1_OAEP|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA2048|PKCS1_OAEP|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA2048|PKCS1_OAEP|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA2048|PKCS1_OAEP|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA2048|PKCS1_OAEP|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PKCS1_OAEP|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PKCS1_OAEP|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PKCS1_OAEP|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PKCS1_OAEP|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PKCS1_OAEP|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PKCS1_OAEP|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PKCS1_OAEP|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PKCS1_OAEP|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PKCS1_OAEP|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PKCS1_OAEP|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PKCS1_OAEP|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PKCS1_OAEP|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PKCS1_OAEP|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PKCS1_OAEP|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PKCS1_OAEP|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PKCS1_OAEP|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PKCS1_OAEP|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PKCS1_OAEP|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA|PKCS1_OAEP|符合长度要求的摘要算法|MGF1_符合长度要求的摘要算法|

  > **说明：**
  >
  > 1. []内的参数只能任选一项，非[]内的为固定值。
  > 2. 使用时请从表格中选择非对称密钥类型、填充模式、摘要、掩码摘要四个数据，用|拼接成“字符串参数”，用于在创建非对称加解密实例时，指定非对称加解密算法规格。<br>
  >    例如："RSA2048|PKCS1_OAEP|SHA256|MGF1_SHA256"
  > 3. 在上表最后一行，为了兼容由密钥参数生成的密钥，RSA加解密参数输入密钥类型时支持不带长度，加解密运算取决于实际输入的密钥长度。
  > 4. 输入的数据必须小于RSA钥模 - md摘要长度 - mgf1_md摘要长度 - 2，如RSA密钥为512位时,不支持SHA512，RSA钥模和摘要长度定义，详见[加解密](#加解密)中RSA的相关描述。

- 使用PKCS1_OAEP模式时，可以通过获取加解密OAEP填充模式的各个[参数](../reference/apis/js-apis-cryptoFramework.md#cipherspecitem10)，并设置OAEP填充的编码输入P。

  | OAEP参数 |枚举值| 获取 | 设置 |
  |---|---|---|---|
  |md|OAEP_MD_NAME_STR |√||
  |mgf|OAEP_MGF_NAME_STR|√||
  |mgf1_md|OAEP_MGF1_MD_STR |√||
  |pSource|OAEP_MGF1_PSRC_UINT8ARR|√|√|

  > **说明：**
  >
  > 上表说明了算法库对于OAEP参数的获取和设置支持情况，打√的表示需要对该参数具有获取或设置的能力。


### 非对称SM2加解密

> **说明：**
>
> 从API version 10开始， 支持非对称SM2加解密，支持不带密钥长度的规格。

SM2加解密时，仅支持C1C3C2密文排列组合模式。SM2非对称加密的结果由C1,C2,C3三部分组成。其中C1是根据生成的随机数计算出的椭圆曲线点，C2是密文数据，C3是通过指定摘要算法计算的值。国密新标准以C1,C3,C2顺序存放，不支持无摘要加密。
- 支持的加密算法:

  | 非对称密钥类型 | 摘要 | 字符串参数 |
  |---|---|---|
  |SM2_256|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512\|SM3]|SM2_256\|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512\|SM3]|
  |SM2|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512\|SM3]|SM2_256\|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512\|SM3]|

  > **说明：**
  >
  >  “字符串参数”是“非对称密钥类型”、“填充模式”拼接而成，用于在创建非对称加解密实例时，指定非对称加解密算法规格。

## 签名验签规格

### RSA签名验签

  > **说明：**
  >
  > 从API version 10开始， 支持RSA签名验签不带密钥长度的规格。

RSA签名验签时，涉及两种填充模式：PKCS1和PSS。

-  使用PKCS1模式时可以指定的参数:

  | 非对称密钥类型 | 填充模式 | 摘要 | 字符串参数 |
  |---|---|---|---|
  |RSA512|PKCS1|[MD5\|SHA1\|SHA224\|SHA256\|SHA384]|RSA512\|PKCS1\|[MD5\|SHA1\|SHA224\|SHA256\|SHA384]|
  |RSA768|PKCS1|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|RSA768\|PKCS1\|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |RSA1024|PKCS1|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|RSA1024\|PKCS1\|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |RSA2048|PKCS1|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|RSA2048\|PKCS1\|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |RSA3072|PKCS1|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|RSA3072\|PKCS1\|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |RSA4096|PKCS1|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|RSA4096\|PKCS1\|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |RSA8192|PKCS1|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|RSA8192\|PKCS1\|[MD5\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |RSA|PKCS1|符合长度要求的摘要算法|RSA\|PKCS1\|符合长度要求的摘要算法|

  > **说明：**
  >
  > 1. []内的参数只能任选一项，非[]内的为固定值。
  > 2. 在上表最后一行，为了兼容由密钥参数生成的密钥，RSA签名验签参数输入密钥类型时支持不带长度，签名验签运算取决于实际输入的密钥长度。
  > 3. RSA签名验签时，摘要算法输出的长度，需要小于RSA的钥模, 如RSA密钥为512位时，不支持SHA512，详见[签名验签](#签名验签)中RSA的相关描述。

- 使用PSS模式时可以指定的参数：

  | 非对称密钥类型 | 填充模式 | 摘要 | 掩码摘要 |
  |---|---|---|---|
  |RSA512|PSS|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256]|
  |RSA512|PSS|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256]|
  |RSA512|PSS|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256]|
  |RSA512|PSS|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224]|RSA512\|PSS\|SHA256\|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224]|
  |RSA768|PSS|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA768|PSS|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA768|PSS|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA768|PSS|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384]|
  |RSA768|PSS|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256]|
  |RSA768|PSS|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224]|
  |RSA1024|PSS|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA1024|PSS|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA1024|PSS|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA1024|PSS|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA1024|PSS|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA1024|PSS|SHA512| [MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384]|
  |RSA2048|PSS|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA2048|PSS|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA2048|PSS|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA2048|PSS|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA2048|PSS|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA2048|PSS|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PSS|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PSS|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PSS|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PSS|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PSS|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA3072|PSS|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PSS|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PSS|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PSS|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PSS|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PSS|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA4096|PSS|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PSS|MD5|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PSS|SHA1|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PSS|SHA224|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PSS|SHA256|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PSS|SHA384|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA8192|PSS|SHA512|[MGF1_MD5\|MGF1_SHA1\|MGF1_SHA224\|MGF1_SHA256\|MGF1_SHA384\|MGF1_SHA512]|
  |RSA|PSS|符合长度要求的摘要算法|MGF1_符合长度要求的摘要算法|

  > **说明：**
  >
  > 1. []内的参数只能任选一项，非[]内的为固定值。
  > 2. 使用时请从表格中选择非对称密钥类型、填充模式、摘要、掩码摘要四个数据，用|拼接成“字符串参数”，用于在创建非对称签名验签实例时，指定非对称签名验签算法规格。<br>
  >    例如："RSA2048|PSS|SHA256|MGF1_SHA256"
  > 3. 在上表最后一行，为了兼容由密钥参数生成的密钥，RSA签名验签参数输入密钥类型时支持不带长度，签名验签运算取决于实际输入的密钥长度。
  > 4. RSA签名验签时，对于PSS模式，md和mgf1_md长度之和（字节）需要小于RSA的钥模。如RSA密钥为512位时，无法支持md和mgf1_md同时为SHA256。RSA钥模和摘要长度定义，详见[签名验签](#签名验签)中RSA的相关描述。

- 使用PSS模式时，可以通过获取签名验签PSS填充模式的各个[参数](../reference/apis/js-apis-cryptoFramework.md#signspecitem10)，并设置PSS的以字节为单位的盐长度(saltLen)。

  | PSS参数 |枚举值| 获取 | 设置 |
  |---|---|---|---|
  |md|PSS_MD_NAME_STR |√||
  |mgf|PSS_MGF_NAME_STR|√||
  |mgf1_md|PSS_MGF1_MD_STR |√||
  |saltLen|PSS_SALT_LEN_NUM|√|√|
  |trailer_field|PSS_TRAILER_FIELD_NUM|√||

  > **说明：**
  >
  > 上表说明了算法库对于PSS参数的获取和设置支持情况，打√的表示需要对该参数具有获取或设置的能力。

### ECDSA签名验签

  > **说明**：<br>
  > 从API version 10开始， 支持ECDSA签名验签不带密钥长度的规格。
- 支持的ECDSA参数：

  |非对称密钥类型|摘要|字符串参数|
  |---|---|---|
  |ECC224|[SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|ECC224\|[SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |ECC256|[SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|ECC256\|[SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |ECC384|[SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|ECC384\|[SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |ECC521|[SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|ECC521\|[SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |ECC|[SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|ECC\|[SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|

  > **说明：**
  >
  > 1. []内的参数只能任选一项，非[]内的为固定值。
  > 2. 使用时请从表格中选择非对称密钥类型、摘要二个数据，用|拼接成“字符串参数”，用于在创建非对称签名验签实例时，指定非对称签名验签算法规格。<br>
  >    例如："ECC224|SHA256"
  > 3. 在上表最后一行，为了兼容由密钥参数生成的密钥，ECDSA签名验签参数输入密钥类型时支持不带长度，签名验签运算取决于实际输入的密钥长度。

### DSA签名验签

  > **说明：**
  >
  > 从API version 10开始， 支持DSA签名验签规格。

- 支持的DSA参数：

  |非对称密钥类型|摘要|字符串参数|
  |---|---|---|
  |DSA1024|[NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|DSA1024\|[NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |DSA2048|[NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|DSA2048\|[NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |DSA3072|[NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|DSA3072\|[NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|
  |DSA|[NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|DSA\|[NoHash\|SHA1\|SHA224\|SHA256\|SHA384\|SHA512]|

  > **说明：**
  >
  > 1. []内的参数只能任选一项，非[]内的为固定值。
  > 2. 使用时请从表格中选择非对称密钥类型、摘要二个数据，用|拼接成“字符串参数”，用于在创建非对称签名验签实例时，指定非对称签名验签算法规格。<br>
  >    例如："DSA1024|SHA256"
  > 3. 在上表最后一行，为了兼容由密钥参数生成的密钥，DSA签名验签参数输入密钥类型时支持不带长度，签名验签运算取决于实际输入的密钥长度。


### SM2签名验签

> **说明：**
>
> 从API version 10开始， 支持SM2签名验签。

- 支持的SM2参数：

  |非对称密钥类型|摘要|字符串参数|
  |---|---|---|
  |SM2_256|SM3|SM2_256\|SM3|
  |SM2|SM3|SM2\|SM3|

  > **说明：**
  >
  > 1. []内的参数只能任选一项，非[]内的为固定值。
  > 2. 使用时请从表格中选择非对称密钥类型、摘要二个数据，用|拼接成“字符串参数”，用于在创建非对称签名验签实例时，指定非对称签名验签算法规格。<br>
  >    SM2签名时只支持SM3摘要。

## 密钥协商规格

### ECDH

  > **说明：**
  >
  > 从API version 10开始， 支持ECDH不带密钥长度的规格。

- 支持的ECDH参数：

  |非对称密钥算法|字符串参数|
  |---|---|
  |ECC|ECC224|
  |ECC|ECC256|
  |ECC|ECC384|
  |ECC|ECC521|
  |ECC|ECC|

  > **说明：**
  >
  > 1. “字符串参数”，用于在创建密钥协商时，指定密钥协商算法规格。
  > 2. 在上表最后一行，为了兼容由密钥参数生成的密钥，ECDH密钥协商参数输入密钥类型时支持不带长度，密钥协商运算取决于实际输入的密钥长度。


## MD消息摘要算法规格

- 加解密算法库框架当前支持的MD算法参数：

    > **说明：**
    >
    > 从API version 10开始， 支持SM3。

  |摘要算法|支持种类|
  |---|---|
  |HASH|SHA1|
  |HASH|SHA224|
  |HASH|SHA256|
  |HASH|SHA384|
  |HASH|SHA512|
  |HASH|MD5|
  |HASH|SM3|

  > **说明：**
  >
  > “支持种类”，用于在创建MD消息摘要时，指定MD消息摘要算法规格。

## HMAC消息认证码算法规格

- 加解密算法库框架当前支持的HMAC算法参数：

    > **说明：**
    >
    > 从API version 10开始， 支持SM3。

  |摘要算法|支持种类|
  |---|---|
  |HASH|SHA1|
  |HASH|SHA224|
  |HASH|SHA256|
  |HASH|SHA384|
  |HASH|SHA512|
  |HASH|SM3|

  > **说明：**
  >
  > “支持种类”，用于在创建HMAC消息认证码时，指定HMAC消息认证码算法规格。

## 随机数
- 加解密算法库框架支持随机数生成算法，目前只支持“CTR_DRBG"算法规格

  > **说明：**
  >
  > 1. 随机数生成算法目前支持生成长度为[1, INT_MAX]的安全随机数，长度单位为byte。
  > 2. 随机数生成算法使用openssl的RAND_priv_bytes接口生成安全随机数。

## 密钥派生函数规格

### PBKDF2

> **说明：**
>
> 从API version 11开始， 支持PBKDF2。

- 支持的PBKDF2参数：

  |密钥派生函数|HMAC函数摘要算法|字符串参数|
  |---|---|---|
  |PBKDF2|SHA1|PBKDF2\|SHA1|
  |PBKDF2|SHA224|PBKDF2\|SHA224|
  |PBKDF2|SHA256|PBKDF2\|SHA256|
  |PBKDF2|SHA384|PBKDF2\|SHA384|
  |PBKDF2|SHA512|PBKDF2\|SHA512|
  |PBKDF2|SM3|PBKDF2\|SM3|

  > **说明：**
  >
  > “字符串参数”是“密钥派生函数”和“HMAC函数摘要算法”使用符号“|”拼接而成，用于在创建密钥派生函数生成器时，指定算法规格。