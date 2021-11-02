//
//  BMQueue.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/3.
//

#import <Foundation/Foundation.h>


typedef void (^BMTask)(void);

NS_ASSUME_NONNULL_BEGIN

@interface BMQueue : NSObject

- (void)addTask:(BMTask)task;

- (void)cancel;
@end

NS_ASSUME_NONNULL_END
