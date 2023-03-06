# File Management Subsystem Changelog

## cl.filemanagement.1 Filter Module Change

Moved **Filter** from **@ohos.fileio** to **@ohos.file.fs**. The attributes of **Filter** remain unchanged.

**Change Impact**

If your application is developed using the APIs of earlier versions, note that the position of **Filter** in the **d.ts** file and the module name are changed. The **Filter** type is moved to **@ohos.file.fs**.

**Key API/Component Changes**

Before the change, **Filter** is in the **@ohos.fileio** module and imported as follows:

```js
import Filter from '@ohos.fileio';
```

**Adaptation Guide**

Now, **Filter** is in the **@ohos.file.fs** module and imported as follows:

```js
import Filter from '@ohos.file.fs';
```
