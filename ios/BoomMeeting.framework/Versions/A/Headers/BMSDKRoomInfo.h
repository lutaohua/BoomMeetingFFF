//
//  BMSDKRoomInfo.h
//  BoomMeeting
//
//  Created by boom on 2021/10/22.
//

#import <Foundation/Foundation.h>
#import "BMRoomInfo.h"

NS_ASSUME_NONNULL_BEGIN

@interface BMSDKRoomInfo : NSObject

/// 房间ID
@property(nonatomic, copy) NSString *roomId;
@property(nonatomic, copy) NSString *roomName;
/// 房间创建者的 userId
@property(nonatomic, copy) NSString *creatorId;

/// 房间主持人的 userId
@property(nonatomic, copy) NSString *masterId;

/// 当前房间是否已启动全员禁止发送消息
@property(nonatomic, assign) BOOL msgOff;

/// 当前房间是否锁定
@property(nonatomic, assign) BOOL lock;


+ (BMSDKRoomInfo *)convertRoomInfo:(BMRoomInfo *)roomInfo;

@end

NS_ASSUME_NONNULL_END
