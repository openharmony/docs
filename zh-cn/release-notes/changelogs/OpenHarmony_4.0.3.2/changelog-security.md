# security子系统ChangeLog

## cl.security.1 ParamsSpec属性名变更为algName。
结构体ParamsSpec的属性algoName由于API命名统一，名称更改为algName。

**变更影响**

影响已发布的JS接口，对ParamsSpec以及其子类IvParamsSpec，GcmParamsSpec与CcmParamsSpec，使用这些对象作为参数或返回值时，其属性名需要更改为algName。
应用需要进行适配，才可以在新版本SDK环境正常编译通过。

**关键的接口/组件变更**

修改前的接口原型：

 ```ts
interface ParamsSpec {
    /**
     * Indicates the algorithm name. Should be set before initialization of a cipher object.
     * @type { string }
     * @syscap SystemCapability.Security.CryptoFramework
     * @since 9
     */
    algoName : string;
}
 ```
修改后的接口原型：

 ```ts
interface ParamsSpec {
    /**
     * Indicates the algorithm name. Should be set before initialization of a cipher object.
     * @type { string }
     * @syscap SystemCapability.Security.CryptoFramework
     * @since 9
     */
    algName : string;
}
 ```

**适配指导**
对ParamsSpec以及其子类IvParamsSpec，GcmParamsSpec与CcmParamsSpec，使用这些对象作为参数或返回值时，其属性名需要从algoName更改为algName。
 ```ts
function genGcmParamsSpec() {
  let arr = [0, 0, 0, 0 , 0, 0, 0, 0, 0, 0 , 0, 0]; // 12 bytes
  let dataIv = new Uint8Array(arr);
  let ivBlob = {data : dataIv};

  arr = [0, 0, 0, 0 , 0, 0, 0, 0]; // 8 bytes
  let dataAad = new Uint8Array(arr);
  let aadBlob = {data : dataAad};

  arr = [0, 0, 0, 0 , 0, 0, 0, 0, 0, 0, 0, 0 , 0, 0, 0, 0]; // 16 bytes
  let dataTag = new Uint8Array(arr);
  let tagBlob = {data : dataTag};
  let gcmParamsSpec = {iv : ivBlob, aad : aadBlob, authTag : tagBlob, algName : "GcmParamsSpec"};
  return gcmParamsSpec;
}
 ```   
详细查看API参考中ParamsSpec对应的接口适配指南：
[加解密算法库框架-ParamsSpec-API参考](../../../application-dev/reference/apis/js-apis-cryptoFramework.md#paramsspec)