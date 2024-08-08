# Converting Binary Data into an Asymmetric Key Pair (C/C++)


This topic uses RSA, ECC, and SM2 as an example to describe how to convert binary data into an asymmetric key pair (**OH_CryptoKeyPair**). That is, convert a piece of external or internal binary data into a **KeyPair** object for subsequent operations, such as encryption and decryption.

> **NOTE**
>
> The asymmetric key conversion must comply with the following requirements: 
>
> - The public key must use the ASN.1 syntax and DER encoding format and comply with X.509 specifications.
>
> - The private key must use the ASN.1 syntax and DER encoding format and comply with PKCS\#8 specifications.

## Adding the Dynamic Library in the CMake Script
```txt
   target_link_libraries(entry PUBLIC libohcrypto.so)
```

## Converting Binary Data into an RSA Key Pair

For details about the algorithm specifications, see [RSA](crypto-asym-key-generation-conversion-spec.md#rsa).

1. Obtain the binary data of the RSA public key or private key and encapsulates the data into [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob).

   Either the public key or private key can be passed in. In this example, the public key is passed in.

2. Use [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create) with the string parameter **'RSA1024'** to create an asymmetric key generator (**OH_CryptoAsymKeyGenerator**) object for a 1024-bit RSA key with two primes.

   The default number of primes for creating an RSA asymmetric key is **2**. The **PRIMES_2** parameter is omitted in the string parameter here.

3. Use [OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_convert) to convert the binary data into an asymmetric key pair (**OH_CryptoKeyPair**).

- Example: Convert binary data into an RSA key pair.
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

## Converting Binary Data into an ECC Key Pair

For details about the algorithm specifications, see [ECC](crypto-asym-key-generation-conversion-spec.md#ecc).

1. Obtain the binary data of the ECC public key or private key and encapsulates the data into [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob).

   Either the public key or private key can be passed in. In the following example, the public key and private key are passed in separately.

2. Use [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create) with the string parameter **'ECC256'** to create an asymmetric key generator (**OH_CryptoAsymKeyGenerator**) object for a 256-bit ECC key pair.

3. Use [OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_convert) to convert the binary data into an asymmetric key pair (**OH_CryptoKeyPair**).

- Example: Convert binary data into an ECC key pair.
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

## Converting PKCS #8 Binary Data into an ECC Private Key

For details about the algorithm specifications, see [ECC](crypto-asym-key-generation-conversion-spec.md#ecc).

Obtain the binary data of the ECC public or private key, encapsulate the data into a [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob) object, and convert the data into the ECC key format.  

1. Use [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create) with the string parameter **'ECC256'** to create an asymmetric key generator (**OH_CryptoAsymKeyGenerator**) object for a 256-bit ECC key pair.
2. Use [OH_CryptoPubKey_Encode](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptopubkey_encode) to obtain the public key data byte stream.
3. Use [OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_convert) to convert the binary key data into an asymmetric key object (**OH_CryptoKeyPair**).

**Example**

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"

static OH_Crypto_ErrCode doAsymEccCovert() 
{
   OH_CryptoAsymKeyGenerator *ctx = nullptr;
   OH_CryptoKeyPair *keyPair = nullptr;
   OH_Crypto_ErrCode ret;

   ret = OH_CryptoAsymKeyGenerator_Create("ECC256", &ctx);
   if (ret != CRYPTO_SUCCESS) {
      return ret;
   }

   ret = OH_CryptoAsymKeyGenerator_Generate(ctx, &keyPair);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoAsymKeyGenerator_Destroy(ctx);
      return ret;
   }

   OH_CryptoPubKey *pubKey = OH_CryptoKeyPair_GetPubKey(keyPair);
   Crypto_DataBlob retBlob = { .data = nullptr, .len = 0 };
   ret = OH_CryptoPubKey_Encode(pubKey, CRYPTO_DER, nullptr, &retBlob);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoAsymKeyGenerator_Destroy(ctx);
      OH_CryptoKeyPair_Destroy(keyPair);
      return ret;
   }

   OH_CryptoKeyPair *dupKeyPair = nullptr;
   ret = OH_CryptoAsymKeyGenerator_Convert(ctx, CRYPTO_DER, &retBlob, nullptr, &dupKeyPair);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoAsymKeyGenerator_Destroy(ctx);
      OH_CryptoKeyPair_Destroy(keyPair);
      return ret;
   }

   OH_Crypto_FreeDataBlob(&retBlob);
   OH_CryptoAsymKeyGenerator_Destroy(ctx);
   OH_CryptoKeyPair_Destroy(keyPair);
   OH_CryptoKeyPair_Destroy(dupKeyPair);
   return ret;
}
```

## Converting Binary Data into an SM2 Key Pair

For details about the algorithm specifications, see [SM2](crypto-asym-key-generation-conversion-spec.md#sm2).

1. Obtain the binary data of the SM2 public key or private key and encapsulate the data into [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/_crypto_common_api.md#crypto_datablob).

   Either the public key or private key can be passed in. In the following example, the public key and private key are passed in separately.

2. Use [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create) with the string parameter **'SM2_256'** to create an asymmetric key generator (**OH_CryptoAsymKeyGenerator**) object for a 256-bit SM2 key pair.

3. Use [OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_convert) to convert the binary data into an asymmetric key pair (**OH_CryptoKeyPair**).

Example: Convert binary data into an SM2 key pair.

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
