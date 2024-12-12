# 适配不同折叠状态的摄像头变更(ArkTS)

在开发相机应用时，需要先参考开发准备[申请相关权限](camera-preparation.md)。

一台可折叠设备在不同折叠状态下，可使用不同的摄像头，应用可调用[CameraManager.on('foldStatusChange')](../../reference/apis-camera-kit/js-apis-camera.md#onfoldstatuschange12)或[display.on('foldStatusChange')](../../reference/apis-arkui/js-apis-display.md#displayonfoldstatuschange10)监听设备的折叠状态变化，并调用[CameraManager.getSupportedCameras](../../reference/apis-camera-kit/js-apis-camera.md#getsupportedcameras)获取当前状态下可用摄像头，完成相应适配，确保应用在折叠状态变更时的用户体验。

详细的API说明请参考[Camera API参考](../../reference/apis-camera-kit/js-apis-camera.md)。

## 创建XComponent
   使用两个[XComponent](../../reference/apis-arkui/arkui-ts/ts-basic-components-xcomponent.md)分别展示折叠态和展开态，防止切换折叠屏状态亮屏的时候上一个摄像头还未关闭，残留上一个摄像头的画面。

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
        //初始化XComponent
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
## 获取设备折叠状态

此处提供两种方案供开发者选择。

- **方案一：使用相机框架提供的[CameraManager.on('foldStatusChange')](../../../application-dev/reference/apis-camera-kit/js-apis-camera.md#onfoldstatuschange12)监听设备折叠态变化。**
    ```ts
    import { camera } from '@kit.CameraKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    let cameraManager = camera.getCameraManager(getContext())

    function registerFoldStatusChanged(err: BusinessError, foldStatusInfo: camera.FoldStatusInfo) {
      // foldStatus 变量用来控制显示XComponent组件
      AppStorage.setOrCreate<number>('foldStatus', foldStatusInfo.foldStatus);
    }

    cameraManager.on('foldStatusChange', registerFoldStatusChanged);
    //cameraManager.off('foldStatusChange', registerFoldStatusChanged);
    ```
- **方案二：使用图形图像的[display.on('foldStatusChange')](../../reference/apis-arkui/js-apis-display.md#displayonfoldstatuschange10)监听设备折叠态变化。**
    ```ts
    import { display } from '@kit.ArkUI';
    let preFoldStatus: display.FoldStatus = display.getFoldStatus();
    display.on('foldStatusChange', (foldStatus: display.FoldStatus) => {
      // 从半折叠态（FOLD_STATUS_HALF_FOLDED）和展开态（FOLD_STATUS_EXPANDED），相机框架返回所支持的摄像头是一致的，所以从半折叠态到展开态不需要重新配流，从展开态到半折叠态也是一样的
      if ((preFoldStatus === display.FoldStatus.FOLD_STATUS_HALF_FOLDED &&
        foldStatus === display.FoldStatus.FOLD_STATUS_EXPANDED) ||
        (preFoldStatus === display.FoldStatus.FOLD_STATUS_EXPANDED &&
          foldStatus === display.FoldStatus.FOLD_STATUS_HALF_FOLDED)) {
        preFoldStatus = foldStatus;
        return;
      }
      preFoldStatus = foldStatus;
      // foldStatus 变量用来控制显示XComponent组件
      AppStorage.setOrCreate<number>('foldStatus', foldStatus);
    })
    ```

## 完整示例
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
  // surface宽高根据需要自行选择
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
  // 监听折叠屏状态，可以使用cameraManager.on(type: 'foldStatusChange', callback: AsyncCallback<FoldStatusInfo>): void;
  // 也可以使用display.on(type: 'foldStatusChange', callback: Callback<FoldStatus>): void;
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
    // 获取当前打开的相机摄像头，如果是后置，折叠状态不影响当前摄像头的使用
    if (!this.curCameraDevice) {
      return;
    }
    // foldStatus 变量用来控制显示XComponent组件
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
    // 解注册
    this.offFoldStatusChange();
  }

  async onPageShow(): Promise<void> {
    await this.initCamera(this.mSurfaceId, this.mCameraPosition);
  }

  async releaseCamera(): Promise<void> {
    // 停止当前会话
    await this.mPhotoSession?.stop();
  
    // 释放相机输入流
    await this.mCameraInput?.close();
  
    // 释放预览输出流
    await this.mPreviewOutput?.release();
  
    this.mPreviewOutput = undefined;
  
    // 释放会话
    await this.mPhotoSession?.release();
  
    // 会话置空
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
    // 创建CameraManager对象
    if (!this.mCameraManager) {
      console.error(TAG + 'camera.getCameraManager error');
      return;
    }
  
    // 获取相机列表
    let cameraArray: Array<camera.CameraDevice> = this.mCameraManager.getSupportedCameras();
    if (cameraArray.length <= 0) {
      console.error(TAG + "cameraManager.getSupportedCameras error");
      return;
    }
  
    for (let index = 0; index < cameraArray.length; index++) {
      console.info(TAG + 'cameraId : ' + cameraArray[index].cameraId); // 获取相机ID
      console.info(TAG + 'cameraPosition : ' + cameraArray[index].cameraPosition); // 获取相机位置
      console.info(TAG + 'cameraType : ' + cameraArray[index].cameraType); // 获取相机类型
      console.info(TAG + 'connectionType : ' + cameraArray[index].connectionType); // 获取相机连接类型
    }
  
    let deviceIndex = cameraArray.findIndex((cameraDevice: camera.CameraDevice) => {
      return cameraDevice.cameraPosition === cameraPosition;
    })
    if (deviceIndex === -1) {
      console.error(TAG + "not found camera");
      return;
    }
    this.curCameraDevice = cameraArray[deviceIndex];
    // 创建相机输入流
    try {
      this.mCameraInput = this.mCameraManager.createCameraInput(this.curCameraDevice);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to createCameraInput errorCode = ' + err.code);
    }
    if (this.mCameraInput === undefined) {
      return;
    }
    // 打开相机
    await this.mCameraInput.open();
  
    // 获取支持的模式类型
    let sceneModes: Array<camera.SceneMode> = this.mCameraManager.getSupportedSceneModes(this.curCameraDevice);
    let isSupportPhotoMode: boolean = sceneModes.indexOf(camera.SceneMode.NORMAL_PHOTO) >= 0;
    if (!isSupportPhotoMode) {
      console.error(TAG + 'photo mode not support');
      return;
    }
    // 获取相机设备支持的输出流能力
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
  
    // 创建预览输出流,其中参数 surfaceId 参考上文 XComponent 组件，预览流为XComponent组件提供的surface
    try {
      this.mPreviewOutput = this.mCameraManager.createPreviewOutput(this.previewProfileObj, surfaceId);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + `Failed to create the PreviewOutput instance. error code: ${err.code}`);
    }
    if (this.mPreviewOutput === undefined) {
      return;
    }
  
    //创建会话
    try {
      this.mPhotoSession = this.mCameraManager.createSession(camera.SceneMode.NORMAL_PHOTO) as camera.PhotoSession;
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to create the session instance. errorCode = ' + err.code);
    }
    if (this.mPhotoSession === undefined) {
      return;
    }
  
    // 开始配置会话
    try {
      this.mPhotoSession.beginConfig();
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to beginConfig. errorCode = ' + err.code);
    }
  
    // 向会话中添加相机输入流
    try {
      this.mPhotoSession.addInput(this.mCameraInput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to addInput. errorCode = ' + err.code);
    }
  
    // 向会话中添加预览输出流
    try {
      this.mPhotoSession.addOutput(this.mPreviewOutput);
    } catch (error) {
      let err = error as BusinessError;
      console.error(TAG + 'Failed to addOutput(previewOutput). errorCode = ' + err.code);
    }
  
    // 提交会话配置
    await this.mPhotoSession.commitConfig();
  
    // 启动会话
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
        Text('切换摄像头')
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
