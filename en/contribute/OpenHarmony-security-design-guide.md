# OpenHarmony Security Design Specifications

With reference to industry standards and best practices, this document provides OpenHarmony security design specifications.

## 1\. Access Channel Control

1-1 To prevent unauthorized access to the system and resources, all system management interfaces unless otherwise specified by standards protocols must be provided with access control mechanisms (enabled by default).

**Description**: To reduce the attack surface of the system, authentication mechanisms must be enabled for system management interfaces (including those used for configuration, upgrade, and commissioning) to prevent unauthorized access.

1-2 All external connections of the system must be necessary for system operation and maintenance. All unnecessary connections and ports must be disabled.

**Description**: Disabling unnecessary communication ports can greatly reduce security threats and is a basic means of system security protection.

## 2\. Application Security

2-1 The session ID and user permission must be verified for each access request if authorization is required.

**Description**: It is a means to prevent unauthorized access.

2-2 User authentication must be conducted on the server since it may be easily bypassed if being conducted on the client.

## 3. Encryption

3-1 Use verified, secure, and open encryption algorithms.

**Description**: The security of an algorithm does not mean its confidentiality.

**Example**: 

Recommended cipher algorithms are as follows:

- Block cipher algorithm: AES (key length of 128 bits or longer)  
- Stream cipher algorithm: AES (key length of 128 bits or longer) (OFB/CTR mode)   
- Asymmetric encryption algorithm: RSA (recommended: 3072 bits)   
- Hash algorithm: SHA-2 (256 bits or longer)  
- Key exchange algorithm: DH (recommended: 3072 bits)  
- Hash-based message authentication code (HMAC) algorithm: HMAC-SHA-2  

The following are examples of insecure cipher algorithms: 

MD5, DES, 3DES (Do not use 3DES in TLS/SSH, and ensure K1≠K2≠K3 in non-cryptographic protocols), HMAC-SHA2-256-96, HMAC-SHA1-96, HMAC-MD5, HMAC-MD5-96, SSH CBC, anonymous algorithm suites, DH512, DH1024, SKIPJACK, RC2, RSA (1024 bits or shorter), MD2, MD4, Blowfish, RC4 

3-2 Do not use algorithms for error control coding, such as parity check and CRC, to perform integrity check, unless otherwise specified in standard protocols.

3-3 Cipher algorithms must use cryptographically secure random numbers for security purposes.

**Description**: The use of insecure random numbers may easily weaken a cipher algorithm or even render it ineffective.

**Example**: 

The following interfaces can be used to generate secure random numbers:

- **RAND\_bytes** or **RAND\_priv\_bytes** of OpenSSL
- DRBG implemented in the OpenSSL FIPS module
- **java.security.SecureRandom** of the JDK  
- **/dev/random** file of Unix-like platforms

3-4 By default, use secure cipher algorithms and disable/prohibit insecure cipher algorithms. Use cipher algorithm libraries that are certified by authoritative organizations, recognized by open-source communities in the industry, or assessed and approved by OpenHarmony.

**Description**: In the context of advances in cryptographic technologies and enhancement in computing capabilities, some cipher algorithms may become insecure. Using such algorithms may bring risks to user data. In addition, unknown flaws may exist in cipher algorithms that are developed by amateurs and not analyzed/verified by the industry. In this regard, use cipher algorithm libraries that are certified by authoritative organizations, recognized by open-source communities in the industry, or assessed and approved by OpenHarmony.

**Example**: See 3-1.

3-5 The GCM mode is preferred when block cipher algorithms are used.

3-6 The OAEP padding scheme is preferred when RSA is used for encryption.

**Description**: PKCS1 padding has been known to be insecure in the industry and academic field. If OAEP padding is not used, attackers can easily decrypt the ciphertext.

3-7 Do not use private keys to encrypt sensitive data when asymmetric encryption is used for protecting data confidentiality.

**Description**: Using private key for encryption cannot ensure data confidentiality.

