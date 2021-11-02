//
//  BMInviteInfo.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/2/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMInviteInfo : NSObject
@property (nonatomic, copy) NSString *meetingName;
@property (nonatomic, copy) NSString *meetingId;
@property (nonatomic, copy) NSString *masterName;
@property (nonatomic, copy) NSString *pwd;
@property (nonatomic, copy) NSString *link;
@property (nonatomic, copy) NSString *hashCode;
@property (nonatomic, copy) NSString *nickname;
@property (nonatomic, copy) NSString *startTime;
@property (nonatomic, copy) NSString *endTime;
///电话入会的电话号码
@property (nonatomic, copy) NSString *phone;

@property (nonatomic, assign) NSTimeInterval startTimeInt;
@property (nonatomic, assign) NSTimeInterval endTimeInt;

@end
NS_ASSUME_NONNULL_END
