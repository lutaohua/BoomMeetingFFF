//
//  BMShareScreen.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/2/24.
//

#import <Foundation/Foundation.h>
#import <BoomCore/BoomCore_i.h>
@class BMRoom;

NS_ASSUME_NONNULL_BEGIN

@interface BMShareScreen : NSObject<BCScreenDelegate>

- (instancetype)initWithRoom:(BMRoom *)room;

@end

NS_ASSUME_NONNULL_END
