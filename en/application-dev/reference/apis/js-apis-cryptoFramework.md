# Crypto Framework

The **cryptoFramework** module shields underlying hardware and algorithm libraries and provides unified APIs for crytographic operations.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9.

## Modules to Import

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"
```

## Result

 Enumerates the error codes.

 **System capability**: SystemCapability.Security.CryptoFramework

| Name                                 | Default Value  | Description                     |
| --------------------------------------| -------- | -------------------------|
| INVALID_PARAMS                        | 401      | Invalid parameters.               |
| NOT_SUPPORT                           | 801      | This operation is not supported.             |
| ERR_OUT_OF_MEMORY                     | 17620001 | Memory error.               |
| ERR_RUNTIME_ERROR                     | 17620002 | Runtime error.          |
| ERR_CRYPTO_OPERATION                  | 17630001 | Crypto operation error.   |

## DataBlob
Defines a binary data array.
 **System capability**: SystemCapability.Security.CryptoFramework
| Name          | Type          | Readable| Writable| Description              |
| -------------- | -------------- | ---- | ---- | ----------------|
| data           | Uint8Array     | Yes  | Yes  | Data.   |

## cryptoFramework.createMac

createMac(algName : string) : Mac

Creates a **Mac** instance for message authentication code (MAC) operations.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Digest algorithm to use, which can be SHA-1, SHA-224, SHA-256, SHA-384, or SHA-512.|

**Return value**

| Type| Description                                   |
| ---- | --------------------------------------- |
| Mac  | [Mac](#mac) instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var mac;
try {
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
}
```

## Mac

Provides APIs for MAC operations. Before using any API of the **Mac** class, you must create a **Mac** instance by using [createMac](#cryptoframeworkcreatemac).

### **Attributes**

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                |
| ------- | ------ | ---- | ---- | -------------------- |
| algName | string | Yes  | No  | Digest algorithm to use.|

### init

init(key : SymKey, callback : AsyncCallback\<void>) : void;	

Initializes the MAC computation using a symmetric key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| key   | SymKey                   | Yes  | Shared symmetric key.      |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var mac;
try {
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
}
var KeyBlob;
var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
symKeyGenerator.convertKey(KeyBlob, (err, symKey) => {
    if (err) {
        console.error("[Callback] err: " + err.code);
    }
    mac.init(symKey, (err1, ) => {
        if (err1) {
            console.error("[Callback] err: " + err1.code);
        }
    });
});
```



### init

init(key : SymKey) : Promise\<void>;

Initializes the MAC computation using a symmetric key. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type  | Mandatory| Description        |
| ------ | ------ | ---- | ------------ |
| key    | SymKey | Yes  | Shared symmetric key.|

**Return value**

| Type           | Description        |
| --------------- | ------------ |
| Promise\<void> | Promise used to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var mac;
try {
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
    AlertDialog.show({message: "[Promise]: error code: " + error.code + ", message is: " + error.message});
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
    
}
console.error("Mac algName is: " + mac.algName);

var KeyBlob;
var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
var promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
promiseConvertKey.then(symKey => {
    var promiseMacInit = mac.init(symKey);
    return promiseMacInit;
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});

```

### update

update(input : DataBlob, callback : AsyncCallback\<void>) : void;

Updates the MAC computation data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ---------- |
| input    | DataBlob              | Yes  | Message to pass in.        |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var KeyBlob;
var mac;
try {
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
    AlertDialog.show({message: "[Callback]: error code: " + error.code + ", message is: " + error.message});
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
}
var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
symKeyGenerator.convertKey(KeyBlob, (err, symKey) => {
    if (err) {
        console.error("[Callback] err: " + err.code);
    }
    mac.init(symKey, (err1, ) => {
        if (err1) {
            console.error("[Callback] err: " + err1.code);
        }
        let blob;
      	mac.update(blob, (err2, data) => {
        	if (err2) {
            console.error("[Callback] err: " + err2.code);
        	}
      	});
    });
});
```

### update

update(input : DataBlob) : Promise\<void>;

Updates the MAC computation data. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| input  | DataBlob | Yes  | Message to pass in.|

**Return value**

| Type           | Description        |
| --------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var mac;
try {
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
    AlertDialog.show({message: "[Promise]: error code: " + error.code + ", message is: " + error.message});
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
}
console.error("Mac algName is: " + mac.algName);
AlertDialog.show({message: "Mac algName is: " + mac.algName});

var KeyBlob;

var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
var promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
promiseConvertKey.then(symKey => {
    var promiseMacInit = mac.init(symKey);
    return promiseMacInit;
}).then(() => {
    let blob;
    var promiseMacUpdate = mac.update(blob);
    return promiseMacUpdate;
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});

```



### doFinal

doFinal(callback : AsyncCallback\<DataBlob>) : void;

Finalizes the MAC computation. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name  | Type                     | Mandatory| Description          |
| -------- | ------------------------- | ---- | -------- |
| callback | AsyncCallback\<DataBlob> | Yes  | Callback invoked to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var KeyBlob;
var mac;
try {
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
    AlertDialog.show({message: "[Callback]: error code: " + error.code + ", message is: " + error.message});
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);  
}
var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
symKeyGenerator.convertKey(KeyBlob, (err, symKey) => {
    if (err) {
        console.error("[Callback] err: " + err.code);
    }
    mac.init(symKey, (err1, ) => {
        if (err1) {
            console.error("[Callback] err: " + err1.code);
        }
        let blob;
        mac.update(blob, (err2, ) => {
            if (err2) {
                console.error("[Callback] err: " + err2.code);
            }
            mac.doFinal((err3, macOutput) => {
                if (err3) {
                    console.error("[Callback] err: " + err3.code);
                } else {
                    console.error("[Promise]: HMAC result: " + macOutput);
                }
            });
        });
    });
});
```

### doFinal

doFinal() : Promise\<DataBlob>

Finalizes the MAC computation. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type             | Description       |
| ------------------- | ----------- |
| Promise\<DataBlob> | Promise used to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var mac;
try {
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);  
}
console.error("Mac algName is: " + mac.algName);
AlertDialog.show({message: "Mac algName is: " + mac.algName});

var KeyBlob;
var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
var promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
promiseConvertKey.then(symKey => {
    var promiseMacInit = mac.init(symKey);
    return promiseMacInit;
}).then(() => {
    let blob;
    var promiseMacUpdate = mac.update(blob);
    return promiseMacUpdate;
}).then(() => {
    var PromiseMacDoFinal = mac.doFinal();
    return PromiseMacDoFinal;
}).then(macOutput => {
    console.error("[Promise]: HMAC result: " + macOutput.data);
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});
```

