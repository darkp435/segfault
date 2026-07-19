# Segfault Preventer
We've all made the classic mistake of dereferencing a null pointer, crashing the program. I've done it, my friends done it, heck, even my dog has done it before. Those who experienced this know that you have to go through character development to find that pesky line where you forgot to check if the pointer is null.

That's exactly the reason why I'm introducing... the **segfault preventor!**

# How does it work?
Let's say you made the rookie mistake of dereferencing a null pointer. The program detects that and writes a 1000 line file bruh.txt shaming you for dereferencing the null pointer before inevitably crashing.

Nobody wants that file on their disk. Nobody wants to get shamed, either, for getting a segmentation fault.

Therefore, with that in your mind, you should begin to write less segmentation faults psychologically. Because, after all, *fear* is the best motivation.

# How do I use it?
I'm glad you asked! This is a C header-only "library" (if you could call it that) which means at the moment using it in C and C++ are the main deals. You can find it under GitHub releases (or, if for some reason it's not there, as segfault_preventor.h in the root directory of this project). Simply `#include` it, and put
```c
prevent_segfaults()
```
at the first line of the `main` function.

Congratulations! You're now utilizing *fear* to help you become a 10x developer!

## FAQ
**Q:** Does this actually work?
**A:** This has not been tested in production for, uhm, *reasons*, but yes, it 100% works!

**Q**: why not just switch to rust bro its memory safe
**A**: *whispers into your ear* No.

**Q**: Will this work with other programming languages in the future?
**A**: Currently, I have much better things to do so not really, but if this repository somehow gets to 1000 stars (for some reason) I'll do it.

**Q**: ur code sucks dude
**A**: That's not a question, but at least it's infinitely times better than what you got there, *Brad*.

**Q**: How do I contribute to this project?
**A**: Issues, and pull requests, just like usual. I'll only check on them once in a blue moon though, and do what you feel is right.