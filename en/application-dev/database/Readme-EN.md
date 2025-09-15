# ArkData (Ark Data Management)
<!--Kit: ArkData-->
<!--Subsystem: DistributedDataManager-->
<!--Owner: @widecode-->
<!--Designer: @widecode-->
<!--Tester: @logic42-->
<!--Adviser: @ge-yafang-->

- [Introduction to ArkData](data-mgmt-overview.md)
- Unified Data Definition<!--uniform-data-definition-->
  - [Unified Data Definition Overview](unified-data-definition-overview.md)
  - [UTDs (ArkTS)](uniform-data-type-descriptors.md)
  - [UTDs (C/C++)](uniform-data-type-descriptors-c.md)
  - [Uniform Data Structs (ArkTS)](uniform-data-structure.md)
  - [Uniform Data Structs (C/C++)](uniform-data-structure-c.md)
  - [Content Cards Based on Uniform Data Structs (ArkTS)](components-based-on-uniform-data-structure.md)
  - [Prebuilt UTDs](uniform-data-type-list.md)
- Application Data Persistence<!--app-data-persistence-->
  - [Application Data Persistence Overview](app-data-persistence-overview.md)
  - [Persisting User Preferences (ArkTS)](data-persistence-by-preferences.md)
  - [Persisting User Preferences (C/C++)](preferences-guidelines.md)
  - [Persisting KV Store Data (ArkTS)](data-persistence-by-kv-store.md)
  - [Persisting RDB Store Data (ArkTS)](data-persistence-by-rdb-store.md)
  - [Persisting RDB Store Data (C/C++)](native-relational-store-guidelines.md)
  - [Persisting Vector Store Data (ArkTS)](data-persistence-by-vector-store.md)
  - [Persisting Vector Store Data (C/C++)](native-vector-store-guidelines.md)
- Distributed Application Data Sync<!--distributed-data-sync-->
  - [Overview of Cross-Device Application Data Sync](sync-app-data-across-devices-overview.md)
  - [Cross-Device Sync of KV Stores (ArkTS)](data-sync-of-kv-store.md)
  - [Cross-Device Sync of RDB Stores (ArkTS)](data-sync-of-rdb-store.md)
  - [Cross-Device Sync of Distributed Data Objects (ArkTS)](data-sync-of-distributed-data-object.md)
- Data Reliability and Security<!--data-reliability-security-->
  - [Data Reliability and Security Overview](data-reliability-security-overview.md)
  - [Database Backup and Restore (ArkTS)](data-backup-and-restore.md)
  - [Database Backup and Restore (C/C++)](native-backup-and-restore.md)
  - [Database Encryption (ArkTS)](data-encryption.md)
  - [Database Encryption (C/C++)](native-data-encryption.md)
  - [Access Control by Device and Data Level (ArkTS)](access-control-by-device-and-data-level.md)
  - [Access Control by Device and Data Level (C/C++)](native-access-control-by-device-and-data-level.md)
  - [Using an EL5 Database (ArkTS)](encrypted_estore_guidelines.md)
- Cross-Application Data Sharing<!--cross-app-data-share-->
  - [Overview of Cross-Application Data Sharing](data-share-overview.md)
  - One-to-Many Data Sharing<!--one-to-many-data-share-->
    <!--Del-->
    - [Sharing Data Using DataShareExtensionAbility (ArkTS) (for System Applications Only)](share-data-by-datashareextensionability.md)
    - [Silent Access via DatamgrService (ArkTS) (for System Applications Only)](share-data-by-silent-access.md)
    <!--DelEnd-->
    - [Sharing Configurations Between Applications (ArkTS)](share-config.md)
  - Many-to-Many Data Sharing<!--many-to-many-data-share-->
    - [Sharing Data via Unified Data Channels (ArkTS)](unified-data-channels.md)
    - [Sharing Data via Unified Data Channels (C/C++)](unified-data-channels-c.md)
- [Application Data Vectorization (ArkTS)](aip-data-intelligence-embedding.md)
- [SQLite Debugging Tool](sqlite-database-debug-tool.md)
- [ArkData Glossary](data-terminology.md)
