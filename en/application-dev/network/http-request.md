# HTTP Data Request

## Overview

An application can initiate a data request over HTTP. Common HTTP methods include **GET**, **POST**, **OPTIONS**, **HEAD**, **PUT**, **DELETE**, **TRACE**, and **CONNECT**.

<!--RP1-->

<!--RP1End-->

The following table lists the functions supported by the HTTP request. The options corresponding to the these functions can be set in [HttpResponseOptions](../reference/apis-network-kit/js-apis-http.md#httprequestoptions) of the HTTP request.

| Category    | Function                          |Description                     | Available Since        |
| ----------- | -----------------------------------|-----------------------------|------------------------|
| Basic    | Setting the request method                     | Specifies the request method, including **GET**, **POST**, **HEAD**, **PUT**, **DELETE**, **TRACE**, **CONNECT**, and **OPTIONS**. The default value is **GET**. |  API version 6  |
| Basic    | Setting additional data of the request                | Specifies additional data can be carried with the request. This parameter is not used by default.| API version 6    |
| Basic    | Setting the read timeout interval                | Specifies the total time from the start to the end of a request, including DNS resolution, connection setup, and transmission. The default value is **60000**, in ms.|  API version 6   |
| Basic    | Setting the connection timeout interval                | Specifies the connection timeout interval. The default value is **60000**, in ms.|  API version 6   |
| Basic    | Setting the HTTP request header                 | Specifies the HTTP request header. If the request method is **POST**, **PUT**, **DELETE**, or left empty, the default value is {'content-Type': 'application/json'}. Otherwise, the default value is {'content-Type': 'application/x-www-form-urlencoded'}.|  API version 6   |
| Basic    | Setting the response data type               | Specifies the type of the HTTP response data. This parameter is not used by default. If this parameter is set, the system returns the specified type of data preferentially.|  API version 9   |
| Basic    | Setting the priority of concurrent requests             |  Specifies the priority of concurrent HTTP/HTTPS requests. A larger value indicates a higher priority. The value ranges from 1 to 1000. The default value is **1**.|  API version 9   |
| Basic    | Enabling the cache               | Specifies whether to use the cache. The default value is **true**. The data in the cache is preferentially read. The cache takes effect with the current process. The new cache replaces the old cache. If this parameter is set to **false**, the cache is not used.|  API version 9   |
| Basic    | Setting the protocol type                | Specifies the protocol type. The default value is automatically assigned by the system. You can set it to **HTTP 1.1**, **HTTP 2**, or **HTTP 3**.|  API version 9   |
| Proxy setting    | Setting the HTTP request proxy                | Specifies whether to use the HTTP proxy. The default value is **false**, indicating that the proxy is not used. If this parameter is set to **true**, the default proxy of the system is used. You can also use a cstom network proxy.|  API version 10  |
| Certificate verification    | Setting the CA certificate path                  | Specifies the CA certificate path. If the CA certificate path is set, the system uses the CA certificate in the specified path. Otherwise, the system uses the preset CA certificate.| API version 10    |
| Certificate verification    | Setting the transmission of client certificates           | Specifies whether to enable the transmission of client certificates, which include the certificate path, certificate type, certificate key path, and password information.| API version 11    |
| Basic    | Setting the start and end positions of the download        | Specifies the data range to retrieve, which is commonly used in file download scenarios.|  API version 11  |
| Basic    | Setting the list of data fields to be uploaded       |Specifies the multipart form data, which is commonly used in file upload scenarios.|  API version 11   |
| DNS setting     | Setting an HTTPS server for DNS resolution | Specifies whether to use an HTTPS server for DNS resolution. The value must be URL-encoded in the following format: "https://host:port/path".| API version 11    |
| DNS setting    | Setting the specified DNS server for DNS resolution        | Specifies whether to use the specified DNS server for DNS resolution.<br> - You can set a maximum of three DNS servers. If there are more than three DNS servers, only the first three DNS servers are used.<br> - The DNS servers must be expressed as IPv4 or IPv6 addresses.|  API version 11   |
| Basic    | Setting the maximum number of bytes in a response message           | Specifies the maximum number of bytes in a response message. The default value is 5\*1024\*1024, in bytes. The maximum value is **100\*1024\*1024**.|   API version 11  |
| Certificate verification    | Setting the certificate pinning configuration            | Specifies the certificate pinning configuration. One or more certificate PINs can be specified.|   API version 12  |
| Certificate verification    | Setting the IP address family       | Specifies the IP address family for resolving the target domain name. The address type can be set to follow the system network configuration, forcibly use only IPv4 addresses for resolution, or forcibly use only IPv6 addresses for resolution.|  API version 15   |
| Certificate verification    | Setting whether to skip SSL certificate verification                    | Specifies whether to skip SSL certificate verification.| API version 18    |
| Certificate verification    | Setting the certificate verification version and cipher suite            | Customizes the certificate verification version and cipher suite.|  API version 18  |
| Certificate verification    | Setting server authentication for secure connections       | Specifies server authentication for secure connections.|  API version 18   |

## Available APIs

The HTTP request function is mainly implemented by the HTTP module.

To use related APIs, you must declare the **ohos.permission.INTERNET** permission.

For details about how to apply for permissions, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

The following table provides only a simple description of the related APIs. For details, see [API Reference](../reference/apis-network-kit/js-apis-http.md).

| API                                   | Description                               |
| ----------------------------------------- | ----------------------------------- |
| createHttp()                              | Creates an HTTP request.                 |
| request()                                 | Initiates an HTTP request to a given URL.    |
| requestInStream()<sup>10+</sup>           | Initiates an HTTP network request to a given URL and returns a streaming response.|
| destroy()                                 | Destroys an HTTP request.                     |
| on(type: 'headersReceive')                | Registers an observer for HTTP Response Header events.    |
| off(type: 'headersReceive')               | Unregisters the observer for HTTP Response Header events.|
| once\('headersReceive'\)<sup>8+</sup>     | Registers a one-time observer for HTTP Response Header events.|
| on\('dataReceive'\)<sup>10+</sup>         | Registers an observer for events indicating receiving of HTTP streaming responses.     |
| off\('dataReceive'\)<sup>10+</sup>        | Unregisters the observer for events indicating receiving of HTTP streaming responses. |
| on\('dataEnd'\)<sup>10+</sup>             | Registers an observer for events indicating completion of receiving HTTP streaming responses. |
| off\('dataEnd'\)<sup>10+</sup>            | Unregisters the observer for events indicating completion of receiving HTTP streaming responses.|
| on\('dataReceiveProgress'\)<sup>10+</sup>        | Registers an observer for events indicating progress of receiving HTTP streaming responses. |
| off\('dataReceiveProgress'\)<sup>10+</sup>       | Unregisters the observer for events indicating progress of receiving HTTP streaming responses.|
| on\('dataSendProgress'\)<sup>11+</sup>        | Registers an observer for events indicating progress of sending HTTP requests. |
| off\('dataSendProgress'\)<sup>11+</sup>       | Unregisters the observer for events indicating progress of sending HTTP requests.|

## Initiating an HTTP Data Request

1. Import the **http** namespace from **@kit.NetworkKit**.
2. Call **createHttp()** to create an **HttpRequest** object.
3. Call **httpRequest.on()** to subscribe to HTTP response header events. This API returns a response earlier than the request. You can subscribe to HTTP response header events based on service requirements.
4. Call **httpRequest.request()** to initiate a network request. You need to pass in the URL and optional parameters of the HTTP request.
5. Parse the returned result based on service requirements.
6. Call **off()** to unsubscribe from HTTP response header events.
7. Call **httpRequest.destroy()** to release resources after the request is processed.

>**NOTE**
>
>In the sample code provided in this topic, **this.context** is used to obtain the UIAbilityContext, where **this** indicates a UIAbility instance inherited from **UIAbility**. To use **UIAbilityContext** APIs on pages, see [Obtaining the Context of UIAbility](../application-models/uiability-usage.md#obtaining-the-context-of-uiability).

<!--code_no_check-->
```ts
// Import the http namespace.
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { common } from '@kit.AbilityKit';

let context: common.UIAbilityContext = this.getUIContext().getHostContext() as common.UIAbilityContext;
// Each httpRequest corresponds to an HTTP request task and cannot be reused.
let httpRequest = http.createHttp();
// This API is used to listen for the HTTP Response Header event, which is returned earlier than the result of the HTTP request. It is up to you whether to listen for HTTP Response Header events.
// on('headerReceive', AsyncCallback) is replaced by on('headersReceive', Callback) since API version 8.
httpRequest.on('headersReceive', (header) => {
  console.info('header: ' + JSON.stringify(header));
});
httpRequest.request(
  // Customize EXAMPLE_URL in extraData on your own. It is up to you whether to add parameters to the URL.
  "EXAMPLE_URL",
  {
    method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET.
    // You can add header fields based on service requirements.
    header: {
      'Content-Type': 'application/json'
    },
    // This field is used to transfer the request body when a POST request is used. Its format needs to be negotiated with the server.
    extraData: "data to send",
    expectDataType: http.HttpDataType.STRING, // Optional. This field specifies the type of the return data.
    usingCache: true, // Optional. The default value is true.
    priority: 1, // Optional. The default value is 1.
    connectTimeout: 60000 // Optional. The default value is 60000, in ms.
    readTimeout: 60000, // Optional. The default value is 60000, in ms.
    usingProtocol: http.HttpProtocol.HTTP1_1, // Optional. The default protocol type is automatically specified by the system.
    usingProxy: false, // Optional. By default, network proxy is not used. This field is supported since API version 10.
    caPath: '/path/to/cacert.pem', // Optional. The prebuilt CA certificate is used by default. This field is supported since API version 10.
    clientCert: { // Optional. The client certificate is not used by default. This field is supported since API version 11.
      certPath: '/path/to/client.pem', // The client certificate is not used by default. This field is supported since API version 11.
      keyPath: '/path/to/client.key', // If the certificate contains key information, an empty string is passed. This field is supported since API version 11.
      certType: http.CertType.PEM, // Certificate type, optional. A certificate in the PEM format is used by default. This field is supported since API version 11.
      keyPassword: "passwordToKey" // Password of the key file, optional. It is supported since API version 11.
    },
    multiFormDataList: [ // Optional. This field is valid only when content-Type in the header is multipart/form-data. It is supported since API version 11.
      {
        name: "Part1", // Data name. This field is supported since API version 11.
        contentType: 'text/plain', // Data type. This field is supported since API version 11.
        data: 'Example data', // Data content, optional. This field is supported since API version 11.
        remoteFileName: 'example.txt' // Optional. This field is supported since API version 11.
      }, {
        name: "Part2", // Data name. This field is supported since API version 11.
        contentType: 'text/plain', // Data type. This field is supported since API version 11.
        // data/app/el2/100/base/com.example.myapplication/haps/entry/files/fileName.txt
        filePath: `${context.filesDir}/fileName.txt`, // File path, optional. This field is supported since API version 11.
        remoteFileName: 'fileName.txt' // Optional. This field is supported since API version 11.
      }
    ]
  }, (err: BusinessError, data: http.HttpResponse) => {
    if (!err) {
      // data.result carries the HTTP response. Parse the response based on service requirements.
      console.info('Result:' + JSON.stringify(data.result));
      console.info('code:' + JSON.stringify(data.responseCode));
      // data.header carries the HTTP response header. Parse the content based on service requirements.
      console.info('header:' + JSON.stringify(data.header));
      console.info('cookies:' + JSON.stringify(data.cookies)); // 8+
      // Call the destroy() method to release resources after HttpRequest is complete.
      httpRequest.destroy();
    } else {
      console.error('error:' + JSON.stringify(err));
      // Unsubscribe from HTTP Response Header events.
      httpRequest.off('headersReceive');
      // Call the destroy() method to release resources after HttpRequest is complete.
      httpRequest.destroy();
    }
  }
);
```

## Initiating an HTTP Streaming Request

1. Import the **http** namespace from **@kit.NetworkKit**.
2. Call **createHttp()** to create an **HttpRequest** object.
3. Depending on your need, call **on()** of the **HttpRequest** object to subscribe to HTTP response header events as well as events indicating receiving of HTTP streaming responses, progress of receiving HTTP streaming responses, and completion of receiving HTTP streaming responses.
4. Call **requestInStream()** to initiate a network request. You need to pass in the URL and optional parameters of the HTTP request.
5. Parse the returned response code as needed.
6. Call **off()** of the **HttpRequest** object to unsubscribe from the related events.
7. Call **httpRequest.destroy()** to release resources after the request is processed.

```ts
// Import the http namespace.
import { http } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Each httpRequest corresponds to an HTTP request task and cannot be reused.
let httpRequest = http.createHttp();
// Subscribe to HTTP response header events.
httpRequest.on('headersReceive', (header: Object) => {
  console.info('header: ' + JSON.stringify(header));
});
// Subscribe to events indicating receiving of HTTP streaming responses.
let res = new ArrayBuffer(0);
httpRequest.on('dataReceive', (data: ArrayBuffer) => {
   const newRes = new ArrayBuffer(res.byteLength + data.byteLength);
   const resView = new Uint8Array(newRes);
   resView.set(new Uint8Array(res));
   resView.set(new Uint8Array(data), res.byteLength);
   res = newRes;
   console.info('res length: ' + res.byteLength);
});
// Subscribe to events indicating completion of receiving HTTP streaming responses.
httpRequest.on('dataEnd', () => {
  console.info('No more data in response, data receive end');
});
// Subscribe to events indicating progress of receiving HTTP streaming responses.
class Data {
  receiveSize: number = 0;
  totalSize: number = 0;
}
httpRequest.on('dataReceiveProgress', (data: Data) => {
  console.log("dataReceiveProgress receiveSize:" + data.receiveSize + ", totalSize:" + data.totalSize);
});

let streamInfo: http.HttpRequestOptions = {
  method: http.RequestMethod.POST, // Optional. The default value is http.RequestMethod.GET.
  // You can add header fields based on service requirements.
  header: {
    'Content-Type': 'application/json'
  },
  // This field is used to transfer the request body when a POST request is used. Its format needs to be negotiated with the server.
  extraData: "data to send",
  expectDataType: http.HttpDataType.STRING, // Optional. This field specifies the type of the return data.
  usingCache: true, // Optional. The default value is true.
  priority: 1, // Optional. The default value is 1.
  connectTimeout: 60000 // Optional. The default value is 60000, in ms.
  readTimeout: 60000, // Optional. The default value is 60000, in ms. If a large amount of data needs to be transmitted, you are advised to set this parameter to a larger value to ensure normal data transmission.
  usingProtocol: http.HttpProtocol.HTTP1_1 // Optional. The default protocol type is automatically specified by the system.
}

// Customize EXAMPLE_URL in extraData on your own. It is up to you whether to add parameters to the URL.
httpRequest.requestInStream("EXAMPLE_URL", streamInfo).then((data: number) => {
  console.info("requestInStream OK!");
  console.info('ResponseCode :' + JSON.stringify(data));
  // Unsubscribe from HTTP Response Header events.
  httpRequest.off('headersReceive');
  // Unregister the observer for events indicating receiving of HTTP streaming responses.
  httpRequest.off('dataReceive');
  // Unregister the observer for events indicating progress of receiving HTTP streaming responses.
  httpRequest.off('dataReceiveProgress');
  // Unregister the observer for events indicating completion of receiving HTTP streaming responses.
  httpRequest.off('dataEnd');
  // Call the destroy() method to release resources after HttpRequest is complete.
  httpRequest.destroy();
}).catch((err: Error) => {
  console.info("requestInStream ERROR : err = " + JSON.stringify(err));
});
```

## Certificate Pinning

You can prebuild application-level certificates or a public key hash values for certificate pinning. This way, an HTTPS connection can be established only when the prebuilt certificate is used.

Both modes are configured through `src/main/resources/base/profile/network_config.json`. In the configuration file, you can create mapping between prebuilt certificates and network servers.

If you do not know the certificate mapping a server domain name, you can use the following command to obtain the certificate. When running the command, change `www.example.com` to the server domain name and `www.example.com.pem` to the name of the obtained certificate file.

```
openssl s_client -servername www.example.com -connect www.example.com:443 \
    < /dev/null | sed -n "/-----BEGIN/,/-----END/p" > www.example.com.pem
```

If you are using a Windows environment, you need to:

* Replace `/dev/null` with `NUL`.
* Press **Enter** to exit. This is different from OpenSSL of Linux, which may exit until the user enters a value.
* If the **sed** command is not present, copy the content between `-----BEGIN CERTIFICATE-----` and `-----END CERTIFICATE-----` (with these two lines included) in the command output and save it.

### Prebuilding Application-level Certificates

Prebuilding application-level certificates means to embed the original certificate files in the application. Currently, certificate files in the **.crt** and **.pem** formats are supported.

> **NOTE**
>
> Currently, certificate pinning has been enabled for the ohos.net.http and Image components, and the hash values of all certificates in the certificate chain are matched. If any certificate is updated on the server, the verification fails. Therefore, if any certificate on the server has been updated, upgrade the application to the latest version as soon as possible. Otherwise, network connection may fail.

### Prebuilding Certificate Public Key Hash Values

You can create mapping between public key hash values and domain name certificates in the configuration file. This way, access to the domain name is allowed only if the used domain name certificate matches the preset public key hash value.

The public key hash value of the domain name certificate can be calculated using the following command. Assume that the domain name certificate is obtained using the preceding OpenSSL command and saved in the `www.example.com.pem` file. The line that starts with # is treated as a comment.

```
# Extract the public key from the certificate.
openssl x509 -in www.example.com.pem -pubkey -noout > www.example.com.pubkey.pem
# Convert the public key from the pem format to the der format.
openssl asn1parse -noout -inform pem -in www.example.com.pubkey.pem -out www.example.com.pubkey.der
# Calculate the SHA256 of the public key and convert it to Base64.
openssl dgst -sha256 -binary www.example.com.pubkey.der | openssl base64
```

### Example of the JSON Configuration File

The following is an example of prebuilt application-level certificates. For details about the configuration path, see [Network Connection Security Configuration](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-network-ca-security#section5454123841911).

```json
{
  "network-security-config": {
    "base-config": {
      "trust-anchors": [
        {
          "certificates": "/etc/security/certificates"
        }
      ]
    },
    "domain-config": [
      {
        "domains": [
          {
            "include-subdomains": true,
            "name": "example.com"
          }
        ],
        "trust-anchors": [
          {
            "certificates": "/data/storage/el1/bundle/entry/resources/resfile"
          }
        ]
      }
    ]
  }
}
```

The following is an example of prebuilt certificate public key hash values:
```
{
  "network-security-config": {
    "domain-config": [
      {
        "domains": [
          {
            "include-subdomains": true,
            "name": "server.com"
          }
        ],
        "pin-set": {
          "expiration": "2024-11-08",
          "pin": [
            {
              "digest-algorithm": "sha256",
              "digest": "FEDCBA987654321"
            }
          ]
        }
      }
    ]
  }
}
```

**Description of fields**

| Field                     | Type           | Description                                  |   
| --------------------------| --------------- | -------------------------------------- |
|network-security-config    | object          |Network security configuration. The value can contain zero or one **base-config** and must contain one **domain-config**.|
|base-config                | object          |Application security configuration. The value must contain one **trust-anchors**.                         |
|domain-config              | array           |Domain security configuration. The value can contain any number of items. An item must contain one **domains** and can contain zero or one **trust-anchors** and **pin-set**.|
|trust-anchors              | array           |Trusted CA. The value can contain any number of items. An item must contain one **certificates**.|
|certificates               | string          |CA certificate path.|
|domains                    | array           |Domain. The value can contain any number of items. An item must contain one **name** (string: domain name) and can contain zero or one **include-subdomains**.|
|include-subdomains         | boolean         |Whether a rule applies to subdomains. Whether a rule applies to subdomains. The value **true** indicates that the rule applies to subdomains, and the value **false** indicates the opposite.|
|pin-set                    | object          |Certificate public key hash setting. The value must contain one **pin** and can contain zero or one **expiration**.|
|expiration                 | string          |Expiration time of the certificate public key hash.|
|pin                        | array           |Certificate public key hash. The value can contain any number of items. An item must contain one **digest-algorithm** and **digest**.|
|digest-algorithm           | string          |Digest algorithm used to generate hashes. Currently, only `sha256` is supported.                                   |
|digest                     | string          |Public key hash.|

