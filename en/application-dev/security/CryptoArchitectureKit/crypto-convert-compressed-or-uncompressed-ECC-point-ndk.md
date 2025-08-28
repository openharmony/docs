# Converting Compressed or Uncompressed ECC Point Data (C/C++)

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

You can convert compressed or uncompressed point data into a **Point** object for generating a key object, or convert a **Point** object into compressed or uncompressed point data.<br>
For details about the ECC algorithm specifications, see [ECC](crypto-asym-key-generation-conversion-spec.md#ecc).<br>
You can pass in the string parameter **format** to specify the format of the point data to obtain. To obtain compressed point data, set **format** to **COMPRESSED**. To obtain uncompressed point data, set **format** to **UNCOMPRESSED**.

## Converting Uncompressed Point Data into Compressed Point Data

1. Pass the uncompressed ECC point data of the uint8_t type, and call [OH_CryptoEcPoint_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoecpoint_create) to construct a [OH_CryptoEcPoint](../../reference/apis-crypto-architecture-kit/capi-cryptoasymkeyapi-oh-cryptoecpoint.md) object for generating point data.
2. Call [OH_CryptoEcPoint_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoecpoint_encode) to obtain the compressed point data.

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode doTestEccPointUncompressedToCompressed()
{
    uint8_t pk[] = {
        4, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111,
        40, 217, 215, 148, 120, 224, 205, 82, 83, 92, 185, 21, 211, 184, 5, 19, 114, 33, 86, 85, 228, 123, 242, 206,
        200, 98, 178, 184, 130, 35, 232, 45, 5, 202, 189, 11, 46, 163, 156, 152
    };
    Crypto_DataBlob pkData = {pk, sizeof(pk)};
    OH_CryptoEcPoint *point = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoEcPoint_Create("NID_brainpoolP256r1", &pkData, &point);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    Crypto_DataBlob returnPointBlobData = {0};
    ret = OH_CryptoEcPoint_Encode(point, "COMPRESSED", &returnPointBlobData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoEcPoint_Destroy(point);
        return ret;
    }
    OH_Crypto_FreeDataBlob(&returnPointBlobData);
    OH_CryptoEcPoint_Destroy(point);
    return ret;
}
```

## Converting Compressed Point Data into a Key Object

1. Pass the compressed ECC point data of the uint8_t type, and call [OH_CryptoEcPoint_Create](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoecpoint_create) to construct a [OH_CryptoEcPoint](../../reference/apis-crypto-architecture-kit/capi-cryptoasymkeyapi-oh-cryptoecpoint.md) object for generating point data.
2. Call [OH_CryptoEcPoint_Encode](../../reference/apis-crypto-architecture-kit/capi-crypto-asym-key-h.md#oh_cryptoecpoint_encode) to obtain the uncompressed point data.

```C++
#include "CryptoArchitectureKit/crypto_architecture_kit.h"

static OH_Crypto_ErrCode doTestEccPointeccPointCompressedToPoint()
{
    uint8_t pk[] = {
        2, 143, 39, 57, 249, 145, 50, 63, 222, 35, 70, 178, 121, 202, 154, 21, 146, 129, 75, 76, 63, 8, 195, 157, 111,
        40, 217, 215, 148, 120, 224, 205, 82
    };
    Crypto_DataBlob pkData = {pk, sizeof(pk)};
    OH_CryptoEcPoint *point = nullptr;
    OH_Crypto_ErrCode ret = OH_CryptoEcPoint_Create("NID_brainpoolP256r1", &pkData, &point);
    if (ret != CRYPTO_SUCCESS) {
        return ret;
    }
    Crypto_DataBlob returnPointBlobData = {0};
    ret = OH_CryptoEcPoint_Encode(point, "UNCOMPRESSED", &returnPointBlobData);
    if (ret != CRYPTO_SUCCESS) {
        OH_CryptoEcPoint_Destroy(point);
        return ret;
    }
    OH_Crypto_FreeDataBlob(&returnPointBlobData);
    OH_CryptoEcPoint_Destroy(point);
    return ret;
}
```
