# Crypto Framework Development

> **NOTE**
>
> This guide applies only to JavaScript development using the SDK of API version 9 or later.

## Key Generation and Conversion

### When to Use

Typical key generation operations involve the following:

1. Randomly create a key object for subsequent encryption and decryption.
2. Create a key object based on the specified key parameters for subsequent encryption and decryption.
3. Convert external or internal binary data into a key object for subsequent encryption and decryption.
4. Obtain the binary data of a key object for storage or transmission.
5. Obtain the parameter properties of an asymmetric key object for storage or transmission.

> **NOTE**
>
> The key object can be a symmetric key object (**SymKey**) or an asymmetric key pair object (**KeyPair**). The **KeyPair** object consists a public key (**PubKey**) and a private key (**PriKey**). For details about the relationship between the keys, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

### Available APIs

The following table describes the APIs used in typical key generation operations. For more information about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).


|Instance|API|Description|
|---|---|---|
|cryptoFramework|createAsyKeyGenerator(algName : string) : AsyKeyGenerator|Creates an **AsyKeyGenerator** instance based on the asymmetric key pair specifications specified by **algName**.|
|cryptoFramework|createAsyKeyGeneratorBySpec(asyKeySpec: AsyKeySpec): AsyKeyGeneratorBySpec;|Creates an **AsyKeyGenerator** instance based on the asymmetric key specifications specified by the key parameter.|
|cryptoFramework|createSymKeyGenerator(algName : string) : SymKeyGenerator|Creates a **SymKeyGenerator** instance.|
|AsyKeyGenerator|generateKeyPair(callback : AsyncCallback\<KeyPair>) : void|Generates an asymmetric key pair randomly. This API uses an asynchronous callback to return the result.|
|AsyKeyGenerator|generateKeyPair() : Promise\<KeyPair>|Generates an asymmetric key pair randomly. This API uses a promise to return the result.|
|SymKeyGenerator|generateSymKey(callback : AsyncCallback\<SymKey>) : void|Generates a symmetric key randomly. This API uses an asynchronous callback to return the result.|
|SymKeyGenerator|generateSymKey() : Promise\<SymKey>|Generates a symmetric key randomly. This API uses a promise to return the result.|
| AsyKeyGenerator          | convertKey(pubKey : DataBlob, priKey : DataBlob, callback : AsyncCallback\<KeyPair>) : void | Converts binary data into a key pair. This API uses an asynchronous callback to return the result.<br>(**pubKey** or **priKey** can be **null**. That is, you can pass in only **pubKey** or **priKey**. As a result, the returned **KeyPair** instance contains only the public or private key.)|
| AsyKeyGenerator          | convertKey(pubKey : DataBlob, priKey : DataBlob) : Promise\<KeyPair> | Converts binary data into a key pair. This API uses a promise to return the result.<br>(**pubKey** or **priKey** can be **null**. That is, you can pass in only **pubKey** or **priKey**. As a result, the returned **KeyPair** instance contains only the public or private key.)|
| SymKeyGenerator         | convertKey(key : DataBlob, callback : AsyncCallback\<SymKey>) : void| Converts binary data into a symmetric key. This API uses an asynchronous callback to return the result.|
| SymKeyGenerator         |convertKey(pubKey : DataBlob, priKey : DataBlob) : Promise\<KeyPair>| Converts binary data into a symmetric key. This API uses a promise to return the result.|
| Key | getEncoded() : DataBlob;  | Obtains the binary data of a key. (The child class instances of **Key** include **SymKey**, **PubKey**, and **PriKey**.)|

### Randomly Generating an RSA Key Pair and Obtaining the Binary Data

Randomly generate an asymmetric key pair and obtain its binary data.

1. Create an **AsyKeyGenerator** instance.
2. Randomly generate an asymmetric key pair using **AsyKeyGenerator**.
3. Obtain the binary data of the key pair generated.

Example: Randomly generate an RSA key (1024 bits and two primes) in promise mode.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function generateAsyKey() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024|PRIMES_2');
  // Use the key generator to randomly generate an asymmetric key pair.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    // Obtain the binary data of the asymmetric key pair.
    let pkBlob = pubKey.getEncoded();
    let skBlob = priKey.getEncoded();
    AlertDialog.show({ message: 'pk bin data' + pkBlob.data });
    AlertDialog.show({ message: 'sk bin data' + skBlob.data });
  })
}
```

### Randomly Generating an AES Key and Obtaining the Binary Data

Randomly generate a symmetric key and obtain its binary data.

1. Create a **SymKeyGenerator** instance.
2. Randomly generate a symmetric key using **SymKeyGenerator**.
3. Obtain the binary data of the key generated.

Example: Randomly generate an AES key (256 bits) in promise mode.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// Output the byte streams in hexadecimal format.
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

function testGenerateAesKey() {
  // Create a SymKeyGenerator instance.
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('AES256');
  // Use the key generator to randomly generate a symmetric key.
  let promiseSymKey = symKeyGenerator.generateSymKey();
  promiseSymKey.then(key => {
    // Obtain the binary data of the symmetric key and output the 256-bit key in hexadecimal format. The length is 64, that is, 32 bytes.
    let encodedKey = key.getEncoded();
    console.info('key hex:' + uint8ArrayToShowStr(encodedKey.data));
  })
}
```

### Converting Binary Data into an RSA Key Pair

Generate an RSA asymmetric key pair from the binary data.

1. Obtain the binary data of the RSA public or private key. The public key must comply with the ASN.1 syntax, X.509 specifications, and DER encoding format. The private key must comply with the ASN.1 syntax, PKCS #8 specifications, and DER encoding format.
2. Create an **AsyKeyGenerator** instance, and use **convertKey()** to convert the key binary data (data of the private or public key, or both) into a **KeyPair** instance.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function convertAsyKey() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator('RSA1024');
  let pkVal = new Uint8Array([48, 129, 159, 48, 13, 6, 9, 42, 134, 72, 134, 247, 13, 1, 1, 1, 5, 0, 3, 129, 141, 0, 48, 129, 137, 2, 129, 129, 0, 174, 203, 113, 83, 113, 3, 143, 213, 194, 79, 91, 9, 51, 142, 87, 45, 97, 65, 136, 24, 166, 35, 5, 179, 42, 47, 212, 79, 111, 74, 134, 120, 73, 67, 21, 19, 235, 80, 46, 152, 209, 133, 232, 87, 192, 140, 18, 206, 27, 106, 106, 169, 106, 46, 135, 111, 118, 32, 129, 27, 89, 255, 183, 116, 247, 38, 12, 7, 238, 77, 151, 167, 6, 102, 153, 126, 66, 28, 253, 253, 216, 64, 20, 138, 117, 72, 15, 216, 178, 37, 208, 179, 63, 204, 39, 94, 244, 170, 48, 190, 21, 11, 73, 169, 156, 104, 193, 3, 17, 100, 28, 60, 50, 92, 235, 218, 57, 73, 119, 19, 101, 164, 192, 161, 197, 106, 105, 73, 2, 3, 1, 0, 1]);
  let pkBlob = { data: pkVal };
  rsaGenerator.convertKey(pkBlob, null, (err, keyPair) => {
    if (err) {
      AlertDialog.show({ message: 'Convert keyPair fail' });
      return;
    }
    AlertDialog.show({ message: 'Convert keyPair success' });
  })
}
```

> **NOTE**
>
> The public key binary data to be converted by **convertKey()** must be in the DER format complying with X.509 specifications, and the private key binary data must be in the DER format complying with PKCS #8 specifications.

### Converting Binary Data into an ECC Key Pair

Generate an ECC asymmetric key pair from the binary data.

1. Obtain the ECC binary key data and encapsulate it into a **DataBlob** instance.
2. Use **convertKey()** to convert the binary data (data of the private or public key, or both) into a **KeyPair** instance.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function convertEccAsyKey() {
  let pubKeyArray = new Uint8Array([48, 89, 48, 19, 6, 7, 42, 134, 72, 206, 61, 2, 1, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7, 3, 66, 0, 4, 83, 96, 142, 9, 86, 214, 126, 106, 247, 233, 92, 125, 4, 128, 138, 105, 246, 162, 215, 71, 81, 58, 202, 121, 26, 105, 211, 55, 130, 45, 236, 143, 55, 16, 248, 75, 167, 160, 167, 106, 2, 152, 243, 44, 68, 66, 0, 167, 99, 92, 235, 215, 159, 239, 28, 106, 124, 171, 34, 145, 124, 174, 57, 92]);
  let priKeyArray = new Uint8Array([48, 49, 2, 1, 1, 4, 32, 115, 56, 137, 35, 207, 0, 60, 191, 90, 61, 136, 105, 210, 16, 27, 4, 171, 57, 10, 61, 123, 40, 189, 28, 34, 207, 236, 22, 45, 223, 10, 189, 160, 10, 6, 8, 42, 134, 72, 206, 61, 3, 1, 7]);
  let pubKeyBlob = { data: pubKeyArray };
  let priKeyBlob = { data: priKeyArray };
  let generator = cryptoFramework.createAsyKeyGenerator('ECC256');
  generator.convertKey(pubKeyBlob, priKeyBlob, (error, data) => {
    if (error) {
      AlertDialog.show({ message: 'Convert keyPair fail' });
      return;
    }
    AlertDialog.show({ message: 'Convert keyPair success' });
  })
}
```

### Converting Binary Data into a 3DES Key

Generate a symmetric key from the binary data.

1. Create a **SymKeyGenerator** instance.
2. Convert the binary data into a **SymKey** instance.
3. Obtain the binary data of the key instance generated.

Example: Generate a 3DES key (192 bits only) in callback mode.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// Output the byte streams in hexadecimal format.
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

function genKeyMaterialBlob() {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72]; // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return { data: keyMaterial };
}

function testConvertSymKey() {
  // Create a SymKeyGenerator instance.
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
  // Generate a symmetric key based on the specified data.
  let keyMaterialBlob = genKeyMaterialBlob();
  try {
    symKeyGenerator.convertKey(keyMaterialBlob, (error, key) => {
      if (error) {// If the service logic fails to be executed, the first parameter of callback returns error information, that is, an exception is thrown asynchronously.
        console.error(`convertKey error, ${error.code}, ${error.message}`);
        return;
      }
      console.info(`key algName: ${key.algName}`);
      console.info(`key format: ${key.format}`);
      let encodedKey = key.getEncoded(); // Obtain the binary data of the symmetric key and output a 192-bit byte stream in hexadecimal format. The length is 48, that is, 24 bytes.
      console.info('key getEncoded hex: ' + uint8ArrayToShowStr(encodedKey.data));
    })
  } catch (error) { // Throw an exception immediately when an error is detected in parameter check.
    console.error(`convertKey failed, ${error.code}, ${error.message}`);
    return;
  }
}
```

### Randomly Generating an SM2 Key Pair and Obtaining the Binary Data

> **NOTE**
>
> SM2 asymmetric keys can be randomly generated from API version 10.

Randomly generate an asymmetric key pair and obtain its binary data.

1. Create an **AsyKeyGenerator** instance.
2. Randomly generate an asymmetric key pair using **AsyKeyGenerator**.
3. Obtain the binary data of the key pair generated.

Example: Randomly generate an SM2 key (256 bits) in promise mode.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function generateAsyKey() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  // Use the key generator to randomly generate an asymmetric key pair.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    let pubKey = keyPair.pubKey;
    let priKey = keyPair.priKey;
    // Obtain the binary data of the asymmetric key pair.
    let pkBlob = pubKey.getEncoded();
    let skBlob = priKey.getEncoded();
    AlertDialog.show({ message: "pk bin data" + pkBlob.data });
    AlertDialog.show({ message: "sk bin data" + skBlob.data });
  })
}
```

