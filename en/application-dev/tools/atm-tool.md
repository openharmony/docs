# Access Token Manager

Access Token Manager (atm) is a tool used to query<!--Del--> and set<!--DelEnd--> the information such as permission and usage type of an application process. It provides the capability of access control based on the token ID, bundle name, and process name.

## Environment Setup
Before using this tool, you must obtain [hdc](../dfx/hdc.md) and run the **hdc shell** command.

## Commands

| Command               | Description|
| ------------------- | -----------|
| help                | Displays the commands supported by the atm tool.|
| <!--DelRow-->perm   | Grants or revokes a permission for an application process.|
| <!--DelRow-->toggle | Sets or obtains the toggle state of a permission.|
| dump                | Obtains access control data.|

## help

```bash
# Display the help information.
atm help
```


<!--Del-->

## perm
```bash
atm perm [-h] [-g -i <token-id> -p <permission-name>] [-c -i <token-id> -p <permission-name>]
```

**Parameters of the perm command**
| Parameter                                              | Description                 | 
| -------------------------------------------------- | ---------------------- | 
| -h                                        | Displays help information.| Commands supported by the **atm perm** command.|
| -g&nbsp;-i \<token-id\>&nbsp;-p \<permission-name\> | Grants a specified permission to an application based on the token ID of the application process. The **-g**, **-i**, and **-p** parameters are mandatory. The return value indicates whether the operation is successful.   | 
| -c&nbsp;-i \<token-id\>&nbsp;-p \<permission-name\> | Cancels a specified permission for an application based on the token ID of the application process. The **-c**, **-i**, and **-p** parameters are mandatory. The return value indicates whether the operation is successful.   | 

Example:

```bash
# Display the help information about the atm perm command.
atm perm -h

# Grant the camera permission to an application process.
atm perm -g -i ********* -p ohos.permission.CAMERA

# Revoke the camera permission for an application process.
atm perm -c -i ********* -p ohos.permission.CAMERA
```


## toggle

```bash
atm toggle [-h] [-s -u <user-id> -p <permission-name> -k <status>] [-o -u <user-id> -p <permission-name>]
```
**Parameters of the toggle command**

| Parameter                                                          | Description                               | 
| ----------------------------------------------------------------- | ----------------------------------- | 
| -h                                                     | Displays help information.             | 
| -s&nbsp;-u \<user-id\>&nbsp;-p \<permission-name\>&nbsp;-k \<status\> | Sets the toggle state (specified by status) of a specified permission of a specified user. The **-c**, **-i**, **-p** and **-k** parameters are mandatory. The return value indicates whether the operation is successful.| 
| -o&nbsp;-u \<user-id\>&nbsp;-p \<permission-name\> | Obtains the toggle state of a specified permission for a specified user. The **-o**, **-u**, and **-p** parameters are mandatory.| 

Example:

```bash
# Display the help information about the atm toggle command.
atm toggle -h

# Enable the camera permission for user 0.
atm toggle -s -u 0 -p ohos.permission.CAMERA -k 1

# Obtain the toggle state of the camera permission for user 0.
atm toggle -o -u 0 -p ohos.permission.CAMERA
```

<!--DelEnd-->


## dump

<!--RP1-->
```bash
atm dump [-h] [-t [-i <token-id>] [-b <bundle-name>] [-n <process-name>]] [-r [-i <token-id>] [-p <permission-name>]] [-v [-i <token-id>] [-p <permission-name>]]
```
<!--RP1End-->

In the following commands, the **-t**, <!--Del-->**-r** <!--DelEnd-->and **-v** parameters are mandatory, and the *-i*, *-b*, *-n* and *-p* parameters are optional. For <!--Del-->**atm dump -r** and <!--DelEnd-->**atm dump -v**, the *-i* and *-p* parameters can be used together. For **atm dump -t**, the *-i*, *-b*, and *-n* parameters can only be used independently.

| Parameter                                         | Description                                                | 
| ----------------------------------------------- | ---------------------------------------------------- | 
| -h                                     | Displays help information.                             | 
| -t                                     | Dumps information about all application processes in the system. This parameter is mandatory.                            | 
| -t&nbsp;-i \<token-id\>                     | Dumps the permission information of an application based on the token ID of the application process. This parameter is optional.            | 
| -t&nbsp;-b \<bundle-name\>                  |  Dumps the permission information of an application based on the bundle name of the application process. This parameter is optional.    | 
| -t&nbsp;-n \<process-name\>                 |  Dumps the permission information of an application based on the process name of the application process. This parameter is optional. |
| <!--DelRow-->-r                        |  Dumps all permission usage records in the system. This parameter is mandatory.                          | 
| <!--DelRow-->-r&nbsp;-i \<token-id\>        | Dumps the permission usage records of an application based on the token ID of the application process. This parameter is optional.       | 
| <!--DelRow-->-r&nbsp;-p \<permission-name\> | Dumps the usage records of a permission with the specified permission name. This parameter is optional.                       |
| -v                                     | Dumps the permission usage types of all application processes in the system. This parameter is mandatory.                   | 
| -v&nbsp;-i \<token-id\>                     | Dumps the permission usage types of an application based on the token ID of the application process. This parameter is optional.        | 
| -v&nbsp;-p \<permission-name\>              | Dumps the usage types of a permission with the specified permission name. This parameter is optional.                       | 

Example:

```bash
#Display the help information about the atm dump command.
atm dump -h

#Dump the token IDs and bundle names of all application processes in the system.
atm dump -t

#Dump the permission information based on the token ID.
atm dump -t -i *********

#Dump the permission information based on the bundle name.
atm dump -t -b ohos.telephony.resources

#Dump the permission information based on the process name.
atm dump -t -n *********

#Dump the permission types of all applications.
atm dump -v

#Dump the permission usage types based on the token ID.
atm dump -v -i *********

#Dump the permission usage types based on the permission name.
atm dump -v -p ohos.permission.CAMERA

#Dump the permission usage types based on the token ID and permission name.
atm dump -v -i ********* -p ohos.permission.CAMERA
```

<!--Del-->
```bash
#Dump all permission usage records in the system.
atm dump -r

#Dump the permission usage records based on the token ID.
atm dump -r -i *********

#Dump the permission usage records based on the permission name.
atm dump -r -p ohos.permission.CAMERA

#Dump the permission usage records based on the token ID and permission name.
atm dump -r -i ********* -p ohos.permission.CAMERA
```
<!--DelEnd-->
