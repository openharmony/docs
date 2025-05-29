# 管理麦克风

因为在录制过程中需要使用麦克风录制相关音频数据，所以建议开发者在调用录制接口前查询麦克风状态，并在录制过程中监听麦克风的状态变化，避免影响录制效果。

在音频录制过程中，用户可以将麦克风静音，此时录音过程正常进行，录制生成的数据文件的大小随录制时长递增，但写入文件的数据均为0，即无声数据（空白数据）。

## 开发步骤及注意事项

在AudioVolumeGroupManager中提供了管理麦克风状态的方法，接口的详细说明请参考[API文档](../../reference/apis-audio-kit/js-apis-audio.md#audiovolumegroupmanager9)。

1. 创建audioVolumeGroupManager对象。
     
   ```ts
   import { audio } from '@kit.AudioKit';

   let audioVolumeGroupManager: audio.AudioVolumeGroupManager;

   // 创建audioVolumeGroupManager对象。
   async function loadVolumeGroupManager() {
     const groupid = audio.DEFAULT_VOLUME_GROUP_ID;
     audioVolumeGroupManager = await audio.getAudioManager().getVolumeManager().getVolumeGroupManager(groupid);
     console.info('audioVolumeGroupManager create success.');
   }
   ```
<!--Del-->
2. **(仅对系统应用开放)** 调用on('micStateChange')监听麦克风状态变化，当麦克风静音状态发生变化时将通知应用。
   
   目前此订阅接口在单进程多AudioManager实例的使用场景下，仅最后一个实例的订阅生效，其他实例的订阅会被覆盖（即使最后一个实例没有进行订阅），因此推荐使用单一AudioManager实例进行开发。

   ```ts
   // 监听麦克风状态变化。
   async function on() {
     audioVolumeGroupManager.on('micStateChange', (micStateChange: audio.MicStateChangeEvent) => {
       console.info(`Current microphone status is: ${micStateChange.mute} `);
     });
   }
   ```
<!--DelEnd-->

3. 调用isMicrophoneMute查询麦克风当前静音状态，返回true为静音，false为非静音。
     
   ```ts
   // 查询麦克风是否静音。
   async function isMicrophoneMute() {
     await audioVolumeGroupManager.isMicrophoneMute().then((value: boolean) => {
       console.info(`isMicrophoneMute is: ${value}.`);
     });
   }
   ```
<!--Del-->
4. **(仅对系统应用开放)** 根据查询结果的实际情况，调用setMicrophoneMute设置麦克风静音状态，入参输入true为静音，false为非静音。
     
   ```ts
   // 设置麦克风静音，入参为true。
   async function setMicrophoneMuteTrue() {
     await audioVolumeGroupManager.setMicMute(true).then(() => {
       console.info('setMicrophoneMute to mute.');
     });
   }

   // 取消麦克风静音，入参为false。
   async function setMicrophoneMuteFalse() {
     await audioVolumeGroupManager.setMicMute(false).then(() => {
       console.info('setMicrophoneMute to not mute.');
     });
   }
   ```

## 完整示例

参考以下示例，完成从设置麦克风静音到取消麦克风静音的过程。

```ts
   import { audio } from '@kit.AudioKit';
   
   let audioVolumeGroupManager: audio.AudioVolumeGroupManager;
   
   async function loadVolumeGroupManager() {
     const groupid = audio.DEFAULT_VOLUME_GROUP_ID;
     audioVolumeGroupManager = await audio.getAudioManager().getVolumeManager().getVolumeGroupManager(groupid);
     console.info('audioVolumeGroupManager------create-------success.');
   }

   // 监听麦克风状态变化。
   async function on() {
     await loadVolumeGroupManager();
     audioVolumeGroupManager.on('micStateChange', (micStateChange) => {
       console.info(`Current microphone status is: ${micStateChange.mute} `);
     });
   }

   // 查询麦克风是否静音。
   async function isMicrophoneMute() {
     await audioVolumeGroupManager.isMicrophoneMute().then((value) => {
       console.info(`isMicrophoneMute is: ${value}.`);
     });
   }

   // 设置麦克风静音。
   async function setMicrophoneMuteTrue() {
     await loadVolumeGroupManager();
     await audioVolumeGroupManager.setMicMute(true).then(() => {
       console.info('setMicrophoneMute to mute.');
     });
   }

   // 取消麦克风静音。
   async function setMicrophoneMuteFalse() {
     await loadVolumeGroupManager();
     await audioVolumeGroupManager.setMicMute(false).then(() => {
       console.info('setMicrophoneMute to not mute.');
     });
   }

   async function test(){
     await on();
     await isMicrophoneMute();
     await setMicrophoneMuteTrue();
     await isMicrophoneMute();
     await setMicrophoneMuteFalse();
     await isMicrophoneMute();
     await setMicrophoneMuteTrue();
     await isMicrophoneMute();
   }
```
<!--DelEnd--> 