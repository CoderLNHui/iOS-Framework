/*
 * NSString.h 
 *
 * Foundation (c) 1994-2017
 */


/*
 An NSString object encodes a Unicode-compliant text string, represented as a sequence of UTF–16 code units. All lengths, character indexes, and ranges are expressed in terms of UTF–16 code units, with index values starting at 0.  The length property of an NSString returns the number of UTF-16 code units in an NSString, and the characterAtIndex: method retrieves a specific UTF-16 code unit. These two "primitive" methods provide basic access to the contents of a string object.
 
 Most use of strings, however, is at a higher level, with the strings being treated as single entities: Using the APIs in NSString, you can compare strings against one another, search them for substrings, combine them into new strings, and so on. In cases where locale settings may make a difference, use the localized... API variants to perform the operations using the current user's locale, or use the locale: variants that take an explicit NSLocale argument.
 
 If you do need to access individual characters in a string, you need to consider whether you want to access the individual UTF-16 code points (referred to as "characters" in APIs, and represented with the "unichar" type), or human-readable characters (referred to as "composed character sequences" or "grapheme clusters").  Composed character sequences can span multiple UTF-16 characters, when representing a base letter plus an accent, for example, or Emoji.
 
 To access composed character sequences, use APIs such as rangeOfComposedCharacterSequenceAtIndex:, or enumerate the whole or part of the string with enumerateSubstringsInRange:options:usingBlock:, supplying NSStringEnumerationByComposedCharacterSequences as the enumeration option.
 
 For instance, to extract the composed character sequence at a given index (where index is a valid location in the string, 0..length-1):
 
 NSString *substr = [string substringWithRange:[string rangeOfComposedCharacterSequenceAtIndex:index]];
 
 And to enumerate composed character sequences in a string:
 
 [string enumerateSubstringsInRange:NSMakeRange(0, string.length)                      // enumerate the whole range of the string
 options:NSStringEnumerationByComposedCharacterSequences    // by composed character sequences
 usingBlock:^(NSString * substr, NSRange substrRange, NSRange enclosingRange, BOOL *stop) {
 ... use substr, whose range in string is substrRange ...
 }];
 
 NSStrings can be immutable or mutable. The contents of an immutable string is defined when it is created and subsequently cannot be changed.  To construct and manage a string that can be changed after it has been created, use NSMutableString, which is a subclass of NSString.
 
 An NSString object can be initialized using a number of ways: From a traditional (char *) C-string, a sequence of bytes, an NSData object, the contents of an NSURL, etc, with the character contents specified in a variety of string encodings, such as ASCII, ISOLatin1, UTF–8, UTF–16, etc.
 */


typedef unsigned short unichar;

#import <limits.h>
#import <Foundation/NSObject.h>
#import <Foundation/NSRange.h>
#import <stdarg.h>


@class NSData, NSArray<ObjectType>, NSDictionary<KeyType, ObjectType>, NSCharacterSet, NSURL, NSError, NSLocale;

NS_ASSUME_NONNULL_BEGIN

/* The unichar type represents a single UTF-16 code unit in an NSString. Although many human-readable characters are representable with a single unichar, some  such as Emoji may span multiple unichars. See discussion above.
 */
#pragma mark -字符串比较选项
typedef NS_OPTIONS(NSUInteger, NSStringCompareOptions) {
    NSCaseInsensitiveSearch = 1,// 不区分大小写比较
    NSLiteralSearch = 2, // 区分大小写比较		/* Exact character-by-character equivalence */
    NSBackwardsSearch = 4,// 从字符串末尾开始搜索		/* Search from end of source string */
    NSAnchoredSearch = 8,// 搜索限制范围的字符串		/* Search is limited to start (or end, if NSBackwardsSearch) of source string */
    NSNumericSearch = 64,// 按照字符串里的数字为依据，算出顺序		/* Added in 10.2; Numbers within strings are compared using numeric value, that is, Foo2.txt < Foo7.txt < Foo25.txt; only applies to compare methods, not find */
    NSDiacriticInsensitiveSearch NS_ENUM_AVAILABLE(10_5, 2_0) = 128, // 忽略 "-" 符号的比较 /* If specified, ignores diacritics (o-umlaut == o) */
    NSWidthInsensitiveSearch NS_ENUM_AVAILABLE(10_5, 2_0) = 256,// 忽略字符串的长度，比较出结果 /* If specified, ignores width differences ('a' == UFF41) */
    NSForcedOrderingSearch NS_ENUM_AVAILABLE(10_5, 2_0) = 512,// 忽略不区分大小写比较的选项 /* If specified, comparisons are forced to return either NSOrderedAscending or NSOrderedDescending if the strings are equivalent but not strictly equal, for stability when sorting (e.g. "aaa" > "AAA" with NSCaseInsensitiveSearch specified) */
    NSRegularExpressionSearch NS_ENUM_AVAILABLE(10_7, 3_2) = 1024  // 只能应用于 rangeOfString:..., stringByReplacingOccurrencesOfString:...和 replaceOccurrencesOfString:...方法
    /* Applies to rangeOfString:..., stringByReplacingOccurrencesOfString:..., and replaceOccurrencesOfString:... methods only; the search string is treated as an ICU-compatible regular expression; if set, no other options can apply except NSCaseInsensitiveSearch and NSAnchoredSearch */
    /**
     比较结果:
        NSComparisonResult    说明
        NSOrderedAscending    升序 (左小右大)
        NSOrderedSame    相同 (内容相同)
        NSOrderedDescending    降序 (左大右小)
     */
};


/* Note that in addition to the values explicitly listed below, NSStringEncoding supports encodings provided by CFString.
 See CFStringEncodingExt.h for a list of these encodings.
 See CFString.h for functions which convert between NSStringEncoding and CFStringEncoding.
 */
