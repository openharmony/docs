# 查询关键资产(ArkTS)

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @JeremyXu-->
<!--Designer: @skye_you-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

## 接口介绍

可通过API文档查询新增关键资产的异步接口[query(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetquery)、同步接口[querySync(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetquerysync12)的详细介绍。

在查询关键资产时，关键资产属性的内容（AssetMap）参数如下表所示：
> **注意：**
>
> 下表中“ALIAS”和名称包含“DATA_LABEL”的关键资产属性，用于存储业务自定义信息，其内容不会被加密，请勿存放敏感个人数据。
> 查询关键资产明文SECRET需要解密，查询时间较长，需要将RETURN_TYPE设置为ALL；只查询其他关键资产属性不需解密，查询时间较短，需要将RETURN_TYPE设置为ATTRIBUTES。

| 属性名称（Tag）        | 属性内容（Value）                                             | 是否必选  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| ALIAS                 | 类型为Uint8Array，长度为1-256字节。                            | 可选     | 关键资产别名，每条关键资产的唯一索引。                       |
| ACCESSIBILITY         | 类型为number，取值范围详见[Accessibility](../../reference/apis-asset-store-kit/js-apis-asset.md#accessibility)。 | 可选     | 基于锁屏状态的访问控制。                                |
| REQUIRE_PASSWORD_SET  | 类型为boolean。                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产。为true时表示查询仅用户设置了锁屏密码才允许访问的关键资产；为false时表示查询无论用户是否设置锁屏密码，均可访问的关键资产。                 |
| AUTH_TYPE             | 类型为number，取值范围详见[AuthType](../../reference/apis-asset-store-kit/js-apis-asset.md#authtype)。 | 可选     | 访问关键资产所需的用户认证类型。                               |
| SYNC_TYPE             | 类型为number，取值范围详见[SyncType](../../reference/apis-asset-store-kit/js-apis-asset.md#synctype)。 | 可选     | 关键资产支持的同步类型。                                      |
| IS_PERSISTENT         | 类型为boolean。                                                   | 可选     | 在应用卸载时是否需要保留关键资产。为true时表示查询应用卸载后会被保留的关键资产；为false时表示查询应用卸载后会被删除的关键资产。               |
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
| RETURN_OFFSET         | 类型为number，取值范围：1-65536。                              | 可选     | 关键资产查询返回的结果偏移量。<br>**说明：** 用于分批查询场景时，指定从第几个结果开始返回。                                 |
| RETURN_ORDERED_BY     | 类型为number，取值范围：asset.Tag.DATA_LABEL_xxx。             | 可选     | 关键资产查询返回的结果排序依据，仅支持按照附属信息排序。<br>**说明：** 默认按照关键资产新增的顺序返回。 |
| REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | 类型为boolean。 | 可选 | 是否查询业务自定义附属信息被加密的数据。为true时表示查询业务自定义附属信息加密存储的数据，为false时表示查询业务自定义附属信息不加密存储的数据。默认值为false。|
| GROUP_ID<sup>18+</sup> | 类型为Uint8Array，长度为7-127字节。 | 可选 | 待查询的关键资产所属群组，默认查询不属于任何群组的关键资产。|

## 约束和限制

批量查询的关键资产需要通过IPC通道传输给业务。由于IPC缓冲区大小的限制，建议当查询超过40条关键资产时，进行分批查询，每次查询数量不超过40条。

## 代码示例

> **说明：**
>
> 本模块提供了异步和同步两套接口，以下为异步接口的使用示例，同步接口详见[API文档](../../reference/apis-asset-store-kit/js-apis-asset.md)。
>
> 在指定群组中查询一条关键资产明文的使用示例详见[查询单条群组关键资产明文](asset-js-group-access-control.md#查询单条群组关键资产明文)，在指定群组中查询一条关键资产属性的使用示例详见[查询单条群组关键资产属性](asset-js-group-access-control.md#查询单条群组关键资产属性)。

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
query.set(asset.Tag.ALIAS, stringToArray('demo_alias')); // 指定了关键资产别名，最多查询到一条满足条件的关键资产。
query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ALL); // 此处表示需要返回关键资产的所有信息，即属性+明文。返回明文需要解密，查询时间较长。
try {
  asset.query(query).then((res: Array<asset.AssetMap>) => {
    for (let i = 0; i < res.length; i++) {
      // 解析secret。
      let secret: Uint8Array = res[i].get(asset.Tag.SECRET) as Uint8Array;
      // 将Uint8Array转为string类型。
      let secretStr: string = arrayToString(secret);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (err) {
  console.error(`Failed to query Asset. Code is ${err?.code}, message is ${err?.message}`);
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
query.set(asset.Tag.ALIAS, stringToArray('demo_alias')); // 指定了关键资产别名，最多查询到一条满足条件的关键资产。
query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ATTRIBUTES); // 此处表示仅返回关键资产属性，不包含关键资产明文。返回属性不需解密，查询时间较短。
try {
  asset.query(query).then((res: Array<asset.AssetMap>) => {
    for (let i = 0; i < res.length; i++) {
      // 解析属性。
      let accessibility: number = res[i].get(asset.Tag.ACCESSIBILITY) as number;
      console.info(`Succeeded in getting accessibility, which is: ${accessibility}.`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (err) {
  console.error(`Failed to query Asset. Code is ${err?.code}, message is ${err?.message}`);
}
```

### 批量查询关键资产属性

批量查询标签1为demo_label的关键资产属性，从第5条符合条件的结果开始返回，共返回10条，结果按DATA_LABEL_NORMAL_1属性内容排序。

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ATTRIBUTES); // 此处表示仅返回关键资产属性，不包含关键资产明文。
query.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
query.set(asset.Tag.RETURN_LIMIT, 10); // 此处表示查询10条满足条件的关键资产。
query.set(asset.Tag.RETURN_ORDERED_BY, asset.Tag.DATA_LABEL_NORMAL_1); // 此处查询结果以DATA_LABEL_NORMAL_1属性内容排序。
try {
  asset.query(query).then((res: Array<asset.AssetMap>) => {
    for (let i = 0; i < res.length; i++) {
      // 解析属性。
      let accessibility: number = res[i].get(asset.Tag.ACCESSIBILITY) as number;
      console.info(`Succeeded in getting accessibility, which is: ${accessibility}.`);
    }
  }).catch((err: BusinessError) => {
    console.error(`Failed to query Asset. Code is ${err.code}, message is ${err.message}`);
  });
} catch (err) {
  console.error(`Failed to query Asset. Code is ${err?.code}, message is ${err?.message}`);
}
```
