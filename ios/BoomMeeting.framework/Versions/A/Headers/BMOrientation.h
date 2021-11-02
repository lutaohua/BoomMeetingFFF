//
//  BMOrientation.h
//  BoomMeeting-BoomMeeting
//
//  Created by zhaozhidan on 2021/1/26.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BMOrientation : NSObject

+ (void)lockToPortrait;

+ (void)lockToLandscapeLeft;
+ (void)lockToLandscapeRight;
@end

NS_ASSUME_NONNULL_END
