# Camera子系统变更说明

OpenHarmony 4.1.6.1 版本相较于OpenHarmony之前的版本，Camera的API使用权限变更如下。

## cl.camera.1 getSupportedOutputCapability接口变更

**访问级别**

公开接口

**变更原因**

getSupportedOutputCapability用来查询相机设备支持的输出能力，增加入参mode: SceneMode，接口改为查询相机设备在模式下支持的输出能力。

**变更影响**

getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability会在API11版本废弃，保留五个版本。
API11版本新增getSupportedOutputCapability(camera: CameraDevice, mode: SceneMode): CameraOutputCapability。

**关键的接口/组件变更**

- 涉及接口

  getSupportedOutputCapability(camera: CameraDevice): CameraOutputCapability

- 变更前：

  入参只有相机设备camera: CameraDevice。

- 变更后：

  增加入参相机模式mode: SceneMode。

**适配指导**

先通过API11新增接口getSupportedSceneModes(camera: CameraDevice): Array\<SceneMode\>， 来获取相机设备对象支持的模式，再通过新增getSupportedOutputCapability(camera: CameraDevice, mode: SceneMode): CameraOutputCapability接口，查询相机设备在模式下支持的输出能力。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.3开始。

## cl.camera.2 createPhotoOutput接口变更

**访问级别**

公开接口

**变更原因**

createPhotoOutput用来创建拍照输出对象，删除入参surfaceId: string，接口改为只通过拍照配置信息创建拍照输出对象。

**变更影响**

createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput会在API11版本废弃，保留五个版本。
API11版本新增createPhotoOutput(profile: Profile): PhotoOutput。

**关键的接口/组件变更**

- 涉及接口

  createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

- 变更前：

  入参包含支持的拍照配置信息profile以及从ImageReceiver获取的surfaceId。

- 变更后：

  入参只有支持的拍照配置信息profile。

**适配指导**

先通过API11新增接口createPhotoOutput(profile: Profile): PhotoOutput， 来创建拍照输出对象。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.3开始。

## cl.camera.3 createCaptureSession接口变更

**访问级别**

公开接口

**变更原因**

createCaptureSession用来创建CaptureSession实例，API11后，Session通过模式进行区分，分为PhotoSession和VideoSession，通过API11新增接口createSession\<T extends Session\>(mode: SceneMode): T进行创建。

**变更影响**

createCaptureSession(): CaptureSession会在API11版本废弃，保留五个版本。
API11版本新增createSession\<T extends Session\>(mode: SceneMode): T。

**关键的接口/组件变更**

- 涉及接口

  createPhotoOutput(profile: Profile, surfaceId: string): PhotoOutput

- 变更前：

  通过createCaptureSession(): CaptureSession创建CaptureSession实例。

- 变更后：

  通过createSession\<T extends Session\>(mode: SceneMode): T创建对应模式的Session。

**适配指导**

通过API11新增接口createSession\<T extends Session\>(mode: SceneMode): T创建对应模式的Session。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.3开始。

## cl.camera.4 CaptureSession接口变更

**访问级别**

公开接口

**变更原因**

CaptureSession用来保存一次相机运行所需要的所有资源CameraInput、CameraOutput，并向相机设备申请完成相机功能（录像，拍照）的会话类。

**变更影响**

CaptureSession以及包含的接口会在API11版本废弃，保留五个版本。
API11版本新增PhotoSession和VideoSession区分录像会话和拍照会话。

**关键的接口/组件变更**

- 涉及接口

  CaptureSession

- 变更前：

  通过createCaptureSession(): CaptureSession创建CaptureSession实例。

- 变更后：

  通过createSession\<T extends Session\>(mode: SceneMode): T创建录像会话和拍照会话对应模式的Session。

**适配指导**

通过API11新增接口PhotoSession对应拍照模式会话，VideoSession对应录像模式会话。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.3开始。

## cl.camera.5 PreviewOutput类start与stop接口变更

**访问级别**

公开接口

**变更原因**

PreviewOutput作为相机的预览输出，和会话保持一致，因此会话中的开始与停止操作，可以包含预览输出的开始与停止操作，因此PreviewOutput中的start与stop操作，在API11版本合并至Session的start与stop操作中。

**变更影响**

PreviewOutput接口包含的start与stop接口会在API11版本废弃，保留五个版本，合并至Session的start与stop操作中。

**关键的接口/组件变更**

- 涉及接口

  PreviewOutput类start与stop

- 变更前：

  interface PreviewOutput extends CameraOutput
    start(callback: AsyncCallback\<void\>): void
    start(): Promise\<void\>
    stop(callback: AsyncCallback\<void\>): void
    stop(): Promise\<void\>

- 变更后：

  合并至PhotoSession或VideoSession的start和stop接口。

**适配指导**

无需适配，通过API11新增的PhotoSession或VideoSession的start和stop接口，或是CaptureSession的start和stop接口，即可执行PreviewOutput类的start和stop接口。

## cl.camera.6 captureStart注册监听与解除注册监听接口变更

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.3开始。

**访问级别**

公开接口

**变更原因**

captureStart注册监听与解除注册监听接口用来监听拍照开始，通过注册回调函数获取Capture ID，在API11版本中，captureStart事件会返回更多的信息，相关回调无法获取更多信息。

**变更影响**

captureStart注册监听与解除注册监听接口以及包含的接口会在API11版本废弃，保留五个版本。
API11版本新增captureStartInfo注册监听与解除注册监听接口。回调数据为CaptureStartInfo结构体，可扩展性获取更多信息

**关键的接口/组件变更**

- 涉及接口

  on(type: 'captureStart', callback: AsyncCallback\<number\>): void
  off(type: 'captureStart', callback?: AsyncCallback\<number\>): void

- 变更前：

  通过captureStart注册监听与解除注册监听接口用来监听拍照开始，通过注册回调函数获取Capture ID。

- 变更后：

  新增CaptureStartInfo结构体，可扩展性获取更多信息
  新增on(type: 'captureStartWithInfo', callback: AsyncCallback\<CaptureStartInfo\>): void
  新增off(type: 'captureStartWithInfo', callback?: AsyncCallback\<CaptureStartInfo\>): void

**适配指导**

通过API11新增captureStartInfo注册监听与解除注册监听接口获取CaptureStartInfo。

**API Level**

11

**变更发生版本**

从OpenHarmony SDK 4.1.6.3开始。
