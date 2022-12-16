# @ohos.security.cryptoFramework (加解密算法库框架)

为屏蔽底层硬件和算法库，向上提供统一的密码算法库加解密相关接口。

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

| 名称                                  |    值   |   说明                         |
| ------------------------------------- | -------- | ---------------------------- |
| INVALID_PARAMS                        | 401      | 非法入参。                   |
| NOT_SUPPORT                           | 801      | 操作不支持。                 |
| ERR_OUT_OF_MEMORY                     | 17620001 | 内存错误。                   |
| ERR_RUNTIME_ERROR                     | 17620002 | 运行时外部错误。             |
| ERR_CRYPTO_OPERATION                  | 17630001 | 调用三方算法库API出错。      |

## DataBlob

buffer数组。
 **系统能力：** SystemCapability.Security.CryptoFramework

| 名称 | 类型       | 可读 | 可写 | 说明   |
| ---- | ---------- | ---- | ---- | ------ |
| data | Uint8Array | 是   | 是   | 数据。 |


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

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 17620001 | memory error       |

**示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var mac;
try {
    // 参数选择请参考上述算法支持范围
    mac = cryptoFramework.createMac("SHA256");
} catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
}
```

## Mac

Mac类，调用Mac方法可以进行MAC（Message Authentication Code）加密计算。调用前，需要通过[createMac](#cryptoframeworkcreatemac)构造Mac实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                 |
| ------- | ------ | ---- | ---- | -------------------- |
| algName | string | 是   | 否   | 代表指定的摘要算法名 |

### init

init(key : SymKey, callback : AsyncCallback\<void>) : void;	

使用对称密钥初始化Mac计算

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明         |
| -------- | -------------------- | ---- | ------------ |
| key      | SymKey               | 是   | 共享对称密钥 |
| callback | AsyncCallback\<void> | 是   | 回调函数     |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17630001 | crypto operation error |

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

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17630001 | crypto operation error |

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

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| input    | DataBlob             | 是   | 传入的消息 |
| callback | AsyncCallback\<void> | 是   | 回调函数   |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17630001 | crypto operation error |

**示例：**

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

传入消息进行Mac更新计算

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| input  | DataBlob | 是   | 传入的消息 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17630001 | crypto operation error |

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

**参数：**

| 参数名   | 类型                     | 必填 | 说明     |
| -------- | ------------------------ | ---- | -------- |
| callback | AsyncCallback\<DataBlob> | 是   | 回调函数 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17620001 | memory error           |
| 17630001 | crypto operation error |

**示例：**

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

返回Mac的计算结果

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型               | 说明        |
| ------------------ | ----------- |
| Promise\<DataBlob> | Promise对象 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17620001 | memory error           |
| 17630001 | crypto operation error |

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

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17630001 | crypto operation error |

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

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 17620001 | memory error       |

**示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

var md;
try {
    // 参数选择请参考上述算法支持范围
    md = cryptoFramework.createMd("SHA256");
} catch (error) {
    console.error("[Promise]: error code: " + error.code + ", message is: " + error.message);
}
```

## Md

