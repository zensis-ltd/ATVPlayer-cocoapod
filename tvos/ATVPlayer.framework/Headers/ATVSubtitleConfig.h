//
//  ATVSubtitleConfig.h
//  ATVPlayer SDK
//
//  Created by Zensis on 29/7/2016.
//  Copyright © 2018 Zensis. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class ATVSubtitle;

/**
 * An container holds all ATVSubtitle.
 */
@interface ATVSubtitleConfig : NSObject

/**
 * An array of ATVSubtitle objects for different languages.
 * @see ATVSubtitle
 */
@property(nonatomic) NSArray<ATVSubtitle *>*subtitles;
/**
 * Subtitle text font.
 */
@property(nonatomic) UIFont *subtitleFont;

/**
 * Subtitle text color.
 */
@property(nonatomic) UIColor *subtitleTextColor;

/**
 * Subtitle stroke color.
 */
@property(nonatomic) UIColor *subtitleStrokeColor;

/**
 * Subtitle stroke width.
 *
 * Note that the subtitle is in two layers: stroke and foreground text. The stroke width should be doubled as inner half
 * of the stroke is covered by the foreground text.
 */
@property(nonatomic) CGFloat subtitleStrokeWidth;

/**
 *Factory method that creates ATVSubtitleConfig object with array of ATVSubtitle object.
 *@param subtitles Array of ATVSubtitle object.
 */
+ (instancetype) initWithSubtitles:(NSArray<ATVSubtitle*>*)subtitles;

@end
