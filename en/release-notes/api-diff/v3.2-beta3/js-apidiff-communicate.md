# JS API Changes of the Communication Subsystem

The table below lists the APIs changes of the communication subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.wifi | wifi | function off(type: "deviceConfigChange", callback?: Callback\<number>): void; | Added|
| ohos.wifi | wifi | function on(type: "deviceConfigChange", callback: Callback\<number>): void;  | Added|
| ohos.wifi | wifi | function removeUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>function removeUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void; | Deprecated|
| ohos.wifi | wifi | function addUntrustedConfig(config: WifiDeviceConfig): Promise\<boolean>;<br>function addUntrustedConfig(config: WifiDeviceConfig, callback: AsyncCallback\<boolean>): void;     | Deprecated|
