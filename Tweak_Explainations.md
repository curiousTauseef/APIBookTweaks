# Tweak Explanations
## Table of Contents
* [Summary](#summary)
* [brace-init-list](#braceinitlist)
* [constexpr](#constexpr)
* [enum class](#enumclass)
* [smart pointers](#smartpointers)
* [make_shared/make_unique](#makeshared)
* [using](#using)
* [=delete](#equalsdelete)
* [std::endl](#endl)


## Summary
The following is a synopsis of the tweaks applied and the reasons they were used.

As mentioned in the top level Readme.md, my intent with the changes is to make better use of modern C++.

<a name="braceinitlist" > </a>
## brace-init-list 
*Technically, this form of direct-list-initialization.*

I prefer to use what is known as uniform initialization, that was introduced in C++11.

```
int i {5};
C c {2};
```

I find it simple and direct and can use it almost anywhere any of the older initializations were used.  Also it won't allow narrowing without a specific cast.  

```
int i (56.75);  // quietly tosses out 0.75
int i2 {56.75}; // error, implicit narrowing
```

However, the brace-init-list can't be used in certain cases.  For example, with classes that are aggregates:

```
std::array<int, 3> ary {1, 2, 3}; // error
```

But one can get around this by adding an extra level of braces:

```
std::array<int, 3> ary { {1, 2, 3} }; // ok
```

Also note the following:

```
std::vector <int> v1 (5, 5);  // these are
std::vector <int> v2 {5, 5};  // different
```

* Form1: creates a vector of five elements all set to five.
* Form2: creates a vector of two elements all set to five.

Another issue, I have run into is under GCC (at least the last time I tried it):

```
auto i {5};  // triggers a GCC compiler error
```

Prior to C++11, there were generally three forms of initializing variables:

```
int i = 5;  // copy initialization
C c(2); // direct initialization, paren-init-list
int ary[] = {1, 2, 3}; // copy list initialization
```

* Form 1, People tended to gloss over the first form and sometimes confusing it with assignment.  A common mistake would be to overload the assignment operator and wonder why it was never being called when the first form was used.  This older form isn't assignment but calls some form of constructor

* Form 2, sometimes known as a C++ style cast, has a number of potential issues.  Scott Meyer's coined the phrase, "C++'s most vexing parse".  Which is to say sometimes this can be confused for a function call.  Also there is the potential for narrowing.

* Form 3, used for initializing aggregates

As shown earlier, C++11 introduced the uniform initialization to replace forms 1 and 2.

## constexpr
As a rule, I try to avoid "magic values".  That is to say, having literal values without any context.  Instead, I will make such values a `constexpr`.

Giving the values a name makes one's intent clearer when the value is used.  Also, the value needs to be changed at some point, there is only one place this needs to happen.

So why `constexpr` and not just `const`?
The later form only tells the compiler that this variable doesn't change.  While the former qualifier tells the compiler that this expression results in a compile time constant value.  This gives the compiler the to option to evaluate and combine the result of constexpr variables for a given statement all at compile time.
 
 <a name="enumclass" > </a>
## enum class 
`enum class` vs `enum`
`enum` is the original form of enumeration.  However, there are cases where these can lead to surprises and subtle bugs due to these surprises.  One of the issues relating to `enum` is that they typically pollute the global namespace (or at least whatever namespace they are defined in).

`enum class` was introduced in C++11 and addresses many of the issues that plagued the use of original `enum`.  For example, an `enum class` is fully scopped.

I tend to gravitate towards the newer `enum class` form.  Even though there are some quirks with the newer form.  For example, one can't do straight comparison against an ordinal value and an `enum class` some casting is needed to make it happen.

```
enum class Colors {
    black = 0,
    red,
    white
};

Colors c{Colors::red};
if (c == 1) // error
```

One could have a helper function like:

```
template <typename E>
constexpr int enumClToInt (E e) {
    return static_cast<int> (e);
}
```

Then the ordinal test could be done as:

```
if (enumClToInt (c) == 1) ... // ok
```

<a name="smartpointers"></a>
## Smart Pointers 
There are plenty of other references on why one should be taking advantage of smart pointers.  So I won't go into detail here. Here are some bullet points:

* Avoid owning raw pointers (non-owning raw pointers can be fine).  Also the [GSL](https://github.com/Microsoft/GSL) provides some nice alternatives when one has to deal with owning and non-owning raw pointers).
* Avoid explicit new/delete

<a name="makeshared"> </a>
## make\_shared make\_unique 
The smart pointers, `std::shared_ptr` and `std::unique_ptr`, both have corresponding calls for making them, `std::make_shared()` and `std::make_unique()` respectfully. (Technically 'std::make_unique()' didn't come until C++14.  But one can copy over the implementation for it, if you still only have C++11.)

So why should one consider using these over just calling `new`?

```
std::shared_ptr <int> i1 {new int {1} };
std::shared_ptr <int> i2 {<std::make_shared <int> (2) };
```

Generally, one should prefer the `make_*` calls over using new.  This form can be more efficient than using `new`. Also, `make_unique` is exception safe.

However you will need to use `new`, if the class needs to have custom deleter or you are getting a raw pointer from somewhere else.

See [Sutter's Mill #89](https://herbsutter.com/2013/05/29/gotw-89-solution-smart-pointers/) for great explanations for avoiding `new` and preferring `make_unique` and `make_shared` instead.

Also the `make_*` can be tricky to work with if the class in question only has private constructors. For example, say the class is a factory.  A work around, would be to do what I did for the [Ch2: shared_pointer example](https://github.com/tlanc007/APIBookTweaks/tree/master/02_Qualities/shared_pointer).

## using
C++11 introduced a new use the `using` keyword.  It can be used as an alias and for me replaces the need to use `typedef`.  I find it easier to read and feels more direct.

```
typedef std::shared_ptr<class MyObject> MyObjectPtr;
using MyObjectPtr = std::shared_ptr<class MyObject>;
```  

The feels cleaner.  Sort of like an assignment.  Also `using` can be templated and `typedef` can't.

<a name="equalsdelete"> </a>
## =delete 
Under certain cases, the compiler will autogenerate certain special methods if they aren't explcitly provided in the class.

Prior to C++11, if one didn't want the compiler to these special methods, one would have to define them manually and make them private.   Now, one can declare these methods with the =delete.

NOTE:  = delete can be applied to any method and not just the special methods.


```
class A {
public:
    A (constA& rhs) = delete;
    ...
};
```
In the above example, the copy constructor for A is deleted and the compiler will give an error if the code attempts to use it.

For example, from 03_adapter example where the copy constructor and copy assignment calls have been deleted:

```
class Adapter
{
public:
	...
    Adapter(const Adapter &) = delete;
    Adapter &operator =(const Adapter &) = delete;
	...
};
```
If one tried something like:

```
Adapter adapter {};
    
Adapter adpt2 {adapter};
Adapter adpt3 {};
adpt3 = adapter;
```
The compiler would give two errors.  Something like:

* Call to deleted constructor of 'Apdapter'
* Overload resolution selected deleted operator'='.


NOTE:  = delete can be applied to any method and not just the special methods.

<a name="endl"></a>
## std::endl
Besides adding a linefeed to the output, a `flush()` command is also given.  This can be a source of inefficency.  Unless there is an explicit need for flushing the output buffer, one should just use the newline character, `'\n'`, instead.