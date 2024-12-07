# 指定二进制数据转换非对称密钥对(C/C++)


以RSA、ECC、SM2为例，根据指定的对称密钥二进制数据，生成非对称密钥对（OH_CryptoKeyPair），即将外部或存储的二进制数据转换为算法库的密钥对象，该对象可用于后续的加解密等操作。

> **说明：**
>
> 针对非对称密钥的convertKey操作：
>
> - 公钥需满足：ASN.1语法、X.509规范、DER编码格式。
>
> - 私钥需满足：ASN.1语法、PKCS\#8规范、DER编码格式。

## 在CMake脚本中链接相关动态库
```txt
   target_link_libraries(entry PUBLIC libohcrypto.so)
```

## 指定二进制数据转换RSA密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：RSA](crypto-asym-key-generation-conversion-spec.md#rsa)。

1. 获取RSA公钥或私钥二进制数据，封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)。

   公钥和私钥可只传入其中一个，此处示例以传入公钥为例。

2. 调用[OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create)，指定字符串参数'RSA1024'，创建RSA密钥类型为RSA1024、素数个数为2的非对称密钥生成器（OH_CryptoAsymKeyGenerator）。

   生成RSA非对称密钥时，默认素数为2，此处省略了参数PRIMES_2。

3. 调用[OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_convert)，传入二进制密钥数据，生成非对称密钥对象（OH_CryptoKeyPair）。

- 以下以生成RSA密钥对为例：
```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"

static OH_Crypto_ErrCode doTestDataCovertAsymKey()
{
   OH_CryptoAsymKeyGenerator *ctx = nullptr;
   OH_Crypto_ErrCode ret;

   ret = OH_CryptoAsymKeyGenerator_Create("RSA1024|PRIMES_2", &ctx);
   if (ret != CRYPTO_SUCCESS) {
      return ret;
   }

   uint8_t rsaDatablob[] = { 48,129,159,48,13,6,9,42,134,72,134,247,13,1,1,1,5,0,3,129,141,0,
   48,129,137,2,129,129,0,235,184,151,247,130,216,140,187,64,124,219,137,140,184,53,137,216,105,
   156,141,137,165,30,80,232,55,96,46,23,237,197,123,121,27,240,190,14,111,237,172,67,42,47,164,
   226,248,211,157,213,194,131,109,181,41,173,217,127,252,121,126,26,130,55,4,134,104,73,5,132,
   91,214,146,232,64,99,87,33,222,155,159,9,59,212,144,46,183,83,89,220,189,148,13,176,5,139,156,
   230,143,16,152,79,36,8,112,40,174,35,83,82,57,137,87,123,215,99,199,66,131,150,31,143,56,252,2,
   73,41,70,159,2,3,1,0,1 }
   Crypto_DataBlob retBlob = { .data = rsaDatablob, .len = sizeof(rsaDatablob) };

   OH_CryptoKeyPair *dupKeyPair = nullptr;
   ret = OH_CryptoAsymKeyGenerator_Convert(ctx, CRYPTO_DER, &retBlob, nullptr, &dupKeyPair);
   if (ret != CRYPTO_SUCCESS) {
         OH_CryptoAsymKeyGenerator_Destroy(ctx);
         return ret;
   }


   OH_CryptoAsymKeyGenerator_Destroy(ctx);
   OH_CryptoKeyPair_Destroy(dupKeyPair);
   return ret;
}
```

## 指定二进制数据转换ECC密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：ECC](crypto-asym-key-generation-conversion-spec.md#ecc)。

1. 获取ECC公钥或私钥二进制数据，封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)。

   公钥和私钥可只传入其中一个，此处示例以传入公钥、私钥为例。

2. 调用[OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create)，指定字符串参数'ECC256'，创建密钥算法为ECC、密钥长度为256位的非对称密钥生成器（OH_CryptoAsymKeyGenerator）。

3. 调用[OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_convert)，传入公钥二进制和私钥二进制，生成非对称密钥对象（OH_CryptoKeyPair）。

