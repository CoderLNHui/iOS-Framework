/*
 * NSDictionary+LNDictionary.m
 *
 * Foundation
 *
 * Public_不知名开发者 / https://githubidea.github.io / https://github.com/CoderLN
 * Welcome your star|fork, Your sharing can be together.
 *
 * 尊重熬夜写作的作者，该模块将系统化学习，替换、补充内容。
 */

#import "NSDictionary+LNDictionary.h"

@implementation NSDictionary (LNDictionary)

#pragma mark - 利用链式编程去实现富文本属性的赋值（字体、颜色）
-(NSMutableDictionary *(^)(CGFloat))Font
{
    return ^id(CGFloat font)
    {
        [self setValue:[UIFont systemFontOfSize:font] forKey:NSFontAttributeName];
        return self;
    };
}

-(NSMutableDictionary *(^)(UIColor *))Color
{
    return ^id(UIColor * color)
    {
        [self setValue:color forKey:NSForegroundColorAttributeName];
        return self;
    };
}



#pragma mark - 字典转模型KVC实现(自动生成模型属性代码)
// isKindOfClass:判断是否是当前类或者子类
// 生成属性代码 => 根据字典中所有key
- (void)ln_createPropertyCode
{
    // 拼接属性字符串代码
    NSMutableString *codes = [NSMutableString string];
    // 遍历字典
    [self enumerateKeysAndObjectsUsingBlock:^(id  _Nonnull key, id  _Nonnull value, BOOL * _Nonnull stop) {
        
        NSString *code;
        if ([value isKindOfClass:[NSString class]]) {
            code = [NSString stringWithFormat:@"@property (nonatomic, strong) NSString *%@;",key];
            
        } else if ([value isKindOfClass:NSClassFromString(@"__NSCFBoolean")]) {
            code = [NSString stringWithFormat:@"@property (nonatomic, assign) BOOL %@;",key];
            
        } else if ([value isKindOfClass:[NSNumber class]]) {
            code = [NSString stringWithFormat:@"@property (nonatomic, assign) NSInteger %@;",key];
            
        } else if ([value isKindOfClass:[NSArray class]]) {
            code = [NSString stringWithFormat:@"@property (nonatomic, strong) NSArray *%@;",key];
            
        } else if ([value isKindOfClass:[NSDictionary class]]) {
            code = [NSString stringWithFormat:@"@property (nonatomic, strong) NSDictionary *%@;",key];
        }
        
        // 每生成属性字符串，就自动换行。
        [codes appendFormat:@"\n%@\n",code];
        
    }];
    
    // 把拼接好的字符串打印出来
    NSLog(@"%@",codes);
    
}


@end

