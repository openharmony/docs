# Image Development

## When to Use

You can use image development APIs to decode images into pixel maps and encode the pixel maps into a supported format.

## Available APIs

For details about the APIs, see [Image Processing](../reference/apis/js-apis-image.md).

## How to Develop

### Full-Process Scenario

The full process includes creating an instance, reading image information, reading and writing pixel maps, updating data, packaging pixels, and releasing resources.

```js
const color = new ArrayBuffer(96); // Create a buffer to store image pixel data.
let opts = { alphaType: 0, editable: true, pixelFormat: 4, scaleMode: 1, size: { height: 2, width: 3 } } // Image pixel data.

// Create a PixelMap object.
const color = new ArrayBuffer(96);
let opts = { alphaType: 0, editable: true, pixelFormat: 4, scaleMode: 1, size: { height: 2, width: 3 } }
        image.createPixelMap(color, opts, pixelmap => {
            expect(pixelmap !== null).assertTrue();
            console.info('TC_001-1 success');
            done();
        })
// Read pixels.
pixelmap.readPixels(area,(data) => {
 	if(data !== null) {
		var bufferArr = new Uint8Array(area.pixels);
        var res = true;
        for (var i = 0; i < bufferArr.length; i++) {
			console.info('TC_021-1 buffer ' + bufferArr[i]);
				if(res) {
					if(bufferArr[i] == 0) {
						res = false;
                        console.info('TC_021-1 Success');
                        expect(true).assertTrue();
                        done();
                        break;
                        }
                    }
                }
 
// Store pixels.
const readBuffer = new ArrayBuffer(96);
pixelmap.readPixelsToBuffer(readBuffer,() => {
var bufferArr = new Uint8Array(readBuffer);
var res = true;
for (var i = 0; i < bufferArr.length; i++) {
    if(res) {
        if (bufferArr[i] !== 0) {
            res = false;
            console.info('TC_020-1 Success');
            expect(true).assertTrue();
            done();
            break;
        }
    }
}
    
// Write pixels.
pixelmap.writePixels(area,() => {
    const readArea = { pixels: new ArrayBuffer(20), offset: 0, stride: 8, region: { size: { height: 1, width: 2 }, x: 0, y: 0 }}
    pixelmap.readPixels(readArea,() => {
        var readArr = new Uint8Array(readArea.pixels);
        var res = true;
        for (var i = 0; i < readArr.length; i++) {
            if(res) {
                if (readArr[i] !== 0) {
                    res = false;
                    console.info('TC_022-1 Success');
                    expect(true).assertTrue();
                    done();
                    break;
                }
            }
        }
  
// Write pixels to the buffer.
pixelmap.writeBufferToPixels(writeColor).then(() => {
    const readBuffer = new ArrayBuffer(96);
    pixelmap.readPixelsToBuffer(readBuffer).then (() => {
    	var bufferArr = new Uint8Array(readBuffer);
     	var res = true;
     	for (var i = 0; i < bufferArr.length; i++) {
     		if(res) {
     			if (bufferArr[i] !== i) {
     				res = false;
                    console.info('TC_023 Success');
                    expect(true).assertTrue()
                    done();
                    break;
                }
            }
        }

// Obtain image information.
pixelmap.getImageInfo( imageInfo => {
    if (imageInfo !== null) {
        console.info('TC_024-1 imageInfo is ready');
        expect(imageInfo.size.height == 4).assertTrue();
        expect(imageInfo.size.width == 6).assertTrue();
        expect(imageInfo.pixelFormat == 4).assertTrue();
        done();
    } 
})

// Release the PixelMap object.
pixelmap.release(()=>{
    expect(true).assertTrue();
    console.log('TC_027-1 suc');
    done();
})

// Create an image source (uri).
const imageSourceApi = image.createImageSource(path); // '/data/local/tmp/test.jpg'

// Create an image source (fd).
const imageSourceApi = image.createImageSource(29);

// Create an image source (data).
const data = new ArrayBuffer(96);
const imageSourceApi = image.createImageSource(data);

// Release the image source.
imageSourceApi.release(() => {
    console.info('TC_044-1 Success');
    })
    
// Encode the image.
const imagePackerApi = image.createImagePacker();
imagePackerApi.packing(imageSourceApi, packOpts, data => {
    console.info('TC_062-1 finished');
    expect(data !== null).assertTrue();
    done();
})
 
// Release the ImagePacker object.
imagePackerApi.release();
```

### Decoding Scenario

