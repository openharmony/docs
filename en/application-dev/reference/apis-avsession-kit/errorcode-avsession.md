# AVSession Management Error Codes
 <!--Kit: AVSession Kit-->
<!--Subsystem: Multimedia-->
<!--Owner: @ccfriend; @liao_qian-->
<!--Designer: @ccfriend-->
<!--Tester: @chenmingxi1_huawei-->
<!--Adviser: @zengyawen-->

> **NOTE**
>
> This topic describes only module-specific error codes. For details about universal error codes, see [Universal Error Codes](../errorcode-universal.md).

## 6600101 Session Service Exception

**Error Message**

Session service exception.

**Description**

The session service is abnormal, and the application cannot obtain a response from the session service. For example, the session service is not running or the communication with the session service fails.

**Possible Causes**

The session service is killed during session restart.

**Solution**

1. The system retries the operation automatically. If the error persists for 3 seconds or more, stop the operation on the session or controller.

2. Destroy the current session or session controller and re-create it. If the re-creation fails, stop the operation on the session.

## 6600102 Session Does Not Exist

**Error Message**

The session does not exist.

**Description**

Parameters are set for or commands are sent to the session that does not exist.

**Possible Causes**

The session has been destroyed, and no session record exists on the server.

**Solution**

1. If the error occurs on the application, re-create the session. If the error occurs on Media Controller, stop sending query or control commands to the session.

2. If the error occurs on the session service, query the current session record and pass the correct session ID when creating the controller.

## 6600103 Session Controller Does Not Exist

**Error Message**

The session controller does not exist.

**Description**

A control command or an event is sent to the controller that does not exist.

**Possible Causes**

The controller has been destroyed.

**Solution**

Query the session record and create the corresponding controller.

<!--Del-->
## 6600104 Remote Session Connection Failure

**Error Message**

The remote session connection failed.

**Description**

The communication between the local session and the remote session fails.

**Possible Causes**

The communication between devices is interrupted.

**Solution**

Stop sending control commands to the session. Subscribe to output device changes, and resume the sending when the output device is changed.
<!--DelEnd-->

## 6600105 Invalid Session Command

**Error Message**

Invalid session command.

**Description**

The control command or event sent to the session is not supported.

**Possible Causes**

The session does not support this command.

**Solution**

Stop sending the command or event. Query the commands supported by the session, and send a command supported.

## 6600106 Session Not Activated

**Error Message**

The session is not activated.

**Description**

A control command or event is sent to the session that is not activated.

**Possible Causes**

The session is in the inactive state.

**Solution**

Stop sending the command or event. Subscribe to the session activation status, and resume the sending when the session is activated.

## 6600107 Too Many Commands or Events

**Error Message**

Too many commands or events.

**Description**

The session client sends too many messages or commands to the server in a period of time, causing the server to be overloaded.

**Possible Causes**

The server is overloaded with messages or events.

**Solution**

Control the frequency of sending commands or events.

<!--Del-->
## 6600108 Device Connection Failure

**Error Message**

Device connection failed.

**Description**

Connection to the device fails.

**Possible Causes**

The device connection logic is abnormal or the device status is abnormal.

**Solution**

Refresh the device list and check whether the device is offline.
<!--DelEnd-->

## 6600109 Remote Session Does Not Exist

**Error Message**

The remote connection is not established.

**Description**

The remote session does not exist, and the related API calls fail.

**Possible Causes**

The remote session has been destroyed or has not been created.

**Solution**

Query the session status again to determine whether the remote session exists.

## 6611000 Unknown Error in the Cast Controller

**Error Message**

The error code for cast control is unspecified.

**Description**

An unknown error occurs in the cast controller.

**Possible Causes**

1. Failure in status switching: The device does not support a quick transition from the current transmission state to the required state.

2. Device authentication failure: The authentication between the local and remote devices fails.

3. Invalid instance: The current instance ID is invalid for AVTransport.

**Solution**

Initiate the session again.

## 6611001 Unknown Error in the Remote Device

**Error Message**

An unspecified error occurs in the remote player.

**Description**

An unknown error occurs in the remote device.

**Possible Causes**

The remote device is abnormal.

**Solution**

Restart the remote device and initiate the session again.

## 6611002 Loading Position Exceeds the Total Video Progress

**Error Message**

The playback position falls behind the live window.

**Description**

The loading position exceeds the total progress of the video to be played.

**Possible Causes**

The current progress exceeds the total progress.

**Solution**

Check and adjust the progress to avoid exceeding the total.

## 6611003 Cast Controller Loading Timeout

**Error Message**

The process of cast control times out.

**Description**

The loading of the cast controller times out.

**Possible Causes**

The loading of the cast controller takes a long period of time.

**Solution**

The current session times out. Initiate a new session.

## 6611004 Runtime Check Failure

**Error Message**