3-8 Use different key pairs for asymmetric encryption and signing.

3-9 Use the sign-then-encrypt mode when both symmetric encryption and digital signature are required. Check the order in which cipher algorithms are called, and do not sign cipher text hashes (i.e., do not perform private key operations on cipher text hashes).

**Description**: If a cipher text is signed (i.e., the cipher text hash is signed), attackers can obtain the cipher text hash (also the cipher text) through network sniffing. In this case, attackers can tamper with the ciphertext signature.

3-10 If the public keys received from peers during key exchange using the DH algorithm are special public keys 0, 1, p-1, or p, negotiation must be performed again.

**Description**: If the public keys received from peers during key exchange using the DH algorithm are special key values, the negotiated keys must also be known values. In this case, attackers may easily decrypt the cipher text within five attempts.

3-11 In SSL and TLS protocols, if DH or ECDH algorithm is used for key exchange, use the cipher suite that contains DHE or ECDHE key exchange algorithm to achieve perfect forward secrecy; do not use the cipher suite that only contains DH/ECDH.

3-12 Do not use truncated message authentication codes (MACs) in cryptographic protocols.

**Description**: In cryptographic protocols (such as TLS, SSH, and IKE), MACs are usually used to verify the integrity of messages. Some protocols support truncated MACs. Truncation reduces MAC security. For example, SLOTH attacks against multiple cryptographic protocols (such as TLS and SSH) may craft collisions using truncated hash values.

**Example**: 

The following are examples of truncated MACs: 

The standard output lengths of HMAC-MD5-96, HMAC-SHA1-96, and HMAC-SHA2-256-96 configured in SSH are listed below. A shorter length is considered a truncation. 

- SHA-1/HMAC-SHA-1: The standard output length is 160 bits.  
- SHA-224/HMAC-SHA-224: The standard output length is 224 bits.  
- SHA-256/HMAC-SHA-256: The standard output length is 256 bits.  
- SHA-384/HMAC-SHA-384: The standard output length is 384 bits.  
- SHA-512/HMAC-SHA-512: The standard output length is 512 bits.  
- SHA-512/224/HMAC-SHA-512/224: The standard output length is 224 bits.  
- SHA-512/256/HMAC-SHA-512/256: The standard output length is 256 bits.

3-13 When HMAC is used for data integrity protection, do not use the calculation result of hash(key\|\|message) or hash(message\|\|key) as the MAC value.

**Description**: Attackers may add any information to the end of the original plaintext information to compromise data integrity.

3-14 Use different symmetric keys for data encryption and MAC calculation in the same transaction.

**Description**: If the same key is used for data encryption and MAC calculation, key exposure creates vulnerabilities for attackers to tamper with confidential information. 	 

3-15 Do not use fixed IVs (for example, IVs hard-coded or fixed in configuration files) for encryption.

**Description**: The randomness of IV in CBC mode ensures the generation of different cipher texts based on the same piece of data in plain text and key. If such randomness cannot be ensured, attackers can easily replace the cipher text. For other block cipher modes, such as OFB and CRT, attackers can easily decrypt the cipher text.

3-16 Do not select anonymous authentication, non-encryption, weak authentication, weak key exchange, weak symmetric key algorithms, or weak message authentication algorithm cipher suites in cryptographic protocols.

**Description**: Their use may compromise system security.

**Example**:

The following are examples of anonymous authentication: 

TLS\_DH\_anon\_WITH\_3DES\_EDE\_CBC\_SHA and TLS\_DH\_anon\_WITH\_AES\_256\_CBC\_SHA  

The following is an example of weak authentication: 

RSA/DSA, with a key length less than 2048 bits

3-17 It is recommended that only ECDHE be used as the cipher suite of the key exchange algorithm.

3-18 Do not hardcode keys used for data encryption/decryption. Use the root key or other means for encryption, and protect the root key with a proper security mechanism (for example, hardcode only some key components).

