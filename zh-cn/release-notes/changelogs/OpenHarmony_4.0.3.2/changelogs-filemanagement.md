# 文件管理子系统ChangeLog

## cl.filemanagement.1 Filter类型模块变更

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现Filter类型变更至@ohos.file.fs模块下。Filter类型具体属性不变。

**关键接口/组件变更**

原Filter类型在模块@ohos.fileio下，通过以下方式import:

```js
import Filter from '@ohos.fileio';
```

**适配指导**

现Filter类型在模块@ohos.file.fs，通过以下方式import:

```js
import Filter from '@ohos.file.fs';
```
