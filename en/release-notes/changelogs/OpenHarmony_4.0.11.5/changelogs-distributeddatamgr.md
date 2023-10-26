
# Distributed Data Management Subsystem Changelog

## cl.distributeddatamgr.1 Change of the Parameters in data.DistributedObject.on

**Change Impact**

The change has no impact on applications.

**Key API/Component Changes**

Changed the parameters of two **on()** methods.

Before change:

 ```ts
 on(type: 'change', callback: Callback<{ sessionId: string, fields: Array<string> }>): void;
 on(
   type: 'status',
   callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
 ): void;
 
 ```

After change:

 ```ts
 on(type: 'change', callback: (sessionId: string, fields: Array<string>) => void): void;
 on(
    type: 'status',
    callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
 ): void;
 ```

**Adaptation Guide**

N/A.



## cl.distributeddatamgr.2 Change of the Parameters in data.DistributedObject.off

**Change Impact**

The change has no impact on applications.

**Key API/Component Changes**

Changed the parameters of two **off()** methods.

Before change:

 ```ts
off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array<string> }>): void;
off(
  type: 'status',
  callback?: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;

 ```

After change:

 ```ts
off(type: 'change', callback?: (sessionId: string, fields: Array<string>) => void): void;
off(
   type: 'status',
   callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**Adaptation Guide**

N/A.



## cl.distributeddatamgr.3 Change of Parameters in data.DataObject.on

**Change Impact**

The change has no impact on applications.

**Key API/Component Changes**

Changed the parameters of two **on()** methods.

Before change:

 ```ts
on(type: 'change', callback: Callback<{ sessionId: string, fields: Array<string> }>): void;
on(
  type: 'status',
  callback: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;

 ```

After change:

 ```ts
on(type: 'change', callback: (sessionId: string, fields: Array<string>) => void): void;
on(
   type: 'status',
   callback: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**Adaptation Guide**

N/A.



## cl.distributeddatamgr.4 Change of Parameters in data.DataObject.off

**Change Impact**

The change has no impact on applications.

**Key API/Component Changes**

Changed the parameters of two **off()** methods.

Before change:

 ```ts
off(type: 'change', callback?: Callback<{ sessionId: string, fields: Array<string> }>): void;
off(
  type: 'status',
  callback?: Callback<{ sessionId: string, networkId: string, status: 'online' | 'offline' }>
): void;

 ```

After change:

 ```ts
off(type: 'change', callback?: (sessionId: string, fields: Array<string>) => void): void;
off(
   type: 'status',
   callback?: (sessionId: string, networkId: string, status: 'online' | 'offline' ) => void
): void;
 ```

**Adaptation Guide**

N/A.



## cl.distributeddatamgr.5 Change of Parameters in data.preferences.on

**Change Impact**

The change has no impact on applications.

**Key API/Component Changes**

Before change:

 ```ts
on(type: 'multiProcessChange', callback: Callback<{ key : string }>): void
on(type: 'change', callback: Callback<{ key : string }>): void
 ```

After change:

 ```ts
on(type: 'multiProcessChange', callback: ( key : string ) => void): void
on(type: 'change', callback: ( key : string ) => void): void
 ```

**Adaptation Guide**

N/A.



## cl.distributeddatamgr.6 Change of Parameters in data.preferences.off

**Change Impact**

The change has no impact on applications.

**Key API/Component Changes**

Before change:

 ```ts
off(type: 'multiProcessChange', callback?: Callback<{ key : string }>): void
off(type: 'change', callback?: Callback<{ key : string }>): void
 ```

After change:

 ```ts
off(type: 'multiProcessChange', callback?: ( key : string ) => void): void
off(type: 'change', callback?: ( key : string ) => void): void
 ```

**Adaptation Guide**

N/A.
