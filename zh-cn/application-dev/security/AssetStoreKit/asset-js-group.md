# 使用示例

可通过API文档查看此功能的相关接口：

| 异步接口 | 同步接口 | 说明 |
| ----- | ------ | ------- |
| [preQuery(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetprequery) | [preQuerySync(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetprequerysync12) | 查询预处理。|
| [query(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetquery) | [querySync(query: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetquerysync12) | 查询关键资产。|
| [postQuery(handle: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetpostquery) | [postQuerySync(handle: AssetMap)](../../reference/apis-asset-store-kit/js-apis-asset.md#assetpostquerysync12) | 查询后置处理。 |

## 新增群组关键资产

业务HAP在BMS配置了一个群组ID：demo_group_id。在群组中新增一条密码是demo_pwd，别名是demo_alias，附属信息是demo_label的关键资产，该关键资产在用户首次解锁设备后可被访问。

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let attr: asset.AssetMap = new Map();
attr.set(asset.Tag.SECRET, stringToArray('demo_pwd'));
attr.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
attr.set(asset.Tag.ACCESSIBILITY, asset.Accessibility.DEVICE_FIRST_UNLOCKED);
attr.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
attr.set(asset.Tag.GROUP_ID, stringToArray('demo_group_id'));
try {
  asset.add(attr).then(() => {
    console.info(`Asset added to the group successfully.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to add Asset to the group. Code is ${err.code}, message is ${err.message}`);
  })
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to add Asset to the group. Code is ${err.code}, message is ${err.message}`);
}
```

## 删除群组关键资产

业务HAP在BMS配置了一个群组ID：demo_group_id。在群组中删除一条别名是demo_alias的关键资产。

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias')); // 此处指定别名删除单条数据，也可不指定别名删除多条数据
query.set(asset.Tag.GROUP_ID, stringToArray('demo_group_id'));
try {
  asset.remove(query).then(() => {
    console.info(`Asset removed from the group successfully.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to remove Asset from the group. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to remove Asset from the group. Code is ${err.code}, message is ${err.message}`);
}
```

## 更新群组关键资产

业务HAP在BMS配置了一个群组ID：demo_group_id。在群组中更新别名是demo_alias的关键资产，将关键资产明文更新为demo_pwd_new，附属属性更新成demo_label_new。

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
query.set(asset.Tag.GROUP_ID, stringToArray('demo_group_id'));
let attrsToUpdate: asset.AssetMap = new Map();
attrsToUpdate.set(asset.Tag.SECRET, stringToArray('demo_pwd_new'));
attrsToUpdate.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label_new'));
try {
  asset.update(query, attrsToUpdate).then(() => {
    console.info(`Asset in the group updated successfully.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to update Asset in the group. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to update Asset in the group. Code is ${err.code}, message is ${err.message}`);
}
```

## 查询单条群组关键资产明文

业务HAP在BMS配置了一个群组ID：demo_group_id。在群组中查询别名是demo_alias的关键资产明文。

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
query.set(asset.Tag.ALIAS, stringToArray('demo_alias')); // 指定了群组关键资产别名，最多查询到一条满足条件的群组关键资产
query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ALL);  // 此处表示需要返回群组关键资产的所有信息，即属性+明文
query.set(asset.Tag.GROUP_ID, stringToArray('demo_group_id'));
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

## 查询单条群组关键资产属性

业务HAP在BMS配置了一个群组ID：demo_group_id。在群组中查询别名是demo_alias的关键资产属性。

```typescript
import { asset } from '@kit.AssetStoreKit';
import { util } from '@kit.ArkTS';
import { BusinessError } from '@kit.BasicServicesKit';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));       // 指定了群组关键资产别名，最多查询到一条满足条件的群组关键资产
query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ATTRIBUTES); // 此处表示仅返回群组关键资产属性，不包含群组关键资产明文
query.set(asset.Tag.GROUP_ID, stringToArray('demo_group_id'));
try {
  asset.query(query).then((res: Array<asset.AssetMap>) => {
    for (let i = 0; i < res.length; i++) {
      // parse the attribute.
      let accessibility: number = res[i].get(asset.Tag.ACCESSIBILITY) as number;
    }
  }).catch ((err: BusinessError) => {
    console.error(`Failed to query Asset from the group. Code is ${err.code}, message is ${err.message}`);
  });
} catch (error) {
  let err = error as BusinessError;
  console.error(`Failed to query Asset from the group. Code is ${err.code}, message is ${err.message}`);
}
```
