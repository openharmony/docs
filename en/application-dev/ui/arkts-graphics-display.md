# Displaying Images


More often than not, you may need to display images in applications, for example, logos in buttons, online images, and local images. To display images in applications, you need to use the **\<Image>** component, which supports multiple image formats, including PNG, JPG, BMP, SVG, and GIF. For details, see [Image](../reference/arkui-ts/ts-basic-components-image.md).


You can call the API in the following format to create an image:



```ts
Image(src: string | Resource | media.PixelMap)
```


Obtains images from the image data source. Local images and online images can be rendered and displayed. In the preceding information, src indicates the data source of the image. For details about how to load the data source, see [Loading Image Resources](#loading-image-resources).


## Loading Image Resources

The **\<Image>** component supports two types of images: archived images and multimedia pixel images.


### Archived Type Data Source

Data sources of the archived type can be classified into local resources, online resources, Resource objects, media library datashare resources, and Base64 resources.

- Local resources
  Create a folder and place the local image in any position in the ets folder.

  The **\<Image>** component imports the local image path to display the image. The root directory is the ets folder.

  ```ts
  Image('images/view.jpg')
  .width(200)
  ```

- Network resource
  To use network images, you need to apply for the ohos.permission.INTERNET permission. For details, see [Applying for Permissions](../security/accesstoken-guidelines.md). In this case, the src parameter of the Image component is the link of the network image.

  ```ts
  Image('https://www.example.com/example.JPG') // Replace the URL with the actual URL.
  ```

- Resource
  The Resource format can be used to import images across bundles or modules. All images in the **resources** folder can be read and converted to the resource format through **$r**.

  **Figure 1** Resouces 

  ![image-resource](figures/image-resource.jpg)

  Method:

  ```
  Image($r('app.media.icon'))
  ```

  You can also place the images in the **rawfile** folder.

  **Figure 2** rawfile 

 ![image-rawfile](figures/image-rawfile.jpg)

  Method:

  ```
  Image($rawfile('snap'))
  ```

- media library datashare
  The value is a string that supports the **datashare://** path prefix, which is used to access the image path provided by the media library.

  1. Call the API in to obtain the photo URL in the gallery.
      ​    
      ```ts
      import picker from '@ohos.file.picker';

      @Entry
      @Component
      struct Index {
        private imgDatas: string[] = [];
        // Obtain the photo URL set.
        async getAllImg() {
          let photoPicker = new picker.PhotoViewPicker();
          let result = new Array<string>();
          try {
            let PhotoSelectOptions = new picker.PhotoSelectOptions();
            PhotoSelectOptions.MIMEType = picker.PhotoViewMIMETypes.IMAGE_TYPE;
            PhotoSelectOptions.maxSelectNumber = 5;
            let photoPicker = new picker.PhotoViewPicker();
            photoPicker.select(PhotoSelectOptions).then((PhotoSelectResult) => {
              result = PhotoSelectResult.photoUris;
            }).catch((err) => {
              console.error(`PhotoViewPicker.select failed with. Code: ${err.code}, message: ${err.message}`);
            });
          } catch (err) {
            console.error(`PhotoViewPicker failed with. Code: ${err.code}, message: ${err.message}`);    }
          return result;
        }

        // Call the preceding function in aboutToAppear to obtain the URLs of all images in the gallery and store the URLs in imgDatas.
        async aboutToAppear() {
          this.imgDatas = await this.getAllImg();
        }
        // Use the URL of imgDatas to load the image.
        build() {
          Grid() {
            ForEach(this.imgDatas, item => {
              GridItem() {
                Image(item)
                  .width(200)
              }
            }, item => JSON.stringify(item))
          }
        }
      }
      ```
  2. The format of the URL obtained from the media library is as follows:
      ​    
      ```ts
      Image('datashare:///media/5')
      .width(200)
      ```

- base64
  The path format is data:image/[png|jpeg|bmp|webp];base64,[base64 data], in which [base64 data] indicates Base64 string data.

  Base64 character strings can be used to store pixel data of images and are widely used on web pages.


### Multimedia Pixel Map

PixelMap is the pixel image after image decoding. For details, see [Image](../media/image.md). In the following example, the data returned by the loaded network image is decoded into the PixelMap format and then displayed on the Image component,

1. Creates a PixelMap state variable.

   ```ts
   @State image: PixelMap = undefined;
   ```

2. Referencing multimedia.
   Requests network images and decodes and encodes PixelMap.

   1. Reference the network permission and media library permission.
       ​    
       ```ts
       import http from '@ohos.net.http';
       import ResponseCode from '@ohos.net.http';
       import image from '@ohos.multimedia.image';
       ```
   2. Enter the network image address.
       ​    
       ```ts
       http.createHttp().request("https://www.example.com/xxx.png",
         (error, data) => {
           if (error){
             console.error(`http reqeust failed with. Code: ${error.code}, message: ${error.message}`);
           } else {
           }
         }
       )
       ```
   3. Encode and transcodes the data returned by the network address to the pixelMap image format.
       ​    
       ```ts
       let code = data.responseCode;
       if(ResponseCode.ResponseCode.OK === code) {
         let imageSource = image.createImageSource(data.result);
         let options = {
           alphaType: 0,                     // Alpha type
           editable: false,                  // Whether the image is editable
           pixelFormat: 3,                   // Pixel format
           scaleMode: 1,                     // Scale mode
           size: {height: 100, width: 100}
          }  // Image size.
           imageSource.createPixelMap(options).then((pixelMap) => {
           this.image = pixelMap
       })
       ```
   4. Show pictures
       ​    
       ```ts
       Button ("Get Online Image")
         .onClick(() => {
           this.httpRequest()
         })
       Image(this.image).height(100).width(100)
       ```


## Display Vector Diagram

The **\<Image>** component can display vector images in SVG format. The supported SVG labels are svg, rect, circle, ellipse, path, line, polyline, polygon, and animate.

You can use the fillColor attribute to change the drawing color of an SVG image.


```ts
Image($r('app.media.cloud')).width(50)
.fillColor(Color.Blue) 
```

  **Figure 3** Original image 
![screenshot_20230223_141141](figures/screenshot_20230223_141141.png)

  **Figure 4** SVG image after the drawing color is set 
![screenshot_20230223_141404](figures/screenshot_20230223_141404.png)


## Adding Attributes

Setting attributes for the **\<Image>** component can make the image display more flexible and achieve some customized effects. The following are examples of common attributes. For details about attributes, see [Image](../reference/arkui-ts/ts-basic-components-image.md).


### Setting the Image Scale Type

The **objectFit** attribute is used to scale an image to a box whose height and width are determined.


```ts
@Entry
@Component
struct MyComponent {
  scroller: Scroller = new Scroller()

  build() {
    Scroll(this.scroller) {
      Row() {
        Image($r('app.media.img_2')).width(200).height(150)
          .border({ width: 1 })
          .objectFit(ImageFit.Contain).margin(15) // Zoom out or zoom in the image based on the aspect ratio so that the image is completely displayed within the display boundary.
          .overlay('Contain', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.ic_img_2')).width(200).height(150)
          .border({ width: 1 })
          .objectFit(ImageFit.Cover).margin(15)
          // The image is scaled with its aspect ratio retained for both sides to be greater than or equal to the display boundaries.
          .overlay('Cover', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.img_2')).width(200).height(150)
          .border({ width: 1 })
            // The image is scaled automatically to fit the display area.
          .objectFit(ImageFit.Auto).margin(15)
          .overlay('Auto', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      }
      Row() {
        Image($r('app.media.img_2')).width(200).height(150)
          .border({ width: 1 })
          .objectFit(ImageFit.Fill).margin(15)
          // The image is scaled to fill the display area, and its aspect ratio is not retained.
          .overlay('Fill', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.img_2')).width(200).height(150)
          .border({ width: 1 })
          // The image content is displayed with its aspect ratio retained. The size is smaller than or equal to the original size.
          .objectFit(ImageFit.ScaleDown).margin(15)
          .overlay('ScaleDown', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
        Image($r('app.media.img_2')).width(200).height(150)
          .border({ width: 1 })
          // The original size is retained.
          .objectFit(ImageFit.None).margin(15)
          .overlay('None', { align: Alignment.Bottom, offset: { x: 0, y: 20 } })
      }
    }
  }
}
```

![en-us_image_0000001511421240](figures/en-us_image_0000001511421240.png)


### Synchronously Loading Images

Generally, the image loading process is performed asynchronously to avoid blocking the main thread and affecting UI interaction. In certain cases, however, the picture flickers when it is refreshed. In this case, you can use the **syncLoad** attribute to load the picture synchronously to avoid flickering. You are not advised to use this function when the image loading takes a long time. Otherwise, the page cannot respond.


```ts
Image($r('app.media.icon'))
  .syncLoad(true)
```


## Invoking Events

After the **onComplete** event is bound to the Image component, necessary information about the image can be obtained after the image is successfully loaded. If the image fails to be loaded, you can also bind the onError callback function to obtain the result.


```ts
@Entry
@Component
struct MyComponent {
  @State widthValue: number = 0
  @State heightValue: number = 0
  @State componentWidth: number = 0
  @State componentHeight: number = 0

  build() {
    Column() {
      Row() {
        Image($r('app.media.ic_img_2'))
          .width(200)
          .height(150)
          .margin(15)
          .onComplete((msg: {
            width: number,
            height: number,
            componentWidth: number,
            componentHeight: number
          }) => {
            this.widthValue = msg.width
            this.heightValue = msg.height
            this.componentWidth = msg.componentWidth
            this.componentHeight = msg.componentHeight
          })
            // If the image fails to be obtained, print the result.
          .onError(() => {
            console.info('load image fail')
          })
          .overlay('\nwidth: ' + String(this.widthValue) + ', height: ' + String(this.heightValue) + '\ncomponentWidth: ' + String(this.componentWidth) + '\ncomponentHeight: ' + String(this.componentHeight), {
            align: Alignment.Bottom,
            offset: { x: 0, y: 60 }
          })
      }
    }
  }
}
```


![en-us_image_0000001511740460](figures/en-us_image_0000001511740460.png)
