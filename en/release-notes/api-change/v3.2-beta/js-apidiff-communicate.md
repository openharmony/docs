# JS API Changes of the Communication Subsystem

The table below lists the APIs changes of the communication subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.bluetooth | ProfileId | PROFILE_HID_HOST = 6 | Added|
| ohos.bluetooth | HidHostProfile | off(type: "connectionStateChange", callback?: Callback\<StateChangeParam>): void; | Added|
| ohos.bluetooth | HidHostProfile | on(type: "connectionStateChange", callback: Callback\<StateChangeParam>): void; | Added|
| ohos.bluetooth | HidHostProfile | disconnect(device: string): boolean; | Added|
| ohos.bluetooth | HidHostProfile | connect(device: string): boolean; | Added|
