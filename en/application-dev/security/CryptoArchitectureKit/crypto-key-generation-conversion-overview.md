# Key Generation and Conversion Overview

<!--Kit: Crypto Architecture Kit-->
<!--Subsystem: Security-->
<!--Owner: @zxz--3-->
<!--Designer: @lanming-->
<!--Tester: @PAFT-->
<!--Adviser: @zengyawen-->

Typical key generation operations involve the following:

1. Randomly create a key object for subsequent encryption and decryption.

2. Convert external or internal binary data into a key object for subsequent encryption and decryption.

3. Create a key object based on the specified key parameter for subsequent encryption and decryption.

4. Obtain the binary data of a key object for storage or transmission.

5. Obtain the properties of an asymmetric key object for storage or transmission.

The key object can be a symmetric key object (**SymKey**) or an asymmetric key pair object (**KeyPair**). The **KeyPair** object consists a public key (**PubKey**) and a private key (**PriKey**).
