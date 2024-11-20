# Adapting to Camera Changes in Different Folding States (ArkTS)

Before developing a camera application, request the camera permission. For details, see [Camera Development Preparations](camera-preparation.md).

Cameras that a foldable device can use vary according to its folding states. To deliver a smooth user experience during transitions between folded and unfolded states, an application can call [CameraManager.on('foldStatusChange')](../../reference/apis-camera-kit/js-apis-camera.md#onfoldstatuschange12) or [display.on('foldStatusChange')](../../reference/apis-arkui/js-apis-display.md#displayonfoldstatuschange10) to listen for folding state changes of the device, call [CameraManager.getSupportedCameras](../../reference/apis-camera-kit/js-apis-camera.md#getsupportedcameras) to obtain the available cameras in the current state, and make adaptations accordingly.

Read [Camera](../../reference/apis-camera-kit/js-apis-camera.md) for the API reference.

## Creating an XComponent
Use two [XComponents](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md) to present the folded and unfolded states, respectively. This prevents the previous camera feed from lingering on the screen if the camera is not properly closed during folding state transition.

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
              .width(px2vp(1080))
              .height(px2vp(1920))
          } else {
            XComponent(this.mXComponentOptions)
              .onLoad(async () => {
                await this.loadXComponent();
              })
              .width(px2vp(1080))
              .height(px2vp(1920))
          }
        }
        .size({ width: '100%', height: '100%' })
        .backgroundColor(Color.Black)
      }
    }
   ```
## Obtaining the Device Folding State

You can use either of the following solutions.

- Solution 1: Call [CameraManager.on('foldStatusChange')](../../../application-dev/reference/apis-camera-kit/js-apis-camera.md#onfoldstatuschange12) provided by the camera framework to listen for folding state changes.
    ```ts
    import { camera } from '@kit.CameraKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let cameraManager = camera.getCameraManager(getContext())

    function registerFoldStatusChanged(err: BusinessError, foldStatusInfo: camera.FoldStatusInfo) {
      // The foldStatus variable is used to control the display of the XComponent.
      AppStorage.setOrCreate<number>('foldStatus', foldStatusInfo.foldStatus);
    }

    cameraManager.on('foldStatusChange', registerFoldStatusChanged);
    //cameraManager.off('foldStatusChange', registerFoldStatusChanged);
    ```
- Solution 2: Call [display.on('foldStatusChange')](../../reference/apis-arkui/js-apis-display.md#displayonfoldstatuschange10) to listen for folding state changes.
    ```ts
    import { display } from '@kit.ArkUI';
    let preFoldStatus: display.FoldStatus = display.getFoldStatus();
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

