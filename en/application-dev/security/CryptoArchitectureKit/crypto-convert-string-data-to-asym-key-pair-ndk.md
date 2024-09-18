# Converting a PEM String into an Asymmetric Key Pair (C/C++)


This topic walks you through on how to convert a string in PEM format into an RSA asymmetric key pair (**OH_CryptoKeyPair**).

> **NOTE**
>
> The **convertPemKey** operation must comply with the following requirements: 
>
> - The public key must comply with X.509 specifications, PKCS\#1 specifications, and PEM encoding format.
>
> - The private key must comply with the PKCS\#8 or PKCS\#1 specifications and the PEM encoding format.
>
> - Currently, only RSA asymmetric keys can be converted.

## Adding the Dynamic Library in the CMake Script
```txt
   target_link_libraries(entry PUBLIC libohcrypto.so)
```


## Converting a String in PEM Format into an RSA Key Pair

For details about the algorithm specifications, see [RSA](crypto-asym-key-generation-conversion-spec.md#rsa).

1. Use [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_create) with the string parameter **'RSA1024'** to create an asymmetric key generator (**OH_CryptoAsymKeyGenerator**) object for a 1024-bit RSA key with two primes.

   The default number of primes for creating an RSA asymmetric key is **2**. The **PRIMES_2** parameter is omitted in the string parameter here.

2. Use [OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptoasymkeygenerator_convert) to convert the binary data into an asymmetric key pair (**OH_CryptoKeyPair**).
3. Use [OH_CryptoPubKey_Encode](../../reference/apis-crypto-architecture-kit/_crypto_asym_key_api.md#oh_cryptopubkey_encode) to convert the public key in the asymmetric key object into PKCS #1 or X.509 format and convert the private key into PKCS #1 or PKCS #8 format.

Example: Convert binary data into an RSA key pair.

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

   uint8_t sm2PubKeyBlobData[] = { 48,129,159,48,13,6,9,42,134,72,134,247,13,1,1,1,5,0,3,129,
      141,0,48,129,137,2,129,129,0,235,184,151,247,130,216,140,187,64,124,219,137,140,184,53,
      137,216,105,156,141,137,165,30,80,232,55,96,46,23,237,197,123,121,27,240,190,14,111,237,
      172,67,42,47,164,226,248,211,157,213,194,131,109,181,41,173,217,127,252,121,126,26,130,
      55,4,134,104,73,5,132,91,214,146,232,64,99,87,33,222,155,159,9,59,212,144,46,183,83,89,
      220,189,148,13,176,5,139,156,230,143,16,152,79,36,8,112,40,174,35,83,82,57,137,87,123,
      215,99,199,66,131,150,31,143,56,252,2,73,41,70,159,2,3,1,0,1 };

   OH_CryptoKeyPair *dupKeyPair = nullptr;
   Crypto_DataBlob pubBlob = { .data = sm2PubKeyBlobData, .len = sizeof(sm2PubKeyBlobData) };
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
   OH_Crypto_FreeDataBlob(retBlob);
   OH_CryptoAsymKeyGenerator_Destroy(ctx);
   OH_CryptoKeyPair_Destroy(dupKeyPair);
   return ret;
}
```