The runtime check failed.

**Description**

The runtime check fails.

**Possible Causes**

1. The application does not comply with the player's API requirements (for example, passing invalid parameters).

2. The player is in an invalid state.

**Solution**

Verify the input parameters according to the API requirements to prevent exceptions.

## 6611100 Cross-Device Data Transmission Locked

**Error Message**

Cross-device data transmission is locked.

**Description**

Cross-device data transmission is locked.

**Possible Causes**

The transmission is locked.

**Solution**

Restart the remote device and initiate the session again.

## 6611101 Unsupported Seek Mode

**Error Message**

The specified seek mode is not supported.

**Description**

The specified seek mode is not supported.

**Possible Causes**

The device does not support the specified seek mode.

**Solution**

Verify the seek mode.

## 6611102 Invalid Seek Target

**Error Message**

The position to seek to is out of the range of the media asset or the specified seek mode is not supported.

**Description**

The position to seek to is out of range.

**Possible Causes**

The position to seek to is out of the audio/video resource progress range or the specified seek mode is unknown.

**Solution**

Verify the position to seek to and the seek mode.

## 6611103 Unsupported Playback Mode

**Error Message**

The specified playback mode is not supported.

**Description**

The specified playback mode is not supported.

**Possible Causes**

The device does not support the specified playback mode.

**Solution**

Verify the playback mode.

## 6611104 Unsupported Playback Speed

**Error Message**

The specified playback speed is not supported.

**Description**

The specified playback speed is not supported.

**Possible Causes**

The current playback speed is not supported by AVTransport.

**Solution**

Verify the playback speed.

## 6611105 Device Revocation

**Error Message**

The action failed because either the media source device or the media sink device has been revoked.

**Description**

The device is revoked.

**Possible Causes**

The local device or the remote device has been revoked.

**Solution**

Restart the remote device and initiate the session again.

## 6611106 Invalid Input Parameter

**Error Message**

The parameter is invalid, for example, the url is illegal to play.

**Description**

An input parameter is invalid.

**Possible Causes**

An invalid parameter is passed in.

**Solution**

Verify the input parameters according to the API requirements to prevent exceptions.

## 6611107 Memory Allocation Failure

**Error Message**

Allocation of memory failed.

**Description**

Memory allocation fails.

**Possible Causes**

1. The memory is insufficient.

2. The system cannot allocate memory.

**Solution**

The device memory is insufficient. Restart the device and then initiate the session again.

## 6611108 Operation Not Allowed

**Error Message**

Operation is not allowed.

**Description**

The operation is not allowed.

**Possible Causes**

The operation is not allowed.

**Solution**

Check the status of the remote device and perform the operation when the remote device is running.

## 6612000 Unknown I/O Error

**Error Message**

An unspecified input/output error occurs.

**Description**

An unknown I/O error occurs.

**Possible Causes**

The message from the peer device does not comply with the standard or fails to be parsed.

**Solution**

Restart the remote device and initiate the session again.

## 6612001 Network Connection Failure

**Error Message**

Network connection failure.

**Description**

Network connection fails.

**Possible Causes**

Network exceptions occur, or the peer network is disconnected.

**Solution**

Reconnect to the network and then initiate the session again.

## 6612002 Network Timeout

**Error Message**

Network timeout.

**Description**

The network times out. As a result, it takes a long time for the server to complete the request.

**Possible Causes**

The network is abnormal, the peer network is disconnected, or the network environment is poor.

**Solution**

Reconnect to the network and then initiate the session again.

## 6612003 Invalid Content-Type HTTP Header

**Error Message**

Invalid "Content-Type" HTTP header.

**Description**

The Content-Type HTTP header is invalid.

**Possible Causes**

The response from the remote device does not comply with the HTTP protocol standard and fails to be parsed.

**Solution**

Reconnect to the network and then initiate the session again.

## 6612004 Unexpected HTTP Response Status Code from the HTTP Server

**Error Message**

The HTTP server returns an unexpected HTTP response status code.

**Description**

The HTTP server returns an unexpected HTTP response status code.

**Possible Causes**

The remote device is abnormal and returns an HTTP error code.

**Solution**

Reconnect to the network and then initiate the session again.

## 6612005 File Does Not Exist

**Error Message**

The file does not exist.

**Description**

The file does not exist.

**Possible Causes**

The file to be played is not found on the network.

**Solution**

Check whether the resource is available. If not, replace the resource and initiate the session again.

## 6612006 No Permission for I/O Operations

**Error Message**

No permission is granted to perform the IO operation.

**Description**

You do not have the permission to perform I/O operations.

**Possible Causes**

The file read permission is not granted.

**Solution**

Grant the file read permission.

## 6612007 Operation Not Allowed by Network Security Configuration

**Error Message**

Access to cleartext HTTP traffic is not allowed by the app's network security configuration.

