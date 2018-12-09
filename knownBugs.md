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

----- Need to implement ------

 /* if the stack runs out without finding a left bracket, then there are mismatched parentheses. */
 /* if the operator token on the top of the stack is a bracket, then there are mismatched parentheses. */
 refer to https://en.wikipedia.org/wiki/Shunting-yard_algorithm
