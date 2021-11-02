//
//  BMVideoCell.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/11/25.
//

#import <UIKit/UIKit.h>
#import "BMMutliClickButton.h"
@class BCCanvas;
@class BMStreamModel;

typedef void (^ClickVideo)(BMStreamModel * _Nonnull streamModel, NSInteger clickCount);


NS_ASSUME_NONNULL_BEGIN

@interface BMVideoCell : UICollectionViewCell

@property (nonatomic, strong) BMMutliClickButton *btnVideo;

@property (nonatomic, strong) BCCanvas *canvas;

@property (nonatomic, strong) BMStreamModel *streamModel;

@property (nonatomic, copy) ClickVideo clickVideo;

- (void)setupUI;
- (void)willDisplayCell;
- (void)didEndDisplayingCell;

- (void)makeCommonView;

- (void)updateMicWithVolume;
@end

NS_ASSUME_NONNULL_END
