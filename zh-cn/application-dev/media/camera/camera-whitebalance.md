# 白平衡设置(ArkTS)
<!--Kit: Camera Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @qano-->
<!--Designer: @leo_ysl-->
<!--Tester: @xchaosioda-->
<!--Adviser: @zengyawen-->

从API version 20开始，支持设置白平衡效果。白平衡是相机的色彩校正技术，通过设置白平衡，使照片产生不同的效果。目前白平衡效果支持：拍照（PhotoSession）、录像（VideoSession）和安全相机模式（SecureSession）。

## 开发步骤

详细的API说明请参考[Camera](../../reference/apis-camera-kit/arkts-apis-camera.md)。

1. 导入camera接口，接口中提供相机相关的属性和方法。

    ```ts
    import { camera } from '@kit.CameraKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 白平衡的设置提供两种方法。

   - 方法一：通过[isWhiteBalanceModeSupported](../../reference/apis-camera-kit/arkts-apis-camera-WhiteBalanceQuery.md#iswhitebalancemodesupported20)判断是否支持该白平衡模式。再通过[setWhiteBalanceMode](../../reference/apis-camera-kit/arkts-apis-camera-WhiteBalance.md#setwhitebalancemode20)和[getWhiteBalanceMode](../../reference/apis-camera-kit/arkts-apis-camera-WhiteBalance.md#getwhitebalancemode20)分别设置和查看白平衡模式（只能查看当前已设置的白平衡模式）。该接口提供白平衡模式设置，目前包括：自动，手动，阴天、白炽光、荧光和日光。当同时设置白平衡模式和设置白平衡值时，仅可生效一种，默认白平衡模式优先生效。
      ```ts
      function isWhiteBalanceModeSupported(session: camera.PhotoSession | camera.VideoSession): boolean {
         let status: boolean = false;
         let whiteBalanceMode: camera.WhiteBalanceMode | undefined = undefined;
         try {
            let mode: camera.WhiteBalanceMode = camera.WhiteBalanceMode.DAYLIGHT;
            status = session.isWhiteBalanceModeSupported(mode);
            if(status){
            session.setWhiteBalanceMode(mode);
            }
            whiteBalanceMode = session.getWhiteBalanceMode();
         } catch (error) {
         let err = error as BusinessError;
         console.error(`The isWhiteBalanceModeSupported call failed. error code: ${err.code}`);
         }
         return status;
      }
      ```

   - 方法二：通过[getWhiteBalanceRange](../../reference/apis-camera-kit/arkts-apis-camera-WhiteBalanceQuery.md#getwhitebalancerange20)接口，获取当前设备支持的白平衡值范围。再通过[setWhiteBalance](../../reference/apis-camera-kit/arkts-apis-camera-WhiteBalance.md#setwhitebalance20)和[getWhiteBalance](../../reference/apis-camera-kit/arkts-apis-camera-WhiteBalance.md#getwhitebalance20)分别设置和查看白平衡值（只能查看当前已设置的白平衡值）。
      ```ts
      function getWhiteBalanceRange(session: camera.PhotoSession | camera.VideoSession): Array<number> {
         let range: Array<number> = [];
         try {
            range = session.getWhiteBalanceRange();
            let whiteBalance: number = 3000;
            if(whiteBalance > range[0] && whiteBalance < range[1]){
            session.setWhiteBalance(whiteBalance);
            }
            whiteBalance = session.getWhiteBalance();
         } catch (error) {
           let err = error as BusinessError;
           console.error(`The getWhiteBalanceRange call failed. error code: ${err.code}`);
         }
         return range;
      }
      ```
