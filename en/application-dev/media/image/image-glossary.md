# Glossary

<!--Kit: Image Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @aulight02-->
<!--Designer: @XiaoYao555-->
<!--Tester: @xchaosioda-->
<!--Adviser: @w_Machine_cc-->
<!-- md-trans-meta sourceCommit=5aca59801d0a2d1a34ff2df14b943216a04ac714 translatedAt=2026-08-11T01:43:57.008Z pushedAt=2026-08-11T07:17:14.458Z -->

## A

### Animated Image

A picture resource formed by playing multiple image frames in chronological order.

### Auxiliary Image

Additional image data stored together with the main image in a multi-image Picture object. It is typically not used for standalone display, but serves as auxiliary data in image processing workflows such as HDR compositing, depth information extraction, or original image recovery.

## C

### Color Space Conversion

The process of converting the color representation of an image between different color spaces, such as sRGB and Display P3, to meet the color management requirements of various devices or display pipelines.

## D

### Depth Map

An auxiliary image that records pixel distance or depth information, which can be used for processing that depends on scene depth, such as 3D reconstruction and background separation.

### Digital Negative (DNG)

An open RAW image file format introduced by Adobe, used to store raw image data captured by camera sensors and shooting-related metadata. It serves as a universal format for processing RAW images across different software.

### Direct Memory Access (DMA) Memory

A type of image buffer memory that can be directly accessed by the decoder, GPU, or display pipeline, used to reduce data copy and texture upload overhead in the image display pipeline.

### Downsampling Decoding

A decoding method where the decoder outputs a smaller image at an appropriate sampling rate based on a specified desired output size. It is used in scenarios such as large image preview where reduced memory usage and decoding time are required.

### Dynamic Range

The range of luminance information that an image can represent. The decoding and processing pipeline can output HDR or SDR results based on the dynamic range policy.

## E

### Exchangeable Image File Format (Exif)

An image metadata format that records photo properties and shooting information, which may include fields such as capture time, orientation, focal length, and geographic location.

### Extensible Metadata Platform (XMP)

An extensible format for describing and exchanging image metadata, capable of recording structured information such as author, copyright, and edit history.

## F

### Filter Chain

An image effect processing pipeline that combines multiple filters in sequence, used to superimpose various image processing effects within a single editing workflow.

### Fragment Map

An auxiliary image that records the areas in the original image occluded by a watermark. It can be used in post-processing scenarios such as watermark removal and original image restoration.

## G

### Gain Map

An auxiliary image that represents luminance gain information. Images with GainMap can generate display results with a higher dynamic range on HDR-capable devices while remaining compatible with SDR main images.

## H

### HDR Dual-layer Image

An image form that expresses the HDR effect through a main image and auxiliary data such as a GainMap. It can be composited into a single-layer HDR image as needed during processing.

### HDR Single-layer Image

An image form that carries HDR display information in a single image layer. It can be composited from an HDR dual-layer image, and can also be split into data such as a primary image and a GainMap.

### High Dynamic Range (HDR)

An image representation method for high dynamic range, capable of recording richer luminance levels and color information. The display effect is influenced by image data, device capabilities, and the processing pipeline.

### High Efficiency Image File Format (HEIF)

A container-based efficient image file format used to encapsulate image data and related information. Compared with JPEG, HEIF generally reduces file size while maintaining comparable image quality, though its compatibility depends on device and software support.

### HEIF Sequence (HEIFS)

The HEIF sequence image format, typically using the `.heifs` extension, can represent multiple frames of images and their playback timing information.

## I

### Image Decoding

The process of parsing an image file in a supported format and converting it into an image object such as a PixelMap or Picture for subsequent display or image processing.

### Image Encoding

The process of packaging processed image data into a file of a specified image format for storage, transmission, or format conversion.

### Image Metadata

A collection of data that describes image properties, shooting information, format information, or processing auxiliary information. It can be read, modified, or used in subsequent image processing.

## L

### Linear Map

An auxiliary image used for visual effect enhancement and color post-processing.

## P

### Picture

A multi-image object in Image Kit. It consists of a primary image, auxiliary images, and metadata, and supports operations such as obtaining the primary image, auxiliary images, metadata, and compositing HDR images.

### PixelMap

An object in Image Kit that holds the pixel data of an image. It allows reading or writing pixel data and supports image processing operations such as cropping, scaling, rotating, and mirroring.

### Pixel Format

A format that describes how pixel data is arranged in memory and how color components are represented. It affects memory usage, transparency capability, and the decoding processing path.

## R

### RAW Data

Image data that directly retains the raw information from the image sensor without lossy compression, suitable for scenarios requiring custom algorithms and high-quality post-processing.

### Region Decoding

A method that decodes only a specified rectangular area of the original image, suitable for scenarios where only a portion of the image needs to be viewed or processed.

## S

### Standard Dynamic Range (SDR)

A standard dynamic range image representation method. Its expressible luminance range is lower than that of HDR, making it suitable for ordinary display devices and conventional image processing scenarios.

### Stride

The storage width of each row of pixel data for an image in memory. Its value may be larger than the actual image width due to hardware alignment and memory allocation requirements, and it must be used correctly when processing pixel buffers.

## Y

### YUV Pixel Format

A pixel format that represents an image using luminance and chrominance components. Formats such as NV12 and NV21 described in the documentation can reduce memory usage in preview and full-image display scenarios.