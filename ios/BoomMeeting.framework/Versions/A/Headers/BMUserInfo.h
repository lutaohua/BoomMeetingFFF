//
//  BMUserInfo.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/27.
//

#import <Foundation/Foundation.h>

@interface BMInfoStatus : NSObject

@property (nonatomic, assign) BOOL audioRaiseHands;
@property (nonatomic, assign) BOOL videoRaiseHands;
@property (nonatomic, assign) BOOL raiseHands;

@end

NS_ASSUME_NONNULL_BEGIN

@interface BMUserInfo : NSObject
@property (nonatomic, copy) NSString *pos;
@property (nonatomic, copy) NSString *cver;
/// 头像
@property (nonatomic, copy) NSString *avatar;
@property (nonatomic, copy) NSString *jointime;
/// 是否是研讨会登录了.
@property (nonatomic, assign) BOOL isLogin;
/// 需要自定义一些状态
@property (nonatomic, strong) BMInfoStatus *status;
@end

NS_ASSUME_NONNULL_END