#pragma mark -字符串编码
typedef NSUInteger NSStringEncoding;
NS_ENUM(NSStringEncoding) {
    NSASCIIStringEncoding = 1,		/* 0..127 only */
    NSNEXTSTEPStringEncoding = 2,
    NSJapaneseEUCStringEncoding = 3,
    NSUTF8StringEncoding = 4,
    NSISOLatin1StringEncoding = 5,
    NSSymbolStringEncoding = 6,
    NSNonLossyASCIIStringEncoding = 7,
    NSShiftJISStringEncoding = 8,          /* kCFStringEncodingDOSJapanese */
    NSISOLatin2StringEncoding = 9,
    NSUnicodeStringEncoding = 10,
    NSWindowsCP1251StringEncoding = 11,    /* Cyrillic; same as AdobeStandardCyrillic */
    NSWindowsCP1252StringEncoding = 12,    /* WinLatin1 */
    NSWindowsCP1253StringEncoding = 13,    /* Greek */
    NSWindowsCP1254StringEncoding = 14,    /* Turkish */
    NSWindowsCP1250StringEncoding = 15,    /* WinLatin2 */
    NSISO2022JPStringEncoding = 21,        /* ISO 2022 Japanese encoding for e-mail */
    NSMacOSRomanStringEncoding = 30,
    
    NSUTF16StringEncoding = NSUnicodeStringEncoding,      /* An alias for NSUnicodeStringEncoding */
    
    NSUTF16BigEndianStringEncoding = 0x90000100,          /* NSUTF16StringEncoding encoding with explicit endianness specified */
    NSUTF16LittleEndianStringEncoding = 0x94000100,       /* NSUTF16StringEncoding encoding with explicit endianness specified */
    
    NSUTF32StringEncoding = 0x8c000100,
    NSUTF32BigEndianStringEncoding = 0x98000100,          /* NSUTF32StringEncoding encoding with explicit endianness specified */
    NSUTF32LittleEndianStringEncoding = 0x9c000100        /* NSUTF32StringEncoding encoding with explicit endianness specified */
};
    
typedef NS_OPTIONS(NSUInteger, NSStringEncodingConversionOptions) {
    NSStringEncodingConversionAllowLossy = 1,
    NSStringEncodingConversionExternalRepresentation = 2
};

#pragma mark -字符串分行、分段
typedef NS_OPTIONS(NSUInteger, NSStringEnumerationOptions) {
    // Pass in one of the "By" options:
    NSStringEnumerationByLines = 0,// 按行                       // Equivalent to lineRangeForRange:
    NSStringEnumerationByParagraphs = 1, // 按段落                 // Equivalent to paragraphRangeForRange:
    NSStringEnumerationByComposedCharacterSequences = 2,// 按字符顺序  // Equivalent to rangeOfComposedCharacterSequencesForRange:
    NSStringEnumerationByWords = 3,// 按单词,字
    NSStringEnumerationBySentences = 4,// 按句子
    // ...and combine any of the desired additional options:
    NSStringEnumerationReverse = 1UL << 8,// 反向遍历
    NSStringEnumerationSubstringNotRequired = 1UL << 9,// 不需要子字符串
    NSStringEnumerationLocalized = 1UL << 10 //     本地化             // User's default locale
};

    
#pragma mark - 【字符串属性】
@interface NSString : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>


/* NSString primitives. A minimal subclass of NSString just needs to implement these two, along with an init method appropriate for that subclass. We also recommend overriding getCharacters:range: for performance.
 */
#pragma mark -长度
@property (readonly) NSUInteger length;

#pragma mark -下标字符对应字符串
- (unichar)characterAtIndex:(NSUInteger)index;

/* The initializers available to subclasses. See further below for additional init methods.
 */
#pragma mark -初始化
- (instancetype)init NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)aDecoder NS_DESIGNATED_INITIALIZER;

@end
    
@interface NSString (NSStringExtensionMethods)

#pragma mark - 【字符串截取】
/* To avoid breaking up character sequences such as Emoji, you can do:
 [str substringFromIndex:[str rangeOfComposedCharacterSequenceAtIndex:index].location]
 [str substringToIndex:NSMaxRange([str rangeOfComposedCharacterSequenceAtIndex:index])]
 [str substringWithRange:[str rangeOfComposedCharacterSequencesForRange:range]
 */
-
#pragma mark -截取指定位置之后的字符串（包括指定位置的字符）
- (NSString *)substringFromIndex:(NSUInteger)from;

#pragma mark -从0下标开始截取到指定位置的字符串（但不包括该位置的字符）
- (NSString *)substringToIndex:(NSUInteger)to;

#pragma mark -截取指定范围的字符串（包括该位置的字符），任意地从字符串中截取子串
- (NSString *)substringWithRange:(NSRange)range;                // Use with rangeOfComposedCharacterSequencesForRange: to avoid breaking up character sequences

#pragma mark -截取字符串指定范围的字符
- (void)getCharacters:(unichar *)buffer range:(NSRange)range;   // Use with rangeOfComposedCharacterSequencesForRange: to avoid breaking up character sequences


#pragma mark - 【字符串比较】
/* In the compare: methods, the range argument specifies the subrange, rather than the whole, of the receiver to use in the comparison. The range is not applied to the search string.  For example, [@"AB" compare:@"ABC" options:0 range:NSMakeRange(0,1)] compares "A" to "ABC", not "A" to "A", and will return NSOrderedAscending. It is an error to specify a range that is outside of the receiver's bounds, and an exception may be raised.
 */
#pragma mark -比较
- (NSComparisonResult)compare:(NSString *)string;

#pragma mark -比较(指定字符串,条件)
- (NSComparisonResult)compare:(NSString *)string options:(NSStringCompareOptions)mask;

#pragma mark -比较(指定字符串,条件,范围)
- (NSComparisonResult)compare:(NSString *)string options:(NSStringCompareOptions)mask range:(NSRange)compareRange;

#pragma mark -比较(指定字符串,条件,范围,本地化)
- (NSComparisonResult)compare:(NSString *)string options:(NSStringCompareOptions)mask range:(NSRange)compareRange locale:(nullable id)locale;

