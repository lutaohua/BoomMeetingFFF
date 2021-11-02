//
//  BMHandleAudio.h
//  BoomMeeting
//
//  Created by zhaozhidan on 2020/12/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/// 处理音频的变化.
@interface BMHandleAudio : NSObject

/// 判断是否插入耳机
- (BOOL)isHeadPhoneEnable;

/// 扬声器和听筒的切换
- (void)switchAudioCategaryWithSpeaker:(BOOL)isSpeaker;

@end

NS_ASSUME_NONNULL_END
