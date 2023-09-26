# Network Management Subsystem Changelog

## request2 API Name Change

Changed the name of the HTTP streaming request from **request2** to **requestInStream**. The original name **request2** does not clearly express the intent of the API and may cause ambiguity, which does not comply with the OpenHarmony API specifications. 
 
  -  

## dataProgress Event Name Change

Changed the name of the streaming data receiving event from **dataProgress** to **dataReceiveProgress**. The original name **dataProgress** does not clearly express the meaning of the event, which does not comply with the OpenHarmony API specifications. 
 
  -  

**Change Impact**

For applications developed based on earlier versions, the corresponding API and event names must be updated. Otherwise, API calls may fail, affecting the service logic.

**Key API/Component Changes**

Involved APIs:

  - request2;
  - on(type: "dataProgress", callback: Callback<{ receiveSize: number, totalSize: number }>): void;
  - off(type: "dataProgress", callback: Callback<{ receiveSize: number, totalSize: number }>): void;

Before change:
  - request2(url: string, callback: AsyncCallback<number>): void;
  - request2(url: string, options: HttpRequestOptions, callback: AsyncCallback<number>): void;
  - request2(url: string, options?: HttpRequestOptions): Promise<number>;
  - on(type: "dataProgress", callback: Callback<{ receiveSize: number, totalSize: number }>): void;
  - off(type: 'dataProgress', callback?: Callback<{ receiveSize: number, totalSize: number }>): void;

After change:
  - requestInStream(url: string, callback: AsyncCallback<number>): void;
  - requestInStream(url: string, options: HttpRequestOptions, callback: AsyncCallback<number>): void;
  - requestInStream(url: string, options?: HttpRequestOptions): Promise<number>;
  - on(type: "dataReceiveProgress", callback: Callback<{ receiveSize: number, totalSize: number }>): void;
  - off(type: 'dataReceiveProgress', callback?: Callback<{ receiveSize: number, totalSize: number }>): void;

**Adaptation Guide**

Replace the API name **request2** and event name **dataProgress** in the original service code with **requestInStream** and **dataReceiveProgress**, respectively.
