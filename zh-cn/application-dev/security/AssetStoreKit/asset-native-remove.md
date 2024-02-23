# 删除关键资产(C/C++)

## 接口介绍

接口文档链接：

[int32_t OH_Asset_Remove(const Asset_Attr *query, uint32_t queryCnt)](../reference/native-apis/_asset_api.md#OH_Asset_Remove())

参数列表：

| 属性名称（Asset_Tag）            | 属性内容（Asset_Value）                                       | 是否必选 | 说明                                             |
| ------------------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------ |
| ASSET_TAG_ALIAS                 | 类型为uint8[]，长度为1-256字节                               | 可选     | 关键资产别名，每条关键资产的唯一索引;            |
| ASSET_TAG_ACCESSIBILITY         | 类型为uint32_t，取值范围详见[Asset_Accessibility](../reference/native-apis/_asset_type.md#asset_accessibility) | 可选     | 基于锁屏状态的访问控制                                     |
| ASSET_TAG_REQUIRE_PASSWORD_SET  | 类型为bool                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产     |
| ASSET_TAG_AUTH_TYPE             | 类型为uint32_t，取值范围详见[Asset_AuthType](../reference/native-apis/_asset_type.md#asset_authtype) | 可选     | 访问关键资产所需的用户认证类型                   |
| ASSET_TAG_SYNC_TYPE             | 类型为uint32_t，取值范围详见[Asset_SyncType](../reference/native-apis/_asset_type.md#asset_synctype) | 可选     | 关键资产支持的同步类型                           |
| ASSET_TAG_IS_PERSISTENT         | 类型为bool                                                   | 可选     | 在应用卸载时是否需要保留关键资产                 |
| ASSET_TAG_DATA_LABEL_CRITICAL_1 | 类型为uint8[]，长度为1-512字节                               | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| ASSET_TAG_DATA_LABEL_CRITICAL_2 | 类型为uint8[]，长度为1-512字节                               | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| ASSET_TAG_DATA_LABEL_CRITICAL_3 | 类型为uint8[]，长度为1-512字节                               | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| ASSET_TAG_DATA_LABEL_CRITICAL_4 | 类型为uint8[]，长度为1-512字节                               | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| ASSET_TAG_DATA_LABEL_NORMAL_1   | 类型为uint8[]，长度为1-512字节                               | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| ASSET_TAG_DATA_LABEL_NORMAL_2   | 类型为uint8[]，长度为1-512字节                               | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| ASSET_TAG_DATA_LABEL_NORMAL_3   | 类型为uint8[]，长度为1-512字节                               | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| ASSET_TAG_DATA_LABEL_NORMAL_4   | 类型为uint8[]，长度为1-512字节                               | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |

## 代码示例

删除别名是demo_alias的关键资产。

```c
#include <string.h>

#include "asset_api.h"

void RemoveAsset() {
    static const char *ALIAS = "demo_alias";
    Asset_Blob alias = { (uint32_t)(strlen(ALIAS)), (uint8_t *)ALIAS };

    Asset_Attr attr[] = {
        { .tag = ASSET_TAG_ALIAS, .value.blob = alias }, // 此处指定别名删除，也可不指定别名删除多条数据
    };

    int32_t ret = OH_Asset_Remove(attr, sizeof(attr) / sizeof(attr[0]));
    if (ret == ASSET_SUCCESS) {
        // Asset removed successfully.
    } else {
        // Failed to remove Asset.
    }
}
```

## 约束和限制

无
