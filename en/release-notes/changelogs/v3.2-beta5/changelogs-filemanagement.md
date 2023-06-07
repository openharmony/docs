# File Management Subsystem Changelog

## cl.filemanagement.1 environment Module Change 

Moved the file management subsystem **d.ts** file to the **file** directory. The **environment** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **environment** module supports error code processing. See [Adaptation Guide](../v3.2-beta4/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **environment** was imported from **@ohos.environment**:

```js
import environment from '@ohos.environment';
```

Now, **environment** is imported from **@ohos.file.environment**:

```js
import environment from '@ohos.file.environment';
```

## cl.filemanagement.2 securityLabel Change

Moved the file management subsystem **d.ts** file to the **file** directory. The **securityLabel** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **securityLabel** module supports error code processing. See [Adaptation Guide](../v3.2-beta4/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **securityLabel** was imported from **@ohos.securityLabel**:

```js
import securityLabel from '@ohos.securityLabel';
```

Now, **securityLabel** is imported from **@ohos.file.securityLabel**:

```js
import securityLabel from '@ohos.file.securityLabel';
```

## cl.filemanagement.3 fs Change

Changed the **ino** attribute type of **Stat** under **fs**.

**Change Impact**

The **ino** attribute type is changed from number to BigInt, to adapt to the **inode** range of all types of files in the file system.

**Key API/Component Changes**

The type of the **ino** attribute of **Stat** is changed from number to BigInt.

## cl.filemanagement.4 fileAccess Change

Moved the file management subsystem **d.ts** file to the **file** directory. The **fileAccess** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **fileAccess** module supports error code processing. See [Adaptation Guide](../v3.2-beta4/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **fileAccess** was imported from **@ohos.data.fileAccess**:

```js
import fileAccess from '@ohos.data.fileAccess';
```

Now, **fileAccess** is imported from **@ohos.file.fileAccess**:

```js
import fileAccess from '@ohos.file.fileAccess';
```

## cl.filemanagement.5 fileExtensionInfo Change

Moved the file management subsystem **d.ts** file to the **file** directory. The **fileExtensionInfo** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **fileExtensionInfo** module supports error code processing. See [Adaptation Guide](../v3.2-beta4/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **fileExtensionInfo** was imported from **@ohos.fileExtensionInfo**:

```js
import fileExtensionInfo from '@ohos.fileExtensionInfo';
```

Now, **fileExtensionInfo** is imported from **@ohos.file.fileExtensionInfo**:

```js
import fileExtensionInfo from '@ohos.file.fileExtensionInfo';
```

## cl.filemanagement.6 storageStatistics Change

Moved the file management subsystem **d.ts** file to the **file** directory. The **fileExtensionInfo** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **storageStatistics** module supports error code processing. See [Adaptation Guide](../v3.2-beta4/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **storageStatistics** was imported from **@ohos.storageStatistics**:

```js
import storageStatistics from '@ohos.storageStatistics';
```

Now, **storageStatistics** is imported from **@ohos.file.storageStatistics**:

```js
import storageStatistics from '@ohos.file.storageStatistics';
```

## cl.filemanagement.7 volumeManager Change

Moved the file management subsystem **d.ts** file to the **file** directory. The **fileExtensionInfo** module supports error code processing.

**Change Impact**

If your application is developed based on earlier versions, note that the **d.ts** file location and the name of the module to be imported are changed. The **volumeManager** module supports error code processing. See [Adaptation Guide](../v3.2-beta4/changelogs-filemanagement.md) for more details.

**Key API/Component Changes**

Before the change, **volumeManager** was imported from **@ohos.volumeManager**:

```js
import volumeManager from '@ohos.volumeManager';
```

Now, **volumeManager** is imported from **@ohos.file.volumeManager**:

```js
import volumeManager from '@ohos.file.volumeManager';
```
