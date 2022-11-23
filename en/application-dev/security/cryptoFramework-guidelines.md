# Crypto Framework Development

> **NOTE**
>
> This development guide applies to API version 9, OpenHarmony SDK version 3.2.7 or later, and JS development.

## Generating and Converting Keys

**When to Use**

Typical key generation operations involve the following:

1. Randomly create a key instance. This instance can be used for subsequent encryption and decryption.
2. Convert external or stored binary data into a key instance. This instance can be used for subsequent encryption and decryption.
3. Obtain the binary data of a key for storage or transmission.
> **NOTE**
>
> The key instance can be a symmetric key instance (**SymKey**) or an asymmetric key pair instance (**KeyPair**). The **KeyPair** instance consists a public key (PubKey) and a private key (**PriKey**). For details about the relationship between keys, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).


**Available APIs**

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

The table below describes the APIs used in this guide.

|Instance|API|Description|
|---|---|---|
|cryptoFramework|createAsyKeyGenerator(algName : string) : AsyKeyGenerator|Creates an **AsyKeyGenerator** instance.|
|cryptoFramework|createSymKeyGenerator(algName : string) : SymKeyGenerator|Creates a **SymKeyGenerator** instance.|
|AsyKeyGenerator|generateKeyPair(callback : AsyncCallback\<KeyPair>) : void|Generates an asymmetric key pair randomly. This API uses an asynchronous callback to return the result.|
|AsyKeyGenerator|generateKeyPair() : Promise\<KeyPair>|Generates an asymmetric key pair randomly. This API uses a promise to return the result.|
|SymKeyGenerator|generateSymKey(callback : AsyncCallback\<SymKey>) : void|Generates a symmetric key randomly. This API uses an asynchronous callback to return the result.|
|SymKeyGenerator|generateSymKey() : Promise\<SymKey>|Generates a symmetric key randomly. This API uses a promise to return the result.|
| AsyKeyGenerator          | convertKey(pubKey : DataBlob, priKey : DataBlob, callback : AsyncCallback\<KeyPair>) : void | Converts binary data into a key pair. This API uses an asynchronous callback to return the result.<br>(**pubKey** or **priKey** can be **null**. That is, you can pass in only **pubKey** or **priKey**. As a result, the return **KeyPair** instance contains only the public or private key.) |
| AsyKeyGenerator          | convertKey(pubKey : DataBlob, priKey : DataBlob) : Promise\<KeyPair> | Converts the binary public key and private key data into a key pair. This API uses a promise to return the result.<br>(**pubKey** or **priKey** can be **null**. That is, you can pass in only **pubKey** or **priKey**. As a result, the returned **KeyPair** instance contains only the public or private key.) |
| SymKeyGenerator         | convertKey(key : DataBlob, callback : AsyncCallback\<SymKey>) : void| Converts binary data into a symmetric key. This API uses an asynchronous callback to return the result.|
| SymKeyGenerator         |convertKey(pubKey : DataBlob, priKey : DataBlob) : Promise\<KeyPair>| Converts binary data into a symmetric key. This API uses a promise to return the result.|
| Key | getEncoded() : DataBlob;  | Obtains the binary data of a key. (The child class instances of **Key** include **SymKey**, **PubKey**, and **PriKey**.)|

**How to Develop**

Example 1: Randomly generate an asymmetric key pair and obtain its binary data.

1. Create an **AsyKeyGenerator** instance.
2. Randomly generate an asymmetric key pair using **AsyKeyGenerator**.
3. Obtain binary data of the key pair generated.

For example, randomly generate an RSA key (1024 bits and two primes) using promise-based APIs.

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

Example 2: Randomly generate a symmetric key and obtain its binary data.

1. Create a **SymKeyGenerator** instance.
2. Randomly generate a symmetric key using **SymKeyGenerator**. 
3. Obtain binary data of the key generated.

For example, randomly generate an AES key (256 bits) using promise-based APIs.

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

Example 3: Generate an asymmetric key pair from the binary RSA key data.

1. Obtain the binary data of the RSA public or private key. The public key must comply with the ASN.1 syntax, X.509 specifications, and DER encoding format. The private key must comply with the ASN.1 syntax, PKCS #8 specifications, and DER encoding format.
2. Create an **AsyKeyGenerator** instance and call **convertKey()** to convert the key binary data (data of the private or public key, or both) passed in to a **KeyPair** instance.

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

**NOTE**

