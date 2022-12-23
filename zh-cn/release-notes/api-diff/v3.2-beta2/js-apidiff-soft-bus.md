# 分布式软总线子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，分布式软总线子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.rpc | RemoteProxy | sendRequestAsync(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>; | 新增 |
| ohos.rpc | RemoteObject | sendRequestAsync(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>; | 新增 |
| ohos.rpc | IRemoteObject | sendRequestAsync(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>; | 新增 |
