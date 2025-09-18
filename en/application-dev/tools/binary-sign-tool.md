# Binary Sign Tool

Binary Sign Tool is used to sign code of binary files on OpenHarmony PC/2in1 devices. You can sign code of standard ELF files or print certificate information of signed ELF files in CLI mode.
You can find the tool in toolchains/lib of the OpenHarmony SDK library downloaded locally. The file name is binary-sign-tool.

## Environment
Before using this tool, you need to obtain the [hdc](../dfx/hdc.md) tool and run the hdc shell command.

## Binary Sign Tool Commands

| Command         | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| help          | Help command, which is used to query the commands supported by the tool.                        |
| sign          | Signs a binary file.                  |
| display-sign  | Prints the certificate information of a file signature.            |

## help

```bash
# Displays the help information.
binary-sign-tool -help
```

## sign

**Parameters**

| Parameter            | Description              |
| ---------------- | ---------------------- |
| -keyAlias        | Key alias, which is mandatory and case-insensitive.   |
| -keyPwd          | Key password, which is optional.|
| -appCertFile     | Signature certificate file (certificate chain, in the sequence of entity certificate - intermediate CA certificate - root certificate), which is mandatory. |
| -profileFile     | Name of the provision profile file after signing, in P7B format, which is optional.|
| -profileSigned   | Whether the profile file is signed. The value 1 indicates that the profile file is signed, and the value 0 indicates that the profile file is not signed. The default value is 1. This parameter is optional.  |
| -signAlg         | Signature algorithm, which is mandatory. The value can be SHA256withECDSA or SHA384withECDSA.|
| -keystoreFile    | Keystore file, which is mandatory in non-self-signed mode.    |
| -keystorePwd     | Keystore password, which is optional.|
| -inFile          | Original ELF file, which is mandatory.   |
| -outFile         | Output file after signing, which is mandatory.|
| -moduleFile      | Permission module.json file, which is optional.    |
| -selfSign        | Whether the local self-signed mode is used. The value 1 indicates that the local self-signed mode is used, and the value 0 indicates that the certificate signature mode is used. The default value is 0. This parameter is optional.|

**Example**:

```bash
# Signs a binary file.
binary-sign-tool sign -keyAlias "oh-app1-key-v1" -signAlg "SHA256withECDSA" -appCertFile "app1.pem" -profileFile "app1-profile.p7b" -profileSigned "1" -inFile "unsigned-elf" -keystoreFile "ohtest.p12" -outFile "signed-elf" -keyPwd "123456" -keystorePwd "123456" -moduleFile "module.json"
# Command output:
write code sign data success.
```

## display-sign

**Parameters**

| Parameter            | Description              |
| ---------------- | ---------------------- |
| -inFile          | (Required) ELF file.   |

**Example**:

```bash
# Prints the signature certificate information of a binary file.
binary-sign-tool display-sign -inFile "signed-elf"
# Execution result
# 1. No code signature
code signature is not found
# 2. Self-signed mode
code signature is self-sign
# 3. Output signature certificate
```

## Error Message

### FILE_NOT_FOUND

**Description**

`ERROR - FILE_NOT_FOUND, code: -102. Details: The 'OpenHarmony.p12' file does not exist or the path is invalid, parameter name '-keystoreFile'` is displayed.

**Possible Causes**

The input file does not exist or the path is incorrect.

**Solution**

Check whether the input file path or file name is correct.

### COMMAND_PARAM_ERROR

**Description**

What Do I Do If the Error Message "`ERROR - COMMAND_PARAM_ERROR, code: -107. Details: 'generate-cert' Parameters error, Param key - value must in pairs`" Is Displayed When I Run a Command?

**Possible Causes**

1. An unnecessary part is pasted in the command, and COMMAND_PARAM_ERROR is displayed.
2. COMMAND_PARAM_ERROR is displayed if the value of the last parameter is not set.

**Solution**

Check and correct the unnecessary or incorrect part in the command.

### KEY_PASSWORD_ERROR

**Description**

What Do I Do If the Error Message "`ERROR - KEY_PASSWORD_ERROR, code: -114. Details: 'oh-app1-key-v1' keypair password error`" Is Displayed When I Run a Command?

**Possible Causes**

KEY_PASSWORD_ERROR is displayed if the key pair password is incorrect.

**Solution**

Check whether the password in the command is correct. Ensure that the key pair password of each keystore is correct.

### NOT_SUPPORT_ERROR

**Description**

What Do I Do If the Error Message "`ERROR - NOT_SUPPORT_ERROR, code: -104. Details: Not support file: ./OpenHarmony.p12`" Is Displayed When I Run a Command?

**Possible Causes**

NOT_SUPPORT_ERROR is displayed if the keystore file type is incorrect.

**Solution**

Ensure that the keystore file name extension is `.p12`.

### KEY_ALIAS_ERROR

**Description**

What Do I Do If the Error Message "`ERROR - KEY_ALIAS_ERROR, code: -109. Details: 'XXX' key alias already exists and cannot be generated repeatedly`" Is Displayed When I Run a Command?

**Possible Causes**

If the key pair with the alias already exists in the keystore, KEY_ALIAS_ERROR will be reported.

**Solution**

Replace the alias of the key pair to be generated with another name.

### SIGN_ERROR

**Description**

After the command is executed, the error message "`ERROR - SIGN_ERROR, code: -105. Details: No certificates configured for sign`" is displayed.

**Possible Causes**

The signature key does not match the entity certificate.

**Solution**

1. Check whether the keyAlias key is correct.
2. Check whether the appCertFile is correct. Ensure that the key matches the certificate.
