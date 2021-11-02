//
//  BMConstants.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/18.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


static inline void BMRunOnMainThreadWithSyncBlock(void (^block)(void)) {
  if ([NSThread isMainThread]) {
    block();
  } else {
    dispatch_sync(dispatch_get_main_queue(), block);
  }
}


/** 窗口排序数字 */
typedef NS_ENUM(NSInteger, BMSortNum) {
    BMSortNum_Screen_Master = 0, //主持人屏幕共享
    BMSortNum_Screen_Manager = 1,//联席主持人屏幕共享
    BMSortNum_Screen_Other = 2,//其他人员屏幕共享
    BMSortNum_Local = 3,//本端
    BMSortNum_AV_Master = 4,//主持人AV
    BMSortNum_AV_Manager = 5,//联席主持人AV
    BMSortNum_AVH_Other = 6, //其他人AVH
    BMSortNum_AV_Other = 7,//其他参会者AV
    BMSortNum_A_Master = 8,//主持人A
    BMSortNum_A_Manager = 9,//联席主持人A
    BMSortNum_AH_Other = 10,
    BMSortNum_A_Other = 11,//其他人A
    BMSortNum_V_Master = 12,//主持人V
    BMSortNum_V_Manager = 13,//联席主持人V
    BMSortNum_VH_Other = 14,
    BMSortNum_V_Other = 15,//其他人V
    BMSortNum_Master = 16,//主持人关闭AV
    BMSortNum_Manager = 17,//联席主持人关闭AV
    BMSortNum_H_Other = 18, //举手的嘉宾
    BMSortNum_Other = 19,//其他人关闭AV
    BMSortNum_Equipment = 20, //设备端
    
    /** 共享 */
//    BMSortNumShare = 0,
//    /** 自己 */
//    BMSortNumSelf = 1,
//    /** 主持人视频都开 */
//    BMSortNumMasterAV = 2,
//    BMSortNumManagerAV = 3,
//    BMSortNumOtherAV,
//    BMSortNumMasterA,
//    BMSortNumManagerA,
//    BMSortNumOtherA,
//    BMSortNumMasterV,
//    BMSortNumManagerV,
//    BMSortNumOtherV,
//    BMSortNumMasterNone,
//    BMSortNumManagerNone,
//    BMSortNumOtherNone
};

/// 拉流的类型
typedef NS_ENUM(NSInteger, BMStreamPullType) {
    BMStreamPullTypeNone = 0,   // 不拉流
    BMStreamPullTypeA = 1,      // 拉流只拉音频
    BMStreamPullTypeAV = 2      // 拉流拉音视频
};

/// 拉流的状态
typedef NS_ENUM(NSInteger, BMStreamPullState) {
    BMStreamPullStateNone = 0,      // 没有拉流
    BMStreamPullStateLoading = 1,   // loading开始
    BMStreamPullStateLoaded = 2,    // 拉流完成.
};

/// 流的类型
typedef NS_ENUM(NSInteger, BMStreamType) {
    BMStreamTypeSubMain = 0,
    BMStreamTypeSingle = 1,
    BMStreamTypeShare = 2,
    BMStreamTypeOther = 3,
};

typedef NS_ENUM(NSInteger, BMWindowType) {
    BMWindowTypeSpeaker = 0,    // 大小窗时,和屏幕共享时
    BMWindowTypeNormal = 1,     // 宫格时
};

typedef NS_ENUM(NSUInteger, BMStreamConnectionState){
    BMStreamConnectionStateInited,
    BMStreamConnectionStateConnecting,
    BMStreamConnectionStateFailed,
    BMStreamConnectionStateDisconnected,
    BMStreamConnectionStateConnected,
    BMStreamConnectionStateClosed,
};

/// 1: 主持人  2:嘉宾  3:观众 4:设备端观众
typedef NS_ENUM(NSUInteger, BMRole){
    BMRoleMaster = 1,
    BMRoleJiaBin = 2,
    BMRoleViewer = 3,
    BMRoleDevice = 4
};

/// 大小流模式
typedef NS_ENUM(NSInteger, BMStreamMode) {
    BMStreamModeSmall = 0,    // 小流
    BMStreamModeBig = 1,     // 大流
};


/// 小流的后缀LowQuality
UIKIT_EXTERN NSString * const STREAM_SUFFIX_LOW;
/// 共享流的后缀 _screen
UIKIT_EXTERN NSString * const STREAM_SUFFIX_SCREEN;
/// 多路流的后缀 _hdmi
UIKIT_EXTERN NSString * const STREAM_SUFFIX_HDMI;
/// 混流的包含 -mixer-
UIKIT_EXTERN NSString * const STREAM_CONTAIN_MIXER;
///rtmp混流包含 -rtmpmixer-
UIKIT_EXTERN NSString * const STREAM_CONTAIN_RTMP_MIXER;


///// url或customToken不能为空（后续为appkey不能为空）
//#define BMErrorUrl = 40001
///// 用户信息错误
//#define BMErrorUserInfo = 40002
/////房间信息错误
//#define BMErrorRoomInfo = 40003
/////需要输入密码
//#define BMErrorEnterPassword = 40004
/////当前会议无法进入投屏，请使用投屏进入
//#define BMErrorMeetingNotEnterChannel = 40005
//  //会议未开始
//#define BMErrorMeetingNotStart = 40006;
//  //会议号无效
//#define BMErrorMeetingNot = 40007;
//
//  //获取房间信息失败
//#define BMErrorGetRoomInfo = 50001;



NS_ASSUME_NONNULL_BEGIN

@interface BMConstants : NSObject

@end

NS_ASSUME_NONNULL_END
