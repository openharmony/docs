# 文件管理子系统ChangeLog

## cl.filemanagement.1 environment模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。environment模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现environment模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原environment使用的是@ohos.environment，以以下方式import:

```js
import environment from '@ohos.environment';
```

现environment使用的是@ohos.file.environment，以以下方式import:

```js
import environment from '@ohos.file.environment';
```

## cl.filemanagement.2 securityLabel模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。securityLabel模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现securityLabel模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原securityLabel使用的是@ohos.securityLabel，以以下方式import:

```js
import securityLabel from '@ohos.securityLabel';
```

现securityLabel使用的是@ohos.file.securityLabel，以以下方式import:

```js
import securityLabel from '@ohos.file.securityLabel';
```

## cl.filemanagement.3 fs模块变更

fs模块下Stat接口ino属性类型变更。

**变更影响**

fs模块下Stat接口ino属性类型变更，由number变更为bigint，以适配文件系统下所有类型文件的inode范围。

**关键接口/组件变更**

原Stat接口ino属性类型为number，现变更为bigint。

## cl.filemanagement.4 fileAccess模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。fileAccess模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现fileAccess模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原fileAccess使用的是@ohos.data.fileAccess，以以下方式import:

```js
import fileAccess from '@ohos.data.fileAccess';
```

现fileAccess使用的是@ohos.file.fileAccess，以以下方式import:

```js
import fileAccess from '@ohos.file.fileAccess';
```

## cl.filemanagement.5 fileExtensionInfo模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。fileExtensionInfo模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现fileExtensionInfo模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原fileExtensionInfo使用的是@ohos.fileExtensionInfo，以以下方式import:

```js
import fileExtensionInfo from '@ohos.fileExtensionInfo';
```

现fileExtensionInfo使用的是@ohos.file.fileExtensionInfo，以以下方式import:

```js
import fileExtensionInfo from '@ohos.file.fileExtensionInfo';
```

## cl.filemanagement.6 storageStatistics模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。fileExtensionInfo模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现storageStatistics模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原storageStatistics使用的是@ohos.storageStatistics，以以下方式import:

```js
import storageStatistics from '@ohos.storageStatistics';
```

现storageStatistics使用的是@ohos.file.storageStatistics，以以下方式import:

```js
import storageStatistics from '@ohos.file.storageStatistics';
```

## cl.filemanagement.7 volumeManager模块变更

文件管理子系统d.ts归档整改，现统一整改到file一层目录下。fileExtensionInfo模块支持错误码处理。

**变更影响**

基于此前版本开发的应用，需注意d.ts位置的变更及import模块名的变更。现volumeManager模块支持错误码处理，需注意错误码处理的使用。[相关适配指导参考](../OpenHarmony_3.2.8.1/changelogs-filemanagement.md)

**关键接口/组件变更**

原volumeManager使用的是@ohos.volumeManager，以以下方式import:

```js
import volumeManager from '@ohos.volumeManager';
```

现volumeManager使用的是@ohos.file.volumeManager，以以下方式import:

```js
import volumeManager from '@ohos.file.volumeManager';
```