Md类，调用Md方法可以进行MD（Message Digest）摘要计算。调用前，需要通过[createMd](#cryptoframeworkcreatemd)构造Md实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                 |
| ------- | ------ | ---- | ---- | -------------------- |
| algName | string | 是   | 否   | 代表指定的摘要算法名 |

### update

update(input : DataBlob, callback : AsyncCallback\<void>) : void;

传入消息进行Md更新计算

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| input    | DataBlob             | 是   | 传入的消息 |
| callback | AsyncCallback\<void> | 是   | 回调函数   |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17630001 | crypto operation error |

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

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17630001 | crypto operation error |

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

| 参数名   | 类型                     | 必填 | 说明     |
| -------- | ------------------------ | ---- | -------- |
| callback | AsyncCallback\<DataBlob> | 是   | 回调函数 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17620001 | memory error           |
| 17630001 | crypto operation error |

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

| 类型               | 说明        |
| ------------------ | ----------- |
| Promise\<DataBlob> | Promise对象 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17620001 | memory error           |
| 17630001 | crypto operation error |

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

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17630001 | crypto operation error |

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
	console.error("MD len: " + mdLen);
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

**错误码：**

| 错误码ID | 错误信息     |
| -------- | ------------ |
| 17620001 | memory error |

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

**参数：**

| 参数名   | 类型                     | 必填 | 说明                 |
| -------- | ------------------------ | ---- | -------------------- |
| len      | number                   | 是   | 表示生成随机数的长度 |
| callback | AsyncCallback\<DataBlob> | 是   | 回调函数             |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17620001 | memory error           |
| 17630001 | crypto operation error |

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

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| len    | number | 是   | 表示生成随机数的长度 |

**返回值：**

| 类型               | 说明        |
| ------------------ | ----------- |
| Promise\<DataBlob> | Promise对象 |

**错误码：**

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 17620001 | memory error           |
| 17630001 | crypto operation error |

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

setSeed(seed : DataBlob) : void;

设置指定的种子

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名   | 类型                  | 必填 | 说明       |
| -------- | --------------------- | ---- | ---------- |
| seed     | DataBlob              | 是   | 设置的种子 |

**错误码：**

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 17620001 | memory error      |

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
        try {
            rand.setSeed(randData);
        } catch (error) {
            console.log("setSeed failed, errCode: " + error.code + ", errMsg: " + error.message);
        }
    }
});
```

## ParamsSpec

加解密参数，在进行对称加解密时需要构造其子类对象，并将子类对象传入[init()](#init-2)方法。<br/>适用于需要iv等参数的对称加解密模式（对于无iv等参数的模式如ECB模式，无需构造，在[init()](#init-2)中传入null即可）。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称     | 类型   | 可读 | 可写 | 说明                    |
| -------- | ------ | ---- | ---- | ----------------------- |
| algoName | string | 是   | 是   | 指明对称加解密参数的算法模式。可选值如下:<br/>- "IvParamsSpec": 适用于CBC\|CTR\|OFB\|CFB模式<br/>- "GcmParamsSpec": 适用于GCM模式<br/>- "CcmParamsSpec": 适用于CCM模式 |

> **说明：** 
> 由于[init()](#init-2)的params参数是ParamsSpec类型（父类），而实际需要传入具体的子类对象（如IvParamsSpec），因此在构造子类对象时应设置其父类ParamsSpec的algoName参数，使算法库在init()时知道传入的是哪种子类对象。

## IvParamsSpec

加解密参数[ParamsSpec](#paramsspec)的子类，用于在对称加解密时作为[init()](#init-2)方法的参数。<br/>适用于CBC、CTR、OFB、CFB这些仅使用iv作为参数的加解密模式。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称 | 类型                  | 可读 | 可写 | 说明                                                         |
| ---- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv   | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数iv。常见取值如下：<br/>- AES的CBC\|CTR\|OFB\|CFB模式：iv长度为16字节<br/>- 3DES的CBC\|OFB\|CFB模式：iv长度为8字节 |

> **说明：** 
> 传入[init()](#init-2)方法前需要指定其algoName属性（来源于父类[ParamsSpec](#paramsspec)）。

## GcmParamsSpec

加解密参数[ParamsSpec](#paramsspec)的子类，用于在对称加解密时作为[init()](#init-2)方法的参数。<br/>适用于GCM模式。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型                  | 可读 | 可写 | 说明                                                         |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数iv，长度为12字节                               |
| aad     | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数aad，长度为8字节                               |
| authTag | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数authTag，长度为16字节。<br/>采用GCM模式加密时，需要获取[doFinal()](#dofinal-2)输出的[DataBlob](#datablob)，取出其末尾16字节作为解密时[init()](#init-2)方法的入参[GcmParamsSpec](#gcmparamsspec)中的的authTag |

> **说明：** 
> 传入[init()](#init-2)方法前需要指定其algoName属性（来源于父类[ParamsSpec](#paramsspec)）。

## CcmParamsSpec

加解密参数[ParamsSpec](#paramsspec)的子类，用于在对称加解密时作为[init()](#init-2)方法的参数。<br/>适用于CCM模式。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型                  | 可读 | 可写 | 说明                                                         |
| ------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| iv      | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数iv，长度为7字节                                |
| aad     | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数aad，长度为8字节                               |
| authTag | [DataBlob](#datablob) | 是   | 是   | 指明加解密参数authTag，长度为12字节。<br/>采用CCM模式加密时，需要获取[doFinal()](#dofinal-2)输出的[DataBlob](#datablob)，取出其末尾12字节作为解密时[init()](#init-2)方法的入参[CcmParamsSpec](#ccmparamsspec)中的authTag |

> **说明：** 
> 传入[init()](#init-2)方法前需要指定其algoName属性（来源于父类[ParamsSpec](#paramsspec)）。

## CryptoMode

表示加解密操作的枚举。

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称         | 值   | 说明             |
| ------------ | ---- | ---------------- |
| ENCRYPT_MODE | 0    | 表示进行加密操作 |
| DECRYPT_MODE | 1    | 表示进行解密操作 |

## Key

密钥（父类），在运行密码算法（如加解密）时需要提前生成其子类对象，并传入[Cipher](#cipher)实例的[init()](#init-2)方法。<br/>密钥可以通过密钥生成器来生成。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework 

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| format  | string | 是   | 否   | 密钥的格式。                 |
| algName | string | 是   | 否   | 密钥对应的算法名（含长度）。 |

### getEncoded

getEncoded() : DataBlob

以同步方法，获取16进制形式的密钥内容。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型                  | 说明                     |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | 用于查看密钥的具体内容。 |

**示例：**

```js
import cryptoFramework from "@ohos.security.cryptoFramework"
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

