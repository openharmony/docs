# Introduction to Image Kit

Image development is the process of parsing, processing, and constructing image pixel data to achieve the required image effect. Image development mainly involves image decoding, processing, and encoding.

Before image development, be familiar with the following basic concepts:

- Image decoding
  
  The operation of decoding an archived image in a supported format into a PixelMap for image display or processing.

- PixelMap
  
  A bitmap that is not compressed after being decoded. It is used for image display or processing.

- Picture
  
  An object that includes a main picture and auxiliary picture. It is used for picture display or processing.

- Image processing
  
  A series of operations on the PixelMap, such as rotation, scaling, opacity setting, image information obtaining, and pixel data reading and writing. The origin of the coordinate system is at the upper left corner.

- Image encoding
  
  The operation of encoding a PixelMap into an archived image in different formats for subsequent processing, such as storage and transmission.

The figure below illustrates the image development process.

**Figure 1** Image development process

![Image development process](figures/image-development-process.png)

1. Image retrieval: Obtain a raw image through the application sandbox.

2. Instance creation: Create an **ImageSource** instance, which is the source class of decoded images and is used to obtain or modify image information.

3. [Image decoding](image-decoding.md): Decode the image source to generate a PixelMap.

4. [Image processing](image-transformation.md): Process the PixelMap by modifying the image attributes to implement image rotation, scaling, and cropping, and then use the [Image component](../../ui/arkts-graphics-display.md) to display the image.

5. [Image encoding](image-encoding.md): Use the **ImagePacker** class to compress and encode the PixelMap or image source to generate a new image.

In addition to the preceding basic image development capabilities, OpenHarmony provides the [image tool](image-tool.md) to ease your development.

## Highlights

Image Kit supports multiple image formats and uses efficient algorithms and optimization policies to speed up image processing.

## Constraints

- **Constraints on read and write permissions:**

  During image processing, applications may need to request the read and write permissions from users on images.

- **Selecting appropriate C APIs**
  
  The image framework provides two sets of C APIs: [C APIs dependent on JS objects](../../reference/apis-image-kit/image.md) and [C APIs independent of JS objects](../../reference/apis-image-kit/_image___native_module.md).
  - C APIs that depend on JS objects
  
    These APIs are used to encode and decode images, receive images, and process image data. Example code related to these functionalities is provided in [Using Image to Decode Images](image-decoding-native.md). You can find these APIs in [Image](../../reference/apis-image-kit/image.md). These APIs are introduced prior to API version 11, and no additional features will be included in later versions.

  - C APIs independent of JS objects
  
    In addition to the functionalities mentioned above, these APIs implements new features such as picture encoding and decoding. For details about the development guide, see [Using Image_NativeModule to Decode Images](image-source-c.md). You can find these APIs in [Image_NativeModule](../../reference/apis-image-kit/_image___native_module.md). These APIs are available since API version 12 and are expected to keep evolving. You are encouraged to use them.

  > **NOTE**
  >
  > You are not advised to use both sets of C APIs in your code. It may cause compatibility issues in some scenarios.

## Related Kits

The image framework provides the image encoding and decoding capabilities for the **Image** component and the Gallery application. The decoding result can be sent to the [**Image** component](../../ui/arkts-graphics-display.md) for display.

