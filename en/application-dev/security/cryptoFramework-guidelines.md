# Crypto Framework Development

> **NOTE**
>
> This guide applies to JS development using OpenHarmony API version 9 and SDK version 3.2.7 or later.

## Key Generation and Conversion

### When to Use

Typical key generation operations involve the following:

1. Randomly create a key object for subsequent encryption and decryption.
2. Convert external or internal binary data into a key object for subsequent encryption and decryption.
3. Obtain the binary data of a key object for storage or transmission.
> **NOTE**<br>The key instance can be a symmetric key instance (**SymKey**) or an asymmetric key pair instance (**KeyPair**). The **KeyPair** instance consists a public key (**PubKey**) and a private key (**PriKey**). For details about the relationship between keys, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).


### Available APIs

The following table describes the APIs used in this guide. For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).


|Instance|API|Description|
|---|---|---|
|cryptoFramework|createAsyKeyGenerator(algName : string) : AsyKeyGenerator|Creates an **AsyKeyGenerator** instance based on the asymmetric key pair specifications specified by **algName**.|
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

### How to Develop

Randomly generate an asymmetric key pair and obtain its binary data.

1. Create an **AsyKeyGenerator** instance.
2. Randomly generate an asymmetric key pair using **AsyKeyGenerator**.
3. Obtain the binary data of the key pair generated.

Example: Randomly generate an RSA key (1024 bits and two primes) in promise mode.

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

function generateAsyKey() {
  // Create an AsyKeyGenerator instance.
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  // Use the key generator to randomly generate an asymmetric key pair.
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then( keyPair => {
    globalKeyPair = keyPair;
    let pubKey = globalKeyPair.pubKey;
    let priKey = globalKeyPair.priKey;
    // Obtain the binary data of the asymmetric key pair.
    pkBlob = pubKey.getEncoded();
    skBlob = priKey.getEncoded();
    AlertDialog.show({ message : "pk bin data" + pkBlob.data} );
    AlertDialog.show({ message : "sk bin data" + skBlob.data} );
  })
}
```

Randomly generate a symmetric key and obtain its binary data.

1. Create a **SymKeyGenerator** instance.
2. Randomly generate a symmetric key using **SymKeyGenerator**. 
3. Obtain the binary data of the key generated.

Example: Randomly generate an AES key (256 bits) in promise mode.

```javascript
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
  promiseSymKey.then( key => {
    // Obtain the binary data of the symmetric key and output a 256-bit byte stream.
    let encodedKey = key.getEncoded();
    console.info('key hex:' + uint8ArrayToShowStr(encodedKey.data));
  })
}
```

Generate an RSA asymmetric key pair from the binary data.

1. Obtain the binary data of the RSA public or private key. The public key must comply with the ASN.1 syntax, X.509 specifications, and DER encoding format. The private key must comply with the ASN.1 syntax, PKCS #8 specifications, and DER encoding format.
2. Create an **AsyKeyGenerator** instance, and use **convertKey()** to convert the key binary data (data of the private or public key, or both) into a **KeyPair** instance.

```javascript
import cryptoFramework from '@ohos.security.cryptoFramework';

