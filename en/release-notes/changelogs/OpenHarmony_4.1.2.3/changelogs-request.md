# Upload and Download Subsystem Changelog

Compared with OpenHarmony 4.1.2.3, OpenHarmony 4.0 has the following API changes in the request subsystem.

## cl.request.1 Removal of Error Code 21900005 task mode error

In earlier versions, the **on('progress')**, **on('complete')**, **on('failed')**, **off('progress')**, **off('complete')**, **off('failed')**, **pause**, and **resume** APIs take effect only for foreground tasks. In this version, they work for both foreground and background tasks. This means that, calling these APIs will no longer return the error code **21900005 task mode error**.

**Change Impact**

Applications developed based on earlier versions may need to be adapted to the changed error codes. Otherwise, the service logic may be affected.

**Key API/Component Changes**

| Module         | Class          | Method/Attribute/Enum/Constant                                                                                                          | Change Type     |
|--------------|--------------|--------------------------------------------------------------------------------------------------|--------------|
| ohos.request | Task      | on(event: 'progress', callback: (progress: Progress) => void): void;                                         | Changed|
| ohos.request | Task      | off(event: 'progress', callback?: (progress: Progress) => void): void;                                       | Changed|
| ohos.request | Task      | on(event: 'completed', callback: (progress: Progress) => void): void;                                      | Changed|
| ohos.request | Task      | off(event: 'completed', callback?: (progress: Progress) => void): void;                                    | Changed|
| ohos.request | Task      | on(event: 'failed', callback: (progress: Progress) => void): void;                                              | Changed|
| ohos.request | Task      | off(event: 'failed', callback?: (progress: Progress) => void): void;                                            | Changed|
| ohos.request | Task      | pause(callback: AsyncCallback<void>): void;                                                                         | Changed|
| ohos.request | Task      | pause(): Promise<void>;                                                                                                       | Changed|
| ohos.request | Task      | resume(callback: AsyncCallback<void>): void;                                                                       | Changed|
| ohos.request | Task      | resume(): Promise<void>;                                                                                                     | Changed|

**Adaptation Guide**

Adapt the code based on the error code changes.