#pragma mark -比较(不区分大小写)
- (NSComparisonResult)caseInsensitiveCompare:(NSString *)string;

#pragma mark -本地化比较
- (NSComparisonResult)localizedCompare:(NSString *)string;

#pragma mark -本地化比较(不区分大小写)
- (NSComparisonResult)localizedCaseInsensitiveCompare:(NSString *)string;

#pragma mark -本地化比较(标准)
- (NSComparisonResult)localizedStandardCompare:(NSString *)string;

#pragma mark -判断两个字符串是否内容一致
- (BOOL)isEqualToString:(NSString *)aString;



#pragma mark - 【字符串搜索】
/* These perform locale unaware prefix or suffix match. If you need locale awareness, use rangeOfString:options:range:locale:, passing NSAnchoredSearch (or'ed with NSBackwardsSearch for suffix, and NSCaseInsensitiveSearch|NSDiacriticInsensitiveSearch if needed) for options, NSMakeRange(0, [receiver length]) for range, and [NSLocale currentLocale] for locale.
 */
#pragma mark -是否包含前缀(以str开头)
- (BOOL)hasPrefix:(NSString *)str;

#pragma mark -是否包含后缀(以str结尾)
- (BOOL)hasSuffix:(NSString *)str;

#pragma mark -获取公共前缀
- (NSString *)commonPrefixWithString:(NSString *)str options:(NSStringCompareOptions)mask;

/* Simple convenience methods for string searching. containsString: returns YES if the target string is contained within the receiver. Same as calling rangeOfString:options: with no options, thus doing a case-sensitive, locale-unaware search. localizedCaseInsensitiveContainsString: is the case-insensitive variant which also takes the current locale into effect. Starting in 10.11 and iOS9, the new localizedStandardRangeOfString: or localizedStandardContainsString: APIs are even better convenience methods for user level searching.   More sophisticated needs can be achieved by calling rangeOfString:options:range:locale: directly.
 */
#pragma mark -是否包含字符串
- (BOOL)containsString:(NSString *)str NS_AVAILABLE(10_10, 8_0);

#pragma mark -本地化是否包含字符串(不区分大小写)
- (BOOL)localizedCaseInsensitiveContainsString:(NSString *)str NS_AVAILABLE(10_10, 8_0);

/* The following two are the most appropriate methods for doing user-level string searches, similar to how searches are done generally in the system.  The search is locale-aware, case and diacritic insensitive. As with other APIs, "standard" in the name implies "system default behavior," so the exact list of search options applied may change over time.  If you need more control over the search options, please use the rangeOfString:options:range:locale: method. You can pass [NSLocale currentLocale] for searches in user's locale.
 */

#pragma mark -本地化是否包含字符串(标准)
- (BOOL)localizedStandardContainsString:(NSString *)str NS_AVAILABLE(10_11, 9_0);

#pragma mark -本地化搜索字符串范围(标准)
- (NSRange)localizedStandardRangeOfString:(NSString *)str NS_AVAILABLE(10_11, 9_0);

/* These methods perform string search, looking for the searchString within the receiver string.  These return length==0 if the target string is not found. So, to check for containment: ([str rangeOfString:@"target"].length > 0).  Note that the length of the range returned by these methods might be different than the length of the target string, due composed characters and such.
 
 Note that the first three methods do not take locale arguments, and perform the search in a non-locale aware fashion, which is not appropriate for user-level searching. To do user-level string searching, use the last method, specifying locale:[NSLocale currentLocale], or better yet, use localizedStandardRangeOfString: or localizedStandardContainsString:.
 
 The range argument specifies the subrange, rather than the whole, of the receiver to use in the search.  It is an error to specify a range that is outside of the receiver's bounds, and an exception may be raised.
 */
#pragma mark -搜索(指定字符串)
- (NSRange)rangeOfString:(NSString *)searchString;

#pragma mark -搜索(指定字符串,条件)
- (NSRange)rangeOfString:(NSString *)searchString options:(NSStringCompareOptions)mask;

#pragma mark -搜索(指定字符串,条件,范围)
- (NSRange)rangeOfString:(NSString *)searchString options:(NSStringCompareOptions)mask range:(NSRange)rangeOfReceiverToSearch;

#pragma mark -搜索(指定字符串,条件,范围,本地化)
- (NSRange)rangeOfString:(NSString *)searchString options:(NSStringCompareOptions)mask range:(NSRange)rangeOfReceiverToSearch locale:(nullable NSLocale *)locale NS_AVAILABLE(10_5, 2_0);


/* These return the range of the first character from the set in the string, not the range of a sequence of characters.
 
 The range argument specifies the subrange, rather than the whole, of the receiver to use in the search.  It is an error to specify a range that is outside of the receiver's bounds, and an exception may be raised.
 */
#pragma mark -搜索(指定字符集合)
- (NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)searchSet;

#pragma mark -搜索(指定字符集合,条件)
- (NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)searchSet options:(NSStringCompareOptions)mask;

#pragma mark -搜索(指定字符集合,条件,范围)
- (NSRange)rangeOfCharacterFromSet:(NSCharacterSet *)searchSet options:(NSStringCompareOptions)mask range:(NSRange)rangeOfReceiverToSearch;

#pragma mark -用字符串的字符编码指定索引查找位置
- (NSRange)rangeOfComposedCharacterSequenceAtIndex:(NSUInteger)index;

#pragma mark -用字符串的字符编码指定区域段查找位置
- (NSRange)rangeOfComposedCharacterSequencesForRange:(NSRange)range NS_AVAILABLE(10_5, 2_0);



#pragma mark - 【字符串拼接】
#pragma mark -普通拼接
- (NSString *)stringByAppendingString:(NSString *)aString;
#pragma mark -格式化拼接
- (NSString *)stringByAppendingFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);