function convertAsyKey() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024");
  let pkval = new Uint8Array([48,129,159,48,13,6,9,42,134,72,134,247,13,1,1,1,5,0,3,129,141,0,48,129,137,2,129,129,0,174,203,113,83,113,3,143,213,194,79,91,9,51,142,87,45,97,65,136,24,166,35,5,179,42,47,212,79,111,74,134,120,73,67,21,19,235,80,46,152,209,133,232,87,192,140,18,206,27,106,106,169,106,46,135,111,118,32,129,27,89,255,183,116,247,38,12,7,238,77,151,167,6,102,153,126,66,28,253,253,216,64,20,138,117,72,15,216,178,37,208,179,63,204,39,94,244,170,48,190,21,11,73,169,156,104,193,3,17,100,28,60,50,92,235,218,57,73,119,19,101,164,192,161,197,106,105,73,2,3,1,0,1]);
  let pkBlob = {data : pkval};
  rsaGenerator.convertKey(pkBlob, null, function(err, keyPair) {
    if (keyPair == null) {
      AlertDialog.show({message : "Convert keypair fail"});
    }
    AlertDialog.show({message : "Convert KeyPair success"});
  })
}
```

> **NOTE**
>
> The public key binary data to be converted by **convertKey()** must be in the DER format complying with X.509 specifications, and the private key binary data must be in the DER format complying with PKCS #8 specifications.

Generate an ECC asymmetric key pair from the binary key data.

1. Obtain the ECC binary key data and encapsulate it into a **DataBlob** instance.
2. Call **convertKey()** to convert the binary data (data of the private or public key, or both) into a **KeyPair** instance.

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

function convertEccAsyKey() {
    let pubKeyArray = new Uint8Array([48,89,48,19,6,7,42,134,72,206,61,2,1,6,8,42,134,72,206,61,3,1,7,3,66,0,4,83,96,142,9,86,214,126,106,247,233,92,125,4,128,138,105,246,162,215,71,81,58,202,121,26,105,211,55,130,45,236,143,55,16,248,75,167,160,167,106,2,152,243,44,68,66,0,167,99,92,235,215,159,239,28,106,124,171,34,145,124,174,57,92]);
    let priKeyArray = new Uint8Array([48,49,2,1,1,4,32,115,56,137,35,207,0,60,191,90,61,136,105,210,16,27,4,171,57,10,61,123,40,189,28,34,207,236,22,45,223,10,189,160,10,6,8,42,134,72,206,61,3,1,7]);
    let pubKeyBlob = { data: pubKeyArray };
    let priKeyBlob = { data: priKeyArray };
    let generator = cryptoFramework.createAsyKeyGenerator("ECC256");
    generator.convertKey(pubKeyBlob, priKeyBlob, (error, data) => {
        if (error) {
            AlertDialog.show({message : "Convert keypair fail"});
        }
        AlertDialog.show({message : "Convert KeyPair success"});
    })
}
```

Generate a symmetric key from the binary key data.

1. Create a **SymKeyGenerator** instance.
2. Generate a symmetric key from the binary data.
3. Obtain the binary data of the key generated.

Example: Generate a 3DES key (192 bits only) in callback mode.

```javascript
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
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72];    // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return {data : keyMaterial};
}

function testConvertAesKey() {
  // Create a SymKeyGenerator instance.
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
  // Generate a symmetric key based on the specified data.
  let keyMaterialBlob = genKeyMaterialBlob();
  try {
    symKeyGenerator.convertKey(keyMaterialBlob, (error, key) => {
      if (error) {    // If the service logic fails to be executed, return the error information in the first parameter of the callback.
        console.error(`convertKey error, ${error.code}, ${error.message}`);
        return;
      }
      console.info(`key algName: ${key.algName}`);
      console.info(`key format: ${key.format}`);
      let encodedKey = key.getEncoded();    // Obtain the binary data of the symmetric key and output a 192-bit byte stream.
      console.info('key getEncoded hex: ' + uint8ArrayToShowStr(encodedKey.data));
    })
  } catch (error) {    // Throw an exception immediately after an error is detected during the parameter check.
    console.error(`convertKey failed, ${error.code}, ${error.message}`);
    return;
  }
}
```

## Encryption and Decryption

### When to Use

Important data needs to be encrypted in data storage or transmission for security purposes. Typical encryption and decryption operations involve the following:
1. Encrypt and decrypt data using a symmetric key.
2. Encrypt and decrypt data using an asymmetric key pair.

### Available APIs

The following table describes the APIs used in this guide. For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md). <br>Due to complexity of cryptographic algorithms, the implementation varies depending on the specifications and parameters you use, and cannot be enumerated by sample code. Before you start, understand the APIs to ensure correct use of these APIs.