### Randomly Generating an SM4 Key and Obtaining the Binary Data

 > **NOTE**
 >
 > SM4 keys can be randomly generated from API version 10.

Randomly generate a symmetric key and obtain its binary data.

1. Create a **SymKeyGenerator** instance.
2. Randomly generate a symmetric key using **SymKeyGenerator**.
3. Obtain the binary data of the key generated.

Example: Randomly generate an SM4 key (128 bits) in promise mode.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// Output the byte streams in hexadecimal format.
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

function testGenerateSM4Key() {
  // Create a SymKeyGenerator instance.
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("SM4_128");
  // Use the key generator to randomly generate a symmetric key.
  let promiseSymKey = symKeyGenerator.generateSymKey();
  promiseSymKey.then(key => {
    // Obtain the binary data of the symmetric key and output a 128-bit byte stream in hexadecimal format. The length is 32, that is, 16 bytes.
    let encodedKey = key.getEncoded();
    console.info('key hex:' + uint8ArrayToShowStr(encodedKey.data));
  })
}
```

### Converting Binary Data into an SM2 Key Pair

 > **NOTE**
 >
 > SM2 key conversion is supported from API version 10.

Generate an SM2 asymmetric key pair from the given binary key data.

1. Obtain the SM2 binary key data and encapsulate it into a **DataBlob** instance.
2. Call **convertKey()** to convert the binary data (data of the private or public key, or both) into a **KeyPair** instance.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function convertSM2AsyKey() {
    let pubKeyArray = new Uint8Array([48,89,48,19,6,7,42,134,72,206,61,2,1,6,8,42,129,28,207,85,1,130,45,3,66,0,4,90,3,58,157,190,248,76,7,132,200,151,208,112,230,96,140,90,238,211,155,128,109,248,40,83,214,78,42,104,106,55,148,249,35,61,32,221,135,143,100,45,97,194,176,52,73,136,174,40,70,70,34,103,103,161,99,27,187,13,187,109,244,13,7]);
    let priKeyArray = new Uint8Array([48,49,2,1,1,4,32,54,41,239,240,63,188,134,113,31,102,149,203,245,89,15,15,47,202,170,60,38,154,28,169,189,100,251,76,112,223,156,159,160,10,6,8,42,129,28,207,85,1,130,45]);
    let pubKeyBlob = { data: pubKeyArray };
    let priKeyBlob = { data: priKeyArray };
    let generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
    generator.convertKey(pubKeyBlob, priKeyBlob, (error, data) => {
        if (error) {
            AlertDialog.show({message : "Convert keypair fail"});
            return;
        }
        AlertDialog.show({message : "Convert KeyPair success"});
    })
}
```

## Generating an Asymmetric Key Object and Obtaining Key Parameters

### When to Use

Typical key generation operations involve the following:
1. Create a key object based on the specified asymmetric key parameters for subsequent encryption and decryption.
2. Obtain the parameter properties of an asymmetric key object for storage or transmission.

> **NOTE**
>
> - Key parameters can be used to generate asymmetric keys from API version 10. 
> - Asymmetric systems use a public key (**PubKey**) to encrypt data and a related private key (**PriKey**) to decrypt it. The public key and private key form a key pair (**KeyPair**). For details about asymmetric key parameters, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

### Available APIs

The following table describes the APIs used in typical key generation operations. For more information about the APIs, see [AsyKeyGeneratorBySpec](../reference/apis/js-apis-cryptoFramework.md#asykeygeneratorbyspec10).

|Instance|API|Description|
|---|---|---|
|AsyKeyGeneratorBySpec|generateKeyPair(callback: AsyncCallback\<KeyPair>): void;|Generates a **KeyPair** instance based on the key parameters. This API uses an asynchronous callback to return the result.|
|AsyKeyGeneratorBySpec|generateKeyPair(): Promise\<KeyPair>;|Generates a **KeyPair** instance based on the key parameters. This API uses a promise to return the result.|
|AsyKeyGeneratorBySpec|generatePriKey(callback: AsyncCallback\<KeyPair>): void;|Generates a **PriKey** instance based on the key parameters. This API uses an asynchronous callback to return the result.|
|AsyKeyGeneratorBySpec|generatePriKey(): Promise\<KeyPair>;|Generates a **PriKey** instance based on the key parameters. This API uses a promise to return the result.|
|AsyKeyGeneratorBySpec|generatePubKey(callback: AsyncCallback\<KeyPair>): void;|Generates a **PubKey** instance based on the key parameters. This API uses an asynchronous callback to return the result.|
|AsyKeyGeneratorBySpec|generatePubKey(): Promise\<KeyPair>;|Generates a **PubKey** instance based on the key parameters. This API uses a promise to return the result.|
| PriKey | getAsyKeySpec(itemType: AsyKeySpecItem): bigint \| string \| number;  | Obtains the key specifications of a **PriKey** instance.|
| PubKey | getAsyKeySpec(itemType: AsyKeySpecItem): bigint \| string \| number;  | Obtains the key specifications of a **PubKey** instance.|

### Generating an ECC Key Pair and Obtaining Key Specifications

Generate an ECC key pair based on parameters and obtain the key specifications.

1. Create an **AsyKeyGenerator** based on key parameters.
2. Use the **AsyKeyGenerator** to generate an asymmetric key pair based on the specified key parameters.
3. Obtain the key specifications of a key object.

Example: Generate an ECC key based on key parameters in promise mode.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// Print bigint information.
function showBigIntInfo(bnName, bnValue) {
  console.warn(bnName + ":");
  console.warn(". Decimal: " + bnValue.toString());
  console.warn(". Hexadecimal: " + bnValue.toString(16));
  console.warn (". Length (bits): " + bnValue.toString(2).length);
}

// Construct the EccCommonSpec struct based on the key specifications. The EccCommonSpec struct defines the common parameters of the ECC private key and public key.
function genEccCommonSpec() {
  let fieldFp = {
    fieldType: "Fp",
    p: BigInt("0xffffffffffffffffffffffffffffffff000000000000000000000001")
  }

  let G = {
    x: BigInt("0xb70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21"),
    y: BigInt("0xbd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34")
  }

  let eccCommonSpec = {
    algName: "ECC",
    specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC,
    field: fieldFp,
    a: BigInt("0xfffffffffffffffffffffffffffffffefffffffffffffffffffffffe"),
    b: BigInt("0xb4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4"),
    g: G,
    n: BigInt("0xffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d"),
    h: 1
  }
  return eccCommonSpec;
}

// Print the ECC key specifications.
function showEccSpecDetailInfo(key, keyType) {
  console.info("show detail of " + keyType + ":");
  try {
    let p = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FP_P_BN);
    showBigIntInfo("--- p", p); // length is 224, hex : ffffffffffffffffffffffffffffffff000000000000000000000001

    let a = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_A_BN);
    showBigIntInfo("--- a", a); // length is 224, hex : fffffffffffffffffffffffffffffffefffffffffffffffffffffffe

    let b = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_B_BN);
    showBigIntInfo("--- b", b); // length is 224, hex : b4050a850c04b3abf54132565044b0b7d7bfd8ba270b39432355ffb4

    let gX = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_G_X_BN);
    showBigIntInfo("--- gX", gX); // length is 224, hex : b70e0cbd6bb4bf7f321390b94a03c1d356c21122343280d6115c1d21

    let gY = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_G_Y_BN);
    showBigIntInfo("--- gY", gY); // length is 224, hex : bd376388b5f723fb4c22dfe6cd4375a05a07476444d5819985007e34

    let n = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_N_BN);
    showBigIntInfo("--- n", n); // length is 224, hex : ffffffffffffffffffffffffffff16a2e0b8f03e13dd29455c5c2a3d

    let h = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_H_NUM);
    console.warn("--- h: " + h); // key h: 1

    let fieldType = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FIELD_TYPE_STR);
    console.warn("--- field type: " + fieldType); // key field type: Fp

    let fieldSize = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_FIELD_SIZE_NUM);
    console.warn("--- field size: " + fieldSize); // key field size: 224

    let curveName = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_CURVE_NAME_STR);
    console.warn("--- curve name: " + curveName); // key curve name: NID_secp224r1

    if (keyType == "priKey") {
      let sk = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_SK_BN);
      showBigIntInfo("--- sk", sk);
    } else if (keyType == "pubKey") {
      let pkX = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_X_BN);
      showBigIntInfo("--- pkX", pkX);
      let pkY = key.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.ECC_PK_Y_BN);
      showBigIntInfo("--- pkY", pkY);
    }
  } catch (error) {
    console.error("getAsyKeySpec error");
    console.error("error code: " + error.code + ", message is: " + error.message);
  }
}

// Generate an ECC key pair based on the EccCommonSpec instance and obtain the key specifications.
function testEccUseCommKeySpecGet() {
  try {
    let commKeySpec = genEccCommonSpec(); // Construct the EccCommonSpec object.
    let generatorBySpec = cryptoFramework.createAsyKeyGeneratorBySpec(commKeySpec); // Create an AsyKeyGenerator instance based on the EccCommonSpec object.
    let keyPairPromise = generatorBySpec.generateKeyPair(); // Generate an ECC key pair.
    keyPairPromise.then(keyPair => {
      showEccSpecDetailInfo(keyPair.priKey, "priKey"); // Obtain the ECC specifications of the private key.
      showEccSpecDetailInfo(keyPair.pubKey, "pubKey"); // Obtain the ECC specifications of the public key.
    }).catch(error => {
      // Capture exceptions such as logic errors asynchronously here.
      console.error("generateComm error");
      console.error("error code: " + error.code + ", message is: " + error.message);
    })
  } catch (error) {
    // Capture parameter errors synchronously here.
    console.error("testEccUseCommSpec error");
    console.error("error code: " + error.code + ", message is: " + error.message);
  }
}
```

### Generating an RSA Public Key and Obtaining Key Specifications

Generate an RSA public key based on parameters and obtain key specifications.

1. Create an **AsyKeyGenerator** based on key parameters.
2. Use the **AsyKeyGenerator** to generate the public key of an asymmetric key pair.
3. Obtain the key specifications of the public key object.

Example: Generate an RSA public key based on key parameters in callback mode.
```js
// Generate RSA public key specifications.
function genRsaPubKeySpec(nIn: bigint, eIn: bigint) {
  let rsaCommSpec = { n: nIn, algName: "RSA", specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC };
  let rsaPubKeySpec = {
    params: rsaCommSpec,
    pk: eIn,
    algName: "RSA",
    specType: cryptoFramework.AsyKeySpecType.PUBLIC_KEY_SPEC
  };
  return rsaPubKeySpec;
}

// Construct an RSA public key specifications object based on the key parameters.
function genRsa2048PubKeySpec() {
  let nIn = BigInt("0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25");
  let eIn = BigInt("0x010001");
  return genRsaPubKeySpec(nIn, eIn);
}

// Compare the RSA public key specifications with the expected values.
function compareRsaPubKeyBySpec(rsaKeySpec, n, e) {
  if (rsaKeySpec.params.n != n) {
    return false;
  }
  if (rsaKeySpec.pk != e) {
    return false;
  }
  return true;
}