#pragma mark - 【字符串基本类型转换】
/* The following convenience methods all skip initial space characters (whitespaceSet) and ignore trailing characters. They are not locale-aware. NSScanner or NSNumberFormatter can be used for more powerful and locale-aware parsing of numbers.
 */
@property (readonly) double doubleValue;
@property (readonly) float floatValue;
@property (readonly) int intValue;
@property (readonly) NSInteger integerValue NS_AVAILABLE(10_5, 2_0);
@property (readonly) long long longLongValue NS_AVAILABLE(10_5, 2_0);
@property (readonly) BOOL boolValue NS_AVAILABLE(10_5, 2_0);  // Skips initial space characters (whitespaceSet), or optional -/+ sign followed by zeroes. Returns YES on encountering one of "Y", "y", "T", "t", or a digit 1-9. It ignores any trailing characters.




#pragma mark - 【字符串大小写转换】
/* The following three return the canonical (non-localized) mappings. They are suitable for programming operations that require stable results not depending on the user's locale preference.  For locale-aware case mapping for strings presented to users, use the "localized" methods below.
 */

#pragma mark -大写
@property (readonly, copy) NSString *uppercaseString;
#pragma mark -小写
@property (readonly, copy) NSString *lowercaseString;
#pragma mark -首字母大写
@property (readonly, copy) NSString *capitalizedString;

/* The following three return the locale-aware case mappings. They are suitable for strings presented to the user.
 */
@property (readonly, copy) NSString *localizedUppercaseString NS_AVAILABLE(10_11, 9_0);

@property (readonly, copy) NSString *localizedLowercaseString NS_AVAILABLE(10_11, 9_0);

@property (readonly, copy) NSString *localizedCapitalizedString NS_AVAILABLE(10_11, 9_0);


/* The following methods perform localized case mappings based on the locale specified. Passing nil indicates the canonical mapping.  For the user preference locale setting, specify +[NSLocale currentLocale].
 */
#pragma mark -本地化(大写)
- (NSString *)uppercaseStringWithLocale:(nullable NSLocale *)locale NS_AVAILABLE(10_8, 6_0);
#pragma mark -本地化(小写)
- (NSString *)lowercaseStringWithLocale:(nullable NSLocale *)locale NS_AVAILABLE(10_8, 6_0);
#pragma mark -本地化(首字母大写)
- (NSString *)capitalizedStringWithLocale:(nullable NSLocale *)locale NS_AVAILABLE(10_8, 6_0);


#pragma mark - 【字符串分行,分段】
#pragma mark -指定范围,分行取字符串
- (void)getLineStart:(nullable NSUInteger *)startPtr end:(nullable NSUInteger *)lineEndPtr contentsEnd:(nullable NSUInteger *)contentsEndPtr forRange:(NSRange)range;
#pragma mark -获取指定范围该行的范围
- (NSRange)lineRangeForRange:(NSRange)range;

#pragma mark -指定范围,分段取字符串
- (void)getParagraphStart:(nullable NSUInteger *)startPtr end:(nullable NSUInteger *)parEndPtr contentsEnd:(nullable NSUInteger *)contentsEndPtr forRange:(NSRange)range;
#pragma mark -获取指定范围该段落的范围
- (NSRange)paragraphRangeForRange:(NSRange)range;


/* In the enumerate methods, the blocks will be invoked inside an autorelease pool, so any values assigned inside the block should be retained.
 */
