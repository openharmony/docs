# Network Management Development

## What are the data formats supported by extraData in an HTTP request?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Solution**

**extraData** specifies additional data in an HTTP request. It varies depending on the HTTP request method.

-   If the HTTP request uses a POST or PUT method, **extraData** serves as the content of the HTTP request.
-   If the HTTP request uses a GET, OPTIONS, DELETE, TRACE, or CONNECT method, **extraData** serves as a supplement to the HTTP request parameters and will be added to the URL when the request is sent.
-   If you pass in a string object, **extraData** contains the string encoded on your own.

## What does error code 28 mean in the response to an HTTP request?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Symptom**

Error code 28 is reported after an HTTP request is initiated.

**Solution**

Error code 28 indicates **CURLE\_OPERATION\_TIMEDOUT**, which means a libcurl library operation timeout. For details, see any HTTP status code description available.

**Reference**

[Common HTTP Response Codes](../reference/apis/js-apis-http.md#responsecode) and [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html)

## What does error code 6 mean in the response to an HTTP request?

Applicable to: OpenHarmony 3.2 Beta (API version 9)  

**Symptom**

Error code 6 is reported after an HTTP request is initiated.

**Solution**

Error code 6 indicates a failure to resolve the host in the address. You can ping the URL carried in the request to check whether the host is accessible.

**Reference**

[Common HTTP Response Codes](../reference/apis/js-apis-http.md#responsecode) and [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html)

## How are parameters passed to queryParams of the POST request initiated by @ohos/axios?

Applicable to: OpenHarmony 3.2 Beta (API version 9)  

**Symptom**

How are parameters passed to **queryParams** when the third-party component @ohos/axios initiates a POST request?

**Solution**

-   Method 1: Have the **axios.post** API receive only one parameter. The **Url.URLSearchParams** parameter needs to be converted into a string and appended to the end of the URL.

    ```
    let params:Url.URLSearchParams = new Url.URLSearchParams()
    params.append('ctl', 'sug')
    params.append('query', 'wangjunkai')
    params.append('cfrom', '1099a')
    axios.post('http://10.100.195.234:3000/save?' + params.toString()).then(res => {
      this.message = "request result: " + JSON.stringify(res.data);
    }).catch(err => {
      this.message = "request error: " + err.message;
    })
    ```

-   Method 2: Have the **axios** API receive only one **config** object. The request parameters are written in **params** of the **config** object.

    ```
    axios({
      url: 'http://10.100.195.234:3000/save',
      method: 'post',
      params: {
      ctl: 'sug',
      query: 'wangjunkai',
      cfrom: '1099a'
      }
    }).then(res => {
      this.message = "request result: " + JSON.stringify(res.data);
    }).catch(err => {
      this.message = "request error: " + err.message;
    })
    ```


## What should I do if no data is returned after connection.getNetCapabilities\(mNetHandle\) is called?

Applicable to: OpenHarmony 3.2 Beta 2 (API version 9)

**Symptom**

No data is returned after **connection.getNetCapabilities\(\)** is called. What should I do?

**Possible Cause**

This problem is due to incorrect pointing of the **this** object. You are expected to use **\(err,data\)=\>\{\}** instead of **function\(err,data\)** to access the callback function to obtain the return result. The reason is that the function declared by **function** has its own **this** object and therefore cannot point to the **globalThis** object.

**Solution**

Change **function\(err,data\)** to **\(err,data\)** for the second parameter of **getNetCapabilities**.

## How is data in HTTP requests transmitted in JSON format?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Solution**

In the HTTP message header, **Content-Type** is used to indicate the media type information. It tells the server how to process the requested data and tells the client (usually a browser) how to parse the response data, for example, displaying an image, parsing HTML, or displaying only the text.

To transmit data in HTTP requests in JSON format, set **Content-Type** to **application/json**.

```
this.options = {
  method:  http.RequestMethod.GET,
  extraData: this.extraData,
  header: { 'Content-Type': 'application/json' },
  readTimeout: 50000,
  connectTimeout: 50000
}
```

## How do I upload photos taken by a camera to the server?

Applicable to: OpenHarmony 3.2 Beta 5 (API version 9)

**Symptom**

After an application calls the camera to take a photo, how do I upload the photo to the server?

**Solution**

After the application is started and the permission is obtained, have the system access the remote server and transfer the locally saved photos to the remote server through the upload API.

**Reference**

[Upload and Download](../reference/apis/js-apis-request.md)

## What should I do if calling connection.hasDefaultNet\(\) fails even when the network is normal?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Symptom**

The network connection is normal, and web pages can be opened properly on the browser. However, calling the **hasDefaultNet** fails, and the callback function returns an error.

**Solution**

Declare the **ohos.permission.GET\_NETWORK\_INFO** permission when calling **connection.hasDefaultNet**.

For details, see [Applying for Permissions](../security/accesstoken-guidelines.md).

## What does netId mean in the netHandle object returned by connection.getDefaultNet?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Symptom**

What are the meanings of the values of **netId**, such as **0** and **100**?

**Solution**

If the value of **netId** is **0**, no network connection is available. In such a case, check and rectify network faults. If the value is greater than or equal to **100**, the network connection is normal.

## How do I use HTTP requests to obtain data from the network?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Solution**

Use the **@ohos.net.http** module to initiate an HTTP request.

1.  Import the **http** module and create an HTTP request.
2.  Set the request URL and parameters and initiate the HTTP request.
3.  Obtain the response and parse the data.

**Reference**

[HTTP Data Request](../connectivity/http-request.md)

## How do I encapsulate network requests by using JavaScript?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Solution**

OpenHarmony supports the JavaScript development mode. You can directly use JavaScript to encapsulate network requests. For details, see [Network Connection](../reference/apis/js-apis-http.md).

## How do I write network requests when developing a JavaScript-based application for smart watches?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Solution**

OpenHarmony supports the JavaScript development mode. You can directly use JavaScript to encapsulate network requests. For details, see [Network Connection](../reference/apis/js-apis-http.md).

## Why does an application fail to start after the ohos.permission.NOTIFICATION\_CONTROLLER permission is declared?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Symptom**

When an application is started, the following error message is reported w: error: install failed due to grant request permissions failed.

**Solution**

The **ohos.permission.NOTIFICATION\_CONTROLLER** permission is a **system core** permission and is not available for third-party applications.

## What should I do if an error is reported when wifi.getIpInfo\(\).ipAddress is used in the Wi-Fi module?

Applicable to: OpenHarmony 3.2 Beta (API version 9)

**Symptom**

When **wifi.getIpInfo\(\).ipAddress** is used in the Wi-Fi module, the following error message is reported: Error: assertion \(wifiDevicePtr != nullptr\) failed: Wifi device instance is null.

**Solution**

This problem is due to insufficient permissions. Check whether you have applied for the required permissions. For details, see [Permission Management](../security/accesstoken-overview.md).