- 以下以生成ECC密钥对为例：
```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"

static OH_Crypto_ErrCode doAsymEccCovert()
{
   OH_CryptoAsymKeyGenerator *ctx = nullptr;
   OH_Crypto_ErrCode ret;

   ret = OH_CryptoAsymKeyGenerator_Create("ECC256", &ctx);
   if (ret != CRYPTO_SUCCESS) {
      return ret;
   }

   uint8_t ecc224PubKeyBlobData[] = {
      48,89,48,19,6,7,42,134,72,206,61,2,1,6,8,42,134, 72,206,61,3,1,7,3,66,0,4,157,58,248,
      205,95,171,229,33,116,44,192,12,115,119,84,156,128,56,180,246,84,43,33,244,224,221,181,
      154,155,222,157,124,131,217,214,134,199,155,61,196,203,107,13,227,121,57,199,109,220,
      103,55,78,148,185,226,212,162,31,66,201,50,129,1,156
   };

   uint8_t ecc224PriKeyBlobData[] = {
      48,49,2,1,1,4,32,255,121,33,196,188,159,112,149,146,107,243,78,152,214,12,119,87,199,
      207,57,116,64,150,240,121,22,88,138,196,71,70,222,160,10,6,8,42,134,72,206,61,3,1,7
   };
   Crypto_DataBlob pubBlob = { .data = ecc224PubKeyBlobData, .len = sizeof(ecc224PubKeyBlobData) };
   Crypto_DataBlob priBlob = { .data = ecc224PriKeyBlobData, .len = sizeof(ecc224PriKeyBlobData) };

   OH_CryptoKeyPair *dupKeyPair = nullptr;
   ret = OH_CryptoAsymKeyGenerator_Convert(ctx, CRYPTO_DER, &pubBlob, &priBlob, &dupKeyPair);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoAsymKeyGenerator_Destroy(ctx);
      return ret;
   }

   OH_CryptoAsymKeyGenerator_Destroy(ctx);
   OH_CryptoKeyPair_Destroy(dupKeyPair);
   return ret;
}
```

## 指定二进制数据转换SM2密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：SM2](crypto-asym-key-generation-conversion-spec.md#sm2)。

1. 获取SM2公钥或私钥二进制数据，封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)。

   公钥和私钥可只传入其中一个，此处示例以传入公钥、私钥为例。

2. 调用[OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create)，指定字符串参数'SM2_256'，创建密钥算法为SM2、密钥长度为256位的非对称密钥生成器（OH_CryptoAsymKeyGenerator）。

3. 调用[OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_convert)，传入公钥二进制和私钥二进制，生成非对称密钥对象（OH_CryptoKeyPair）。

- 以下以生成SM2密钥对为例：
```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"

static OH_Crypto_ErrCode doAsymSm2Covert()
{
   OH_CryptoAsymKeyGenerator *ctx = nullptr;
   OH_CryptoKeyPair *dupKeyPair = nullptr;
   OH_Crypto_ErrCode ret;

   ret = OH_CryptoAsymKeyGenerator_Create("SM2_256", &ctx);
   if (ret != CRYPTO_SUCCESS) {
      return ret;
   }

   uint8_t sm2PubKeyBlobData[] = { 48,89,48,19,6,7,42,134,72,206,61,2,1,6,8,42,134,
      72,206,61,3,1,7,3,66,0,4,157,58,248,205,95,171,229,33,116,44,192,12,115,119,84,156,128,
      56,180,246,84,43,33,244,224,221,181,154,155,222,157,124,131,217,214,134,199,155,61,196,
      203,107,13,227,121,57,199,109,220,103,55,78,148,185,226,212,162,31,66,201,50,129,1,156 };

   uint8_t sm2PriKeyBlobData[] = { 48,49,2,1,1,4,32,255,121,33,196,188,159,112,149,146,
      107,243,78,152,214,12,119,87,199,207,57,116,64,150,240,121,22,88,138,196,71,70,222,160,
      10,6,8,42,134,72,206,61,3,1,7 };
   Crypto_DataBlob pubBlob = { .data = sm2PubKeyBlobData, .len = sizeof(sm2PubKeyBlobData) };
   Crypto_DataBlob priBlob = { .data = sm2PriKeyBlobData, .len = sizeof(sm2PriKeyBlobData) };
   ret = OH_CryptoAsymKeyGenerator_Convert(ctx, CRYPTO_DER, &pubBlob, &priBlob, &dupKeyPair);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoAsymKeyGenerator_Destroy(ctx);
      return ret;
   }

   OH_CryptoAsymKeyGenerator_Destroy(ctx);
   OH_CryptoKeyPair_Destroy(dupKeyPair);
   return ret;
}
```

