# 更新关键资产(C/C++)

## 接口介绍

可通过API文档查看更新关键资产的接口[OH_Asset_Update](../../reference/apis-asset-store-kit/_asset_api.md#oh_asset_update)的详细介绍。

在更新关键资产时，关键资产属性的内容参数如下表所示：

>**注意：**
>
>下表中名称包含“ASSET_TAG_DATA_LABEL”的关键资产属性，用于存储业务自定义信息，其内容不会被加密，请勿存放个人数据。

- **query的参数列表：**

  | 属性名称（Asset_Tag）            | 属性内容（Asset_Value）                                       | 是否必选 | 说明                                             |
  | ------------------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------ |
  | ASSET_TAG_ALIAS                 | 类型为uint8[]，长度为1-256字节。                               | 必选     | 关键资产别名，每条关键资产的唯一索引。            |
  | ASSET_TAG_ACCESSIBILITY         | 类型为uint32_t，取值范围详见[Asset_Accessibility](../../reference/apis-asset-store-kit/_asset_type.md#asset_accessibility)。 | 可选     | 基于锁屏状态的访问控制。                                     |
  | ASSET_TAG_REQUIRE_PASSWORD_SET  | 类型为bool。                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产。     |
  | ASSET_TAG_AUTH_TYPE             | 类型为uint32_t，取值范围详见[Asset_AuthType](../../reference/apis-asset-store-kit/_asset_type.md#asset_authtype)。 | 可选     | 访问关键资产所需的用户认证类型。                   |
  | ASSET_TAG_SYNC_TYPE             | 类型为uint32_t，取值范围详见[Asset_SyncType](../../reference/apis-asset-store-kit/_asset_type.md#asset_synctype)。 | 可选     | 关键资产支持的同步类型。                           |
  | ASSET_TAG_IS_PERSISTENT         | 类型为bool。                                                   | 可选     | 在应用卸载时是否需要保留关键资产。                 |
  | ASSET_TAG_DATA_LABEL_CRITICAL_1 | 类型为uint8[]，长度为1-2048字节。                           | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_CRITICAL_2 | 类型为uint8[]，长度为1-2048字节。                           | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_CRITICAL_3 | 类型为uint8[]，长度为1-2048字节。                           | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_CRITICAL_4 | 类型为uint8[]，长度为1-2048字节。                           | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_1   | 类型为uint8[]，长度为1-2048字节。                           | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_2   | 类型为uint8[]，长度为1-2048字节。                           | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_3   | 类型为uint8[]，长度为1-2048字节。                           | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_4   | 类型为uint8[]，长度为1-2048字节。                           | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | 类型为uint8[]，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | 类型为uint8[]，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | 类型为uint8[]，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | 类型为uint8[]，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
  | ASSET_TAG_REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | 类型为bool。 | 可选 | 是否更新业务自定义附属信息被加密的数据，默认更新业务附属信息不加密的数据。|
  | ASSET_TAG_GROUP_ID<sup>16+</sup> | 类型为uint8[]，长度为7-127字节。 | 可选 | 待更新的关键资产所属群组，默认更新不属于任何群组的关键资产。|

- **attributesToUpdate的参数列表：**

  | 属性名称（Asset_Tag）| 属性内容（Asset_Value）          | 是否必选 | 说明                                             |
  | ------------------- | ------------------------------- | -------- | ------------------------------------------------ |
  | ASSET_TAG_SECRET    | 类型为uint8[]，长度为1-1024字节。 | 可选     | 关键资产明文。                                     |
  | ASSET_TAG_DATA_LABEL_NORMAL_1 | 类型为uint8[]，长度为1-2048字节。 | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_2 | 类型为uint8[]，长度为1-2048字节。 | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_3 | 类型为uint8[]，长度为1-2048字节。 | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_4 | 类型为uint8[]，长度为1-2048字节。 | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护。<br/>**说明：** API12前长度为1-512字节。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_1<sup>12+</sup> | 类型为uint8[]，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_2<sup>12+</sup> | 类型为uint8[]，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_3<sup>12+</sup> | 类型为uint8[]，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |
  | ASSET_TAG_DATA_LABEL_NORMAL_LOCAL_4<sup>12+</sup> | 类型为uint8[]，长度为1-2048字节。 | 可选 | 关键资产附属的本地信息，内容由业务自定义且无完整性保护，该项信息不会进行同步。 |

## 代码示例

更新别名是demo_alias的关键资产，将关键资产明文更新为demo_pwd_new，附属信息更新成demo_label_new。

在指定群组中更新一条关键资产的示例代码详见[更新群组关键资产](asset-native-group-access-control.md#更新群组关键资产)。

1. 在CMake脚本中链接相关动态库
   ```txt
   target_link_libraries(entry PUBLIC libasset_ndk.z.so)
   ```

2. 参考如下示例代码，进行业务功能开发
   ```c
   #include <string.h>

   #include "asset/asset_api.h"

   void UpdateAsset() {
      static const char *ALIAS = "demo_alias";
      static const char *SECRET = "demo_pwd_new";
      static const char *LABEL = "demo_label_new";

      Asset_Blob alias = { (uint32_t)(strlen(ALIAS)), (uint8_t *)ALIAS };
      Asset_Blob new_secret = { (uint32_t)(strlen(SECRET)), (uint8_t *)SECRET };
      Asset_Blob new_label = { (uint32_t)(strlen(LABEL)), (uint8_t *)LABEL };
      Asset_Attr query[] = { { .tag = ASSET_TAG_ALIAS, .value.blob = alias } };
      Asset_Attr attributesToUpdate[] = {
         { .tag = ASSET_TAG_SECRET, .value.blob = new_secret },
         { .tag = ASSET_TAG_DATA_LABEL_NORMAL_1, .value.blob = new_label },
      };

      int32_t ret = OH_Asset_Update(query, sizeof(query) / sizeof(query[0]), attributesToUpdate,
                                    sizeof(attributesToUpdate) / sizeof(attributesToUpdate[0]));
      if (ret == ASSET_SUCCESS) {
         // Asset updated successfully.
      } else {
         // Failed to update Asset.
      }
   }
   ```
