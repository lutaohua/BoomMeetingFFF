//
//  NSString+extension.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/2/7.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (extension)

+ (NSString *)formateDate:(NSTimeInterval)interval;
+ (NSString *)formateHorizontalLineDate:(NSTimeInterval)interval;
@end

NS_ASSUME_NONNULL_END
