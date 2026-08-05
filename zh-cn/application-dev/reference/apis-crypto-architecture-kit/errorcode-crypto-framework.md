# cryptoFramework错误码

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

> **说明：**
>
> 以下仅介绍本模块特有错误码，通用错误码请参考[通用错误码说明文档](../errorcode-universal.md)。

## 17620001 内存操作失败

**错误信息**

Memory operation failed.

**错误描述**

内存操作失败。

**可能原因**

当前系统内存分配失败。

**处理步骤**

1. 检查当前系统功能是否正常。
2. 业务检查数据是否超长，导致系统无法分配内存。

## 17620002 获取Native对象失败或参数转换失败

**错误信息**

Failed to obtain the native object or convert parameters.

**错误描述**

获取Native对象失败或参数转换失败。

**可能原因**

系统出现的不可预期的错误。

**处理步骤**

检查当前系统功能是否正常。

## 17620003 参数检查失败

**错误信息**

Parameter check failed.

**错误描述**

参数检查失败。

**可能原因**

输入的参数超出了规格范围，如长度、值等。

**处理步骤**

检查当前输入的参数是否在支持的范围内。

## 17620004 无效的函数调用

**错误信息**

Invalid function call.

**错误描述**

无效的函数调用。

**可能原因**

当前操作不支持当前函数调用。

**处理步骤**

检查当前函数调用是否合理。

## 17630001 密码操作错误

**错误信息**

Crypto operation error.

**错误描述**

密码操作错误。

**可能原因**

加解密算法框架与三方算法库交互时，出现错误。

**处理步骤**

检查该接口或相关联接口输入参数的正确性。

开发者在解密时经常遇到报错17630001，下文按照典型场景分类详细分析。

### 使用AES-GCM算法解密时调用doFinal失败

**问题现象**

AES-GCM解密时调用doFinal失败，返回错误码17630001。

> **说明：**
>
> - 建议开发者使用update接口加密数据，最后调用doFinal接口完成本次加密，获取tag。
> - 建议开发者使用update接口解密数据，最后调用doFinal接口完成本次解密，doFinal接口内将会对tag进行验证，若失败，接口会抛出异常。

**可能原因**

doFinal失败，表示校验tag失败，解密输入的tag和解密过程中计算的tag不一致。解密输入的key、iv、aad、tag和ciphertext，任意一个不正确，都会导致该报错。

1. key不正确，update得到的明文不正确，doFinal失败，即校验tag失败。
2. iv不正确，update得到的明文不正确，doFinal失败，即校验tag失败。
3. aad不正确，update得到的明文正确，doFinal失败，即校验tag失败。
4. ciphertext不正确，update得到的明文不正确，doFinal失败，即校验tag失败。
5. tag不正确，update得到的明文正确，doFinal失败，即校验tag失败。

**解决措施**

确认加密和解密的key、iv和aad参数一致，确保解密时输入的ciphertext和tag是正确的。

### 使用AES-CBC算法解密时调用doFinal失败

**问题现象**

解密时调用doFinal失败，返回错误码17630001。

> **说明：**
>
> AES-CBC属于块加密算法，因此需要使用到填充算法PKCS7，将明文填充至块大小整数倍。
>
> 解密时，doFinal接口会对padding进行校验。

**可能原因**

doFinal失败，表示校验padding失败，doFinal对最后一块密文数据解密，并校验padding是否合法。解密输入的key、iv和ciphertext，任意一个不正确，都可能会导致该报错。

1. key不正确，update得到的明文不正确，doFinal失败，即校验padding失败。
2. iv不正确，完整的密文长度为16字节，update无输出，doFinal失败，即校验padding失败；完整的密文长度是16字节的整数倍（不包含16字节），update得到的明文部分正确，doFinal成功。
3. ciphertext不正确，倒数第一个或第二个密文块错误，update得到的明文部分正确（或无输出），doFinal失败，即校验padding失败；其他密文块错误，update得到的明文部分正确，doFinal成功。

**解决措施**

确认加密和解密的key和iv参数一致，确保解密时输入的ciphertext是正确的。

