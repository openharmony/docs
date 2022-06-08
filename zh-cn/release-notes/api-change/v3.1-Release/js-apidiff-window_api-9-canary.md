# 窗口管理子系统JS API变更

OpenHarmony 3.2 Canary1版本相较于OpenHarmony 3.1 Release版本，窗口管理子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.window | WindowStage | loadContent(path: string, storage: ContentStorage, callback: AsyncCallback\<void>): void;<br>loadContent(path: string, storage?: ContentStorage): Promise\<void>;<br>loadContent(path: string, callback: AsyncCallback\<void>): void; | 新增 |
| ohos.window | WindowStage | getSubWindow(): Promise\<Array\<Window>>;<br>getSubWindow(callback: AsyncCallback\<Array\<Window>>): void; | 新增 |
| ohos.window | WindowStage | createSubWindow(name: string): Promise\<Window>;<br>createSubWindow(name: string, callback: AsyncCallback\<Window>): void; | 新增 |
| ohos.window | WindowStage | getMainWindow(): Promise\<Window>;<br>getMainWindow(callback: AsyncCallback\<Window>): void; | 新增 |
| ohos.window | WindowStageEventType | BACKGROUND | 新增 |
| ohos.window | WindowStageEventType | INACTIVE | 新增 |
| ohos.window | WindowStageEventType | ACTIVE | 新增 |
| ohos.window | WindowStageEventType | FOREGROUND = 1 | 新增 |