// Generate an RSA public key based on the RSA public key specifications, obtain the key specifications, and compare the key specifications with the expected values.
function rsaUsePubKeySpecGetCallback() {
  let rsaPubKeySpec = genRsa2048PubKeySpec();
  let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaPubKeySpec);
  rsaGeneratorSpec.generatePubKey((error, key) => {
    let pubKey = key;
    let nBN = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.RSA_N_BN);
    let eBN = pubKey.getAsyKeySpec(cryptoFramework.AsyKeySpecItem.RSA_PK_BN);
    if (compareRsaPubKeyBySpec(rsaPubKeySpec, nBN, eBN) != true) {
      AlertDialog.show({ message: "error pub key big number" });
    } else {
      console.info("n, e in the pubKey are same as the spec.");
    }
    if (error) {
      console.error("generate pubKey error" + "error code: " + error.code + "error message" + error.message);
    }
  });
}
```

## Encryption and Decryption

### When to Use

Important data needs to be encrypted in data storage or transmission for security purposes. Typical encryption and decryption operations involve the following:
1. Encrypt and decrypt data using a symmetric key.
2. Encrypt and decrypt data using an asymmetric key pair.
3. Obtain and set the **CipherSpecItem** parameter when the PKCS1_OAEP padding mode is used in RSA.

> **NOTE**
>
> - From API version 10, [CipherSpecItem](../reference/apis/js-apis-cryptoFramework.md#cipherspecitem10) can be obtained and set when the PKCS1_OAEP padding mode is used in RSA.
> - From API version 10, the string parameter without the key length is supported in encryption and decryption.

### Available APIs

The following table describes the APIs used in the typical encryption and decryption operations. For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md). 
> **NOTE**
>
> Due to complexity of cryptographic algorithms, the implementation varies depending on the key specifications and parameters you use, and cannot be enumerated by sample code. Before you start, understand the APIs to ensure correct use of these APIs.



|Instance|API|Description|
|---|---|---|
|cryptoFramework|createCipher(transformation : string) : Cipher|Creates a **Cipher** instance.|
|Cipher|init(opMode : CryptoMode, key : Key, params : ParamsSpec, callback : AsyncCallback\<void>) : void|Sets a key and initializes the **Cipher** instance. This API uses an asynchronous callback to return the result.|
|Cipher|init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>|Sets a key and initializes the **Cipher** instance. This API uses a promise to return the result.|
|Cipher|update(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|Updates the data for encryption and decryption. This API uses an asynchronous callback to return the result.|
|Cipher|update(data : DataBlob) : Promise\<DataBlob>|Updates the data for encryption and decryption. This API uses a promise to return the result.|
|Cipher|doFinal(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|Finalizes the encryption or decryption. This API uses an asynchronous callback to return the result.|
|Cipher|doFinal(data : DataBlob) : Promise\<DataBlob>|Finalizes the encryption or decryption. This API uses a promise to return the result.|
|Cipher|getCipherSpec(itemType: CipherSpecItem): string \| Uint8Array|Obtains cipher specifications. Currently, only the RSA is supported.|
|Cipher|setCipherSpec(itemType: CipherSpecItem, itemValue: Uint8Array): void|Sets cipher specifications. Currently, only the RSA is supported.|

### Encrypting and Decrypting Data Using AES GCM (Promise)

Encrypt and decrypt data using an AES symmetric key.

1. Create a **SymKeyGenerator** instance.
2. Use the **SymKeyGenerator** to randomly generate a symmetric key.
3. Create a **Cipher** instance.
4. Encrypt or decrypt data.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

var globalCipher;
var globalGcmParams;
var globalKey;
var globalCipherText;

function genGcmParamsSpec() {
  let arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 12 bytes
  let dataIv = new Uint8Array(arr);
  let ivBlob = { data: dataIv };

  arr = [0, 0, 0, 0, 0, 0, 0, 0]; // 8 bytes
  let dataAad = new Uint8Array(arr);
  let aadBlob = { data: dataAad };

  arr = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]; // 16 bytes
  let dataTag = new Uint8Array(arr);
  let tagBlob = { data: dataTag }; // The GCM authTag is obtained by doFinal() in encryption and passed in params of init() in decryption.

  let gcmParamsSpec = { iv: ivBlob, aad: aadBlob, authTag: tagBlob, algName: "GcmParamsSpec" };
  return gcmParamsSpec;
}

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Output the byte streams in hexadecimal format.
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

// Automatically generate an AES GCM key in promise mode.
function testAesGcm() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve('testAesGcm');
    }, 10)
  }).then(() => {
    // Create a SymKeyGenerator instance.
    let symAlgName = 'AES128';
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
    if (symKeyGenerator == null) {
      console.error('createSymKeyGenerator failed');
      return;
    }
    console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);
    // Use the key generator to randomly generate a 128-bit symmetric key.
    let promiseSymKey = symKeyGenerator.generateSymKey();
    // Generate GCM parameter specifications.
    globalGcmParams = genGcmParamsSpec();

    // Create a Cipher instance.
    let cipherAlgName = 'AES128|GCM|PKCS7';
    try {
      globalCipher = cryptoFramework.createCipher(cipherAlgName);
      console.info(`cipher algName: ${globalCipher.algName}`);
    } catch (error) {
      console.error(`createCipher failed, ${error.code}, ${error.message}`);
      return;
    }
    return promiseSymKey;
  }).then(key => {
    let encodedKey = key.getEncoded();
    console.info('key hex:' + uint8ArrayToShowStr(encodedKey.data));
    globalKey = key;
    return key;
  }).then(key => {
    // Initialize the Cipher instance and start encryption.
    let mode = cryptoFramework.CryptoMode.ENCRYPT_MODE;
    let promiseInit = globalCipher.init(mode, key, globalGcmParams); // init
    return promiseInit;
  }).then(() => {
    let plainText = {data : stringToUint8Array('this is test!')};
    let promiseUpdate = globalCipher.update(plainText); // update
    return promiseUpdate;
  }).then(updateOutput => {
    globalCipherText = updateOutput;
    let promiseFinal = globalCipher.doFinal(null); // doFinal
    return promiseFinal;
  }).then(authTag => {
    // In GCM mode, the encrypted authentication information needs to be obtained from the output of doFinal() and passed in globalGcmParams of init() in decryption.
    globalGcmParams.authTag = authTag;
    return;
  }).then(() => {
    // Initialize the Cipher instance and start decryption.
    let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
    let promiseInit = globalCipher.init(mode, globalKey, globalGcmParams); // init
    return promiseInit;
  }).then(() => {
    let promiseUpdate = globalCipher.update(globalCipherText); // update
    return promiseUpdate;
  }).then(updateOutput => {
    console.info('decrypt plainText: ' + uint8ArrayToString(updateOutput.data));
    let promiseFinal = globalCipher.doFinal(null); // doFinal
    return promiseFinal;
  }).then(finalOutput => {
    if (finalOutput == null) { // Check whether the result is null before using finalOutput.data.
      console.info('GCM finalOutput is null');
    }
  }).catch(error => {
    console.error(`catch error, ${error.code}, ${error.message}`);
  })
}
```

### Encrypting and Decrypting Data Using a 3DES ECB Symmetric Key (Callback)

Encrypt and decrypt data using a 3DES symmetric key.

1. Create a **SymKeyGenerator** instance.
2. Generate a key based on the existing binary data.
3. Create a **Cipher** instance.
4. Encrypt or decrypt data.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

var globalCipher;
var globalGcmParams;
var globalKey;
var globalCipherText;

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Output the byte streams in hexadecimal format.
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

function genKeyMaterialBlob() {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72];    // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return {data : keyMaterial};
}

// Generate a 3DES ECB key from the existing data in callback mode.
function test3DesEcb() {
  // Create a SymKeyGenerator instance.
  let symAlgName = '3DES192';
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
  if (symKeyGenerator == null) {
    console.error('createSymKeyGenerator failed');
    return;
  }
  console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);

  // Create a Cipher instance.
  let cipherAlgName = '3DES192|ECB|PKCS7';
  try {
    globalCipher = cryptoFramework.createCipher(cipherAlgName);
    console.info(`cipher algName: ${globalCipher.algName}`);
  } catch (error) {
    console.error(`createCipher failed, ${error.code}, ${error.message}`);
    return;
  }

  // Generate a symmetric key based on the specified data.
  let keyMaterialBlob = genKeyMaterialBlob();
  try {
    symKeyGenerator.convertKey(keyMaterialBlob, (error, key) => {
      if (error) {
        console.error(`convertKey error, ${error.code}, ${error.message}`);
        return;
      }
      console.info(`key algName: ${key.algName}`);
      console.info(`key format: ${key.format}`);
      let encodedKey = key.getEncoded();
      console.info('key getEncoded hex: ' + uint8ArrayToShowStr(encodedKey.data));
      globalKey = key;

      // Initialize the Cipher instance and start encryption.
      let mode = cryptoFramework.CryptoMode.ENCRYPT_MODE;
      // init
      globalCipher.init(mode, key, null, (err,) => {
        let plainText = { data: stringToUint8Array('this is test!') };
        // update
        globalCipher.update(plainText, (err, updateOutput) => {
          globalCipherText = updateOutput;
          //doFinal
          globalCipher.doFinal(null, (err, finalOutput) => {
            if (error) {
              console.error(`doFinal error, ${error.code}, ${error.message}`);
              return;
            }
            if (finalOutput != null) {
              globalCipherText = Array.from(globalCipherText.data);
              finalOutput = Array.from(finalOutput.data);
              globalCipherText = globalCipherText.concat(finalOutput);
              globalCipherText = new Uint8Array(globalCipherText);
              globalCipherText = { data: globalCipherText };
            }
            // Initialize the Cipher instance and start decryption.
            let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
            // init
            globalCipher.init(mode, globalKey, null, (err,) => {
              // update
              globalCipher.update(globalCipherText, (err, updateOutput) => {
                console.info('decrypt plainText: ' + uint8ArrayToString(updateOutput.data));
                // doFinal
                globalCipher.doFinal(null, (error, finalOutput) => {
                  if (finalOutput != null) { // Check whether the result is null before using finalOutput.data.
                    console.info('decrypt plainText: ' + uint8ArrayToString(finalOutput.data));
                  }
                })
              })
            })
          })
        })
      })
    })
  } catch (error) {
    console.error(`convertKey failed, ${error.code}, ${error.message}`);
    return;
  }
}
```

### Encrypting and Decrypting Data Using an AES GCM Symmetric Key by Segment (Promise)

Use an AES symmetric key to encrypt and decrypt a large amount of data by segment using **update()**.

1. Create a **SymKeyGenerator** instance.
2. Generate a key based on the existing binary data.
3. Create a **Cipher** instance.
4. Encrypt or decrypt data.

Example: Encrypt and decrypt a large amount in AES GCM mode by calling **update()** multiple times in promise mode.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

var globalCipher;
var globalGcmParams;
var globalKey;
var globalCipherText;
var globalPlainText;

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

// Output the byte streams in hexadecimal format.
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

// The algorithm library does not limit the number of update() times and the amount of data to be encrypted and decrypted each time. You can use update() multiple times based on the memory usage.
function testAesMultiUpdate() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve('testAesMultiUpdate');
    }, 10)
  }).then(() => {
    // Create a SymKeyGenerator instance.
    let symAlgName = 'AES128';
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
    if (symKeyGenerator == null) {
      console.error('createSymKeyGenerator failed');
      return;
    }
    console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);
    // Use the key generator to randomly generate a 128-bit symmetric key.
    let promiseSymKey = symKeyGenerator.generateSymKey();
    // Construct key specifications.
    globalGcmParams = genGcmParamsSpec();

    // Create a Cipher instance.
    let cipherAlgName = 'AES128|GCM|PKCS7';
    try {
      globalCipher = cryptoFramework.createCipher(cipherAlgName);
      console.info(`cipher algName: ${globalCipher.algName}`);
    } catch (error) {
      console.error(`createCipher failed, ${error.code}, ${error.message}`);
      return;
    }
    return promiseSymKey;
  })
    .then(key => {
      let encodedKey = key.getEncoded();
      console.info('key hex:' + uint8ArrayToShowStr(encodedKey.data));
      globalKey = key;
      return key;
    })
    .then(key => {
      // Initialize the Cipher instance and start encryption.
      let mode = cryptoFramework.CryptoMode.ENCRYPT_MODE;
      let promiseInit = globalCipher.init(mode, key, globalGcmParams); // init
      return promiseInit;
    })
    .then(async () => {
      let plainText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // Assume that the plaintext is of 43 bytes.
      let messageArr = [];
      let updateLength = 20; // Pass in 20 bytes by update() each time.
      globalCipherText = [];

      for (let i = 0; i <= plainText.length; i++) {
        if ((i % updateLength == 0 || i == plainText.length) && messageArr.length != 0) {
          let message = new Uint8Array(messageArr);
          let messageBlob = { data: message };
          let updateOutput = await globalCipher.update(messageBlob); // Update by segment.
          // Combine the result of each update() to obtain the ciphertext. In certain cases, the doFinal() results need to be combined, which depends on the cipher block mode
          // and padding mode you use. In this example, the doFinal() result in GCM mode contains authTag but not ciphertext. Therefore, there is no need to combine the results.
          globalCipherText = globalCipherText.concat(Array.from(updateOutput.data));
          messageArr = [];
        }
        if (i < plainText.length) {
          messageArr.push(plainText.charCodeAt(i));
        }
      }
      return;
    })
    .then(() => {
      let promiseFinal = globalCipher.doFinal(null); // doFinal
      return promiseFinal;
    })
    .then(authTag => {
      // Obtain the authentication information after encryption.
      globalGcmParams.authTag = authTag;
      return;
    })
    .then(() => {
      // Initialize the Cipher instance and start decryption.
      let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
      let promiseInit = globalCipher.init(mode, globalKey, globalGcmParams); // init
      return promiseInit;
    })
    .then(async () => {
      let updateLength = 20;
      let updateTimes = Math.ceil(globalCipherText.length / updateLength); // Round up to the nearest integer.
      globalPlainText = "";
      for (let i = 0; i < updateTimes; i++) {
        let messageArr = globalCipherText.slice(i * updateLength, (i + 1) * updateLength);
        let message = new Uint8Array(messageArr);
        let messageBlob = { data: message };
        let updateOutput = await globalCipher.update(messageBlob); // Update by segment.
        globalPlainText += uint8ArrayToString(updateOutput.data); // Restore the original plaintext.
      }
      return;
    })
    .then(() => {
      let promiseFinal = globalCipher.doFinal(null); // doFinal
      return promiseFinal;
    })
    .then(finalOutput => {
      if (finalOutput == null) {
        console.info('GCM finalOutput is null');
      }
      console.info(`decrypt output: ${globalPlainText}`);
    })
    .catch(error => {
      console.error(`catch error, ${error.code}, ${error.message}`);
    })
}
```

