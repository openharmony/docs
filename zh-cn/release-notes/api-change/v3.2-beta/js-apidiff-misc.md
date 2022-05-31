# 杂散软件服务子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，杂散软件服务子系统的API变更如下:

## 接口变更

| 模块名 | 方法/事件名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.screenLock | sendScreenLockEvent | sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;<br>sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>; | 新增 |
| ohos.screenLock | off_changeUser | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_endSleep | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_beginSleep | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_screenlockEnabled | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_beginExitAnimation | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_unlockScreen | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_endScreenOff | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_beginScreenOff | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_endScreenOn | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_beginScreenOn | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_endWakeUp | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | off_beginWakeUp | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | on_screenlockEnabled | on(type: 'screenlockEnabled', callback: Callback\<boolean>): void; | 新增 |
| ohos.screenLock | on_changeUser | on(type: 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<number>): void; | 新增 |
| ohos.screenLock | on_endSleep | on(type: 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<number>): void; | 新增 |
| ohos.screenLock | on_beginSleep | on(type: 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<number>): void; | 新增 |
| ohos.screenLock | on_beginExitAnimation | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | on_unlockScreen | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | on_endScreenOff | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | on_beginScreenOff | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | on_endScreenOn | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | on_beginScreenOn | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | on_endWakeUp | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | on_beginWakeUp | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
