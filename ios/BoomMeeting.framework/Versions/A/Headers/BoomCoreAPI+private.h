//
//  BoomCoreAPI+private.h
//  BoomMeetingDemo
//
//  Created by zhaozhidan on 2020/12/29.
//

#import "_RoomConfig.h"
#import "_UserInfo.h"

typedef void (^RoomCloseCallback)(void);
typedef void (^ToSettingCallback)(NSDictionary *dict);
typedef void (^ToShareWechatCallback)(NSDictionary *dict);
typedef void (^ToMixerCallback)(NSString *mixerData);

@interface BoomCoreAPI()

@property (nonatomic, copy) NSString *appkey;
@property (nonatomic, copy) NSString *serverUrl;
@property (nonatomic, copy) NSString *appGroupIndentifier;
@property (nonatomic, copy) NSString *launchBundleID;
@property (nonatomic, copy) NSString *token;
/// Boom的业务URL
@property (nonatomic, copy) NSString *boomServerUrl;
/// 业务端的token
@property (nonatomic, copy) NSString *customToken;
/// 需要房间内的一些参数  
@property (nonatomic, strong) _RoomConfig *roomConfig;
/// 记录一些共有的用户信息参数
@property (nonatomic, strong) _UserInfo *userInfo;
/// 去往设置页面
@property (nonatomic, copy) ToSettingCallback toSettingCallback;
/// 去分享的回调, 返回要分享的数据.
@property (nonatomic, copy) ToShareWechatCallback toShareWechatCallback;

@property (nonatomic, copy) RoomCloseCallback roomCloseCallback;
/// 外界调用开始混流.
@property (nonatomic, copy) ToMixerCallback mixerCallback;

- (void)saveAppKey:(NSString *)appkey serverUrl:(NSString *)serverUri boomServerUrl:(NSString *)boomServerUrl appGroupIndentifier:(NSString *)appGroupIndentifier launchBundleID:(NSString *)launchBundleID;

@end
