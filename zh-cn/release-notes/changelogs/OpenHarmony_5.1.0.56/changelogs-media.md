# 媒体子系统Changelog

## cl.media.1 应用创建SoundPool时调用media.createSoundPool接口变更

**访问级别**

公开接口

**变更原因**

原来的应用创建SoundPool实例，一个应用进程只能够创建一个SoundPool实例，为单实例模式，无法满足应用的使用场景。例如很多应用在使用SoundPool的能力的同时，还需要使用TimePicker组件(该组件中封装了SoundPool的能力)，单实例模式会使得SoundPool对象之间互相干扰，影响应用的使用体验。

**变更影响**

此变更不涉及应用适配。

变更前：API 18以下版本(build-profile.json5文件中targetSdkVersion配置为5.1.0(18)以下)，创建的SoundPool对象底层为单实例模式，一个应用进程只能够创建1个SoundPool实例。

变更后：API 18及API 18以上版本(build-profile.json5文件中targetSdkVersion配置为5.1.0(18)及以上)，创建的SoundPool对象底层为多实例模式，一个应用进程最多能够创建128个SoundPool实例。

**起始API Level**

API 18

**变更发生版本**

从OpenHarmony SDK 5.1.0.56开始。

**变更的接口/组件**

无变更接口

**适配指导**

默认行为变更，无需适配。
