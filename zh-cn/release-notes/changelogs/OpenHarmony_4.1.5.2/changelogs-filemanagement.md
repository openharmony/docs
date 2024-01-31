# 文件管理子系统变更说明

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

该变更为非兼容变更。因系统安全影响，此接口受SEHarmony管控，以下接口功能变更为功能不可用。

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

变更后上述接口受SEHarmony管控影响，调用接口将返回错误码13900012（Permission denied）。

**适配指导**

系统将不再提供创建软链接能力，请及时清理无用接口或进行异常处理。