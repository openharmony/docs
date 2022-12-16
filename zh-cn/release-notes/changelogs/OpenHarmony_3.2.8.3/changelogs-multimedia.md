# 多媒体子系统ChangeLog

## cl.multimedia.audio.001 getRoutingManager()调用方式变更

getRoutingManager()接口的调用方法由异步变为同步。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
getRoutingManager(callback: AsyncCallback<AudioRoutingManager>): void;
getRoutingManager(): Promise<AudioRoutingManager>;
```
变更后
```js
getRoutingManager(): AudioRoutingManager;
```


## cl.multimedia.audio.002 getStreamManager()调用方式变更

getStreamManager()接口的调用方法由异步变为同步。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
getStreamManager(callback: AsyncCallback<AudioStreamManager>): void;
getStreamManager(): Promise<AudioStreamManager>;
```
变更后
```js
getStreamManager(): AudioStreamManager;
```


## cl.multimedia.audio.003 原AudioRoutingManager中micStateChange监听注册方式变更

原AudioRoutingManager中，on()函数的micStateChange监听注册方式变更。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前

```js
interface AudioRoutingManager {
   on(type: 'micStateChange', callback: Callback<MicStateChangeEvent>): void;
}
```
变更后
```js
interface AudioVolumeGroupManager {
  on(type: 'micStateChange', callback: Callback<MicStateChangeEvent>): void;
}
```


## cl.multimedia.audio.004 getVolumeGroups()调用方式变更

getVolumeGroups()接口的调用方式变更。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
getVolumeGroups(networkId: string, callback:AsyncCallback<VolumeGroupInfos>): void;
getVolumeGroups(networkId: string): Promise<VolumeGroupInfos>;
```
变更后
```js
getVolumeManager(): AudioVolumeManager;
interface AudioVolumeManager{
  getVolumeGroupInfos(networkId: string, callback: AsyncCallback<VolumeGroupInfos>): void;
  getVolumeGroupInfos(networkId: string): Promise<VolumeGroupInfos>;
}
```


## cl.multimedia.audio.005 getGroupManager()调用方式变更

getGroupManager()接口的调用方式变更。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
getGroupManager(groupId: number, callback: AsyncCallback<AudioGroupManager>): void;
getGroupManager(groupId: number): Promise<AudioGroupManager>;
```
变更后
```js
getVolumeManager(): AudioVolumeManager;
interface AudioVolumeManager{
  getVolumeGroupManager(groupId: number, callback: AsyncCallback<AudioVolumeGroupManager>): void;
  getVolumeGroupManager(groupId: number): Promise<AudioVolumeGroupManager>;
}
```


## cl.multimedia.audio.006 枚举FocusType成员名变更

枚举FocusType中，成员FOCUS_TYPE_RECORDING重命名为FOCUS_TYPE_DEFAULT。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
enum FocusType {
  FOCUS_TYPE_RECORDING = 0,
}
```
变更后
```js
enum InterruptRequestType {
  INTERRUPT_REQUEST_TYPE_DEFAULT = 0,
}
```


## cl.multimedia.audio.007 AudioRenderer中interrupt监听注册名称变更

AudioRenderer中on()函数的interrupt监听注册名称变更。

**变更影响**

如不符合上述调用规则，将会在编译执行时出错。

**关键的接口/组件变更**

变更前
```js
interface AudioRenderer {
    on(type: 'interrupt', callback: Callback<InterruptEvent>): void;
}
```
变更后
```js
interface AudioRenderer {
    on(type: 'audioInterrupt', callback: Callback<InterruptEvent>): void;
}
```
