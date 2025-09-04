# Signing and Signature Verification with an ECDSA Key Pair (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

For details about the algorithm specifications, see [ECDSA](crypto-sign-sig-verify-overview.md#ecdsa).

## Adding the Dynamic Library in the CMake Script
```txt
target_link_libraries(entry PUBLIC libohcrypto.so)
```

## Signing Data
1. Call [OH_CryptoSign_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptosign_create) with the string parameter **'RSA2048|PSS|SHA256|MGF1_SHA256'** to create a **Sign** instance. As indicated by the string parameter, the asymmetric key type is **RSA2048**, the padding mode is **PSS**, the MD algorithm is **SHA256**, and mask algorithm is **MGF1_SHA256**.

2. Call [OH_CryptoSign_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptosign_init) to initialize the **Sign** instance using [OH_CryptoPrivKey](../../reference/apis-crypto-architecture-kit/capi-cryptoasymkeyapi-oh-cryptoprivkey.md).

3. Call [OH_CryptoSign_Update](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptosign_update) to pass in the data to be signed. Currently, the amount of data to be passed in by a single **OH_CryptoVerify_Update** is not limited. You can determine how to pass in data based on the data volume. If a small amount of data is to be verified, you can directly call **OH_CryptoSign_Final** after **OH_CryptoVerify_Init()**.

4. Call [OH_CryptoSign_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptosign_final) to sign the data.

5. Call [OH_CryptoSign_Destroy](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptosign_destroy) to free the memory.

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_signature.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"

static OH_Crypto_ErrCode doTestRsaPssSignSeg() {
   OH_CryptoAsymKeyGenerator *keyCtx = nullptr;
   OH_CryptoKeyPair *keyPair = nullptr;
   OH_CryptoSign *sign = nullptr;
   Crypto_DataBlob signData = {.data = nullptr, .len = 0};

   uint8_t plainText[] = {
      0xe4, 0x2b, 0xcc, 0x08, 0x11, 0x79, 0x16, 0x1b, 0x35, 0x7f, 0xb3, 0xaf, 0x40, 0x3b, 0x3f, 0x7c
   }; // Data to be signed, for reference only.
   Crypto_DataBlob msgBlob = {
      .data = reinterpret_cast<uint8_t *>(plainText),
      .len = sizeof(plainText)
   };

   OH_Crypto_ErrCode ret = OH_CryptoAsymKeyGenerator_Create((const char *)"ECC256", &keyCtx);
   if (ret != CRYPTO_SUCCESS) {
      return ret;
   }
   ret = OH_CryptoAsymKeyGenerator_Generate(keyCtx, &keyPair);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
      return ret;
   }

   OH_CryptoPrivKey *privKey = OH_CryptoKeyPair_GetPrivKey(keyPair);
   ret = OH_CryptoSign_Create((const char *)"ECC256|SHA256", &sign);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
      OH_CryptoKeyPair_Destroy(keyPair);
      return ret;
   }

   ret = OH_CryptoSign_Init(sign, privKey);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoSign_Destroy(sign);
      OH_CryptoKeyPair_Destroy(keyPair);
      OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
      return ret;
   }
   ret = OH_CryptoSign_Update(sign, &msgBlob);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoSign_Destroy(sign);
      OH_CryptoKeyPair_Destroy(keyPair);
      OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
      return ret;
   }
   ret = OH_CryptoSign_Final(sign, nullptr, &signData);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoSign_Destroy(sign);
      OH_CryptoKeyPair_Destroy(keyPair);
      OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
      return ret;
   }

   OH_CryptoSign_Destroy(sign);
   OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
   OH_CryptoKeyPair_Destroy(keyPair);
   return CRYPTO_SUCCESS;
}
```

## Verifying the Signature

1. Call [OH_CryptoVerify_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoverify_create) with the string parameter **'ECC256|SHA256'** to create a **Verify** instance. The key type is **ECC256**, and MD algorithm is **SHA256**.

2. Call [OH_CryptoVerify_Init](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoverify_init) to initialize the **Verify** instance by using the public key (**OH_CryptoPubKey**).

3. Call [OH_CryptoVerify_Update](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoverify_update) to pass in the data to be verified. Currently, the amount of data to be passed in by a single **OH_CryptoVerify_Update** is not limited. You can determine how to pass in data based on the data volume. If a small amount of data is to be verified, you can call **OH_CryptoVerify_Final** immediately after **OH_CryptoVerify_Init()**.

4. Call [OH_CryptoVerify_Final](../../reference/apis-crypto-architecture-kit/capi-crypto-signature-h.md#oh_cryptoverify_final) to verify the signature.

```c++
#include "CryptoArchitectureKit/crypto_common.h"
#include "CryptoArchitectureKit/crypto_signature.h"
#include "CryptoArchitectureKit/crypto_asym_key.h"

