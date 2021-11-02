//
//  BMBundle.h
//  BoomMeeting-BoomMeeting
//
//  Created by zhaozhidan on 2021/3/7.
//

#import <Foundation/Foundation.h>


#define BMLocalizedString(key) \
[[BMBundle localizeBundle] localizedStringForKey:(key) value:@"" table:@"BoomMeeting"] ?: key

#define BMConstantString(key) key



NS_ASSUME_NONNULL_BEGIN

@interface BMBundle : NSBundle
+ (NSBundle *)localizeBundle;

+ (void)setLanguage:(NSString *)language;

+ (BOOL)isEnglish;
@end

NS_ASSUME_NONNULL_END
