| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：stationary;<br>方法or属性：type ActivityType = 'still' \| 'relativeStill';|@ohos.stationary.d.ts|
|新增|NA|类名：stationary;<br>方法or属性：function on(activity: ActivityType, event: ActivityEvent, reportLatencyNs: number, callback: Callback\<ActivityResponse>): void;|@ohos.stationary.d.ts|
|新增|NA|类名：stationary;<br>方法or属性：function once(activity: ActivityType, callback: Callback\<ActivityResponse>): void;|@ohos.stationary.d.ts|
|新增|NA|类名：stationary;<br>方法or属性：function off(activity: ActivityType, event: ActivityEvent, callback?: Callback\<ActivityResponse>): void;|@ohos.stationary.d.ts|
|新增|NA|类名：ActivityResponse;<br>方法or属性：state: ActivityState;|@ohos.stationary.d.ts|
|新增|NA|类名：ActivityEvent;<br>方法or属性：ENTER = 1|@ohos.stationary.d.ts|
|新增|NA|类名：ActivityState;<br>方法or属性：ENTER = 1|@ohos.stationary.d.ts|
|新增|NA|类名：ActivityEvent;<br>方法or属性：EXIT = 2|@ohos.stationary.d.ts|
|新增|NA|类名：ActivityState;<br>方法or属性：EXIT = 2|@ohos.stationary.d.ts|
|新增|NA|类名：ActivityEvent;<br>方法or属性：ENTER_EXIT = 3|@ohos.stationary.d.ts|