|Instance|API|Description|
|---|---|---|
|cryptoFramework|createCipher(transformation : string) : Cipher|Creates a **Cipher** instance.|
|Cipher|init(opMode : CryptoMode, key : Key, params : ParamsSpec, callback : AsyncCallback\<void>) : void|Sets a key and initializes the **Cipher** instance. This API uses an asynchronous callback to return the result.|
|Cipher|init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>|Sets a key and initializes the **Cipher** instance. This API uses a promise to return the result.|
|Cipher|update(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|Updates the data for encryption and decryption. This API uses an asynchronous callback to return the result.|
|Cipher|update(data : DataBlob) : Promise\<DataBlob>|Updates the data for encryption and decryption. This API uses a promise to return the result.|
|Cipher|doFinal(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|Finalizes the encryption or decryption. This API uses an asynchronous callback to return the result.|
|Cipher|doFinal(data : DataBlob) : Promise\<DataBlob>|Finalizes the encryption or decryption. This API uses a promise to return the result.|

### How to Develop

Encrypt and decrypt data using a symmetric key.

1. Create a **SymKeyGenerator** instance.
2. Use the key generator to generate a symmetric key.
3. Create a **Cipher** instance.
4. Encrypt or decrypt data.

Example: Use AES GCM to encrypt and decrypt data in promise mode.

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

var globalCipher;
var globalGcmParams;
var globalKey;
var globalCipherText;

function genGcmParamsSpec() {
  let arr = [0, 0, 0, 0 , 0, 0, 0, 0, 0, 0 , 0, 0]; // 12 bytes
  let dataIv = new Uint8Array(arr);
  let ivBlob = {data : dataIv};

  arr = [0, 0, 0, 0 , 0, 0, 0, 0]; // 8 bytes
  let dataAad = new Uint8Array(arr);
  let aadBlob = {data : dataAad};

  arr = [0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0]; // 16 bytes
  let dataTag = new Uint8Array(arr);
  let tagBlob = {data : dataTag};  // The authTag of GCM is obtained by doFinal() in encryption and passed in params of init() in decryption.
  
  let gcmParamsSpec = {iv : ivBlob, aad : aadBlob, authTag : tagBlob, algName : "GcmParamsSpec"};
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

function genKeyMaterialBlob() {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72];    // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return {data : keyMaterial};
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
      let promiseInit = globalCipher.init(mode, key, globalGcmParams);    // init
      return promiseInit;
  }).then(() => {
      let plainText = {data : stringToUint8Array('this is test!')};
      let promiseUpdate = globalCipher.update(plainText);   // update
      return promiseUpdate;
  }).then(updateOutput => {
      globalCipherText = updateOutput;
      let promiseFinal = globalCipher.doFinal(null);    // doFinal
      return promiseFinal;
  }).then(authTag => {
      // In GCM mode, the encrypted authentication information needs to be obtained from the output of doFinal() and passed in globalGcmParams of init() in decryption.
      globalGcmParams.authTag = authTag;
      return;
  }).then(() => {
      // Initialize the Cipher instance and start decryption.
      let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
      let promiseInit = globalCipher.init(mode, globalKey, globalGcmParams);    // init
      return promiseInit;
  }).then(() => {
      let promiseUpdate = globalCipher.update(globalCipherText);    // update
      return promiseUpdate;
  }).then(updateOutput => {
      console.info('decrypt plainText: ' + uint8ArrayToString(updateOutput.data));
      let promiseFinal = globalCipher.doFinal(null);    // doFinal
      return promiseFinal;
  }).then(finalOutput => {
      if (finalOutput == null) {  // Check whether the result is null before using finalOutput.data.
          console.info('GCM finalOutput is null');
      }
  }).catch(error => {
      console.error(`catch error, ${error.code}, ${error.message}`);
  })
}
```

Example: Generate a key from the existing data to encrypt and decrypt data using 3DES ECB in callback mode.

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
      globalCipher.init(mode, key, null, (err, ) => {
        let plainText = {data : stringToUint8Array('this is test!')};
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
              globalCipherText = {data : globalCipherText};
            }
            // Initialize the Cipher instance and start decryption.
            let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
            // init
            globalCipher.init(mode, globalKey, null, (err, ) => {
              // update
              globalCipher.update(globalCipherText, (err, updateOutput) => {
                console.info('decrypt plainText: ' + uint8ArrayToString(updateOutput.data));
                // doFinal
                globalCipher.doFinal(null, (error, finalOutput) => {
                  if (finalOutput == null) {  // Check whether the result is null before using finalOutput.data.
                    console.info("decrypt plainText:" + uint8ArrayToString(finalOutput.data));
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
Example: Encrypt and decrypt a large amount in AES GCM mode by calling **update()** multiple times in promise mode.

```javascript
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
    let promiseInit = globalCipher.init(mode, key, globalGcmParams);    // init
    return promiseInit;
  }).then(async () => {
    let plainText = "aaaaa.....bbbbb.....ccccc.....ddddd.....eee"; // Assume that the plaintext is of 43 bytes.
    let messageArr = [];
    let updateLength = 20; // Pass in 20 bytes by update() each time.
    globalCipherText = [];
    
    for (let i = 0; i <= plainText.length; i++) {
      if ((i % updateLength == 0 || i == plainText.length) && messageArr.length != 0) {
        let message = new Uint8Array(messageArr);
        let messageBlob = { data : message };
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
  }).then(() => {
    let promiseFinal = globalCipher.doFinal(null);    // doFinal
    return promiseFinal;
  }).then(authTag => {
    // Obtain the authentication information after encryption.
    globalGcmParams.authTag = authTag;
    return;
  }).then(() => {
    // Initialize the Cipher instance and start decryption.
    let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
    let promiseInit = globalCipher.init(mode, globalKey, globalGcmParams);    // init
    return promiseInit;
  }).then(async () => {
    let updateLength = 20;
    let updateTimes = Math.ceil(globalCipherText.length / updateLength);  // Round up to the nearest integer.
    globalPlainText = "";
    for (let i = 0; i < updateTimes; i++) {
      let messageArr = globalCipherText.slice(i * updateLength, (i + 1) * updateLength);
      let message = new Uint8Array(messageArr);
      let messageBlob = { data : message };
      let updateOutput = await globalCipher.update(messageBlob); // Update by segment.
      globalPlainText += uint8ArrayToString(updateOutput.data);     // Restore the original plaintext.
    }
    return;
  }).then(() => {
    let promiseFinal = globalCipher.doFinal(null);      // doFinal
    return promiseFinal;
  }).then(finalOutput => {
    if (finalOutput == null) {
      console.info('GCM finalOutput is null');
    }
    console.info(`decrypt output: ${globalPlainText}`);
  }).catch(error => {
      console.error(`catch error, ${error.code}, ${error.message}`);
  })
}
```

Encrypt and decrypt data using an asymmetric key pair.

1. Generate an RSA key pair.<br>Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an RSA asymmetric key pair.
2. Create a **Cipher** instance.<br>Call **createCipher()** to create a **Cipher** instance, and set the key and encryption/decryption mode.
3. Encrypt and decrypt data.<br>Call **doFinal()** provided by the **Cipher** instance to encrypt data or decrypt data.

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let plan = "This is cipher test.";

function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  var tmpArray = new Uint8Array(arr);
  return tmpArray;
}

function encryptMessageProMise() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then(rsaKeyPair => {
    let pubKey = rsaKeyPair.pubKey;
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null);
  }).then(() => {
    let input = { data : stringToUint8Array(plan) };
    return cipher.doFinal(input);
  }).then(dataBlob => {
    console.info("EncryptOutPut is " + dataBlob.data);
  });
}

function encryptMessageCallback() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  rsaGenerator.generateKeyPair(function (err, keyPair) {
    let pubKey = keyPair.pubKey;
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null, function (err, data) {
      let input = {data : stringToUint8Array(plan) };
      cipher.doFinal(input, function (err, data) {
        console.info("EncryptOutPut is " + data.data);
      })
    })
  })
}

function decryptMessageProMise() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  let decoder = cryptoFramework.createCipher("RSA1024|PKCS1");
  let keyGenPromise = rsaGenerator.generateKeyPair();
  let keyPair;
  let cipherDataBlob;
  let input = { data : stringToUint8Array(plan) };
  keyGenPromise.then(rsaKeyPair => {
    keyPair = rsaKeyPair;
    return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null);
  }).then(() => {
    return cipher.doFinal(input);
  }).then(dataBlob => {
    console.info("EncryptOutPut is " + dataBlob.data);
    AlertDialog.show({message : "output" + dataBlob.data});
    cipherDataBlob = dataBlob;
    return decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null);
  }).then(() => {
    return decoder.doFinal(cipherDataBlob);
  }).then(decodeData => {
    if (decodeData.data.toString() === input.data.toString()) {
      AlertDialog.show({message : "decrypt success"});
      return;
    }
    AlertDialog.show({message : "decrypt fail"});
  });
}

function decryptMessageCallback() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
  let decoder = cryptoFramework.createCipher("RSA1024|PKCS1");
  let plainText = "this is cipher text";
  let input = {data : stringToUint8Array(plainText) };
  let cipherData;
  let keyPair;
  rsaGenerator.generateKeyPair(function (err, newKeyPair) {
    keyPair = newKeyPair;
    cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, keyPair.pubKey, null, function (err, data) {
      cipher.doFinal(input, function (err, data) {
        AlertDialog.show({ message : "EncryptOutPut is " + data.data} );
        cipherData = data;
        decoder.init(cryptoFramework.CryptoMode.DECRYPT_MODE, keyPair.priKey, null, function (err, data) {
          decoder.doFinal(cipherData, function (err, data) {
            if (input.data.toString() === data.data.toString()) {
              AlertDialog.show({ message : "decrype success"} );
              return;
            }
            AlertDialog.show({ message : "decrype fail"} );
          });
        });
      });
    });
  });
}
```
Example: Use an RSA asymmetric key pair to encrypt and decrypt data. In this example, **doFinal()** is called multiple times to process data by segment.
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  var tmpArray = new Uint8Array(arr);
  return tmpArray;
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

**NOTE**

- In RSA encryption and decryption, **init()** cannot be repeatedly called to initialize a **Cipher** instance. You must create a **Cipher** instance for each encryption and decryption.
- The RSA encryption has a limit on the length of the plaintext to be encrypted. For details, see "Basic Concepts" in [Cryptographic Framework Overview](cryptoFramework-overview.md).
- In RSA decryption, the length of the ciphertext to be decrypted each time is the number of bits of the RSA key divided by 8.

## Signing and Signature Verification

### When to Use

A digital signature can be used to verify the authenticity of a message. Typical signing and signature verification operations involve the following:
1. Use RSA to generate a signature and verify the signature.
2. Use ECC to generate a signature and verify the signature.

### Available APIs

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md). <br>Due to complexity of cryptographic algorithms, the implementation varies depending on the specifications and parameters you use, and cannot be enumerated by sample code. Before you start, understand the APIs to ensure correct use of these APIs.