**Description**: Hard-coded keys are likely to be cracked by reverse engineering.

3-19 It is recommended that the function design cover the working key update methods (such as manual or automatic key update) and update rules (online update, offline update, and update time, etc.).

**Description**: The longer a key is in use, the more likely it is to be cracked. The larger the amount of data encrypted using the key, the greater the chance for attackers to obtain ciphertext data as it is easier to analyze the ciphertexts encrypted using the same key. If the key is leaked, the loss incurred increases with its service period.

**Example**: The system generates new keys based on key generation rules, uses the old key to decrypt the data, uses the new key to encrypt the data again, and destroys the old key. In scenarios where mass data needs to be encrypted, consider reserving the old key to decrypt the old data and use the new key to encrypt the new data.

3-20 Key materials and components must be subject to strict access control (such as permission 600 or 400).

3-21 For keys saved in memory, overwrite the memory by other data (such as 0x00) before freeing it.

## 4. Sensitive Data Protection

4-1 Store authentication credentials such as passwords in ciphertext and apply access control.

4-2 Use irreversible algorithms such as PBKDF2 for encryption in scenarios where authentication credentials do not need to be restored. HMAC (authentication credentials and salt values) can be used in scenarios where performance is sensitive and the security requirement is not high. (Note: Password and salt value locations can be exchanged.)

**Example**: 

- When calculating the one-way password hash using PBKDF2, the number of iterations is at least 1000. 
- A salt value is a cryptographically secure random number generated by the system. The salt value has at least 16 bytes and is unique to each user. 
- Avoid using HASH (user name\|\|password), HMAC (user name, password), and HASH (password XOR salt).

4-3 If sensitive data needs to be transmitted over untrusted networks, ensure that sensitive data is transmitted over secure paths or is transmitted after being encrypted.

4-4 For access to sensitive data, use appropriate security mechanisms (such as authentication, authorization, or encryption) based on risks. Files and directories containing sensitive data (for example, configuration files, log files, personal sensitive data files, user password files, key files, certificate files, drive files, and backup files) shall be accessible only to their owners or permitted users.

4-5 Filter out or shield authentication credentials in logs, debugging information, and error messages.

## 5. System Management and Maintenance Security

5-1 Adopt one or more of the following protection measures for login authentication on system O\&M interfaces to support anti-brute force cracking based on actual scenarios and risks: 

- Account lockout 
- IP address lockout
- Login postponed
- Verification code required

5-2 By default, all the passwords entered by users on the GUI for system O\&M purposes are not displayed in plaintext.

5-3 The password in a text box cannot be copied out.

5-4 Use appropriate security protocols, and disable insecure protocols by default.

**Example**: 

The following are examples of security protocols: 

SSHv2, TLS 1.2, TLS 1.3, IPsec, SFTP, SNMPv3, and their latest versions 

It is recommended that AES in OFB or CTR mode or ChaCha20 be used to replace RC4. 

The following are examples of insecure protocols: 

TFTP, FTP, Telnet, SSL 2.0, SSL 3.0, TLS 1.0, TLS 1.1, SNMPv1/v2, and SSHv1.x

5-5 Do not assign a role to a new account or assign a role with the least privilege (for example, read only) by default in line with the principle of least privilege.

**Description**: In this way, unauthorized users cannot but obtain the least privilege when the authorization mechanism is faulty or bypassed.

## 6. Privacy Protection

6-1 Explicitly notify users and obtain their consent before collecting/using their personal data or forwarding the data to third parties.

**Description**: It is to increase transparency and grant users more control over their data in compliance with laws and regulations such as GDPR.

6-2 Provide necessary security protection mechanisms (such as authentication, access control, and logging) for personal data collection, processing, and storage as required by normal services to prevent personal data from being disclosed, lost, or damaged.

6-3 Describe the product functions involving user privacy in documentation, including the purpose, scope, method, and period of personal data processing, and require that the function should be used in compliance with local laws and regulations.

