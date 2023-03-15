# JS API Changes of the DSoftBus Subsystem

The table below lists the APIs changes of the DSoftBus subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.rpc | RemoteProxy | sendRequestAsync(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>; | Added|
| ohos.rpc | RemoteObject | sendRequestAsync(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>; | Added|
| ohos.rpc | IRemoteObject | sendRequestAsync(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult>; | Added|