### Encrypting and Decrypting Data Using RSA

Encrypt and decrypt data using an RSA asymmetric key pair.

1. Generate an RSA key pair.<br>Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an RSA asymmetric key pair.
2. Create a **Cipher** instance.<br>Call **createCipher()** to create a **Cipher** instance, and set the key and encryption/decryption mode.
3. Encrypt and decrypt data.<br>Call **doFinal()** provided by the **Cipher** instance to encrypt data or decrypt data.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

let plan = "This is cipher test.";

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Encrypt the message in promise mode.
function encryptMessagePromise() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  // Create a Cipher instance.
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(rsaKeyPair => {
    let pubKey = rsaKeyPair.pubKey;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
  }).then(() => {
    // doFinal
    let input = { data: stringToUint8Array(plan) };
    return cipher.doFinal(input);
  }).then(dataBlob => {
    // Obtain the encrypted data.
    console.info("EncryptOutPut is " + dataBlob.data);
  });
}

// Encrypt the data in callback mode.
function encryptMessageCallback() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  // Create a Cipher instance.
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  rsaGenerator.generateKeyPair(function (err, keyPair) {
    let pubKey = keyPair.pubKey;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null, function (err, data) {
      let input = { data: stringToUint8Array(plan) };
      // doFinal
      cipher.doFinal(input, function (err, data) {
        // Obtain the encrypted data.
        console.info("EncryptOutPut is " + data.data);
      })
    })
  })
}

// Encrypt and decrypt data in promise mode.
function decryptMessagePromise() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  // Create a Cipher instance for encryption.
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  // Create a Cipher instance for decryption.
  let decoder = cryptoFramework.createCipher("RSA1024|PKCS1");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  let keyPair;
  let cipherDataBlob;
  let input = { data: stringToUint8Array(plan) };
  keyGenPromise.then(rsaKeyPair => {
    keyPair = rsaKeyPair;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
  })
    .then(() => {
      // Call doFinal() to encrypt data.
      return cipher.doFinal(input);
    })
    .then(dataBlob => {
      // Obtain the encrypted information and use it as the input parameter for decryption.
      console.info("EncryptOutPut is " + dataBlob.data);
      AlertDialog.show({ message: "output" + dataBlob.data });
      cipherDataBlob = dataBlob;
      // Initialize the Cipher instance and use the private key to decrypt the data.
      return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
    })
    .then(() => {
      // Call doFinal() to decrypt data.
      return decoder.doFinal(cipherDataBlob);
    })
    .then(decodeData => {
      // Check whether the decrypted data is consistent with the original data.
      if (decodeData.data.toString() === input.data.toString()) {
        AlertDialog.show({ message: "decrypt success" });
        return;
      }
      AlertDialog.show({ message: "decrypt fail" });
    });
}

// Encrypt and decrypt data in callback mode.
function decryptMessageCallback() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  // Create a Cipher instance for encryption.
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  // Create a Cipher instance for decryption.
  let decoder = cryptoFramework.createCipher("RSA1024|PKCS1");
  let plainText = "this is cipher text";
  let input = { data: stringToUint8Array(plainText) };
  let cipherData;
  let keyPair;
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  rsaGenerator.generateKeyPair(function (err, newKeyPair) {
    keyPair = newKeyPair;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null, function (err, data) {
      // Call doFinal() to encrypt data.
      cipher.doFinal(input, function (err, data) {
        // Obtain the encrypted information and use it as the input parameter for decryption.
        AlertDialog.show({ message: "EncryptOutPut is " + data.data });
        cipherData = data;
        // Initialize the Cipher instance and use the private key to decrypt the data.
        decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null, function (err, data) {
          // Call doFinal() to decrypt data.
          decoder.doFinal(cipherData, function (err, data) {
            // Check whether the decrypted data is consistent with the original data.
            if (input.data.toString() === data.data.toString()) {
              AlertDialog.show({ message: "decrype success" });
              return;
            }
            AlertDialog.show({ message: "decrype fail" });
          });
        });
      });
    });
  });
}
```

### Encrypting and Decrypting Data Using RSA by Segment

Use an RSA asymmetric key pair to encrypt and decrypt a large amount of data by segment.

1. Generate an RSA key pair.<br>Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an RSA asymmetric key pair.
2. Create a **Cipher** instance.<br>Call **createCipher()** to create a **Cipher** instance, and set the key and encryption/decryption mode.
3. Encrypt and decrypt data.<br>Call **doFinal()** provided by the **Cipher** instance multiple times to encrypt and decrypt data.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

function encryptLongMessagePromise() {
  let globalPlainText = "This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";
  let globalCipherOutput;
  let globalDecodeOutput;
  var globalKeyPair;
  let plainTextSplitLen = 64; // The length of the plaintext to be encrypted or decrypted each time by RSA depends on the number of key bits and padding mode. For details, see the Crypto Framework Overview.
  let cipherTextSplitLen = 128; // Length of the ciphertext = Number of key bits/8
  let keyGenName = "RSA1024";
  let cipherAlgName = "RSA1024|PKCS1";
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator(keyGenName); // Create an AsyKeyGenerator object.
  let cipher = cryptoFramework.createCipher(cipherAlgName); // Create a Cipher object.
  let decoder = cryptoFramework.createCipher(cipherAlgName); // Create a Decoder object.
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve("testRsaMultiDoFinal");
    }, 10);
  }).then(() => {
    return asyKeyGenerator.generateKeyPair(); // Generate an RSA key pair.
  }).then(keyPair => {
    globalKeyPair = keyPair; // Save the key pair as a global variable.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, globalKeyPair.pubKey, null);
  }).then(async () => {
    globalCipherOutput = [];
    // Split the plaintext by 64 characters and cyclically call doFinal() to encrypt the plaintext. If a 1024-bit key is used, 128-byte ciphertext is generated each time.
    for (let i = 0; i < (globalPlainText.length / plainTextSplitLen); i++) {
      let tempStr = globalPlainText.substr(i * plainTextSplitLen, plainTextSplitLen);
      let tempBlob = { data : stringToUint8Array(tempStr) };
      let tempCipherOutput = await cipher.doFinal(tempBlob);
      globalCipherOutput = globalCipherOutput.concat(Array.from(tempCipherOutput.data));
    }
    console.info(`globalCipherOutput len is ${globalCipherOutput.length}, data is: ${globalCipherOutput.toString()}`);
    return;
  }).then(() =>{
    return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, globalKeyPair.priKey, null);
  }).then(async() => {
    globalDecodeOutput = [];
    // Split and decrypt the ciphertext by 128 bytes, and combine the plaintext obtained each time.
    for (let i = 0; i < (globalCipherOutput.length / cipherTextSplitLen); i++) {
      let tempBlobData = globalCipherOutput.slice(i * cipherTextSplitLen, (i + 1) * cipherTextSplitLen);
      let message = new Uint8Array(tempBlobData);
      let tempBlob = { data : message };
      let tempDecodeOutput = await decoder.doFinal(tempBlob);
      globalDecodeOutput += uint8ArrayToString(tempDecodeOutput.data);
    }
    if (globalDecodeOutput === globalPlainText) {
      console.info(`encode and decode success`);
    } else {
      console.info(`encode and decode error`);
    }
    return;
  }).catch(error => {
    console.error(`catch error, ${error.code}, ${error.message}`);
  })
}
```

