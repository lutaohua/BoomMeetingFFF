//
//  UIImage+BM.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/12.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (BM)

- (UIImage*)scaleToSize:(CGSize)size;

+ (nullable UIImage *)bmImageNamed:(NSString *)name;

@end

NS_ASSUME_NONNULL_END
