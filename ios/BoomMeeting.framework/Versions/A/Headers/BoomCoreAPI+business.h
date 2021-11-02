//
//  BoomCoreAPI+business.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/30.
//

#import "BoomCoreAPI.h"
#import "BMCreateRoomConfig.h"
#import "BoomCoreAPI+private.h"
#import "BoomMeeting.h"

NS_ASSUME_NONNULL_BEGIN

@interface BoomCoreAPI (business)

- (void)loginWithChinabondDict:(NSDictionary *)dict callback:(void (^)(NSDictionary *dict))callback;

- (void)loginWithNickname:(NSString *)nickname token:(NSString *)customToken callback:(void (^)(NSDictionary *dict))callback failCallback:(void (^)(NSError *))failCallback;

/// AppId登录
/// @param param 登录配置参数
/// @param callback 回调
- (void)loginByAppIdWithParam:(BMAppIDLoginParam *)param callback:(void(^)(NSDictionary *responseObj, NSError *error))callback;

/// SSO登录
- (void)loginBySSOWithParam:(BMSSOLoginParam *)param callback:(void (^)(NSDictionary *responseObj, NSError *error))callback;

/// 创建会议
/// @param config 创建会议参数
/// @param callback 成功回调
/// @param failCallback 失败回调
- (void)create:(BMCreateRoomConfig *)config   callback:(void (^)(NSDictionary *dict))callback failCallback:(void (^)(NSError * error))failCallback meetingDelegate:(id<BoomMeetingDelegate>)meetingDelegate;

/// 加入会议
/// @param config 加入会议参数
/// @param callback 成功回调
/// @param failCallback 失败回调
- (void)join:(BMJoinRoomConfig *)config  callback:(void (^)(NSDictionary *dict))callback failCallback:(void (^)(NSError * error))failCallback meetingDelegate:(id<BoomMeetingDelegate>)meetingDelegate;

/// 获取用户的麦克风状态
/// @param userId 用户ID
- (BOOL)getAudioEnable:(NSString *)userId;

/// 获取用户的摄像头状态
/// @param userId 用户ID
- (BOOL)getVideoEnable:(NSString *)userId;

/// 设置麦克风状态
/// @param userId 用户ID
/// @param mute 禁用标识；YES 表示禁止播放；NO 表示恢复播放
- (void)setAudioEnable:(NSString *)userId mute:(BOOL)mute;

/// 设置摄像头状态
/// @param userId 用户ID
/// @param mute 禁用标识；YES 表示禁止播放；NO 表示恢复播放
- (void)setVideoEnable:(NSString *)userId mute:(BOOL)mute;

/// 退出登录
- (void)logOut;

/// 获取与会者列表
- (NSArray<BMSDKUser *> *)getAttendeeList;

/// 获取观众列表
- (NSArray<BMSDKUser *> *)getAudienceList;

/// 判断自己是否是主持人
- (BOOL)selfIsChairMan;

/// 获取用户状态：摄像头/麦克风状态、权限、昵称、头像
/// @param userId 用户ID
- (BMSDKUser *)getUserInfo:(NSString *)userId;

- (void)createMeeting:(BMCreateRoomConfig *)config callback:(void (^)(NSDictionary *dict))callback failCallback:(void (^)(NSError *))failCallback;

- (void)joinMeeting:(BMCreateRoomConfig *)config callback:(void (^)(NSDictionary *dict))callback failCallback:(void (^)(NSError *))failCallback;

- (void)getTokenWithCallback:(void (^)(NSString * _Nonnull))callback failcallback:(void (^)(NSError *))failcallback;

- (void)getRoomNumberWithToken:(NSString *)token callback:(void (^)(NSString *))callback failCallback:(void (^)(NSError *))failCallback;


/// 检查会议号是否合法,
/// @param roomId 房间号
/// @param userId 用户ID
/// @param callback dict.binded   none | room | channel;    dict.joined     true | false
/// @param failCallback 错误回调
- (void)checkRoomId:(NSString *)roomId userId:(NSString *)userId callback:(void (^)(NSDictionary *dict))callback failCallback:(void (^)(NSError *))failCallback;

/// 请求房间信息
/// @param roomId 房间号
/// @param password 用户密码
/// @param userId 用户id
/// @param callback dict.binded   none | room | channel;    dict.joined     true | false
/// @param failCallback 错误回调
- (void)requestRoomInfo:(NSString *)roomId password:(NSString *)password userId:(NSString *)userId callback:(void (^)(NSDictionary *dict))callback failCallback:(void (^)(NSError *))failCallback;


/// 获取个人会议号是否需要密码
/// @param roomNumber 会议号
/// @param callback   NSDictionary {{is_join: number, is_owner: number, need_pwd: number, message: string}}
/// @param failCallback NSError error
- (void)getPersonalNumberNeedPwd:(NSString *)roomNumber pwd:(NSString *)pwd callback:(void (^)(NSDictionary *dict))callback failCallback:(void (^)(NSError *error))failCallback;

/// 检查房间信息并可入会, 兼容个人会议号,
- (void)checkRoomInfo:(NSString *)roomNumber secret:(NSString *)secret userId:(NSString *)userId screen:(BOOL)screen callback:(void (^)(NSDictionary *dict))callback failCallback:(void (^)(NSError *error))failCallback;

- (void)toSettingCallback:(ToSettingCallback)callback;

/// 去分享
- (void)toShareWechatCallback:(void (^)(NSDictionary *dict))callback;

@end

NS_ASSUME_NONNULL_END
