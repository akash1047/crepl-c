#ifndef CREPL_STR_H
#define CREPL_STR_H

/**
 * Author: Akash Lohar
 *
 * str is a utility library for working with strings in C.
 * The str_t struct represents a string. It contains a pointer to the string.
 * Errors are reported through the global variable STR_ERRNO.
 */

extern int STR_ERRONO;

#define STR_OK 0
#define STR_ERR_ALLOC -1
#define STR_ERR_NULL -2
#define STR_ERR_NEG_CAP -3

#define STR_DEFAULT_CAP 8

typedef struct {
    char *ptr; // pointer to the string

    // length of the string is the number of characters in the string
    int len;

    // capacity is always 1 byte more than the length,
    // which holds the null terminator
    int cap;
} str_t;

// Return's 1 if string length is 0 otherwise 1
// @note If string is NULL return's 0
int str_is_empty(const str_t *string);

// Create an empty string with some capacity.
//
// @param capacity The ammount of bytes string can hold.
//
// @exception Return's NULL if memory allocation fails
str_t *str_with_capacity(size_t capacity);

// Create an empty string with default capacity.
inline str_t *str_new() { return str_with_capacity(STR_DEFAULT_CAP); }

// Create new string from c style string(null-byte-terminated-string)
str_t *str_from_cstr(const char *cstring);

// Create new string from c style string by taking exactly n bytes from the
// start.
// @note If cstring length is less then n bytes, the function creates string to
// fit the amount of bytes available to copy, i.e- string of same length as
// cstring.
str_t *str_from_cstr_n(const char *cstring, size_t n);

// Pushes a character at the end of the string.
// @note reallocates if the capacity excededs.
void str_push_char_end(str_t *string, char ch);

// Put's a character at an index.
// @note reallocates if the capacity excededs.
void str_push_char_at(str_t *string, size_t at, char ch);

// Append string to the end of a string
// @note reallocates if the capacity excededs
void str_push_str_end(str_t *string, const str_t *string_to_append);

// Fit in a string at a certain index.
// @note reallocates if the capacity excededs.
void str_push_str_at(str_t *string, size_t at, const str_t *string_to_append);

// Append c style string to the end of a string
// @note reallocates if the capacity excededs
void str_push_cstr_end(str_t *string, const char *cstring_to_append);

// Fit in a c style string at a certain index.
// @note reallocates if the capacity excededs.
void str_push_cstr_at(str_t *string, size_t at, const str_t *cstring_to_append);

// It is what you think it is.
int str_scanf(const str_t *s, const char *fmt, ...);

// It is what you think it is.
int str_printf(str_t *s, const char *fmt, ...);

// Create's new string by joining two string together.
str_t *str_concat(const str_t *first_string, const str_t *second_string);

/**
 * The popping functions
 *
 * // Pop the character from the end of the string ( modifies the string )
 * int str_pop_char_end(str_t *);
 *
 * // Pop the character from the start of the string ( modifies the string )
 * int str_pop_char_at(str_t *, int);
 *
 */

/**
 * The trimming functions
 *
 * // Eleminate the whitespace characters from the start of the string (
 * modifies the string ) void str_self_trim_start(str_t *);
 *
 * // Eleminate the whitespace characters from the end of the string ( modifies
 * the string ) void str_self_trim_end(str_t *);
 *
 * // Eleminate the whitespace characters from the start and end of the string (
 * modifies the string ) void str_self_trim(str_t *);
 *
 * // Eleminate the whitespace characters from the start of the string ( creates
 * a new string ) str_t str_trim_start(const str_t *);
 *
 * // Eleminate the whitespace characters from the end of the string ( creates a
 * new string ) str_t str_trim_end(const str_t *);
 *
 * // Eleminate the whitespace characters from the start and end of the string (
 * creates a new string ) str_t str_trim(const str_t *);
 *
 */

/**
 * Free's the memory of the string.
 *
 * @param s The pointer to string to be free'd.
 *
 * @return 1 if the string was successfully free'd, otherwise 0.
 *
 * @exception STR_ERR_NULL if the string is NULL.
 */
int str_free(str_t *s);

/**
 * Compare two strings.
 *
 * @param a The first string.
 * @param b The second string.
 *
 * @return 0 if the strings are equal, negative integer if a is less than b,
 * positive if a is greater than b.
 *
 * @exception STR_ERR_NULL if any of the strings are NULL.
 */
int str_cmp(const str_t *a, const str_t *b);

/**
 * Compare two strings ignoring case.
 *
 * @param a The first string.
 * @param b The second string.
 *
 * @return 0 if the strings are equal, negative integer if a is less than b,
 * positive if a is greater than b.
 *
 * @exception STR_ERR_NULL if any of the strings are NULL.
 */
int str_cmp_ignore_case(const str_t *a, const str_t *b);

/**
 * Find the index of the first occurrence of a substring in a string.
 *
 * @param s The base string.
 * @param sub The substring.
 *
 * @return The index of the first occurrence of the substring in the base
 * string, or -1 if the substring is not found.
 *
 * @exception STR_ERR_NULL if any of the strings are NULL.
 */
int str_find_str(const str_t *s, const str_t *sub);

/**
 * Find the index of the first occurrence of a character in a string.
 *
 * @param s The base string.
 *
 * @return The index of the first occurrence of the character in the base
 * string, or -1 if the character is not found.
 *
 * @exception STR_ERR_NULL if the string is NULL.
 */
int str_find_char(const str_t *s, char c);

/**
 * Find the index of the first occurrence of a C string in a string.
 *
 * @param s The base string.
 * @param cstr The C string (null-byte-terminated).
 *
 * @return The index of the first occurrence of the C string in the base string,
 * or -1 if the C string is not found.
 *
 * @exception STR_ERR_NULL if any of the parameteres are NULL.
 */
int str_find_cstr(const str_t *s, const char *cstr);

#endif // CREPL_STR_H