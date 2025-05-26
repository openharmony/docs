# 密钥派生介绍及算法规格

密钥派生函数（key derivation function）是指使用伪随机函数从秘密值中导出一个或多个密钥。密钥派生函数可用于将密钥扩展到更长的密钥或获得所需格式的密钥。

## PBKDF2算法

PBKDF（Password-Based Key Derivation Function）是具有可变计算成本的密钥派生函数，PBKDF2是PKCS系列的标准之一。

PBKDF2是将伪随机函数PRF（Pseudo-Random Function，例如基于散列的[HMAC](crypto-compute-hmac.md)），输入密码明文和盐值，重复多次运算来进行密钥派生。

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

HKDF（HMAC-based Extract-and-Expand Key Derivation Function，是基于[HMAC](crypto-compute-hmac.md)）消息身份验证代码的简单密钥派生，输入原始的密钥材料和盐值来提取和输入原始的密钥材料和拓展信息来扩展。它是一种密钥派生函数，用于从较短的输入密钥中派生出更长的输出密钥。

HKDF包含三个模式，提取（EXTRACT_ONLY）、拓展（EXPAND_ONLY）、提取和拓展（EXTRACT_AND_EXPAND）。

- 提取：使用原始的密钥材料，派生出一个符合密码学强度的伪随机密钥。
- 拓展：将短密钥经过拓展变长，使用提取出的伪随机密钥，拓展出指定长度的密钥，同时保证随机性。
- 提取和拓展：派生伪随机密钥，拓展出指定长度的密钥。

当前支持以字符串参数进行密钥派生，具体的“字符串参数”由“密钥派生函数”、“HMAC函数摘要算法”和“模式”使用符号“|”拼接而成，用于在创建密钥派生函数生成器时，指定算法规格。

如下表所示，各取值范围（即[]中的内容）中，最多选取一项完成字符串拼接，其中“模式”为可选项，未指定时默认为EXTRACT_AND_EXPAND。例如：当密钥派生算法为HKDF、HMAC，函数摘要算法为SHA1和模式为EXTRACT_AND_EXPAND时，其字符串参数为"HKDF|SHA1"或"HKDF|SHA1|EXTRACT_AND_EXPAND"。
| 密钥派生算法 | HMAC函数摘要算法 | 模式 | API版本 | 
| -------- | -------- | -------- | -------- |
| HKDF | SHA1 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | 12+ | 
| HKDF | SHA224 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | 12+ | 
| HKDF | SHA256 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | 12+ | 
| HKDF | SHA384 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | 12+ | 
| HKDF | SHA512 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | 12+ | 
| HKDF | SM3 | [EXPAND_ONLY\|EXTRACT_ONLY\|EXTRACT_AND_EXPAND] | 12+ | 

## SCRYPT算法

SCRYPT算法是一种密钥派生函数（KDF），主要用于从输入的密码和盐值生成加密密钥。这个算法主要包含三个主要的参数：n、r和p。n是迭代次数，r是块大小，p是并行性。通过调整这些参数，可以根据不同的安全需求和硬件性能进行优化。
SCRYPT算法是一个需要耗费大量内存和计算资源来派生密钥的派生算法，使用者需要根据设备硬件条件去传入合适的值。
内存的计算方式为：p * 128 * r + 32 * r * (n + 2) * 4 字节。

| 密钥派生算法 | 字符串参数 | API版本 | 
| -------- | -------- | -------- |
| SCRYPT | SCRYPT | 16+ | 