> **NOTE**
>
> - In RSA encryption and decryption, **init()** cannot be repeatedly called to initialize a **Cipher** instance. You must create a **Cipher** instance for each encryption and decryption.
> - The RSA encryption has a limit on the length of the plaintext to be encrypted. For details, see [Encryption and Decryption](cryptoFramework-overview.md#encryption-and-decryption).
> - In RSA decryption, the length of the ciphertext to be decrypted each time is the number of bits of the RSA key divided by 8.

### Using PKCS1_OAEP in RSA Encryption and Decryption

Use the PKCS1_OAEP padding mode in RSA encryption and decryption in promise mode.

1. Generate an RSA key pair based on the key parameters.<br>Call **createAsyKeyGeneratorBySpec()** to create an **AsyKeyGeneratorBySpec** object and generate an RSA asymmetric key pair. (You can also use **createAsyKeyGenerator()** to randomly generate or convert an RSA key object.)
2. Create a **Cipher** instance.<br>Call **createCipher()** to create a cipher instance, initialize the cipher instance, set the key and encryption/decryption mode, use **setCipherSpec()** to set PKCS1_OAEP **pSource**, and use **update()** to pass in data.
3. Encrypt and decrypt data.<br>Call the **doFinal()** provided by the **Cipher** class to perform encryption or decryption. The **pSource** of the **Cipher** instance to be encrypted must be the same as that decrypted.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Construct the key parameters of the RSA asymmetric key pair based on the key pair specifications.
function genRsaKeyPairSpec(nIn: bigint, eIn: bigint, dIn: bigint) {
  let rsaCommSpec = { n: nIn, algName: "RSA", specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC };
  let rsaKeyPairSpec = {
    params: rsaCommSpec,
    sk: dIn,
    pk: eIn,
    algName: "RSA",
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC
  };
  return rsaKeyPairSpec;
}

// Generate RSA2048 key pair parameters.
function genRsa2048KeyPairSpec() {
  let nIn = BigInt("0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25");
  let eIn = BigInt("0x010001");
  let dIn = BigInt("0x6a7df2ca63ead4dda191d614b6b385e0d9056a3d6d5cfe07db1daabee022db08212d97613d3328e0267c9dd23d787abde2afcb306aeb7dfce69246cc73f5c87fdf06030179a2114b767db1f083ff841c025d7dc00cd82435b9a90f695369e94df23d2ce458bc3b3283ad8bba2b8fa1ba62e2dce9accff3799aae7c840016f3ba8e0048c0b6cc4339af7161003a5beb864a0164b2c1c9237b64bc87556994351b27506c33d4bcdfce0f9c491a7d6b0628c7c852be4f0a9c3132b2ed3a2c8881e9aab07e20e17deb074691be677776a78b5c502e05d9bdde72126b3738695e2dd1a0a98a14247c65d8a7ee79432a092cb0721a12df798e44f7cfce0c498147a9b1");
  return genRsaKeyPairSpec(nIn, eIn, dIn);
}

function rsaUseSpecDecryptOAEPPromise() {
  let plan = "This is cipher test.";
  // Obtain the key parameter object of the RSA key pair.
  let rsaKeyPairSpec = genRsa2048KeyPairSpec();
  // Generate an RSA key pair based on the RSA key parameters.
  let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
  let keyGenPromise = rsaGeneratorSpec.generateKeyPair();
  let cipher = cryptoFramework.createCipher("RSA|PKCS1_OAEP|SHA256|MGF1_SHA1");
  let decoder = cryptoFramework.createCipher("RSA|PKCS1_OAEP|SHA256|MGF1_SHA1");
  let keyPair;
  let cipherDataBlob;
  // Set the pSource, which defines the encoding input P filled by OAEP.
  let pSource = new Uint8Array([1, 2, 3, 4]);
  let input = { data: stringToUint8Array(plan) };
  // Generate the key pair.
  keyGenPromise.then(rsaKeyPair => {
    keyPair = rsaKeyPair;
    // Initialize the Cipher instance for encryption.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
  })
    .then(() => {
      // Set and obtain the cipher specifications after the initialization.
      cipher.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
      let retP = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
      // Check whether the obtained PSource is the same as the PSource set.
      if (retP.toString() != pSource.toString()) {
        AlertDialog.show({ message: "error init pSource" + retP });
      } else {
        console.info("pSource changed ==" + retP);
      }
      // Obtain other OAEP parameters.
      let md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
      console.info("md == " + md);
      let mgf = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
      console.info("mgf == " + mgf);
      let mgf1Md = cipher.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
      console.info("mgf1Md == " + mgf1Md);
      return cipher.doFinal(input);
    })
    .then(dataBlob => {
      console.info("EncryptOutPut is " + dataBlob.data);
      cipherDataBlob = dataBlob;
      // The get() and set() operations can be performed before the init() operation of the Cipher object and are equivalent to those after the init() operation. For example, set and get the decoder.
      decoder.setCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR, pSource);
      let retP = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_PSRC_UINT8ARR);
      // Check whether the obtained PSource is the same as the PSource set.
      if (retP.toString() != pSource.toString()) {
        AlertDialog.show({ message: "error init pSource" + retP });
      } else {
        console.info("pSource changed ==" + retP);
      }
      // Obtain other OAEP parameters.
      let md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MD_NAME_STR);
      console.info("md == " + md);
      let mgf = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF_NAME_STR);
      console.info("mgf == " + mgf);
      let mgf1Md = decoder.getCipherSpec(cryptoFramework.CipherSpecItem.OAEP_MGF1_MD_STR);
      console.info("mgf1Md == " + mgf1Md);
      // Initialize the decryption operation.
      return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
    })
    .then(() => {
      return decoder.doFinal(cipherDataBlob);
    })
    .then(decodeData => {
      // The decryption is successful.
      if (decodeData.data.toString() === input.data.toString()) {
        console.info("oaep decrypt success");
        AlertDialog.show({ message: " oaep decrypt success" });
      } else {
        AlertDialog.show({ message: "oeap decrypt fail" });
      }
    });
}
```

### Encrypting and Decrypting Data Using SM2

> **NOTE**
>
> SM2 encryption and decryption are supported from API version 10.

Use an SM2 asymmetric key pair to encrypt and decrypt data.

1. Generate an SM2 key pair. Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an SM2 asymmetric key pair.
2. Create a **Cipher** instance.<br>Call **createCipher()** to create a **Cipher** instance, and set the key and encryption/decryption mode.
3. Encrypt and decrypt data.<br>Call **doFinal()** provided by the **Cipher** instance to encrypt data or decrypt data.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

let plan = "This is cipher test.";

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Encrypt the message in promise mode.
function encryptMessagePromise() {
  // Create an AsyKeyGenerator instance.
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  // Create a Cipher instance.
  let cipher = cryptoFramework.createCipher("SM2_256|SM3");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  let keyGenPromise = sm2Generator.generateKeyPair();
  keyGenPromise.then(sm2KeyPair => {
    let pubKey = sm2KeyPair.pubKey;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
  }).then(() => {
    // doFinal
    let input = { data: stringToUint8Array(plan) };
    return cipher.doFinal(input);
  }).then(dataBlob => {
    // Obtain the encrypted data.
    console.info("EncryptOutPut is " + dataBlob.data);
  });
}

// Encrypt the data in callback mode.
function encryptMessageCallback() {
  // Create an AsyKeyGenerator instance.
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  // Create a Cipher instance.
  let cipher = cryptoFramework.createCipher("SM2_256|SM3");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  sm2Generator.generateKeyPair(function (err, keyPair) {
    let pubKey = keyPair.pubKey;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null, function (err, data) {
      let input = { data: stringToUint8Array(plan) };
      // doFinal
      cipher.doFinal(input, function (err, data) {
        // Obtain the encrypted data.
        console.info("EncryptOutPut is " + data.data);
      })
    })
  })
}

// Encrypt and decrypt data in promise mode.
function decryptMessagePromise() {
  // Create an AsyKeyGenerator instance.
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  // Create a Cipher instance for encryption.
  let cipher = cryptoFramework.createCipher("SM2_256|SM3");
  // Create a Cipher instance for decryption.
  let decoder = cryptoFramework.createCipher("SM2_256|SM3");
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  let keyGenPromise = sm2Generator.generateKeyPair();
  let keyPair;
  let cipherDataBlob;
  let input = { data: stringToUint8Array(plan) };
  keyGenPromise.then(rsaKeyPair => {
    keyPair = rsaKeyPair;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
  })
    .then(() => {
      // Call doFinal() to encrypt data.
      return cipher.doFinal(input);
    })
    .then(dataBlob => {
      // Obtain the encrypted information and use it as the input parameter for decryption.
      console.info("EncryptOutPut is " + dataBlob.data);
      AlertDialog.show({ message: "output" + dataBlob.data });
      cipherDataBlob = dataBlob;
      // Initialize the Cipher instance and use the private key to decrypt the data.
      return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
    })
    .then(() => {
      // Call doFinal() to decrypt data.
      return decoder.doFinal(cipherDataBlob);
    })
    .then(decodeData => {
      // Check whether the decrypted data is consistent with the original data.
      if (decodeData.data.toString() === input.data.toString()) {
        AlertDialog.show({ message: "decrypt success" });
        return;
      }
      AlertDialog.show({ message: "decrypt fail" });
    });
}

// Encrypt and decrypt data in callback mode.
function decryptMessageCallback() {
  // Create an AsyKeyGenerator instance.
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  // Create a Cipher instance for encryption.
  let cipher = cryptoFramework.createCipher("SM2_256|SM3");
  // Create a Cipher instance for decryption.
  let decoder = cryptoFramework.createCipher("SM2_256|SM3");
  let plainText = "this is cipher text";
  let input = { data: stringToUint8Array(plainText) };
  let cipherData;
  let keyPair;
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  sm2Generator.generateKeyPair(function (err, newKeyPair) {
    keyPair = newKeyPair;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null, function (err, data) {
      // Call doFinal() to encrypt data.
      cipher.doFinal(input, function (err, data) {
        // Obtain the encrypted information and use it as the input parameter for decryption.
        AlertDialog.show({ message: "EncryptOutPut is " + data.data });
        cipherData = data;
        // Initialize the Cipher instance and use the private key to decrypt the data.
        decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null, function (err, data) {
          // Call doFinal() to decrypt data.
          decoder.doFinal(cipherData, function (err, data) {
            // Check whether the decrypted data is consistent with the original data.
            if (input.data.toString() === data.data.toString()) {
              AlertDialog.show({ message: "decrype success" });
              return;
            }
            AlertDialog.show({ message: "decrype fail" });
          });
        });
      });
    });
  });
}
```

### Encrypting and Decrypting Data Using an SM4 ECB Symmetric Key (Callback)

> **NOTE**
>
> SM4 encryption and decryption are supported from API version 10.

Use an SM4 symmetric key to encrypt and decrypt data.

1. Create a **SymKeyGenerator** instance.
2. Generate a key based on the existing binary data.
3. Create a **Cipher** instance.
4. Encrypt or decrypt data.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function stringToUint8Array(str) {
	let arr = [];
	for (let i = 0, j = str.length; i < j; ++i) {
	arr.push(str.charCodeAt(i));
	}
	return new Uint8Array(arr);
}

// Convert byte streams into strings in plaintext.
function uint8ArrayToString(array) {
  let arrayString = '';
  for (let i = 0; i < array.length; i++) {
    arrayString += String.fromCharCode(array[i]);
  }
  return arrayString;
}

