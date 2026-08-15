# 长时任务开发指导 (TaskPool)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

此处提供使用TaskPool进行长时任务的开发指导，以定期采集传感器数据为例。

## 使用TaskPool进行传感器数据监听

1. 导入所需的模块。

   <!-- @[taskpool_listen_sensor_data_import](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/LongTimeTaskGuide.ets) -->
   
   ``` TypeScript
   import { sensor } from '@kit.SensorServiceKit';
   import { taskpool } from '@kit.ArkTS';
   import { BusinessError, emitter } from '@kit.BasicServicesKit';
   ```

2. 定义长时任务，内部监听sensor数据，并通过emitter注册销毁通知。

   <!-- @[taskpool_listen_sensor_data_concurrent](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/LongTimeTaskGuide.ets) -->
   
   ``` TypeScript
   @Concurrent
   async function sensorListener(): Promise<void> {
     sensor.on(sensor.SensorId.ACCELEROMETER, (data) => {
       emitter.emit({ eventId: 0 }, { data: data });
     }, { interval: 1000000000 });
   
     emitter.on({ eventId: 1 }, () => {
       sensor.off(sensor.SensorId.ACCELEROMETER)
       emitter.off(1)
     })
   }
   ```

3. 给应用添加ohos.permission.ACCELEROMETER权限，在module.json5中的"module"字段中添加如下代码示例的"requestPermissions"字段，配置相关权限。

   ```json
   "requestPermissions": [
     {
       "name": "ohos.permission.ACCELEROMETER"
     }
   ]
   ```
4. 宿主线程定义注册及销毁的行为。
   - 注册：发起长时任务，并通过emitter接收监听数据。
   - 销毁：发送取消传感器监听的事件，并结束长时任务。

   <!-- @[taskpool_listen_sensor_data](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/LongTimeTaskGuide.ets) -->
   
   ``` TypeScript
   import { sensor } from '@kit.SensorServiceKit';
   import { taskpool } from '@kit.ArkTS';
   import { BusinessError, emitter } from '@kit.BasicServicesKit';
   
   @Concurrent
   async function sensorListener(): Promise<void> {
     sensor.on(sensor.SensorId.ACCELEROMETER, (data) => {
       emitter.emit({ eventId: 0 }, { data: data });
     }, { interval: 1000000000 });
   
     emitter.on({ eventId: 1 }, () => {
       sensor.off(sensor.SensorId.ACCELEROMETER)
       emitter.off(1)
     })
   }
   
   @Entry
   @Component
   struct Index {
     sensorTask?: taskpool.LongTask
     @State addListener: string = 'Add listener';
     @State deleteListener: string = 'Delete listener';
   
     build() {
       Column() {
         Text(this.addListener)
           .id('Add listener')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             this.sensorTask = new taskpool.LongTask(sensorListener);
             emitter.on({ eventId: 0 }, (data) => {
               // Do something here
               console.info(`Receive ACCELEROMETER data: {${data.data?.x}, ${data.data?.y}, ${data.data?.z}}`);
             });
             taskpool.execute(this.sensorTask).then(() => {
               this.addListener = 'success';
               console.info('Add listener of ACCELEROMETER success');
             }).catch((e: BusinessError) => {
               this.addListener = 'failed';
             })
           })
         Text(this.deleteListener)
           .id('Delete listener')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             emitter.emit({ eventId: 1 });
             emitter.off(0);
             if (this.sensorTask != undefined) {
               taskpool.terminateTask(this.sensorTask);
               this.deleteListener = 'success';
             } else {
               console.error('sensorTask is undefined.');
               this.deleteListener = 'failed';
             }
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
   
   
