
# 分布式数据管理子系统ChangeLog

## cl.distributeddatamgr.1 data.distributedDataObject.on参数变更

**变更影响**

无需应用适配变更。

**关键接口/组件变更**

修改前的接口原型

 ```ts
 on(type: 'change', callback: Callback<{ sessionId: string, fields: Array<string> }>): void;
 ```

修改后的接口原型

 ```ts
 on(type: 'change', callback: (sessionId: string, fields: Array<string>) => void): void;
 ```

**适配指导**
无需应用适配变更。



## cl.distributeddatamgr.2 data.distributedDataObject.off参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array<string> }>): void;
 ```

修改后的接口原型

 ```ts
off(type: 'change', callback?: (sessionId: string, fields: Array<string>) => void): void;
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改



## cl.distributeddatamgr.3 data.distributedDataObject.on参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
on(
  type: 'status',
  callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;
 ```

修改后的接口原型

 ```ts
 on(
   type: 'status',
   callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
 ): void;
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改



## cl.distributeddatamgr.4 data.distributedDataObject.off参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
off(
   type: 'status',
   callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' | 'offline' }>
): void;
 ```

修改后的接口原型

 ```ts
off(
   type: 'status',
   callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改



## cl.distributeddatamgr.5 data.distributedDataObject.off参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
on(type: 'change', callback: Callback<{ sessionId: string, fields: Array<string> }>): void;
 ```

修改后的接口原型

 ```ts
 on(type: 'change', callback: (sessionId: string, fields: Array<string>) => void ): void;
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改



## cl.distributeddatamgr.6 data.distributedDataObject.off参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array<string> }>): void;
 ```

修改后的接口原型

 ```ts
off(type: 'change', callback?: (sessionId: string, fields: Array<string>) => void ): void;
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改



## cl.distributeddatamgr.7 data.distributedDataObject.off参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
on(
  type: 'status',
  callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;
 ```

修改后的接口原型

 ```ts
on(
  type: 'status',
  callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改



## cl.distributeddatamgr.8 data.distributedDataObject.off参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
off(
   type: 'status',
   callback?: Callback<{ sessionId: string, deviceId: string, status: 'online' | 'offline' }>
): void;
 ```

修改后的接口原型

 ```ts
off(
   type: 'status',
   callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改



## cl.distributeddatamgr.9 data.preferences.on参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
on(type: 'change', callback: Callback<{ key : string }>): void
 ```

修改后的接口原型

 ```ts
on(type: 'change', callback: ( key : string ) => void): void
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改



## cl.distributeddatamgr.10 data.preferences.on参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
on(type: 'multiProcessChange', callback: Callback<{ key : string }>): void
 ```

修改后的接口原型

 ```ts
on(type: 'multiProcessChange', callback: ( key : string ) => void): void
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改



## cl.distributeddatamgr.11 data.preferences.off参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
off(type: 'change', callback?: Callback<{ key : string }>): void
 ```

修改后的接口原型

 ```ts
off(type: 'change', callback?: ( key : string ) => void): void
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改



## cl.distributeddatamgr.12 data.preferences.off参数变更

**变更影响**

按照示例代码编写的应用，无需应用适配变更

**关键接口/组件变更**

修改前的接口原型

 ```ts
off(type: 'multiProcessChange', callback?: Callback<{ key : string }>): void
 ```

修改后的接口原型

 ```ts
off(type: 'multiProcessChange', callback?: ( key : string ) => void): void
 ```

**适配指导**
示例代码如下：

按照示例代码编写的应用无需修改
