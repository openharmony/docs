# 音频录制流管理

对于录制音频类的应用，开发者需要关注该应用的音频流的状态以做出相应的操作，比如监听到状态为结束时，及时提示用户录制已结束。

## 读取或监听应用内音频流状态变化

参考[使用AudioCapturer开发音频录制功能](using-audiocapturer-for-recording.md)或[audio.createAudioCapturer](../../reference/apis-audio-kit/js-apis-audio.md#audiocreateaudiocapturer8)，完成AudioCapturer的创建，然后可以通过以下两种方式查看音频流状态的变化：

- 方法1：直接查看AudioCapturer的[state](../../reference/apis-audio-kit/js-apis-audio.md#属性)：
    
  ```ts
  let audioCapturerState: audio.AudioState = audioCapturer.state;
  console.info(`Current state is: ${audioCapturerState }`)
  ```

- 方法2：注册stateChange监听AudioCapturer的状态变化：
    
  ```ts
  audioCapturer.on('stateChange', (capturerState: audio.AudioState) => {
    console.info(`State change to: ${capturerState}`)
  });
  ```

获取state后可对照[AudioState](../../reference/apis-audio-kit/js-apis-audio.md#audiostate8)来进行相应的操作，比如显示录制结束的提示等。

## 读取或监听所有录制流的变化

如果部分应用需要查询获取所有音频流的变化信息，可以通过AudioStreamManager读取或监听所有音频流的变化。

<!--Del-->
> **说明：**
> 
> 对于标记为系统接口（system api）的音频流变化信息需要系统级别应用才可查看，若应用不是系统应用，将无法获取准确信息。
<!--DelEnd-->

如下为音频流管理调用关系图：

![Invoking relationship of recording stream management](figures/invoking-relationship-recording-stream-mgmt.png)

在进行应用开发的过程中，开发者需要使用getStreamManager()创建一个AudioStreamManager实例，进而通过该实例管理音频流。开发者可通过调用on('audioCapturerChange')监听音频流的变化，在音频流状态变化、设备变化时获得通知，同时可通过off('audioCapturerChange')取消相关事件的监听。另外，开发者可以通过主动调用getCurrentAudioCapturerInfoArray()查询录制流的唯一ID、录制流客户端的UID、以及流状态等信息。

详细API含义可参考[AudioStreamManager](../../reference/apis-audio-kit/js-apis-audio.md#audiostreammanager9)。

## 开发步骤及注意事项

1. 创建AudioStreamManager实例。
     在使用AudioStreamManager的API前，需要使用getStreamManager()创建一个AudioStreamManager实例。
     
   ```ts
   import { audio } from '@kit.AudioKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   let audioManager = audio.getAudioManager();
   let audioStreamManager = audioManager.getStreamManager();
   ```

2. 使用on('audioCapturerChange')监听音频录制流更改事件。 如果音频流监听应用需要在音频录制流状态变化、设备变化时获取通知，可以订阅该事件。
     
   ```ts
   audioStreamManager.on('audioCapturerChange', (AudioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) =>  {
     for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
       console.info(`## CapChange on is called for element ${i} ##`);
       console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
       console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
       console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
       let devDescriptor: audio.AudioDeviceDescriptors = AudioCapturerChangeInfoArray[i].deviceDescriptors;
       for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
         console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
         console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
         console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
         console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
         console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
         console.info(`SampleRates: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
         console.info(`ChannelCounts ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
         console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks}`);
       }
     }
   });
   ```

3. （可选）使用off('audioCapturerChange')取消监听音频录制流变化。
     
   ```ts
   audioStreamManager.off('audioCapturerChange');
   console.info('CapturerChange Off is called');
   ```

4. （可选）使用getCurrentAudioCapturerInfoArray()获取当前音频录制流的信息。
     该接口可获取音频录制流唯一ID、音频录制客户端的UID、音频状态以及音频捕获器的其他信息。
     
   > **说明：**
   > 对所有音频流状态进行监听的应用需要[声明权限](../../security/AccessToken/declare-permissions.md)ohos.permission.USE_BLUETOOTH，否则无法获得实际的设备名称和设备地址信息，查询到的设备名称和设备地址（蓝牙设备的相关属性）将为空字符串。

   ```ts
   async function getCurrentAudioCapturerInfoArray(){
     await audioStreamManager.getCurrentAudioCapturerInfoArray().then((AudioCapturerChangeInfoArray: audio.AudioCapturerChangeInfoArray) => {
       console.info('getCurrentAudioCapturerInfoArray  Get Promise Called ');
       if (AudioCapturerChangeInfoArray != null) {
         for (let i = 0; i < AudioCapturerChangeInfoArray.length; i++) {
           console.info(`StreamId for ${i} is: ${AudioCapturerChangeInfoArray[i].streamId}`);
           console.info(`Source for ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.source}`);
           console.info(`Flag  ${i} is: ${AudioCapturerChangeInfoArray[i].capturerInfo.capturerFlags}`);
           for (let j = 0; j < AudioCapturerChangeInfoArray[i].deviceDescriptors.length; j++) {
             console.info(`Id: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].id}`);
             console.info(`Type: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceType}`);
             console.info(`Role: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].deviceRole}`);
             console.info(`Name: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].name}`);
             console.info(`Address: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].address}`);
             console.info(`SampleRates: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].sampleRates[0]}`);
             console.info(`ChannelCounts ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelCounts[0]}`);
             console.info(`ChannelMask: ${i} : ${AudioCapturerChangeInfoArray[i].deviceDescriptors[j].channelMasks}`);
           }
         }
       }
     }).catch((err: BusinessError) => {
       console.error(`Invoke getCurrentAudioCapturerInfoArray failed, code is ${err.code}, message is ${err.message}`);
     });
   }
   ```
