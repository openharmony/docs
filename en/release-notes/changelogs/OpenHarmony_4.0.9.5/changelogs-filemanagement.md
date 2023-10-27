# File Management Subsystem Changelog
## cl.filemanagement.1 Change the Filter Type from systemapi to publicapi

Changed the **Filter** type in @ohos.file.fs from **systemapi** to **publicapi**.

**Change Impact**
The compatibility is changed, and there is no impact of the change. Third-party applications can use the **Filter** type.

## cl.filemanagement.2 Change of Watcher APIs from systemapi to publicapi

Changed Watcher-related APIs in @ohos.file.fs from **systemapi** to **publicapi**.

Watcher-related APIs are as follows:

| API| Description|
|------|---------|
| **function** createWatcher(path: string, events: number, listener: WatchEventListener): Watcher | Creates a **Watcher** object to observe file or directory changes.    |
| **interface** WatchEventListener                | Event listening class.    |
| **interface** WatchEvent                | Event class.    |
| **property** WatchEvent.fileName                | Name of the file for which the event occurs.    |
| **property** WatchEvent.event                        | Events to observe.    |
| **property** WatchEvent.cookie                | Cookie bound with the event.    |
| **interface** Watcher              | File or directory object whose changes are observed.    |
| **function** Watcher.start(): void                | Starts listening.    |
| **function** Watcher.stop(): void                 | Stops listening.    |

**Change Impact**
The compatibility is changed, and there is no impact of the change. Third-party applications can use the capability of file listening.