**Description**

The player attempts to access plaintext HTTP streams. This operation is not allowed by the network security configuration of the application.

**Possible Causes**

Network security access permission is insufficient.

**Solution**

Reconnect to the network and then initiate the session again.

## 6612008 Data to Read Out of Range

**Error Message**

Reading data out of the data bound.

**Description**

The data to read exceeds the data range.

**Possible Causes**

The data to read exceeds the data range.

**Solution**

Check whether the resource is available. If not, replace the resource and initiate the session again.

## 6612100 No Playable Content

**Error Message**

The media does not contain any contents that can be played.

**Description**

The media asset does not contain any playable content.

**Possible Causes**

There is no playable content in the media asset.

**Solution**

Check whether the resource is available. If not, replace the resource and initiate the session again.

## 6612101 Failure in Reading Media Assets

**Error Message**

The media cannot be read.

**Description**

Media assets cannot be read.

**Possible Causes**

The file fails to be read, possibly because the file is damaged.

**Solution**

Verify file integrity.

## 6612102 Resource Is Being Used

**Error Message**

This resource is already in use.

**Description**

The resource is already in use.

**Possible Causes**

The resource is already in use.

**Solution**

Check whether the resource is available. If not, replace the resource and initiate the session again.

## 6612103 Content Expired

**Error Message**

The content using the validity interval has expired.

**Description**

The content has expired.

**Possible Causes**

The content has expired.

**Solution**

Check whether the resource is available. If not, replace the resource and initiate the session again.

## 6612104 Requested Content Cannot Be Used

**Error Message**

Using the requested content to play is not allowed.

**Description**

Using the requested content is not allowed.

**Possible Causes**

Using the requested content is not allowed.

**Solution**

Check whether the resource is available. If not, replace the resource and initiate the session again.

## 6612105 Unable to Verify the Allowed Content

**Error Message**

The use of the allowed content cannot be verified.

**Description**

The allowed content cannot be verified.

**Possible Causes**

The allowed content cannot be verified.

**Solution**

Check whether the resource is available. If not, replace the resource and initiate the session again.

## 6612106 Frequent Resource Usage

**Error Message**

The number of times this content has been used as requested has reached the maximum allowed number of uses.

**Description**

The number of times that the content is requested has reached the maximum allowed.

**Possible Causes**

The number of times that the content is requested has reached the maximum allowed.

**Solution**

Control the frequency of queries and commands.

## 6612107 Failure in Sending Resource Packages to the Remote Device

**Error Message**

An error occurs when sending packet from source device to sink device.

**Description**

The local device fails to send resource packages to the remote device.

**Possible Causes**

The network is abnormal, the peer device is abnormal, or the peer device cannot receive messages.

**Solution**

Reconnect to the network and then initiate the session again.

## 6613000 Unknown Parsing Error

**Error Message**

Unspecified error related to content parsing.

**Description**

Unknown parsing error.

**Possible Causes**

The message from the peer device does not comply with the standard or fails to be parsed.

**Solution**

Restart the remote device and initiate the session again.

## 6613001 Invalid Type

**Error Message**

Parsing error associated with media container format bit streams.

**Description**

Invalid type.

**Possible Causes**

The MIME type of the resource to play is not supported by AVTransport.

**Solution**

Use another type of resource and initiate the session again.

## 6613002 Error in Parsing Media Manifest

**Error Message**

Parsing error associated with the media manifest.

**Description**

The media manifest fails to be parsed.

**Possible Causes**

The device does not support the current media storage format.

**Solution**

Check whether the resource format is correct. If not, change the resource format and initiate the session again.

## 6613003 Unsupported Media Format

**Error Message**

An error occurs when attempting to extract a file with an unsupported media container format or an unsupported media container feature.

**Description**

The media format is not supported.

**Possible Causes**

The device does not support the current media storage format.

**Solution**

Check whether the resource format is correct. If not, change the resource format and initiate the session again.

## 6613004 Unsupported Feature in the Media Manifest

**Error Message**

Unsupported feature in the media manifest.

**Description**

This feature is not supported in the media manifest.

**Possible Causes**

The device does not support the current media storage format.

**Solution**

Check whether the resource format is correct. If not, change the resource format and initiate the session again.

## 6614000 Unknown Decoding Error

**Error Message**

Unspecified decoding error.

**Description**

Unknown decoding error.

**Possible Causes**

The decoder of the remote device is abnormal.

**Solution**

Restart the remote device and initiate the session again.

## 6614001 Decoder Initialization Failure

**Error Message**

Decoder initialization failed.

**Description**

Initializing the decoder fails.

**Possible Causes**

The decoder of the remote device fails to be initialized.

**Solution**

Restart the remote device and initiate the session again.

## 6614002 Decoder Query Failure

**Error Message**

Decoder query failed.

