
# 分布式数据管理子系统ChangeLog

## cl.distributeddatamgr.1 data.DistributedObject.on参数变更

**变更影响**

无需应用适配变更。

**关键接口/组件变更**

共有2个on函数的参数发生变更

修改前的接口原型

 ```ts
 on(type: 'change', callback: Callback<{ sessionId: string, fields: Array<string> }>): void;
 on(
   type: 'status',
   callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
 ): void;
 
 ```

修改后的接口原型

 ```ts
 on(type: 'change', callback: (sessionId: string, fields: Array<string>) => void): void;
 on(
    type: 'status',
    callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
 ): void;
 ```

**适配指导**

无需应用适配变更。



## cl.distributeddatamgr.2 data.DistributedObject.off参数变更

**变更影响**

无需应用适配变更。

**关键接口/组件变更**

共有2个off函数的参数发生变更

修改前的接口原型

 ```ts
off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array<string> }>): void;
off(
  type: 'status',
  callback?: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;

 ```

修改后的接口原型

 ```ts
off(type: 'change', callback?: (sessionId: string, fields: Array<string>) => void): void;
off(
   type: 'status',
   callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**适配指导**

无需应用适配变更。



## cl.distributeddatamgr.3 data.DataObject.on参数变更

**变更影响**

无需应用适配变更。

**关键接口/组件变更**

共有2个on函数的参数发生变更

修改前的接口原型

 ```ts
on(type: 'change', callback: Callback<{ sessionId: string, fields: Array<string> }>): void;
on(
  type: 'status',
  callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;

 ```

修改后的接口原型

 ```ts
on(type: 'change', callback: (sessionId: string, fields: Array<string>) => void): void;
on(
   type: 'status',
   callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**适配指导**

无需应用适配变更。



## cl.distributeddatamgr.4 data.DataObject.off参数变更

**变更影响**

无需应用适配变更。

**关键接口/组件变更**

共有2个off函数的参数发生变更

修改前的接口原型

 ```ts
off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array<string> }>): void;
off(
  type: 'status',
  callback?: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;

 ```

修改后的接口原型

 ```ts
off(type: 'change', callback?: (sessionId: string, fields: Array<string>) => void): void;
off(
   type: 'status',
   callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**适配指导**

无需应用适配变更。



## cl.distributeddatamgr.5 data.preferences.on参数变更

**变更影响**

无需应用适配变更。

**关键接口/组件变更**

修改前的接口原型

 ```ts
on(type: 'multiProcessChange', callback: Callback<{ key : string }>): void
on(type: 'change', callback: Callback<{ key : string }>): void
 ```

修改后的接口原型

 ```ts
on(type: 'multiProcessChange', callback: ( key : string ) => void): void
on(type: 'change', callback: ( key : string ) => void): void
 ```

**适配指导**

无需应用适配变更。



## cl.distributeddatamgr.6 data.preferences.off参数变更

**变更影响**

无需应用适配变更。

**关键接口/组件变更**

修改前的接口原型

 ```ts
off(type: 'multiProcessChange', callback?: Callback<{ key : string }>): void
off(type: 'change', callback?: Callback<{ key : string }>): void
 ```

修改后的接口原型

 ```ts
off(type: 'multiProcessChange', callback?: ( key : string ) => void): void
off(type: 'change', callback?: ( key : string ) => void): void
 ```

**适配指导**

无需应用适配变更。