### 使用AES-CCM算法解密时调用doFinal失败

**问题现象**

AES-CCM解密时调用doFinal失败，返回错误码17630001。

> **说明：**
>
> - AES-CCM为认证加密模式，加解密时需要指定附加验证数据aad（长度需大于等于1字节且小于等于2048字节）和认证标签tag。
> - 建议开发者使用update接口加密数据，最后调用doFinal接口完成本次加密，获取tag。
> - 建议开发者使用update接口解密数据，最后调用doFinal接口完成本次解密，doFinal接口内将会对tag进行验证，若失败，接口会抛出异常。

**可能原因**

doFinal失败，表示校验tag失败，解密输入的tag和解密过程中计算的tag不一致。解密输入的key、iv、aad、tag和ciphertext，任意一个不正确，都会导致该报错。

1. key不正确，update得到的明文不正确，doFinal失败，即校验tag失败。
2. iv不正确，update得到的明文不正确，doFinal失败，即校验tag失败。
3. aad不正确，update得到的明文正确，doFinal失败，即校验tag失败。
4. ciphertext不正确，update得到的明文不正确，doFinal失败，即校验tag失败。
5. tag不正确，update得到的明文正确，doFinal失败，即校验tag失败。

**解决措施**

确认加密和解密的key、iv和aad参数一致，确保解密时输入的ciphertext和tag是正确的。

### 使用AES-ECB算法解密时调用doFinal失败

**问题现象**

AES-ECB解密时调用doFinal失败，返回错误码17630001。

> **说明：**
>
> AES-ECB属于块加密算法，分组长度为128位（16字节），因此需要使用到填充算法PKCS7，将明文填充至分组大小的整数倍。
>
> 解密时，doFinal接口会对padding进行校验。

**可能原因**

doFinal失败，表示校验padding失败，doFinal对最后一块密文数据解密，并校验padding是否合法。解密输入的key和ciphertext，任意一个不正确，都可能会导致该报错。

1. key不正确，update得到的明文不正确，doFinal失败，即校验padding失败。
2. ciphertext不正确，最后一个密文块错误，update得到的明文部分正确，doFinal失败，即校验padding失败；其他密文块错误，update得到的明文部分正确，doFinal成功。
3. ciphertext长度不是16字节（分组大小）的整数倍（使用PKCS7填充时），doFinal失败。

**解决措施**

确认加密和解密的key参数一致，确保解密时输入的ciphertext是正确的，且密文长度为分组大小（16字节）的整数倍。

### 使用DES/3DES算法解密时调用doFinal失败

**问题现象**

DES或3DES解密时调用doFinal失败，返回错误码17630001。

> **说明：**
>
> DES/3DES为分组加密算法，分组长度为64位（8字节）。ECB、CBC模式下，明文长度不是64位整数倍时，必须使用填充方法补足。
>
> 解密时，doFinal接口会对padding进行校验。
>
> 若使用NoPadding模式，key、iv或密文不正确（长度均符合要求）时，解密仍能成功，但得到的明文是错误的。

**可能原因**

doFinal失败，表示校验padding失败。解密输入的key内容错误（长度正确但密钥值不正确）或ciphertext不正确，都可能会导致该报错。

1. key内容不正确（DES密钥应为8字节，3DES密钥应为24字节），update得到的明文不正确，doFinal失败。
2. iv不正确（CBC/OFB/CFB模式下iv为8字节）：CBC和CFB模式下仅影响第一个密文块的解密，update得到的明文部分不正确，doFinal成功；OFB为流密码，iv不正确将导致所有明文不正确，但doFinal仍成功。
3. ciphertext不正确，ECB模式下最后一个密文块错误，或CBC模式下倒数第一或第二个密文块错误时，doFinal失败，即padding校验失败；其他密文块错误，doFinal成功，但得到的明文不正确。
4. ciphertext长度不是8字节（分组大小）的整数倍（使用PKCS7填充时），doFinal失败。

**解决措施**

确认加密和解密的key和iv参数一致，确保解密时输入的ciphertext是正确的。DES密钥长度为8字节，3DES密钥长度为24字节。