### getMacLength

getMacLength() : number

Obtains the MAC length, in bytes.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type  | Description                     |
| ------ | ------------------------- |
| number | MAC length obtained.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var mac;
try {
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
}
console.error("Mac algName is: " + mac.algName);
AlertDialog.show({message: "Mac algName is: " + mac.algName});

var KeyBlob;
var symKeyGenerator = cryptoFramework.createSymKeyGenerator("AES128");
var promiseConvertKey = symKeyGenerator.convertKey(KeyBlob);
promiseConvertKey.then(symKey => {
    var promiseMacInit = mac.init(symKey);
    return promiseMacInit;
}).then(() => {
    let blob;
    var promiseMacUpdate = mac.update(blob);
    return promiseMacUpdate;
}).then(() => {
    var PromiseMacDoFinal = mac.doFinal();
    return PromiseMacDoFinal;
}).then(macOutput => {
    console.error("[Promise]: HMAC result: " + macOutput.data);
    let macLen = mac.getMacLength();
	AlertDialog.show({message: "MAC len: " + macLen});
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});
```

## cryptoFramework.createMd

createMd(algName : string) : Md

Creates an **Md** instance for message digest operations.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Digest algorithm to use, which can be SHA-1, SHA-224, SHA-256, SHA-384, SHA-512, or MD5.|

**Return value**

| Type| Description                                 |
| ---- | ------------------------------------- |
| Md   | [Md](#md) instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var md;
try {
    md = cryptoFramework.createMd("SHA256");
} catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
}
```

## Md

