# 加解密算法库框架

为屏蔽底层硬件和算法库，向上提供统一的密码算法库加解密和证书相关接口。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。

## 导入模块

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"
```

## Result

 表示执行结果的枚举。

 **系统能力：** SystemCapability.Security.CryptoFramework

| 名称                                  | 默认值   | 描述                          |
| --------------------------------------| -------- | ------------------------------|
| INVALID_PARAMS                        | 401      | 非法入参。                    |
| NOT_SUPPORT                           | 801      | 操作不支持。                  |
| ERR_OUT_OF_MEMORY                     | 17620001 | 内存错误。                    |
| ERR_RUNTIME_ERROR                     | 17620002 | 运行时外部错误。                  |
| ERR_CRYPTO_OPERATION                  | 17630001 | 调用三方算法库API出错。       |
| ERR_CERT_SIGNATURE_FAILURE            | 17630002 | 证书签名验证错误。            |
| ERR_CERT_NOT_YET_VALID                | 17630003 | 证书尚未生效。                |
| ERR_CERT_HAS_EXPIRED                  | 17630004 | 证书过期。                    |
| ERR_UNABLE_TO_GET_ISSUER_CERT_LOCALLY | 17630005 | 无法获取证书的颁发者。        |
| ERR_KEYUSAGE_NO_CERTSIGN              | 17630006 | 证书的秘钥用途不含证书签名。  |
| ERR_KEYUSAGE_NO_DIGITAL_SIGNATURE     | 17630007 |  证书的秘钥用途不含数字签名。 |

## DataBlob
buffer数组。
 **系统能力：** SystemCapability.Security.CryptoFramework
| 名称           | 类型           | 可读 | 可写 | 描述               |
| -------------- | -------------- | ---- | ---- | ----------------|
| data           | Uint8Array     | 是   | 是   | 数据。    |

## DataArray
buffer数组的列表。
 **系统能力：** SystemCapability.Security.CryptoFramework
| 名称           | 类型           | 可读 | 可写 | 描述               |
| -------------- | -------------- | ---- | ---- | ----------------|
| data           | Uint8Array     | 是   | 是   | 数据列表。    |

## EncodingFormat

 表示证书编码格式的枚举。

 **系统能力：** SystemCapability.Security.CryptoFramework

| 名称        | 默认值   | 描述       |
| ------------| ---------| -----------|
| FORMAT_DER  | 0        | DER格式。  |
| FORMAT_PEM  | 1        | PEM格式。  |


## EncodingBlob

带编码格式的证书二进制数组。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称           | 类型           | 可读 | 可写 | 描述                              |
| -------------- | -------------- | ---- | ---- | ----------------------------------|
| data           | Uint8Array     | 是   | 是   | 传入的数据中，包含的证书数量。    |
| encodingFormat | [EncodingFormat](#encodingformat) | 是   | 是   | 指明证书编码格式。 |


## CertChainData

证书链数据，在证书链校验时，作为入参传入。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称           | 类型           | 可读 | 可写 | 描述                                                         |
| -------------- | -------------- | ---- | ---- | ------------------------------------------------------------ |
| data           | Uint8Array     | 是   | 是   | 证书数据，按照长度(2字节)-数据的形式传入，如：08ABCDEFGH07ABCDEFG,第一本证书，前2个字节表示证书的长度为8字节，后面附加8字节的证书数据；第2本证书前2个字节表示证书的长度为7字节，后面附加7字节的证书数据。   |
| count          | number         | 是   | 是   | 传入的数据中，包含的证书数量。                             |
| encodingFormat | [EncodingFormat](#encodingformat) | 是   | 是   | 指明证书编码格式。 |


## cryptoFramework.createMac

createMac(algName : string) : Mac

生成Mac实例，用于进行消息认证码的计算与操作

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 指定摘要算法，支持算法范围：SHA1/SHA224/SHA256/SHA384/SHA512 |

**返回值**：

| 类型 | 说明                                    |
| ---- | --------------------------------------- |
| Mac  | 返回由输入算法指定生成的[Mac](#mac)对象 |

**示例：**

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

Mac类，调用Mac方法可以进行MAC（Message Authentication Code）加密计算。调用前，需要通过[createMac](#cryptoframeworkcreatemac)构造Mac实例。

### **属性**

**系统能力：**SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                 |
| ------- | ------ | ---- | ---- | -------------------- |
| algName | string | 是   | 否   | 代表指定的摘要算法名 |

### init

init(key : SymKey, callback : AsyncCallback\<void>) : void;	

使用对称密钥初始化Mac计算

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| key   | SymKey                   | 是   | 共享对称密钥       |
| callback | AsyncCallback\<void> | 是   | 回调函数 |

**示例：**

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

使用对称密钥初始化Mac计算

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| key    | SymKey | 是   | 共享对称密钥 |

**返回值：**

| 类型            | 说明         |
| --------------- | ------------ |
| Promise\<void> | Promise对象 |

**示例：**

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

传入消息进行Mac更新计算

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ---------- |
| input    | DataBlob              | 是   | 传入的消息         |
| callback | AsyncCallback\<void> | 是   | 回调函数 |

**示例：**

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

传入消息进行Mac更新计算

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| input  | DataBlob | 是   | 传入的消息 |

**返回值：**

| 类型            | 说明         |
| --------------- | ----------- |
| Promise\<void> | Promise对象 |

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

返回Mac的计算结果

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名   | 类型                      | 必填 | 说明           |
| -------- | ------------------------- | ---- | -------- |
| callback | AsyncCallback\<DataBlob> | 是   | 回调函数 |

**示例：**

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

返回Mac的计算结果

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型              | 说明        |
| ------------------- | ----------- |
| Promise\<DataBlob> | Promise对象 |

**示例：**

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

获取Mac消息认证码的长度（字节数）

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| number | 返回mac计算结果的字节长度 |

**示例：**

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

生成Md实例，用于进行消息摘要的计算与操作

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 指定摘要算法，支持算法范围：SHA1/SHA224/SHA256/SHA384/SHA512/MD5 |

**返回值**：

| 类型 | 说明                                  |
| ---- | ------------------------------------- |
| Md   | 返回由输入算法指定生成的[Md](#md)对象 |

**示例：**

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

Md类，调用Md方法可以进行MD（Message Digest）摘要计算。调用前，需要通过[createMd](#cryptoframeworkcreatemd)构造Md实例。

### **属性**

**系统能力：**SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                 |
| ------- | ------ | ---- | ---- | -------------------- |
| algName | string | 是   | 否   | 代表指定的摘要算法名 |

### update

update(input : DataBlob, callback : AsyncCallback\<void>) : void;

传入消息进行Md更新计算

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名   | 类型                  | 必填 | 说明         |
| -------- | --------------------- | ---- | ------------ |
| input    | DataBlob              | 是   | 传入的消息   |
| callback | AsyncCallback\<void> | 是   | 回调函数 |

**返回值：**

| 类型            | 说明         |
| --------------- | ------------ |
| Promise\<void> | Promise对象 |

**示例：**

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

传入消息进行Md更新计算

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| input  | DataBlob | 是   | 传入的消息 |

**返回值：**

| 类型            | 说明         |
| --------------- | ------------ |
| Promise\<void> | Promise对象 |

**示例：**

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

返回Md的计算结果

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| callback | AsyncCallback\<DataBlob> | 是   | 回调函数 |

**示例：**

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

返回Md的计算结果

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型              | 说明        |
| ------------------- | ----------- |
| Promise\<DataBlob> | Promise对象 |

**示例：**

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

获取Md消息摘要长度（字节数）

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| number | 返回md计算结果的字节长度 |

**示例：**

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

生成Random实例，用于进行随机数的计算与设置种子

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                                          |
| ------ | --------------------------------------------- |
| Random | 返回由输入算法指定生成的[Random](#random)对象 |

**示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

try {
    var rand = cryptoFramework.createRandom();
} catch (error) {
    console.error("[Callback]: error code: " + error.code + ", message is: " + error.message); 
}
```

## Random

