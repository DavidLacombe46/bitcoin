namespace PerfectHash {
    /* C code produced by gperf version 3.0.4 */
    /* Command-line: gperf -lCcE  */
    /* Computed positions: -k'2,$' */
        enum
        {
            TOTAL_KEYWORDS = 26,
            MIN_WORD_LENGTH = 2,
            MAX_WORD_LENGTH = 11,
            MIN_HASH_VALUE = 2,
            MAX_HASH_VALUE = 39
        };

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
        && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
        && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
        && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
        && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
        && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
        && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
        && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
        && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
        && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
        && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
        && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
        && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
        && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
        && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
        && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
        && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
        && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
        && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
        && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
        && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
    && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
    && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
    /* The character set is not based on ISO-646.  */
    error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

        /* maximum key range = 38, duplicates = 0 */

        static unsigned int
        hash (const char *str, unsigned int len)
    {
        static const unsigned char asso_values[] =
        {
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 20, 40, 40,
            10,  0, 40,  0, 40, 10, 40, 15, 15,  0,
            5,  0, 40, 40, 10,  0, 30, 40,  0, 40,
            0, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40, 40, 40, 40, 40,
            40, 40, 40, 40, 40, 40
        };
        return len + asso_values[(unsigned char)str[1]] + asso_values[(unsigned char)str[len - 1]];
    }

        unsigned int in_word_set (const char* str,unsigned int len)
    {

        static const unsigned char lengthtable[] =
        {
            0,  0,  2,  0,  4,  0,  0,  7,  3,  9, 10, 11,  7,  0,
            4,  0, 11,  7,  8,  9,  0,  6,  7,  0,  4, 10, 11,  7,
            8,  9, 10, 11,  0,  0,  0,  5,  6,  0,  0,  9
        };
        static const char * const wordlist[] =
        {
            "", "",
            "tx",
            "",
            "pong",
            "", "",
            "headers",
            "inv",
            "getblocks",
            "getheaders",
            "sendheaders",
            "version",
            "",
            "ping",
            "",
            "getblocktxn",
            "getaddr",
            "notfound",
            "feefilter",
            "",
            "verack",
            "mempool",
            "",
            "addr",
            "cmpctblock",
            "merkleblock",
            "getdata",
            "blocktxn",
            "filteradd",
            "filterload",
            "filterclear",
            "", "", "",
            "block",
            "reject",
            "", "",
            "sendcmpct"
        };

        if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
        {
            register unsigned int key = hash (str, len);

            if (key <= MAX_HASH_VALUE && key >= 0)
                if (len == lengthtable[key])
                {
                    register const char *s = wordlist[key];

                    if (*str == *s && !memcmp (str + 1, s + 1, len - 1))
                        return key;
                }
        }
        return MAX_HASH_VALUE+1;
    }
}