// Use SM4 ECB mode as an example. Callback-based APIs are used.
function testSM4Ecb() {
  // Create an AsyKeyGenerator instance.
  let sm4Generator = cryptoFramework.createSymKeyGenerator('SM4_128');
  // Create a Cipher instance for encryption.
  let cipher = cryptoFramework.createCipher("SM4_128|ECB|PKCS7");
  // Create a Cipher instance for decryption.
  let decoder = cryptoFramework.createCipher("SM4_128|ECB|PKCS7");
  let plainText = "this is cipher text";
  let input = { data: stringToUint8Array(plainText) };
  let cipherData;
  let key;
  // Generate an asymmetric key pair using the AsyKeyGenerator instance.
  sm4Generator.generateSymKey(function (err, newKey) {
    key = newKey;
    // Initialize the Cipher instance and use the public key to encrypt the data.
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, key, null, function (err, data) {
      // Call doFinal() to encrypt data.
      cipher.doFinal(input, function (err, data) {
        // Obtain the encrypted information and use it as the input parameter for decryption.
        AlertDialog.show({ message: "EncryptOutPut is " + data.data });
        cipherData = data;
        // Initialize the Cipher instance and use the private key to decrypt the data.
        decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, key, null, function (err, data) {
          // Call doFinal() to decrypt data.
          decoder.doFinal(cipherData, function (err, data) {
            // Check whether the decrypted data is consistent with the original data.
            if (input.data.toString() === data.data.toString()) {
              AlertDialog.show({ message: "decrype success" });
              return;
            }
            AlertDialog.show({ message: "decrype fail" });
          });
        });
      });
    });
  });
}
```

## Signing and Signature Verification

### When to Use

A digital signature can be used to verify the authenticity of a message. Typical signing and signature verification operations involve the following:
1. Use RSA to generate a signature and verify the signature.
2. Use ECC to generate a signature and verify the signature.
3. Use RSA to generate a signature and verify the signature. Obtain and set **SignSpecItem** when the PSS padding mode is used.
4. Use SM2 to generate a signature and verify the signature.

> **NOTE**
>
> - From API version 10, [SignSpecItem](../reference/apis/js-apis-cryptoFramework.md#signspecitem10) can be set and obtained when the PSS padding mode is used.
> - From API version 10, the string parameter without the key length is supported in signature verification.

### Available APIs

The following table describes the APIs used in typical signing and signature verification operations. For more information about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).
> **NOTE**
>
> Due to complexity of cryptographic algorithms, the implementation varies depending on the specifications and parameters you use, and cannot be enumerated by sample code. Before you start, understand the APIs to ensure correct use of these APIs.

|Instance|API|Description|
|---|---|---|
|cryptoFramework|createSign(algName : string) : Sign|Creates a **Sign** instance.|
|Sign|init(priKey : PriKey, callback : AsyncCallback\<void>) : void|Sets a key and initializes the **Sign** instance. This API uses an asynchronous callback to return the result.|
|Sign|init(priKey : PriKey) : Promise\<void>|Sets a key and initializes the **Sign** instance. This API uses a promise to return the result.|
|Sign|update(data : DataBlob, callback : AsyncCallback\<void>) : void|Updates the data for signing. This API uses an asynchronous callback to return the result.|
|Sign|update(data : DataBlob) : Promise\<void>|Updates the data for signing. This API uses a promise to return the result.|
|Sign|sign(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|Signs the data. This API uses an asynchronous callback to return the result.|
|Sign|sign(data : DataBlob) : Promise\<DataBlob>|Signs the data. This API uses a promise to return the result.|
|Sign|getSignSpec(itemType: SignSpecItem): string \| number|Obtains signing specifications. Currently, only the RSA is supported.|
|Sign|setSignSpec(itemType: SignSpecItem, itemValue: number): void|Sets signing specifications. Currently, only the RSA is supported.|
|cryptoFramework|function createVerify(algName : string) : Verify|Creates a **Verify** instance.|
|Verify|init(pubKey : PubKey, callback : AsyncCallback\<void>) : void|Sets a key and initializes the **Verify** instance. This API uses an asynchronous callback to return the result.|
|Verify|init(pubKey : PubKey) : Promise\<void>|Sets a key and initializes the **Verify** instance. This API uses a promise to return the result.|
|Verify|update(data : DataBlob, callback : AsyncCallback\<void>) : void|Updates the data for signature verification. This API uses an asynchronous callback to return the result.|
|Verify|update(data : DataBlob) : Promise\<void>|Updates the data for signature verification. This API uses a promise to return the result.|
|Verify|verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback\<boolean>) : void|Verifies a signature. This API uses an asynchronous callback to return the result.|
|Verify|verify(data : DataBlob, signatureData : DataBlob) : Promise\<boolean>|Verifies a signature. This API uses a promise to return the result.|
|Verify|getVerifySpec(itemType: SignSpecItem): string \| number|Obtains signature verification specifications. Currently, only the RSA is supported.|
|Verify|setVerifySpec(itemType: SignSpecItem, itemValue: number): void|Sets signature verification specifications. Currently, only the RSA is supported.|

### Signing and Signature Verification Using RSA

Use RSA to sign data and verify the signature.

1. Generate an RSA key pair.<br>Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an RSA asymmetric key pair.
2. Create a **Sign** instance.<br>Call **createSign()** to create a **Sign** instance, initialize the **Sign** instance, and set a private key for signing.
3. Generate a signature.<br>Call **update()** provided by the **Sign** class to pass in the data for signing and call **sign()** to generate a signature.
4. Create a **Verify** instance.<br>Call **createVerify()** to create a **Verify** instance, initialize the instance, and set a public key for signature verification.
5. Verify the signature.<br>Call **update()** provided by the **Verify** class to pass in the signature data and call **verify()** to verify the signature.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let globalKeyPair;
let SignMessageBlob;
let plan1 = "This is Sign test plan1";
let plan2 = "This is Sign test plan1";
let input1 = { data: stringToUint8Array(plan1) };
let input2 = { data: stringToUint8Array(plan2) };

function signMessagePromise() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256"); // From API version 10, a Sign instance can be created by specifying a string parameter defining the key specifications.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    return signer.init(priKey);
  }).then(() => {
    return signer.update(input1);
  }).then(() => {
    return signer.sign(input2);
  }).then(dataBlob => {
    SignMessageBlob = dataBlob;
    console.info("sign output is " + SignMessageBlob.data);
  });
}

// Call verify() after sign() is called.
function verifyMessagePromise() {
  let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
  let verifyInitPromise = verifyer.init(globalKeyPair.pubKey);
  verifyInitPromise.then(() => {
    return verifyer.update(input1);
  }).then(() => {
    return verifyer.verify(input2, SignMessageBlob);
  }).then(res => {
    console.log("Verify result is " + res);
  });
}

function signMessageCallback() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256"); // From API version 10, a Sign instance can be created by specifying a string parameter defining the key specifications.
  rsaGenerator.generateKeyPair(function (err, keyPair) {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    signer.init(priKey, err => {
      signer.update(input1, err => {
        signer.sign(input2, (err, data) => {
          SignMessageBlob = data;
          console.info("sign output is " + SignMessageBlob.data);
        });
      });
    });
  });
}

// Call verify() after sign() is called.
function verifyMessageCallback() {
  let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
  verifyer.init(globalKeyPair.pubKey, err => {
    verifyer.update(input1, err => {
      verifyer.verify(input2, SignMessageBlob, function (err, data) {
        console.info("verify result is " + data);
      });
    });
  })
}
```

### Signing and Signature Verification Using ECDSA

Use ECDSA to sign data and verify the signature.

1. Generate an ECC key.<br>Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an ECC asymmetric key pair.
2. Create a **Sign** instance.<br>Call **createSign()** to create a **Sign** instance, initialize the **Sign** instance, and set a private key for signing.
3. Generate a signature.<br>Call **update()** provided by the **Sign** class to pass in the data for signing and call **doFinal()** to generate a signature.
4. Create a **Verify** instance.<br>Call **createVerify()** to create a **Verify** instance, initialize the instance, and set a public key for signature verification.
5. Verify the signature.<br>Call **update()** provided by the **Verify** class to pass in the signature data and call **doFinal()** to verify the signature.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let globalKeyPair;
let SignMessageBlob;
let plan1 = "This is Sign test plan1";
let plan2 = "This is Sign test plan1";
let input1 = { data: stringToUint8Array(plan1) };
let input2 = { data: stringToUint8Array(plan2) };

function signMessagePromise() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let signer = cryptoFramework.createSign("ECC256|SHA256");
  let keyGenPromise = eccGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    return signer.init(priKey);
  }).then(() => {
    return signer.update(input1);
  }).then(() => {
    return signer.sign(input2);
  }).then(dataBlob => {
    SignMessageBlob = dataBlob;
    console.info("sign output is " + SignMessageBlob.data);
  });
}

function verifyMessagePromise() {
  let verifyer = cryptoFramework.createVerify("ECC256|SHA256");
  let verifyInitPromise = verifyer.init(globalKeyPair.pubKey);
  verifyInitPromise.then(() => {
    return verifyer.update(input1);
  }).then(() => {
    return verifyer.verify(input2, SignMessageBlob);
  }).then(res => {
    console.log("Verify result is " + res);
  });
}

function signMessageCallback() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let signer = cryptoFramework.createSign("ECC256|SHA256");
  eccGenerator.generateKeyPair(function (err, keyPair) {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    signer.init(priKey, err => {
      signer.update(input1, err => {
        signer.sign(input2, (err, data) => {
          SignMessageBlob = data;
          console.info("sign output is " + SignMessageBlob.data);
        });
      });
    });
  });
}

function verifyMessageCallback() {
  let verifyer = cryptoFramework.createVerify("ECC256|SHA256");
  verifyer.init(globalKeyPair.pubKey, err => {
    verifyer.update(input1, err => {
      verifyer.verify(input2, SignMessageBlob, function (err, data) {
        console.info("verify result is " + data);
      });
    });
  })
}
```

### Signing and Signature Verification Using RSA by Segment

Use RSA to sign data and verify the signature by segment.

1. Generate an RSA key pair.<br>Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an RSA asymmetric key pair.
2. Create a **Sign** instance.<br>Call **createSign()** to create a **Sign** instance, initialize the **Sign** instance, and set a private key for signing.
3. Generate a signature.<br>Call the **update()** provided by the **Sign** class multiple times to pass in data by segment and call **sign()** to generate a signature.
4. Create a **Verify** instance.<br>Call **createVerify()** to create a **Verify** instance, initialize the instance, and set a public key for signature verification.
5. Verify the signature.<br>Call the **update()** method provided by the **Verify** class multiple times to pass in data by segment and call **verify()** to verify the signature.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function signLongMessagePromise() {
  let globalPlainText = "This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!" +
  "This is a long plainTest! This is a long plainTest! This is a long plainTest! This is a long plainTest!";
  let globalSignData;
  let textSplitLen = 64; // Customized data splitting length.
  let keyGenName = "RSA1024";
  let signAlgName = "RSA1024|PKCS1|SHA256";
  let globalKeyPair;
  let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator(keyGenName); // Create an AsyKeyGenerator object.
  let signer = cryptoFramework.createSign(signAlgName); // Create a Signer instance.
  let verifier = cryptoFramework.createVerify(signAlgName); // Create a Verifier instance.
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve("testRsaMultiUpdate");
    }, 10);
  }).then(() => {
    return asyKeyGenerator.generateKeyPair(); // Generate an RSA key pair.
  }).then(keyPair => {
    globalKeyPair = keyPair; // Save the key pair as a global variable.
    return signer.init(globalKeyPair.priKey);
  }).then(async () => {
    // If the plaintext is too large, split the plaintext based on the specified length and cyclically call update() to pass in the plaintext.
    for (let i = 0; i < (globalPlainText.length / textSplitLen); i++) {
      let tempStr = globalPlainText.substr(i * textSplitLen, textSplitLen);
      let tempBlob = { data : stringToUint8Array(tempStr) };
      await signer.update(tempBlob);
    }
    return signer.sign(null);
  }).then(data =>{
    globalSignData = data.data;
    console.info(`globalSignOutput len is ${globalSignData.length}, data is: ${globalSignData.toString()}`);
    return verifier.init(globalKeyPair.pubKey);
  }).then(async() => {
    // If the plaintext is too large, split the plaintext based on the specified length and cyclically call update() to pass in the plaintext.
    for (let i = 0; i < (globalPlainText.length / textSplitLen); i++) {
      let tempData = globalPlainText.slice(i * textSplitLen, (i + 1) * textSplitLen);
      let tempBlob = { data : stringToUint8Array(tempData) };
      await verifier.update(tempBlob);
    }
    return verifier.verify(null, { data : globalSignData});
  }).then(res => {
    console.info(`verify res is ${res}`);
  }).catch(error => {
    console.error(`catch error, ${error.code}, ${error.message}`);
  })
}
```

### Using PSS in RSA Signing and Signature Verification

Use the PSS padding mode in RSA signing and signature verification in callback mode.

1. Generate an RSA key pair based on the key parameters.<br>Call **createAsyKeyGeneratorBySpec** to create an **AsyKeyGeneratorBySpec** object and generate an RSA asymmetric key pair.
2. Create a **Sign** instance.<br>Call **createSign()** to create a **Sign** object, initialize the **Sign** object, set the private key for signing, and set and obtain PSS parameters.
3. Generate a signature.<br>Call **update()** provided by the **Sign** class to pass in the data for signing and call **sign()** to generate a signature.
4. Create a **Verify** instance.<br>Call **createVerify()** to create a **Verify** object, initialize the object, set the public key for signature verification, and set and obtain PSS parameters. The signature verification is successful if the salt length is the same.
5. Verify the signature.<br>Call **update()** provided by the **Verify** class to pass in the signature data and call **verify()** to verify the signature.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Construct the key parameters of the RSA asymmetric key pair based on the key pair specifications.
function genRsaKeyPairSpec(nIn: bigint, eIn: bigint, dIn: bigint) {
  let rsaCommSpec = { n: nIn, algName: "RSA", specType: cryptoFramework.AsyKeySpecType.COMMON_PARAMS_SPEC };
  let rsaKeyPairSpec = {
    params: rsaCommSpec,
    sk: dIn,
    pk: eIn,
    algName: "RSA",
    specType: cryptoFramework.AsyKeySpecType.KEY_PAIR_SPEC
  };
  return rsaKeyPairSpec;
}

