

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "BMCreateRoomConfig.h"
#import "BMSDKRoomInfo.h"
#import "BMSDKUser.h"

@class HomeController;
@class NavigationController;
@class BMRootMeetingController;
//@class BMSDKUser;

//! Project version number for BoomMeeting.
FOUNDATION_EXPORT double BoomMeetingVersionNumber;

//! Project version string for BoomMeeting.
FOUNDATION_EXPORT const unsigned char BoomMeetingVersionString[];


typedef void (^SettingCallback)(NSDictionary *dict);

// In this header, you should import all the public headers of your framework using statements like #import <BoomMeeting/PublicHeader.h>

@protocol BoomMeetingDelegate <NSObject>

- (void)didJoinRoomSuccess:(NSString *)roomId meetingParam:(NSDictionary *)meetingParam meetingViewController:(UIViewController *)meetingViewController;

- (void)didJoinRoomFailed:(NSString *)roomId error:(NSError *)error;

//- (UINavigationController *)currentNavigation;

/// 用户被踢出
- (void)onKickedOut:(NSString *)userId;

/// 有用户加入了
- (void)onUserJoined:(BMSDKUser *)user;

/// 有用户离开了
- (void)onUserLefted:(BMSDKUser *)user;

/// 用户状态改变了. 音频, 视频,
- (void)onUserStateChanged:(BMSDKUser *)user;

/// 主持人改变了的通知
- (void)onMasterChanged:(BMSDKUser *)user;

/// 联席主持人改变了的通知
- (void)onCoHostChanged:(BMSDKUser *)user;

/// 昵称改变了的通知
- (void)onNicknameChanged:(BMSDKUser *)user;

/// 房间状态改变了的通知  chageType:1:会议锁定改变，2：全员禁音改变
- (void)onRoomStatusChange:(BMSDKRoomInfo *)roomInfo changeType:(int)changeType;

/// 用户列表改变了的通知
- (void)onUserListChange:(NSArray<BMSDKUser *> *)userList;

@end

@interface BMSDKConfig: NSObject
/// APPID 接入方式时，config.appId 传入申请到的企业APPID；非APPID接入方式推荐传入企业名称
@property (nonatomic, copy) NSString *appId;
/// 屏幕共享extension的appGroup。
@property (nonatomic, copy) NSString *appGroupIndentifier;
/// 屏幕共享extension的BundleID。
@property (nonatomic, copy) NSString *launchBundleID;
/// 服务器url
@property (nonatomic, copy) NSString *serverUrl;

//@property (nonatomic, copy) NSString *schemeUrl;

@end

@interface BMAppIDLoginParam: NSObject
/// (必填)加密信息
@property (nonatomic, copy) NSString *signature;
/// (必填)用户的账号。1~64位
@property (nonatomic, copy) NSString *thirdUserId;
/// (必填)signature 过期时间。单位为秒的时间戳，为0时表示不会过期
@property (nonatomic, assign) NSInteger expireTime;
/// (必填)随机字符串。32~64位
@property (nonatomic, copy) NSString *nonce;
/// (必填)用户名
@property (nonatomic, copy) NSString *userName;
/// (必填)用户ID
@property (nonatomic, copy) NSString *userId;
/// (选填，无默认值)邮箱。0~255位
@property (nonatomic, copy) NSString *userEmail;
/// (选填，无默认值)手机号。0~32位
@property (nonatomic, copy) NSString *userPhone;
/// (选填，无默认值)用户头像地址
@property (nonatomic, copy) NSString *userAvatar;
/// (选填)企业ID
@property (nonatomic, copy) NSString *corpId;

/// 判断是否是安全对象 : 必填信息是否没有空值
- (BOOL)isSafeObject;

@end

/// SSO登录参数
@interface BMSSOLoginParam: NSObject
/// (必填，无默认值)企业域名
@property (nonatomic, copy) NSString *domain;
/// (选填，无默认值)邮箱。0~255位
@property (nonatomic, copy) NSString *userEmail;
/// 用户密码
@property (nonatomic, copy) NSString *password;
/// (选填)企业ID
@property (nonatomic, copy) NSString *corpId;
/// 判断是否是安全对象 : 必填信息是否没有空值
- (BOOL)isSafeObject;

