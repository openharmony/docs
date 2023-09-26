# security子系统ChangeLog

## cl.security.1 对API9中已经抛出的异常，补写throws标签
对于在API9中已经抛出异常而JS DOC中漏写throws标签的接口，在since 9的注释中补上throws标签。

**变更影响**

对于已发布的JS接口，可能影响异常处理流程，包括同步异常和异步异常。应用需要根据最新的throws标签，排查是否有遗漏的异常处理流程，结合实际情况进行适配。

**关键的接口/组件变更**

修改前的接口原型：

 ```ts
interface Key {
  /**
   * Encode the key object to binary data.
   *
   * @returns { DataBlob } the binary data of the key object.
   * @syscap SystemCapability.Security.CryptoFramework
   * @since 9
   */
  getEncoded(): DataBlob;
}

interface AsyKeyGenerator {
  /**
   * Used to generate asymmetric key pair.
   *
   * @param { AsyncCallback<KeyPair> } callback - the callback used to return keypair.
   * @throws { BusinessError } 401 - invalid parameters.
   * @throws { BusinessError } 17620001 - memory error.
   * @syscap SystemCapability.Security.CryptoFramework
   * @since 9
   */
  generateKeyPair(callback: AsyncCallback<KeyPair>): void;

  /**
   * Used to generate asymmetric key pair.
   *
   * @returns { Promise<KeyPair> } the promise used to return keypair.
   * @throws { BusinessError } 401 - invalid parameters.
   * @throws { BusinessError } 17620001 - memory error.
   * @syscap SystemCapability.Security.CryptoFramework
   * @since 9
   */
  generateKeyPair(): Promise<KeyPair>;

  /**
   * Used to convert asymmetric key data to key pair object.
   *
   * @param { DataBlob } pubKey - the public key data blob.
   * @param { DataBlob } priKey - the private key data blob.
   * @param { AsyncCallback<KeyPair> } callback - the callback used to return keypair.
   * @throws { BusinessError } 401 - invalid parameters.
   * @throws { BusinessError } 17620001 - memory error.
   * @syscap SystemCapability.Security.CryptoFramework
   * @since 9
   */
  convertKey(pubKey: DataBlob, priKey: DataBlob, callback: AsyncCallback<KeyPair>): void;

  /**
   * Used to convert asymmetric key data to key pair object.
   *
   * @param { DataBlob } pubKey - the public key data blob.
   * @param { DataBlob } priKey - the private key data blob.
   * @returns { Promise<KeyPair> } the promise used to return keypair.
   * @throws { BusinessError } 401 - invalid parameters.
   * @throws { BusinessError } 17620001 - memory error.
   * @syscap SystemCapability.Security.CryptoFramework
   * @since 9
   */
  convertKey(pubKey: DataBlob, priKey: DataBlob): Promise<KeyPair>;
}

/**
 * Provides the asymmetric key generator instance func.
 *
 * @param { string } algName - indicates the algorithm name.
 * @returns { AsyKeyGenerator } the generator obj create by algName.
 * @throws { BusinessError } 401 - invalid parameters.
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 9
 */
function createAsyKeyGenerator(algName: string): AsyKeyGenerator;

/**
 * Create a cipher object for encryption and decryption operations according to the given specifications.
 * Two different Cipher objects should be created when using RSA encryption and decryption,
 * even with the same specifications.
 *
 * @param { string } transformation - indicates the description to be transformed to cipher specifications.
 * @returns { Cipher } the cipher object returned by the function.
 * @throws { BusinessError } 401 - invalid parameters.
 * @throws { BusinessError } 801 - this operation is not supported.
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 9
 */
function createCipher(transformation: string): Cipher;

/**
 * Create sign class.
 *
 * @param { string } algName - indicates the algorithm name and params.
 * @returns { Sign } the sign class.
 * @throws { BusinessError } 401 - invalid parameters.
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 9
 */
function createSign(algName: string): Sign;

/**
 * Create verify class.
 *
 * @param { string } algName - indicates the algorithm name and params.
 * @returns { Verify } the verify class.
 * @throws { BusinessError } 401 - invalid parameters.
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 9
 */
function createVerify(algName: string): Verify;

/**
 * Create key agreement class.
 *
 * @param { string } algName - indicates the algorithm name and params.
 * @returns { KeyAgreement } the key agreement class.
 * @throws { BusinessError } 401 - invalid parameters.
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 9
 */
function createKeyAgreement(algName: string): KeyAgreement;
 ```
