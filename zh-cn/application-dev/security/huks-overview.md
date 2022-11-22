# HUKS开发概述

## 功能简介

HUKS（OpenHarmony Universal KeyStore）向应用提供密钥库能力，包括密钥管理及密钥的密码学操作等功能。HUKS所管理的密钥可以由应用导入或者由应用调用HUKS接口生成。 

## 基本概念

- HUKS提供密钥管理功能，支持的主要操作包括：加密解密、签名验签、派生协商密钥、计算HMAC（Hash-based Message Authentication Code）。
- HUKS涉及的算法主要有：AES加密解密、RSA加密解密、RSA签名验签、ECC签名验签、DSA签名验签、ED25519签名验签、PBKDF2派生、DH协商、ECDH协商、X25519协商等。
- HUKS当前使用的算法库为OpenSSL和mbed TLS。

## 运作机制

HUKS对密钥的使用主要通过InitSession、UpdateSession、FinishSession操作来实现。

- **InitSession操作**：读取密钥，并为其创建Session Id返回给调用者。

- **UpdateSession操作**：根据InitSession操作获取的Session Id对数据进行分段updateSession处理。

- **FinishSession操作**：当所有待处理的数据均传入HUKS后，调用FinishSession操作完成最终数据处理，释放资源。

> **须知：**<br>
> 当InitSession、UpdateSession、FinishSession操作中的任一阶段发生错误时，都需要调用AbortSession操作来终止密钥的使用。


## 约束与限制
不涉及。
