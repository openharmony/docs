# 文件管理子系统ChangeLog
## cl.filemanagement.1 Filter类型由systemapi变更至publicapi

@ohos.file.fs中Filter类型由systemapi变更至publicapi。

**变更影响**<br>
兼容性变更，无变更影响。三方应用可使用Filter类型。

## cl.filemanagement.2 Watcher相关接口由systemapi变更至publicapi

@ohos.file.fs中Watcher相关接口由systemapi变更至publicapi。

Watcher相关接口包括：

| 接口声明 | 接口描述 |
|------|---------|
| **function** createWatcher(path: string, events: number, listener: WatchEventListener): Watcher | 创建Watcher对象，用来监听文件或目录变动     |
| **interface** WatchEventListener                | 事件监听类     |
| **interface** WatchEvent                | 事件类     |
| **property** WatchEvent.fileName                | 发生监听事件的文件名     |
| **property** WatchEvent.event                        | 发生的监听事件     |
| **property** WatchEvent.cookie                | 绑定相关事件的cookie     |
| **interface** Watcher              | 文件目录变化监听对象     |
| **function** Watcher.start(): void                | 开启监听     |
| **function** Watcher.stop(): void                 | 停止监听     |

**变更影响**<br>
兼容性变更，无变更影响。三方应用可使用文件监听能力。