修改后的接口原型：

 ```ts
interface Key {
  /**
   * Encode the key object to binary data.
   *
   * @returns { DataBlob } the binary data of the key object.
   * @throws { BusinessError } 801 - this operation is not supported.
   * @throws { BusinessError } 17620001 - memory error.
   * @throws { BusinessError } 17630001 - crypto operation error.
   * @syscap SystemCapability.Security.CryptoFramework
   * @since 9
   */
  getEncoded(): DataBlob;
}

interface AsyKeyGenerator {
  /**
   * Used to generate asymmetric keypair.
   *
   * @param { AsyncCallback<KeyPair> } callback - the callback used to return keypair.
   * @throws { BusinessError } 401 - invalid parameters.
   * @throws { BusinessError } 17620001 - memory error.
   * @throws { BusinessError } 17630001 - crypto operation error.
   * @syscap SystemCapability.Security.CryptoFramework
   * @since 9
   */
  generateKeyPair(callback: AsyncCallback<KeyPair>): void;

  /**
   * Used to generate asymmetric keypair.
   *
   * @returns { Promise<KeyPair> } the promise used to return keypair.
   * @throws { BusinessError } 401 - invalid parameters.
   * @throws { BusinessError } 17620001 - memory error.
   * @throws { BusinessError } 17630001 - crypto operation error.
   * @syscap SystemCapability.Security.CryptoFramework
   * @since 9
   */
  generateKeyPair(): Promise<KeyPair>;

  /**
   * Used to convert asymmetric key data to keypair object.
   *
   * @param { DataBlob } pubKey - the public key data blob.
   * @param { DataBlob } priKey - the private key data blob.
   * @param { AsyncCallback<KeyPair> } callback - the callback used to return keypair.
   * @throws { BusinessError } 401 - invalid parameters.
   * @throws { BusinessError } 17620001 - memory error.
   * @throws { BusinessError } 17630001 - crypto operation error.
   * @syscap SystemCapability.Security.CryptoFramework
   * @since 9
   */
  convertKey(pubKey: DataBlob, priKey: DataBlob, callback: AsyncCallback<KeyPair>): void;

  /**
   * Used to convert asymmetric key data to keypair object.
   *
   * @param { DataBlob } pubKey - the public key data blob.
   * @param { DataBlob } priKey - the private key data blob.
   * @returns { Promise<KeyPair> } the promise used to return keypair.
   * @throws { BusinessError } 401 - invalid parameters.
   * @throws { BusinessError } 17620001 - memory error.
   * @throws { BusinessError } 17630001 - crypto operation error.
   * @syscap SystemCapability.Security.CryptoFramework
   * @since 9
   */
  convertKey(pubKey: DataBlob, priKey: DataBlob): Promise<KeyPair>;
}

/**
 * Create the asymmetric key generator instance according to the given algorithm name.
 *
 * @param { string } algName - indicates the algorithm name.
 * @returns { AsyKeyGenerator } the asymmetric key generator instance.
 * @throws { BusinessError } 401 - invalid parameters.
 * @throws { BusinessError } 801 - this operation is not supported.
 * @throws { BusinessError } 17620001 - memory error.
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 9
 */
function createAsyKeyGenerator(algName: string): AsyKeyGenerator;

/**
 * Create a cipher object for encryption and decryption operations according to the given specifications.
 * Two different Cipher objects should be created when using RSA encryption and decryption,
 * even with the same specifications.
 *
 * @param { string } transformation - indicates the description to be transformed to cipher specifications.
 * @returns { Cipher } the cipher object returned by the function.
 * @throws { BusinessError } 401 - invalid parameters.
 * @throws { BusinessError } 801 - this operation is not supported.
 * @throws { BusinessError } 17620001 - memory error.
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 9
 */
function createCipher(transformation: string): Cipher;

/**
 * Create a sign object for generating signatures.
 *
 * @param { string } algName - indicates the algorithm name and params.
 * @returns { Sign } the sign class.
 * @throws { BusinessError } 401 - invalid parameters.
 * @throws { BusinessError } 801 - this operation is not supported.
 * @throws { BusinessError } 17620001 - memory error.
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 9
 */
function createSign(algName: string): Sign;

/**
 * Create a verify object for verifying signatures.
 *
 * @param { string } algName - indicates the algorithm name and the parameters.
 * @returns { Verify } the verify class.
 * @throws { BusinessError } 401 - invalid parameters.
 * @throws { BusinessError } 801 - this operation is not supported.
 * @throws { BusinessError } 17620001 - memory error.
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 9
 */
function createVerify(algName: string): Verify;

/**
 * Create a key agreement object.
 *
 * @param { string } algName - indicates the algorithm name and params.
 * @returns { KeyAgreement } the key agreement object.
 * @throws { BusinessError } 401 - invalid parameters.
 * @throws { BusinessError } 801 - this operation is not supported.
 * @throws { BusinessError } 17620001 - memory error.
 * @syscap SystemCapability.Security.CryptoFramework
 * @since 9
 */
function createKeyAgreement(algName: string): KeyAgreement;
 ```

**适配指导**

由于漏标的throws异常发生在较少见的情况下，应用可以结合实际情况，排查漏标的throws标签是否需要专门适配。

- 对于同步方法，如createSign等，请使用try/catch方式处理错误信息。

- 对于异步方法，如convertKey等，请使用try/catch方式处理同步的参数错误，使用error对象的方式获取异步的参数错误和业务执行错误。
