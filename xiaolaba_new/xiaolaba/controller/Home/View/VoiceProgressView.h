//
//  VoiceProgressView.h
//  xiaolaba
//
//  Created by 戴葛辉 on 2018/4/25.
//  Copyright © 2018年 jackzhang. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface VoiceProgressView : UIView

@property (nonatomic,copy) NSString *progressValue;

@property (nonatomic,strong) UIColor *progressColor;

@property (nonatomic,strong) UIColor *progressBackColor;

@property (nonatomic,assign) float time;
@end
