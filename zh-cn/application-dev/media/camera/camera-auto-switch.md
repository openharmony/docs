# 自动切换摄像头实践(ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

本文档仅针对折叠屏设备自动切换前置摄像头的场景。在不同折叠状态下，自动切换到当前状态支持的摄像头。

例如：折叠设备A拥有三颗摄像头：后置摄像头B、前置摄像头C和前置摄像头D。在展开状态下，通过[CameraManager.getSupportedCameras](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedcameras)接口可获取到后置摄像头B和前置摄像头C。在折叠状态下，可获取到后置摄像头B和前置摄像头D。在当前折叠状态下启用前置摄像头，并调用[enableAutoDeviceSwitch](../../reference/apis-camera-kit/arkts-apis-camera-AutoDeviceSwitch.md#enableautodeviceswitch13)开启自动切换镜头。这样，在下次折叠屏状态变化时，会自动切换到对应折叠状态下的前置摄像头。

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/arkts-apis-camera.md)。

Context获取方式请参考：[获取UIAbility的上下文信息](../../application-models/uiability-usage.md#获取uiability的上下文信息)。

在开发相机应用时，请先参考开发准备[申请相关权限](camera-preparation.md)。

## 导入相关依赖
```ts
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl } from '@kit.AbilityKit';
```
## 创建XComponent
使用[XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)展示摄像头的预览画面。
```ts
@Entry
@Component
struct Index {
  private mXComponentController: XComponentController = new XComponentController();
  private mCameraPosition: camera.CameraPosition = camera.CameraPosition.CAMERA_POSITION_BACK;
  private mXComponentOptions: XComponentOptions = {
    type: XComponentType.SURFACE,
    controller: this.mXComponentController
  }

  async loadXComponent() {
    //初始化XComponent。
  }

  build() {
    Stack() {
      XComponent(this.mXComponentOptions)
        .onLoad(async () => {
          await this.loadXComponent();
        })
        .width(this.getUIContext().px2vp(1080))
        .height(this.getUIContext().px2vp(1920))
      Text('切换相机')
        .size({ width: 80, height: 48 })
        .position({ x: 1, y: 1 })
        .backgroundColor(Color.White)
        .textAlign(TextAlign.Center)
        .borderRadius(24)
        .onClick(async () => {
          this.mCameraPosition = this.mCameraPosition === camera.CameraPosition.CAMERA_POSITION_BACK ?
            camera.CameraPosition.CAMERA_POSITION_FRONT : camera.CameraPosition.CAMERA_POSITION_BACK;
          await this.loadXComponent();
        })
    }
    .size({ width: '100%', height: '100%' })
    .backgroundColor(Color.Black)
  }
}
```
## 开启自动切换摄像头
调用[enableAutoDeviceSwitch](../../reference/apis-camera-kit/arkts-apis-camera-AutoDeviceSwitch.md#enableautodeviceswitch13)接口前需要通过[isAutoDeviceSwitchSupported](../../reference/apis-camera-kit/arkts-apis-camera-AutoDeviceSwitchQuery.md#isautodeviceswitchsupported13)接口查询当前设备是否支持自动切换摄像头能力。
```ts
function enableAutoDeviceSwitch(session: camera.PhotoSession) {
  if (session.isAutoDeviceSwitchSupported()) {
    session.enableAutoDeviceSwitch(true);
  }
}
```
## 监听或解监听自动切换摄像头状态
可以通过[enableAutoDeviceSwitch](../../reference/apis-camera-kit/arkts-apis-camera-PhotoSession.md#onautodeviceswitchstatuschange13)监听自动切换摄像头的结果。系统自动切换镜头结束后会触发该回调。
自动切换摄像头期间，禁止调用任何session相关接口。
```ts
function callback(err: BusinessError, autoDeviceSwitchStatus: camera.AutoDeviceSwitchStatus): void {
  if (err !== undefined && err.code !== 0) {
    console.error(`Callback Error, errorCode: ${err.code}`);
    return;
  }
  console.info(`isDeviceSwitched: ${autoDeviceSwitchStatus.isDeviceSwitched}, isDeviceCapabilityChanged: ${autoDeviceSwitchStatus.isDeviceCapabilityChanged}`);
}

function registerAutoDeviceSwitchStatus(photoSession: camera.PhotoSession): void {
  photoSession.on('autoDeviceSwitchStatusChange', callback);
}
function unregisterAutoDeviceSwitchStatus(photoSession: camera.PhotoSession): void {
  photoSession.off('autoDeviceSwitchStatusChange', callback);
}
```

## 完整示例代码
```ts
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl } from '@kit.AbilityKit';

const TAG = 'AutoSwitchCameraDemo ';

@Entry
@Component
struct Index {
  @State isShow: boolean = false;
  @State reloadXComponentFlag: boolean = false;
  private mXComponentController: XComponentController = new XComponentController();
  private mXComponentOptions: XComponentOptions = {
    type: XComponentType.SURFACE,
    controller: this.mXComponentController
  }
  private mSurfaceId: string = '';
  private mCameraPosition: camera.CameraPosition = camera.CameraPosition.CAMERA_POSITION_BACK;
  private mCameraManager: camera.CameraManager | undefined = undefined;
  // surface宽高根据需要自行选择。
  private surfaceRect: SurfaceRect = {
    surfaceWidth: 1080,
    surfaceHeight: 1920
  };
  private curCameraDevice: camera.CameraDevice | undefined = undefined;
  private mCameraInput: camera.CameraInput | undefined = undefined;
  private mPreviewOutput: camera.PreviewOutput | undefined = undefined;
  private mPhotoSession: camera.PhotoSession | undefined = undefined;
  // One of the recommended preview resolutions.
  private previewProfileObj: camera.Profile = {
    format: 1003,
    size: {
      width: 1920,
      height: 1080
    }
  };
  private mContext: Context | undefined = undefined;
  autoDeviceSwitchCallback: (err: BusinessError, autoDeviceSwitchStatus: camera.AutoDeviceSwitchStatus) => void =
    (err: BusinessError, autoDeviceSwitchStatus: camera.AutoDeviceSwitchStatus) => {
      if (err !== undefined && err.code !== 0) {
        console.error(`${TAG} Callback Error, errorCode: ${err.code}`);
        return;
      }
      console.info(`${TAG} isDeviceSwitched: ${autoDeviceSwitchStatus.isDeviceSwitched}, isDeviceCapabilityChanged: ${autoDeviceSwitchStatus.isDeviceCapabilityChanged}`);
  }

  requestPermissionsFn(): void {
    let atManager = abilityAccessCtrl.createAtManager();
    atManager.requestPermissionsFromUser(this.mContext, [
      'ohos.permission.CAMERA'
    ]).then((): void => {
      this.isShow = true;
    }).catch((error: BusinessError): void => {
      console.error(TAG + 'ohos.permission.CAMERA no permission.');
    });
  }

  initContext(): void {
    let uiContext = this.getUIContext();
    this.mContext = uiContext.getHostContext();
  }

  initCameraManager(): void {
    this.mCameraManager = camera.getCameraManager(this.mContext);
  }

  aboutToAppear(): void {
    console.log(TAG + 'aboutToAppear is called');
    this.initContext();
    this.requestPermissionsFn();
    this.initCameraManager();
  }

  async aboutToDisappear(): Promise<void> {
    await this.releaseCamera();
  }

  async onPageShow(): Promise<void> {
    await this.initCamera(this.mSurfaceId, this.mCameraPosition);
  }

  async releaseCamera(): Promise<void> {
    // 停止当前会话。
    try {
      await this.mPhotoSession?.stop();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to stop session, errorCode = ' + err.code);
    }

    // 释放相机输入流。
    try {
      await this.mCameraInput?.close();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to close device, errorCode = ' + err.code);
    }

    // 释放预览输出流。
    try {
      await this.mPreviewOutput?.release();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to release previewOutput, errorCode = ' + err.code);
    }

    this.mPreviewOutput = undefined;

    // 释放会话。
    try {
      await this.mPhotoSession?.release();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to release photoSession, errorCode = ' + err.code);
    }

    // 会话置空。
    this.mPhotoSession = undefined;
  }

  async loadXComponent(): Promise<void> {
    this.mSurfaceId = this.mXComponentController.getXComponentSurfaceId();
    console.info(TAG + `mCameraPosition: ${this.mCameraPosition}`)
    await this.initCamera(this.mSurfaceId, this.mCameraPosition);
  }

  getPreviewProfile(cameraOutputCapability: camera.CameraOutputCapability): camera.Profile | undefined {
    let previewProfiles = cameraOutputCapability.previewProfiles;
    if (previewProfiles.length < 1) {
      return undefined;
    }
    let index = previewProfiles.findIndex((previewProfile: camera.Profile) => {
      return previewProfile.size.width === this.previewProfileObj.size.width &&
        previewProfile.size.height === this.previewProfileObj.size.height &&
        previewProfile.format === this.previewProfileObj.format;
    })
    if (index === -1) {
      return undefined;
    }
    return previewProfiles[index];
  }

  async initCamera(surfaceId: string, cameraPosition: camera.CameraPosition,
    connectionType: camera.ConnectionType = camera.ConnectionType.CAMERA_CONNECTION_BUILT_IN): Promise<void> {
    await this.releaseCamera();
    // 创建CameraManager对象。
    if (!this.mCameraManager) {
      console.error(TAG + 'camera.getCameraManager error');
      return;
    }

    // 获取相机列表。
    let cameraArray: Array<camera.CameraDevice> = this.mCameraManager.getSupportedCameras();
    if (cameraArray.length <= 0) {
      console.error(TAG + 'cameraManager.getSupportedCameras error');
      return;
    }

    for (let index = 0; index < cameraArray.length; index++) {
      console.info(TAG + 'cameraId : ' + cameraArray[index].cameraId); // 获取相机ID。
      console.info(TAG + 'cameraPosition : ' + cameraArray[index].cameraPosition); // 获取相机位置。
      console.info(TAG + 'cameraType : ' + cameraArray[index].cameraType); // 获取相机类型。
      console.info(TAG + 'connectionType : ' + cameraArray[index].connectionType); // 获取相机连接类型。
    }

    let deviceIndex = cameraArray.findIndex((cameraDevice: camera.CameraDevice) => {
      return cameraDevice.cameraPosition === cameraPosition && cameraDevice.connectionType === connectionType;
    })
    // 没有找到对应位置的摄像头，可选择其他摄像头，具体场景具体对待。
    if (deviceIndex === -1) {
      deviceIndex = 0;
      console.error(TAG + 'not found camera');
    }
    this.curCameraDevice = cameraArray[deviceIndex];

    // 创建相机输入流。
    try {
      this.mCameraInput = this.mCameraManager.createCameraInput(this.curCameraDevice);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to createCameraInput errorCode = ' + err.code);
    }
    if (this.mCameraInput === undefined) {
      return;
    }

    // 打开相机。
    try {
      await this.mCameraInput.open();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to open device, errorCode = ' + err.code);
    }

    // 获取支持的模式类型。
    let sceneModes: Array<camera.SceneMode> = this.mCameraManager.getSupportedSceneModes(this.curCameraDevice);
    let isSupportPhotoMode: boolean = sceneModes.indexOf(camera.SceneMode.NORMAL_PHOTO) >= 0;
    if (!isSupportPhotoMode) {
      console.error(TAG + 'photo mode not support');
      return;
    }

    // 获取相机设备支持的输出流能力。
    let cameraOutputCapability: camera.CameraOutputCapability =
      this.mCameraManager.getSupportedOutputCapability(this.curCameraDevice, camera.SceneMode.NORMAL_PHOTO);
    if (!cameraOutputCapability) {
      console.error(TAG + 'cameraManager.getSupportedOutputCapability error');
      return;
    }
    console.info(TAG + 'outputCapability: ' + JSON.stringify(cameraOutputCapability));
    let previewProfile = this.getPreviewProfile(cameraOutputCapability);
    if (previewProfile === undefined) {
      console.error(TAG + 'The resolution of the current preview stream is not supported.');
      return;
    }
    this.previewProfileObj = previewProfile;

    // 创建预览输出流,其中参数 surfaceId 参考上文 XComponent 组件，预览流为XComponent组件提供的surface。
    try {
      this.mPreviewOutput = this.mCameraManager.createPreviewOutput(this.previewProfileObj, surfaceId);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + `Failed to create the PreviewOutput instance. error code: ${err.code}`);
    }
    if (this.mPreviewOutput === undefined) {
      return;
    }

    //创建会话。
    try {
      this.mPhotoSession = this.mCameraManager.createSession(camera.SceneMode.NORMAL_PHOTO) as camera.PhotoSession;
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to create the session instance. errorCode = ' + err.code);
    }
    if (this.mPhotoSession === undefined) {
      return;
    }
    if (this.mPhotoSession.isAutoDeviceSwitchSupported()) {
      this.mPhotoSession.enableAutoDeviceSwitch(true);
      this.mPhotoSession.on('autoDeviceSwitchStatusChange', this.autoDeviceSwitchCallback);
    }
    // 开始配置会话。
    try {
      this.mPhotoSession.beginConfig();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to beginConfig. errorCode = ' + err.code);
    }

    // 向会话中添加相机输入流。
    try {
      this.mPhotoSession.addInput(this.mCameraInput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to addInput. errorCode = ' + err.code);
    }

    // 向会话中添加预览输出流。
    try {
      this.mPhotoSession.addOutput(this.mPreviewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to addOutput(previewOutput). errorCode = ' + err.code);
    }

    // 提交会话配置。
    try {
      await this.mPhotoSession.commitConfig();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to commit session configuration, errorCode = ' + err.code);
    }

    // 启动会话。
    try {
      await this.mPhotoSession.start()
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to start session. errorCode = ' + err.code);
    }
  }

  build() {
    if (this.isShow) {
      Stack() {
        XComponent(this.mXComponentOptions)
          .onLoad(async () => {
            await this.loadXComponent();
          })
          .width(this.getUIContext().px2vp(1080))
          .height(this.getUIContext().px2vp(1920))
        Text('切换相机')
          .size({ width: 80, height: 48 })
          .position({ x: 1, y: 1 })
          .backgroundColor(Color.White)
          .textAlign(TextAlign.Center)
          .borderRadius(24)
          .onClick(async () => {
            this.mCameraPosition = this.mCameraPosition === camera.CameraPosition.CAMERA_POSITION_BACK ?
            camera.CameraPosition.CAMERA_POSITION_FRONT : camera.CameraPosition.CAMERA_POSITION_BACK;
            await this.loadXComponent();
          })
      }
      .size({ width: '100%', height: '100%' })
      .backgroundColor(Color.Black)
    }
  }
}
```