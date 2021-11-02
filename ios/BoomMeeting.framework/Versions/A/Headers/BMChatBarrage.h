//
//  BMChatBarrage.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2021/3/6.
//

#import <UIKit/UIKit.h>
@class BMMessageInfo;

NS_ASSUME_NONNULL_BEGIN

/// 聊天弹幕
@interface BMChatBarrage : UIView

- (void)addMessageInfo:(BMMessageInfo *)info;

@end

NS_ASSUME_NONNULL_END
