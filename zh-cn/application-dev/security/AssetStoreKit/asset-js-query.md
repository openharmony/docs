# 查询关键资产(ArkTS)

## 接口介绍

可通过API文档查询新增关键资产的异步接口[query(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetquery)、同步接口[querySync(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetquerysync12)的详细介绍。

在查询关键资产时，关键资产属性的内容（AssetMap）参数如下表所示：
>**注意：**
>
>下表中名称包含“DATA_LABEL”的关键资产属性，用于存储业务自定义信息，其内容不会被加密，请勿存放个人数据。

| 属性名称（Tag）        | 属性内容（Value）                                             | 是否必选  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| ALIAS                 | 类型为Uint8Array，长度为1-256字节。                            | 可选     | 关键资产别名，每条关键资产的唯一索引。                       |
| ACCESSIBILITY         | 类型为number，取值范围详见[Accessibility](../../reference/apis-asset-store-kit/js-apis-asset.md#accessibility)。 | 可选     | 基于锁屏状态的访问控制。                                |
| REQUIRE_PASSWORD_SET  | 类型为bool。                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产。                 |
| AUTH_TYPE             | 类型为number，取值范围详见[AuthType](../../reference/apis-asset-store-kit/js-apis-asset.md#authtype)。 | 可选     | 访问关键资产所需的用户认证类型。                               |
| SYNC_TYPE             | 类型为number，取值范围详见[SyncType](../../reference/apis-asset-store-kit/js-apis-asset.md#synctype)。 | 可选     | 关键资产支持的同步类型。                                      |
| IS_PERSISTENT         | 类型为bool。                                                   | 可选     | 在应用卸载时是否需要保留关键资产。                             |
| DATA_LABEL_CRITICAL_1 | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br>**说明：** API12前长度为1-512字节。 |
| DATA_LABEL_CRITICAL_2 | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
| DATA_LABEL_CRITICAL_3 | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
| DATA_LABEL_CRITICAL_4 | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
| DATA_LABEL_NORMAL_1   | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
| DATA_LABEL_NORMAL_2   | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
| DATA_LABEL_NORMAL_3   | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
| DATA_LABEL_NORMAL_4   | 类型为Uint8Array，长度为1-2048字节。                        | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
| DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | 类型为Uint8Array，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
| DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | 类型为Uint8Array，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
| DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | 类型为Uint8Array，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
| DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | 类型为Uint8Array，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
| RETURN_TYPE           | 类型为number，取值范围详见[ReturnType](../../reference/apis-asset-store-kit/js-apis-asset.md#returntype)。 | 可选     | 关键资产查询返回的结果类型。             |
| RETURN_LIMIT          | 类型为number。                                                 | 可选     | 关键资产查询返回的结果数量。                                         |
| RETURN_OFFSET         | 类型为number，取值范围：1-65536。                              | 可选     | 关键资产查询返回的结果偏移量。<br>**说明：** 用于分批查询场景，指定从第几个开始返回。                                 |
| RETURN_ORDERED_BY     | 类型为number，取值范围：asset.Tag.DATA_LABEL_xxx。             | 可选     | 关键资产查询返回的结果排序依据，仅支持按照附属信息排序。<br>**说明：** 默认按照关键资产新增的顺序返回。 |
| REQUIRE_ATTR_ENCRYPTED<sup>13+</sup> | 类型为bool。 | 可选 | 是否查询业务自定义附属信息被加密的数据，默认查询业务附属信息不加密的数据。|

## 约束和限制

批量查询出的关键资产需要通过IPC通道传输给业务，受IPC缓冲区大小限制，建议对查询超过40条关键资产时，进行分批查询，且每次查询数量不超过40条。

## 代码示例

> **说明：**
>
> 本模块提供了异步和同步两套接口，以下为异步接口的使用示例，同步接口详见[API文档](../../reference/apis-asset-store-kit/js-apis-asset.md)。

### 查询单条关键资产明文

查询别名是demo_alias的关键资产明文。

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

function arrayToString(arr: Uint8Array): string {
  let textDecoder = util.TextDecoder.create("utf-8", { ignoreBOM: true });
  let str = textDecoder.decodeToString(arr, { stream: false })
  return str;
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias')); // 指定了关键资产别名，最多查询到一条满足条件的关键资产
query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ALL);  // 此处表示需要返回关键资产的所有信息，即属性+明文
try {
  asset.query(query).then((res: Array<asset.AssetMap>) => {
    for (let i = 0; i < res.length; i++) {
      // parse the secret.
      let secret: Uint8Array = res[i].get(asset.Tag.SECRET) as Uint8Array;
      // parse uint8array to string
      let secretStr: string = arrayToString(secret);
    }
  }).catch ((err: BusinessError) => {
    console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
}
```

### 查询单条关键资产属性

查询别名是demo_alias的关键资产属性。

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));       // 指定了关键资产别名，最多查询到一条满足条件的关键资产
query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ATTRIBUTES); // 此处表示仅返回关键资产属性，不包含关键资产明文
try {
  asset.query(query).then((res: Array<asset.AssetMap>) => {
    for (let i = 0; i < res.length; i++) {
      // parse the attribute.
      let accessibility: number = res[i].get(asset.Tag.ACCESSIBILITY) as number;
    }
  }).catch ((err: BusinessError) => {
    console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
}
```

### 批量查询关键资产属性

批量查询标签1是demo_label的关键资产属性，从第5条满足条件的结果开始返回，一共返回10条，且返回结果以DATA_LABEL_NORMAL_1属性内容排序。

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ATTRIBUTES); // 此处表示仅返回关键资产属性，不包含关键资产明文
query.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
query.set(asset.Tag.RETURN_OFFSET, 5); // 此处表示查询结果的偏移量，即从满足条件的第5条关键资产开始返回
query.set(asset.Tag.RETURN_LIMIT, 10); // 此处表示查询10条满足条件的关键资产
query.set(asset.Tag.RETURN_ORDERED_BY, asset.Tag.DATA_LABEL_NORMAL_1); // 此处查询结果以DATA_LABEL_NORMAL_1属性内容排序
try {
  asset.query(query).then((res: Array<asset.AssetMap>) => {
    for (let i = 0; i < res.length; i++) {
      // parse the attribute.
      let accessibility: number = res[i].get(asset.Tag.ACCESSIBILITY) as number;
    }
  }).catch ((err: BusinessError) => {
    console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
}
```
