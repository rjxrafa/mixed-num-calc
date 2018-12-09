
- Take in mixed number in mixed form e.g. 3 1/2, 4 5/8
- doesn't convert decimals to mixedNumber
- account for missing parenthtesis
- account 3 + 3
- if we add more than 1

parser works with mixed in the form of fractions and integers.
needs to work with decimals (0.5, .5) and mixed numbers (3 1/2).

- Parenthesis problem:
    - We need to consider issues like parenthesis mismatch (each paren has to come with pairs)
    - We need to make sure there is a valid input within the parenthesis (correct expression in paren)
    - invalid inputs such as ') ('
    - 2 + 2 (
    - 2 + 2 )

sources:

https://regexr.com/
https://en.wikipedia.org/wiki/Reverse_Polish_notation
https://en.wikipedia.org/wiki/Shunting-yard_algorithm
https://rosettacode.org/wiki/Parsing/Shunting-yard_algorithm#C
http://mathworld.wolfram.com/ReversePolishNotation.html
https://www.techopedia.com/definition/9194/reverse-polish-notation-rpn
https://www.regular-expressions.info/stdregex.html
https://www.lynda.com/C-tutorials/Reporting-errors-exceptions/182674/366572-4.html


----- Need to implement ------

 /* if the stack runs out without finding a left bracket, then there are mismatched parentheses. */
 /* if the operator token on the top of the stack is a bracket, then there are mismatched parentheses. */
 refer to https://en.wikipedia.org/wiki/Shunting-yard_algorithm
