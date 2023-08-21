# Summary


| Subsystem | Change Type | Description |
| -------- | -------- | -------- |
| ArkUI |                                       |                                                              |
| ArkUI |                                       |                                                              |
| ArkUI |                                       |                                                              |
| ArkUI |                                       |                                                              |
| ArkUI |                                       |                                                              |
| ArkUI |  |  |
| ArkUI |  |  |
| ArkUI |  |  |
| ArkUI |  |                                                              |
| ArkUI |  |                                                              |
| ArkUI |  |                                                              |
| ArkUI |  |  |
| Bundle management |  |  |
| Bundle management |  |                                                              |
| Bundle management |  |  |
| Bundle management |  |  |
| Bundle management |                                       |  |
| OS media |  |  |
| OS media |  |                                                              |
| OS media |  |  |
| Application access control | Permission changed | [Change of the Permission Requesting Modes of the Phone, Messaging, and Call Logs Permission Groups](changelogs-accessToken.md#claccesstoken2-change-of-the-permission-requesting-modes-of-the-phone-messaging-and-call-logs-permission-groups) |
| Application access control | Permission group changed | [Change of the Media and Files Permission Group:<br/>Moved ohos.permission.MEDIA_LOCATION to the Images and Videos permission group.<br/>Moved ohos.permission.READ_MEDIA and ohos.permission.WRITE_MEDIA to the Documents permission group.](changelogs-accessToken.md#claccesstoken1-change-of-the-media-and-files-permission-group) |
| Input method framework |  |  |
| Theme framework |  |  |
| Distributed data management | API/Component changed | [Change of ValuesBucket to a Public Interface](changelogs-distributeddatamgr.md#cldistributeddatamgr1-change-of-valuesbucket-to-a-public-interface) |
| Distributed data management | API/Component changed | [Change of Some Predicate Interfaces in dataSharePredicates to Public Interfaces](changelogs-distributeddatamgr.md#cldistributeddatamgr2-change-of-some-predicate-interfaces-in-datasharepredicates-to-public-interfaces) |
| Distributed data management | API/Component changed | [Change of the DataShareExtensionAbility Context](cldistributeddatamgr3-change-of-the-datashareextensionability-context) |
| Distributed data management | API/Component changed | [Change of the Return Value Type of Function Pointer Variables in the OH_Predicates Struct from OH_Predicates to OH_Predicates *](cldistributeddatamgr4-change-of-the-return-value-type-of-function-pointer-variables-in-the-oh_predicates-struct-from-oh_predicates-to-oh_predicates-) |
| Distributed data management | API/Component changed | [Change of the Error Codes of the OH_Rdb_ErrCode Struct](cldistributeddatamgr5-change-of-the-error-codes-of-the-oh_rdb_errcode-struct) |
| Distributed data management | Variable changed (Native) | [1. Change of int (*close)(OH_Cursor *cursor) in OH_Cursor Struct to int (*destroy)(OH_Cursor *cursor)](cldistributeddatamgr6-change-of-int-closeoh_cursor-cursor-in-oh_cursor-struct-to-int-destroyoh_cursor-cursor)<br/>[2. Change of int (*destroyPredicates)(OH_Predicates *predicates) in OH_Predicates Struct to int (*destroy) (OH_Predicates *predicates)](cldistributeddatamgr7-change-of-int-destroypredicatesoh_predicates-predicates-in-oh_predicates-struct-to-int-destroy-oh_predicates-predicates)<br/>[3. Change of int (*destroyValueObject)(OH_VObject *valueObject) in OH_VObject Struct to int (*destroy) (OH_VObject *valueObject)](cldistributeddatamgr8-change-of-int-destroyvalueobjectoh_vobject-valueobject-in-oh_vobject-struct-to-int-destroy-oh_vobject-valueobject)<br/>[4. Change of int (*destroyValuesBucket)(OH_VBucket *bucket) in OH_VBucket Struct to int (*destroy) (OH_VBucket *bucket)](cldistributeddatamgr9-change-of-int-destroyvaluesbucketoh_vbucket-bucket-in-oh_vbucket-struct-to-int-destroy-oh_vbucket-bucket) |
| Distributed data management | Variable changed (Native) | [Change of OH_Rdb_Config Struct Member Variables:<br/>1. Changed the type of **securityLevel** from **enum OH_Rdb_SecurityLevel** to **in**.<br/>2. Deleted the member variable **path**.<br/>3. Added the member variables **selfSize**, **dataBaseDir**, **storeName**, **bundleName**, and **moduleName**.](cldistributeddatamgr10-change-of-oh_rdb_config-struct-member-variables) |
| Distributed data management | API input parameter changed  (Native) | [Change of const char *path in OH_Rdb_DeleteStore() to const OH_Rdb_Config *config](changelogs-distributeddatamgr.md#cldistributeddatamgr11-change-of-const-char-path-in-oh_rdb_deletestore-to-const-oh_rdb_config-config) |
| Distributed hardware |  |  |
| Media |                                       |                                                              |
| Media |                                       |                                                              |
| Ability - widget framework |                                       |                                                              |
| Ability - widget framework |  |  |
| Pan-Sensor |  |  |
| File management (media library) | API/Component changed | [Change of the mediaLibrary Interface Compatibility](changelogs-medialibrary.md#clfile1-change-of-the-mediabibrary-interface-compatibility) |
| Communication | API/Component changed | [Change of the API Name](changelogs-wifiManager.md#clwifi1-change-of-the-name-of-the-api-for-obtaining-wi-fi-scan-result) |


> **NOTE**
>
>  Unless otherwise specified, the changes described in this topic are ArkTS API changes. 

<!--no_check-->