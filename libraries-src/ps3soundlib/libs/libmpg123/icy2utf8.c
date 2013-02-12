/* mpg123 note: This is BSD-licensed code that is no problem for mpg123 usage under LGPL.
   It's Free, understood? ;-) */

/* Another note: This code is basically written by Thorsten Glaser,
   Thomas Orgis did just some rearrangements and comments. */

/*-
 * Copyright (c) 2008
 *      Thorsten Glaser <tg@mirbsd.org>
 *
 * Provided that these terms and disclaimer and all copyright notices
 * are retained or reproduced in an accompanying document, permission
 * is granted to deal in this work without restriction, including un-
 * limited rights to use, publicly perform, distribute, sell, modify,
 * merge, give away, or sublicence.
 *
 * This work is provided "AS IS" and WITHOUT WARRANTY of any kind, to
 * the utmost extent permitted by applicable law, neither express nor
 * implied; without malicious intent or gross negligence. In no event
 * may a licensor, author or contributor be held liable for indirect,
 * direct, other damage, loss, or other issues arising in any way out
 * of dealing in the work, even if advised of the possibility of such
 * damage or existence of a defect, except proven that it results out
 * of said person's immediate fault when using the work as intended.
 *-
 * Convert from ICY encoding (windows-1252 codepage) to UTF-8
 */

/* Includes string and stdlib headers... */
#include "compat.h"
#include <string.h>

/* ThOr: too lazy for this type check; also we use char/short all around anyway.
   Of cource, it would be the proper way to use _these_ kind of types all around. */
#define uint8_t  unsigned char
#define uint16_t unsigned short

