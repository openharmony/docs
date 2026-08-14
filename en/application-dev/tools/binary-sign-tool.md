# Binary Sign Tool

<!--Kit: Common-->
<!--Subsystem: Security-->
<!--Owner: @zhanganxiang-->
<!--Designer: @renzehua; @huangjieliang; @zhanganxiang-->
<!--Tester: @rongwei-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=2845f22b3a6c7c573421bce7ff3e32f73246613d translatedAt=2026-07-20T10:51:44.450Z pushedAt=2026-08-13T03:06:28.705Z -->

Binary Sign Tool is used for code signing of binary files. It supports signing standard ELF files or printing the permission and certificate information of signed ELF files through the command line.

## Obtaining the Command Line Tool

- Tool for Linux platform: Download the latest [Command Line Tools](command-line-tools-overview.md). You can obtain the **binary-sign-tool** file from **openHarmony/toolchains/lib** of the SDK library.

- Tool for OpenHarmony PC/2-in-1 device: Download and install DevBox from AppGallery. You can run the **binary-sign-tool** command in the terminal window without additional configuration.

- Tool for Java platform: Download [command line tools](command-line-tools-overview.md) of API 24 or later. You can obtain the tool file **binary-sign-tool.jar** from the SDK library **openHarmony/toolchains/lib**. The tools require JDK 8 or later.

## Commands

| Command         | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| help          | Displays the commands supported by the tool.                        |
| sign          | Signs a binary file.                  |
| display-sign  | Prints the certificate information of the file signature.            |

## help

```bash
# Java version command example:
java -jar binary-sign-tool.jar -help

# C++ version command example:
binary-sign-tool -help
```

## sign

Signs a binary file using certificate-signed or self-signed.<!--RP1--><!--RP1End-->

**Parameters**

| Parameter            | Description              |
| ---------------- | ---------------------- |
| -keyAlias        | Key alias, a required parameter for certificate-signed, case-insensitive.    |
| -keyPwd          | Key password, which is optional.|
| -appCertFile     | Signing certificate file (certificate chain, in the order of entity certificate, intermediate CA certificate, and root certificate), a required parameter for certificate-signed.  |
| -signAlg         | Signing algorithm, which can be **SHA256withECDSA** or **SHA384withECDSA**. This parameter is mandatory.|
| -keystoreFile    | Keystore file, mandatory for certificate-signed.     |
| -keystorePwd     | Keystore password, which is optional.|
| -inFile          | Original ELF file, which is mandatory.   |
| -outFile         | Signed file, which is mandatory.|
| -moduleFile      | Permission **module.json** file, which is optional.    |
| -selfSign        | Whether the signing mode is self-signed. **1** indicates self-signed, **0** indicates certificate-signed. The default value is **0**. This is an optional parameter. |

**Example**

```bash
# 1. Sign the binary file using a certificate.
# Note: Replace keyAlias, appCertFile, keystoreFile, keyPwd, and keystorePwd with your own certificate and key.
# Java version command example:
java -jar binary-sign-tool.jar sign -keyAlias "test" -signAlg "SHA256withECDSA" -appCertFile "test.cer" -inFile "unsigned-elf" -keystoreFile "test.p12" -outFile "signed-elf" -keyPwd "123456" -keystorePwd "123456" -moduleFile "module.json"

# C++ version command example:
binary-sign-tool sign -keyAlias "test" -signAlg "SHA256withECDSA" -appCertFile "test.cer" -inFile "unsigned-elf" -keystoreFile "test.p12" -outFile "signed-elf" -keyPwd "123456" -keystorePwd "123456" -moduleFile "module.json"

# 2. Sign the binary file in self-signed mode.
# Java version command example:
java -jar binary-sign-tool.jar sign -inFile "unsigned-elf" -outFile "signed-elf" -selfSign "1"

# C++ version command example:
binary-sign-tool sign -inFile "unsigned-elf" -outFile "signed-elf" -selfSign "1"

# Command output:
write code sign data success.
```

## display-sign

**Parameters**

| Parameter            | Description              |
| ---------------- | ---------------------- |
| -inFile          | ELF file, which is mandatory.   |

**Example**

```bash
# Sample command for the Java version:
java -jar binary-sign-tool.jar display-sign -inFile "signed-elf"

# Sample command for the C++ version:
binary-sign-tool display-sign -inFile "signed-elf"

# Command output:
# Permission information output
# 1. No permission information
permission is not found
# 2. Output permission information
# Signature information output
# 1. No code signature.
code signature is not found
# 2. Self-signed mode.
code signature is self-sign
# 3. Output the signing certificate.
```

## Error Message

### FILE_NOT_FOUND

**Description**

When running the command, the following error message is displayed: `ERROR - FILE_NOT_FOUND, code: -102. Details: The 'test.p12' file does not exist or the path is invalid, parameter name '-keystoreFile'`

**Possible Causes**

The input file does not exist or the path is incorrect.

**Solution**

Check whether the input file path or file name is correct.

### COMMAND_PARAM_ERROR

**Description**

When the command is executed, the error message "ERROR - COMMAND_PARAM_ERROR, code: -107. Details: 'generate-cert' Parameters error, Param key - value must in pairs" is displayed.

**Possible Causes**

1. An unnecessary part is pasted in the command.

2. The **value** of the last parameter is not entered.

**Solution**

Check and correct the unnecessary or incorrect part in the command.

### KEY_PASSWORD_ERROR

**Description**

When running the command, the following error message is displayed: `ERROR - KEY_PASSWORD_ERROR, code: -114. Details: 'test' keypair password error`

**Possible Causes**

If the key pair password is incorrect, the **KEY_PASSWORD_ERROR** error occurs.

**Solution**

Check whether the password parameter in the command is correct. Ensure that the key pair password is correct when accessing different keystores.

### NOT_SUPPORT_ERROR

**Description**

When running the command, the following error message is displayed: `ERROR - NOT_SUPPORT_ERROR, code: -104. Details: Not support file: ./test.p12`

**Possible Causes**

The keystore file type is incorrect.

**Solution**

Ensure that the keystore file name extension is **.p12**.

### KEY_ALIAS_ERROR

**Description**

When the command is executed, the error message "ERROR - KEY_ALIAS_ERROR, code: -109. Details: 'XXX' key alias already exists and cannot be generated repeatedly" is displayed.

**Possible Causes**

The key pair with the same alias already exists in the keystore.

**Solution**

Rename the alias of the key pair.

### SIGN_ERROR

**Description**

After the command is executed, the error message "ERROR - SIGN_ERROR, code: -105. Details: No certificates configured for sign" is displayed.

**Possible Causes**

The signing key does not match the entity certificate.

**Solution**

1. Check whether the **keyAlias** key is correct.

2. Check whether the **appCertFile** is correct. Ensure that the key matches the certificate.