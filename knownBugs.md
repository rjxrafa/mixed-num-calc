- if (isdigit(temp[0])) // *BUG*: Will be unable to take in decimals that start with . (e.g. .5)

Functionality

- Take in mixed number in mixed form e.g. 3 1/2, 4 5/8
- doesn't convert decimals to mixedNumber
- account for missing parenthtesis
- account 3 + 3
- if we add more than 1

parser works with mixed in the form of fractions and integers.
needs to work with decimals (0.5, .5) and mixed numbers (3 1/2).


sources:

https://rosettacode.org/wiki/Parsing/Shunting-yard_algorithm#C
https://regexr.com/
https://en.wikipedia.org/wiki/Reverse_Polish_notation


for (int i = 0; i > -255; i--)
    cout << i << ":" << char(i) << '_'
        << endl;