static const uint8_t cp1252_utf8[] = {
        /* 0x00 @   0 */        0x00,
        /* 0x01 @   1 */        0x01,
        /* 0x02 @   2 */        0x02,
        /* 0x03 @   3 */        0x03,
        /* 0x04 @   4 */        0x04,
        /* 0x05 @   5 */        0x05,
        /* 0x06 @   6 */        0x06,
        /* 0x07 @   7 */        0x07,
        /* 0x08 @   8 */        0x08,
        /* 0x09 @   9 */        0x09,
        /* 0x0A @  10 */        0x0A,
        /* 0x0B @  11 */        0x0B,
        /* 0x0C @  12 */        0x0C,
        /* 0x0D @  13 */        0x0D,
        /* 0x0E @  14 */        0x0E,
        /* 0x0F @  15 */        0x0F,
        /* 0x10 @  16 */        0x10,
        /* 0x11 @  17 */        0x11,
        /* 0x12 @  18 */        0x12,
        /* 0x13 @  19 */        0x13,
        /* 0x14 @  20 */        0x14,
        /* 0x15 @  21 */        0x15,
        /* 0x16 @  22 */        0x16,
        /* 0x17 @  23 */        0x17,
        /* 0x18 @  24 */        0x18,
        /* 0x19 @  25 */        0x19,
        /* 0x1A @  26 */        0x1A,
        /* 0x1B @  27 */        0x1B,
        /* 0x1C @  28 */        0x1C,
        /* 0x1D @  29 */        0x1D,
        /* 0x1E @  30 */        0x1E,
        /* 0x1F @  31 */        0x1F,
        /* 0x20 @  32 */        0x20,
        /* 0x21 @  33 */        0x21,
        /* 0x22 @  34 */        0x22,
        /* 0x23 @  35 */        0x23,
        /* 0x24 @  36 */        0x24,
        /* 0x25 @  37 */        0x25,
        /* 0x26 @  38 */        0x26,
        /* 0x27 @  39 */        0x27,
        /* 0x28 @  40 */        0x28,
        /* 0x29 @  41 */        0x29,
        /* 0x2A @  42 */        0x2A,
        /* 0x2B @  43 */        0x2B,
        /* 0x2C @  44 */        0x2C,
        /* 0x2D @  45 */        0x2D,
        /* 0x2E @  46 */        0x2E,
        /* 0x2F @  47 */        0x2F,
        /* 0x30 @  48 */        0x30,
        /* 0x31 @  49 */        0x31,
        /* 0x32 @  50 */        0x32,
        /* 0x33 @  51 */        0x33,
        /* 0x34 @  52 */        0x34,
        /* 0x35 @  53 */        0x35,
        /* 0x36 @  54 */        0x36,
        /* 0x37 @  55 */        0x37,
        /* 0x38 @  56 */        0x38,
        /* 0x39 @  57 */        0x39,
        /* 0x3A @  58 */        0x3A,
        /* 0x3B @  59 */        0x3B,
        /* 0x3C @  60 */        0x3C,
        /* 0x3D @  61 */        0x3D,
        /* 0x3E @  62 */        0x3E,
        /* 0x3F @  63 */        0x3F,
        /* 0x40 @  64 */        0x40,
        /* 0x41 @  65 */        0x41,
        /* 0x42 @  66 */        0x42,
        /* 0x43 @  67 */        0x43,
        /* 0x44 @  68 */        0x44,
        /* 0x45 @  69 */        0x45,
        /* 0x46 @  70 */        0x46,
        /* 0x47 @  71 */        0x47,
        /* 0x48 @  72 */        0x48,
        /* 0x49 @  73 */        0x49,
        /* 0x4A @  74 */        0x4A,
        /* 0x4B @  75 */        0x4B,
        /* 0x4C @  76 */        0x4C,
        /* 0x4D @  77 */        0x4D,
        /* 0x4E @  78 */        0x4E,
        /* 0x4F @  79 */        0x4F,
        /* 0x50 @  80 */        0x50,
        /* 0x51 @  81 */        0x51,
        /* 0x52 @  82 */        0x52,
        /* 0x53 @  83 */        0x53,
        /* 0x54 @  84 */        0x54,
        /* 0x55 @  85 */        0x55,
        /* 0x56 @  86 */        0x56,
        /* 0x57 @  87 */        0x57,
        /* 0x58 @  88 */        0x58,
        /* 0x59 @  89 */        0x59,
        /* 0x5A @  90 */        0x5A,
        /* 0x5B @  91 */        0x5B,
        /* 0x5C @  92 */        0x5C,
        /* 0x5D @  93 */        0x5D,
        /* 0x5E @  94 */        0x5E,
        /* 0x5F @  95 */        0x5F,
        /* 0x60 @  96 */        0x60,
        /* 0x61 @  97 */        0x61,
        /* 0x62 @  98 */        0x62,
        /* 0x63 @  99 */        0x63,
        /* 0x64 @ 100 */        0x64,
        /* 0x65 @ 101 */        0x65,
        /* 0x66 @ 102 */        0x66,
        /* 0x67 @ 103 */        0x67,
        /* 0x68 @ 104 */        0x68,
        /* 0x69 @ 105 */        0x69,
        /* 0x6A @ 106 */        0x6A,
        /* 0x6B @ 107 */        0x6B,
        /* 0x6C @ 108 */        0x6C,
        /* 0x6D @ 109 */        0x6D,
        /* 0x6E @ 110 */        0x6E,
        /* 0x6F @ 111 */        0x6F,
        /* 0x70 @ 112 */        0x70,
        /* 0x71 @ 113 */        0x71,
        /* 0x72 @ 114 */        0x72,
        /* 0x73 @ 115 */        0x73,
        /* 0x74 @ 116 */        0x74,
        /* 0x75 @ 117 */        0x75,
        /* 0x76 @ 118 */        0x76,
        /* 0x77 @ 119 */        0x77,
        /* 0x78 @ 120 */        0x78,
        /* 0x79 @ 121 */        0x79,
        /* 0x7A @ 122 */        0x7A,
        /* 0x7B @ 123 */        0x7B,
        /* 0x7C @ 124 */        0x7C,
        /* 0x7D @ 125 */        0x7D,
        /* 0x7E @ 126 */        0x7E,
        /* 0x7F @ 127 */        0x7F,
        /* 0x80 @ 128 */        0xE2, 0x82, 0xAC,
        /* 0x81 @ 131 */        0xEF, 0xBF, 0xBD,
        /* 0x82 @ 134 */        0xE2, 0x80, 0x9A,
        /* 0x83 @ 137 */        0xC6, 0x92,
        /* 0x84 @ 139 */        0xE2, 0x80, 0x9E,
        /* 0x85 @ 142 */        0xE2, 0x80, 0xA6,
        /* 0x86 @ 145 */        0xE2, 0x80, 0xA0,
        /* 0x87 @ 148 */        0xE2, 0x80, 0xA1,
        /* 0x88 @ 151 */        0xCB, 0x86,
        /* 0x89 @ 153 */        0xE2, 0x80, 0xB0,
        /* 0x8A @ 156 */        0xC5, 0xA0,
        /* 0x8B @ 158 */        0xE2, 0x80, 0xB9,
        /* 0x8C @ 161 */        0xC5, 0x92,
        /* 0x8D @ 163 */        0xEF, 0xBF, 0xBD,
        /* 0x8E @ 166 */        0xC5, 0xBD,
        /* 0x8F @ 168 */        0xEF, 0xBF, 0xBD,
        /* 0x90 @ 171 */        0xEF, 0xBF, 0xBD,
        /* 0x91 @ 174 */        0xE2, 0x80, 0x98,
        /* 0x92 @ 177 */        0xE2, 0x80, 0x99,
        /* 0x93 @ 180 */        0xE2, 0x80, 0x9C,
        /* 0x94 @ 183 */        0xE2, 0x80, 0x9D,
        /* 0x95 @ 186 */        0xE2, 0x80, 0xA2,
        /* 0x96 @ 189 */        0xE2, 0x80, 0x93,
        /* 0x97 @ 192 */        0xE2, 0x80, 0x94,
        /* 0x98 @ 195 */        0xCB, 0x9C,
        /* 0x99 @ 197 */        0xE2, 0x84, 0xA2,
        /* 0x9A @ 200 */        0xC5, 0xA1,
        /* 0x9B @ 202 */        0xE2, 0x80, 0xBA,
        /* 0x9C @ 205 */        0xC5, 0x93,
        /* 0x9D @ 207 */        0xEF, 0xBF, 0xBD,
        /* 0x9E @ 210 */        0xC5, 0xBE,
        /* 0x9F @ 212 */        0xC5, 0xB8,
        /* 0xA0 @ 214 */        0xC2, 0xA0,
        /* 0xA1 @ 216 */        0xC2, 0xA1,
        /* 0xA2 @ 218 */        0xC2, 0xA2,
        /* 0xA3 @ 220 */        0xC2, 0xA3,
        /* 0xA4 @ 222 */        0xC2, 0xA4,
        /* 0xA5 @ 224 */        0xC2, 0xA5,
        /* 0xA6 @ 226 */        0xC2, 0xA6,
        /* 0xA7 @ 228 */        0xC2, 0xA7,
        /* 0xA8 @ 230 */        0xC2, 0xA8,
        /* 0xA9 @ 232 */        0xC2, 0xA9,
        /* 0xAA @ 234 */        0xC2, 0xAA,
        /* 0xAB @ 236 */        0xC2, 0xAB,
        /* 0xAC @ 238 */        0xC2, 0xAC,
        /* 0xAD @ 240 */        0xC2, 0xAD,
        /* 0xAE @ 242 */        0xC2, 0xAE,
        /* 0xAF @ 244 */        0xC2, 0xAF,
        /* 0xB0 @ 246 */        0xC2, 0xB0,
        /* 0xB1 @ 248 */        0xC2, 0xB1,
        /* 0xB2 @ 250 */        0xC2, 0xB2,
        /* 0xB3 @ 252 */        0xC2, 0xB3,
        /* 0xB4 @ 254 */        0xC2, 0xB4,
        /* 0xB5 @ 256 */        0xC2, 0xB5,
        /* 0xB6 @ 258 */        0xC2, 0xB6,
        /* 0xB7 @ 260 */        0xC2, 0xB7,
        /* 0xB8 @ 262 */        0xC2, 0xB8,
        /* 0xB9 @ 264 */        0xC2, 0xB9,
        /* 0xBA @ 266 */        0xC2, 0xBA,
        /* 0xBB @ 268 */        0xC2, 0xBB,
        /* 0xBC @ 270 */        0xC2, 0xBC,
        /* 0xBD @ 272 */        0xC2, 0xBD,
        /* 0xBE @ 274 */        0xC2, 0xBE,
        /* 0xBF @ 276 */        0xC2, 0xBF,
        /* 0xC0 @ 278 */        0xC3, 0x80,
        /* 0xC1 @ 280 */        0xC3, 0x81,
        /* 0xC2 @ 282 */        0xC3, 0x82,
        /* 0xC3 @ 284 */        0xC3, 0x83,
        /* 0xC4 @ 286 */        0xC3, 0x84,
        /* 0xC5 @ 288 */        0xC3, 0x85,
        /* 0xC6 @ 290 */        0xC3, 0x86,
        /* 0xC7 @ 292 */        0xC3, 0x87,
        /* 0xC8 @ 294 */        0xC3, 0x88,
        /* 0xC9 @ 296 */        0xC3, 0x89,
        /* 0xCA @ 298 */        0xC3, 0x8A,
        /* 0xCB @ 300 */        0xC3, 0x8B,
        /* 0xCC @ 302 */        0xC3, 0x8C,
        /* 0xCD @ 304 */        0xC3, 0x8D,
        /* 0xCE @ 306 */        0xC3, 0x8E,
        /* 0xCF @ 308 */        0xC3, 0x8F,
        /* 0xD0 @ 310 */        0xC3, 0x90,
        /* 0xD1 @ 312 */        0xC3, 0x91,
        /* 0xD2 @ 314 */        0xC3, 0x92,
        /* 0xD3 @ 316 */        0xC3, 0x93,
        /* 0xD4 @ 318 */        0xC3, 0x94,
        /* 0xD5 @ 320 */        0xC3, 0x95,
        /* 0xD6 @ 322 */        0xC3, 0x96,
        /* 0xD7 @ 324 */        0xC3, 0x97,
        /* 0xD8 @ 326 */        0xC3, 0x98,
        /* 0xD9 @ 328 */        0xC3, 0x99,
        /* 0xDA @ 330 */        0xC3, 0x9A,
        /* 0xDB @ 332 */        0xC3, 0x9B,
        /* 0xDC @ 334 */        0xC3, 0x9C,
        /* 0xDD @ 336 */        0xC3, 0x9D,
        /* 0xDE @ 338 */        0xC3, 0x9E,
        /* 0xDF @ 340 */        0xC3, 0x9F,
        /* 0xE0 @ 342 */        0xC3, 0xA0,
        /* 0xE1 @ 344 */        0xC3, 0xA1,
        /* 0xE2 @ 346 */        0xC3, 0xA2,
        /* 0xE3 @ 348 */        0xC3, 0xA3,
        /* 0xE4 @ 350 */        0xC3, 0xA4,
        /* 0xE5 @ 352 */        0xC3, 0xA5,
        /* 0xE6 @ 354 */        0xC3, 0xA6,
        /* 0xE7 @ 356 */        0xC3, 0xA7,
        /* 0xE8 @ 358 */        0xC3, 0xA8,
        /* 0xE9 @ 360 */        0xC3, 0xA9,
        /* 0xEA @ 362 */        0xC3, 0xAA,
        /* 0xEB @ 364 */        0xC3, 0xAB,
        /* 0xEC @ 366 */        0xC3, 0xAC,
        /* 0xED @ 368 */        0xC3, 0xAD,
        /* 0xEE @ 370 */        0xC3, 0xAE,
        /* 0xEF @ 372 */        0xC3, 0xAF,
        /* 0xF0 @ 374 */        0xC3, 0xB0,
        /* 0xF1 @ 376 */        0xC3, 0xB1,
        /* 0xF2 @ 378 */        0xC3, 0xB2,
        /* 0xF3 @ 380 */        0xC3, 0xB3,
        /* 0xF4 @ 382 */        0xC3, 0xB4,
        /* 0xF5 @ 384 */        0xC3, 0xB5,
        /* 0xF6 @ 386 */        0xC3, 0xB6,
        /* 0xF7 @ 388 */        0xC3, 0xB7,
        /* 0xF8 @ 390 */        0xC3, 0xB8,
        /* 0xF9 @ 392 */        0xC3, 0xB9,
        /* 0xFA @ 394 */        0xC3, 0xBA,
        /* 0xFB @ 396 */        0xC3, 0xBB,
        /* 0xFC @ 398 */        0xC3, 0xBC,
        /* 0xFD @ 400 */        0xC3, 0xBD,
        /* 0xFE @ 402 */        0xC3, 0xBE,
        /* 0xFF @ 404 */        0xC3, 0xBF,
};

