# File Management Subsystem ChangeLog

## cl.filemanagement.1 Changed environment

The file management subsystem **d.ts** file has been archived and moved to the **file** directory. The **environment** module supports error code processing.

**Change Impacts**

If your application is developed based on earlier versions, note that the **d.ts** file storage location and the name of the module to be imported are changed. The **environment** module supports error code processing. See [adaptation instructions](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **environment** was imported using **@ohos.environment**:

```js
import environment from '@ohos.environment';
```

But now, **environment** is imported using **@ohos.file.environment**:

```js
import environment from '@ohos.file.environment';
```

## cl.filemanagement.2 Changed securityLabel

The file management subsystem **d.ts** file has been archived and moved to the **file** directory. The **securityLabel** module supports error code processing.

**Change Impacts**

If your application is developed based on earlier versions, note that the **d.ts** file storage location and the name of the module to be imported are changed. The **securityLabel** module supports error code processing. See [adaptation instructions](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **securityLabel** was imported using **@ohos.securityLabel**:

```js
import securityLabel from '@ohos.securityLabel';
```

But now, **securityLabel** is imported using **@ohos.file.securityLabel**:

```js
import securityLabel from '@ohos.file.securityLabel';
```

## cl.filemanagement.3 Changed fs

The **ino** attribute type of the **Stat** API under the **fs** module is changed.

**Change Impacts**

The **ino** attribute type is changed from number to BigInt, to adapt the inode range of all types of files in the file system.

**Key API/Component Changes**

The type of the **ino** attribute of the **Stat** API is changed from number to BigInt.

## cl.filemanagement.4 Changed fileAccess

The file management subsystem **d.ts** file has been archived and moved to the **file** directory. The **fileAccess** module supports error code processing.

**Change Impacts**

If your application is developed based on earlier versions, note that the **d.ts** file storage location and the name of the module to be imported are changed. The **fileAccess** module supports error code processing. See [adaptation instructions](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **fileAccess** was imported using **@ohos.data.fileAccess**:

```js
import fileAccess from '@ohos.data.fileAccess';
```

But now, **fileAccess** is imported using **@ohos.file.fileAccess**:

```js
import fileAccess from '@ohos.file.fileAccess';
```

## cl.filemanagement.5 Changed fileExtensionInfo

The file management subsystem **d.ts** file has been archived and moved to the **file** directory. The **fileExtensionInfo** module supports error code processing.

**Change Impacts**

If your application is developed based on earlier versions, note that the **d.ts** file storage location and the name of the module to be imported are changed. The **fileExtensionInfo** module supports error code processing. See [adaptation instructions](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **fileExtensionInfo** was imported using **@ohos.fileExtensionInfo**:

```js
import fileExtensionInfo from '@ohos.fileExtensionInfo';
```

But now, **fileExtensionInfo** is imported using **@ohos.file.fileExtensionInfo**:

```js
import fileExtensionInfo from '@ohos.file.fileExtensionInfo';
```

## cl.filemanagement.6 Changed storageStatistics

The file management subsystem **d.ts** file has been archived and moved to the **file** directory. The **fileExtensionInfo** module supports error code processing.

**Change Impacts**

If your application is developed based on earlier versions, note that the **d.ts** file storage location and the name of the module to be imported are changed. The **storageStatistics** module supports error code processing. See [adaptation instructions](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **storageStatistics** was imported using **@ohos.storageStatistics**:

```js
import storageStatistics from '@ohos.storageStatistics';
```

But now, **storageStatistics** is imported using **@ohos.file.storageStatistics**:

```js
import storageStatistics from '@ohos.file.storageStatistics';
```

## cl.filemanagement.7 Changed volumeManager

The file management subsystem **d.ts** file has been archived moved to the **file** directory. The **volumeManager** module supports error code processing.

**Change Impacts**

If your application is developed based on earlier versions, note that the **d.ts** file storage location and the name of the module to be imported are changed. The **volumeManager** module supports error code processing. See [adaptation instructions](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **volumeManager** was imported using **@ohos.volumeManager**:

```js
import volumeManager from '@ohos.volumeManager';
```

But now, **volumeManager** is imported using **@ohos.file.volumeManager**:

```js
import volumeManager from '@ohos.file.volumeManager';
```
