# Security Subsystem Changelog

## cl.security.1 Addition of the @throws Tags for Exceptions Thrown in API Version 9
Added the @throws tags for the APIs of API version 9 in the JS document.

**Change Impact**

For released JS interfaces, the exception handling process may be affected, including synchronous and asynchronous exceptions. Check the exception handling process based on the latest @throws tags and make adaptation.

**Key API/Component Changes**

Before change:

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
After change:

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

**Adaptation Guide**

Check the exception handling process based on the latest @throws tags and modify the code as required.

- For synchronization methods, such as **createSign**, use try/catch to process error information.

- For asynchronous methods, such as **convertKey**, use try/catch to process synchronous parameter errors and use the **error** object to obtain asynchronous parameter errors and service execution errors.
