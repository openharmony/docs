# 删除关键资产(ArkTS)

## 接口介绍

接口文档链接：

[remove(query: AssetMap): Promise\<void>](../reference/apis/js-apis-asset.md#asset.remove)

参数列表：

| 属性名称（Tag）        | 属性内容（Value）                                             | 是否必选  | 说明                                             |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------ |
| ALIAS                 | 类型为Uint8Array，长度为1-256字节                            | 可选     | 关键资产别名，每条关键资产的唯一索引;            |
| ACCESSIBILITY         | 类型为number，取值范围详见[Accessibility](../reference/apis/js-apis-asset.md#accessibility) | 可选     | 基于锁屏状态的访问控制                                     |
| REQUIRE_PASSWORD_SET  | 类型为bool                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产     |
| AUTH_TYPE             | 类型为number，取值范围详见[AuthType](../reference/apis/js-apis-asset.md#authtype) | 可选     | 访问关键资产所需的用户认证类型                   |
| SYNC_TYPE             | 类型为number，取值范围详见[SyncType](../reference/apis/js-apis-asset.md#synctype) | 可选     | 关键资产支持的同步类型                           |
| IS_PERSISTENT         | 类型为bool                                                   | 可选     | 在应用卸载时是否需要保留关键资产                 |
| DATA_LABEL_CRITICAL_1 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_CRITICAL_2 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_CRITICAL_3 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_CRITICAL_4 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_NORMAL_1   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| DATA_LABEL_NORMAL_2   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| DATA_LABEL_NORMAL_3   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| DATA_LABEL_NORMAL_4   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |

## 代码示例

删除一条别名是demo_alias的关键资产。

```typescript
import { asset } from '@kit.AssetStoreKit';
import util from '@ohos.util';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

let query: asset.AssetMap = new Map();
query.set(asset.Tag.ALIAS, stringToArray('demo_alias')); // 此处指定别名删除单条数据，也可不指定别名删除多条数据
try {
  asset.remove(query).then(() => {
    console.info(`Asset removed successfully.`);
  }).catch(() => {
    console.error(`Failed to remove Asset.`);
  });
} catch (error) {
  console.error(`Failed to remove Asset.`);
}
```

## 约束和限制

无