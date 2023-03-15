# Security Subsystem Changelog

## cl.security.1 ParamsSpec Attribute Name Change
Changed **algoName** of the **ParamsSpec** structure to **algName**.

**Change Impact**

For the released JavaScript APIs that use **ParamsSpec** and its child classes **IvParamsSpec**, **GcmParamsSpec**, and **CcmParamsSpec** as parameters or return values, **algoName** must be changed to **algName**.
The change must be made for all the applications that use these APIs. Otherwise, the compilation in the SDK of the new version cannot be successful.

**Key API/Component Changes**

API prototype before the change:

 ```ts
interface ParamsSpec {
    /**
     * Indicates the algorithm name. Should be set before initialization of a cipher object.
     * @type { string }
     * @syscap SystemCapability.Security.CryptoFramework
     * @since 9
     */
    algoName : string;
}
 ```
API prototype after the change:

 ```ts
interface ParamsSpec {
    /**
     * Indicates the algorithm name. Should be set before initialization of a cipher object.
     * @type { string }
     * @syscap SystemCapability.Security.CryptoFramework
     * @since 9
     */
    algName : string;
}
 ```

**Adaptation Guide**

Change **algoName** to **algName** in **ParamsSpec** and its child classes **IvParamsSpec**, **GcmParamsSpec**, and **CcmParamsSpec**.
 ```ts
function genGcmParamsSpec() {
  let arr = [0, 0, 0, 0 , 0, 0, 0, 0, 0, 0 , 0, 0]; // 12 bytes
  let dataIv = new Uint8Array(arr);
  let ivBlob = {data : dataIv};

  arr = [0, 0, 0, 0 , 0, 0, 0, 0]; // 8 bytes
  let dataAad = new Uint8Array(arr);
  let aadBlob = {data : dataAad};

  arr = [0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0]; // 16 bytes
  let dataTag = new Uint8Array(arr);
  let tagBlob = {data : dataTag};
  let gcmParamsSpec = {iv : ivBlob, aad : aadBlob, authTag : tagBlob, algName : "GcmParamsSpec"};
  return gcmParamsSpec;
}
 ```
For details, see the APIs of **ParamsSpec** in [Crypto Framework](../../../application-dev/reference/apis/js-apis-cryptoFramework.md#paramsspec).

## Change of cl.security.2 ECC Algorithm Parameter Name from ECC512 to ECC521

**Change Impact**

Behavior of released JavaScript APIs will be changed.
The application needs to be adapted to obtain the correct result in the SDK of the new version.

**Key API/Component Changes**
The parameter passed in the APIs is changed from **ECC512** to **ECC521**. The related APIs remain unchanged. For details, see [Key Generation Specifications](../../../application-dev/security/cryptoFramework-overview.md#key-generation-specifications). The following APIs are involved:

cryptoFramework.createAsyKeyGenerator

cryptoFramework.createSign

cryptoFramework.createVerify

cryptoFramework.createKeyAgreement

**Adaptation Guide**

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC521");
```