#pragma mark -列举(按行)
- (void)enumerateSubstringsInRange:(NSRange)range options:(NSStringEnumerationOptions)opts usingBlock:(void (^)(NSString * _Nullable substring, NSRange substringRange, NSRange enclosingRange, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);

#pragma mark -列举(范围,条件)
- (void)enumerateLinesUsingBlock:(void (^)(NSString *line, BOOL *stop))block NS_AVAILABLE(10_6, 4_0);



#pragma mark - 【字符串编码和转换】
//*** Character encoding and converting to/from c-string representations ***

@property (nullable, readonly) const char *UTF8String NS_RETURNS_INNER_POINTER;	// Convenience to return null-terminated UTF8 representation

#pragma mark -最快编码值(枚举)
@property (readonly) NSStringEncoding fastestEncoding;    	// Result in O(1) time; a rough estimate
#pragma mark -最小编码值(枚举)
@property (readonly) NSStringEncoding smallestEncoding;   	// Result in O(n) time; the encoding in which the string is most compact

#pragma mark -选择编码,是否允许有损编码
- (nullable NSData *)dataUsingEncoding:(NSStringEncoding)encoding allowLossyConversion:(BOOL)lossy;   // External representation
#pragma mark -选择编码
- (nullable NSData *)dataUsingEncoding:(NSStringEncoding)encoding;                                    // External representation

#pragma mark -判断是否可以无损编码
- (BOOL)canBeConvertedToEncoding:(NSStringEncoding)encoding;

/* Methods to convert NSString to a NULL-terminated cString using the specified encoding. Note, these are the "new" cString methods, and are not deprecated like the older cString methods which do not take encoding arguments.
 */
#pragma mark -C字符编码转换
- (nullable const char *)cStringUsingEncoding:(NSStringEncoding)encoding NS_RETURNS_INNER_POINTER;	// "Autoreleased"; NULL return if encoding conversion not possible; for performance reasons, lifetime of this should not be considered longer than the lifetime of the receiving string (if the receiver string is freed, this might go invalid then, before the end of the autorelease scope)

#pragma mark -判读C字符转化是否可以成功
- (BOOL)getCString:(char *)buffer maxLength:(NSUInteger)maxBufferCount encoding:(NSStringEncoding)encoding;	// NO return if conversion not possible due to encoding errors or too small of a buffer. The buffer should include room for maxBufferCount bytes; this number should accomodate the expected size of the return value plus the NULL termination character, which this method adds. (So note that the maxLength passed to this method is one more than the one you would have passed to the deprecated getCString:maxLength:.)

/* Use this to convert string section at a time into a fixed-size buffer, without any allocations.  Does not NULL-terminate.
 buffer is the buffer to write to; if NULL, this method can be used to computed size of needed buffer.
 maxBufferCount is the length of the buffer in bytes. It's a good idea to make sure this is at least enough to hold one character's worth of conversion.
 usedBufferCount is the length of the buffer used up by the current conversion. Can be NULL.
 encoding is the encoding to convert to.
 options specifies the options to apply.
 range is the range to convert.
 leftOver is the remaining range. Can be NULL.
 YES return indicates some characters were converted. Conversion might usually stop when the buffer fills,
 but it might also stop when the conversion isn't possible due to the chosen encoding.
 */

#pragma mark -指定缓存区转换
- (BOOL)getBytes:(nullable void *)buffer maxLength:(NSUInteger)maxBufferCount usedLength:(nullable NSUInteger *)usedBufferCount encoding:(NSStringEncoding)encoding options:(NSStringEncodingConversionOptions)options range:(NSRange)range remainingRange:(nullable NSRangePointer)leftover;

/* These return the maximum and exact number of bytes needed to store the receiver in the specified encoding in non-external representation. The first one is O(1), while the second one is O(n). These do not include space for a terminating null.
 */
#pragma mark -对字符串进行编码时所需的最大字节数
- (NSUInteger)maximumLengthOfBytesUsingEncoding:(NSStringEncoding)enc;	// Result in O(1) time; the estimate may be way over what's needed. Returns 0 on error (overflow)
#pragma mark -对字符串进行编码时所需的字节数
- (NSUInteger)lengthOfBytesUsingEncoding:(NSStringEncoding)enc;		// Result in O(n) time; the result is exact. Returns 0 on error (cannot convert to specified encoding, or overflow)

#if FOUNDATION_SWIFT_SDK_EPOCH_AT_LEAST(8)
#pragma mark -可用字符串编码
@property (class, readonly) const NSStringEncoding *availableStringEncodings;
#endif

#pragma mark -本地化编码名称
+ (NSString *)localizedNameOfStringEncoding:(NSStringEncoding)encoding;

/* User-dependent encoding whose value is derived from user's default language and potentially other factors. The use of this encoding might sometimes be needed when interpreting user documents with unknown encodings, in the absence of other hints.  This encoding should be used rarely, if at all. Note that some potential values here might result in unexpected encoding conversions of even fairly straightforward NSString content --- for instance, punctuation characters with a bidirectional encoding.
 */
#if FOUNDATION_SWIFT_SDK_EPOCH_AT_LEAST(8)
#pragma mark -默认C字符串编码
@property (class, readonly) NSStringEncoding defaultCStringEncoding;	// Should be rarely used
#endif



#pragma mark - 【字符串操作(分割,修剪,填充,折叠,替换)】
@property (readonly, copy) NSString *decomposedStringWithCanonicalMapping;
@property (readonly, copy) NSString *precomposedStringWithCanonicalMapping;
@property (readonly, copy) NSString *decomposedStringWithCompatibilityMapping;
@property (readonly, copy) NSString *precomposedStringWithCompatibilityMapping;

#pragma mark -分割(指定字符串)
- (NSArray<NSString *> *)componentsSeparatedByString:(NSString *)separator;
#pragma mark -分割(指定字符集合)
- (NSArray<NSString *> *)componentsSeparatedByCharactersInSet:(NSCharacterSet *)separator NS_AVAILABLE(10_5, 2_0);
/**
 字符集合:
 NSCharacterSet    说明
 controlCharacterSet    控制符
 whitespaceCharacterSet    空格符
 whitespaceAndNewlineCharacterSet    空格换行符
 decimalDigitCharacterSet    小数
 letterCharacterSet    文字
 lowercaseLetterCharacterSet    小写字母
 uppercaseLetterCharacterSet    大写字母
 nonBaseCharacterSet    非基础
 alphanumericCharacterSet    数字字母
 decomposableCharacterSet    可分解
 illegalCharacterSet    非法
 punctuationCharacterSet    标点
 capitalizedLetterCharacterSet    大写
 symbolCharacterSet    符号
 newlineCharacterSet    换行符
 */

#pragma mark -修剪
- (NSString *)stringByTrimmingCharactersInSet:(NSCharacterSet *)set;
#pragma mark -填充
- (NSString *)stringByPaddingToLength:(NSUInteger)newLength withString:(NSString *)padString startingAtIndex:(NSUInteger)padIndex;

/* Returns a string with the character folding options applied. theOptions is a mask of compare flags with *InsensitiveSearch suffix.
 */
#pragma mark -折叠
- (NSString *)stringByFoldingWithOptions:(NSStringCompareOptions)options locale:(nullable NSLocale *)locale NS_AVAILABLE(10_5, 2_0);

/* Replace all occurrences of the target string in the specified range with replacement. Specified compare options are used for matching target. If NSRegularExpressionSearch is specified, the replacement is treated as a template, as in the corresponding NSRegularExpression methods, and no other options can apply except NSCaseInsensitiveSearch and NSAnchoredSearch.
 */
#pragma mark -替换
- (NSString *)stringByReplacingOccurrencesOfString:(NSString *)target withString:(NSString *)replacement options:(NSStringCompareOptions)options range:(NSRange)searchRange NS_AVAILABLE(10_5, 2_0);

/* Replace all occurrences of the target string with replacement. Invokes the above method with 0 options and range of the whole string.
 */
#pragma mark -替换(指定字符串,条件,范围)
- (NSString *)stringByReplacingOccurrencesOfString:(NSString *)target withString:(NSString *)replacement NS_AVAILABLE(10_5, 2_0);

/* Replace characters in range with the specified string, returning new string.
 */
#pragma mark -替换(指定范围)
- (NSString *)stringByReplacingCharactersInRange:(NSRange)range withString:(NSString *)replacement NS_AVAILABLE(10_5, 2_0);

typedef NSString *NSStringTransform NS_EXTENSIBLE_STRING_ENUM;

/* Perform string transliteration.  The transformation represented by transform is applied to the receiver. reverse indicates that the inverse transform should be used instead, if it exists. Attempting to use an invalid transform identifier or reverse an irreversible transform will return nil; otherwise the transformed string value is returned (even if no characters are actually transformed). You can pass one of the predefined transforms below (NSStringTransformLatinToKatakana, etc), or any valid ICU transform ID as defined in the ICU User Guide. Arbitrary ICU transform rules are not supported.
 */
#pragma mark -字符串翻译
- (nullable NSString *)stringByApplyingTransform:(NSStringTransform)transform reverse:(BOOL)reverse NS_AVAILABLE(10_11, 9_0);	// Returns nil if reverse not applicable or transform is invalid

FOUNDATION_EXPORT NSStringTransform const NSStringTransformLatinToKatakana         NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformLatinToHiragana         NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformLatinToHangul           NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformLatinToArabic           NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformLatinToHebrew           NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformLatinToThai             NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformLatinToCyrillic         NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformLatinToGreek            NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformToLatin                 NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformMandarinToLatin         NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformHiraganaToKatakana      NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformFullwidthToHalfwidth    NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformToXMLHex                NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformToUnicodeName           NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformStripCombiningMarks     NS_AVAILABLE(10_11, 9_0);
FOUNDATION_EXPORT NSStringTransform const NSStringTransformStripDiacritics         NS_AVAILABLE(10_11, 9_0);
/**
 字符串翻译
 NSStringTransformLatinToKatakana	拉丁->片假名
 NSStringTransformLatinToHiragana	拉丁->平假名
 NSStringTransformLatinToHangul	拉丁->韩语
 NSStringTransformLatinToArabic	拉丁->阿拉伯语
 NSStringTransformLatinToHebrew	拉丁->希伯来语
 NSStringTransformLatinToThai	拉丁->泰国
 NSStringTransformLatinToCyrillic	拉丁->西里尔字母
 NSStringTransformLatinToGreek	拉丁->希腊
 NSStringTransformToLatin	拉丁
 NSStringTransformMandarinToLatin	普通话->拉丁
 NSStringTransformHiraganaToKatakana	平假名->片假名
 NSStringTransformFullwidthToHalfwidth	全角->半角
 NSStringTransformToXMLHex	XML16进制
 NSStringTransformToUnicodeName	Unicode名
 NSStringTransformStripCombiningMarks	结合地带商标
 NSStringTransformStripDiacritics	带音符
 */

/* Write to specified url or path using the specified encoding.  The optional error return is to indicate file system or encoding errors.
 */
#pragma mark -写入到指定路径,编码的文件中
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)useAuxiliaryFile encoding:(NSStringEncoding)enc error:(NSError **)error;
#pragma mark -写入到指定URL,编码的文件中
- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile encoding:(NSStringEncoding)enc error:(NSError **)error;


