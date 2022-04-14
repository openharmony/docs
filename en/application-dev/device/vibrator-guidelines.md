# Vibrator Development


## When to Use

You can set different vibration effects as needed, for example, customizing vibration effects with different intensities and durations for buttons on the device, and customizing one-shot or periodic vibration effects with different intensities and durations for alarm clocks and incoming calls.


## Available APIs

  | Module| API| Description| 
| -------- | -------- | -------- |
| ohos.vibrator | vibrate(duration:&nbsp;number):&nbsp;Promise&lt;void&gt; | Triggers vibration with the specified duration. This API uses a promise to return the result.| 
| ohos.vibrator | vibrate(duration:&nbsp;number,&nbsp;callback?:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Triggers vibration with the specified duration. This API uses a callback to return the result.| 
| ohos.vibrator | vibrate(effectId:&nbsp;EffectId):&nbsp;Promise&lt;void&gt; | Triggers vibration with the specified effect. This API uses a promise to return the result.| 
| ohos.vibrator | vibrate(effectId:&nbsp;EffectId,&nbsp;callback?:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Triggers vibration with the specified effect. This API uses a callback to return the result.| 
| ohos.vibrator | stop(stopMode:&nbsp;VibratorStopMode):&nbsp;Promise&lt;void&gt; | Stops vibration. This API uses a promise to return the result.| 
| ohos.vibrator | stop(stopMode:&nbsp;VibratorStopMode,&nbsp;callback?:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | Stops vibration. This API uses a callback to return the result.| 


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
   vibrator.vibrate(1000).then((error)=>{
       if (error) {// The call fails, and error.code and error.message are printed.
          Console.log("Promise return failed.error.code"+error.code+"error.message"+error.message);  
       }else{// The call is successful, and the device starts to vibrate.
          Console.log("Promise returned to indicate a successful vibration.")  
       };
   })
   ```

3. Stop the vibration.
  
   ```
   import vibrator from "@ohos.vibrator"
   vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then((error)=>{
      if (error) {// The call fails, and error.code and error.message are printed.
          Console.log("Promise return failed.error.code"+error.code+"error.message"+error.message);
      }else{// The call is successful, and the device stops vibration.
          Console.log("Promise returned to indicate a successful stop.");
      };
   })
   ```
