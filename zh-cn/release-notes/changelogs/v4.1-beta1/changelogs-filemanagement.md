# 文件子系统ChangeLog

## cl.file.1 picker PhotoViewPicker.save 接口兼容性变更

[PhotoViewPicker.save](../../../application-dev/reference/apis/js-apis-file-picker.md#save)接口兼容性变更。

**变更影响**

基于此前版本开发的应用，使用PhotoViewPicker.save接口保存文件只能保存到文管目录，文管目录下的文件在图库中并不可见。如果需要保存到图库则需要切换为使用[安全控件创建媒体资源](../../../application-dev/file-management/photoAccessHelper-resource-guidelines.md#使用安全控件创建媒体资源)的方式。

**关键接口/组件变更**

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| picker   |   **function** PhotoViewPicker.save(option?: PhotoSaveOptions) : Promise&lt;Array&lt;string&gt;&gt; | 接口兼容性变更     |
| picker   |   **function** PhotoViewPicker.save(option: PhotoSaveOptions, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void | 接口兼容性变更     |
| picker   |   **function** PhotoViewPicker.save(callback: AsyncCallback&lt;Array&lt;string&gt;&gt;) : void | 接口兼容性变更     |

**适配指导**

PhotoViewPicker.save接口的具体行为是拉起FilePicker，将文件保存在系统文件管理器的特定目录中。
从OpenHarmony_4.0.11.2版本开始，文件访问框架管理的资源范围发生变化，不再支持访问媒体库管理的资源。导致与图库管理的资源隔离，无法在图库中看到。如需要在图库中看到所保存的图片、视频资源，请使用安全控件的[保存控件](../../../../zh-cn/application-dev/reference/arkui-ts/ts-security-components-savebutton.md)。

**使用安全控件创建媒体资源示例：**

示例代码详情见媒体资源使用指导中的[安全控件创建媒体资源](../../../application-dev/file-management/photoAccessHelper-resource-guidelines.md#使用安全控件创建媒体资源)

## cl.filemanagement.1 chmod、fchmod、chown、fchown、lchown同异步接口功能不可用

**访问级别**

公开接口

**变更影响**

该变更为非兼容变更。受系统安全性影响，不再提供修改文件权限、文件所有者的能力，以下接口功能将不再可用。

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| @ohos.fileio        |  **function** chmod(path: string, mode: number): Promise<void> | 功能不可用     |
| @ohos.fileio        |  **function** chmod(path: string, mode: number, callback: AsyncCallback<void>): void | 功能不可用     |
| @ohos.fileio        |  **function** chmodSync(path: string, mode: number): void | 功能不可用     |
| @ohos.fileio        |  **function** fchmod(fd: number, mode: number): Promise<void> | 功能不可用     |
| @ohos.fileio        |  **function** fchmod(fd: number, mode: number, callback: AsyncCallback<void>): void | 功能不可用     |
| @ohos.fileio        |  **function** fchmodSync(fd: number, mode: number): void | 功能不可用     |
| @ohos.fileio        |  **function** chown(path: string, uid: number, gid: number): Promise<void> | 功能不可用     |
| @ohos.fileio        |  **function** chown(path: string, uid: number, gid: number, callback: AsyncCallback<void>): void | 功能不可用     |
| @ohos.fileio        |  **function** chownSync(path: string, uid: number, gid: number): void | 功能不可用     |
| @ohos.fileio        |  **function** fchown(fd: number, uid: number, gid: number): Promise<void> | 功能不可用     |
| @ohos.fileio        |  **function** fchown(fd: number, uid: number, gid: number, callback: AsyncCallback<void>): void | 功能不可用     |
| @ohos.fileio        |  **function** fchownSync(fd: number, uid: number, gid: number): void | 功能不可用     |
| @ohos.fileio        |  **function** lchown(path: string, uid: number, gid: number): Promise<void> | 功能不可用     |
| @ohos.fileio        |  **function** lchown(path: string, uid: number, gid: number, callback: AsyncCallback<void>): void | 功能不可用     |
| @ohos.fileio        |  **function** lchownSync(path: string, uid: number, gid: number): void | 功能不可用     |

**变更发生版本**

从OpenHarmony SDK 4.1.5.2开始。

**变更的接口/组件**

变更后上述接口将直接返回void。原始功能不生效。

**适配指导**

为了提高系统安全性，不再给应用提供修改文件权限、文件所有者的能力，请开发者及时清理无用接口。

## cl.filemanagement.2 fileio.symlink、fs.symlink同异步接口功能不可用

**访问级别**

公开接口

**变更影响**

该变更为非兼容变更。因系统安全影响，此接口受selinux管控，以下接口功能变更为功能不可用。

| 模块名                    | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------------------------------------------------ | -------- |
| @ohos.fileio        |  **function** symlink(target: string, srcPath: string): Promise<void> | 功能不可用     |
| @ohos.fileio        |  **function** symlink(target: string, srcPath: string, callback: AsyncCallback<void>): void | 功能不可用     |
| @ohos.fileio        |  **function** symlinkSync(target: string, srcPath: string): void | 功能不可用     |
| @ohos.file.fs       |  **function** symlink(target: string, srcPath: string): Promise<void> | 功能不可用     |
| @ohos.file.fs       |  **function** symlink(target: string, srcPath: string, callback: AsyncCallback<void>): void | 功能不可用     |
| @ohos.file.fs       |  **function** symlinkSync(target: string, srcPath: string): void | 功能不可用     |

**变更发生版本**

从OpenHarmony SDK 4.1.5.2开始。

**变更的接口/组件**

变更后上述接口受selinux管控影响，调用接口将返回错误码13900012（Permission denied）。

**适配指导**

系统将不再提供创建软链接能力，请及时清理无用接口或进行异常处理。

## c1.file_manager.1 文件管理模块接口以及相关参数废弃

**访问级别**

系统接口

**废弃原因**

该接口为API11授权方案新增接口，后续因考虑API10已有方案的兼容性问题，授权方案调整，在原有的AMS接口GrantUriPermission上兼容实现，不需要提供这个新的接口，因此该API需要废弃。

**废弃影响**

系统接口的非兼容变更，当前未有发布版本带入，为开发版本接口变更，无需适配。

**API level**

<11>

**废弃发生版本**

从OpenHarmony SDK 4.1.5.1开始。

**废弃的接口/参数**

function grantPermission(tokenId: number, policies: Array<PolicyInfo>, policyFlag: number): Promise<void>

export enum policyFlag

FORBID_PERSISTENCE = 0b10

ALLOW_PERSISTENCE = 0b1

**适配指导**

该接口为API11授权方案新增接口，当前还未有相应版本发布，所以不存在存量应用使用，目前无需开发者适配。
