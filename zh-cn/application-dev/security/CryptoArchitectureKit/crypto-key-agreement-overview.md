# 密钥协商介绍及算法规格

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--SE: @lanming-->
<!--TSE: @PAFT-->

在非安全通道环境中，需要不共享任何秘密的情况下，协商出一个安全的共享密钥，可以使用密钥协商算法。

接下来将说明系统目前支持的算法及其对应的规格。

## ECDH

ECDH（Elliptic Curve Diffie–Hellman key exchange），算法库框架提供了多种椭圆曲线的ECDH能力。

当创建密钥协商时，需要使用表中“字符串参数”一列，指定密钥协商算法规格。

| 非对称密钥算法 | 字符串参数 | API版本 | 
| -------- | -------- | -------- |
| ECC | ECC224 | 9+ | 
| ECC | ECC256 | 9+ | 
| ECC | ECC384 | 9+ | 
| ECC | ECC521 | 9+ | 
| ECC | ECC_BrainPoolP160r1 | 11+ | 
| ECC | ECC_BrainPoolP160t1 | 11+ | 
| ECC | ECC_BrainPoolP192r1 | 11+ | 
| ECC | ECC_BrainPoolP192t1 | 11+ | 
| ECC | ECC_BrainPoolP224r1 | 11+ | 
| ECC | ECC_BrainPoolP224t1 | 11+ | 
| ECC | ECC_BrainPoolP256r1 | 11+ | 
| ECC | ECC_BrainPoolP256t1 | 11+ | 
| ECC | ECC_BrainPoolP320r1 | 11+ | 
| ECC | ECC_BrainPoolP320t1 | 11+ | 
| ECC | ECC_BrainPoolP384r1 | 11+ | 
| ECC | ECC_BrainPoolP384t1 | 11+ | 
| ECC | ECC_BrainPoolP512r1 | 11+ | 
| ECC | ECC_BrainPoolP512t1 | 11+ | 
| ECC | ECC_Secp256k1 | 14+ | 
| ECC | ECC | 10+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，ECDH密钥协商参数输入密钥类型时支持不指定长度和曲线，密钥协商运算取决于实际输入的密钥。

## X25519

算法库框架提供了X25519密钥协商的能力。

当创建密钥协商时，需要使用表中“字符串参数”一列，指定密钥协商算法规格。

| 非对称密钥算法 | 字符串参数 | API版本 | 
| -------- | -------- | -------- |
| X25519 | X25519 | 11+ | 

## DH

DH（Diffie–Hellman key exchange），算法库框架提供了DH密钥协商的能力。

当创建密钥协商时，需要使用表中“字符串参数”一列，指定密钥协商算法规格。

| 非对称密钥算法 | 字符串参数 | API版本 | 
| -------- | -------- | -------- |
| DH | DH_modp1536 | 11+ | 
| DH | DH_modp2048 | 11+ | 
| DH | DH_modp3072 | 11+ | 
| DH | DH_modp4096 | 11+ | 
| DH | DH_modp6144 | 11+ | 
| DH | DH_modp8192 | 11+ | 
| DH | DH_ffdhe2048 | 11+ | 
| DH | DH_ffdhe3072 | 11+ | 
| DH | DH_ffdhe4096 | 11+ | 
| DH | DH_ffdhe6144 | 11+ | 
| DH | DH_ffdhe8192 | 11+ | 
| DH | DH | 11+ | 

如表中最后一行所示，为了兼容由密钥参数生成的密钥，DH密钥协商参数输入密钥类型时支持不指定知名安全素数群，密钥协商运算结果由实际输入的密钥决定，且该场景支持非标准群组的密钥协商。