对称密钥，是[Key](#key)的子类，在对称加解密时需要将其对象传入[Cipher](#cipher)实例的[init()](#init-2)方法使用。<br/>对称密钥可以通过对称密钥生成器[SymKeyGenerator](#symkeygenerator)来生成。

### clearMem

clearMem() : void

以同步方法，将系统底层内存中的的密钥内容清零。建议在不再使用对称密钥实例时，调用本函数，避免内存中密钥数据存留过久。

**系统能力：** SystemCapability.Security.CryptoFramework

**示例：**

```js
import cryptoFramework from "@ohos.security.cryptoFramework"
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

公钥，是Key的子类，在非对称加解密、验签、密钥协商时需要将其对象作为输入使用。<br/>公钥可以通过非对称密钥生成器AsyKeyGenerator来生成。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework 

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| format  | string | 是   | 否   | 密钥的格式。                 |
| algName | string | 是   | 否   | 密钥对应的算法名（含长度）。 |


### getEncoded

getEncoded() : DataBlob

以同步方法，获取二进制形式的密钥内容。公钥格式满足ASN.1语法、X.509规范、DER编码格式。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型                  | 说明                     |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | 用于查看密钥的具体内容。 |

**示例：**

```js
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

let key; // key为使用非对称密钥生成器生成的非对称密钥的公钥对象，此处省略生成过程
console.info("key format:" + key.format);
console.info("key algName:" + key.algName);
var encodedKey = key.getEncoded();
console.info("key encoded:" + uint8ArrayToShowStr(encodedKey.data));
```

## PriKey

私钥，是Key的子类，在非对称加解密、签名、密钥协商时需要将其作为输入使用。<br/>私钥可以通过非对称密钥生成器AsyKeyGenerator来生成。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework 

| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| format  | string | 是   | 否   | 密钥的格式。                 |
| algName | string | 是   | 否   | 密钥对应的算法名（含长度）。 |

### getEncoded

getEncoded() : DataBlob

以同步方法，获取二进制形式的密钥内容。私钥格式满足ASN.1语法，PKCS#8规范、DER编码方式。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型                  | 说明                     |
| --------------------- | ------------------------ |
| [DataBlob](#datablob) | 用于查看密钥的具体内容。 |

**示例：**

```js
function uint8ArrayToShowStr(uint8Array) {
  return Array.prototype.map
    .call(uint8Array, (x) => ('00' + x.toString(16)).slice(-2))
    .join('');
}

let key; // key为使用非对称密钥生成器生成的非对称密钥的私钥对象，此处省略生成过程
console.info("key format:" + key.format);
console.info("key algName:" + key.algName);
var encodedKey = key.getEncoded();
console.info("key encoded:" + uint8ArrayToShowStr(encodedKey.data));
```

### clearMem

clearMem() : void

以同步方法，将系统底层内存中的的密钥内容清零。

**系统能力：** SystemCapability.Security.CryptoFramework

**示例：**

```js
let key; // key为使用非对称密钥生成器生成的非对称密钥的私钥对象，此处省略生成过程
key.clearMem();
```

## KeyPair

非对称密钥对，包含：公钥与私钥，。<br/>可以通过非对称密钥生成器AsyKeyGenerator来生成。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明           |
| ------- | ------ | ---- | ---- | ------------ |
| priKey  | [PriKey](#prikey) | 是   | 否   | 私钥。      |
| pubKey | [PubKey](#pubkey) | 是   | 否   | 公钥。       |


## cryptoFramework.createSymKeyGenerator

createSymKeyGenerator(algName : string) : SymKeyGenerator

通过指定算法名称的字符串，获取相应的对称密钥生成器实例。<br/>支持的规格详见框架概述“[密钥生成规格](../../security/cryptoFramework-overview.md#密钥生成规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 待生成对称密钥生成器的算法名称。<br/>具体取值详见框架概述“[密钥生成规格](../../security/cryptoFramework-overview.md#密钥生成规格)”一节中的“字符串参数”。 |

**返回值：**

| 类型                                | 说明                       |
| ----------------------------------- | -------------------------- |
| [SymKeyGenerator](#symkeygenerator) | 返回对称密钥生成器的对象。 |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
```

## SymKeyGenerator

对称密钥生成器。<br/>在使用该类的方法前，需要先使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)方法构建一个symKeyGenerator实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                           |
| ------- | ------ | ---- | ---- | ------------------------------ |
| algName | string | 是   | 否   | 对称密钥生成器指定的算法名称。 |

### generateSymKey

generateSymKey(callback : AsyncCallback\<SymKey>) : void

异步获取对称密钥生成器随机生成的密钥，通过注册回调函数获取结果。<br/>必须在使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)创建对称密钥生成器后，才能使用本函数。<br/>目前支持使用OpenSSL的RAND_priv_bytes()作为底层能力生成随机密钥。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                                         |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<[SymKey](#symkey)> | 是   | 回调函数。当生成对称密钥成功，err为undefined，data为获取到的SymKey；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17620001 | memory error. |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symAlgoName = '3DES192';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgoName);
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

异步获取该对称密钥生成器随机生成的密钥，通过Promise获取结果。<br/>必须在使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)创建对称密钥生成器后，才能使用本函数。<br/>目前支持使用OpenSSL的RAND_priv_bytes()作为底层能力生成随机密钥。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值：**

| 类型                        | 说明                              |
| --------------------------- | --------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise对象，返回对称密钥SymKey。 |

**错误码：**

