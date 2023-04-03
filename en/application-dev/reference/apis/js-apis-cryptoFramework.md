# @ohos.security.cryptoFramework (Crypto Framework)

The **cryptoFramework** module shields underlying hardware and algorithm libraries and provides unified APIs for cryptographic operations.

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

| Name                                 |    Value  |   Description                        |
| ------------------------------------- | -------- | ---------------------------- |
| INVALID_PARAMS                        | 401      | Invalid parameters.                  |
| NOT_SUPPORT                           | 801      | Unsupported operation.                |
| ERR_OUT_OF_MEMORY                     | 17620001 | Memory error.                  |
| ERR_RUNTIME_ERROR                     | 17620002 | Runtime error.            |
| ERR_CRYPTO_OPERATION                  | 17630001 | Cryptographic operation error.     |

## DataBlob

Defines a binary data array.

**System capability**: SystemCapability.Security.CryptoFramework

| Name| Type      | Readable| Writable| Description  |
| ---- | ---------- | ---- | ---- | ------ |
| data | Uint8Array | Yes  | Yes  | Binary data array. |


## cryptoFramework.createMac

createMac(algName : string) : Mac

Creates a **Mac** instance for message authentication code (MAC) operations.

For details about the supported specifications, see [HMAC Algorithm Specifications](../../security/cryptoFramework-overview.md#hmac-algorithm-specifications).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Digest algorithm. For details about the supported algorithms, see [HMAC Algorithm Specifications](../../security/cryptoFramework-overview.md#hmac-algorithm-specifications).|

**Return value**

| Type| Description                                   |
| ---- | --------------------------------------- |
| Mac  | [Mac](#mac) instance created.|

**Error codes**

| ID| Error Message          |
| -------- | ------------------ |
| 17620001 | memory error.       |

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var mac;
try {
    // Set algName based on the algorithm supported.
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
}
```

## Mac

Provides APIs for MAC operations. Before using any API of the **Mac** class, you must create a **Mac** instance by using [createMac](#cryptoframeworkcreatemac).

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                |
| ------- | ------ | ---- | ---- | -------------------- |
| algName | string | Yes  | No  | Digest algorithm to use.|

### init

init(key : SymKey, callback : AsyncCallback\<void>) : void;	

Initializes the MAC computation using a symmetric key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description        |
| -------- | -------------------- | ---- | ------------ |
| key      | [SymKey](#symkey)    | Yes  | Shared symmetric key.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.    |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

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
| key    | [SymKey](#symkey) | Yes  | Shared symmetric key.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

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

> **NOTE**<br>
> For details about the sample code for calling **update()** multiple times, see [Generating a MAC](../../security/cryptoFramework-guidelines.md#generating-a-mac).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| input    | [DataBlob](#datablob)| Yes  | Data to pass in.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.  |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var KeyBlob;
var mac;
try {
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
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

> **NOTE**<br>
> For details about the sample code for calling **update()** multiple times, see [Generating a MAC](../../security/cryptoFramework-guidelines.md#generating-a-mac).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| input  | [DataBlob](#datablob) | Yes  | Data to pass in.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

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

**Parameters**

| Name  | Type                    | Mandatory| Description    |
| -------- | ------------------------ | ---- | -------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var KeyBlob;
var mac;
try {
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
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

| Type              | Description       |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

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

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

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
	console.error("MAC len: " + macLen);
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});
```

## cryptoFramework.createMd

createMd(algName : string) : Md

Creates an **Md** instance for message digest operations. 

For details about the supported specifications, see [MD Algorithm Specifications](../../security/cryptoFramework-overview.md#md-algorithm-specifications).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Digest algorithm. For details about the supported algorithms, see [MD Algorithm Specifications](../../security/cryptoFramework-overview.md#md-algorithm-specifications).|

**Return value**

| Type| Description                                 |
| ---- | ------------------------------------- |
| Md   | [Md](#md) instance created.|

**Error codes**

| ID| Error Message          |
| -------- | ------------------ |
| 17620001 | memory error.       |

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var md;
try {
    // Set algName based on the algorithm supported.
    md = cryptoFramework.createMd("SHA256");
} catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
}
```

## Md

Provides APIs for message digest operations. Before using any API of the **Md** class, you must create an **Md** instance by using [createMd](#cryptoframeworkcreatemd).

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                |
| ------- | ------ | ---- | ---- | -------------------- |
| algName | string | Yes  | No  | Digest algorithm.|

### update

update(input : DataBlob, callback : AsyncCallback\<void>) : void;

Updates the message digest data. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> For details about the sample code for calling **update()** multiple times, see [Generating a Digest](../../security/cryptoFramework-guidelines.md#generating-a-digest).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| input    | [DataBlob](#datablob)| Yes  | Data to pass in.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.  |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

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

Updates the message digest data. This API uses a promise to return the result.

> **NOTE**<br>
> For details about the sample code for calling **update()** multiple times, see [Generating a Digest](../../security/cryptoFramework-guidelines.md#generating-a-digest).

**System capability**: SystemCapability.Security.CryptoFramework

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| input  | DataBlob | Yes  | Data to pass in.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

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

| Name  | Type                    | Mandatory| Description    |
| -------- | ------------------------ | ---- | -------- |
| callback | AsyncCallback\<DataBlob> | Yes  | Callback invoked to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

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

| Type              | Description       |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

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
| number | Message digest length obtained.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17630001 | crypto operation error. |

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
	console.error("MD len: " + mdLen);
}).catch(error => {
    console.error("[Promise]: error: " + error.message);
});
```

## cryptoFramework.createRandom

createRandom() : Random

Creates a **Random** instance for generating a random number and setting a seed.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type  | Description                                         |
| ------ | --------------------------------------------- |
| Random | [Random](#random) instance created.|

**Error codes**

| ID| Error Message    |
| -------- | ------------ |
| 17620001 | memory error. |

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

Provides APIs for computing random numbers and setting seeds. Before using any API of the **Random** class, you must create a **Random** instance by using [createRandom](#cryptoframeworkcreaterandom).

### generateRandom

generateRandom(len : number, callback: AsyncCallback\<DataBlob>) : void;

Generates a random number of the given length. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                    | Mandatory| Description                |
| -------- | ------------------------ | ---- | -------------------- |
| len      | number                   | Yes  | Length of the random number to generate.|
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return the result.            |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

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

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| len    | number | Yes  | Length of the random number to generate.|

**Return value**

| Type              | Description       |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

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

setSeed(seed : DataBlob) : void;

Sets a seed. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

| Name  | Type                 | Mandatory| Description      |
| -------- | --------------------- | ---- | ---------- |
| seed     | DataBlob              | Yes  | Seed to set.|

**Error codes**

| ID| Error Message          |
| -------- | ----------------- |
| 17620001 | memory error.      |

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
        try {
            rand.setSeed(randData);
        } catch (error) {
            console.log("setSeed failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
    }
});
```

## ParamsSpec

Defines the parameters used for encryption and decryption. 

For the symmetric encryption and decryption modes that require parameters such as the initialization vector (IV), you must construct a child class object and pass it to [init()](#init-2). If no IV is required (for example, the ECB mode is used), pass in **null** in [init()](#init-2).

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                                                        |
| ------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Yes  | Symmetric encryption and decryption parameters. Options:<br>- **IvParamsSpec**: applicable to the CBC, CTR, OFB, and CFB modes.<br>- **GcmParamsSpec**: applicable to the GCM mode.<br>- **CcmParamsSpec**: applicable to the CCM mode.|

> **NOTE**<br>
> The **params** parameter in [init()](#init-2) is of the **ParamsSpec** type (parent class), but a child class object (such as **IvParamsSpec**) needs to be passed in. When constructing the child class object, set **algName** in the parent class **ParamsSpec** to let the algorithm library know the type of child class object to pass in in **init()**.

## IvParamsSpec

Defines the child class of [ParamsSpec](#paramsspec). It is used as the parameters of [init()](#init-2) during symmetric encryption and decryption. 

**IvParamsSpec** applies to the encryption and decryption modes such as CBC, CTR, OFB, and CFB, which use only the IV.

**System capability**: SystemCapability.Security.CryptoFramework

| Name| Type                 | Readable| Writable| Description                                                        |
| ---- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv   | [DataBlob](#datablob) | Yes  | Yes  | IV for encryption and decryption. Options:<br>- AES CBC, CTR, OFB, or CFB mode: 16-byte IV<br>- 3DES CBC, OFB, or CFB mode: 8-byte IV|

> **NOTE**<br>
> Before passing **IvParamsSpec** to [init()](#init-2), specify **algName** in its parent class [ParamsSpec](#paramsspec).

## GcmParamsSpec

Defines the child class of [ParamsSpec](#paramsspec) for the GCM mode. It is used as the parameters of [init()](#init-2) during symmetric encryption and decryption. 

**GcmParamsSpec** applies to the GCM mode.

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type                 | Readable| Writable| Description                                                        |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | Yes  | Yes  | IV, which is of 12 bytes.                              |
| aad     | [DataBlob](#datablob) | Yes  | Yes  | Additional authenticated data (AAD), which is of 8 bytes.                              |
| authTag | [DataBlob](#datablob) | Yes  | Yes  | Authentication tag, which is of 16 bytes.<br>When the GCM mode is used for encryption, [DataBlob](#datablob) output by [doFinal()](#dofinal-2) is required. The last 16 bytes of [DataBlob](#datablob) are used as as **authTag** in [GcmParamsSpec](#gcmparamsspec) of [init()](#init-2). |

> **NOTE**
> Before passing **GcmParamsSpec** to [init()](#init-2), specify **algName** in its parent class [ParamsSpec](#paramsspec).

## CcmParamsSpec

Defines the child class of [ParamsSpec](#paramsspec) for the CCM mode. It is used as the parameters of [init()](#init-2) during symmetric encryption and decryption.

**CcmParamsSpec** applies to the CCM mode.

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type                 | Readable| Writable| Description                                                        |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | Yes  | Yes  | IV, which is of 7 bytes.                               |
| aad     | [DataBlob](#datablob) | Yes  | Yes  | AAD, which is of 8 bytes.                              |
| authTag | [DataBlob](#datablob) | Yes  | Yes  | Authentication tag, which is of 12 bytes.<br>When the CCM mode is used for encryption, [DataBlob](#datablob) output by [doFinal()](#dofinal-2) is required. The last 12 bytes of [DataBlob](#datablob) are used as as **authTag** in [CcmParamsSpec](#ccmparamsspec) of [init()](#init-2).|

> **NOTE**
> Before passing **CcmParamsSpec** to [init()](#init-2), specify **algName** in its parent class [ParamsSpec](#paramsspec).

## CryptoMode

Enumerates the cryptographic operations.

**System capability**: SystemCapability.Security.CryptoFramework

| Name        | Value  | Description            |
| ------------ | ---- | ---------------- |
| ENCRYPT_MODE | 0    | Encryption.|
| DECRYPT_MODE | 1    | Decryption.|

## Key

Provides APIs for key operations. Before performing cryptographic operations (such as encryption and decryption), you need to construct a child class object of **Key** and pass it to [init()](#init-2) of the [Cipher](#cipher) instance. <br>Keys can be generated by a key generator.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| format  | string | Yes  | No  | Format of the key.                |
| algName | string | Yes  | No  | Algorithm name (including the key length).|

### getEncoded

getEncoded() : DataBlob

Obtains a key in hexadecimal format. This API returns the result synchronously.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type                 | Description                    |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | Key obtained.|

**Example**

```js
import cryptoFramework from "@ohos.security.cryptoFramework"
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

let key;    // The key is generated by a symKeyGenerator. The generation process is omitted here.
let encodedKey = key.getEncoded();
console.info("key hex:" + uint8ArrayToShowStr(encodedKey.data));
```

## SymKey

Provides APIs for symmetric key operations. **SymKey** is a child class of [Key](#key), and its objects need to be passed to [init()](#init-2) of the [Cipher](#cipher) instance in symmetric encryption and decryption.

Symmetric keys can be generated by a [SymKeyGenerator](#symkeygenerator).

### clearMem

clearMem() : void

Clears the keys in the memory. This API returns the result synchronously. You are advised to use this API when symmetric key instances are no longer used.

**System capability**: SystemCapability.Security.CryptoFramework

**Example**

```js
import cryptoFramework from "@ohos.security.cryptoFramework"
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

let key;    // The key is generated by a symKeyGenerator. The generation process is omitted here.
let encodedKey = key.getEncoded();
console.info("key hex: "+ uint8ArrayToShowStr(encodedKey.data));    // Key content is displayed.
key.clearMem();
encodedKey = key.getEncoded();
console.info("key hex:" + uint8ArrayToShowStr(encodedKey.data));    // All 0s are displayed.
```

## PubKey

Provides APIs for public key operations. **PubKey** is a child class of [Key](#key), and its objects need to be passed in during asymmetric encryption and decryption, signature verification, and key agreement.

Public keys can be generated by an **AsyKeyGenerator**.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| format  | string | Yes  | No  | Format of the key.                |
| algName | string | Yes  | No  | Algorithm name (including the key length).|


### getEncoded

getEncoded() : DataBlob

Obtains a key in binary format. This API returns the result synchronously. The public key format must comply with the ASN.1 syntax, X.509 specifications, and DER encoding format.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type                 | Description                    |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | Key obtained.|

**Example**

```js
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

let key; // The key is a public key generated by the asymmetric key generator. The generation process is omitted here.
console.info("key format:" + key.format);
console.info("key algName:" + key.algName);
var encodedKey = key.getEncoded();
console.info("key encoded:" + uint8ArrayToShowStr(encodedKey.data));
```

## PriKey

Provides APIs for private key operations. **PriKey** is a child class of [Key](#key), and its objects need to be passed in during asymmetric encryption and decryption, signature verification, and key agreement.

Private keys can be generated by an **AsyKeyGenerator**.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| format  | string | Yes  | No  | Format of the key.                |
| algName | string | Yes  | No  | Algorithm name (including the key length).|

### getEncoded

getEncoded() : DataBlob

Obtains a key in binary format. This API returns the result synchronously. The private key format must comply with the ASN.1 syntax, PKCS #8 specifications, and DER encoding mode.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type                 | Description                    |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | Key obtained.|

**Example**

```js
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

let key; // The key is a private key generated by the asymmetric key generator. The generation process is omitted here.
console.info("key format:" + key.format);
console.info("key algName:" + key.algName);
var encodedKey = key.getEncoded();
console.info("key encoded:" + uint8ArrayToShowStr(encodedKey.data));
```

### clearMem

clearMem() : void

Clears the keys in the memory. This API returns the result synchronously.

**System capability**: SystemCapability.Security.CryptoFramework

**Example**

```js
let key; // The key is a private key generated by the asymmetric key generator. The generation process is omitted here.
key.clearMem();
```

## KeyPair

Defines an asymmetric key pair, which includes a public key and a private key. 

Asymmetric key pairs can be generated by an **AsyKeyGenerator**.

> **NOTE**
> 
> The **pubKey** and **priKey** objects in the **KeyPair** object are defined as one parameter in **KeyPair**. When **KeyPair** leaves the scope, its internal objects may be destructed. <br>The service must reference the **KeyPair** object instead of the **pubKey** or **priKey** object.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description          |
| ------- | ------ | ---- | ---- | ------------ |
| priKey  | [PriKey](#prikey) | Yes  | No  | Private key.     |
| pubKey | [PubKey](#pubkey) | Yes  | No  | Public key.      |


## cryptoFramework.createSymKeyGenerator

createSymKeyGenerator(algName : string) : SymKeyGenerator

Creates a **symKeyGenerator** instance based on the specified algorithm. 

For details about the supported specifications, see [Key Generation Specifications](../../security/cryptoFramework-overview.md#key-generation-specifications).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Algorithm used to create the **symKeyGenerator** instance.<br>For details, see "String Parameter" in [Key Generation Specifications](../../security/cryptoFramework-overview.md#key-generation-specifications). |

**Return value**

| Type                               | Description                      |
| ----------------------------------- | -------------------------- |
| [SymKeyGenerator](#symkeygenerator) | **symKeyGenerator** instance created.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
```

## SymKeyGenerator

Provides APIs for using the **symKeyGenerator**.

Before using any API of the **SymKeyGenerator** class, you must create a **symKeyGenerator** instance by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                          |
| ------- | ------ | ---- | ---- | ------------------------------ |
| algName | string | Yes  | No  | Algorithm used by the **symKeyGenerator**.|

### generateSymKey

generateSymKey(callback : AsyncCallback\<SymKey>) : void

Generates a symmetric key randomly. This API uses an asynchronous callback to return the result.

This API can be used only after a **symKeyGenerator** instance is created by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator). 

**RAND_priv_bytes()** of OpenSSL can be used to generate random keys.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                             | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[SymKey](#symkey)> | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the symmetric key generated. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message     |
| -------- | ------------- |
| 17620001 | memory error. |

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symAlgName = '3DES192';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
symKeyGenerator.generateSymKey((err, symKey) => {
  if (err) {
    console.error(`Generate symKey failed, ${err.code}, ${err.message}`);
  } else {
    console.info(`Generate symKey success, algName: ${symKey.algName}`);
  }
})
```

### generateSymKey

generateSymKey() : Promise\<SymKey>

Generates a symmetric key randomly. This API uses a promise to return the result. 

This API can be used only after a **symKeyGenerator** instance is created by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator). 

**RAND_priv_bytes()** of OpenSSL can be used to generate random keys.

**System capability**: SystemCapability.Security.CryptoFramework

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise used to return the symmetric key generated.|

**Error codes**

| ID| Error Message     |
| -------- | ------------- |
| 17620001 | memory error. |

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symAlgName = 'AES128';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
symKeyGenerator.generateSymKey()
.then(symKey => {
  console.info(`Generate symKey success, algName: ${symKey.algName}`);
}, error => {
  console.error(`Generate symKey failed, ${error.code}, ${error.message}`);
})
```

### convertKey

convertKey(key : DataBlob, callback : AsyncCallback\<SymKey>) : void

Converts data into a symmetric key. This API uses an asynchronous callback to return the result. <br>This API can be used only after a **symKeyGenerator** instance is created by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                             | Mandatory| Description                                                        |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| key      | [DataBlob](#datablob)             | Yes  | Data to convert.                                        |
| callback | AsyncCallback\<[SymKey](#symkey)> | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the symmetric key generated. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                                              |
| -------- | --------------------------------------------------- |
| 17620001 | memory error.                                       |

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

let symAlgName = '3DES192';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
let keyMaterialBlob = genKeyMaterialBlob();
symKeyGenerator.convertKey(keyMaterialBlob, (err, symKey) => {
  if (err) {
    console.error(`Convert symKey failed, ${err.code}, ${err.message}`);
  } else {
    console.info(`Convert symKey success, algName: ${symKey.algName}`);
  }
})
```

### convertKey

convertKey(key : DataBlob) : Promise\<SymKey>

Converts data into a symmetric key. This API uses a promise to return the result. <br>This API can be used only after a **symKeyGenerator** instance is created by using [createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| key  | [DataBlob](#datablob) | Yes  | Data to convert.|

**Return value**

| Type                       | Description                             |
| --------------------------- | --------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise used to return the symmetric key generated.|

**Error codes**

| ID| Error Message                                         |
| -------- | --------------------------------------------- |
| 17620001 | memory error.                                |

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

let symAlgName = '3DES192';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgName);
let keyMaterialBlob = genKeyMaterialBlob();
symKeyGenerator.convertKey(keyMaterialBlob)
.then(symKey => {
  console.info(`Convert symKey success, algName: ${symKey.algName}`);
}, error => {
  console.error(`Convert symKey failed, ${error.code}, ${error.message}`);
})
```

## cryptoFramework.createAsyKeyGenerator

createAsyKeyGenerator(algName : string) : AsyKeyGenerator

Creates an **AsyKeyGenerator** instance based on the specified algorithm. 

For details about the supported specifications, see [Key Generation Specifications](../../security/cryptoFramework-overview.md#key-generation-specifications).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                            |
| ------- | ------ | ---- | -------------------------------- |
| algName | string | Yes  | Algorithm used to create the **symkeyGenerator**.|

**Return value**

| Type           | Description                        |
| --------------- | ---------------------------- |
| [AsyKeyGenerator](#asykeygenerator) | **AsyKeyGenerator** instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
```

## AsyKeyGenerator

Provides APIs for using the **AsKeyGenerator**. Before using any API of the **AsKeyGenerator** class, you must create an **AsyKeyGenerator** instance by using **createAsyKeyGenerator()**.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                            |
| ------- | ------ | ---- | ---- | -------------------------------- |
| algName | string | Yes  | No  | Algorithm used by the **AsKeyGenerator**.|

### generateKeyPair

generateKeyPair(callback : AsyncCallback\<KeyPair>) : void;

Generates a key pair randomly. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                   | Mandatory| Description                          |
| -------- | ----------------------- | ---- | ------------------------------ |
| callback | AsyncCallback\<[KeyPair](#keypair)> | Yes  | Callback invoked to return the key pair obtained.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |

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

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the key pair generated.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |

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

Converts data into an asymmetric key. This API uses an asynchronous callback to return the result. For more information, see **Key Conversion**.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type      | Mandatory| Description                          |
| -------- | ----------- | ---- | ------------------------------ |
| pubKey   | [DataBlob](#datablob)     | Yes  | Public key material to convert. If no public key is required, set this parameter to **null**.       |
| priKey   | [DataBlob](#datablob)     | Yes  | Private key material to convert. If no private key is required, set this parameter to **null**.       |
| callback | AsyncCallback\<[KeyPair](#keypair)> | Yes  | Callback invoked to return the key pair obtained.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"
let pubKey; // Public key data in DER format complying with X.509 specifications. The data is omitted here.
let priKey; // Private key data in DER format complying with PKCS#8 specifications. The data is omitted here.
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

Converts data into an asymmetric key. This API uses a promise to return the result. For more information, see **Key Conversion**.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type   | Mandatory| Description            |
| ------ | -------- | ---- | ---------------- |
| pubKey | DataBlob | Yes  | Public key material to convert. If no public key is required, set this parameter to **null**.|
| priKey | DataBlob | Yes  | Private key material to convert. If no private key is required, set this parameter to **null**.|

**Return value**

| Type             | Description                             |
| ----------------- | --------------------------------- |
| Promise\<[KeyPair](#keypair)> | Promise used to return the key pair obtained. |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
let pubKey; // pubKey is a public key generated by the asymmetric key generator. The generation process is omitted here.
let priKey; // priKey is a private key generated by the asymmetric key generator. The generation process is omitted here.
let keyGenPromise = asyKeyGenerator.convertKey(pubKey, priKey);
keyGenPromise.then( keyPair => {
  console.info("convertKey success.");
}).catch(error => {
  console.error("convertKey error.");
});
```

**Key Conversion**

- If **getEncoded()** is called to obtain a public key and a private key (RSA and ECC), binary data in X.509 format and binary data in PKCS #8 format are returned, respectively. The data can be used for cross-application transfer or persistent storage.
- When **convertKey()** is called to convert binary data into an asymmetric key pair, the public key material must comply with the ASN.1 syntax, X.509 specifications, and DER encoding format, and the private key material must comply with the ASN.1 syntax, PKCS #8 specifications, and DER encoding format.
- In **convertKey()**, you can pass in either **pubKey** or **priKey**, or both of them. If one of them is passed in, the returned **KeyPair** instance contains only the key converted from the data you passed in.

## cryptoFramework.createCipher

createCipher(transformation : string) : Cipher

Creates a [Cipher](#cipher) instance based on the specified algorithm.

For details about the supported specifications, see [Encryption and Decryption Specifications](../../security/cryptoFramework-overview.md#encryption-and-decryption-specifications).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name        | Type  | Mandatory| Description                                                        |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| transformation | string | Yes  | Combination of the algorithm name (including the key length), encryption mode, and padding algorithm of the **Cipher** instance to create.<br>For details, see **Algorithm String** in [Encryption and Decryption Specifications](../../security/cryptoFramework-overview.md#encryption-and-decryption-specifications). |

> **NOTE**
> - In symmetric encryption and decryption, the implementation of PKCS #5 is the same as that of PKCS #7. PKCS #5 and PKCS #7 use the same padding length and block length. That is, data is padded with 8 bytes in 3DES and 16 bytes in AES. **noPadding** indicates that no padding is performed. <br>You need to understand the differences between different block cipher modes and set parameter correctly. For example, padding is required for ECB and CBC. Otherwise, the plaintext length must be an integer multiple of the block size. No padding is recommended for other modes. In this case, the ciphertext length is the same as the plaintext length.
> - If RSA is used for asymmetric encryption and decryption, two **Cipher** objects must be created to perform encryption and decryption separately. For symmetric encryption and decryption, one **cipher** object can be used to perform both encryption and decryption as long as the algorithm specifications are the same.

**Return value**

| Type             | Description                    |
| ----------------- | ------------------------ |
| [Cipher](#cipher) | [Cipher](#cipher) instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let cipherAlgName = '3DES192|ECB|PKCS7';
var cipher;
try {
  cipher = cryptoFramework.createCipher(cipherAlgName);
  console.info(`cipher algName: ${cipher.algName}`);
} catch (error) {
  console.error(`createCipher failed, ${error.code}, ${error.message}`);
}
```

## Cipher

Provides APIs for cipher operations. The [init()](#init-2), [update()](#update-4), and [doFinal()](#dofinal-2) APIs in this class are called in sequence to implement symmetric encryption/decryption and asymmetric encryption/decryption.

For details about the complete encryption and decryption process, see [Encrypting and Decrypting Data](../../security/cryptoFramework-guidelines.md#encrypting-and-decrypting-data).

A complete symmetric encryption/decryption process is slightly different from the asymmetric encryption/decryption process.

- In symmetric encryption and decryption, **init()** and **doFinal()** are mandatory. **update()** is optional and can be called multiple times to encrypt or decrypt big data by segment. After **doFinal()** is called to complete an encryption/decryption operation, **init()** can be called to start a new encryption/decryption operation.
- In RSA asymmetric encryption and decryption, **init()** and **doFinal()** are mandatory, and **update()** is not supported. **doFinal()** can be called multiple times to encrypt or decrypt big data by segment. **init()** cannot be called repeatedly. If the encryption/decryption mode or padding mode is changed, a new **Cipher** object must be created.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework


| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm.|

### init

init(opMode : CryptoMode, key : Key, params : ParamsSpec, callback : AsyncCallback\<void>) : void

Initializes a [cipher](#cipher) instance. This API uses an asynchronous callback to return the result. 

This API can be used only after a [Cipher](#cipher) instance is created by using [createCipher](#cryptoframeworkcreatecipher).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode   | [CryptoMode](#cryptomode) | Yes  | Operation (encryption or decryption) to perform.                                          |
| key      | [Key](#key)               | Yes  | Key for encryption or decryption.                                      |
| params   | [ParamsSpec](#paramsspec) | Yes  | Parameters for encryption or decryption. For algorithm modes without parameters (such as ECB), **null** can be passed in.|
| callback | AsyncCallback\<void>      | Yes  | Callback invoked to return the result. If the initialization is successful, **err** is **undefined**. Otherwise, **err** is an error object.    |

**Error codes**

| ID| Error Message                                                |
| -------- | --------------------------------------------------------- |
| 17620001 | memory error.                                            |
| 17620002 | runtime error.                                           |
| 17630001 | crypto operation error.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKey;     // The process of generating the symmetric key is omitted here.
let cipher;        // The process of creating a Cipher instance is omitted here.

cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null, (err, ) => {
  if (err) {
    console.error(`Failed to init cipher, ${err.code}, ${err.message}`);
  } else {
    console.info(`Init cipher success`);
    // Perform subsequent operations such as update.
  }
})
```

### init

init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>

Initializes a [cipher](#cipher) instance. This API uses a promise to return the result. 

This API can be used only after a [Cipher](#cipher) instance is created by using [createCipher](#cryptoframeworkcreatecipher).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode | [CryptoMode](#cryptomode) | Yes  | Operation (encryption or decryption) to perform.                                          |
| key    | [Key](#key)               | Yes  | Key for encryption or decryption.                                      |
| params | [ParamsSpec](#paramsspec) | Yes  | Parameters for encryption or decryption. For algorithm modes without parameters (such as ECB), **null** can be passed in.|

**Return value**

| Type          | Description                                  |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

| ID| Error Message                                         |
| -------- | ------------------------------------------------- |
| 17620001 | memory error.                                     |
| 17620002 | runtime error.                                    |
| 17630001 | crypto operation error.|

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKey;     // The process of generating the symmetric key is omitted here.
let cipher;        // The process of creating a Cipher instance is omitted here.
cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null)
.then(() => {
  console.info(`Init cipher success`);
  // Perform subsequent operations such as update.
}, error => {
  console.error(`Failed to init cipher, ${error.code}, ${error.message}`);
})
```

### update

update(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

Updates the data to encrypt or decrypt by segment. This API uses an asynchronous callback to return the encrypted or decrypted data. 

This API can be called only after the [Cipher](#cipher) instance is initialized by using [init()](init-2).

> **NOTE**
> - The **update()** and [doFinal()](#dofinal-2) results vary with the block mode you use. If you are not familiar with the block modes for symmetric encryption and decryption, add a judgment to determine whether the result of each **update()** and **doFinal()** is null. If the result is not null, obtain the data to concatenate the complete ciphertext or plaintext.<br>For example, in ECB and CBC modes, data is encrypted or decrypted by block no matter whether the data passed in by **update()** is an integer multiple of the block length, and the encrypted/decrypted block data generated by this **update()** is output. <br>That is, data is output by **update()** as long as the input data is of the block size. Otherwise, **null** is returned and the data will be retained until a block is formed in the next **update()**/**doFinal()**. <br>When **doFinal()** is called, the data that has not been encrypted or decrypted will be padded based on the padding mode set in [createCipher](#cryptoframeworkcreatecipher) to an integer multiple of the block length, and then encrypted or decrypted. <br>For a mode in which a block cipher can be converted into a stream cipher, the length of the ciphertext may be the same as that of the plaintext.
> - **update()** can be called multiple times or not be called ([doFinal()](#dofinal-2) is called after [init](#init-2)), depending on the size of the data to encrypt or decrypt. <br>The algorithm library does not set a limit on the amount of data that can be passed in by **updated()** (once or accumulatively). For symmetric encryption and decryption of a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment. <br>For details about the sample code for calling **update()** multiple times in AES, see [Encrypting and Decrypting Data](../../security/cryptoFramework-guidelines.md#encrypting-and-decrypting-data).
> - RSA asymmetric encryption and decryption do not support **update()**.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob)                 | Yes  | Data to encrypt or decrypt. It cannot be **null** or {data:Uint8Array (null)}.           |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**, and **data** is **DataBlob** (containing the encrypted or decrypted data). Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                                   |
| -------- | ------------------------------------------- |
| 17620001 | memory error.                               |
| 17620002 | runtime error.                              |
| 17630001 | crypto operation error.                     |

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
    console.error(`Failed to update cipher`);
  } else {
    console.info(`Update cipher success`);
    if (output != null) {
      // Concatenate output.data to the ciphertext.
    }
    // Perform subsequent operations such as doFinal().
  }
})
```

### update

update(data : DataBlob) : Promise\<DataBlob>

Updates the data to encrypt or decrypt by segment. This API uses a promise to return the encrypted or decrypted data. <br>This API can be called only after the [Cipher](#cipher) instance is initialized by using [init()](init-2).

> **NOTE**
> - The **update()** and [doFinal()](#dofinal-2) results vary with the block mode you use. If you are not familiar with the block modes for symmetric encryption and decryption, add a judgment to determine whether the result of each **update()** and **doFinal()** is null. If the result is not null, obtain the data to concatenate the complete ciphertext or plaintext.<br>For example, in ECB and CBC modes, data is encrypted or decrypted by block no matter whether the data passed in by **update()** is an integer multiple of the block length, and the encrypted/decrypted block data generated by this **update()** is output. <br>That is, data is output as long as the data passed in by **update()** is of the block size. Otherwise, **null** is returned and the data will be retained until a block is formed in the next **update()**/**doFinal()**. <br>When **doFinal()** is called, the data that has not been encrypted or decrypted will be padded based on the padding mode set in [createCipher](#cryptoframeworkcreatecipher) to an integer multiple of the block length, and then encrypted or decrypted. <br>For a mode in which a block cipher can be converted into a stream cipher, the length of the ciphertext may be the same as that of the plaintext.
> - **update()** can be called multiple times or not be called ([doFinal()](#dofinal-2) is called after [init](#init-2)), depending on the size of the data to encrypt or decrypt. <br>The algorithm library does not set a limit on the amount of data that can be passed in by **updated()** (once or accumulatively). For symmetric encryption and decryption of a large amount of data, you are advised to call **update()** multiple times to pass in the data by segment. For details about the sample code for calling **update()** multiple times in AES, see [Encrypting and Decrypting Data](../../security/cryptoFramework-guidelines.md#encrypting-and-decrypting-data).
> - RSA asymmetric encryption and decryption do not support **update()**.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| data | [DataBlob](#datablob) | Yes  | Data to encrypt or decrypt. It cannot be **null** or {data:Uint8Array (null)}.|

**Return value**

| Type                           | Description                                            |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[DataBlob](#datablob)> | Promise used to return the **DataBlob** (containing the encrypted or decrypted data).|

**Error codes**

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 17620001 | memory error.                                |
| 17620002 | runtime error.                               |
| 17630001 | crypto operation error.                      |

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
cipher.update(plainText)
.then((output) => {
  console.info(`Update cipher success.`);
  if (output != null) {
    // Concatenate output.data to the ciphertext.
  }
  // Perform subsequent operations such as doFinal().
}, error => {
  console.info(`Update cipher failed.`);
})
```

### doFinal

doFinal(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

(1) Encrypts or decrypts the remaining data (generated by the block ciper mode) and the data passed in by **doFinal()** to finalize the symmetric encryption or decryption. This API uses an asynchronous callback to return the encrypted or decrypted data. <br>If a small amount of data needs to be encrypted or decrypted, you can use **doFinal()** to pass in data without using **update()**. If all the data has been passed in by [update()](#update-4), you can pass in **null** in **data** of **doFinal()**. 

The output of **doFinal()** varies with the symmetric encryption/decryption mode in use.

- Symmetric encryption in GCM and CCM mode: The result consists of the ciphertext and **authTag** (the last 16 bytes for GCM and the last 12 bytes for CCM). If **null** is passed in by **data** of **doFinal()**, the result of **doFinal()** is **authTag**. <br>**authTag** must be [GcmParamsSpec](#gcmparamsspec) or [CcmParamsSpec](#ccmparamsspec) used for decryption. The ciphertext is the **data** passed in for decryption.
- Symmetric encryption and decryption in other modes and symmetric decryption in GCM and CCM modes: The result is the complete plaintext/ciphertext.

(2) Encrypts or decrypts the input data for RSA asymmetric encryption/decryption. This API uses an asynchronous callback to return the result. If a large amount of data needs to be encrypted/decrypted, call **doFinal()** multiple times and concatenate the result of each **doFinal()** to obtain the complete plaintext/ciphertext.

>  **NOTE**
>  - In symmetric encryption or decryption, calling **doFinal()** means the end of an  encryption or decryption process, and the [Cipher](#cipher) instance state will be cleared. To start a new encryption or decryption operation, you must call [init()](#init-2) to pass in a complete parameter list for initialization. <br>For example, if the same symmetric key is used for a **Cipher** instance to perform encryption and then decryption. After the encryption is complete, the **params** in **init** for decryption must be set instead of being **null**.
>  - If a decryption operation fails, check whether the data to be encrypted and decrypted matches the parameters in **[init](#init-2)**. For the GCM mode, check whether the **authTag** obtained after encryption is obtained from the **GcmParamsSpec** for decryption.
>  - The result of **doFinal()** may be **null**. To avoid exceptions, determine whether the result is **null** before using the **.data** field to access the **doFinal()** result.
>  - For details about the sample code for calling **doFinal()** multiple times during RSA asymmetric encryption and decryption, see [Encrypting and Decrypting Data](../../security/cryptoFramework-guidelines.md#encrypting-and-decrypting-data).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name    | Type                                 | Mandatory| Description                                                        |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob)                 | Yes  | Data to encrypt or decrypt. It can be **null** in symmetric encryption or decryption, but cannot be {data:Uint8Array(null)}.      |
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return the result. If the data is successfully encrypted or decrypted, **err** is **undefined**, and **data** is the **DataBlob** (encryption or decryption result of the remaining data). Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message               |
| -------- | ----------------------- |
| 17620001 | memory error.           |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let cipher;        // The process of creating a Cipher instance is omitted here.
let data;           // The process of preparing the data to encrypt or decrypt is omitted here.
// The init() and update() processes are omitted here.
cipher.doFinal(data, (err, output) => {
  if (err) {
    console.error(`Failed to finalize cipher, ${err.code}, ${err.message}`);
  } else {
    console.info(`Finalize cipher success`);
    if (output != null) {
      // Concatenate output.data to obtain the complete plaintext/ciphertext (and authTag).
    }
  }
})
```

### doFinal

doFinal(data : DataBlob) : Promise\<DataBlob>

(1) Encrypts or decrypts the remaining data (generated by the block ciper mode) and the data passed in by **doFinal()** to finalize the symmetric encryption or decryption. This API uses a promise to return the encrypted or decrypted data. <br>If a small amount of data needs to be encrypted or decrypted, you can use **doFinal()** to pass in data without using **update()**. If all the data has been passed in by [update()](#update-4), you can pass in **null** in **data** of **doFinal()**. 

The output of **doFinal()** varies with the symmetric encryption/decryption mode in use.

- Symmetric encryption in GCM and CCM mode: The result consists of the ciphertext and **authTag** (the last 16 bytes for GCM and the last 12 bytes for CCM). If **null** is passed in by **data** of **doFinal()**, the result of **doFinal()** is **authTag**. <br>**authTag** must be [GcmParamsSpec](#gcmparamsspec) or [CcmParamsSpec](#ccmparamsspec) used for decryption. The ciphertext is the **data** passed in for decryption.
- Symmetric encryption and decryption in other modes and symmetric decryption in GCM and CCM modes: The result is the complete plaintext/ciphertext.

(2) Encrypts or decrypts the input data for RSA asymmetric encryption/decryption. This API uses a promise to return the result. If a large amount of data needs to be encrypted/decrypted, call **doFinal()** multiple times and concatenate the result of each **doFinal()** to obtain the complete plaintext/ciphertext.

>  **NOTE**
>  - In symmetric encryption or decryption, calling **doFinal()** means the end of an  encryption or decryption process, and the [Cipher](#cipher) instance state will be cleared. To start a new encryption or decryption operation, you must call [init()](#init-2) to pass in a complete parameter list for initialization. <br>For example, if the same symmetric key is used for a **Cipher** instance to perform encryption and then decryption. After the encryption is complete, the **params** in **init** for decryption must be set instead of being **null**.
>  - If a decryption fails, check whether the data to be encrypted and decrypted matches the parameters in **[init](#init-2)**. For the GCM mode, check whether the **authTag** obtained after encryption is obtained from the **GcmParamsSpec** for decryption.
>  - The result of **doFinal()** may be **null**. To avoid exceptions, determine whether the result is **null** before using the **.data** field to access the **doFinal()** result.
>  - For details about the sample code for calling **doFinal()** multiple times during RSA asymmetric encryption and decryption, see [Encrypting and Decrypting Data](../../security/cryptoFramework-guidelines.md#encrypting-and-decrypting-data).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type                 | Mandatory| Description                |
| ---- | --------------------- | ---- | -------------------- |
| data | [DataBlob](#datablob) | Yes  | Data to encrypt or decrypt. It can be **null**, but cannot be {data:Uint8Array(null)}.|

**Return value**

| Type                           | Description                                            |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[DataBlob](#datablob)> | Promise used to return the **DataBlob**, which is the encryption or decryption result of the remaining data.|

**Error codes**

| ID| Error Message                                    |
| -------- | -------------------------------------------- |
| 17620001 | memory error.                                |
| 17620002 | runtime error.                               |
| 17630001 | crypto operation error.                      |

**Example**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let cipher;        // The process of creating a Cipher instance is omitted here.
let data;           // The process of preparing the data to encrypt or decrypt is omitted here.
// The init() and update() processes are omitted here.
cipher.doFinal(data)
.then(output => {
  console.info(`Finalize cipher success`);
    if (output != null) {
    // Concatenate output.data to obtain the complete plaintext/ciphertext (and authTag).
  }
}, error => {
  console.error(`Failed to finalize cipher, ${error.code}, ${error.message}`);
})
```

**RSA encryption example (callback)**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
rsaGenerator.generateKeyPair(function (err, keyPair) {
  let pubKey = keyPair.pubKey;
  cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null, function (err, data) {
    let plainText = "this is cipher text";
    let input = {data : stringToUint8Array(plainText) };
    cipher.doFinal(input, function (err, data) {
      AlertDialog.show({ message : "EncryptOutPut is " + data.data} );
    });
  });
});
```

**RSA encryption example (promise)**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
let keyGenPromise = rsaGenerator.generateKeyPair();
keyGenPromise.then(rsaKeyPair => {
  let pubKey = rsaKeyPair.pubKey;
  return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null); // Pass in the private key and DECRYPT_MODE to initialize the decryption mode.
}).then(() => {
  let plainText = "this is cipher text";
  let input = { data : stringToUint8Array(plainText) };
  return cipher.doFinal(input);
}).then(dataBlob => {
  console.info("EncryptOutPut is " + dataBlob.data);
});
```

> **NOTE**<br>
> For more encryption and decryption examples, see [Encrypting and Decrypting Data](../../security/cryptoFramework-guidelines.md#encrypting-and-decrypting data).

## cryptoFramework.createSign

createSign(algName : string) : Sign

Creates a **Sign** instance.

For details about the supported specifications, see [Signing and Signature Verification Specifications](../../security/cryptoFramework-overview.md#signing-and-signature-verification-specifications).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Signing algorithm to use, which can be RSA or ECC. If RSA PKCS #1 is used, the digest must be set. If RSA PSS is used, the digest and mask digest must be set.|

**Return value**

| Type| Description                            |
| ---- | -------------------------------- |
| Sign | **Sign** instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let signer1 = cryptoFramework.createSign("RSA1024|PKCS1|SHA256");

let singer2 = cryptoFramework.createSign("RSA1024|PSS|SHA256|MGF1_SHA256")
```

## Sign

Provides APIs for signing. Before using any API of the **Sign** class, you must create a **Sign** instance by using **createSign()**. The **Sign** class does not support repeated initialization. When a new key is used for signing, you must create a new **Sign** object and call **init()** for initialization.

The signing mode is determined in **createSign()**, and the key is set by **init()**.

If the data to be signed is short, you can use **sign()** to pass in the data for signing after **init()**.

If the data to be signed is long, you can use **update()** to pass in the data by segment, and then use **sign()** to sign the entire data.

If **update()** is used to pass in data by segment, **data** of **sign()** can be **null**.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm to use.|

### init

init(priKey : PriKey, callback : AsyncCallback\<void>) : void

Initializes a **Sign** instance using a private key. This API uses an asynchronous callback to return the result. The **Sign** class does not support repeated calling of **init()**. 

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description            |
| -------- | -------------------- | ---- | ---------------- |
| priKey   | [PriKey](#prikey)    | Yes  | Private key used for the initialization.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.      |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### init

init(priKey : PriKey) : Promise\<void>

Initializes a **Sign** instance using a private key. This API uses a promise to return the result. The **Sign** class does not support repeated calling of **init()**. 

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type| Mandatory| Description            |
| ------ | ---- | ---- | ---------------- |
| priKey | [PriKey](#prikey)  | Yes  | Private key used for the initialization.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data : DataBlob, callback : AsyncCallback\<void>) : void

Updates the data to be signed. This API uses an asynchronous callback to return the result.

> **NOTE**<br>
> For details about the sample code for calling **update()** multiple times, see [Generating and Verifying a Signature](../../security/cryptoFramework-guidelines.md#generating-and-verifying-a-signature).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| data     | [DataBlob](#datablob)| Yes  | Data to pass in.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.  |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data : DataBlob) : Promise\<void>;

Updates the data to be signed. This API uses a promise to return the result.

> **NOTE**<br>
> For details about the sample code for calling **update()** multiple times, see [Generating and Verifying a Signature](../../security/cryptoFramework-guidelines.md#generating-and-verifying-a-signature).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob)  | Yes  | Data to pass in.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### sign

sign(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

Signs the data. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| data     | [DataBlob](#datablob)              | Yes  | Data to pass in.|
| callback | AsyncCallback\<[DataBlob](#datablob) > | Yes  | Callback invoked to return the result.  |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### sign

sign(data : DataBlob) : Promise\<DataBlob>

Signs the data. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob)  | Yes  | Data to pass in.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**Callback example**:

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
let plan1 = "This is Sign test plan1"; // The first segment of the data.
let plan2 = "This is Sign test plan2"; // The second segment of the data.
let input1 = { data : stringToUint8Array(plan1) };
let input2 = { data : stringToUint8Array(plan2) };

function signMessageCallback() {
  let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
  let signer = cryptoFramework.createSign("RSA1024|PKCS1|SHA256");
  rsaGenerator.generateKeyPair(function (err, keyPair) {
    globalKeyPair = keyPair;
    let priKey = globalKeyPair.priKey;
    signer.init(priKey, function (err, data) {
      signer.update(input1, function (err, data) { // Add the first segment of the data.
        signer.sign(input2, function (err, data) { // Add the second segment of the data, and sign input1 and input2.
          SignMessageBlob = data;
          AlertDialog.show({message : "res" +  SignMessageBlob.data});
        });
      });
    });
  });
}
```

**Promise example**:

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
let plan1 = "This is Sign test plan1"; // The first segment of the data.
let plan2 = "This is Sign test plan2"; // The second segment of the data.
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
    return signer.update(input1); // Add the first segment of the data.
  }).then(() => {
    return signer.sign(input2); // Add the second segment of the data, and sign input1 and input2.
  }).then(dataBlob => {
    SignMessageBlob = dataBlob;
    console.info("sign output is " + SignMessageBlob.data);
    AlertDialog.show({message : "output" +  SignMessageBlob.data});
  });
}
```

## cryptoFramework.createVerify

createVerify(algName : string) : Verify

Creates a **Verify** instance. For details about the supported specifications, see [Signing and Signature Verification Specifications](../../security/cryptoFramework-overview.md#signing-and-signature-verification-specifications).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                                                        |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | Yes  | Signing algorithm to use, which can be RSA or ECC. If RSA PKCS #1 is used, the digest must be set. If RSA PSS is used, the digest and mask digest must be set.|

**Return value**

| Type  | Description                              |
| ------ | ---------------------------------- |
| Verify | **Verify** instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let verifyer1 = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");

let verifyer2 = cryptoFramework.createVerify("RSA1024|PSS|SHA256|MGF1_SHA256")
```

## Verify

Provides APIs for signature verification. Before using any API of the **Verify** class, you must create a **Verify** instance by using **createVerify()**.

The **Verify** class does not support repeated initialization. When a new key is used for signature verification, you must create a new **Verify** object and call **init()** for initialization.

The signature verification mode is determined in **createVerify()**, and key is set by **init()**.

If the signature data to be verified is short, you can call **verify()** to pass in the signature data and original data after **init()**.

If the signature data to be verified is long, you can use **update()** to pass in the data by segment, and then use **verify()** to verify the entire data.

If **update()** is used to pass in data by segment, **data** of **verify()** can be **null**.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm to be used for signature verification.|



### init

init(pubKey : PubKey, callback : AsyncCallback\<void>) : void

Initializes the **Verify** instance using a public key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description                        |
| -------- | -------------------- | ---- | ---------------------------- |
| pubKey   | [PubKey](#pubkey)    | Yes  | Public key used for the initialization.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.                    |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### init

init(pubKey : PubKey) : Promise\<void>

Initializes the **Verify** instance using a public key. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type| Mandatory| Description                        |
| ------ | ---- | ---- | ---------------------------- |
| pubKey | [PubKey](#pubkey)  | Yes  | Public key used for the initialization.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data : DataBlob, callback : AsyncCallback\<void>) : void

Updates the data for signature verification. This API uses an asynchronous callback to return the result.

> **NOTE**
> For details about the sample code for calling **update()** multiple times, see [Generating and Verifying a Signature](../../security/cryptoFramework-guidelines.md#generating-and-verifying-a-signature).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                | Mandatory| Description      |
| -------- | -------------------- | ---- | ---------- |
| data     | [DataBlob](#datablob)| Yes  | Data to pass in.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.  |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### update

update(data : DataBlob) : Promise\<void>;

Updates the data for signature verification. This API uses a promise to return the result.

> **NOTE**
> For details about the sample code for calling **update()** multiple times, see [Generating and Verifying a Signature](../../security/cryptoFramework-guidelines.md#generating-and-verifying-a-signature).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type    | Mandatory| Description      |
| ------ | -------- | ---- | ---------- |
| data   | [DataBlob](#datablob)  | Yes  | Data to pass in.|

**Return value**

| Type          | Description       |
| -------------- | ----------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### verify

verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback\<boolean>) : void

Verifies a signature. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name       | Type                | Mandatory| Description      |
| ------------- | -------------------- | ---- | ---------- |
| data          | [DataBlob](#datablob)              | Yes  | Data to pass in.|
| signatureData | [DataBlob](#datablob)              | Yes  | Signature data.  |
| callback      | AsyncCallback\<boolean> | Yes  | Callback invoked to return the result.  |

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### verify

verify(data : DataBlob, signatureData : DataBlob) : Promise\<boolean>

Verifies a signature. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name       | Type    | Mandatory| Description      |
| ------------- | -------- | ---- | ---------- |
| data          | [DataBlob](#datablob)  | Yes  | Data to pass in.|
| signatureData | [DataBlob](#datablob)  | Yes  | Signature data.  |

**Return value**

| Type             | Description                        |
| ----------------- | ---------------------------- |
| Promise\<boolean> | Promise used to return the result.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**Callback example**:

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalKeyPair; // globalKeyPair is an asymmetric key object generated by the asymmetric key generator. The generation process is omitted here.
let input1 = null;
let input2 = null;
let signMessageBlob = null; // Signed data, which is omitted here.
let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA25");
verifyer.init(globalKeyPair.pubKey, function (err, data) {
  verifyer.update(input1, function(err, data) {
    verifyer.verify(input2, signMessageBlob, function(err, data) {
      console.info("verify result is " + data);
    })
  });
})
```

**Promise example**:

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalKeyPair; // globalKeyPair is an asymmetric key object generated by the asymmetric key generator. The generation process is omitted here.
let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
let verifyInitPromise = verifyer.init(globalKeyPair.pubKey);
let input1 = null;
let input2 = null;
let signMessageBlob = null; // Signed data, which is omitted here.
verifyInitPromise.then(() => {
  return verifyer.update(input1);
}).then(() => {
  return verifyer.verify(input2, signMessageBlob);
}).then(res => {
  console.log("Verify result is " + res);
});
```

## cryptoFramework.createKeyAgreement

createKeyAgreement(algName : string) : KeyAgreement

Creates a **KeyAgreement** instance.

For details about the supported specifications, see [Key Agreement Specifications](../../security/cryptoFramework-overview.md#key-agreement-specifications).

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name | Type  | Mandatory| Description                           |
| ------- | ------ | ---- | ------------------------------- |
| algName | string | Yes  | Key agreement algorithm to use. Only ECC is supported.|

**Return value**

| Type        | Description                                    |
| ------------ | ---------------------------------------- |
| KeyAgreement | **KeyAgreement** instance created.|

**Example**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let keyAgreement = cryptoFramework.createKeyAgreement("ECC256");

```

## KeyAgreement

Provides APIs for key agreement operations. Before using any API of the **KeyAgreement** class, you must create a **KeyAgreement** instance by using **createKeyAgreement()**.

### Attributes

**System capability**: SystemCapability.Security.CryptoFramework

| Name   | Type  | Readable| Writable| Description                        |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | Yes  | No  | Algorithm used for key agreement.|

### generateSecret

generateSecret(priKey : PriKey, pubKey : PubKey, callback : AsyncCallback\<DataBlob>) : void

Generates a shared secret. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name  | Type                    | Mandatory| Description                  |
| -------- | ------------------------ | ---- | ---------------------- |
| priKey   | [PriKey](#prikey)        | Yes  | Private key used for key agreement.|
| pubKey   | [PubKey](#pubkey)        | Yes  | Public key used for key agreement.|
| callback | AsyncCallback\<[DataBlob](#datablob)> | Yes  | Callback invoked to return the shared secret.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

### generateSecret

generateSecret(priKey : PriKey, pubKey : PubKey) : Promise\<DataBlob>

Generates a shared secret. This API uses a promise to return the result.

**System capability**: SystemCapability.Security.CryptoFramework

**Parameters**

| Name| Type  | Mandatory| Description                  |
| ------ | ------ | ---- | ---------------------- |
| priKey | [PriKey](#prikey) | Yes  | Private key used for key agreement.|
| pubKey | [PubKey](#pubkey) | Yes  | Public key used for key agreement.|

**Return value**

| Type              | Description    |
| ------------------ | -------- |
| Promise\<[DataBlob](#datablob)> | Promise used to return the shared secret.|

**Error codes**

| ID| Error Message              |
| -------- | ---------------------- |
| 17620001 | memory error.          |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**Callback example**:

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalKeyPair; // globalKeyPair is an asymmetric key object generated by the asymmetric key generator. The generation process is omitted here.
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

let globalKeyPair; // globalKeyPair is an asymmetric key object generated by the asymmetric key generator. The generation process is omitted here.
let keyAgreement = cryptoFramework.createKeyAgreement("ECC256");
let keyAgreementPromise = keyAgreement.generateSecret(globalKeyPair.priKey, globalKeyPair.pubKey);
keyAgreementPromise.then((secret) => {
  console.info("keyAgreement output is " + secret.data);
}).catch((error) => {
  console.error("keyAgreement error.");
});
```
