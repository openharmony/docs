# Interface (MediaSourceLoadingRequest)

> **NOTE**
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The initial APIs of this interface are supported since API version 18.

The MediaSourceLoadingRequest class a loading request object. Applications use this object to obtain the location of the requested resource and to interact with the player for data exchange.

## Modules to Import

```ts
import { media } from '@kit.MediaKit';
```

## Properties

**System capability**: SystemCapability.Multimedia.Media.Core

| Name  | Type   | Read-Only  | Optional  | Description               |
| --------------------------------------------------- | ------------------------------------------------------------ | ---- | ---- | ------------------------------------------------------------ |
| url       | string                        | No  | No  | Resource URL, which is the path to the resource that the application needs to open.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|
| header     | Record<string, string>        | No  | Yes  | HTTP request header. If the header exists, the application should set the header information in the HTTP request when downloading data.<br>**Atomic service API**: This API can be used in atomic services since API version 18.|

## respondData<sup>18+</sup>

respondData(uuid: number, offset: number, buffer: ArrayBuffer): number

Sends data to the player.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| uuid | number | Yes | 	ID for the resource handle.|
| offset | number | Yes | 	Offset of the current media data relative to the start of the resource.|
| buffer | ArrayBuffer | Yes | 	Media data sent to the player.<br>**Note**: Do not transmit irrelevant data, as it can affect normal data parsing and playback.|

**Return value**

| Type          | Description                               |
| -------------- | ----------------------------------- |
| number | Number of bytes received by the server.<br>- A return value less than 0 indicates failure.<br>- A return value of -2 indicates that the player no longer needs the current data, and the client should stop the current read process.<br>- A return value of -3 indicates that the player's buffer is full, and the client should wait for the next read.|

**Example**

```ts
import HashMap from '@ohos.util.HashMap';
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();
let uuid = 1;

let request = requests.get(uuid);
let offset = 0; // Offset of the current media data relative to the start of the resource.
let buf = new ArrayBuffer(0); // Data defined by the application and pushed to the player.
let num = request.respondData(uuid, offset, buf);
```

## respondHeader<sup>18+</sup>

respondHeader(uuid: number, header?: Record<string, string>, redirectUrl?: string): void

Sends response header information to the player. This API must be called before the first call to [respondData](#responddata18).

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| uuid | number | Yes | 	ID for the resource handle.|
| header | Record<string, string> | No | Header information in the HTTP response. The application can intersect the header fields with the fields supported by the underlying layer for parsing or directly pass in all corresponding header information.<br> - The following fields need to be parsed by the underlying player: Transfer-Encoding, Location, Content-Type, Content-Range, Content-Encode, Accept-Ranges, and content-length.|
| redirectUrl | string | No | 	Redirect URL in the HTTP response.|

**Example**

```ts
import HashMap from '@ohos.util.HashMap';
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();
let uuid = 1;

// The application fills this in as needed.
let header:Record<string, string> = {
  'Transfer-Encoding':'xxx',
  'Location' : 'xxx',
  'Content-Type' : 'xxx',
  'Content-Range' : 'xxx',
  'Content-Encode' : 'xxx',
  'Accept-Ranges' : 'xxx',
  'content-length' : 'xxx'
};
let request = requests.get(uuid);
request.respondHeader(uuid, header);
```

## finishLoading<sup>18+</sup>

finishLoading(uuid: number, state: LoadingRequestError): void

Notifies the player of the current request status. After pushing all the data for a single resource, the application should send the **LOADING_ERROR_SUCCESS** state to notify the player that the resource push is complete.

**Atomic service API**: This API can be used in atomic services since API version 18.

**System capability**: SystemCapability.Multimedia.Media.Core

**Parameters**

| Name  | Type    | Mandatory| Description                |
| -------- | -------- | ---- | -------------------- |
| uuid | number | Yes | 	ID for the resource handle.|
| state  | [LoadingRequestError](arkts-apis-media-e.md#loadingrequesterror18) | Yes | Request status.|

**Example**

```ts
import HashMap from '@ohos.util.HashMap';
let requests: HashMap<number, media.MediaSourceLoadingRequest> = new HashMap();
let uuid = 1;

let request = requests.get(uuid);
let loadingError = media.LoadingRequestError.LOADING_ERROR_SUCCESS;
request.finishLoading(uuid, loadingError);
```