static const uint16_t tblofs[257] = {
        /* 0x00 */   0,   1,   2,   3,   4,   5,   6,   7,
        /* 0x08 */   8,   9,  10,  11,  12,  13,  14,  15,
        /* 0x10 */  16,  17,  18,  19,  20,  21,  22,  23,
        /* 0x18 */  24,  25,  26,  27,  28,  29,  30,  31,
        /* 0x20 */  32,  33,  34,  35,  36,  37,  38,  39,
        /* 0x28 */  40,  41,  42,  43,  44,  45,  46,  47,
        /* 0x30 */  48,  49,  50,  51,  52,  53,  54,  55,
        /* 0x38 */  56,  57,  58,  59,  60,  61,  62,  63,
        /* 0x40 */  64,  65,  66,  67,  68,  69,  70,  71,
        /* 0x48 */  72,  73,  74,  75,  76,  77,  78,  79,
        /* 0x50 */  80,  81,  82,  83,  84,  85,  86,  87,
        /* 0x58 */  88,  89,  90,  91,  92,  93,  94,  95,
        /* 0x60 */  96,  97,  98,  99, 100, 101, 102, 103,
        /* 0x68 */ 104, 105, 106, 107, 108, 109, 110, 111,
        /* 0x70 */ 112, 113, 114, 115, 116, 117, 118, 119,
        /* 0x78 */ 120, 121, 122, 123, 124, 125, 126, 127,
        /* 0x80 */ 128, 131, 134, 137, 139, 142, 145, 148,
        /* 0x88 */ 151, 153, 156, 158, 161, 163, 166, 168,
        /* 0x90 */ 171, 174, 177, 180, 183, 186, 189, 192,
        /* 0x98 */ 195, 197, 200, 202, 205, 207, 210, 212,
        /* 0xA0 */ 214, 216, 218, 220, 222, 224, 226, 228,
        /* 0xA8 */ 230, 232, 234, 236, 238, 240, 242, 244,
        /* 0xB0 */ 246, 248, 250, 252, 254, 256, 258, 260,
        /* 0xB8 */ 262, 264, 266, 268, 270, 272, 274, 276,
        /* 0xC0 */ 278, 280, 282, 284, 286, 288, 290, 292,
        /* 0xC8 */ 294, 296, 298, 300, 302, 304, 306, 308,
        /* 0xD0 */ 310, 312, 314, 316, 318, 320, 322, 324,
        /* 0xD8 */ 326, 328, 330, 332, 334, 336, 338, 340,
        /* 0xE0 */ 342, 344, 346, 348, 350, 352, 354, 356,
        /* 0xE8 */ 358, 360, 362, 364, 366, 368, 370, 372,
        /* 0xF0 */ 374, 376, 378, 380, 382, 384, 386, 388,
        /* 0xF8 */ 390, 392, 394, 396, 398, 400, 402, 404,
        /* sizeof (cp1252_utf8) */ 406
};

