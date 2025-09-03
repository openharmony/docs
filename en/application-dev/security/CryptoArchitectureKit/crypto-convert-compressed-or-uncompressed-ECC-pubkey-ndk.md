# Converting a Compressed or Uncompressed ECC Public Key (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

You can generate a public key object [PubKey](../../reference/apis-crypto-architecture-kit/capi-cryptoasymkeyapi-oh-cryptopubkey.md) from ECC public key data or obtain the ECC public key data from a public key (**PubKey**) object.
Currently, the system supports only the X.509-certified compressed or uncompressed ECC public key data, which must be complete. The public key data mentioned in this topic is a complete X.509 public key. For details about the operations on point data, see [Converting Compressed or Uncompressed ECC Point Data](crypto-convert-compressed-or-uncompressed-ECC-point.md).   
For details, see the ECC section of [Asymmetric Key Generation and Conversion Specifications](crypto-asym-key-generation-conversion-spec.md). 
<br>You can pass in the string parameter to set the format of the ECC public key to obtain. To obtain a compressed public key that complies with the X.509 standard, pass in **X509|COMPRESSED**. To obtain an uncompressed public key, pass in **X509|UNCOMPRESSED**.

##  Converting Uncompressed Public Key Data to Compressed Public Key Data

1. Specify uncompressed ECC public key data of the uint8_t type and encapsulate the data into a [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md) object. 
The public key and private key can be passed separately. In this example, the non-compressed public key is passed.
2. Call [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate) with the string parameter **'ECC_BrainPoolP256r1'** to create an asymmetric key generator (**OH_CryptoAsymKeyGenerator**) object for a 256-bit ECC key.
3. Call [OH_CryptoAsymKeyGenerator_Convert](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_convert) and pass the encapsulated [Crypto_DataBlob](../../reference/apis-crypto-architecture-kit/capi-cryptocommonapi-crypto-datablob.md) to generate an asymmetric key object (**OH_CryptoKeyPair**).
4. Call [OH_CryptoPubKey_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptopubkey_encode) with the parameter set to **'X509|COMPRESSED'** to obtain the byte stream of the compressed public key data.

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"

static OH_Crypto_ErrCode doTestEccDataCovert()
{
    OH_CryptoAsymKeyGenerator *generator = nullptr;
    OH_CryptoKeyPair *keyPair = nullptr;
    Crypto_DataBlob returnBlob = { .data = nullptr, .len = 0 };
    OH_Crypto_ErrCode ret = CRYPTO_INVALID_PARAMS;

    ret = OH_CryptoAsymKeyGenerator_Create("ECC_BrainPoolP256r1", &generator);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    uint8_t pubKeyBlobData[] = {
        48, 90, 48, 20, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 9, 43, 36, 3, 3, 2,
        8, 1, 1, 7, 3, 66, 0, 4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 
        121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111, 40, 217, 215,
        148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85,
        228,123, 242, 206, 200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 
        46, 163, 156, 152
    };
    Crypto_DataBlob pubKeyUncompressedBlob = {
        .data = pubKeyBlobData,
        .len = sizeof(pubKeyBlobData),
    };
    ret = OH_CryptoAsymKeyGenerator_Convert(generator, CRYPTO_DER, &pubKeyUncompressedBlob, nullptr, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(generator);
        return ret;
    }

    OH_CryptoPubKey *pubKey = OH_CryptoKeyPair_GetPubKey(keyPair);
    ret = OH_CryptoPubKey_Encode(pubKey, CRYPTO_DER, "X509|COMPRESSED", &returnBlob);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(generator);
        OH_CryptoKeyPair_Destroy(keyPair);
        return ret;
    }
    OH_CryptoAsymKeyGenerator_Destroy(generator);
    OH_CryptoKeyPair_Destroy(keyPair);
    OH_Crypto_FreeDataBlob(&returnBlob);
    return ret;
}
```
