//  UITextInputTraits纯协议  作用是提供了很多键盘的属性   完全实现
#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, UITextAutocapitalizationType) {
    UITextAutocapitalizationTypeNone,
    UITextAutocapitalizationTypeWords,
    UITextAutocapitalizationTypeSentences,
    UITextAutocapitalizationTypeAllCharacters,
};

typedef NS_ENUM(NSInteger, UITextAutocorrectionType) {
    UITextAutocorrectionTypeDefault,
    UITextAutocorrectionTypeNo,
    UITextAutocorrectionTypeYes,
};

typedef NS_ENUM(NSInteger, UIKeyboardAppearance) {
    UIKeyboardAppearanceDefault,
    UIKeyboardAppearanceAlert,
};

typedef NS_ENUM(NSInteger, UIKeyboardType) {
    UIKeyboardTypeDefault,
    UIKeyboardTypeASCIICapable,
    UIKeyboardTypeNumbersAndPunctuation,
    UIKeyboardTypeURL,
    UIKeyboardTypeNumberPad,
    UIKeyboardTypePhonePad,
    UIKeyboardTypeNamePhonePad,
    UIKeyboardTypeEmailAddress,
    UIKeyboardTypeDecimalPad,
    UIKeyboardTypeTwitter,
    UIKeyboardTypeAlphabet = UIKeyboardTypeASCIICapable
};

typedef NS_ENUM(NSInteger, UIReturnKeyType) {
    UIReturnKeyDefault,
    UIReturnKeyGo,
    UIReturnKeyGoogle,
    UIReturnKeyJoin,
    UIReturnKeyNext,
    UIReturnKeyRoute,
    UIReturnKeySearch,
    UIReturnKeySend,
    UIReturnKeyYahoo,
    UIReturnKeyDone,
    UIReturnKeyEmergencyCall,
};

@protocol UITextInputTraits <NSObject>
@property (nonatomic) UITextAutocapitalizationType autocapitalizationType;
@property (nonatomic) UITextAutocorrectionType autocorrectionType;
@property (nonatomic) BOOL enablesReturnKeyAutomatically;
@property (nonatomic) UIKeyboardAppearance keyboardAppearance;
@property (nonatomic) UIKeyboardType keyboardType;
@property (nonatomic) UIReturnKeyType returnKeyType;
@property (nonatomic, getter=isSecureTextEntry) BOOL secureTextEntry;
@end