| 错误码ID | 错误信息      |
| -------- | ------------- |
| 17620001 | memory error. |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symAlgoName = 'AES128';
let symKeyGenerator = cryptoFramework.createSymKeyGenerator(symAlgoName);
symKeyGenerator.generateSymKey()
.then(symKey => {
  console.info(`Generate symKey success, algName: ${symKey.algName}`);
}, error => {
  console.error(`Generate symKey failed, ${error.code}, ${error.message}`);
})
```

### convertKey

convertKey(key : DataBlob, callback : AsyncCallback\<SymKey>) : void

异步根据指定数据生成对称密钥，通过注册回调函数获取结果。<br/>必须在使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)创建对称密钥生成器后，才能使用本函数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                              | 必填 | 说明                                                         |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| key      | [DataBlob](#datablob)             | 是   | 指定的对称密钥材料。                                         |
| callback | AsyncCallback\<[SymKey](#symkey)> | 是   | 回调函数。当生成对称密钥成功，err为undefined，data为获取到的SymKey；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                                               |
| -------- | --------------------------------------------------- |
| 17620001 | memory error.                                       |

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

异步根据指定数据生成对称密钥，通过Promise获取结果。<br/>必须在使用[createSymKeyGenerator](#cryptoframeworkcreatesymkeygenerator)创建对称密钥生成器后，才能使用本函数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型                  | 必填 | 说明                 |
| ---- | --------------------- | ---- | -------------------- |
| key  | [DataBlob](#datablob) | 是   | 指定的密钥材料数据。 |

**返回值：**

| 类型                        | 说明                              |
| --------------------------- | --------------------------------- |
| Promise\<[SymKey](#symkey)> | Promise对象，返回对称密钥SymKey。 |

**错误码：**

| 错误码ID | 错误信息                                          |
| -------- | --------------------------------------------- |
| 17620001 | memory error.                                |

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
symKeyGenerator.convertKey(keyMaterialBlob)
.then(symKey => {
  console.info(`Convert symKey success, algName: ${symKey.algName}`);
}, error => {
  console.error(`Convert symKey failed, ${error.code}, ${error.message}`);
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

| 类型            | 说明                         |
| --------------- | ---------------------------- |
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

| 名称    | 类型   | 可读 | 可写 | 说明                             |
| ------- | ------ | ---- | ---- | -------------------------------- |
| algName | string | 是   | 否   | 非对称密钥生成器指定的算法名称。 |

### generateKeyPair

generateKeyPair(callback : AsyncCallback\<KeyPair>) : void;

异步获取非对称密钥生成器随机生成的密钥，通过注册回调函数获取结果。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                    | 必填 | 说明                           |
| -------- | ----------------------- | ---- | ------------------------------ |
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

| 类型              | 说明                              |
| ----------------- | --------------------------------- |
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

| 参数名     | 类型       | 必填 | 说明                           |
| -------- | ----------- | ---- | ------------------------------ |
| pubKey   | DataBlob    | 是   | 指定的公钥材料。如果公钥不需要转换，可直接传入null        |
| priKey   | DataBlob    | 是   | 指定的私钥材料。如果私钥不需要转换，可直接传入null        |
| callback | AsyncCallback\<KeyPair> | 是   | 回调函数，用于获取非对称密钥。 |

**示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"
let pubKey; // X.509规范、DER格式的公钥数据，此处省略数据。
let priKey; // PKCS#8规范、DER格式的私钥数据，此处省略数据。
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

| 参数名   | 类型    | 必填 | 说明             |
| ------ | -------- | ---- | ---------------- |
| pubKey | DataBlob | 是   | 指定的公钥材料。如果公钥不需要转换，可直接传入null |
| priKey | DataBlob | 是   | 指定的私钥材料。如果私钥不需要转换，可直接传入null |

**返回值：**

| 类型              | 说明                              |
| ----------------- | --------------------------------- |
| Promise\<KeyPair> | 使用Promise的方式获取非对称密钥。 |

**示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let asyKeyGenerator = cryptoFramework.createAsyKeyGenerator("ECC256");
let pubKey; // pubKey为使用非对称密钥生成器生成的非对称密钥的公钥对象，此处省略生成过程
let priKey; // priKey为使用非对称密钥生成器生成的非对称密钥的私钥对象，此处省略生成过程
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

通过指定算法名称，获取相应的[Cipher](#cipher)实例。<br/>支持的规格详见框架概述“[加解密规格](../../security/cryptoFramework-overview.md#加解密规格)”一节。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名         | 类型   | 必填 | 说明                                                         |
| -------------- | ------ | ---- | ------------------------------------------------------------ |
| transformation | string | 是   | 待生成Cipher的算法名称（含密钥长度）、加密模式以及填充方法的组合。<br/>具体取值详见框架概述“[加解密规格](../../security/cryptoFramework-overview.md#加解密规格)”一节中的“字符串参数”。 |

> **说明：** 
> 1. 目前对称加解密中，PKCS5和PKCS7的实现相同，其padding长度和分组长度保持一致（即PKCS5和PKCS7在3DES中均按照8字节填充，在AES中均按照16字节填充），另有NoPadding表示不填充。<br/>开发者需要自行了解密码学不同分组模式的差异，以便选择合适的参数规格。例如选择ECB和CBC模式时，建议启用填充，否则必须确保明文长度是分组大小的整数倍；选择其他模式时，可以不启用填充，此时密文长度和明文长度一致（即可能不是分组大小的整数倍）。
> 2. 使用RSA进行非对称加解密时，必须创建两个Cipher对象分别进行加密和解密操作，而不能对同一个Cipher对象进行加解密。对称加解密没有此要求（即只要算法规格一样，可以对同一个Cipher对象进行加解密操作）。

**返回值：**

| 类型              | 说明                     |
| ----------------- | ------------------------ |
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
}
```

## Cipher

