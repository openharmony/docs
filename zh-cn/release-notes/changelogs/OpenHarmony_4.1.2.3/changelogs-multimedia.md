# multimedia子系统ChangeLog

## cl.multimedia.1 5400102错误码实现修正

部分含入参的API10接口，当开发者传递的参数错误，或状态机异常（如load未完成就直接play），接口应当按照API声明抛出操作异常，提醒开发者在应用调试过程中出现此类接口使用问题。
当前版本修正了部分接口没有按此预期抛出错误的问题

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
load(uri: string): Promise<number>
load(fd: number, offset: number, length: number): Promise<number>
play(soundID: number, params: PlayParameters, callback: AsyncCallback<number>): void
play(soundID: number, callback: AsyncCallback<number>): void
play(soundID: number, params?: PlayParameters): Promise<number>
stop(streamID: number, callback: AsyncCallback<void>): void
stop(streamID: number): Promise<void>
setLoop(streamID: number, loop: number): Promise<void>
setPriority(streamID: number, priority: number): Promise<void>
setRate(streamID: number, rate: audio.AudioRendererRate): Promise<void>
setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise<void>
unload(soundID: number): Promise<void>
```

修改后，上述接口新增5400102错误码声明:

```ts
@throws { BusinessError } 5400102 - Operation not allowed.
```

**适配指导**

正确使用API，无需适配。如发现抛出异常，则说明传入参数有误，或状态机异常，需要按照API定义调用接口。

## cl.multimedia.2 5400103错误码实现修正

部分含入参的API10接口，当开发者调用接口发生媒体与其他模块的数据交互问题（I/O ERROR）的时候，接口应当按照接口声明抛出异常，提醒开发者在应用调试过程中出现此类接口使用问题。
当前版本修正了部分接口没有按此预期抛出错误的问题

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
load(uri: string): Promise<number>
load(fd: number, offset: number, length: number, callback: AsyncCallback<number>): void
load(fd: number, offset: number, length: number): Promise<number>
unload(soundID: number): Promise<void>
```

修改后，上述接口新增5400103错误码声明:

```ts
@throws { BusinessError } 5400103 - I/O error.
```

**适配指导**

正确使用API，无需适配。如发现抛出异常，则说明发生媒体与其他模块的数据交互问题，需要按照API定义调用接口。

## cl.multimedia.3 5400105错误码实现修正

部分含入参的API10接口，当调用接口发生播放服务死亡时，接口应当按照接口声明抛出异常，提醒开发者在应用调试过程中出现此类接口使用问题。
当前版本修正了部分接口没有按此预期抛出错误的问题

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
load(uri: string): Promise<number>
load(fd: number, offset: number, length: number): Promise<number>
play(soundID: number, params?: PlayParameters): Promise<number>
stop(streamID: number): Promise<void>
setLoop(streamID: number, loop: number): Promise<void>
setPriority(streamID: number, priority: number): Promise<void>
setRate(streamID: number, rate: audio.AudioRendererRate): Promise<void>
setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise<void>
unload(soundID: number): Promise<void>
release(): Promise<void>
```

修改后，上述接口新增5400105错误码声明:

```ts
@throws { BusinessError } 5400105 - Service died.
```

**适配指导**

正确使用API，无需适配。如发现抛出异常，则说明当前播放服务死亡，需要按照API定义调用接口。

## cl.multimedia.4 SoundPool.on('loadComplete')接口实现错误修正

SoundPool的on('loadComplete')接口，按照API定义，开发者调用接口进行加载完成监听，发生错误时通过on('error')回调接口抛出。历史版本中接口抛出错误码的设计多余，在新版本中修复此问题。

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
on(type: 'loadComplete', callback: Callback<number>): void
```

修改后，上述接口不进行错误码声明:

```ts
@param {'loadComplete'} type Type of the play finish event to listen for.
@param {Callback<number>} callback Callback used to listen for load result event
@syscap SystemCapability.Multimedia.Media.SoundPool
@since 10
```

**适配指导**

正确使用API，无需适配。按照API定义调用接口，发生错误时通过on('error')回调接口抛出，不需要针对接口进行抛出错误码的设计。

## cl.multimedia.5 SoundPool.on('playFinished')接口实现错误修正

SoundPool的on('playFinished')接口，按照API定义，开发者调用接口进行播放完成监听，发生错误时通过on('error')回调接口抛出。历史版本中接口抛出错误码的设计多余，在新版本中修复此问题。

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
on(type: 'playFinished', callback: Callback<void>): void
```

修改后，上述接口不进行错误码声明:

```ts
@param {'loadComplete'} type Type of the play finish event to listen for.
@param {Callback<number>} callback Callback used to listen for load result event
@syscap SystemCapability.Multimedia.Media.SoundPool
@since 10
```

**适配指导**

正确使用API，无需适配。按照API定义调用接口，发生错误时通过on('error')回调接口抛出，不需要针对接口进行抛出错误码的设计。

## cl.multimedia.6 401错误码实现修正

部分含入参的API10接口，当开发者调用接口时缺少入参，接口应当按照API声明抛出401操作异常，提醒开发者在应用调试过程中出现了此类接口使用问题。
当前版本修正了部分接口没有按此预期抛出错误的问题

**变更影响**

仅影响错误使用接口的场景

当前变更涉及的接口原型：

```ts
play(soundID: number, params: PlayParameters, callback: AsyncCallback<number>): void;
play(soundID: number, callback: AsyncCallback<number>): void;
play(soundID: number, params?: PlayParameters): Promise<number>;
stop(streamID: number, callback: AsyncCallback<void>): void;
stop(streamID: number): Promise<void>;
setLoop(streamID: number, loop: number, callback: AsyncCallback<void>): void;
setLoop(streamID: number, loop: number): Promise<void>;
setPriority(streamID: number, priority: number, callback: AsyncCallback<void>): void;
setPriority(streamID: number, priority: number): Promise<void>;
setRate(streamID: number, rate: audio.AudioRendererRate, callback: AsyncCallback<void>): void;
setRate(streamID: number, rate: audio.AudioRendererRate): Promise<void>;
setVolume(streamID: number, leftVolume: number, rightVolume: number, callback: AsyncCallback<void>): void;
setVolume(streamID: number, leftVolume: number, rightVolume: number): Promise<void>;
```

修改后，上述接口新增401错误码声明:

```ts
@throws { BusinessError } 401 - The parameter check failed. Return by callback.
```

**适配指导**

正确使用API，无需适配。如发现抛出异常，则说明当前接口调用缺少必要参数，需要按照API定义调用接口。