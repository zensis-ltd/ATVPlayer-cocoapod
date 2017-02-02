//
//  ATVSubtitle.h
//  ATVPlayer SDK
//
//  Created by Zensis on 29/7/2016.
//  Copyright © 2016 Zensis. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 * An object for creating a individual subtitle in srt.
 */
@interface ATVSubtitle : NSObject

/**
 * Subtitle Url, support SRT format currently
 */
@property (strong,nonatomic) NSURL *url;
/**
 * Subtitle display label, e.g. Chinese, English
 */
@property (copy,nonatomic) NSString *label;

/**
 *Factory method that creates ATVSubtitle object with url and label.
 *@param url URL of the subtitle.
 *@param label Label for this subtitle, useful for display if you add custom subtitle control.
 */
+ (instancetype) subtitleWithUrl:(NSURL*)url label:(NSString *)label;


@end