@property (readonly, copy) NSString *description;
@property (readonly) NSUInteger hash;


#pragma mark - 【初始化】
/* In general creation methods in NSString do not apply to subclassers, as subclassers are assumed to provide their own init methods which create the string in the way the subclass wishes.  Designated initializers of NSString are thus init and initWithCoder:.
 */
- (instancetype)initWithCharactersNoCopy:(unichar *)characters length:(NSUInteger)length freeWhenDone:(BOOL)freeBuffer;	/* "NoCopy" is a hint */
- (instancetype)initWithCharacters:(const unichar *)characters length:(NSUInteger)length;
- (nullable instancetype)initWithUTF8String:(const char *)nullTerminatedCString;
- (instancetype)initWithString:(NSString *)aString;
- (instancetype)initWithFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);
- (instancetype)initWithFormat:(NSString *)format arguments:(va_list)argList NS_FORMAT_FUNCTION(1,0);
- (instancetype)initWithFormat:(NSString *)format locale:(nullable id)locale, ... NS_FORMAT_FUNCTION(1,3);
- (instancetype)initWithFormat:(NSString *)format locale:(nullable id)locale arguments:(va_list)argList NS_FORMAT_FUNCTION(1,0);
- (nullable instancetype)initWithData:(NSData *)data encoding:(NSStringEncoding)encoding;
- (nullable instancetype)initWithBytes:(const void *)bytes length:(NSUInteger)len encoding:(NSStringEncoding)encoding;
- (nullable instancetype)initWithBytesNoCopy:(void *)bytes length:(NSUInteger)len encoding:(NSStringEncoding)encoding freeWhenDone:(BOOL)freeBuffer;	/* "NoCopy" is a hint */

+ (instancetype)string;
+ (instancetype)stringWithString:(NSString *)string;
+ (instancetype)stringWithCharacters:(const unichar *)characters length:(NSUInteger)length;
+ (nullable instancetype)stringWithUTF8String:(const char *)nullTerminatedCString;
+ (instancetype)stringWithFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);
+ (instancetype)localizedStringWithFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);

- (nullable instancetype)initWithCString:(const char *)nullTerminatedCString encoding:(NSStringEncoding)encoding;
+ (nullable instancetype)stringWithCString:(const char *)cString encoding:(NSStringEncoding)enc;

/* These use the specified encoding.  If nil is returned, the optional error return indicates problem that was encountered (for instance, file system or encoding errors).
 */
- (nullable instancetype)initWithContentsOfURL:(NSURL *)url encoding:(NSStringEncoding)enc error:(NSError **)error;
- (nullable instancetype)initWithContentsOfFile:(NSString *)path encoding:(NSStringEncoding)enc error:(NSError **)error;
+ (nullable instancetype)stringWithContentsOfURL:(NSURL *)url encoding:(NSStringEncoding)enc error:(NSError **)error;
+ (nullable instancetype)stringWithContentsOfFile:(NSString *)path encoding:(NSStringEncoding)enc error:(NSError **)error;

