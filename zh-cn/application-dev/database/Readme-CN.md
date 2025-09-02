# ArkData（方舟数据管理）
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @widecode-->
<!--Designer: @widecode-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->

- [ArkData简介](data-mgmt-overview.md)
- 标准化数据定义<!--uniform-data-definition-->
  - [标准化数据定义概述](unified-data-definition-overview.md)
  - [标准化数据类型 (ArkTS)](uniform-data-type-descriptors.md)
  - [标准化数据类型 (C/C++)](uniform-data-type-descriptors-c.md)
  - [标准化数据结构 (ArkTS)](uniform-data-structure.md)
  - [标准化数据结构 (C/C++)](uniform-data-structure-c.md)
  - [基于标准化数据结构的控件（ArkTS）](components-based-on-uniform-data-structure.md)
  - [Uniform Type Descriptor(UTD)预置类型列表](uniform-data-type-list.md)
- 应用数据持久化<!--app-data-persistence-->
  - [应用数据持久化概述](app-data-persistence-overview.md)
  - [通过用户首选项实现数据持久化 (ArkTS)](data-persistence-by-preferences.md)
  - [通过用户首选项实现数据持久化 (C/C++)](preferences-guidelines.md)
  - [通过键值型数据库实现数据持久化 (ArkTS)](data-persistence-by-kv-store.md)
  - [通过关系型数据库实现数据持久化 (ArkTS)](data-persistence-by-rdb-store.md)
  - [通过关系型数据库实现数据持久化 (C/C++)](native-relational-store-guidelines.md)
  - [通过向量数据库实现数据持久化 (ArkTS)](data-persistence-by-vector-store.md)
  - [通过向量数据库实现数据持久化 (C/C++)](native-vector-store-guidelines.md)
- 同应用跨设备数据同步（分布式）<!--distributed-data-sync-->
  - [同应用跨设备数据同步概述](sync-app-data-across-devices-overview.md)
  - [键值型数据库跨设备数据同步 (ArkTS)](data-sync-of-kv-store.md)
  - [关系型数据库跨设备数据同步 (ArkTS)](data-sync-of-rdb-store.md)
  - [分布式数据对象跨设备数据同步 (ArkTS)](data-sync-of-distributed-data-object.md)
- 数据可靠性与安全性<!--data-reliability-security-->
  - [数据可靠性与安全性概述](data-reliability-security-overview.md)
  - [数据库备份与恢复 (ArkTS)](data-backup-and-restore.md)
  - [数据库备份与恢复 (C/C++)](native-backup-and-restore.md)
  - [数据库加密 (ArkTS)](data-encryption.md)
  - [数据库加密 (C/C++)](native-data-encryption.md)
  - [基于设备分类和数据分级的访问控制 (ArkTS)](access-control-by-device-and-data-level.md)
  - [基于设备分类和数据分级的访问控制 (C/C++)](native-access-control-by-device-and-data-level.md)
  - [E类加密数据库的使用 (ArkTS)](encrypted_estore_guidelines.md)
- 跨应用数据共享<!--cross-app-data-share-->
  - [跨应用数据共享概述](data-share-overview.md)
  - 一对多跨应用数据共享<!--one-to-many-data-share-->
    <!--Del-->
    - [通过DataShareExtensionAbility实现数据共享 (ArkTS)(仅对系统应用开放)](share-data-by-datashareextensionability.md)
    - [通过数据管理服务实现数据共享静默访问 (ArkTS)(仅对系统应用开放)](share-data-by-silent-access.md)
    <!--DelEnd-->
    - [应用间配置共享 (ArkTS)](share-config.md)
  - 多对多跨应用数据共享<!--many-to-many-data-share-->
    - [通过标准化数据通路实现数据共享 (ArkTS)](unified-data-channels.md)
    - [通过标准化数据通路实现数据共享 (C/C++)](unified-data-channels-c.md)
- [应用数据向量化 (ArkTS)](aip-data-intelligence-embedding.md)
- [SQLite调试工具指导](sqlite-database-debug-tool.md)
- [ArkData术语](data-terminology.md)