```js
/data/local/tmp/test.jpg // Set the path for creating an image source.

// Create an image source using a path.
const imageSourceApi = image.createImageSource(path); // '/data/local/tmp/test.jpg'

// Set parameters.
let decodingOptions = {
    sampleSize:1, // Sampling size of the thumbnail.
    editable: true, // Whether the image can be edited.
    desiredSize:{ width:1, height:2}, // Desired output size of the image.
    rotateDegrees:10, // Rotation angle of the image.
    desiredPixelFormat:2, // Decoded pixel format.
    desiredRegion: { size: { height: 1, width: 2 }, x: 0, y: 0 }, // Region of the image to decode.
    index:0// Image sequence number.
    };
    
// Create a pixel map in callback mode.
imageSourceApi.createPixelMap(decodingOptions, pixelmap => {
    console.info('TC_050 createPixelMap ');
    expect(pixelmap !== null ).assertTrue();
    done();
    })
}  

// Create a pixel map in promise mode.
imageSourceApi.createPixelMap().then(pixelmap => {
    console.info('TC_050-11 createPixelMap ');
    expect(pixelmap !== null ).assertTrue();
    done();
})

// Capture error information when an exception occurs during function invoking.
catch(error => {
    console.log('TC_050-11 error: ' + error);
    expect().assertFail();
    done();
})

// Obtain the number of bytes in each line of pixels.
pixelmap.getBytesNumberPerRow( num => {
	console.info('TC_025-1 num is ' + num);
	expect(num == expectNum).assertTrue();
	done();
})

// Obtain the total number of pixel bytes.
pixelmap.getPixelBytesNumber(num => {
    console.info('TC_026-1 num is ' + num);
    expect(num == expectNum).assertTrue();
    done();
})

// Obtain the pixel map information.
pixelmap.getImageInfo( imageInfo => {})
 
// Print the failure information.
console.info('TC_024-1 imageInfo is empty');
expect(false).assertTrue()

// Release the PixelMap object.
pixelmap.release(()=>{
    expect(true).assertTrue();
    console.log('TC_027-1 suc');
    done();
})    

// Capture release failure information.
catch(error => {
    console.log('TC_027-1 error: ' + error);
    expect().assertFail();
    done();
})
```

### Encoding Scenario

```js
/data/local/tmp/test.png // Set the path for creating an image source.

// Set the image source.
const imageSourceApi = image.createImageSource(path); // '/data/local/tmp/test.png'
 
// Print the error message if the image source fails to be created.
if (imageSourceApi == null) {
    console.info('TC_062 create image source failed');
    expect(false).assertTrue();
    done();
}
   
// Create an image packer if the image source is successfully created.
const imagePackerApi = image.createImagePacker();

// Print the error information if the image packer fails to be created.
if (imagePackerApi == null) {
    console.info('TC_062 create image packer failed');
    expect(false).assertTrue();
    done();
}

// Set encoding parameters if the image packer is successfully created.
let packOpts = { format:["image/jpeg"], // The supported encoding format is jpg.
                 quality:98 } // Image quality, which ranges from 0 to 100.

// Encode the image.
imagePackerApi.packing(imageSourceApi, packOpts)
.then( data => {
    console.info('TC_062 finished');
    expect(data !== null).assertTrue();
    done();
})
             
// Release the image packer after the encoding is complete.
imagePackerApi.release();

// Obtain the image source information.
imageSourceApi.getImageInfo(imageInfo => {
    console.info('TC_045 imageInfo');
    expect(imageInfo !== null).assertTrue();
    done();
})

// Update incremental data.
imageSourceIncrementalSApi.updateData(array, false, 0, 10,(error,data )=> {})

```

### Using ImageReceiver

Example scenario: The camera functions as the client to transmit image data to the server.

```js
public async init(surfaceId: any) {

    // (Server code) Create an ImageReceiver object.
    var receiver = image.createImageReceiver(8 * 1024, 8, image.ImageFormat.JPEG, 1);

    // Obtain the surface ID.
    var surfaceId = await receiver.getReceivingSurfaceId();

    // Register a surface listener, which is triggered after the buffer of the surface is ready.
    receiver.on('imageArrival', () => {
        // Obtain the latest buffer of the surface.
        receiver.readNextImage((err, img) => {
            img.getComponent(4, (err, component) => {
                // Consume component.byteBuffer. For example, save the content in the buffer as an image.
		    })
	    })
    })

    // Call a Camera API to transfer the surface ID to the camera, which then obtains the surface based on the surface ID and generates a surface buffer.
}
```
