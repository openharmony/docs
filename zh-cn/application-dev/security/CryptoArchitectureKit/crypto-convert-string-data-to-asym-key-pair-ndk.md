# 指定PEM格式字符串数据转换非对称密钥对(C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--SE: @lanming-->
<!--TSE: @PAFT-->

以RSA为例，根据指定的非对称密钥字符串数据，生成非对称密钥对（OH_CryptoKeyPair）。

> **说明：**
>
> 针对非对称密钥的convertPemKey操作：
>
> - 公钥需满足X.509规范、PKCS\#1规范、PEM编码格式。
>
> - 私钥需满足PKCS\#8规范、PKCS\#1规范、PEM编码格式。
>
> - 当前只支持RSA非对称密钥的转换。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```

## 指定PEM格式字符串数据转换RSA密钥对

对应的算法规格请查看[非对称密钥生成和转换规格：RSA](crypto-asym-key-generation-conversion-spec.md#rsa)。

1. 调用[OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create)，指定字符串参数'RSA1024'，创建RSA密钥类型为RSA1024、素数个数为2的非对称密钥生成器（OH_CryptoAsymKeyGenerator）。

   生成RSA非对称密钥时，默认素数为2，此处省略了参数PRIMES_2。

2. 调用[OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_convert)，传入二进制密钥数据，生成非对称密钥对象（OH_CryptoKeyPair）。
3. 调用[OH_CryptoPubKey_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_encode)，将非对称密钥对象中的公钥转换成pkcs1或x509格式。

- 以下以生成RSA密钥对为例：

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"

static OH_Crypto_ErrCode doTestPemDataCovertAsymKey()
{
   OH_CryptoAsymKeyGenerator *ctx = nullptr;
   OH_Crypto_ErrCode ret;

   ret = OH_CryptoAsymKeyGenerator_Create("RSA1024", &ctx);
   if (ret != CRYPTO_SUCCESS) {
      return ret;
   }

   uint8_t pubKeyBlobData[] = { 48,129,159,48,13,6,9,42,134,72,134,247,13,1,1,1,5,0,3,129,
      141,0,48,129,137,2,129,129,0,235,184,151,247,130,216,140,187,64,124,219,137,140,184,53,
      137,216,105,156,141,137,165,30,80,232,55,96,46,23,237,197,123,121,27,240,190,14,111,237,
      172,67,42,47,164,226,248,211,157,213,194,131,109,181,41,173,217,127,252,121,126,26,130,
      55,4,134,104,73,5,132,91,214,146,232,64,99,87,33,222,155,159,9,59,212,144,46,183,83,89,
      220,189,148,13,176,5,139,156,230,143,16,152,79,36,8,112,40,174,35,83,82,57,137,87,123,
      215,99,199,66,131,150,31,143,56,252,2,73,41,70,159,2,3,1,0,1 };

   OH_CryptoKeyPair *dupKeyPair = nullptr;
   Crypto_DataBlob pubBlob = { .data = pubKeyBlobData, .len = sizeof(pubKeyBlobData) };
   ret = OH_CryptoAsymKeyGenerator_Convert(ctx, CRYPTO_DER, &pubBlob, nullptr, &dupKeyPair);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoAsymKeyGenerator_Destroy(ctx);
      return ret;
   }

   OH_CryptoPubKey *pubKey1 = OH_CryptoKeyPair_GetPubKey(dupKeyPair);
   Crypto_DataBlob retBlob = { .data = nullptr, .len = 0 };
   ret = OH_CryptoPubKey_Encode(pubKey1, CRYPTO_PEM, "PKCS1", &retBlob);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoAsymKeyGenerator_Destroy(ctx);
      OH_CryptoKeyPair_Destroy(dupKeyPair);
      return ret;
   }
   OH_Crypto_FreeDataBlob(&retBlob);
   OH_CryptoAsymKeyGenerator_Destroy(ctx);
   OH_CryptoKeyPair_Destroy(dupKeyPair);
   return ret;
}
```


