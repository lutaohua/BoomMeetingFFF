//
//  _UserInfo.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/1/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface _UserInfo : NSObject

@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy) NSString *nickname;
@property (nonatomic, copy) NSString *avatar;
/// 个人会议号
@property (nonatomic, copy) NSString *personNumber;
/// 个人会议号密码
@property (nonatomic, copy) NSString *personSecret;
/// 是否是Vip
@property (nonatomic, assign) BOOL isVip;
/// 是否有量子权限
@property (nonatomic, assign) BOOL liangziQuan;
/// 是否量子授权了
@property (nonatomic, assign) BOOL liangziQuthorization;

/// 是否可以提前入会
@property (nonatomic, assign) BOOL canEarlyJoin;
/// 会议最大人数上限
@property (nonatomic, assign) NSInteger memberLimit;

@end

NS_ASSUME_NONNULL_END