Provides APIs for message digest operations. Before using any API of the **Md** class, you must create an **Md** instance by using [createMd](#cryptoframeworkcreatemd).

### **Attributes**

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                |
| ------- | ------ | ---- | ---- | -------------------- |
| algName | string | Yes  | No  | Digest algorithm to use.|

### update

update(input : DataBlob, callback : AsyncCallback\<void>) : void;

Updates the message digest data with the message passed in. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name  | Type                 | Mandatory| Description        |
| -------- | --------------------- | ---- | ------------ |
| input    | DataBlob              | Yes  | Message to pass in.  |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|


**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var md;
try {
    md = cryptoFramework.createMd("SHA256");
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
}
console.error("Md algName is: " + md.algName);

let blob;
md.update(blob, (err,) => {
    if (err) {
        console.error("[Callback] err: " + err.code);
    }
});
```

### update

update(input : DataBlob) : Promise\<void>;

Updates the message digest data with the message passed in. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| input  | DataBlob | Yes  | Message to pass in.|

**Return value**

| Type           | Description        |
| --------------- | ------------ |
| Promise\<void> | Promise used to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var md;
try {
    md = cryptoFramework.createMd("SHA256");
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
}
console.error("Md algName is: " + md.algName);

let blob;
var promiseMdUpdate = md.update(blob);
promiseMdUpdate.then(() => {
    // do something
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});
```

### digest

digest(callback : AsyncCallback\<DataBlob>) : void

Generates a message digest. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<DataBlob> | Yes  | Callback invoked to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var md;
try {
    md = cryptoFramework.createMd("SHA256");
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
}
console.error("Md algName is: " + md.algName);

let blob;
md.update(blob, (err,) => {
    if (err) {
        console.error("[Callback] err: " + err.code);
    }
    md.digest((err1, mdOutput) => {
		if (err1) {
            console.error("[Callback] err: " + err1.code);
        } else {
            console.error("[Callback]: MD result: " + mdOutput);
        }
    });
});
```

### digest

digest() : Promise\<DataBlob>

Generates a message digest. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type             | Description       |
| ------------------- | ----------- |
| Promise\<DataBlob> | Promise used to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var md;
try {
    md = cryptoFramework.createMd("SHA256");
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
}
console.error("Md algName is: " + md.algName);

let blob;
var promiseMdUpdate = md.update(blob);
promiseMdUpdate.then(() => {
    var PromiseMdDigest = md.digest();
    return PromiseMdDigest;
}).then(mdOutput => {
    console.error("[Promise]: MD result: " + mdOutput.data);
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});
```

### getMdLength

getMdLength() : number

Obtains the message digest length, in bytes.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| number | Message digest length obtained. |

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var md;
try {
    md = cryptoFramework.createMd("SHA256");
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
}
console.error("Md algName is: " + md.algName);

let blob;
var promiseMdUpdate = md.update(blob);
promiseMdUpdate.then(() => {
    var PromiseMdDigest = md.digest();
    return PromiseMdDigest;
}).then(mdOutput => {
    console.error("[Promise]: MD result: " + mdOutput.data);
    let mdLen = md.getMdLength();
	AlertDialog.show({message: "MD len: " + mdLen});
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});
```

## cryptoFramework.createRandom

createRandom() : Random

Creates a **Random** instance for generating random numbers and setting seeds.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type  | Description                                         |
| ------ | --------------------------------------------- |
| Random | [Random](#random) instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

try {
    var rand = cryptoFramework.createRandom();
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message); 
}
```

## Random

Provides APIs for computing random numbers. Before using any API of the **Random** class, you must create a **Random** instance by using [createRandom](#cryptoframeworkcreaterandom).

### generateRandom

generateRandom(len : number, callback: AsyncCallback\<DataBlob>) : void;

Generates a random number of the given length. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name  | Type                     | Mandatory| Description                |
| -------- | ------------------------- | ---- | -------------------- |
| len      | number                    | Yes  | Length of the random number to generate.|
| callback | AsyncCallback\<DataBlob> | Yes  | Callback invoked to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var rand;
try {
    rand = cryptoFramework.createRandom();
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);    
}
rand.generateRandom(12, (err, randData) => {
    if (err) {
        console.error("[Callback] err: " + err.code);
    } else {
        console.error("[Callback]: generate random result: " + randData.data);
    }
});
```

### generateRandom

generateRandom(len : number) : Promise\<DataBlob>;

Generates a random number of the given length. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| len    | number | Yes  | Length of the random number to generate.|

**Return value**

| Type             | Description       |
| ------------------- | ----------- |
| Promise\<DataBlob> | Promise used to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var rand;
try {
    rand = cryptoFramework.createRandom();
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
}

var promiseGenerateRand = rand.generateRandom(12);
promiseGenerateRand.then(randData => {
    console.error("[Promise]: rand result: " + randData.data);
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});
```

### setSeed

setSeed(seed : DataBlob, callback : AsyncCallback\<void>) : void;

Sets a seed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name  | Type                | Mandatory| Description        |
| -------- | -------------------- | ---- | ------------ |
| seed     | DataBlob             | Yes  | Seed to set.  |
| callback | AsyncCallback\<void\> | Yes  | Callback invoked to return the result.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var rand;
try {
    rand = cryptoFramework.createRandom();
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
}

rand.generateRandom(12, (err, randData) => {
    if (err) {
        console.error("[Callback] err: " + err.code);
    } else {
        console.error("[Callback]: generate random result: " + randData.data);
        rand.setSeed(randData, (err1, data) => {
            if (err1) {
                console.error("[Callback] err: " + err1.code);
            } else {
                console.error("[Callback]: setSeed success");
            }
        });
    }
});
```

### setSeed

setSeed(seed : DataBlob) : Promise\<void>;

Sets a seed. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| seed   | DataBlob | Yes  | Seed to set.|

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var rand;
try {
    rand = cryptoFramework.createRandom();
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message);
}

var promiseGenerateRand = rand.generateRandom(12);
promiseGenerateRand.then(randData => {
    console.error("[Promise]: rand result: " + randData.data);
    var promiseSetSeed = rand.setSeed(randData);
    return promiseSetSeed;
}).then(() => {
    console.error("[Promise]: setSeed success");
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});
```

## ParamsSpec

Defines the parameters for encryption and decryption. For the symmetric encryption and decryption modes that require parameters such as the initialization vector (IV), you need to construct a child class object and pass it to [init()](#init-2). You do not need to construct the child class object if the IV is not required.

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                  |
| ------- | ------ | ---- | ---- | ---------------------- |
| algoName | string | Yes  | Yes  | Symmetric encryption and decryption parameters. <br/>Options:<br>- **IvParamsSpec**: applicable to the CBC, CTR, OFB, and CFB modes.<br>- **GcmParamsSpec**: applicable to the GCM mode.<br>- **CcmParamsSpec**: applicable to the CCM mode. |

## IvParamsSpec

Defines the parameters for the CBC, CTR, OFB, and CFB modes, which require only an IV for each encryption operation. For the symmetric encryption and decryption that use the CBC, CTR, OFB, or CFB mode, you need to construct **IvParamsSpec** and pass it to [init()](#init-2).

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                  |
| ------- | ------ | ---- | ---- | ---------------------- |
| iv | [DataBlob](#datablob) | Yes  | Yes  | IV for encryption and decryption. <br/>Options:<br>- AES CBC, CTR, OFB, or CFB mode: 16-byte IV<br>- 3DES CBC, OFB or CFB mode: 8-byte IV |

## GcmParamsSpec

Defines the parameters for the GCM mode. For the symmetric encryption and decryption that use the GCM mode, you need to construct **GcmParamsSpec** and pass it to [init()](#init-2).

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                  |
| ------- | ------ | ---- | ---- | ---------------------- |
| iv | [DataBlob](#datablob) | Yes  | Yes  | IV, which is of 12 bytes.|
| aad | [DataBlob](#datablob) | Yes  | Yes  | Additional authenticated data (AAD), which is of 8 bytes.|
| authTag | [DataBlob](#datablob) | Yes  | Yes  | AuthTag, which is of 16 bytes.<br>When the GCM mode is used for encryption, the last 16 bytes of the [DataBlob](#datablob) returned by [doFinal()](#dofinal-2) are used as the **authTag** in [GcmParamsSpec](#gcmparamsspec) for decryption.|

## CcmParamsSpec

Defines the parameters for the CCM mode. For the symmetric encryption and decryption that use the CCM mode, you need to construct **CcmParamsSpec** and pass it to [init()](#init-2).

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type    | Readable| Writable| Description                                                        |
| ------- | -------- | ---- | ---- | -------------------------------|
| iv      | [DataBlob](#datablob) | Yes  | Yes  | IV, which is of 7 bytes.                               |
| aad     | [DataBlob](#datablob) | Yes  | Yes  | AAD, which is of 8 bytes.                              |
| authTag | [DataBlob](#datablob) | Yes  | Yes  | AuthTag, which is of 12 bytes.<br>When the CCM mode is used for encryption, the last 12 bytes of the [DataBlob](#datablob) returned by [doFinal()](#dofinal-2) are used as the **authTag** in [CcmParamsSpec](#ccmparamsspec) for decryption.|

## CryptoMode

Enumerates the cryptographic operations.

**System capability**: SystemCapability.Security.CryptoFramework

| Name        | Value       | Description                            |
| ------------ | -------- | -------------------------------- |
| ENCRYPT_MODE | 0        | Encryption.                   |
| DECRYPT_MODE | 1        | Decryption.                   |

## Key

Provides APIs for key operations. Before performing cryptographic operations (such as encryption and decryption), you need to construct a child class object of **Key** and pass it to [init()](#init-2) of the [Cipher](#cipher) instance. Keys can be generated by a key generator.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                  |
| ------- | ------ | ---- | ---- | ---------------------- |
| format | string | Yes  | No  | Format of the key.|
| algName | string | Yes  | No  | Algorithm name (including the key length).|

### getEncoded

getEncoded() : DataBlob

Obtains the key in hexadecimal format. This API returns the result synchronously.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type  |Description                  |
| ------- | ----------- |
| [DataBlob](#datablob) | Key obtained.|

**Example**

```js
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

let key; // The key is generated by a symKeyGenerator. The generation process is omitted here.
let encodedKey = key.getEncoded();
console.info("key hex:" + uint8ArrayToShowStr(encodedKey.data));
```

## SymKey

Provides APIs for symmetric key operations. It is a child class of [Key](#key). Its objects need to be passed to [init()](#init-2) of the [Cipher](#cipher) instance in symmetric encryption and decryption. Symmetric keys can be generated by a [SymKeyGenerator](#symkeygenerator).

### clearMem

clearMem() : void

Clears the keys from the memory. This API returns the result synchronously.

**System capability**: SystemCapability.Security.CryptoFramework

**Example**

```js
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

let key; // The key is generated by a symKeyGenerator. The generation process is omitted here.
let encodedKey = key.getEncoded();
console.info("key hex: "+ uint8ArrayToShowStr(encodedKey.data)); // Display key content.
key.clearMem();
encodedKey = key.getEncoded();
console.info("key hex:" + uint8ArrayToShowStr(encodedKey.data));    // Display all 0s.
```

## PubKey

Provides APIs for public key operations. It is a child class of [Key](#key). Its objects need to be passed in during asymmetric encryption and decryption, signature verification, and key agreement. Public keys can be generated by an **AsyKeyGenerator**.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                  |
| ------- | ------ | ---- | ---- | ---------------------- |
| format | string | Yes  | No  | Format of the key.|
| algName | string | Yes  | No  | Algorithm name (including the key length).|


### getEncoded

getEncoded() : DataBlob

Obtains the key in binary format. This API returns the result synchronously. The public key format must comply with the ASN.1 syntax, X.509 specifications, and DER encoding format.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type  |Description                  |
| ------- | ----------- |
| [DataBlob](#datablob) | Key obtained.|

**Example**

```js
console.info("key format:" + key.format);
console.info("key algName:" + key.algName);
var encodedKey = key.getEncoded();
console.info("key encoded:" + Uint8ArrayToShowStr(encodedKey.data));
```

## PriKey

Provides APIs for private key operations. It is a child class of [Key](#key). Its objects need to be passed in during asymmetric encryption and decryption, signature verification, and key agreement. Private keys can be generated by an **AsyKeyGenerator**.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                  |
| ------- | ------ | ---- | ---- | ---------------------- |
| format | string | Yes  | No  | Format of the key.|
| algName | string | Yes  | No  | Algorithm name (including the key length).|

### getEncoded

getEncoded() : DataBlob

Obtains the key in binary format. This API returns the result synchronously. The private key format must comply with the ASN.1 syntax, PKCS #8 specifications, and DER encoding mode.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type  |Description                  |
| ------- | ----------- |
| [DataBlob](#datablob) | Key obtained.|

**Example**

```js
console.info("key format:" + key.format);
console.info("key algName:" + key.algName);
var encodedKey = key.getEncoded();
console.info("key encoded:" + Uint8ArrayToShowStr(encodedKey.data));
```

### clearMem

clearMem() : void

Clears the keys from the memory. This API returns the result synchronously.

**System capability**: SystemCapability.Security.CryptoFramework

**Example**

```js
key.clearMem();
```

## cryptoFramework.createSymKeyGenerator

createSymKeyGenerator(algName : string) : SymKeyGenerator

Creates a **SymKeyGenerator** instance based on the specified algorithm. For details about the supported symmetric key parameters, see "String for Generating a Key" in [Key Generation Specifications](../../security/cryptoFramework-overview.md#key-generation-specifications).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                            |
| ------- | ------ | ---- | ----------------------------- |
| algName | string | Yes  | Algorithm used by the **symkeyGenerator**.|

**Return value**

| Type           | Description                      |
| ----------------------------------- | -------------------------- |
| [SymKeyGenerator](#symkeygenerator) | **SymKeyGenerator** instance created.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
```

## SymKeyGenerator

Provides APIs for using the **symKeyGenerator**. Before using any API of the **SymKeyGenerator** class, you must create a **symKeyGenerator** instance by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm used by the **symKeyGenerator**.|

### generateSymKey

generateSymKey(callback : AsyncCallback\<SymKey>) : void

Generates a key randomly. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type              | Mandatory| Description                |
| -------- | ----------------- | ---- | ------------------- |
| callback | AsyncCallback\<[SymKey](#symkey)> | Yes | Callback invoked to return the symmetric key generated.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symAlgoName = '3DES192';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgoName);
symKeyGenerator.generateSymKey((err, symKey) => {
    if (err) {
        console.error('Failed to generate symKey');
        return;
    }
    console.log('Generate symKey success, algName: ' + symKey.algName);
})
```

### generateSymKey

generateSymKey() : Promise\<SymKey>

Generates a key randomly. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise used to return the symmetric key generated.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symAlgoName = 'AES128';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgoName);
symKeyGenerator.generateSymKey().then((symKey) => {
    console.log('Generate symKey success, algName:' + symKey.algName);
})
```

### convertKey

convertKey(key : DataBlob, callback : AsyncCallback\<SymKey>) : void

Converts a key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type               | Mandatory| Description                 |
| -------- | ----------------- | ---- | ---------------------- |
| key      | [DataBlob](#datablob)  | Yes  | Key to convert.        |
| callback | AsyncCallback\<[SymKey](#symkey)> | Yes  | Callback invoked to return the symmetric key generated.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function genKeyMaterialBlob() {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72];    // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return {data : keyMaterial};
}

let symAlgoName = '3DES192';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgoName);
let keyMaterialBlob = genKeyMaterialBlob();
symKeyGenerator.convertKey(keyMaterial, (err,  symKey) => {
    if (err) {
        console.error('Failed to convert symKey');
        return;
    }
    console.log('Convert symKey success, algName:' + symKey.algName);
})
```

### convertKey

convertKey(key : DataBlob) : Promise\<SymKey>

Converts a key. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description                |
| ---- | -------- | ---- | -------------------- |
| key  | [DataBlob](#datablob) | Yes  | Key to convert.|

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise used to return the symmetric key generated.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function genKeyMaterialBlob() {
  let arr = [
    0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
    0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
    0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72];    // keyLen = 192 (24 bytes)
  let keyMaterial = new Uint8Array(arr);
  return {data : keyMaterial};
}

let symAlgoName = '3DES192';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgoName);
let keyMaterialBlob = genKeyMaterialBlob();
symKeyGenerator.convertKey(keyMaterial).then((symKey) => {
    console.log('Convert symKey success, algName:' + symKey.algName);
})
```

## cryptoFramework.createAsyKeyGenerator

createAsyKeyGenerator(algName : string) : AsyKeyGenerator
Creates an **AsyKeyGenerator** instance based on the specified algorithm.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                            |
| ------- | ------ | ---- | -------------------------------- |
| algName | string | Yes  | Algorithm used by the **symkeyGenerator**.|

**Return value**

| Type           | Description                      |
| --------------- | -------------------------- |
| asyKeyGenerator | **AsyKeyGenerator** instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
```

## AsyKeyGenerator

Provides APIs for using the **AsKeyGenerator**. Before using any API of the **AsKeyGenerator** class, you must create an **AsyKeyGenerator** instance by using **createAsyKeyGenerator()**.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name          | Type          | Readable| Writable| Description                             |
| -------------- | -------------- | ---- | ---- | ----------------------------------|
| algName        | string         | Yes  | No  | Algorithm used by the **AsKeyGenerator**. |



### generateKeyPair

generateKeyPair(callback : AsyncCallback\<KeyPair>) : void;
Generates a key pair randomly. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                      | Mandatory| Description                        |
| -------- | -------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<KeyPair> | Yes  | Callback invoked to return the key pair obtained.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
asyKeyGenerator.generateKeyPair((err, keyPair) => {
  if (err) {
    console.error("generateKeyPair: error.");
    return;
  }
  console.info("generateKeyPair: success.");
})
```


### generateKeyPair

generateKeyPair() : Promise\<KeyPair>
Generates a key pair randomly. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise\<KeyPair> | Promise used to return the key pair generated.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
let keyGenPromise = asyKeyGenerator.generateKeyPair();
keyGenPromise.then( keyPair => {
  console.info("generateKeyPair success.");
}).catch(error => {
  console.error("generateKeyPair error.");
});
```

### convertKey

convertKey(pubKey : DataBlob, priKey : DataBlob, callback : AsyncCallback\<KeyPair\>) : void
Converts an asymmetric key. This API uses an asynchronous callback to return the result. For details, see **Key Conversion**.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                      | Mandatory| Description                        |
| -------- | -------------------------- | ---- | ---------------------------- |
| pubKey      | DataBlob                   | No  | Public key material to convert. |
| priKey      | DataBlob                   | No  | Private key material to convert. |
| callback | AsyncCallback\<KeyPair> | Yes  | Callback invoked to return the key pair obtained.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
asyKeyGenerator.convertKey(pubKey, priKey, (err, keyPair) => {
  if (err) {
    console.error("convertKey: error.");
    return;
  }
  console.info("convertKey: success.");
})
```

### convertKey

convertKey(pubKey : DataBlob, priKey : DataBlob) : Promise\<KeyPair>
Converts an asymmetric key. This API uses a promise to return the result. For details, see **Key Conversion**.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description                |
| ---- | -------- | ---- | -------------------- |
| pubKey      | DataBlob                   | No  | Public key material to convert. |
| priKey      | DataBlob                   | No  | Private key material to convert. |

**Return value**

| Type                 | Description                           |
| --------------------- | ------------------------------- |
| Promise\<KeyPair> | Promise used to return the key pair generated.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
let keyGenPromise = asyKeyGenerator.convertKey(pubKey, priKey);
keyGenPromise.then( keyPair => {
  console.info("convertKey success.");
}).catch(error => {
  console.error("convertKey error.");
});
```

**Key Conversion**

- After **getEncoded()** is called for the asymmetric public and private keys (RSA and ECC), binary data in X.509 and PKCS #8 formats is returned, respectively. The data can be used for cross-application transfer or persistent storage.
- The public key returned by **convertKey()** must comply with the ASN.1 syntax, X.509 specifications, and DER encoding format, and the private key must comply with the ASN.1 syntax, PKCS #8 specifications, and DER encoding format.
- In **convertKey()**, **pubKey** and **priKey** are optional. Either **pubKey** or **priKey** can be passed in. As a result, the returned **KeyPair** instance contains only the key converted from the data you passed in.

## cryptoFramework.createCipher

createCipher(transformation : string) : Cipher
Creates a [Cipher](#cipher) instance based on the specified algorithm. 
For details about the supported algorithms, see "Algorithm String" in [Encryption and Decryption Specifications](../../security/cryptoFramework-overview.md#encryption-and-decryption-specifications).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name        | Type  |  Mandatory |  Description                                                        |
| -------------- | ------ | -------- | ------------------------------------------------------------ |
| transformation | string | Yes  | Combination of the algorithm name, encryption mode, and padding algorithm of the **Cipher** instance to create. For example, **RSA1024\|PKCS1** or **RSA1024\|PKCS1_OAEP\|SHA256\|SHA256**.|

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| [Cipher](#cipher) | [Cipher](#cipher) instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let cipherAlgoName = '3DES192|ECB|PKCS7';
var cipher;
try {
  cipher = cryptoFramework.createCipher(cipherAlgoName);
  console.info(`cipher algName: ${cipher.algName}`);
} catch (error) {
  console.error(`createCipher failed, ${error.code}, ${error.message}`);
  return;
}
```

## Cipher

Provides APIs for cipher operations. The [init()](#init-2), [update()](#update-4), and [doFinal()](#dofinal-2) APIs in this class are called in sequence to implement symmetric encryption or decryption and asymmetric encryption or decryption. For details about the complete encryption and decryption process, see [Encryption and Decryption Operations](../../security/cryptoFramework-guidelines.md#encryption-and-decryption-operations).

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework


| Name   | Type  | Readable | Writable | Description                        |
| ------- | ------ | -------- | ----------- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm to use.|

### init

init(opMode : CryptoMode, key : Key, params : ParamsSpec, callback : AsyncCallback\<void>) : void

Initializes a [cipher](#cipher) instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                    | Mandatory   | Description                    |
| -------- | ------------------------ | ------- | ------------------------ |
| opMode   | [CryptoMode](#cryptomode)      | Yes  | Operation (encryption or decryption) to perform.      |
| key      | [Key](#key)           | Yes  | Key for encryption or decryption.  |
| params   | [ParamsSpec](#paramsspec)               | Yes  | Parameters for encryption or decryption.  |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKey;     // The process of generating the symmetric key is omitted here.
let cipher;        // The process of creating a Cipher instance is omitted here.
cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null, (err, ) => {
  if (err) {
    console.error('Failed to init cipher');
    return;
  }
  console.log('Init cipher success');
  // Perform subsequent operations such as update.
})
```

### init

init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>

Initializes a [cipher](#cipher) instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type      | Mandatory| Description                  |
| ------ | ---------- | ---- | ---------------------- |
| opMode |  [CryptoMode](#cryptomode)  | Yes  | Operation (encryption or decryption) to perform.    |
| key    |  [Key](#key)       | Yes  | Key for encryption or decryption.|
| params | [ParamsSpec](#paramsspec) | Yes  | Parameters for encryption or decryption. For algorithm modes without parameters (such as ECB), **null** can be passed in. |

**Return value**

| Type               | Description                       |
| ------------------- | --------------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKey;     // The process of generating the symmetric key is omitted here.
let cipher;        // The process of creating a Cipher instance is omitted here.
cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null).then(() => {
  console.log('Init cipher success');
  // Perform subsequent operations such as update.
})
```

### update

update(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

Updates the data to encrypt or decrypt by segment. This API uses an asynchronous callback to return the encrypted or decrypted data. The number of times that **update()** is called varies depending on the data volume.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                        | Mandatory| Description                                      |
| -------- | ---------------------------- | ---- | ------------------------------------------ |
| data     | [DataBlob](#datablob)                  | Yes  | Data to encrypt or decrypt.                      |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return the encrypted or decrypted data.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let cipher;        // The process of creating a Cipher instance is omitted here.
// The init() process is omitted here.
let plainText = {data : stringToUint8Array('this is test!')};
cipher.update(plainText, (err, output) => {       // Example of the encryption process.
  if (err) {
    console.error('Failed to update cipher');
    return;
  }
  console.log('Update cipher success');
  // Perform subsequent operations such as doFinal.
})
```

### update

update(data : DataBlob) : Promise\<DataBlob>

Updates the data to encrypt or decrypt by segment. This API uses a promise to return the result. The number of times that **update()** is called varies depending on the data volume.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description                |
| ---- | -------- | ---- | -------------------- |
| data |  [DataBlob](#datablob) | Yes  | Data to encrypt or decrypt.|

**Return value**

| Type                   | Description                       |
| ----------------------- | --------------------------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the result.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let cipher;        // The process of creating a Cipher instance is omitted here.
// The init() process is omitted here.
let plainText = {data : stringToUint8Array('this is test!')};
cipher.update(data).then((output) => {
  console.log('Update cipher success');
  // Perform subsequent operations such as doFinal.
})
```

### doFinal

doFinal(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

Finalizes the data encryption or decryption operation. This API uses an asynchronous callback to return the result.

The output of **doFinal** varies depending on the symmetric encryption and decryption mode. 

- For symmetric encryption in GCM or CCM mode, **doFinal** returns the combination of the remaining ciphertext and **authTag**. **authTag** is the last 16 bytes for the GCM mode or the last 12 bytes for the CCM mode. If **data** of **doFinal** is **null**, **doFinal** returns **authTag**. After **doFinal** is complete, **authTag** needs to be temporarily stored and filled in [**GcmParamsSpec**](#gcmparamsspec) or [**CcmParamsSpec**](#ccmparamsspec) during decryption.
- For symmetric encryption and decryption in other modes, the output can be either of the following: 
  (1) **Update()** returns part of the encryption and decryption result, and **doFinal()** returns the remaining encryption and decryption result. 
  (2) **Update()** returns all the encryption and decryption result, and **doFinal()** returns no value.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                        | Mandatory| Description                                      |
| -------- | ---------------------------- | ---- | ------------------------------------------ |
| data     |  [DataBlob](#datablob)                     | Yes  | Data to encrypt or decrypt.<br/>If data is already passed in by [update()](#update-4), **data** can be **null**. |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return the encrypted or decrypted data.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let cipher;        // The process of creating a Cipher instance is omitted here.
let data;           // The process of preparing the data to encrypt or decrypt is omitted here.
// The init() and update() processes are omitted here.
cipher.doFinal(data, (err, output) => {
  if (err) {
    console.error('Failed to final cipher');
    return;
  }
  console.log('Final cipher success');
})
```

### doFinal

doFinal(data : DataBlob) : Promise\<DataBlob>

Finalizes the data encryption or decryption operation. This API uses a promise to return the result. 

The output of **doFinal** varies depending on the symmetric encryption and decryption mode.

- For symmetric encryption in GCM or CCM mode, **doFinal** returns the combination of the remaining ciphertext and **authTag**. **authTag** is the last 16 bytes for the GCM mode or the last 12 bytes for the CCM mode. If **data** of **doFinal** is **null**, **doFinal** returns **authTag**. After **doFinal** is complete, **authTag** needs to be temporarily stored and filled in [**GcmParamsSpec**](#gcmparamsspec) or [**CcmParamsSpec**](#ccmparamsspec) during decryption. 

- For symmetric encryption and decryption in other modes, the output includes the following: 

  (1) **Update()** returns part of the encryption and decryption results, and **doFinal()** returns the remaining encryption and decryption results. 

  (2) **Update()** returns all the encryption and decryption result, and **doFinal()** returns no value.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description                |
| ---- | -------- | ---- | -------------------- |
| data | [DataBlob](#datablob) | Yes  | Data to encrypt or decrypt. If data is already passed in by [update()](#update-4), **data** can be **null**. |

**Return value**

| Type                   | Description                       |
| ----------------------- | --------------------------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the result.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let cipher;        // The process of creating a Cipher instance is omitted here.
let data;           // The process of preparing the data to encrypt or decrypt is omitted here.
// The init() and update() processes are omitted here.
cipher.doFinal(data).then((output) => {
    console.log('Final cipher success');
})
```

**Callback example**:

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
rsaGenerator.generateKeyPair(function (err, keyPair) {
  let pubKey = keyPair.pubKey;
  cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null, function (err, data) {
    let input = {data : stringToUint8Array(plan) };
    cipher.doFinal(input, function (err, data) {
      AlertDialog.show({ message : "EncryptOutPut is " + data.data} );
    });
  });
});
```

**Promise example**:

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
let keyGenPromise = rsaGenerator.generateKeyPair();
keyGenPromise.then(rsaKeyPair => {
  let pubKey = rsaKeyPair.pubKey;
  return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null); // Pass in the private key and DECRYPT_MODE to initialize the decryption mode.
}).then(() => {
  let input = { data : stringToUint8Array(plan) };
  return cipher.doFinal(input);
}).then(dataBlob => {
  console.info("EncryptOutPut is " + dataBlob.data);
});
```


## cryptoFramework.createSign

createSign(algName : string) : Sign

Creates a **Sign** instance.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Signing algorithm to use, which can be RSA or ECC. If RSA PKCS #1 is used, the digest must be set. If RSA PSS is used, the digest and mask digest must be set.|

**Return value**

| Type| Description                          |
| ---- | ------------------------------ |
| Sign   | **Sign** instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let signer1 = cryptoFramework.createSign("RSA1024|PKCS1|SHA256");

let singer2 = cryptoFramework.createSign("RSA1024|PKCS1_OAEP|SHA256|MGF1_SHA256")
```

## Sign

Provides APIs for signing. Before using any API of the **Sign** class, you must create a **Sign** instance by using **createSign()**.

### init

init(priKey : PriKey, callback : AsyncCallback\<void>) : void

Initializes a **Sign** instance using a private key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| priKey   | Key |Yes| Private key used for the initialization.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

### init

init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>

Initializes a **Sign** instance using a private key. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| priKey   | Key |Yes| Private key used for the initialization.|

**Return value**

| Type         | Description       |
| ------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

### update

update(data : DataBlob, callback : AsyncCallback\<void>) : void

Updates the data to be signed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| data    | DataBlob              | Yes  | Message to pass in.    |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

### update

update(data : DataBlob) : Promise\<void>;

Updates the data to be signed. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data  | DataBlob | Yes  | Message to pass in. |

**Return value**

| Type         | Description       |
| ------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

### sign

sign(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

Signs the data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| data    | DataBlob              | Yes  | Message to pass in.     |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

### sign

sign(data : DataBlob) : Promise\<DataBlob>

Signs the data. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data  | DataBlob | Yes  | Message to pass in. |

**Return value**

| Type         | Description       |
| ------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Callback example**:
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

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
```

**Promise example**:
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

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
```

## cryptoFramework.createVerify

createVerify(algName : string) : Verify

Creates a **Verify** instance.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Signing algorithm to use, which can be RSA or ECC. If RSA PKCS #1 is used, the digest must be set. If RSA PSS is used, the digest and mask digest must be set.|

**Return value**

| Type| Description                          |
| ---- | ------------------------------ |
| Verify   | **Verify** instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let verifyer1 = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");

let verifyer2 = cryptoFramework.createVerify("RSA1024|PKCS1_OAEP|SHA256|MGF1_SHA256")
```
## Verify

Provides APIs for signature verification. Before using any API of the **Verify** class, you must create a **Verify** instance by using **createVerify()**.

### init

init(pubKey : PubKey, callback : AsyncCallback\<void>) : void

Initializes the **Verify** instance using a public key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| pubKey   | Key |Yes| Public key used for the initialization.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

### init
init(pubKey : PubKey) : Promise\<void>

Initializes the **Verify** instance using a public key. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| pubKey   | Key |Yes|Public key used for the initialization.|

**Return value**

| Type           | Description        |
| --------------- | ------------ |
| Promise\<void> | Promise used to return the result.|

### update

update(data : DataBlob, callback : AsyncCallback\<void>) : void

Updates the data for signature verification. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| data    | DataBlob              | Yes  | Message to pass in.        |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

### update

update(data : DataBlob) : Promise\<void>;

Updates the data for signature verification. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data  | DataBlob | Yes  | Message to pass in. |

**Return value**

| Type         | Description       |
| ------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

### verify

verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback\<boolean>) : void

Verifies the signature. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| data    | DataBlob              | Yes  | Message to pass in.        |
| signatureData    | DataBlob              | Yes  | Signature data.       |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

### verify

verify(data : DataBlob, signatureData : DataBlob) : Promise\<boolean>

Verifies the signature. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data  | DataBlob | Yes  | Message to pass in.|
| signatureData    | DataBlob| Yes| Signature data.|

**Return value**

| Type           | Description        |
| --------------- | ------------ |
| Promise\<boolean> | Promise used to return the result.|

**Callback example**:
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA25");
verifyer.init(globalKeyPair.pubKey, function (err, data) {
  verifyer.update(input1, function(err, data) {
    verifyer.verify(input2, SignMessageBlob, function(err, data) {
      console.info("verify result is " + data);
    })
  });
})
```

**Promise example**:
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
let verifyInitPromise = verifyer.init(globalKeyPair.pubKey);
verifyInitPromise.then(() => {
  return verifyer.update(input1);
}).then(() => {
  return verifyer.verify(input2, SignMessageBlob);
}).then(res => {
  console.log("Verify result is " + res);
});
```
## cryptoFramework.createKeyAgreement

createKeyAgreement(algName : string) : KeyAgreement

Creates a **KeyAgreement** instance.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Key agreement algorithm to use. Only ECC is supported. |

**Return value**

| Type| Description                          |
| ---- | ------------------------------ |
| KeyAgreement   | **KeyAgreement** instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let keyAgreement = cryptoFramework.createKeyAgreement("ECC256");

```

## KeyAgreement

Provides APIs for key agreement operations. Before using any API of the **keyAgreement** class, you must create a **KeyAgreement** instance by using **createKeyAgreement()**.

### generateSecret

generateSecret(priKey : PriKey, pubKey : PubKey, callback : AsyncCallback\<DataBlob>) : void

Generates a shared secret. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| priKey   | PriKey |Yes| Private key used for key agreement.|
| pubKey   | PubKey |Yes| Public key used for key agreement.|
| callback | AsyncCallback\<DataBlob> | Yes  | Callback invoked to return the shared secret generated. |

### generateSecret
generateSecret(priKey : PriKey, pubKey : PubKey) : Promise\<DataBlob>

Generates a shared secret. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                 | Mandatory| Description              |
| -------- | --------------------- | ---- | ------------------ |
| priKey   | PriKey |Yes| Private key used for key agreement.|
| pubKey   | PubKey |Yes| Public key used for key agreement.|

**Return value**

| Type           | Description        |
| --------------- | ------------ |
| Promise\<DataBlob> | Promise used to return the shared secret generated. |

**Callback example**:
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let keyAgreement = cryptoFramework.createKeyAgreement("ECC256");
keyAgreement.generateSecret(globalKeyPair.priKey, globalKeyPair.pubKey, function (err, secret) {
  if (err) {
    console.error("keyAgreement error.");
    return;
  }
  console.info("keyAgreement output is " + secret.data);
});
```

**Promise example**:
```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let keyAgreement = cryptoFramework.createKeyAgreement("ECC256");
let keyAgreementPromise = keyAgreement.generateSecret(globalKeyPair.priKey, globalKeyPair.pubKey);
keyAgreementPromise.then((secret) => {
  console.info("keyAgreement output is " + secret.data);
}).catch((error) => {
  console.error("keyAgreement error.");
});
```
