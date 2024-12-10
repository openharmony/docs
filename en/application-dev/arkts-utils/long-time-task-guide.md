# Continuous Task Development (TaskPool)

This section describes how to use TaskPool to develop a continuous task. The following uses periodic sensor data collection as an example.

## Using TaskPool to Listen to Sensor Data

1. Import the required modules.

   ```ts
   // Index.ets
   import { sensor } from '@kit.SensorServiceKit';
   import { taskpool } from '@kit.ArkTS';
   import { BusinessError, emitter } from '@kit.BasicServicesKit';
   ```

2. Defines a long-term task, listens to sensor data internally, and registers a destruction notification through the emitter.

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

3. The host thread defines the registration and destruction behavior.
   - Registration: Initiate a long-term task and receive listening data through the emitter.
   - Destroy: Sends the event for canceling the sensor listening and ends the continuous task.

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
   
   
