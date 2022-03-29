# Vibrator Development


## When to Use

You can set different vibration effects as needed, for example, customizing vibration effects with different intensities and durations for buttons on the device, and customizing one-shot or periodic vibration effects with different intensities and durations for alarm clocks and incoming calls.


## Available APIs

  | Module | API | Description | 
| -------- | -------- | -------- |
| ohos.vibrator | vibrate(duration:&nbsp;number):&nbsp;Promise&lt;void&gt; | Triggers&nbsp;vibration&nbsp;with&nbsp;the&nbsp;specified&nbsp;duration.&nbsp;This&nbsp;API&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 
| ohos.vibrator | vibrate(duration:&nbsp;number,&nbsp;callback?:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Triggers&nbsp;vibration&nbsp;with&nbsp;the&nbsp;specified&nbsp;duration.&nbsp;This&nbsp;API&nbsp;uses&nbsp;a&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 
| ohos.vibrator | vibrate(effectId:&nbsp;EffectId):&nbsp;Promise&lt;void&gt; | Triggers&nbsp;vibration&nbsp;with&nbsp;the&nbsp;specified&nbsp;effect.&nbsp;This&nbsp;API&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 
| ohos.vibrator | vibrate(effectId:&nbsp;EffectId,&nbsp;callback?:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Triggers&nbsp;vibration&nbsp;with&nbsp;the&nbsp;specified&nbsp;effect.&nbsp;This&nbsp;API&nbsp;uses&nbsp;a&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 
| ohos.vibrator | stop(stopMode:&nbsp;VibratorStopMode):&nbsp;Promise&lt;void&gt; | Stops&nbsp;vibration.&nbsp;This&nbsp;API&nbsp;uses&nbsp;a&nbsp;promise&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 
| ohos.vibrator | stop(stopMode:&nbsp;VibratorStopMode,&nbsp;callback?:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Stops&nbsp;vibration.&nbsp;This&nbsp;API&nbsp;uses&nbsp;a&nbsp;callback&nbsp;to&nbsp;return&nbsp;the&nbsp;result. | 


## How to Develop

1. Declare the permissions required for controlling vibrators on the hardware device in the **config.json** file. 
     
   ```
   "reqPermissions":[
     {
        "name":"ohos.permission.ACCELEROMETER",
        "reason"":"", 
        "usedScene":{
         "ability""[
           ".MainAbility"
         ],
         "when":"inuse"
       }
     },
     {
        "name":"ohos.permission.VIBRATE",
        "reason"":"", 
        "usedScene":{
         "ability""[
           ".MainAbility"
         ],
         "when":"inuse"
       }
     },
     {
        "name":"ohos.permission.ACTIVITY_MOTION",
        "reason"":"", 
        "usedScene":{
         "ability""[
           ".MainAbility"
         ],
         "when":"inuse"
       }
     },
   ]
   ```

2. Trigger the device to vibrate.
     
   ```
   import vibrator from "@ohos.vibrator"
   vibrator.vibrate(duration: number).then((error)=>{
       if(error){// The call fails, and error.code and error.message are printed.
          console.log("Promise return failed.error.code"+error.code+"error.message"+error.message);  
       }else{// The call succeeded. The device starts to vibrate.
          console.log("Promise returned to indicate a successful vibration.")  
       };
   })
   ```

3. Stop the vibration.
     
   ```
   import vibrator from "@ohos.vibrator"
   vibrator.stop(stopMode: VibratorStopMode).then((error)=>{
      if(error){// The call fails, and error.code and error.message are printed.
          console.log("Promise return failed. error.code"+error.code+"error.message"+error.message);
      }else{// The call succeeded. The device stops vibration.
          Console.log("Promise returned to indicate a successful stop.");
      };
   })
   ```