The public key returned by **convertKey()** must be in the DER format complying with X.509 specifications, and the private key must be in the DER format complying with PKCS #8 specifications.

Example 4: Generate an asymmetric key pair from the binary ECC key data.

1. Obtain the ECC binary key data and encapsulate it into a **DataBlob** instance.
2. Call **convertKey()** to convert the key binary data (data of the private or public key, or both) passed in to a **KeyPair** instance.

```javascript
function convertEccAsyKey() {
    let pubKeyArray = new Uint8Array([4,196,55,233,100,227,224,38,38,5,128,81,53,112,129,7,59,189,116,105,182,87,190,85,31,248,172,116,213,7,206,85,190,65,169,193,138,173,232,187,74,54,78,251,29,131,192,223,251,227,170,138,80,7,98,193,216,168,235,114,255,188,70,134,104]);
    let priKeyArray = new Uint8Array([255,70,89,220,189,19,41,157,175,173,83,60,74,216,195,96,24,181,231,23,112,247,150,126,15,155,24,79,33,97,31,225]);
    let pubKeyBlob = { data: pubKeyArray };
    let priKeyBlob = { data: priKeyArray };
    let generator = cryptoFrameWork.createAsyKeyGenerator("ECC256");
    generator.convertKey(pubKeyBlob, priKeyBlob, (error, data) => {
        if (error) {
            AlertDialog.show({message : "Convert keypair fail"});
        }
        AlertDialog.show({message : "Convert KeyPair success"});
    })
}
```

Example 5: Generate a symmetric key from binary key data.

1. Create a **SymKeyGenerator** instance.
2. Generate a symmetric key from the binary data passed in.
3. Obtain binary data of the key generated.

For example, generate a 3DES key (192 bits only) using callback-based APIs.

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
  } catch (error) {    // Throw an exception immediately in synchronous mode when an error is detected during the parameter check.
    console.error(`convertKey failed, ${error.code}, ${error.message}`);
    return;
  }
}
```

## Encrypting and Decrypting Data

**When to Use**

Important data needs to be encrypted in data storage or transmission for security purposes. Typical encryption and decryption operations involve the following:
1. Encrypt and decrypt data using a symmetric key.
2. Encrypt and decrypt data using an asymmetric key pair.

**Available APIs**

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

The table below describes the APIs used in this guide.

|Instance|API|Description|
|---|---|---|
|cryptoFramework|createCipher(transformation : string) : Cipher|Creates a **Cipher** instance.|
|Cipher|init(opMode : CryptoMode, key : Key, params : ParamsSpec, callback : AsyncCallback\<void>) : void|Sets a key and initializes the **Cipher** instance. This API uses an asynchronous callback to return the result.|
|Cipher|init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>|Sets a key and initializes the **Cipher** instance. This API uses a promise to return the result.|
|Cipher|update(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|Updates the data for encryption and decryption. This API uses an asynchronous callback to return the result.|
|Cipher|update(data : DataBlob) : Promise\<DataBlob>|Updates the data for encryption and decryption. This API uses a promise to return the result.|
|Cipher|doFinal(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void|Finalizes the encryption or decryption. This API uses an asynchronous callback to return the result.|
|Cipher|doFinal(data : DataBlob) : Promise\<DataBlob>|Finalizes the encryption or decryption. This API uses a promise to return the result.|

**How to Develop**

Example 1: Encrypt and decrypt data using a symmetric key.

1. Create a **SymKeyGenerator** instance.
2. Use the key generator to generate a symmetric key.
3. Create a **Cipher** instance.
4. Encrypt or decrypt data.

For example, use AES GCM to encrypt and decrypt data using promise-based APIs.

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
  let tagBlob = {data : dataTag};
  let gcmParamsSpec = {iv : ivBlob, aad : aadBlob, authTag : tagBlob, algoName : "GcmParamsSpec"};
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

// Convert byte streams into strings in plaintext.
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

// Output the byte streams in hexadecimal format.
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


// Automatically generate a key in AES GCM mode and return the result in a promise.
function testAesGcm() {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve('testAesGcm');
    }, 10)
  }).then(() => {
    // Create a SymKeyGenerator instance.
    let symAlgoName = 'AES128';
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgoName);
    if (symKeyGenerator == null) {
      console.error('createSymKeyGenerator failed');
      return;
    }
    console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);
    // Use the key generator to randomly generate a 128-bit symmetric key.
    let promiseSymKey = symKeyGenerator.generateSymKey();
    // Constructor
    globalGcmParams = genGcmParamsSpec();

    // Create a Cipher instance.
    let cipherAlgoName = 'AES128|GCM|PKCS7';
    try {
      globalCipher = cryptoFramework.createCipher(cipherAlgoName);
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
      // Initialize the cipher environment and start encryption.
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
      // Obtain the authentication information after encryption.
      globalGcmParams.authTag = authTag;
      return;
  }).then(() => {
      // Initialize the cipher environment and start decryption.
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
      if (finalOutput == null) {
          console.info('GCM finalOutput is null');
      }
  }).catch(error => {
      console.error(`catch error, ${error.code}, ${error.message}`);
  })
}
```

