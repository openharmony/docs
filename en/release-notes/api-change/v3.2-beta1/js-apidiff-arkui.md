# JS API Changes of the ArkUI Development Framework

The table below lists the APIs changes of the ArkUI development framework in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| common |  | function getContext(component?: Object): Object; | Added|
| sidebar | SideBarContainerAttribute | autoHide(value: boolean): SideBarContainerAttribute; | Added|
| state_management | LocalStorage | clear(): boolean; | Added|
| state_management | LocalStorage | delete(propName: string): boolean; | Added|
| state_management | LocalStorage | setAndProp\<T>(propName: string, defaultValue: T, propUser?: T, subscribersName?: string): T; | Added|
| state_management | LocalStorage | prop\<T>(propName: string, propUser?: T, subscribersName?: string): T; | Added|
| state_management | LocalStorage | setAndLink\<T>(propName: string, defaultValue: T, linkUser?: T, subscribersName?: string): T; | Added|
| state_management | LocalStorage | link\<T>(propName: string, linkUser?: T, subscribersName?: string): T; | Added|
| state_management | LocalStorage | setOrCreate\<T>(propName: string, newValue?: T): boolean; | Added|
| state_management | LocalStorage | set\<T>(propName: string, newValue: T): boolean; | Added|
| state_management | LocalStorage | get\<T>(propName: string): T; | Added|
| state_management | LocalStorage | size(): number; | Added|
| state_management | LocalStorage | keys(): IterableIterator\<string>; | Added|
| state_management | LocalStorage | has(propName: string): boolean; | Added|
| state_management | LocalStorage | static GetShared(): LocalStorage; | Added|
| state_management | LocalStorage | constructor(initializingProperties?: Object); | Added|
