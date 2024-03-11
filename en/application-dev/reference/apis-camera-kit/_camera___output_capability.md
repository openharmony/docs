# Camera_OutputCapability


## Overview

The **Camera_OutputCapability** struct defines the camera output capability.

**Since**: 11

**Related module**: [OH_Camera](_o_h___camera.md)


## Summary


### Member Variables

| Name| Description| 
| -------- | -------- |
| [Camera_Profile](_camera___profile.md) \*\* [previewProfiles](#previewprofiles) | List of preview profiles. | 
| uint32_t [previewProfilesSize](#previewprofilessize) | Size of the preview profiles. | 
| [Camera_Profile](_camera___profile.md) \*\* [photoProfiles](#photoprofiles) | List of photo profiles. | 
| uint32_t [photoProfilesSize](#photoprofilessize) | Size of the photo profiles. | 
| [Camera_VideoProfile](_camera___video_profile.md) \*\* [videoProfiles](#videoprofiles) | List of video profiles. | 
| uint32_t [videoProfilesSize](#videoprofilessize) | Size of the video profiles. | 
| [Camera_MetadataObjectType](_o_h___camera.md#camera_metadataobjecttype) \*\* [supportedMetadataObjectTypes](#supportedmetadataobjecttypes) | Types of the metadata objects supported. | 
| uint32_t [metadataProfilesSize](#metadataprofilessize) | Size of the metadata profiles. | 


## Member Variable Description


### metadataProfilesSize

```
uint32_t Camera_OutputCapability::metadataProfilesSize
```
**Description**

Size of the metadata profiles.


### photoProfiles

```
Camera_Profile** Camera_OutputCapability::photoProfiles
```
**Description**

List of photo profiles.


### photoProfilesSize

```
uint32_t Camera_OutputCapability::photoProfilesSize
```
**Description**

Size of the photo profiles.


### previewProfiles

```
Camera_Profile** Camera_OutputCapability::previewProfiles
```
**Description**

List of preview profiles.


### previewProfilesSize

```
uint32_t Camera_OutputCapability::previewProfilesSize
```
**Description**

Size of the preview profiles.


### supportedMetadataObjectTypes

```
Camera_MetadataObjectType** Camera_OutputCapability::supportedMetadataObjectTypes
```
**Description**

Types of the metadata objects supported.


### videoProfiles

```
Camera_VideoProfile** Camera_OutputCapability::videoProfiles
```
**Description**

List of video profiles.


### videoProfilesSize

```
uint32_t Camera_OutputCapability::videoProfilesSize
```
**Description**

Size of the video profiles.
