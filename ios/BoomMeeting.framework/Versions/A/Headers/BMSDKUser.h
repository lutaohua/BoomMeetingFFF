//
//  BMSDKUser.h
//  BoomMeeting
//
//  Created by boom on 2021/10/22.
//

#import <Foundation/Foundation.h>
#import "BMUser.h"
#import "BMStreamModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface BMSDKUser : NSObject<NSCopying>

/// 用户ID
@property (nonatomic, copy) NSString *userId;
/// 昵称
@property (nonatomic, copy) NSString *nickname;
/// 头像
@property (nonatomic, copy) NSString *avatar;
/// 权限
@property (nonatomic, copy) NSString *permission;
/// 音频是否开启
@property (nonatomic, assign) BOOL audioEnable;
/// 视频是否开始
@property (nonatomic, assign) BOOL videoEnable;

+ (BMSDKUser *)convertUser:(BMUser *)user;

+ (BMSDKUser *)convertStreamModel:(BMStreamModel *)model;

@end

NS_ASSUME_NONNULL_END