For example, 3DES ECB is used. Generate a key from the existing data to encrypt and decrypt data using callback-based APIs.

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

// Convert byte streams into strings in plaintext.
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

// Output the byte streams in hexadecimal format.
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

// For example, 3DES ECB is used. Use existing data to generate a key to encrypt and decrypt data, and return the result in a callback.
function test3DesEcb() {
  // Create a SymKeyGenerator instance.
  let symAlgoName = '3DES192';
  let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgoName);
  if (symKeyGenerator == null) {
    console.error('createSymKeyGenerator failed');
    return;
  }
  console.info(`symKeyGenerator algName: ${symKeyGenerator.algName}`);

  // Create a Cipher instance.
  let cipherAlgoName = '3DES192|ECB|PKCS7';
  try {
    globalCipher = cryptoFramework.createCipher(cipherAlgoName);
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

      // Initialize the cipher environment and start encryption.
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
            // Initialize the cipher environment and start decryption.
            let mode = cryptoFramework.CryptoMode.DECRYPT_MODE;
            // init
            globalCipher.init(mode, globalKey, null, (err, ) => {
              // update
              globalCipher.update(globalCipherText, (err, updateOutput) => {
                console.info('decrypt plainText: ' + uint8ArrayToString(updateOutput.data));
                // doFinal
                globalCipher.doFinal(null, (error, finalOutput) => {
                  if (finalOutput != null) {
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

Example 2: Encrypt and decrypt data using an asymmetric key pair.

1. Generate an RSA key pair. 

   Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an RSA asymmetric key pair.

2. Create a **Cipher** instance.

   Call **createCipher()** to create a **Cipher** instance, and set the key and encryption/decryption mode.

3. Perform encryption and decryption operations. 

   Call **doFinal()** provided by the **Cipher** instance to encrypt data or decrypt data.

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
```

**NOTE**

- In RSA encryption and decryption, **init()** cannot be repeatedly called to initialize the **Cipher** instance. You must create a **Cipher** instance for each of encryption and decryption.
- The RSA encryption has a limit on the length of the plaintext to be encrypted. For details, see "Basic Concepts" in [Crypto Framework Overview](cryptoFramework-overview.md).
- In RSA decryption, the length of the ciphertext to be decrypted each time is the number of bits of the RSA key divided by 8.

## Signing Data and Verifying Signatures

**When to Use**

A digital signature can be used to verify the authenticity of a message. Typical signing and signature verification operations involve the following:
1. Use RSA to sign data and verify the signature.
2. Use ECC to sign data and verify the signature.

**Available APIs**

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

|Instance|API|Description|
|---|---|---|
|cryptoFramework|createSign(algName : string) : Sign|Creates a **Sign** instance.|
|Sign|init(priKey : PriKey, callback : AsyncCallback\<void>) : void|Sets a key and initializes the **Sign** instance. This API uses an asynchronous callback to return the result.|
|Sign|init(priKey : PriKey) : Promise\<void>|Sets a key and initializes the **Sign** instance. This API uses a promise to return the result.|
|Sign|update(data : DataBlob, callback : AsyncCallback\<void>) : void|Updates the data for signing. This API uses an asynchronous callback to return the result.|
|Sign|update(data : DataBlob) : Promise\<void>|Updates the data for signing. This API uses a promise to return the result.|
|Sign|sign(data : DataBlob, callback : AsyncCallback<DataBlob>) : void|Signs the data. This API uses an asynchronous callback to return the result.|
|Sign|sign(data : DataBlob) : Promise<DataBlob>|Signs the data. This API uses a promise to return the result.|
|cryptoFramework|function createVerify(algName : string) : Verify|Creates a **Verify** instance.|
|Verify|init(priKey : PriKey, callback : AsyncCallback\<void>) : void|Sets a key and initializes the **Verify** instance. This API uses an asynchronous callback to return the result.|
|Verify|init(priKey : PriKey) : Promise\<void>|Sets a key and initializes the **Verify** instance. This API uses a promise to return the result.|
|Verify|update(data : DataBlob, callback : AsyncCallback\<void>) : void|Updates the data for signature verification. This API uses an asynchronous callback to return the result.|
|Verify|update(data : DataBlob) : Promise\<void>|Updates the data for signature verification. This API uses a promise to return the result.|
|Verify|verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback<boolean>) : void|Verifies the signature. This API uses an asynchronous callback to return the result.|
|Verify|verify(data : DataBlob, signatureData : DataBlob) : Promise<boolean>|Verifies the signature. This API uses a promise to return the result.|

**How to Develop**

Example 1: Use RSA to sign data and verify the signature.
1. Generate an RSA key pair.

   Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an RSA asymmetric key pair.

2. Create a **Sign** instance.

   Call **createSign()** to create a **Sign** instance, initialize the **Sign** instance, and set a private key for signing.

3. Generate a signature.

   Call **update()** provided by the **Sign** class to add the data for signing and call **sign()** to generate a signature.

4. Create a **Verify** instance.

   Call **createVerify()** to create a **Verify** instance, initialize the instance, and set a public key for signature verification.

5. Verify the signature.

   Call **update()** provided by the **Verify** class to add signature data and call **verify()** to verify the signature.
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

Example 2: Using ECC to sign data and verify the signature.
1. Generate an ECC key.

   Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an ECC asymmetric key pair.

2. Create a **Sign** instance.

   Call **createSign()** to create a **Sign** instance, initialize the **Sign** instance, and set a private key for signing.

3. Generate a signature.

   Call **update()** provided by the **Sign** class to add the data for signing and call **doFinal()** to generate a signature.

4. Create a **Verify** instance.

   Call **createVerify()** to create a **Verify** instance, initialize the instance, and set a public key for signature verification.

5. Verify the signature.

   Call **update()** provided by the **Verify** class to add signature data and call **doFinal()** to verify the signature.

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

## Generating a Digest

**When to Use**

A message digest is a fixed size numeric representation of the content of a message, computed by a has function. The message digest is sent with the message. The receiver can generate a digest for the message and compare it with the digest received. If the two digests are the same, the message integrity is verified.

Typical message digest operations involve the following:

1. Create an **Md** instance.
2. Add one or more segments of data for generating a digest.
3. Compute a digest. 
4. Obtain the algorithm and length of a digest.

**Available APIs**

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

| Instance         | API                                                      | Description                                              |
| --------------- | ------------------------------------------------------------ | -------------------------------------------------- |
| cryptoFramework | function createMd(algName : string) : Md;                    | Creates an **Md** instance.                  |
| Md              | update(input : DataBlob, callback : AsyncCallback\<void\>) : void; | Updates the data for a digest. This API uses an asynchronous callback to return the result.|
| Md              | update(input : DataBlob) : Promise\<void\>;                  | Updates the data for a digest. This API uses a promise to return the result. |
| Md              | digest(callback : AsyncCallback\<DataBlob\>) : void;         | Generates the digest. This API uses an asynchronous callback to return the result.                      |
| Md              | digest() : Promise\<DataBlob\>;                              | Generates the digest. This API uses a promise to return the result.                       |
| Md              | getMdLength() : number;                                      | Obtains the digest length based on the specified digest algorithm.            |
| Md              | readonly algName : string;                                   | Obtains the digest algorithm.                          |

**How to Develop**

1. Call **createMd()** to create an **Md** instance.
2. Call **update()** to update the data for computing a digest. **update()** can be called multiple times to update the data by segment.
3. Call **digest()** to compute a digest.
4. Obtain the digest algorithm and length of the digest generated.

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert string into uint8Arr.
function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; ++i) {
      arr.push(str.charCodeAt(i));
  }
  var tmpUint8Array = new Uint8Array(arr);
  return tmpUint8Array;
}

// Generate a dataBlob of the given length.
function GenDataBlob(dataBlobLen) {
  var dataBlob;
  if (dataBlobLen == 12) {
      dataBlob = {data: stringToUint8Array("my test data")};
  } else {
      console.error("GenDataBlob: dataBlobLen is invalid");
      dataBlob = {data: stringToUint8Array("my test data")};
  }
  return dataBlob;
}

// Compute a message digest using promise-based APIs.
function doMdByPromise(algName) {
  var md;
  try {
    md = cryptoFramework.createMd(algName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
  }
  console.error("[Promise]: Md algName is: " + md.algName);
  var promiseMdUpdate = md.update(GenDataBlob(12));
  promiseMdUpdate.then(() => {
    var PromiseMdDigest = md.digest();
    return PromiseMdDigest;
  }).then(mdOutput => {
    console.error("[Promise]: MD result: " + mdOutput.data);
    var mdLen = md.getMdLength();
    console.error("[Promise]: MD len: " + mdLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// Compute a message digest using callback-based APIs.
function doMdByCallback(algName) {
  var md;
  try {
    md = cryptoFramework.createMd(algName);
  } catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  console.error("[Callback]: Md algName is: " + md.algName);
  md.update(GenDataBlob(12), (err,) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    }
    md.digest((err1, mdOutput) => {
      if (err1) {
        console.error("[Callback]: err: " + err1.code);
      } else {
        console.error("[Callback]: MD result: " + mdOutput.data);
        var mdLen = md.getMdLength();
        console.error("[Callback]: MD len: " + mdLen);
      }
    });
  });
}
```

## Performing Key Agreement

**When to Use**

Key agreement allows two parties to establish a shared secret over an insecure channel.

**Available APIs**

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

|Instance|API|Description|
|---|---|---|
|cryptoFramework|createKeyAgreement(algName : string) : KeyAgreement|Creates a **KeyAgreement** instance.|
|KeyAgreement|generateSecret(priKey : PriKey, pubKey : PubKey, callback : AsyncCallback\<DataBlob>) : void|Generates a shared secret. This API uses an asynchronous callback to return the result.|
|KeyAgreement|generateSecret(priKey : PriKey, pubKey : PubKey) : Promise\<DataBlob>|Generates a shared secret. This API uses a promise to return the result.|

**How to Develop**

1. Generate an ECC key.

   Call **createAsyKeyGenerator()** to create an **AsyKeyGenerator** instance and generate an ECC asymmetric key pair.

2. Generate a shared secret by using the private and public ECC keys.

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalKeyPair;

function ecdhPromise() {
  let eccGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
  let eccKeyAgreement = cryptoFramework.createKeyAgreement("ECC256");
  let keyGenPromise = eccGenerator.generateKeyPair();
  keyGenPromise.then( keyPair => {
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

## Generating a MAC

**When to Use**

A message authentication code (MAC) can be used to verify both the integrity and authenticity of a message using a shared secret. 

Typical MAC operations involve the following:

1. Create a **Mac** instance.
2. Initialize the **Mac** instance, add one or more segments of data for generating a MAC, and generate a MAC.
3. Obtain the algorithm and length of a MAC.

**Available APIs**

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

| Instance         | API                                                      | Description                                               |
| --------------- | ------------------------------------------------------------ | --------------------------------------------------- |
| cryptoFramework | function createMac(algName : string) : Md;                    | Creates a **Mac** instance.                |
| Mac             | init(key : SymKey, callback : AsyncCallback\<void\>) : void; | Initializes the MAC operation. This API uses an asynchronous callback to return the result.|
| Mac             | init(key : SymKey) : Promise\<void\>;                        | Initializes the MAC operation. This API uses a promise to return the result. |
| Mac             | update(input : DataBlob, callback : AsyncCallback\<void\>) : void; | Updates the data for the MAC operation. This API uses an asynchronous callback to return the result.      |
| Mac             | update(input : DataBlob) : Promise\<void\>;                  | Updates the data for the MAC operation. This API uses a promise to return the result.       |
| Mac             | doFinal(callback : AsyncCallback\<DataBlob\>) : void;        | Finalizes the MAC operation to generate a MAC. This API uses an asynchronous callback to return the result.                |
| Mac             | doFinal() : Promise\<DataBlob\>;                             | Finalizes the MAC operation to generate a MAC. This API uses a promise to return the result.                 |
| Mac             | getMacLength() : number;                                     | Obtains the length of the MAC based on the specified algorithm.              |
| Mac             | readonly algName : string;                                   | Obtains the algorithm.                           |

**How to Develop**

1. Call **createMac()** to create a **Mac** instance.
2. Call **init()** to initialize the **Mac** instance with the symmetric key passed in.
3. Call **update()** one or more times to add the data for computing a MAC.
4. Call **doFinal()** to generate a MAC.
5. Obtain the algorithm and length of the MAC.

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

// Convert string into uint8Arr.
function stringToUint8Array(str) {
  var arr = [];
  for (var i = 0, j = str.length; i < j; ++i) {
      arr.push(str.charCodeAt(i));
  }
  var tmpUint8Array = new Uint8Array(arr);
  return tmpUint8Array;
}

// Generate a blob.
function GenDataBlob(dataBlobLen) {
  var dataBlob;
  if (dataBlobLen == 12) {
      dataBlob = {data: stringToUint8Array("my test data")};
  } else {
      console.error("GenDataBlob: dataBlobLen is invalid");
      dataBlob = {data: stringToUint8Array("my test data")};
  }
  return dataBlob;
}

// Generate a MAC using promise-based APIs.
function doHmacByPromise(algName) {
  var mac;
  try {
    mac = cryptoFramework.createMac(algName);
  } catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
  }
  console.error("[Promise]: Mac algName is: " + mac.algName);
  var KeyBlob = {
    data : stringToUint8Array("12345678abcdefgh")
  }
  var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  var promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
  promiseConvertKey.then(symKey => {
    var promiseMacInit = mac.init(symKey);
    return promiseMacInit;
  }).then(() => {
    var promiseMacUpdate = mac.update(GenDataBlob(12));
    return promiseMacUpdate;
  }).then(() => {
    var PromiseMacDoFinal = mac.doFinal();
    return PromiseMacDoFinal;
  }).then(macOutput => {
    console.error("[Promise]: HMAC result: " + macOutput.data);
    var macLen = mac.getMacLength();
    console.error("[Promise]: MAC len: " + macLen);
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// Generate a MAC using callback-based APIs.
function doHmacByCallback(algName) {
  var mac;
  try {
    mac = cryptoFramework.createMac(algName);
  } catch (error) {
    AlertDialog.show({message: "[Callback]: error code: " + error.code + ", message is: " + error.message});
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
  }
  var KeyBlob = {
    data : stringToUint8Array("12345678abcdefgh")
  }
  var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
  symKeyGenerator.convertKey(KeyBlob, (err, symKey) => {
    if (err) {
      console.error("[Callback]: err: " + err.code);
    }
    mac.init(symKey, (err1, ) => {
      if (err1) {
        console.error("[Callback]: err: " + err1.code);
      }
      mac.update(GenDataBlob(12), (err2, ) => {
        if (err2) {
          console.error("[Callback]: err: " + err2.code);
        }
        mac.doFinal((err3, macOutput) => {
          if (err3) {
            console.error("[Callback]: err: " + err3.code);
          } else {
            console.error("[Callback]: HMAC result: " + macOutput.data);
            var macLen = mac.getMacLength();
            console.error("[Callback]: MAC len: " + macLen);
          }
        });
      });
    });
  });
}
```



## Generating Random Numbers

**When to Use**

Typical random number operations involve the following:

1. Generate a random number.
2. Set a seed based on the random number generated.

**Available APIs**

For details about the APIs, see [Crypto Framework](../reference/apis/js-apis-cryptoFramework.md).

| Instance         | API                                                      | Description                                          |
| --------------- | ------------------------------------------------------------ | ---------------------------------------------- |
| cryptoFramework | function createRandom() : Random;                            | Creates a **Random** instance.                          |
| Random          | generateRandom(len : number, callback: AsyncCallback\<DataBlob\>) : void; | Generates a random number. This API uses an asynchronous callback to return the result.    |
| Random          | generateRandom(len : number) : Promise\<DataBlob\>;          | Generates a random number. This API uses a promise to return the result.     |
| Random          | setSeed(seed : DataBlob, callback : AsyncCallback\<void\>) : void; | Sets a seed. This API uses an asynchronous callback to return the result.|
| Random          | setSeed(seed : DataBlob) : Promise\<void\>;                  | Sets a seed. This API uses a promise to return the result. |

**How to Develop**

1. Call **createRandom()** to create a **Random** instance.
2. Call **generateRandom()** to generate a random number of the given length.
3. Call **setSeed()** to set a seed.

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

// Generate a random number and set a seed using promise-based APIs.
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
    var promiseSetSeed = rand.setSeed(randData);
    return promiseSetSeed;
  }).then(() => {
    console.error("[Promise]: setSeed success");
  }).catch(error => {
    console.error("[Promise]: error: " + error.message);
  });
}

// Generate a random number and set a seed using callback-based APIs.
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
      rand.setSeed(randData, (err1,) => {
        if (err1) {
          console.error("[Callback] err: " + err1.code);
        } else {
          console.error("[Callback]: setSeed success");
        }
      });
    }
  });
}
```
