# 查询关键资产(C/C++)

<!--Kit: Asset Store Kit-->
<!--Subsystem: Security-->
<!--Owner: @JeremyXu-->
<!--Designer: @skye_you-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

## 接口介绍

可通过API文档查看查询关键资产的接口[OH_Asset_Query](../../reference/apis-asset-store-kit/capi-asset-api-h.md#oh_asset_query)
的详细介绍。

在查询关键资产时，关键资产属性的内容参数如下表所示：

>**注意：**
>
>下表中名称包含“ASSET_TAG_DATA_LABEL”的关键资产属性，用于存储业务自定义信息，其内容不会被加密，请勿存放个人数据。

| 属性名称（Asset_Tag）            | 属性内容（Asset_Value）                                       | 是否必选 | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| ASSET_TAG_ALIAS                 | 类型为uint8[]，长度为1-256字节。                               | 可选     | 关键资产别名，每条关键资产的唯一索引。                       |
| ASSET_TAG_ACCESSIBILITY         | 类型为uint32_t，取值范围详见[Asset_Accessibility](../../reference/apis-asset-store-kit/capi-asset-type-h.md#asset_accessibility)。 | 可选     | 基于锁屏状态的访问控制。                                                 |
| ASSET_TAG_REQUIRE_PASSWORD_SET  | 类型为bool。                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产。为true时表示查询仅用户设置了锁屏密码才允许访问的关键资产；为false时表示查询无论用户是否设置锁屏密码，均可访问的关键资产。                 |
| ASSET_TAG_AUTH_TYPE             | 类型为uint32_t，取值范围详见[Asset_AuthType](../../reference/apis-asset-store-kit/capi-asset-type-h.md#asset_authtype)。 | 可选     | 访问关键资产所需的用户认证类型。                               |
| ASSET_TAG_SYNC_TYPE             | 类型为uint32_t，取值范围详见[Asset_SyncType](../../reference/apis-asset-store-kit/capi-asset-type-h.md#asset_synctype)。 | 可选     | 关键资产支持的同步类型。                                       |
| ASSET_TAG_IS_PERSISTENT         | 类型为bool。                                                   | 可选     | 在应用卸载时是否需要保留关键资产。为true时表示查询应用卸载后会被保留的关键资产；为false时表示查询应用卸载后会被删除的关键资产。                            |
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
| ASSET_TAG_RETURN_TYPE           | 类型为uint32_t，取值范围详见[Asset_ReturnType](../../reference/apis-asset-store-kit/capi-asset-type-h.md#asset_returntype)。 | 可选     | 关键资产查询返回的结果类型。                                         |
| ASSET_TAG_RETURN_LIMIT          | 类型为uint32_t。                                               | 可选     | 关键资产查询返回的结果数量。                                         |
| ASSET_TAG_RETURN_OFFSET         | 类型为uint32_t，取值范围：1-65536。                            | 可选     | 关键资产查询返回的结果偏移量。<br>**说明：** 用于分批查询场景，指定从第几个开始返回。                  |
| ASSET_TAG_RETURN_ORDERED_BY     | 类型为uint32_t，取值范围：ASSET_TAG_DATA_LABEL_xxx。           | 可选     | 关键资产查询返回的结果排序依据，仅支持按照附属信息排序。<br>**说明：** 默认按照关键资产新增的顺序返回。 |
| ASSET_TAG_REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | 类型为bool。 | 可选 | 是否查询业务自定义附属信息被加密的数据。为true时表示查询业务自定义附属信息加密存储的数据，为false时表示查询业务自定义附属信息不加密存储的数据。默认值为false。|
| ASSET_TAG_GROUP_ID<sup>18+</sup> | 类型为uint8[]，长度为7-127字节。 | 可选 | 待查询的关键资产所属群组，默认查询不属于任何群组的关键资产。|

## 约束和限制

批量查询出的关键资产需要通过IPC通道传输给业务，受IPC缓冲区大小限制，建议对查询超过40条关键资产时，进行分批查询，且每次查询数量不超过40条。

## 代码示例

### 查询单条关键资产明文

查询别名是demo_alias的关键资产明文。

在指定群组中查询一条关键资产明文的示例代码详见[查询单条群组关键资产明文](asset-native-group-access-control.md#查询单条群组关键资产明文)。

1. 在CMake脚本中链接相关动态库。
   ```txt
   target_link_libraries(entry PUBLIC libasset_ndk.z.so)
   ```

2. 参考如下示例代码，进行业务功能开发。
   ```c
   #include <string.h>

   #include "asset/asset_api.h"

   void QueryAsset() {
       static const char *ALIAS = "demo_alias";
       Asset_Blob alias = {(uint32_t)(strlen(ALIAS)), (uint8_t *)ALIAS};
       Asset_Attr attr[] = {
           {.tag = ASSET_TAG_ALIAS, .value.blob = alias}, // 指定了关键资产别名，最多查询到一条满足条件的关键资产。
           {.tag = ASSET_TAG_RETURN_TYPE, .value.u32 = ASSET_RETURN_ALL}, // 此处表示需要返回关键资产的所有信息，即属性+明文。
       };

       Asset_ResultSet resultSet = {0};
       int32_t ret = OH_Asset_Query(attr, sizeof(attr) / sizeof(attr[0]), &resultSet);
       if (ret == ASSET_SUCCESS) {
           // 解析resultSet。
           for (uint32_t i = 0; i < resultSet.count; i++) {
                // 解析secret属性：其中data数据对应是secret->blob.data，长度对应是secret->blob.size。
                Asset_Attr *secret = OH_Asset_ParseAttr(resultSet.results + i, ASSET_TAG_SECRET);
           }
       }
       OH_Asset_FreeResultSet(&resultSet);
   }
   ```

### 查询单条关键资产属性

查询别名是demo_alias的关键资产属性。

在指定群组中查询一条关键资产属性的示例代码详见[查询单条群组关键资产属性](asset-native-group-access-control.md#查询单条群组关键资产属性)。

1. 在CMake脚本中链接相关动态库。
   ```txt
   target_link_libraries(entry PUBLIC libasset_ndk.z.so)
   ```

2. 参考如下示例代码，进行业务功能开发。
   ```c
   #include <string.h>

   #include "asset/asset_api.h"

   void QueryAttributes() {
       static const char *ALIAS = "demo_alias";
       Asset_Blob alias = { (uint32_t)(strlen(ALIAS)), (uint8_t *)ALIAS };
       Asset_Attr attr[] = {
           {.tag = ASSET_TAG_ALIAS, .value.blob = alias}, // 指定了关键资产别名，最多查询到一条满足条件的关键资产。
           {.tag = ASSET_TAG_RETURN_TYPE, .value.u32 = ASSET_RETURN_ATTRIBUTES}, // 此处表示仅返回关键资产属性，不包含关键资产明文。
       };

       Asset_ResultSet resultSet = {0};
       int32_t ret = OH_Asset_Query(attr, sizeof(attr) / sizeof(attr[0]), &resultSet);
       if (ret == ASSET_SUCCESS) {
           // 解析结果。
           for (uint32_t i = 0; i < resultSet.count; i++) {
               // 解析数据标签：其中数据是label->blob.data，长度对应是label->blob.size。
               Asset_Attr *label = OH_Asset_ParseAttr(resultSet.results + i, ASSET_TAG_DATA_LABEL_NORMAL_1);
           }
       }
       OH_Asset_FreeResultSet(&resultSet);
   }
   ```

### 批量查询关键资产属性

批量查询附属信息是demo_label的关键资产属性，从第5条满足条件的结果开始返回，一共返回10条，且返回结果以DATA_LABEL_NORMAL_1属性内容排序。

1. 在CMake脚本中链接相关动态库。
   ```txt
   target_link_libraries(entry PUBLIC libasset_ndk.z.so)
   ```

2. 参考如下示例代码，进行业务功能开发。
   ```c
   #include <string.h>

   #include "asset/asset_api.h"

   void BatchQuery() {
       static const char *LABEL = "demo_label";
       Asset_Blob label = {(uint32_t)(strlen(LABEL)), (uint8_t *)LABEL};

       Asset_Attr attr[] = {
           {.tag = ASSET_TAG_RETURN_TYPE, .value.u32 = ASSET_RETURN_ATTRIBUTES},
           {.tag = ASSET_TAG_DATA_LABEL_NORMAL_1, .value.blob = label},
           {.tag = ASSET_TAG_RETURN_OFFSET, .value.u32 = 5},
           {.tag = ASSET_TAG_RETURN_LIMIT, .value.u32 = 10},
           {.tag = ASSET_TAG_RETURN_ORDERED_BY, .value.u32 = ASSET_TAG_DATA_LABEL_NORMAL_1},
       };

       Asset_ResultSet resultSet = { 0 };
       int32_t ret = OH_Asset_Query(attr, sizeof(attr) / sizeof(attr[0]), &resultSet);
       if (ret == ASSET_SUCCESS) {
           // 解析结果。
           for (uint32_t i = 0; i < resultSet.count; i++) {
               // 解析数据别名：其中别名是label->blob.data，长度对应是label->blob.size。
               Asset_Attr *alias = OH_Asset_ParseAttr(resultSet.results + i, ASSET_TAG_ALIAS);
           }
       }
       OH_Asset_FreeResultSet(&resultSet);
   }
   ```