提供加解密的算法操作功能，按序调用本类中的[init()](#init-2)、[update()](#update-4)、[doFinal()](#dofinal-2)方法，可以实现对称加密/对称解密/非对称加密/非对称解密。<br/>完整的加解密流程示例可参考开发指导中的“[使用加解密操作](../../security/cryptoFramework-guidelines.md#使用加解密操作)”一节。

一次完整的加/解密流程在对称加密和非对称加密中略有不同：

- 对称加解密：init为必选，update为可选（且允许多次update加/解密大数据），doFinal为必选；doFinal结束后可以重新init开始新一轮加/解密流程。
- RSA非对称加解密：init为必选，不支持update操作，doFinal为必选（允许连续多次doFinal加/解密大数据）；doFinal后不支持重新init。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework


| 名称    | 类型   | 可读 | 可写 | 说明                         |
| ------- | ------ | ---- | ---- | ---------------------------- |
| algName | string | 是   | 否   | 加解密生成器指定的算法名称。 |

### init

init(opMode : CryptoMode, key : Key, params : ParamsSpec, callback : AsyncCallback\<void>) : void

初始化加解密的[cipher](#cipher)对象，通过注册回调函数获取结果。<br/>必须在使用[createCipher](#cryptoframeworkcreatecipher)创建[Cipher](#cipher)实例后，才能使用本函数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode   | [CryptoMode](#cryptomode) | 是   | 加密或者解密模式。                                           |
| key      | [Key](#key)               | 是   | 指定加密或解密的密钥。                                       |
| params   | [ParamsSpec](#paramsspec) | 是   | 指定加密或解密的参数，对于ECB等没有参数的算法模式，可以传入null。 |
| callback | AsyncCallback\<void>      | 是   | 回调函数。当初始化成功，err为undefined，否则为错误对象。     |

**错误码：**

| 错误码ID | 错误信息                                                 |
| -------- | --------------------------------------------------------- |
| 17620001 | memory error.                                            |
| 17620002 | runtime error.                                           |
| 17630001 | crypto operation error.|

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKey;     // 此处省略生成对称密钥的过程
let cipher;         // 此处省略生成cipher实例的过程

cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null, (err, ) => {
  if (err) {
    console.error(`Failed to init cipher, ${err.code}, ${err.message}`);
  } else {
    console.info(`Init cipher success`);
    // 此处进行update等后续操作
  }
})
```

### init

init(opMode : CryptoMode, key : Key, params : ParamsSpec) : Promise\<void>

初始化加解密的cipher对象，通过Promise获取结果。<br/>必须在使用[createCipher](#cryptoframeworkcreatecipher)创建[Cipher](#cipher)实例后，才能使用本函数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                         |
| ------ | ------------------------- | ---- | ------------------------------------------------------------ |
| opMode | [CryptoMode](#cryptomode) | 是   | 加密或者解密模式。                                           |
| key    | [Key](#key)               | 是   | 指定加密或解密的密钥。                                       |
| params | [ParamsSpec](#paramsspec) | 是   | 指定加密或解密的参数，对于ECB等没有参数的算法模式，可以传入null。 |

**返回值：**

| 类型           | 说明                                   |
| -------------- | -------------------------------------- |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 17620001 | memory error.                                     |
| 17620002 | runtime error.                                    |
| 17630001 | crypto operation error.|

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';
let symKey;     // 此处省略生成对称密钥的过程
let cipher;         // 此处省略生成cipher实例的过程
cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, symKey, null)
.then(() => {
  console.info(`Init cipher success`);
  // 此处进行update等后续操作
}, error => {
  console.error(`Failed to init cipher, ${error.code}, ${error.message}`);
})
```

### update

update(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

分段更新加密或者解密数据操作，通过注册回调函数获取加/解密数据。 <br/>必须在对[Cipher](#cipher)实例使用[init()](init-2)初始化后，才能使用本函数。

> **说明：** 
> 1. 在进行对称加解密操作的时候，如果开发者对各个分组模式不够熟悉，建议对每次update和doFinal的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文/明文。这是因为选择的分组模式等各项规格都可能对update和[doFinal](#dofinal-2)结果产生影响。<br/>（例如对于ECB和CBC模式，不论update传入的数据是否为分组长度的整数倍，都会以分组作为基本单位进行加/解密，并输出本次update新产生的加/解密分组结果。<br/>可以理解为，update只要凑满一个新的分组就会有输出，如果没有凑满则此次update输出为null，把当前还没被加/解密的数据留着，等下一次update/doFinal传入数据的时候，拼接起来继续凑分组。<br/>最后doFinal的时候，会把剩下的还没加/解密的数据，根据[createCipher](#cryptoframeworkcreatecipher)时设置的padding模式进行填充，补齐到分组的整数倍长度，再输出剩余加解密结果。<br/>而对于可以将分组密码转化为流模式实现的模式，还可能出现密文长度和明文长度相同的情况等。）
> 2. 根据数据量，可以不调用update（即[init](#init-2)完成后直接调用[doFinal](#dofinal-2)）或多次调用update。<br/>算法库目前没有对update（单次或累计）的数据量设置大小限制，建议对于大数据量的对称加解密，采用多次update的方式传入数据。
> 3. RSA非对称加解密不支持update操作。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob)                 | 是   | 加密或者解密的数据。data不能为null，也不允许传入{data : Uint8Array(空) }            |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数。当更新加/解密数据成功，err为undefined，data为此次更新的加/解密结果DataBlob；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 17620001 | memory error.                               |
| 17620002 | runtime error.                              |
| 17630001 | crypto operation error.                     |

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
    console.error(`Failed to update cipher`);
  } else {
    console.info(`Update cipher success`);
    if (output != null) {
      // 拼接output.data到密文
    }
    // 此处进行doFinal等后续操作
  }
})
```

### update

update(data : DataBlob) : Promise\<DataBlob>

分段更新加密或者解密数据操作，通过通过Promise获取加/解密数据。<br/>必须在对[Cipher](#cipher)实例使用[init()](init-2)初始化后，才能使用本函数。

> **说明：** 
> 1. 在进行对称加解密操作的时候，如果开发者对各个分组模式不够熟悉，建议对每次update和doFinal的结果都判断是否为null，并在结果不为null时取出其中的数据进行拼接，形成完整的密文/明文。这是因为选择的分组模式等各项规格都可能对update和[doFinal](#dofinal-2)结果产生影响。<br/>（例如对于ECB和CBC模式，不论update传入的数据是否为分组长度的整数倍，都会以分组作为基本单位进行加/解密，并输出本次update新产生的加/解密分组结果。<br/>可以理解为，update只要凑满一个新的分组就会有输出，如果没有凑满则此次update输出为null，把当前还没被加/解密的数据留着，等下一次update/doFinal传入数据的时候，拼接起来继续凑分组。<br/>最后doFinal的时候，会把剩下的还没加/解密的数据，根据[createCipher](#cryptoframeworkcreatecipher)时设置的padding模式进行填充，补齐到分组的整数倍长度，再输出剩余加解密结果。<br/>而对于可以将分组密码转化为流模式实现的模式，还可能出现密文长度和明文长度相同的情况等。）
> 2. 根据数据量，可以不调用update（即[init](#init-2)完成后直接调用[doFinal](#dofinal-2)）或多次调用update。<br/>算法库目前没有对update（单次或累计）的数据量设置大小限制，建议对于大数据量的对称加解密，可以采用多次update的方式传入数据。
> 3. RSA非对称加解密不支持update操作。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型                  | 必填 | 说明                 |
| ---- | --------------------- | ---- | -------------------- |
| data | [DataBlob](#datablob) | 是   | 加密或者解密的数据。data不能为null，也不允许传入{data : Uint8Array(空) } |

**返回值：**

| 类型                            | 说明                                             |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[DataBlob](#datablob)> | Promise对象，返回此次更新的加/解密结果DataBlob。 |

**错误码：**

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 17620001 | memory error.                                |
| 17620002 | runtime error.                               |
| 17630001 | crypto operation error.                      |

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
cipher.update(plainText)
.then((output) => {
  console.info(`Update cipher success.`);
  if (output != null) {
    // 拼接output.data到密文
  }
  // 此处进行doFinal等后续操作
}, error => {
  console.info(`Update cipher failed.`);
})
```

### doFinal

doFinal(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

（1）在对称加解密中，doFinal加/解密（分组模式产生的）剩余数据和本次传入的数据，最后结束加密或者解密数据操作，通过注册回调函数获取加密或者解密数据。<br/>如果数据量较小，可以在doFinal中一次性传入数据，而不使用update；如果在本次加解密流程中，已经使用[update](#update-4)传入过数据，可以在doFinal的data参数处传入null。<br/>根据对称加解密的模式不同，doFinal的输出有如下区别：

- 对于GCM和CCM模式的对称加密：一次加密流程中，如果将每一次update和doFinal的结果拼接起来，会得到“密文+authTag”，即末尾的16字节（GCM模式）或12字节（CCM模式）是authTag，而其余部分均为密文。（也就是说，如果doFinal的data参数传入null，则doFinal的结果就是authTag）<br/>authTag需要填入解密时的[GcmParamsSpec](#gcmparamsspec)或[CcmParamsSpec](#ccmparamsspec)；密文则作为解密时的入参data。
- 对于其他模式的对称加解密、GCM和CCM模式的对称解密：一次加/解密流程中，每一次update和doFinal的结果拼接起来，得到完整的明文/密文。

（2）在RSA非对称加解密中，doFinal加/解密本次传入的数据，通过注册回调函数获取加密或者解密数据。如果数据量较大，可以多次调用doFinal，拼接结果得到完整的明文/密文。

>  **说明：** 
>  1. 对称加解密中，调用doFinal标志着一次加解密流程已经完成，即[Cipher](#cipher)实例的状态被清除，因此当后续开启新一轮加解密流程时，需要重新调用[init()](init-2)并传入完整的参数列表进行初始化<br/>（比如即使是对同一个Cipher实例，采用同样的对称密钥，进行加密然后解密，则解密中调用init的时候仍需填写params参数，而不能直接省略为null）。
>  2. 如果遇到解密失败，需检查加解密数据和[init](#init-2)时的参数是否匹配，包括GCM模式下加密得到的authTag是否填入解密时的GcmParamsSpec等。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名     | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| data     | [DataBlob](#datablob)                 | 是   | 加密或者解密的数据。在对称加解密中允许为null，但不允许传入{data : Uint8Array(空) }。       |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数。当最终加/解密数据成功，err为undefined，data为剩余数据的加/解密结果DataBlob；否则为错误对象。 |

**错误码：**

| 错误码ID | 错误信息                |
| -------- | ----------------------- |
| 17620001 | memory error.           |
| 17620002 | runtime error.          |
| 17630001 | crypto operation error. |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let cipher;         // 此处省略生成cipher实例的过程
let data;           // 此处省略准备待加密/解密数据的过程
// 此处省略init()和update()过程
cipher.doFinal(data, (err, output) => {
  if (err) {
    console.error(`Failed to finalize cipher, ${err.code}, ${err.message}`);
  } else {
    console.info(`Finalize cipher success`);
    if (output != null) {
      // 拼接output.data得到完整的明文/密文(及authTag)
    }
  }
})
```

### doFinal

doFinal(data : DataBlob) : Promise\<DataBlob>

（1）在对称加解密中，doFinal加/解密（分组模式产生的）剩余数据和本次传入的数据，最后结束加密或者解密数据操作，通过Promise获取加密或者解密数据。<br/>如果数据量较小，可以在doFinal中一次性传入数据，而不使用update；如果在本次加解密流程中，已经使用[update](#update-4)传入过数据，可以在doFinal的data参数处传入null。<br/>根据对称加解密的模式不同，doFinal的输出有如下区别：

- 对于GCM和CCM模式的对称加密：一次加密流程中，如果将每一次update和doFinal的结果拼接起来，会得到“密文+authTag”，即末尾的16字节（GCM模式）或12字节（CCM模式）是authTag，而其余部分均为密文。（也就是说，如果doFinal的data参数传入null，则doFinal的结果就是authTag）<br/>authTag需要填入解密时的[GcmParamsSpec](#gcmparamsspec)或[CcmParamsSpec](#ccmparamsspec)；密文则作为解密时的入参data。
- 对于其他模式的对称加解密、GCM和CCM模式的对称解密：一次加/解密流程中，每一次update和doFinal的结果拼接起来，得到完整的明文/密文。

（2）在RSA非对称加解密中，doFinal加/解密本次传入的数据，通过Promise获取加密或者解密数据。如果数据量较大，可以多次调用doFinal，拼接结果得到完整的明文/密文。

>  **说明：** 
>  1. 对称加解密中，调用doFinal标志着一次加解密流程已经完成，即[Cipher](#cipher)实例的状态被清除，因此当后续开启新一轮加解密流程时，需要重新调用[init()](init-2)并传入完整的参数列表进行初始化<br/>（比如即使是对同一个Cipher实例，采用同样的对称密钥，进行加密然后解密，则解密中调用init的时候仍需填写params参数，而不能直接省略为null）。
>  2. 如果遇到解密失败，需检查加解密数据和[init](#init-2)时的参数是否匹配，包括GCM模式下加密得到的authTag是否填入解密时的GcmParamsSpec等。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型                  | 必填 | 说明                 |
| ---- | --------------------- | ---- | -------------------- |
| data | [DataBlob](#datablob) | 是   | 加密或者解密的数据。data参数允许为null，但不允许传入{data : Uint8Array(空) } |

**返回值：**

| 类型                            | 说明                                             |
| ------------------------------- | ------------------------------------------------ |
| Promise\<[DataBlob](#datablob)> | Promise对象，返回剩余数据的加/解密结果DataBlob。 |

**错误码：**

| 错误码ID | 错误信息                                     |
| -------- | -------------------------------------------- |
| 17620001 | memory error.                                |
| 17620002 | runtime error.                               |
| 17630001 | crypto operation error.                      |

**示例：**

```js
import cryptoFramework from '@ohos.security.cryptoFramework';

let cipher;         // 此处省略生成cipher实例的过程
let data;           // 此处省略准备待加密/解密数据的过程
// 此处省略init()和update()过程
cipher.doFinal(data)
.then(output => {
  console.info(`Finalize cipher success`);
    if (output != null) {
    // 拼接output.data得到完整的明文/密文(及authTag)
  }
}, error => {
  console.error(`Failed to finalize cipher, ${error.code}, ${error.message}`);
})
```

**使用RSA加密的callback完整示例：**

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

**使用RSA加密的promise完整示例：**

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
  return cipher.init(cryptoFramework.CryptoMode.ENCRYPT_MODE, pubKey, null); // 传入私钥和DECRYPT_MODE可初始化解密模式
}).then(() => {
  let plainText = "this is cipher text";
  let input = { data : stringToUint8Array(plainText) };
  return cipher.doFinal(input);
}).then(dataBlob => {
  console.info("EncryptOutPut is " + dataBlob.data);
});
```

> **说明：** 
> 更多加解密流程的完整示例可参考开发指导中的“[使用加解密操作](../../security/cryptoFramework-guidelines.md#使用加解密操作)”一节。

## cryptoFramework.createSign

createSign(algName : string) : Sign

Sign实例生成

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| algName | string | 是   | 指定签名算法：RSA或ECC，使用RSA PKCS1模式时需要设置摘要，使用RSA PSS模式时需要设置摘要和掩码摘要 |

**返回值**：

| 类型 | 说明                             |
| ---- | -------------------------------- |
| Sign | 返回由输入算法指定生成的Sign对象 |

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

| 参数名   | 类型                 | 必填 | 说明             |
| -------- | -------------------- | ---- | ---------------- |
| priKey   | PriKey                  | 是   | 用于Sign的初始化 |
| callback | AsyncCallback\<void> | 是   | 回调函数的       |

### init

init(priKey : PriKey) : Promise\<void>

使用私钥初始化Sign对象，Promise形式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| ------ | ---- | ---- | ---------------- |
| priKey | PriKey  | 是   | 用于Sign的初始化 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

### update

update(data : DataBlob, callback : AsyncCallback\<void>) : void

追加待签名数据，callback方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| data     | DataBlob             | 是   | 传入的消息 |
| callback | AsyncCallback\<void> | 是   | 回调函数   |

### update

update(data : DataBlob) : Promise\<void>;

追加待签名数据，promise方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| data   | DataBlob | 是   | 传入的消息 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

### sign

sign(data : DataBlob, callback : AsyncCallback\<DataBlob>) : void

对数据进行签名，返回签名结果，callback方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| data     | DataBlob             | 是   | 传入的消息 |
| callback | AsyncCallback\<DataBlob> | 是   | 回调函数   |

### sign

sign(data : DataBlob) : Promise\<DataBlob>

对数据进行签名，返回签名结果，promise方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| data   | DataBlob | 是   | 传入的消息 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

**callback示例：**

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
          AlertDialog.show({message : "res" +  SignMessageBlob.data});
        });
      });
    });
  });
}
```

**promise示例：**

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
    AlertDialog.show({message : "output" +  SignMessageBlob.data});
  });
}
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

| 类型   | 说明                               |
| ------ | ---------------------------------- |
| Verify | 返回由输入算法指定生成的Verify对象 |

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

传入公钥初始化Verify对象，Callback形式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明                         |
| -------- | -------------------- | ---- | ---------------------------- |
| pubKey   | PubKey                  | 是   | 公钥对象，用于Verify的初始化 |
| callback | AsyncCallback\<void> | 是   | 回调函数                     |

### init

init(pubKey : PubKey) : Promise\<void>

传入公钥初始化Verify对象，Promise形式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型 | 必填 | 说明                         |
| ------ | ---- | ---- | ---------------------------- |
| pubKey | PubKey  | 是   | 公钥对象，用于Verify的初始化 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

### update

update(data : DataBlob, callback : AsyncCallback\<void>) : void

追加待验签数据，callback方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                 | 必填 | 说明       |
| -------- | -------------------- | ---- | ---------- |
| data     | DataBlob             | 是   | 传入的消息 |
| callback | AsyncCallback\<void> | 是   | 回调函数   |

### update

update(data : DataBlob) : Promise\<void>;

追加待验签数据，promise方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型     | 必填 | 说明       |
| ------ | -------- | ---- | ---------- |
| data   | DataBlob | 是   | 传入的消息 |

**返回值：**

| 类型           | 说明        |
| -------------- | ----------- |
| Promise\<void> | Promise对象 |

### verify

verify(data : DataBlob, signatureData : DataBlob, callback : AsyncCallback\<boolean>) : void

对数据进行验签，返回验签结果，callback方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名        | 类型                 | 必填 | 说明       |
| ------------- | -------------------- | ---- | ---------- |
| data          | DataBlob             | 是   | 传入的消息 |
| signatureData | DataBlob             | 是   | 签名数据   |
| callback      | AsyncCallback\<boolean> | 是   | 回调函数   |

### verify

verify(data : DataBlob, signatureData : DataBlob) : Promise\<boolean>

对数据进行验签，返回验签结果，promise方式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名        | 类型     | 必填 | 说明       |
| ------------- | -------- | ---- | ---------- |
| data          | DataBlob | 是   | 传入的消息 |
| signatureData | DataBlob | 是   | 签名数据   |

**返回值：**

| 类型              | 说明                         |
| ----------------- | ---------------------------- |
| Promise\<boolean> | 异步返回值，代表验签是否通过 |

**callback示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalKeyPair; // globalKeyPair为使用非对称密钥生成器生成的非对称密钥对象，此处省略生成过程
let input1 = null;
let input2 = null;
let signMessageBlob = null; // 签名后的数据，此处省略
let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA25");
verifyer.init(globalKeyPair.pubKey, function (err, data) {
  verifyer.update(input1, function(err, data) {
    verifyer.verify(input2, signMessageBlob, function(err, data) {
      console.info("verify result is " + data);
    })
  });
})
```

