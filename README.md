# CS 210 Project Journal and Repository

David Scott SNHU CS210 12/17/23

A demonstration portfilio repo for CS210 C++ Project Code

## Summarize the project and what problem it was solving.

This project counts item sales from business records, and provides a console interface for viewing
the per-item counts, and listing the frequencies and histograms of all sales. It reads input from
line-based text files.

## What did you do particularly well?

I used standard library datastructures to keep the code easy to read for a
typical C++ programmer, and I handled most common input validation tasks. I
maintained a consistent style across the project. I used const pass-by-reference
to reduce string copying for efficiency.

## Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?

More user input validation could enhance the user experience, giving more useful
feedback on what is invalid in the inputs instead of just retrying. Adding suite
of unit and acceptance tests would be make the code simpler to modify in future,
increasing confidence that the expected behaviors around input and output
handling are maintained.

## Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?

Some differences in text-file line ending handling between my local mac system,
and the virtual environment's Windows system caused it to act differently in
handling edge cases in the user input streams. I dealt with this by narrowing
down the cases where it was failing and rewriting the code in a more platform
neutral way. Test cases would have helped with this. I also had some unexpected
syntax errors while working which turned out to be because there are several C++
features which have been standardized after I last used C++ many years ago, and
this has led me to read up on the newer standards and learn the very useful
additions to the language from C++11, C++14, C++17 and onwards.

## What skills from this project will be particularly transferable to other projects or course work?

The focus on object oriented modeling of problems prior to implementation will
be useful to me. I do not tend to take this approach in my own code often, but I
have tried to take the best elements of it into my professional work.

## How did you make this program maintainable, readable, and adaptable?

In this program I use standard libraries wherever possible, to reduce the
application specific code to maintain. I separated definitions from
implementations to make the codebase simpler to navigate, and decomposed the
problem into two classes, one of which is concerned only with counting a set of
string categories, and the other is concerned with the application user
interface. This makes the code more modular and the counting code could easily
be adapted to other tasks in the same project or others.
