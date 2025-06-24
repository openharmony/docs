# Continuous Task Development (TaskPool)

This section provides a development guide for continuous tasks using TaskPool, with the example of periodically collecting sensor data.

## Using TaskPool to Listen for Sensor Data

1. Import the required modules.

   ```ts
   // Index.ets
   import { sensor } from '@kit.SensorServiceKit';
   import { taskpool } from '@kit.ArkTS';
   import { BusinessError, emitter } from '@kit.BasicServicesKit';
   ```

2. Define a continuous task to listen for sensor data internally and register a destruction notification via emitter.

   ```ts
   // Index.ets
   @Concurrent
   async function SensorListener() : Promise<void> {
     sensor.on(sensor.SensorId.ACCELEROMETER, (data) => {
       emitter.emit({ eventId: 0 }, { data: data });
     }, { interval: 1000000000 });
   
     emitter.on({ eventId: 1 }, () => {
       sensor.off(sensor.SensorId.ACCELEROMETER)
       emitter.off(1)
     })
   }
   ```

3. Define the registration and destruction behavior in the host thread.
   - Registration: Initiate the continuous task and receive listening data via emitter.
   - Destruction: Send an event to cancel sensor listening and terminate the continuous task.

   ```ts
   // Index.ets
   @Entry
   @Component
   struct Index {
     sensorTask?: taskpool.LongTask
   
     build() {
       Column() {
         Text("Add listener")
           .id('HelloWorld')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             this.sensorTask = new taskpool.LongTask(SensorListener);
             emitter.on({ eventId: 0 }, (data) => {
               // Do something here
               console.info(`Receive ACCELEROMETER data: {${data.data?.x}, ${data.data?.y}, ${data.data?.z}`);
             });
             taskpool.execute(this.sensorTask).then(() => {
               console.info("Add listener of ACCELEROMETER success");
             }).catch((e: BusinessError) => {
               // Process error
             })
           })
         Text("Delete listener")
           .id('HelloWorld')
           .fontSize(50)
           .fontWeight(FontWeight.Bold)
           .onClick(() => {
             emitter.emit({ eventId: 1 });
             emitter.off(0);
             if(this.sensorTask != undefined) {
               taskpool.terminateTask(this.sensorTask);
             } else {
               console.error("sensorTask is undefined.");
             }
           })
       }
       .height('100%')
       .width('100%')
     }
   }
   ```
   <!-- @[taskpool_listen_sensor_data](https://gitee.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ArkTS/ArkTsConcurrent/ApplicationMultithreadingDevelopment/ApplicationMultithreading/entry/src/main/ets/managers/LongTimeTaskGuide.ets) -->
   
   
