# 应用接入歌词组件
<!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend@devil_red-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @w_Machine_cc-->

从API version 23开始，系统提供歌词组件功能。歌词组件以悬浮窗形式显示于系统桌面，支持歌词内容展示、组件隐藏、组件锁定等操作。暂不支持应用对组件进行自定义样式设置。本文将说明应用接入歌词组件的开发步骤。

## 具体步骤

1. 调用[isDesktopLyricSupported](../../reference/apis-avsession-kit/arkts-apis-avsession-f.md#avsessionisdesktoplyricsupported23)接口判断系统/设备是否支持歌词组件能力，返回true时表示支持歌词组件能力。

2. 创建[AVSession实例](../avsession/avsession-access-scene.md#创建不同类型的会话)，通过[设置元数据信息](../avsession/avsession-access-scene.md#设置元数据信息)填入LRC格式的歌词数据，包含时间标签及对应的歌词文本。不符合LRC格式的歌词数据，系统可能存在解析异常导致无法展示歌词内容。

3. 调用[enableDesktopLyric](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#enabledesktoplyric23)接口启用歌词组件，需传入参数true打开歌词组件。

4. 歌词组件启用后默认是隐藏（不显示），应用可以通过接口主动显示/隐藏歌词组件，具体接口如下：
   
   **设置可见性：** 调用[setDesktopLyricVisible](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setdesktoplyricvisible23)接口，设置歌词组件是否显示。

   **查询可见性：** 调用[isDesktopLyricVisible](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#isdesktoplyricvisible23)接口，查询当前歌词组件是否显示。

5. 歌词组件启用后默认是非锁定状态，应用可以通过接口主动锁定/解锁歌词组件，具体接口如下：

   **设置锁定状态：** 调用[setDesktopLyricState](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#setdesktoplyricstate23)接口，设置歌词窗口是否锁定（限制歌词窗口的拖动、设置等操作）。
   
   **查询锁定状态：** 调用[getDesktopLyricState](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#getdesktoplyricstate23)接口，查询当前歌词组件锁定状态。

6. 应用可以通过系统提供的回调监听歌词组件可见性、锁定状态的变化，具体接口如下：

   **监听歌词组件是否可见：** 监听[onDesktopLyricVisibilityChanged](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#ondesktoplyricvisibilitychanged23)，回调返回false，表示当前歌词组件不可见；回调返回true，表示当前歌词组件可见。如需取消该监听，使用[offDesktopLyricVisibilityChanged](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#offdesktoplyricvisibilitychanged23)接口。

   **监听歌词组件是否锁定：** 监听[onDesktopLyricStateChanged](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#ondesktoplyricstatechanged23)，回调返回false，表示当前歌词组件未锁定；回调返回true，表示当前歌词组件锁定。如需取消该监听，使用[offDesktopLyricStateChanged](../../reference/apis-avsession-kit/arkts-apis-avsession-AVSession.md#offdesktoplyricstatechanged23)接口。

   > **说明：**
   >
   > 确保AVSession对象在后台播放期间不被系统回收/应用不主动释放，否则会导致歌词组件异常。

   <!-- @[setAVSessionInformation](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Media/AVSession/LocalAVSession/AVSessionProvider/entry/src/main/ets/pages/DesktopLyric.ets) -->
   
   ``` TypeScript
   import { avSession as AVSessionManager } from '@kit.AVSessionKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   // ...
   
   @Entry
   @Component
   struct Index {
     @State message: string = 'hello world';
     // ...
   
     build() {
       Column() {
         // ...
         Text(this.message)
           .onClick(async () => {
             console.info(`DesktopLyric set start`);
             let context = this.getUIContext().getHostContext() as Context;
             // 假设已经创建了一个session，如何创建session可以参考之前的案例。
             let session = await AVSessionManager.createAVSession(context, 'SESSION_NAME', 'audio');
   
             // 系统是否支持歌词组件
             let isDesktopLyricSupported: boolean = false;
             try {
               isDesktopLyricSupported = await AVSessionManager.isDesktopLyricSupported();
             } catch (err) {
               console.error(`Failed to get isDesktopLyricSupported. Code: ${err.code}, message: ${err.message}`);
             }
             if (!isDesktopLyricSupported) {
               return;
             }
   
             try {
               // 使能歌词组件
               await session.enableDesktopLyric(true);
             } catch (err) {
               console.error(`enableDesktopLyric err. Code: ${err.code}, message: ${err.message}`);
             }
   
             try {
               // 监听歌词组件是否显示
               session.onDesktopLyricVisibilityChanged((isVisible: boolean) => {
                 console.info(`onDesktopLyricVisibilityChanged changed: ${isVisible}`)
               });
             } catch (err) {
               console.error(`onDesktopLyricVisibilityChanged err. Code: ${err.code}, message: ${err.message}`);
             }
   
             try {
               // 监听歌词组件锁定状态
               session.onDesktopLyricStateChanged((state) => {
                 console.info(`onDesktopLyricStateChanged changed: ${state.isLocked}`)
               });
             } catch (err) {
               console.error(`onDesktopLyricStateChanged err. Code: ${err.code}, message: ${err.message}`);
             }
   
             try {
               // 显示或隐藏歌词组件，歌词组件使能后默认隐藏
               await session.setDesktopLyricVisible(true);
             } catch (err) {
               console.error(`setDesktopLyricVisible err. Code: ${err.code}, message: ${err.message}`);
             }
   
             try {
               // 锁定或解锁歌词组件，歌词组件使能后默认是解锁状态
               await session.setDesktopLyricState({isLocked: true});
             } catch (err) {
               console.error(`setDesktopLyricState err. Code: ${err.code}, message: ${err.message}`);
             }
   
             console.info(`DesktopLyric set done`);
           })
       }
       .width('100%')
       .height('100%')
     }
   }
   ```
