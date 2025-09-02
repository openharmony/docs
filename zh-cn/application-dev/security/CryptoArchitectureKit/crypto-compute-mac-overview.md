# 消息认证码计算介绍及算法规格

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

MAC（Message Authentication Code，消息认证码）可以对消息进行完整性校验，通过使用双方共享的密钥，识别出信息伪装篡改等行为。

接下来将说明系统目前支持的算法及其对应的规格。

## HMAC
HMAC（Hash-based Message Authentication Code）是一种基于哈希的消息认证码算法。

HMAC通过指定的摘要算法，以通信双方共享的密钥和消息作为输入，生成消息认证码，用于检验传递报文的完整性。HMAC在消息摘要算法基础上增加了密钥输入，确保信息的正确性。生成的消息认证码长度固定。

当创建HMAC消息认证码时，需要根据表中“支持种类”一列指定算法规格。

| 摘要算法 | 支持种类 | API版本 | 
| -------- | -------- | -------- |
| HASH | SHA1 | 9+ | 
| HASH | SHA224 | 9+ | 
| HASH | SHA256 | 9+ | 
| HASH | SHA384 | 9+ | 
| HASH | SHA512 | 9+ | 
| HASH | SM3 | 10+ | 
| HASH | MD5 | 12+ | 

## CMAC

‌CMAC（Cipher-based Message Authentication Code）是一种基于密码的消息认证码算法，主要用于确保消息的完整性和真实性。

CMAC通过使用分组密码（如AES）和一个密钥来生成消息认证码，确保消息在传输过程中未被篡改‌。

| 加密算法 | API版本 | 
| -------- | -------- |
| AES128 | 16+ |
| AES256 | 16+ |
