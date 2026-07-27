# 截图与隐私模式 (ArkTS)

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->

## 场景介绍

截图包含窗口截图、屏幕截图和组件截图。其中窗口截图和屏幕截图都受到[隐私模式](#隐私模式)限制。不同截图的能力范围和适用场景不同：

- 窗口截图以应用窗口为单位，获取当前窗口的可见内容，适用于当前应用页面采集等。

- 屏幕截图以设备屏幕为单位，可获取整屏、指定显示屏和用户框选区域内容，适用于整屏截图、区域截图等场景。

- 组件截图以单个组件为场景，仅获取指定组件的内容，适用于分享卡片生成等场景。

## 隐私模式

设置为隐私模式的窗口称为隐私窗口，隐私窗口的窗口内容将无法被截屏/录屏/投屏，主要用于禁止截屏/录屏/投屏的场景，一般用于带有密码等敏感信息的页面。

隐私窗口用于保护窗口中的敏感内容，避免窗口内容在截图、预览等场景下被非预期获取。对于包含个人信息、支付信息、会话内容或其他敏感数据的窗口，建议按业务需要设置隐私模式。

### 规格表现

- 当未调用相关接口设置隐私模式时，窗口默认不开启隐私模式，可以被截屏或录屏。

- 当隐私窗口处于前台时，此时在投屏、录屏等[虚拟屏](../displaymanager/display-terminology.md#虚拟屏)显示场景下，系统会对隐私内容进行保护，隐私窗口显示黑色或隐私窗口所在屏幕显示黑色； 当主窗或子窗为隐私窗口时，退后台在多任务卡片中显示为白色蒙层或模糊蒙层。针对隐私窗口进行截图（屏幕截图和窗口截图）的表现如下：

  - 通过[snapshot()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshot9-1)/[snapshotSync()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshotsync20)接口获取到的窗口截图结果为白屏。

  - 在Phone或Tablet设备上，将不允许用户通过下拉控制中心的截屏按钮或指关节敲击截屏，会提示类似“当前界面涉及隐私，不允许截图”的相关信息。

  - 在PC/2in1设备上，允许用户通过控制中心的截屏按钮进行截屏，但是设置隐私模式的窗口将显示为黑屏，其他窗口正常显示。

- 当业务场景明确需要对隐私窗口进行有效截图时，可以使用[snapshotIgnorePrivacy()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshotignoreprivacy18)接口实现。

- 当业务场景明确需要对隐私窗口进行屏幕录制时，需要先调用[setWindowPrivacyMode()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9-1)接口传入false取消该窗口的隐私模式，以避免无法获取到对应的窗口画面。

### 设置隐私模式

可以使用[setWindowPrivacyMode()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9-1)接口设置窗口是否隐私模式。

对于需要防截屏/录屏/投屏的页面，通常是在进入到该页面时就调用[setWindowPrivacyMode()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9-1)接口传入true设置为隐私模式；当页面隐藏、销毁，或切换到其他非隐私页面时，应该在对应生命周期中调用[setWindowPrivacyMode()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9-1)接口传入false取消隐私模式。

## 窗口截图

窗口截图主要提供单窗口截图、多窗口截图。通过对应监听能力可以在窗口截图时，接收到截图监听回调。

### 单窗口截图
可通过调用[snapshot()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshot9-1)/[snapshotSync()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshotsync20)接口对当前窗口进行截图。  

  <!--@[Snapshot_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/snapshot/entry/src/main/ets/pages/Index.ets) -->
  
  ``` TypeScript
  import { display, screenshot, window } from '@kit.ArkUI';
  import { common, abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { image } from '@kit.ImageKit';
  
  const DOMAIN = 0x0000;
  
  @Entry
  @Component
  struct Index {
    @State statusText: string = 'Tap a button to run the snapshot sample.';
    @State logText: string = 'ready\n';
    @State imageWidth: number = 0;
    @State imageHeight: number = 0;
    @State previewPixelMap?: image.PixelMap = undefined;
    @State displayIdText: string = '0';
    @State displayInfoText: string = '-';
    @State pickRectText: string = '-';
  
    private currentWindow?: window.Window = undefined;
  
    aboutToAppear(): void {
      void this.initWindow();
      this.initDisplayInfo();
    }
    // 在页面中记录接口调用结果，同时输出到hilog，便于调试。
    private appendLog(message: string): void {
      this.statusText = message;
      hilog.info(DOMAIN, 'snapshotSample', message);
  
      const line = `${Date.now()}: ${message}`;
      this.logText += `${line}\n`;
      hilog.info(DOMAIN, 'snapshotSample', line);
    }
  
    // 获取当前应用窗口。window.snapshot系列接口需要通过Window对象调用。
    private async initWindow(): Promise<void> {
      try {
        const hostContext = this.getUIContext().getHostContext();
        if (!hostContext) {
          throw new Error('Host context is unavailable.');
        }
  
        const context = hostContext as common.UIAbilityContext;
        this.currentWindow = await window.getLastWindow(context);
  
        const windowId = this.currentWindow.getWindowProperties().id;
        this.statusText = `windowId=${windowId}`;
        this.appendLog(`window initialized, windowId=${windowId}`);
      } catch (err) {
        this.statusText = `Initialization failed: ${JSON.stringify(err)}`;
        this.appendLog(`Initialization failed: ${JSON.stringify(err)}`);
        this.appendLog(this.statusText);
      }
    }
    // 获取当前设备可用的displayId，供screenshot.capture使用。
    private async initDisplayInfo(): Promise<void> {
      try {
        const defaultDisplay = display.getDefaultDisplaySync();
        this.displayIdText = `${defaultDisplay.id}`;
  
        const displays = await display.getAllDisplays();
        this.displayInfoText = displays.map((item) => `${item.id}`).join(', ');
        this.statusText = `available displayIds=${this.displayInfoText}`;
      } catch (err) {
        this.statusText = `init display info failed: ${JSON.stringify(err)}`;
        hilog.error(DOMAIN, 'screenshotSample', this.statusText);
      }
    }
  
    // 截图前确认当前窗口已初始化。
    private async ensureWindow(): Promise<boolean> {
      if (!this.currentWindow) {
        await this.initWindow();
      }
  
      if (!this.currentWindow) {
        this.statusText = 'Current window is unavailable.';
        this.appendLog(this.statusText);
        return false;
      }
  
      return true;
    }
  
    // 将截图结果展示到页面预览区域，并读取PixelMap宽高。
    private updatePreview(pixelMap: image.PixelMap, source: string): void {
      this.previewPixelMap = pixelMap;
  
      try {
        const imageInfo = pixelMap.getImageInfoSync();
        this.imageWidth = imageInfo.size.width;
        this.imageHeight = imageInfo.size.height;
        this.statusText = `${source} success, size=${this.imageWidth}x${this.imageHeight}`;
        this.appendLog(`${source} success, size=${this.imageWidth}x${this.imageHeight}`);
      } catch (err) {
        this.imageWidth = 0;
        this.imageHeight = 0;
        this.statusText = `${source} success, but getImageInfoSync failed: ${JSON.stringify(err)}`;
        this.appendLog(`${source} success, but getImageInfoSync failed: ${JSON.stringify(err)}`);
      }
  
      hilog.info(DOMAIN, 'screenshotSample', this.statusText);
      this.appendLog(this.statusText);
    }
  
    // 异步截取当前窗口。隐私窗口场景下，截图结果会受到隐私模式保护。
    private async takeWindowSnapshot(): Promise<void> {
      if (!await this.ensureWindow()) {
        return;
      }
  
      try {
        const pixelMap = await this.currentWindow!.snapshot();
        await this.updatePreview(pixelMap, 'window.snapshot');
      } catch (err) {
        this.statusText = `window.snapshot failed: ${JSON.stringify(err)}`;
        this.appendLog(this.statusText);
      }
    }
  
    // 同步截取当前窗口。调用方式更直接，但会同步返回PixelMap。
    private takeWindowSnapshotSync(): void {
      if (!this.currentWindow) {
        this.statusText = 'window.snapshotSync failed: current window is unavailable.';
        this.appendLog(this.statusText);
        return;
      }
  
      try {
        const pixelMap = this.currentWindow.snapshotSync();
        void this.updatePreview(pixelMap, 'window.snapshotSync');
      } catch (err) {
        this.statusText = `window.snapshotSync failed: ${JSON.stringify(err)}`;
        this.appendLog(this.statusText);
      }
    }
  
    // 忽略隐私模式截取当前窗口。仅在业务明确需要且设备支持时使用。
    private async takeWindowSnapshotIgnorePrivacy(): Promise<void> {
      if (!await this.ensureWindow()) {
        return;
      }
  
      try {
        const pixelMap = await this.currentWindow!.snapshotIgnorePrivacy();
        await this.updatePreview(pixelMap, 'window.snapshotIgnorePrivacy');
      } catch (err) {
        this.statusText = `window.snapshotIgnorePrivacy failed: ${JSON.stringify(err)}`;
        this.appendLog(this.statusText);
      }
    }
    // ...
  
    build() {
    // ...
  }
  ```

### 多窗口截图
可通过调用[getMainWindowSnapshot()](../reference/apis-arkui/arkts-apis-window-f.md#windowgetmainwindowsnapshot21)接口，针对一个或多个主窗（通过windowId指定）进行截图。  

  <!--@[SnapshotMore_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/snapshot/entry/src/main/ets/pages/Index.ets) -->
  
  ``` TypeScript
  import { display, screenshot, window } from '@kit.ArkUI';
  import { common, abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  import { image } from '@kit.ImageKit';
  
  const DOMAIN = 0x0000;
  
  @Entry
  @Component
  struct Index {
    @State statusText: string = 'Tap a button to run the snapshot sample.';
    @State logText: string = 'ready\n';
    @State imageWidth: number = 0;
    @State imageHeight: number = 0;
    @State previewPixelMap?: image.PixelMap = undefined;
    @State displayIdText: string = '0';
    @State displayInfoText: string = '-';
    @State pickRectText: string = '-';
  
    private currentWindow?: window.Window = undefined;
  
    aboutToAppear(): void {
      void this.initWindow();
      this.initDisplayInfo();
    }
    // 在页面中记录接口调用结果，同时输出到hilog，便于调试。
    private appendLog(message: string): void {
      this.statusText = message;
      hilog.info(DOMAIN, 'snapshotSample', message);
  
      const line = `${Date.now()}: ${message}`;
      this.logText += `${line}\n`;
      hilog.info(DOMAIN, 'snapshotSample', line);
    }
  
    // 获取当前应用窗口。window.snapshot系列接口需要通过Window对象调用。
    private async initWindow(): Promise<void> {
      try {
        const hostContext = this.getUIContext().getHostContext();
        if (!hostContext) {
          throw new Error('Host context is unavailable.');
        }
  
        const context = hostContext as common.UIAbilityContext;
        this.currentWindow = await window.getLastWindow(context);
  
        const windowId = this.currentWindow.getWindowProperties().id;
        this.statusText = `windowId=${windowId}`;
        this.appendLog(`window initialized, windowId=${windowId}`);
      } catch (err) {
        this.statusText = `Initialization failed: ${JSON.stringify(err)}`;
        this.appendLog(`Initialization failed: ${JSON.stringify(err)}`);
        this.appendLog(this.statusText);
      }
    }
    // ...
    // getMainWindowSnapshot需要使用ohos.permission.CUSTOM_SCREEN_CAPTURE权限。
    private async requestCapturePermission(): Promise<boolean> {
      try {
        const hostContext = this.getUIContext().getHostContext();
        if (!hostContext) {
          this.statusText = 'permission request failed: hostContext is unavailable';
          this.appendLog('permission request failed: hostContext is unavailable');
          return false;
        }
  
        const context = hostContext as common.UIAbilityContext;
        const atManager = abilityAccessCtrl.createAtManager();
        const result = await atManager.requestPermissionsFromUser(context, [
          'ohos.permission.CUSTOM_SCREEN_CAPTURE' as Permissions
        ]);
  
        const granted = result.authResults.length > 0 && result.authResults[0] === 0;
        this.statusText = `permission granted=${granted}`;
        this.appendLog(`permission granted=${granted}`);
        return granted;
      } catch (err) {
        this.statusText = `permission request failed: ${JSON.stringify(err)}`;
        this.appendLog(`permission request failed: ${JSON.stringify(err)}`);
        return false;
      }
    }
  
    // 通过当前主窗口ID获取主窗口截图。
    private async takeMainWindowSnapshot(): Promise<void> {
      if (!this.currentWindow) {
        await this.initWindow();
      }
  
      if (!this.currentWindow) {
        this.appendLog('Current window is unavailable.');
        return;
      }
  
      const granted = await this.requestCapturePermission();
      if (!granted) {
        this.appendLog('CUSTOM_SCREEN_CAPTURE permission denied or unavailable.');
        return;
      }
  
      try {
        const windowId = this.currentWindow.getWindowProperties().id;
        const pixelMaps = await window.getMainWindowSnapshot([windowId], {
          useCache: false
        });
  
        const pixelMap = pixelMaps[0];
        if (!pixelMap) {
          this.appendLog(`getMainWindowSnapshot(${windowId}) returned undefined.`);
          return;
        }
  
        await this.updatePreview(pixelMap, 'window.getMainWindowSnapshot');
      } catch (err) {
        this.appendLog(`getMainWindowSnapshot failed: ${JSON.stringify(err)}`);
      }
    }
    // ...
  
    build() {
    // ...
  }
  ```

## 屏幕截图

屏幕截图是指对当前屏幕进行截屏。

屏幕截图相关接口的使用及示例如下所示：

- [screenshot.pick()](../reference/apis-arkui/js-apis-screenshot.md#screenshotpick)接口仅支持获取主屏的屏幕截图，允许区域截屏，用户通过手势交互选择屏幕任意区域。

- [screenshot.capture()](../reference/apis-arkui/js-apis-screenshot.md#screenshotcapture14)接口可以通过设置不同的displayId针对不同屏幕进行截图，且只能截取全屏。

- 监听屏幕截图：注册屏幕截图监听后，每当有截屏发生时，都会触发注册的回调函数。

  - [on('screenshot')](../reference/apis-arkui/arkts-apis-window-Window.md#onscreenshot9)接口只能监听截屏动作，无法区分具体的截屏事件类型。对控制中心截屏、hdc命令截屏、screenshot.capture()接口截屏生效。

  - [on('screenshotAppEvent')](../reference/apis-arkui/arkts-apis-window-Window.md#onscreenshotappevent20)接口可以监听截屏动作，并能返回触发的截屏事件类型[ScreenshotEventType](../reference/apis-arkui/arkts-apis-window-e.md#screenshoteventtype20)。比如系统截屏成功或中止、滚动截屏开始或结束等。

  - 当不需要再对屏幕截图进行监听时，可通过对应off接口（[off('screenshot')](../reference/apis-arkui/arkts-apis-window-Window.md#offscreenshot9)/[off('screenshotAppEvent')](../reference/apis-arkui/arkts-apis-window-Window.md#offscreenshotappevent20)）关闭监听。

<!--@[SnapshotScreen_start](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkUISample/ArkUIWindowSamples/snapshot/entry/src/main/ets/pages/Index.ets) -->

``` TypeScript
import { display, screenshot, window } from '@kit.ArkUI';
import { common, abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { image } from '@kit.ImageKit';

const DOMAIN = 0x0000;

@Entry
@Component
struct Index {
  @State statusText: string = 'Tap a button to run the snapshot sample.';
  @State logText: string = 'ready\n';
  @State imageWidth: number = 0;
  @State imageHeight: number = 0;
  @State previewPixelMap?: image.PixelMap = undefined;
  @State displayIdText: string = '0';
  @State displayInfoText: string = '-';
  @State pickRectText: string = '-';

  private currentWindow?: window.Window = undefined;

  aboutToAppear(): void {
    void this.initWindow();
    this.initDisplayInfo();
  }
  // ...
  // getMainWindowSnapshot需要使用ohos.permission.CUSTOM_SCREEN_CAPTURE权限。
  private async requestCapturePermission(): Promise<boolean> {
    try {
      const hostContext = this.getUIContext().getHostContext();
      if (!hostContext) {
        this.statusText = 'permission request failed: hostContext is unavailable';
        this.appendLog('permission request failed: hostContext is unavailable');
        return false;
      }

      const context = hostContext as common.UIAbilityContext;
      const atManager = abilityAccessCtrl.createAtManager();
      const result = await atManager.requestPermissionsFromUser(context, [
        'ohos.permission.CUSTOM_SCREEN_CAPTURE' as Permissions
      ]);

      const granted = result.authResults.length > 0 && result.authResults[0] === 0;
      this.statusText = `permission granted=${granted}`;
      this.appendLog(`permission granted=${granted}`);
      return granted;
    } catch (err) {
      this.statusText = `permission request failed: ${JSON.stringify(err)}`;
      this.appendLog(`permission request failed: ${JSON.stringify(err)}`);
      return false;
    }
  }

  // 通过当前主窗口ID获取主窗口截图。
  private async takeMainWindowSnapshot(): Promise<void> {
    if (!this.currentWindow) {
      await this.initWindow();
    }

    if (!this.currentWindow) {
      this.appendLog('Current window is unavailable.');
      return;
    }

    const granted = await this.requestCapturePermission();
    if (!granted) {
      this.appendLog('CUSTOM_SCREEN_CAPTURE permission denied or unavailable.');
      return;
    }

    try {
      const windowId = this.currentWindow.getWindowProperties().id;
      const pixelMaps = await window.getMainWindowSnapshot([windowId], {
        useCache: false
      });

      const pixelMap = pixelMaps[0];
      if (!pixelMap) {
        this.appendLog(`getMainWindowSnapshot(${windowId}) returned undefined.`);
        return;
      }

      await this.updatePreview(pixelMap, 'window.getMainWindowSnapshot');
    } catch (err) {
      this.appendLog(`getMainWindowSnapshot failed: ${JSON.stringify(err)}`);
    }
  }
  // 通过手势框选屏幕区域，仅支持主屏区域截图。
  private async pickScreenArea(): Promise<void> {
    try {
      const result = await screenshot.pick();
      this.pickRectText = `left=${result.pickRect.left}, top=${result.pickRect.top}, width=${result.pickRect.width}, height=${result.pickRect.height}`;
      await this.updatePreview(result.pixelMap, 'screenshot.pick');
    } catch (err) {
      this.statusText = `screenshot.pick failed: ${JSON.stringify(err)}`;
      hilog.error(DOMAIN, 'screenshotSample', this.statusText);
    }
  }

  // 根据displayId截取对应屏幕的全屏内容。
  private async captureByDisplayId(): Promise<void> {
    const granted = await this.requestCapturePermission();
    if (!granted) {
      this.statusText = 'CUSTOM_SCREEN_CAPTURE permission denied or unavailable.';
      return;
    }

    try {
      const displayId = Number.parseInt(this.displayIdText, 10);
      if (Number.isNaN(displayId) || displayId < 0) {
        throw new Error(`Invalid displayId: ${this.displayIdText}`);
      }

      const pixelMap = await screenshot.capture({ displayId });
      await this.updatePreview(pixelMap, `screenshot.capture(displayId=${displayId})`);
    } catch (err) {
      this.statusText = `screenshot.capture failed: ${JSON.stringify(err)}`;
      hilog.error(DOMAIN, 'screenshotSample', this.statusText);
    }
  }

  build() {
  // ...
}
```

## 组件截图

组件截图只能够截取组件大小的区域，如果组件自身的绘制内容超出了该组件的布局边界，或子组件的绘制超出了父组件的区域，这些在组件区域外绘制的内容不会在截图中呈现，具体可见[使用组件截图（ComponentSnapshot）](../ui/arkts-uicontext-component-snapshot.md)。