static bool doTestEcdsaSignature()
{
   OH_CryptoAsymKeyGenerator *keyCtx = nullptr;
   OH_CryptoKeyPair *keyPair = nullptr;
   OH_CryptoVerify *verify = nullptr;

   uint8_t plainText[] = {
      0xe4, 0x2b, 0xcc, 0x08, 0x11, 0x79, 0x16, 0x1b, 0x35, 0x7f, 0xb3, 0xaf, 0x40, 0x3b, 0x3f, 0x7c
   }; // Data to be verified, for reference only.
   Crypto_DataBlob msgBlob = {
      .data = reinterpret_cast<uint8_t *>(plainText),
      .len = sizeof(plainText)
   };

   uint8_t pubKeyText[] = {
      0x30, 0x39, 0x30, 0x13, 0x06, 0x07, 0x2a, 0x86, 0x48, 0xce, 0x3d, 0x02, 0x01, 0x06, 0x08, 0x2a,
      0x86, 0x48, 0xce, 0x3d, 0x03, 0x01, 0x07, 0x03, 0x22, 0x00, 0x03, 0x4d, 0xe4, 0xbb, 0x11, 0x10,
      0x1a, 0xd2, 0x05, 0x74, 0xf1, 0x0b, 0xb4, 0x75, 0x57, 0xf4, 0x3e, 0x55, 0x14, 0x17, 0x05, 0x4a,
      0xb2, 0xfb, 0x8c, 0x84, 0x64, 0x38, 0x02, 0xa0, 0x2a, 0xa6, 0xf0
   }; // Public key in DER format, for reference only.

   Crypto_DataBlob keyBlob = {
      .data = reinterpret_cast<uint8_t *>(pubKeyText),
      .len = sizeof(pubKeyText)
   };

   uint8_t signText[] = {
      0x30, 0x44, 0x02, 0x20, 0x21, 0x89, 0x99, 0xb1, 0x56, 0x4e, 0x3a, 0x2c, 0x16, 0x08, 0xb5, 0x8a,
      0x06, 0x6f, 0x67, 0x47, 0x1b, 0x04, 0x18, 0x7d, 0x53, 0x2d, 0xba, 0x00, 0x38, 0xd9, 0xe3, 0xe7,
      0x8c, 0xcf, 0x76, 0x83, 0x02, 0x20, 0x13, 0x54, 0x84, 0x9d, 0x73, 0x40, 0xc3, 0x92, 0x66, 0xdc,
      0x3e, 0xc9, 0xf1, 0x4c, 0x33, 0x84, 0x2a, 0x76, 0xaf, 0xc6, 0x61, 0x84, 0x5c, 0xae, 0x4b, 0x0d,
      0x3c, 0xb0, 0xc8, 0x04, 0x89, 0x71
   }; // Signature data, for reference only.

   Crypto_DataBlob signBlob = {
      .data = reinterpret_cast<uint8_t *>(signText),
      .len = sizeof(signText)
   };
   
   OH_Crypto_ErrCode ret = CRYPTO_SUCCESS;

   ret = OH_CryptoAsymKeyGenerator_Create((const char *)"ECC256", &keyCtx);
   if (ret != CRYPTO_SUCCESS) {
      return false;
   }
   ret = OH_CryptoAsymKeyGenerator_Convert(keyCtx, CRYPTO_DER, &keyBlob, nullptr, &keyPair); // Convert the public key in DER format to OH_CryptoKeyPair.
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
      return false;
   }
   OH_CryptoPubKey *pubKey = OH_CryptoKeyPair_GetPubKey(keyPair); // Obtain the public key object.
   // verify
   ret = OH_CryptoVerify_Create((const char *)"ECC256|SHA256", &verify); // Create a Verify instance.
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoVerify_Destroy(verify);
      OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
      return false;
   }
   ret = OH_CryptoVerify_Init(verify, pubKey);
   if (ret != CRYPTO_SUCCESS) {
      OH_CryptoVerify_Destroy(verify);
      OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
      return false;
   }
   bool res = OH_CryptoVerify_Final(verify, &msgBlob, &signBlob);
   if (res != true) {
      OH_CryptoVerify_Destroy(verify);
      OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
      return false;
   }

   OH_CryptoVerify_Destroy(verify);
   OH_CryptoAsymKeyGenerator_Destroy(keyCtx);
   OH_CryptoKeyPair_Destroy(keyPair);
   return res;
}
```