Random类，调用Random方法可以进行随机数计算。调用前，需要通过[createRandom](#cryptoframeworkcreaterandom)构造Random实例。

### generateRandom

generateRandom(len : number, callback: AsyncCallback\<DataBlob>) : void;

生成指定长度的随机数

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名   | 类型                      | 必填 | 说明                 |
| -------- | ------------------------- | ---- | -------------------- |
| len      | number                    | 是   | 表示生成随机数的长度 |
| callback | AsyncCallback\<DataBlob> | 是   | 回调函数 |

**示例：**

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

生成指定长度的随机数

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| len    | number | 是   | 表示生成随机数的长度 |

**返回值：**

| 类型              | 说明        |
| ------------------- | ----------- |
| Promise\<DataBlob> | Promise对象 |

**示例：**

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

设置指定的种子

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名   | 类型                 | 必填 | 说明         |
| -------- | -------------------- | ---- | ------------ |
| seed     | DataBlob             | 是   | 设置的种子   |
| callback | AsyncCallback\<void\> | 是   | 回调函数 |

**示例：**

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

设置指定的种子

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| seed   | DataBlob | 是   | 设置的种子 |

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

加解密参数，在进行对称加解密时需要构造其子类对象，并将子类对象传入[init()](#init-2)方法。适用于需要iv等参数的对称加解密模式（对于无iv等参数的模式如ECB模式，不需要构造其子类对象）。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 描述                   |
| ------- | ------ | ---- | ---- | ---------------------- |
| algoName | string | 是   | 是   | 指明对称加解密参数的算法模式。可选值如下:<br/>- "IvParamsSpec": 适用于CBC\|CTR\|OFB\|CFB模式<br/>- "GcmParamsSpec": 适用于GCM模式<br/>- "CcmParamsSpec": 适用于CCM模式 |

## IvParamsSpec

适用于CBC、CTR、OFB、CFB模式，仅使用iv的加解密参数，在对称加解密时构造并传入[init()](#init-2)方法作为参数。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 描述                   |
| ------- | ------ | ---- | ---- | ---------------------- |
| iv | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数iv。常见取值如下：<br/>- AES的CBC\|CTR\|OFB\|CFB模式：iv长度为16字节<br/>- 3DES的CBC\|OFB\|CFB模式：iv长度为8字节|

## GcmParamsSpec

适用于GCM模式的加解密参数，在对称加解密时构造并传入[init()](#init-2)方法作为参数。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 描述                   |
| ------- | ------ | ---- | ---- | ---------------------- |
| iv | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数iv，长度为12字节|
| aad | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数aad，长度为8字节|
| authTag | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数authTag，长度为16字节。<br/>采用GCM模式加密时，需要获取[doFinal()](#dofinal-2)输出的[DataBlob](#datablob)，将其末尾16字节作为解密时[GcmParamsSpec](#gcmparamsspec)中的authTag |

## CcmParamsSpec

适用于CCM模式的加解密参数，在对称加解密时构造并传入[init()](#init-2)方法作为参数。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型     | 可读 | 可写 | 描述                                                         |
| ------- | -------- | ---- | ---- | -------------------------------|
| iv      | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数iv，长度为7字节                                |
| aad     | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数aad，长度为8字节                               |
| authTag | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数authTag，长度为12字节。<br/>采用CCM模式加密时，需要获取[doFinal()](#dofinal-2)输出的[DataBlob](#datablob)，将其末尾12字节作为解密时[CcmParamsSpec](#ccmparamsspec)中的authTag |

## CryptoMode

表示加解密操作的枚举。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称         | 值        | 描述                             |
| ------------ | -------- | -------------------------------- |
| ENCRYPT_MODE | 0        | 表示进行加密操作                    |
| DECRYPT_MODE | 1        | 表示进行解密操作                    |

## Key

密钥（父类），在运行密码算法（如加解密）时需要提前生成其子类对象，并传入[Cipher](#cipher)实例的[init()](#init-2)方法。密钥可以通过密钥生成器来生成。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework 

| 名称    | 类型   | 可读 | 可写 | 描述                   |
| ------- | ------ | ---- | ---- | ---------------------- |
| format | string | 是   | 否   | 密钥的格式。|
| algName | string | 是   | 否   | 密钥对应的算法名（含长度）。|

### getEncoded

getEncoded() : DataBlob

以同步方法，获取16进制形式的密钥内容。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型   |描述                   |
| ------- | ----------- |
| [DataBlob](#datablob) | 用于查看密钥的具体内容。|

**示例：**

```js
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

let key;    // key为使用对称密钥生成器 生成的密钥，此处省略生成过程
let encodedKey = key.getEncoded();
console.info("key hex:" + uint8ArrayToShowStr(encodedKey.data));
```

## SymKey

对称密钥，是[Key](#key)的子类，在对称加解密时需要将其对象传入[Cipher](#cipher)实例的[init()](#init-2)方法使用。对称密钥可以通过对称密钥生成器[SymKeyGenerator](#symkeygenerator)来生成。

### clearMem

clearMem() : void

以同步方法，将系统底层内存中的的密钥内容清零。

**系统能力：** SystemCapability.Security.CryptoFramework

**示例：**

```js
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

let key;    // key为使用对称密钥生成器 生成的密钥，此处省略生成过程
let encodedKey = key.getEncoded();
console.info("key hex:" + uint8ArrayToShowStr(encodedKey.data));    // 输出密钥内容
key.clearMem();
encodedKey = key.getEncoded();
console.info("key hex:" + uint8ArrayToShowStr(encodedKey.data));    // 输出全零
```

## PubKey

公钥，是Key的子类，在非对称加解密、验签、密钥协商时需要将其对象作为输入使用。公钥可以通过非对称密钥生成器AsyKeyGenerator来生成。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework 

| 名称    | 类型   | 可读 | 可写 | 描述                   |
| ------- | ------ | ---- | ---- | ---------------------- |
| format | string | 是   | 否   | 密钥的格式。|
| algName | string | 是   | 否   | 密钥对应的算法名（含长度）。|


### getEncoded

getEncoded() : DataBlob

以同步方法，获取二进制形式的密钥内容。公钥格式满足ASN.1语法、X.509规范、DER编码格式。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型   |描述                   |
| ------- | ----------- |
| [DataBlob](#datablob) | 用于查看密钥的具体内容。|

**示例：**

```js
console.info("key format:" + key.format);
console.info("key algName:" + key.algName);
var encodedKey = key.getEncoded();
console.info("key encoded:" + Uint8ArrayToShowStr(encodedKey.data));
```

## PriKey

私钥，是Key的子类，在非对称加解密、签名、密钥协商时需要将其作为输入使用。私钥可以通过非对称密钥生成器AsyKeyGenerator来生成。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework 

| 名称    | 类型   | 可读 | 可写 | 描述                   |
| ------- | ------ | ---- | ---- | ---------------------- |
| format | string | 是   | 否   | 密钥的格式。|
| algName | string | 是   | 否   | 密钥对应的算法名（含长度）。|

### getEncoded

getEncoded() : DataBlob

以同步方法，获取二进制形式的密钥内容。私钥格式满足ASN.1语法，PKCS#8规范、DER编码方式。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型   |描述                   |
| ------- | ----------- |
| [DataBlob](#datablob) | 用于查看密钥的具体内容。|

**示例：**

```js
console.info("key format:" + key.format);
console.info("key algName:" + key.algName);
var encodedKey = key.getEncoded();
console.info("key encoded:" + Uint8ArrayToShowStr(encodedKey.data));
```

### clearMem

clearMem() : void

以同步方法，将系统底层内存中的的密钥内容清零。

**系统能力：** SystemCapability.Security.CryptoFramework

**示例：**

```js
key.clearMem();
```

## cryptoFramework.createSymKeyGenerator

createSymKeyGenerator(algName : string) : SymKeyGenerator

通过指定算法名称的字符串，获取相应的对称密钥生成器实例。支持的对称密钥参数详见框架概述“[密钥生成规格](../../security/cryptoFramework-overview.md#密钥生成规格)”一节中“生成密钥的字符串”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                             |
| ------- | ------ | ---- | ----------------------------- |
| algName | string | 是   | 待生成对称密钥生成器的算法名称。 |

**返回值：**

| 类型            | 说明                       |
| ----------------------------------- | -------------------------- |
| [SymKeyGenerator](#symkeygenerator) | 返回对称密钥生成器的对象。 |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
```

## SymKeyGenerator

对称密钥生成器。在使用该类的方法前，需要先使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)方法构建一个symKeyGenerator实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 描述                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | 是   | 否   | 对称密钥生成器指定的算法名称。 |

### generateSymKey

generateSymKey(callback : AsyncCallback\<SymKey>) : void

异步获取对称密钥生成器随机生成的密钥，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称     | 类型               | 必填 | 说明                 |
| -------- | ----------------- | ---- | ------------------- |
| callback | AsyncCallback\<[SymKey](#symkey)> | 是  | 回调函数，用于获取对称密钥。 |

**示例：**

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

异步获取该对称密钥生成器随机生成的密钥，通过Promise获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise\<[SymKey](#symkey)> | 使用Promise的方式获取对称密钥。 |

**示例：**

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

异步获取指定数据生成对称密钥，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称     | 类型                | 必填 | 说明                  |
| -------- | ----------------- | ---- | ---------------------- |
| key      | [DataBlob](#datablob)  | 是   | 指定的对称密钥材料。         |
| callback | AsyncCallback\<[SymKey](#symkey)> | 是   | 回调函数，用于获取对称密钥。 |

**示例：**

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

异步获取指定数据生成对称密钥，通过Promise获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称 | 类型     | 必填 | 说明                 |
| ---- | -------- | ---- | -------------------- |
| key  | [DataBlob](#datablob) | 是   | 指定的密钥材料数据。 |

**返回值：**

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise\<[SymKey](#symkey)> | 使用Promise的方式获取对称密钥。 |

**示例：**

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
通过指定算法名称的字符串，获取相应的非对称密钥生成器实例。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                             |
| ------- | ------ | ---- | -------------------------------- |
| algName | string | 是   | 待生成对称密钥生成器的算法名称。 |

**返回值：**

| 类型            | 说明                       |
| --------------- | -------------------------- |
| asyKeyGenerator | 返回非对称密钥生成器的对象。 |

**示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
```

## AsyKeyGenerator

非对称密钥生成器。在使用该类的方法前，需要先使用createAsyKeyGenerator()方法构建一个AsyKeyGenerator实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称           | 类型           | 可读 | 可写 | 描述                              |
| -------------- | -------------- | ---- | ---- | ----------------------------------|
| algName        | string         | 是   | 否   | 非对称密钥生成器指定的算法名称。  |



### generateKeyPair

generateKeyPair(callback : AsyncCallback\<KeyPair>) : void;
异步获取非对称密钥生成器随机生成的密钥，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称     | 类型                       | 必填 | 说明                         |
| -------- | -------------------------- | ---- | ---------------------------- |
| callback | AsyncCallback\<KeyPair> | 是   | 回调函数，用于获取非对称密钥。 |

**示例：**

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
异步获取该非对称密钥生成器随机生成的密钥，通过Promise获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise\<KeyPair> | 使用Promise的方式获取非对称密钥。 |

**示例：**

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
异步获取指定数据生成非对称密钥，通过注册回调函数获取结果。详情请看下方**密钥转换说明**

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称     | 类型                       | 必填 | 说明                         |
| -------- | -------------------------- | ---- | ---------------------------- |
| pubKey      | DataBlob                   | 否   | 指定的公钥材料。         |
| priKey      | DataBlob                   | 否   | 指定的私钥材料。         |
| callback | AsyncCallback\<KeyPair> | 是   | 回调函数，用于获取非对称密钥。 |

**示例：**

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
异步获取指定数据生成非对称密钥，通过Promise获取结果。详情请看下方**密钥转换说明**

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称 | 类型     | 必填 | 说明                 |
| ---- | -------- | ---- | -------------------- |
| pubKey      | DataBlob                   | 否   | 指定的公钥材料。         |
| priKey      | DataBlob                   | 否   | 指定的私钥材料。         |

**返回值：**

| 类型                  | 说明                            |
| --------------------- | ------------------------------- |
| Promise\<KeyPair> | 使用Promise的方式获取非对称密钥。 |

**示例：**

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

**密钥转换说明**

1. 非对称密钥（RSA、ECC）的公钥和私钥调用getEncoded()方法后，分别返回X.509格式和PKCS#8格式的二进制数据，此数据可用于跨应用传输或持久化存储。
2. 当调用convertKey方法将外来二进制数据转换为算法库非对称密钥对象时，公钥应满足ASN.1语法、X.509规范、DER编码格式，私钥应满足ASN.1语法、PKCS#8规范、DER编码格式。
3. convertKey方法中，公钥和密钥二进制数据非必选项，可单独传入公钥或私钥的数据，生成对应只包含公钥或私钥的KeyPair对象。

## cryptoFramework.createCipher

createCipher(transformation : string) : Cipher
通过指定算法名称，获取相应的[Cipher](#cipher)实例。支持的算法名参数详见框架概述“[加解密规格](../../security/cryptoFramework-overview.md#加解密规格)”一节中的“指定算法名称字符串”。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名         | 类型   |  必填  |  说明                                                         |
| -------------- | ------ | -------- | ------------------------------------------------------------ |
| transformation | string | 是   | 待生成Cipher的算法名称、加密模式以及填充方法的组合。输入可以为"RSA1024\|PKCS1", "RSA1024\|PKCS1_OAEP\|SHA256\|SHA256"等 |

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| [Cipher](#cipher) | 返回加解密生成器的对象。 |

**示例：**

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

提供加解密的算法操作功能，按序调用本类中的[init()](#init-2)、[update()](#update-4)、[doFinal()](#dofinal-2)方法，可以实现对称加密/对称解密/非对称加密/非对称解密。完整的加解密流程示例可参考开发指导中的“[使用加解密操作](../../security/cryptoFramework-guidelines.md#使用加解密操作)”一节。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework


| 名称    | 类型   | 可读  | 可写  | 描述                         |
| ------- | ------ | -------- | ----------- | ---------------------------- |
| algName | string | 是   | 否   | 加解密生成器指定的算法名称。 |

### init

init(opMode : CryptoMode, key : Key, params : ParamsSpec, callback : AsyncCallback\<void>) : void

初始化加解密的[cipher](#cipher)对象，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称     | 类型                     | 必填    | 说明                     |
| -------- | ------------------------ | ------- | ------------------------ |
| opMode   | [CryptoMode](#cryptomode)      | 是   | 加密或者解密模式。       |
| key      | [Key](#key)           | 是   | 指定加密或解密的密钥。   |
| params   | [ParamsSpec](#paramsspec)               | 是   | 指定加密或解密的参数。   |
| callback | AsyncCallback\<void> | 是   | 回调函数。 |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKey;     // 此处省略生成对称密钥的过程
let cipher;         // 此处省略生成cipher实例的过程
cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null, (err, ) => {
  if (err) {
    console.error('Failed to init cipher');
    return;
  }
  console.log('Init cipher success');
  // 此处进行update等后续操作
})
```

### init

init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>

初始化加解密的cipher对象，通过Promise获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称   | 类型       | 必填 | 说明                   |
| ------ | ---------- | ---- | ---------------------- |
| opMode |  [CryptoMode](#cryptomode)  | 是   | 加密或者解密模式。     |
| key    |  [Key](#key)       | 是   | 指定加密或解密的密钥。 |
| params | [ParamsSpec](#paramsspec) | 是   | 指定加密或解密的参数，对于ECB等没有参数的算法模式，可以传入null。 |

**返回值：**

| 类型                | 说明                        |
| ------------------- | --------------------------- |
| Promise\<void> | 使用Promise的方式获取结果。 |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKey;     // 此处省略生成对称密钥的过程
let cipher;         // 此处省略生成cipher实例的过程
cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null).then(() => {
  console.log('Init cipher success');
  // 此处进行update等后续操作
})
```

### update

update(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

分段更新加密或者解密数据操作，通过注册回调函数获取加密或者解密数据。（根据数据量，可不调用update或调用多次update）

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称     | 类型                         | 必填 | 说明                                       |
| -------- | ---------------------------- | ---- | ------------------------------------------ |
| data     | [DataBlob](#datablob)                  | 是   | 加密或者解密的数据。                       |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数，用于获取加密或者解密的数据结果。 |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let cipher;         // 此处省略生成cipher实例的过程
// 此处省略init()过程
let plainText = {data : stringToUint8Array('this is test!')};
cipher.update(plainText, (err, output) => {       // 加密过程举例
  if (err) {
    console.error('Failed to update cipher');
    return;
  }
  console.log('Update cipher success');
  // 此处进行doFinal等后续操作
})
```

### update

update(data : DataBlob) : Promise\<DataBlob>

分段更新加密或者解密数据操作，通过Promise获取结果。（根据数据量，可不调用update或调用多次update）

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称 | 类型     | 必填 | 说明                 |
| ---- | -------- | ---- | -------------------- |
| data |  [DataBlob](#datablob) | 是   | 加密或者解密的数据。 |

**返回值：**

| 类型                    | 说明                        |
| ----------------------- | --------------------------- |
| Promise\<[DataBlob](#datablob)> | 使用Promise的方式获取结果。 |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

function stringToUint8Array(str) {
  let arr = [];
  for (let i = 0, j = str.length; i < j; ++i) {
    arr.push(str.charCodeAt(i));
  }
  return new Uint8Array(arr);
}

let cipher;         // 此处省略生成cipher实例的过程
// 此处省略init()过程
let plainText = {data : stringToUint8Array('this is test!')};
cipher.update(data).then((output) => {
  console.log('Update cipher success');
  // 此处进行doFinal等后续操作
})
```

### doFinal

doFinal(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

最后结束加密或者解密数据操作，通过注册回调函数获取加密或者解密数据。如果在本次加解密过程中已经使用[update](#update-4)传入过数据，可以在doFinal的data参数处传入null。<br/>根据对称加解密的模式不同，doFinal的输出可能不同：<br/>对于GCM和CCM模式的对称加密，doFinal的结果是剩余密文和authTag的拼接，即末尾的16字节（GCM模式）或12字节（CCM模式）是authTag（因此如果doFinal的data参数传入null，则doFinal的结果就是authTag）。在doFinal完成后需要将authTag暂存，填入解密时的[GcmParamsSpec](#gcmparamsspec)或[CcmParamsSpec](#ccmparamsspec)。<br/>对于其他模式的对称加解密，根据不同的模式特点，存在两种情况（1）update输出一部分加解密结果，doFinal输出剩余加解密结果；（2）加解密结果全部由update输出，doFinal输出空。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称     | 类型                         | 必填 | 说明                                       |
| -------- | ---------------------------- | ---- | ------------------------------------------ |
| data     |  [DataBlob](#datablob)                     | 是   | 加密或者解密的数据。                       |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数，用于获取加密或者解密的数据结果。 |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let cipher;         // 此处省略生成cipher实例的过程
let data;           // 此处省略准备待加密/解密数据的过程
// 此处省略init()和update()过程
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

最后结束加密或者解密数据操作，通过Promise获取结果。如果在本次加解密过程中已经使用[update](#update-4)传入过数据，可以在doFinal的data参数处传入null。<br/>根据对称加解密的模式不同，doFinal的输出可能不同：<br/>对于GCM和CCM模式的对称加密，doFinal的结果是剩余密文和authTag的拼接，即末尾的16字节（GCM模式）或12字节（CCM模式）是authTag（因此如果doFinal的data参数传入null，则doFinal的结果就是authTag）。在doFinal完成后需要将authTag暂存，填入解密时的[GcmParamsSpec](#gcmparamsspec)或[CcmParamsSpec](#ccmparamsspec)。<br/>对于其他模式的对称加解密，根据不同的模式特点，存在两种情况（1）update输出一部分加解密结果，doFinal输出剩余加解密结果；（2）加解密结果全部由update输出，doFinal输出空。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 名称 | 类型     | 必填 | 说明                 |
| ---- | -------- | ---- | -------------------- |
| data | [DataBlob](#datablob) | 是   | 加密或者解密的数据。 |

**返回值：**

| 类型                    | 说明                        |
| ----------------------- | --------------------------- |
| Promise\<[DataBlob](#datablob)> | 使用Promise的方式获取结果。 |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let cipher;         // 此处省略生成cipher实例的过程
let data;           // 此处省略准备待加密/解密数据的过程
// 此处省略init()和update()过程
cipher.doFinal(data).then((output) => {
    console.log('Final cipher success');
})
```

**callback示例：**

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

**promise示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let rsaGenerator = cryptoFramework.createAsyKeyGenerator("RSA1024|PRIMES_2");
let cipher = cryptoFramework.createCipher("RSA1024|PKCS1");
let keyGenPromise = rsaGenerator.generateKeyPair();
keyGenPromise.then(rsaKeyPair => {
  let pubKey = rsaKeyPair.pubKey;
  return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null); // 传入私钥和DECRYPT_MODE可初始化解密模式
}).then(() => {
  let input = { data : stringToUint8Array(plan) };
  return cipher.doFinal(input);
}).then(dataBlob => {
  console.info("EncryptOutPut is " + dataBlob.data);
});
```


## cryptoFramework.createSign

createSign(algName : string) : Sign

Sign实例生成

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 指定签名算法：RSA或ECC，使用RSA PKCS1模式时需要设置摘要，使用RSA PSS模式时需要设置摘要和掩码摘要 |

**返回值**：

| 类型 | 说明                           |
| ---- | ------------------------------ |
| Sign   | 返回由输入算法指定生成的Sign对象 |

**示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let signer1 = cryptoFramework.createSign("RSA1024|PKCS1|SHA256");

let singer2 = cryptoFramework.createSign("RSA1024|PKCS1_OAEP|SHA256|MGF1_SHA256")
```

## Sign

Sign类，使用Sign方法之前需要创建该类的实例进行操作，通过createSign(algName : string) : Sign方法构造此实例。

### init

init(priKey : PriKey, callback : AsyncCallback\<void>) : void

使用私钥初始化Sign对象，Callback形式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| priKey   | Key |是| 用于Sign的初始化 |
| callback | AsyncCallback\<void> | 是   | 回调函数的 |

### init

init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>

使用私钥初始化Sign对象，Promise形式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| priKey   | Key |是| 用于Sign的初始化 |

**返回值：**

| 类型          | 说明        |
| ------------- | ----------- |
| Promise\<void> | Promise对象 |

### update

update(data : DataBlob, callback : AsyncCallback\<void>) : void

追加待签名数据，callback方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| data    | DataBlob              | 是   | 传入的消息         |
| callback | AsyncCallback\<void> | 是   | 回调函数 |

### update

update(data : DataBlob) : Promise\<void>;

追加待签名数据，promise方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| data  | DataBlob | 是   | 传入的消息 |

**返回值：**

| 类型          | 说明        |
| ------------- | ----------- |
| Promise\<void> | Promise对象 |

### sign

sign(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

对数据进行签名，返回签名结果，callback方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| data    | DataBlob              | 是   | 传入的消息         |
| callback | AsyncCallback\<void> | 是   | 回调函数 |

### sign

sign(data : DataBlob) : Promise\<DataBlob>

对数据进行签名，返回签名结果，promise方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| data  | DataBlob | 是   | 传入的消息 |

**返回值：**

| 类型          | 说明        |
| ------------- | ----------- |
| Promise\<void> | Promise对象 |

**callback示例：**
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

**promise示例：**
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

Verify实例生成

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 指定签名算法：RSA或ECC，使用RSA PKCS1模式时需要设置摘要，使用RSA PSS模式时需要设置摘要和掩码摘要 |

**返回值**：

| 类型 | 说明                           |
| ---- | ------------------------------ |
| Verify   | 返回由输入算法指定生成的Verify对象 |

**示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let verifyer1 = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");

let verifyer2 = cryptoFramework.createVerify("RSA1024|PKCS1_OAEP|SHA256|MGF1_SHA256")
```
## Verify

Verify类，使用Verify方法之前需要创建该类的实例进行操作，通过createVerify(algName : string) : Verify方法构造此实例。

### init

init(pubKey : PubKey, callback : AsyncCallback\<void>) : void

传入私钥初始化Verify对象，Callback形式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| pubKey   | Key |是| 公钥对象，用于Verify的初始化 |
| callback | AsyncCallback\<void> | 是   | 回调函数 |

### init
init(pubKey : PubKey) : Promise\<void>

传入私钥初始化Verify对象，Promise形式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| pubKey   | Key |是|公钥对象，用于Verify的初始化 |

**返回值：**

| 类型            | 说明         |
| --------------- | ------------ |
| Promise\<void> | Promise对象 |

### update

update(data : DataBlob, callback : AsyncCallback\<void>) : void

追加待验签数据，callback方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| data    | DataBlob              | 是   | 传入的消息         |
| callback | AsyncCallback\<void> | 是   | 回调函数 |

### update

update(data : DataBlob) : Promise\<void>;

追加待验签数据，promise方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| data  | DataBlob | 是   | 传入的消息 |

**返回值：**

| 类型          | 说明        |
| ------------- | ----------- |
| Promise\<void> | Promise对象 |

### verify

verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback\<boolean>) : void

对数据进行签名，返回签名结果，callback方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| data    | DataBlob              | 是   | 传入的消息         |
| signatureData    | DataBlob              | 是   | 签名数据        |
| callback | AsyncCallback\<void> | 是   | 回调函数 |

### verify

verify(data : DataBlob, signatureData : DataBlob) : Promise\<boolean>

对数据进行签名，返回签名结果，promise方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| data  | DataBlob | 是   | 传入的消息 |
| signatureData    | DataBlob| 是 | 签名数据 |

**返回值：**

| 类型            | 说明         |
| --------------- | ------------ |
| Promise\<boolean> | 异步返回值，代表验签是否通过|

**callback示例：**
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

**promise示例：**
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

KeyAgreement实例生成

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 指定密钥协商算法：目前仅支持ECC |

**返回值**：

| 类型 | 说明                           |
| ---- | ------------------------------ |
| KeyAgreement   | 返回由输入算法指定生成的KeyAgreement对象 |

**示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let keyAgreement = cryptoFramework.createKeyAgreement("ECC256");

```

## KeyAgreement

KeyAgreement类，使用密钥协商方法之前需要创建该类的实例进行操作，通过createKeyAgreement(algName : string) : KeyAgreement方法构造此实例。

### generateSecret

generateSecret(priKey : PriKey, pubKey : PubKey, callback : AsyncCallback\<DataBlob>) : void

基于传入的私钥与公钥进行密钥协商，返回共享秘密，Callback形式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| priKey   | PriKey |是| 设置密钥协商的私钥输入 |
| pubKey   | PubKey |是| 设置密钥协商的公钥输入 |
| callback | AsyncCallback\<DataBlob> | 是   | 异步接受共享秘密的回调 |

### generateSecret
generateSecret(priKey : PriKey, pubKey : PubKey) : Promise\<DataBlob>

基于传入的私钥与公钥进行密钥协商，返回共享秘密，Promise形式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| priKey   | PriKey |是| 设置密钥协商的私钥输入 |
| pubKey   | PubKey |是| 设置密钥协商的公钥输入 |

**返回值：**

| 类型            | 说明         |
| --------------- | ------------ |
| Promise\<DataBlob> | 共享秘密 |

**callback示例：**
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

**promise示例：**
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
## cryptoFramework.createX509Cert

createX509Cert(inStream : EncodingBlob, callback : AsyncCallback\<X509Cert>) : void

表示创建X509证书对象。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明               |
| -------- | ------------- | ---- | ------------------ |
| inStream | [EncodingBlob](#encodingblob)  | 是   | X509证书序列化数据 |
| callback | AsyncCallback\<X509Cert> | 否   | 回调函数。表示X509证书对象           |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
    }
});
```

## cryptoFramework.createX509Cert

createX509Cert(inStream : EncodingBlob) : Promise\<X509Cert>

表示创建X509证书对象。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型         | 必填 | 说明               |
| -------- | ------------ | ---- | ------------------ |
| inStream | [EncodingBlob](#encodingblob) | 是   | X509证书序列化数据 |

**返回值**：

| 类型     | 说明             |
| :------- | ---------------- |
| X509Cert | 表示X509证书对象 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob).then(x509Cert => {
    Console.log("createX509Cert success");
}, error => {
    Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

## X509Cert

X509证书类。

### verify

verify(key : PubKey, callback : AsyncCallback\<void>) : void

表示对证书验签。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明               |
| -------- | ------------- | ---- | ------------------ |
| key      | [PubKey](#pubkey)        | 是   | 用于验签的公钥对象 |
| callback | AsyncCallback\<void>) | 否   | 回调函数。使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，不为null表示失败           |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        // 业务需通过AsyKeyGenerator生成PubKey或通过上级X509Cert证书对象的getPublicKey获取PubKey
		let pubKey = null;
        x509Cert.verify(pubKey, function (error, data) {
            if (error != null) {
                Console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                Console.log("verify success");
            }
        });
    }
});
```

### verify

verify(key : PubKey) : Promise\<void>

表示对证书验签。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| key    | [PubKey](#pubkey) | 是   | 用于验签的公钥对象 |

**返回值**：

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob).then(x509Cert => {
    Console.log("createX509Cert success");
    // 业务需通过AsyKeyGenerator生成PubKey或通过上级X509Cert证书对象的getPublicKey获取PubKey
	let pubKey = null;
    x509Cert.verify(pubKey).then(result => {
        Console.log("verify success");
    }, error => {
        Console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取X509证书序列化数据。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明     |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 否   | 回调函数。表示X509证书序列化数据 |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        x509Cert.getEncoded(function (error, data) {
           if (error != null) {
               Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("getEncoded success");
           }
        });
    }
});
```

### getEncoded

getEncoded() : Promise\<EncodingBlob>

表示获取X509证书序列化数据。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型         | 说明                   |
| ------------ | ---------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示X509证书序列化数据 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob).then(x509Cert => {
    Console.log("createX509Cert success");
    x509Cert.getEncoded().then(result => {
        Console.log("getEncoded success");
    }, error => {
        Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getPublicKey

getPublicKey(callback : AsyncCallback\<PubKey>) : void

表示获取X509证书公钥。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明     |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback | 否   | 回调函数，X509证书公钥对象 |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        x509Cert.getPublicKey(function (error, pubKey) {
           if (error != null) {
               Console.log("getPublicKey failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("getPublicKey success");
           }
        });
    }
});
```

### getPublicKey

getPublicKey() : Promise\<PubKey>

表示获取X509证书公钥。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| PubKey | X509证书公钥对象 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob).then(x509Cert => {
    Console.log("createX509Cert success");
    x509Cert.getPublicKey().then(pubKey => {
        Console.log("getPublicKey success");
    }, error => {
        Console.log("getPublicKey failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### checkValidityWithDate

checkValidityWithDate(date: string, callback : AsyncCallback\<void>) : void

表示检查X509证书有效期。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明     |
| -------- | ------------- | ---- | -------- |
| date     | string        | 是   | 日期     |
| callback | AsyncCallback\<void> | 否   | 回调函数。使用AsyncCallback的第一个error参数判断是否检查成功，error为null表示成功，不为null表示失败 |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let date = "150527000001Z";
        x509Cert.checkValidityWithDate(date, function (error, data) {
           if (error != null) {
               Console.log("checkValidityWithDate failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("checkValidityWithDate success");
           }
        });
    }
});
```

### checkValidityWithDate

checkValidityWithDate(date: string) : Promise\<void>

表示检查X509证书有效期。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名 | 类型   | 必填 | 说明 |
| ------ | ------ | ---- | ---- |
| date   | string | 是   | 日期 |

**返回值**：

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| void | 使用AsyncCallback的第一个error参数判断是否检查成功，error为null表示成功，不为null表示失败 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob).then(x509Cert => {
    Console.log("createX509Cert success");
    let date = "150527000001Z";
    x509Cert.checkValidityWithDate(date).then(result => {
        Console.log("checkValidityWithDate success");
    }, error => {
        Console.log("checkValidityWithDate failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getVersion

getVersion() : number

表示获取X509证书版本。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明             |
| ------ | ---------------- |
| number | 表示X509证书版本 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let version = x509Cert.getVersion();
    }
});
```

### getSerialNumber

getSerialNumber() : number

表示获取X509证书序列号。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明               |
| ------ | ------------------ |
| number | 表示X509证书序列号 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let serialNumber = x509Cert.getSerialNumber();
    }
});
```

### getIssuerName

getIssuerName() : DataBlob

表示获取X509证书颁发者名称。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型     | 说明                   |
| -------- | ---------------------- |
| [DataBlob](#datablob) | 表示X509证书颁发者名称 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let issuerName = x509Cert.getIssuerName();
    }
});
```

### getSubjectName

getSubjectName() : DataBlob

表示获取X509证书主体名称。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型     | 说明                 |
| -------- | -------------------- |
| [DataBlob](#datablob) | 表示X509证书主体名称 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let subjectName = x509Cert.getSubjectName();
    }
});
```

### getNotBeforeTime

getNotBeforeTime() : string

表示获取X509证书有效期起始时间。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                       |
| ------ | -------------------------- |
| string | 表示X509证书有效期起始时间 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let notBefore = x509Cert.getNotBeforeTime();
    }
});
```

### getNotAfterTime

getNotAfterTime() : string

表示获取X509证书有效期截止时间。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                       |
| ------ | -------------------------- |
| string | 表示X509证书有效期截止时间 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let notAfter = x509Cert.getNotAfterTime();
    }
});
```

### getSignature

getSignature() : DataBlob

表示获取X509证书签名数据。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型     | 说明                 |
| -------- | -------------------- |
| [DataBlob](#datablob) | 表示X509证书签名数据 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let signature = x509Cert.getSignature();
    }
});
```

### getSignatureAlgName

getSignatureAlgName() : string

表示获取X509证书签名算法名称。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 表示X509证书签名算法名称 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let sigAlgName = x509Cert.getSignatureAlgName();
    }
});
```

### getSignatureAlgOid

getSignatureAlgOid() : string

表示获取X509证书签名算法的对象标志符OID(Object Identifier)。OID是由国际标准组织(ISO)的名称注册机构分配。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                              |
| ------ | --------------------------------- |
| string | 表示X509证书签名算法对象标志符OID |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let sigAlgOid = x509Cert.getSignatureAlgOid();
    }
});
```

### getSignatureAlgParams

getSignatureAlgParams() : DataBlob

表示获取X509证书签名算法参数。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型     | 说明                     |
| -------- | ------------------------ |
| [DataBlob](#datablob) | 表示X509证书签名算法参数 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let sigAlgParams = x509Cert.getSignatureAlgParams();
    }
});
```

### getKeyUsage

getKeyUsage() : DataBlob

表示获取X509证书秘钥用途。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型     | 说明                 |
| -------- | -------------------- |
| [DataBlob](#datablob) | 表示X509证书秘钥用途 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let keyUsage = x509Cert.getKeyUsage();
    }
});
```

### getExtKeyUsage

getExtKeyUsage() : DataArray

表示获取X509证书扩展秘钥用途。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型      | 说明                     |
| --------- | ------------------------ |
| [DataArray](#dataarray) | 表示X509证书扩展秘钥用途 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let extKeyUsage = x509Cert.getExtKeyUsage();
    }
});
```

### getBasicConstraints

getBasicConstraints() : number

表示获取X509证书基本约束。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 表示X509证书基本约束 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let basicConstraints = x509Cert.getBasicConstraints();
    }
});
```

### getSubjectAltNames

getSubjectAltNames() : DataArray

表示获取X509证书主体可选名称。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型      | 说明                     |
| --------- | ------------------------ |
| [DataArray](#dataarray) | 表示X509证书主体可选名称 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let subjectAltNames = x509Cert.getSubjectAltNames();
    }
});
```

### getIssuerAltNames

getIssuerAltNames() : DataArray

表示获取X509证书颁发者可选名称。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型      | 说明                       |
| --------- | -------------------------- |
| [DataArray](#dataarray) | 表示X509证书颁发者可选名称 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Cert(encodingBlob, function (error, x509Cert) {
    if (error != null) {
        Console.log("createX509Cert failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Cert success");
        let issuerAltNames = x509Cert.getIssuerAltNames();
    }
});
```

## cryptoFramework.createX509Crl

createX509Crl(inStream : EncodingBlob, callback : AsyncCallback\<X509Crl>) : void

表示创建X509证书吊销列表的对象。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明                       |
| -------- | ------------- | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob)  | 是   | 表示证书吊销列表序列化数据 |
| callback | AsyncCallback\<X509Crl> | 否   | 回调函数。表示证书吊销列表对象                   |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
    }
});
```

## cryptoFramework.createX509Crl

createX509Crl(inStream : EncodingBlob) : Promise\<X509Crl>

表示创建X509证书吊销列表的对象。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型         | 必填 | 说明                       |
| -------- | ------------ | ---- | -------------------------- |
| inStream | [EncodingBlob](#encodingblob) | 是   | 表示证书吊销列表序列化数据 |

**返回值**：

| 类型    | 说明                 |
| ------- | -------------------- |
| Promise\<X509Crl> | 表示证书吊销列表对象 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob).then(x509Crl => {
    Console.log("createX509Crl success");
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

## X509Crl

X509证书吊销列表对象。

### isRevoked

isRevoked(cert : X509Cert, callback : AsyncCallback\<boolean>) : void

表示检查证书是否吊销。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明                 |
| -------- | ------------- | ---- | -------------------- |
| cert     | [X509Cert](#x509cert)      | 是   | 表示被检查的证书对象 |
| callback | AsyncCallback\<boolean> | 否   | 回调函数。表示证书吊销状态，true表示已吊销，false表示未吊销             |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        // 业务需自行生成X509Cert证书对象
        let x509Cert = null;
        x509Crl.isRevoked(x509Cert, function (error, isRevoked) {
           if (error != null) {
               Console.log("call isRevoked failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("call isRevoked success");
           }
        });
    }
});
```

### isRevoked

isRevoked(cert : X509Cert) : Promise\<boolean>

表示检查证书是否吊销。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名 | 类型     | 必填 | 说明                 |
| ------ | -------- | ---- | -------------------- |
| cert   | X509Cert | 是   | 表示被检查的证书对象 |

**返回值**：

| 类型    | 说明                                              |
| ------- | ------------------------------------------------- |
| Promise\<boolean> | 表示证书吊销状态，true表示已吊销，false表示未吊销 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob).then(x509Crl => {
    Console.log("createX509Crl success");
    // 业务需自行生成X509Cert证书对象
    let x509Cert = null;
    x509Crl.isRevoked(x509Cert).then(isRevoked => {
        Console.log("call isRevoked success");
    }, error => {
        Console.log("call isRevoked failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getType

getType() : string

表示获取证书吊销列表类型。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 表示证书吊销列表类型 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let type = x509Crl.getType();
    }
});
```

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取X509证书吊销列表的序列化数据。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明     |
| -------- | ------------- | ---- | -------- |
| callback |  AsyncCallback\<EncodingBlob> | 否   | 回调函数，表示X509证书吊销列表的序列化数据 |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        x509Crl.getEncoded(function (error, data) {
           if (error != null) {
               Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("getEncoded success");
           }
        });
    }
});
```

### getEncoded

getEncoded() : Promise\<EncodingBlob>

表示获取X509证书吊销列表的序列化数据。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型         | 说明                             |
| ------------ | -------------------------------- |
| Promise\<EncodingBlob> | 表示X509证书吊销列表的序列化数据 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob).then(x509Crl => {
    Console.log("createX509Crl success");
    x509Crl.getEncoded().then(result => {
        Console.log("getEncoded success");
    }, error => {
        Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### verify

verify(key : PubKey, callback : AsyncCallback\<void>) : void

表示对X509证书吊销列表进行验签。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明                   |
| -------- | ------------- | ---- | ---------------------- |
| key      | PubKey        | 是   | 表示用于验签的公钥对象 |
| callback | AsyncCallback\<void> | 否   | 回调函数,使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，error不为null表示失败。       |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        // 业务需通过AsyKeyGenerator生成PubKey
        let pubKey = null;
        x509Crl.verify(pubKey, function (error, data) {
           if (error != null) {
               Console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
           } else {
               Console.log("verify success");
           }
        });
    }
});
```

### verify

verify(key : PubKey) : Promise\<void>

表示对X509证书吊销列表进行验签。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| key    | [PubKey](#pubkey) | 是   | 表示用于验签的公钥对象 |

**返回值**：

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | 使用AsyncCallback的第一个error参数判断是否验签成功，error为null表示成功，error不为null表示失败 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob).then(x509Crl => {
    Console.log("createX509Crl success");
    // 业务需通过AsyKeyGenerator生成PubKey
    let pubKey = null;
    x509Crl.verify(pubKey).then(result => {
        Console.log("verify success");
    }, error => {
        Console.log("verify failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getVersion

getVersion() : number

表示获取X509证书吊销列表的版本号。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| number | 表示获取X509证书吊销列表的版本号 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let version = x509Crl.getVersion();
    }
});
```

### getIssuerName

getIssuerName() : DataBlob

表示获取X509证书吊销列表颁发者名称。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型     | 说明                           |
| -------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表颁发者名称 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let issuerName = x509Crl.getIssuerName();
    }
});
```

### getLastUpdate

getLastUpdate() : string

表示获取X509证书吊销列表最后一次更新日期。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表最后一次更新日期 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let lastUpdate = x509Crl.getLastUpdate();
    }
});
```

### getNextUpdate

getNextUpdate() : string

表示获取证书吊销列表下一次更新的日期。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                                 |
| ------ | ------------------------------------ |
| string | 表示X509证书吊销列表下一次更新的日期 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let nextUpdate = x509Crl.getNextUpdate();
    }
});
```

### getRevokedCert

getRevokedCert(serialNumber : number, callback : AsyncCallback\<X509CrlEntry>) : void

表示通过指定证书序列号获取被吊销X509证书对象。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名       | 类型          | 必填 | 说明           |
| ------------ | ------------- | ---- | -------------- |
| serialNumber | number        | 是   | 表示证书序列号 |
| callback     | AsyncCallback\<X509CrlEntry> | 否   | 回调函数。表示被吊销X509证书对象       |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        // 业务需赋值为对应证书的序列号
        let serialNumber = 1000;
        x509Crl.getRevokedCert(serialNumber, function (error, entry) {
            if (error != null) {
                Console.log("getRevokedCert failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                Console.log("getRevokedCert success");
            }
        });
    }
});
```

### getRevokedCert

getRevokedCert(serialNumber : number) : Promise\<X509CrlEntry>

表示通过指定证书序列号获取被吊销X509证书对象。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名       | 类型   | 必填 | 说明           |
| ------------ | ------ | ---- | -------------- |
| serialNumber | number | 是   | 表示证书序列号 |

**返回值**:

| 类型         | 说明                   |
| ------------ | ---------------------- |
| Promise\<X509CrlEntry> | 表示被吊销X509证书对象 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob).then(x509Crl => {
    Console.log("createX509Crl success");
    // 业务需赋值为对应证书的序列号
    let serialNumber = 1000;
    x509Crl.getRevokedCert(serialNumber).then(entry => {
        Console.log("getRevokedCert success");
    }, error => {
        Console.log("getRevokedCert failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getRevokedCertWithCert

getRevokedCertWithCert(cert : X509Cert, callback : AsyncCallback\<X509CrlEntry>) : void

表示通过指定证书对象获取被吊销X509证书对象。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明         |
| -------- | ------------- | ---- | ------------ |
| cert     | X509Cert      | 是   | 表示证书对象 |
| callback | AsyncCallback\<X509CrlEntry> | 否   | 回调函数,表示被吊销X509证书对象    |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        // 业务需自行生成X509Cert证书对象
        let x509Cert = null;
        x509Crl.getRevokedCertWithCert(x509Cert, function (error, entry) {
            if (error != null) {
                Console.log("getRevokedCertWithCert failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                Console.log("getRevokedCertWithCert success");
            }
        });
    }
});
```

### getRevokedCertWithCert

getRevokedCertWithCert(cert : X509Cert) : Promise\<X509CrlEntry>

表示通过指定证书对象获取被吊销X509证书对象。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名 | 类型     | 必填 | 说明         |
| ------ | -------- | ---- | ------------ |
| cert   | X509Cert | 是   | 表示证书对象 |

**返回值**:

| 类型         | 说明                   |
| ------------ | ---------------------- |
| Promise\<X509CrlEntry> | 表示被吊销X509证书对象 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob).then(x509Crl => {
    Console.log("createX509Crl success");
    // 业务需自行生成X509Cert证书对象
    let x509Cert = null;
    x509Crl.getRevokedCertWithCert(x509Cert).then(entry => {
        Console.log("getRevokedCertWithCert success");
    }, error => {
        Console.log("getRevokedCertWithCert failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getRevokedCerts

getRevokedCerts(callback : AsyncCallback<Array\<X509CrlEntry>>) : void

表示获取被吊销X509证书列表。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明     |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback<Array\<X509CrlEntry>> | 否   | 回调函数。表示被吊销X509证书列表 |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        x509Crl.getRevokedCerts(function (error, array) {
            if (error != null) {
                Console.log("getRevokedCerts failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                Console.log("getRevokedCerts success");
            }
        });
    }
});
```

### getRevokedCerts

getRevokedCerts() : Promise<Array\<X509CrlEntry>>

表示获取被吊销X509证书列表。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**:

| 类型                | 说明                   |
| ------------------- | ---------------------- |
|Promise<Array\<X509CrlEntry>> | 表示被吊销X509证书列表 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob).then(x509Crl => {
    Console.log("createX509Crl success");
    x509Crl.getRevokedCerts().then(array => {
        Console.log("getRevokedCerts success");
    }, error => {
        Console.log("getRevokedCerts failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getTbsInfo

getTbsInfo(callback : AsyncCallback\<DataBlob>) : void

表示获取证书吊销列表的tbsCertList信息。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明     |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 否   | 回调函数。表示证书吊销列表的tbsCertList信息 |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        x509Crl.getTbsInfo(function (error, tbsInfo) {
            if (error != null) {
                Console.log("getTbsInfo failed, errCode: " + error.code + ", errMsg: " + error.message);
            } else {
                Console.log("getTbsInfo success");
            }
        });
    }
});
```

### getTbsInfo

getTbsInfo() : Promise\<DataBlob>

表示获取证书吊销列表的tbsCertList信息。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**:

| 类型     | 说明                              |
| -------- | --------------------------------- |
| Promise\<[DataBlob](#datablob)> | 表示证书吊销列表的tbsCertList信息 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob).then(x509Crl => {
    Console.log("createX509Crl success");
    x509Crl.getTbsInfo().then(tbsInfo => {
        Console.log("getTbsInfo success");
    }, error => {
        Console.log("getTbsInfo failed, errCode: " + error.code + ", errMsg: " + error.message);
    });
}, error => {
    Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getSignature

getSignature() : DataBlob

表示获取X509证书吊销列表的签名数据。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型     | 说明                           |
| -------- | ------------------------------ |
| [DataBlob](#datablob) | 表示X509证书吊销列表的签名数据 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let signature = x509Crl.getSignature();
    }
});
```

### getSignatureAlgName

getSignatureAlgName() : string

表示获取X509证书吊销列表签名的算法名称。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                             |
| ------ | -------------------------------- |
| string | 表示X509证书吊销列表签名的算法名 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let sigAlgName = x509Crl.getSignatureAlgName();
    }
});
```

### getSignatureAlgOid

getSignatureAlgOid() : string

表示获取X509证书吊销列表签名算法的对象标志符OID(Object Identifier)。OID是由国际标准组织(ISO)的名称注册机构分配。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                                          |
| ------ | --------------------------------------------- |
| string | 表示X509证书吊销列表签名算法的对象标志符OID。 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let sigAlgOid = x509Crl.getSignatureAlgOid();
    }
});
```

### getSignatureAlgParams

getSignatureAlgParams() : DataBlob

表示获取X509证书吊销列表签名的算法参数。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型     | 说明                               |
| -------- | ---------------------------------- |
| [DataBlob](#datablob) | 表示X509证书吊销列表签名的算法参数 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 证书吊销列表二进制数据，需业务自行赋值
let encodingData = null;
let encodingBlob = {
    data: encodingData,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM
};
cryptoFramework.createX509Crl(encodingBlob, function (error, x509Crl) {
    if (error != null) {
        Console.log("createX509Crl failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("createX509Crl success");
        let sigAlgParams = x509Crl.getSignatureAlgParams();
    }
});
```

## cryptoFramework.createCertChainValidator

createCertChainValidator(algorithm :string) : CertChainValidator

表示创建证书链校验器对象。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名    | 类型   | 必填 | 说明                                       |
| --------- | ------ | ---- | ------------------------------------------ |
| algorithm | string | 是   | 表示证书链校验器算法。当前仅支持输入“PKIX” |

**返回值**：

| 类型               | 说明                 |
| ------------------ | -------------------- |
| CertChainValidator | 表示证书链校验器对象 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let validator = cryptoFramework.createCertChainValidator("PKIX");
```

## CertChainValidator

证书链校验器对象。

### validate

validate(certChain : CertChainData, callback : AsyncCallback\<void>) : void

表示校验X509证书链。
由于端侧系统时间不可信，证书链校验不包含对证书有效时间的校验。如果需要检查证书的时间有效性，可使用X509证书的[checkValidityWithDate](#checkvaliditywithdate)方法进行检查。详见[证书规格](../../security/cryptoFramework-overview.md#证书规格)

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名    | 类型          | 必填 | 说明                     |
| --------- | ------------- | ---- | ------------------------ |
| certChain | [CertChainData](#certchaindata) | 是   | 表示X509证书链序列化数据 |
| callback  | AsyncCallback\<void> | 否   | 回调函数。使用AsyncCallback的第一个error参数判断是否校验成功，error为null表示成功，error不为null表示失败                 |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let validator = cryptoFramework.createCertChainValidator("PKIX");
// 证书链二进制数据，需业务自行赋值
let encodingData = null;
// 证书链包含的证书个数，需业务自行赋值
let certCount = 2;
let certChainData = {
    data: encodingData,
    count: certCount,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM 
};
validator.validate(certChainData, function (error, data) {
    if (error != null) {
        Console.log("validate failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("validate success");
    }
});
```

### validate

validate(certChain : CertChainData) : Promise\<void>

表示校验X509证书链。
由于端侧系统时间不可信，证书链校验不包含对证书有效时间的校验。如果需要检查证书的时间有效性，可使用X509证书的[checkValidityWithDate](#checkvaliditywithdate)方法进行检查。详见[证书规格](../../security/cryptoFramework-overview.md#证书规格)

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名    | 类型          | 必填 | 说明                     |
| --------- | ------------- | ---- | ------------------------ |
| certChain | [CertChainData](#certchaindata) | 是   | 表示X509证书链序列化数据。 |

**返回值**：

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| Promise\<void> | Promise对象 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let validator = cryptoFramework.createCertChainValidator("PKIX");
// 证书链二进制数据，需业务自行赋值
let encodingData = null;
// 证书链包含的证书个数，需业务自行赋值
let certCount = 2;
let certChainData = {
    data: encodingData,
    count: certCount,
    // 根据encodingData的格式进行赋值，支持FORMAT_PEM和FORMAT_DER
    encodingFormat: cryptoFramework.EncodingFormat.FORMAT_PEM 
};
validator.validate(certChainData).then(result => {
    Console.log("validate success");
}, error => {
    Console.log("validate failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### algorithm

algorithm : string

表示X509证书链校验器算法名称。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 表示证书链校验器算法名称 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let validator = cryptoFramework.createCertChainValidator("PKIX");
let algorithm = validator.algorithm;
```

## X509CrlEntry

被吊销证书对象。

### getEncoded

getEncoded(callback : AsyncCallback\<EncodingBlob>) : void

表示获取被吊销证书的序列化数据。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明     |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback\<[EncodingBlob](#encodingblob)> | 否   | 回调函数。表示被吊销证书的序列化数据 |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
x509CrlEntry.getEncoded(function (error, data) {
    if (error != null) {
        Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("getEncoded success");
    }
});
```

### getEncoded

getEncoded() : Promise\<EncodingBlob>

表示获取被吊销证书的序列化数据。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型         | 说明                       |
| ------------ | -------------------------- |
| Promise\<[EncodingBlob](#encodingblob)> | 表示被吊销证书的序列化数据 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
x509CrlEntry.getEncoded().then(result => {
    Console.log("getEncoded success");
}, error => {
    Console.log("getEncoded failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getSerialNumber

getSerialNumber() : number

表示获取被吊销证书的序列号。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 表示被吊销证书的序列号 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
let serialNumber = x509CrlEntry.getSerialNumber();
```

### getCertIssuer

getCertIssuer(callback : AsyncCallback\<DataBlob>) : void

表示获取被吊销证书的颁发者信息。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明     |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 否   | 回调函数。表示被吊销证书的颁发者信息 |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
x509CrlEntry.getCertIssuer(function (error, issuer) {
    if (error != null) {
        Console.log("getCertIssuer failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("getCertIssuer success");
    }
});
```

### getCertIssuer

getCertIssuer() : Promise\<DataBlob>

表示获取被吊销证书的颁发者信息。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型     | 说明                       |
| -------- | -------------------------- |
| Promise\<[DataBlob](#datablob)> | 表示被吊销证书的颁发者信息 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
x509CrlEntry.getCertIssuer().then(issuer => {
    Console.log("getCertIssuer success");
}, error => {
    Console.log("getCertIssuer failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```

### getRevocationDate

getRevocationDate(callback : AsyncCallback\<string>) : void

表示获取证书被吊销的日期。

**系统能力**：SystemCapability.Security.CryptoFramework

**参数**：

| 参数名   | 类型          | 必填 | 说明     |
| -------- | ------------- | ---- | -------- |
| callback | AsyncCallback\<string> | 否   | 回调函数。表示证书被吊销的日期 |


**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
x509CrlEntry.getRevocationDate(function (error, date) {
    if (error != null) {
        Console.log("getRevocationDate failed, errCode: " + error.code + ", errMsg: " + error.message);
    } else {
        Console.log("getRevocationDate success");
    }
});
```

### getRevocationDate

getRevocationDate() : Promise\<string>

表示获取证书被吊销的日期。

**系统能力**：SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                 |
| ------ | -------------------- |
| Promise\<string> | 表示证书被吊销的日期 |

**示例**：

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

// 业务需通过X509Crl的getRevokedCert相关方法获取X509CrlEntry
let x509CrlEntry = null;
x509CrlEntry.getRevocationDate().then(date => {
    Console.log("getRevocationDate success");
}, error => {
    Console.log("getRevocationDate failed, errCode: " + error.code + ", errMsg: " + error.message);
});
```
