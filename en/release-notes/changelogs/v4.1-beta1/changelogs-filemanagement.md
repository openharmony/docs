# File Subsystem Changelog

## cl.file.1 Change of picker PhotoViewPicker.save() Compatibility

Changed the [PhotoViewPicker.save()](https://gitee.com/openharmony/docs/tree/OpenHarmony-4.1-Beta1/en/application-dev/reference/apis/js-apis-file-picker.md#save) interface compatibility.

**Change Impact**

For applications developed based on earlier versions, **PhotoViewPicker.save()** saves files only to the file manager directory, and the files in the file manager directory are invisible in **Gallery**. To save a file to **Gallery**, create a media asset using a security component. For details, see [Creating a Media Asset Using a Security Component](../../../application-dev/file-management/photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security-component).

**Key API/Component Changes**

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| picker   |   **function** PhotoViewPicker.save(option?: PhotoSaveOptions) : Promise&lt;Array&lt;string&gt;&gt; | Interface compatibility    |
| picker   |   **function** PhotoViewPicker.save(option: PhotoSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void | Interface compatibility    |
| picker   |   **function** PhotoViewPicker.save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void | Interface compatibility    |

**Adaptation Guide**

**PhotoViewPicker.save()** starts **FilePicker** and saves files to a directory in the system file manager.
From OpenHarmony_4.0.11.2, **FilePicker** cannot access assets in the media library. As a result, the files in the file manager directory cannot be viewed in **Gallery**. To enable the saved images or videos to be viewed in **Gallery**, use [**\<SaveButton>**](../../../application-dev/reference/arkui-ts/ts-security-components-savebutton.md) to save images or videos.

**Example**

See [Creating a Media Asset Using a Security Component](../../../application-dev/file-management/photoAccessHelper-resource-guidelines.md#creating-a-media-asset-using-a-security component).

## cl.filemanagement.1 chmod, fchmod, chown, fchown, and lchown Function Unavailable

**Access Level**

Public API

**Change Impact**

This change is a non-compatible change. For security purposes, the APIs for modifying the file permissions and owner are no longer available.

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| @ohos.fileio        |  **function** chmod(path: string, mode: number): Promise<void> | Function unavailable    |
| @ohos.fileio        |  **function** chmod(path: string, mode: number, callback: AsyncCallback<void>): void | Function unavailable    |
| @ohos.fileio        |  **function** chmodSync(path: string, mode: number): void | Function unavailable    |
| @ohos.fileio        |  **function** fchmod(fd: number, mode: number): Promise<void> | Function unavailable    |
| @ohos.fileio        |  **function** fchmod(fd: number, mode: number, callback: AsyncCallback<void>): void | Function unavailable    |
| @ohos.fileio        |  **function** fchmodSync(fd: number, mode: number): void | Function unavailable    |
| @ohos.fileio        |  **function** chown(path: string, uid: number, gid: number): Promise<void> | Function unavailable    |
| @ohos.fileio        |  **function** chown(path: string, uid: number, gid: number, callback: AsyncCallback<void>): void | Function unavailable    |
| @ohos.fileio        |  **function** chownSync(path: string, uid: number, gid: number): void | Function unavailable    |
| @ohos.fileio        |  **function** fchown(fd: number, uid: number, gid: number): Promise<void> | Function unavailable    |
| @ohos.fileio        |  **function** fchown(fd: number, uid: number, gid: number, callback: AsyncCallback<void>): void | Function unavailable    |
| @ohos.fileio        |  **function** fchownSync(fd: number, uid: number, gid: number): void | Function unavailable    |
| @ohos.fileio        |  **function** lchown(path: string, uid: number, gid: number): Promise<void> | Function unavailable    |
| @ohos.fileio        |  **function** lchown(path: string, uid: number, gid: number, callback: AsyncCallback<void>): void | Function unavailable    |
| @ohos.fileio        |  **function** lchownSync(path: string, uid: number, gid: number): void | Function unavailable    |

**Change Since**

OpenHarmony SDK 4.1.5.2

**Key API/Component Changes**

After the change, calling the preceding APIs returns void, without implementing the original functionalities.

**Adaptation Guide**

For security purposes, the APIs for modifying the file permissions and owner are no longer available. Delete the related APIs in a timely manner.

## cl.filemanagement.2 fileio.symlink and fs.symlink Function Unavailable

**Access Level**

Public API

**Change Impact**

This change is a non-compatible change. For security purposes, the following APIs do not provide original functionalities.

| Module                   | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------------------------------------------------ | -------- |
| @ohos.fileio        |  **function** symlink(target: string, srcPath: string): Promise<void> | Function unavailable    |
| @ohos.fileio        |  **function** symlink(target: string, srcPath: string, callback: AsyncCallback<void>): void | Function unavailable    |
| @ohos.fileio        |  **function** symlinkSync(target: string, srcPath: string): void | Function unavailable    |
| @ohos.file.fs       |  **function** symlink(target: string, srcPath: string): Promise<void> | Function unavailable    |
| @ohos.file.fs       |  **function** symlink(target: string, srcPath: string, callback: AsyncCallback<void>): void | Function unavailable    |
| @ohos.file.fs       |  **function** symlinkSync(target: string, srcPath: string): void | Function unavailable    |

**Change Since**

OpenHarmony SDK 4.1.5.2

**Key API/Component Changes**

After the change, error code 13900012 (Permission denied) will be returned when these APIs are called.

**Adaptation Guide**

The system does not provide the capability of creating soft links. Delete the related APIs or add exception handling in a timely manner.

## c1.file_manager.1 Deprecation of grantPermission and Related Parameters

**Access Level**

System API

**Reason for Change**

The **grantPermission** API deprecated is a new API added in API version 11. Considering the compatibility with the existing APIs in API version 10, the authorization scheme is adjusted and the authorization is implemented by the AMS API **GrantUriPermission**. This API is no longer required and therefore is deprecated.

**Change Impact**

This API has never been released with a formal version. No adaptation is required.

**API level**

<11>

**Deprecated Since**

OpenHarmony SDK 4.1.5.1

**Deprecated API/Parameters**

function grantPermission(tokenId: number, policies: Array<PolicyInfo>, policyFlag: number): Promise<void>

export enum policyFlag

FORBID_PERSISTENCE = 0b10

ALLOW_PERSISTENCE = 0b1

**Adaptation Guide**

This API has never been released with a formal version. No adaptation is required.
