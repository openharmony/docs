# JS API Changes of the DSoftBus Subsystem

The table below lists the APIs changes of the DSoftBus subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.rpc | RemoteObject | onRemoteRequestEx(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean \| Promise\<boolean>; | Added|
| ohos.rpc | RemoteObject | onRemoteRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean; | Deprecated|
