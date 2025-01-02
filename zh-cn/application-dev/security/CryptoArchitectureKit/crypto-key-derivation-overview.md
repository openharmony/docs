# 密钥派生介绍及算法规格

密钥派生函数（key derivation function）是指使用伪随机函数从秘密值（如主密钥）中导出一个或多个密钥。密钥派生函数可用于将密钥扩展到更长的密钥或获得所需格式的密钥。

## PBKDF2算法

PBKDF（Password-Based Key Derivation Function）是具有可变计算成本的密钥派生函数，PBKDF2是PKCS系列的标准之一。

PBKDF2是将伪随机函数PRF（Pseudo-Random Function，例如基于散列的[HMAC](crypto-compute-mac.md)），输入密码明文和盐值，重复多次运算来进行密钥派生。

当前支持以字符串参数进行密钥派生，具体的“字符串参数”由“密钥派生函数”和“HMAC函数摘要算法”使用符号“|”拼接而成，用于在创建密钥派生函数生成器时，指定算法规格。
| 密钥派生算法 | HMAC函数摘要算法 | 字符串参数 | API版本 | 
| -------- | -------- | -------- | -------- |
| PBKDF2 | SHA1 | PBKDF2\|SHA1 | 11+ | 
| PBKDF2 | SHA224 | PBKDF2\|SHA224 | 11+ | 
| PBKDF2 | SHA256 | PBKDF2\|SHA256 | 11+ | 
| PBKDF2 | SHA384 | PBKDF2\|SHA384 | 11+ | 
| PBKDF2 | SHA512 | PBKDF2\|SHA512 | 11+ | 
| PBKDF2 | SM3 | PBKDF2\|SM3 | 11+ | 

## HKDF算法

HKDF（HMAC-based Extract-and-Expand Key Derivation Function，是基于[HMAC](crypto-compute-mac.md)）消息身份验证代码的简单密钥派生，输入原始的密钥材料和盐值来提取和输入原始的密钥材料和拓展信息来扩展。它是一种密钥派生函数，用于从较短的输入密钥中派生出更长的输出密钥。

HKDF包含俩个基本模块，提取（Extract）、拓展（Expand）
提取：使用原始的密钥材料，派生出一个符合密码学强度的伪随机密钥。
拓展：将短密钥经过拓展变长，使用提取出的伪随机密钥，拓展出指定长度的密钥，同时保证随机性。

当前支持以字符串参数进行密钥派生，具体的“字符串参数”由“密钥派生函数”、“HMAC函数摘要算法”和“模式”使用符号“|”拼接而成，用于在创建密钥派生函数生成器时，指定算法规格。
| 密钥派生算法 | HMAC函数摘要算法 | 字符串参数 | API版本 | 
| -------- | -------- | -------- | -------- |
| HKDF | SHA1 | HKDF\|SHA1 | 12+ | 
| HKDF | SHA224 | HKDF\|SHA224 | 12+ | 
| HKDF | SHA256 | HKDF\|SHA256 | 12+ | 
| HKDF | SHA384 | HKDF\|SHA384 | 12+ | 
| HKDF | SHA512 | HKDF\|SHA512 | 12+ | 
| HKDF | SM3 | HKDF\|SM3 | 12+ | 