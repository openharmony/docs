# Sample Server Development Overview
<!--Kit: Basic Services Kit-->
<!--Subsystem: Update-->
<!--Owner: @RainyDay_005; @huangsiping3-->
<!--Designer: @zhangzhengxue; @jackd320-->
<!--Tester: @mamba-ting-->
<!--Adviser: @zhang_yixin13-->

The sample server provides a simple server instance for deploying update packages. It can be used as an auxiliary test environment for the UpdateService subsystem.

## When to Use

In actual applications, developers need to query and download update packages from the server. The sample server provides the following functions:

- Update package query: The server returns the version information of the update package.

- Update package download: The server returns the download link of the update package.

The sample server supports update service testing and secondary development function verification, building an end-to-end environment to cater for diverse update service use cases.

## Basic Concepts

- Package search service: one of the service capabilities provided by the UpdateService. It depends on the server that supports the TCP and SSL protocols.

- Package search server: a server that provisions the package search service through the TCP connection and the SSL protocol. The sample server mentioned in this document is such a package search server.

- Download server: an HTTP server.

- update.serverip.search: a system parameter that indicates the IP address of the package search server configured on the UpdateService. The default value is **127.0.0.1**.

## Constraints

- The following is an example of the json response returned by the server. Note that the **verifyInfo** field indicates the SHA-256 value of the update package, and the **size** field indicates the size of the update package, in bytes.

```json
{
    "searchStatus": 0,
    "errMsg": "success",
    "checkResults": [{
        "versionName": "versionNameSample",
        "versionCode": "versionCodeSample",
        "verifyInfo": "verifyInfoSHA256Value1234567",
        "size": 1234567,
        "packageType": 1,
        "url": "http://serverAddressSample/packageNameSample.fileTypeSample",
        "descriptPackageId": "abcdefg1234567ABCDEFG"
    }],
    "descriptInfo": [{
        "descriptionType": 0,
        "content": "This package is used for update."
    }]
}
```
