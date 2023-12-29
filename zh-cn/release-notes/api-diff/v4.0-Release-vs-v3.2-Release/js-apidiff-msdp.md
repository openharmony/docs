| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：cooperate;<br>方法or属性：function prepare(callback: AsyncCallback\<void>): void;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function prepare(): Promise\<void>;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function unprepare(callback: AsyncCallback\<void>): void;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function unprepare(): Promise\<void>;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function activate(targetNetworkId: string, inputDeviceId: number, callback: AsyncCallback\<void>): void;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function activate(targetNetworkId: string, inputDeviceId: number): Promise\<void>;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function deactivate(isUnchained: boolean, callback: AsyncCallback\<void>): void;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function deactivate(isUnchained: boolean): Promise\<void>;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function getCrossingSwitchState(networkId: string, callback: AsyncCallback\<boolean>): void;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function getCrossingSwitchState(networkId: string): Promise\<boolean>;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function on(type: 'cooperate', callback: Callback\<{ networkId: string, msg: CooperateMsg }>): void;|@ohos.cooperate.d.ts|
|新增|NA|类名：cooperate;<br>方法or属性：function off(type: 'cooperate', callback?: Callback\<void>): void;|@ohos.cooperate.d.ts|
|新增|NA|类名：CooperateMsg;<br>方法or属性：COOPERATE_PREPARE = 0|@ohos.cooperate.d.ts|
|新增|NA|类名：CooperateMsg;<br>方法or属性：COOPERATE_UNPREPARE = 1|@ohos.cooperate.d.ts|
|新增|NA|类名：CooperateMsg;<br>方法or属性：COOPERATE_ACTIVATE = 2|@ohos.cooperate.d.ts|
|新增|NA|类名：CooperateMsg;<br>方法or属性：COOPERATE_ACTIVATE_SUCCESS = 3|@ohos.cooperate.d.ts|
|新增|NA|类名：CooperateMsg;<br>方法or属性：COOPERATE_ACTIVATE_FAIL = 4|@ohos.cooperate.d.ts|
|新增|NA|类名：CooperateMsg;<br>方法or属性：COOPERATE_DEACTIVATE_SUCCESS = 5|@ohos.cooperate.d.ts|
|新增|NA|类名：CooperateMsg;<br>方法or属性：COOPERATE_DEACTIVATE_FAIL = 6|@ohos.cooperate.d.ts|
|新增|NA|类名：CooperateMsg;<br>方法or属性：COOPERATE_SESSION_DISCONNECTED = 7|@ohos.cooperate.d.ts|
|新增|NA|类名：dragInteraction;<br>方法or属性：function on(type: 'drag', callback: Callback\<DragState>): void;|@ohos.deviceStatus.dragInteraction.d.ts|
|新增|NA|类名：dragInteraction;<br>方法or属性：function off(type: 'drag', callback?: Callback\<DragState>): void;|@ohos.deviceStatus.dragInteraction.d.ts|
|新增|NA|类名：DragState;<br>方法or属性：MSG_DRAG_STATE_START = 1|@ohos.deviceStatus.dragInteraction.d.ts|
|新增|NA|类名：DragState;<br>方法or属性：MSG_DRAG_STATE_STOP = 2|@ohos.deviceStatus.dragInteraction.d.ts|
|新增|NA|类名：DragState;<br>方法or属性：MSG_DRAG_STATE_CANCEL = 3|@ohos.deviceStatus.dragInteraction.d.ts|
