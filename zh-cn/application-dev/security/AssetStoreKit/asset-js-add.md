# 新增关键资产(ArkTS)

## 接口介绍

接口文档链接：

[add(attributes: AssetMap): Promise\<void>](../reference/apis/js-apis-asset.md#asset.add)

参数列表：

| 属性名称（Tag）        | 属性内容（Value）                                             | 是否必选  | 说明                                                         |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| SECRET                | 类型为Uint8Array，长度为1-1024字节                           | 必选     | 关键资产明文                                              |
| ALIAS                 | 类型为Uint8Array，长度为1-256字节                            | 必选     | 关键资产别名，每条关键资产的唯一索引                        |
| ACCESSIBILITY         | 类型为number，取值范围详见[Accessibility](../reference/apis/js-apis-asset.md#accessibility) | 可选     | 基于锁屏状态的访问控制      |
| REQUIRE_PASSWORD_SET  | 类型为bool                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产              |
| AUTH_TYPE             | 类型为number，取值范围详见[AuthType](../reference/apis/js-apis-asset.md#authtype) | 可选     | 访问关键资产所需的用户认证类型         |
| SYNC_TYPE             | 类型为number，取值范围详见[SyncType](../reference/apis/js-apis-asset.md#synctype) | 可选     | 关键资产支持的同步类型                |
| IS_PERSISTENT         | 类型为bool                                                   | 可选     | 在应用卸载时是否需要保留关键资产<br>**需要权限：** ohos.permission.STORE_PERSISTENT_DATA |
| DATA_LABEL_CRITICAL_1 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护             |
| DATA_LABEL_CRITICAL_2 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护             |
| DATA_LABEL_CRITICAL_3 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护             |
| DATA_LABEL_CRITICAL_4 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护             |
| DATA_LABEL_NORMAL_1   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护             |
| DATA_LABEL_NORMAL_2   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护             |
| DATA_LABEL_NORMAL_3   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护             |
| DATA_LABEL_NORMAL_4   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护             |
| CONFLICT_RESOLUTION   | 类型为number，取值范围详见[ConflictResolution](../reference/apis/js-apis-asset.md#conflictresolution) | 可选     | 新增关键资产时的冲突（如：别名相同）处理策略                             |

## 代码示例

新增一条密码是demo_pwd，别名是demo_alias，附属信息是demo_label的数据，该数据在用户首次解锁设备后可被访问。

```typescript
import { asset } from '@kit.AssetStoreKit';
import util from '@ohos.util';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let attr: asset.AssetMap = new Map();
attr.set(asset.Tag.SECRET, stringToArray('demo_pwd'));
attr.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
attr.set(asset.Tag.ACCESSIBILITY, asset.Accessibility.DEVICE_FIRST_UNLOCKED);
attr.set(asset.Tag.DATA_LABEL_NORMAL_1, stringToArray('demo_label'));
try {
  asset.add(attr).then(() => {
    console.info(`Asset added successfully.`);
  }).catch(() => {
    console.error(`Failed to add Asset.`);
  })
} catch (error) {
  console.error(`Failed to add Asset.`);
}
```

## 约束和限制

* 基于别名的访问

关键资产以密文的形式存储在ASSET数据库中，以业务身份 + 别名作为唯一索引。故业务需要保证每条关键资产的别名唯一。

* 业务自定义数据存储

ASSET为业务预留了8个关键资产自定义属性，名称以"DATA_LABEL"开头。对于超过8个自定义属性的情况，业务可以将多段数据按照一定的格式（如JSON）拼接到同一个ASSET属性中。

ASSET对部分属性会进行完整性保护，这部分属性名称以"DATA_LABEL_CRITICAL"开头，写入后不支持更新。
