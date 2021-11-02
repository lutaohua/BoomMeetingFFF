//
//  BMGiveLikeBarrage.h
//  BoomMeeting
//
//  Created by boom on 2021/3/31.
//

#import <UIKit/UIKit.h>
@class BMMessageInfo;
NS_ASSUME_NONNULL_BEGIN
///点赞弹幕
@interface BMGiveLikeBarrage : UIView

- (void)addMessageInfo:(BMMessageInfo *)info;

@end

NS_ASSUME_NONNULL_END