@end


@interface BoomMeeting : NSObject


+ (void)setupInstance:(NSString *)appKey serverUrl:(NSString *)uri boomServerUrl:(NSString *)boomServerUrl schemeUrl:(NSString *)schemeUrl;

/// 初始化BoomMeeting
/// @param config 初始化参数
+ (void)setupInstance:(BMSDKConfig *)config;

/// AppId登录
/// @param param 登录配置参数
/// @param callback 回调
+ (void)loginByAppIdWithParam:(BMAppIDLoginParam *)param callback:(void(^)(NSDictionary *responseObj, NSError *error))callback;

/// SSO登录
+ (void)loginBySSOWithParam:(BMSSOLoginParam *)param callback:(void (^)(NSDictionary *responseObj, NSError *error))callback;

/// 创建会议
/// @param config 创建会议参数
/// @param delegate delegate回调
+ (void)create:(BMCreateRoomConfig *)config delegate:(id<BoomMeetingDelegate>)delegate;

/// 加入会议
/// @param config 加入房间参数
/// @param delegate delegate回调
+ (void)join:(BMJoinRoomConfig *)config delegate:(id<BoomMeetingDelegate>)delegate;

/// 离开房间
+ (void)leave;

/// 结束房间
+ (void)release;

/// 获取用户的麦克风状态
/// @param userId 用户ID
+ (BOOL)getAudioEnable:(NSString *)userId;

/// 获取用户的摄像头状态
/// @param userId 用户ID
+ (BOOL)getVideoEnable:(NSString *)userId;

/// 设置麦克风状态
/// @param userId 用户ID
/// @param mute 禁用标识；YES 表示禁止播放；NO 表示恢复播放
+ (void)setAudioEnable:(NSString *)userId mute:(BOOL)mute;

/// 设置摄像头状态
/// @param userId 用户ID
/// @param mute 禁用标识；YES 表示禁止播放；NO 表示恢复播放
+ (void)setVideoEnable:(NSString *)userId mute:(BOOL)mute;

/// 退出登录
+ (void)logOut;

/// 获取与会者列表
+ (NSArray<BMSDKUser *> *)getAttendeeList;

/// 获取观众列表
+ (NSArray<BMSDKUser *> *)getAudienceList;

/// 判断自己是否是主持人
+ (BOOL)selfIsChairMan;

/// 获取用户状态：摄像头/麦克风状态、权限、昵称、头像
/// @param userId 用户ID
+ (BMSDKUser *)getUserInfo:(NSString *)userId;

+ (void)loginWithNickname:(NSString *)nickname token:(NSString *)customToken callback:(void (^)(NSDictionary *dict))callback failCallback:(void (^)(NSError *))failCallback;

/// 中债的登录
+ (void)loginWithChinabondDict:(NSDictionary *)dict callback:(void (^)(NSDictionary *dict))callback;

/// Boom 用户的登录方式
+ (void)loginWithAccount:(NSString *)account password:(NSString *)password;

+ (void)createMeeting:(BMCreateRoomConfig *)config delegate:(id<BoomMeetingDelegate>)delegate;

+ (void)joinMeeting:(BMCreateRoomConfig *)config delegate:(id<BoomMeetingDelegate>)delegate;


/// 业务上 去设置页面
+ (void)toSettingCallback:(SettingCallback)callback;
/// 业务 去分享页面.
+ (void)toWechatShareCallback:(void (^)(NSDictionary *dict))callback;
/// 业务上去更新混流
+ (void)toMixerCallback:(void (^)(NSString *mixerData))callback;
///// 加入无线投屏.
//+ (void)joinChannelWithURI:(NSString *)uri config:(BMCreateRoomConfig *)config delegate:(id<BoomMeetingDelegate>)delegate;


+ (UIStoryboard *)getStoryBoard;
@end

