# 同步（备份恢复）关键资产(ArkTS)

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @JeremyXu-->
<!--Designer: @skye_you-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

## 新增支持同步的关键资产

新增密码demo_pwd（别名demo_alias），附属信息为demo_label，支持同步的关键资产。

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
attr.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
attr.set(asset.Tag.SYNC_TYPE, asset.SyncType.TRUSTED_DEVICE); // 需指定在可信设备间同步（如新旧设备间克隆）。

try {
  asset.add(attr).then(() => {
    console.info(`Succeeded in adding Asset with sync.`);
  }).catch((err: BusinessError) => {
    console.error(`Failed to add Asset with sync. Code is ${err.code}, message is ${err.message}`);
  })
} catch (err) {
  console.error(`Failed to add Asset with sync. Code is ${err?.code}, message is ${err?.message}`);
}
```

## 接入备份恢复扩展能力

为触发应用数据备份恢复，需要[应用接入数据备份恢复](../../file-management/app-file-backup-extension.md)。

## 查询关键资产同步结果

### 接口介绍

通过API文档查看查询关键资产同步结果接口[asset.querySyncResult](../../reference/apis-asset-store-kit/js-apis-asset.md#assetquerysyncresult20)。

在查询关键资产同步结果时，关键资产属性的内容（AssetMap）参数如下表所示。

| 属性名称（Tag）        | 属性内容（Value）                                             | 是否可选  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | 类型为boolean。 | 是 | 是否查询业务自定义附属信息被加密的关键资产同步结果。true表示查询业务自定义附属信息加密存储的关键资产同步结果，false表示查询业务自定义附属信息不加密存储的关键资产同步结果。默认值为false。|
| GROUP_ID<sup>18+</sup> | 类型为Uint8Array，长度为7-127字节。 | 是 | 待查询的关键资产所属群组，默认查询不属于任何群组的关键资产同步结果。|

### 代码示例

```typescript
import { asset } from '@kit.AssetStoreKit';
import { BusinessError } from '@kit.BasicServicesKit';

let query: asset.AssetMap = new Map();
asset.querySyncResult(query).then((res: asset.SyncResult) => {
  console.info(`Succeeded in querying sync result: ${JSON.stringify(res)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to query sync result of Asset. Code is ${err.code}, message is ${err.message}`);
});
```

## 约束和限制

在可信设备间同步过程中，新旧设备的关键资产均需处于可访问的状态，否则可能出现关键资产无法同步的情况。

- 仅设置密码时可访问的关键资产，如果新旧设备中任意一台设备未设置锁屏密码，则无法同步成功。
  
- 仅屏幕处于解锁状态时可访问的关键资产，如果新旧设备中任意一台设备的屏幕未处于解锁状态，则无法同步成功。

- 仅用户认证通过后可访问的关键资产，如果旧设备未设置锁屏密码，则无法同步成功。