/* Check if a string qualifies as UTF-8. */
static int
is_utf8(const char* src)
{
        uint8_t ch;
        size_t i;
        const uint8_t* s = (const uint8_t*) src;

        /* We make a loop over every character, until we find a null one.
           Remember: The string is supposed to end with a NUL, so ahead checks are safe. */
        while ((ch = *s++))     {
                /* Ye olde 7bit ASCII chars 'rr fine for anything */
                if(ch < 0x80) continue;

                /* Now, we watch out for non-UTF conform sequences. */
                else if ((ch < 0xC2) || (ch > 0xFD))
                        return 0;
                /* check for some misformed sequences */
                if (((ch == 0xC2) && (s[0] < 0xA0)) ||
                    ((ch == 0xEF) && (s[0] == 0xBF) && (s[1] > 0xBD)))
                        /* XXX add more for outside the BMP */
                        return 0;

                /* Check the continuation bytes. */
                if      (ch < 0xE0) i = 1;
                else if (ch < 0xF0) i = 2;
                else if (ch < 0xF8)     i = 3;
                else if (ch < 0xFC)     i = 4;
                else
                        i = 5;

                while (i--)
                        if ((*s++ & 0xC0) != 0x80)
                                return 0;
        }

        /* If no check failed, the string indeed looks like valid UTF-8. */
        return 1;
}

