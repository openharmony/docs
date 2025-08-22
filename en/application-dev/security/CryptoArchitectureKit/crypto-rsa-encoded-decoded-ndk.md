# Encoding and Decoding with an RSA Private Key (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

**Encoding**

1. Call [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create) and [OH_CryptoAsymKeyGenerator_Generate](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_generate) to generate an asymmetric key pair (**keyPair**) of the RSA2048 type with two prime numbers. The **keyPair** object includes a public key (**PubKey**) and a private key (**PriKey**).

   For details about how to generate an RSA asymmetric key pair, see the following example. To learn more, see [RSA](crypto-asym-key-generation-conversion-spec.md#rsa) and [Randomly Generating an Asymmetric Key Pair (C/C++)](crypto-generate-asym-key-pair-randomly-ndk.md). There may be differences between the input parameters in the reference documents and those in the following example.

2. Call [OH_CryptoPrivKeyEncodingParams_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkeyencodingparams_create) to create a parameter object (**params**), and call [OH_CryptoPrivKeyEncodingParams_SetParam](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkeyencodingparams_setparam) to set the encryption algorithm and password.

3. Call [OH_CryptoPrivKey_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoprivkey_encode) and pass **CRYPTO_PEM/CRYPTO_DER**, **PKCS1/PCKS8**, and the parameter object (**params**) to generate the encoded private key string.

**Decoding**

1. Call [OH_CryptoAsymKeyGenerator_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoasymkeygenerator_create) to generate an RSA asymmetric key generator (**keyGen**).

   For details about how to generate an RSA asymmetric key pair, see the following example and [RSA](crypto-asym-key-generation-conversion-spec.md#rsa).

2. Call [OH_CryptoAsymKeyGenerator_SetPassword] to pass the encoded private key string and encoding password.

3. Call [OH_CryptoAsymKeyGenerator_Convert] and pass the **CRYPTO_PEM** parameter and the encoded private key string. The RSA key pair is returned.

- Encoding example:
```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode doTestPriKeyPkcs1Encoded()
{
    OH_CryptoAsymKeyGenerator *keyGen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("RSA2048", &keyGen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    OH_CryptoKeyPair *keyPair = nullptr;
    ret = OH_CryptoAsymKeyGenerator_Generate(keyGen, &keyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    OH_CryptoPrivKey *privKey = OH_CryptoKeyPair_GetPrivKey(keyPair);
    if (privKey == nullptr) {
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return CRYPTO_OPERTION_ERROR;
    }
    OH_CryptoPrivKeyEncodingParams *params = nullptr;
    ret = OH_CryptoPrivKeyEncodingParams_Create(&params);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    Crypto_DataBlob password = {(uint8_t *)"1234567890", 10};
    Crypto_DataBlob cipher = {(uint8_t *)"AES-128-CBC", 11};
    ret = OH_CryptoPrivKeyEncodingParams_SetParam(params, CRYPTO_PRIVATE_KEY_ENCODING_PASSWORD_STR, &password);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoPrivKeyEncodingParams_Destroy(params);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }
    ret = OH_CryptoPrivKeyEncodingParams_SetParam(params, CRYPTO_PRIVATE_KEY_ENCODING_SYMMETRIC_CIPHER_STR, &cipher);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoPrivKeyEncodingParams_Destroy(params);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }

    Crypto_DataBlob pemData = {0};
    ret = OH_CryptoPrivKey_Encode(privKey, CRYPTO_PEM, "PKCS1", params, &pemData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoPrivKeyEncodingParams_Destroy(params);
        OH_CryptoKeyPair_Destroy(keyPair);
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }
    OH_Crypto_FreeDataBlob(&pemData);
    OH_CryptoPrivKeyEncodingParams_Destroy(params);
    OH_CryptoKeyPair_Destroy(keyPair);
    OH_CryptoAsymKeyGenerator_Destroy(keyGen);
    return ret;
}
```

- Decoding example:
```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"
#include <string>

static OH_Crypto_ErrCode doTestConvertPemKeyByPromise()
{
    std::string priKeyPkcs1EncodingStr = "-----BEGIN RSA PRIVATE KEY-----\n"
                                         "Proc-Type: 4,ENCRYPTED\n"
                                         "DEK-Info: AES-128-CBC,815A066131BF05CF87CE610A59CC69AE\n\n"
                                         "7Jd0vmOmYGFZ2yRY8fqRl3+6rQlFtNcMILvcb5KWHDSrxA0ULmJE7CW0DSRikHoA\n"
                                         "t0KgafhYXeQXh0dRy9lvVRAFSLHCLJVjchx90V7ZSivBFEq7+iTozVp4AlbgYsJP\n"
                                         "vx/1sfZD2WAcyMJ7IDmJyft7xnpVSXsyWGTT4f3eaHJIh1dqjwrso7ucAW0FK6rp\n"
                                         "/TONyOoXNfXtRbVtxNyCWBxt4HCSclDZFvS9y8fz9ZwmCUV7jei/YdzyQI2wnE13\n"
                                         "W8cKlpzRFL6BWi8XPrUtAw5MWeHBAPUgPWMfcmiaeyi5BJFhQCrHLi+Gj4EEJvp7\n"
                                         "mP5cbnQAx6+paV5z9m71SKrI/WSc4ixsYYdVmlL/qwAK9YliFfoPl030YJWW6rFf\n"
                                         "T7J9BUlHGUJ0RB2lURNNLakM+UZRkeE9TByzCzgTxuQtyv5Lwsh2mAk3ia5x0kUO\n"
                                         "LHg3Eoabhdh+YZA5hHaxnpF7VjspB78E0F9Btq+A41rSJ6zDOdToHey4MJ2nxdey\n"
                                         "Z3bi81TZ6Fp4IuROrvZ2B/Xl3uNKR7n+AHRKnaAO87ywzyltvjwSh2y3xhJueiRs\n"
                                         "BiYkyL3/fnocD3pexTdN6h3JgQGgO5GV8zw/NrxA85mw8o9im0HreuFObmNj36T9\n"
                                         "k5N+R/QIXW83cIQOLaWK1ThYcluytf0tDRiMoKqULiaA6HvDMigExLxuhCtnoF8I\n"
                                         "iOLN1cPdEVQjzwDHLqXP2DbWW1z9iRepLZlEm1hLRLEmOrTGKezYupVv306SSa6J\n"
                                         "OA55lAeXMbyjFaYCr54HWrpt4NwNBX1efMUURc+1LcHpzFrBTTLbfjIyq6as49pH\n"
                                         "-----END RSA PRIVATE KEY-----\n";

    OH_CryptoAsymKeyGenerator *keyGen = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create("RSA2048", &keyGen);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }

    OH_CryptoKeyPair *dupKeyPair = nullptr;
    Crypto_DataBlob priKeyPkcs1EncodingData = {};
    priKeyPkcs1EncodingData.data = reinterpret_cast<uint8_t *>(const_cast<char *>(priKeyPkcs1EncodingStr.c_str()));
    priKeyPkcs1EncodingData.len = strlen(priKeyPkcs1EncodingStr.c_str());
    std::string password = "123456";
    ret = OH_CryptoAsymKeyGenerator_SetPassword(keyGen, reinterpret_cast<const unsigned char *>(password.c_str()),
        password.size());
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }
    ret = OH_CryptoAsymKeyGenerator_Convert(keyGen, CRYPTO_PEM, nullptr, &priKeyPkcs1EncodingData, &dupKeyPair);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoAsymKeyGenerator_Destroy(keyGen);
        return ret;
    }
    OH_CryptoKeyPair_Destroy(dupKeyPair);
    OH_CryptoAsymKeyGenerator_Destroy(keyGen);
    return ret;
}
```
