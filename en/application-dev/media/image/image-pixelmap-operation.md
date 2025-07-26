# Using PixelMap for PixelMap Operations

To process a certain area in an image, you can perform PixelMap operations, which are usually used to beautify the image.

As shown in the figure below, the pixel data of a rectangle in an image is read, modified, and then written back to the corresponding area of the original image.

**Figure 1** PixelMap operation

![PixelMap operation](figures/bitmap-operation.png)

## How to Develop

Read the [API reference](../../reference/apis-image-kit/arkts-apis-image-PixelMap.md) for APIs related to PixelMap operations.

1. Complete [image decoding](image-decoding.md) and obtain a PixelMap object.

2. Obtain information from the PixelMap object.

   ```ts
   import { image } from '@kit.ImageKit';
   // Obtain the total number of bytes of this PixelMap object.
   let pixelBytesNumber : number = pixelMap.getPixelBytesNumber();
   // Obtain the number of bytes per row of this PixelMap object.
   let rowBytes : number = pixelMap.getBytesNumberPerRow();
   // Obtain the pixel density of this PixelMap object. Pixel density refers to the number of pixels per inch of an image. A larger value of the pixel density indicates a finer image.
   let density : number = pixelMap.getDensity();
   ```

3. Read and modify the pixel data of the target area, and write the modified data back to the original image.
   > **NOTE**
   >
   > To prevent issues with the PixelMap due to inconsistent pixel formats, you are advised to use **readPixelsToBuffer** with **writeBufferToPixels** and **readPixels** with **writePixels** in corresponding pairs.

   ```ts
   import { BusinessError } from '@kit.BasicServicesKit';
   // Scenario 1: Read and modify data of the entire image.
   // Read the pixel data of the PixelMap based on the PixelMap's pixel format and write the data to the buffer.
   const buffer = new ArrayBuffer(pixelBytesNumber);
   pixelMap.readPixelsToBuffer(buffer).then(() => {
     console.info('Succeeded in reading image pixel data.');
   }).catch((error : BusinessError) => {
     console.error('Failed to read image pixel data. The error is: ' + error);
   })
   // Read the pixel data in the buffer based on the PixelMap's pixel format and write the data to the PixelMap.
   pixelMap.writeBufferToPixels(buffer).then(() => {
     console.info('Succeeded in writing image pixel data.');
   }).catch((error : BusinessError) => {
     console.error('Failed to write image pixel data. The error is: ' + error);
   })

   // Scenario 2: Read and modify image data in a specified area.
   // Read the pixel data in the area specified by PositionArea.region in the PixelMap in the BGRA_8888 format and write the data to the PositionArea.pixels buffer.
   const area : image.PositionArea = {
     pixels: new ArrayBuffer(8),
     offset: 0,
     stride: 8,
     region: { size: { height: 1, width: 2 }, x: 0, y: 0 }
   }
   pixelMap.readPixels(area).then(() => {
     console.info('Succeeded in reading the image data in the area.');
   }).catch((error : BusinessError) => {
     console.error('Failed to read the image data in the area. The error is: ' + error);
   })
   // Read the pixel data in the PositionArea.pixels buffer in the BGRA_8888 format and write the data to the area specified by PositionArea.region in the PixelMap.
   pixelMap.writePixels(area).then(() => {
     console.info('Succeeded in writing the image data in the area.');
   }).catch((error : BusinessError) => {
     console.error('Failed to write the image data in the area. The error is: ' + error);
   })
   ```

## Development Example: Cloning (Deep Copying) a PixelMap

1. Complete [image decoding](image-decoding.md) and obtain a PixelMap object.

2. Clone (deep copy) this PixelMap object to obtain a new PixelMap.
   > **NOTE**
   > 
   > When creating a PixelMap, you must set **srcPixelFormat** to the pixel format of the original PixelMap. Otherwise, the new PixelMap is abnormal.

      ```ts
      /**
       * Clone (deep copy) a PixelMap.
       *
       * @param pixelMap - PixelMap to clone.
       * @param desiredPixelFormat - Pixel format of the new PixelMap. If this parameter is not specified, the pixel format of the current PixelMap is used.
       * @return Returns a new PixelMap.
       **/
      clonePixelMap(pixelMap: PixelMap, desiredPixelFormat?: image.PixelMapFormat): PixelMap {
        // Obtain the image information of the current PixelMap.
        const imageInfo = pixelMap.getImageInfoSync();
        // Read the pixel data of the PixelMap and write the data to a buffer array based on the PixelMap's pixel format.
        const buffer = new ArrayBuffer(pixelMap.getPixelBytesNumber());
        pixelMap.readPixelsToBufferSync(buffer);
        // Generate initialization options based on the image information of the current PixelMap.
        const options: image.InitializationOptions = {
          // Pixel format of the current PixelMap.
          srcPixelFormat: imageInfo.pixelFormat,
          // Pixel format of the new PixelMap.
          pixelFormat: desiredPixelFormat ?? imageInfo.pixelFormat,
          // Size of the current PixelMap.
          size: imageInfo.size
        };
        // Generate a new PixelMap based on the initialization options and buffer array.
        return image.createPixelMapSync(buffer, options);
      }
      ```

<!--RP1-->
<!--RP1End-->
