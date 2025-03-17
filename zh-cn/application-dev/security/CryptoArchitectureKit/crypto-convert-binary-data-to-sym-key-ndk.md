# 指定二进制数据转换对称密钥(C/C++)

以3DES和HMAC为例，根据指定的对称密钥二进制数据，生成密钥（OH_CryptoSymKey），即将外部或存储的二进制数据转换为算法库的密钥对象，该对象可用于后续的加解密等操作。

## 在CMake脚本中链接相关动态库
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```

## 指定二进制数据转换3DES密钥

对应的算法规格请查看[对称密钥生成和转换规格：3DES](crypto-sym-key-generation-conversion-spec.md#3des)。

1. 获取3DES二进制密钥数据，封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)。

2. 调用[OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_create)，指定字符串参数'3DES192'，创建密钥算法为3DES、密钥长度为192位的对称密钥生成器（OH_CryptoSymKeyGenerator）。

3. 调用[OH_CryptoSymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_convert)，根据指定的对称密钥二进制数据，生成对称密钥对象（OH_CryptoSymKey）。

4. 调用[OH_CryptoSymKey_GetKeyData](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkey_getkeydata)，获取密钥对象的二进制数据。

以下以生成3DES密钥为例：

  ```c++
  #include "CryptoArchitectureKit/crypto_common.h"
  #include "CryptoArchitectureKit/crypto_sym_key.h"

  static OH_Crypto_ErrCode doTestDataCovertSymKey() {
      const char *algName = "3DES192";
      OH_CryptoSymKeyGenerator *ctx = nullptr;
      OH_CryptoSymKey *convertKeyCtx = nullptr;
      Crypto_DataBlob out = {.data = nullptr, .len = 0};
      OH_Crypto_ErrCode ret;
      uint8_t arr[] = {0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56, 0xad, 0x47, 0xfc, 0x5a,
                      0x46, 0x39, 0xee, 0x7c, 0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72};
      Crypto_DataBlob convertBlob = {.data = arr, .len = sizeof(arr)};
      ret = OH_CryptoSymKeyGenerator_Create(algName, &ctx);
      if (ret != CRYPTO_SUCCESS) {
          return ret;
      }
      ret = OH_CryptoSymKeyGenerator_Convert(ctx, &convertBlob, &convertKeyCtx);
      if (ret != CRYPTO_SUCCESS) {
          OH_CryptoSymKeyGenerator_Destroy(ctx);
          return ret;
      }
      ret = OH_CryptoSymKey_GetKeyData(convertKeyCtx, &out);
      OH_CryptoSymKeyGenerator_Destroy(ctx);
      OH_CryptoSymKey_Destroy(convertKeyCtx);
      if (ret != CRYPTO_SUCCESS) {
          return ret;
      }
      OH_Crypto_FreeDataBlob(&out);
      return ret;
  }
  ```

## 指定二进制数据转换HMAC密钥

对应的算法规格请查看[对称密钥生成和转换规格：HMAC](crypto-sym-key-generation-conversion-spec.md#hmac)。

1. 获取HMAC二进制密钥，封装成[Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob)。

2. 调用[OH_CryptoSymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_create)，指定字符串参数'HMAC'，创建密钥算法为HMAC、密钥长度为[1, 32768]位的对称密钥生成器（OH_CryptoSymKeyGenerator）。

3. 调用[OH_CryptoSymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkeygenerator_convert)，根据指定的对称密钥二进制数据，生成对称密钥对象（OH_CryptoSymKey）。

4. 调用[OH_CryptoSymKey_GetKeyData](../../reference/apis-crypto-architecture-kit/_crypto_sym_key_api.md#oh_cryptosymkey_getkeydata)，获取密钥对象的二进制数据。

以下以生成HMAC密钥为例：

  ```c++
  #include "CryptoArchitectureKit/crypto_common.h"
  #include "CryptoArchitectureKit/crypto_sym_key.h"
  #include <string.h>

  static OH_Crypto_ErrCode testConvertHmacKey() {
      const char *algName = "HMAC";
      OH_CryptoSymKeyGenerator *ctx = nullptr;
      OH_CryptoSymKey *convertKeyCtx = nullptr;
      Crypto_DataBlob out = {.data = nullptr, .len = 0};
      OH_Crypto_ErrCode ret;

      char *arr = const_cast<char *>("12345678abcdefgh12345678abcdefgh12345678abcdefgh12345678abcdefgh");
      Crypto_DataBlob convertBlob = {.data = (uint8_t *)(arr), .len = strlen(arr)};
      ret = OH_CryptoSymKeyGenerator_Create(algName, &ctx);
      if (ret != CRYPTO_SUCCESS) {
          return ret;
      }
      ret = OH_CryptoSymKeyGenerator_Convert(ctx, &convertBlob, &convertKeyCtx);
      if (ret != CRYPTO_SUCCESS) {
          OH_CryptoSymKeyGenerator_Destroy(ctx);
          return ret;
      }
      ret = OH_CryptoSymKey_GetKeyData(convertKeyCtx, &out);
      OH_CryptoSymKeyGenerator_Destroy(ctx);
      OH_CryptoSymKey_Destroy(convertKeyCtx);
      if (ret != CRYPTO_SUCCESS) {
          return ret;
      }
      OH_Crypto_FreeDataBlob(&out);
      return ret;
  }
  ```
