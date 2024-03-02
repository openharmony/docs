# File Management Subsystem Changelog

## cl.filemanagement.1 chmod, fchmod, chown, fchown, and lchown Function Unavailable

**Access Level**

Public

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

Public

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
