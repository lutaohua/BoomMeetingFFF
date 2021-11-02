//
//  BMTextView.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/27.
//

#import <UIKit/UIKit.h>

typedef void(^TextHeightChangedBlock)(CGFloat textHeight);

NS_ASSUME_NONNULL_BEGIN

@interface BMTextView : UITextView
@property (nonatomic, copy) NSString *placeholder;
@property (nonatomic, copy) UIColor *placeholderColor;

/// textView最大行数
@property (nonatomic, assign) NSUInteger maxNumberOfLines;


/// 文字高度改变block → 文字高度改变会自动调用
/// block参数(text) → 文字内容
/// block参数(textHeight) → 文字高度
@property (nonatomic, copy) TextHeightChangedBlock textChangedBlock;

@end

NS_ASSUME_NONNULL_END
