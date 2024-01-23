# @ohos.security.cryptoFramework (加解密算法库框架)

本模块提供安全随机数生成能力。当业务需要随机生成临时密钥、会话标识等数据时，可以使用。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import cryptoFramework from "@ohos.security.cryptoFramework";
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
| ERR_CRYPTO_OPERATION                  | 17630001 | 调用三方算法库API出错。     |

## DataBlob

buffer数组，提供blob数据类型。

 **系统能力：** SystemCapability.Security.CryptoFramework

| 名称 | 类型       | 可读 | 可写 | 说明   |
| ---- | ---------- | ---- | ---- | ------ |
| data | Uint8Array | 是   | 是   | 数据。 |

## cryptoFramework.createRandom

createRandom(): Random

生成Random实例，用于进行随机数的计算与设置种子。

支持的规格详见框架概述[随机数算法规格](../../security/CryptoArchitectureKit/crypto-generate-random-number.md#支持的算法与规格)。

**系统能力：** SystemCapability.Security.CryptoFramework

**返回值**：

| 类型   | 说明                                            |
| ------ | ----------------------------------------------- |
| Random | 返回由输入算法指定生成的[Random](#random)对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息     |
| -------- | ------------ |
| 17620001 | memory error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

try {
  let rand = cryptoFramework.createRandom();
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

## Random

Random类，调用Random方法可以进行随机数计算。调用前，需要通过[createRandom](#cryptoframeworkcreaterandom)构造Random实例。

### 属性

**系统能力：** SystemCapability.Security.CryptoFramework

| 名称    | 类型   | 可读 | 可写 | 说明                 |
| ------- | ------ | ---- | ---- | -------------------- |
| algName<sup>10+</sup> | string | 是   | 否   | 代表当前使用的随机数生成算法，目前只支持“CTR_DRBG"。 |

### generateRandom

generateRandom(len: number, callback: AsyncCallback\<DataBlob>): void

异步生成指定长度的随机数，通过注册回调函数返回。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名   | 类型                     | 必填 | 说明                 |
| -------- | ------------------------ | ---- | -------------------- |
| len      | number                   | 是   | 表示生成随机数的长度，单位为byte，范围在[1, INT_MAX]。 |
| callback | AsyncCallback\<[DataBlob](#datablob)> | 是   | 回调函数，用于获取DataBlob数据。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.          |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let rand = cryptoFramework.createRandom();
rand.generateRandom(12, (err, randData) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  } else {
    console.info('[Callback]: generate random result: ' + randData.data);
  }
});
```

### generateRandom

generateRandom(len: number): Promise\<DataBlob>

异步生成指定长度的随机数，通过Promise返回。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                   |
| ------ | ------ | ---- | ------------------------------------------------------ |
| len    | number | 是   | 表示生成随机数的长度，单位为byte，范围在[1, INT_MAX]。 |

**返回值：**

| 类型               | 说明        |
| ------------------ | ----------- |
| Promise\<[DataBlob](#datablob)> | Promise对象。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let rand = cryptoFramework.createRandom();
let promiseGenerateRand = rand.generateRandom(12);
promiseGenerateRand.then(randData => {
  console.info('[Promise]: rand result: ' + randData.data);
}).catch((error: BusinessError) => {
  console.error("[Promise]: error: " + error.message);
});
```

### generateRandomSync<sup>10+</sup>

generateRandomSync(len: number): DataBlob

同步生成指定长度的随机数。

**系统能力：** SystemCapability.Security.CryptoFramework

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| len    | number | 是   | 表示生成随机数的长度，单位为byte，范围在[1, INT_MAX]。 |

**返回值：**

| 类型               | 说明        |
| ------------------ | ----------- |
|[DataBlob](#datablob) | 表示生成的随机数。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息               |
| -------- | ---------------------- |
| 401 | invalid parameters.          |
| 17620001 | memory error.           |
| 17630001 | crypto operation error. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let rand = cryptoFramework.createRandom();
try {
  let randData = rand.generateRandomSync(12);
  if (randData != null) {
    console.info('[Sync]: rand result: ' + randData.data);
  } else {
    console.error("[Sync]: get rand result fail!");
  }
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`sync error, ${e.code}, ${e.message}`);
}
```

### setSeed

setSeed(seed: DataBlob): void

设置指定的种子。

**系统能力：** SystemCapability.Security.CryptoFramework

| 参数名 | 类型     | 必填 | 说明         |
| ------ | -------- | ---- | ------------ |
| seed   | DataBlob | 是   | 设置的种子。 |

**错误码：**
以下错误码的详细介绍请参见[crypto framework错误码](../errorcodes/errorcode-crypto-framework.md)

| 错误码ID | 错误信息           |
| -------- | ----------------- |
| 17620001 | memory error.      |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let rand = cryptoFramework.createRandom();
rand.generateRandom(12, (err, randData) => {
  if (err) {
    console.error("[Callback] err: " + err.code);
  } else {
    console.info('[Callback]: generate random result: ' + randData.data);
    try {
      rand.setSeed(randData);
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`sync error, ${e.code}, ${e.message}`);
    }
  }
});
```