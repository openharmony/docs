# Image Transformation

Image processing refers to a series of operations performed on the pixel map, such as obtaining image information, cropping, scaling, translating, rotating, flipping, setting opacity, and reading and writing pixel data. These operations can be classified into image transformation and [pixel map operation](image-pixelmap-operation.md). This topic describes the image transformation operations that you can perform.

## How to Develop

Read [Image](../reference/apis/js-apis-image.md#pixelmap7) for APIs related to image transformation.

1. Complete [image decoding](image-decoding.md#how-to-develop) and obtain a **PixelMap** object.

2. Obtain image information.
     
   ```
   // Obtain the image size.
   pixelMap.getImageInfo().then( info => {
     console.info('info.width = ' + info.size.width);
     console.info('info.height = ' + info.size.height);
   }).catch((err) => {
     console.error("Failed to obtain the image pixel map information.And the error is: " + err);
   });
   ```

3. Perform image transformation.
   
   Original image:

     ![Original drawing](figures/original-drawing.jpeg)
   - Crop the image.
       
     ```
     // x: x-axis coordinate of the start point for cropping (0).
     // y: y-axis coordinate of the start point for cropping (0).
     // height: height after cropping (400), cropping from top to bottom.
     // width: width after cropping (400), cropping from left to right.
     pixelMap.crop({x: 0, y: 0, size: { height: 400, width: 400 } });
     ```
   
     ![cropping](figures/cropping.jpeg)
   
   - Scale the image.
       
     ```
     // The width of the image after scaling is 0.5 of the original width.
     // The height of the image after scaling is 0.5 of the original height.
     pixelMap.scale(0.5, 0.5);
     ```
   
     ![zoom](figures/zoom.jpeg)
   
   - Translate the image.
       
     ```
     // Translate the image by 100 units downwards.
     // Translate the image by 100 units to the right.
     pixelMap.translate(100, 100);
     ```
   
     ![offsets](figures/offsets.jpeg)
   
   - Rotate the image.
       
     ```
     // Rate the image clockwise by 90°.
     pixelMap.rotate(90);
     ```
   
     ![rotate](figures/rotate.jpeg)
   
   - Flip the image.
       
     ```
     // Flip the image vertically.
     pixelMap.flip(false, true);
     ```
   
     ![Vertical Flip](figures/vertical-flip.jpeg)
   
       
     ```
     // Flip the image horizontally.
     pixelMap.flip(true, false);
     ```
   
     ![Horizontal Flip](figures/horizontal-flip.jpeg)
   
   - Set the opacity of the image.
       
     ```
     // Set the opacity to 0.5.
     pixelMap.opacity(0.5);
     ```
   
     ![Transparency](figures/transparency.png)