|Instance|API|Description|
|---|---|---|
|cryptoFramework|createSign(algName : string) : Sign|Creates a **Sign** instance.|
|Sign|init(priKey : PriKey, callback : AsyncCallback\<void>) : void|Sets a key and initializes the **Sign** instance. This API uses an asynchronous callback to return the result.|
|Sign|init(priKey : PriKey) : Promise\<void>|Sets a key and initializes the **Sign** instance. This API uses a promise to return the result.|
|Sign|update(data : DataBlob, callback : AsyncCallback\<void>) : void|Updates the data for signing. This API uses an asynchronous callback to return the result.|
|Sign|update(data : DataBlob) : Promise\<void>|Updates the data for signing. This API uses a promise to return the result.|
|Sign|sign(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|Signs the data. This API uses an asynchronous callback to return the result.|
|Sign|sign(data : DataBlob) : Promise\<DataBlob>|Signs the data. This API uses a promise to return the result.|
|cryptoFramework|function createVerify(algName : string) : Verify|Creates a **Verify** instance.|
|Verify|init(priKey : PriKey, callback : AsyncCallback\<void>) : void|Sets a key and initializes the **Verify** instance. This API uses an asynchronous callback to return the result.|
|Verify|init(priKey : PriKey) : Promise\<void>|Sets a key and initializes the **Verify** instance. This API uses a promise to return the result.|
|Verify|update(data : DataBlob, callback : AsyncCallback\<void>) : void|Updates the data for signature verification. This API uses an asynchronous callback to return the result.|
|Verify|update(data : DataBlob) : Promise\<void>|Updates the data for signature verification. This API uses a promise to return the result.|
|Verify|verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback\<boolean>) : void|Verifies a signature. This API uses an asynchronous callback to return the result.|
|Verify|verify(data : DataBlob, signatureData : DataBlob) : Promise\<boolean>|Verifies a signature. This API uses a promise to return the result.|