**promise示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalKeyPair; // globalKeyPair为使用非对称密钥生成器生成的非对称密钥对象，此处省略生成过程
let verifyer = cryptoFramework.createVerify("RSA1024|PKCS1|SHA256");
let verifyInitPromise = verifyer.init(globalKeyPair.pubKey);
let input1 = null;
let input2 = null;
let signMessageBlob = null; // 签名后的数据，此处省略
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

KeyAgreement实例生成

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名  | 类型   | 必填 | 说明                            |
| ------- | ------ | ---- | ------------------------------- |
| algName | string | 是   | 指定密钥协商算法：目前仅支持ECC |

**返回值**：

| 类型         | 说明                                     |
| ------------ | ---------------------------------------- |
| KeyAgreement | 返回由输入算法指定生成的KeyAgreement对象 |

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

| 参数名   | 类型                     | 必填 | 说明                   |
| -------- | ------------------------ | ---- | ---------------------- |
| priKey   | PriKey                   | 是   | 设置密钥协商的私钥输入 |
| pubKey   | PubKey                   | 是   | 设置密钥协商的公钥输入 |
| callback | AsyncCallback\<DataBlob> | 是   | 异步接受共享秘密的回调 |

### generateSecret

generateSecret(priKey : PriKey, pubKey : PubKey) : Promise\<DataBlob>

基于传入的私钥与公钥进行密钥协商，返回共享秘密，Promise形式

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                   |
| ------ | ------ | ---- | ---------------------- |
| priKey | PriKey | 是   | 设置密钥协商的私钥输入 |
| pubKey | PubKey | 是   | 设置密钥协商的公钥输入 |

**返回值：**

| 类型               | 说明     |
| ------------------ | -------- |
| Promise\<DataBlob> | 共享秘密 |

**callback示例：**

```javascript
import cryptoFramework from "@ohos.security.cryptoFramework"

let globalKeyPair; // globalKeyPair为使用非对称密钥生成器生成的非对称密钥对象，此处省略生成过程
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

let globalKeyPair; // globalKeyPair为使用非对称密钥生成器生成的非对称密钥对象，此处省略生成过程
let keyAgreement = cryptoFramework.createKeyAgreement("ECC256");
let keyAgreementPromise = keyAgreement.generateSecret(globalKeyPair.priKey, globalKeyPair.pubKey);
keyAgreementPromise.then((secret) => {
  console.info("keyAgreement output is " + secret.data);
}).catch((error) => {
  console.error("keyAgreement error.");
});
```
