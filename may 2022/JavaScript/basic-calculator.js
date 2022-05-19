// Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

// Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

// Example 1:
// Input: s = "1 + 1"
// Output: 2

// Example 2:
// Input: s = " 2-1 + 2 "
// Output: 3

// Example 3:
// Input: s = "(1+(4+5+2)-3)+(6+8)"
// Output: 23
 
// Constraints:
// 1 <= s.length <= 3 * 10^5
// s consists of digits, '+', '-', '(', ')', and ' '.
// s represents a valid expression.
// '+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
// '-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
// There will be no two consecutive operators in the input.
// Every number and running calculation will fit in a signed 32-bit integer.

/**
 * @param {string} s
 * @return {number}
 */

 var calculate = function(s) {
    s = s.replace(/\s/g, '');
    let result = 0;
    let stack = [];
    let num = 0;
    let sign = 1;
    let i = 0;

    while (i < s.length) {
        switch (s[i]) {
            case '(': 
                stack.push(result);
                stack.push(sign);
                sign = 1;
                result = 0;
                break;
            case ')':
                result *= stack.pop();
                result += stack.pop();
                break;
            case '+':
                sign = 1;
                break;
            case '-':
                sign = -1;
                break;
            default:
                num = 0;
                while (i < s.length && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                i--;
                break;
        }
        i++;
    }
    return result;
}