### How to Develop

Use RSA to sign data and verify the signature.
1. Generate an RSA key pair.<br>Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an RSA asymmetric key pair.
2. Create a **Sign** instance.<br>Call **createSign()** to create a **Sign** instance, initialize the **Sign** instance, and set a private key for signing.
3. Generate a signature.<br>Call **update()** provided by the **Sign** class to pass in the data for signing and call **sign()** to generate a signature.
4. Create a **Verify** instance.<br>Call **createVerify()** to create a **Verify** instance, initialize the instance, and set a public key for signature verification.
5. Verify the signature.<br>Call **update()** provided by the **Verify** class to pass in the signature data and call **verify()** to verify the signature.
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

function stringToUint8Array(str) {
	var arr = [];
	for (var i = 0, j = str.length; i < j; ++i) {
		arr.push(str.charCodeAt(i));
	}
	var tmpArray = new Uint8Array(arr);
	return tmpArray;
}

let globalKeyPair;
let SignMessageBlob;
let plan1 = "This is Sign test plan1";
let plan2 = "This is Sign test plan1";
let input1 = { data : stringToUint8Array(plan1) };
let input2 = { data : stringToUint8Array(plan2) };

function signMessagePromise() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256");
  let keyGenPromise = rsaGenerator.generateKeyPair();
  keyGenPromise.then( keyPair => {
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
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256");
  rsaGenerator.generateKeyPair(function (err, keyPair) {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    signer.init(priKey, function (err, data) {
      signer.update(input1, function (err, data) {
        signer.sign(input2, function (err, data) {
          SignMessageBlob = data;
          console.info("sign output is " + SignMessageBlob.data);
        });
      });
    });
  });
}

function verifyMessageCallback() {
  let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
  verifyer.init(globalKeyPair.pubKey, function (err, data) {
    verifyer.update(input1, function(err, data) {
      verifyer.verify(input2, SignMessageBlob, function(err, data) {
        console.info("verify result is " + data);
      });
    });
  })
}
```

Use ECDSA to sign data and verify the signature.
1. Generate an ECC key.<br>Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an ECC asymmetric key pair.
2. Create a **Sign** instance.<br>Call **createSign()** to create a **Sign** instance, initialize the **Sign** instance, and set a private key for signing.
3. Generate a signature.<br>Call **update()** provided by the **Sign** class to pass in the data for signing and call **doFinal()** to generate a signature.
4. Create a **Verify** instance.<br>Call **createVerify()** to create a **Verify** instance, initialize the instance, and set a public key for signature verification.
5. Verify the signature.<br>Call **update()** provided by the **Verify** class to pass in the signature data and call **doFinal()** to verify the signature.

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

function stringToUint8Array(str) {
	var arr = [];
	for (var i = 0, j = str.length; i < j; ++i) {
		arr.push(str.charCodeAt(i));
	}
	var tmpArray = new Uint8Array(arr);
	return tmpArray;
}

let globalKeyPair;
let SignMessageBlob;
let plan1 = "This is Sign test plan1";
let plan2 = "This is Sign test plan1";
let input1 = { data : stringToUint8Array(plan1) };
let input2 = { data : stringToUint8Array(plan2) };

function signMessagePromise() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let signer = cryptoFramework.createSign("ECC256|SHA256");
  let keyGenPromise = eccGenerator.generateKeyPair();
  keyGenPromise.then( keyPair => {
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
    signer.init(priKey, function (err, data) {
      signer.update(input1, function (err, data) {
        signer.sign(input2, function (err, data) {
          SignMessageBlob = data;
          console.info("sign output is " + SignMessageBlob.data);
        });
      });
    });
  });
}

function verifyMessageCallback() {
  let verifyer = cryptoFramework.createVerify("ECC256|SHA256");
  verifyer.init(globalKeyPair.pubKey, function (err, data) {
    verifyer.update(input1, function(err, data) {
      verifyer.verify(input2, SignMessageBlob, function(err, data) {
        console.info("verify result is " + data);
      });
    });
  })
}
```
The following example presents how to call **update()** multiple times to implement signing and signature verification.

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  var tmpArray = new Uint8Array(arr);
  return tmpArray;
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
    // Split and decrypt the ciphertext by 128 bytes, and combine the plaintext obtained each time.
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

## Message Digest

### When to Use

A message digest (MD) is a fixed size numeric representation of the content of a message, computed by a hash function. It is sent with the message. The receiver can generate a digest for the message and compare it with the digest received. If the two digests are the same, the message integrity is verified.

Typical MD operations involve the following:

1. Create an **Md** instance.
2. Add one or more segments of data for generating a digest.
3. Compute a digest.
4. Obtain the algorithm and length of a digest.

### Available APIs

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

| Instance         | API                                                      | Description                                              |
| --------------- | ------------------------------------------------------------ | -------------------------------------------------- |
| cryptoFramework | function createMd(algName : string) : Md;                    | Creates an **Md** instance.                  |
| Md              | update(input : DataBlob, callback : AsyncCallback\<void>) : void; | Updates the data for a digest. This API uses an asynchronous callback to return the result.|
| Md              | update(input : DataBlob) : Promise\<void>;                  | Updates the data for a digest. This API uses a promise to return the result. |
| Md              | digest(callback : AsyncCallback\<DataBlob>) : void;         | Generates the digest. This API uses an asynchronous callback to return the result.                      |
| Md              | digest() : Promise\<DataBlob>;                              | Generates the digest. This API uses a promise to return the result.                       |
| Md              | getMdLength() : number;                                      | Obtains the digest length based on the specified digest algorithm.            |
| Md              | readonly algName : string;                                   | Obtains the digest algorithm.                          |

### How to Develop

1. Use **createMd()** to create an **Md** instance.
2. Use **update()** to update the data for computing a digest. **update()** can be called multiple times to update the data by segment.
3. Use **digest()** to compute a digest.
4. Obtain the digest algorithm and length of the digest generated.

```javascript
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
The following example presents how to call **update()** multiple times to update the MD.
```javascript
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
      let messageBlob = { data : message };
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

## Key Agreement

### When to Use


Key agreement allows two parties to establish a shared secret over an insecure channel.

### Available APIs

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

|Instance|API|Description|
|---|---|---|
|cryptoFramework|createKeyAgreement(algName : string) : KeyAgreement|Creates a **KeyAgreement** instance.|
|KeyAgreement|generateSecret(priKey : PriKey, pubKey : PubKey, callback : AsyncCallback\<DataBlob>) : void|Generates a shared secret. This API uses an asynchronous callback to return the result.|
|KeyAgreement|generateSecret(priKey : PriKey, pubKey : PubKey) : Promise\<DataBlob>|Generates a shared secret. This API uses a promise to return the result.|

### How to Develop

1. Use **createKeyAgreement()** to create a **KeyAgreement** instance for subsequent key agreement operations.
2. Use **generateSecret()** provided by **KeyAgreement** to pass in the peer ECC public key object and the ECC private key object generated locally.

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalSelfPriKey;
let globalPeerPubKey;

function ecdhPromise() {
  let peerPubKeyArray = new Uint8Array([48,89,48,19,6,7,42,134,72,206,61,2,1,6,8,42,134,72,206,61,3,1,7,3,66,0,4,83,96,142,9,86,214,126,106,247,233,92,125,4,128,138,105,246,162,215,71,81,58,202,121,26,105,211,55,130,45,236,143,55,16,248,75,167,160,167,106,2,152,243,44,68,66,0,167,99,92,235,215,159,239,28,106,124,171,34,145,124,174,57,92]);
  let peerPubKeyBlob = { data: peerPubKeyArray };
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256");
  eccGenerator.convertKey(peerPubKeyBlob, null).then((peerKeyPair) => {
    globalPeerPubKey = peerKeyPair.pubKey;
    return eccGenerator.generateKeyPair();
  }).then((keyPair) => {
    globalSelfPriKey = keyPair.priKey;
    return eccKeyAgreement.generateSecret(globalSelfPriKey, globalPeerPubKey);
  }).then((secret) => {
    console.info("ecdh promise output is " + secret.data);
  }).catch((error) => {
    console.error("ecdh error.");
  });
}

function ecdhCallback() {
  let peerPubKeyArray = new Uint8Array([48,89,48,19,6,7,42,134,72,206,61,2,1,6,8,42,134,72,206,61,3,1,7,3,66,0,4,83,96,142,9,86,214,126,106,247,233,92,125,4,128,138,105,246,162,215,71,81,58,202,121,26,105,211,55,130,45,236,143,55,16,248,75,167,160,167,106,2,152,243,44,68,66,0,167,99,92,235,215,159,239,28,106,124,171,34,145,124,174,57,92]);
  let peerPubKeyBlob = { data: peerPubKeyArray };
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256");
  eccGenerator.convertKey(peerPubKeyBlob, null, function (err, peerKeyPair) {
    globalPeerPubKey = peerKeyPair.pubKey;
    eccGenerator.generateKeyPair(function (err, keyPair) {
      globalSelfPriKey = keyPair.priKey;
      eccKeyAgreement.generateSecret(globalSelfPriKey, globalPeerPubKey, function (err, secret) {
        if (err) {
          console.error("ecdh error.");
          return;
        }
        console.info("ecdh callback output is " + secret.data);
      });
    });
  })
}
```

## HMAC

### When to Use

A hash-based message authentication code (HMAC) can be used to verify both the integrity and authenticity of a message using a shared secret. 

Typical MAC operations involve the following:

1. Create a **Mac** instance.
2. Initialize the **Mac** instance, add one or more segments of data for generating a MAC, and generate an HMAC.
3. Obtain the algorithm and length of an HMAC.

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

### How to Develop

1. Call **createMac()** to create a **Mac** instance.
2. Call **init()** to initialize the **Mac** instance with the symmetric key passed in.
3. Call **update()** one or more times to add the data for computing a MAC.
4. Call **doFinal()** to generate a MAC.
5. Obtain the algorithm and length of the MAC.

```javascript
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
    data : stringToUint8Array("12345678abcdefgh")
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
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  console.info("[Promise]: Mac algName is: " + mac.algName);
  let KeyBlob = {
    // 128-bit key
    data : stringToUint8Array("12345678abcdefgh")
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
            console.info("[Callback]: HMAC result: " + macOutput.data);
            let macLen = mac.getMacLength();
            console.info("[Callback]: MAC len: " + macLen);
          }
        });
      });
    });
  });
}
```
Generate an HMAC by segment. 
```javascript
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
        let messageBlob = { data : message };
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