/* The main conversion routine.
   ICY in CP-1252 (or UTF-8 alreay) to UTF-8 encoded string.
   If force is applied, it will always encode to UTF-8, without checking. */
char *
icy2utf8(const char *src, int force)
{
        const uint8_t *s = (const uint8_t *)src;
        size_t srclen, dstlen, i, k;
        uint8_t ch, *d;
        char *dst;

        /* Some funny streams from Apple/iTunes give ICY info in UTF-8 already.
           So, be prepared and don't try to re-encode such. Unless forced. */
        if(!force && is_utf8(src)) return (strdup(src));

        srclen = strlen(src) + 1;
        /* allocate conservatively */
        if ((d = malloc(srclen * 3)) == NULL)
                return (NULL);

        i = 0;
        dstlen = 0;
        while (i < srclen) {
                ch = s[i++];
                k = tblofs[ch];
                while (k < tblofs[ch + 1])
                        d[dstlen++] = cp1252_utf8[k++];
        }

        /* dstlen includes trailing NUL since srclen also does */
        if ((dst = safe_realloc(d, dstlen)) == NULL) {
                free(d);
                return (NULL);
        }
        return (dst);
}

/* This stuff is for testing only. */
#ifdef TEST_ICULO
static const char intext[] = "\225 Gr\374\337e kosten 0,55 \200\205";

#include <stdio.h>

int
main(void)
{
        char *t, *t2;

        if ((t = icy2utf8(intext, 0)) == NULL) {
                fprintf(stderr, "out of memory\n");
                return (1);
        }

        /* make sure it won't be converted twice */
        if ((t2 = icy2utf8(t), 0) == NULL) {
                fprintf(stderr, "out of memory\n");
                return (1);
        }

        printf("Result is:\t\343\200\214%s\343\200\215\n"
                "\t\t\343\200\214%s\343\200\215\n", t, t2);

        free(t);
        free(t2);
        return (0);
}
#endif
