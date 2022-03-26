# appspawn Module for the Standard System<a name="EN-US_TOPIC_0000001063680582"></a>

## Overview<a name="section56901555910"></a>

After being started by the init process, the appspawn process waits for inter-process communication (IPC) messages. Upon receiving a message, the appspawn process starts an application service based on the message content, and grants the corresponding permission to the application service.

### Introduction<a name="section56901555911"></a>

- Security control
  <br>Support for setting of SELinux tags for applications

- Application process control

  - Support for setting of AccessToken for applications
  - Support for simultaneous stopping of all spawn application processes (after stopping of the appspawn process and before a restart)

- Cold start
  <br>Support for cold start of applications by using the **aa** command

  ```
  param set appspawn.cold.boot true // Enable cold start.
  aa start -d 12345 -a $name -b $package -C 
  Example:
  aa start -d 12345 -a ohos.acts.startup.sysparam.function.MainAbility -b ohos.acts.startup.sysparam.function -C  
 
### Basic Concepts<a name="section56901555912"></a>

**appspawn** is a registered service name. The appspawn process receives requests from the client by listening to messages over the local socket. The message type is an **AppProperty** structure. It is defined in **base/startup/appspawn_standard/interfaces/innerkits/include/sclient_socket.h**.

**Table 1**  Field description

<table><thead align="left"><tr id="row6650142913713"><th class="cellrowborder" valign="top" width="39.489999999999995%" id="mcps1.2.3.1.1"><p id="p17650112914379"><a name="p17650112914379"></a><a name="p17650112914379"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="60.51%" id="mcps1.2.3.1.2"><p id="p865032916376"><a name="p865032916376"></a><a name="p865032916376"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row36506298373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p76501029113715"><a name="p76501029113715"></a><a name="p76501029113715"></a>processName</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p2650329183715"><a name="p2650329183715"></a><a name="p2650329183715"></a>Name of the service process to be started. The value contains a maximum of 256 bytes.</p>
</td>
</tr>
<tr id="row36506298373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p76501029113715"><a name="p76501029113715"></a><a name="p76501029113715"></a>bundleName</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p2650329183715"><a name="p2650329183715"></a><a name="p2650329183715"></a>Bundle name of the application to be started. The value contains a maximum of 256 bytes.</p>
</td>
</tr>
<tr id="row86501129183712"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p2065010298379"><a name="p2065010298379"></a><a name="p2065010298379"></a>soPath</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p13650192963715"><a name="p13650192963715"></a><a name="p13650192963715"></a>Path of the dynamic library specified by the application. The value contains a maximum of 256 bytes.</p>
</td>
</tr>
<tr id="row13650329103719"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p16501292377"><a name="p16501292377"></a><a name="p16501292377"></a>uid</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p186503291371"><a name="p186503291371"></a><a name="p186503291371"></a>UID of the application process to be started. The value must be a positive number.</p>
</td>
</tr>
<tr id="row187625816314"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p188771758833"><a name="p188771758833"></a><a name="p188771758833"></a>gid</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p187716587310"><a name="p187716587310"></a><a name="p187716587310"></a>GID of the application process to be started. The value must be a positive number.</p>
</td>
</tr>
<tr id="row187625816314"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p188771758833"><a name="p188771758833"></a><a name="p188771758833"></a>gidTable</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p187716587310"><a name="p187716587310"></a><a name="p187716587310"></a>Information about the application process group to be started. Its length is specified by <strong>gidCount</strong>. A maximum of 64 process groups are supported. The value must be a positive number.</p>
</td>
</tr>
<tr id="row187625816314"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p188771758833"><a name="p188771758833"></a><a name="p188771758833"></a>gidCount</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p187716587310"><a name="p187716587310"></a><a name="p187716587310"></a>Number of application process groups to be started.</p>
</td>
</tr>
<tr id="row106508294373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p16501829183715"><a name="p16501829183715"></a><a name="p16501829183715"></a>accessTokenId</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p11650182953717"><a name="p11650182953717"></a><a name="p11650182953717"></a>Token ID for application process permission control.</p>
</td>
</tr>
<tr id="row106508294373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p16501829183715"><a name="p16501829183715"></a><a name="p16501829183715"></a>apl</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p11650182953717"><a name="p11650182953717"></a><a name="p11650182953717"></a> APL for application process permission control. The value contains a maximum of 32 bytes.</p>
</td>
</tr>
</tbody>
</table>

## Development Guidelines<a name="section56901555913"></a>

  The API definitions are provided in **base/startup/appspawn_standard/interfaces/innerkits/include/client_socket.h**. Table 2 is a list of available APIs.

### Available APIs<a name="section56901555914"></a>

**Table 2**  API description
<table><thead align="left"><tr id="row6650142913713"><th class="cellrowborder" valign="top" width="39.489999999999995%" id="mcps1.2.3.1.1"><p id="p17650112914379"><a name="p17650112914379"></a><a name="p17650112914379"></a>API</p>
</th>
<th class="cellrowborder" valign="top" width="60.51%" id="mcps1.2.3.1.2"><p id="p865032916376"><a name="p865032916376"></a><a name="p865032916376"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row36506298373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p76501029113715"><a name="p76501029113715"></a><a name="p76501029113715"></a>CreateClient</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p2650329183715"><a name="p2650329183715"></a><a name="p2650329183715"></a>Creates a client.</p>
</td>
</tr>
<tr id="row36506298373"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p76501029113715"><a name="p76501029113715"></a><a name="p76501029113715"></a>CloseClient</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p2650329183715"><a name="p2650329183715"></a><a name="p2650329183715"></a>Closes a client.</p>
</td>
</tr>
<tr id="row86501129183712"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p2065010298379"><a name="p2065010298379"></a><a name="p2065010298379"></a>ConnectSocket</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p13650192963715"><a name="p13650192963715"></a><a name="p13650192963715"></a>Sends a connection request to the appspawn service.</p>
</td>
</tr>
<tr id="row13650329103719"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p16501292377"><a name="p16501292377"></a><a name="p16501292377"></a>WriteSocketMessage</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p186503291371"><a name="p186503291371"></a><a name="p186503291371"></a>Sends a message to the appspawn service.</p>
</td>
</tr>
<tr id="row187625816314"><td class="cellrowborder" valign="top" width="39.489999999999995%" headers="mcps1.2.3.1.1 "><p id="p188771758833"><a name="p188771758833"></a><a name="p188771758833"></a>ReadSocketMessage</p>
</td>
<td class="cellrowborder" valign="top" width="60.51%" headers="mcps1.2.3.1.2 "><p id="p187716587310"><a name="p187716587310"></a><a name="p187716587310"></a>Receives a message from the appspawn service.</p>
</td>
</tr>
</tbody>
</table>

### Development Example<a name="section56901555915"></a>

<br>The following is an example of using related APIs:
```
    std::shared_ptr<AppSpawn::ClientSocket> clientSocket = std::make_unique<AppSpawn::ClientSocket>("AppSpawn");
    if (clientSocket == nullptr) {
        return -1;
    }
    if (clientSocket->CreateClient() != ERR_OK) {
        return -1;
    }
    if (clientSocket->ConnectSocket() != ERR_OK) {
        return -1;;
    }
    // Construct AppProperty based on the specified property.
    clientSocket->WriteSocketMessage((void *)&property, sizeof(AppSpawn::AppProperty));
    // Read the result.
    int pid;
    clientSocket->ReadSocketMessage((void *)&pid, sizeof(pid));
    // Normally, the process ID of the application is returned. If the PID is less than or equal to 0, an error has occurred.
```

## FAQ<a name="section56901555916"></a>

### Cold Start Failure<a name="section56901555917"></a>

   &emsp; **Symptom**
   <br> &emsp; &emsp; Cold start failed because of a command execution failure.

   &emsp; **Solution**
    <br> &emsp;  &emsp; 1. Check whether cold start is enabled.
    <br> &emsp; &emsp; 2. Check whether the cold start command is correct.
