# ArkUI子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，ArkUI子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| common |  | function getContext(component?: Object): Object; | 新增 |
| sidebar | SideBarContainerAttribute | autoHide(value: boolean): SideBarContainerAttribute; | 新增 |
| state_management | LocalStorage | clear(): boolean; | 新增 |
| state_management | LocalStorage | delete(propName: string): boolean; | 新增 |
| state_management | LocalStorage | setAndProp\<T>(propName: string, defaultValue: T, propUser?: T, subscribersName?: string): T; | 新增 |
| state_management | LocalStorage | prop\<T>(propName: string, propUser?: T, subscribersName?: string): T; | 新增 |
| state_management | LocalStorage | setAndLink\<T>(propName: string, defaultValue: T, linkUser?: T, subscribersName?: string): T; | 新增 |
| state_management | LocalStorage | link\<T>(propName: string, linkUser?: T, subscribersName?: string): T; | 新增 |
| state_management | LocalStorage | setOrCreate\<T>(propName: string, newValue?: T): boolean; | 新增 |
| state_management | LocalStorage | set\<T>(propName: string, newValue: T): boolean; | 新增 |
| state_management | LocalStorage | get\<T>(propName: string): T; | 新增 |
| state_management | LocalStorage | size(): number; | 新增 |
| state_management | LocalStorage | keys(): IterableIterator\<string>; | 新增 |
| state_management | LocalStorage | has(propName: string): boolean; | 新增 |
| state_management | LocalStorage | static GetShared(): LocalStorage; | 新增 |
| state_management | LocalStorage | constructor(initializingProperties?: Object); | 新增 |
