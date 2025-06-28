# 同步（备份恢复）关键资产(C/C++)


## 添加依赖

在CMake脚本中链接相关动态库。
```txt
target_link_libraries(entry PUBLIC libasset_ndk.z.so)
```

## 新增支持同步的关键资产

新增密码demo_pwd（别名demo_alias），附属信息为demo_label，支持同步的关键资产。

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
        { .tag = ASSET_TAG_SECRET, .value.blob = secret },
        { .tag = ASSET_TAG_ALIAS, .value.blob = alias },
        { .tag = ASSET_TAG_DATA_LABEL_NORMAL_1, .value.blob = label },
        { .tag = ASSET_TAG_SYNC_TYPE, .value.u32 = ASSET_SYNC_TYPE_TRUSTED_DEVICE }, // 需指定在可信设备间同步（如新旧设备间克隆）。
    };

    int32_t ret = OH_Asset_Add(attr, sizeof(attr) / sizeof(attr[0]));
    if (ret == ASSET_SUCCESS) {
        // 添加支持同步的关键资产成功。
    } else {
        // 添加支持同步的关键资产失败。
    }
}
```

## 接入备份恢复扩展能力

为触发应用数据备份恢复，需要[应用接入数据备份恢复](../../file-management/app-file-backup-extension.md)。

## 查询关键资产同步结果

### 接口介绍

通过API文档查看查询关键资产同步结果接口OH_Asset_QuerySyncResult。

在查询关键资产时，关键资产属性的内容参数如下表所示。

| 属性名称（Asset_Tag）            | 属性内容（Asset_Value）                                       | 是否必选 | 说明                                                         |
| ------------------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| ASSET_TAG_REQUIRE_ATTR_ENCRYPTED<sup>14+</sup> | 类型为bool。 | 是 | 是否查询业务自定义附属信息被加密的关键资产同步结果。true表示查询业务自定义附属信息加密存储的关键资产同步结果，false表示查询业务自定义附属信息不加密存储的关键资产同步结果。默认值为false。|
| ASSET_TAG_GROUP_ID<sup>18+</sup> | 类型为uint8[]，长度为7-127字节。 | 是 | 待查询的关键资产所属群组，默认查询不属于任何群组的关键资产同步结果。|


### 代码示例

```c
#include <string.h>

#include "asset/asset_api.h"

void QuerySyncResults() {
    Asset_SyncResult syncResult = {0};
    int32_t ret = OH_Asset_QuerySyncResult(NULL, 0, &syncResult);
    if (ret == ASSET_SUCCESS) {
        // 查询关键资产同步结果成功。
    } else {
        // 查询关键资产同步结果失败。
    }
}
```

## 约束和限制

在可信设备间同步过程中，新旧设备的关键资产均需处于可访问的状态，否则可能出现关键资产无法同步的情况。

* 仅设置密码时可访问的关键资产，如果新旧设备中任意一台设备未设置锁屏密码，则无法同步成功。
  
* 仅屏幕处于解锁状态时可访问的关键资产，如果新旧设备中任意一台设备的屏幕未处于解锁状态，则无法同步成功。

* 仅用户认证通过后可访问的关键资产，如果旧设备未设置锁屏密码，则无法同步成功。
