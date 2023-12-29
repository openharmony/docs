# 综合传感处理平台子系统变更说明

## c1.device_status.1 键鼠穿越功能模块接口废弃

**访问级别**

系统接口

**废弃原因**

键鼠穿越模块接口增加权限，新开放的接口包含旧的系统级接口完整功能，接口更加标准并且原子化，符合社区API规范。

**废弃影响**

非兼容性变更，需要开发者进行适配。

**废弃发生版本**

从OpenHarmony SDK 4.1.5.1开始。

**废弃的接口**

| 接口声明                                                     | 废弃说明                                                     | 替代接口                                                     |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| function prepare(callback: AsyncCallback&lt;void&gt;): void; | 使用cooperate.prepareCooperate接口准备键鼠穿越。             | function prepareCooperate(callback: AsyncCallback&lt;void&gt;): void; |
| function prepare(): Promise&lt;void&gt;;                     | 使用cooperate.prepareCooperate接口准备键鼠穿越。             | function prepareCooperate(): Promise&lt;void&gt;;            |
| function unprepare(callback: AsyncCallback&lt;void&gt;): void; | 使用cooperate.unprepareCooperate取消键鼠穿越准备。           | function unprepareCooperate(callback: AsyncCallback&lt;void&gt;): void; |
| function unprepare(): Promise&lt;void&gt;;                   | 使用cooperate.unprepareCooperate取消键鼠穿越准备。           | function unprepareCooperate(): Promise&lt;void&gt;;          |
| function activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void; | 使用cooperate.activateCooperate启动键鼠穿越。                | function activateCooperate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback&lt;void&gt;): void; |
| function activate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;; | 使用cooperate.activateCooperate启动键鼠穿越。                | function activateCooperate(targetNetworkId: string, inputDeviceId: number): Promise&lt;void&gt;; |
| function deactivate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void; | 使用cooperate.deactivateCooperate停止键鼠穿越。              | function deactivateCooperate(isUnchained: boolean, callback: AsyncCallback&lt;void&gt;): void; |
| function deactivate(isUnchained: boolean): Promise&lt;void&gt;; | 使用cooperate.deactivateCooperate停止键鼠穿越。              | function deactivateCooperate(isUnchained: boolean): Promise&lt;void&gt;; |
| function getCrossingSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void; | 使用cooperate.getCooperateSwitchState获取目标设备键鼠穿越开关的状态。 | function getCooperateSwitchState(networkId: string, callback: AsyncCallback&lt;boolean&gt;): void; |
| function getCrossingSwitchState(networkId: string): Promise&lt;boolean&gt;; | 使用cooperate.getCooperateSwitchState获取目标设备键鼠穿越开关的状态。 | function getCooperateSwitchState(networkId: string): Promise&lt;boolean&gt;; |
| function on(type: 'cooperate', callback: Callback&lt;{ networkId: string, msg: CooperateMsg }&gt;): void; | 使用cooperate.on注册监听键鼠穿越状态。                       | function on(type: 'cooperateMessage', callback: Callback&lt;CooperateMessage&gt;): void; |
| function off(type: 'cooperate', callback?: Callback&lt;void&gt;): void; | 使用cooperate.off取消监听键鼠穿越状态。                      | function off(type: 'cooperateMessage', callback?: Callback&lt;CooperateMessage&gt;): void; |
| enum CooperateMsg                                            | 使用CooperateMessage表示键鼠穿越的消息通知。                 | interface CooperateMessage                                   |
| COOPERATE_PREPARE                                            | 使用CooperateState.COOPERATE_PREPARE表示准备键鼠穿越。       | CooperateState.COOPERATE_PREPARE                             |
| COOPERATE_UNPREPARE                                          | 使用CooperateState.COOPERATE_UNPREPARE表示取消键鼠穿越准备   | CooperateState.COOPERATE_UNPREPARE                           |
| COOPERATE_ACTIVATE                                           | 使用CooperateState.COOPERATE_ACTIVATE表示启动键鼠穿越。      | CooperateState.COOPERATE_ACTIVATE                            |
| COOPERATE_ACTIVATE_SUCCESS                                   | 使用CooperateState.COOPERATE_ACTIVATE_SUCCESS表示键鼠穿越启动成功。 | CooperateState.COOPERATE_ACTIVATE_SUCCESS                    |
| COOPERATE_ACTIVATE_FAIL                                      | 使用CooperateState.COOPERATE_ACTIVATE_FAILURE表示键鼠穿越启动失败。 | CooperateState.COOPERATE_ACTIVATE_FAILURE                    |
| COOPERATE_DEACTIVATE_SUCCESS                                 | 使用CooperateState.COOPERATE_DEACTIVATE_SUCCESS表示键鼠穿越停止成功。 | CooperateState.COOPERATE_DEACTIVATE_SUCCESS                  |
| COOPERATE_DEACTIVATE_FAIL                                    | 使用CooperateState.COOPERATE_DEACTIVATE_FAILURE表示键鼠穿越停止失败。 | CooperateState.COOPERATE_DEACTIVATE_FAILURE                  |
| COOPERATE_SESSION_DISCONNECTED                               | 使用CooperateState.COOPERATE_SESSION_DISCONNECTED表示键鼠穿越会话断开。 | CooperateState.COOPERATE_SESSION_DISCONNECTED                |

**适配指导**

建议使用新模块的接口进行开发，参见[@ohos.cooperate ](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/reference/apis/js-apis-devicestatus-cooperate.md#cooperateprepare)。