// Generate RSA2048 key pair parameters.
function genRsa2048KeyPairSpec() {
  let nIn = BigInt("0x9260d0750ae117eee55c3f3deaba74917521a262ee76007cdf8a56755ad73a1598a1408410a01434c3f5bc54a88b57fa19fc4328daea0750a4c44e88cff3b2382621b80f670464433e4336e6d003e8cd65bff211da144b88291c2259a00a72b711c116ef7686e8fee34e4d933c868187bdc26f7be071493c86f7a5941c3510806ad67b0f94d88f5cf5c02a092821d8626e8932b65c5bd8c92049c210932b7afa7ac59c0e886ae5c1edb00d8ce2c57633db26bd6639bff73cee82be9275c402b4cf2a4388da8cf8c64eefe1c5a0f5ab8057c39fa5c0589c3e253f0960332300f94bea44877b588e1edbde97cf2360727a09b775262d7ee552b3319b9266f05a25");
  let eIn = BigInt("0x010001");
  let dIn = BigInt("0x6a7df2ca63ead4dda191d614b6b385e0d9056a3d6d5cfe07db1daabee022db08212d97613d3328e0267c9dd23d787abde2afcb306aeb7dfce69246cc73f5c87fdf06030179a2114b767db1f083ff841c025d7dc00cd82435b9a90f695369e94df23d2ce458bc3b3283ad8bba2b8fa1ba62e2dce9accff3799aae7c840016f3ba8e0048c0b6cc4339af7161003a5beb864a0164b2c1c9237b64bc87556994351b27506c33d4bcdfce0f9c491a7d6b0628c7c852be4f0a9c3132b2ed3a2c8881e9aab07e20e17deb074691be677776a78b5c502e05d9bdde72126b3738695e2dd1a0a98a14247c65d8a7ee79432a092cb0721a12df798e44f7cfce0c498147a9b1");
  return genRsaKeyPairSpec(nIn, eIn, dIn);
}

function verifyMessageCallbackPSS() {
  let plan1 = "This is Sign test plan1";
  let plan2 = "This is Sign test plan1";
  let input1 = { data: stringToUint8Array(plan1) };
  let input2 = { data: stringToUint8Array(plan2) };
  let globalKeyPair;
  let signMessageBlob;
  // Obtain the key parameter object of the RSA key pair.
  let rsaKeyPairSpec = genRsa2048KeyPairSpec();
  // Create an RSA key pair generator.
  let rsaGeneratorSpec = cryptoFramework.createAsyKeyGeneratorBySpec(rsaKeyPairSpec);
  // Both sign() and verify() support the RSA key with or without the length.
  let signer = cryptoFramework.createSign("RSA|PSS|SHA256|MGF1_SHA256");
  let verifyer = cryptoFramework.createVerify("RSA2048|PSS|SHA256|MGF1_SHA256");
  rsaGeneratorSpec.generateKeyPair(function (err, keyPair) {
    globalKeyPair = keyPair;
    signer.init(globalKeyPair.priKey, err => {
      // After the initialization, set and obtain the PSS parameters.
      let setN = 32;
      signer.setSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
      let saltLen = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
      console.info("SaltLen == " + saltLen);
      let tf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
      console.info("trailer field == " + tf);
      let md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
      console.info("md == " + md);
      let mgf = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
      console.info("mgf == " + mgf);
      let mgf1Md = signer.getSignSpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
      console.info("mgf1Md == " + mgf1Md);
      signer.update(input1, err => {
        signer.sign(input2, function (err, data) {
          // Before signature verification initialization, set and obtain PSS parameters. The functions are the same as those after initialization.
          signMessageBlob = data;
          AlertDialog.show({ message: "res" + signMessageBlob.data });
          let setN = 32;
          verifyer.setVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM, setN);
          let saltLen = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_SALT_LEN_NUM);
          console.info("SaltLen == " + saltLen);
          let tf = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_TRAILER_FIELD_NUM);
          console.info("trailer field == " + tf);
          let md = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MD_NAME_STR);
          console.info("md == " + md);
          let mgf = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF_NAME_STR);
          console.info("mgf == " + mgf);
          let mgf1Md = verifyer.getVerifySpec(cryptoFramework.SignSpecItem.PSS_MGF1_MD_STR);
          console.info("mgf1Md == " + mgf1Md);
          verifyer.init(globalKeyPair.pubKey, err => {
            verifyer.update(input1, err => {
              verifyer.verify(input2, signMessageBlob, function (err, data) {
                AlertDialog.show({ message: "res " + data });
              })
            });
          });
        });
      });
    });
  });
}
```

### Signing and Signature Verification Using SM2

> **NOTE**
>
> SM2 signing and signature verification are supported from API version 10.

Use SM2 to sign data and verify the signature.

1. Generate an SM2 key pair. Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an SM2 asymmetric key pair.
2. Create a **Sign** instance.<br>Call **createSign()** to create a **Sign** instance, initialize the **Sign** instance, and set a private key for signing.
3. Generate a signature.<br>Call **update()** provided by the **Sign** class to pass in the data for signing and call **doFinal()** to generate a signature.
4. Create a **Verify** instance.<br>Call **createVerify()** to create a **Verify** instance, initialize the instance, and set a public key for signature verification.
5. Verify the signature.<br>Call **update()** provided by the **Verify** class to pass in the signature data and call **doFinal()** to verify the signature.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
    var arr = [];
    for (var i = 0, j = str.length; i < j; ++i) {
      arr.push(str.charCodeAt(i));
    }
    var tmpArray = new Uint8Array(arr);
    return tmpArray;
}

let plan1 = "This is Sign test plan1";
let plan2 = "This is Sign test plan2";
let input1 = { data: stringToUint8Array(plan1) };
let input2 = { data: stringToUint8Array(plan2) };

function signAndVerify() {
  let signMessageBlob;
  let globalKeyPair;
  let sm2Generator = cryptoFramework.createAsyKeyGenerator("SM2_256");
  let signer = cryptoFramework.createSign("SM2_256|SM3");
  sm2Generator.generateKeyPair(function (err, keyPair) {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    signer.init(priKey, err => {
      signer.update(input1, err => {
        signer.sign(input2, function (err, data) {
          signMessageBlob = data;
          console.info("sign output is " + signMessageBlob.data);
          let verifyer = cryptoFramework.createVerify("SM2_256|SM3");
          verifyer.init(globalKeyPair.pubKey, err => {
            verifyer.update(input1, err => {
              verifyer.verify(input2, signMessageBlob, function (err, data) {
                console.info("verify result is " + data);
                AlertDialog.show({ message: "verify success" })
              });
            });
          })
        });
      });
    });
  });
}
```

## Key Agreement

### When to Use


Key agreement allows two parties to establish a shared secret over an insecure channel.

> **NOTE**
>
> From API version 10, the string parameter without the key length is supported in key agreement.

### Available APIs

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

|Instance|API|Description|
|---|---|---|
|cryptoFramework|createKeyAgreement(algName : string) : KeyAgreement|Creates a **KeyAgreement** instance.|
|KeyAgreement|generateSecret(priKey : PriKey, pubKey : PubKey, callback : AsyncCallback\<DataBlob>) : void|Generates a shared secret. This API uses an asynchronous callback to return the result.|
|KeyAgreement|generateSecret(priKey : PriKey, pubKey : PubKey) : Promise\<DataBlob>|Generates a shared secret. This API uses a promise to return the result.|

### How to Develop

1. Generate an ECC key.<br>Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an ECC asymmetric key pair.
2. Generate a shared secret by using the private and public ECC keys.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalKeyPair;

function ecdhPromise() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256"); // ECC is supported for key agreement from API version 10.
  let keyGenPromise = eccGenerator.generateKeyPair();
  keyGenPromise.then(keyPair => {
    globalKeyPair = keyPair;
    return eccKeyAgreement.generateSecret(keyPair.priKey, keyPair.pubKey);
  }).then((secret) => {
    console.info("ecdh output is " + secret.data);
  }).catch((error) => {
    console.error("ecdh error.");
  });
}

function ecdhCallback() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256");
  eccGenerator.generateKeyPair(function (err, keyPair) {
    globalKeyPair = keyPair;
    eccKeyAgreement.generateSecret(keyPair.priKey, keyPair.pubKey, function (err, secret) {
      if (err) {
        console.error("ecdh error.");
        return;
      }
      console.info("ecdh output is " + secret.data);
    });
  });
}
```

## Message Digest

### When to Use

A message digest (MD) is a fixed size numeric representation of the content of a message, computed by a hash function. It is sent with the message. The receiver can generate a digest for the message and compare it with the digest received. If the two digests are the same, the message integrity is verified.

Typical MD operations involve the following:

1. Create an **Md** instance with the specified digest algorithm (such as SHA-256).
2. Pass in one or more messages for generating a digest, and generate a digest. 
3. Obtain the digest algorithm and digest length (in bytes).

### Available APIs

For more information about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

| Instance         | API                                                      | Description                                              |
| --------------- | ------------------------------------------------------------ | -------------------------------------------------- |
| cryptoFramework | function createMd(algName : string) : Md;                    | Creates an **Md** instance with the specified algorithm. |
| Md              | update(input : DataBlob, callback : AsyncCallback\<void>) : void; | Updates the data for a digest. This API uses an asynchronous callback to return the result.|
| Md              | update(input : DataBlob) : Promise\<void>;                  | Updates the data for a digest. This API uses a promise to return the result. |
| Md              | digest(callback : AsyncCallback\<DataBlob>) : void;         | Generates the digest. This API uses an asynchronous callback to return the result.                      |
| Md              | digest() : Promise\<DataBlob>;                              | Generates the digest. This API uses a promise to return the result.                       |
| Md              | getMdLength() : number;                                      | Obtains the digest length based on the specified digest algorithm.            |
| Md              | readonly algName : string;                                   | Obtains the digest algorithm.                          |

### Generating a Digest

1. Use **createMd()** to create an **Md** instance.
2. Use **update()** to pass in data. **update()** can be called multiple times. The algorithm library does not limit the data length of a single **update()**.
3. Use **digest()** to compute a digest.
4. Obtain the digest algorithm and length of the digest generated.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Generate a digest in promise mode.
function doMdByPromise() {
  let mdAlgName = "SHA256"; // Digest algorithm name.
  let message = "mdTestMessgae"; // Data to be digested.
  let md;
  let mdOutput;
  try {
    md = cryptoFramework.createMd(mdAlgName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
    return;
  }
  console.info("[Promise]: Md algName is: " + md.algName);
  // If the data volume is small, you can use update() once to pass in all data. There is no limit on the length of the input parameter.
  let promiseMdUpdate = md.update({ data: stringToUint8Array(message) });
  promiseMdUpdate.then(() => {
    // Call digest() to return the result.
    let PromiseMdDigest = md.digest();
    return PromiseMdDigest;
  }).then(digestOutput => {
    mdOutput = digestOutput;
    console.info("[Promise]: MD result: " + mdOutput.data);
    let mdLen = md.getMdLength();
    console.info("[Promise]: MD len: " + mdLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// Generate a digest in callback mode.
function doMdByCallback() {
  let mdAlgName = "SHA256"; // Digest algorithm name.
  let message = "mdTestMessgae"; // Data to be digested.
  let md;
  let mdOutput;
  try {
    md = cryptoFramework.createMd(mdAlgName);
  } catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  console.info("[Callback]: Md algName is: " + md.algName);
  // If the data volume is small, you can use update() once to pass in all data. There is no limit on the length of the input parameter.
  md.update({ data: stringToUint8Array(message) }, (err,) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    }
    md.digest((err1, digestOutput) => {
      if (err1) {
        console.error("[Callback]: err: " + err1.code);
      } else {
        mdOutput = digestOutput;
        console.info("[Callback]: MD result: " + mdOutput.data);
        let mdLen = md.getMdLength();
        console.info("[Callback]: MD len: " + mdLen);
      }
    });
  });
}
```