## Example
```ts
import { camera } from '@kit.CameraKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { abilityAccessCtrl } from '@kit.AbilityKit';
import { display } from '@kit.ArkUI';

let context = getContext(this);

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
  private mCameraManager: camera.CameraManager = camera.getCameraManager(context);
  // Select the surface width and height as required.
  private surfaceRect: SurfaceRect = {
    surfaceWidth: 1080,
    surfaceHeight: 1920
  };
  private curCameraDevice: camera.CameraDevice | undefined = undefined;
  private mCameraInput: camera.CameraInput | undefined = undefined;
  private mPreviewOutput: camera.PreviewOutput | undefined = undefined;
  private mPhotoSession: camera.PhotoSession | undefined = undefined;
  // One of the recommended preview resolutions
  private previewProfileObj: camera.Profile = {
    format: 1003,
    size: {
      width: 1920,
      height: 1080
    }
  };

  private preFoldStatus: display.FoldStatus = display.getFoldStatus();
  // Listen for the foldable screen status. You can use cameraManager.on(type: 'foldStatusChange', callback: AsyncCallback<FoldStatusInfo>): void;
  // or display.on(type: 'foldStatusChange', callback: Callback<FoldStatus>): void;.
  private foldStatusCallback =
    (err: BusinessError, info: camera.FoldStatusInfo): void => this.registerFoldStatusChanged(err, info);
  private displayFoldStatusCallback =
    (foldStatus: display.FoldStatus): void => this.onDisplayFoldStatusChange(foldStatus);


  registerFoldStatusChanged(err: BusinessError, foldStatusInfo: camera.FoldStatusInfo) {
    console.info(TAG + 'foldStatusChanged foldStatus: ' + foldStatusInfo.foldStatus);
    for (let i = 0; i < foldStatusInfo.supportedCameras.length; i++) {
      console.info(TAG +
        `foldStatusChanged camera[${i}]: ${foldStatusInfo.supportedCameras[i].cameraId},cameraPosition: ${foldStatusInfo.supportedCameras[i].cameraPosition}`);
    }
    AppStorage.setOrCreate<number>('foldStatus', foldStatusInfo.foldStatus);
  }

  onDisplayFoldStatusChange(foldStatus: display.FoldStatus): void {
    console.error(TAG + `onDisplayFoldStatusChange foldStatus: ${foldStatus}`);
    if ((this.preFoldStatus === display.FoldStatus.FOLD_STATUS_HALF_FOLDED &&
      foldStatus === display.FoldStatus.FOLD_STATUS_EXPANDED) ||
      (this.preFoldStatus === display.FoldStatus.FOLD_STATUS_EXPANDED &&
        foldStatus === display.FoldStatus.FOLD_STATUS_HALF_FOLDED)) {
      this.preFoldStatus = foldStatus;
      return;
    }
    this.preFoldStatus = foldStatus;
    // Obtain the currently opened camera. If the rear camera is opened, its use is not affected when the device is folded.
    if (!this.curCameraDevice) {
      return;
    }
    // The foldStatus variable is used to control the display of the XComponent.
    AppStorage.setOrCreate<number>('foldStatus', foldStatus);
  }

  requestPermissionsFn(): void {
    let atManager = abilityAccessCtrl.createAtManager();
    atManager.requestPermissionsFromUser(context, [
      'ohos.permission.CAMERA'
    ]).then((): void => {
      this.isShow = true;
    }).catch((error: BusinessError): void => {
      console.error(TAG + 'ohos.permission.CAMERA no permission.');
    });
  }

  aboutToAppear(): void {
    console.log(TAG + 'aboutToAppear is called');
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
    await this.mPhotoSession?.stop();
  
    // Release the camera input stream.
    await this.mCameraInput?.close();
  
    // Release the preview output stream.
    await this.mPreviewOutput?.release();
  
    this.mPreviewOutput = undefined;
  
    // Release the session.
    await this.mPhotoSession?.release();
  
    // Set the session to null.
    this.mPhotoSession = undefined;
  }

  onFoldStatusChange(): void {
    this.mCameraManager.on('foldStatusChange', this.foldStatusCallback);
    // display.on('foldStatusChange', this.displayFoldStatusCallback);
  }

  offFoldStatusChange(): void {
    this.mCameraManager.off('foldStatusChange', this.foldStatusCallback);
    // display.off('foldStatusChange', this.displayFoldStatusCallback);
  }

  reloadXComponent(): void {
    this.reloadXComponentFlag = !this.reloadXComponentFlag;
  }

  async loadXComponent(): Promise<void> {
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

  async initCamera(surfaceId: string, cameraPosition: camera.CameraPosition): Promise<void> {
    await this.releaseCamera();
    // Create a CameraManager object.
    if (!this.mCameraManager) {
      console.error(TAG + 'camera.getCameraManager error');
      return;
    }
  
    // Obtain the camera list.
    let cameraArray: Array<camera.CameraDevice> = this.mCameraManager.getSupportedCameras();
    if (cameraArray.length <= 0) {
      console.error(TAG + "cameraManager.getSupportedCameras error");
      return;
    }
  
    for (let index = 0; index < cameraArray.length; index++) {
      console.info(TAG + 'cameraId : ' + cameraArray[index].cameraId); // Obtain the camera ID.
      console.info(TAG + 'cameraPosition : ' + cameraArray[index].cameraPosition); // Obtain the camera position.
      console.info(TAG + 'cameraType : ' + cameraArray[index].cameraType); // Obtain the camera type.
      console.info(TAG + 'connectionType : ' + cameraArray[index].connectionType); // Obtain the camera connection type.
    }
  
    let deviceIndex = cameraArray.findIndex((cameraDevice: camera.CameraDevice) => {
      return cameraDevice.cameraPosition === cameraPosition;
    })
    if (deviceIndex === -1) {
      console.error(TAG + "not found camera");
      return;
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
    // Open a camera.
    await this.mCameraInput.open();
  
    // Obtain the supported scene modes.
    let sceneModes: Array<camera.SceneMode> = this.mCameraManager.getSupportedSceneModes(this.curCameraDevice);
    let isSupportPhotoMode: boolean = sceneModes.indexOf(camera.SceneMode.NORMAL_PHOTO) >= 0;
    if (!isSupportPhotoMode) {
      console.error(TAG + 'photo mode not support');
      return;
    }
    // Obtain the output streams supported by the camera device.
    let cameraOutputCapability: camera.CameraOutputCapability =
      this.mCameraManager.getSupportedOutputCapability(this.curCameraDevice, camera.SceneMode.NORMAL_PHOTO);
    if (!cameraOutputCapability) {
      console.error(TAG + "cameraManager.getSupportedOutputCapability error");
      return;
    }
    console.info(TAG + "outputCapability: " + JSON.stringify(cameraOutputCapability));
  
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
    await this.mPhotoSession.commitConfig();
  
    // Start the session.
    await this.mPhotoSession.start().then(() => {
      console.info(TAG + 'Promise returned to indicate the session start success.');
    });
  }

  build() {
    if (this.isShow) {
      Stack() {
        if (this.reloadXComponentFlag) {
          XComponent(this.mXComponentOptions)
            .onLoad(async () => {
              await this.loadXComponent();
            })
            .width(px2vp(1080))
            .height(px2vp(1920))
        } else {
          XComponent(this.mXComponentOptions)
            .onLoad(async () => {
              await this.loadXComponent();
            })
            .width(px2vp(1080))
            .height(px2vp(1920))
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
