//
//  BMCreateRoomConfig.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/29.
//

#import <Foundation/Foundation.h>
#import "BMConstants.h"
//#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@class BMCreateRoomConfig;

@interface BMJoinRoomConfig : NSObject

/// (必填)会议号
@property (nonatomic, copy) NSString *roomNumber;
/// (必填)用户身份标识
@property (nonatomic, copy) NSString *userId;
/// (必填)用户昵称
@property (nonatomic, copy) NSString *nickname;
/// (必填)房间名称
@property (nonatomic, copy) NSString *roomName;
/// (必填)房间模式 1 = 会议；2 = 直播 默认 1
@property (nonatomic, copy) NSString *mode;

/// 入会密码 如果是个人会议号,会自动补充密码
@property (nonatomic, copy) NSString *password;
/// 音频开关
@property (nonatomic, assign) BOOL enableAudio;
/// 视频开关
@property (nonatomic, assign) BOOL enableVideo;
/// 创建还是加入
@property (nonatomic, assign) BOOL create;
/// 是否是投屏进来的(包括无线投屏和会议外投屏)
@property (nonatomic, assign) BOOL screen;
/// 是否是无线投屏
@property (nonatomic, assign, getter=isChannel) BOOL channel;

@property (nonatomic, copy) NSString *avator;
/// 是否强制加入
@property (nonatomic, assign) BOOL joined;
//@property (nonatomic, strong) UINavigationController *navigation;
/// 是否是研讨会
@property (nonatomic, assign, getter=isConference) BOOL conference;
/// 研讨会身份  1: 主持人  2:嘉宾  3:观众 4:设备端观众    TODO 定义成枚举
@property (nonatomic, assign) BMRole ythIdenitify;
/// 研讨会是否登录
@property (nonatomic, assign, getter=isLogin) BOOL login;
/// 会议类型, 会议性质 (公开,非公开)
@property (nonatomic, assign) BOOL meetType;


///共享屏幕扩展的bundleID
@property (nonatomic, copy) NSString *screenShareBunldID;
///groupBundleID 用于屏幕共享，进程间分享数据
@property (nonatomic, copy) NSString *groupBundleID;
/// 是否不可以使用共享屏幕功能
@property (nonatomic, assign) BOOL notShareScreen;
/// 不能使用共享的原因
@property (nonatomic, copy) NSString *notShareScreenReason;
///// 唤醒url
//@property (nonatomic, copy) NSString *weakURL;

/// 判断是否是安全对象 : 必填信息是否没有空值
- (BOOL)isSafeObject;

@end

@interface BMCreateRoomConfig : NSObject

/// (必填)会议号
@property (nonatomic, copy) NSString *roomNumber;
/// (必填)用户身份标识
@property (nonatomic, copy) NSString *userId;
/// (必填)用户昵称
@property (nonatomic, copy) NSString *nickname;
/// (必填)房间名称
@property (nonatomic, copy) NSString *roomName;
/// (必填)房间模式 1 = 会议；2 = 直播 默认 1
@property (nonatomic, copy) NSString *mode;

/// 入会密码 如果是个人会议号,会自动补充密码
@property (nonatomic, copy) NSString *password;
/// 音频开关
@property (nonatomic, assign) BOOL enableAudio;
/// 视频开关
@property (nonatomic, assign) BOOL enableVideo;
/// 创建还是加入
@property (nonatomic, assign) BOOL create;
/// 是否是投屏进来的(包括无线投屏和会议外投屏)
@property (nonatomic, assign) BOOL screen;
/// 是否是无线投屏
@property (nonatomic, assign, getter=isChannel) BOOL channel;

@property (nonatomic, copy) NSString *avator;
/// 是否强制加入
@property (nonatomic, assign) BOOL joined;
//@property (nonatomic, strong) UINavigationController *navigation;
/// 是否是研讨会
@property (nonatomic, assign, getter=isConference) BOOL conference;
/// 研讨会身份  1: 主持人  2:嘉宾  3:观众 4:设备端观众    TODO 定义成枚举
@property (nonatomic, assign) BMRole ythIdenitify;
/// 研讨会是否登录
@property (nonatomic, assign, getter=isLogin) BOOL login;
/// 会议类型, 会议性质 (公开,非公开)
@property (nonatomic, assign) BOOL meetType;


///共享屏幕扩展的bundleID
@property (nonatomic, copy) NSString *screenShareBunldID;
///groupBundleID 用于屏幕共享，进程间分享数据
@property (nonatomic, copy) NSString *groupBundleID;
/// 是否不可以使用共享屏幕功能
@property (nonatomic, assign) BOOL notShareScreen;
/// 不能使用共享的原因
@property (nonatomic, copy) NSString *notShareScreenReason;
///// 唤醒url
//@property (nonatomic, copy) NSString *weakURL;

/// 判断是否是安全对象 : 必填信息是否没有空值
- (BOOL)isSafeObject;

@end


NS_ASSUME_NONNULL_END
