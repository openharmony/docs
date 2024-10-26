# Converting Binary Data into a Symmetric Key (ArkTS)


This topic uses 3DES and HMAC as an example to describe how to convert binary data into a symmetric key. That is, convert a piece of external or internal binary data into a key object for subsequent operations, such as encryption and decryption.


## Converting Binary Data into a 3DES Key

For details about the algorithm specifications, see [3DES](crypto-sym-key-generation-conversion-spec.md#3des).

1. Obtain the 3DES key binary data and encapsulate it into a **DataBlob** object.

2. Use [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) with the string parameter **'3DES192'** to create a symmetric key generator (**SymKeyGenerator**) object for a 192-bit 3DES key.

3. Use [SymKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-1) to convert the binary data into a symmetric key (**SymKey**).

4. Use [SymKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the key.

- Example: Convert binary data into a 192-bit 3DES key (using callback-based APIs).

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { BusinessError } from '@kit.BasicServicesKit';

  function genKeyMaterialBlob(): cryptoFramework.DataBlob {
    let arr = [
      0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
      0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
      0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72]; // The key length is 192 bits, that is, 24 bytes.
    let keyMaterial = new Uint8Array(arr);
    return { data: keyMaterial };
  }

  function testConvertSymKey() {
    // Create a SymKeyGenerator instance.
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
    // Convert the data into a symmetric key.
    let keyMaterialBlob = genKeyMaterialBlob();
    try {
      symKeyGenerator.convertKey(keyMaterialBlob, (error, key) => {
        if (error) {// If the service logic fails to be executed, the first parameter of the callback returns error information, that is, throw an exception asynchronously.
          let e: BusinessError = error as BusinessError;
          console.error(`convertKey error, ${e.code}, ${e.message}`);
          return;
        }
        console.info('key algName: ' + key.algName);
        console.info('key format: ' + key.format);
        let encodedKey = key.getEncoded(); // Obtain the binary data of the symmetric key and output the data as a byte array. The length is 24 bytes.
        console.info('key getEncoded hex: ' + encodedKey.data);
      })
    } catch (error) {// Throw an exception immediately when an error is detected during parameter check.
      let e: BusinessError = error as BusinessError;
      console.error(`convertKey failed, ${e.code}, ${e.message}`);
    }
  }
  ```

- Example using synchronous API [convertKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkeysync12):
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';

  function genKeyMaterialBlob(): cryptoFramework.DataBlob {
    let arr = [
      0xba, 0x3d, 0xc2, 0x71, 0x21, 0x1e, 0x30, 0x56,
      0xad, 0x47, 0xfc, 0x5a, 0x46, 0x39, 0xee, 0x7c,
      0xba, 0x3b, 0xc2, 0x71, 0xab, 0xa0, 0x30, 0x72]; // The key length is 192 bits, that is, 24 bytes.
    let keyMaterial = new Uint8Array(arr);
    return { data: keyMaterial };
  }

  function testConvertSymKey() {
    // Create a SymKeyGenerator instance.
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('3DES192');
    // Convert the data into a symmetric key.
    let keyMaterialBlob = genKeyMaterialBlob();
    let key = symKeyGenerator.convertKeySync(keyMaterialBlob);
    let encodedKey = key.getEncoded(); // Obtain the binary data of the symmetric key and output the data as a byte array. The length is 24 bytes.
    console.info('key getEncoded hex' + encodedKey.data);
  }
  ```

## Converting Binary Data into an HMAC Key

For details about the algorithm specifications, see [HMAC](crypto-sym-key-generation-conversion-spec.md#hmac).

1. Obtain the HMAC binary key and encapsulate it into a **DataBlob** object.

2. Use [cryptoFramework.createSymKeyGenerator](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#cryptoframeworkcreatesymkeygenerator) with the string parameter **'HMAC'** to create a symmetric key generator (**SymKeyGenerator**) object for an HMAC key of [1, 32768] bits.

3. Use [SymKeyGenerator.convertKey](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkey-1) to convert the binary data into a symmetric key (**SymKey**).

4. Use [SymKey.getEncoded](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#getencoded) to obtain the binary data of the key.

- Example: Convert binary data into an HMAC key in await mode.

  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  async function testConvertHmacKey() {
    // The symmetric key length is 64 bytes and 512 bits.
    let keyMessage = '12345678abcdefgh12345678abcdefgh12345678abcdefgh12345678abcdefgh';
    let keyBlob: cryptoFramework.DataBlob = {
      data : new Uint8Array(buffer.from(keyMessage, 'utf-8').buffer)
    }
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('HMAC');
    let key = await symKeyGenerator.convertKey(keyBlob);
    let encodedKey = key.getEncoded();
    console.info('key encoded data: ' + encodedKey.data);
  }
  ```

- Example using synchronous API [convertKeySync](../../reference/apis-crypto-architecture-kit/js-apis-cryptoFramework.md#convertkeysync12):
  ```ts
  import { cryptoFramework } from '@kit.CryptoArchitectureKit';
  import { buffer } from '@kit.ArkTS';

  function testConvertKeySync() {
    // The symmetric key length is 64 bytes and 512 bits.
    let keyMessage = '12345678abcdefgh12345678abcdefgh12345678abcdefgh12345678abcdefgh';
    let keyBlob: cryptoFramework.DataBlob = {
      data : new Uint8Array(buffer.from(keyMessage, 'utf-8').buffer)
    }
    let symKeyGenerator = cryptoFramework.createSymKeyGenerator('HMAC');
    let key = symKeyGenerator.convertKeySync(keyBlob);
    let encodedKey = key.getEncoded();
    console.info('key encoded data: ' + encodedKey.data);
  }
  ```
