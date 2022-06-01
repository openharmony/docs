# 常见问题


## 如何查询设备类型

设备类型分为default（默认设备）、tablet、tv、wearable等，有多种查询设备类型的方式。

1. 通过命令行的方式查询设备类型。
   通过命令行查询指定系统参数（const.build.characteristics）进而确定设备类型，详见[系统参数介绍](../../../device-dev/subsystems/subsys-boot-syspara.md)。

   
   ```ts
    # 方法一
    hdc shell param get "const.build.characteristics"
    # 方法二
    hdc shell cat /etc/param/ohos.para | grep const.build.characteristic
   ```

2. 在应用开发过程中查询设备类型。
   - 通过js接口查询指定系统参数（const.build.characteristics）进而确定设备类型，详见[系统属性](../../reference/apis/js-apis-system-parameter.md)。
     
      ```ts
      import parameter from '@ohos.systemParameter'
      
      @Entry
      @Component
      struct GetDeviceTypeSample {
        @State deviceType: string = 'unknown'; 
      
        aboutToAppear() {
          try {
            this.deviceType = parameter.getSync("const.build.characteristics");
          } catch(e) {
            console.log("getSync unexpected error: " + e);
          }
        }
      
        build() {
          Column() {
            Text(this.deviceType).fontSize(24)
          }
          .width('100%')
          .height('100%')
        }
      }
      ```
   - 通过deviceInfo查询设备类型，deviceInfo中各个字段的含义请参考[设备信息](../../reference/apis/js-apis-device-info.md)。
     
      ```ts
       import deviceInfo from'@ohos.deviceInfo'
      
       @Entry
       @Component
       struct GetDeviceTypeSample {
         @State deviceType:string='unknown';
      
         aboutToAppear() {
           this.deviceType= deviceInfo.deviceType;
         }
      
         build() {
           Column() {
             Text(this.deviceType).fontSize()
           }
           .width('100%')
           .height('100%')
         }
      }
      ```


## 如何查询屏幕/窗口尺寸

在应用开发过程中，为了在不同的设备上取得更好的显示效果，开发者可能需要查询屏幕尺寸或应用显示窗口尺寸。

- 通过display查询显示设备的属性（包括屏幕宽、高和屏幕密度等），详见[屏幕属性](../../reference/apis/js-apis-display.md)。
  
  ```ts
  private aboutToAppear() {
     display.getDefaultDisplay()
       .then((displayInfo) => {
           console.info('Display width: '+ displayInfo.width);
           console.info('Display height: '+ displayInfo.height);
           console.info('Display density: '+ displayInfo.densityDPI);
       })
       .catch((error) => {
         console.error('Failed to obtain the default display size. Cause:  '+JSON.stringify(error));
       })
   }
  ```

- 通过window.getTopWindow获取应用窗口，进而查询应用窗口的宽高等，详见[窗口](../../reference/apis/js-apis-window.md)。
  注意必须在应用创建窗口后才可以拿到窗口对象，window.getTopWindow依赖AbilityContext作为入参，可以在MainAbility中通过this.context拿到AbilityContext对象，详见[Ability开发指导](../../ability/stage-ability.md)。可以在MainAbility的onCreate生命周期中拿到窗口尺寸，如下所示。

  
  ```ts
  onCreate(want, launchParam) {
     window.getTopWindow(this.context)
       .then((windowClass) => { return windowClass.getProperties(); })
       .then((topWindow) => {
         console.info('Window width: '+ topWindow.windowRect.width);
         console.info('Window height: '+ topWindow.windowRect.height);
       })
       .catch((error)=>{
          console.error('Failed to obtain the window size. Cause: '+JSON.stringify(error));
       })
   }
  ```

  > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
  > 通过窗口尺寸调整显示更加“可靠”，因为顶部状态栏、三键导航等可能占据部分屏幕空间，另外部分设备上的应用可能以窗口形式显示。