**Description**: It is to increase transparency in compliance with laws and regulations such as GDPR.

6-4 Support filtering, anonymization, or pseudonymization for personal data to be displayed (for example, on UIs or in stored or exported files).

**Description**: It is to reduce the risk of personal privacy breaches.

6-5 To prevent location tracking, do not identify precise locations of users for maintenance purposes (such as troubleshooting) unless it is explicitly required.

**Description**: Precise location information is very sensitive, and is not needed in troubleshooting.

6-6 Collect personal data necessary for stated purposes in compliance with the data minimization principle. Comply with the data minimization principle when displaying personal data in fault diagnosis logs.

**Description**: The display of personal data in fault diagnosis logs may arouse users' doubts. Therefore, personal data should not be displayed in fault diagnosis logs. If it has to be displayed (for example, for debugging purpose) anonymization is required.

6-7 In scenarios involving personal data processing, provide mechanisms to ensure that data subjects can query, update, and erase their personal data.

**Description**: It is to protect data subjects' rights.

## Terms

| No.  |             Term             | Definition                                                   |
| :--: | :--------------------------: | ------------------------------------------------------------ |
|  1   |        anonymization         | A process of irreversibly de-identifying personal data such that the person cannot be identified by using reasonable time, cost, technology either by the controller or by any other person to identify that individual. |
|  2   |  authentication credential   | Private or public data declared to prove identity authenticity. Common authentication credentials include passwords, pre-shared keys, private keys, SNMP community names, smart cards, dynamic tokens, fingerprints, and retinas. |
|  3   |         data subject         | An individual who provides the data controller and processor with personal data. A data subject can be identified directly by personal data (such as a name) or indirectly by the combination of personal data. |
|  4   |        personal data         | Any information relating to an identified or identifiable natural person ("data subject") who can be identified, directly or indirectly, in particular by reference to an identifier such as a name, an identification number, and location data or to one or more factors specific to the physical, physiological, genetic, mental, economic, cultural, or social identity of that natural person. Personal data includes a natural person's email address, telephone number, biometric information (such as a fingerprint), location data, IP address, health care information, religious belief, social security number, marital status, and so on. |
|  5   | precise location information | Precise longitude and latitude. For example, the GPS can locate an object with the precision of dozens of meters. The criterion of precise location information is that the information is precise enough for locating a natural person. |
|  6   |       pseudonymization       | In order to restrict the ability of using personal data to identify a data subject, identity information contained in personal data can be replaced by aliases. The substitution is considered pseudonymization, which has the following features: (1) The remaining attributes linked to the alias do not suffice to identify the data subject to whom they relate; and (2) The alias assignment cannot be reversed by reasonable efforts of the privacy stakeholders (such as the data controller) other than those that performed assignment. Pseudonymized data is still personal data. Pseudonyms are also known as aliases. |
|  7   |        sensitive data        | The scope of sensitive data varies with product application scenarios, and should be analyzed and determined based on risks in specific scenarios. Typical sensitive data includes authentication credentials (such as passwords, private keys, and dynamic token cards), encryption keys, sensitive personal data, etc. |
|  8   |   sensitive personal data    | An important subset of personal data, referring to the information involving most private data of a data subject, or the data, once leaked or modified, may result in adverse impacts to a data subject. Sensitive personal data includes data revealing racial or ethnic origin, political opinions, religious or philosophical beliefs, trade-union membership, genetic data, biometric information, data concerning health, sex life, or sexual orientation, as well as bank account numbers, ID card numbers, passports, passwords, and other information associated with a natural person's identity. Sensitive personal data requires additional and stricter protection measures. |
|  9   |      standard protocol       | An international standard protocol (e.g., ETSI, 3GPP, or ITU-T standard, or that from some other standard-setting organization), regional standard (e.g., standard developed by the European Union), national industry standard (e.g., standard formulated by the Ministry of Industry and Information Technology of China), or de facto industry standard (e.g., industry standard defined by UPnP). |