### 使用SM4-GCM算法解密时调用doFinal失败

**问题现象**

SM4-GCM解密时调用doFinal失败，返回错误码17630001。

> **说明：**
>
> - SM4-GCM为认证加密模式，加解密时需要指定附加验证数据aad和认证标签tag。
> - 建议开发者使用update接口加密数据，最后调用doFinal接口完成本次加密，获取tag。
> - 建议开发者使用update接口解密数据，最后调用doFinal接口完成本次解密，doFinal接口内将会对tag进行验证，若失败，接口会抛出异常。

**可能原因**

doFinal失败，表示校验tag失败，解密输入的tag和解密过程中计算的tag不一致。解密输入的key、iv、aad、tag和ciphertext，任意一个不正确，都会导致该报错。

1. key不正确，update得到的明文不正确，doFinal失败，即校验tag失败。
2. iv不正确，update得到的明文不正确，doFinal失败，即校验tag失败。
3. aad不正确，update得到的明文正确，doFinal失败，即校验tag失败。
4. ciphertext不正确，update得到的明文不正确，doFinal失败，即校验tag失败。
5. tag不正确，update得到的明文正确，doFinal失败，即校验tag失败。

**解决措施**

确认加密和解密的key、iv和aad参数一致，确保解密时输入的ciphertext和tag是正确的。

### 使用SM4-ECB/CBC算法解密时调用doFinal失败

**问题现象**

SM4-ECB或SM4-CBC解密时调用doFinal失败，返回错误码17630001。

> **说明：**
>
> SM4为分组加密算法，分组长度为128位。ECB、CBC模式下，明文长度不是128位整数倍时，必须使用填充方法补足。
>
> 解密时，doFinal接口会对padding进行校验。

**可能原因**

doFinal失败，表示校验padding失败。解密输入的key和ciphertext，任意一个不正确，都可能会导致该报错。

1. key不正确（SM4密钥应为16字节），update得到的明文不正确，doFinal失败，即校验padding失败。
2. iv不正确（CBC模式下iv为16字节），仅影响第一个密文块的解密，update得到的明文部分不正确，doFinal成功。
3. ciphertext不正确，ECB模式下最后一个密文块错误，或CBC模式下倒数第一或第二个密文块错误时，doFinal失败，即padding校验失败；其他密文块错误，doFinal成功，但得到的明文不正确。
4. ciphertext长度不是16字节（分组大小）的整数倍（使用PKCS7填充时），doFinal失败。

**解决措施**

确认加密和解密的key和iv参数一致，确保解密时输入的ciphertext是正确的。SM4密钥长度为16字节（128位）。

### 使用ChaCha20-Poly1305算法解密时调用doFinal失败

**问题现象**

ChaCha20-Poly1305解密时调用doFinal失败，返回错误码17630001。

> **说明：**
>
> - ChaCha20-Poly1305为认证加密模式，加解密时需要指定附加验证数据aad和认证标签tag。
> - 建议开发者使用update接口加密数据，最后调用doFinal接口完成本次加密，获取tag。
> - 建议开发者使用update接口解密数据，最后调用doFinal接口完成本次解密，doFinal接口内将会对tag进行验证，若失败，接口会抛出异常。

**可能原因**

doFinal失败，表示校验tag失败，解密输入的tag和解密过程中计算的tag不一致。解密输入的key、nonce（IV）、aad、tag和ciphertext，任意一个不正确，都会导致该报错。

1. key值不正确（key长度正确，但key内容不正确），update得到的明文不正确，doFinal失败，即校验tag失败。
2. nonce不正确（nonce为12字节），update得到的明文不正确，doFinal失败，即校验tag失败。
3. aad不正确，update得到的明文正确，doFinal失败，即校验tag失败。
4. ciphertext不正确，update得到的明文不正确，doFinal失败，即校验tag失败。
5. tag不正确，update得到的明文正确，doFinal失败，即校验tag失败。

**解决措施**

确认加密和解密的key、nonce和aad参数一致，确保解密时输入的ciphertext和tag是正确的。
