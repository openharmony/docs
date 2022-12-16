# 杂散软件服务子系统JS API变更

OpenHarmony 3.2 Canary1版本相较于OpenHarmony 3.1 Release版本，杂散软件服务子系统的API变更如下:

## 接口变更

| 模块名* | 类名 | 函数* | 变更类型 |
|---|---|---|---|
| ohos.screenLock | screenLock | sendScreenLockEvent(event: String, parameter: number, callback: AsyncCallback\<boolean>): void;<br>sendScreenLockEvent(event: String, parameter: number): Promise\<boolean>; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | off(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff'  \| 'unlockScreen' \| 'beginExitAnimation' \| 'screenlockEnabled' \| 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'screenlockEnabled', callback: Callback\<boolean>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<number>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<number>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginSleep' \| 'endSleep' \| 'changeUser', callback: Callback\<number>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |
| ohos.screenLock | screenLock | on(type: 'beginWakeUp' \| 'endWakeUp' \| 'beginScreenOn' \| 'endScreenOn' \| 'beginScreenOff' \| 'endScreenOff' \| 'unlockScreen' \| 'beginExitAnimation', callback: Callback\<void>): void; | 新增 |

