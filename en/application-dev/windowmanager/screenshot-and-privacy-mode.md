# Screenshot and Privacy Mode (ArkTS)

<!--Kit: ArkUI-->
<!--Subsystem: Window-->
<!--Owner: @fei_1007-->
<!--Designer: @gcw_sPCsris4-->
<!--Tester: @qinliwen0417-->
<!--Adviser: @ge-yafang-->
<!-- md-trans-meta sourceCommit=279d7d8e7f77f1675b7e5fea89cc7d4dfef86da1 translatedAt=2026-08-11T10:11:03.098Z pushedAt=2026-08-11T11:19:36.715Z -->

## How to Use

Screenshots include window screenshots, screen captures, and component snapshots. Among them, window screenshots and screen captures are both restricted by [privacy mode](#privacy-mode). The capabilities and applicable scenarios of different screenshots vary:

- Window screenshots are based on the app window unit, capturing the visible content of the current window, suitable for current app page collection.

- Screen captures are based on the device screen unit, capable of capturing the entire screen, a specified display, and user-selected area content, suitable for full-screen capture, area capture, and other scenarios.

- Component snapshot targets a single component, capturing only the content of the specified component. It is suitable for scenarios such as sharing card generation.

## Privacy Mode

A window set to privacy mode is called a privacy window. The content of a privacy window cannot be captured by screenshot, screen recording, or screen mirroring. This is mainly used in scenarios where screenshot, screen recording, or screen mirroring is prohibited, typically for pages containing sensitive information such as passwords.

Privacy windows are used to protect sensitive content within a window, preventing the window content from being obtained unexpectedly in scenarios such as screenshots and previews. For windows containing personal information, payment information, conversation content, or other sensitive data, it is recommended to set privacy mode based on service requirements.

### Specification and Behavior

- When no related API is called to set privacy mode, the window does not enable privacy mode by default and can be captured or recorded.

- When a privacy window is in the foreground, in [virtual screen](../displaymanager/display-terminology.md#virtual-screen) display scenarios such as screen mirroring and recording, the system protects private content. The privacy window is displayed as black, or the screen where the privacy window is located is displayed as black. When the main window or subwindow is a privacy window, it is displayed with a white overlay or blurred overlay in the recent tasks cards when moved to the background. The behavior of taking screenshots (screen capture and window screenshot) of a privacy window is as follows:

  - The window screenshot result obtained through the [snapshot()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshot9-1)/[snapshotSync()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshotsync20) API is a white screen.

  - On phones or tablets, users are not allowed to take screenshots using the screenshot button in the pull‑down Control Panel or by knuckle gestures. A message similar to "Screenshots are not allowed due to privacy concerns" is displayed.

  - On PCs/2-in-1 devices, users are allowed to take screenshots using the screenshot button in the pull‑down Control Panel, but the window with privacy mode enabled is displayed as a black screen, while other windows are displayed normally.

- When the service scenario explicitly requires a valid screenshot of a privacy window, you can use the [snapshotIgnorePrivacy()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshotignoreprivacy18) API to achieve this.

- When the business scenario explicitly requires screen recording of a privacy window, you need to first call the [setWindowPrivacyMode()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9-1) API and pass in **false** to cancel the privacy mode of the window, so as to avoid being unable to obtain the corresponding window content.

### Setting Privacy Mode

You can use the [setWindowPrivacyMode()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9-1) API to set whether the window is in privacy mode.

For pages that require protection against screenshots, screen recording, or screen mirroring, you typically call the [setWindowPrivacyMode()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9-1) API and pass in **true** to enable privacy mode when entering the page. When the page is hidden, destroyed, or switched to another non-privacy page, you should call the [setWindowPrivacyMode()](../reference/apis-arkui/arkts-apis-window-Window.md#setwindowprivacymode9-1) API and pass in **false** to cancel privacy mode in the corresponding lifecycle.

## Window Screenshot

Window screenshots are classified into single-window screenshot and multi-window screenshot. Through the corresponding listening capability, you can receive a screenshot listening callback when a window screenshot is taken.

### Single-Window Screenshot

You can take a screenshot of the current window by calling the [snapshot()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshot9-1)/[snapshotSync()](../reference/apis-arkui/arkts-apis-window-Window.md#snapshotsync20) API.

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
    // Record the API call result on the page and output it to hilog for debugging.
    private appendLog(message: string): void {
      this.statusText = message;
      hilog.info(DOMAIN, 'snapshotSample', message);
  
      const line = `${Date.now()}: ${message}`;
      this.logText += `${line}\n`;
      hilog.info(DOMAIN, 'snapshotSample', line);
    }
  
    // Get the current application window. The window.snapshot series APIs must be called through a Window object.
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
    // Get the displayId available for the current device, for use with screenshot.capture.
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
  
    // Confirm that the current window has been initialized before taking a screenshot.
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
  
    // Display the screenshot result in the page preview area and read the width and height of the PixelMap.
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
  
    // Asynchronously capture the current window. In a privacy window scenario, the screenshot result will be protected by privacy mode.
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
  
    // Synchronously captures the current window. The calling method is more direct, but it returns a PixelMap synchronously.
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
  
    // Captures the current window ignoring privacy mode. Use only when explicitly required by the business and supported by the device.
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

### Multi-window Screenshot

You can call the [getMainWindowSnapshot()](../reference/apis-arkui/arkts-apis-window-f.md#windowgetmainwindowsnapshot21) API to capture one or more main windows (specified by **windowId**).

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
    // Record the API call result on the page and output it to hilog for debugging.
    private appendLog(message: string): void {
      this.statusText = message;
      hilog.info(DOMAIN, 'snapshotSample', message);
  
      const line = `${Date.now()}: ${message}`;
      this.logText += `${line}\n`;
      hilog.info(DOMAIN, 'snapshotSample', line);
    }
  
    // Get the current app window. The window.snapshot series APIs need to be called through a Window object.
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
    // getMainWindowSnapshot requires the ohos.permission.CUSTOM_SCREEN_CAPTURE permission.
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
  
    // Get the main window screenshot by the current main window ID.
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

## Screen Capture

Screen capture refers to taking a screenshot of the current screen.

The usage and examples of screen capture APIs are as follows:

- [screenshot.pick()](../reference/apis-arkui/js-apis-screenshot.md#screenshotpick) only supports capturing the main screen. It allows area-based capture, where the user selects any area of the screen through gesture interaction.

- [screenshot.capture()](../reference/apis-arkui/js-apis-screenshot.md#screenshotcapture14) can capture different screens by setting different display IDs, and only supports full-screen capture.

- Listening for screen capture: After registering a screen capture listener, the registered callback function is triggered whenever a screenshot occurs.

  - The [on('screenshot')](../reference/apis-arkui/arkts-apis-window-Window.md#onscreenshot9) API can only listen for the screenshot action and cannot distinguish the specific screenshot event type. It takes effect for screenshots from Control Panel, hdc command-triggered screenshots, and screenshots from the **screenshot.capture()** API.

  - The [on('screenshotAppEvent')](../reference/apis-arkui/arkts-apis-window-Window.md#onscreenshotappevent20) API can listen for screenshot actions and return the triggered screenshot event type [ScreenshotEventType](../reference/apis-arkui/arkts-apis-window-e.md#screenshoteventtype20). For example, system screenshot success or cancellation, scrolling screenshot start or end.

  - When you no longer need to listen for screen capture events, you can disable listening through the corresponding off the ([off('screenshot')](../reference/apis-arkui/arkts-apis-window-Window.md#offscreenshot9)/[off('screenshotAppEvent')](../reference/apis-arkui/arkts-apis-window-Window.md#offscreenshotappevent20)) APIs.

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
  // getMainWindowSnapshot requires the ohos.permission.CUSTOM_SCREEN_CAPTURE permission.
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

  // Obtain the main window screenshot by the current main window ID.
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
  // Select a screen area through a gesture. Only the main screen area screenshot is supported.
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

  // Capture the full-screen content of the corresponding screen based on the displayId.
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

## Component Snapshot

Component snapshots can only capture the area within the component's size. If the component's own drawing content exceeds its layout boundaries, or if a child component's drawing exceeds the parent component's area, the content drawn outside the component area will not appear in the snapshot. For details, see [Using Component Snapshot (ComponentSnapshot)](../ui/arkts-uicontext-component-snapshot.md).