/* These try to determine the encoding, and return the encoding which was used.  Note that these methods might get "smarter" in subsequent releases of the system, and use additional techniques for recognizing encodings. If nil is returned, the optional error return indicates problem that was encountered (for instance, file system or encoding errors).
 */
- (nullable instancetype)initWithContentsOfURL:(NSURL *)url usedEncoding:(nullable NSStringEncoding *)enc error:(NSError **)error;
- (nullable instancetype)initWithContentsOfFile:(NSString *)path usedEncoding:(nullable NSStringEncoding *)enc error:(NSError **)error;
+ (nullable instancetype)stringWithContentsOfURL:(NSURL *)url usedEncoding:(nullable NSStringEncoding *)enc error:(NSError **)error;
+ (nullable instancetype)stringWithContentsOfFile:(NSString *)path usedEncoding:(nullable NSStringEncoding *)enc error:(NSError **)error;

@end
    

typedef NSString * NSStringEncodingDetectionOptionsKey NS_STRING_ENUM;
@interface NSString (NSStringEncodingDetection)

// - 编码检测
/* This API is used to detect the string encoding of a given raw data. It can also do lossy string conversion. It converts the data to a string in the detected string encoding. The data object contains the raw bytes, and the option dictionary contains the hints and parameters for the analysis. The opts dictionary can be nil. If the string parameter is not NULL, the string created by the detected string encoding is returned. The lossy substitution string is emitted in the output string for characters that could not be converted when lossy conversion is enabled. The usedLossyConversion indicates if there is any lossy conversion in the resulted string. If no encoding can be detected, 0 is returned.
 
 The possible items for the dictionary are:
 1) an array of suggested string encodings (without specifying the 3rd option in this list, all string encodings are considered but the ones in the array will have a higher preference; moreover, the order of the encodings in the array is important: the first encoding has a higher preference than the second one in the array)
 2) an array of string encodings not to use (the string encodings in this list will not be considered at all)
 3) a boolean option indicating whether only the suggested string encodings are considered
 4) a boolean option indicating whether lossy is allowed
 5) an option that gives a specific string to substitude for mystery bytes
 6) the current user's language
 7) a boolean option indicating whether the data is generated by Windows
 
 If the values in the dictionary have wrong types (for example, the value of NSStringEncodingDetectionSuggestedEncodingsKey is not an array), an exception is thrown.
 If the values in the dictionary are unknown (for example, the value in the array of suggested string encodings is not a valid encoding), the values will be ignored.
 */
+ (NSStringEncoding)stringEncodingForData:(NSData *)data
                          encodingOptions:(nullable NSDictionary<NSStringEncodingDetectionOptionsKey, id> *)opts
                          convertedString:(NSString * _Nullable * _Nullable)string
                      usedLossyConversion:(nullable BOOL *)usedLossyConversion NS_AVAILABLE(10_10, 8_0);

/* The following keys are for the option dictionary for the string encoding detection API.
 */
FOUNDATION_EXPORT NSStringEncodingDetectionOptionsKey const NSStringEncodingDetectionSuggestedEncodingsKey           NS_AVAILABLE(10_10, 8_0);   // NSArray of NSNumbers which contain NSStringEncoding values; if this key is not present in the dictionary, all encodings are weighted the same
FOUNDATION_EXPORT NSStringEncodingDetectionOptionsKey const NSStringEncodingDetectionDisallowedEncodingsKey          NS_AVAILABLE(10_10, 8_0);   // NSArray of NSNumbers which contain NSStringEncoding values; if this key is not present in the dictionary, all encodings are considered
FOUNDATION_EXPORT NSStringEncodingDetectionOptionsKey const NSStringEncodingDetectionUseOnlySuggestedEncodingsKey    NS_AVAILABLE(10_10, 8_0);   // NSNumber boolean value; if this key is not present in the dictionary, the default value is NO
FOUNDATION_EXPORT NSStringEncodingDetectionOptionsKey const NSStringEncodingDetectionAllowLossyKey                   NS_AVAILABLE(10_10, 8_0);   // NSNumber boolean value; if this key is not present in the dictionary, the default value is YES
FOUNDATION_EXPORT NSStringEncodingDetectionOptionsKey const NSStringEncodingDetectionFromWindowsKey                  NS_AVAILABLE(10_10, 8_0);   // NSNumber boolean value; if this key is not present in the dictionary, the default value is NO
FOUNDATION_EXPORT NSStringEncodingDetectionOptionsKey const NSStringEncodingDetectionLossySubstitutionKey            NS_AVAILABLE(10_10, 8_0);   // NSString value; if this key is not present in the dictionary, the default value is U+FFFD
FOUNDATION_EXPORT NSStringEncodingDetectionOptionsKey const NSStringEncodingDetectionLikelyLanguageKey               NS_AVAILABLE(10_10, 8_0);   // NSString value; ISO language code; if this key is not present in the dictionary, no such information is considered

@end
    
    
    
    
    
    
    
    
    
#pragma mark - 【NSMutableString 是动态的字符串，可以动态的添加，修改，删除等】
@interface NSMutableString : NSString

/* NSMutableString primitive (funnel) method. See below for the other mutation methods.
 */
-
#pragma mark -指定范围替换
- (void)replaceCharactersInRange:(NSRange)range withString:(NSString *)aString;

@end
    
@interface NSMutableString (NSMutableStringExtensionMethods)

/* Additional mutation methods.  For subclassers these are all available implemented in terms of the primitive replaceCharactersInRange:range: method.
 */

#pragma mark -插入
- (void)insertString:(NSString *)aString atIndex:(NSUInteger)loc;
#pragma mark -删除
- (void)deleteCharactersInRange:(NSRange)range;
#pragma mark -拼接
- (void)appendString:(NSString *)aString;
#pragma mark -格式化拼接
- (void)appendFormat:(NSString *)format, ... NS_FORMAT_FUNCTION(1,2);
#pragma mark -设置新字符串
- (void)setString:(NSString *)aString;

