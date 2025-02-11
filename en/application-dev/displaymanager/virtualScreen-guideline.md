# Creating and Using a Virtual Screen (ArkTS) (for System Applications Only)

## When to Use

A virtual screen serves as a conceptual representation in the system. It allows an application to create a virtual screen without depending on a physical screen. It provides a rendering target through the surface, allowing applications to render content such as images and videos onto the virtual screen.

## Available APIs

The following lists the common APIs available for the virtual screen. For details about the APIs, see [@ohos.screen (Screen) (System API)](../reference/apis-arkui/js-apis-screen-sys.md).

| API                                                      | Description                                        |
| ------------------------------------------------------------ | -------------------------------------------- |
| createVirtualScreen(options:VirtualScreenOption): Promise&lt;Screen&gt; | Creates a virtual screen. This API uses a promise to return the result.         |
| setVirtualScreenSurface(screenId:number, surfaceId: string): Promise&lt;void&gt; | Sets the surface for a virtual screen. This API uses a promise to return the result.|
| makeMirror(mainScreen:number, mirrorScreen:Array&lt;number&gt;): Promise&lt;number&gt; | Sets screen mirroring. This API uses a promise to return the result. |
| stopMirror(mirrorScreen:Array&lt;number&gt;): Promise&lt;void&gt; | Stops screen mirroring. This API uses a promise to return the result.   |
| destroyVirtualScreen(screenId:number): Promise&lt;void&gt;   | Destroys a virtual screen. This API uses a promise to return the result.         |

## How to Develop

1. Create a virtual screen.

   - Define the parameters used for creating the virtual screen.

   - Call **createVirtualScreen()** to create the virtual screen.

   The ohos.permission.CAPTURE_SCREEN permission is required for calling **createVirtualScreen()**. For details, see [Requesting Restricted Permissions](../security/AccessToken/declare-permissions-in-acl.md).

2. Bind the surface ID of the rendering target to the virtual screen.

   To enable the virtual screen to accurately present the intended content, bind the surface ID of the rendering target to the virtual screen. The operations are as follows:

   - Call **getXComponentSurfaceId()** to obtain the surface ID. As a unique identifier, the surface ID carries important data related to the screen's image properties. It facilitates the acquisition and adjustable configuration of the image properties such as resolution and pixel format.

   - Call **setVirtualScreenSurface()** to associate the obtained surface ID with the virtual screen, ensuring that the virtual screen can properly receive and process the associated image data.

3. Call **makeMirror()** to create a mirror of the physical screen and project it onto the virtual screen.

   After the virtual screen is created, the application can call **makeMirror()** to start mirroring of the physical screen based on service requirements. This API duplicates the content currently displayed on the physical screen and projects it onto the virtual screen created earlier, facilitating real-time synchronized viewing between the two screens.

4. Stop mirroring.

   If synchronized mirroring between the physical and virtual screens is no longer needed, call **stopMirror()** to stop mirroring. This operation terminates the mirroring from the physical screen to the virtual screen, restoring the virtual screen to an autonomous state.

5. Destroy the virtual screen.

   Upon completion of the service process and when the virtual screen is no longer needed, release the related resources in a timely manner to prevent memory leaks and unnecessary consumption of system resources. You can call **destroyVirtualScreen()** to destroy the virtual screen securely and effectively, thereby releasing the system resources occupied by the virtual screen.

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { screen } from '@kit.ArkUI';

@Entry
@Component
struct VirtualScreen {
  xComponentController: XComponentController = new XComponentController();

  build() {
    RelativeContainer() {
      Column() {
        XComponent({
          type: XComponentType.SURFACE,
          controller: this.xComponentController
        })
      }
      Button('Virtual screen')
        .onClick(() => {
          // screenVirtualScreen is used to store the created virtual screen object.
          let screenVirtualScreen: screen.Screen | null = null;
          class VirtualScreenOption {
            name: string = '';
            width: number = 0;
            height: number = 0;
            density: number = 0;
            surfaceId: string = '';
          }
          // option defines the parameters required for creating the virtual screen.
          let option: VirtualScreenOption = {
            name: 'screen01',
            width: 1080,
            height: 2340,
            density: 2,
            surfaceId: ''
          };
          // Create a virtual screen.
          screen.createVirtualScreen(option, (err: BusinessError, data: screen.Screen) => {
            const errCode: number = err.code;
            if (errCode) {
              console.error(`Failed to create the virtual screen. Code:${err.code},message is ${err.message}`);
              return;
            }
            screenVirtualScreen = data;
            console.info('Succeeded in creating the virtual screen. Data: ' + JSON.stringify(data));
            // Obtain the surface ID.
            let surfaceId = this.xComponentController.getXComponentSurfaceId();
            screen.setVirtualScreenSurface(screenVirtualScreen.id, surfaceId, (err: BusinessError) => {
              const errCode: number = err.code;
              if (errCode) {
                console.error(`Failed to set the surface for the virtual screen. Code:${err.code},message is ${err.message}`);
                return;
              }
              console.info('Succeeded in setting the surface for the virtual screen.');
            });
            let mirrorScreenIds: Array<number> = [screenVirtualScreen.id];
            // Obtain all screens.
            screen.getAllScreens((err: BusinessError, data: Array<screen.Screen>) => {
              const errCode: number = err.code;
              if (errCode) {
                console.error(`Failed to get all screens. Code:${err.code},message is ${err.message}`);
                return;
              }
              // Call makeMirror to create a mirror for the physical screen and project it to the virtual screen.
              let mainScreenId = data.find(item => item.sourceMode === 0)?.id;
              screen.makeMirror(mainScreenId, mirrorScreenIds, (err: BusinessError, data: number) => {
                const errCode: number = err.code;
                if (errCode) {
                  console.error(`Failed to set screen mirroring. Code:${err.code},message is ${err.message}`);
                  return;
                }
                console.info('Succeeded in setting screen mirroring. Data: ' + JSON.stringify(data));
              });
              // Stop mirroring.
              screen.stopMirror(mirrorScreenIds, (err: BusinessError) => {
                const errCode: number = err.code;
                if (errCode) {
                  console.error(`Failed to stop mirror screens. Code:${err.code},message is ${err.message}`);
                  return;
                }
                console.info('Succeeded in stopping mirror screens.');
              });
              // Destroy the virtual screen.
              screen.destroyVirtualScreen(mirrorScreenIds[0], (err: BusinessError) => {
                const errCode: number = err.code;
                if (errCode) {
                  console.error(`Failed to destroy the virtual screen. Code:${err.code},message is ${err.message}`);
                  return;
                }
                console.info('Succeeded in destroying the virtual screen.');
              });
            });
          });
        })
    }
    .height('100%')
    .width('100%')
  }
}
```
