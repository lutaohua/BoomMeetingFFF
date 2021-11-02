//
//  BMUser+prive.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/1/24.
//

#import "BMUser.h"
#import <BoomCore/BoomCore_i.h>
NS_ASSUME_NONNULL_BEGIN

@interface BMUser ()
@property (nonatomic, strong) BCUserPermission *permission;

- (void)updateUser:(BCUser *)user;

/// 检查用户是不是观众
+ (BOOL)checkIsViewer:(BCUserPermission *)permission;
@end

NS_ASSUME_NONNULL_END