/* This method replaces all occurrences of the target string with the replacement string, in the specified range of the receiver string, and returns the number of replacements. NSBackwardsSearch means the search is done from the end of the range (the results could be different); NSAnchoredSearch means only anchored (but potentially multiple) instances will be replaced. NSLiteralSearch and NSCaseInsensitiveSearch also apply. NSNumericSearch is ignored. Use NSMakeRange(0, [receiver length]) to process whole string. If NSRegularExpressionSearch is specified, the replacement is treated as a template, as in the corresponding NSRegularExpression methods, and no other options can apply except NSCaseInsensitiveSearch and NSAnchoredSearch.
 */

#pragma mark -指定字符串,条件,范围替换
- (NSUInteger)replaceOccurrencesOfString:(NSString *)target withString:(NSString *)replacement options:(NSStringCompareOptions)options range:(NSRange)searchRange;

/* Perform string transliteration.  The transformation represented by transform is applied to the given range of string in place. Only the specified range will be modified, but the transform may look at portions of the string outside that range for context. If supplied, resultingRange is modified to reflect the new range corresponding to the original range. reverse indicates that the inverse transform should be used instead, if it exists. Attempting to use an invalid transform identifier or reverse an irreversible transform will return NO; otherwise YES is returned, even if no characters are actually transformed. You can pass one of the predefined transforms listed above (NSStringTransformLatinToKatakana, etc), or any valid ICU transform ID as defined in the ICU User Guide. Arbitrary ICU transform rules are not supported.
 */
- (BOOL)applyTransform:(NSString *)transform reverse:(BOOL)reverse range:(NSRange)range updatedRange:(nullable NSRangePointer)resultingRange NS_AVAILABLE(10_11, 9_0);

/* In addition to these two, NSMutableString responds properly to all NSString creation methods.
 */
#pragma mark -字符串分配容量
- (NSMutableString *)initWithCapacity:(NSUInteger)capacity;
+ (NSMutableString *)stringWithCapacity:(NSUInteger)capacity;
/**
 //1.初始化容量为Capacity大小的字符串  (需要手动释放内存)
 NSMutableString *mutableStr1 = [[NSMutableString alloc] initWithCapacity:20];
 
 //2.初始化容量为Capacity大小的字符串  (不需要手动释放内存)
 NSMutableString *mutableStr2 = [NSMutableString stringWithCapacity:20];
 */
@end
    
    
    
FOUNDATION_EXPORT NSExceptionName const NSCharacterConversionException;
FOUNDATION_EXPORT NSExceptionName const NSParseErrorException; // raised by -propertyList
#define NSMaximumStringLength	(INT_MAX-1)
    
// *** Deprecated/discouraged APIs ***
#pragma mark - 弃用
@interface NSString (NSExtendedStringPropertyListParsing)

/* These methods are no longer recommended since they do not work with property lists and strings files in binary plist format. Please use the APIs in NSPropertyList.h instead.
 */
- (id)propertyList;
- (nullable NSDictionary *)propertyListFromStringsFileFormat;

@end
    
@interface NSString (NSStringDeprecated)

/* The following methods are deprecated and will be removed from this header file in the near future. These methods use NSString.defaultCStringEncoding as the encoding to convert to, which means the results depend on the user's language and potentially other settings. This might be appropriate in some cases, but often these methods are misused, resulting in issues when running in languages other then English. UTF8String in general is a much better choice when converting arbitrary NSStrings into 8-bit representations. Additional potential replacement methods are being introduced in NSString as appropriate.
 */
- (nullable const char *)cString NS_RETURNS_INNER_POINTER NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
- (nullable const char *)lossyCString NS_RETURNS_INNER_POINTER NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
- (NSUInteger)cStringLength NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
- (void)getCString:(char *)bytes NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
- (void)getCString:(char *)bytes maxLength:(NSUInteger)maxLength NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
- (void)getCString:(char *)bytes maxLength:(NSUInteger)maxLength range:(NSRange)aRange remainingRange:(nullable NSRangePointer)leftoverRange NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);

- (BOOL)writeToFile:(NSString *)path atomically:(BOOL)useAuxiliaryFile NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
- (BOOL)writeToURL:(NSURL *)url atomically:(BOOL)atomically NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);

- (nullable id)initWithContentsOfFile:(NSString *)path NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
- (nullable id)initWithContentsOfURL:(NSURL *)url NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
+ (nullable id)stringWithContentsOfFile:(NSString *)path NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
+ (nullable id)stringWithContentsOfURL:(NSURL *)url NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);

- (nullable id)initWithCStringNoCopy:(char *)bytes length:(NSUInteger)length freeWhenDone:(BOOL)freeBuffer NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
- (nullable id)initWithCString:(const char *)bytes length:(NSUInteger)length NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
- (nullable id)initWithCString:(const char *)bytes NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
+ (nullable id)stringWithCString:(const char *)bytes length:(NSUInteger)length NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);
+ (nullable id)stringWithCString:(const char *)bytes NS_DEPRECATED(10_0, 10_4, 2_0, 2_0);

/* This method is unsafe because it could potentially cause buffer overruns. You should use -getCharacters:range: instead.
 */
- (void)getCharacters:(unichar *)buffer;

@end
    
    NS_ENUM(NSStringEncoding) {
        NSProprietaryStringEncoding = 65536    /* Installation-specific encoding */
        };
        
        /* The rest of this file is bookkeeping stuff that has to be here. Don't use this stuff, don't refer to it.
         */
#if !defined(_OBJC_UNICHAR_H_)
#define _OBJC_UNICHAR_H_
#endif
#define NS_UNICHAR_IS_EIGHT_BIT 0
        
        @interface NSSimpleCString : NSString {
            @package
            char *bytes;
            int numBytes;
#if __LP64__
            int _unused;
#endif
        }
@end
        
        @interface NSConstantString : NSSimpleCString
@end
        
#if __LP64__
#else
        extern void *_NSConstantStringClassReference;
#endif
        
CoderLN_NOTE NS_ASSUME_NONNULL_END
