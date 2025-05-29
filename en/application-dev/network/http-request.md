# HTTP Data Request

## When to Use

An application can initiate a data request over HTTP. Common HTTP methods include **GET**, **POST**, **OPTIONS**, **HEAD**, **PUT**, **DELETE**, **TRACE**, and **CONNECT**.

<!--RP1-->

<!--RP1End-->

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

You can create mapping between public key hash values and domain name certificates in the configuration file. This way, access to the domain name is allowed only if the used domain name certificate matches the prebuilt public key hash value.

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

The following is an example configuration for overall and host name–based HTTP access:
```
{
  "network-security-config": {
    "base-config": {
      "cleartextTrafficPermitted": true
    },
    "domain-config": [
      {
        "domains": [
          {
            "include-subdomains": true,
            "name": "example.com"
          }
        ],
        "cleartextTrafficPermitted": false
      }
    ]
  }
}
```

The following is an example configuration of the certificate pin:
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
  },
  "trust-global-user-ca": false,
  "trust-current-user-ca": false,
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
|cleartextTrafficPermitted  | boolean          |Whether plaintext HTTP is allowed. The value **true** indicates that plaintext HTTP is allowed, and the value **false** indicates the opposite.|


## Configuring Untrusted User-Installed CA Certificates
By default, the system trusts the prebuilt CA certificates and user-installed CA certificates. To further improve security, you can configure untrusted user-installed CA certificates in **src/main/resources/base/profile/network_config.json**. For more network connection security configurations, see [Network Connection Security Configuration](https://developer.huawei.com/consumer/en/doc/best-practices/bpta-network-ca-security#section5454123841911).
```
{
  "network-security-config": {
    ... ...
  },
  "trust-global-user-ca": false, // Set whether to trust the CA certificate manually installed by the enterprise MDM system or device administrator. The default value is true.
  "trust-current-user-ca" : false // Set whether to trust the certificate installed by the current user. The default value is true.
}
```
