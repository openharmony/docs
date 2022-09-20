# Network and Connection Development

## What Are the Data Formats Supported by extraData in an HTTP Request?

Applicable to: OpenHarmony SDK 3.2.2.5, stage model of API version 9

**extraData** indicates additional data in an HTTP request. It varies depending on the HTTP request method.

- If the HTTP request uses a POST or PUT method, **extraData** serves as the content of the HTTP request.

- If the HTTP request uses a GET, OPTIONS, DELETE, TRACE, or CONNECT method, **extraData** serves as a supplement to the HTTP request parameters and will be added to the URL when the request is sent.

- If you pass in a string object, **extraData** contains the string encoded on your own.

## What Does Error Code 28 Mean for an HTTP Request?

Applicable to: OpenHarmony SDK 3.2.2.5, stage model of API version 9

Error code 28 refers to **CURLE_OPERATION_TIMEDOUT**, which means a libcurl library operation timeout. For details, see any HTTP status code description available.

Reference: [Development Guide](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-http.md#httpresponse) and [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html)

## What Does Error Code 6 Mean for the Response of \@ohos.net.http.d.ts?

Applicable to: OpenHarmony SDK 3.2.3.5

Error code 6 indicates a failure to resolve the host in the address. You can ping the URL carried in the request to check whether the host is accessible.

Reference: [Development Guide](https://gitee.com/openharmony/docs/blob/master/en/application-dev/reference/apis/js-apis-http.md#httpresponse) and [Curl Error Codes](https://curl.se/libcurl/c/libcurl-errors.html)
