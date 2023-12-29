# MSDP Subsystem Changelog

## c1.device_status.1 Screen Hopping APIs Deprecated

**Access Level**

System APIs

**Reason for Change**

Permission control is added for screen hopping APIs. The new APIs incorporate complete functions of the old system APIs and are more standard and atomic with full compliance with community API specifications.

**Change Impact**

The change is not compatible with earlier versions. You are advised to use new APIs.

**Valid Since**

OpenHarmony SDK 4.1.5.1

**Deprecated APIs**

| API                                                    | Description                                                    | Substitute API                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| function prepare(callback: AsyncCallback&lt;void&gt;): void; | **cooperate.prepareCooperate** is used to prepare for screen hopping.            | function prepareCooperate(callback: AsyncCallback&lt;void&gt;): void; |
| function prepare(): Promise&lt;void&gt;;                     | **cooperate.prepareCooperate** is used to prepare for screen hopping.            | function prepareCooperate(): Promise&lt;void&gt;;            |
| function unprepare(callback: AsyncCallback&lt;void&gt;): void; | **cooperate.unprepareCooperate** is used to cancel the preparation for screen hopping.          | function unprepareCooperate(callback: AsyncCallback&lt;void&gt;): void; |
| function unprepare(): Promise&lt;void&gt;;                   | **cooperate.unprepareCooperate** is used to cancel the preparation for screen hopping.          | function unprepareCooperate(): Promise&lt;void&gt;;          |
| function activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void; | **cooperate.activateCooperate** is used to start screen hopping.               | function activateCooperate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void; |
| function activate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;; | **cooperate.activateCooperate** is used to start screen hopping.               | function activateCooperate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;; |
| function deactivate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void; | **cooperate.deactivateCooperate** is used to stop screen hopping.             | function deactivateCooperate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void; |
| function deactivate(isUnchained: boolean): Promise&lt;void&gt;; | **cooperate.deactivateCooperate** is used to stop screen hopping.             | function deactivateCooperate(isUnchained: boolean): Promise&lt;void&gt;; |
| function getCrossingSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void; | **cooperate.getCooperateSwitchState** is used to obtain the screen hopping status of the target device.| function getCooperateSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void; |
| function getCrossingSwitchState(networkId: string): Promise&lt;boolean&gt;; | **cooperate.getCooperateSwitchState** is used to obtain the screen hopping status of the target device.| function getCooperateSwitchState(networkId: string): Promise&lt;boolean&gt;; |
| function on(type: 'cooperate', callback: Callback&lt;{ networkId: string, msg: CooperateMsg }&gt;): void; | **cooperate.on** is used to subscribe to screen hopping status change events.                      | function on(type: 'cooperateMessage', callback: Callback&lt;CooperateMessage&gt;): void; |
| function off(type: 'cooperate', callback?: Callback&lt;void&gt;): void; | **cooperate.off** is used to unsubscribe from screen hopping status change events.                     | function off(type: 'cooperateMessage', callback?: Callback&lt;CooperateMessage&gt;): void; |
| enum CooperateMsg                                            | **CooperateMessage** is used to define a screen hopping status change event.                | interface CooperateMessage                                   |
| COOPERATE_PREPARE                                            | **CooperateState.COOPERATE_PREPARE** is used to indicate that the preparation for screen hopping is finished.      | CooperateState.COOPERATE_PREPARE                             |
| COOPERATE_UNPREPARE                                          | **CooperateState.COOPERATE_UNPREPARE** is used to indicate that the preparation for screen hopping is canceled.  | CooperateState.COOPERATE_UNPREPARE                           |
| COOPERATE_ACTIVATE                                           | **CooperateState.COOPERATE_ACTIVATE** is used to indicate that screen hopping is started.     | CooperateState.COOPERATE_ACTIVATE                            |
| COOPERATE_ACTIVATE_SUCCESS                                   | **CooperateState.COOPERATE_ACTIVATE_SUCCESS** is used to indicate that starting screen hopping is successful.| CooperateState.COOPERATE_ACTIVATE_SUCCESS                    |
| COOPERATE_ACTIVATE_FAIL                                      | **CooperateState.COOPERATE_ACTIVATE_FAILURE** is used to indicate that starting screen hopping has failed.| CooperateState.COOPERATE_ACTIVATE_FAILURE                    |
| COOPERATE_DEACTIVATE_SUCCESS                                 | **CooperateState.COOPERATE_DEACTIVATE_SUCCESS** is used to indicate that stopping screen hopping is successful.| CooperateState.COOPERATE_DEACTIVATE_SUCCESS                  |
| COOPERATE_DEACTIVATE_FAIL                                    | **CooperateState.COOPERATE_DEACTIVATE_FAILURE** is used to indicate that stopping screen hopping has failed.| CooperateState.COOPERATE_DEACTIVATE_FAILURE                  |
| COOPERATE_SESSION_DISCONNECTED                               | **CooperateState.COOPERATE_SESSION_DISCONNECTED** is used to indicate that the screen hopping session is disconnected.| CooperateState.COOPERATE_SESSION_DISCONNECTED                |

**Adaptation Guide**

You are advised to use [@ohos.cooperate](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-devicestatus-cooperate.md#cooperateprepare).