1. Generate a random number of the specified length.
2. Set a seed based on the random number generated.

### Available APIs

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

| Instance         | API                                                      | Description                                          |
| --------------- | ------------------------------------------------------------ | ---------------------------------------------- |
| cryptoFramework | function createRandom() : Random;                            | Creates a **Random** instance.                          |
| Random          | generateRandom(len : number, callback: AsyncCallback\<DataBlob>) : void; | Generates a random number. This API uses an asynchronous callback to return the result.  |
| Random          | generateRandom(len : number) : Promise\<DataBlob>;          | Generates a random number. This API uses a promise to return the result.     |
| Random          | setSeed(seed : DataBlob) : void;                            | Sets a seed. |

### How to Develop

1. Call **createRandom()** to create a **Random** instance.
2. Call **generateRandom()** to generate a random number of the given length.
3. Call **setSeed()** to set a seed.

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

// Generate a random number and set a seed in promise mode.
function doRandByPromise(len) {
  var rand;
  try {
    rand = cryptoFramework.createRandom();
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
  }
  var promiseGenerateRand = rand.generateRandom(len);
  promiseGenerateRand.then(randData => {
    console.error("[Promise]: rand result: " + randData.data);
      try {
          rand.setSeed(randData);
      } catch (error) {
          console.log("setSeed failed, errCode: " + error.code + ", errMsg: " + error.message);
      }
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// Generate a random number and set a seed in callback mode.
function doRandByCallback(len) {
  var rand;
  try {
    rand = cryptoFramework.createRandom();
  } catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  rand.generateRandom(len, (err, randData) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    } else {
      console.error("[Callback]: generate random result: " + randData.data);
      try {
          rand.setSeed(randData);
      } catch (error) {
          console.log("setSeed failed, errCode: " + error.code + ", errMsg: " + error.message);
      }
    }
  });
}
```
