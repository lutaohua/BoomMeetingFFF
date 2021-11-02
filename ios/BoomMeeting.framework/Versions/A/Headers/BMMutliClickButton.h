//
//  BMMutliClickButton.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/30.
//

#import <UIKit/UIKit.h>

typedef void (^MutliClickAction)(NSInteger clickCount);

NS_ASSUME_NONNULL_BEGIN

@interface BMMutliClickButton : UIButton

@property (nonatomic, copy) MutliClickAction mutliClickAction;

@end

NS_ASSUME_NONNULL_END