**Description**

Querying the decoder fails.

**Possible Causes**

When the device or software attempts to play or process a media file, the device or software cannot correctly decode the data in the file.

**Solution**

Check the file format and ensure that the file format is supported.

## 6614003 Media Sample Decoding Failure

**Error Message**

Decoding the media samples failed.

**Description**

Decoding the media sample fails.

**Possible Causes**

The file type you are trying to access is not supported by the device.

**Solution**

Check the file format and ensure that the file format is supported.

## 6614004 Content Format Is Beyond the Device Capability

**Error Message**

The format of the content to decode exceeds the capabilities of the device.

**Description**

The decoding capability of the device does not meet the requirements.

**Possible Causes**

The file type you are trying to access is not supported by the device.

**Solution**

Check the file format and ensure that the file format is supported.

## 6614005 Decoding of the Content Format Is Not Supported

**Error Message**

The format of the content to decode is not supported.

**Description**

Decoding fails because the content format is not supported.

**Possible Causes**

The file type you are trying to access is not supported by the device.

**Solution**

Check the file format and ensure that the file format is supported.

## 6615000 Unknown Error Related to the Audio Renderer

**Error Message**

Unspecified errors related to the audio renderer.

**Description**

An unknown error related to the audio renderer occurs.

**Possible Causes**

The audio renderer of the remote device is faulty and cannot identify the current audio track.

**Solution**

Check the file format and ensure that the file format is supported.

## 6615001 Audio Renderer Initialization Failure

**Error Message**

Initializing the audio renderer failed.

**Description**

Initializing the audio renderer fails.

**Possible Causes**

The audio renderer of the remote device fails to be initialized.

**Solution**

Restart the remote device and initiate the session again.

## 6615002 Audio Renderer Failure in Writing Data

**Error Message**

The audio renderer fails to write data.

**Description**

The audio renderer fails to write data.

**Possible Causes**

The audio renderer of the remote device cannot write data.

**Solution**

Restart the remote device and initiate the session again.

## 6616000 Unknown DRM Error

**Error Message**

Unspecified error related to DRM.

**Description**

An unknown DRM error occurs.

**Possible Causes**

The DRM of the remote device is abnormal.

**Solution**

Update the DRM component and initiate the session again.

## 6616001 Device Does Not Support the Selected DRM Solution

**Error Message**

The chosen DRM protection scheme is not supported by the device.

**Description**

The device does not support the DRM solution selected.

**Possible Causes**

An unknown DRM error occurs.

**Solution**

Update the DRM component and initiate the session again.

## 6616002 Device Provisioning Failure

**Error Message**

Device provisioning failed.

**Description**

An error occurs during device provisioning.

**Possible Causes**

The DRM-protected content cannot be played.

**Solution**

Check the DRM format of the file and ensure that the DRM format is supported.

## 6616003 DRM-Protected Content to Play Is Incompatible

**Error Message**

The DRM-protected content to play is incompatible.

**Description**

The DRM-protected content to play is incompatible.

**Possible Causes**

The DRM-protected content cannot be played.

**Solution**

Update the DRM component and initiate the session again.

## 6616004 License Obtaining Failure

**Error Message**

Failed to obtain a license.

**Description**

The license fails to be obtained.

**Possible Causes**

The DRM license is not complied with.

**Solution**

Check the DRM format of the file and ensure that the DRM format is supported.

## 6616005 Operation Not Allowed by the License Policy

**Error Message**

The operation is disallowed by the license policy.

**Description**

The operation is not allowed by the license policy.

**Possible Causes**

The DRM license is not complied with.

**Solution**

Check the DRM format of the file and ensure that the DRM format is supported.

## 6616006 DRM System Error

**Error Message**

An error occurs in the DRM system.

**Description**

The DRM system is faulty.

**Possible Causes**

The DRM of the remote device is abnormal.

**Solution**

Check the DRM format of the file and ensure that the DRM format is supported.

## 6616007 DRM Privileges Revoked

**Error Message**

The device has revoked DRM privileges.

**Description**

The DRM privileges have been revoked from the device.

**Possible Causes**

The DRM privileges of the device are disabled or revoked. As a result, DRM-protected content cannot be played or processed.

**Solution**

Update the DRM component and initiate the session again.

## 6616008 Expired DRM License Loaded

**Error Message**

The DRM license being loaded into the open DRM session has expired.

**Description**

An expired DRM license is loaded to an open DRM session.

**Possible Causes**

The DRM license has expired.

**Solution**

Update the DRM component and initiate the session again.

## 6616100 Error in Processing the Key Response

**Error Message**

An error occurs when the DRM processes the key response.

**Description**

An error occurs when the DRM processes the key response.

**Possible Causes**

An error occurs when the DRM processes the key response.

**Solution**

Update the DRM component and initiate the session again.
