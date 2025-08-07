# Practices for Automatic Camera Switching (ArkTS)

This document describes the scenario of automatic front-camera switching on foldable devices. The system selects the appropriate front camera depending on the device's fold state.

For example, foldable device A has three cameras: rear camera B, front camera C, and front camera D. In the unfolded state, [CameraManager.getSupportedCameras](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedcameras) returns rear camera B and front camera C. In the folded state, it returns rear camera B and front camera D.

Enable the front camera in the current fold state, and call [enableAutoDeviceSwitch](../../reference/apis-camera-kit/arkts-apis-camera-AutoDeviceSwitch.md#enableautodeviceswitch13) to enable automatic camera switching. This ensures that when the fold state changes, the front camera corresponding to that state is automatically selected.

Read [Module Description](../../reference/apis-camera-kit/arkts-apis-camera.md) for the API reference.

For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

Before developing a camera application, request permissions by following the instructions provided in [Requesting Camera Development Permissions](camera-preparation.md).

## Importing Dependencies
```ts
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl } from '@kit.AbilityKit';
```
## Creating an XComponent
Use [XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md) to display the camera preview.
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
    // Initialize the XComponent.
  }

  build() {
    Stack() {
      XComponent(this.mXComponentOptions)
        .onLoad(async () => {
          await this.loadXComponent();
        })
        .width(this.getUIContext().px2vp(1080))
        .height(this.getUIContext().px2vp(1920))
      Text('Switch camera')
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
## Enabling Automatic Camera Switching
Before calling [enableAutoDeviceSwitch](../../reference/apis-camera-kit/arkts-apis-camera-AutoDeviceSwitch.md#enableautodeviceswitch13), use [isAutoDeviceSwitchSupported](../../reference/apis-camera-kit/arkts-apis-camera-AutoDeviceSwitchQuery.md#isautodeviceswitchsupported13) to check whether the device supports automatic camera switching.
```ts
function enableAutoDeviceSwitch(session: camera.PhotoSession) {
  if (session.isAutoDeviceSwitchSupported()) {
    session.enableAutoDeviceSwitch(true);
  }
}
```
## Listening for Automatic Camera Switching
You can use [enableAutoDeviceSwitch](../../reference/apis-camera-kit/arkts-apis-camera-PhotoSession.md#onautodeviceswitchstatuschange13) to listen for automatic camera switching. A callback is invoked once the switch is complete.

Do not call any session related APIs during the switching process.

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

## Sample Code
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
  // Select the surface width and height as required.
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
    // Stop the session.
    try {
      await this.mPhotoSession?.stop();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to stop session, errorCode = ' + err.code);
    }

    // Release the camera input stream.
    try {
      await this.mCameraInput?.close();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to close device, errorCode = ' + err.code);
    }

    // Release the preview output stream.
    try {
      await this.mPreviewOutput?.release();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to release previewOutput, errorCode = ' + err.code);
    }

    this.mPreviewOutput = undefined;

    // Release the session.
    try {
      await this.mPhotoSession?.release();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to release photoSession, errorCode = ' + err.code);
    }

    // Set the session to null.
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
    // Create a CameraManager object.
    if (!this.mCameraManager) {
      console.error(TAG + 'camera.getCameraManager error');
      return;
    }

    // Obtain the camera list.
    let cameraArray: Array<camera.CameraDevice> = this.mCameraManager.getSupportedCameras();
    if (cameraArray.length <= 0) {
      console.error(TAG + 'cameraManager.getSupportedCameras error');
      return;
    }

    for (let index = 0; index < cameraArray.length; index++) {
      console.info(TAG + 'cameraId : ' + cameraArray[index].cameraId); // Obtain the camera ID.
      console.info(TAG + 'cameraPosition : ' + cameraArray[index].cameraPosition); // Obtain the camera position.
      console.info(TAG + 'cameraType : ' + cameraArray[index].cameraType); // Obtain the camera type.
      console.info(TAG + 'connectionType : ' + cameraArray[index].connectionType); // Obtain the camera connection type.
    }

    let deviceIndex = cameraArray.findIndex((cameraDevice: camera.CameraDevice) => {
      return cameraDevice.cameraPosition === cameraPosition && cameraDevice.connectionType === connectionType;
    })
    // If no camera is found at the specified position, you can select another camera. Handle the situation based on the specific scenario.
    if (deviceIndex === -1) {
      deviceIndex = 0;
      console.error(TAG + 'not found camera');
    }
    this.curCameraDevice = cameraArray[deviceIndex];

    // Create a camera input stream.
    try {
      this.mCameraInput = this.mCameraManager.createCameraInput(this.curCameraDevice);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to createCameraInput errorCode = ' + err.code);
    }
    if (this.mCameraInput === undefined) {
      return;
    }

    // Open the camera.
    try {
      await this.mCameraInput.open();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to open device, errorCode = ' + err.code);
    }

    // Obtain the supported modes.
    let sceneModes: Array<camera.SceneMode> = this.mCameraManager.getSupportedSceneModes(this.curCameraDevice);
    let isSupportPhotoMode: boolean = sceneModes.indexOf(camera.SceneMode.NORMAL_PHOTO) >= 0;
    if (!isSupportPhotoMode) {
      console.error(TAG + 'photo mode not support');
      return;
    }

    // Obtain the output stream capability supported by the camera.
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

    // Create a preview output stream. For details about the surfaceId parameter, see the XComponent. The preview stream uses the surface provided by the XComponent.
    try {
      this.mPreviewOutput = this.mCameraManager.createPreviewOutput(this.previewProfileObj, surfaceId);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + `Failed to create the PreviewOutput instance. error code: ${err.code}`);
    }
    if (this.mPreviewOutput === undefined) {
      return;
    }

    // Create a session.
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
    // Start configuration for the session.
    try {
      this.mPhotoSession.beginConfig();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to beginConfig. errorCode = ' + err.code);
    }

    // Add the camera input stream to the session.
    try {
      this.mPhotoSession.addInput(this.mCameraInput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to addInput. errorCode = ' + err.code);
    }

    // Add the preview output stream to the session.
    try {
      this.mPhotoSession.addOutput(this.mPreviewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to addOutput(previewOutput). errorCode = ' + err.code);
    }

    // Commit the session configuration.
    try {
      await this.mPhotoSession.commitConfig();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to commit session configuration, errorCode = ' + err.code);
    }

    // Start the session.
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
        Text('Switch camera')
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
