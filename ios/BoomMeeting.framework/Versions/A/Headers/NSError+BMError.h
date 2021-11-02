//
//  NSError+BMError.h
//  BMiveCore
//
//  Created by MingLQ on 2016-11-30.
//  Copyright © 2016 BaijiaYun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <BJLiveBase/BJLiveBase.h>


NS_ASSUME_NONNULL_BEGIN

/**
 BMError 可用属性
 .domain                    BMErrorDomain
 .code                      BMErrorCode - 错误码
 .localizedDescription      NSString * - 错误描述
 .localizedFailureReason    NSString * - 错误原因，可能为空 - TODO: 干掉，如果有具体错误信息则替换调默认的错误描述
 .bjl_sourceError           NSError * - 引起当前错误的错误，可能为空
 TODO: server errorCode, message
 */

FOUNDATION_EXPORT const NSErrorDomain BMErrorDomain;

#define BMErrorUrl = 40001

#define BMErrorUserInfo = 40002
///房间信息错误
#define BMErrorRoomInfo = 40003
///需要输入密码
#define BMErrorEnterPassword = 40004
///当前会议无法进入投屏，请使用投屏进入
#define BMErrorMeetingNotEnterChannel = 40005
  //会议未开始
#define BMErrorMeetingNotStart = 40006;
  //会议号无效
#define BMErrorMeetingNot = 40007;

  //获取房间信息失败
//#define BMErrorGetRoomInfo = 50001;

typedef NS_ENUM(NSInteger, BMErrorCode) {
    /** url或customToken不能为空（后续为appkey不能为空） */
    /** 参数错误 */
    BMErrorCode_invalidArguments = 40001,
    
    //// enter room ////
    /** 用户信息错误*/
    BMErrorCode_userInfo,
    /** 房间信息错误 */
    BMErrorCode_roomInfo,
    /** 需要输入密码 */
    BMErrorCode_enterPassword,
    /** 输入密码错误 */
    BMErrorCode_errorPassword,
    /** 当前会议无法进入投屏，请使用投屏进入 */
    BMErrorCode_meetingNotEnterChannel,
    BMErrorCode_meetingNotStart,
    /** 会议号无效 */
    BMErrorCode_meetingInvalid,
    
    /** 用户已经在其它设备登录 */
    BMErrorCode_enterRoom_loginConflict,
    BMErrorCode_tokenExpire, //token过期
    /** 试听结束 */
    BMErrorCode_enterRoom_auditionTimeout,
    /** 教室时间到期 */
    BMErrorCode_enterRoom_timeExpire,
    //// exit room ////
    /** 连接断开 */
    BMErrorCode_exitRoom_disconnected,
    /** 用户在其它设备登录 */
    BMErrorCode_exitRoom_loginConflict,
    /** 用户被请出教室 */
    BMErrorCode_exitRoom_kickout,
    /** 试听结束 */
    BMErrorCode_exitRoom_auditionTimeout,
    /** 教室时间到期 */
    BMErrorCode_exitRoom_timeExpire,
    /** 主讲离开，教室关闭 */
    BMErrorCode_exitRoom_presenterLeave,
    /** 网络错误 */
    BMErrorCode_networkError,
    /** 请求失败 */
    BMErrorCode_requestFailed,
    /** 主动调用取消 */
    BMErrorCode_cancelled,
    /** 非法用户角色 */
    BMErrorCode_invalidUserRole,
    /** 非法调用 */
    BMErrorCode_invalidCalling,
    /** 操作过于频繁 */
    BMErrorCode_areYouRobot,
    /* !!!: 
     1、在此之前增加错误码；
     2、不要设置错误码取值；
     3、同步增删 BMErrorDescriptions； */
    BMErrorCode_unknown    // 未知错误
};

FOUNDATION_EXPORT NSString * const BMErrorDescription_unknown;
FOUNDATION_EXPORT NSString * _Nonnull const BMErrorDescriptions[];

typedef BJLError BMError;

static inline BMError * _Nullable BMErrorMakeFromError(BMErrorCode errorCode, NSString * _Nullable reason, NSError * _Nullable sourceError) {
//    if (errorCode == BMErrorCode_success) {
//        return nil;
//    }
    BMErrorCode titleIndex = (BMErrorCode)MIN(MAX(0, errorCode), BMErrorCode_unknown);
    NSMutableDictionary *userInfo = [NSMutableDictionary new];
    [userInfo setObject:BMErrorDescriptions[titleIndex] ?: BMErrorDescription_unknown forKey:NSLocalizedDescriptionKey];
    if (reason) {
        [userInfo setObject:reason forKey:NSLocalizedFailureReasonErrorKey];
    }
    if (sourceError) {
        [userInfo setObject:sourceError forKey:BJLErrorSourceErrorKey];
    }
    return (BMError *)[NSError errorWithDomain:BMErrorDomain code:errorCode userInfo:userInfo];
}

static inline BMError * _Nullable BMErrorMake(BMErrorCode errorCode, NSString * _Nullable reason) {
    return BMErrorMakeFromError(errorCode, reason, nil);
}


NS_ASSUME_NONNULL_END
