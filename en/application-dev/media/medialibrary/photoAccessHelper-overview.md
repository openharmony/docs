# Introduction to Media Library Kit

Media Library Kit provides the capabilities of managing albums and media files, including images and videos, to enable your application to quickly display images and play back videos.

## Available Capabilities

With Media Library Kit, you can manage albums and media files, including creating albums and accessing and modifying media assets in albums. The following capabilities are available to third-party applications:

- [Media asset management](photoAccessHelper-resource-guidelines.md), including:
  - Obtaining media assets (images and videos)
  - Obtaining image and video thumbnails
  - Creating a media asset (using a security component)
  - Renaming a media asset
- [User album management](photoAccessHelper-userAlbum-guidelines.md), including:
  - Obtaining a user album
  - Renaming a user album
  - Adding images and videos to a user album.
  - Obtaining images and videos from a user album
  - Removing images and videos from a user album
- [Management of system albums](photoAccessHelper-systemAlbum-guidelines.md), including:
  - Favorites
  - Video album
- [Change notifications of images, videos, and albums](photoAccessHelper-notify-guidelines.md), including:
  - Registering a listener for the specified URI
  - Unregistering a listener for the specified URI

The following capabilities are available to system applications:

- Media asset operations, including:
  - Creating a media asset
  - Moving a media asset to the trash
  - Deleting a media asset permanently

- Album-related operations, including:
  - Creating a user album
  - Deleting a user album
  - Hiding an album
  - Favoriting and unfavoriting an album
  - Using the Screenshots album

## Features

- Simple and efficient development thanks to object-based API design.
- Integrated device-cloud access management.
- Precise security control and automatic authorization with Pickers and security component \<**SaveButton**>.
- Intelligent format conversion completed at the framework layer in a unified manner.

## Working Principles

The media library receives requests for obtaining or changing media assets from users, verifies the request validity and permissions, interacts with the database if the verification is successful, and returns the result.

## Constraints

User personal data is involved in the **photoAccessHelper** module. Therefore, the application needs to apply for the related read and write permissions from the user.
Before requesting permissions, ensure that the [basic principles for using permissions](../../security/AccessToken/app-permission-mgmt-overview.md#basic-principles-for-using-permissions) are met. The following permissions are required. For details about how to request user authorization, see [Requesting User Authorization](../../security/AccessToken/request-user-authorization.md).

| Permission                        | Description                                      | Authorization Mode  |
| ------------------------------ | ------------------------------------------ | ---------- |
| ohos.permission.READ_IMAGEVIDEO     | Allows an application to read image and video file information from a user's external storage.| user_grant |
| ohos.permission.WRITE_IMAGEVIDEO    | Allows an application to read and write image and video file information on a user's external storage.| user_grant |