### Generating a Digest by Segment

1. Use **createMd()** to create an **Md** instance.
2. Use **update()** multiple times to pass in by segment.
3. Use **digest()** to compute a digest.
4. Obtain the digest algorithm and length of the digest generated.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Generate a digest by segment in promise mode.
async function doLoopMdPromise() {
  let mdAlgName = "SHA256"; // Digest algorithm name.
  let md;
  let mdOutput;
  try {
    md = cryptoFramework.createMd(mdAlgName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
    return;
  }
  console.info("[Promise]: Md algName is: " + md.algName);
  let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // Assume that the message is of 43 bytes.
  let messageArr = [];
  let updateLength = 20; // For example, pass in 20 bytes in each update().

  for (let i = 0; i <= messageText.length; i++) {
    if ((i % updateLength == 0 || i == messageText.length) && messageArr.length != 0) {
      let message = new Uint8Array(messageArr);
      let messageBlob = { data: message };
      // Use await to process the update() in the for() loop.
      try {
        await md.update (messageBlob); // Use update() to process data by segment.
      } catch (error) {
        console.error("await update error code: " + error.code + ", message is: " + error.message);
        return;
      }
      messageArr = [];
    }
    // Pad messageArr based on the segment length.
    if (i < messageText.length) {
      messageArr.push(messageText.charCodeAt(i));
    }
  }
  let PromiseMdDigest = md.digest();
  PromiseMdDigest.then(digestOutput => {
    mdOutput = digestOutput;
    console.info("[Promise]: MD result: " + mdOutput.data);
    let mdLen = md.getMdLength();
    console.info("[Promise]: MD len: " + mdLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}
```

## HMAC

### When to Use

A hash-based message authentication code (HMAC) can be used to verify both the integrity and authenticity of a message using a shared secret. 

Typical MAC operations involve the following:

1. Create a **Mac** instance.
2. Initialize the **Mac** instance, add one or more segments of data for generating a MAC, and generate a MAC.
3. Obtain the algorithm and length of a MAC.

### Available APIs

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

| Instance         | API                                                      | Description                                               |
| --------------- | ------------------------------------------------------------ | --------------------------------------------------- |
| cryptoFramework | function createMac(algName : string) : Mac;                  | Creates a **Mac** instance.                |
| Mac             | init(key : SymKey, callback : AsyncCallback\<void>) : void; | Initializes the **Mac** instance. This API uses an asynchronous callback to return the result.|
| Mac             | init(key : SymKey) : Promise\<void>;                        | Initializes the **Mac** instance. This API uses a promise to return the result. |
| Mac             | update(input : DataBlob, callback : AsyncCallback\<void>) : void; | Updates the data for the MAC operation. This API uses an asynchronous callback to return the result.      |
| Mac             | update(input : DataBlob) : Promise\<void>;                  | Updates the data for the MAC operation. This API uses a promise to return the result.       |
| Mac             | doFinal(callback : AsyncCallback\<DataBlob>) : void;        | Finalizes the MAC operation to generate a MAC. This API uses an asynchronous callback to return the result.                |
| Mac             | doFinal() : Promise\<DataBlob>;                             | Finalizes the MAC operation to generate a MAC. This API uses a promise to return the result.                 |
| Mac             | getMacLength() : number;                                     | Obtains the length of the MAC based on the specified algorithm.              |
| Mac             | readonly algName : string;                                   | Obtains the digest algorithm.                           |

### Generating an HMAC

1. Use **createMac()** to create a **Mac** instance.
2. Use **init()** to initialize the **Mac** instance with the symmetric key passed in.
3. Use **update()** to pass in the data for computing an HMAC.
4. Use **doFinal()** to generate an HMAC.
5. Obtain the algorithm and length of the HMAC.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert strings in plaintext into byte streams.
function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

// Generate an HMAC in promise mode.
function doHmacByPromise() {
  let macAlgName = "SHA256"; // Digest algorithm name.
  let message = "hmacTestMessgae"; // Data used to generate an HMAC.
  let macOutput;
  let mac;
  try {
    mac = cryptoFramework.createMac(macAlgName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
  }
  console.info("[Promise]: Mac algName is: " + mac.algName);
  let KeyBlob = {
    // 128-bit key
    data: stringToUint8Array("12345678abcdefgh")
  }
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  // Convert the binary data into a key.
  let promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
  promiseConvertKey.then(symKey => {
    let promiseMacInit = mac.init(symKey);
    return promiseMacInit;
  }).then(() => {
    // If the data volume is small, you can use update() once to pass in all data. There is no limit on the length of the input parameter.
    let promiseMacUpdate = mac.update({ data: stringToUint8Array(message) });
    return promiseMacUpdate;
  }).then(() => {
    let PromiseMacDoFinal = mac.doFinal();
    return PromiseMacDoFinal;
  }).then(output => {
    macOutput = output;
    console.info("[Promise]: HMAC result: " + macOutput.data);
    let macLen = mac.getMacLength();
    console.info("[Promise]: MAC len: " + macLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// Generate an HMAC in callback mode.
function doHmacByCallback() {
  let macAlgName = "SHA256"; // Digest algorithm name.
  let message = "hmacTestMessgae"; // Data used to generate an HMAC.
  let macOutput;
  let mac;
  try {
    mac = cryptoFramework.createMac(macAlgName);
  } catch (error) {
    AlertDialog.show({message: "[Callback]: error code: " + error.code + ", message is: " + error.message});
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  console.info("[Promise]: Mac algName is: " + mac.algName);
  let KeyBlob = {
    // 128-bit key
    data: stringToUint8Array("12345678abcdefgh")
  }
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  // Convert the binary data into a key.
  symKeyGenerator.convertKey(KeyBlob, (err, symKey) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    }
    mac.init(symKey, (err1, ) => {
      if (err1) {
        console.error("[Callback]: err: " + err1.code);
      }
      // If the data volume is small, you can use update() once to pass in all data. There is no limit on the length of the input parameter.
      mac.update({ data: stringToUint8Array(message) }, (err2, ) => {
        if (err2) {
          console.error("[Callback]: err: " + err2.code);
        }
        mac.doFinal((err3, output) => {
          if (err3) {
            console.error("[Callback]: err: " + err3.code);
          } else {
            macOutput = output;
            console.error("[Callback]: HMAC result: " + macOutput.data);
            let macLen = mac.getMacLength();
            console.error("[Callback]: MAC len: " + macLen);
          }
        });
      });
    });
  });
}
```

### Generating an HMAC by Segment

Generate an HMAC by segment.

1. Use **createMac()** to create a **Mac** instance.
2. Use **init()** to initialize the **Mac** instance with the symmetric key passed in.
3. Call **update()** multiple times to pass in data by segment.
4. Use **doFinal()** to generate an HMAC.
5. Obtain the algorithm and length of the HMAC.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

function doLoopHmacPromise() {
  let macAlgName = "SHA256"; // Digest algorithm name.
  let macOutput;
  let mac;
  try {
    mac = cryptoFramework.createMac(macAlgName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
    return;
  }
  console.info("[Promise]: Mac algName is: " + mac.algName);
  let KeyBlob = {
    // 128-bit key
    data : stringToUint8Array("12345678abcdefgh")
  }
  let messageText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // Assume that the message is of 43 bytes.
  let updateLength = 20; // For example, pass in 20 bytes in each update().
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  // Convert the binary data into a key.
  let promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
  promiseConvertKey.then(symKey => {
    let promiseMacInit = mac.init(symKey);
    return promiseMacInit;
  }).then(async () => {
    let promiseMacUpdate;
    let messageArr = [];
    for (let i = 0; i <= messageText.length; i++) {
      if ((i % updateLength == 0 || i == messageText.length) && messageArr.length != 0) {
        let message = new Uint8Array(messageArr);
        let messageBlob = { data: message };
        // Use await to process the update() in the for() loop.
        try {
          promiseMacUpdate = await mac.update(messageBlob); // Invoke update() multiple times.
        } catch (error) {
          console.error("await update error code: " + error.code + ", message is: " + error.message);
          return;
        }
        messageArr = [];
      }
      // Pad messageArr based on the segment length.
      if (i < messageText.length) {
        messageArr.push(messageText.charCodeAt(i));
      }
    }
    return promiseMacUpdate;
  }).then(() => {
    let PromiseMacDoFinal = mac.doFinal();
    return PromiseMacDoFinal;
  }).then(output => {
    macOutput = output;
    console.log("[Promise]: HMAC result: " + macOutput.data);
    let macLen = mac.getMacLength();
    console.log("[Promise]: MAC len: " + macLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}
```

## Random Number

### When to Use

Typical random number operations involve the following:

1. Create a **Random** instance and specify the length (in bytes) of the random number to generate a secure random number of the specified length (ranging from **1** to **INT_MAX**).
2. Set a seed based on the random number generated.

### Available APIs

For more information about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

| Instance         | API                                                      | Description                                      |
| --------------- | ------------------------------------------------------------ | ------------------------------------------ |
| cryptoFramework | function createRandom() : Random;                            | Creates a **Random** instance.                      |
| Random          | generateRandom(len : number, callback: AsyncCallback\<DataBlob>) : void; | Generates a random number. This API uses an asynchronous callback to return the result.|
| Random          | generateRandom(len : number) : Promise\<DataBlob>;           | Generates a random number. This API uses a promise to return the result. |
| Random          | generateRandomSync(len: number): DataBlob;                   | Generates a random number of the specified length synchronously.              |
| Random          | setSeed(seed : DataBlob) : void;                             | Sets a seed.                    |

### How to Develop

1. Use **createRandom()** to create a **Random** instance.
2. Use **generateRandom()** to generate a random number of the given length.
3. Use **setSeed()** to set a seed.

```js
import cryptoFramework from "@ohos.security.cryptoFramework"

// Generate a random number in promise mode.
function doRandByPromise() {
  let rand;
  let len = 4; // Generate a 4-byte random number.
  try {
    rand = cryptoFramework.createRandom();
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
  }
  let promiseGenerateRand = rand.generateRandom(len);
  promiseGenerateRand.then(randData => {
    console.info("[Promise]: rand result: " + randData.data);
    try {
      rand.setSeed(randData);
    } catch (error) {
      console.error("setSeed failed, errCode: " + error.code + ", errMsg: " + error.message);
    }
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// Generate a random number in callback mode.
function doRandByCallback() {
  let rand;
  let len = 4; // Generate a 4-byte random number.
  try {
    rand = cryptoFramework.createRandom();
  } catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  rand.generateRandom(len, (err, randData) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    } else {
      console.info("[Callback]: generate random result: " + randData.data);
      try {
        rand.setSeed(randData);
      } catch (error) {
        console.error("setSeed failed, errCode: " + error.code + ", errMsg: " + error.message);
      }
    }
  });
}

// Generate a random number synchronously.
function doRandBySync() {
  let rand;
  let len = 24; // Generate a 24-byte random number.
  try {
    rand = cryptoFramework.createRandom();
  } catch (error) {
    console.error("[Sync]: error code: " + error.code + ", message is: " + error.message);
  }

  try {
    let randData = rand.generateRandomSync(len);
    if (randData != null) {
      console.info("[Sync]: rand result: " + randData.data);
    } else {
      console.error("[Sync]: get rand result fail!");
    }
  } catch (error) {
    console.error("[Sync]: error: " + error.message);
  }
}
```