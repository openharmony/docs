# 新增关键资产(C/C++)

## 接口介绍

可通过API文档查看新增关键资产的接口[OH_Asset_Add](../../reference/apis-asset-store-kit/_asset_api.md#oh_asset_add)的详细介绍。

在新增关键资产时，关键资产属性的内容参数如下表所示：

>**注意：**
>
>下表中名称包含“ASSET_TAG_DATA_LABEL”的关键资产属性，用于存储业务自定义信息，其内容不会被加密，请勿存放个人数据。

| 属性名称（Asset_Tag）            | 属性内容（Asset_Value）                                       | 是否必选 | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| ASSET_TAG_SECRET                | 类型为uint8[]，长度为1-1024字节。                              | 必选     | 关键资产明文。                                                 |
| ASSET_TAG_ALIAS                 | 类型为uint8[]，长度为1-256字节。                               | 必选     | 关键资产别名，每条关键资产的唯一索引。                         |
| ASSET_TAG_ACCESSIBILITY         | 类型为uint32_t，取值范围详见[Asset_Accessibility](../../reference/apis-asset-store-kit/_asset_type.md#asset_accessibility)。 | 可选     | 基于锁屏状态的访问控制。                                                 |
| ASSET_TAG_REQUIRE_PASSWORD_SET  | 类型为bool。                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产。                 |
| ASSET_TAG_AUTH_TYPE             | 类型为uint32_t，取值范围详见[Asset_AuthType](../../reference/apis-asset-store-kit/_asset_type.md#asset_authtype)。 | 可选     | 访问关键资产所需的用户认证类型。                               |
| ASSET_TAG_SYNC_TYPE             | 类型为uint32_t，取值范围详见[Asset_SyncType](../../reference/apis-asset-store-kit/_asset_type.md#asset_synctype)。 | 可选     | 关键资产支持的同步类型。                                       |
| ASSET_TAG_IS_PERSISTENT         | 类型为bool。                                                   | 可选     | 在应用卸载时是否需要保留关键资产。 <br>**注意：** 设置此属性时，需[申请权限](../AccessToken/declare-permissions.md)ohos.permission.STORE_PERSISTENT_DATA。|
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
| ASSET_TAG_CONFLICT_RESOLUTION   | 类型为uint32_t，取值范围详见[Asset_ConflictResolution](../../reference/apis-asset-store-kit/_asset_type.md#asset_conflictresolution)。 | 可选     | 新增关键资产时的冲突（如：别名相同）处理策略。                             |
| ASSET_TAG_REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | 类型为bool。 | 可选 | 是否加密业务自定义附属信息，默认不需要加密。|

## 约束和限制

* 基于别名的访问

  关键资产以密文的形式存储在ASSET数据库中，以业务身份 + 别名作为唯一索引。故业务需要保证每条关键资产的别名唯一。

* 业务自定义数据存储

  ASSET为业务预留了12个关键资产自定义属性，名称以"ASSET_TAG_DATA_LABEL"开头。对于超过12个自定义属性的情况，业务可以将多段数据按照一定的格式（如JSON）拼接到同一个ASSET属性中。

  ASSET对部分属性会进行完整性保护，这部分属性名称以"ASSET_TAG_DATA_LABEL_CRITICAL"开头，且写入后不支持更新。

## 代码示例

新增一条密码是demo_pwd，别名是demo_alias，附属信息是demo_label的数据，该数据在用户首次解锁设备后可被访问。

1. 在CMake脚本中链接相关动态库
   ```txt
   target_link_libraries(entry PUBLIC libasset_ndk.z.so)
   ```

2. 参考如下示例代码，进行业务功能开发
   ```c
   #include <string.h>

   #include "asset/asset_api.h"

   void AddAsset() {
      static const char *SECRET = "demo_pwd";
      static const char *ALIAS = "demo_alias";
      static const char *LABEL = "demo_label";

      Asset_Blob secret = { (uint32_t)(strlen(SECRET)), (uint8_t *)SECRET };
      Asset_Blob alias = { (uint32_t)(strlen(ALIAS)), (uint8_t *)ALIAS };
      Asset_Blob label = { (uint32_t)(strlen(LABEL)), (uint8_t *)LABEL };
      Asset_Attr attr[] = {
         { .tag = ASSET_TAG_ACCESSIBILITY, .value.u32 = ASSET_ACCESSIBILITY_DEVICE_FIRST_UNLOCKED },
         { .tag = ASSET_TAG_SECRET, .value.blob = secret },
         { .tag = ASSET_TAG_ALIAS, .value.blob = alias },
         { .tag = ASSET_TAG_DATA_LABEL_NORMAL_1, .value.blob = label },
      };

      int32_t ret = OH_Asset_Add(attr, sizeof(attr) / sizeof(attr[0]));
      if (ret == ASSET_SUCCESS) {
         // Asset added successfully.
      } else {
         // Failed to add Asset.
      }
   }
   ```
