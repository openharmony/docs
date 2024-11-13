# ArkData方舟数据管理子系统变更说明

## cl.kv_store.1 键值型数据库跨设备自动同步的使用场景变更

**访问级别**

公开接口。

**变更原因**

解决跨设备无效数据同步问题。

**变更影响**

该变更为不兼容变更。

变更前：使用autoSync配置为true的键值型数据库，进行数据增删改操作时，可自动触发向同一组网环境内的设备进行跨设备数据同步。

变更后：使用autoSync配置为true的键值型数据库，进行数据增删改操作时，可自动触发向同一组网环境内处于[多端协同](../../../application-dev/application-models/hop-multi-device-collaboration.md)状态下的设备进行跨设备数据同步。

**起始 API Level**

9

**变更发生的版本**

从OpenHarmony SDK 5.0.0.37开始。

**变更的接口/组件**

autoSync/分布式键值型数据库（distributedKVStore）

**适配指导**

键值型数据库的跨设备自动同步功能只支持在跨设备协同场景下使用。详见[键值型数据库跨设备同步开发指导](../../../application-dev/database/data-sync-of-kv-store.md)。
非跨设备协同场景下，请不要使用键值型数据跨设备自动同步功能，即autoSync需要设置为false，即使配置autoSync为true也不生效。
