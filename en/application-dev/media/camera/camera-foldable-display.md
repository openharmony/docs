# Adapting Camera Changes in Different Fold States (ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->
Foldable devices come in various forms. When developing camera applications, a consistent camera switching solution is necessary to enhance user experience during photo and video capture.

A single foldable device can use different cameras depending on its fold state. The system identifies each camera and associates it with a specific fold state, indicating which cameras are available in those states. Applications can call [CameraManager.on('foldStatusChange')](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#onfoldstatuschange12) or [display.on('foldStatusChange')](../../reference/apis-arkui/js-apis-display.md#displayonfoldstatuschange10) to listen for fold state changes of the device, call [CameraManager.getSupportedCameras](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedcameras) to obtain the available cameras in the current state, and make adaptations accordingly.

The number of supported cameras can differ among foldable devices in various fold states.

For example, foldable device A has three cameras: B (rear), C (front), and D (front). In the unfolded state, calling [CameraManager.getSupportedCameras](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedcameras) returns both cameras B (rear) and C (front). However, in the folded state, only camera D (front) is accessible. Therefore, when using the rear camera or switching between cameras, it is crucial to first verify the existence of the rear camera.

Read [Camera](../../reference/apis-camera-kit/arkts-apis-camera.md) for the API reference.

For details about how to obtain the context, see [Obtaining the Context of UIAbility](../../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

Before developing a camera application, you must [request required permissions](camera-preparation.md).
## Creating an XComponent
Use two [XComponents](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md) to present the folded and unfolded states, respectively. This prevents the previous camera feed from lingering on the screen if the camera is not properly closed during fold state transition.

   ```ts
    @Entry
    @Component
    struct Index {
      @State reloadXComponentFlag: boolean = false;
      @StorageLink('foldStatus') @Watch('reloadXComponent') foldStatus: number = 0;
      private mXComponentController: XComponentController = new XComponentController();
      private mXComponentOptions: XComponentOptions = {
        type: XComponentType.SURFACE,
        controller: this.mXComponentController
      }

      reloadXComponent() {
        this.reloadXComponentFlag = !this.reloadXComponentFlag;
      }

      async loadXComponent() {
        // Initialize the XComponent.
      }

      build() {
        Stack() {
          if (this.reloadXComponentFlag) {
            XComponent(this.mXComponentOptions)
              .onLoad(async () => {
                await this.loadXComponent();
              })
              .width(this.getUIContext().px2vp(1080))
              .height(this.getUIContext().px2vp(1920))
          } else {
            XComponent(this.mXComponentOptions)
              .onLoad(async () => {
                await this.loadXComponent();
              })
              .width(this.getUIContext().px2vp(1080))
              .height(this.getUIContext().px2vp(1920))
          }
        }
        .size({ width: '100%', height: '100%' })
        .backgroundColor(Color.Black)
      }
    }
   ```
## Obtaining the Device Fold State

You can use either of the following solutions.

- Solution 1: Call [CameraManager.on('foldStatusChange')](../../../application-dev/reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#onfoldstatuschange12) provided by the camera framework to listen for fold state changes.
    ```ts
    import { camera } from '@kit.CameraKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    function registerFoldStatusChanged(err: BusinessError, foldStatusInfo: camera.FoldStatusInfo) {
      // The foldStatus variable is used to control the display of the XComponent.
      AppStorage.setOrCreate<number>('foldStatus', foldStatusInfo.foldStatus);
    }

    function onFoldStatusChange(cameraManager: camera.CameraManager) {
      cameraManager.on('foldStatusChange', registerFoldStatusChanged);
    }

    function offFoldStatusChange(cameraManager: camera.CameraManager) {
      cameraManager.off('foldStatusChange', registerFoldStatusChanged);
    }
    ```
- Solution 2: Call [display.on('foldStatusChange')](../../reference/apis-arkui/js-apis-display.md#displayonfoldstatuschange10) to listen for fold state changes.
    ```ts
    import { display } from '@kit.ArkUI';
    
    function getFoldStatus(): display.FoldStatus {
      let curFoldStatus: display.FoldStatus = display.FoldStatus.FOLD_STATUS_UNKNOWN;
      try {
        curFoldStatus = display.getFoldStatus();
      } catch (error) {
        console.error('getFoldStatus call failed');
      }
      return curFoldStatus;
    }
    
    let preFoldStatus: display.FoldStatus = getFoldStatus();
    display.on('foldStatusChange', (foldStatus: display.FoldStatus) => {
      // The supported cameras returned by the camera framework are the same when the device is in the FOLD_STATUS_HALF_FOLDED or FOLD_STATUS_EXPANDED state. Therefore, you do not need to reconfigure streams during the transition between these two states.
      if ((preFoldStatus === display.FoldStatus.FOLD_STATUS_HALF_FOLDED &&
        foldStatus === display.FoldStatus.FOLD_STATUS_EXPANDED) ||
        (preFoldStatus === display.FoldStatus.FOLD_STATUS_EXPANDED &&
          foldStatus === display.FoldStatus.FOLD_STATUS_HALF_FOLDED)) {
        preFoldStatus = foldStatus;
        return;
      }
      preFoldStatus = foldStatus;
      // The foldStatus variable is used to control the display of the XComponent.
      AppStorage.setOrCreate<number>('foldStatus', foldStatus);
    })
    ```
## Checking the Presence of a Camera at a Specific Position
You can call [CameraManager.getSupportedCameras](../../reference/apis-camera-kit/arkts-apis-camera-CameraManager.md#getsupportedcameras) to obtain all the cameras supported by the device in the current fold state. By iterating through the results and using [CameraPosition](../../reference/apis-camera-kit/arkts-apis-camera-e.md#cameraposition), you can determine whether a camera exists at the specified position.
```ts
import { camera } from '@kit.CameraKit';

// The default value of connectionType is camera.ConnectionType.CAMERA_CONNECTION_BUILT_IN, indicating the device's built-in camera.
function hasCameraAt(cameraManager: camera.CameraManager, cameraPosition: camera.CameraPosition,
  connectionType: camera.ConnectionType = camera.ConnectionType.CAMERA_CONNECTION_BUILT_IN): boolean {
  let cameraArray: Array<camera.CameraDevice> = cameraManager.getSupportedCameras();
  if (cameraArray.length <= 0) {
    console.error('cameraManager.getSupportedCameras error');
    return false;
  }
  for (let index = 0; index < cameraArray.length; index++) {
    if (cameraArray[index].cameraPosition === cameraPosition &&
      cameraArray[index].connectionType === connectionType) {
      return true;
    }
  }
  return false;
}
```
## Camera Switching Logic
When a fold state change is detected, the **foldStatus** variable, decorated with @StorageLink, is updated. This triggers the **reloadXComponent** API to reload the **XComponent**, thereby implementing the camera switching logic.
## Complete Sample Code
```ts
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { display } from '@kit.ArkUI';

const TAG = 'FoldScreenCameraAdaptationDemo ';

@Entry
@Component
struct Index {
  @State isShow: boolean = false;
  @State reloadXComponentFlag: boolean = false;
  @StorageLink('foldStatus') @Watch('reloadXComponent') foldStatus: number = 0;
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
  // Choose the appropriate preview stream profile based on your specific needs. This example uses a resolution of 1080P with CameraFormat: 1003.
  private previewProfileObj: camera.Profile = {
    format: 1003,
    size: {
      width: 1920,
      height: 1080
    }
  };
  private mContext: Context | undefined = undefined;

  private preFoldStatus: display.FoldStatus = this.getFoldStatus();
  // Listen for the foldable screen status. You can use cameraManager.on(type: 'foldStatusChange', callback: AsyncCallback<FoldStatusInfo>): void;
  // or display.on(type: 'foldStatusChange', callback: Callback<FoldStatus>): void;.
  private foldStatusCallback =
    (err: BusinessError, info: camera.FoldStatusInfo): void => this.registerFoldStatusChanged(err, info);
  private displayFoldStatusCallback =
    (foldStatus: display.FoldStatus): void => this.onDisplayFoldStatusChange(foldStatus);

  getFoldStatus(): display.FoldStatus {
    let curFoldStatus: display.FoldStatus = display.FoldStatus.FOLD_STATUS_UNKNOWN;
    try {
      curFoldStatus = display.getFoldStatus();
    } catch (error) {
      console.info(`${TAG} getFoldStatus call failed, error: ${error.code}`);
    }
    return curFoldStatus;
  }

  registerFoldStatusChanged(err: BusinessError, foldStatusInfo: camera.FoldStatusInfo) {
    if (err !== undefined && err.code !== 0) {
      console.info(`${TAG} registerFoldStatusChanged call failed, error: ${err.code}`);
      return;
    }
    console.info(TAG + 'foldStatusChanged foldStatus: ' + foldStatusInfo.foldStatus);
    for (let i = 0; i < foldStatusInfo.supportedCameras.length; i++) {
      console.info(TAG +
        `foldStatusChanged camera[${i}]: ${foldStatusInfo.supportedCameras[i].cameraId},cameraPosition: ${foldStatusInfo.supportedCameras[i].cameraPosition}`);
    }
    AppStorage.setOrCreate<number>('foldStatus', foldStatusInfo.foldStatus);
  }

  onDisplayFoldStatusChange(foldStatus: display.FoldStatus): void {
    console.info(TAG + `onDisplayFoldStatusChange foldStatus: ${foldStatus}`);
    if ((this.preFoldStatus === display.FoldStatus.FOLD_STATUS_HALF_FOLDED &&
      foldStatus === display.FoldStatus.FOLD_STATUS_EXPANDED) ||
      (this.preFoldStatus === display.FoldStatus.FOLD_STATUS_EXPANDED &&
        foldStatus === display.FoldStatus.FOLD_STATUS_HALF_FOLDED)) {
      this.preFoldStatus = foldStatus;
      return;
    }
    this.preFoldStatus = foldStatus;
    if (!this.curCameraDevice) {
      return;
    }
    // The foldStatus variable is used to control the display of the XComponent.
    AppStorage.setOrCreate<number>('foldStatus', foldStatus);
  }

  requestPermissionsFn(): void {
    let atManager = abilityAccessCtrl.createAtManager();
    atManager.requestPermissionsFromUser(this.mContext, [
      'ohos.permission.CAMERA'
    ]).then((): void => {
      this.isShow = true;
    }).catch((error: BusinessError): void => {
      console.error(`${TAG} requestPermissionsFromUser call failed, error: ${error.code}`);
    });
  }

  initContext(): void {
    let uiContext = this.getUIContext();
    this.mContext = uiContext.getHostContext();
  }

  initCameraManager(): void {
    try {
      this.mCameraManager = camera.getCameraManager(this.mContext);
    } catch (error) {
      console.error(`${TAG} getCameraManager call failed, error: ${error.code}`);
    }
  }

  aboutToAppear(): void {
    console.log(TAG + 'aboutToAppear is called');
    this.initContext();
    this.initCameraManager();
    this.requestPermissionsFn();
    this.onFoldStatusChange();
  }

  async aboutToDisappear(): Promise<void> {
    await this.releaseCamera();
    // Stop the listening.
    this.offFoldStatusChange();
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

  onFoldStatusChange(): void {
    this.mCameraManager?.on('foldStatusChange', this.foldStatusCallback);
    // display.on('foldStatusChange', this.displayFoldStatusCallback);
  }

  offFoldStatusChange(): void {
    this.mCameraManager?.off('foldStatusChange', this.foldStatusCallback);
    // display.off('foldStatusChange', this.displayFoldStatusCallback);
  }

  reloadXComponent(): void {
    this.reloadXComponentFlag = !this.reloadXComponentFlag;
  }

  async loadXComponent(): Promise<void> {
    if (!this.mXComponentController) {
      console.error(TAG + 'mXComponentController is null');
      return;
    }
    this.mSurfaceId = this.mXComponentController.getXComponentSurfaceId();
    this.mXComponentController.setXComponentSurfaceRect(this.surfaceRect);
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
    if (!cameraArray || cameraArray.length == 0) {
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
      await this.releaseCamera();
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
    if (!previewProfile) {
      console.error(TAG + 'The resolution of the current preview stream is not supported.');
      await this.releaseCamera();
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
    if (!this.mPreviewOutput) {
      await this.releaseCamera();
      return;
    }

    // Create a session.
    try {
      let session = this.mCameraManager.createSession(camera.SceneMode.NORMAL_PHOTO);
      if (!session) {
        await this.releaseCamera();
        return;
      }
      this.mPhotoSession = session as camera.PhotoSession;
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to create the session instance. errorCode = ' + err.code);
    }

    if (!this.mPhotoSession) {
      await this.releaseCamera();
      return;
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
        if (this.reloadXComponentFlag) {
          XComponent(this.mXComponentOptions)
            .onLoad(async () => {
              await this.loadXComponent();
            })
            .width(this.getUIContext().px2vp(1080))
            .height(this.getUIContext().px2vp(1920))
        } else {
          XComponent(this.mXComponentOptions)
            .onLoad(async () => {
              await this.loadXComponent();
            })
            .width(this.getUIContext().px2vp(1080))
            .height(this.getUIContext().px2vp(1920))
        }
        Text('Switch camera')
          .size({ width: 80, height: 48 })
          .position({ x: 1, y: 1 })
          .backgroundColor(Color.White)
          .textAlign(TextAlign.Center)
          .borderRadius(24)
          .onClick(async () => {
            this.mCameraPosition = this.mCameraPosition === camera.CameraPosition.CAMERA_POSITION_BACK ?
              camera.CameraPosition.CAMERA_POSITION_FRONT : camera.CameraPosition.CAMERA_POSITION_BACK;
            this.reloadXComponentFlag = !this.reloadXComponentFlag;
          })
      }
      .size({ width: '100%', height: '100%' })
      .backgroundColor(Color.Black)
    }
  }
}
```
