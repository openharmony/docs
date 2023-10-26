# Multimedia Subsystem Changelog

## cl.multimedia.1 Implementation of Error Code 5400102 Corrected

If a parameter passed in to an API is incorrect or an API is called in an incorrect state (for example, **play()** is called before **load()** is complete), the API should throw an error according to the API declaration.
However, certain APIs that contain input parameters and is of API version 10 do not throw errors as expected. This issue is rectified.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

The following lists the API prototypes involved in this change.

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

Error code 5400102 is declared in these APIs.

```ts
@throws { BusinessError } 5400102 - Operation not allowed.
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If error code 5400102 is thrown, call the API according to the API definition.

## cl.multimedia.2 Implementation of Error Code 5400103 Corrected

If an I/O error occurs during the interaction between the media module and other modules, the API should throw an error according to the API declaration.
However, certain APIs that contain input parameters and is of API version 10 do not throw errors as expected. This issue is rectified.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

The following lists the API prototypes involved in this change.

```ts
load(uri: string): Promise<number>
load(fd: number, offset: number, length: number, callback: AsyncCallback<number>): void
load(fd: number, offset: number, length: number): Promise<number>
unload(soundID: number): Promise<void>
```

Error code 5400103 is declared in these APIs.

```ts
@throws { BusinessError } 5400103 - I/O error.
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If error code 5400103 is thrown, call the API according to the API definition.

## cl.multimedia.3 Implementation of Error Code 5400105 Corrected

If the playback service is dead when an API is called, the API should throw an error according to the API declaration.
However, certain APIs that contain input parameters and is of API version 10 do not throw errors as expected. This issue is rectified.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

The following lists the API prototypes involved in this change.

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

Error code 5400105 is declared in these APIs.

```ts
@throws { BusinessError } 5400105 - Service died.
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If error code 5400105 is thrown, call the API according to the API definition.

## cl.multimedia.4 Implementation of SoundPool.on('loadComplete') Corrected

According to the API definition, if an error occurs during sound loading, **on('error')** is triggered to throw the error. There is no need for the system to throw errors in **on('loadComplete')**.

**Change Impact**

The scenario where the API is incorrectly used is affected.

The following lists the API prototype involved in this change.

```ts
on(type: 'loadComplete', callback: Callback<number>): void
```

No error code is declared in this API.

```ts
@param {'loadComplete'} type Type of the play finish event to listen for.
@param {Callback<number>} callback Callback used to listen for load result event
@syscap SystemCapability.Multimedia.Media.SoundPool
@since 10
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If an error occurs during sounds loading, **on('error')** will be triggered to throw the error.

## cl.multimedia.5 Implementation of SoundPool.on('playFinished') Corrected

According to the API definition, if an error occurs during sound playback, **on('error')** is triggered to throw the error. There is no need for the system to throw errors in **on('playFinished')**.

**Change Impact**

The scenario where the API is incorrectly used is affected.

The following lists the API prototype involved in this change.

```ts
on(type: 'playFinished', callback: Callback<void>): void
```

No error code is declared in this API.

```ts
@param {'loadComplete'} type Type of the play finish event to listen for.
@param {Callback<number>} callback Callback used to listen for load result event
@syscap SystemCapability.Multimedia.Media.SoundPool
@since 10
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If an error occurs during sound playback, **on('error')** will be triggered to throw the error.

## cl.multimedia.6 Implementation of Error Code 401 Corrected

If a mandatory parameter is not passed in to an API, the API should throw an error according to the API declaration.
However, certain APIs that contain input parameters and is of API version 10 do not throw errors as expected. This issue is rectified.

**Change Impact**

The scenario where these APIs are incorrectly used is affected.

The following lists the API prototypes involved in this change.

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

Error code 401 is declared in these APIs.

```ts
@throws { BusinessError } 401 - The parameter check failed. Return by callback.
```

**Adaptation Guide**

If the API is called correctly, no adaptation is required. If error code 401 is thrown, pass in the mandatory parameters and call the API according to the API definition.
