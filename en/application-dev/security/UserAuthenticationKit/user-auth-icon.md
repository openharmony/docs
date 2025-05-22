# Using userAuthIcon

**userAuthIcon** provides built-in authentication icons for easy embedding with your application's UI. With **userAuthIcon**, you can:

1. Easily integrate the facial authentication and fingerprint authentication icons into your applications.
2. Customize the color and size of the icons. The icon style cannot be changed.
3. Start the facial or fingerprint authentication pop-up component once the icon is tapped.

**userAuthIcon** supports the following types of authentication:

- Facial authentication
- Fingerprint authentication
- Facial + lock screen password authentication
- Fingerprint + lock screen password authentication
- Facial + fingerprint + lock screen password authentication

The following figure shows the use of **userAuthIcon** for fingerprint authentication. When a user taps the fingerprint icon on the left (implemented by **userAuthIcon**), the system automatically launches the system authentication component shown on the right to complete user authentication. With **userAuthIcon**, you do not need to initiate an authentication request through an API, which simplifies the authentication process.

![user_auth_icon_demo](figures/user_auth_icon_demo.png)

## Example

For details, see [@ohos.userIAM.userAuthIcon](../../reference/apis-user-authentication-kit/ohos-useriam-userauthicon.md).
